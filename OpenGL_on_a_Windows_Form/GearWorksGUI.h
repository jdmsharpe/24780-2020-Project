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
	/// Summary for GearWorksGUI
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GearWorksGUI : public System::Windows::Forms::Form
	{
	public:
		GearWorksGUI(void)
		{
			InitializeComponent();
			OpenGL = gcnew COpenGL(this, openGLPanel->Left, openGLPanel->Top, openGLPanel->Width, openGLPanel->Height);
			unitsComboBox->SelectedIndex = 0;
			hubComboBox->SelectedIndex = 0;
			pitchInput->Text = "16";
			pressureInput->Text = "20";
			teethInput->Text = "32";
			materialWidthInput->Text = "12";
			materialHeightInput->Text = "12";
			updateMaterial();
		}

	public:
		System::Collections::Generic::List<NumericUpDown^> gearQtys;
		System::Collections::Generic::List<Label^> gearLabels;



	private: System::Windows::Forms::Panel^ gearParametersPanel;
	private: System::Windows::Forms::Button^ addGearButton;
	private: System::Windows::Forms::GroupBox^ hubGroupBox;
	private: System::Windows::Forms::TextBox^ hubInputB;
	private: System::Windows::Forms::Label^ hubLabelB;
	private: System::Windows::Forms::TextBox^ hubInputA;
	private: System::Windows::Forms::Label^ hubLabelA;
	private: System::Windows::Forms::PictureBox^ hubPictureBox;
	private: System::Windows::Forms::ComboBox^ hubComboBox;
	private: System::Windows::Forms::GroupBox^ gearGroupBox;
	private: System::Windows::Forms::NumericUpDown^ teethInput;
	private: System::Windows::Forms::Label^ teethLabel;
	private: System::Windows::Forms::TextBox^ pressureInput;
	private: System::Windows::Forms::Label^ pressureLabel;
	private: System::Windows::Forms::TextBox^ pitchInput;
	private: System::Windows::Forms::Label^ pitchLabel;
	private: System::Windows::Forms::GroupBox^ unitsGroupBox;
	private: System::Windows::Forms::ComboBox^ unitsComboBox;

	private: System::Windows::Forms::Panel^ openGLPanel;
	private: System::Windows::Forms::Panel^ visualizerControlPanel;
	private: System::Windows::Forms::Button^ exportButton;
	private: System::Windows::Forms::Panel^ gearListPanel;
	private: System::Windows::Forms::TableLayoutPanel^ gearListTable;
	private: System::Windows::Forms::Label^ gearTableCol1Label;
	private: System::Windows::Forms::Label^ gearTableCol2Label;
	private: System::Windows::Forms::Label^ gearTableCol3Label;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ materialHeightInput;
	private: System::Windows::Forms::Label^ materialHeightLabel;
	private: System::Windows::Forms::TextBox^ materialWidthInput;
	private: System::Windows::Forms::Label^ materialWidthLabel;
	private: System::Windows::Forms::Panel^ gearListScrollPanel;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GearWorksGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^ timer1;

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
			System::Windows::Forms::GroupBox^ ExportBox;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GearWorksGUI::typeid));
			this->materialHeightInput = (gcnew System::Windows::Forms::TextBox());
			this->materialHeightLabel = (gcnew System::Windows::Forms::Label());
			this->materialWidthInput = (gcnew System::Windows::Forms::TextBox());
			this->materialWidthLabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->gearParametersPanel = (gcnew System::Windows::Forms::Panel());
			this->addGearButton = (gcnew System::Windows::Forms::Button());
			this->hubGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->hubInputB = (gcnew System::Windows::Forms::TextBox());
			this->hubLabelB = (gcnew System::Windows::Forms::Label());
			this->hubInputA = (gcnew System::Windows::Forms::TextBox());
			this->hubLabelA = (gcnew System::Windows::Forms::Label());
			this->hubPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->hubComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->gearGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->teethInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->teethLabel = (gcnew System::Windows::Forms::Label());
			this->pressureInput = (gcnew System::Windows::Forms::TextBox());
			this->pressureLabel = (gcnew System::Windows::Forms::Label());
			this->pitchInput = (gcnew System::Windows::Forms::TextBox());
			this->pitchLabel = (gcnew System::Windows::Forms::Label());
			this->unitsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->unitsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->openGLPanel = (gcnew System::Windows::Forms::Panel());
			this->visualizerControlPanel = (gcnew System::Windows::Forms::Panel());
			this->exportButton = (gcnew System::Windows::Forms::Button());
			this->gearListPanel = (gcnew System::Windows::Forms::Panel());
			this->gearListScrollPanel = (gcnew System::Windows::Forms::Panel());
			this->gearListTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->gearTableCol1Label = (gcnew System::Windows::Forms::Label());
			this->gearTableCol2Label = (gcnew System::Windows::Forms::Label());
			this->gearTableCol3Label = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			ExportBox = (gcnew System::Windows::Forms::GroupBox());
			ExportBox->SuspendLayout();
			this->gearParametersPanel->SuspendLayout();
			this->hubGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hubPictureBox))->BeginInit();
			this->gearGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teethInput))->BeginInit();
			this->unitsGroupBox->SuspendLayout();
			this->gearListPanel->SuspendLayout();
			this->gearListScrollPanel->SuspendLayout();
			this->gearListTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// ExportBox
			// 
			ExportBox->AutoSize = true;
			ExportBox->Controls->Add(this->materialHeightInput);
			ExportBox->Controls->Add(this->materialHeightLabel);
			ExportBox->Controls->Add(this->materialWidthInput);
			ExportBox->Controls->Add(this->materialWidthLabel);
			ExportBox->Dock = System::Windows::Forms::DockStyle::Bottom;
			ExportBox->Location = System::Drawing::Point(0, 495);
			ExportBox->Name = L"ExportBox";
			ExportBox->Size = System::Drawing::Size(294, 139);
			ExportBox->TabIndex = 1;
			ExportBox->TabStop = false;
			ExportBox->Text = L"Material Size";
			// 
			// materialHeightInput
			// 
			this->materialHeightInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->materialHeightInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->materialHeightInput->Location = System::Drawing::Point(3, 106);
			this->materialHeightInput->Name = L"materialHeightInput";
			this->materialHeightInput->Size = System::Drawing::Size(288, 30);
			this->materialHeightInput->TabIndex = 3;
			this->materialHeightInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::materialHeightInput_KeyPress);
			// 
			// materialHeightLabel
			// 
			this->materialHeightLabel->AutoSize = true;
			this->materialHeightLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->materialHeightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->materialHeightLabel->Location = System::Drawing::Point(3, 81);
			this->materialHeightLabel->Name = L"materialHeightLabel";
			this->materialHeightLabel->Size = System::Drawing::Size(74, 25);
			this->materialHeightLabel->TabIndex = 2;
			this->materialHeightLabel->Text = L"Height:";
			// 
			// materialWidthInput
			// 
			this->materialWidthInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->materialWidthInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->materialWidthInput->Location = System::Drawing::Point(3, 51);
			this->materialWidthInput->Name = L"materialWidthInput";
			this->materialWidthInput->Size = System::Drawing::Size(288, 30);
			this->materialWidthInput->TabIndex = 1;
			this->materialWidthInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::materialWidthInput_KeyPress);
			// 
			// materialWidthLabel
			// 
			this->materialWidthLabel->AutoSize = true;
			this->materialWidthLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->materialWidthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->materialWidthLabel->Location = System::Drawing::Point(3, 26);
			this->materialWidthLabel->Name = L"materialWidthLabel";
			this->materialWidthLabel->Size = System::Drawing::Size(69, 25);
			this->materialWidthLabel->TabIndex = 0;
			this->materialWidthLabel->Text = L"Width:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &GearWorksGUI::timer1_Tick);
			// 
			// gearParametersPanel
			// 
			this->gearParametersPanel->AutoScroll = true;
			this->gearParametersPanel->Controls->Add(this->addGearButton);
			this->gearParametersPanel->Controls->Add(this->hubGroupBox);
			this->gearParametersPanel->Controls->Add(this->gearGroupBox);
			this->gearParametersPanel->Controls->Add(this->unitsGroupBox);
			this->gearParametersPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->gearParametersPanel->Location = System::Drawing::Point(0, 0);
			this->gearParametersPanel->Name = L"gearParametersPanel";
			this->gearParametersPanel->Size = System::Drawing::Size(194, 673);
			this->gearParametersPanel->TabIndex = 1;
			// 
			// addGearButton
			// 
			this->addGearButton->AutoSize = true;
			this->addGearButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->addGearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addGearButton->Location = System::Drawing::Point(0, 539);
			this->addGearButton->Name = L"addGearButton";
			this->addGearButton->Size = System::Drawing::Size(194, 37);
			this->addGearButton->TabIndex = 3;
			this->addGearButton->Text = L"Add Gear";
			this->addGearButton->UseVisualStyleBackColor = true;
			this->addGearButton->Click += gcnew System::EventHandler(this, &GearWorksGUI::addGearButton_Click);
			// 
			// hubGroupBox
			// 
			this->hubGroupBox->AutoSize = true;
			this->hubGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->hubGroupBox->Controls->Add(this->hubInputB);
			this->hubGroupBox->Controls->Add(this->hubLabelB);
			this->hubGroupBox->Controls->Add(this->hubInputA);
			this->hubGroupBox->Controls->Add(this->hubLabelA);
			this->hubGroupBox->Controls->Add(this->hubPictureBox);
			this->hubGroupBox->Controls->Add(this->hubComboBox);
			this->hubGroupBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubGroupBox->Location = System::Drawing::Point(0, 256);
			this->hubGroupBox->Name = L"hubGroupBox";
			this->hubGroupBox->Size = System::Drawing::Size(194, 283);
			this->hubGroupBox->TabIndex = 2;
			this->hubGroupBox->TabStop = false;
			this->hubGroupBox->Text = L"Hub";
			// 
			// hubInputB
			// 
			this->hubInputB->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubInputB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hubInputB->Location = System::Drawing::Point(3, 250);
			this->hubInputB->Name = L"hubInputB";
			this->hubInputB->Size = System::Drawing::Size(188, 30);
			this->hubInputB->TabIndex = 5;
			this->hubInputB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::hubInputB_KeyPress);
			// 
			// hubLabelB
			// 
			this->hubLabelB->AutoSize = true;
			this->hubLabelB->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubLabelB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hubLabelB->Location = System::Drawing::Point(3, 225);
			this->hubLabelB->Name = L"hubLabelB";
			this->hubLabelB->Size = System::Drawing::Size(64, 25);
			this->hubLabelB->TabIndex = 4;
			this->hubLabelB->Text = L"label1";
			// 
			// hubInputA
			// 
			this->hubInputA->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubInputA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hubInputA->Location = System::Drawing::Point(3, 195);
			this->hubInputA->Name = L"hubInputA";
			this->hubInputA->Size = System::Drawing::Size(188, 30);
			this->hubInputA->TabIndex = 3;
			this->hubInputA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::hubInputA_KeyPress);
			// 
			// hubLabelA
			// 
			this->hubLabelA->AutoSize = true;
			this->hubLabelA->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubLabelA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hubLabelA->Location = System::Drawing::Point(3, 170);
			this->hubLabelA->Name = L"hubLabelA";
			this->hubLabelA->Size = System::Drawing::Size(64, 25);
			this->hubLabelA->TabIndex = 2;
			this->hubLabelA->Text = L"label1";
			// 
			// hubPictureBox
			// 
			this->hubPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->hubPictureBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubPictureBox->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hubPictureBox.InitialImage")));
			this->hubPictureBox->Location = System::Drawing::Point(3, 59);
			this->hubPictureBox->Name = L"hubPictureBox";
			this->hubPictureBox->Padding = System::Windows::Forms::Padding(3);
			this->hubPictureBox->Size = System::Drawing::Size(188, 111);
			this->hubPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->hubPictureBox->TabIndex = 1;
			this->hubPictureBox->TabStop = false;
			// 
			// hubComboBox
			// 
			this->hubComboBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->hubComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->hubComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hubComboBox->FormattingEnabled = true;
			this->hubComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Circle", L"Rectangle" });
			this->hubComboBox->Location = System::Drawing::Point(3, 26);
			this->hubComboBox->Name = L"hubComboBox";
			this->hubComboBox->Size = System::Drawing::Size(188, 33);
			this->hubComboBox->TabIndex = 0;
			this->hubComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GearWorksGUI::hubComboBox_SelectedIndexChanged);
			// 
			// gearGroupBox
			// 
			this->gearGroupBox->AutoSize = true;
			this->gearGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->gearGroupBox->Controls->Add(this->teethInput);
			this->gearGroupBox->Controls->Add(this->teethLabel);
			this->gearGroupBox->Controls->Add(this->pressureInput);
			this->gearGroupBox->Controls->Add(this->pressureLabel);
			this->gearGroupBox->Controls->Add(this->pitchInput);
			this->gearGroupBox->Controls->Add(this->pitchLabel);
			this->gearGroupBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->gearGroupBox->Location = System::Drawing::Point(0, 62);
			this->gearGroupBox->Name = L"gearGroupBox";
			this->gearGroupBox->Size = System::Drawing::Size(194, 194);
			this->gearGroupBox->TabIndex = 1;
			this->gearGroupBox->TabStop = false;
			this->gearGroupBox->Text = L"Gear";
			// 
			// teethInput
			// 
			this->teethInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->teethInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->teethInput->Location = System::Drawing::Point(3, 161);
			this->teethInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->teethInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->teethInput->Name = L"teethInput";
			this->teethInput->Size = System::Drawing::Size(188, 30);
			this->teethInput->TabIndex = 5;
			this->teethInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// teethLabel
			// 
			this->teethLabel->AutoSize = true;
			this->teethLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->teethLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->teethLabel->Location = System::Drawing::Point(3, 136);
			this->teethLabel->Name = L"teethLabel";
			this->teethLabel->Size = System::Drawing::Size(69, 25);
			this->teethLabel->TabIndex = 4;
			this->teethLabel->Text = L"Teeth:";
			// 
			// pressureInput
			// 
			this->pressureInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->pressureInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pressureInput->Location = System::Drawing::Point(3, 106);
			this->pressureInput->Name = L"pressureInput";
			this->pressureInput->Size = System::Drawing::Size(188, 30);
			this->pressureInput->TabIndex = 3;
			this->pressureInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::pressureInput_KeyPress);
			// 
			// pressureLabel
			// 
			this->pressureLabel->AutoSize = true;
			this->pressureLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->pressureLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pressureLabel->Location = System::Drawing::Point(3, 81);
			this->pressureLabel->Name = L"pressureLabel";
			this->pressureLabel->Size = System::Drawing::Size(152, 25);
			this->pressureLabel->TabIndex = 2;
			this->pressureLabel->Text = L"Pressure Angle:";
			// 
			// pitchInput
			// 
			this->pitchInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->pitchInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pitchInput->Location = System::Drawing::Point(3, 51);
			this->pitchInput->Name = L"pitchInput";
			this->pitchInput->Size = System::Drawing::Size(188, 30);
			this->pitchInput->TabIndex = 1;
			this->pitchInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GearWorksGUI::pitchInput_KeyPress);
			// 
			// pitchLabel
			// 
			this->pitchLabel->AutoSize = true;
			this->pitchLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->pitchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pitchLabel->Location = System::Drawing::Point(3, 26);
			this->pitchLabel->Name = L"pitchLabel";
			this->pitchLabel->Size = System::Drawing::Size(61, 25);
			this->pitchLabel->TabIndex = 0;
			this->pitchLabel->Text = L"Pitch:";
			// 
			// unitsGroupBox
			// 
			this->unitsGroupBox->AutoSize = true;
			this->unitsGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->unitsGroupBox->Controls->Add(this->unitsComboBox);
			this->unitsGroupBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->unitsGroupBox->Location = System::Drawing::Point(0, 0);
			this->unitsGroupBox->Name = L"unitsGroupBox";
			this->unitsGroupBox->Size = System::Drawing::Size(194, 62);
			this->unitsGroupBox->TabIndex = 0;
			this->unitsGroupBox->TabStop = false;
			this->unitsGroupBox->Text = L"Units";
			// 
			// unitsComboBox
			// 
			this->unitsComboBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->unitsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->unitsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unitsComboBox->FormattingEnabled = true;
			this->unitsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inches", L"Millimeters" });
			this->unitsComboBox->Location = System::Drawing::Point(3, 26);
			this->unitsComboBox->Name = L"unitsComboBox";
			this->unitsComboBox->Size = System::Drawing::Size(188, 33);
			this->unitsComboBox->TabIndex = 0;
			// 
			// openGLPanel
			// 
			this->openGLPanel->BackColor = System::Drawing::Color::Gray;
			this->openGLPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->openGLPanel->Location = System::Drawing::Point(194, 0);
			this->openGLPanel->Name = L"openGLPanel";
			this->openGLPanel->Size = System::Drawing::Size(774, 673);
			this->openGLPanel->TabIndex = 1;
			this->openGLPanel->Visible = false;
			// 
			// visualizerControlPanel
			// 
			this->visualizerControlPanel->AutoSize = true;
			this->visualizerControlPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->visualizerControlPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->visualizerControlPanel->Location = System::Drawing::Point(194, 0);
			this->visualizerControlPanel->Name = L"visualizerControlPanel";
			this->visualizerControlPanel->Size = System::Drawing::Size(774, 0);
			this->visualizerControlPanel->TabIndex = 0;
			// 
			// exportButton
			// 
			this->exportButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->exportButton->Location = System::Drawing::Point(0, 634);
			this->exportButton->Name = L"exportButton";
			this->exportButton->Size = System::Drawing::Size(294, 39);
			this->exportButton->TabIndex = 0;
			this->exportButton->Text = L"Export";
			this->exportButton->UseVisualStyleBackColor = true;
			this->exportButton->Click += gcnew System::EventHandler(this, &GearWorksGUI::exportButton_Click);
			// 
			// gearListPanel
			// 
			this->gearListPanel->BackColor = System::Drawing::Color::Transparent;
			this->gearListPanel->Controls->Add(this->gearListScrollPanel);
			this->gearListPanel->Controls->Add(ExportBox);
			this->gearListPanel->Controls->Add(this->exportButton);
			this->gearListPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->gearListPanel->Location = System::Drawing::Point(968, 0);
			this->gearListPanel->MinimumSize = System::Drawing::Size(200, 0);
			this->gearListPanel->Name = L"gearListPanel";
			this->gearListPanel->Size = System::Drawing::Size(294, 673);
			this->gearListPanel->TabIndex = 3;
			// 
			// gearListScrollPanel
			// 
			this->gearListScrollPanel->AutoScroll = true;
			this->gearListScrollPanel->Controls->Add(this->gearListTable);
			this->gearListScrollPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearListScrollPanel->Location = System::Drawing::Point(0, 0);
			this->gearListScrollPanel->Name = L"gearListScrollPanel";
			this->gearListScrollPanel->Size = System::Drawing::Size(294, 495);
			this->gearListScrollPanel->TabIndex = 4;
			// 
			// gearListTable
			// 
			this->gearListTable->AutoSize = true;
			this->gearListTable->BackColor = System::Drawing::Color::Transparent;
			this->gearListTable->ColumnCount = 3;
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				211)));
			this->gearListTable->Controls->Add(this->gearTableCol1Label, 0, 0);
			this->gearListTable->Controls->Add(this->gearTableCol2Label, 1, 0);
			this->gearListTable->Controls->Add(this->gearTableCol3Label, 2, 0);
			this->gearListTable->Dock = System::Windows::Forms::DockStyle::Top;
			this->gearListTable->Location = System::Drawing::Point(0, 0);
			this->gearListTable->MaximumSize = System::Drawing::Size(500, 600);
			this->gearListTable->Name = L"gearListTable";
			this->gearListTable->RowCount = 2;
			this->gearListTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->gearListTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->gearListTable->Size = System::Drawing::Size(294, 72);
			this->gearListTable->TabIndex = 3;
			// 
			// gearTableCol1Label
			// 
			this->gearTableCol1Label->AutoSize = true;
			this->gearTableCol1Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearTableCol1Label->Location = System::Drawing::Point(3, 3);
			this->gearTableCol1Label->Margin = System::Windows::Forms::Padding(3);
			this->gearTableCol1Label->Name = L"gearTableCol1Label";
			this->gearTableCol1Label->Size = System::Drawing::Size(34, 30);
			this->gearTableCol1Label->TabIndex = 0;
			this->gearTableCol1Label->Text = L"#";
			this->gearTableCol1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gearTableCol2Label
			// 
			this->gearTableCol2Label->AutoSize = true;
			this->gearTableCol2Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearTableCol2Label->Location = System::Drawing::Point(43, 3);
			this->gearTableCol2Label->Margin = System::Windows::Forms::Padding(3);
			this->gearTableCol2Label->Name = L"gearTableCol2Label";
			this->gearTableCol2Label->Size = System::Drawing::Size(57, 30);
			this->gearTableCol2Label->TabIndex = 1;
			this->gearTableCol2Label->Text = L"QTY";
			this->gearTableCol2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gearTableCol3Label
			// 
			this->gearTableCol3Label->AutoEllipsis = true;
			this->gearTableCol3Label->AutoSize = true;
			this->gearTableCol3Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearTableCol3Label->Location = System::Drawing::Point(106, 3);
			this->gearTableCol3Label->Margin = System::Windows::Forms::Padding(3);
			this->gearTableCol3Label->Name = L"gearTableCol3Label";
			this->gearTableCol3Label->Size = System::Drawing::Size(205, 30);
			this->gearTableCol3Label->TabIndex = 2;
			this->gearTableCol3Label->Text = L"Gear Description";
			this->gearTableCol3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GearWorksGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->openGLPanel);
			this->Controls->Add(this->visualizerControlPanel);
			this->Controls->Add(this->gearListPanel);
			this->Controls->Add(this->gearParametersPanel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(1000, 480);
			this->Name = L"GearWorksGUI";
			this->Text = L"GearWorks";
			this->SizeChanged += gcnew System::EventHandler(this, &GearWorksGUI::GearWorksGUI_SizeChanged);
			ExportBox->ResumeLayout(false);
			ExportBox->PerformLayout();
			this->gearParametersPanel->ResumeLayout(false);
			this->gearParametersPanel->PerformLayout();
			this->hubGroupBox->ResumeLayout(false);
			this->hubGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hubPictureBox))->EndInit();
			this->gearGroupBox->ResumeLayout(false);
			this->gearGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teethInput))->EndInit();
			this->unitsGroupBox->ResumeLayout(false);
			this->gearListPanel->ResumeLayout(false);
			this->gearListPanel->PerformLayout();
			this->gearListScrollPanel->ResumeLayout(false);
			this->gearListScrollPanel->PerformLayout();
			this->gearListTable->ResumeLayout(false);
			this->gearListTable->PerformLayout();
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

	// Change label of 'pitch' for gear depending on unit system
	if (unitsComboBox->SelectedIndex == 0)
		pitchLabel->Text = L"Pitch:";
	else if (unitsComboBox->SelectedIndex == 1)
		pitchLabel->Text = L"Module:";

	// change hub picture depending on selection
	if (hubComboBox->SelectedIndex <= 0) {
		hubPictureBox->Hide();
		hubLabelA->Hide();
		hubLabelB->Hide();
		hubInputA->Hide();
		hubInputB->Hide();
	}
	else if (hubComboBox->SelectedIndex == 1) {
		hubPictureBox->Show();
		hubPictureBox->ImageLocation = "circleHub.png";
		hubLabelA->Text = L"Diameter:";
		hubLabelA->Show();
		hubLabelB->Hide();
		hubInputA->Show();
		hubInputB->Hide();
	}
	else if (hubComboBox->SelectedIndex == 2) {
		hubPictureBox->Show();
		hubPictureBox->ImageLocation = "rectangleHub.png";
		hubLabelA->Text = L"W:";
		hubLabelB->Text = L"H:";
		hubLabelA->Show();
		hubLabelB->Show();
		hubInputA->Show();
		hubInputB->Show();
	}

	// update ViewManager
	updateMaterial();

	}
private: System::Void addGearButton_Click(System::Object^ sender, System::EventArgs^ e) {

	// collect inputs from controls and prepare to pass to ViewManager
	double pitch = double::Parse(pitchInput->Text->ToString());
	double pressureAngle = double::Parse(pressureInput->Text->ToString());
	int teeth = int::Parse(teethInput->Text->ToString());

	// set hub input text boxes to zero if no input
	if (hubInputA->Text->Length == 0)
		hubInputA->Text = "0";
	if (hubInputB->Text->Length == 0)
		hubInputB->Text = "0";

	// get hub text box values
	double hubA = double::Parse(hubInputA->Text->ToString());
	double hubB = double::Parse(hubInputB->Text->ToString());
	
	// The initial qty is 1
	int qty = 1;

	int hubType = hubComboBox->SelectedIndex;
	HubShape thisHub;

	// set hub type and create gear in view manager
	if (hubType == 0) {
		thisHub = none;
		hubA = 0; hubB = 0;
	}
	else if (hubType == 1) {
		thisHub = circle;
		hubB = 0;
	}
	else if (hubType == 2) {
		thisHub = rectangle;
	}

	// create new gear in view manager
	int newGearCriteria = OpenGL->theManager->addGear(pitch, pressureAngle, teeth, qty, thisHub, hubA, hubB);


	//// delete controls
	//while (3 < gearListTable->Controls->Count)
	//	gearListTable->Controls->RemoveAt((gearListTable->Controls->Count) - 1);
	//gearQtys.Clear();

	// Add control 
	//int listLength = OpenGL->theManager->gearEntries();
	//for (int i = 0; i < listLength; i++){
	if (newGearCriteria == -1){
		int i = OpenGL->theManager->gearEntries() - 1;
		// entry number
		Label^ aLabel = gcnew Label();
		aLabel->AutoSize = true;
		aLabel->Dock = System::Windows::Forms::DockStyle::Fill;
		aLabel->Location = System::Drawing::Point(3, 3);
		aLabel->Margin = System::Windows::Forms::Padding(3);
		//aLabel->Size = System::Drawing::Size(34, 30);
		aLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		aLabel->Text = (i + 1).ToString();
		gearListTable->Controls->Add(aLabel, 0, i + 1);

		gearLabels.Add(aLabel);
		
		// qty box
		NumericUpDown^ aBox = gcnew NumericUpDown();
		aBox->AutoSize = true;
		aBox->Dock = System::Windows::Forms::DockStyle::Fill;
		aBox->Location = System::Drawing::Point(3, 3);
		aBox->Margin = System::Windows::Forms::Padding(3);
		//aBox->Size = System::Drawing::Size(34, 30);
		aBox->Value = OpenGL->theManager->getQTY(i);
		aBox->ValueChanged += gcnew System::EventHandler(this, &GearWorksGUI::qtyChange);
		gearListTable->Controls->Add(aBox, 1, i + 1);
		
		gearQtys.Add(aBox);

		// description box
		Label^ gearDescription = gcnew Label();
		gearDescription->Dock = System::Windows::Forms::DockStyle::Fill;
		gearDescription->Location = System::Drawing::Point(3, 3);
		gearDescription->Margin = System::Windows::Forms::Padding(3);
		gearDescription->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		String^ label = gcnew String((OpenGL->theManager->getLabel(i)).c_str());
		gearDescription->Text = label;
		gearDescription->AutoEllipsis = true;
		gearDescription->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GearWorksGUI::clickOnDescription);
		gearListTable->Controls->Add(gearDescription, 2, i + 1);
	}
	else {
		// if the gear already exists, just update the quantity
		gearQtys[newGearCriteria]->Value = OpenGL->theManager->getQTY(newGearCriteria);
	}
}

private: System::Void clickOnDescription(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	e->X;
	e->Y;
}

private: System::Void qtyChange(System::Object^ sender, System::EventArgs^ e) {
	// iterate through all the numericUpDown boxes and set in viewManager
	for (int i = 0; i < gearQtys.Count; i++) {
		OpenGL->theManager->setQTY(i, int::Parse((gearQtys[i]->Value).ToString()));
	}
}

private: System::Void exportButton_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();
}
private: System::Void pitchInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->pitchInput->Text->Contains(".") && !this->pitchInput->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void pressureInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->pressureInput->Text->Contains(".") && !this->pressureInput->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void hubInputA_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->hubInputA->Text->Contains(".") && !this->hubInputA->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void hubInputB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->hubInputB->Text->Contains(".") && !this->hubInputB->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void materialWidthInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->materialWidthInput->Text->Contains(".") && !this->materialWidthInput->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void materialHeightInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// https://stackoverflow.com/questions/24491883/visual-c-2010-only-allow-numbers-in-textbox
	if (e->KeyChar == '.') {
		if (this->materialHeightInput->Text->Contains(".") && !this->materialHeightInput->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits "." and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}

private: System::Void GearWorksGUI_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	updateMaterial();
}

private: System::Void updateMaterial() {
	// the openGl panel does not update size because it is not visible so the openGL area
	// is calculated using the other objects on the screen. -18 accounts for margins etc
	int width = this->Width - gearParametersPanel->Width - gearListScrollPanel->Width - 18;
	int height = gearParametersPanel->Height;// this->Height;

	double materialWidth = 0;
	double materialHeight = 0;

	if (materialWidthInput->TextLength != 0)
		materialWidth = double::Parse(materialWidthInput->Text->ToString());
	if (materialHeightInput->TextLength != 0)
		materialHeight = double::Parse(materialHeightInput->Text->ToString());


	OpenGL->theManager->defineMaterial(width, height, materialWidth, materialHeight);
	// Resize the open gl window
	OpenGL->ReSizeGLScene(width, height);
}

private: System::Void hubComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

