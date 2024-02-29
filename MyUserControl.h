#pragma once
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TTA_ui {

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	public:
		MyUserControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Panel^ panel12;
    protected:
    private: System::Windows::Forms::RadioButton^ radioButton10;
    private: System::Windows::Forms::RadioButton^ radioButton9;
    private: System::Windows::Forms::Label^ label46;
    private: System::Windows::Forms::TextBox^ textBox15;
    private: System::Windows::Forms::Label^ label47;
    private: System::Windows::Forms::Label^ label48;
    private: System::Windows::Forms::TextBox^ textBox16;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown5;
    private: System::Windows::Forms::Panel^ addsubjectpanel;
    private: System::Windows::Forms::Panel^ panel11;
    private: System::Windows::Forms::RadioButton^ radioButton8;
    private: System::Windows::Forms::RadioButton^ radioButton7;
    private: System::Windows::Forms::Button^ newaddsub;
    private: System::Windows::Forms::TextBox^ textBox13;
    private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
    private: System::Windows::Forms::Button^ addsubsave;
    private: System::Windows::Forms::NumericUpDown^ bfactorupdown;
    private: System::Windows::Forms::Label^ label41;
    private: System::Windows::Forms::Label^ label42;
    private: System::Windows::Forms::Label^ label43;
    private: System::Windows::Forms::DataGridView^ sldataGridView;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher_Name;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn4;
    private: System::Windows::Forms::Label^ label44;
    private: System::Windows::Forms::Label^ label45;
    private: System::Windows::Forms::Label^ label49;
    private: System::Windows::Forms::DataGridView^ sedataGridView;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ TeacherName;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;

    protected:























































	protected:

	protected:


















































































    protected:

	protected:


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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->textBox15 = (gcnew System::Windows::Forms::TextBox());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->textBox16 = (gcnew System::Windows::Forms::TextBox());
            this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
            this->addsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
            this->newaddsub = (gcnew System::Windows::Forms::Button());
            this->textBox13 = (gcnew System::Windows::Forms::TextBox());
            this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
            this->addsubsave = (gcnew System::Windows::Forms::Button());
            this->bfactorupdown = (gcnew System::Windows::Forms::NumericUpDown());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->sldataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->Teacher_Name = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->sedataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->panel12->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
            this->addsubjectpanel->SuspendLayout();
            this->panel11->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bfactorupdown))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sldataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // panel12
            // 
            this->panel12->Controls->Add(this->radioButton10);
            this->panel12->Controls->Add(this->radioButton9);
            this->panel12->ForeColor = System::Drawing::Color::Black;
            this->panel12->Location = System::Drawing::Point(347, 326);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(220, 56);
            this->panel12->TabIndex = 263;
            // 
            // radioButton10
            // 
            this->radioButton10->AutoSize = true;
            this->radioButton10->Location = System::Drawing::Point(5, 21);
            this->radioButton10->Name = L"radioButton10";
            this->radioButton10->Size = System::Drawing::Size(62, 24);
            this->radioButton10->TabIndex = 2;
            this->radioButton10->TabStop = true;
            this->radioButton10->Text = L"Yes";
            this->radioButton10->UseVisualStyleBackColor = true;
            // 
            // radioButton9
            // 
            this->radioButton9->AutoSize = true;
            this->radioButton9->Location = System::Drawing::Point(139, 21);
            this->radioButton9->Name = L"radioButton9";
            this->radioButton9->Size = System::Drawing::Size(54, 24);
            this->radioButton9->TabIndex = 3;
            this->radioButton9->TabStop = true;
            this->radioButton9->Text = L"No";
            this->radioButton9->UseVisualStyleBackColor = true;
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(318, 583);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(330, 28);
            this->label46->TabIndex = 235;
            this->label46->Text = L"Teacher handling the elective subject";
            // 
            // textBox15
            // 
            this->textBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox15->ForeColor = System::Drawing::Color::Black;
            this->textBox15->Location = System::Drawing::Point(323, 479);
            this->textBox15->Name = L"textBox15";
            this->textBox15->Size = System::Drawing::Size(482, 34);
            this->textBox15->TabIndex = 25;
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(319, 425);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(158, 28);
            this->label47->TabIndex = 24;
            this->label47->Text = L"Name of elective";
            // 
            // label48
            // 
            this->label48->AutoSize = true;
            this->label48->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(319, 274);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(148, 28);
            this->label48->TabIndex = 23;
            this->label48->Text = L"Is it an elective\?";
            // 
            // textBox16
            // 
            this->textBox16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox16->ForeColor = System::Drawing::Color::Black;
            this->textBox16->Location = System::Drawing::Point(330, 187);
            this->textBox16->Name = L"textBox16";
            this->textBox16->Size = System::Drawing::Size(480, 34);
            this->textBox16->TabIndex = 3;
            // 
            // numericUpDown5
            // 
            this->numericUpDown5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->numericUpDown5->Location = System::Drawing::Point(371, 1335);
            this->numericUpDown5->Name = L"numericUpDown5";
            this->numericUpDown5->Size = System::Drawing::Size(170, 34);
            this->numericUpDown5->TabIndex = 240;
            // 
            // addsubjectpanel
            // 
            this->addsubjectpanel->AutoScroll = true;
            this->addsubjectpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubjectpanel->Controls->Add(this->panel12);
            this->addsubjectpanel->Controls->Add(this->panel11);
            this->addsubjectpanel->Controls->Add(this->newaddsub);
            this->addsubjectpanel->Controls->Add(this->textBox13);
            this->addsubjectpanel->Controls->Add(this->checkedListBox2);
            this->addsubjectpanel->Controls->Add(this->label46);
            this->addsubjectpanel->Controls->Add(this->addsubsave);
            this->addsubjectpanel->Controls->Add(this->bfactorupdown);
            this->addsubjectpanel->Controls->Add(this->textBox15);
            this->addsubjectpanel->Controls->Add(this->label41);
            this->addsubjectpanel->Controls->Add(this->label47);
            this->addsubjectpanel->Controls->Add(this->label42);
            this->addsubjectpanel->Controls->Add(this->label48);
            this->addsubjectpanel->Controls->Add(this->label43);
            this->addsubjectpanel->Controls->Add(this->textBox16);
            this->addsubjectpanel->Controls->Add(this->numericUpDown5);
            this->addsubjectpanel->Controls->Add(this->sldataGridView);
            this->addsubjectpanel->Controls->Add(this->label44);
            this->addsubjectpanel->Controls->Add(this->label45);
            this->addsubjectpanel->Controls->Add(this->label49);
            this->addsubjectpanel->Controls->Add(this->sedataGridView);
            this->addsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->addsubjectpanel->Name = L"addsubjectpanel";
            this->addsubjectpanel->Size = System::Drawing::Size(1795, 1525);
            this->addsubjectpanel->TabIndex = 125;
            // 
            // panel11
            // 
            this->panel11->Controls->Add(this->radioButton8);
            this->panel11->Controls->Add(this->radioButton7);
            this->panel11->ForeColor = System::Drawing::Color::Black;
            this->panel11->Location = System::Drawing::Point(356, 911);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(219, 48);
            this->panel11->TabIndex = 262;
            // 
            // radioButton8
            // 
            this->radioButton8->AutoSize = true;
            this->radioButton8->Location = System::Drawing::Point(23, 14);
            this->radioButton8->Name = L"radioButton8";
            this->radioButton8->Size = System::Drawing::Size(62, 24);
            this->radioButton8->TabIndex = 10;
            this->radioButton8->TabStop = true;
            this->radioButton8->Text = L"Yes";
            this->radioButton8->UseVisualStyleBackColor = true;
            // 
            // radioButton7
            // 
            this->radioButton7->AutoSize = true;
            this->radioButton7->Location = System::Drawing::Point(148, 14);
            this->radioButton7->Name = L"radioButton7";
            this->radioButton7->Size = System::Drawing::Size(54, 24);
            this->radioButton7->TabIndex = 11;
            this->radioButton7->TabStop = true;
            this->radioButton7->Text = L"No";
            this->radioButton7->UseVisualStyleBackColor = true;
            // 
            // newaddsub
            // 
            this->newaddsub->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->newaddsub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newaddsub->Location = System::Drawing::Point(1211, 1836);
            this->newaddsub->Name = L"newaddsub";
            this->newaddsub->Size = System::Drawing::Size(116, 54);
            this->newaddsub->TabIndex = 247;
            this->newaddsub->Text = L" Add New";
            this->newaddsub->UseVisualStyleBackColor = false;
            // 
            // textBox13
            // 
            this->textBox13->Location = System::Drawing::Point(964, 276);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(154, 26);
            this->textBox13->TabIndex = 248;
            // 
            // checkedListBox2
            // 
            this->checkedListBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox2->CheckOnClick = true;
            this->checkedListBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->checkedListBox2->FormattingEnabled = true;
            this->checkedListBox2->Location = System::Drawing::Point(371, 1465);
            this->checkedListBox2->Name = L"checkedListBox2";
            this->checkedListBox2->Size = System::Drawing::Size(224, 186);
            this->checkedListBox2->Sorted = true;
            this->checkedListBox2->TabIndex = 246;
            this->checkedListBox2->ThreeDCheckBoxes = true;
            // 
            // addsubsave
            // 
            this->addsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubsave->Location = System::Drawing::Point(992, 1836);
            this->addsubsave->Name = L"addsubsave";
            this->addsubsave->Size = System::Drawing::Size(116, 54);
            this->addsubsave->TabIndex = 245;
            this->addsubsave->Text = L"Save";
            this->addsubsave->UseVisualStyleBackColor = false;
            // 
            // bfactorupdown
            // 
            this->bfactorupdown->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->bfactorupdown->DecimalPlaces = 2;
            this->bfactorupdown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->bfactorupdown->Location = System::Drawing::Point(370, 1717);
            this->bfactorupdown->Name = L"bfactorupdown";
            this->bfactorupdown->Size = System::Drawing::Size(170, 34);
            this->bfactorupdown->TabIndex = 244;
            // 
            // label41
            // 
            this->label41->AutoSize = true;
            this->label41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label41->Location = System::Drawing::Point(362, 1419);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(255, 28);
            this->label41->TabIndex = 242;
            this->label41->Text = L"Rooms to be used(optional)";
            // 
            // label42
            // 
            this->label42->AutoSize = true;
            this->label42->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label42->Location = System::Drawing::Point(379, 1663);
            this->label42->Name = L"label42";
            this->label42->Size = System::Drawing::Size(75, 28);
            this->label42->TabIndex = 243;
            this->label42->Text = L"bfactor";
            // 
            // label43
            // 
            this->label43->AutoSize = true;
            this->label43->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label43->Location = System::Drawing::Point(368, 1291);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(125, 28);
            this->label43->TabIndex = 241;
            this->label43->Text = L"No of credits";
            // 
            // sldataGridView
            // 
            this->sldataGridView->AllowUserToOrderColumns = true;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
            this->sldataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this->sldataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sldataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->sldataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->sldataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sldataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->sldataGridView->ColumnHeadersHeight = 40;
            this->sldataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sldataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->Teacher_Name,
                    this->dataGridViewButtonColumn4
            });
            dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle5->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->sldataGridView->DefaultCellStyle = dataGridViewCellStyle5;
            this->sldataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sldataGridView->Location = System::Drawing::Point(373, 1043);
            this->sldataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->sldataGridView->Name = L"sldataGridView";
            dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sldataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this->sldataGridView->RowHeadersVisible = false;
            this->sldataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
            this->sldataGridView->RowsDefaultCellStyle = dataGridViewCellStyle7;
            this->sldataGridView->RowTemplate->Height = 28;
            this->sldataGridView->Size = System::Drawing::Size(735, 226);
            this->sldataGridView->TabIndex = 239;
            // 
            // Teacher_Name
            // 
            dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Teacher_Name->DefaultCellStyle = dataGridViewCellStyle3;
            this->Teacher_Name->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Teacher_Name->HeaderText = L"Teacher Name";
            this->Teacher_Name->MinimumWidth = 30;
            this->Teacher_Name->Name = L"Teacher_Name";
            this->Teacher_Name->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->Teacher_Name->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
            this->Teacher_Name->Width = 350;
            // 
            // dataGridViewButtonColumn4
            // 
            this->dataGridViewButtonColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn4->DefaultCellStyle = dataGridViewCellStyle4;
            this->dataGridViewButtonColumn4->DividerWidth = 1;
            this->dataGridViewButtonColumn4->HeaderText = L"";
            this->dataGridViewButtonColumn4->MinimumWidth = 100;
            this->dataGridViewButtonColumn4->Name = L"dataGridViewButtonColumn4";
            this->dataGridViewButtonColumn4->ReadOnly = true;
            this->dataGridViewButtonColumn4->Text = L"Delete";
            this->dataGridViewButtonColumn4->UseColumnTextForButtonValue = true;
            // 
            // label44
            // 
            this->label44->AutoSize = true;
            this->label44->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label44->Location = System::Drawing::Point(337, 1003);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(299, 28);
            this->label44->TabIndex = 238;
            this->label44->Text = L"Teachers handling the lab subject";
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label45->Location = System::Drawing::Point(336, 866);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(98, 28);
            this->label45->TabIndex = 236;
            this->label45->Text = L"Is it a lab\?";
            // 
            // label49
            // 
            this->label49->AutoSize = true;
            this->label49->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label49->ForeColor = System::Drawing::Color::Black;
            this->label49->Location = System::Drawing::Point(325, 137);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(134, 28);
            this->label49->TabIndex = 2;
            this->label49->Text = L"Subject Name";
            // 
            // sedataGridView
            // 
            this->sedataGridView->AllowUserToOrderColumns = true;
            dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle8->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle8;
            this->sedataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->sedataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->sedataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sedataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
            this->sedataGridView->ColumnHeadersHeight = 40;
            this->sedataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sedataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->TeacherName,
                    this->dataGridViewButtonColumn5
            });
            dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle12->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle12->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->sedataGridView->DefaultCellStyle = dataGridViewCellStyle12;
            this->sedataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->Location = System::Drawing::Point(335, 637);
            this->sedataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->sedataGridView->Name = L"sedataGridView";
            dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle13->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle13->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle13->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle13->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sedataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle13;
            this->sedataGridView->RowHeadersVisible = false;
            this->sedataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle14->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->RowsDefaultCellStyle = dataGridViewCellStyle14;
            this->sedataGridView->RowTemplate->Height = 28;
            this->sedataGridView->Size = System::Drawing::Size(735, 226);
            this->sedataGridView->TabIndex = 234;
            // 
            // TeacherName
            // 
            dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle10->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle10->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->TeacherName->DefaultCellStyle = dataGridViewCellStyle10;
            this->TeacherName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->TeacherName->HeaderText = L"Teacher Name";
            this->TeacherName->MinimumWidth = 30;
            this->TeacherName->Name = L"TeacherName";
            this->TeacherName->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->TeacherName->Width = 350;
            // 
            // dataGridViewButtonColumn5
            // 
            this->dataGridViewButtonColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle11->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle11->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn5->DefaultCellStyle = dataGridViewCellStyle11;
            this->dataGridViewButtonColumn5->DividerWidth = 1;
            this->dataGridViewButtonColumn5->HeaderText = L"";
            this->dataGridViewButtonColumn5->MinimumWidth = 100;
            this->dataGridViewButtonColumn5->Name = L"dataGridViewButtonColumn5";
            this->dataGridViewButtonColumn5->ReadOnly = true;
            this->dataGridViewButtonColumn5->Text = L"Delete";
            this->dataGridViewButtonColumn5->UseColumnTextForButtonValue = true;
            // 
            // MyUserControl
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->Controls->Add(this->addsubjectpanel);
            this->Name = L"MyUserControl";
            this->Size = System::Drawing::Size(1795, 1525);
            this->Load += gcnew System::EventHandler(this, &MyUserControl::MyUserControl_Load);
            this->panel12->ResumeLayout(false);
            this->panel12->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
            this->addsubjectpanel->ResumeLayout(false);
            this->addsubjectpanel->PerformLayout();
            this->panel11->ResumeLayout(false);
            this->panel11->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bfactorupdown))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sldataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion


private: System::Void MyUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
