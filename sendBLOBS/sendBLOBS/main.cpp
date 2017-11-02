#include "opencv2/opencv.hpp"
#include "Settings.h"

using namespace cv;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void findEdge(int posX, int posY, int size, Mat input, int minTH, int maxTH);// , int id);

Mat input;

Mat im;

Mat blobs;

int main(int argc, char** argv)
{
	VideoCapture cap(0);

	sendBLOBS::Settings formSettings;
	formSettings.Show();

	// Storage for blobs
	vector<KeyPoint> keypoints;

	while (true){

		cap.read(input);
		cvtColor(input, im, CV_RGB2GRAY);

		blobs = Mat::zeros(input.rows, input.cols, CV_8UC1);

		SimpleBlobDetector::Params params;

		// Change thresholds
		float vminTH, vmaxTH;
		System::Single::TryParse(formSettings.get_minTH(), vminTH);
		System::Single::TryParse(formSettings.get_maxTH(), vmaxTH);
		params.minThreshold = vminTH;
		params.maxThreshold = vmaxTH;

		// Filter by Area.
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

		Mat im_with_keypoints;
		drawKeypoints(im, keypoints, im_with_keypoints, Scalar(0, 255, 0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

		// Show blobs
		imshow("keypoints", im_with_keypoints);

		try{
			if (sizeof(keypoints) > 0){
				for each (KeyPoint key in keypoints){
					findEdge(key.pt.x, key.pt.y, key.size, im, vminTH, vmaxTH);
				}
			}
		}
		catch (exception e) {}

		if (waitKey(30) >= 0) break;
	}
		waitKey(0);
	return 0;
} 

void findEdge(int posX, int posY, int size, Mat input, int minTH, int maxTH){

	Mat mean = Mat::zeros(input.rows, input.cols, CV_8UC1);
	Mat Gx = Mat::zeros(input.rows, input.cols, CV_8UC1);
	Mat Gy = Mat::zeros(input.rows, input.cols, CV_8UC1);
	Mat Gm = Mat::zeros(input.rows, input.cols, CV_8UC1);

	//Nested for loop to run through all pixels in input image and apply operations to them
	//The loop starts at 1,1 and ending at width-2,height-2 (because of 3x3 kernel)
	for (int y = posY - size/2 - 25; y < posY + size / 2 + 25; y++)// abs(posY - size / 2) + 1; y < size - 2; y++)
	{
		for (int x = posX - size/2 - 25; x < posX + size / 2 + 25; x++)//(int x = abs(posX - size/2) + 1; x < size - 2; x++)
		{
			//Applying a Mean filter to the input and saving it to mean
			//  1 1 1
			//  1 1 1 x (1/9)
			//  1 1 1

			mean.at<unsigned char>(y, x) = (input.at<unsigned char>(y - 1, x - 1) + input.at<unsigned char>(y - 1, x) + input.at<unsigned char>(y - 1, x + 1) +
				input.at<unsigned char>(y, x - 1) + input.at<unsigned char>(y, x) + input.at<unsigned char>(y, x + 1) +
				input.at<unsigned char>(y + 1, x - 1) + input.at<unsigned char>(y + 1, x) + input.at<unsigned char>(y + 1, x + 1)) / 9;

			//This kernel is applied to mean and saved in Gx:
			// 0  1  2
			//-1  0  1
			//-2 -1  0				

			Gx.at<unsigned char>(y, x) = mean.at<unsigned char>(y - 1, x) + (mean.at<unsigned char>(y - 1, x + 1) * 2) +
				(mean.at<unsigned char>(y, x - 1)* -1) + mean.at<unsigned char>(y, x + 1) +
				(mean.at<unsigned char>(y + 1, x - 1)* -2) + (mean.at<unsigned char>(y + 1, x)* -1);

			//This kernel is applied to mean and saved in Gy:
			// -2 -1  0
			// -1  0  1
			//  0  1  2

			Gy.at<unsigned char>(y, x) = (mean.at<unsigned char>(y - 1, x - 1)*-2) + (mean.at<unsigned char>(y - 1, x) * -1) +
				(mean.at<unsigned char>(y, x - 1)*-1) + mean.at<unsigned char>(y, x + 1) +
				mean.at<unsigned char>(y + 1, x) + (mean.at<unsigned char>(y + 1, x + 1) * 2);

			//Apply Gm = |Gx|+|Gy| and save it in Gm
			Gm.at<unsigned char>(y, x) = abs(Gy.at<unsigned char>(y, x)) + abs(Gx.at<unsigned char>(y, x));

			if (Gm.at<unsigned char>(y, x) >= minTH && Gm.at<uchar>(y, x) <= maxTH)
			{
				blobs.at<unsigned char>(y, x) = 255; //White if the input is above the threshold
			}
			else
			{
				blobs.at<unsigned char>(y, x) = 0; //Black if its below (It already is)
			}
		}
	}

	imshow("Blobs", blobs);
}
