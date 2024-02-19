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
    private: System::Windows::Forms::Label^ label50;
    protected:
    private: System::Windows::Forms::Label^ label40;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Button^ buttons35;
    private: System::Windows::Forms::Button^ buttons34;
    private: System::Windows::Forms::Button^ buttons33;
    private: System::Windows::Forms::Button^ buttons32;
    private: System::Windows::Forms::Button^ buttons31;
    private: System::Windows::Forms::Button^ buttons29;
    private: System::Windows::Forms::Button^ buttons28;
    private: System::Windows::Forms::Button^ buttons27;
    private: System::Windows::Forms::Button^ buttons26;
    private: System::Windows::Forms::Button^ buttons25;
    private: System::Windows::Forms::Button^ buttons24;
    private: System::Windows::Forms::Button^ buttons23;
    private: System::Windows::Forms::Button^ buttons22;
    private: System::Windows::Forms::Button^ buttons21;
    private: System::Windows::Forms::Button^ buttons20;
    private: System::Windows::Forms::Button^ buttons19;
    private: System::Windows::Forms::Button^ buttons18;
    private: System::Windows::Forms::Button^ buttons17;
    private: System::Windows::Forms::Button^ buttons16;
    private: System::Windows::Forms::Button^ buttons15;
    private: System::Windows::Forms::Button^ buttons14;
    private: System::Windows::Forms::Button^ buttons13;
    private: System::Windows::Forms::Button^ buttons12;
    private: System::Windows::Forms::Button^ buttons11;
    private: System::Windows::Forms::Button^ buttons10;
    private: System::Windows::Forms::Button^ buttons9;
    private: System::Windows::Forms::Button^ buttons8;
    private: System::Windows::Forms::Button^ buttons7;
    private: System::Windows::Forms::Button^ buttons6;
    private: System::Windows::Forms::Button^ buttons5;
    private: System::Windows::Forms::Button^ buttons4;
    private: System::Windows::Forms::Button^ buttons3;
    private: System::Windows::Forms::Button^ buttons2;
    private: System::Windows::Forms::Button^ buttons1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Button^ button37;
    private: System::Windows::Forms::Button^ button38;
    private: System::Windows::Forms::Button^ buttons30;
    private: System::Windows::Forms::Button^ buttons36;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label14;

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
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->buttons35 = (gcnew System::Windows::Forms::Button());
            this->buttons34 = (gcnew System::Windows::Forms::Button());
            this->buttons33 = (gcnew System::Windows::Forms::Button());
            this->buttons32 = (gcnew System::Windows::Forms::Button());
            this->buttons31 = (gcnew System::Windows::Forms::Button());
            this->buttons29 = (gcnew System::Windows::Forms::Button());
            this->buttons28 = (gcnew System::Windows::Forms::Button());
            this->buttons27 = (gcnew System::Windows::Forms::Button());
            this->buttons26 = (gcnew System::Windows::Forms::Button());
            this->buttons25 = (gcnew System::Windows::Forms::Button());
            this->buttons24 = (gcnew System::Windows::Forms::Button());
            this->buttons23 = (gcnew System::Windows::Forms::Button());
            this->buttons22 = (gcnew System::Windows::Forms::Button());
            this->buttons21 = (gcnew System::Windows::Forms::Button());
            this->buttons20 = (gcnew System::Windows::Forms::Button());
            this->buttons19 = (gcnew System::Windows::Forms::Button());
            this->buttons18 = (gcnew System::Windows::Forms::Button());
            this->buttons17 = (gcnew System::Windows::Forms::Button());
            this->buttons16 = (gcnew System::Windows::Forms::Button());
            this->buttons15 = (gcnew System::Windows::Forms::Button());
            this->buttons14 = (gcnew System::Windows::Forms::Button());
            this->buttons13 = (gcnew System::Windows::Forms::Button());
            this->buttons12 = (gcnew System::Windows::Forms::Button());
            this->buttons11 = (gcnew System::Windows::Forms::Button());
            this->buttons10 = (gcnew System::Windows::Forms::Button());
            this->buttons9 = (gcnew System::Windows::Forms::Button());
            this->buttons8 = (gcnew System::Windows::Forms::Button());
            this->buttons7 = (gcnew System::Windows::Forms::Button());
            this->buttons6 = (gcnew System::Windows::Forms::Button());
            this->buttons5 = (gcnew System::Windows::Forms::Button());
            this->buttons4 = (gcnew System::Windows::Forms::Button());
            this->buttons3 = (gcnew System::Windows::Forms::Button());
            this->buttons2 = (gcnew System::Windows::Forms::Button());
            this->buttons1 = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->button37 = (gcnew System::Windows::Forms::Button());
            this->button38 = (gcnew System::Windows::Forms::Button());
            this->buttons30 = (gcnew System::Windows::Forms::Button());
            this->buttons36 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(1029, 450);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(94, 28);
            this->label50->TabIndex = 285;
            this->label50->Text = L"3:30-4:30";
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(718, 449);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(116, 28);
            this->label40->TabIndex = 284;
            this->label40->Text = L"12:30-11:30";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(540, 449);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(116, 28);
            this->label12->TabIndex = 282;
            this->label12->Text = L"11:30-12:30";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(400, 449);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(116, 28);
            this->label11->TabIndex = 281;
            this->label11->Text = L"10:00-11:00";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(259, 449);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(105, 28);
            this->label4->TabIndex = 280;
            this->label4->Text = L"9:00-10:00";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(104, 576);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(83, 28);
            this->label10->TabIndex = 279;
            this->label10->Text = L"Tuesday";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(90, 645);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(113, 28);
            this->label9->TabIndex = 278;
            this->label9->Text = L"Wednesday";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(100, 706);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(91, 28);
            this->label8->TabIndex = 277;
            this->label8->Text = L"Thursday";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(121, 768);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(66, 28);
            this->label7->TabIndex = 276;
            this->label7->Text = L"Friday";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(107, 823);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(90, 28);
            this->label6->TabIndex = 275;
            this->label6->Text = L"Saturday";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(104, 519);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(85, 28);
            this->label5->TabIndex = 274;
            this->label5->Text = L"Monday";
            // 
            // buttons35
            // 
            this->buttons35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons35->Location = System::Drawing::Point(867, 816);
            this->buttons35->Name = L"buttons35";
            this->buttons35->Size = System::Drawing::Size(138, 54);
            this->buttons35->TabIndex = 270;
            this->buttons35->Text = L"free";
            this->buttons35->UseVisualStyleBackColor = false;
            // 
            // buttons34
            // 
            this->buttons34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons34->Location = System::Drawing::Point(708, 816);
            this->buttons34->Name = L"buttons34";
            this->buttons34->Size = System::Drawing::Size(138, 54);
            this->buttons34->TabIndex = 269;
            this->buttons34->Text = L"free";
            this->buttons34->UseVisualStyleBackColor = false;
            // 
            // buttons33
            // 
            this->buttons33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons33->Location = System::Drawing::Point(555, 816);
            this->buttons33->Name = L"buttons33";
            this->buttons33->Size = System::Drawing::Size(138, 54);
            this->buttons33->TabIndex = 268;
            this->buttons33->Text = L"free";
            this->buttons33->UseVisualStyleBackColor = false;
            // 
            // buttons32
            // 
            this->buttons32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons32->Location = System::Drawing::Point(396, 816);
            this->buttons32->Name = L"buttons32";
            this->buttons32->Size = System::Drawing::Size(138, 54);
            this->buttons32->TabIndex = 267;
            this->buttons32->Text = L"free";
            this->buttons32->UseVisualStyleBackColor = false;
            // 
            // buttons31
            // 
            this->buttons31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons31->Location = System::Drawing::Point(241, 816);
            this->buttons31->Name = L"buttons31";
            this->buttons31->Size = System::Drawing::Size(138, 54);
            this->buttons31->TabIndex = 266;
            this->buttons31->Text = L"free";
            this->buttons31->UseVisualStyleBackColor = false;
            // 
            // buttons29
            // 
            this->buttons29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons29->Location = System::Drawing::Point(867, 755);
            this->buttons29->Name = L"buttons29";
            this->buttons29->Size = System::Drawing::Size(138, 55);
            this->buttons29->TabIndex = 264;
            this->buttons29->Text = L"free";
            this->buttons29->UseVisualStyleBackColor = false;
            // 
            // buttons28
            // 
            this->buttons28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons28->Location = System::Drawing::Point(708, 755);
            this->buttons28->Name = L"buttons28";
            this->buttons28->Size = System::Drawing::Size(138, 55);
            this->buttons28->TabIndex = 263;
            this->buttons28->Text = L"free";
            this->buttons28->UseVisualStyleBackColor = false;
            // 
            // buttons27
            // 
            this->buttons27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons27->Location = System::Drawing::Point(555, 755);
            this->buttons27->Name = L"buttons27";
            this->buttons27->Size = System::Drawing::Size(138, 55);
            this->buttons27->TabIndex = 262;
            this->buttons27->Text = L"free";
            this->buttons27->UseVisualStyleBackColor = false;
            // 
            // buttons26
            // 
            this->buttons26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons26->Location = System::Drawing::Point(396, 755);
            this->buttons26->Name = L"buttons26";
            this->buttons26->Size = System::Drawing::Size(138, 55);
            this->buttons26->TabIndex = 261;
            this->buttons26->Text = L"free";
            this->buttons26->UseVisualStyleBackColor = false;
            // 
            // buttons25
            // 
            this->buttons25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons25->Location = System::Drawing::Point(241, 755);
            this->buttons25->Name = L"buttons25";
            this->buttons25->Size = System::Drawing::Size(138, 55);
            this->buttons25->TabIndex = 260;
            this->buttons25->Text = L"free";
            this->buttons25->UseVisualStyleBackColor = false;
            // 
            // buttons24
            // 
            this->buttons24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons24->Location = System::Drawing::Point(1022, 692);
            this->buttons24->Name = L"buttons24";
            this->buttons24->Size = System::Drawing::Size(138, 55);
            this->buttons24->TabIndex = 259;
            this->buttons24->Text = L"free";
            this->buttons24->UseVisualStyleBackColor = false;
            // 
            // buttons23
            // 
            this->buttons23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons23->Location = System::Drawing::Point(867, 693);
            this->buttons23->Name = L"buttons23";
            this->buttons23->Size = System::Drawing::Size(138, 55);
            this->buttons23->TabIndex = 258;
            this->buttons23->Text = L"free";
            this->buttons23->UseVisualStyleBackColor = false;
            // 
            // buttons22
            // 
            this->buttons22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons22->Location = System::Drawing::Point(708, 692);
            this->buttons22->Name = L"buttons22";
            this->buttons22->Size = System::Drawing::Size(138, 55);
            this->buttons22->TabIndex = 257;
            this->buttons22->Text = L"free";
            this->buttons22->UseVisualStyleBackColor = false;
            // 
            // buttons21
            // 
            this->buttons21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons21->Location = System::Drawing::Point(555, 693);
            this->buttons21->Name = L"buttons21";
            this->buttons21->Size = System::Drawing::Size(138, 55);
            this->buttons21->TabIndex = 256;
            this->buttons21->Text = L"free";
            this->buttons21->UseVisualStyleBackColor = false;
            // 
            // buttons20
            // 
            this->buttons20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons20->Location = System::Drawing::Point(396, 693);
            this->buttons20->Name = L"buttons20";
            this->buttons20->Size = System::Drawing::Size(138, 55);
            this->buttons20->TabIndex = 255;
            this->buttons20->Text = L"free";
            this->buttons20->UseVisualStyleBackColor = false;
            // 
            // buttons19
            // 
            this->buttons19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons19->Location = System::Drawing::Point(241, 692);
            this->buttons19->Name = L"buttons19";
            this->buttons19->Size = System::Drawing::Size(138, 55);
            this->buttons19->TabIndex = 254;
            this->buttons19->Text = L"free";
            this->buttons19->UseVisualStyleBackColor = false;
            // 
            // buttons18
            // 
            this->buttons18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons18->Location = System::Drawing::Point(1022, 635);
            this->buttons18->Name = L"buttons18";
            this->buttons18->Size = System::Drawing::Size(138, 55);
            this->buttons18->TabIndex = 253;
            this->buttons18->Text = L"free";
            this->buttons18->UseVisualStyleBackColor = false;
            // 
            // buttons17
            // 
            this->buttons17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons17->Location = System::Drawing::Point(867, 632);
            this->buttons17->Name = L"buttons17";
            this->buttons17->Size = System::Drawing::Size(138, 55);
            this->buttons17->TabIndex = 252;
            this->buttons17->Text = L"free";
            this->buttons17->UseVisualStyleBackColor = false;
            // 
            // buttons16
            // 
            this->buttons16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons16->Location = System::Drawing::Point(708, 632);
            this->buttons16->Name = L"buttons16";
            this->buttons16->Size = System::Drawing::Size(138, 55);
            this->buttons16->TabIndex = 251;
            this->buttons16->Text = L"free";
            this->buttons16->UseVisualStyleBackColor = false;
            // 
            // buttons15
            // 
            this->buttons15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons15->Location = System::Drawing::Point(555, 632);
            this->buttons15->Name = L"buttons15";
            this->buttons15->Size = System::Drawing::Size(138, 55);
            this->buttons15->TabIndex = 250;
            this->buttons15->Text = L"free";
            this->buttons15->UseVisualStyleBackColor = false;
            // 
            // buttons14
            // 
            this->buttons14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons14->Location = System::Drawing::Point(396, 632);
            this->buttons14->Name = L"buttons14";
            this->buttons14->Size = System::Drawing::Size(138, 55);
            this->buttons14->TabIndex = 249;
            this->buttons14->Text = L"free";
            this->buttons14->UseVisualStyleBackColor = false;
            // 
            // buttons13
            // 
            this->buttons13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons13->Location = System::Drawing::Point(241, 632);
            this->buttons13->Name = L"buttons13";
            this->buttons13->Size = System::Drawing::Size(138, 55);
            this->buttons13->TabIndex = 248;
            this->buttons13->Text = L"free";
            this->buttons13->UseVisualStyleBackColor = false;
            // 
            // buttons12
            // 
            this->buttons12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons12->Location = System::Drawing::Point(1022, 571);
            this->buttons12->Name = L"buttons12";
            this->buttons12->Size = System::Drawing::Size(138, 55);
            this->buttons12->TabIndex = 247;
            this->buttons12->Text = L"free";
            this->buttons12->UseVisualStyleBackColor = false;
            // 
            // buttons11
            // 
            this->buttons11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons11->Location = System::Drawing::Point(867, 571);
            this->buttons11->Name = L"buttons11";
            this->buttons11->Size = System::Drawing::Size(138, 55);
            this->buttons11->TabIndex = 246;
            this->buttons11->Text = L"free";
            this->buttons11->UseVisualStyleBackColor = false;
            // 
            // buttons10
            // 
            this->buttons10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons10->Location = System::Drawing::Point(708, 571);
            this->buttons10->Name = L"buttons10";
            this->buttons10->Size = System::Drawing::Size(138, 55);
            this->buttons10->TabIndex = 245;
            this->buttons10->Text = L"free";
            this->buttons10->UseVisualStyleBackColor = false;
            // 
            // buttons9
            // 
            this->buttons9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons9->Location = System::Drawing::Point(555, 571);
            this->buttons9->Name = L"buttons9";
            this->buttons9->Size = System::Drawing::Size(138, 55);
            this->buttons9->TabIndex = 244;
            this->buttons9->Text = L"free";
            this->buttons9->UseVisualStyleBackColor = false;
            // 
            // buttons8
            // 
            this->buttons8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons8->Location = System::Drawing::Point(396, 571);
            this->buttons8->Name = L"buttons8";
            this->buttons8->Size = System::Drawing::Size(138, 55);
            this->buttons8->TabIndex = 243;
            this->buttons8->Text = L"free";
            this->buttons8->UseVisualStyleBackColor = false;
            // 
            // buttons7
            // 
            this->buttons7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons7->Location = System::Drawing::Point(241, 571);
            this->buttons7->Name = L"buttons7";
            this->buttons7->Size = System::Drawing::Size(138, 55);
            this->buttons7->TabIndex = 242;
            this->buttons7->Text = L"free";
            this->buttons7->UseVisualStyleBackColor = false;
            // 
            // buttons6
            // 
            this->buttons6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons6->Location = System::Drawing::Point(1022, 511);
            this->buttons6->Name = L"buttons6";
            this->buttons6->Size = System::Drawing::Size(138, 55);
            this->buttons6->TabIndex = 241;
            this->buttons6->Text = L"free";
            this->buttons6->UseVisualStyleBackColor = false;
            // 
            // buttons5
            // 
            this->buttons5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons5->Location = System::Drawing::Point(867, 511);
            this->buttons5->Name = L"buttons5";
            this->buttons5->Size = System::Drawing::Size(138, 55);
            this->buttons5->TabIndex = 240;
            this->buttons5->Text = L"free";
            this->buttons5->UseVisualStyleBackColor = false;
            // 
            // buttons4
            // 
            this->buttons4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons4->Location = System::Drawing::Point(708, 511);
            this->buttons4->Name = L"buttons4";
            this->buttons4->Size = System::Drawing::Size(138, 55);
            this->buttons4->TabIndex = 239;
            this->buttons4->Text = L"free";
            this->buttons4->UseVisualStyleBackColor = false;
            // 
            // buttons3
            // 
            this->buttons3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons3->Location = System::Drawing::Point(555, 511);
            this->buttons3->Name = L"buttons3";
            this->buttons3->Size = System::Drawing::Size(138, 55);
            this->buttons3->TabIndex = 238;
            this->buttons3->Text = L"free";
            this->buttons3->UseVisualStyleBackColor = false;
            // 
            // buttons2
            // 
            this->buttons2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons2->Location = System::Drawing::Point(396, 511);
            this->buttons2->Name = L"buttons2";
            this->buttons2->Size = System::Drawing::Size(138, 55);
            this->buttons2->TabIndex = 237;
            this->buttons2->Text = L"free";
            this->buttons2->UseVisualStyleBackColor = false;
            // 
            // buttons1
            // 
            this->buttons1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons1->Location = System::Drawing::Point(241, 511);
            this->buttons1->Name = L"buttons1";
            this->buttons1->Size = System::Drawing::Size(138, 55);
            this->buttons1->TabIndex = 236;
            this->buttons1->Text = L"free";
            this->buttons1->UseVisualStyleBackColor = false;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(96, 364);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(161, 28);
            this->label3->TabIndex = 235;
            this->label3->Text = L"Teacher Schedule";
            // 
            // comboBox1
            // 
            this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(100, 267);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(362, 36);
            this->comboBox1->TabIndex = 234;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(101, 222);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(198, 28);
            this->label2->TabIndex = 233;
            this->label2->Text = L"Enter the department";
            // 
            // textBox2
            // 
            this->textBox2->AcceptsTab = true;
            this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox2->ForeColor = System::Drawing::Color::Black;
            this->textBox2->Location = System::Drawing::Point(100, 141);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(361, 27);
            this->textBox2->TabIndex = 232;
            // 
            // button37
            // 
            this->button37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button37->Location = System::Drawing::Point(800, 945);
            this->button37->Name = L"button37";
            this->button37->Size = System::Drawing::Size(121, 45);
            this->button37->TabIndex = 273;
            this->button37->Text = L"Save";
            this->button37->UseVisualStyleBackColor = false;
            // 
            // button38
            // 
            this->button38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button38->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button38->Location = System::Drawing::Point(970, 945);
            this->button38->Name = L"button38";
            this->button38->Size = System::Drawing::Size(121, 45);
            this->button38->TabIndex = 272;
            this->button38->Text = L"Add New";
            this->button38->UseVisualStyleBackColor = false;
            // 
            // buttons30
            // 
            this->buttons30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons30->Location = System::Drawing::Point(1022, 755);
            this->buttons30->Name = L"buttons30";
            this->buttons30->Size = System::Drawing::Size(138, 55);
            this->buttons30->TabIndex = 265;
            this->buttons30->Text = L"free";
            this->buttons30->UseVisualStyleBackColor = false;
            // 
            // buttons36
            // 
            this->buttons36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons36->Location = System::Drawing::Point(1022, 816);
            this->buttons36->Name = L"buttons36";
            this->buttons36->Size = System::Drawing::Size(138, 54);
            this->buttons36->TabIndex = 271;
            this->buttons36->Text = L"free";
            this->buttons36->UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(96, 95);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(179, 28);
            this->label1->TabIndex = 231;
            this->label1->Text = L"Enter teacher name";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(875, 449);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(94, 28);
            this->label14->TabIndex = 283;
            this->label14->Text = L"2:30-3:30";
            // 
            // MyUserControl
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->Controls->Add(this->label50);
            this->Controls->Add(this->label40);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->buttons35);
            this->Controls->Add(this->buttons34);
            this->Controls->Add(this->buttons33);
            this->Controls->Add(this->buttons32);
            this->Controls->Add(this->buttons31);
            this->Controls->Add(this->buttons29);
            this->Controls->Add(this->buttons28);
            this->Controls->Add(this->buttons27);
            this->Controls->Add(this->buttons26);
            this->Controls->Add(this->buttons25);
            this->Controls->Add(this->buttons24);
            this->Controls->Add(this->buttons23);
            this->Controls->Add(this->buttons22);
            this->Controls->Add(this->buttons21);
            this->Controls->Add(this->buttons20);
            this->Controls->Add(this->buttons19);
            this->Controls->Add(this->buttons18);
            this->Controls->Add(this->buttons17);
            this->Controls->Add(this->buttons16);
            this->Controls->Add(this->buttons15);
            this->Controls->Add(this->buttons14);
            this->Controls->Add(this->buttons13);
            this->Controls->Add(this->buttons12);
            this->Controls->Add(this->buttons11);
            this->Controls->Add(this->buttons10);
            this->Controls->Add(this->buttons9);
            this->Controls->Add(this->buttons8);
            this->Controls->Add(this->buttons7);
            this->Controls->Add(this->buttons6);
            this->Controls->Add(this->buttons5);
            this->Controls->Add(this->buttons4);
            this->Controls->Add(this->buttons3);
            this->Controls->Add(this->buttons2);
            this->Controls->Add(this->buttons1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->button37);
            this->Controls->Add(this->button38);
            this->Controls->Add(this->buttons30);
            this->Controls->Add(this->buttons36);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label14);
            this->Name = L"MyUserControl";
            this->Size = System::Drawing::Size(1795, 1525);
            this->Load += gcnew System::EventHandler(this, &MyUserControl::MyUserControl_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

private: System::Void sedataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void MyUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
