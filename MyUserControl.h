#pragma once

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
	private: System::Windows::Forms::Panel^ panel1;




    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::CheckedListBox^ checkedListBox1;




    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;



    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::DataGridView^ dataGridView5;


    private: System::Windows::Forms::DataGridView^ dataGridView2;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn2;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ SubjectName;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;
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
            System::Windows::Forms::Panel^ panel3;
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->SubjectName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->Teacher = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            panel3 = (gcnew System::Windows::Forms::Panel());
            this->panel1->SuspendLayout();
            panel3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            this->SuspendLayout();
            // 
            // panel1
            // 
            this->panel1->Controls->Add(panel3);
            this->panel1->Location = System::Drawing::Point(40, -99);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(1654, 1735);
            this->panel1->TabIndex = 0;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(266, 587);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(520, 84);
            this->label4->TabIndex = 7;
            this->label4->Text = L"Select the subjects taught and their corresponding teacher\r\n\r\n for non-elective a"
                L"nd non-lab subjects";
            // 
            // maskedTextBox1
            // 
            this->maskedTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox1->Location = System::Drawing::Point(272, 521);
            this->maskedTextBox1->Mask = L"0000";
            this->maskedTextBox1->Name = L"maskedTextBox1";
            this->maskedTextBox1->Size = System::Drawing::Size(401, 34);
            this->maskedTextBox1->TabIndex = 5;
            this->maskedTextBox1->ValidatingType = System::Int32::typeid;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(266, 464);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(225, 28);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Batch(year of admission)";
            // 
            // comboBox1
            // 
            this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(272, 389);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(269, 36);
            this->comboBox1->TabIndex = 9;
            // 
            // maskedTextBox2
            // 
            this->maskedTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox2->Location = System::Drawing::Point(268, 259);
            this->maskedTextBox2->Mask = L"A";
            this->maskedTextBox2->Name = L"maskedTextBox2";
            this->maskedTextBox2->Size = System::Drawing::Size(434, 34);
            this->maskedTextBox2->TabIndex = 8;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(262, 195);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(77, 28);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Section";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label5->Location = System::Drawing::Point(267, 913);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(160, 28);
            this->label5->TabIndex = 31;
            this->label5->Text = L"Elective subjects";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(267, 1212);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(124, 28);
            this->label6->TabIndex = 32;
            this->label6->Text = L"Lab subjects";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(266, 328);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(71, 28);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Branch";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(1016, 1829);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(132, 44);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Add New";
            this->button1->UseVisualStyleBackColor = false;
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(854, 1829);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(104, 44);
            this->button3->TabIndex = 12;
            this->button3->Text = L"Save";
            this->button3->UseVisualStyleBackColor = false;
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button4->Location = System::Drawing::Point(660, 1829);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(147, 44);
            this->button4->TabIndex = 26;
            this->button4->Text = L"Generate";
            this->button4->UseVisualStyleBackColor = false;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label7->Location = System::Drawing::Point(278, 1588);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(142, 28);
            this->label7->TabIndex = 34;
            this->label7->Text = L"Default rooms";
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Location = System::Drawing::Point(271, 1630);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(287, 155);
            this->checkedListBox1->TabIndex = 33;
            // 
            // panel3
            // 
            panel3->AutoScroll = true;
            panel3->Controls->Add(this->label9);
            panel3->Controls->Add(this->label8);
            panel3->Controls->Add(this->dataGridView2);
            panel3->Controls->Add(this->dataGridView1);
            panel3->Controls->Add(this->dataGridView5);
            panel3->Controls->Add(this->button1);
            panel3->Controls->Add(this->button3);
            panel3->Controls->Add(this->button4);
            panel3->Controls->Add(this->label7);
            panel3->Controls->Add(this->checkedListBox1);
            panel3->Controls->Add(this->label5);
            panel3->Controls->Add(this->label6);
            panel3->Controls->Add(this->label4);
            panel3->Controls->Add(this->maskedTextBox1);
            panel3->Controls->Add(this->label2);
            panel3->Controls->Add(this->comboBox1);
            panel3->Controls->Add(this->maskedTextBox2);
            panel3->Controls->Add(this->label3);
            panel3->Controls->Add(this->label1);
            panel3->Dock = System::Windows::Forms::DockStyle::Fill;
            panel3->Location = System::Drawing::Point(0, 0);
            panel3->Name = L"panel3";
            panel3->Size = System::Drawing::Size(1654, 1735);
            panel3->TabIndex = 18;
            // 
            // dataGridView5
            // 
            this->dataGridView5->AllowUserToOrderColumns = true;
            dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView5->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle15;
            this->dataGridView5->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView5->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView5->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView5->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle16;
            this->dataGridView5->ColumnHeadersHeight = 40;
            this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->SubjectName,
                    this->Teacher, this->dataGridViewButtonColumn5
            });
            dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle20->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView5->DefaultCellStyle = dataGridViewCellStyle20;
            this->dataGridView5->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView5->Location = System::Drawing::Point(272, 715);
            this->dataGridView5->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView5->Name = L"dataGridView5";
            dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView5->RowHeadersDefaultCellStyle = dataGridViewCellStyle21;
            this->dataGridView5->RowHeadersVisible = false;
            this->dataGridView5->RowHeadersWidth = 62;
            dataGridViewCellStyle22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView5->RowsDefaultCellStyle = dataGridViewCellStyle22;
            this->dataGridView5->RowTemplate->Height = 28;
            this->dataGridView5->Size = System::Drawing::Size(735, 226);
            this->dataGridView5->TabIndex = 235;
            this->dataGridView5->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyUserControl::dataGridView5_CellContentClick);
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToOrderColumns = true;
            dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle8->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle8;
            this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
            this->dataGridView1->ColumnHeadersHeight = 40;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn1,
                    this->dataGridViewButtonColumn1
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
            this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle12;
            this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->Location = System::Drawing::Point(268, 1014);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle13->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle13->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle13->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle13->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle13;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 62;
            dataGridViewCellStyle14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle14->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle14;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(735, 226);
            this->dataGridView1->TabIndex = 236;
            // 
            // dataGridViewComboBoxColumn1
            // 
            dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle10->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle10->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->DefaultCellStyle = dataGridViewCellStyle10;
            this->dataGridViewComboBoxColumn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn1->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn1->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn1->Name = L"dataGridViewComboBoxColumn1";
            this->dataGridViewComboBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle11->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle11->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle11;
            this->dataGridViewButtonColumn1->DividerWidth = 1;
            this->dataGridViewButtonColumn1->HeaderText = L"";
            this->dataGridViewButtonColumn1->MinimumWidth = 100;
            this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
            this->dataGridViewButtonColumn1->ReadOnly = true;
            this->dataGridViewButtonColumn1->Text = L"Delete";
            this->dataGridViewButtonColumn1->UseColumnTextForButtonValue = true;
            // 
            // dataGridView2
            // 
            this->dataGridView2->AllowUserToOrderColumns = true;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->dataGridView2->ColumnHeadersHeight = 40;
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn2,
                    this->dataGridViewButtonColumn2
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
            this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle5;
            this->dataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->Location = System::Drawing::Point(252, 1352);
            this->dataGridView2->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView2->Name = L"dataGridView2";
            dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this->dataGridView2->RowHeadersVisible = false;
            this->dataGridView2->RowHeadersWidth = 62;
            dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->RowsDefaultCellStyle = dataGridViewCellStyle7;
            this->dataGridView2->RowTemplate->Height = 28;
            this->dataGridView2->Size = System::Drawing::Size(735, 226);
            this->dataGridView2->TabIndex = 237;
            // 
            // dataGridViewComboBoxColumn2
            // 
            dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn2->DefaultCellStyle = dataGridViewCellStyle3;
            this->dataGridViewComboBoxColumn2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn2->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn2->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn2->Name = L"dataGridViewComboBoxColumn2";
            this->dataGridViewComboBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn2->Width = 350;
            // 
            // dataGridViewButtonColumn2
            // 
            this->dataGridViewButtonColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle4;
            this->dataGridViewButtonColumn2->DividerWidth = 1;
            this->dataGridViewButtonColumn2->HeaderText = L"";
            this->dataGridViewButtonColumn2->MinimumWidth = 100;
            this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
            this->dataGridViewButtonColumn2->ReadOnly = true;
            this->dataGridViewButtonColumn2->Text = L"Delete";
            this->dataGridViewButtonColumn2->UseColumnTextForButtonValue = true;
            // 
            // SubjectName
            // 
            dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle17->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->SubjectName->DefaultCellStyle = dataGridViewCellStyle17;
            this->SubjectName->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->SubjectName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->SubjectName->HeaderText = L"Teacher Name";
            this->SubjectName->MinimumWidth = 30;
            this->SubjectName->Name = L"SubjectName";
            this->SubjectName->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->SubjectName->Width = 350;
            // 
            // Teacher
            // 
            dataGridViewCellStyle18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
            this->Teacher->DefaultCellStyle = dataGridViewCellStyle18;
            this->Teacher->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->Teacher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Teacher->HeaderText = L"Teacher";
            this->Teacher->MinimumWidth = 8;
            this->Teacher->Name = L"Teacher";
            this->Teacher->Width = 150;
            // 
            // dataGridViewButtonColumn5
            // 
            this->dataGridViewButtonColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn5->DefaultCellStyle = dataGridViewCellStyle19;
            this->dataGridViewButtonColumn5->DividerWidth = 1;
            this->dataGridViewButtonColumn5->HeaderText = L"";
            this->dataGridViewButtonColumn5->MinimumWidth = 100;
            this->dataGridViewButtonColumn5->Name = L"dataGridViewButtonColumn5";
            this->dataGridViewButtonColumn5->ReadOnly = true;
            this->dataGridViewButtonColumn5->Text = L"Delete";
            this->dataGridViewButtonColumn5->UseColumnTextForButtonValue = true;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(267, 969);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(153, 28);
            this->label8->TabIndex = 238;
            this->label8->Text = L"Elective subjects";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(291, 1299);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(118, 28);
            this->label9->TabIndex = 239;
            this->label9->Text = L"Lab subjects";
            // 
            // MyUserControl
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Controls->Add(this->panel1);
            this->Name = L"MyUserControl";
            this->Size = System::Drawing::Size(1821, 1525);
            this->panel1->ResumeLayout(false);
            panel3->ResumeLayout(false);
            panel3->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void dataGridView5_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
