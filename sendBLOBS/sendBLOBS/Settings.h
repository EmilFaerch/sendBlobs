#pragma once
#include <string>

using namespace std;

namespace sendBLOBS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
		}

	protected:
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  txt_maxA;
	protected:

	private: System::Windows::Forms::TrackBar^  maxA;
	protected:

	protected:

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  txt_minA;
	private: System::Windows::Forms::TrackBar^  minA;
	private: System::Windows::Forms::Label^  txt_maxTH;
	private: System::Windows::Forms::TrackBar^  maxTH;

	private: System::Windows::Forms::Label^  txt_minTH;
	private: System::Windows::Forms::TrackBar^  minTH;
	private: System::Windows::Forms::Label^  txt_maxIn;

	private: System::Windows::Forms::TrackBar^  maxIn;
	private: System::Windows::Forms::Label^  txt_minIn;

	private: System::Windows::Forms::TrackBar^  minIn;

	private: System::Windows::Forms::Label^  txt_maxCir;
	private: System::Windows::Forms::TrackBar^  maxCir;

	private: System::Windows::Forms::Label^  txt_minCir;
	private: System::Windows::Forms::TrackBar^  minCir;
	private: System::Windows::Forms::Label^  txt_maxCon;
	private: System::Windows::Forms::TrackBar^  maxCon;

	private: System::Windows::Forms::Label^  txt_minCon;
	private: System::Windows::Forms::TrackBar^  minCon;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::Label^  label17;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_maxA = (gcnew System::Windows::Forms::Label());
			this->maxA = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_minA = (gcnew System::Windows::Forms::Label());
			this->minA = (gcnew System::Windows::Forms::TrackBar());
			this->txt_maxTH = (gcnew System::Windows::Forms::Label());
			this->maxTH = (gcnew System::Windows::Forms::TrackBar());
			this->txt_minTH = (gcnew System::Windows::Forms::Label());
			this->minTH = (gcnew System::Windows::Forms::TrackBar());
			this->txt_maxIn = (gcnew System::Windows::Forms::Label());
			this->maxIn = (gcnew System::Windows::Forms::TrackBar());
			this->txt_minIn = (gcnew System::Windows::Forms::Label());
			this->minIn = (gcnew System::Windows::Forms::TrackBar());
			this->txt_maxCir = (gcnew System::Windows::Forms::Label());
			this->maxCir = (gcnew System::Windows::Forms::TrackBar());
			this->txt_minCir = (gcnew System::Windows::Forms::Label());
			this->minCir = (gcnew System::Windows::Forms::TrackBar());
			this->txt_maxCon = (gcnew System::Windows::Forms::Label());
			this->maxCon = (gcnew System::Windows::Forms::TrackBar());
			this->txt_minCon = (gcnew System::Windows::Forms::Label());
			this->minCon = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxTH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minTH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxIn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minIn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxCir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minCir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxCon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minCon))->BeginInit();
			this->SuspendLayout();
			// 
			// txt_maxA
			// 
			this->txt_maxA->AutoSize = true;
			this->txt_maxA->Location = System::Drawing::Point(148, 39);
			this->txt_maxA->Name = L"txt_maxA";
			this->txt_maxA->Size = System::Drawing::Size(46, 17);
			this->txt_maxA->TabIndex = 12;
			this->txt_maxA->Text = Convert::ToString(maxA->Value);
			// 
			// maxA
			// 
			this->maxA->Location = System::Drawing::Point(122, 59);
			this->maxA->Maximum = 5000;
			this->maxA->Minimum = 200;
			this->maxA->Name = L"maxA";
			this->maxA->Size = System::Drawing::Size(104, 56);
			this->maxA->TabIndex = 11;
			this->maxA->ValueChanged += gcnew System::EventHandler(this, &Settings::maxA_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(97, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Area";
			// 
			// txt_minA
			// 
			this->txt_minA->AutoSize = true;
			this->txt_minA->Location = System::Drawing::Point(44, 39);
			this->txt_minA->Name = L"txt_minA";
			this->txt_minA->Size = System::Drawing::Size(60, 17);
			this->txt_minA->TabIndex = 9;
			this->txt_minA->Text = Convert::ToString(minA->Value);
			// 
			// minA
			// 
			this->minA->Location = System::Drawing::Point(12, 59);
			this->minA->Maximum = 5000;
			this->minA->Minimum = 100;
			this->minA->Name = L"minA";
			this->minA->Size = System::Drawing::Size(104, 56);
			this->minA->TabIndex = 8;
			this->minA->ValueChanged += gcnew System::EventHandler(this, &Settings::minA_ValueChanged);
			// 
			// txt_maxTH
			// 
			this->txt_maxTH->AutoSize = true;
			this->txt_maxTH->Location = System::Drawing::Point(397, 39);
			this->txt_maxTH->Name = L"txt_maxTH";
			this->txt_maxTH->Size = System::Drawing::Size(46, 17);
			this->txt_maxTH->TabIndex = 17;
			this->txt_maxTH->Text = Convert::ToString(maxTH->Value);
			// 
			// maxTH
			// 
			this->maxTH->Location = System::Drawing::Point(371, 59);
			this->maxTH->Maximum = 255;
			this->maxTH->Minimum = 1;
			this->maxTH->Name = L"maxTH";
			this->maxTH->Size = System::Drawing::Size(104, 56);
			this->maxTH->TabIndex = 16;
			this->maxTH->ValueChanged += gcnew System::EventHandler(this, &Settings::maxTH_ValueChanged);
			// 
			// txt_minTH
			// 
			this->txt_minTH->AutoSize = true;
			this->txt_minTH->Location = System::Drawing::Point(293, 39);
			this->txt_minTH->Name = L"txt_minTH";
			this->txt_minTH->Size = System::Drawing::Size(46, 17);
			this->txt_minTH->TabIndex = 14;
			this->txt_minTH->Text = Convert::ToString(minTH->Value);
			// 
			// minTH
			// 
			this->minTH->Location = System::Drawing::Point(261, 59);
			this->minTH->Maximum = 254;
			this->minTH->Minimum = 0;
			this->minTH->Name = L"minTH";
			this->minTH->Size = System::Drawing::Size(104, 56);
			this->minTH->TabIndex = 13;
			this->minTH->ValueChanged += gcnew System::EventHandler(this, &Settings::minTH_ValueChanged);
			// 
			// txt_maxIn
			// 
			this->txt_maxIn->AutoSize = true;
			this->txt_maxIn->Location = System::Drawing::Point(397, 150);
			this->txt_maxIn->Name = L"txt_maxIn";
			this->txt_maxIn->Size = System::Drawing::Size(46, 17);
			this->txt_maxIn->TabIndex = 27;
			this->txt_maxIn->Text = Convert::ToString(maxIn->Value);
			// 
			// maxIn
			// 
			this->maxIn->Location = System::Drawing::Point(371, 170);
			this->maxIn->Maximum = 100;
			this->maxIn->Minimum = 1;
			this->maxIn->Name = L"maxIn";
			this->maxIn->Size = System::Drawing::Size(104, 56);
			this->maxIn->TabIndex = 26;
			this->maxIn->ValueChanged += gcnew System::EventHandler(this, &Settings::maxIn_ValueChanged);
			// 
			// txt_minIn
			// 
			this->txt_minIn->AutoSize = true;
			this->txt_minIn->Location = System::Drawing::Point(293, 150);
			this->txt_minIn->Name = L"txt_minIn";
			this->txt_minIn->Size = System::Drawing::Size(46, 17);
			this->txt_minIn->TabIndex = 24;
			this->txt_minIn->Text = Convert::ToString(minIn->Value);
			// 
			// minIn
			// 
			this->minIn->Location = System::Drawing::Point(261, 170);
			this->minIn->Maximum = 100;
			this->minIn->Minimum = 1;
			this->minIn->Name = L"minIn";
			this->minIn->Size = System::Drawing::Size(104, 56);
			this->minIn->TabIndex = 23;
			this->minIn->ValueChanged += gcnew System::EventHandler(this, &Settings::minIn_ValueChanged);
			// 
			// txt_maxCir
			// 
			this->txt_maxCir->AutoSize = true;
			this->txt_maxCir->Location = System::Drawing::Point(148, 150);
			this->txt_maxCir->Name = L"txt_maxCir";
			this->txt_maxCir->Size = System::Drawing::Size(54, 17);
			this->txt_maxCir->TabIndex = 22;
			this->txt_maxCir->Text = Convert::ToString(maxCir->Value);
			// 
			// maxCir
			// 
			this->maxCir->Location = System::Drawing::Point(122, 170);
			this->maxCir->Maximum = 100;
			this->maxCir->Minimum = 1;
			this->maxCir->Name = L"maxCir";
			this->maxCir->Size = System::Drawing::Size(104, 56);
			this->maxCir->TabIndex = 21;
			this->maxCir->ValueChanged += gcnew System::EventHandler(this, &Settings::maxCir_ValueChanged);
			// 
			// txt_minCir
			// 
			this->txt_minCir->AutoSize = true;
			this->txt_minCir->Location = System::Drawing::Point(44, 150);
			this->txt_minCir->Name = L"txt_minCir";
			this->txt_minCir->Size = System::Drawing::Size(54, 17);
			this->txt_minCir->TabIndex = 19;
			this->txt_minCir->Text = Convert::ToString(minCir->Value);
			// 
			// minCir
			// 
			this->minCir->Location = System::Drawing::Point(12, 170);
			this->minCir->Maximum = 100;
			this->minCir->Minimum = 1;
			this->minCir->Name = L"minCir";
			this->minCir->Size = System::Drawing::Size(104, 56);
			this->minCir->TabIndex = 18;
			this->minCir->ValueChanged += gcnew System::EventHandler(this, &Settings::minCir_ValueChanged);
			// 
			// txt_maxCon
			// 
			this->txt_maxCon->AutoSize = true;
			this->txt_maxCon->Location = System::Drawing::Point(148, 258);
			this->txt_maxCon->Name = L"txt_maxCon";
			this->txt_maxCon->Size = System::Drawing::Size(54, 17);
			this->txt_maxCon->TabIndex = 32;
			this->txt_maxCon->Text = Convert::ToString(maxCon->Value);
			// 
			// maxCon
			// 
			this->maxCon->Location = System::Drawing::Point(122, 278);
			this->maxCon->Maximum = 100;
			this->maxCon->Minimum = 1;
			this->maxCon->Name = L"maxCon";
			this->maxCon->Size = System::Drawing::Size(104, 56);
			this->maxCon->TabIndex = 31;
			this->maxCon->ValueChanged += gcnew System::EventHandler(this, &Settings::maxCon_ValueChanged);
			// 
			// txt_minCon
			// 
			this->txt_minCon->AutoSize = true;
			this->txt_minCon->Location = System::Drawing::Point(44, 258);
			this->txt_minCon->Name = L"txt_minCon";
			this->txt_minCon->Size = System::Drawing::Size(54, 17);
			this->txt_minCon->TabIndex = 29;
			this->txt_minCon->Text = Convert::ToString(minCon->Value);
			// 
			// minCon
			// 
			this->minCon->Location = System::Drawing::Point(12, 278);
			this->minCon->Maximum = 100;
			this->minCon->Minimum = 1;
			this->minCon->Name = L"minCon";
			this->minCon->Size = System::Drawing::Size(104, 56);
			this->minCon->TabIndex = 28;
			this->minCon->ValueChanged += gcnew System::EventHandler(this, &Settings::minCon_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(327, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 24);
			this->label5->TabIndex = 38;
			this->label5->Text = L"Threshold";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(337, 114);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(60, 24);
			this->label8->TabIndex = 40;
			this->label8->Text = L"Inertia";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(78, 114);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(91, 24);
			this->label11->TabIndex = 39;
			this->label11->Text = L"Circularity";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(79, 225);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(92, 24);
			this->label17->TabIndex = 41;
			this->label17->Text = L"Convexity";

			this->maxA->Value = vmaxA;
			this->minA->Value = vminA;
			this->maxTH->Value = vmaxTH;
			this->minTH->Value = vminTH;
			this->maxIn->Value = vmaxIn;
			this->minIn->Value = vminIn;
			this->maxCir->Value = vmaxCir;
			this->minCir->Value = vminCir;
			this->maxCon->Value = vmaxCon;
			this->minCon->Value = vminCon;
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(488, 334);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txt_maxCon);
			this->Controls->Add(this->maxCon);
			this->Controls->Add(this->txt_minCon);
			this->Controls->Add(this->minCon);
			this->Controls->Add(this->txt_maxIn);
			this->Controls->Add(this->maxIn);
			this->Controls->Add(this->txt_minIn);
			this->Controls->Add(this->minIn);
			this->Controls->Add(this->txt_maxCir);
			this->Controls->Add(this->maxCir);
			this->Controls->Add(this->txt_minCir);
			this->Controls->Add(this->minCir);
			this->Controls->Add(this->txt_maxTH);
			this->Controls->Add(this->maxTH);
			this->Controls->Add(this->txt_minTH);
			this->Controls->Add(this->minTH);
			this->Controls->Add(this->txt_maxA);
			this->Controls->Add(this->maxA);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txt_minA);
			this->Controls->Add(this->minA);
			this->Name = L"Settings";
			this->Text = L"Settings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxTH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minTH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxIn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minIn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxCir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minCir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxCon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minCon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	************ STANDARD VARIABLES! ************/
	public: float vminA = 100, vmaxA = 400, vminTH = 0, vmaxTH = 120, vminCir = 50, vmaxCir = 100, vminIn = 70, vmaxIn = 100, vminCon = 70, vmaxCon = 100;

public: System::String^ get_minA(){ return Convert::ToString(vminA); }
public: System::String^ get_maxA(){ return Convert::ToString(vmaxA); }
private: System::Void minA_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vminA = minA->Value; txt_minA->Text = Convert::ToString(vminA); }
private: System::Void maxA_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vmaxA = maxA->Value; txt_maxA->Text = Convert::ToString(vmaxA); }

public: System::String^ get_minTH(){ return Convert::ToString(vminTH); }
public: System::String^ get_maxTH(){ return Convert::ToString(vmaxTH); }
private: System::Void minTH_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vminTH = minTH->Value; txt_minTH->Text = Convert::ToString(vminTH); }
private: System::Void maxTH_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vmaxTH = maxTH->Value; txt_maxTH->Text = Convert::ToString(vmaxTH); }

public: System::String^ get_minCir(){ return Convert::ToString(vminCir); }
public: System::String^ get_maxCir(){ return Convert::ToString(vmaxCir); }
private: System::Void minCir_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vminCir = minCir->Value / 100.0; txt_minCir->Text = Convert::ToString(vminCir); }
private: System::Void maxCir_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vmaxCir = maxCir->Value / 100.0; txt_maxCir->Text = Convert::ToString(vmaxCir); }

public: System::String^ get_minCon(){ return Convert::ToString(vminCon); }
public: System::String^ get_maxCon(){ return Convert::ToString(vmaxCon); }
private: System::Void minCon_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vminCon = minCon->Value / 100.0; txt_minCon->Text = Convert::ToString(vminCon); }
private: System::Void maxCon_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vmaxCon = maxCon->Value / 100.0; txt_maxCon->Text = Convert::ToString(vmaxCon); }

public: System::String^ get_minIn(){ return Convert::ToString(vminIn); }
public: System::String^ get_maxIn(){ return Convert::ToString(vmaxIn); }
private: System::Void minIn_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vminIn = minIn->Value / 100.0; txt_minIn->Text = Convert::ToString(vminIn); }
private: System::Void maxIn_ValueChanged(System::Object^  sender, System::EventArgs^  e) { vmaxIn = maxIn->Value / 100.0; txt_maxIn->Text = Convert::ToString(vmaxIn); }
};
}
