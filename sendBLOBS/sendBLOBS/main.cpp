#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "Settings.h"
#include <Windows.h>

using namespace cv;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void findEdge(int posX, int posY, int size, Mat input, int minTH, int maxTH);
void increaseContrast(Mat input, int amount);
void subtractBack(Mat background, Mat input);
void findTriangle(int posX, int posY, int size, Mat input);

Mat hwnd2mat(HWND hwnd); // Function used to get desktop stream

Mat input, im, blobs, background, b_triangle;

HWND hwndDesktop = GetDesktopWindow();

int main(int argc, char** argv)
{
	//VideoCapture cap(0);
	//cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 100);	

	// Show Parameter Interface
	sendBLOBS::Settings formSettings;
	formSettings.Show();

	// Storage for blobs
	vector<KeyPoint> keypoints;
	background = hwnd2mat(hwndDesktop);

	b_triangle = imread("C:/Users/EmilFaerch/Desktop/trekant.PNG", 0);

	while (true){

		//cap.read(input);				// Webcam stream
		input = hwnd2mat(hwndDesktop);	// Desktop stream
		cvtColor(input, im, CV_RGB2GRAY);

		//subtractBack(background, im);
	
	//	GaussianBlur(im, im, Size(7, 7), 1.5, 1.5);
	//	increaseContrast(im, 3);

		blobs = Mat::zeros(input.rows, input.cols, CV_8UC1);	// Initiate / Clear BLOBs picture

		SimpleBlobDetector::Params params;

		// Filter by Threshold
		float vminTH, vmaxTH;
		System::Single::TryParse(formSettings.get_minTH(), vminTH);
		System::Single::TryParse(formSettings.get_maxTH(), vmaxTH);
		params.minThreshold = vminTH;
		params.maxThreshold = vmaxTH;

		// Filter by Area
		float vminA, vmaxA;
		System::Single::TryParse(formSettings.get_minA(), vminA);
		System::Single::TryParse(formSettings.get_maxA(), vmaxA);
		params.filterByArea = true;
		params.minArea = vminA;
		params.maxArea = vmaxA;

		// Filter by Circularity
		float vminCir, vmaxCir;
		System::Single::TryParse(formSettings.get_minCir(), vminCir);
		System::Single::TryParse(formSettings.get_maxCir(), vmaxCir);
		params.filterByCircularity = true;
		params.minCircularity = vminCir;
		params.maxCircularity = vmaxCir;

		// Filter by Convexity
		float vminCon, vmaxCon;
		System::Single::TryParse(formSettings.get_minCon(), vminCon);
		System::Single::TryParse(formSettings.get_maxCon(), vmaxCon);
		params.filterByConvexity = true;
		params.minConvexity = vminCon;
		params.maxConvexity = vmaxCon;

		// Filter by Inertia
		float vminIn, vmaxIn;
		System::Single::TryParse(formSettings.get_minIn(), vminIn);
		System::Single::TryParse(formSettings.get_maxIn(), vmaxIn);
		params.filterByInertia = true;
		params.minInertiaRatio = vminIn;
		params.maxInertiaRatio = vmaxIn;

#if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2

		// Set up detector with params
		SimpleBlobDetector detector(params);

		// Detect blobs
		detector.detect(im, keypoints);
#else 

		// Set up detector with params
		Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

#endif 

		// Detect blobs
		detector->detect(im, keypoints);

		// Setup SimpleBlobDetector parameters.
		// Draw detected blobs as red circles.
		// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures
		// the size of the circle corresponds to the size of blob

		Mat im_with_keypoints; // image with keypoints
		drawKeypoints(im, keypoints, im_with_keypoints, Scalar(0, 255, 0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS); // Draw circles on identified BLOBs

		try{
			if (sizeof(keypoints) > 0){ // if we found any BLOBs
				for each (KeyPoint key in keypoints){ // for each of those
					printf("Found a blob!\n");
					findEdge(key.pt.x, key.pt.y, key.size, im, vminTH, vmaxTH); // we find edges
					printf("Found edges!\n");
					findTriangle(key.pt.x, key.pt.y, key.size, blobs);
					printf("Looked for triangle!\n");
				}
			}
		}
		catch (exception e) {} // We get a lot of errors, but this way it doesn't crash

		// Show blobs
		imshow("keypoints", im_with_keypoints);
		imshow("Blobs", blobs);

		if (waitKey(30) >= 0) break;
	}

	waitKey(0);

	return 0;
}

void findEdge(int posX, int posY, int size, Mat input, int minTH, int maxTH){
	int offset = 5;

	float startY = posY - (size / 2) - offset;
	float stopY = posY + (size / 2) + offset;
	float sizeY = stopY - startY;

	float startX = posX - (size / 2) - offset;
	float stopX = posX + (size / 2) + offset;
	float sizeX = stopX - startX;

	Mat foundBLOB = Mat::zeros(sizeY, sizeX, CV_8UC1);

	for (int y = startY; y < stopY; y++)
	{
		for (int x = startX; x < stopX; x++)
		{
			foundBLOB.at<uchar>(y - startY, x - startX) = input.at<uchar>(y, x);
		}
	}

	GaussianBlur(foundBLOB, foundBLOB, Size(7, 7), 1.5, 1.5);
	Canny(foundBLOB, foundBLOB, 0, 30, 3);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			blobs.at<uchar>(y + startY, x + startX) = foundBLOB.at<uchar>(y, x);
		}
	}

	imshow("Blobs", blobs);
}

void increaseContrast(Mat input, int amount){
	int curVal;
	for (int y = 0; y < input.rows; y++){
		for (int x = 0; x < input.cols; x++){
			curVal = input.at<uchar>(y, x);
			if (curVal * amount <= 255) input.at<uchar>(y, x) = curVal * amount;
			else input.at<uchar>(y, x) = 255;
		}
	}
}


// Virker ikke, fordi vi ikke tager størrelsesforhold i betragtning! Template skal være samme størrelse som BLOB vi finder, på bordet!
// ... og så er der fejl næsten hele tiden. -- nok fordi DET ER SÅ LILLE ET TEMPLATE!
void findTriangle(int posX, int posY, int size, Mat input){
	printf("Finding triangle...\n");
	int samePix = 0;
	int offset = 5;

	float startY = posY - (size / 2) - offset;
	float stopY = posY + (size / 2) + offset;
	float sizeY = stopY - startY;

	float startX = posX - (size / 2) - offset;
	float stopX = posX + (size / 2) + offset;
	float sizeX = stopX - startX;

	for (int y = startY; y < stopY; y++)
	{
		printf("For-loop Y\n");
		for (int x = startX; x < stopX; x++)
		{
			printf("For-loop X\n");
			printf("Checking to see if they're the same.\n");
			if (b_triangle.at<uchar>(y - startY, x - startX) == input.at<uchar>(y,x)){
				printf("They were the same! samePix++\n");
				samePix++;
			}
			else
			{
				printf("Not the same ...\n");
			}
		}
	}

	if (samePix / (sizeX * sizeY) * 100 < 75.0){
		printf("Under 75 percent correct\n");
	}
	else
	{
		printf("Above 75 percent correct\n");
	}

}

/* Hold kæft hvor det ikke virker -----
void subtractBack(Mat background, Mat input){
	int pixInp, pixBG, pixVal;

	blur(background, background, Size(30, 30));

	for (int y = 0; y < background.rows; y++){
		for (int x = 0; x < background.cols; x++){
			pixInp = input.at<uchar>(y, x);
			pixBG = background.at<uchar>(y, x);
			pixVal = pixInp - pixBG;

			if (pixVal < 256 || pixVal > -1) input.at<uchar>(y, x) = pixVal;
			else if (pixVal > 255) input.at<uchar>(y, x) = 255;
			else input.at<uchar>(y, x) = 0;
		}
	}
}*/

Mat hwnd2mat(HWND hwnd) // Dont ask me about this :S - found this snippet online
{
	HDC hwindowDC, hwindowCompatibleDC;

	int height, width, srcheight, srcwidth;
	HBITMAP hbwindow;
	Mat src;
	BITMAPINFOHEADER  bi;

	hwindowDC = GetDC(hwnd);
	hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
	SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

	RECT windowsize;    // get the height and width of the screen
	GetClientRect(hwnd, &windowsize);

	// SOURCE CAPTURE
	srcheight = windowsize.bottom / 1.1;
	srcwidth = windowsize.right / 1.6;

	// DISPLAY WINDOW
	height = windowsize.bottom / 1.37;
	width = windowsize.right / 2;

	src.create(height, width, CV_8UC4);

	// create a bitmap
	hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
	bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
	bi.biWidth = width;
	bi.biHeight = -height;  //this is the line that makes it draw upside down or not
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	// use the previously created device context with the bitmap
	SelectObject(hwindowCompatibleDC, hbwindow);
	// copy from the window device context to the bitmap device context
	StretchBlt(hwindowCompatibleDC, -2, -30, width, height, hwindowDC, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
	GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

	// avoid memory leak
	DeleteObject(hbwindow);
	DeleteDC(hwindowCompatibleDC);
	ReleaseDC(hwnd, hwindowDC);

	return src;
}