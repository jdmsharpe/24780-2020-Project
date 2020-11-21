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
		
		}
	private: System::Windows::Forms::TableLayoutPanel^ designerLayoutTable;
	public:
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
	private: System::Windows::Forms::Panel^ visualizerPanel;
	private: System::Windows::Forms::Panel^ openGLPanel;
	private: System::Windows::Forms::Panel^ visualizerControlPanel;
	private: System::Windows::Forms::Button^ exportButton;
	private: System::Windows::Forms::Panel^ gearListPanel;
	private: System::Windows::Forms::TableLayoutPanel^ gearListTable;
	private: System::Windows::Forms::Label^ gearTableCol1Label;
	private: System::Windows::Forms::Label^ gearTableCol2Label;
	private: System::Windows::Forms::Label^ gearTableCol3Label;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


	// temporary
	int gearNum = 0;

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
	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::TabPage^ designerTab;
	private: System::Windows::Forms::TabPage^ layoutTab;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GearWorksGUI::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->designerTab = (gcnew System::Windows::Forms::TabPage());
			this->designerLayoutTable = (gcnew System::Windows::Forms::TableLayoutPanel());
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
			this->visualizerPanel = (gcnew System::Windows::Forms::Panel());
			this->openGLPanel = (gcnew System::Windows::Forms::Panel());
			this->visualizerControlPanel = (gcnew System::Windows::Forms::Panel());
			this->exportButton = (gcnew System::Windows::Forms::Button());
			this->gearListPanel = (gcnew System::Windows::Forms::Panel());
			this->gearListTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->gearTableCol1Label = (gcnew System::Windows::Forms::Label());
			this->layoutTab = (gcnew System::Windows::Forms::TabPage());
			this->gearTableCol2Label = (gcnew System::Windows::Forms::Label());
			this->gearTableCol3Label = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl->SuspendLayout();
			this->designerTab->SuspendLayout();
			this->designerLayoutTable->SuspendLayout();
			this->gearParametersPanel->SuspendLayout();
			this->hubGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hubPictureBox))->BeginInit();
			this->gearGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teethInput))->BeginInit();
			this->unitsGroupBox->SuspendLayout();
			this->visualizerPanel->SuspendLayout();
			this->visualizerControlPanel->SuspendLayout();
			this->gearListPanel->SuspendLayout();
			this->gearListTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &GearWorksGUI::timer1_Tick);
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->designerTab);
			this->tabControl->Controls->Add(this->layoutTab);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(1262, 673);
			this->tabControl->TabIndex = 0;
			// 
			// designerTab
			// 
			this->designerTab->Controls->Add(this->designerLayoutTable);
			this->designerTab->Location = System::Drawing::Point(4, 34);
			this->designerTab->Name = L"designerTab";
			this->designerTab->Padding = System::Windows::Forms::Padding(3);
			this->designerTab->Size = System::Drawing::Size(1254, 635);
			this->designerTab->TabIndex = 0;
			this->designerTab->Text = L"Designer";
			this->designerTab->UseVisualStyleBackColor = true;
			// 
			// designerLayoutTable
			// 
			this->designerLayoutTable->ColumnCount = 3;
			this->designerLayoutTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				200)));
			this->designerLayoutTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->designerLayoutTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				300)));
			this->designerLayoutTable->Controls->Add(this->gearParametersPanel, 0, 0);
			this->designerLayoutTable->Controls->Add(this->visualizerPanel, 1, 0);
			this->designerLayoutTable->Controls->Add(this->gearListPanel, 2, 0);
			this->designerLayoutTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->designerLayoutTable->Location = System::Drawing::Point(3, 3);
			this->designerLayoutTable->Name = L"designerLayoutTable";
			this->designerLayoutTable->RowCount = 1;
			this->designerLayoutTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->designerLayoutTable->Size = System::Drawing::Size(1248, 629);
			this->designerLayoutTable->TabIndex = 0;
			this->designerLayoutTable->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GearWorksGUI::tableLayoutPanel1_Paint);
			// 
			// gearParametersPanel
			// 
			this->gearParametersPanel->AutoScroll = true;
			this->gearParametersPanel->Controls->Add(this->addGearButton);
			this->gearParametersPanel->Controls->Add(this->hubGroupBox);
			this->gearParametersPanel->Controls->Add(this->gearGroupBox);
			this->gearParametersPanel->Controls->Add(this->unitsGroupBox);
			this->gearParametersPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearParametersPanel->Location = System::Drawing::Point(3, 3);
			this->gearParametersPanel->Name = L"gearParametersPanel";
			this->gearParametersPanel->Size = System::Drawing::Size(194, 623);
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
			this->hubInputB->Location = System::Drawing::Point(3, 250);
			this->hubInputB->Name = L"hubInputB";
			this->hubInputB->Size = System::Drawing::Size(188, 30);
			this->hubInputB->TabIndex = 5;
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
			this->hubInputA->Location = System::Drawing::Point(3, 195);
			this->hubInputA->Name = L"hubInputA";
			this->hubInputA->Size = System::Drawing::Size(188, 30);
			this->hubInputA->TabIndex = 3;
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
			this->unitsGroupBox->Text = L"Unit System";
			this->unitsGroupBox->Enter += gcnew System::EventHandler(this, &GearWorksGUI::unitsGroupBox_Enter);
			// 
			// unitsComboBox
			// 
			this->unitsComboBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->unitsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->unitsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unitsComboBox->FormattingEnabled = true;
			this->unitsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"English", L"Metric" });
			this->unitsComboBox->Location = System::Drawing::Point(3, 26);
			this->unitsComboBox->Name = L"unitsComboBox";
			this->unitsComboBox->Size = System::Drawing::Size(188, 33);
			this->unitsComboBox->TabIndex = 0;
			this->unitsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GearWorksGUI::unitsComboBox_SelectedIndexChanged);
			// 
			// visualizerPanel
			// 
			this->visualizerPanel->Controls->Add(this->openGLPanel);
			this->visualizerPanel->Controls->Add(this->visualizerControlPanel);
			this->visualizerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->visualizerPanel->Location = System::Drawing::Point(203, 3);
			this->visualizerPanel->Name = L"visualizerPanel";
			this->visualizerPanel->Size = System::Drawing::Size(742, 623);
			this->visualizerPanel->TabIndex = 2;
			// 
			// openGLPanel
			// 
			this->openGLPanel->BackColor = System::Drawing::Color::Gray;
			this->openGLPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->openGLPanel->Location = System::Drawing::Point(0, 45);
			this->openGLPanel->Name = L"openGLPanel";
			this->openGLPanel->Size = System::Drawing::Size(742, 578);
			this->openGLPanel->TabIndex = 1;
			// 
			// visualizerControlPanel
			// 
			this->visualizerControlPanel->AutoSize = true;
			this->visualizerControlPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->visualizerControlPanel->Controls->Add(this->exportButton);
			this->visualizerControlPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->visualizerControlPanel->Location = System::Drawing::Point(0, 0);
			this->visualizerControlPanel->Name = L"visualizerControlPanel";
			this->visualizerControlPanel->Size = System::Drawing::Size(742, 45);
			this->visualizerControlPanel->TabIndex = 0;
			// 
			// exportButton
			// 
			this->exportButton->Location = System::Drawing::Point(3, 3);
			this->exportButton->Name = L"exportButton";
			this->exportButton->Size = System::Drawing::Size(103, 39);
			this->exportButton->TabIndex = 0;
			this->exportButton->Text = L"Export";
			this->exportButton->UseVisualStyleBackColor = true;
			this->exportButton->Click += gcnew System::EventHandler(this, &GearWorksGUI::exportButton_Click);
			// 
			// gearListPanel
			// 
			this->gearListPanel->AutoScroll = true;
			this->gearListPanel->Controls->Add(this->gearListTable);
			this->gearListPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearListPanel->Location = System::Drawing::Point(951, 3);
			this->gearListPanel->Name = L"gearListPanel";
			this->gearListPanel->Size = System::Drawing::Size(294, 623);
			this->gearListPanel->TabIndex = 3;
			// 
			// gearListTable
			// 
			this->gearListTable->AutoSize = true;
			this->gearListTable->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->gearListTable->ColumnCount = 3;
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->gearListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->gearListTable->Controls->Add(this->gearTableCol1Label, 0, 0);
			this->gearListTable->Controls->Add(this->gearTableCol2Label, 1, 0);
			this->gearListTable->Controls->Add(this->gearTableCol3Label, 2, 0);
			this->gearListTable->Dock = System::Windows::Forms::DockStyle::Top;
			this->gearListTable->Location = System::Drawing::Point(0, 0);
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
			// layoutTab
			// 
			this->layoutTab->Location = System::Drawing::Point(4, 34);
			this->layoutTab->Name = L"layoutTab";
			this->layoutTab->Padding = System::Windows::Forms::Padding(3);
			this->layoutTab->Size = System::Drawing::Size(1254, 635);
			this->layoutTab->TabIndex = 1;
			this->layoutTab->Text = L"Layout";
			this->layoutTab->UseVisualStyleBackColor = true;
			// 
			// gearTableCol2Label
			// 
			this->gearTableCol2Label->AutoSize = true;
			this->gearTableCol2Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearTableCol2Label->Location = System::Drawing::Point(43, 3);
			this->gearTableCol2Label->Margin = System::Windows::Forms::Padding(3);
			this->gearTableCol2Label->Name = L"gearTableCol2Label";
			this->gearTableCol2Label->Size = System::Drawing::Size(64, 30);
			this->gearTableCol2Label->TabIndex = 1;
			this->gearTableCol2Label->Text = L"QTY";
			// 
			// gearTableCol3Label
			// 
			this->gearTableCol3Label->AutoSize = true;
			this->gearTableCol3Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gearTableCol3Label->Location = System::Drawing::Point(113, 3);
			this->gearTableCol3Label->Margin = System::Windows::Forms::Padding(3);
			this->gearTableCol3Label->Name = L"gearTableCol3Label";
			this->gearTableCol3Label->Size = System::Drawing::Size(178, 30);
			this->gearTableCol3Label->TabIndex = 2;
			this->gearTableCol3Label->Text = L"Gear Description";
			// 
			// GearWorksGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->tabControl);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MinimumSize = System::Drawing::Size(1000, 480);
			this->Name = L"GearWorksGUI";
			this->Text = L"GearWorks";
			this->tabControl->ResumeLayout(false);
			this->designerTab->ResumeLayout(false);
			this->designerLayoutTable->ResumeLayout(false);
			this->gearParametersPanel->ResumeLayout(false);
			this->gearParametersPanel->PerformLayout();
			this->hubGroupBox->ResumeLayout(false);
			this->hubGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hubPictureBox))->EndInit();
			this->gearGroupBox->ResumeLayout(false);
			this->gearGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teethInput))->EndInit();
			this->unitsGroupBox->ResumeLayout(false);
			this->visualizerPanel->ResumeLayout(false);
			this->visualizerPanel->PerformLayout();
			this->visualizerControlPanel->ResumeLayout(false);
			this->gearListPanel->ResumeLayout(false);
			this->gearListPanel->PerformLayout();
			this->gearListTable->ResumeLayout(false);
			this->gearListTable->PerformLayout();
			this->ResumeLayout(false);

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

	}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void unitsGroupBox_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void unitsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void hubComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void addGearButton_Click(System::Object^ sender, System::EventArgs^ e) {
	gearNum++;

	// populate the 'gear table'
	Label^ aLabel = gcnew Label();
	aLabel->AutoSize = true;
	aLabel->Dock = System::Windows::Forms::DockStyle::Fill;
	aLabel->Location = System::Drawing::Point(3, 3);
	aLabel->Margin = System::Windows::Forms::Padding(3);
	aLabel->Size = System::Drawing::Size(34, 30);
	aLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	aLabel->Text = gearNum.ToString();
	gearListTable->Controls->Add(aLabel, 0, gearNum);

	// qty for each gear
	NumericUpDown^ aBox = gcnew NumericUpDown();
	aBox->AutoSize = true;
	aBox->Dock = System::Windows::Forms::DockStyle::Fill;
	aBox->Location = System::Drawing::Point(3, 3);
	aBox->Margin = System::Windows::Forms::Padding(3);
	aBox->Size = System::Drawing::Size(34, 30);
	aBox->Value = 1;
	gearListTable->Controls->Add(aBox, 1, gearNum);

	// description for each gear
	String^ output;
	if (unitsComboBox->SelectedIndex == 0)
		output = "P: ";
	else
		output = "M: ";
	output += pitchInput->Text->ToString();
	output += ", A: ";
	output += pressureInput->Text->ToString();
	output += ", T: ";
	output += teethInput->Text->ToString();
	output += ", Hub: ";
	output += hubComboBox->SelectedText->ToString();

	Label^ gearDescription = gcnew Label();
	gearDescription->AutoSize = true;
	gearDescription->Dock = System::Windows::Forms::DockStyle::Fill;
	gearDescription->Location = System::Drawing::Point(3, 3);
	gearDescription->Margin = System::Windows::Forms::Padding(3);
	gearDescription->Size = System::Drawing::Size(34, 30);
	gearDescription->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	gearDescription->Text = output;
	gearListTable->Controls->Add(gearDescription, 2, gearNum);
}
private: System::Void exportButton_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->ShowDialog();
}
};
}

