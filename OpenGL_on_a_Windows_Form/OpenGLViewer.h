#pragma once

#include "OpenGL.h"

namespace OpenGL_on_a_Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;



	/// <summary>
	/// Summary for OpenGLViewer
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class OpenGLViewer : public System::Windows::Forms::Form
	{
	public:
		OpenGLViewer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			OpenGL = gcnew COpenGL(this, panelOpenGL->Left, panelOpenGL->Top,
				panelOpenGL->Width, panelOpenGL->Height);

			// some sound stuff

			// using SoundPlayer (good for sound effects, but limited to .wav and very little control)
			insideSound = gcnew System::Media::SoundPlayer("cash_register.wav");
			outsideSound = gcnew System::Media::SoundPlayer("buzzer.wav");

			// using Windows Media Player (full-fledged sound and video player, can use many file types)
			axWindowsMediaPlayer1->settings->autoStart = false; // if you don't do this, the sound will play once when it is loaded
			axWindowsMediaPlayer1->URL = "Toilet_Flushing.mp3";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OpenGLViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panelOpenGL;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ userFeedback;

	private: System::Windows::Forms::Label^ label2;


		   // sound stuff

	protected:
		System::Media::SoundPlayer^ insideSound;
		System::Media::SoundPlayer^ outsideSound;

	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OpenGLViewer::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelOpenGL = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->userFeedback = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &OpenGLViewer::timer1_Tick);
			// 
			// panelOpenGL
			// 
			this->panelOpenGL->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelOpenGL->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->panelOpenGL->Location = System::Drawing::Point(95, 36);
			this->panelOpenGL->Name = L"panelOpenGL";
			this->panelOpenGL->Size = System::Drawing::Size(691, 431);
			this->panelOpenGL->TabIndex = 0;
			this->panelOpenGL->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Broadway", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"My First Windows App";
			// 
			// userFeedback
			// 
			this->userFeedback->AutoSize = true;
			this->userFeedback->Location = System::Drawing::Point(21, 495);
			this->userFeedback->Name = L"userFeedback";
			this->userFeedback->Size = System::Drawing::Size(28, 13);
			this->userFeedback->TabIndex = 1;
			this->userFeedback->Text = L" - - - ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Input1";
			this->label2->MouseEnter += gcnew System::EventHandler(this, &OpenGLViewer::label2_MouseEnter);
			this->label2->MouseLeave += gcnew System::EventHandler(this, &OpenGLViewer::label2_MouseLeave);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(648, 12);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(75, 46);
			this->axWindowsMediaPlayer1->TabIndex = 4;
			this->axWindowsMediaPlayer1->Visible = false;
			// 
			// OpenGLViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 522);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->userFeedback);
			this->Controls->Add(this->panelOpenGL);
			this->Name = L"OpenGLViewer";
			this->Text = L"Nestor\'s Borrowed OpenGL on a Windows Form using Managed C++";
			this->Load += gcnew System::EventHandler(this, &OpenGLViewer::OpenGLViewer_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &OpenGLViewer::OpenGLViewer_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLViewer::OpenGLViewer_MouseClick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}

	private: System::Void mainform_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Q) {
			userFeedback->Text = "Got the letter Q";
			e->SuppressKeyPress = true;
		}
		else
			userFeedback->Text = " - - -";

	}

	private: System::Void OpenGLViewer_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		userFeedback->Text = "Got a click";
	}
	private: System::Void OpenGLViewer_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void OpenGLViewer_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Q) {
			userFeedback->Text = "Got the letter Q";
			e->SuppressKeyPress = true;
		}
		else {
			userFeedback->Text = " - - -";
			MessageBox::Show("You pressed another key >> " + e->KeyValue);
		}
	}

	private: System::Void label2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		userFeedback->Text = "Now over label";
	}
	private: System::Void label2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		userFeedback->Text = " - - -";
	}

	public: void playInsideSound() {
		insideSound->Play();
	}
	public: void playOutsideSound() {
		outsideSound->Play();

		// for looping (play the sound over and over like a background), use
		//outsideSound->PlayLooping();
	}
	public: void playThirdSound() {
		// if you need the duration
		auto soundDuration = axWindowsMediaPlayer1->currentMedia->duration;

		// use this to set or get current position of the sound
		// axWindowsMediaPlayer1->Ctlcontrols->currentPosition  (a value of type double, in seconds from start)

		// to set up looping 
		// axWindowsMediaPlayer1->settings->setMode("loop", true);

		// let's say I wanted to restart and lower volume everytime I clicked . . .
		if (axWindowsMediaPlayer1->playState == WMPLib::WMPPlayState::wmppsPlaying) {
			axWindowsMediaPlayer1->Ctlcontrols->stop();
			axWindowsMediaPlayer1->settings->volume -= 5;  // volume starts at 50, by default
		}

		axWindowsMediaPlayer1->Ctlcontrols->play(); // if media is already playing, this has no effect
	}
	};
}

