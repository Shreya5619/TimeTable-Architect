#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include "includes.h"
#include<list>
extern std::string searchteachername;
extern std::string searchroomname;
extern std::string searchsubname;
extern std::string editteacherlastpanel;
extern std::string addteacherlastpanel;
extern std::string editroomlastpanel;
extern std::string addroomlastpanel;
extern std::string addclasslastpanel;
extern std::vector<std::vector<bool>>reserveMatrix;
extern std::vector<std::vector<std::string>>labteachers;
extern std::string editsublastpanel;
extern std::string addsublastpanel;
section l;
namespace TTA_ui {
    using namespace std;
    using namespace System::IO;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Diagnostics;
    using namespace Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm()
        {

            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //// Initialize the form components
            timer1->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
            timer2->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
            timer3->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
            timer4->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
            timer5->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
            timer6->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
            timer7->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer7->Tick += gcnew System::EventHandler(this, &MyForm::timer7_Tick);
            timer8->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer8->Tick += gcnew System::EventHandler(this, &MyForm::timer8_Tick);
            timer9->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer9->Tick += gcnew System::EventHandler(this, &MyForm::timer9_Tick);
            timer10->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer10->Tick += gcnew System::EventHandler(this, &MyForm::timer10_Tick);
            timer11->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer11->Tick += gcnew System::EventHandler(this, &MyForm::timer11_Tick);
            timer12->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer12->Tick += gcnew System::EventHandler(this, &MyForm::timer12_Tick);
            timer13->Interval = 50; // Set the interval for the timer (adjust as needed)
            timer13->Tick += gcnew System::EventHandler(this, &MyForm::timer13_Tick);
        }
        System::Void EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
        {
            // Check if the current cell is in the TextBoxColumn
            try
            {
                if (deptDataGridView->CurrentCell->OwningColumn->Name == "dataGridViewTextBoxColumn1")
                {
                    // Attach  event handler to the TextBox control
                    System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(e->Control);
                    textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
                }
            }
            catch(...)
            { }
        }

    private: System::Windows::Forms::Timer^ timer1;
    private: ComponentFactory::Krypton::Toolkit::KryptonButton^ editsubactivepanel;
    private: System::Windows::Forms::Label^ label94;
    private: System::Windows::Forms::Button^ editsubsave;
    private: System::Windows::Forms::Button^ editsubdelete;
    private: System::Windows::Forms::Panel^ editsubelepanel;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Panel^ panel13;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel2;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubsearchgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonButton^ editsubsearchbutton;
    private: System::Windows::Forms::Label^ label99;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ editsubsearch;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel1;
    private: System::Windows::Forms::Label^ label109;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editsubtitle;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubelegroup;
    private: System::Windows::Forms::Label^ label92;
    private: System::Windows::Forms::Panel^ panel10;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ editsubeleyes;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ editsubeleno;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubnamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel3;
    private: System::Windows::Forms::Label^ label93;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editsubname;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubcodegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel4;
    private: System::Windows::Forms::Label^ label15;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editsubcode;
    private: System::Windows::Forms::Panel^ editsubjectpanel;
    private: System::Windows::Forms::Label^ label95;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubeleyesgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ editsubcluster;
    private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ editsubeleteacher;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubcreditsgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ editsubcredits;
    private: System::Windows::Forms::Label^ label101;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubbfactorgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ kryptonNumericUpDown1;
    private: System::Windows::Forms::Label^ label97;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubroomlistgroup;
    private: System::Windows::Forms::Label^ label150;
    private: ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox^ editsubroomlist;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ editsubbfactor;
    private: System::Windows::Forms::Label^ label110;
    private: System::Windows::Forms::Button^ panel3;
    private: System::Windows::Forms::Panel^ panel11;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubbfactorgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ addsubbfactor;
    private: System::Windows::Forms::Label^ label96;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ kryptonNumericUpDown3;
    private: System::Windows::Forms::Label^ label100;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubroomlistgroup;
    private: System::Windows::Forms::Label^ label152;
    private: ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox^ addsubroomlist;
    private: System::Windows::Forms::Button^ button19;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubeleyesgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ sedataGridView;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ addsubcluster;
    private: System::Windows::Forms::Button^ addsubclusteroptions;
    private: System::Windows::Forms::Label^ label178;
    private: System::Windows::Forms::Label^ label179;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel3;
    private: System::Windows::Forms::Button^ addsubsave;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubcreditsgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ addsubcredits;
    private: System::Windows::Forms::Label^ label181;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubtitlegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel2;
    private: System::Windows::Forms::Label^ label182;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addsubtitle;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubelegroup;
    private: System::Windows::Forms::Label^ label183;
    private: System::Windows::Forms::Panel^ panel42;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ addsubeleyes;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ addsubeleno;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubnamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel5;
    private: System::Windows::Forms::Label^ label184;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addsubname;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addsubcodegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel7;
    private: System::Windows::Forms::Label^ label185;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addsubcode;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ TeacherName;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn4;
    private: System::Windows::Forms::Timer^ timer2;
    private: System::Windows::Forms::Panel^ panel7;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ roomdeptgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel5;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ roomcapacitygroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ roomcapacity;
    private: System::Windows::Forms::Label^ label187;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ roomlabgroup;
    private: System::Windows::Forms::Label^ label189;
    private: System::Windows::Forms::Panel^ panel44;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ roomlabyes;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ roomlabno;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ roomnamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel12;
    private: System::Windows::Forms::Label^ label190;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ roomname;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ roomdept;
    private: System::Windows::Forms::Label^ label28;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Panel^ panel37;
    private: System::Windows::Forms::Panel^ panel43;
    private: System::Windows::Forms::TableLayoutPanel^ addroomtablepanel;
    private: System::Windows::Forms::Label^ label29;
    private: System::Windows::Forms::Label^ label30;
    private: System::Windows::Forms::Label^ label31;
    private: System::Windows::Forms::Label^ label126;
    private: System::Windows::Forms::Label^ label127;
    private: System::Windows::Forms::Label^ label128;
    private: System::Windows::Forms::Label^ label129;
    private: System::Windows::Forms::Label^ label130;
    private: System::Windows::Forms::Label^ label131;
    private: System::Windows::Forms::Label^ label132;
    private: System::Windows::Forms::Label^ label133;
    private: System::Windows::Forms::Label^ label134;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox9;
    private: System::Windows::Forms::Panel^ panel12;
    private: System::Windows::Forms::Panel^ panel5;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editteachersearchgroup;
    private: System::Windows::Forms::Label^ label6;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ teachersearch;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editteachertablegroup;
    private: System::Windows::Forms::Panel^ panel19;
    private: System::Windows::Forms::Panel^ panel23;
    private: System::Windows::Forms::TableLayoutPanel^ editteachertablepanel;
    private: System::Windows::Forms::Panel^ panel24;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::Label^ label16;
    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::Label^ label19;
    private: System::Windows::Forms::Label^ label20;
    private: System::Windows::Forms::Panel^ panel28;
    private: System::Windows::Forms::Button^ button21;
    private: System::Windows::Forms::Button^ button23;
    private: System::Windows::Forms::Label^ label21;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editteacherdepartmentgroup;
    private: System::Windows::Forms::Label^ label22;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ editteacherdepartment;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel4;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editteachernamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel8;
    private: System::Windows::Forms::Label^ label25;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editteachername;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editteacheremailidgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel9;
    private: System::Windows::Forms::Label^ label23;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editteacheremailid;
    private: System::Windows::Forms::Panel^ panel16;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addteacheremailidgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel10;
    private: System::Windows::Forms::Label^ label1;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addteacheremailid;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addteachertablegroup;
    private: System::Windows::Forms::Panel^ panel30;
    private: System::Windows::Forms::Panel^ panel31;
    private: System::Windows::Forms::TableLayoutPanel^ teachertablepanel;
    private: System::Windows::Forms::Panel^ panel32;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label24;
    private: System::Windows::Forms::Label^ label26;
    private: System::Windows::Forms::Label^ label27;
    private: System::Windows::Forms::Label^ label40;
    private: System::Windows::Forms::Label^ label41;
    private: System::Windows::Forms::Label^ label42;
    private: System::Windows::Forms::Label^ label43;
    private: System::Windows::Forms::Label^ label46;
    private: System::Windows::Forms::Label^ label47;
    private: System::Windows::Forms::Label^ label48;
    private: System::Windows::Forms::Label^ label49;
    private: System::Windows::Forms::Panel^ panel35;
    private: System::Windows::Forms::Button^ button26;
    private: System::Windows::Forms::Button^ button27;
    private: System::Windows::Forms::Label^ label50;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addteacherdepartmentgroup;
    private: System::Windows::Forms::Label^ label51;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ addteacherdepartment;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel7;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ addteachernamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel13;
    private: System::Windows::Forms::Label^ label63;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addteachername;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel9;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ deptgroup;

    private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ deptDataGridView;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel8;
    private: System::Windows::Forms::Panel^ panel29;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classbranchgroup;
    private: System::Windows::Forms::Label^ label82;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ classbranch;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel10;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classnamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel15;
    private: System::Windows::Forms::Label^ label119;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ classname;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classbatchgroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ classbatch;
    private: System::Windows::Forms::Label^ label2;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classcoregroup;
    private: System::Windows::Forms::Label^ label37;
    private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classcore;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classelegroup;
    private: System::Windows::Forms::Label^ label36;
    private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classele;
    private: System::Windows::Forms::Button^ editteachersearchbutton;
    private: System::Windows::Forms::Panel^ panel6;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editroomsearchgroup;
    private: System::Windows::Forms::Label^ label242;
    private: System::Windows::Forms::Button^ editroomsearchbutton;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ editroomsearch;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox10;
    private: System::Windows::Forms::Panel^ panel15;
    private: System::Windows::Forms::Panel^ panel33;
    private: System::Windows::Forms::TableLayoutPanel^ editroomtablepanel;
    private: System::Windows::Forms::Panel^ panel34;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label78;
    private: System::Windows::Forms::Label^ label79;
    private: System::Windows::Forms::Label^ label80;
    private: System::Windows::Forms::Label^ label81;
    private: System::Windows::Forms::Label^ label103;
    private: System::Windows::Forms::Label^ label104;
    private: System::Windows::Forms::Label^ label105;
    private: System::Windows::Forms::Label^ label106;
    private: System::Windows::Forms::Label^ label107;
    private: System::Windows::Forms::Label^ label108;
    private: System::Windows::Forms::Label^ label113;
    private: System::Windows::Forms::Panel^ panel14;
    private: System::Windows::Forms::Button^ editroomdelete;
    private: System::Windows::Forms::Button^ editroomsave;
    private: System::Windows::Forms::Label^ label114;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editroomdepartmentgroup;
    private: System::Windows::Forms::Label^ label115;
    private: ComponentFactory::Krypton::Toolkit::KryptonComboBox^ editroomdepartment;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel6;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editroomcapacitygroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ editroomcapacity;
    private: System::Windows::Forms::Label^ label116;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editroomlabgroup;
    private: System::Windows::Forms::Label^ label117;
    private: System::Windows::Forms::Panel^ panel45;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ editroomlabyes;
    private: ComponentFactory::Krypton::Toolkit::KryptonRadioButton^ editroomlabno;
    private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editroomnamegroup;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel11;
    private: System::Windows::Forms::Label^ label118;
    private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editroomname;
    private: System::Windows::Forms::Panel^ editroompanel;
    private: System::Windows::Forms::Timer^ timer3;
    private: System::Windows::Forms::Timer^ timer4;
    private: System::Windows::Forms::Timer^ timer5;
private: System::Windows::Forms::Timer^ timer6;
private: System::Windows::Forms::Panel^ panel46;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox2;
private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ sectiondeletedatagridview;
private: System::Windows::Forms::Panel^ panel47;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ classcolumn;
private: System::Windows::Forms::DataGridViewButtonColumn^ classdeletebutton;
private: System::Windows::Forms::Panel^ panel48;
private: System::Windows::Forms::Timer^ timer7;
private: System::Windows::Forms::Timer^ timer8;
private: System::Windows::Forms::Panel^ panel38;
private: System::Windows::Forms::Panel^ panel41;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::Panel^ panel49;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::Label^ label66;
private: System::Windows::Forms::Label^ label67;
private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::Label^ label69;
private: System::Windows::Forms::Label^ label70;
private: System::Windows::Forms::Label^ label71;
private: System::Windows::Forms::Label^ label72;
private: System::Windows::Forms::Label^ label73;
private: System::Windows::Forms::Label^ label74;
private: System::Windows::Forms::Timer^ timer9;
private: System::Windows::Forms::Timer^ timer10;
private: System::Windows::Forms::Timer^ timer11;
private: System::Windows::Forms::Timer^ timer12;
private: System::Windows::Forms::Panel^ panel51;
private: System::Windows::Forms::Label^ label155;
private: System::Windows::Forms::Panel^ panel39;
private: System::Windows::Forms::Panel^ panel40;
private: System::Windows::Forms::TableLayoutPanel^ editsubeletable;
private: System::Windows::Forms::Panel^ panel52;
private: System::Windows::Forms::Label^ label75;
private: System::Windows::Forms::Label^ label76;
private: System::Windows::Forms::Label^ label77;
private: System::Windows::Forms::Label^ label120;
private: System::Windows::Forms::Label^ label123;
private: System::Windows::Forms::Label^ label124;
private: System::Windows::Forms::Label^ label125;
private: System::Windows::Forms::Label^ label147;
private: System::Windows::Forms::Label^ label148;
private: System::Windows::Forms::Label^ label149;
private: System::Windows::Forms::Label^ label151;
private: System::Windows::Forms::Label^ label153;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ esubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ csubject;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ cteacher;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classlabgroup;
private: System::Windows::Forms::Label^ label154;
private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlabteachers;
private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel14;
private: System::Windows::Forms::Label^ label156;
private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ classlabcombo;
private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ classsessions;
private: System::Windows::Forms::Label^ label157;
private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ classbatches;
private: System::Windows::Forms::Label^ label39;
private: ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox^ classlabroomlist;
private: System::Windows::Forms::Label^ label44;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classresgroup;
private: System::Windows::Forms::Panel^ panel50;
private: System::Windows::Forms::Panel^ panel53;
private: System::Windows::Forms::TableLayoutPanel^ classtablegen;
private: System::Windows::Forms::Panel^ panel54;
private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::Label^ label158;
private: System::Windows::Forms::Label^ label159;
private: System::Windows::Forms::Label^ label160;
private: System::Windows::Forms::Label^ label161;
private: System::Windows::Forms::Label^ label162;
private: System::Windows::Forms::Label^ label163;
private: System::Windows::Forms::Label^ label164;
private: System::Windows::Forms::Label^ label166;
private: System::Windows::Forms::Label^ label167;
private: System::Windows::Forms::Label^ label168;
private: System::Windows::Forms::Label^ label169;
private: System::Windows::Forms::Label^ label170;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classroomgroup;
private: System::Windows::Forms::Label^ label35;
private: ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox^ classdefaultrooms;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ classgengroup;
private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::Panel^ panel25;
private: System::Windows::Forms::TableLayoutPanel^ classtablegen1;
private: System::Windows::Forms::Panel^ panel26;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::Label^ label52;
private: System::Windows::Forms::Label^ label53;
private: System::Windows::Forms::Label^ label54;
private: System::Windows::Forms::Label^ label55;
private: System::Windows::Forms::Label^ label56;
private: System::Windows::Forms::Label^ label57;
private: System::Windows::Forms::Label^ label58;
private: System::Windows::Forms::Label^ label59;
private: System::Windows::Forms::Label^ label60;
private: System::Windows::Forms::Label^ label61;
private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::Label^ label135;
private: ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlab;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ lsubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn7;
private: System::Windows::Forms::Panel^ panel27;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn3;
private: System::Windows::Forms::Timer^ timer13;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ editsubeleteachercombo;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn10;
private: System::Windows::Forms::Panel^ panel36;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox3;
private: System::Windows::Forms::Label^ label137;
private: System::Windows::Forms::Button^ settingssave;
private: System::Windows::Forms::Panel^ panel59;
private: System::Windows::Forms::Button^ button28;
private: System::Windows::Forms::Button^ button29;
private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel11;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox6;
private: System::Windows::Forms::Label^ label175;
private: System::Windows::Forms::Button^ Homebutton1;
private: ComponentFactory::Krypton::Toolkit::KryptonTextBox^ filepath;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox4;
private: System::Windows::Forms::Panel^ panel56;
private: System::Windows::Forms::Panel^ panel57;
private: System::Windows::Forms::TableLayoutPanel^ settingstable;
private: System::Windows::Forms::Panel^ panel58;
private: System::Windows::Forms::Label^ label138;
private: System::Windows::Forms::Label^ label139;
private: System::Windows::Forms::Label^ label140;
private: System::Windows::Forms::Label^ label141;
private: System::Windows::Forms::Label^ label142;
private: System::Windows::Forms::Label^ label143;
private: System::Windows::Forms::Label^ label144;
private: System::Windows::Forms::Label^ label145;
private: System::Windows::Forms::Label^ label146;
private: System::Windows::Forms::Label^ label165;
private: System::Windows::Forms::Label^ label171;
private: System::Windows::Forms::Label^ label172;
private: System::Windows::Forms::Label^ label173;
private: ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ kryptonGroupBox5;
private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ busyfactor;

private: System::Windows::Forms::Label^ label45;
private: ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown^ freefactor;
private: ComponentFactory::Krypton::Toolkit::KryptonCheckBox^ compactlabs;
private: ComponentFactory::Krypton::Toolkit::KryptonCheckBox^ classoptrooms;




    public:
        int animationProgress = 0;
    private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
        ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel13->Controls[msclr::interop::marshal_as<String^>(editsublastpanel)]);
        animationProgress++;
        // Update the border color based on the animation progress
        if (animationProgress <= 2) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

            editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
        }
        else if (animationProgress <= 4) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
        }
        else if (animationProgress <= 5.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
        }
        else if (animationProgress <= 6.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
        }
        // If the animation is complete, stop the timer
        if (animationProgress >= 8) {

            editsubactivepanel->Height = int(editsubtitlegroup->Height);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            timer1->Stop();
        }
    }
           // Method to start the animation
           void StartAnimation() {
               animationProgress = 0;
               timer1->Start();
           }

           System::Void timer13_Tick(System::Object^ sender, System::EventArgs^ e) {
               ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel29->Controls[msclr::interop::marshal_as<String^>(addclasslastpanel)]);
               animationProgress++;
               // Update the border color based on the animation progress
               if (animationProgress <= 2) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

                   editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
               }
               else if (animationProgress <= 4) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
               }
               else if (animationProgress <= 5.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
               }
               else if (animationProgress <= 6.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
               }
               // If the animation is complete, stop the timer
               if (animationProgress >= 8) {

                   editsubactivepanel->Height = int(editsubtitlegroup->Height);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   timer13->Stop();
               }
           }
           // Method to start the animation
           void StartAnimationaddclass() {
               animationProgress = 0;
               timer13->Start();
           }


           System::Void timer7_Tick(System::Object^ sender, System::EventArgs^ e) {
               
               addsubeleyesgroup->Height += 20;
               addsubcreditsgroup->Top = addsubeleyesgroup->Bottom + 30;
               addsubroomlistgroup->Top = addsubcreditsgroup->Bottom + 30;
               addsubbfactorgroup->Top = addsubroomlistgroup->Bottom + 30;
               panel48->Top = addsubbfactorgroup->Bottom + 30;
               panel11->Height += 20;
               if (addsubeleyesgroup->Height >= 330) {
                   timer7->Stop();
               }
           }
           System::Void timer10_Tick(System::Object^ sender, System::EventArgs^ e) {

               editsubeleyesgroup->Height += 20;
               editsubcreditsgroup->Top = editsubeleyesgroup->Bottom + 30;
               editsubroomlistgroup->Top = editsubcreditsgroup->Bottom + 30;
               editsubbfactorgroup->Top = editsubroomlistgroup->Bottom + 30;
               panel51->Top = editsubbfactorgroup->Bottom + 30;
               panel13->Height += 20;
               if (editsubeleyesgroup->Height >= 330) {
                   timer10->Stop();
               }
           }
           System::Void timer9_Tick(System::Object^ sender, System::EventArgs^ e) {

               addsubeleyesgroup->Height -= 20;
               addsubcreditsgroup->Top = addsubeleyesgroup->Bottom + 30;
               addsubroomlistgroup->Top = addsubcreditsgroup->Bottom + 30;
               addsubbfactorgroup->Top = addsubroomlistgroup->Bottom + 30;
               panel48->Top = addsubbfactorgroup->Bottom + 30;
               panel11->Height -= 20;
               if (addsubeleyesgroup->Height <= 0) {
                   timer9->Stop();
               }
           }
           System::Void timer12_Tick(System::Object^ sender, System::EventArgs^ e) {

               editsubeleyesgroup->Height -= 20;
               editsubcreditsgroup->Top = editsubeleyesgroup->Bottom + 30;
               editsubroomlistgroup->Top = editsubcreditsgroup->Bottom + 30;
               editsubbfactorgroup->Top = editsubroomlistgroup->Bottom + 30;
               panel51->Top = editsubbfactorgroup->Bottom + 30;
               panel13->Height -= 20;
               if (editsubeleyesgroup->Height <= 0) {
                   timer12->Stop();
               }
           }
           System::Void timer8_Tick(System::Object^ sender, System::EventArgs^ e) {

               addsubeleyesgroup->Height += 40;
               editsubactivepanel->Height += 40;
               addsubcreditsgroup->Top = addsubeleyesgroup->Bottom + 30;
               addsubroomlistgroup->Top = addsubcreditsgroup->Bottom + 30;
               addsubbfactorgroup->Top = addsubroomlistgroup->Bottom + 30;
               panel48->Top = addsubbfactorgroup->Bottom + 30;
               panel11->Height += 40;
               if (addsubeleyesgroup->Height >= 800) {
                   timer8->Stop();
               }
           }
           System::Void timer11_Tick(System::Object^ sender, System::EventArgs^ e) {

               editsubeleyesgroup->Height += 40;
               editsubactivepanel->Height += 40;
               editsubcreditsgroup->Top = editsubeleyesgroup->Bottom + 30;
               editsubroomlistgroup->Top = editsubcreditsgroup->Bottom + 30;
               editsubbfactorgroup->Top = editsubroomlistgroup->Bottom + 30;
               panel51->Top = editsubbfactorgroup->Bottom + 30;
               panel13->Height += 40;
               if (editsubeleyesgroup->Height >= 800) {
                   timer11->Stop();
               }
           }
           System::Void timer6_Tick(System::Object^ sender, System::EventArgs^ e) {
               ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel7->Controls[msclr::interop::marshal_as<String^>(addroomlastpanel)]);
               animationProgress++;
               // Update the border color based on the animation progress
               if (animationProgress <= 2) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

                   editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
               }
               else if (animationProgress <= 4) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
               }
               else if (animationProgress <= 5.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
               }
               else if (animationProgress <= 6.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
               }
               // If the animation is complete, stop the timer
               if (animationProgress >= 8) {

                   editsubactivepanel->Height = int(editsubtitlegroup->Height);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   timer6->Stop();
               }
           }
           // Method to start the animation
           void StartAnimationaddroom() {
               animationProgress = 0;
               timer6->Start();
           }


    private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
        ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel11->Controls[msclr::interop::marshal_as<String^>(addsublastpanel)]);
        animationProgress++;
        // Update the border color based on the animation progress
        if (animationProgress <= 2) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

            editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
        }
        else if (animationProgress <= 4) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
        }
        else if (animationProgress <= 5.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
        }
        else if (animationProgress <= 6.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
        }
        // If the animation is complete, stop the timer
        if (animationProgress >= 8) {

            editsubactivepanel->Height = (editsubtitlegroup->Height);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            timer2->Stop();
        }
    }
           // Method to start the animation
           void StartAnimationaddsub() {
               animationProgress = 0;
               timer2->Start();
           }

           System::Void timer5_Tick(System::Object^ sender, System::EventArgs^ e) {
               ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel6->Controls[msclr::interop::marshal_as<String^>(editroomlastpanel)]);
               animationProgress++;
               // Update the border color based on the animation progress
               if (animationProgress <= 2) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

                   editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
               }
               else if (animationProgress <= 4) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
               }
               else if (animationProgress <= 5.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
               }
               else if (animationProgress <= 6.5) {
                   editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
                   editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
               }
               // If the animation is complete, stop the timer
               if (animationProgress >= 8) {

                   editsubactivepanel->Height = (editsubtitlegroup->Height);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
                   timer5->Stop();
               }
           }
           // Method to start the animation
           void StartAnimationeditroom() {
               animationProgress = 0;
               timer5->Start();
           }

    private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
        ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel5->Controls[msclr::interop::marshal_as<String^>(editteacherlastpanel)]);
        animationProgress++;
        // Update the border color based on the animation progress
        if (animationProgress <= 2) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;

            editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
        }
        else if (animationProgress <= 4) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
        }
        else if (animationProgress <= 5.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
        }
        else if (animationProgress <= 6.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
        }
        // If the animation is complete, stop the timer
        if (animationProgress >= 8) {

            editsubactivepanel->Height = (editsubtitlegroup->Height);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            timer3->Stop();
        }
    }
           // Method to start the animation
           void StartAnimationeditteacher() {
               animationProgress = 0;
               timer3->Start();
           }
    private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
        ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubtitlegroup = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel16->Controls[msclr::interop::marshal_as<String^>(addteacherlastpanel)]);
        animationProgress++;
        // Update the border color based on the animation progress
        if (animationProgress <= 2) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch90;
            editsubactivepanel->Height = int(editsubtitlegroup->Panel->Height * 0.25);
        }
        else if (animationProgress <= 4) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch50;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.5);
        }
        else if (animationProgress <= 5.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch33;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.6875);
        }
        else if (animationProgress <= 6.5) {
            editsubtitlegroup->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Switch25;
            editsubactivepanel->Height = int(editsubtitlegroup->Height * 0.8125);
        }
        // If the animation is complete, stop the timer
        if (animationProgress >= 8) {

            editsubactivepanel->Height = (editsubtitlegroup->Height);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            editsubtitlegroup->StateCommon->Border->Color1 = Color::FromArgb(0, 0, 77);
            timer4->Stop();
        }
    }
           // Method to start the animation
           void StartAnimationaddteacher() {
               animationProgress = 0;
               timer4->Start();
           }
           void textBox_KeyDown(Object^ sender, KeyEventArgs^ e)
           {
               // Check if the Enter key was pressed
               if (e->KeyCode == Keys::Enter)
               {
                   // Perform the desired action (e.g., process the input)
                   ComponentFactory::Krypton::Toolkit::KryptonComboBox^ textBox = dynamic_cast<ComponentFactory::Krypton::Toolkit::KryptonComboBox^>(sender);
                   if (textBox != nullptr)
                   {
                       editteachercsvshow("details/teacher_file.csv");
                   }
               }
           }
           void coloredpanel(Panel^ panel, string s, ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ editsubbfactorgroup, int i, string editsublastpanels)
           {
               try
               {
                   ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel->Controls[msclr::interop::marshal_as<String^>(editsublastpanels)]);
                   g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
                   g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);  //(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);  
               }
               catch (...)
               {
               }
               editsubactivepanel->Height = 0;
               editsubbfactorgroup->Panel->Controls->Add(this->editsubactivepanel);
               editsubactivepanel->Location = System::Drawing::Point(0, 0);
               editsubbfactorgroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
               editsubbfactorgroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
               editsubbfactorgroup->SendToBack();
               editsubactivepanel->BringToFront(); 
               if (i == 1)
               {
                   StartAnimationaddroom();
                   addroomlastpanel = s;
               }
               else if (i == 2)
               {
                   StartAnimationeditroom();
                   editroomlastpanel = s;
               }
               else if (i == 3)
               {
                   StartAnimationaddteacher();
                   addteacherlastpanel = s;
               }
               else if (i == 4)
               {
                   StartAnimationeditteacher();
                   editteacherlastpanel = s;
               }
               else if (i == 5)
               {
                   StartAnimationaddsub();
                   addsublastpanel = s;
               }
               else if (i == 6)
               {
                   StartAnimation();
                   editsublastpanel = s;
               }
               else if (i == 7)
               {
                   StartAnimationaddclass();
                   addclasslastpanel = s;
               }
           }
           void textBox_KeyDownClass(Object^ sender, KeyEventArgs^ e)
           {
               // Check if the Enter key was pressed
               if (e->KeyCode == Keys::Enter)
               {
                   // Perform the desired action (e.g., process the input)
                   classlabteachers->Rows->Clear();
                   classbatches->Value = 0;
                   classsessions->Value = 0;
                   for (int i = 0; i < classlabroomlist->Items->Count; i++) {
                       classlabroomlist->SetItemChecked(i, false);
                   }
                   string find = replacewhitespace(msclr::interop::marshal_as<string>(classlabcombo->Text));
                   MaskedTextBox^ textBox = dynamic_cast<MaskedTextBox^>(sender);
                   if (textBox != nullptr)
                   {
                       for (const auto& row : labteachers)
                       {
                           if (row[0] == find)
                           {
                               classbatches->Text = msclr::interop::marshal_as<String^>(row[1]);
                               classsessions->Text = msclr::interop::marshal_as<String^>(row[2]);
                               bool flag = false;
                               for (int i = 3; i < row.size() - 1; i++)
                               {
                                   classlabteachers->Rows->Add(msclr::interop::marshal_as<String^>(replaceunderscore(row[i])));
                               }
                               string s;
                               for (const char& cell : row[row.size() - 1])
                               {
                                   if (cell == '[')
                                       continue;
                                   else if (cell == ',' || cell == ']')
                                   {
                                       String^ y = msclr::interop::marshal_as<String^>(s);
                                       for (int i = 0; i < classlabroomlist->Items->Count; i++)
                                       {

                                           String^ item = classlabroomlist->Items[i]->ToString();
                                           if (item == y)
                                           {
                                               classlabroomlist->SetItemChecked(i, true);
                                               break;
                                           }
                                       }
                                       s = "";
                                   }
                                   else
                                       s += cell;
                               }
                           }
                       }
                   }
               }
           }

           void textBox_KeyDownRoom(Object^ sender, KeyEventArgs^ e)
           {
               if (e->KeyCode == Keys::Enter)
               {
                   ComponentFactory::Krypton::Toolkit::KryptonComboBox^ textBox = dynamic_cast<ComponentFactory::Krypton::Toolkit::KryptonComboBox^>(sender);
                   if (textBox != nullptr)
                   {
                       editroomcsvshow("details/classroom.csv");
                   }
               }
           }

           void textBox_KeyDownsubject(Object^ sender, KeyEventArgs^ e)
           {
               if (e->KeyCode == Keys::Enter)
               {
                   ComponentFactory::Krypton::Toolkit::KryptonComboBox^ textBox = dynamic_cast<ComponentFactory::Krypton::Toolkit::KryptonComboBox^>(sender);
                   if (textBox != nullptr)
                   {
                       editsubjectcsvshow();

                   }
               }
           }

           void OnSearchBoxFocus(Object^ sender, EventArgs^ e)
           {
               // Clear placeholder text and change text color
               if (teachersearch->Text == "Search")
               {
                   teachersearch->Text = "";
                   teachersearch->ForeColor = Color::Black; // Change text color to black when focused
               }
           }

           void OnSearchBoxLostFocus(Object^ sender, EventArgs^ e)
           {
               // Restore placeholder text if search box is empty
               if (String::IsNullOrEmpty(teachersearch->Text))
               {
                   teachersearch->Text = "Search";
                   teachersearch->ForeColor = Color::Gray; // Change text color to gray when unfocused
               }
           }

           void OnSearchBoxFocusRoom(Object^ sender, EventArgs^ e)
           {
               // Clear placeholder text and change text color
               if (editroomsearch->Text == "Search")
               {
                   editroomsearch->Text = "";
                   editroomsearch->ForeColor = Color::Black; // Change text color to black when focused
               }
           }

           void OnSearchBoxLostFocusRoom(Object^ sender, EventArgs^ e)
           {
               // Restore placeholder text if search box is empty
               if (String::IsNullOrEmpty(editroomsearch->Text))
               {
                   editroomsearch->Text = "Search";
                   editroomsearch->ForeColor = Color::Gray; // Change text color to gray when unfocused
               }
           }

           void OnSearchBoxFocusSub(Object^ sender, EventArgs^ e)
           {
               // Clear placeholder text and change text color
               if (editsubsearch->Text == "Search")
               {
                   editsubsearch->Text = "";
                   editsubsearch->ForeColor = Color::Black; // Change text color to black when focused
               }
           }

           void OnSearchBoxLostFocusSub(Object^ sender, EventArgs^ e)
           {
               // Restore placeholder text if search box is empty
               if (String::IsNullOrEmpty(editsubsearch->Text))
               {
                   editsubsearch->Text = "Search";
                   editsubsearch->ForeColor = Color::Gray; // Change text color to gray when unfocused
               }
           }

           void deptcsvgen(DataGridView^ classlab, const string filePath) {
               try
               {
                   ofstream outputFile(filePath);
                   if (outputFile.is_open())
                   {
                       for (int i = 0; i < classlab->RowCount - 1; ++i)
                       {

                           if (classlab->Rows[i]->Cells[0]->Value != nullptr)
                           {
                               System::String^ cellvalue = classlab->Rows[i]->Cells[0]->Value->ToString();
                               string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                               outputFile << CellValue;

                           }outputFile << '\n';

                       }outputFile.close();
                   }                MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
               }
               catch (...)
               {
                   MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           vector<vector<string>> ReadCSVFile(const string& filename) {
               l.logs.log("Inside ReadCSVFile");
               ifstream file(filename);
               vector<vector<string>> data;
               string line;

               while (getline(file, line)) {
                   stringstream lineStream(line);
                   vector<string> row;
                   string cell;

                   while (getline(lineStream, cell, ',')) {
                       row.push_back(cell);
                       l.logs.log(cell);
                   }

                   data.push_back(row);
               }
               file.close();

               return data;
           }
           void DisplayCSVInDataGridView(ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlabs, const string& filename) {
               try
               {
                   classlabs->Rows->Clear();
                   vector<vector<string>> data = ReadCSVFile(filename);

                   for (const auto& row : data) {
                       String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[0]);
                       classlabs->Rows->Add(rowStringManaged);
                   }
               }
               catch (...)
               {

               }
           }
           void DisplayCSVInComboBoxkrypt(const string& filename, ComponentFactory::Krypton::Toolkit::KryptonComboBox^ comboBox) {
               comboBox->Items->Clear();
               vector<string> it;
               vector<vector<string>> data = ReadCSVFile(filename);

               for (const auto& row : data) {
                   it.push_back(replaceunderscore(row[0]));
               }
               std::sort(it.begin(), it.end());
               for (int i = 0; i < it.size(); i++)
               {
                   comboBox->Items->Add(msclr::interop::marshal_as<String^>(it[i]));
               }
           }
           void DisplayCSVInComboBoxsub(const string& filename, ComponentFactory::Krypton::Toolkit::KryptonComboBox^ comboBox) {
               comboBox->Items->Clear();
               vector<string> it;
               vector<vector<string>> data = ReadCSVFile(filename);
               vector<vector<string>> sub = ReadCSVFile("details/subject_file.csv");
               for (const auto& row : data) {
                   for (int i = 1; i < row.size(); i++)
                   {
                       if (row[i] != "0")
                       {
                           string rowString = row[i] + "(" + row[0] + ")";
                           it.push_back(replaceunderscore(rowString));
                       }
                   }
               }
               for (const auto& cell : sub)
               {
                   it.push_back(replaceunderscore(cell[0]));
               }
               std::sort(it.begin(), it.end());
               for (int i = 0; i < it.size(); i++)
               {
                   if (!comboBox->Items->Contains(msclr::interop::marshal_as<String^>(it[i])))
                       comboBox->Items->Add(msclr::interop::marshal_as<String^>(it[i]));
               }

           }
           void DisplayCluster(const string& filename, ComponentFactory::Krypton::Toolkit::KryptonComboBox^ comboBox) {
               comboBox->Items->Clear();
               vector<vector<string>> data = ReadCSVFile(filename);

               for (const auto& row : data) {
                   bool bools = true;
                   String^ rowStringManaged = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
                   for each (Object ^ item in comboBox->Items)
                   {
                       if (item->ToString() == rowStringManaged)
                           bools = false;
                   }
                   if (bools)
                   {
                       comboBox->Items->Add(rowStringManaged);
                   }
               }
           }

           void deletebutton(DataGridViewButtonColumn^ x, DataGridView^ classlab, System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
           {
               try
               {
                   if (e->ColumnIndex == x->Index && e->RowIndex >= 0)
                   {
                       int rowIndexToDelete = e->RowIndex;
                       classlab->Rows->RemoveAt(rowIndexToDelete);
                   }
               }
               catch (...)
               {

               }
           }
           void deletebuttonkrypt(DataGridViewButtonColumn^ x, ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlab, System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
           {
               try
               {
                   if (e->ColumnIndex == x->Index && e->RowIndex >= 0)
                   {
                       int rowIndexToDelete = e->RowIndex;
                       classlab->Rows->RemoveAt(rowIndexToDelete);
                   }
               }
               catch (...)
               {

               }
           }
           void deletebuttonlab(DataGridViewButtonColumn^ x, ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlab, System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
           {
               try
               {
                   if (e->ColumnIndex == x->Index && e->RowIndex >= 0)
                   {
                       int rowIndexToDelete = e->RowIndex;
                       for (int i = 0; i < labteachers.size(); i++)
                       {
                           if (labteachers[i][0] == replacewhitespace(msclr::interop::marshal_as<string>(classlab->Rows[rowIndexToDelete]->Cells[0]->Value->ToString())))
                           {
                               labteachers.erase(labteachers.begin() + i);
                           }
                       }
                       classlab->Rows->RemoveAt(rowIndexToDelete);
                   }
                   classlabcombo->Text = "";
                   classlabteachers->Rows->Clear();
               }
               catch (...)
               {

               }
           }
           void editbuttonlab(DataGridViewTextBoxColumn^ x, ComponentFactory::Krypton::Toolkit::KryptonDataGridView^ classlab, System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
           {
               try
               {
                   if (e->ColumnIndex == x->Index && e->RowIndex >= 0)
                   {
                       int rowIndexToDelete = e->RowIndex;
                       classlabteachers->Rows->Clear();
                       classbatches->Value = 0;
                       classsessions->Value = 0;
                       for (int i = 0; i < classlabroomlist->Items->Count; i++) {
                           classlabroomlist->SetItemChecked(i, false);
                       }
                       string find = replacewhitespace(msclr::interop::marshal_as<string>(classlab->Rows[rowIndexToDelete]->Cells[0]->Value->ToString()));
                       for (const auto& row : labteachers)
                       {
                           if (row[0] == find)
                           {
                               classlabcombo->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
                               classbatches->Text = msclr::interop::marshal_as<String^>(row[1]);
                               classsessions->Text = msclr::interop::marshal_as<String^>(row[2]);
                               bool flag = false;
                               for (int i = 3; i < row.size() - 1; i++)
                               {
                                   classlabteachers->Rows->Add(msclr::interop::marshal_as<String^>(replaceunderscore(row[i])));
                               }
                               string s;
                               for (const char& cell : row[row.size() - 1])
                               {
                                   if (cell == '[')
                                       continue;
                                   else if (cell == ',' || cell == ']')
                                   {
                                       String^ y = msclr::interop::marshal_as<String^>(replaceunderscore(s));
                                       for (int i = 0; i < classlabroomlist->Items->Count; i++)
                                       {

                                           String^ item = classlabroomlist->Items[i]->ToString();
                                           if (item == y)
                                           {
                                               classlabroomlist->SetItemChecked(i, true);
                                               break;
                                           }
                                       }
                                       s = "";
                                   }
                                   else
                                       s += cell;
                               }
                               if (classlabroomlist->CheckedItems->Count > classbatches->Value)
                               {
                                   classoptrooms->Checked = true;
                               }
                           }
                       }
                   }
               }
               catch (...)
               {

               }
           }

           void Button_click(Object^ sender, EventArgs^ e)
           {
               Button^ clickedButton = dynamic_cast<Button^>(sender);
               if (clickedButton != nullptr) {
                   // Toggle the text of the clicked button
                   if (clickedButton->Text == "Available")
                   {
                       clickedButton->Text = addsubname->Text;
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   else if (clickedButton->Text == addsubname->Text)
                   {
                       clickedButton->Text = "Available";
                       clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                   }
                   else if (clickedButton->Text == "free")
                   {
                       clickedButton->Text = "Busy";
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   else if (clickedButton->Text == "Busy")
                   {
                       clickedButton->Text = "free";
                       clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                   }

               }
           }

           void Button_clicks(Object^ sender, EventArgs^ e)
           {
               Button^ clickedButton = dynamic_cast<Button^>(sender);
               if (clickedButton != nullptr) {
                   // Toggle the text of the clicked button
                   if (clickedButton->Text == "Available")
                   {
                       clickedButton->Text = addsubname->Text;
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   if (clickedButton->Text == addsubname->Text)
                   {
                       clickedButton->Text = "Available";
                       clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                   }
                   if (clickedButton->Text == "Open")
                   {
                       clickedButton->Text = "Reserved";
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   else if (clickedButton->Text == "Reserved")
                   {
                       clickedButton->Text = "Open";
                       clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                   }
               }
           }

           void Button_clickEle(Object^ sender, EventArgs^ e)
           {
               Button^ clickedButton = dynamic_cast<Button^>(sender);
               if (clickedButton != nullptr) {
                   // Toggle the text of the clicked button
                   if (clickedButton->Text == "Available")
                   {
                       clickedButton->Text = addsubname->Text;
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   else if (clickedButton->Text == "blocked" || clickedButton->Text == addsubname->Text)
                   {
                       clickedButton->Text = "Available";
                       clickedButton->BackColor = Color::FromArgb(230, 255, 255);
                   }

               }
           }
           void Button_clickEditEle(Object^ sender, EventArgs^ e)
           {
               Button^ clickedButton = dynamic_cast<Button^>(sender);
               if (clickedButton != nullptr) {
                   // Toggle the text of the clicked button
                   if (clickedButton->Text == "Available")
                   {
                       clickedButton->Text = editsubname->Text;
                       clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                   }
                   else if (clickedButton->Text == editsubname->Text)
                   {
                       clickedButton->Text = "Available";
                       clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                   }

               }
           }

           void change(Button^ clickedButton)
           { // Toggle the text of the clicked button
               if (clickedButton->Text == "free")
               {
                   clickedButton->Text = "Busy";
                   clickedButton->BackColor = Color::FromArgb(160, 252, 255);
               }
               else
               {
                   clickedButton->Text = "free";
                   clickedButton->BackColor = Color::FromArgb(210, 255, 255);
               }
           }

           string replacewhitespace(string text)
           {
               replace(text.begin(), text.end(), ' ', '_');
               return text;
           }

           string replaceunderscore(string text)
           {
               replace(text.begin(), text.end(), '_', ' ');
               return text;
           }

           void addnamecsvgen(string filePath)
           {
               try
               {
                   bool flag = true;
                   string find = replacewhitespace(msclr::interop::marshal_as<string>(addteachername->Text));
                   if (searchname(find, "details/teacher_file.csv", 0))
                   {
                       System::Windows::Forms::DialogResult Result = MessageBox::Show("Teacher name already exists.\nDo you want to replace the teacher.", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
                       if (Result == System::Windows::Forms::DialogResult::No)
                           flag = false;
                       else 
                       {
                           string x;
                           String^ name = addteachername->Text->ToString();
                           string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                           x += Name + ",";
                           String^ cap = addteacherdepartment->Text->ToString();
                           string Cap = msclr::interop::marshal_as<string>(cap);
                           x += Cap + ",";
                           String^ ename = addteacheremailid->Text->ToString();
                           string eName = (msclr::interop::marshal_as<string>(ename));
                           x += eName + ",";
                           for (int i = 1; i <= 36; ++i)
                           {
                               String^ tagValue = i.ToString();
                               Button^ button = dynamic_cast<Button^>(addroomtablepanel->Controls[String::Format("buttonteacher{0}", tagValue)]);
                               if (button != nullptr)
                               {
                                   if (button->Text == "Busy")
                                   {
                                       x += "1,0";
                                   }
                                   else if (button->Text == "Free")
                                   {
                                       x += "0,0";
                                   }
                                   if (i != 36)
                                   {
                                       x += ",";
                                   }
                               }
                           }
                           x += "\n";
                           replacename(find, filePath, 0, x);
                           flag = false;
                       }
                   }
                   if (flag)
                   {
                       ofstream outputFile;
                       outputFile.open((filePath), ios::app);
                       if (outputFile.is_open())
                       {
                           {	String^ name = addteachername->Text->ToString();
                           string Name = msclr::interop::marshal_as<string>(name);
                           string teachername = replacewhitespace(Name);
                           outputFile << teachername << ",";
                           String^ dep = addteacherdepartment->Text->ToString();
                           string Dep = msclr::interop::marshal_as<string>(dep);
                           string Depname = replacewhitespace(Dep);
                           outputFile << Depname << ",";
                           String^ ename = addteacheremailid->Text->ToString();
                           string eName = (msclr::interop::marshal_as<string>(ename));
                           outputFile << eName << ",";
                           for (int i = 1; i <= 36; ++i)
                           {
                               String^ tagValue = i.ToString();
                               Button^ button = dynamic_cast<Button^>(teachertablepanel->Controls[String::Format("buttonteacher{0}", tagValue)]);
                               if (button != nullptr)
                               {
                                   if (button->Text == "Busy")
                                   {
                                       outputFile << "1,0";
                                   }
                                   else if (button->Text == "Free")
                                   {
                                       outputFile << "0,0";
                                   }
                                   if (i != 36)
                                   {
                                       outputFile << ",";
                                   }
                               }
                           }outputFile << "\n";
                           outputFile.close();
                           }
                       }

                       MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                   }
               }
               catch (...)
               {
                   MessageBox::Show("Error occured while saving Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           bool searchname(string find, string filename, int n)
           {
               for (char& a : find)
               {
                   a = toupper(static_cast<unsigned char>(a));
               }
               fstream file;
               file.open(filename);
               string line;
               while (getline(file, line))
               {
                   stringstream lineStream(line);
                   vector<string> rows;
                   string cell;
                   while (getline(lineStream, cell, ',')) {
                       rows.push_back(cell);
                   }
                   for (char& a : rows[n])
                   {
                       a = toupper(static_cast<unsigned char>(a));
                   }
                   if (rows[n] == find)
                   {
                       return true;
                   }

               }
               file.close();
               return false;
           }

           void replacename(string find, string filename, int n, string x)
           {
               for (char& a : find)
               {
                   a = toupper(static_cast<unsigned char>(a));
               }
               vector<vector<string>>data = ReadCSVFile(filename);
               ofstream file(filename);
               bool flag = true;
               if (file.is_open())// Temporary file
               {
                   for (auto& row : data)
                   {
                       string str;
                       for (char& a : row[n])
                       {
                           str+= toupper(static_cast<unsigned char>(a));
                       }
                       if (str == find)
                       {
                           file << x;
                           flag = false;
                       }
                       else
                       {
                           for (int i = 0; i < row.size() - 1; i++)
                           {
                               file << row[i] << ",";
                           }
                           file << row[row.size() - 1] << "\n";
                       }
                   }
               }
               if (flag)
               {
                   file << x;
               }
               file.close();
           }

           void classroomcsvcreate(const string filePath)
           {
               try
               {
                   bool flag = true;
                   string find = replacewhitespace(msclr::interop::marshal_as<string>(roomname->Text));
                   if (searchname(find, "details/classroom.csv", 0))
                   {
                       System::Windows::Forms::DialogResult Result = MessageBox::Show("Room name already exists.\nDo you want to replace the room.", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
                       if (Result == System::Windows::Forms::DialogResult::No)
                           flag = false;
                       else 
                       {
                           string x;
                           String^ name = roomname->Text->ToString();
                           string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                           x += Name + ",";
                           String^ cap = roomcapacity->Text->ToString();
                           string Cap = msclr::interop::marshal_as<string>(cap);
                           x += Cap + ",";
                           if (roomlabyes->Checked)
                           {
                               x = x + "1" + ",";
                           }
                           else
                           {
                               x = x + "0" + ",";
                           }
                           System::String^ dep = roomdept->Text->ToString();
                           std::string Dep = replacewhitespace(msclr::interop::marshal_as<string>(dep));
                           x += Dep + ",";
                           for (int i = 1; i <= 36; ++i)
                           {
                               String^ tagValue = i.ToString();
                               Button^ button = dynamic_cast<Button^>(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);
                               if (button != nullptr)
                               {
                                   if (button->Text == "Busy")
                                   {
                                       x += "1,0";
                                   }
                                   else if (button->Text == "Free")
                                   {
                                       x += "0,0";
                                   }
                                   if (i != 36)
                                   {
                                       x += ",";
                                   }
                               }
                           }
                           x += "\n";
                           replacename(find, filePath, 0, x);
                           flag = false;
                       }
                   }
                   if (flag)
                   {
                       ofstream outputFile;
                       outputFile.open(filePath, ios::app);
                       if (outputFile.is_open())
                       {
                           {	String^ name = roomname->Text->ToString();
                           string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                           outputFile << Name << ",";
                           String^ cap = roomcapacity->Text->ToString();
                           string Cap = msclr::interop::marshal_as<string>(cap);
                           outputFile << Cap << ",";
                           if (roomlabyes->Checked)
                           {
                               outputFile << "1" << ",";
                           }
                           else
                           {
                               outputFile << "0" << ",";
                           }
                           System::String^ dep = roomdept->Text->ToString();
                           std::string Dep = replacewhitespace(msclr::interop::marshal_as<string>(dep));
                           outputFile << Dep << ",";
                           for (int i = 1; i <= 36; ++i)
                           {
                               String^ tagValue = i.ToString();
                               Button^ button = dynamic_cast<Button^>(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);
                               if (button != nullptr)
                               {
                                   if (button->Text == "Busy")
                                   {
                                       outputFile << "1,0";
                                   }
                                   else if (button->Text == "Free")
                                   {
                                       outputFile << "0,0";
                                   }
                                   if (i != 36)
                                   {
                                       outputFile << ",";
                                   }
                               }
                           }outputFile << "\n";
                           outputFile.close();
                           }
                       }                MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                   }
               }
               catch (...)
               {
                   MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           void subcsvgen(String^ filePath)
           {
               try {
                   bool flag = true;
                   string find = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
                   if (searchname(find, "details/subject_file.csv", 0))
                   {
                       System::Windows::Forms::DialogResult Result = MessageBox::Show("Subject already exists.\nDo you want to replace the subject", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
                       if (Result == System::Windows::Forms::DialogResult::No)
                           flag = false;
                       else 
                       {
                           flag = false;
                           string x;
                           String^ name = addsubname->Text->ToString();
                           string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                           x += Name + ",";
                           String^ Tname = addsubtitle->Text->ToString();
                           string TName = replacewhitespace(msclr::interop::marshal_as<string>(Tname));
                           x += TName + ",";
                           String^ Cname = addsubcode->Text->ToString();
                           string CName = replacewhitespace(msclr::interop::marshal_as<string>(Cname));
                           x += CName + ",";
                           if (addsubeleyes->Checked)
                           {
                               x = x + "1" + ",";
                           }
                           else
                           {
                               x = x + "0" + ",";
                           }
                           x = x + "0" + ",";
                           String^ cap = addsubcredits->Text->ToString();
                           string Cap = msclr::interop::marshal_as<string>(cap);
                           x += Cap + ",";
                           x += "1,";
                           String^ Bfact = addsubbfactor->Text->ToString();
                           string BFact = msclr::interop::marshal_as<string>(Bfact);
                           x += BFact + ",";
                           x += "[";
                           bool y = true;
                           for (int i = 0; i < addsubroomlist->CheckedItems->Count; ++i) {
                               String^ value = addsubroomlist->CheckedItems[i]->ToString();
                               std::string Value = replacewhitespace(msclr::interop::marshal_as<string>(value));
                               x += Value;
                               y = false;
                               if (i < addsubroomlist->CheckedItems->Count - 1) {
                                   x += ",";// Add a comma after each value, except the last one
                               }
                           }
                           if (y)
                           {
                               x += "0";
                           }
                           x += "]\n";
                           replacename(find, "details/subject_file.csv", 0, x);
                           flag = false;
                       }
                   }

                   if (flag)
                   {
                       ofstream outputFile;
                       outputFile.open(("details/subject_file.csv"), ios::app);
                       if (outputFile.is_open())
                       {
                           String^ name = addsubname->Text->ToString();
                           string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                           outputFile << Name << ",";
                           String^ title = addsubtitle->Text->ToString();
                           string Title = replacewhitespace(msclr::interop::marshal_as<string>(title));
                           outputFile << Title << ",";
                           String^ code = addsubcode->Text->ToString();
                           string Code = replacewhitespace(msclr::interop::marshal_as<string>(code));
                           outputFile << Code << ",";
                           {if (addsubeleyes->Checked)
                           {
                               String^ ele = addsubcluster->Text->ToString();
                               string Ele = replacewhitespace(msclr::interop::marshal_as<string>(ele));
                               outputFile << Ele << ",";

                               vector<string> teachers;
                               for (int i = 0; i < sedataGridView->RowCount - 1; ++i)
                               {
                                   if (sedataGridView->Rows[i]->Cells[0]->Value != nullptr)
                                   {
                                       System::String^ cellvalue = sedataGridView->Rows[i]->Cells[0]->Value->ToString();
                                       string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                                       teachers.push_back(CellValue);
                                   }
                               }
                           }
                           else if (addsubeleno->Checked)
                           {
                               outputFile << "0,";
                           }}
                           outputFile << "0,";
                           System::String^ credits = addsubcredits->Text->ToString();
                           std::string Credits = msclr::interop::marshal_as<string>(credits);
                           outputFile << Credits << ",";
                           outputFile << "1,";
                           System::String^ bfactor = addsubbfactor->Text->ToString();
                           std::string Bfactor = msclr::interop::marshal_as<string>(bfactor);
                           outputFile << Bfactor << ",";
                           //code to add roomlist
                           outputFile << "[";
                           bool x = true;
                           for (int i = 0; i < addsubroomlist->CheckedItems->Count; ++i) {
                               String^ value = addsubroomlist->CheckedItems[i]->ToString();
                               std::string Value = replacewhitespace(msclr::interop::marshal_as<string>(value));
                               outputFile << Value;
                               x = false;
                               if (i < addsubroomlist->CheckedItems->Count - 1) {
                                   outputFile << ",";// Add a comma after each value, except the last one
                               }
                           }
                           if (x)
                           {
                               outputFile << "0";
                           }
                           outputFile << "]\n";
                           outputFile.close();
                       }
                       MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                   }
               }
               catch (...)
               {
                   MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }
           void DisplayCSVInListBoxkrypt(const string& filename, ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox^ ListBox, int i) {
               ListBox->Items->Clear();
               vector<string> a;
               vector<vector<string>> data = ReadCSVFile(filename);

               for (const auto& row : data) {
                   a.push_back(replaceunderscore(row[i]));
               }
               std::sort(a.begin(), a.end());
               for (int i = 0; i < a.size(); i++)
               {
                   if (!ListBox->Items->Contains(msclr::interop::marshal_as<String^>(a[i])))
                       ListBox->Items->Add(msclr::interop::marshal_as<String^>(a[i]));
               }
           }

           void editcsvelectivee(const string filePath)
           {
               try
               {
                   string find = msclr::interop::marshal_as<string>(editsubsearch->Text);

                   vector<vector<string>>data = ReadCSVFile(filePath);
                   ofstream outputFile(filePath);

                   {
                       for (const auto& row : data)
                       {
                           if (find == row[0])
                           {
                               System::String^ name = editsubname->Text->ToString();
                               std::string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                               outputFile << Name << ",";
                               System::String^ elename = editsubcluster->Text->ToString();
                               std::string eleName = replacewhitespace(msclr::interop::marshal_as<string>(elename));
                               outputFile << eleName << ",";
                               for (int i = 0; i < editsubeleteacher->RowCount - 1; ++i)
                               {
                                   if (editsubeleteacher->Rows[i]->Cells[0]->Value != nullptr)
                                   {
                                       System::String^ cellvalue = editsubeleteacher->Rows[i]->Cells[0]->Value->ToString();
                                       std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                                       outputFile << CellValue << ",";
                                   }

                               }
                               outputFile << "\n";
                           }
                           else
                           {

                               for (int i = 0; i < row.size() - 1; i++)
                               {
                                   outputFile << row[i] + ",";
                               }
                               outputFile << row[row.size() - 1] << "\n";

                           }
                       }
                       outputFile.close();
                   }

               }
               catch (...)
               {
                   MessageBox::Show("Error saving Data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           System::Data::DataTable^ CreateDataTableFromCSV1(const std::string filePath, String^ name) {
               System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
               vector<string> it;
               dataTable->Columns->Add(name);
               vector<vector<string>> data = ReadCSVFile(filePath);
               for (const auto& row : data) {
                   if (!row.empty()) {
                       // Display only the first word before the comma
                       it.push_back(row[0]);
                   }
               }
               std::sort(it.begin(), it.end());
               for (int i = 0; i < it.size(); i++)
               {
                   dataTable->Rows->Add(msclr::interop::marshal_as<String^>(replaceunderscore(it[i])));
               }
               if (name == "cteacher" || name == "lteacher1" || name == "editsubeleteachercombo"|| name=="teacherName")
               {
                   dataTable->Rows->Add("No Teacher");
               }
               return dataTable;
           }

           std::string returnLine(std::string name, std::string path) {
               std::fstream file(path);
               for (int i = 0; i < 1000; i++) {
                   std::string line;
                   if (file.eof()) {
                       break;
                   }
                   file >> line;
                   int j;
                   for (j = 0; j < name.size(); j++) {
                       if (name[j] != line[j]) {
                           goto a;
                       }
                   }
                   return line;
               a:
                   continue;
               }
               file.close();
               return "not found";
           }

    public:
        void labcreate(vector<vector<string>> teachers, section& t)
        {
            for (auto row : teachers)
            {
                subject subj;
                vector<string> a;
                subj.name = row[0];
                subj.credits = stoi(row[2]);
                subj.hoursPerCredit = 2;
                subj.lab = 1;
                int noTeacher = 0;
                vector<string>lrooms;
                string s;
                for (char& cell : row[row.size() - 1])
                {
                    if (cell == '[')
                        continue;
                    else if (cell == ',' || cell == ']')
                    {
                        lrooms.push_back(s);
                        s = "";
                    }
                    else
                        s += cell;
                }
                subj.rooms = lrooms;
                for (int i = 3; i < row.size() - 1; i++)
                {
                    a.push_back(row[i]);
                    noTeacher++;
                }
                int functionTeacherNo = noTeacher / stoi(row[1]) + !(!(noTeacher % stoi(row[1])));
                while (noTeacher < functionTeacherNo * stoi(row[1]))
                {
                    a.push_back(row[3]);
                    noTeacher++;
                }
                t.addLab(a, subj, stoi(row[1]), functionTeacherNo);
            }
        }

        void editteachercsvshow(const string filename)
        {
            bool flag = true;
            string* a = &searchteachername;
            string find = replacewhitespace(msclr::interop::marshal_as<string>(teachersearch->Text));
            vector<vector<string>>data = ReadCSVFile(filename);
            {
                for (auto& row : data)
                {
                    string str;
                    for (char& c : find) {
                        c = std::toupper(static_cast<unsigned char>(c)); // Cast char to unsigned char before calling toupper
                    }
                    for (char& c : row[0]) {
                        str += std::toupper(static_cast<unsigned char>(c)); // Cast char to unsigned char before calling toupper
                    }
                    if (find == str)
                    {
                        flag = false;
                        *a = row[0];
                        editteachername->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
                        editteacherdepartment->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[1]));
                        editteacheremailid->Text = msclr::interop::marshal_as<String^>(row[2]);
                        for (int i = 3; i < row.size(); i += 2)
                        {
                            int x = i / 2;
                            String^ tagValue = x.ToString();
                            Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
                            if (row[i] == "1")
                            {
                                if (row[i + 1] == "0")
                                {
                                    button->Text = "Busy";
                                    button->BackColor = Color::FromArgb(160, 252, 255);
                                }
                                else
                                {
                                    button->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[i + 1]));
                                    button->BackColor = Color::FromArgb(160, 252, 255);
                                }
                            }
                            else
                            {
                                button->Text = "Free";
                                button->BackColor = Color::FromArgb(210, 255, 255);
                            }
                        }

                    }

                }
            }
            if (flag)
            {
                MessageBox::Show("Teacher not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }

        void editteachercsvsave(const string filename)

        {
            try
            {
                string find = searchteachername;
                bool flag = true;
                vector<vector<string>>data = ReadCSVFile(filename);
                ofstream file(filename);
                {
                    for (const auto& row : data)
                    {
                        if (find == row[0])
                        {
                            flag = false;
                            file << replacewhitespace(msclr::interop::marshal_as<string>(editteachername->Text->ToString()));
                            file << ",";
                            file << replacewhitespace(msclr::interop::marshal_as<string>(editteacherdepartment->Text->ToString()));
                            file << ",";
                            file << (msclr::interop::marshal_as<string>(editteacheremailid->Text->ToString()));
                            file << ",";
                            for (int i = 1; i < 37; i++)
                            {

                                String^ tagValue = i.ToString();
                                Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);

                                if (button != nullptr)
                                {
                                    if (button->Text == "Busy")
                                    {
                                        file << "1,0";
                                    }
                                    else if (button->Text == "Free")
                                    {
                                        file << "0,0";
                                    }
                                    if (i != 36)
                                    {
                                        file << ",";
                                    }
                                }
                            }file << "\n";
                            MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                        }
                        else
                        {
                            for (int i = 0; i < row.size() - 1; i++)
                            {
                                file << row[i] + ",";
                            }
                            file << row[row.size() - 1] << "\n";
                        }
                    }
                }file.close();
                if (flag)
                {
                    MessageBox::Show("Teacher not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                }

            }
            catch (...)
            {
                MessageBox::Show("Error saving changes", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void editteachercsvdelete(const string filename)
        {
            try
            {
                string find = searchteachername;
                bool flag = true;
                vector<vector<string>>data = ReadCSVFile(filename);
                ofstream file(filename);
                {
                    for (const auto& row : data)
                    {
                        if (find == row[0])
                        {
                            flag = false;
                            MessageBox::Show("Deleted successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                            DeleteTeacherFromCSV(row[0], "details/Electivetimetable.csv");
                        }
                        else
                        {
                            for (int i = 0; i < row.size() - 1; i++)
                            {
                                file << row[i] + ",";
                            }
                            file << row[row.size() - 1] << "\n";
                        }
                    }
                }file.close();
                if (flag)
                {
                    MessageBox::Show("Teacher not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                }
            }
            catch (...)
            {
                MessageBox::Show("Error deleting data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void editroomcsvshow(const string filename)
        {
            string* a = &searchroomname;
            string find = replacewhitespace(msclr::interop::marshal_as<string>(editroomsearch->Text));
            bool flag = true;
            vector<vector<string>>data = ReadCSVFile(filename);
            for (auto& row : data)
            {
                string str;
                for (char& r : find)
                {
                    r = toupper(static_cast<unsigned char>(r));
                }
                for (char& r : row[0])
                {
                    str += toupper(static_cast<unsigned char>(r));
                }
                if (find == str) {
                    flag = false;
                    *a = row[0];
                    editroomname->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
                    editroomcapacity->Text = msclr::interop::marshal_as<String^>(row[1]);
                    if (row[2] == "0")
                    {
                        editroomlabno->Checked = true;
                    }
                    else
                    {
                        editroomlabyes->Checked = true;
                    }
                    editroomdepartment->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[3]));

                    for (int i = 4; i < row.size(); i += 2)
                    {
                        int x = (i / 2) - 1;
                        String^ tagValue = x.ToString();
                        Button^ button = dynamic_cast<Button^>(editroomtablepanel->Controls[String::Format("buttoneditroom{0}", tagValue)]);
                        if (row[i] == "1")
                        {
                            if (row[i + 1] == "0")
                            {
                                button->Text = "Busy";
                                button->BackColor = Color::FromArgb(160, 252, 255);
                            }
                            else
                            {
                                button->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[i + 1]));
                                button->BackColor = Color::FromArgb(160, 252, 255);
                            }
                        }
                        else
                        {
                            button->Text = "Free";
                            button->BackColor = Color::FromArgb(210, 255, 255);
                        }
                    }
                }
            }
            if (flag)
            {
                MessageBox::Show("Room not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }

        void editroomcsvsave(const string filename)
        {
            try {
                string find = searchroomname;
                bool flag = true;
                vector<vector<string>>data = ReadCSVFile(filename);
                ofstream file(filename);
                {
                    for (const auto& row : data)
                    {
                        if (find == row[0]) {
                            flag = false;
                            file << replacewhitespace(msclr::interop::marshal_as<string>(editroomname->Text)) << ",";
                            file << msclr::interop::marshal_as<string>(editroomcapacity->Text) << ",";
                            if (editroomlabyes->Checked)
                            {
                                file << "1,";
                            }
                            else
                            {
                                file << "0,";
                            }
                            file << replacewhitespace(msclr::interop::marshal_as<string>(editroomdepartment->Text)) << ",";

                            for (int i = 1; i < 37; i++)
                            {
                                String^ tagValue = i.ToString();
                                Button^ button = dynamic_cast<Button^>(editroomtablepanel->Controls[String::Format("buttoneditroom{0}", tagValue)]);
                                if (button != nullptr)
                                {
                                    if (button->Text == "Free")
                                    {
                                        file << "0,0";
                                    }
                                    else
                                    {
                                        file << "1,0";
                                    }
                                    if (i != 36)
                                    {
                                        file << ",";
                                    }
                                    else
                                    {
                                        file << "\n";
                                    }
                                }
                            }
                            MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                        }
                        else
                        {
                            for (int i = 0; i < row.size() - 1; i++)
                            {
                                file << row[i] + ",";
                            }
                            file << row[row.size() - 1] << "\n";
                        }
                    }
                }file.close();
                if (flag)
                {
                    MessageBox::Show("Room not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                }
            }
            catch (...)
            {
                MessageBox::Show("Error Saving data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void editroomcsvdelete(const string filename)
        {
            string find = searchroomname;

            vector<vector<string>>data = ReadCSVFile(filename);
            bool flag = true;
            ofstream file(filename);
            {
                for (const auto& row : data)
                {
                    if (find == row[0]) {
                        flag = false;
                        MessageBox::Show("Deleted successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                    }
                    else
                    {
                        for (int i = 0; i < row.size() - 1; i++)
                        {
                            file << row[i] + ",";
                        }
                        file << row[row.size() - 1] << "\n";
                    }
                }
            }file.close();
            if (flag)
            {
                MessageBox::Show("Room not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }

        void editsubjectcsvshow()
        {
            string* a = &searchsubname;
            string find = replacewhitespace(msclr::interop::marshal_as<string>(editsubsearch->Text));
            bool flag = true;
            vector<vector<string>>data = ReadCSVFile("details/subject_file.csv");
            for (auto& row : data)
            {
                if (row[0] == find)
                {
                    editsubname->ReadOnly = false;
                    editsubtitle->ReadOnly = false;
                    editsubcode->ReadOnly = false;
                    editsubeleyes->Enabled = true;
                    editsubeleno->Enabled = true;
                    editsubcluster->Cursor = Cursors::Arrow;
                    editsubname->Cursor = Cursors::Arrow;
                    editsubtitle->Cursor = Cursors::Arrow;
                    editsubcode->Cursor = Cursors::Arrow;

                    flag = false;
                    *a = find;
                    editsubname->Text = msclr::interop::marshal_as<String^>(row[0]);
                    editsubtitle->Text = msclr::interop::marshal_as<String^>(row[1]);
                    editsubcode->Text = msclr::interop::marshal_as<String^>(row[2]);
                    if (row[3] == "0")
                    {
                        editsubeleno->Checked = true;
                        editsubcluster->Text = "";
                        editsubeleteacher->Rows->Clear();
                    }
                    editsubcredits->Text = msclr::interop::marshal_as<String^>(row[5]);
                    editsubbfactor->Text = msclr::interop::marshal_as<String^>(row[7]);
                    for (int i = 0; i < editsubroomlist->Items->Count; i++) {
                        editsubroomlist->SetItemChecked(i, false);
                    }

                    if (row.size() == 8) {
                        String^ y = msclr::interop::marshal_as<String^>(row[8].erase(0, 1).substr(0, (row[8].length()) - 1));
                        for (int i = 0; i < editsubroomlist->Items->Count; i++)
                        {

                            String^ item = editsubroomlist->Items[i]->ToString();
                            if (item == y)
                            {
                                editsubroomlist->SetItemChecked(i, true);
                                break;
                            }
                        }

                    }
                    else
                    {
                        String^ y = msclr::interop::marshal_as<String^>(row[8].erase(0, 1));
                        for (int i = 0; i < editsubroomlist->Items->Count; i++)
                        {

                            String^ item = editsubroomlist->Items[i]->ToString();
                            if (item == y)
                            {
                                editsubroomlist->SetItemChecked(i, true);
                                break;
                            }
                        }
                        for (int j = 9; j < row.size() - 1; j++)
                        {
                            String^ searchString = msclr::interop::marshal_as<String^>(row[j]);
                            for (int i = 0; i < editsubroomlist->Items->Count; i++)
                            {

                                String^ item = editsubroomlist->Items[i]->ToString();
                                if (item == searchString)
                                {
                                    editsubroomlist->SetItemChecked(i, true);
                                    break;
                                }
                            }
                        }

                        String^ searchString = msclr::interop::marshal_as<String^>(row[row.size() - 1].substr(0, row[row.size() - 1].length() - 1));
                        for (int i = 0; i < editsubroomlist->Items->Count; i++)
                        {

                            String^ item = editsubroomlist->Items[i]->ToString();
                            if (item == searchString)
                            {
                                editsubroomlist->SetItemChecked(i, true);
                                break;
                            }
                        }

                    }

                }

            }
            if (flag)
            {
                vector<vector<string>> ele = ReadCSVFile("details/Electivetimetable.csv");
                bool eleflag = true;
                string name, clust;
                bool e = false;
                for (char& n : find)
                {
                    if (n == '(')
                    {
                        e = true;
                        continue;
                    }
                    if (n == ')')
                        continue;
                    if (e)
                    {
                        clust += n;
                    }
                    else
                        name += n;
                }
                for (auto& elerow : ele)
                {

                    if (clust == elerow[0])
                    {
                        editsubname->ReadOnly = true;
                        editsubtitle->ReadOnly = true;
                        editsubcode->ReadOnly = true;
                        editsubeleyes->Enabled = false;
                        editsubeleno->Enabled = false;
                        editsubcluster->Cursor = Cursors::No;
                        editsubname->Cursor = Cursors::No;
                        editsubtitle->Cursor = Cursors::No;
                        editsubcode->Cursor = Cursors::No;
                        for (int i = 1; i < elerow.size(); i++)
                        {

                            if (name == elerow[i])
                            {

                                eleflag = false;
                                *a = find;
                                editsubelepanel->Visible = true;
                                editsubelepanel->Top = button3->Bottom;
                                // editpanelsub->Top = editsubelepanel->Bottom;
                                editsubname->Text = msclr::interop::marshal_as<String^>(elerow[i]);
                                editsubeleyes->Checked = true;
                                editsubcluster->Text = msclr::interop::marshal_as<String^>(elerow[0]);
                                for (int k = 1; k < 37; k++)
                                {
                                    Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", k)]);
                                    if (elerow[k] == "0")
                                    {
                                        button->Text = "Available";
                                        button->BackColor = Color::FromArgb(210, 255, 255);
                                    }
                                    else
                                    {
                                        button->Text = msclr::interop::marshal_as<String^>(elerow[k]);
                                        button->BackColor = Color::FromArgb(160, 252, 255);
                                    }
                                }
                                editsubeleteacher->Rows->Clear();
                                vector<vector<string>>teachers = ReadCSVFile("details/teacher_file.csv");
                                bool f = true;
                                for (const auto& teach : teachers)
                                {
                                    for (int n = 4; n < teach.size(); n += 2)
                                    {
                                        if (teach[n] == find)
                                        {
                                            f = false;
                                            editsubeleteacher->Rows->Add(msclr::interop::marshal_as<String^>(replaceunderscore(teach[0])));
                                            break;
                                        }
                                    }
                                }
                                if (f)
                                {
                                    editsubeleteacher->Rows->Add("No Teacher");
                                }
                                goto out;
                            }

                        }
                    }
                }
            out:
                if (eleflag)
                    MessageBox::Show("Subject not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }

        void editsubcsvsave(const string filename)
        {
            try {
                string find = searchsubname;
                bool ele;
                if (searchname(find, filename, 0))
                {
                    if (editsubeleyes->Checked)
                    {
                        string x = "";
                        vector<vector<string>>temp = ReadCSVFile("details/teacher_file.csv");
                        replacename(find, filename, 0, "");
                        x += msclr::interop::marshal_as<string>(editsubcluster->Text);
                        for (auto& row : temp)
                        {
                            for (int m = 4; m < row.size(); m += 2)
                            {
                                if (row[m] == find)
                                {
                                    row[m - 1] = "0";
                                    row[m] = "0";
                                }
                            }
                        }
                        for (int i = 1; i <= 36; i++)
                        {
                            Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", i)]);
                            if (button != nullptr)
                            {
                                if (button->Text == msclr::interop::marshal_as<String^>(find))
                                {
                                    x += "," + msclr::interop::marshal_as<string>(button->Text);

                                    for (auto& row : temp)
                                    {
                                        for (int j = 0; j < editsubeleteacher->RowCount; j++)
                                        {
                                            if (editsubeleteacher->Rows[j]->Cells[0]->Value != nullptr)
                                            {
                                                string s = replacewhitespace(msclr::interop::marshal_as<string>(editsubeleteacher->Rows[j]->Cells[0]->Value->ToString()));
                                                if (row[0] == s)
                                                {
                                                    row[(2 * i) + 1] = '1';
                                                    row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(editsubname->Text)) + "(" + replacewhitespace(msclr::interop::marshal_as<string>(editsubcluster->Text)) + ")";
                                                }
                                                else
                                                {
                                                }
                                            }
                                        }
                                    }

                                }
                                else
                                {
                                    if (button->Text == "Available")
                                        x += ",0";
                                    else if (button->Text == "Busy")
                                        x += ",0";
                                    else
                                        x += "," + msclr::interop::marshal_as<string>(button->Text);
                                }
                            }
                        }
                        x += "\n";
                        replacename(msclr::interop::marshal_as<string>(editsubcluster->Text), "details/Electivetimetable.csv", 0, x);
                        ofstream tFile("details/teacher_file.csv");
                        if (tFile.is_open()) {
                            for (const auto& t : temp) {
                                for (int i = 0; i < t.size() - 1; i++) {
                                    tFile << t[i] << ",";
                                }
                                tFile << t[t.size() - 1] << "\n";
                            }
                        }
                        tFile.close();
                        MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);

                    }
                    else
                    {
                        string x;
                        x += replacewhitespace(msclr::interop::marshal_as<string>(editsubname->Text)) + ",";
                        x += replacewhitespace(msclr::interop::marshal_as<string>(editsubtitle->Text)) + ",";
                        x += replacewhitespace(msclr::interop::marshal_as<string>(editsubcode->Text)) + ",";
                        x += "0,";
                        x += "0,";
                        x += msclr::interop::marshal_as<string>(editsubcredits->Text) + ",1,";
                        x += msclr::interop::marshal_as<string>(editsubbfactor->Text) + ",";
                        x += "[";
                        bool room = true;
                        for (int i = 0; i < editsubroomlist->CheckedItems->Count; ++i) {
                            String^ value = editsubroomlist->CheckedItems[i]->ToString();
                            x += replacewhitespace(msclr::interop::marshal_as<string>(value));
                            room = false;
                            if (i < editsubroomlist->CheckedItems->Count - 1) {
                                x += ",";// Add a comma after each value, except the last one
                            }
                        }
                        if (room)
                        {
                            x += "0";
                        }
                        x += "]\n";
                        replacename(find, filename, 0, x);
                        MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                        goto err;
                    }
                }
                else
                {
                    vector<vector<string>>ele = ReadCSVFile("details/Electivetimetable.csv");
                    string name, clust;
                    bool e = false;
                    for (char& n : find)
                    {
                        if (n == '(')
                        {
                            e = true;
                            continue;
                        }
                        if (n == ')')
                            continue;
                        if (e)
                        {
                            clust += n;
                        }
                        else
                            name += n;
                    }
                    for (auto& row : ele)
                    {
                        if (row[0] == clust)
                        {
                            if (clust != replacewhitespace(msclr::interop::marshal_as<string>(editsubcluster->Text)))
                            {
                                MessageBox::Show("Cluster name changed.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                editsubcluster->Text = msclr::interop::marshal_as<String^>(replaceunderscore(clust));
                                goto err;
                            }
                            for (int i = 1; i < row.size(); i++)
                            {
                                if (row[i] == name)
                                {
                                    //if elective
                                    vector < vector<string>> temp = ReadCSVFile("details/teacher_file.csv");
                                    bool nflag = false;
                                    for (int i = 1; i <= 36; i++)
                                    {
                                        Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", i)]);
                                        if (button != nullptr)
                                        {
                                            if (button->Text == editsubname->Text)
                                                nflag = true;
                                        }
                                    }
                                    if (!nflag)
                                    {
                                        MessageBox::Show("Block slots for the subject", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                        onOptionClickedit(editsubcluster, editsubeleteacher, editsubeletable, "editele", editsubname);
                                        goto err;
                                    }
                                    else
                                    {
                                        string file;
                                        bool first = true;
                                        file += row[0];
                                        for (int i = 1; i <= 36; i++)
                                        {
                                            Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", i)]);
                                            if (button != nullptr)
                                            {
                                                if (button->Text == editsubname->Text)
                                                {
                                                    file += "," + msclr::interop::marshal_as<string>(editsubname->Text);

                                                    for (auto& row : temp)
                                                    {
                                                        if (first)
                                                        {
                                                            for (int n = 4; n < row.size(); n += 2)
                                                            {
                                                                if (row[n] == find)
                                                                {
                                                                    row[n] = "0";
                                                                    row[n - 1] = "0";
                                                                }
                                                            }
                                                        }
                                                        for (int j = 0; j < editsubeleteacher->RowCount; j++)
                                                        {
                                                            if (editsubeleteacher->Rows[j]->Cells[0]->Value != nullptr)
                                                            {
                                                                if (row[0] == msclr::interop::marshal_as<string>(editsubeleteacher->Rows[j]->Cells[0]->Value->ToString()))
                                                                {
                                                                    row[(2 * i) + 1] = '1';
                                                                    row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(editsubname->Text)) + "(" + replacewhitespace(msclr::interop::marshal_as<string>(editsubcluster->Text)) + ")";
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    first = false;
                                                }
                                                else if (button->Text == "Busy" || button->Text == "Available")
                                                {
                                                    file += ",0";
                                                }
                                                else
                                                    file += "," + row[i];
                                            }
                                        }
                                        file += "\n";
                                        replacename(msclr::interop::marshal_as<string>(editsubcluster->Text), "details/Electivetimetable.csv", 0, file);
                                        ofstream tFile("details/teacher_file.csv");
                                        if (tFile.is_open()) {
                                            for (const auto& t : temp) {
                                                for (int i = 0; i < t.size() - 1; i++) {
                                                    tFile << t[i] << ",";
                                                }
                                                tFile << t[t.size() - 1] << "\n";
                                            }
                                        }
                                        tFile.close();
                                        MessageBox::Show("Replaced successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                        goto err;
                                    }
                                }
                            }
                        }
                    }
                }

                MessageBox::Show("Subject Not Found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            err:
                {}
            }
            catch (...)
            {
                MessageBox::Show("Error Saving data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void editsubcsvdelete(const string filename)
        {
            string find = searchsubname;
            vector<vector<string>>data = ReadCSVFile(filename);
            ofstream file(filename);
            bool flag = true;
            {
                for (const auto& row : data)
                {
                    if (find == row[0]) {
                        flag = false;
                        MessageBox::Show("Deleted successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                    }
                    else
                    {
                        for (int i = 0; i < row.size() - 1; i++)
                        {
                            file << row[i] + ",";
                        }
                        file << row[row.size() - 1] << "\n";
                    }
                }
            }file.close();
            if (flag)
            {
                bool subr = true;
                vector<vector<string>>ele = ReadCSVFile("details/Electivetimetable.csv");
                ofstream efile("details/Electivetimetable.csv");
                if (efile.is_open())
                {
                    string name, clust;
                    bool e = false;
                    for (char& n : find)
                    {
                        if (n == '(')
                        {
                            e = true;
                            continue;
                        }
                        if (n == ')')
                            continue;
                        if (e)
                        {
                            clust += n;
                        }
                        else
                            name += n;
                    }
                    for (auto& row : ele)
                    {
                        if (row[0] == clust)
                        {
                            efile << row[0];
                            for (int i = 1; i < row.size(); i++)
                            {
                                if (row[i] == name)
                                {
                                    subr = false;
                                    efile << ",0";
                                }
                                else
                                {
                                    efile << "," << row[i];
                                }
                            }
                            efile << "\n";
                        }
                        else
                        {
                            efile << row[0];
                            for (int i = 1; i < row.size(); i++)
                            {
                                efile << "," << row[i];
                            }
                            efile << "\n";
                        }
                    }
                    efile.close();

                }
                vector<vector<string>>temp = ReadCSVFile("details/teacher_file.csv");
                ofstream tfile("details/teacher_file.csv");
                if (tfile.is_open())
                {
                    for (auto& row : temp)
                    {
                        tfile << row[0] << "," << row[1] << "," << row[2];
                        for (int i = 4; i < row.size(); i += 2)
                        {
                            if (row[i] == find)
                            {
                                tfile << ",0,0";
                            }
                            else
                                tfile << "," << row[i - 1] << "," << row[i];
                        }
                        tfile << "\n";
                    }
                    tfile.close();
                }
                if (subr)
                {
                    MessageBox::Show("Subject not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                }
                else
                {
                    MessageBox::Show("Deleted successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                }
            }
        }

        void allroomsfunction(const string filename, section& t)
        {
            std::fstream outputFile(filename);
            string line;
            if (outputFile.is_open())
            {
                while (outputFile >> line)
                {
                    room obj;
                    obj.readData(line);
                    t.allRooms.push_back(obj);
                }
                room obj;
                string line = "No_Room,0,0,0";
                for (int i = 0; i < 72; i++)
                {
                    line += ",0";
                }
                line += "\n";
                obj.readData(line);
                t.allRooms.push_back(obj);
            }
            outputFile.close();
        }

        void allteachersfunction(const string filename, section& t)
        {
            fstream output(filename);
            string line;
            if (output.is_open())
            {

                while (output >> line)
                {
                    teacher obj;
                    obj.readData(line);
                    t.allTeachers.push_back(obj);
                }
                teacher obj;
                string line = "No_Teacher,nil,nil";
                for (int i = 0; i < 72; i++)
                {
                    line += ",0";
                }
                line += "\n";
                obj.readData(line);
                t.allTeachers.push_back(obj);
            }
            output.close();
        }

        void loadcore(section& obj)
        {
            for (int i = 0; i < classcore->RowCount; ++i)
            {
                if (classcore->Rows[i]->Cells[1]->Value != nullptr)
                {
                    subject sub;
                    sub.readData(returnLine(replacewhitespace(msclr::interop::marshal_as<string>(classcore->Rows[i]->Cells[0]->Value->ToString())), "details/subject_file.csv"));
                    obj.addCore(replacewhitespace(msclr::interop::marshal_as<string>(classcore->Rows[i]->Cells[1]->Value->ToString())), sub);
                }
            }
        }

        void defaultroomallot(section& obj)
        {
            vector<string>drooms;
            for each (int checkedIndex in classdefaultrooms->CheckedIndices)
            {
                String^ itemRoom = classdefaultrooms->Items[checkedIndex]->ToString();
                if (itemRoom == "No Room")
                {
                    drooms.push_back("No_Room");
                }
                else
                {
                    string ItemRoom = msclr::interop::marshal_as<string>(itemRoom);
                    vector < vector<string>>data = ReadCSVFile("details/classroom.csv");

                    for (const auto& row : data)
                    {
                        if (!row.empty())
                        {

                            if (ItemRoom == row[3] || row[2]=="0")
                            {
                                drooms.push_back(row[0]);
                            }
                        }
                    }
                }
            }
            obj.defaultRooms = drooms;
        }

        void DeleteTeacherFromCSV(string teacherName, string filename) {
            vector < vector<string>>data = ReadCSVFile(filename);
            ofstream file(filename);
            if (file.is_open())
            {
                for (auto& row : data)
                {
                    file << row[0] << "," << row[1];
                    for (int i = 2; i < row.size() - 1; i++)
                    {
                        if (teacherName == row[i])
                        {
                        }
                        else
                        {
                            file << "," << row[i];
                        }
                    }
                    if (teacherName == row[row.size() - 1])
                    {
                    }
                    else
                    {
                        file << row[row.size() - 1];
                    }
                    file << "\n";
                }
            }
            file.close();
        }
        vector<vector<bool>> returntimetable(string clustername)
        {
            l.logs.log("Inside returnTimeTable");
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector<vector<bool>>tt;
            vector<bool>ttval;
            bool flag = true;
            for (auto& row : data)
            {
                if (row[0] == clustername)
                {
                    flag = false;
                    int count = 0;
                    for (int i = 1; i < row.size(); i++)
                    {
                        count++;
                        if (row[i] == "0")
                        {
                            ttval.push_back(0);
                        }
                        else
                        {
                            ttval.push_back(1);
                        }
                        if (count == 6)
                        {
                            tt.push_back(ttval);
                            count = 0;
                            ttval.clear();
                        }
                    }
                }
            }
            if (flag)
            {
                int count = 0;
                for (int i = 1; i < 37; i++)
                {
                    count++;
                    ttval.push_back(0);
                    if (count == 6)
                    {
                        tt.push_back(ttval);
                        count = 0;
                        ttval.clear();
                    }
                }
            }
            return tt;
        }

        vector<vector<vector<bool>>>valuetimetable(string clustername, DataGridView^ sedataGridView, ComponentFactory::Krypton::Toolkit::KryptonTextBox^ addsubnames, ComponentFactory::Krypton::Toolkit::KryptonComboBox^ addsubclusts)
        {
            l.logs.log("Inside valueTimeTable");
            vector < vector < vector<bool>>>allt;
            vector<vector<bool>>tt;
            vector<bool>ttval;
            allt.push_back(returntimetable(clustername));
            vector<vector<string>>data = ReadCSVFile("details/teacher_file.csv");
            for (int i = 0; i < sedataGridView->RowCount; i++)
            {
                if (sedataGridView->Rows[i]->Cells[0]->Value != nullptr)
                {
                    string name = replacewhitespace(msclr::interop::marshal_as<string>(sedataGridView->Rows[i]->Cells[0]->Value->ToString()));
                    for (const auto& row : data)
                    {
                        if (name == row[0])
                        {
                            int count = 0;
                            for (int i = 3; i < row.size(); i += 2)
                            {
                                count++;
                                if (row[i] == "0" || row[i + 1] == replacewhitespace(msclr::interop::marshal_as<string>(addsubnames->Text)) + "(" + replacewhitespace(msclr::interop::marshal_as<string>(addsubclusts->Text)) + ")")
                                {
                                    ttval.push_back(0);
                                }
                                else
                                {
                                    ttval.push_back(1);
                                }
                                if (count == 6)
                                {
                                    tt.push_back(ttval);
                                    count = 0;
                                    ttval.clear();
                                }
                            }
                            allt.push_back(tt);
                            tt.clear();
                            break;
                        }
                    }
                }
            }
            return allt;
        }


        vector<vector<bool>> intersectionElective(std::vector<std::vector<std::vector<bool>>> inputs) {
            l.logs.log("Inside intersectionElective");
            std::vector<std::vector<bool>> output;//return type is a vector of vector of booleans
            std::vector<std::vector<int>> temp;//tempetrory vector that stores number of intersections
            //_intersections = 0;
            for (int i = 0; i < inputs[0].size(); i++) {//making a days*periods matrix
                std::vector<int>tempp;
                for (int j = 0; j < inputs[0][0].size(); j++) {
                    tempp.push_back(0);
                }
                temp.push_back(tempp);
            }
            for (std::vector<std::vector<bool>> each : inputs) {//incrementing when timetable free
                for (int i = 0; i < each.size(); i++) {
                    for (int j = 0; j < each[i].size(); j++) {
                        temp[i][j] += !each[i][j];
                    }
                }
            }
            for (int i = 0; i < inputs[0].size(); i++) {
                std::vector<bool>tempp;
                bool alloted = 0;
                for (int j = 0; j < inputs[0][0].size(); j++) {
                    tempp.push_back(!(temp[i][j] / (inputs.size())));
                    if (!alloted && !tempp[tempp.size() - 1]) {
                        alloted = 1;
                    }
                }
                output.push_back(tempp);
            }
            return output;
        }
        void onOptionClickedit(ComponentFactory::Krypton::Toolkit::KryptonComboBox^ addsubclusters, DataGridView^ dgv, TableLayoutPanel^ t, String^ s, ComponentFactory::Krypton::Toolkit::KryptonTextBox^ editsubnames)
        {
            string name = replacewhitespace(msclr::interop::marshal_as<string>(addsubclusters->Text));
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector < vector<string>> temp = ReadCSVFile("details/teacher_file.csv");
            vector<vector<bool>>intersecttt = intersectionElective(valuetimetable(name, dgv, editsubnames, addsubclusters));
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {

                    Button^ button = dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", i * 6 + j + 1)]);
                    {if (button != nullptr)
                    {
                        if (intersecttt[i][j])
                        {
                            button->Text = "Busy";
                            button->BackColor = Color::FromArgb(160, 252, 255);
                        }
                        else
                        {
                            button->Text = "Available";
                            button->BackColor = Color::FromArgb(210, 255, 255);
                        }
                    }
                    for (auto row : data)
                    {
                        if (row[0] == name)
                        {
                            if (row[i * 6 + j + 1] != "0")
                            {
                                button->Text = msclr::interop::marshal_as<String^>(row[i * 6 + j + 1]);
                                button->BackColor = Color::FromArgb(160, 252, 255);
                            }
                        }
                    }
                    }
                }
            }
            for (int x = 0; x < dgv->RowCount; x++)
            {
                if (dgv->Rows[x]->Cells[0]->Value != nullptr)
                {
                    string n = replacewhitespace(msclr::interop::marshal_as<string>(dgv->Rows[x]->Cells[0]->Value->ToString()));
                    for (auto cell : temp)
                    {
                        if (cell[0] == n)
                        {
                            for (int l = 3; l < cell.size(); l += 2)
                            {
                                if ((cell[l] == "1" && cell[l + 1] != (msclr::interop::marshal_as<string>(editsubnames->Text) + "(" + msclr::interop::marshal_as<string>(addsubclusters->Text) + ")") && (dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", l / 2)])->Text == editsubnames->Text)))
                                {
                                    dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", l / 2)])->Text = "Busy";
                                    dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", l / 2)])->BackColor = Color::FromArgb(224, 224, 224);
                                }
                            }
                        }
                    }
                }
            }
        }
        System::Void KeyPress(System::Object^ sender, KeyPressEventArgs^ e) {
            if (e->KeyChar == ',') {
                e->Handled = true;
            }
        }
        void Button_ClickFreeBusy(Object^ sender, EventArgs^ e) {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr) {
                // Toggle the text of the clicked button
                if (clickedButton->Text == "Free")
                {
                    clickedButton->Text = "Busy";
                    clickedButton->BackColor = Color::FromArgb(160, 252, 255);
                }
                else if (clickedButton->Text == "Busy")
                {
                    clickedButton->Text = "Free";
                    clickedButton->BackColor = Color::FromArgb(210, 255, 255);
                }
            }
        }
        void InitializeMatrix(TableLayoutPanel^ tableLayoutPanel, String^ s, String^ Texts, int x) {

            // Clear existing buttons if any
            tableLayoutPanel->Controls->Clear();
            // Create buttons and add them to the TableLayoutPanel

            for (int i = 0; i < 6; i++) {
                int count = 0;
                for (int j = 0; j < 8; j++) {
                    if (j == 2 || j == 5)
                    {
                        count++;
                    }
                    else
                    {
                        Button^ button = gcnew Button();
                        button->Text = Texts;
                        button->BackColor = Color::FromArgb(210, 255, 255);
                        button->Dock = DockStyle::Fill;
                        button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                            static_cast<System::Byte>(0)));
                        if (count == 0)
                            button->Name = String::Format("button" + s + "{0}", i * 6 + j + 1);
                        else if (count == 1)
                            button->Name = String::Format("button" + s + "{0}", i * 6 + j);
                        else
                            button->Name = String::Format("button" + s + "{0}", i * 6 + j - 1);
                        tableLayoutPanel->Controls->Add(button, j, i);
                        if (x == 0)
                            button->Click += gcnew EventHandler(this, &MyForm::Button_clickEle);
                        if (x == 1)
                            button->Click += gcnew EventHandler(this, &MyForm::Button_ClickFreeBusy);
                        if (x == 2)
                            button->Click += gcnew EventHandler(this, &MyForm::Button_clickEditEle);
                        if (x == 3)
                            button->Click += gcnew EventHandler(this, &MyForm::Button_clicks);
                        tableLayoutPanel->Controls->Add(button, j, i);
                    }
                }
            }
        }
        void ClearReset()
        {
            for (int i = 1; i <= 36; i++)
            {
                try
                {
                    Button^ button = dynamic_cast<Button^>(classtablegen->Controls[String::Format("buttonres{0}", i)]);
                    button->Text = "Reserved";
                    Button^ button1 = dynamic_cast<Button^>(classtablegen1->Controls[String::Format("buttong{0}", i)]);
                    button1->Text = "free";
                }
                catch (...) {

                }
            }
        }
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::DataGridViewComboBoxColumn^ SubjectName;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn8;
    private: System::Windows::Forms::Panel^ addsubjectpanel;
    private: System::Windows::Forms::Button^ saveroom;
    private: System::Windows::Forms::Button^ clearroom;
    private: System::Windows::Forms::Panel^ addclassroompanel;
    private: System::Windows::Forms::Panel^ Homepanel;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Panel^ editteacherpanel;
    private: System::Windows::Forms::Label^ label62;
    private: System::Windows::Forms::Button^ editteachersave;
    private: System::Windows::Forms::Button^ editteacherdelete;
    private: System::Windows::Forms::Panel^ settingspanel;


    private: System::Windows::Forms::Label^ label112;


    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button12;
    private: System::Windows::Forms::Button^ button11;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Button^ button15;
    private: System::Windows::Forms::Button^ button14;
    private: System::Windows::Forms::Button^ button13;

    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::PictureBox^ pictureBox4;
    private: System::Windows::Forms::PictureBox^ pictureBox5;
    private: System::Windows::Forms::PictureBox^ pictureBox6;
    private: System::Windows::Forms::PictureBox^ pictureBox7;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Button^ classgenerate;
    private: System::Windows::Forms::Button^ classsave;
    private: System::Windows::Forms::Button^ classclear;
    private: System::Windows::Forms::Button^ classreserve;
    private: System::Windows::Forms::Panel^ classpanel;
    private: System::Windows::Forms::Panel^ panel9;
    private: System::Windows::Forms::Panel^ addteacherpanel;
    private: System::Windows::Forms::Panel^ panel17;
    private: System::Windows::Forms::Button^ addteachersave;
    private: System::Windows::Forms::Button^ addteachernew;
    private: System::Windows::Forms::Panel^ panel18;
















    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button22;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Panel^ deleteclasspanel;
    private: System::Windows::Forms::Button^ classlabsave;
    private: System::Windows::Forms::Panel^ textBox5;
    private: System::Windows::Forms::Panel^ textBox7;
    private: System::Windows::Forms::Panel^ textBox6;
    private: System::Windows::Forms::Panel^ textBox11;
    private: System::Windows::Forms::Panel^ textBox10;
    private: System::Windows::Forms::Panel^ textBox4;
    private: System::Windows::Forms::Panel^ textBox9;
    private: System::Windows::Forms::Panel^ textBox8;

    private: System::Windows::Forms::Button^ button16;

    private: System::Windows::Forms::FolderBrowserDialog^ fbd;
    private: ComponentFactory::Krypton::Toolkit::KryptonPanel^ kryptonPanel6;
    private: System::Windows::Forms::Panel^ panel4;
    private: ComponentFactory::Krypton::Toolkit::KryptonLabel^ kryptonLabel1;
    private: System::Windows::Forms::PictureBox^ pictureBox11;
    private: System::Windows::Forms::Button^ button17;
    private: System::Windows::Forms::PictureBox^ pictureBox8;
    private: System::Windows::Forms::TextBox^ username;
    private: System::Windows::Forms::PictureBox^ pictureBox12;
    private: System::Windows::Forms::Button^ button18;
    private: System::ComponentModel::IContainer^ components;
    protected:
    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->addsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->panel48 = (gcnew System::Windows::Forms::Panel());
            this->button19 = (gcnew System::Windows::Forms::Button());
            this->addsubsave = (gcnew System::Windows::Forms::Button());
            this->addsubbfactorgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->addsubbfactor = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->kryptonNumericUpDown3 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label100 = (gcnew System::Windows::Forms::Label());
            this->addsubroomlistgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label152 = (gcnew System::Windows::Forms::Label());
            this->addsubroomlist = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox());
            this->addsubeleyesgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label74 = (gcnew System::Windows::Forms::Label());
            this->panel38 = (gcnew System::Windows::Forms::Panel());
            this->panel41 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel49 = (gcnew System::Windows::Forms::Panel());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label66 = (gcnew System::Windows::Forms::Label());
            this->label67 = (gcnew System::Windows::Forms::Label());
            this->label68 = (gcnew System::Windows::Forms::Label());
            this->label69 = (gcnew System::Windows::Forms::Label());
            this->label70 = (gcnew System::Windows::Forms::Label());
            this->label71 = (gcnew System::Windows::Forms::Label());
            this->label72 = (gcnew System::Windows::Forms::Label());
            this->label73 = (gcnew System::Windows::Forms::Label());
            this->sedataGridView = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->addsubcluster = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->addsubclusteroptions = (gcnew System::Windows::Forms::Button());
            this->label178 = (gcnew System::Windows::Forms::Label());
            this->label179 = (gcnew System::Windows::Forms::Label());
            this->kryptonLabel3 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->addsubcreditsgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->addsubcredits = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label181 = (gcnew System::Windows::Forms::Label());
            this->addsubtitlegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel2 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label182 = (gcnew System::Windows::Forms::Label());
            this->addsubtitle = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->addsubelegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label183 = (gcnew System::Windows::Forms::Label());
            this->panel42 = (gcnew System::Windows::Forms::Panel());
            this->addsubeleyes = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->addsubeleno = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->addsubnamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel5 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label184 = (gcnew System::Windows::Forms::Label());
            this->addsubname = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->addsubcodegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel7 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label185 = (gcnew System::Windows::Forms::Label());
            this->addsubcode = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->saveroom = (gcnew System::Windows::Forms::Button());
            this->clearroom = (gcnew System::Windows::Forms::Button());
            this->addclassroompanel = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->kryptonGroupBox9 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel37 = (gcnew System::Windows::Forms::Panel());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->addroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel43 = (gcnew System::Windows::Forms::Panel());
            this->label134 = (gcnew System::Windows::Forms::Label());
            this->label133 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label132 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label131 = (gcnew System::Windows::Forms::Label());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->label130 = (gcnew System::Windows::Forms::Label());
            this->label126 = (gcnew System::Windows::Forms::Label());
            this->label129 = (gcnew System::Windows::Forms::Label());
            this->label127 = (gcnew System::Windows::Forms::Label());
            this->label128 = (gcnew System::Windows::Forms::Label());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->roomdeptgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->roomdept = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->kryptonLabel5 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->roomcapacitygroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->roomcapacity = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label187 = (gcnew System::Windows::Forms::Label());
            this->roomlabgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label189 = (gcnew System::Windows::Forms::Label());
            this->panel44 = (gcnew System::Windows::Forms::Panel());
            this->roomlabyes = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->roomlabno = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->roomnamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel12 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label190 = (gcnew System::Windows::Forms::Label());
            this->roomname = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->Homepanel = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->editteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->editteacheremailidgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel9 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->editteacheremailid = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editteachersearchgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editteachersearchbutton = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->teachersearch = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->editteacherdelete = (gcnew System::Windows::Forms::Button());
            this->editteachersave = (gcnew System::Windows::Forms::Button());
            this->editteachertablegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->panel23 = (gcnew System::Windows::Forms::Panel());
            this->editteachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel24 = (gcnew System::Windows::Forms::Panel());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->panel28 = (gcnew System::Windows::Forms::Panel());
            this->button21 = (gcnew System::Windows::Forms::Button());
            this->button23 = (gcnew System::Windows::Forms::Button());
            this->editteacherdepartmentgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->editteacherdepartment = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->kryptonLabel4 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->editteachernamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel8 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->editteachername = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editsubactivepanel = (gcnew ComponentFactory::Krypton::Toolkit::KryptonButton());
            this->kryptonPanel6 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->kryptonLabel1 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->username = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
            this->textBox7 = (gcnew System::Windows::Forms::Panel());
            this->settingspanel = (gcnew System::Windows::Forms::Panel());
            this->panel36 = (gcnew System::Windows::Forms::Panel());
            this->kryptonGroupBox5 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->busyfactor = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->settingssave = (gcnew System::Windows::Forms::Button());
            this->kryptonGroupBox3 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->filepath = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->label137 = (gcnew System::Windows::Forms::Label());
            this->button16 = (gcnew System::Windows::Forms::Button());
            this->kryptonGroupBox4 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel56 = (gcnew System::Windows::Forms::Panel());
            this->panel57 = (gcnew System::Windows::Forms::Panel());
            this->settingstable = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel58 = (gcnew System::Windows::Forms::Panel());
            this->label138 = (gcnew System::Windows::Forms::Label());
            this->label139 = (gcnew System::Windows::Forms::Label());
            this->label140 = (gcnew System::Windows::Forms::Label());
            this->label141 = (gcnew System::Windows::Forms::Label());
            this->label142 = (gcnew System::Windows::Forms::Label());
            this->label143 = (gcnew System::Windows::Forms::Label());
            this->label144 = (gcnew System::Windows::Forms::Label());
            this->label145 = (gcnew System::Windows::Forms::Label());
            this->label146 = (gcnew System::Windows::Forms::Label());
            this->label165 = (gcnew System::Windows::Forms::Label());
            this->label171 = (gcnew System::Windows::Forms::Label());
            this->label172 = (gcnew System::Windows::Forms::Label());
            this->label173 = (gcnew System::Windows::Forms::Label());
            this->panel59 = (gcnew System::Windows::Forms::Panel());
            this->button28 = (gcnew System::Windows::Forms::Button());
            this->button29 = (gcnew System::Windows::Forms::Button());
            this->kryptonLabel11 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->kryptonGroupBox6 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->freefactor = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label175 = (gcnew System::Windows::Forms::Label());
            this->label112 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button12 = (gcnew System::Windows::Forms::Button());
            this->button11 = (gcnew System::Windows::Forms::Button());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->button15 = (gcnew System::Windows::Forms::Button());
            this->button14 = (gcnew System::Windows::Forms::Button());
            this->button13 = (gcnew System::Windows::Forms::Button());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Button());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
            this->button18 = (gcnew System::Windows::Forms::Button());
            this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
            this->button17 = (gcnew System::Windows::Forms::Button());
            this->textBox5 = (gcnew System::Windows::Forms::Panel());
            this->textBox9 = (gcnew System::Windows::Forms::Panel());
            this->textBox11 = (gcnew System::Windows::Forms::Panel());
            this->textBox4 = (gcnew System::Windows::Forms::Panel());
            this->textBox10 = (gcnew System::Windows::Forms::Panel());
            this->textBox8 = (gcnew System::Windows::Forms::Panel());
            this->Homebutton1 = (gcnew System::Windows::Forms::Button());
            this->textBox6 = (gcnew System::Windows::Forms::Panel());
            this->classgenerate = (gcnew System::Windows::Forms::Button());
            this->classsave = (gcnew System::Windows::Forms::Button());
            this->classclear = (gcnew System::Windows::Forms::Button());
            this->classreserve = (gcnew System::Windows::Forms::Button());
            this->classpanel = (gcnew System::Windows::Forms::Panel());
            this->panel29 = (gcnew System::Windows::Forms::Panel());
            this->panel27 = (gcnew System::Windows::Forms::Panel());
            this->classgengroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->panel25 = (gcnew System::Windows::Forms::Panel());
            this->classtablegen1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel26 = (gcnew System::Windows::Forms::Panel());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->label52 = (gcnew System::Windows::Forms::Label());
            this->label53 = (gcnew System::Windows::Forms::Label());
            this->label54 = (gcnew System::Windows::Forms::Label());
            this->label55 = (gcnew System::Windows::Forms::Label());
            this->label56 = (gcnew System::Windows::Forms::Label());
            this->label57 = (gcnew System::Windows::Forms::Label());
            this->label58 = (gcnew System::Windows::Forms::Label());
            this->label59 = (gcnew System::Windows::Forms::Label());
            this->label60 = (gcnew System::Windows::Forms::Label());
            this->label61 = (gcnew System::Windows::Forms::Label());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->label135 = (gcnew System::Windows::Forms::Label());
            this->classroomgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->classdefaultrooms = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox());
            this->label158 = (gcnew System::Windows::Forms::Label());
            this->classresgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel50 = (gcnew System::Windows::Forms::Panel());
            this->panel53 = (gcnew System::Windows::Forms::Panel());
            this->classtablegen = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel54 = (gcnew System::Windows::Forms::Panel());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->label159 = (gcnew System::Windows::Forms::Label());
            this->label160 = (gcnew System::Windows::Forms::Label());
            this->label161 = (gcnew System::Windows::Forms::Label());
            this->label162 = (gcnew System::Windows::Forms::Label());
            this->label163 = (gcnew System::Windows::Forms::Label());
            this->label164 = (gcnew System::Windows::Forms::Label());
            this->label166 = (gcnew System::Windows::Forms::Label());
            this->label167 = (gcnew System::Windows::Forms::Label());
            this->label168 = (gcnew System::Windows::Forms::Label());
            this->label169 = (gcnew System::Windows::Forms::Label());
            this->label170 = (gcnew System::Windows::Forms::Label());
            this->classlabgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->classoptrooms = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckBox());
            this->compactlabs = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckBox());
            this->classlab = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->lsubject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn7 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->classlabroomlist = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->classlabsave = (gcnew System::Windows::Forms::Button());
            this->classsessions = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label157 = (gcnew System::Windows::Forms::Label());
            this->classbatches = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->kryptonPanel14 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label156 = (gcnew System::Windows::Forms::Label());
            this->classlabcombo = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->label154 = (gcnew System::Windows::Forms::Label());
            this->classlabteachers = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->Teacher1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->classelegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->classele = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->esubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->classcoregroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->classcore = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->csubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->cteacher = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->classbatchgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->classbatch = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->classbranchgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label82 = (gcnew System::Windows::Forms::Label());
            this->classbranch = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->kryptonLabel10 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->classnamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel15 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label119 = (gcnew System::Windows::Forms::Label());
            this->classname = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->addteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
            this->addteacheremailidgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel10 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->addteacheremailid = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->addteachersave = (gcnew System::Windows::Forms::Button());
            this->addteachernew = (gcnew System::Windows::Forms::Button());
            this->addteachertablegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel30 = (gcnew System::Windows::Forms::Panel());
            this->panel31 = (gcnew System::Windows::Forms::Panel());
            this->teachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel32 = (gcnew System::Windows::Forms::Panel());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->panel35 = (gcnew System::Windows::Forms::Panel());
            this->button26 = (gcnew System::Windows::Forms::Button());
            this->button27 = (gcnew System::Windows::Forms::Button());
            this->addteacherdepartmentgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->addteacherdepartment = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->kryptonLabel7 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->addteachernamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel13 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->addteachername = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button22 = (gcnew System::Windows::Forms::Button());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panel46 = (gcnew System::Windows::Forms::Panel());
            this->kryptonLabel9 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->deptgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->deptDataGridView = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->deleteclasspanel = (gcnew System::Windows::Forms::Panel());
            this->panel47 = (gcnew System::Windows::Forms::Panel());
            this->kryptonLabel8 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->kryptonGroupBox2 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->sectiondeletedatagridview = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->classcolumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->classdeletebutton = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->fbd = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->label94 = (gcnew System::Windows::Forms::Label());
            this->editsubbfactorgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editsubbfactor = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label110 = (gcnew System::Windows::Forms::Label());
            this->kryptonNumericUpDown1 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->editsubroomlistgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label150 = (gcnew System::Windows::Forms::Label());
            this->editsubroomlist = (gcnew ComponentFactory::Krypton::Toolkit::KryptonCheckedListBox());
            this->editsubdelete = (gcnew System::Windows::Forms::Button());
            this->editsubsave = (gcnew System::Windows::Forms::Button());
            this->editsubcreditsgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editsubcredits = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label101 = (gcnew System::Windows::Forms::Label());
            this->editsubelepanel = (gcnew System::Windows::Forms::Panel());
            this->label155 = (gcnew System::Windows::Forms::Label());
            this->panel39 = (gcnew System::Windows::Forms::Panel());
            this->panel40 = (gcnew System::Windows::Forms::Panel());
            this->editsubeletable = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel52 = (gcnew System::Windows::Forms::Panel());
            this->label75 = (gcnew System::Windows::Forms::Label());
            this->label76 = (gcnew System::Windows::Forms::Label());
            this->label77 = (gcnew System::Windows::Forms::Label());
            this->label120 = (gcnew System::Windows::Forms::Label());
            this->label123 = (gcnew System::Windows::Forms::Label());
            this->label124 = (gcnew System::Windows::Forms::Label());
            this->label125 = (gcnew System::Windows::Forms::Label());
            this->label147 = (gcnew System::Windows::Forms::Label());
            this->label148 = (gcnew System::Windows::Forms::Label());
            this->label149 = (gcnew System::Windows::Forms::Label());
            this->label151 = (gcnew System::Windows::Forms::Label());
            this->label153 = (gcnew System::Windows::Forms::Label());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->panel51 = (gcnew System::Windows::Forms::Panel());
            this->editsubeleyesgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editsubeleteacher = (gcnew ComponentFactory::Krypton::Toolkit::KryptonDataGridView());
            this->editsubeleteachercombo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn10 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->editsubcluster = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->label95 = (gcnew System::Windows::Forms::Label());
            this->kryptonLabel2 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->editsubsearchgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editsubsearchbutton = (gcnew ComponentFactory::Krypton::Toolkit::KryptonButton());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->editsubsearch = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->editsubtitlegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel1 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label109 = (gcnew System::Windows::Forms::Label());
            this->editsubtitle = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editsubelegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label92 = (gcnew System::Windows::Forms::Label());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->editsubeleyes = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->editsubeleno = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->editsubnamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel3 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label93 = (gcnew System::Windows::Forms::Label());
            this->editsubname = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editsubcodegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel4 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->editsubcode = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->editroomsearchgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label242 = (gcnew System::Windows::Forms::Label());
            this->editroomsearchbutton = (gcnew System::Windows::Forms::Button());
            this->editroomsearch = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->kryptonGroupBox10 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
            this->panel33 = (gcnew System::Windows::Forms::Panel());
            this->editroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label114 = (gcnew System::Windows::Forms::Label());
            this->panel34 = (gcnew System::Windows::Forms::Panel());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label78 = (gcnew System::Windows::Forms::Label());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->label80 = (gcnew System::Windows::Forms::Label());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->label103 = (gcnew System::Windows::Forms::Label());
            this->label104 = (gcnew System::Windows::Forms::Label());
            this->label105 = (gcnew System::Windows::Forms::Label());
            this->label106 = (gcnew System::Windows::Forms::Label());
            this->label107 = (gcnew System::Windows::Forms::Label());
            this->label108 = (gcnew System::Windows::Forms::Label());
            this->label113 = (gcnew System::Windows::Forms::Label());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->editroomdelete = (gcnew System::Windows::Forms::Button());
            this->editroomsave = (gcnew System::Windows::Forms::Button());
            this->editroomdepartmentgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label115 = (gcnew System::Windows::Forms::Label());
            this->editroomdepartment = (gcnew ComponentFactory::Krypton::Toolkit::KryptonComboBox());
            this->kryptonLabel6 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonLabel());
            this->editroomcapacitygroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->editroomcapacity = (gcnew ComponentFactory::Krypton::Toolkit::KryptonNumericUpDown());
            this->label116 = (gcnew System::Windows::Forms::Label());
            this->editroomlabgroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->label117 = (gcnew System::Windows::Forms::Label());
            this->panel45 = (gcnew System::Windows::Forms::Panel());
            this->editroomlabyes = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->editroomlabno = (gcnew ComponentFactory::Krypton::Toolkit::KryptonRadioButton());
            this->editroomnamegroup = (gcnew ComponentFactory::Krypton::Toolkit::KryptonGroupBox());
            this->kryptonPanel11 = (gcnew ComponentFactory::Krypton::Toolkit::KryptonPanel());
            this->label118 = (gcnew System::Windows::Forms::Label());
            this->editroomname = (gcnew ComponentFactory::Krypton::Toolkit::KryptonTextBox());
            this->editroompanel = (gcnew System::Windows::Forms::Panel());
            this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer7 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer8 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer9 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer10 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer11 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer12 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer13 = (gcnew System::Windows::Forms::Timer(this->components));
            this->addsubjectpanel->SuspendLayout();
            this->panel11->SuspendLayout();
            this->panel48->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactorgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactorgroup->Panel))->BeginInit();
            this->addsubbfactorgroup->Panel->SuspendLayout();
            this->addsubbfactorgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubroomlistgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubroomlistgroup->Panel))->BeginInit();
            this->addsubroomlistgroup->Panel->SuspendLayout();
            this->addsubroomlistgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubeleyesgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubeleyesgroup->Panel))->BeginInit();
            this->addsubeleyesgroup->Panel->SuspendLayout();
            this->addsubeleyesgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcluster))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcreditsgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcreditsgroup->Panel))->BeginInit();
            this->addsubcreditsgroup->Panel->SuspendLayout();
            this->addsubcreditsgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubtitlegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubtitlegroup->Panel))->BeginInit();
            this->addsubtitlegroup->Panel->SuspendLayout();
            this->addsubtitlegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubelegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubelegroup->Panel))->BeginInit();
            this->addsubelegroup->Panel->SuspendLayout();
            this->addsubelegroup->SuspendLayout();
            this->panel42->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubnamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubnamegroup->Panel))->BeginInit();
            this->addsubnamegroup->Panel->SuspendLayout();
            this->addsubnamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcodegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcodegroup->Panel))->BeginInit();
            this->addsubcodegroup->Panel->SuspendLayout();
            this->addsubcodegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel7))->BeginInit();
            this->addclassroompanel->SuspendLayout();
            this->panel7->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox9->Panel))->BeginInit();
            this->kryptonGroupBox9->Panel->SuspendLayout();
            this->kryptonGroupBox9->SuspendLayout();
            this->panel9->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdeptgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdeptgroup->Panel))->BeginInit();
            this->roomdeptgroup->Panel->SuspendLayout();
            this->roomdeptgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdept))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacitygroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacitygroup->Panel))->BeginInit();
            this->roomcapacitygroup->Panel->SuspendLayout();
            this->roomcapacitygroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomlabgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomlabgroup->Panel))->BeginInit();
            this->roomlabgroup->Panel->SuspendLayout();
            this->roomlabgroup->SuspendLayout();
            this->panel44->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomnamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomnamegroup->Panel))->BeginInit();
            this->roomnamegroup->Panel->SuspendLayout();
            this->roomnamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel12))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->editteacherpanel->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacheremailidgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacheremailidgroup->Panel))->BeginInit();
            this->editteacheremailidgroup->Panel->SuspendLayout();
            this->editteacheremailidgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachersearchgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachersearchgroup->Panel))->BeginInit();
            this->editteachersearchgroup->Panel->SuspendLayout();
            this->editteachersearchgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teachersearch))->BeginInit();
            this->panel18->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachertablegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachertablegroup->Panel))->BeginInit();
            this->editteachertablegroup->Panel->SuspendLayout();
            this->editteachertablegroup->SuspendLayout();
            this->panel28->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartmentgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartmentgroup->Panel))->BeginInit();
            this->editteacherdepartmentgroup->Panel->SuspendLayout();
            this->editteacherdepartmentgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartment))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachernamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachernamegroup->Panel))->BeginInit();
            this->editteachernamegroup->Panel->SuspendLayout();
            this->editteachernamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel6))->BeginInit();
            this->kryptonPanel6->SuspendLayout();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            this->settingspanel->SuspendLayout();
            this->panel36->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox5->Panel))->BeginInit();
            this->kryptonGroupBox5->Panel->SuspendLayout();
            this->kryptonGroupBox5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox3->Panel))->BeginInit();
            this->kryptonGroupBox3->Panel->SuspendLayout();
            this->kryptonGroupBox3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox4->Panel))->BeginInit();
            this->kryptonGroupBox4->Panel->SuspendLayout();
            this->kryptonGroupBox4->SuspendLayout();
            this->panel59->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox6->Panel))->BeginInit();
            this->kryptonGroupBox6->Panel->SuspendLayout();
            this->kryptonGroupBox6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            this->classpanel->SuspendLayout();
            this->panel29->SuspendLayout();
            this->panel27->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classgengroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classgengroup->Panel))->BeginInit();
            this->classgengroup->Panel->SuspendLayout();
            this->classgengroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classroomgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classroomgroup->Panel))->BeginInit();
            this->classroomgroup->Panel->SuspendLayout();
            this->classroomgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classresgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classresgroup->Panel))->BeginInit();
            this->classresgroup->Panel->SuspendLayout();
            this->classresgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabgroup->Panel))->BeginInit();
            this->classlabgroup->Panel->SuspendLayout();
            this->classlabgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlab))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel14))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabteachers))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classelegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classelegroup->Panel))->BeginInit();
            this->classelegroup->Panel->SuspendLayout();
            this->classelegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classele))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcoregroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcoregroup->Panel))->BeginInit();
            this->classcoregroup->Panel->SuspendLayout();
            this->classcoregroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcore))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbatchgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbatchgroup->Panel))->BeginInit();
            this->classbatchgroup->Panel->SuspendLayout();
            this->classbatchgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranchgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranchgroup->Panel))->BeginInit();
            this->classbranchgroup->Panel->SuspendLayout();
            this->classbranchgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranch))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classnamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classnamegroup->Panel))->BeginInit();
            this->classnamegroup->Panel->SuspendLayout();
            this->classnamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel15))->BeginInit();
            this->addteacherpanel->SuspendLayout();
            this->panel16->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacheremailidgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacheremailidgroup->Panel))->BeginInit();
            this->addteacheremailidgroup->Panel->SuspendLayout();
            this->addteacheremailidgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel10))->BeginInit();
            this->panel17->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachertablegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachertablegroup->Panel))->BeginInit();
            this->addteachertablegroup->Panel->SuspendLayout();
            this->addteachertablegroup->SuspendLayout();
            this->panel35->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartmentgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartmentgroup->Panel))->BeginInit();
            this->addteacherdepartmentgroup->Panel->SuspendLayout();
            this->addteacherdepartmentgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartment))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachernamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachernamegroup->Panel))->BeginInit();
            this->addteachernamegroup->Panel->SuspendLayout();
            this->addteachernamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel13))->BeginInit();
            this->panel2->SuspendLayout();
            this->panel46->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptgroup->Panel))->BeginInit();
            this->deptgroup->Panel->SuspendLayout();
            this->deptgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->BeginInit();
            this->deleteclasspanel->SuspendLayout();
            this->panel47->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox2->Panel))->BeginInit();
            this->kryptonGroupBox2->Panel->SuspendLayout();
            this->kryptonGroupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectiondeletedatagridview))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactorgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactorgroup->Panel))->BeginInit();
            this->editsubbfactorgroup->Panel->SuspendLayout();
            this->editsubbfactorgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubroomlistgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubroomlistgroup->Panel))->BeginInit();
            this->editsubroomlistgroup->Panel->SuspendLayout();
            this->editsubroomlistgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcreditsgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcreditsgroup->Panel))->BeginInit();
            this->editsubcreditsgroup->Panel->SuspendLayout();
            this->editsubcreditsgroup->SuspendLayout();
            this->editsubelepanel->SuspendLayout();
            this->panel13->SuspendLayout();
            this->panel51->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleyesgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleyesgroup->Panel))->BeginInit();
            this->editsubeleyesgroup->Panel->SuspendLayout();
            this->editsubeleyesgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleteacher))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcluster))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearchgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearchgroup->Panel))->BeginInit();
            this->editsubsearchgroup->Panel->SuspendLayout();
            this->editsubsearchgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearch))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubtitlegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubtitlegroup->Panel))->BeginInit();
            this->editsubtitlegroup->Panel->SuspendLayout();
            this->editsubtitlegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubelegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubelegroup->Panel))->BeginInit();
            this->editsubelegroup->Panel->SuspendLayout();
            this->editsubelegroup->SuspendLayout();
            this->panel10->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubnamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubnamegroup->Panel))->BeginInit();
            this->editsubnamegroup->Panel->SuspendLayout();
            this->editsubnamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcodegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcodegroup->Panel))->BeginInit();
            this->editsubcodegroup->Panel->SuspendLayout();
            this->editsubcodegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel4))->BeginInit();
            this->editsubjectpanel->SuspendLayout();
            this->panel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearchgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearchgroup->Panel))->BeginInit();
            this->editroomsearchgroup->Panel->SuspendLayout();
            this->editroomsearchgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearch))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox10->Panel))->BeginInit();
            this->kryptonGroupBox10->Panel->SuspendLayout();
            this->kryptonGroupBox10->SuspendLayout();
            this->panel14->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartmentgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartmentgroup->Panel))->BeginInit();
            this->editroomdepartmentgroup->Panel->SuspendLayout();
            this->editroomdepartmentgroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartment))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacitygroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacitygroup->Panel))->BeginInit();
            this->editroomcapacitygroup->Panel->SuspendLayout();
            this->editroomcapacitygroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomlabgroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomlabgroup->Panel))->BeginInit();
            this->editroomlabgroup->Panel->SuspendLayout();
            this->editroomlabgroup->SuspendLayout();
            this->panel45->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomnamegroup))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomnamegroup->Panel))->BeginInit();
            this->editroomnamegroup->Panel->SuspendLayout();
            this->editroomnamegroup->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel11))->BeginInit();
            this->editroompanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // addsubjectpanel
            // 
            this->addsubjectpanel->AutoScroll = true;
            this->addsubjectpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubjectpanel->Controls->Add(this->panel11);
            this->addsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->addsubjectpanel->Name = L"addsubjectpanel";
            this->addsubjectpanel->Size = System::Drawing::Size(1924, 1050);
            this->addsubjectpanel->TabIndex = 124;
            this->addsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addsubjectpanel_Paint);
            // 
            // panel11
            // 
            this->panel11->Controls->Add(this->panel48);
            this->panel11->Controls->Add(this->addsubbfactorgroup);
            this->panel11->Controls->Add(this->addsubroomlistgroup);
            this->panel11->Controls->Add(this->addsubeleyesgroup);
            this->panel11->Controls->Add(this->kryptonLabel3);
            this->panel11->Controls->Add(this->addsubcreditsgroup);
            this->panel11->Controls->Add(this->addsubtitlegroup);
            this->panel11->Controls->Add(this->addsubelegroup);
            this->panel11->Controls->Add(this->addsubnamegroup);
            this->panel11->Controls->Add(this->addsubcodegroup);
            this->panel11->Location = System::Drawing::Point(179, 13);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(1194, 2224);
            this->panel11->TabIndex = 341;
            // 
            // panel48
            // 
            this->panel48->Controls->Add(this->button19);
            this->panel48->Controls->Add(this->addsubsave);
            this->panel48->Location = System::Drawing::Point(646, 3221);
            this->panel48->Name = L"panel48";
            this->panel48->Size = System::Drawing::Size(461, 136);
            this->panel48->TabIndex = 345;
            // 
            // button19
            // 
            this->button19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button19->Location = System::Drawing::Point(253, 27);
            this->button19->Name = L"button19";
            this->button19->Size = System::Drawing::Size(154, 58);
            this->button19->TabIndex = 309;
            this->button19->Text = L"Clear";
            this->button19->UseVisualStyleBackColor = false;
            this->button19->Click += gcnew System::EventHandler(this, &MyForm::newaddsub_Click);
            // 
            // addsubsave
            // 
            this->addsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubsave->Location = System::Drawing::Point(54, 27);
            this->addsubsave->Name = L"addsubsave";
            this->addsubsave->Size = System::Drawing::Size(154, 58);
            this->addsubsave->TabIndex = 308;
            this->addsubsave->Text = L"Save";
            this->addsubsave->UseVisualStyleBackColor = false;
            this->addsubsave->Click += gcnew System::EventHandler(this, &MyForm::addsubsave_Click);
            // 
            // addsubbfactorgroup
            // 
            this->addsubbfactorgroup->CaptionOverlap = 1;
            this->addsubbfactorgroup->CaptionVisible = false;
            this->addsubbfactorgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubbfactorgroup->Location = System::Drawing::Point(23, 2986);
            this->addsubbfactorgroup->Name = L"addsubbfactorgroup";
            // 
            // addsubbfactorgroup.Panel
            // 
            this->addsubbfactorgroup->Panel->Controls->Add(this->addsubbfactor);
            this->addsubbfactorgroup->Panel->Controls->Add(this->label96);
            this->addsubbfactorgroup->Panel->Controls->Add(this->kryptonNumericUpDown3);
            this->addsubbfactorgroup->Panel->Controls->Add(this->label100);
            this->addsubbfactorgroup->Size = System::Drawing::Size(1127, 194);
            this->addsubbfactorgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubbfactorgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubbfactorgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->addsubbfactorgroup->StateCommon->Border->ColorAngle = 50;
            this->addsubbfactorgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubbfactorgroup->StateCommon->Border->Rounding = 7;
            this->addsubbfactorgroup->StateCommon->Border->Width = 1;
            this->addsubbfactorgroup->TabIndex = 342;
            this->addsubbfactorgroup->Enter += gcnew System::EventHandler(this, &MyForm::addsubbfactorgroup_Enter);
            // 
            // addsubbfactor
            // 
            this->addsubbfactor->DecimalPlaces = 1;
            this->addsubbfactor->Location = System::Drawing::Point(98, 96);
            this->addsubbfactor->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->addsubbfactor->Name = L"addsubbfactor";
            this->addsubbfactor->Size = System::Drawing::Size(304, 30);
            this->addsubbfactor->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->addsubbfactor->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->addsubbfactor->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubbfactor->TabIndex = 328;
            // 
            // label96
            // 
            this->label96->AutoSize = true;
            this->label96->BackColor = System::Drawing::Color::White;
            this->label96->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label96->ForeColor = System::Drawing::Color::Black;
            this->label96->Location = System::Drawing::Point(94, 39);
            this->label96->Name = L"label96";
            this->label96->Size = System::Drawing::Size(730, 28);
            this->label96->TabIndex = 327;
            this->label96->Text = L"Rate the subject from 1 to 5 based on its exhaustiveness according to students";
            // 
            // kryptonNumericUpDown3
            // 
            this->kryptonNumericUpDown3->Location = System::Drawing::Point(98, 96);
            this->kryptonNumericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->kryptonNumericUpDown3->Name = L"kryptonNumericUpDown3";
            this->kryptonNumericUpDown3->Size = System::Drawing::Size(304, 30);
            this->kryptonNumericUpDown3->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->kryptonNumericUpDown3->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->kryptonNumericUpDown3->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonNumericUpDown3->TabIndex = 328;
            // 
            // label100
            // 
            this->label100->AutoSize = true;
            this->label100->BackColor = System::Drawing::Color::White;
            this->label100->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label100->ForeColor = System::Drawing::Color::Black;
            this->label100->Location = System::Drawing::Point(94, 39);
            this->label100->Name = L"label100";
            this->label100->Size = System::Drawing::Size(184, 28);
            this->label100->TabIndex = 327;
            this->label100->Text = L"Number Of Credits";
            // 
            // addsubroomlistgroup
            // 
            this->addsubroomlistgroup->CaptionOverlap = 1;
            this->addsubroomlistgroup->CaptionVisible = false;
            this->addsubroomlistgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubroomlistgroup->Location = System::Drawing::Point(22, 2582);
            this->addsubroomlistgroup->Name = L"addsubroomlistgroup";
            // 
            // addsubroomlistgroup.Panel
            // 
            this->addsubroomlistgroup->Panel->Controls->Add(this->label152);
            this->addsubroomlistgroup->Panel->Controls->Add(this->addsubroomlist);
            this->addsubroomlistgroup->Size = System::Drawing::Size(1127, 357);
            this->addsubroomlistgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubroomlistgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubroomlistgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->addsubroomlistgroup->StateCommon->Border->ColorAngle = 50;
            this->addsubroomlistgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubroomlistgroup->StateCommon->Border->Rounding = 7;
            this->addsubroomlistgroup->StateCommon->Border->Width = 1;
            this->addsubroomlistgroup->TabIndex = 344;
            this->addsubroomlistgroup->Enter += gcnew System::EventHandler(this, &MyForm::addsubroomlistgroup_Enter);
            // 
            // label152
            // 
            this->label152->AutoSize = true;
            this->label152->BackColor = System::Drawing::Color::White;
            this->label152->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label152->ForeColor = System::Drawing::Color::Black;
            this->label152->Location = System::Drawing::Point(143, 43);
            this->label152->Name = L"label152";
            this->label152->Size = System::Drawing::Size(267, 28);
            this->label152->TabIndex = 344;
            this->label152->Text = L"Rooms to be used(optional)";
            // 
            // addsubroomlist
            // 
            this->addsubroomlist->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::InputControlRibbon;
            this->addsubroomlist->BorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ContextMenuItemSplit;
            this->addsubroomlist->CheckOnClick = true;
            this->addsubroomlist->Location = System::Drawing::Point(162, 110);
            this->addsubroomlist->Name = L"addsubroomlist";
            this->addsubroomlist->Size = System::Drawing::Size(348, 182);
            this->addsubroomlist->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->addsubroomlist->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubroomlist->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubroomlist->StateCommon->Border->Rounding = 5;
            this->addsubroomlist->StateCommon->Border->Width = 1;
            this->addsubroomlist->TabIndex = 343;
            // 
            // addsubeleyesgroup
            // 
            this->addsubeleyesgroup->CaptionOverlap = 1;
            this->addsubeleyesgroup->CaptionVisible = false;
            this->addsubeleyesgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubeleyesgroup->Location = System::Drawing::Point(29, 1167);
            this->addsubeleyesgroup->Name = L"addsubeleyesgroup";
            // 
            // addsubeleyesgroup.Panel
            // 
            this->addsubeleyesgroup->Panel->Controls->Add(this->label74);
            this->addsubeleyesgroup->Panel->Controls->Add(this->panel38);
            this->addsubeleyesgroup->Panel->Controls->Add(this->panel41);
            this->addsubeleyesgroup->Panel->Controls->Add(this->tableLayoutPanel1);
            this->addsubeleyesgroup->Panel->Controls->Add(this->panel49);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label13);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label33);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label38);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label64);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label66);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label67);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label68);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label69);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label70);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label71);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label72);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label73);
            this->addsubeleyesgroup->Panel->Controls->Add(this->sedataGridView);
            this->addsubeleyesgroup->Panel->Controls->Add(this->addsubcluster);
            this->addsubeleyesgroup->Panel->Controls->Add(this->addsubclusteroptions);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label178);
            this->addsubeleyesgroup->Panel->Controls->Add(this->label179);
            this->addsubeleyesgroup->Size = System::Drawing::Size(1127, 1159);
            this->addsubeleyesgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubeleyesgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubeleyesgroup->StateCommon->Border->ColorAngle = 50;
            this->addsubeleyesgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubeleyesgroup->StateCommon->Border->Rounding = 7;
            this->addsubeleyesgroup->StateCommon->Border->Width = 1;
            this->addsubeleyesgroup->TabIndex = 343;
            this->addsubeleyesgroup->Enter += gcnew System::EventHandler(this, &MyForm::addsubeleyesgroup_Enter);
            // 
            // label74
            // 
            this->label74->AutoSize = true;
            this->label74->BackColor = System::Drawing::Color::White;
            this->label74->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label74->Location = System::Drawing::Point(70, 603);
            this->label74->Name = L"label74";
            this->label74->Size = System::Drawing::Size(329, 28);
            this->label74->TabIndex = 360;
            this->label74->Text = L"Select the eligible slots for elective";
            // 
            // panel38
            // 
            this->panel38->BackColor = System::Drawing::Color::White;
            this->panel38->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel38.BackgroundImage")));
            this->panel38->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel38->Location = System::Drawing::Point(762, 701);
            this->panel38->Name = L"panel38";
            this->panel38->Size = System::Drawing::Size(44, 420);
            this->panel38->TabIndex = 344;
            // 
            // panel41
            // 
            this->panel41->BackColor = System::Drawing::Color::White;
            this->panel41->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel41.BackgroundImage")));
            this->panel41->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel41->Location = System::Drawing::Point(427, 701);
            this->panel41->Name = L"panel41";
            this->panel41->Size = System::Drawing::Size(44, 430);
            this->panel41->TabIndex = 359;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->BackColor = System::Drawing::Color::White;
            this->tableLayoutPanel1->ColumnCount = 8;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->tableLayoutPanel1->Location = System::Drawing::Point(140, 701);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 6;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(950, 431);
            this->tableLayoutPanel1->TabIndex = 346;
            // 
            // panel49
            // 
            this->panel49->BackColor = System::Drawing::Color::White;
            this->panel49->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel49.BackgroundImage")));
            this->panel49->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel49->Location = System::Drawing::Point(416, 701);
            this->panel49->Name = L"panel49";
            this->panel49->Size = System::Drawing::Size(82, 412);
            this->panel49->TabIndex = 345;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->BackColor = System::Drawing::Color::White;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(40, 721);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(85, 28);
            this->label13->TabIndex = 347;
            this->label13->Text = L"Monday";
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->BackColor = System::Drawing::Color::White;
            this->label33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label33->Location = System::Drawing::Point(46, 790);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(83, 28);
            this->label33->TabIndex = 348;
            this->label33->Text = L"Tuesday";
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->BackColor = System::Drawing::Color::White;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(158, 661);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(105, 28);
            this->label38->TabIndex = 353;
            this->label38->Text = L"9:00-10:00";
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->BackColor = System::Drawing::Color::White;
            this->label64->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label64->Location = System::Drawing::Point(30, 867);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(113, 28);
            this->label64->TabIndex = 349;
            this->label64->Text = L"Wednesday";
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->BackColor = System::Drawing::Color::White;
            this->label66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label66->Location = System::Drawing::Point(294, 661);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(116, 28);
            this->label66->TabIndex = 354;
            this->label66->Text = L"10:00-11:00";
            // 
            // label67
            // 
            this->label67->AutoSize = true;
            this->label67->BackColor = System::Drawing::Color::White;
            this->label67->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label67->Location = System::Drawing::Point(30, 931);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(91, 28);
            this->label67->TabIndex = 350;
            this->label67->Text = L"Thursday";
            // 
            // label68
            // 
            this->label68->AutoSize = true;
            this->label68->BackColor = System::Drawing::Color::White;
            this->label68->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label68->Location = System::Drawing::Point(480, 661);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(116, 28);
            this->label68->TabIndex = 355;
            this->label68->Text = L"11:30-12:30";
            // 
            // label69
            // 
            this->label69->AutoSize = true;
            this->label69->BackColor = System::Drawing::Color::White;
            this->label69->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label69->Location = System::Drawing::Point(44, 1007);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(66, 28);
            this->label69->TabIndex = 351;
            this->label69->Text = L"Friday";
            // 
            // label70
            // 
            this->label70->AutoSize = true;
            this->label70->BackColor = System::Drawing::Color::White;
            this->label70->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label70->Location = System::Drawing::Point(634, 661);
            this->label70->Name = L"label70";
            this->label70->Size = System::Drawing::Size(105, 28);
            this->label70->TabIndex = 356;
            this->label70->Text = L"12:30-1:30";
            // 
            // label71
            // 
            this->label71->AutoSize = true;
            this->label71->BackColor = System::Drawing::Color::White;
            this->label71->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label71->Location = System::Drawing::Point(44, 1084);
            this->label71->Name = L"label71";
            this->label71->Size = System::Drawing::Size(90, 28);
            this->label71->TabIndex = 352;
            this->label71->Text = L"Saturday";
            // 
            // label72
            // 
            this->label72->AutoSize = true;
            this->label72->BackColor = System::Drawing::Color::White;
            this->label72->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label72->Location = System::Drawing::Point(828, 657);
            this->label72->Name = L"label72";
            this->label72->Size = System::Drawing::Size(94, 28);
            this->label72->TabIndex = 357;
            this->label72->Text = L"2:30-3:30";
            // 
            // label73
            // 
            this->label73->AutoSize = true;
            this->label73->BackColor = System::Drawing::Color::White;
            this->label73->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label73->Location = System::Drawing::Point(958, 657);
            this->label73->Name = L"label73";
            this->label73->Size = System::Drawing::Size(94, 28);
            this->label73->TabIndex = 358;
            this->label73->Text = L"3:30-4:30";
            // 
            // sedataGridView
            // 
            this->sedataGridView->AllowUserToOrderColumns = true;
            this->sedataGridView->AllowUserToResizeColumns = false;
            this->sedataGridView->AllowUserToResizeRows = false;
            dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle17->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle17;
            this->sedataGridView->ColumnHeadersHeight = 36;
            this->sedataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->TeacherName,
                    this->dataGridViewButtonColumn4
            });
            this->sedataGridView->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->sedataGridView->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->sedataGridView->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sedataGridView->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sedataGridView->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sedataGridView->HideOuterBorders = true;
            this->sedataGridView->Location = System::Drawing::Point(71, 204);
            this->sedataGridView->Name = L"sedataGridView";
            this->sedataGridView->RowHeadersVisible = false;
            this->sedataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->RowsDefaultCellStyle = dataGridViewCellStyle18;
            this->sedataGridView->RowTemplate->Height = 28;
            this->sedataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->sedataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->sedataGridView->Size = System::Drawing::Size(865, 224);
            this->sedataGridView->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->sedataGridView->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->sedataGridView->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sedataGridView->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sedataGridView.StateCommon.DataCell.Content.Image")));
            this->sedataGridView->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->sedataGridView->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->sedataGridView->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->sedataGridView->StateCommon->HeaderColumn->Border->Width = 0;
            this->sedataGridView->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sedataGridView->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sedataGridView.StateCommon.HeaderColumn.Content.Image")));
            this->sedataGridView->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->sedataGridView->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->sedataGridView->TabIndex = 343;
            this->sedataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::kryptonDataGridView1_CellContentClick_1);
            // 
            // TeacherName
            // 
            this->TeacherName->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->TeacherName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->TeacherName->HeaderText = L"Teacher Name";
            this->TeacherName->MinimumWidth = 8;
            this->TeacherName->Name = L"TeacherName";
            this->TeacherName->Width = 350;
            // 
            // dataGridViewButtonColumn4
            // 
            this->dataGridViewButtonColumn4->HeaderText = L"";
            this->dataGridViewButtonColumn4->MinimumWidth = 8;
            this->dataGridViewButtonColumn4->Name = L"dataGridViewButtonColumn4";
            this->dataGridViewButtonColumn4->ReadOnly = true;
            this->dataGridViewButtonColumn4->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewButtonColumn4->Text = L"Delete";
            this->dataGridViewButtonColumn4->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn4->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn4->Width = 150;
            // 
            // addsubcluster
            // 
            this->addsubcluster->DropDownWidth = 342;
            this->addsubcluster->Location = System::Drawing::Point(75, 93);
            this->addsubcluster->Name = L"addsubcluster";
            this->addsubcluster->Size = System::Drawing::Size(508, 29);
            this->addsubcluster->StateCommon->DropBack->Color1 = System::Drawing::Color::Cyan;
            this->addsubcluster->StateCommon->DropBack->Color2 = System::Drawing::Color::Cyan;
            this->addsubcluster->TabIndex = 342;
            this->addsubcluster->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // addsubclusteroptions
            // 
            this->addsubclusteroptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubclusteroptions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubclusteroptions->Location = System::Drawing::Point(727, 444);
            this->addsubclusteroptions->Name = L"addsubclusteroptions";
            this->addsubclusteroptions->Size = System::Drawing::Size(154, 46);
            this->addsubclusteroptions->TabIndex = 310;
            this->addsubclusteroptions->Text = L"Options";
            this->addsubclusteroptions->UseVisualStyleBackColor = false;
            this->addsubclusteroptions->Click += gcnew System::EventHandler(this, &MyForm::addsubclusteroptions_Click_1);
            // 
            // label178
            // 
            this->label178->AutoSize = true;
            this->label178->BackColor = System::Drawing::Color::White;
            this->label178->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label178->Location = System::Drawing::Point(70, 34);
            this->label178->Name = L"label178";
            this->label178->Size = System::Drawing::Size(160, 28);
            this->label178->TabIndex = 341;
            this->label178->Text = L"Name of Cluster";
            // 
            // label179
            // 
            this->label179->AutoSize = true;
            this->label179->BackColor = System::Drawing::Color::White;
            this->label179->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label179->Location = System::Drawing::Point(70, 160);
            this->label179->Name = L"label179";
            this->label179->Size = System::Drawing::Size(349, 28);
            this->label179->TabIndex = 297;
            this->label179->Text = L"Teacher handling the elective subject";
            // 
            // kryptonLabel3
            // 
            this->kryptonLabel3->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel3->Name = L"kryptonLabel3";
            this->kryptonLabel3->Size = System::Drawing::Size(217, 43);
            this->kryptonLabel3->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel3->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel3->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel3->TabIndex = 2;
            this->kryptonLabel3->Values->Text = L"Subject Details";
            // 
            // addsubcreditsgroup
            // 
            this->addsubcreditsgroup->CaptionOverlap = 1;
            this->addsubcreditsgroup->CaptionVisible = false;
            this->addsubcreditsgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubcreditsgroup->Location = System::Drawing::Point(23, 2358);
            this->addsubcreditsgroup->Name = L"addsubcreditsgroup";
            // 
            // addsubcreditsgroup.Panel
            // 
            this->addsubcreditsgroup->Panel->Controls->Add(this->addsubcredits);
            this->addsubcreditsgroup->Panel->Controls->Add(this->label181);
            this->addsubcreditsgroup->Size = System::Drawing::Size(1127, 194);
            this->addsubcreditsgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubcreditsgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubcreditsgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->addsubcreditsgroup->StateCommon->Border->ColorAngle = 50;
            this->addsubcreditsgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubcreditsgroup->StateCommon->Border->Rounding = 7;
            this->addsubcreditsgroup->StateCommon->Border->Width = 1;
            this->addsubcreditsgroup->TabIndex = 341;
            this->addsubcreditsgroup->Enter += gcnew System::EventHandler(this, &MyForm::addsubcreditsgroup_Enter);
            // 
            // addsubcredits
            // 
            this->addsubcredits->Location = System::Drawing::Point(98, 96);
            this->addsubcredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->addsubcredits->Name = L"addsubcredits";
            this->addsubcredits->Size = System::Drawing::Size(304, 30);
            this->addsubcredits->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->addsubcredits->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->addsubcredits->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubcredits->TabIndex = 328;
            // 
            // label181
            // 
            this->label181->AutoSize = true;
            this->label181->BackColor = System::Drawing::Color::White;
            this->label181->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label181->ForeColor = System::Drawing::Color::Black;
            this->label181->Location = System::Drawing::Point(94, 39);
            this->label181->Name = L"label181";
            this->label181->Size = System::Drawing::Size(184, 28);
            this->label181->TabIndex = 327;
            this->label181->Text = L"Number Of Credits";
            // 
            // addsubtitlegroup
            // 
            this->addsubtitlegroup->CaptionOverlap = 1;
            this->addsubtitlegroup->CaptionVisible = false;
            this->addsubtitlegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubtitlegroup->Location = System::Drawing::Point(23, 404);
            this->addsubtitlegroup->Name = L"addsubtitlegroup";
            // 
            // addsubtitlegroup.Panel
            // 
            this->addsubtitlegroup->Panel->Controls->Add(this->kryptonPanel2);
            this->addsubtitlegroup->Panel->Controls->Add(this->label182);
            this->addsubtitlegroup->Panel->Controls->Add(this->addsubtitle);
            this->addsubtitlegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::addsubtitlegroup_Panel_Enter);
            this->addsubtitlegroup->Size = System::Drawing::Size(1127, 194);
            this->addsubtitlegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubtitlegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubtitlegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->addsubtitlegroup->StateCommon->Border->ColorAngle = 50;
            this->addsubtitlegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubtitlegroup->StateCommon->Border->Rounding = 7;
            this->addsubtitlegroup->StateCommon->Border->Width = 1;
            this->addsubtitlegroup->TabIndex = 338;
            // 
            // kryptonPanel2
            // 
            this->kryptonPanel2->Location = System::Drawing::Point(101, 128);
            this->kryptonPanel2->Name = L"kryptonPanel2";
            this->kryptonPanel2->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel2->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel2->TabIndex = 329;
            // 
            // label182
            // 
            this->label182->AutoSize = true;
            this->label182->BackColor = System::Drawing::Color::White;
            this->label182->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label182->ForeColor = System::Drawing::Color::Black;
            this->label182->Location = System::Drawing::Point(94, 39);
            this->label182->Name = L"label182";
            this->label182->Size = System::Drawing::Size(124, 28);
            this->label182->TabIndex = 327;
            this->label182->Text = L"Subject Title";
            // 
            // addsubtitle
            // 
            this->addsubtitle->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->addsubtitle->Location = System::Drawing::Point(99, 86);
            this->addsubtitle->Name = L"addsubtitle";
            this->addsubtitle->Size = System::Drawing::Size(478, 44);
            this->addsubtitle->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->addsubtitle->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubtitle->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubtitle->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->addsubtitle->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->addsubtitle->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->addsubtitle->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubtitle->StateCommon->Border->Rounding = 10;
            this->addsubtitle->StateCommon->Border->Width = 3;
            this->addsubtitle->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->addsubtitle->TabIndex = 328;
            this->addsubtitle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // addsubelegroup
            // 
            this->addsubelegroup->CaptionOverlap = 1;
            this->addsubelegroup->CaptionVisible = false;
            this->addsubelegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubelegroup->Location = System::Drawing::Point(23, 853);
            this->addsubelegroup->Name = L"addsubelegroup";
            // 
            // addsubelegroup.Panel
            // 
            this->addsubelegroup->Panel->Controls->Add(this->label183);
            this->addsubelegroup->Panel->Controls->Add(this->panel42);
            this->addsubelegroup->Size = System::Drawing::Size(1127, 194);
            this->addsubelegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubelegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubelegroup->StateCommon->Border->ColorAngle = 50;
            this->addsubelegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubelegroup->StateCommon->Border->Rounding = 7;
            this->addsubelegroup->StateCommon->Border->Width = 1;
            this->addsubelegroup->TabIndex = 339;
            this->addsubelegroup->Enter += gcnew System::EventHandler(this, &MyForm::addsubelegroup_Enter);
            // 
            // label183
            // 
            this->label183->AutoSize = true;
            this->label183->BackColor = System::Drawing::Color::White;
            this->label183->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label183->Location = System::Drawing::Point(95, 44);
            this->label183->Name = L"label183";
            this->label183->Size = System::Drawing::Size(376, 28);
            this->label183->TabIndex = 266;
            this->label183->Text = L"Is it a Elective or Common time subject\?";
            // 
            // panel42
            // 
            this->panel42->BackColor = System::Drawing::Color::White;
            this->panel42->Controls->Add(this->addsubeleyes);
            this->panel42->Controls->Add(this->addsubeleno);
            this->panel42->ForeColor = System::Drawing::Color::Black;
            this->panel42->Location = System::Drawing::Point(162, 90);
            this->panel42->Name = L"panel42";
            this->panel42->Size = System::Drawing::Size(492, 60);
            this->panel42->TabIndex = 267;
            // 
            // addsubeleyes
            // 
            this->addsubeleyes->Location = System::Drawing::Point(16, 14);
            this->addsubeleyes->Name = L"addsubeleyes";
            this->addsubeleyes->Size = System::Drawing::Size(58, 32);
            this->addsubeleyes->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->addsubeleyes->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->addsubeleyes->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->addsubeleyes->TabIndex = 328;
            this->addsubeleyes->Values->Text = L"YES";
            this->addsubeleyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsubeleyes_CheckedChanged_1);
            // 
            // addsubeleno
            // 
            this->addsubeleno->Location = System::Drawing::Point(230, 14);
            this->addsubeleno->Name = L"addsubeleno";
            this->addsubeleno->Size = System::Drawing::Size(56, 32);
            this->addsubeleno->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->addsubeleno->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->addsubeleno->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->addsubeleno->TabIndex = 330;
            this->addsubeleno->Values->Text = L"NO";
            this->addsubeleno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsubeleno_CheckedChanged_1);
            // 
            // addsubnamegroup
            // 
            this->addsubnamegroup->CaptionOverlap = 1;
            this->addsubnamegroup->CaptionVisible = false;
            this->addsubnamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubnamegroup->Location = System::Drawing::Point(23, 168);
            this->addsubnamegroup->Name = L"addsubnamegroup";
            // 
            // addsubnamegroup.Panel
            // 
            this->addsubnamegroup->Panel->Controls->Add(this->kryptonPanel5);
            this->addsubnamegroup->Panel->Controls->Add(this->label184);
            this->addsubnamegroup->Panel->Controls->Add(this->addsubname);
            this->addsubnamegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::addsubnamegroup_Panel_Enter);
            this->addsubnamegroup->Size = System::Drawing::Size(1127, 194);
            this->addsubnamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubnamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubnamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubnamegroup->StateCommon->Border->ColorAngle = 50;
            this->addsubnamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubnamegroup->StateCommon->Border->Rounding = 9;
            this->addsubnamegroup->StateCommon->Border->Width = 1;
            this->addsubnamegroup->TabIndex = 337;
            // 
            // kryptonPanel5
            // 
            this->kryptonPanel5->Location = System::Drawing::Point(97, 119);
            this->kryptonPanel5->Name = L"kryptonPanel5";
            this->kryptonPanel5->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel5->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel5->TabIndex = 326;
            // 
            // label184
            // 
            this->label184->AutoSize = true;
            this->label184->BackColor = System::Drawing::Color::White;
            this->label184->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label184->ForeColor = System::Drawing::Color::Black;
            this->label184->Location = System::Drawing::Point(93, 30);
            this->label184->Name = L"label184";
            this->label184->Size = System::Drawing::Size(228, 28);
            this->label184->TabIndex = 264;
            this->label184->Text = L"Enter the Subject Name";
            // 
            // addsubname
            // 
            this->addsubname->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->addsubname->Location = System::Drawing::Point(105, 75);
            this->addsubname->Name = L"addsubname";
            this->addsubname->Size = System::Drawing::Size(478, 44);
            this->addsubname->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->addsubname->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubname->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubname->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->addsubname->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->addsubname->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->addsubname->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubname->StateCommon->Border->Rounding = 10;
            this->addsubname->StateCommon->Border->Width = 3;
            this->addsubname->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->addsubname->TabIndex = 325;
            this->addsubname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // addsubcodegroup
            // 
            this->addsubcodegroup->CaptionOverlap = 1;
            this->addsubcodegroup->CaptionVisible = false;
            this->addsubcodegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addsubcodegroup->Location = System::Drawing::Point(23, 625);
            this->addsubcodegroup->Name = L"addsubcodegroup";
            // 
            // addsubcodegroup.Panel
            // 
            this->addsubcodegroup->Panel->Controls->Add(this->kryptonPanel7);
            this->addsubcodegroup->Panel->Controls->Add(this->label185);
            this->addsubcodegroup->Panel->Controls->Add(this->addsubcode);
            this->addsubcodegroup->Size = System::Drawing::Size(1127, 194);
            this->addsubcodegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addsubcodegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addsubcodegroup->StateCommon->Border->ColorAngle = 50;
            this->addsubcodegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubcodegroup->StateCommon->Border->Rounding = 7;
            this->addsubcodegroup->StateCommon->Border->Width = 1;
            this->addsubcodegroup->TabIndex = 336;
            // 
            // kryptonPanel7
            // 
            this->kryptonPanel7->Location = System::Drawing::Point(99, 137);
            this->kryptonPanel7->Name = L"kryptonPanel7";
            this->kryptonPanel7->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel7->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel7->TabIndex = 329;
            // 
            // label185
            // 
            this->label185->AutoSize = true;
            this->label185->BackColor = System::Drawing::Color::White;
            this->label185->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label185->ForeColor = System::Drawing::Color::Black;
            this->label185->Location = System::Drawing::Point(93, 46);
            this->label185->Name = L"label185";
            this->label185->Size = System::Drawing::Size(132, 28);
            this->label185->TabIndex = 327;
            this->label185->Text = L"Subject Code";
            // 
            // addsubcode
            // 
            this->addsubcode->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->addsubcode->Location = System::Drawing::Point(98, 92);
            this->addsubcode->Name = L"addsubcode";
            this->addsubcode->Size = System::Drawing::Size(478, 44);
            this->addsubcode->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->addsubcode->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubcode->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubcode->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->addsubcode->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->addsubcode->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->addsubcode->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addsubcode->StateCommon->Border->Rounding = 10;
            this->addsubcode->StateCommon->Border->Width = 3;
            this->addsubcode->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->addsubcode->TabIndex = 328;
            this->addsubcode->Enter += gcnew System::EventHandler(this, &MyForm::addsubcode_Enter);
            this->addsubcode->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // saveroom
            // 
            this->saveroom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->saveroom->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->saveroom->Location = System::Drawing::Point(19, 45);
            this->saveroom->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->saveroom->Name = L"saveroom";
            this->saveroom->Size = System::Drawing::Size(154, 58);
            this->saveroom->TabIndex = 66;
            this->saveroom->Text = L"Save";
            this->saveroom->UseVisualStyleBackColor = false;
            this->saveroom->Click += gcnew System::EventHandler(this, &MyForm::saveroom_Click);
            // 
            // clearroom
            // 
            this->clearroom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->clearroom->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->clearroom->Location = System::Drawing::Point(252, 45);
            this->clearroom->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->clearroom->Name = L"clearroom";
            this->clearroom->Size = System::Drawing::Size(154, 58);
            this->clearroom->TabIndex = 122;
            this->clearroom->Text = L"Clear";
            this->clearroom->UseVisualStyleBackColor = false;
            this->clearroom->Click += gcnew System::EventHandler(this, &MyForm::clearroom_Click);
            // 
            // addclassroompanel
            // 
            this->addclassroompanel->AutoScroll = true;
            this->addclassroompanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addclassroompanel->Controls->Add(this->panel7);
            this->addclassroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addclassroompanel->Location = System::Drawing::Point(0, 0);
            this->addclassroompanel->Name = L"addclassroompanel";
            this->addclassroompanel->Size = System::Drawing::Size(1924, 1050);
            this->addclassroompanel->TabIndex = 230;
            this->addclassroompanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addclassroompanel_Paint);
            // 
            // panel7
            // 
            this->panel7->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->panel7->Controls->Add(this->kryptonGroupBox9);
            this->panel7->Controls->Add(this->panel9);
            this->panel7->Controls->Add(this->roomdeptgroup);
            this->panel7->Controls->Add(this->kryptonLabel5);
            this->panel7->Controls->Add(this->roomcapacitygroup);
            this->panel7->Controls->Add(this->roomlabgroup);
            this->panel7->Controls->Add(this->roomnamegroup);
            this->panel7->Location = System::Drawing::Point(179, 13);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(1194, 2180);
            this->panel7->TabIndex = 342;
            this->panel7->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel7_Paint_1);
            // 
            // kryptonGroupBox9
            // 
            this->kryptonGroupBox9->CaptionOverlap = 1;
            this->kryptonGroupBox9->CaptionVisible = false;
            this->kryptonGroupBox9->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox9->Location = System::Drawing::Point(25, 1212);
            this->kryptonGroupBox9->Name = L"kryptonGroupBox9";
            // 
            // kryptonGroupBox9.Panel
            // 
            this->kryptonGroupBox9->Panel->Controls->Add(this->panel37);
            this->kryptonGroupBox9->Panel->Controls->Add(this->panel12);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label5);
            this->kryptonGroupBox9->Panel->Controls->Add(this->addroomtablepanel);
            this->kryptonGroupBox9->Panel->Controls->Add(this->panel43);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label134);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label133);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label29);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label132);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label30);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label131);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label31);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label130);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label126);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label129);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label127);
            this->kryptonGroupBox9->Panel->Controls->Add(this->label128);
            this->kryptonGroupBox9->Size = System::Drawing::Size(1127, 642);
            this->kryptonGroupBox9->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox9->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox9->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox9->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox9->StateCommon->Border->Rounding = 7;
            this->kryptonGroupBox9->StateCommon->Border->Width = 1;
            this->kryptonGroupBox9->TabIndex = 346;
            this->kryptonGroupBox9->Enter += gcnew System::EventHandler(this, &MyForm::kryptonGroupBox9_Enter);
            // 
            // panel37
            // 
            this->panel37->BackColor = System::Drawing::Color::White;
            this->panel37->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel37.BackgroundImage")));
            this->panel37->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel37->Location = System::Drawing::Point(735, 146);
            this->panel37->Name = L"panel37";
            this->panel37->Size = System::Drawing::Size(44, 420);
            this->panel37->TabIndex = 1;
            // 
            // panel12
            // 
            this->panel12->BackColor = System::Drawing::Color::White;
            this->panel12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel12.BackgroundImage")));
            this->panel12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel12->Location = System::Drawing::Point(400, 146);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(44, 430);
            this->panel12->TabIndex = 300;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::White;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(98, 36);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(154, 28);
            this->label5->TabIndex = 344;
            this->label5->Text = L"Room Schedule";
            // 
            // addroomtablepanel
            // 
            this->addroomtablepanel->BackColor = System::Drawing::Color::White;
            this->addroomtablepanel->ColumnCount = 8;
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->addroomtablepanel->Location = System::Drawing::Point(113, 146);
            this->addroomtablepanel->Name = L"addroomtablepanel";
            this->addroomtablepanel->RowCount = 6;
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->Size = System::Drawing::Size(950, 431);
            this->addroomtablepanel->TabIndex = 260;
            // 
            // panel43
            // 
            this->panel43->BackColor = System::Drawing::Color::White;
            this->panel43->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel43.BackgroundImage")));
            this->panel43->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel43->Location = System::Drawing::Point(389, 146);
            this->panel43->Name = L"panel43";
            this->panel43->Size = System::Drawing::Size(82, 412);
            this->panel43->TabIndex = 2;
            // 
            // label134
            // 
            this->label134->AutoSize = true;
            this->label134->BackColor = System::Drawing::Color::White;
            this->label134->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label134->Location = System::Drawing::Point(13, 166);
            this->label134->Name = L"label134";
            this->label134->Size = System::Drawing::Size(85, 28);
            this->label134->TabIndex = 261;
            this->label134->Text = L"Monday";
            // 
            // label133
            // 
            this->label133->AutoSize = true;
            this->label133->BackColor = System::Drawing::Color::White;
            this->label133->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label133->Location = System::Drawing::Point(19, 235);
            this->label133->Name = L"label133";
            this->label133->Size = System::Drawing::Size(83, 28);
            this->label133->TabIndex = 262;
            this->label133->Text = L"Tuesday";
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->BackColor = System::Drawing::Color::White;
            this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label29->Location = System::Drawing::Point(131, 106);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(105, 28);
            this->label29->TabIndex = 294;
            this->label29->Text = L"9:00-10:00";
            // 
            // label132
            // 
            this->label132->AutoSize = true;
            this->label132->BackColor = System::Drawing::Color::White;
            this->label132->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label132->Location = System::Drawing::Point(3, 312);
            this->label132->Name = L"label132";
            this->label132->Size = System::Drawing::Size(113, 28);
            this->label132->TabIndex = 263;
            this->label132->Text = L"Wednesday";
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->BackColor = System::Drawing::Color::White;
            this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(267, 106);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(116, 28);
            this->label30->TabIndex = 295;
            this->label30->Text = L"10:00-11:00";
            // 
            // label131
            // 
            this->label131->AutoSize = true;
            this->label131->BackColor = System::Drawing::Color::White;
            this->label131->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label131->Location = System::Drawing::Point(3, 376);
            this->label131->Name = L"label131";
            this->label131->Size = System::Drawing::Size(91, 28);
            this->label131->TabIndex = 264;
            this->label131->Text = L"Thursday";
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->BackColor = System::Drawing::Color::White;
            this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label31->Location = System::Drawing::Point(453, 106);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(116, 28);
            this->label31->TabIndex = 296;
            this->label31->Text = L"11:30-12:30";
            // 
            // label130
            // 
            this->label130->AutoSize = true;
            this->label130->BackColor = System::Drawing::Color::White;
            this->label130->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label130->Location = System::Drawing::Point(17, 452);
            this->label130->Name = L"label130";
            this->label130->Size = System::Drawing::Size(66, 28);
            this->label130->TabIndex = 265;
            this->label130->Text = L"Friday";
            // 
            // label126
            // 
            this->label126->AutoSize = true;
            this->label126->BackColor = System::Drawing::Color::White;
            this->label126->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label126->Location = System::Drawing::Point(607, 106);
            this->label126->Name = L"label126";
            this->label126->Size = System::Drawing::Size(105, 28);
            this->label126->TabIndex = 297;
            this->label126->Text = L"12:30-1:30";
            // 
            // label129
            // 
            this->label129->AutoSize = true;
            this->label129->BackColor = System::Drawing::Color::White;
            this->label129->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label129->Location = System::Drawing::Point(17, 529);
            this->label129->Name = L"label129";
            this->label129->Size = System::Drawing::Size(90, 28);
            this->label129->TabIndex = 266;
            this->label129->Text = L"Saturday";
            // 
            // label127
            // 
            this->label127->AutoSize = true;
            this->label127->BackColor = System::Drawing::Color::White;
            this->label127->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label127->Location = System::Drawing::Point(801, 102);
            this->label127->Name = L"label127";
            this->label127->Size = System::Drawing::Size(94, 28);
            this->label127->TabIndex = 298;
            this->label127->Text = L"2:30-3:30";
            // 
            // label128
            // 
            this->label128->AutoSize = true;
            this->label128->BackColor = System::Drawing::Color::White;
            this->label128->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label128->Location = System::Drawing::Point(931, 102);
            this->label128->Name = L"label128";
            this->label128->Size = System::Drawing::Size(94, 28);
            this->label128->TabIndex = 299;
            this->label128->Text = L"3:30-4:30";
            // 
            // panel9
            // 
            this->panel9->Controls->Add(this->clearroom);
            this->panel9->Controls->Add(this->saveroom);
            this->panel9->Location = System::Drawing::Point(725, 1879);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(414, 156);
            this->panel9->TabIndex = 124;
            // 
            // roomdeptgroup
            // 
            this->roomdeptgroup->CaptionOverlap = 1;
            this->roomdeptgroup->CaptionVisible = false;
            this->roomdeptgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->roomdeptgroup->Location = System::Drawing::Point(23, 903);
            this->roomdeptgroup->Name = L"roomdeptgroup";
            // 
            // roomdeptgroup.Panel
            // 
            this->roomdeptgroup->Panel->Controls->Add(this->roomdept);
            this->roomdeptgroup->Panel->Controls->Add(this->label28);
            this->roomdeptgroup->Size = System::Drawing::Size(1127, 194);
            this->roomdeptgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->roomdeptgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->roomdeptgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->roomdeptgroup->StateCommon->Border->ColorAngle = 50;
            this->roomdeptgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomdeptgroup->StateCommon->Border->Rounding = 7;
            this->roomdeptgroup->StateCommon->Border->Width = 1;
            this->roomdeptgroup->TabIndex = 342;
            this->roomdeptgroup->Enter += gcnew System::EventHandler(this, &MyForm::roomdeptgroup_Enter);
            // 
            // roomdept
            // 
            this->roomdept->DropDownWidth = 342;
            this->roomdept->Location = System::Drawing::Point(99, 100);
            this->roomdept->Name = L"roomdept";
            this->roomdept->Size = System::Drawing::Size(508, 29);
            this->roomdept->StateCommon->DropBack->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->roomdept->StateCommon->DropBack->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->roomdept->TabIndex = 344;
            this->roomdept->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::roomdept_SelectedIndexChanged);
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->BackColor = System::Drawing::Color::White;
            this->label28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label28->Location = System::Drawing::Point(94, 41);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(122, 28);
            this->label28->TabIndex = 343;
            this->label28->Text = L"Department";
            this->label28->Click += gcnew System::EventHandler(this, &MyForm::label28_Click);
            // 
            // kryptonLabel5
            // 
            this->kryptonLabel5->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel5->Name = L"kryptonLabel5";
            this->kryptonLabel5->Size = System::Drawing::Size(264, 43);
            this->kryptonLabel5->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel5->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel5->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel5->TabIndex = 2;
            this->kryptonLabel5->Values->Text = L"ClassRoom Details";
            // 
            // roomcapacitygroup
            // 
            this->roomcapacitygroup->CaptionOverlap = 1;
            this->roomcapacitygroup->CaptionVisible = false;
            this->roomcapacitygroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->roomcapacitygroup->Location = System::Drawing::Point(23, 421);
            this->roomcapacitygroup->Name = L"roomcapacitygroup";
            // 
            // roomcapacitygroup.Panel
            // 
            this->roomcapacitygroup->Panel->Controls->Add(this->roomcapacity);
            this->roomcapacitygroup->Panel->Controls->Add(this->label187);
            this->roomcapacitygroup->Size = System::Drawing::Size(1127, 194);
            this->roomcapacitygroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->roomcapacitygroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->roomcapacitygroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->roomcapacitygroup->StateCommon->Border->ColorAngle = 50;
            this->roomcapacitygroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomcapacitygroup->StateCommon->Border->Rounding = 7;
            this->roomcapacitygroup->StateCommon->Border->Width = 1;
            this->roomcapacitygroup->TabIndex = 341;
            this->roomcapacitygroup->Enter += gcnew System::EventHandler(this, &MyForm::roomcapacitygroup_Enter);
            // 
            // roomcapacity
            // 
            this->roomcapacity->Location = System::Drawing::Point(98, 96);
            this->roomcapacity->Name = L"roomcapacity";
            this->roomcapacity->Size = System::Drawing::Size(304, 30);
            this->roomcapacity->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomcapacity->TabIndex = 328;
            // 
            // label187
            // 
            this->label187->AutoSize = true;
            this->label187->BackColor = System::Drawing::Color::White;
            this->label187->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label187->ForeColor = System::Drawing::Color::Black;
            this->label187->Location = System::Drawing::Point(94, 39);
            this->label187->Name = L"label187";
            this->label187->Size = System::Drawing::Size(146, 28);
            this->label187->TabIndex = 327;
            this->label187->Text = L"Room Capacity";
            // 
            // roomlabgroup
            // 
            this->roomlabgroup->CaptionOverlap = 1;
            this->roomlabgroup->CaptionVisible = false;
            this->roomlabgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->roomlabgroup->Location = System::Drawing::Point(22, 661);
            this->roomlabgroup->Name = L"roomlabgroup";
            // 
            // roomlabgroup.Panel
            // 
            this->roomlabgroup->Panel->Controls->Add(this->label189);
            this->roomlabgroup->Panel->Controls->Add(this->panel44);
            this->roomlabgroup->Size = System::Drawing::Size(1127, 194);
            this->roomlabgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->roomlabgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->roomlabgroup->StateCommon->Border->ColorAngle = 50;
            this->roomlabgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomlabgroup->StateCommon->Border->Rounding = 7;
            this->roomlabgroup->StateCommon->Border->Width = 1;
            this->roomlabgroup->TabIndex = 339;
            this->roomlabgroup->Enter += gcnew System::EventHandler(this, &MyForm::roomlabgroup_Enter);
            // 
            // label189
            // 
            this->label189->AutoSize = true;
            this->label189->BackColor = System::Drawing::Color::White;
            this->label189->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label189->Location = System::Drawing::Point(95, 44);
            this->label189->Name = L"label189";
            this->label189->Size = System::Drawing::Size(108, 28);
            this->label189->TabIndex = 266;
            this->label189->Text = L"Is it a Lab\?";
            // 
            // panel44
            // 
            this->panel44->BackColor = System::Drawing::Color::White;
            this->panel44->Controls->Add(this->roomlabyes);
            this->panel44->Controls->Add(this->roomlabno);
            this->panel44->ForeColor = System::Drawing::Color::Black;
            this->panel44->Location = System::Drawing::Point(162, 90);
            this->panel44->Name = L"panel44";
            this->panel44->Size = System::Drawing::Size(492, 60);
            this->panel44->TabIndex = 267;
            // 
            // roomlabyes
            // 
            this->roomlabyes->Location = System::Drawing::Point(16, 14);
            this->roomlabyes->Name = L"roomlabyes";
            this->roomlabyes->Size = System::Drawing::Size(58, 32);
            this->roomlabyes->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->roomlabyes->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->roomlabyes->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->roomlabyes->TabIndex = 328;
            this->roomlabyes->Values->Text = L"YES";
            // 
            // roomlabno
            // 
            this->roomlabno->Location = System::Drawing::Point(230, 14);
            this->roomlabno->Name = L"roomlabno";
            this->roomlabno->Size = System::Drawing::Size(56, 32);
            this->roomlabno->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->roomlabno->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->roomlabno->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->roomlabno->TabIndex = 330;
            this->roomlabno->Values->Text = L"NO";
            // 
            // roomnamegroup
            // 
            this->roomnamegroup->CaptionOverlap = 1;
            this->roomnamegroup->CaptionVisible = false;
            this->roomnamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->roomnamegroup->Location = System::Drawing::Point(23, 168);
            this->roomnamegroup->Name = L"roomnamegroup";
            // 
            // roomnamegroup.Panel
            // 
            this->roomnamegroup->Panel->Controls->Add(this->kryptonPanel12);
            this->roomnamegroup->Panel->Controls->Add(this->label190);
            this->roomnamegroup->Panel->Controls->Add(this->roomname);
            this->roomnamegroup->Size = System::Drawing::Size(1127, 194);
            this->roomnamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->roomnamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->roomnamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->roomnamegroup->StateCommon->Border->ColorAngle = 50;
            this->roomnamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomnamegroup->StateCommon->Border->Rounding = 9;
            this->roomnamegroup->StateCommon->Border->Width = 1;
            this->roomnamegroup->TabIndex = 337;
            this->roomnamegroup->Enter += gcnew System::EventHandler(this, &MyForm::roomnamegroup_Enter);
            // 
            // kryptonPanel12
            // 
            this->kryptonPanel12->Location = System::Drawing::Point(97, 119);
            this->kryptonPanel12->Name = L"kryptonPanel12";
            this->kryptonPanel12->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel12->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel12->TabIndex = 326;
            // 
            // label190
            // 
            this->label190->AutoSize = true;
            this->label190->BackColor = System::Drawing::Color::White;
            this->label190->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label190->ForeColor = System::Drawing::Color::Black;
            this->label190->Location = System::Drawing::Point(93, 30);
            this->label190->Name = L"label190";
            this->label190->Size = System::Drawing::Size(255, 28);
            this->label190->TabIndex = 264;
            this->label190->Text = L"Enter the Classroom Name";
            // 
            // roomname
            // 
            this->roomname->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->roomname->Location = System::Drawing::Point(105, 75);
            this->roomname->Name = L"roomname";
            this->roomname->Size = System::Drawing::Size(478, 44);
            this->roomname->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->roomname->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomname->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->roomname->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->roomname->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->roomname->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->roomname->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->roomname->StateCommon->Border->Rounding = 10;
            this->roomname->StateCommon->Border->Width = 3;
            this->roomname->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->roomname->TabIndex = 325;
            this->roomname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // Homepanel
            // 
            this->Homepanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Homepanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Homepanel->Location = System::Drawing::Point(0, 0);
            this->Homepanel->Name = L"Homepanel";
            this->Homepanel->Size = System::Drawing::Size(1924, 1050);
            this->Homepanel->TabIndex = 258;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(292, -3);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(245, 140);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // editteacherpanel
            // 
            this->editteacherpanel->AutoScroll = true;
            this->editteacherpanel->Controls->Add(this->panel5);
            this->editteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editteacherpanel->Location = System::Drawing::Point(0, 0);
            this->editteacherpanel->Name = L"editteacherpanel";
            this->editteacherpanel->Size = System::Drawing::Size(1924, 1050);
            this->editteacherpanel->TabIndex = 264;
            this->editteacherpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editteacherpanel_Paint);
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->editteacheremailidgroup);
            this->panel5->Controls->Add(this->editteachersearchgroup);
            this->panel5->Controls->Add(this->panel18);
            this->panel5->Controls->Add(this->editteachertablegroup);
            this->panel5->Controls->Add(this->panel28);
            this->panel5->Controls->Add(this->editteacherdepartmentgroup);
            this->panel5->Controls->Add(this->kryptonLabel4);
            this->panel5->Controls->Add(this->editteachernamegroup);
            this->panel5->Location = System::Drawing::Point(179, 13);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1194, 2207);
            this->panel5->TabIndex = 344;
            // 
            // editteacheremailidgroup
            // 
            this->editteacheremailidgroup->CaptionOverlap = 1;
            this->editteacheremailidgroup->CaptionVisible = false;
            this->editteacheremailidgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editteacheremailidgroup->Location = System::Drawing::Point(23, 947);
            this->editteacheremailidgroup->Name = L"editteacheremailidgroup";
            // 
            // editteacheremailidgroup.Panel
            // 
            this->editteacheremailidgroup->Panel->Controls->Add(this->kryptonPanel9);
            this->editteacheremailidgroup->Panel->Controls->Add(this->label23);
            this->editteacheremailidgroup->Panel->Controls->Add(this->editteacheremailid);
            this->editteacheremailidgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editteacheremailidgroup_Panel_Enter);
            this->editteacheremailidgroup->Size = System::Drawing::Size(1127, 194);
            this->editteacheremailidgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editteacheremailidgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteacheremailidgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteacheremailidgroup->StateCommon->Border->ColorAngle = 50;
            this->editteacheremailidgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteacheremailidgroup->StateCommon->Border->Rounding = 9;
            this->editteacheremailidgroup->StateCommon->Border->Width = 1;
            this->editteacheremailidgroup->TabIndex = 348;
            // 
            // kryptonPanel9
            // 
            this->kryptonPanel9->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel9->Name = L"kryptonPanel9";
            this->kryptonPanel9->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel9->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel9->TabIndex = 326;
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->BackColor = System::Drawing::Color::White;
            this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->ForeColor = System::Drawing::Color::Black;
            this->label23->Location = System::Drawing::Point(93, 30);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(171, 28);
            this->label23->TabIndex = 264;
            this->label23->Text = L"Teacher\'s Email id";
            // 
            // editteacheremailid
            // 
            this->editteacheremailid->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editteacheremailid->Location = System::Drawing::Point(97, 79);
            this->editteacheremailid->Name = L"editteacheremailid";
            this->editteacheremailid->Size = System::Drawing::Size(478, 44);
            this->editteacheremailid->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editteacheremailid->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteacheremailid->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editteacheremailid->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editteacheremailid->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editteacheremailid->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editteacheremailid->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteacheremailid->StateCommon->Border->Rounding = 10;
            this->editteacheremailid->StateCommon->Border->Width = 3;
            this->editteacheremailid->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editteacheremailid->TabIndex = 325;
            this->editteacheremailid->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editteachersearchgroup
            // 
            this->editteachersearchgroup->CaptionOverlap = 1;
            this->editteachersearchgroup->CaptionVisible = false;
            this->editteachersearchgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editteachersearchgroup->Location = System::Drawing::Point(23, 168);
            this->editteachersearchgroup->Name = L"editteachersearchgroup";
            // 
            // editteachersearchgroup.Panel
            // 
            this->editteachersearchgroup->Panel->Controls->Add(this->editteachersearchbutton);
            this->editteachersearchgroup->Panel->Controls->Add(this->label6);
            this->editteachersearchgroup->Panel->Controls->Add(this->teachersearch);
            this->editteachersearchgroup->Size = System::Drawing::Size(1127, 260);
            this->editteachersearchgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editteachersearchgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteachersearchgroup->StateCommon->Border->ColorAngle = 50;
            this->editteachersearchgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteachersearchgroup->StateCommon->Border->Rounding = 10;
            this->editteachersearchgroup->StateCommon->Border->Width = 1;
            this->editteachersearchgroup->TabIndex = 347;
            this->editteachersearchgroup->Enter += gcnew System::EventHandler(this, &MyForm::editteachersearchgroup_Enter);
            // 
            // editteachersearchbutton
            // 
            this->editteachersearchbutton->BackColor = System::Drawing::Color::White;
            this->editteachersearchbutton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editteachersearchbutton.BackgroundImage")));
            this->editteachersearchbutton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->editteachersearchbutton->FlatAppearance->BorderSize = 0;
            this->editteachersearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editteachersearchbutton->Location = System::Drawing::Point(767, 126);
            this->editteachersearchbutton->Name = L"editteachersearchbutton";
            this->editteachersearchbutton->Size = System::Drawing::Size(28, 28);
            this->editteachersearchbutton->TabIndex = 345;
            this->editteachersearchbutton->UseVisualStyleBackColor = false;
            this->editteachersearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editteachersearchbutton_Click);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::White;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::Color::Black;
            this->label6->Location = System::Drawing::Point(372, 68);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(243, 28);
            this->label6->TabIndex = 264;
            this->label6->Text = L"Search the Teacher Name";
            // 
            // teachersearch
            // 
            this->teachersearch->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->teachersearch->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->teachersearch->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->teachersearch->DropBackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->teachersearch->DropDownWidth = 356;
            this->teachersearch->Location = System::Drawing::Point(236, 122);
            this->teachersearch->Name = L"teachersearch";
            this->teachersearch->Size = System::Drawing::Size(563, 34);
            this->teachersearch->Sorted = true;
            this->teachersearch->StateCommon->ComboBox->Back->Color1 = System::Drawing::Color::White;
            this->teachersearch->StateCommon->ComboBox->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->teachersearch->StateCommon->ComboBox->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->teachersearch->StateCommon->ComboBox->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Linear;
            this->teachersearch->StateCommon->ComboBox->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->teachersearch->StateCommon->ComboBox->Border->Rounding = 5;
            this->teachersearch->StateCommon->ComboBox->Border->Width = 2;
            this->teachersearch->StateCommon->ComboBox->Content->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->teachersearch->StateCommon->ComboBox->Content->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
            this->teachersearch->StateCommon->DropBack->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->teachersearch->StateCommon->Item->Content->ShortText->Color1 = System::Drawing::Color::DimGray;
            this->teachersearch->StateCommon->Item->Content->ShortText->Color2 = System::Drawing::Color::DimGray;
            this->teachersearch->StateCommon->Item->Content->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->teachersearch->StateNormal->ComboBox->Content->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->teachersearch->StateNormal->ComboBox->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->teachersearch->StateNormal->Item->Content->LongText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->teachersearch->StateNormal->Item->Content->LongText->Color2 = System::Drawing::Color::Silver;
            this->teachersearch->StateNormal->Item->Content->ShortText->Color1 = System::Drawing::Color::DimGray;
            this->teachersearch->StateNormal->Item->Content->ShortText->Color2 = System::Drawing::Color::DimGray;
            this->teachersearch->TabIndex = 323;
            this->teachersearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocus);
            this->teachersearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDown);
            this->teachersearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            this->teachersearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocus);
            // 
            // panel18
            // 
            this->panel18->Controls->Add(this->editteacherdelete);
            this->panel18->Controls->Add(this->editteachersave);
            this->panel18->Location = System::Drawing::Point(689, 1977);
            this->panel18->Name = L"panel18";
            this->panel18->Size = System::Drawing::Size(406, 116);
            this->panel18->TabIndex = 291;
            // 
            // editteacherdelete
            // 
            this->editteacherdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editteacherdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdelete->Location = System::Drawing::Point(232, 34);
            this->editteacherdelete->Name = L"editteacherdelete";
            this->editteacherdelete->Size = System::Drawing::Size(154, 58);
            this->editteacherdelete->TabIndex = 290;
            this->editteacherdelete->Text = L"Delete";
            this->editteacherdelete->UseVisualStyleBackColor = false;
            this->editteacherdelete->Click += gcnew System::EventHandler(this, &MyForm::editteacherdelete_Click);
            // 
            // editteachersave
            // 
            this->editteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteachersave->Location = System::Drawing::Point(16, 34);
            this->editteachersave->Name = L"editteachersave";
            this->editteachersave->Size = System::Drawing::Size(154, 58);
            this->editteachersave->TabIndex = 273;
            this->editteachersave->Text = L"Save";
            this->editteachersave->UseVisualStyleBackColor = false;
            this->editteachersave->Click += gcnew System::EventHandler(this, &MyForm::editteachersave_Click);
            // 
            // editteachertablegroup
            // 
            this->editteachertablegroup->CaptionOverlap = 1;
            this->editteachertablegroup->CaptionVisible = false;
            this->editteachertablegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editteachertablegroup->Location = System::Drawing::Point(23, 1262);
            this->editteachertablegroup->Name = L"editteachertablegroup";
            // 
            // editteachertablegroup.Panel
            // 
            this->editteachertablegroup->Panel->Controls->Add(this->panel19);
            this->editteachertablegroup->Panel->Controls->Add(this->panel23);
            this->editteachertablegroup->Panel->Controls->Add(this->editteachertablepanel);
            this->editteachertablegroup->Panel->Controls->Add(this->panel24);
            this->editteachertablegroup->Panel->Controls->Add(this->label7);
            this->editteachertablegroup->Panel->Controls->Add(this->label21);
            this->editteachertablegroup->Panel->Controls->Add(this->label8);
            this->editteachertablegroup->Panel->Controls->Add(this->label9);
            this->editteachertablegroup->Panel->Controls->Add(this->label10);
            this->editteachertablegroup->Panel->Controls->Add(this->label11);
            this->editteachertablegroup->Panel->Controls->Add(this->label12);
            this->editteachertablegroup->Panel->Controls->Add(this->label14);
            this->editteachertablegroup->Panel->Controls->Add(this->label16);
            this->editteachertablegroup->Panel->Controls->Add(this->label17);
            this->editteachertablegroup->Panel->Controls->Add(this->label18);
            this->editteachertablegroup->Panel->Controls->Add(this->label19);
            this->editteachertablegroup->Panel->Controls->Add(this->label20);
            this->editteachertablegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editteachertablegroup_Panel_Enter);
            this->editteachertablegroup->Size = System::Drawing::Size(1127, 642);
            this->editteachertablegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editteachertablegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteachertablegroup->StateCommon->Border->ColorAngle = 50;
            this->editteachertablegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteachertablegroup->StateCommon->Border->Rounding = 7;
            this->editteachertablegroup->StateCommon->Border->Width = 1;
            this->editteachertablegroup->TabIndex = 346;
            // 
            // panel19
            // 
            this->panel19->BackColor = System::Drawing::Color::White;
            this->panel19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel19.BackgroundImage")));
            this->panel19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel19->Location = System::Drawing::Point(743, 159);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(44, 420);
            this->panel19->TabIndex = 1;
            // 
            // panel23
            // 
            this->panel23->BackColor = System::Drawing::Color::White;
            this->panel23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel23.BackgroundImage")));
            this->panel23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel23->Location = System::Drawing::Point(408, 159);
            this->panel23->Name = L"panel23";
            this->panel23->Size = System::Drawing::Size(44, 430);
            this->panel23->TabIndex = 300;
            // 
            // editteachertablepanel
            // 
            this->editteachertablepanel->BackColor = System::Drawing::Color::White;
            this->editteachertablepanel->ColumnCount = 8;
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->editteachertablepanel->Location = System::Drawing::Point(121, 159);
            this->editteachertablepanel->Name = L"editteachertablepanel";
            this->editteachertablepanel->RowCount = 6;
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66666F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66666F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66666F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66666F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->Size = System::Drawing::Size(950, 431);
            this->editteachertablepanel->TabIndex = 260;
            // 
            // panel24
            // 
            this->panel24->BackColor = System::Drawing::Color::White;
            this->panel24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel24.BackgroundImage")));
            this->panel24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel24->Location = System::Drawing::Point(397, 159);
            this->panel24->Name = L"panel24";
            this->panel24->Size = System::Drawing::Size(82, 412);
            this->panel24->TabIndex = 2;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::White;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(21, 179);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(85, 28);
            this->label7->TabIndex = 261;
            this->label7->Text = L"Monday";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->BackColor = System::Drawing::Color::White;
            this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->Location = System::Drawing::Point(81, 42);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(170, 28);
            this->label21->TabIndex = 344;
            this->label21->Text = L"Teacher Schedule";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::Color::White;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(27, 248);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(83, 28);
            this->label8->TabIndex = 262;
            this->label8->Text = L"Tuesday";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::Color::White;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(139, 119);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(105, 28);
            this->label9->TabIndex = 294;
            this->label9->Text = L"9:00-10:00";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->BackColor = System::Drawing::Color::White;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(11, 325);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(113, 28);
            this->label10->TabIndex = 263;
            this->label10->Text = L"Wednesday";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->BackColor = System::Drawing::Color::White;
            this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(275, 119);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(116, 28);
            this->label11->TabIndex = 295;
            this->label11->Text = L"10:00-11:00";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->BackColor = System::Drawing::Color::White;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(11, 389);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(91, 28);
            this->label12->TabIndex = 264;
            this->label12->Text = L"Thursday";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->BackColor = System::Drawing::Color::White;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(461, 119);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(116, 28);
            this->label14->TabIndex = 296;
            this->label14->Text = L"11:30-12:30";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->BackColor = System::Drawing::Color::White;
            this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(25, 465);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(66, 28);
            this->label16->TabIndex = 265;
            this->label16->Text = L"Friday";
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->BackColor = System::Drawing::Color::White;
            this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label17->Location = System::Drawing::Point(615, 119);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(105, 28);
            this->label17->TabIndex = 297;
            this->label17->Text = L"12:30-1:30";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->BackColor = System::Drawing::Color::White;
            this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(25, 542);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(90, 28);
            this->label18->TabIndex = 266;
            this->label18->Text = L"Saturday";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->BackColor = System::Drawing::Color::White;
            this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label19->Location = System::Drawing::Point(809, 115);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(94, 28);
            this->label19->TabIndex = 298;
            this->label19->Text = L"2:30-3:30";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->BackColor = System::Drawing::Color::White;
            this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(939, 115);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(94, 28);
            this->label20->TabIndex = 299;
            this->label20->Text = L"3:30-4:30";
            // 
            // panel28
            // 
            this->panel28->Controls->Add(this->button21);
            this->panel28->Controls->Add(this->button23);
            this->panel28->Location = System::Drawing::Point(709, 2211);
            this->panel28->Name = L"panel28";
            this->panel28->Size = System::Drawing::Size(502, 137);
            this->panel28->TabIndex = 295;
            // 
            // button21
            // 
            this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button21->Location = System::Drawing::Point(303, 38);
            this->button21->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button21->Name = L"button21";
            this->button21->Size = System::Drawing::Size(154, 58);
            this->button21->TabIndex = 180;
            this->button21->Text = L"Delete";
            this->button21->UseVisualStyleBackColor = false;
            // 
            // button23
            // 
            this->button23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button23->Location = System::Drawing::Point(49, 38);
            this->button23->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button23->Name = L"button23";
            this->button23->Size = System::Drawing::Size(154, 58);
            this->button23->TabIndex = 124;
            this->button23->Text = L"Save";
            this->button23->UseVisualStyleBackColor = false;
            // 
            // editteacherdepartmentgroup
            // 
            this->editteacherdepartmentgroup->CaptionOverlap = 1;
            this->editteacherdepartmentgroup->CaptionVisible = false;
            this->editteacherdepartmentgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editteacherdepartmentgroup->Location = System::Drawing::Point(23, 695);
            this->editteacherdepartmentgroup->Name = L"editteacherdepartmentgroup";
            // 
            // editteacherdepartmentgroup.Panel
            // 
            this->editteacherdepartmentgroup->Panel->Controls->Add(this->label22);
            this->editteacherdepartmentgroup->Panel->Controls->Add(this->editteacherdepartment);
            this->editteacherdepartmentgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editteacherdepartmentgroup_Panel_Enter);
            this->editteacherdepartmentgroup->Size = System::Drawing::Size(1127, 194);
            this->editteacherdepartmentgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editteacherdepartmentgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteacherdepartmentgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editteacherdepartmentgroup->StateCommon->Border->ColorAngle = 50;
            this->editteacherdepartmentgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteacherdepartmentgroup->StateCommon->Border->Rounding = 7;
            this->editteacherdepartmentgroup->StateCommon->Border->Width = 1;
            this->editteacherdepartmentgroup->TabIndex = 342;
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->BackColor = System::Drawing::Color::White;
            this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(94, 41);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(122, 28);
            this->label22->TabIndex = 343;
            this->label22->Text = L"Department";
            // 
            // editteacherdepartment
            // 
            this->editteacherdepartment->DropDownWidth = 342;
            this->editteacherdepartment->Location = System::Drawing::Point(87, 95);
            this->editteacherdepartment->Name = L"editteacherdepartment";
            this->editteacherdepartment->Size = System::Drawing::Size(563, 29);
            this->editteacherdepartment->StateCommon->DropBack->Color1 = System::Drawing::Color::Cyan;
            this->editteacherdepartment->StateCommon->DropBack->Color2 = System::Drawing::Color::Cyan;
            this->editteacherdepartment->TabIndex = 344;
            this->editteacherdepartment->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // kryptonLabel4
            // 
            this->kryptonLabel4->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel4->Name = L"kryptonLabel4";
            this->kryptonLabel4->Size = System::Drawing::Size(223, 43);
            this->kryptonLabel4->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel4->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel4->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel4->TabIndex = 2;
            this->kryptonLabel4->Values->Text = L"Teacher Details";
            // 
            // editteachernamegroup
            // 
            this->editteachernamegroup->CaptionOverlap = 1;
            this->editteachernamegroup->CaptionVisible = false;
            this->editteachernamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editteachernamegroup->Location = System::Drawing::Point(23, 451);
            this->editteachernamegroup->Name = L"editteachernamegroup";
            // 
            // editteachernamegroup.Panel
            // 
            this->editteachernamegroup->Panel->Controls->Add(this->kryptonPanel8);
            this->editteachernamegroup->Panel->Controls->Add(this->label25);
            this->editteachernamegroup->Panel->Controls->Add(this->editteachername);
            this->editteachernamegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editteachernamegroup_Panel_Enter);
            this->editteachernamegroup->Size = System::Drawing::Size(1127, 194);
            this->editteachernamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editteachernamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteachernamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editteachernamegroup->StateCommon->Border->ColorAngle = 50;
            this->editteachernamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteachernamegroup->StateCommon->Border->Rounding = 9;
            this->editteachernamegroup->StateCommon->Border->Width = 1;
            this->editteachernamegroup->TabIndex = 337;
            // 
            // kryptonPanel8
            // 
            this->kryptonPanel8->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel8->Name = L"kryptonPanel8";
            this->kryptonPanel8->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel8->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel8->TabIndex = 326;
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->BackColor = System::Drawing::Color::White;
            this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label25->ForeColor = System::Drawing::Color::Black;
            this->label25->Location = System::Drawing::Point(93, 30);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(141, 28);
            this->label25->TabIndex = 264;
            this->label25->Text = L"Teacher Name";
            // 
            // editteachername
            // 
            this->editteachername->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editteachername->Location = System::Drawing::Point(97, 79);
            this->editteachername->Name = L"editteachername";
            this->editteachername->Size = System::Drawing::Size(478, 44);
            this->editteachername->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editteachername->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteachername->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editteachername->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editteachername->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editteachername->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editteachername->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editteachername->StateCommon->Border->Rounding = 10;
            this->editteachername->StateCommon->Border->Width = 3;
            this->editteachername->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editteachername->TabIndex = 325;
            this->editteachername->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editsubactivepanel
            // 
            this->editsubactivepanel->Location = System::Drawing::Point(427, 179);
            this->editsubactivepanel->Name = L"editsubactivepanel";
            this->editsubactivepanel->Size = System::Drawing::Size(8, 147);
            this->editsubactivepanel->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubactivepanel->StateCommon->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubactivepanel->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>(((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left));
            this->editsubactivepanel->StateCommon->Border->Rounding = 9;
            this->editsubactivepanel->TabIndex = 327;
            this->editsubactivepanel->Values->Text = L"";
            // 
            // kryptonPanel6
            // 
            this->kryptonPanel6->Controls->Add(this->kryptonLabel1);
            this->kryptonPanel6->Controls->Add(this->panel4);
            this->kryptonPanel6->Dock = System::Windows::Forms::DockStyle::Top;
            this->kryptonPanel6->Location = System::Drawing::Point(0, 0);
            this->kryptonPanel6->Name = L"kryptonPanel6";
            this->kryptonPanel6->Size = System::Drawing::Size(1924, 76);
            this->kryptonPanel6->StateCommon->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->kryptonPanel6->TabIndex = 338;
            // 
            // kryptonLabel1
            // 
            this->kryptonLabel1->Location = System::Drawing::Point(382, 14);
            this->kryptonLabel1->Name = L"kryptonLabel1";
            this->kryptonLabel1->Size = System::Drawing::Size(328, 49);
            this->kryptonLabel1->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel1->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->kryptonLabel1->TabIndex = 1;
            this->kryptonLabel1->Values->Text = L"TimeTable Architect";
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->panel4->Controls->Add(this->username);
            this->panel4->Controls->Add(this->pictureBox8);
            this->panel4->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel4->Location = System::Drawing::Point(0, 0);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(364, 76);
            this->panel4->TabIndex = 0;
            // 
            // username
            // 
            this->username->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->username->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->username->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->username->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->username->Location = System::Drawing::Point(152, 28);
            this->username->Name = L"username";
            this->username->ReadOnly = true;
            this->username->Size = System::Drawing::Size(308, 32);
            this->username->TabIndex = 341;
            this->username->Text = L"UserName";
            // 
            // pictureBox8
            // 
            this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
            this->pictureBox8->Location = System::Drawing::Point(15, 8);
            this->pictureBox8->Name = L"pictureBox8";
            this->pictureBox8->Size = System::Drawing::Size(125, 64);
            this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox8->TabIndex = 340;
            this->pictureBox8->TabStop = false;
            // 
            // textBox7
            // 
            this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox7.BackgroundImage")));
            this->textBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox7->Location = System::Drawing::Point(278, 412);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(62, 22);
            this->textBox7->TabIndex = 322;
            // 
            // settingspanel
            // 
            this->settingspanel->AutoScroll = true;
            this->settingspanel->Controls->Add(this->panel36);
            this->settingspanel->Controls->Add(this->label112);
            this->settingspanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->settingspanel->Location = System::Drawing::Point(0, 0);
            this->settingspanel->Name = L"settingspanel";
            this->settingspanel->Size = System::Drawing::Size(1924, 1050);
            this->settingspanel->TabIndex = 286;
            // 
            // panel36
            // 
            this->panel36->Controls->Add(this->kryptonGroupBox5);
            this->panel36->Controls->Add(this->settingssave);
            this->panel36->Controls->Add(this->kryptonGroupBox3);
            this->panel36->Controls->Add(this->kryptonGroupBox4);
            this->panel36->Controls->Add(this->panel59);
            this->panel36->Controls->Add(this->kryptonLabel11);
            this->panel36->Controls->Add(this->kryptonGroupBox6);
            this->panel36->Location = System::Drawing::Point(179, 13);
            this->panel36->Name = L"panel36";
            this->panel36->Size = System::Drawing::Size(1194, 1678);
            this->panel36->TabIndex = 345;
            // 
            // kryptonGroupBox5
            // 
            this->kryptonGroupBox5->CaptionOverlap = 1;
            this->kryptonGroupBox5->CaptionVisible = false;
            this->kryptonGroupBox5->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox5->Location = System::Drawing::Point(23, 598);
            this->kryptonGroupBox5->Name = L"kryptonGroupBox5";
            // 
            // kryptonGroupBox5.Panel
            // 
            this->kryptonGroupBox5->Panel->Controls->Add(this->busyfactor);
            this->kryptonGroupBox5->Panel->Controls->Add(this->label45);
            this->kryptonGroupBox5->Size = System::Drawing::Size(1127, 194);
            this->kryptonGroupBox5->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox5->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox5->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox5->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox5->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox5->StateCommon->Border->Rounding = 9;
            this->kryptonGroupBox5->StateCommon->Border->Width = 1;
            this->kryptonGroupBox5->TabIndex = 349;
            // 
            // busyfactor
            // 
            this->busyfactor->DecimalPlaces = 1;
            this->busyfactor->Location = System::Drawing::Point(98, 85);
            this->busyfactor->Name = L"busyfactor";
            this->busyfactor->Size = System::Drawing::Size(328, 30);
            this->busyfactor->TabIndex = 265;
            this->busyfactor->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 65536 });
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->BackColor = System::Drawing::Color::White;
            this->label45->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label45->ForeColor = System::Drawing::Color::Black;
            this->label45->Location = System::Drawing::Point(93, 30);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(157, 28);
            this->label45->TabIndex = 264;
            this->label45->Text = L"ReductionFactor";
            // 
            // settingssave
            // 
            this->settingssave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->settingssave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->settingssave->Location = System::Drawing::Point(877, 1554);
            this->settingssave->Name = L"settingssave";
            this->settingssave->Size = System::Drawing::Size(154, 58);
            this->settingssave->TabIndex = 273;
            this->settingssave->Text = L"Save";
            this->settingssave->UseVisualStyleBackColor = false;
            this->settingssave->Click += gcnew System::EventHandler(this, &MyForm::settingssave_Click);
            // 
            // kryptonGroupBox3
            // 
            this->kryptonGroupBox3->CaptionOverlap = 1;
            this->kryptonGroupBox3->CaptionVisible = false;
            this->kryptonGroupBox3->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox3->Location = System::Drawing::Point(23, 168);
            this->kryptonGroupBox3->Name = L"kryptonGroupBox3";
            // 
            // kryptonGroupBox3.Panel
            // 
            this->kryptonGroupBox3->Panel->Controls->Add(this->filepath);
            this->kryptonGroupBox3->Panel->Controls->Add(this->label137);
            this->kryptonGroupBox3->Panel->Controls->Add(this->button16);
            this->kryptonGroupBox3->Size = System::Drawing::Size(1127, 194);
            this->kryptonGroupBox3->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox3->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox3->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox3->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox3->StateCommon->Border->Rounding = 10;
            this->kryptonGroupBox3->StateCommon->Border->Width = 1;
            this->kryptonGroupBox3->TabIndex = 347;
            // 
            // filepath
            // 
            this->filepath->Location = System::Drawing::Point(65, 94);
            this->filepath->Name = L"filepath";
            this->filepath->Size = System::Drawing::Size(449, 32);
            this->filepath->TabIndex = 265;
            this->filepath->Text = L"Path";
            // 
            // label137
            // 
            this->label137->AutoSize = true;
            this->label137->BackColor = System::Drawing::Color::White;
            this->label137->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label137->ForeColor = System::Drawing::Color::Black;
            this->label137->Location = System::Drawing::Point(47, 42);
            this->label137->Name = L"label137";
            this->label137->Size = System::Drawing::Size(650, 28);
            this->label137->TabIndex = 264;
            this->label137->Text = L"Select the FilePath where you want to store the TimeTables generated";
            // 
            // button16
            // 
            this->button16->Location = System::Drawing::Point(535, 94);
            this->button16->Name = L"button16";
            this->button16->Size = System::Drawing::Size(130, 33);
            this->button16->TabIndex = 302;
            this->button16->Text = L"Browse";
            this->button16->UseVisualStyleBackColor = true;
            this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
            // 
            // kryptonGroupBox4
            // 
            this->kryptonGroupBox4->CaptionOverlap = 1;
            this->kryptonGroupBox4->CaptionVisible = false;
            this->kryptonGroupBox4->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox4->Location = System::Drawing::Point(23, 844);
            this->kryptonGroupBox4->Name = L"kryptonGroupBox4";
            // 
            // kryptonGroupBox4.Panel
            // 
            this->kryptonGroupBox4->Panel->Controls->Add(this->panel56);
            this->kryptonGroupBox4->Panel->Controls->Add(this->panel57);
            this->kryptonGroupBox4->Panel->Controls->Add(this->settingstable);
            this->kryptonGroupBox4->Panel->Controls->Add(this->panel58);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label138);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label139);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label140);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label141);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label142);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label143);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label144);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label145);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label146);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label165);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label171);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label172);
            this->kryptonGroupBox4->Panel->Controls->Add(this->label173);
            this->kryptonGroupBox4->Size = System::Drawing::Size(1127, 642);
            this->kryptonGroupBox4->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox4->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox4->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox4->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox4->StateCommon->Border->Rounding = 7;
            this->kryptonGroupBox4->StateCommon->Border->Width = 1;
            this->kryptonGroupBox4->TabIndex = 346;
            // 
            // panel56
            // 
            this->panel56->BackColor = System::Drawing::Color::White;
            this->panel56->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel56.BackgroundImage")));
            this->panel56->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel56->Location = System::Drawing::Point(743, 159);
            this->panel56->Name = L"panel56";
            this->panel56->Size = System::Drawing::Size(44, 420);
            this->panel56->TabIndex = 1;
            // 
            // panel57
            // 
            this->panel57->BackColor = System::Drawing::Color::White;
            this->panel57->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel57.BackgroundImage")));
            this->panel57->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel57->Location = System::Drawing::Point(408, 159);
            this->panel57->Name = L"panel57";
            this->panel57->Size = System::Drawing::Size(44, 430);
            this->panel57->TabIndex = 300;
            // 
            // settingstable
            // 
            this->settingstable->BackColor = System::Drawing::Color::White;
            this->settingstable->ColumnCount = 8;
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->settingstable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->settingstable->Location = System::Drawing::Point(121, 159);
            this->settingstable->Name = L"settingstable";
            this->settingstable->RowCount = 6;
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->settingstable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->settingstable->Size = System::Drawing::Size(950, 431);
            this->settingstable->TabIndex = 260;
            // 
            // panel58
            // 
            this->panel58->BackColor = System::Drawing::Color::White;
            this->panel58->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel58.BackgroundImage")));
            this->panel58->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel58->Location = System::Drawing::Point(397, 159);
            this->panel58->Name = L"panel58";
            this->panel58->Size = System::Drawing::Size(82, 412);
            this->panel58->TabIndex = 2;
            // 
            // label138
            // 
            this->label138->AutoSize = true;
            this->label138->BackColor = System::Drawing::Color::White;
            this->label138->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label138->Location = System::Drawing::Point(21, 179);
            this->label138->Name = L"label138";
            this->label138->Size = System::Drawing::Size(85, 28);
            this->label138->TabIndex = 261;
            this->label138->Text = L"Monday";
            // 
            // label139
            // 
            this->label139->AutoSize = true;
            this->label139->BackColor = System::Drawing::Color::White;
            this->label139->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label139->Location = System::Drawing::Point(81, 42);
            this->label139->Name = L"label139";
            this->label139->Size = System::Drawing::Size(192, 28);
            this->label139->TabIndex = 344;
            this->label139->Text = L"TimeTable Structure";
            // 
            // label140
            // 
            this->label140->AutoSize = true;
            this->label140->BackColor = System::Drawing::Color::White;
            this->label140->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label140->Location = System::Drawing::Point(27, 248);
            this->label140->Name = L"label140";
            this->label140->Size = System::Drawing::Size(83, 28);
            this->label140->TabIndex = 262;
            this->label140->Text = L"Tuesday";
            // 
            // label141
            // 
            this->label141->AutoSize = true;
            this->label141->BackColor = System::Drawing::Color::White;
            this->label141->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label141->Location = System::Drawing::Point(139, 119);
            this->label141->Name = L"label141";
            this->label141->Size = System::Drawing::Size(105, 28);
            this->label141->TabIndex = 294;
            this->label141->Text = L"9:00-10:00";
            // 
            // label142
            // 
            this->label142->AutoSize = true;
            this->label142->BackColor = System::Drawing::Color::White;
            this->label142->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label142->Location = System::Drawing::Point(11, 325);
            this->label142->Name = L"label142";
            this->label142->Size = System::Drawing::Size(113, 28);
            this->label142->TabIndex = 263;
            this->label142->Text = L"Wednesday";
            // 
            // label143
            // 
            this->label143->AutoSize = true;
            this->label143->BackColor = System::Drawing::Color::White;
            this->label143->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label143->Location = System::Drawing::Point(275, 119);
            this->label143->Name = L"label143";
            this->label143->Size = System::Drawing::Size(116, 28);
            this->label143->TabIndex = 295;
            this->label143->Text = L"10:00-11:00";
            // 
            // label144
            // 
            this->label144->AutoSize = true;
            this->label144->BackColor = System::Drawing::Color::White;
            this->label144->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label144->Location = System::Drawing::Point(11, 389);
            this->label144->Name = L"label144";
            this->label144->Size = System::Drawing::Size(91, 28);
            this->label144->TabIndex = 264;
            this->label144->Text = L"Thursday";
            // 
            // label145
            // 
            this->label145->AutoSize = true;
            this->label145->BackColor = System::Drawing::Color::White;
            this->label145->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label145->Location = System::Drawing::Point(461, 119);
            this->label145->Name = L"label145";
            this->label145->Size = System::Drawing::Size(116, 28);
            this->label145->TabIndex = 296;
            this->label145->Text = L"11:30-12:30";
            // 
            // label146
            // 
            this->label146->AutoSize = true;
            this->label146->BackColor = System::Drawing::Color::White;
            this->label146->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label146->Location = System::Drawing::Point(25, 465);
            this->label146->Name = L"label146";
            this->label146->Size = System::Drawing::Size(66, 28);
            this->label146->TabIndex = 265;
            this->label146->Text = L"Friday";
            // 
            // label165
            // 
            this->label165->AutoSize = true;
            this->label165->BackColor = System::Drawing::Color::White;
            this->label165->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label165->Location = System::Drawing::Point(615, 119);
            this->label165->Name = L"label165";
            this->label165->Size = System::Drawing::Size(105, 28);
            this->label165->TabIndex = 297;
            this->label165->Text = L"12:30-1:30";
            // 
            // label171
            // 
            this->label171->AutoSize = true;
            this->label171->BackColor = System::Drawing::Color::White;
            this->label171->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label171->Location = System::Drawing::Point(25, 542);
            this->label171->Name = L"label171";
            this->label171->Size = System::Drawing::Size(90, 28);
            this->label171->TabIndex = 266;
            this->label171->Text = L"Saturday";
            // 
            // label172
            // 
            this->label172->AutoSize = true;
            this->label172->BackColor = System::Drawing::Color::White;
            this->label172->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label172->Location = System::Drawing::Point(809, 115);
            this->label172->Name = L"label172";
            this->label172->Size = System::Drawing::Size(94, 28);
            this->label172->TabIndex = 298;
            this->label172->Text = L"2:30-3:30";
            // 
            // label173
            // 
            this->label173->AutoSize = true;
            this->label173->BackColor = System::Drawing::Color::White;
            this->label173->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label173->Location = System::Drawing::Point(939, 115);
            this->label173->Name = L"label173";
            this->label173->Size = System::Drawing::Size(94, 28);
            this->label173->TabIndex = 299;
            this->label173->Text = L"3:30-4:30";
            // 
            // panel59
            // 
            this->panel59->Controls->Add(this->button28);
            this->panel59->Controls->Add(this->button29);
            this->panel59->Location = System::Drawing::Point(709, 2211);
            this->panel59->Name = L"panel59";
            this->panel59->Size = System::Drawing::Size(502, 137);
            this->panel59->TabIndex = 295;
            // 
            // button28
            // 
            this->button28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button28->Location = System::Drawing::Point(303, 38);
            this->button28->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button28->Name = L"button28";
            this->button28->Size = System::Drawing::Size(154, 58);
            this->button28->TabIndex = 180;
            this->button28->Text = L"Delete";
            this->button28->UseVisualStyleBackColor = false;
            // 
            // button29
            // 
            this->button29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button29->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button29->Location = System::Drawing::Point(49, 38);
            this->button29->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button29->Name = L"button29";
            this->button29->Size = System::Drawing::Size(154, 58);
            this->button29->TabIndex = 124;
            this->button29->Text = L"Save";
            this->button29->UseVisualStyleBackColor = false;
            // 
            // kryptonLabel11
            // 
            this->kryptonLabel11->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel11->Name = L"kryptonLabel11";
            this->kryptonLabel11->Size = System::Drawing::Size(126, 43);
            this->kryptonLabel11->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel11->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel11->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel11->TabIndex = 2;
            this->kryptonLabel11->Values->Text = L"Settings";
            // 
            // kryptonGroupBox6
            // 
            this->kryptonGroupBox6->CaptionOverlap = 1;
            this->kryptonGroupBox6->CaptionVisible = false;
            this->kryptonGroupBox6->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox6->Location = System::Drawing::Point(23, 391);
            this->kryptonGroupBox6->Name = L"kryptonGroupBox6";
            // 
            // kryptonGroupBox6.Panel
            // 
            this->kryptonGroupBox6->Panel->Controls->Add(this->freefactor);
            this->kryptonGroupBox6->Panel->Controls->Add(this->label175);
            this->kryptonGroupBox6->Size = System::Drawing::Size(1127, 194);
            this->kryptonGroupBox6->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox6->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox6->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox6->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox6->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox6->StateCommon->Border->Rounding = 9;
            this->kryptonGroupBox6->StateCommon->Border->Width = 1;
            this->kryptonGroupBox6->TabIndex = 337;
            // 
            // freefactor
            // 
            this->freefactor->DecimalPlaces = 1;
            this->freefactor->Location = System::Drawing::Point(98, 85);
            this->freefactor->Name = L"freefactor";
            this->freefactor->Size = System::Drawing::Size(328, 30);
            this->freefactor->TabIndex = 265;
            this->freefactor->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 65536 });
            // 
            // label175
            // 
            this->label175->AutoSize = true;
            this->label175->BackColor = System::Drawing::Color::White;
            this->label175->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label175->ForeColor = System::Drawing::Color::Black;
            this->label175->Location = System::Drawing::Point(93, 30);
            this->label175->Name = L"label175";
            this->label175->Size = System::Drawing::Size(105, 28);
            this->label175->TabIndex = 264;
            this->label175->Text = L"FreeFactor";
            // 
            // label112
            // 
            this->label112->AutoSize = true;
            this->label112->Location = System::Drawing::Point(688, 656);
            this->label112->Name = L"label112";
            this->label112->Size = System::Drawing::Size(152, 20);
            this->label112->TabIndex = 4;
            this->label112->Text = L"TimeTable Structure";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button1->FlatAppearance->BorderSize = 0;
            this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button1->Location = System::Drawing::Point(0, 195);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(362, 44);
            this->button1->TabIndex = 2;
            this->button1->Text = L"        Departments";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button6
            // 
            this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button6->FlatAppearance->BorderSize = 0;
            this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button6->Location = System::Drawing::Point(0, 300);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(365, 44);
            this->button6->TabIndex = 12;
            this->button6->Text = L"   Classrooms";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
            // 
            // button9
            // 
            this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button9->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button9->FlatAppearance->BorderSize = 0;
            this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button9->Location = System::Drawing::Point(0, 406);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(368, 44);
            this->button9->TabIndex = 12;
            this->button9->Text = L"Teachers";
            this->button9->UseVisualStyleBackColor = false;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button5->FlatAppearance->BorderSize = 0;
            this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button5->ForeColor = System::Drawing::Color::White;
            this->button5->Location = System::Drawing::Point(3, 344);
            this->button5->Margin = System::Windows::Forms::Padding(0);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(359, 34);
            this->button5->TabIndex = 13;
            this->button5->Text = L"      Add";
            this->button5->UseVisualStyleBackColor = false;
            this->button5->Visible = false;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button8->FlatAppearance->BorderSize = 0;
            this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button8->ForeColor = System::Drawing::Color::White;
            this->button8->Location = System::Drawing::Point(3, 450);
            this->button8->Margin = System::Windows::Forms::Padding(0);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(362, 34);
            this->button8->TabIndex = 13;
            this->button8->Text = L"     Add\r\n";
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Visible = false;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button4->FlatAppearance->BorderSize = 0;
            this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button4->ForeColor = System::Drawing::Color::White;
            this->button4->Location = System::Drawing::Point(3, 374);
            this->button4->Margin = System::Windows::Forms::Padding(0);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(362, 34);
            this->button4->TabIndex = 14;
            this->button4->Text = L"      Edit\r\n";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Visible = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button7->FlatAppearance->BorderSize = 0;
            this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button7->ForeColor = System::Drawing::Color::White;
            this->button7->Location = System::Drawing::Point(0, 474);
            this->button7->Margin = System::Windows::Forms::Padding(0);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(365, 34);
            this->button7->TabIndex = 14;
            this->button7->Text = L"       Edit";
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Visible = false;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click_1);
            // 
            // button12
            // 
            this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button12->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button12->FlatAppearance->BorderSize = 0;
            this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button12->Location = System::Drawing::Point(0, 512);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(368, 44);
            this->button12->TabIndex = 17;
            this->button12->Text = L"Subjects";
            this->button12->UseVisualStyleBackColor = false;
            this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
            // 
            // button11
            // 
            this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button11->FlatAppearance->BorderSize = 0;
            this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button11->ForeColor = System::Drawing::Color::White;
            this->button11->Location = System::Drawing::Point(0, 558);
            this->button11->Margin = System::Windows::Forms::Padding(0);
            this->button11->Name = L"button11";
            this->button11->Size = System::Drawing::Size(366, 34);
            this->button11->TabIndex = 18;
            this->button11->Text = L"     Add";
            this->button11->UseVisualStyleBackColor = false;
            this->button11->Visible = false;
            this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
            // 
            // button10
            // 
            this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button10->FlatAppearance->BorderSize = 0;
            this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button10->ForeColor = System::Drawing::Color::White;
            this->button10->Location = System::Drawing::Point(0, 588);
            this->button10->Margin = System::Windows::Forms::Padding(0);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(365, 34);
            this->button10->TabIndex = 19;
            this->button10->Text = L"      Edit";
            this->button10->UseVisualStyleBackColor = false;
            this->button10->Visible = false;
            this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click_1);
            // 
            // button15
            // 
            this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button15->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button15->FlatAppearance->BorderSize = 0;
            this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button15->Location = System::Drawing::Point(3, 620);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(360, 44);
            this->button15->TabIndex = 22;
            this->button15->Text = L"Classes";
            this->button15->UseVisualStyleBackColor = false;
            this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
            // 
            // button14
            // 
            this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button14->FlatAppearance->BorderSize = 0;
            this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button14->ForeColor = System::Drawing::Color::White;
            this->button14->Location = System::Drawing::Point(0, 663);
            this->button14->Margin = System::Windows::Forms::Padding(0);
            this->button14->Name = L"button14";
            this->button14->Size = System::Drawing::Size(362, 34);
            this->button14->TabIndex = 23;
            this->button14->Text = L"     Add";
            this->button14->UseVisualStyleBackColor = false;
            this->button14->Visible = false;
            this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
            // 
            // button13
            // 
            this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button13->FlatAppearance->BorderSize = 0;
            this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button13->ForeColor = System::Drawing::Color::White;
            this->button13->Location = System::Drawing::Point(0, 694);
            this->button13->Margin = System::Windows::Forms::Padding(0);
            this->button13->Name = L"button13";
            this->button13->Size = System::Drawing::Size(360, 34);
            this->button13->TabIndex = 24;
            this->button13->Text = L"        Delete";
            this->button13->UseVisualStyleBackColor = false;
            this->button13->Visible = false;
            this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(60, 86);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(40, 44);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 6;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(60, 195);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(40, 44);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(60, 300);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(40, 44);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(60, 406);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(40, 44);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(60, 511);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(40, 44);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(60, 620);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(40, 44);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox7->TabIndex = 31;
            this->pictureBox7->TabStop = false;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->panel1->Controls->Add(this->panel3);
            this->panel1->Controls->Add(this->pictureBox12);
            this->panel1->Controls->Add(this->button18);
            this->panel1->Controls->Add(this->pictureBox11);
            this->panel1->Controls->Add(this->button17);
            this->panel1->Controls->Add(this->textBox7);
            this->panel1->Controls->Add(this->textBox5);
            this->panel1->Controls->Add(this->textBox9);
            this->panel1->Controls->Add(this->textBox11);
            this->panel1->Controls->Add(this->textBox4);
            this->panel1->Controls->Add(this->textBox10);
            this->panel1->Controls->Add(this->pictureBox7);
            this->panel1->Controls->Add(this->textBox8);
            this->panel1->Controls->Add(this->pictureBox6);
            this->panel1->Controls->Add(this->pictureBox5);
            this->panel1->Controls->Add(this->pictureBox4);
            this->panel1->Controls->Add(this->pictureBox3);
            this->panel1->Controls->Add(this->pictureBox2);
            this->panel1->Controls->Add(this->Homebutton1);
            this->panel1->Controls->Add(this->button13);
            this->panel1->Controls->Add(this->button14);
            this->panel1->Controls->Add(this->button15);
            this->panel1->Controls->Add(this->button10);
            this->panel1->Controls->Add(this->button11);
            this->panel1->Controls->Add(this->textBox6);
            this->panel1->Controls->Add(this->button12);
            this->panel1->Controls->Add(this->button7);
            this->panel1->Controls->Add(this->button4);
            this->panel1->Controls->Add(this->button8);
            this->panel1->Controls->Add(this->button5);
            this->panel1->Controls->Add(this->button9);
            this->panel1->Controls->Add(this->button6);
            this->panel1->Controls->Add(this->button1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel1->Location = System::Drawing::Point(0, 76);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(364, 974);
            this->panel1->TabIndex = 259;
            // 
            // panel3
            // 
            this->panel3->Location = System::Drawing::Point(26, 86);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(8, 44);
            this->panel3->TabIndex = 341;
            this->panel3->Text = L"button19";
            this->panel3->UseVisualStyleBackColor = true;
            // 
            // pictureBox12
            // 
            this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
            this->pictureBox12->Location = System::Drawing::Point(60, 740);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(40, 44);
            this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox12->TabIndex = 328;
            this->pictureBox12->TabStop = false;
            // 
            // button18
            // 
            this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button18->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button18->FlatAppearance->BorderSize = 0;
            this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button18->Location = System::Drawing::Point(3, 740);
            this->button18->Name = L"button18";
            this->button18->Size = System::Drawing::Size(364, 44);
            this->button18->TabIndex = 327;
            this->button18->Text = L"   Contact Us";
            this->button18->UseVisualStyleBackColor = false;
            // 
            // pictureBox11
            // 
            this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
            this->pictureBox11->Location = System::Drawing::Point(60, 808);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(40, 44);
            this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox11->TabIndex = 4;
            this->pictureBox11->TabStop = false;
            this->pictureBox11->Click += gcnew System::EventHandler(this, &MyForm::pictureBox11_Click);
            this->pictureBox11->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox11_MouseEnter);
            this->pictureBox11->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox11_MouseLeave);
            // 
            // button17
            // 
            this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button17->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->button17->FlatAppearance->BorderSize = 0;
            this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button17->Location = System::Drawing::Point(3, 808);
            this->button17->Name = L"button17";
            this->button17->Size = System::Drawing::Size(359, 44);
            this->button17->TabIndex = 325;
            this->button17->Text = L"Settings";
            this->button17->UseVisualStyleBackColor = false;
            // 
            // textBox5
            // 
            this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox5.BackgroundImage")));
            this->textBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox5->Location = System::Drawing::Point(282, 306);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(62, 22);
            this->textBox5->TabIndex = 321;
            // 
            // textBox9
            // 
            this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox9.BackgroundImage")));
            this->textBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox9->Location = System::Drawing::Point(270, 520);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(62, 22);
            this->textBox9->TabIndex = 323;
            // 
            // textBox11
            // 
            this->textBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox11.BackgroundImage")));
            this->textBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox11->Location = System::Drawing::Point(276, 627);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(62, 22);
            this->textBox11->TabIndex = 323;
            // 
            // textBox4
            // 
            this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox4.BackgroundImage")));
            this->textBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox4->Location = System::Drawing::Point(285, 308);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(62, 22);
            this->textBox4->TabIndex = 324;
            // 
            // textBox10
            // 
            this->textBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox10.BackgroundImage")));
            this->textBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox10->Location = System::Drawing::Point(278, 627);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(62, 22);
            this->textBox10->TabIndex = 323;
            // 
            // textBox8
            // 
            this->textBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox8.BackgroundImage")));
            this->textBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox8->Location = System::Drawing::Point(274, 520);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(62, 22);
            this->textBox8->TabIndex = 324;
            // 
            // Homebutton1
            // 
            this->Homebutton1->BackColor = System::Drawing::Color::Transparent;
            this->Homebutton1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->Homebutton1->FlatAppearance->BorderSize = 0;
            this->Homebutton1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->Homebutton1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->Homebutton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Homebutton1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Homebutton1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->Homebutton1->Location = System::Drawing::Point(3, 86);
            this->Homebutton1->Name = L"Homebutton1";
            this->Homebutton1->Size = System::Drawing::Size(359, 44);
            this->Homebutton1->TabIndex = 26;
            this->Homebutton1->Text = L"    Home";
            this->Homebutton1->UseVisualStyleBackColor = false;
            this->Homebutton1->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            // 
            // textBox6
            // 
            this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox6.BackgroundImage")));
            this->textBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->textBox6->Location = System::Drawing::Point(280, 412);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(62, 22);
            this->textBox6->TabIndex = 324;
            // 
            // classgenerate
            // 
            this->classgenerate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classgenerate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classgenerate->Location = System::Drawing::Point(290, 12);
            this->classgenerate->Name = L"classgenerate";
            this->classgenerate->Size = System::Drawing::Size(154, 58);
            this->classgenerate->TabIndex = 248;
            this->classgenerate->Text = L"Generate";
            this->classgenerate->UseVisualStyleBackColor = false;
            this->classgenerate->Click += gcnew System::EventHandler(this, &MyForm::classgenerate_Click);
            // 
            // classsave
            // 
            this->classsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classsave->Location = System::Drawing::Point(511, 9);
            this->classsave->Name = L"classsave";
            this->classsave->Size = System::Drawing::Size(154, 58);
            this->classsave->TabIndex = 247;
            this->classsave->Text = L"Save";
            this->classsave->UseVisualStyleBackColor = false;
            this->classsave->Click += gcnew System::EventHandler(this, &MyForm::classsave_Click);
            // 
            // classclear
            // 
            this->classclear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classclear->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classclear->Location = System::Drawing::Point(736, 9);
            this->classclear->Name = L"classclear";
            this->classclear->Size = System::Drawing::Size(154, 58);
            this->classclear->TabIndex = 246;
            this->classclear->Text = L"Clear";
            this->classclear->UseVisualStyleBackColor = false;
            this->classclear->Click += gcnew System::EventHandler(this, &MyForm::classclear_Click);
            // 
            // classreserve
            // 
            this->classreserve->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classreserve->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classreserve->Location = System::Drawing::Point(48, 10);
            this->classreserve->Name = L"classreserve";
            this->classreserve->Size = System::Drawing::Size(154, 58);
            this->classreserve->TabIndex = 260;
            this->classreserve->Text = L"Reserve";
            this->classreserve->UseVisualStyleBackColor = false;
            this->classreserve->Click += gcnew System::EventHandler(this, &MyForm::classreserve_Click_1);
            // 
            // classpanel
            // 
            this->classpanel->AutoScroll = true;
            this->classpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classpanel->Controls->Add(this->panel29);
            this->classpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->classpanel->Location = System::Drawing::Point(364, 76);
            this->classpanel->Name = L"classpanel";
            this->classpanel->Size = System::Drawing::Size(1560, 974);
            this->classpanel->TabIndex = 230;
            this->classpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint_1);
            // 
            // panel29
            // 
            this->panel29->Controls->Add(this->panel27);
            this->panel29->Controls->Add(this->classgengroup);
            this->panel29->Controls->Add(this->classroomgroup);
            this->panel29->Controls->Add(this->label158);
            this->panel29->Controls->Add(this->classresgroup);
            this->panel29->Controls->Add(this->classlabgroup);
            this->panel29->Controls->Add(this->classelegroup);
            this->panel29->Controls->Add(this->classcoregroup);
            this->panel29->Controls->Add(this->classbatchgroup);
            this->panel29->Controls->Add(this->classbranchgroup);
            this->panel29->Controls->Add(this->kryptonLabel10);
            this->panel29->Controls->Add(this->classnamegroup);
            this->panel29->Location = System::Drawing::Point(179, 13);
            this->panel29->Name = L"panel29";
            this->panel29->Size = System::Drawing::Size(1194, 3989);
            this->panel29->TabIndex = 346;
            this->panel29->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel29_Paint);
            // 
            // panel27
            // 
            this->panel27->Controls->Add(this->classgenerate);
            this->panel27->Controls->Add(this->classclear);
            this->panel27->Controls->Add(this->classsave);
            this->panel27->Controls->Add(this->classreserve);
            this->panel27->Location = System::Drawing::Point(233, 3194);
            this->panel27->Name = L"panel27";
            this->panel27->Size = System::Drawing::Size(917, 79);
            this->panel27->TabIndex = 350;
            // 
            // classgengroup
            // 
            this->classgengroup->CaptionOverlap = 1;
            this->classgengroup->CaptionVisible = false;
            this->classgengroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classgengroup->Location = System::Drawing::Point(27, 3985);
            this->classgengroup->Name = L"classgengroup";
            // 
            // classgengroup.Panel
            // 
            this->classgengroup->Panel->Controls->Add(this->panel8);
            this->classgengroup->Panel->Controls->Add(this->panel25);
            this->classgengroup->Panel->Controls->Add(this->classtablegen1);
            this->classgengroup->Panel->Controls->Add(this->panel26);
            this->classgengroup->Panel->Controls->Add(this->label34);
            this->classgengroup->Panel->Controls->Add(this->label52);
            this->classgengroup->Panel->Controls->Add(this->label53);
            this->classgengroup->Panel->Controls->Add(this->label54);
            this->classgengroup->Panel->Controls->Add(this->label55);
            this->classgengroup->Panel->Controls->Add(this->label56);
            this->classgengroup->Panel->Controls->Add(this->label57);
            this->classgengroup->Panel->Controls->Add(this->label58);
            this->classgengroup->Panel->Controls->Add(this->label59);
            this->classgengroup->Panel->Controls->Add(this->label60);
            this->classgengroup->Panel->Controls->Add(this->label61);
            this->classgengroup->Panel->Controls->Add(this->label65);
            this->classgengroup->Panel->Controls->Add(this->label135);
            this->classgengroup->Size = System::Drawing::Size(1127, 642);
            this->classgengroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classgengroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classgengroup->StateCommon->Border->ColorAngle = 50;
            this->classgengroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classgengroup->StateCommon->Border->Rounding = 7;
            this->classgengroup->StateCommon->Border->Width = 1;
            this->classgengroup->TabIndex = 349;
            this->classgengroup->Enter += gcnew System::EventHandler(this, &MyForm::classgengroup_Enter);
            // 
            // panel8
            // 
            this->panel8->BackColor = System::Drawing::Color::White;
            this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
            this->panel8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel8->Location = System::Drawing::Point(743, 159);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(44, 420);
            this->panel8->TabIndex = 1;
            // 
            // panel25
            // 
            this->panel25->BackColor = System::Drawing::Color::White;
            this->panel25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel25.BackgroundImage")));
            this->panel25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel25->Location = System::Drawing::Point(408, 159);
            this->panel25->Name = L"panel25";
            this->panel25->Size = System::Drawing::Size(44, 430);
            this->panel25->TabIndex = 300;
            // 
            // classtablegen1
            // 
            this->classtablegen1->BackColor = System::Drawing::Color::White;
            this->classtablegen1->ColumnCount = 8;
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->classtablegen1->Location = System::Drawing::Point(121, 159);
            this->classtablegen1->Name = L"classtablegen1";
            this->classtablegen1->RowCount = 6;
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->Size = System::Drawing::Size(950, 431);
            this->classtablegen1->TabIndex = 260;
            // 
            // panel26
            // 
            this->panel26->BackColor = System::Drawing::Color::White;
            this->panel26->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel26.BackgroundImage")));
            this->panel26->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel26->Location = System::Drawing::Point(397, 159);
            this->panel26->Name = L"panel26";
            this->panel26->Size = System::Drawing::Size(82, 412);
            this->panel26->TabIndex = 2;
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->BackColor = System::Drawing::Color::White;
            this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label34->Location = System::Drawing::Point(21, 179);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(85, 28);
            this->label34->TabIndex = 261;
            this->label34->Text = L"Monday";
            // 
            // label52
            // 
            this->label52->AutoSize = true;
            this->label52->BackColor = System::Drawing::Color::White;
            this->label52->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label52->Location = System::Drawing::Point(81, 42);
            this->label52->Name = L"label52";
            this->label52->Size = System::Drawing::Size(205, 28);
            this->label52->TabIndex = 344;
            this->label52->Text = L"Generated TimeTable";
            // 
            // label53
            // 
            this->label53->AutoSize = true;
            this->label53->BackColor = System::Drawing::Color::White;
            this->label53->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label53->Location = System::Drawing::Point(27, 248);
            this->label53->Name = L"label53";
            this->label53->Size = System::Drawing::Size(83, 28);
            this->label53->TabIndex = 262;
            this->label53->Text = L"Tuesday";
            // 
            // label54
            // 
            this->label54->AutoSize = true;
            this->label54->BackColor = System::Drawing::Color::White;
            this->label54->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label54->Location = System::Drawing::Point(139, 119);
            this->label54->Name = L"label54";
            this->label54->Size = System::Drawing::Size(105, 28);
            this->label54->TabIndex = 294;
            this->label54->Text = L"9:00-10:00";
            // 
            // label55
            // 
            this->label55->AutoSize = true;
            this->label55->BackColor = System::Drawing::Color::White;
            this->label55->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label55->Location = System::Drawing::Point(11, 325);
            this->label55->Name = L"label55";
            this->label55->Size = System::Drawing::Size(113, 28);
            this->label55->TabIndex = 263;
            this->label55->Text = L"Wednesday";
            // 
            // label56
            // 
            this->label56->AutoSize = true;
            this->label56->BackColor = System::Drawing::Color::White;
            this->label56->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label56->Location = System::Drawing::Point(275, 119);
            this->label56->Name = L"label56";
            this->label56->Size = System::Drawing::Size(116, 28);
            this->label56->TabIndex = 295;
            this->label56->Text = L"10:00-11:00";
            // 
            // label57
            // 
            this->label57->AutoSize = true;
            this->label57->BackColor = System::Drawing::Color::White;
            this->label57->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label57->Location = System::Drawing::Point(11, 389);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(91, 28);
            this->label57->TabIndex = 264;
            this->label57->Text = L"Thursday";
            // 
            // label58
            // 
            this->label58->AutoSize = true;
            this->label58->BackColor = System::Drawing::Color::White;
            this->label58->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label58->Location = System::Drawing::Point(461, 119);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(116, 28);
            this->label58->TabIndex = 296;
            this->label58->Text = L"11:30-12:30";
            // 
            // label59
            // 
            this->label59->AutoSize = true;
            this->label59->BackColor = System::Drawing::Color::White;
            this->label59->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label59->Location = System::Drawing::Point(25, 465);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(66, 28);
            this->label59->TabIndex = 265;
            this->label59->Text = L"Friday";
            // 
            // label60
            // 
            this->label60->AutoSize = true;
            this->label60->BackColor = System::Drawing::Color::White;
            this->label60->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label60->Location = System::Drawing::Point(615, 119);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(105, 28);
            this->label60->TabIndex = 297;
            this->label60->Text = L"12:30-1:30";
            // 
            // label61
            // 
            this->label61->AutoSize = true;
            this->label61->BackColor = System::Drawing::Color::White;
            this->label61->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label61->Location = System::Drawing::Point(25, 542);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(90, 28);
            this->label61->TabIndex = 266;
            this->label61->Text = L"Saturday";
            // 
            // label65
            // 
            this->label65->AutoSize = true;
            this->label65->BackColor = System::Drawing::Color::White;
            this->label65->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label65->Location = System::Drawing::Point(809, 115);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(94, 28);
            this->label65->TabIndex = 298;
            this->label65->Text = L"2:30-3:30";
            // 
            // label135
            // 
            this->label135->AutoSize = true;
            this->label135->BackColor = System::Drawing::Color::White;
            this->label135->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label135->Location = System::Drawing::Point(939, 115);
            this->label135->Name = L"label135";
            this->label135->Size = System::Drawing::Size(94, 28);
            this->label135->TabIndex = 299;
            this->label135->Text = L"3:30-4:30";
            // 
            // classroomgroup
            // 
            this->classroomgroup->CaptionOverlap = 1;
            this->classroomgroup->CaptionVisible = false;
            this->classroomgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classroomgroup->Location = System::Drawing::Point(21, 2822);
            this->classroomgroup->Name = L"classroomgroup";
            // 
            // classroomgroup.Panel
            // 
            this->classroomgroup->Panel->Controls->Add(this->label35);
            this->classroomgroup->Panel->Controls->Add(this->classdefaultrooms);
            this->classroomgroup->Size = System::Drawing::Size(1127, 357);
            this->classroomgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classroomgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classroomgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->classroomgroup->StateCommon->Border->ColorAngle = 50;
            this->classroomgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classroomgroup->StateCommon->Border->Rounding = 7;
            this->classroomgroup->StateCommon->Border->Width = 1;
            this->classroomgroup->TabIndex = 349;
            this->classroomgroup->Enter += gcnew System::EventHandler(this, &MyForm::classroomgroup_Enter);
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->BackColor = System::Drawing::Color::White;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label35->ForeColor = System::Drawing::Color::Black;
            this->label35->Location = System::Drawing::Point(143, 43);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(250, 28);
            this->label35->TabIndex = 344;
            this->label35->Text = L"Default Rooms to be used";
            // 
            // classdefaultrooms
            // 
            this->classdefaultrooms->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::InputControlRibbon;
            this->classdefaultrooms->BorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ContextMenuItemSplit;
            this->classdefaultrooms->CheckOnClick = true;
            this->classdefaultrooms->Location = System::Drawing::Point(162, 110);
            this->classdefaultrooms->Name = L"classdefaultrooms";
            this->classdefaultrooms->Size = System::Drawing::Size(348, 182);
            this->classdefaultrooms->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->classdefaultrooms->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classdefaultrooms->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classdefaultrooms->StateCommon->Border->Rounding = 5;
            this->classdefaultrooms->StateCommon->Border->Width = 1;
            this->classdefaultrooms->TabIndex = 343;
            // 
            // label158
            // 
            this->label158->AutoSize = true;
            this->label158->BackColor = System::Drawing::Color::White;
            this->label158->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label158->Location = System::Drawing::Point(108, 4000);
            this->label158->Name = L"label158";
            this->label158->Size = System::Drawing::Size(838, 28);
            this->label158->TabIndex = 344;
            this->label158->Text = L"Select the slots to be reserved and then click on generate to view the generated "
                L"timetable";
            // 
            // classresgroup
            // 
            this->classresgroup->CaptionOverlap = 1;
            this->classresgroup->CaptionVisible = false;
            this->classresgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classresgroup->Location = System::Drawing::Point(23, 3302);
            this->classresgroup->Name = L"classresgroup";
            // 
            // classresgroup.Panel
            // 
            this->classresgroup->Panel->Controls->Add(this->panel50);
            this->classresgroup->Panel->Controls->Add(this->panel53);
            this->classresgroup->Panel->Controls->Add(this->classtablegen);
            this->classresgroup->Panel->Controls->Add(this->panel54);
            this->classresgroup->Panel->Controls->Add(this->label98);
            this->classresgroup->Panel->Controls->Add(this->label159);
            this->classresgroup->Panel->Controls->Add(this->label160);
            this->classresgroup->Panel->Controls->Add(this->label161);
            this->classresgroup->Panel->Controls->Add(this->label162);
            this->classresgroup->Panel->Controls->Add(this->label163);
            this->classresgroup->Panel->Controls->Add(this->label164);
            this->classresgroup->Panel->Controls->Add(this->label166);
            this->classresgroup->Panel->Controls->Add(this->label167);
            this->classresgroup->Panel->Controls->Add(this->label168);
            this->classresgroup->Panel->Controls->Add(this->label169);
            this->classresgroup->Panel->Controls->Add(this->label170);
            this->classresgroup->Size = System::Drawing::Size(1127, 642);
            this->classresgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classresgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classresgroup->StateCommon->Border->ColorAngle = 50;
            this->classresgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classresgroup->StateCommon->Border->Rounding = 7;
            this->classresgroup->StateCommon->Border->Width = 1;
            this->classresgroup->TabIndex = 348;
            this->classresgroup->Enter += gcnew System::EventHandler(this, &MyForm::classresgroup_Enter);
            // 
            // panel50
            // 
            this->panel50->BackColor = System::Drawing::Color::White;
            this->panel50->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel50.BackgroundImage")));
            this->panel50->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel50->Location = System::Drawing::Point(743, 159);
            this->panel50->Name = L"panel50";
            this->panel50->Size = System::Drawing::Size(44, 420);
            this->panel50->TabIndex = 1;
            // 
            // panel53
            // 
            this->panel53->BackColor = System::Drawing::Color::White;
            this->panel53->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel53.BackgroundImage")));
            this->panel53->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel53->Location = System::Drawing::Point(408, 159);
            this->panel53->Name = L"panel53";
            this->panel53->Size = System::Drawing::Size(44, 430);
            this->panel53->TabIndex = 300;
            // 
            // classtablegen
            // 
            this->classtablegen->BackColor = System::Drawing::Color::White;
            this->classtablegen->ColumnCount = 8;
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->classtablegen->Location = System::Drawing::Point(121, 159);
            this->classtablegen->Name = L"classtablegen";
            this->classtablegen->RowCount = 6;
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen->Size = System::Drawing::Size(950, 431);
            this->classtablegen->TabIndex = 260;
            // 
            // panel54
            // 
            this->panel54->BackColor = System::Drawing::Color::White;
            this->panel54->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel54.BackgroundImage")));
            this->panel54->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel54->Location = System::Drawing::Point(397, 159);
            this->panel54->Name = L"panel54";
            this->panel54->Size = System::Drawing::Size(82, 412);
            this->panel54->TabIndex = 2;
            // 
            // label98
            // 
            this->label98->AutoSize = true;
            this->label98->BackColor = System::Drawing::Color::White;
            this->label98->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label98->Location = System::Drawing::Point(21, 179);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(85, 28);
            this->label98->TabIndex = 261;
            this->label98->Text = L"Monday";
            // 
            // label159
            // 
            this->label159->AutoSize = true;
            this->label159->BackColor = System::Drawing::Color::White;
            this->label159->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label159->Location = System::Drawing::Point(27, 248);
            this->label159->Name = L"label159";
            this->label159->Size = System::Drawing::Size(83, 28);
            this->label159->TabIndex = 262;
            this->label159->Text = L"Tuesday";
            // 
            // label160
            // 
            this->label160->AutoSize = true;
            this->label160->BackColor = System::Drawing::Color::White;
            this->label160->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label160->Location = System::Drawing::Point(139, 119);
            this->label160->Name = L"label160";
            this->label160->Size = System::Drawing::Size(105, 28);
            this->label160->TabIndex = 294;
            this->label160->Text = L"9:00-10:00";
            // 
            // label161
            // 
            this->label161->AutoSize = true;
            this->label161->BackColor = System::Drawing::Color::White;
            this->label161->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label161->Location = System::Drawing::Point(11, 325);
            this->label161->Name = L"label161";
            this->label161->Size = System::Drawing::Size(113, 28);
            this->label161->TabIndex = 263;
            this->label161->Text = L"Wednesday";
            // 
            // label162
            // 
            this->label162->AutoSize = true;
            this->label162->BackColor = System::Drawing::Color::White;
            this->label162->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label162->Location = System::Drawing::Point(275, 119);
            this->label162->Name = L"label162";
            this->label162->Size = System::Drawing::Size(116, 28);
            this->label162->TabIndex = 295;
            this->label162->Text = L"10:00-11:00";
            // 
            // label163
            // 
            this->label163->AutoSize = true;
            this->label163->BackColor = System::Drawing::Color::White;
            this->label163->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label163->Location = System::Drawing::Point(11, 389);
            this->label163->Name = L"label163";
            this->label163->Size = System::Drawing::Size(91, 28);
            this->label163->TabIndex = 264;
            this->label163->Text = L"Thursday";
            // 
            // label164
            // 
            this->label164->AutoSize = true;
            this->label164->BackColor = System::Drawing::Color::White;
            this->label164->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label164->Location = System::Drawing::Point(461, 119);
            this->label164->Name = L"label164";
            this->label164->Size = System::Drawing::Size(116, 28);
            this->label164->TabIndex = 296;
            this->label164->Text = L"11:30-12:30";
            // 
            // label166
            // 
            this->label166->AutoSize = true;
            this->label166->BackColor = System::Drawing::Color::White;
            this->label166->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label166->Location = System::Drawing::Point(25, 465);
            this->label166->Name = L"label166";
            this->label166->Size = System::Drawing::Size(66, 28);
            this->label166->TabIndex = 265;
            this->label166->Text = L"Friday";
            // 
            // label167
            // 
            this->label167->AutoSize = true;
            this->label167->BackColor = System::Drawing::Color::White;
            this->label167->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label167->Location = System::Drawing::Point(615, 119);
            this->label167->Name = L"label167";
            this->label167->Size = System::Drawing::Size(105, 28);
            this->label167->TabIndex = 297;
            this->label167->Text = L"12:30-1:30";
            // 
            // label168
            // 
            this->label168->AutoSize = true;
            this->label168->BackColor = System::Drawing::Color::White;
            this->label168->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label168->Location = System::Drawing::Point(25, 542);
            this->label168->Name = L"label168";
            this->label168->Size = System::Drawing::Size(90, 28);
            this->label168->TabIndex = 266;
            this->label168->Text = L"Saturday";
            // 
            // label169
            // 
            this->label169->AutoSize = true;
            this->label169->BackColor = System::Drawing::Color::White;
            this->label169->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label169->Location = System::Drawing::Point(809, 115);
            this->label169->Name = L"label169";
            this->label169->Size = System::Drawing::Size(94, 28);
            this->label169->TabIndex = 298;
            this->label169->Text = L"2:30-3:30";
            // 
            // label170
            // 
            this->label170->AutoSize = true;
            this->label170->BackColor = System::Drawing::Color::White;
            this->label170->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label170->Location = System::Drawing::Point(939, 115);
            this->label170->Name = L"label170";
            this->label170->Size = System::Drawing::Size(94, 28);
            this->label170->TabIndex = 299;
            this->label170->Text = L"3:30-4:30";
            // 
            // classlabgroup
            // 
            this->classlabgroup->CaptionOverlap = 1;
            this->classlabgroup->CaptionVisible = false;
            this->classlabgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classlabgroup->Location = System::Drawing::Point(23, 1707);
            this->classlabgroup->Name = L"classlabgroup";
            // 
            // classlabgroup.Panel
            // 
            this->classlabgroup->Panel->Controls->Add(this->classoptrooms);
            this->classlabgroup->Panel->Controls->Add(this->compactlabs);
            this->classlabgroup->Panel->Controls->Add(this->classlab);
            this->classlabgroup->Panel->Controls->Add(this->label32);
            this->classlabgroup->Panel->Controls->Add(this->classlabroomlist);
            this->classlabgroup->Panel->Controls->Add(this->label44);
            this->classlabgroup->Panel->Controls->Add(this->classlabsave);
            this->classlabgroup->Panel->Controls->Add(this->classsessions);
            this->classlabgroup->Panel->Controls->Add(this->label157);
            this->classlabgroup->Panel->Controls->Add(this->classbatches);
            this->classlabgroup->Panel->Controls->Add(this->label39);
            this->classlabgroup->Panel->Controls->Add(this->kryptonPanel14);
            this->classlabgroup->Panel->Controls->Add(this->label156);
            this->classlabgroup->Panel->Controls->Add(this->classlabcombo);
            this->classlabgroup->Panel->Controls->Add(this->label154);
            this->classlabgroup->Panel->Controls->Add(this->classlabteachers);
            this->classlabgroup->Size = System::Drawing::Size(1127, 1100);
            this->classlabgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classlabgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classlabgroup->StateCommon->Border->ColorAngle = 50;
            this->classlabgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabgroup->StateCommon->Border->Rounding = 7;
            this->classlabgroup->StateCommon->Border->Width = 1;
            this->classlabgroup->TabIndex = 347;
            this->classlabgroup->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::kryptonGroupBox1_Paint);
            this->classlabgroup->Enter += gcnew System::EventHandler(this, &MyForm::classlabgroup_Enter);
            // 
            // classoptrooms
            // 
            this->classoptrooms->Location = System::Drawing::Point(677, 580);
            this->classoptrooms->Name = L"classoptrooms";
            this->classoptrooms->Size = System::Drawing::Size(321, 29);
            this->classoptrooms->TabIndex = 357;
            this->classoptrooms->Values->Text = L"Select optimal rooms automatically\?";
            // 
            // compactlabs
            // 
            this->compactlabs->Location = System::Drawing::Point(119, 1036);
            this->compactlabs->Name = L"compactlabs";
            this->compactlabs->Size = System::Drawing::Size(137, 29);
            this->compactlabs->TabIndex = 356;
            this->compactlabs->Values->Text = L"Compact labs";
            // 
            // classlab
            // 
            this->classlab->AllowUserToOrderColumns = true;
            this->classlab->AllowUserToResizeColumns = false;
            this->classlab->AllowUserToResizeRows = false;
            dataGridViewCellStyle19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->SelectionForeColor = System::Drawing::Color::Black;
            this->classlab->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle19;
            this->classlab->ColumnHeadersHeight = 36;
            this->classlab->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->lsubject, this->dataGridViewButtonColumn7 });
            this->classlab->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->classlab->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classlab->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlab->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlab->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlab->HideOuterBorders = true;
            this->classlab->Location = System::Drawing::Point(119, 816);
            this->classlab->Name = L"classlab";
            this->classlab->RowHeadersVisible = false;
            this->classlab->RowHeadersWidth = 62;
            dataGridViewCellStyle20->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::Black;
            this->classlab->RowsDefaultCellStyle = dataGridViewCellStyle20;
            this->classlab->RowTemplate->Height = 28;
            this->classlab->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->classlab->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->classlab->Size = System::Drawing::Size(784, 194);
            this->classlab->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->classlab->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classlab->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classlab->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classlab.StateCommon.DataCell.Content.Image")));
            this->classlab->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->classlab->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->classlab->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlab->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlab->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlab->StateCommon->HeaderColumn->Border->Width = 0;
            this->classlab->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classlab->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classlab.StateCommon.HeaderColumn.Content.Image")));
            this->classlab->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->classlab->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->classlab->TabIndex = 355;
            this->classlab->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classlab_CellContentClick_2);
            // 
            // lsubject
            // 
            this->lsubject->HeaderText = L"Subjects";
            this->lsubject->MinimumWidth = 8;
            this->lsubject->Name = L"lsubject";
            this->lsubject->ReadOnly = true;
            this->lsubject->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->lsubject->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            this->lsubject->Width = 250;
            // 
            // dataGridViewButtonColumn7
            // 
            this->dataGridViewButtonColumn7->HeaderText = L"";
            this->dataGridViewButtonColumn7->MinimumWidth = 8;
            this->dataGridViewButtonColumn7->Name = L"dataGridViewButtonColumn7";
            this->dataGridViewButtonColumn7->ReadOnly = true;
            this->dataGridViewButtonColumn7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn7->Text = L"Delete";
            this->dataGridViewButtonColumn7->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn7->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn7->Width = 150;
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->BackColor = System::Drawing::Color::White;
            this->label32->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label32->ForeColor = System::Drawing::Color::Black;
            this->label32->Location = System::Drawing::Point(385, 767);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(257, 28);
            this->label32->TabIndex = 354;
            this->label32->Text = L"Lab Subjects applicable are";
            // 
            // classlabroomlist
            // 
            this->classlabroomlist->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::InputControlRibbon;
            this->classlabroomlist->BorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ContextMenuItemSplit;
            this->classlabroomlist->CheckOnClick = true;
            this->classlabroomlist->Location = System::Drawing::Point(678, 379);
            this->classlabroomlist->Name = L"classlabroomlist";
            this->classlabroomlist->Size = System::Drawing::Size(348, 182);
            this->classlabroomlist->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->classlabroomlist->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabroomlist->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabroomlist->StateCommon->Border->Rounding = 5;
            this->classlabroomlist->StateCommon->Border->Width = 1;
            this->classlabroomlist->TabIndex = 353;
            // 
            // label44
            // 
            this->label44->AutoSize = true;
            this->label44->BackColor = System::Drawing::Color::White;
            this->label44->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label44->ForeColor = System::Drawing::Color::Black;
            this->label44->Location = System::Drawing::Point(672, 320);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(112, 28);
            this->label44->TabIndex = 352;
            this->label44->Text = L"Lab Rooms";
            // 
            // classlabsave
            // 
            this->classlabsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classlabsave->Location = System::Drawing::Point(891, 628);
            this->classlabsave->Name = L"classlabsave";
            this->classlabsave->Size = System::Drawing::Size(154, 58);
            this->classlabsave->TabIndex = 261;
            this->classlabsave->Text = L"Save";
            this->classlabsave->UseVisualStyleBackColor = false;
            this->classlabsave->Click += gcnew System::EventHandler(this, &MyForm::classlabsave_Click);
            // 
            // classsessions
            // 
            this->classsessions->Location = System::Drawing::Point(677, 241);
            this->classsessions->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2020, 0, 0, 0 });
            this->classsessions->Name = L"classsessions";
            this->classsessions->Size = System::Drawing::Size(304, 30);
            this->classsessions->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classsessions->TabIndex = 351;
            this->classsessions->ValueChanged += gcnew System::EventHandler(this, &MyForm::classsessions_ValueChanged);
            // 
            // label157
            // 
            this->label157->AutoSize = true;
            this->label157->BackColor = System::Drawing::Color::White;
            this->label157->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label157->ForeColor = System::Drawing::Color::Black;
            this->label157->Location = System::Drawing::Point(672, 175);
            this->label157->Name = L"label157";
            this->label157->Size = System::Drawing::Size(194, 28);
            this->label157->TabIndex = 350;
            this->label157->Text = L"Number of sessions";
            // 
            // classbatches
            // 
            this->classbatches->Location = System::Drawing::Point(106, 243);
            this->classbatches->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2020, 0, 0, 0 });
            this->classbatches->Name = L"classbatches";
            this->classbatches->Size = System::Drawing::Size(304, 30);
            this->classbatches->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classbatches->TabIndex = 349;
            // 
            // label39
            // 
            this->label39->AutoSize = true;
            this->label39->BackColor = System::Drawing::Color::White;
            this->label39->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label39->ForeColor = System::Drawing::Color::Black;
            this->label39->Location = System::Drawing::Point(101, 191);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(188, 28);
            this->label39->TabIndex = 348;
            this->label39->Text = L"Number of batches";
            // 
            // kryptonPanel14
            // 
            this->kryptonPanel14->Location = System::Drawing::Point(99, 139);
            this->kryptonPanel14->Name = L"kryptonPanel14";
            this->kryptonPanel14->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel14->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel14->TabIndex = 347;
            // 
            // label156
            // 
            this->label156->AutoSize = true;
            this->label156->BackColor = System::Drawing::Color::White;
            this->label156->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label156->ForeColor = System::Drawing::Color::Black;
            this->label156->Location = System::Drawing::Point(101, 48);
            this->label156->Name = L"label156";
            this->label156->Size = System::Drawing::Size(177, 28);
            this->label156->TabIndex = 345;
            this->label156->Text = L"Lab Subject Name";
            // 
            // classlabcombo
            // 
            this->classlabcombo->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->classlabcombo->Location = System::Drawing::Point(105, 97);
            this->classlabcombo->Name = L"classlabcombo";
            this->classlabcombo->Size = System::Drawing::Size(478, 44);
            this->classlabcombo->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->classlabcombo->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabcombo->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabcombo->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->classlabcombo->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->classlabcombo->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->classlabcombo->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabcombo->StateCommon->Border->Rounding = 10;
            this->classlabcombo->StateCommon->Border->Width = 3;
            this->classlabcombo->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->classlabcombo->TabIndex = 346;
            this->classlabcombo->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownClass);
            this->classlabcombo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // label154
            // 
            this->label154->AutoSize = true;
            this->label154->BackColor = System::Drawing::Color::White;
            this->label154->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label154->ForeColor = System::Drawing::Color::Black;
            this->label154->Location = System::Drawing::Point(100, 310);
            this->label154->Name = L"label154";
            this->label154->Size = System::Drawing::Size(348, 28);
            this->label154->TabIndex = 344;
            this->label154->Text = L"Electives and Common-time subjects";
            // 
            // classlabteachers
            // 
            this->classlabteachers->AllowUserToOrderColumns = true;
            this->classlabteachers->AllowUserToResizeColumns = false;
            this->classlabteachers->AllowUserToResizeRows = false;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            this->classlabteachers->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle21;
            this->classlabteachers->ColumnHeadersHeight = 36;
            this->classlabteachers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->Teacher1,
                    this->dataGridViewButtonColumn3
            });
            this->classlabteachers->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->classlabteachers->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classlabteachers->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlabteachers->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlabteachers->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classlabteachers->HideOuterBorders = true;
            this->classlabteachers->Location = System::Drawing::Point(93, 374);
            this->classlabteachers->Name = L"classlabteachers";
            this->classlabteachers->RowHeadersVisible = false;
            this->classlabteachers->RowHeadersWidth = 62;
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->classlabteachers->RowsDefaultCellStyle = dataGridViewCellStyle22;
            this->classlabteachers->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::White;
            this->classlabteachers->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
            this->classlabteachers->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)),
                static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(242)));
            this->classlabteachers->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
            this->classlabteachers->RowTemplate->DividerHeight = 1;
            this->classlabteachers->RowTemplate->Height = 25;
            this->classlabteachers->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->classlabteachers->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->classlabteachers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->classlabteachers->Size = System::Drawing::Size(540, 194);
            this->classlabteachers->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->classlabteachers->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classlabteachers->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classlabteachers->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classlabteachers.StateCommon.DataCell.Content.Image")));
            this->classlabteachers->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->classlabteachers->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->classlabteachers->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabteachers->StateCommon->HeaderColumn->Border->Rounding = 4;
            this->classlabteachers->StateCommon->HeaderColumn->Border->Width = 0;
            this->classlabteachers->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classlabteachers->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classlabteachers.StateCommon.HeaderColumn.Content.Image")));
            this->classlabteachers->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->classlabteachers->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->classlabteachers->StatePressed->HeaderRow->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StatePressed->HeaderRow->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StatePressed->HeaderRow->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabteachers->StatePressed->HeaderRow->Border->Rounding = 3;
            this->classlabteachers->StatePressed->HeaderRow->Border->Width = 0;
            this->classlabteachers->StateSelected->DataCell->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StateSelected->DataCell->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlabteachers->StateSelected->DataCell->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classlabteachers->TabIndex = 343;
            this->classlabteachers->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick_1);
            // 
            // Teacher1
            // 
            this->Teacher1->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->Teacher1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Teacher1->HeaderText = L"Teachers";
            this->Teacher1->MinimumWidth = 8;
            this->Teacher1->Name = L"Teacher1";
            this->Teacher1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->Teacher1->Width = 200;
            // 
            // dataGridViewButtonColumn3
            // 
            this->dataGridViewButtonColumn3->HeaderText = L"";
            this->dataGridViewButtonColumn3->MinimumWidth = 8;
            this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
            this->dataGridViewButtonColumn3->ReadOnly = true;
            this->dataGridViewButtonColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn3->Text = L"Delete";
            this->dataGridViewButtonColumn3->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn3->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn3->Width = 150;
            // 
            // classelegroup
            // 
            this->classelegroup->CaptionOverlap = 1;
            this->classelegroup->CaptionVisible = false;
            this->classelegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classelegroup->Location = System::Drawing::Point(23, 1283);
            this->classelegroup->Name = L"classelegroup";
            // 
            // classelegroup.Panel
            // 
            this->classelegroup->Panel->Controls->Add(this->label36);
            this->classelegroup->Panel->Controls->Add(this->classele);
            this->classelegroup->Size = System::Drawing::Size(1127, 346);
            this->classelegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classelegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classelegroup->StateCommon->Border->ColorAngle = 50;
            this->classelegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classelegroup->StateCommon->Border->Rounding = 7;
            this->classelegroup->StateCommon->Border->Width = 1;
            this->classelegroup->TabIndex = 346;
            this->classelegroup->Enter += gcnew System::EventHandler(this, &MyForm::classelegroup_Enter);
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->BackColor = System::Drawing::Color::White;
            this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->ForeColor = System::Drawing::Color::Black;
            this->label36->Location = System::Drawing::Point(134, 42);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(348, 28);
            this->label36->TabIndex = 344;
            this->label36->Text = L"Electives and Common-time subjects";
            // 
            // classele
            // 
            this->classele->AllowUserToOrderColumns = true;
            this->classele->AllowUserToResizeColumns = false;
            this->classele->AllowUserToResizeRows = false;
            dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle23->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle23->SelectionForeColor = System::Drawing::Color::Black;
            this->classele->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle23;
            this->classele->ColumnHeadersHeight = 36;
            this->classele->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->esubject, this->dataGridViewButtonColumn5 });
            this->classele->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->classele->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classele->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classele->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classele->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classele->HideOuterBorders = true;
            this->classele->Location = System::Drawing::Point(135, 113);
            this->classele->Name = L"classele";
            this->classele->RowHeadersVisible = false;
            this->classele->RowHeadersWidth = 62;
            dataGridViewCellStyle24->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle24->SelectionForeColor = System::Drawing::Color::Black;
            this->classele->RowsDefaultCellStyle = dataGridViewCellStyle24;
            this->classele->RowTemplate->Height = 28;
            this->classele->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->classele->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->classele->Size = System::Drawing::Size(865, 194);
            this->classele->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->classele->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classele->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classele->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classele.StateCommon.DataCell.Content.Image")));
            this->classele->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->classele->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->classele->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classele->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classele->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classele->StateCommon->HeaderColumn->Border->Width = 0;
            this->classele->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classele->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classele.StateCommon.HeaderColumn.Content.Image")));
            this->classele->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->classele->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->classele->TabIndex = 343;
            this->classele->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classele_CellContentClick_1);
            // 
            // esubject
            // 
            this->esubject->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->esubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->esubject->HeaderText = L"Subjects";
            this->esubject->MinimumWidth = 8;
            this->esubject->Name = L"esubject";
            this->esubject->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->esubject->Width = 350;
            // 
            // dataGridViewButtonColumn5
            // 
            this->dataGridViewButtonColumn5->HeaderText = L"";
            this->dataGridViewButtonColumn5->MinimumWidth = 8;
            this->dataGridViewButtonColumn5->Name = L"dataGridViewButtonColumn5";
            this->dataGridViewButtonColumn5->ReadOnly = true;
            this->dataGridViewButtonColumn5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn5->Text = L"Delete";
            this->dataGridViewButtonColumn5->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn5->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn5->Width = 150;
            // 
            // classcoregroup
            // 
            this->classcoregroup->CaptionOverlap = 1;
            this->classcoregroup->CaptionVisible = false;
            this->classcoregroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classcoregroup->Location = System::Drawing::Point(23, 883);
            this->classcoregroup->Name = L"classcoregroup";
            // 
            // classcoregroup.Panel
            // 
            this->classcoregroup->Panel->Controls->Add(this->label37);
            this->classcoregroup->Panel->Controls->Add(this->classcore);
            this->classcoregroup->Size = System::Drawing::Size(1127, 346);
            this->classcoregroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classcoregroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classcoregroup->StateCommon->Border->ColorAngle = 50;
            this->classcoregroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classcoregroup->StateCommon->Border->Rounding = 7;
            this->classcoregroup->StateCommon->Border->Width = 1;
            this->classcoregroup->TabIndex = 345;
            this->classcoregroup->Enter += gcnew System::EventHandler(this, &MyForm::classcoregroup_Enter);
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->BackColor = System::Drawing::Color::White;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->ForeColor = System::Drawing::Color::Black;
            this->label37->Location = System::Drawing::Point(64, 41);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(1037, 28);
            this->label37->TabIndex = 344;
            this->label37->Text = L"Select the subjects taught and their corresponding teachers for core subjects(non"
                L"-elective and non-lab subjects)";
            // 
            // classcore
            // 
            this->classcore->AllowUserToOrderColumns = true;
            this->classcore->AllowUserToResizeColumns = false;
            this->classcore->AllowUserToResizeRows = false;
            dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
            this->classcore->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle25;
            this->classcore->ColumnHeadersHeight = 36;
            this->classcore->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->csubject, this->cteacher,
                    this->dataGridViewButtonColumn6
            });
            this->classcore->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->classcore->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classcore->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classcore->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classcore->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->classcore->HideOuterBorders = true;
            this->classcore->Location = System::Drawing::Point(135, 113);
            this->classcore->Name = L"classcore";
            this->classcore->RowHeadersVisible = false;
            this->classcore->RowHeadersWidth = 62;
            dataGridViewCellStyle26->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle26->SelectionForeColor = System::Drawing::Color::Black;
            this->classcore->RowsDefaultCellStyle = dataGridViewCellStyle26;
            this->classcore->RowTemplate->Height = 28;
            this->classcore->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->classcore->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->classcore->Size = System::Drawing::Size(865, 194);
            this->classcore->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->classcore->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->classcore->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classcore->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classcore.StateCommon.DataCell.Content.Image")));
            this->classcore->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->classcore->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->classcore->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classcore->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classcore->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classcore->StateCommon->HeaderColumn->Border->Width = 0;
            this->classcore->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classcore->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"classcore.StateCommon.HeaderColumn.Content.Image")));
            this->classcore->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->classcore->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->classcore->TabIndex = 343;
            this->classcore->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classcore_CellContentClick_1);
            // 
            // csubject
            // 
            this->csubject->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->csubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->csubject->HeaderText = L"Subjects";
            this->csubject->MinimumWidth = 8;
            this->csubject->Name = L"csubject";
            this->csubject->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->csubject->Width = 200;
            // 
            // cteacher
            // 
            this->cteacher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cteacher->HeaderText = L"Teachers";
            this->cteacher->MinimumWidth = 8;
            this->cteacher->Name = L"cteacher";
            this->cteacher->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->cteacher->Width = 200;
            // 
            // dataGridViewButtonColumn6
            // 
            this->dataGridViewButtonColumn6->HeaderText = L"";
            this->dataGridViewButtonColumn6->MinimumWidth = 8;
            this->dataGridViewButtonColumn6->Name = L"dataGridViewButtonColumn6";
            this->dataGridViewButtonColumn6->ReadOnly = true;
            this->dataGridViewButtonColumn6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn6->Text = L"Delete";
            this->dataGridViewButtonColumn6->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn6->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn6->Width = 150;
            // 
            // classbatchgroup
            // 
            this->classbatchgroup->CaptionOverlap = 1;
            this->classbatchgroup->CaptionVisible = false;
            this->classbatchgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classbatchgroup->Location = System::Drawing::Point(23, 632);
            this->classbatchgroup->Name = L"classbatchgroup";
            // 
            // classbatchgroup.Panel
            // 
            this->classbatchgroup->Panel->Controls->Add(this->classbatch);
            this->classbatchgroup->Panel->Controls->Add(this->label2);
            this->classbatchgroup->Size = System::Drawing::Size(1127, 194);
            this->classbatchgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classbatchgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classbatchgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->classbatchgroup->StateCommon->Border->ColorAngle = 50;
            this->classbatchgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classbatchgroup->StateCommon->Border->Rounding = 7;
            this->classbatchgroup->StateCommon->Border->Width = 1;
            this->classbatchgroup->TabIndex = 343;
            this->classbatchgroup->Enter += gcnew System::EventHandler(this, &MyForm::classbatchgroup_Enter);
            // 
            // classbatch
            // 
            this->classbatch->Location = System::Drawing::Point(104, 86);
            this->classbatch->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2999, 0, 0, 0 });
            this->classbatch->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2020, 0, 0, 0 });
            this->classbatch->Name = L"classbatch";
            this->classbatch->Size = System::Drawing::Size(304, 30);
            this->classbatch->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classbatch->TabIndex = 328;
            this->classbatch->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2020, 0, 0, 0 });
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::White;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::Black;
            this->label2->Location = System::Drawing::Point(99, 34);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(297, 28);
            this->label2->TabIndex = 327;
            this->label2->Text = L"Class Batch (Year of Admission)";
            // 
            // classbranchgroup
            // 
            this->classbranchgroup->CaptionOverlap = 1;
            this->classbranchgroup->CaptionVisible = false;
            this->classbranchgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classbranchgroup->Location = System::Drawing::Point(23, 381);
            this->classbranchgroup->Name = L"classbranchgroup";
            // 
            // classbranchgroup.Panel
            // 
            this->classbranchgroup->Panel->Controls->Add(this->label82);
            this->classbranchgroup->Panel->Controls->Add(this->classbranch);
            this->classbranchgroup->Size = System::Drawing::Size(1127, 194);
            this->classbranchgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classbranchgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classbranchgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->classbranchgroup->StateCommon->Border->ColorAngle = 50;
            this->classbranchgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classbranchgroup->StateCommon->Border->Rounding = 7;
            this->classbranchgroup->StateCommon->Border->Width = 1;
            this->classbranchgroup->TabIndex = 342;
            this->classbranchgroup->Enter += gcnew System::EventHandler(this, &MyForm::classbranchgroup_Enter);
            // 
            // label82
            // 
            this->label82->AutoSize = true;
            this->label82->BackColor = System::Drawing::Color::White;
            this->label82->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label82->Location = System::Drawing::Point(94, 41);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(125, 28);
            this->label82->TabIndex = 343;
            this->label82->Text = L"Class branch";
            // 
            // classbranch
            // 
            this->classbranch->DropDownWidth = 342;
            this->classbranch->Location = System::Drawing::Point(87, 95);
            this->classbranch->Name = L"classbranch";
            this->classbranch->Size = System::Drawing::Size(563, 29);
            this->classbranch->StateCommon->DropBack->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classbranch->StateCommon->DropBack->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classbranch->TabIndex = 344;
            this->classbranch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // kryptonLabel10
            // 
            this->kryptonLabel10->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel10->Name = L"kryptonLabel10";
            this->kryptonLabel10->Size = System::Drawing::Size(184, 43);
            this->kryptonLabel10->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel10->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel10->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel10->TabIndex = 2;
            this->kryptonLabel10->Values->Text = L"Class Details";
            // 
            // classnamegroup
            // 
            this->classnamegroup->CaptionOverlap = 1;
            this->classnamegroup->CaptionVisible = false;
            this->classnamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->classnamegroup->Location = System::Drawing::Point(23, 168);
            this->classnamegroup->Name = L"classnamegroup";
            // 
            // classnamegroup.Panel
            // 
            this->classnamegroup->Panel->Controls->Add(this->kryptonPanel15);
            this->classnamegroup->Panel->Controls->Add(this->label119);
            this->classnamegroup->Panel->Controls->Add(this->classname);
            this->classnamegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::classnamegroup_Panel_Enter);
            this->classnamegroup->Size = System::Drawing::Size(1127, 194);
            this->classnamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->classnamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classnamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->classnamegroup->StateCommon->Border->ColorAngle = 50;
            this->classnamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classnamegroup->StateCommon->Border->Rounding = 9;
            this->classnamegroup->StateCommon->Border->Width = 1;
            this->classnamegroup->TabIndex = 337;
            // 
            // kryptonPanel15
            // 
            this->kryptonPanel15->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel15->Name = L"kryptonPanel15";
            this->kryptonPanel15->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel15->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel15->TabIndex = 326;
            // 
            // label119
            // 
            this->label119->AutoSize = true;
            this->label119->BackColor = System::Drawing::Color::White;
            this->label119->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label119->ForeColor = System::Drawing::Color::Black;
            this->label119->Location = System::Drawing::Point(93, 30);
            this->label119->Name = L"label119";
            this->label119->Size = System::Drawing::Size(117, 28);
            this->label119->TabIndex = 264;
            this->label119->Text = L"Class Name";
            // 
            // classname
            // 
            this->classname->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->classname->Location = System::Drawing::Point(97, 79);
            this->classname->Name = L"classname";
            this->classname->Size = System::Drawing::Size(478, 44);
            this->classname->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->classname->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classname->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classname->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->classname->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->classname->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->classname->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->classname->StateCommon->Border->Rounding = 10;
            this->classname->StateCommon->Border->Width = 3;
            this->classname->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->classname->TabIndex = 325;
            this->classname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // addteacherpanel
            // 
            this->addteacherpanel->AutoScroll = true;
            this->addteacherpanel->Controls->Add(this->panel16);
            this->addteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addteacherpanel->Location = System::Drawing::Point(0, 0);
            this->addteacherpanel->Name = L"addteacherpanel";
            this->addteacherpanel->Size = System::Drawing::Size(1924, 1050);
            this->addteacherpanel->TabIndex = 293;
            // 
            // panel16
            // 
            this->panel16->Controls->Add(this->addteacheremailidgroup);
            this->panel16->Controls->Add(this->panel17);
            this->panel16->Controls->Add(this->addteachertablegroup);
            this->panel16->Controls->Add(this->panel35);
            this->panel16->Controls->Add(this->addteacherdepartmentgroup);
            this->panel16->Controls->Add(this->kryptonLabel7);
            this->panel16->Controls->Add(this->addteachernamegroup);
            this->panel16->Location = System::Drawing::Point(179, 13);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(1194, 1834);
            this->panel16->TabIndex = 345;
            // 
            // addteacheremailidgroup
            // 
            this->addteacheremailidgroup->CaptionOverlap = 1;
            this->addteacheremailidgroup->CaptionVisible = false;
            this->addteacheremailidgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addteacheremailidgroup->Location = System::Drawing::Point(23, 633);
            this->addteacheremailidgroup->Name = L"addteacheremailidgroup";
            // 
            // addteacheremailidgroup.Panel
            // 
            this->addteacheremailidgroup->Panel->Controls->Add(this->kryptonPanel10);
            this->addteacheremailidgroup->Panel->Controls->Add(this->label1);
            this->addteacheremailidgroup->Panel->Controls->Add(this->addteacheremailid);
            this->addteacheremailidgroup->Size = System::Drawing::Size(1127, 194);
            this->addteacheremailidgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addteacheremailidgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteacheremailidgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteacheremailidgroup->StateCommon->Border->ColorAngle = 50;
            this->addteacheremailidgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteacheremailidgroup->StateCommon->Border->Rounding = 9;
            this->addteacheremailidgroup->StateCommon->Border->Width = 1;
            this->addteacheremailidgroup->TabIndex = 348;
            // 
            // kryptonPanel10
            // 
            this->kryptonPanel10->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel10->Name = L"kryptonPanel10";
            this->kryptonPanel10->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel10->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel10->TabIndex = 326;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::White;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::Black;
            this->label1->Location = System::Drawing::Point(93, 30);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(171, 28);
            this->label1->TabIndex = 264;
            this->label1->Text = L"Teacher\'s Email id";
            // 
            // addteacheremailid
            // 
            this->addteacheremailid->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->addteacheremailid->Location = System::Drawing::Point(97, 79);
            this->addteacheremailid->Name = L"addteacheremailid";
            this->addteacheremailid->Size = System::Drawing::Size(478, 44);
            this->addteacheremailid->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->addteacheremailid->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteacheremailid->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addteacheremailid->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->addteacheremailid->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->addteacheremailid->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->addteacheremailid->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteacheremailid->StateCommon->Border->Rounding = 10;
            this->addteacheremailid->StateCommon->Border->Width = 3;
            this->addteacheremailid->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->addteacheremailid->TabIndex = 325;
            this->addteacheremailid->TextChanged += gcnew System::EventHandler(this, &MyForm::addteacheremailid_TextChanged);
            this->addteacheremailid->Enter += gcnew System::EventHandler(this, &MyForm::addteacheremailid_Enter);
            this->addteacheremailid->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // panel17
            // 
            this->panel17->Controls->Add(this->addteachersave);
            this->panel17->Controls->Add(this->addteachernew);
            this->panel17->Location = System::Drawing::Point(676, 1649);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(444, 110);
            this->panel17->TabIndex = 298;
            // 
            // addteachersave
            // 
            this->addteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachersave->Location = System::Drawing::Point(14, 28);
            this->addteachersave->Name = L"addteachersave";
            this->addteachersave->Size = System::Drawing::Size(154, 58);
            this->addteachersave->TabIndex = 273;
            this->addteachersave->Text = L"Save";
            this->addteachersave->UseVisualStyleBackColor = false;
            this->addteachersave->Click += gcnew System::EventHandler(this, &MyForm::addteachersave_Click);
            // 
            // addteachernew
            // 
            this->addteachernew->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addteachernew->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachernew->Location = System::Drawing::Point(252, 29);
            this->addteachernew->Name = L"addteachernew";
            this->addteachernew->Size = System::Drawing::Size(154, 58);
            this->addteachernew->TabIndex = 272;
            this->addteachernew->Text = L"Clear";
            this->addteachernew->UseVisualStyleBackColor = false;
            this->addteachernew->Click += gcnew System::EventHandler(this, &MyForm::addteachernew_Click);
            // 
            // addteachertablegroup
            // 
            this->addteachertablegroup->CaptionOverlap = 1;
            this->addteachertablegroup->CaptionVisible = false;
            this->addteachertablegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addteachertablegroup->Location = System::Drawing::Point(23, 948);
            this->addteachertablegroup->Name = L"addteachertablegroup";
            // 
            // addteachertablegroup.Panel
            // 
            this->addteachertablegroup->Panel->Controls->Add(this->panel30);
            this->addteachertablegroup->Panel->Controls->Add(this->panel31);
            this->addteachertablegroup->Panel->Controls->Add(this->teachertablepanel);
            this->addteachertablegroup->Panel->Controls->Add(this->panel32);
            this->addteachertablegroup->Panel->Controls->Add(this->label50);
            this->addteachertablegroup->Panel->Controls->Add(this->label3);
            this->addteachertablegroup->Panel->Controls->Add(this->label24);
            this->addteachertablegroup->Panel->Controls->Add(this->label26);
            this->addteachertablegroup->Panel->Controls->Add(this->label27);
            this->addteachertablegroup->Panel->Controls->Add(this->label40);
            this->addteachertablegroup->Panel->Controls->Add(this->label41);
            this->addteachertablegroup->Panel->Controls->Add(this->label42);
            this->addteachertablegroup->Panel->Controls->Add(this->label43);
            this->addteachertablegroup->Panel->Controls->Add(this->label46);
            this->addteachertablegroup->Panel->Controls->Add(this->label47);
            this->addteachertablegroup->Panel->Controls->Add(this->label48);
            this->addteachertablegroup->Panel->Controls->Add(this->label49);
            this->addteachertablegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::addteachertablegroup_Panel_Enter);
            this->addteachertablegroup->Size = System::Drawing::Size(1127, 642);
            this->addteachertablegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addteachertablegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteachertablegroup->StateCommon->Border->ColorAngle = 50;
            this->addteachertablegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteachertablegroup->StateCommon->Border->Rounding = 7;
            this->addteachertablegroup->StateCommon->Border->Width = 1;
            this->addteachertablegroup->TabIndex = 346;
            // 
            // panel30
            // 
            this->panel30->BackColor = System::Drawing::Color::White;
            this->panel30->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel30.BackgroundImage")));
            this->panel30->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel30->Location = System::Drawing::Point(764, 156);
            this->panel30->Name = L"panel30";
            this->panel30->Size = System::Drawing::Size(44, 420);
            this->panel30->TabIndex = 1;
            // 
            // panel31
            // 
            this->panel31->BackColor = System::Drawing::Color::White;
            this->panel31->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel31.BackgroundImage")));
            this->panel31->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel31->Location = System::Drawing::Point(429, 156);
            this->panel31->Name = L"panel31";
            this->panel31->Size = System::Drawing::Size(44, 430);
            this->panel31->TabIndex = 300;
            // 
            // teachertablepanel
            // 
            this->teachertablepanel->BackColor = System::Drawing::Color::White;
            this->teachertablepanel->ColumnCount = 8;
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->teachertablepanel->Location = System::Drawing::Point(142, 156);
            this->teachertablepanel->Name = L"teachertablepanel";
            this->teachertablepanel->RowCount = 6;
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->Size = System::Drawing::Size(950, 431);
            this->teachertablepanel->TabIndex = 260;
            // 
            // panel32
            // 
            this->panel32->BackColor = System::Drawing::Color::White;
            this->panel32->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel32.BackgroundImage")));
            this->panel32->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel32->Location = System::Drawing::Point(418, 156);
            this->panel32->Name = L"panel32";
            this->panel32->Size = System::Drawing::Size(82, 412);
            this->panel32->TabIndex = 2;
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->BackColor = System::Drawing::Color::White;
            this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(62, 36);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(170, 28);
            this->label50->TabIndex = 344;
            this->label50->Text = L"Teacher Schedule";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::White;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(42, 176);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(85, 28);
            this->label3->TabIndex = 261;
            this->label3->Text = L"Monday";
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->BackColor = System::Drawing::Color::White;
            this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(48, 245);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(83, 28);
            this->label24->TabIndex = 262;
            this->label24->Text = L"Tuesday";
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->BackColor = System::Drawing::Color::White;
            this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(160, 116);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(105, 28);
            this->label26->TabIndex = 294;
            this->label26->Text = L"9:00-10:00";
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->BackColor = System::Drawing::Color::White;
            this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label27->Location = System::Drawing::Point(32, 322);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(113, 28);
            this->label27->TabIndex = 263;
            this->label27->Text = L"Wednesday";
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->BackColor = System::Drawing::Color::White;
            this->label40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(296, 116);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(116, 28);
            this->label40->TabIndex = 295;
            this->label40->Text = L"10:00-11:00";
            // 
            // label41
            // 
            this->label41->AutoSize = true;
            this->label41->BackColor = System::Drawing::Color::White;
            this->label41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label41->Location = System::Drawing::Point(32, 386);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(91, 28);
            this->label41->TabIndex = 264;
            this->label41->Text = L"Thursday";
            // 
            // label42
            // 
            this->label42->AutoSize = true;
            this->label42->BackColor = System::Drawing::Color::White;
            this->label42->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label42->Location = System::Drawing::Point(482, 116);
            this->label42->Name = L"label42";
            this->label42->Size = System::Drawing::Size(116, 28);
            this->label42->TabIndex = 296;
            this->label42->Text = L"11:30-12:30";
            // 
            // label43
            // 
            this->label43->AutoSize = true;
            this->label43->BackColor = System::Drawing::Color::White;
            this->label43->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label43->Location = System::Drawing::Point(46, 462);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(66, 28);
            this->label43->TabIndex = 265;
            this->label43->Text = L"Friday";
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->BackColor = System::Drawing::Color::White;
            this->label46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(636, 116);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(105, 28);
            this->label46->TabIndex = 297;
            this->label46->Text = L"12:30-1:30";
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->BackColor = System::Drawing::Color::White;
            this->label47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(46, 539);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(90, 28);
            this->label47->TabIndex = 266;
            this->label47->Text = L"Saturday";
            // 
            // label48
            // 
            this->label48->AutoSize = true;
            this->label48->BackColor = System::Drawing::Color::White;
            this->label48->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(830, 112);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(94, 28);
            this->label48->TabIndex = 298;
            this->label48->Text = L"2:30-3:30";
            // 
            // label49
            // 
            this->label49->AutoSize = true;
            this->label49->BackColor = System::Drawing::Color::White;
            this->label49->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label49->Location = System::Drawing::Point(960, 112);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(94, 28);
            this->label49->TabIndex = 299;
            this->label49->Text = L"3:30-4:30";
            // 
            // panel35
            // 
            this->panel35->Controls->Add(this->button26);
            this->panel35->Controls->Add(this->button27);
            this->panel35->Location = System::Drawing::Point(709, 2211);
            this->panel35->Name = L"panel35";
            this->panel35->Size = System::Drawing::Size(502, 137);
            this->panel35->TabIndex = 295;
            // 
            // button26
            // 
            this->button26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button26->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button26->Location = System::Drawing::Point(303, 38);
            this->button26->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button26->Name = L"button26";
            this->button26->Size = System::Drawing::Size(154, 58);
            this->button26->TabIndex = 180;
            this->button26->Text = L"Delete";
            this->button26->UseVisualStyleBackColor = false;
            // 
            // button27
            // 
            this->button27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button27->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button27->Location = System::Drawing::Point(49, 38);
            this->button27->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button27->Name = L"button27";
            this->button27->Size = System::Drawing::Size(154, 58);
            this->button27->TabIndex = 124;
            this->button27->Text = L"Save";
            this->button27->UseVisualStyleBackColor = false;
            // 
            // addteacherdepartmentgroup
            // 
            this->addteacherdepartmentgroup->CaptionOverlap = 1;
            this->addteacherdepartmentgroup->CaptionVisible = false;
            this->addteacherdepartmentgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addteacherdepartmentgroup->Location = System::Drawing::Point(23, 381);
            this->addteacherdepartmentgroup->Name = L"addteacherdepartmentgroup";
            // 
            // addteacherdepartmentgroup.Panel
            // 
            this->addteacherdepartmentgroup->Panel->Controls->Add(this->label51);
            this->addteacherdepartmentgroup->Panel->Controls->Add(this->addteacherdepartment);
            this->addteacherdepartmentgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::addteacherdepartmentgroup_Panel_Enter);
            this->addteacherdepartmentgroup->Size = System::Drawing::Size(1127, 194);
            this->addteacherdepartmentgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addteacherdepartmentgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteacherdepartmentgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->addteacherdepartmentgroup->StateCommon->Border->ColorAngle = 50;
            this->addteacherdepartmentgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteacherdepartmentgroup->StateCommon->Border->Rounding = 7;
            this->addteacherdepartmentgroup->StateCommon->Border->Width = 1;
            this->addteacherdepartmentgroup->TabIndex = 342;
            // 
            // label51
            // 
            this->label51->AutoSize = true;
            this->label51->BackColor = System::Drawing::Color::White;
            this->label51->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(94, 41);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(122, 28);
            this->label51->TabIndex = 343;
            this->label51->Text = L"Department";
            // 
            // addteacherdepartment
            // 
            this->addteacherdepartment->DropDownWidth = 342;
            this->addteacherdepartment->Location = System::Drawing::Point(87, 95);
            this->addteacherdepartment->Name = L"addteacherdepartment";
            this->addteacherdepartment->Size = System::Drawing::Size(563, 29);
            this->addteacherdepartment->StateCommon->DropBack->Color1 = System::Drawing::Color::Cyan;
            this->addteacherdepartment->StateCommon->DropBack->Color2 = System::Drawing::Color::Cyan;
            this->addteacherdepartment->TabIndex = 344;
            // 
            // kryptonLabel7
            // 
            this->kryptonLabel7->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel7->Name = L"kryptonLabel7";
            this->kryptonLabel7->Size = System::Drawing::Size(223, 43);
            this->kryptonLabel7->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel7->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel7->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel7->TabIndex = 2;
            this->kryptonLabel7->Values->Text = L"Teacher Details";
            // 
            // addteachernamegroup
            // 
            this->addteachernamegroup->CaptionOverlap = 1;
            this->addteachernamegroup->CaptionVisible = false;
            this->addteachernamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->addteachernamegroup->Location = System::Drawing::Point(23, 168);
            this->addteachernamegroup->Name = L"addteachernamegroup";
            // 
            // addteachernamegroup.Panel
            // 
            this->addteachernamegroup->Panel->Controls->Add(this->kryptonPanel13);
            this->addteachernamegroup->Panel->Controls->Add(this->label63);
            this->addteachernamegroup->Panel->Controls->Add(this->addteachername);
            this->addteachernamegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::addteachernamegroup_Panel_Enter);
            this->addteachernamegroup->Size = System::Drawing::Size(1127, 194);
            this->addteachernamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->addteachernamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteachernamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->addteachernamegroup->StateCommon->Border->ColorAngle = 50;
            this->addteachernamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteachernamegroup->StateCommon->Border->Rounding = 9;
            this->addteachernamegroup->StateCommon->Border->Width = 1;
            this->addteachernamegroup->TabIndex = 337;
            // 
            // kryptonPanel13
            // 
            this->kryptonPanel13->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel13->Name = L"kryptonPanel13";
            this->kryptonPanel13->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel13->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel13->TabIndex = 326;
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->BackColor = System::Drawing::Color::White;
            this->label63->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label63->ForeColor = System::Drawing::Color::Black;
            this->label63->Location = System::Drawing::Point(93, 30);
            this->label63->Name = L"label63";
            this->label63->Size = System::Drawing::Size(243, 28);
            this->label63->TabIndex = 264;
            this->label63->Text = L"Enter the Teacher\'s Name";
            // 
            // addteachername
            // 
            this->addteachername->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->addteachername->Location = System::Drawing::Point(97, 79);
            this->addteachername->Name = L"addteachername";
            this->addteachername->Size = System::Drawing::Size(478, 44);
            this->addteachername->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->addteachername->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteachername->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addteachername->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->addteachername->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->addteachername->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->addteachername->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->addteachername->StateCommon->Border->Rounding = 10;
            this->addteachername->StateCommon->Border->Width = 3;
            this->addteachername->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->addteachername->TabIndex = 325;
            this->addteachername->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(759, 655);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(130, 58);
            this->button2->TabIndex = 234;
            this->button2->Text = L"Save";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // button22
            // 
            this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button22->Location = System::Drawing::Point(991, 654);
            this->button22->Name = L"button22";
            this->button22->Size = System::Drawing::Size(130, 58);
            this->button22->TabIndex = 235;
            this->button22->Text = L"Clear";
            this->button22->UseVisualStyleBackColor = false;
            this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel2->Controls->Add(this->panel46);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel2->Location = System::Drawing::Point(0, 0);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(1924, 1050);
            this->panel2->TabIndex = 5;
            this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
            // 
            // panel46
            // 
            this->panel46->Controls->Add(this->kryptonLabel9);
            this->panel46->Controls->Add(this->deptgroup);
            this->panel46->Controls->Add(this->button22);
            this->panel46->Controls->Add(this->button2);
            this->panel46->Location = System::Drawing::Point(179, 13);
            this->panel46->Name = L"panel46";
            this->panel46->Size = System::Drawing::Size(1194, 730);
            this->panel46->TabIndex = 348;
            // 
            // kryptonLabel9
            // 
            this->kryptonLabel9->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel9->Name = L"kryptonLabel9";
            this->kryptonLabel9->Size = System::Drawing::Size(234, 43);
            this->kryptonLabel9->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel9->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel9->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel9->TabIndex = 347;
            this->kryptonLabel9->Values->Text = L"Department List";
            // 
            // deptgroup
            // 
            this->deptgroup->CaptionOverlap = 1;
            this->deptgroup->CaptionVisible = false;
            this->deptgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->deptgroup->Location = System::Drawing::Point(23, 168);
            this->deptgroup->Name = L"deptgroup";
            // 
            // deptgroup.Panel
            // 
            this->deptgroup->Panel->Controls->Add(this->deptDataGridView);
            this->deptgroup->Size = System::Drawing::Size(1127, 398);
            this->deptgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->deptgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->deptgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->deptgroup->StateCommon->Border->ColorAngle = 50;
            this->deptgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->deptgroup->StateCommon->Border->Rounding = 7;
            this->deptgroup->StateCommon->Border->Width = 1;
            this->deptgroup->TabIndex = 346;
            // 
            // deptDataGridView
            // 
            this->deptDataGridView->AllowUserToOrderColumns = true;
            this->deptDataGridView->AllowUserToResizeColumns = false;
            this->deptDataGridView->AllowUserToResizeRows = false;
            dataGridViewCellStyle27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle27->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle27->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle27;
            this->deptDataGridView->ColumnHeadersHeight = 36;
            this->deptDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->deptDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewButtonColumn1
            });
            this->deptDataGridView->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->deptDataGridView->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->deptDataGridView->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->deptDataGridView->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->deptDataGridView->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->deptDataGridView->HideOuterBorders = true;
            this->deptDataGridView->Location = System::Drawing::Point(161, 75);
            this->deptDataGridView->Name = L"deptDataGridView";
            this->deptDataGridView->RowHeadersVisible = false;
            this->deptDataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle28->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->RowsDefaultCellStyle = dataGridViewCellStyle28;
            this->deptDataGridView->RowTemplate->Height = 28;
            this->deptDataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->deptDataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->deptDataGridView->Size = System::Drawing::Size(865, 244);
            this->deptDataGridView->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->deptDataGridView->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->deptDataGridView->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->deptDataGridView->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deptDataGridView.StateCommon.DataCell.Content.Image")));
            this->deptDataGridView->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->deptDataGridView->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->deptDataGridView->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->deptDataGridView->StateCommon->HeaderColumn->Border->Width = 0;
            this->deptDataGridView->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->deptDataGridView->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deptDataGridView.StateCommon.HeaderColumn.Content.Image")));
            this->deptDataGridView->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->deptDataGridView->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->deptDataGridView->TabIndex = 343;
            this->deptDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::deptDataGridView_CellContentClick);
            this->deptDataGridView->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::EditingControlShowing);
            // 
            // dataGridViewTextBoxColumn1
            // 
            this->dataGridViewTextBoxColumn1->HeaderText = L"Departments";
            this->dataGridViewTextBoxColumn1->MinimumWidth = 8;
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            this->dataGridViewTextBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->HeaderText = L"";
            this->dataGridViewButtonColumn1->MinimumWidth = 8;
            this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
            this->dataGridViewButtonColumn1->ReadOnly = true;
            this->dataGridViewButtonColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn1->Text = L"Delete";
            this->dataGridViewButtonColumn1->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn1->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn1->Width = 150;
            // 
            // deleteclasspanel
            // 
            this->deleteclasspanel->Controls->Add(this->panel47);
            this->deleteclasspanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->deleteclasspanel->Location = System::Drawing::Point(0, 0);
            this->deleteclasspanel->Name = L"deleteclasspanel";
            this->deleteclasspanel->Size = System::Drawing::Size(1924, 1050);
            this->deleteclasspanel->TabIndex = 236;
            // 
            // panel47
            // 
            this->panel47->Controls->Add(this->kryptonLabel8);
            this->panel47->Controls->Add(this->kryptonGroupBox2);
            this->panel47->Location = System::Drawing::Point(179, 13);
            this->panel47->Name = L"panel47";
            this->panel47->Size = System::Drawing::Size(1194, 683);
            this->panel47->TabIndex = 348;
            // 
            // kryptonLabel8
            // 
            this->kryptonLabel8->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel8->Name = L"kryptonLabel8";
            this->kryptonLabel8->Size = System::Drawing::Size(129, 43);
            this->kryptonLabel8->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel8->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel8->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel8->TabIndex = 345;
            this->kryptonLabel8->Values->Text = L"Sections";
            // 
            // kryptonGroupBox2
            // 
            this->kryptonGroupBox2->CaptionOverlap = 1;
            this->kryptonGroupBox2->CaptionVisible = false;
            this->kryptonGroupBox2->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox2->Location = System::Drawing::Point(23, 168);
            this->kryptonGroupBox2->Name = L"kryptonGroupBox2";
            // 
            // kryptonGroupBox2.Panel
            // 
            this->kryptonGroupBox2->Panel->Controls->Add(this->sectiondeletedatagridview);
            this->kryptonGroupBox2->Size = System::Drawing::Size(1127, 398);
            this->kryptonGroupBox2->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox2->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonGroupBox2->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonGroupBox2->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox2->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox2->StateCommon->Border->Rounding = 7;
            this->kryptonGroupBox2->StateCommon->Border->Width = 1;
            this->kryptonGroupBox2->TabIndex = 347;
            // 
            // sectiondeletedatagridview
            // 
            this->sectiondeletedatagridview->AllowUserToOrderColumns = true;
            this->sectiondeletedatagridview->AllowUserToResizeColumns = false;
            this->sectiondeletedatagridview->AllowUserToResizeRows = false;
            dataGridViewCellStyle29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
            this->sectiondeletedatagridview->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle29;
            this->sectiondeletedatagridview->ColumnHeadersHeight = 36;
            this->sectiondeletedatagridview->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sectiondeletedatagridview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->classcolumn,
                    this->classdeletebutton
            });
            this->sectiondeletedatagridview->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->sectiondeletedatagridview->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->sectiondeletedatagridview->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sectiondeletedatagridview->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sectiondeletedatagridview->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->sectiondeletedatagridview->HideOuterBorders = true;
            this->sectiondeletedatagridview->Location = System::Drawing::Point(161, 75);
            this->sectiondeletedatagridview->Name = L"sectiondeletedatagridview";
            this->sectiondeletedatagridview->RowHeadersVisible = false;
            this->sectiondeletedatagridview->RowHeadersWidth = 62;
            dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle30->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle30->SelectionForeColor = System::Drawing::Color::Black;
            this->sectiondeletedatagridview->RowsDefaultCellStyle = dataGridViewCellStyle30;
            this->sectiondeletedatagridview->RowTemplate->Height = 28;
            this->sectiondeletedatagridview->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->sectiondeletedatagridview->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->sectiondeletedatagridview->Size = System::Drawing::Size(865, 244);
            this->sectiondeletedatagridview->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->sectiondeletedatagridview->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->sectiondeletedatagridview->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sectiondeletedatagridview->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sectiondeletedatagridview.StateCommon.DataCell.Content.Image")));
            this->sectiondeletedatagridview->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->sectiondeletedatagridview->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Border->Width = 0;
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sectiondeletedatagridview.StateCommon.HeaderColumn.Content.Image")));
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->sectiondeletedatagridview->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->sectiondeletedatagridview->TabIndex = 343;
            this->sectiondeletedatagridview->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            // 
            // classcolumn
            // 
            this->classcolumn->HeaderText = L"Sections";
            this->classcolumn->MinimumWidth = 8;
            this->classcolumn->Name = L"classcolumn";
            this->classcolumn->ReadOnly = true;
            this->classcolumn->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->classcolumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
            this->classcolumn->Width = 350;
            // 
            // classdeletebutton
            // 
            this->classdeletebutton->HeaderText = L"";
            this->classdeletebutton->MinimumWidth = 8;
            this->classdeletebutton->Name = L"classdeletebutton";
            this->classdeletebutton->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->classdeletebutton->Text = L"Delete";
            this->classdeletebutton->ToolTipText = L"Delete";
            this->classdeletebutton->UseColumnTextForButtonValue = true;
            this->classdeletebutton->Width = 150;
            // 
            // timer1
            // 
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
            // 
            // label94
            // 
            this->label94->AutoSize = true;
            this->label94->BackColor = System::Drawing::Color::White;
            this->label94->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label94->Location = System::Drawing::Point(70, 160);
            this->label94->Name = L"label94";
            this->label94->Size = System::Drawing::Size(349, 28);
            this->label94->TabIndex = 297;
            this->label94->Text = L"Teacher handling the elective subject";
            // 
            // editsubbfactorgroup
            // 
            this->editsubbfactorgroup->CaptionOverlap = 1;
            this->editsubbfactorgroup->CaptionVisible = false;
            this->editsubbfactorgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubbfactorgroup->Location = System::Drawing::Point(23, 2945);
            this->editsubbfactorgroup->Name = L"editsubbfactorgroup";
            // 
            // editsubbfactorgroup.Panel
            // 
            this->editsubbfactorgroup->Panel->Controls->Add(this->editsubbfactor);
            this->editsubbfactorgroup->Panel->Controls->Add(this->label110);
            this->editsubbfactorgroup->Panel->Controls->Add(this->kryptonNumericUpDown1);
            this->editsubbfactorgroup->Panel->Controls->Add(this->label97);
            this->editsubbfactorgroup->Size = System::Drawing::Size(1127, 194);
            this->editsubbfactorgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubbfactorgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubbfactorgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubbfactorgroup->StateCommon->Border->ColorAngle = 50;
            this->editsubbfactorgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubbfactorgroup->StateCommon->Border->Rounding = 7;
            this->editsubbfactorgroup->StateCommon->Border->Width = 1;
            this->editsubbfactorgroup->TabIndex = 342;
            // 
            // editsubbfactor
            // 
            this->editsubbfactor->DecimalPlaces = 1;
            this->editsubbfactor->Location = System::Drawing::Point(98, 96);
            this->editsubbfactor->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->editsubbfactor->Name = L"editsubbfactor";
            this->editsubbfactor->Size = System::Drawing::Size(304, 30);
            this->editsubbfactor->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->editsubbfactor->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->editsubbfactor->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubbfactor->TabIndex = 328;
            this->editsubbfactor->Enter += gcnew System::EventHandler(this, &MyForm::editsubbfactor_Enter);
            // 
            // label110
            // 
            this->label110->AutoSize = true;
            this->label110->BackColor = System::Drawing::Color::White;
            this->label110->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label110->ForeColor = System::Drawing::Color::Black;
            this->label110->Location = System::Drawing::Point(94, 39);
            this->label110->Name = L"label110";
            this->label110->Size = System::Drawing::Size(730, 28);
            this->label110->TabIndex = 327;
            this->label110->Text = L"Rate the subject from 1 to 5 based on its exhaustiveness according to students";
            // 
            // kryptonNumericUpDown1
            // 
            this->kryptonNumericUpDown1->Location = System::Drawing::Point(98, 96);
            this->kryptonNumericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->kryptonNumericUpDown1->Name = L"kryptonNumericUpDown1";
            this->kryptonNumericUpDown1->Size = System::Drawing::Size(304, 30);
            this->kryptonNumericUpDown1->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->kryptonNumericUpDown1->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->kryptonNumericUpDown1->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonNumericUpDown1->TabIndex = 328;
            // 
            // label97
            // 
            this->label97->AutoSize = true;
            this->label97->BackColor = System::Drawing::Color::White;
            this->label97->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label97->ForeColor = System::Drawing::Color::Black;
            this->label97->Location = System::Drawing::Point(94, 39);
            this->label97->Name = L"label97";
            this->label97->Size = System::Drawing::Size(184, 28);
            this->label97->TabIndex = 327;
            this->label97->Text = L"Number Of Credits";
            // 
            // editsubroomlistgroup
            // 
            this->editsubroomlistgroup->CaptionOverlap = 1;
            this->editsubroomlistgroup->CaptionVisible = false;
            this->editsubroomlistgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubroomlistgroup->Location = System::Drawing::Point(23, 2542);
            this->editsubroomlistgroup->Name = L"editsubroomlistgroup";
            // 
            // editsubroomlistgroup.Panel
            // 
            this->editsubroomlistgroup->Panel->Controls->Add(this->label150);
            this->editsubroomlistgroup->Panel->Controls->Add(this->editsubroomlist);
            this->editsubroomlistgroup->Size = System::Drawing::Size(1127, 357);
            this->editsubroomlistgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubroomlistgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubroomlistgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubroomlistgroup->StateCommon->Border->ColorAngle = 50;
            this->editsubroomlistgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubroomlistgroup->StateCommon->Border->Rounding = 7;
            this->editsubroomlistgroup->StateCommon->Border->Width = 1;
            this->editsubroomlistgroup->TabIndex = 344;
            // 
            // label150
            // 
            this->label150->AutoSize = true;
            this->label150->BackColor = System::Drawing::Color::White;
            this->label150->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label150->ForeColor = System::Drawing::Color::Black;
            this->label150->Location = System::Drawing::Point(143, 43);
            this->label150->Name = L"label150";
            this->label150->Size = System::Drawing::Size(267, 28);
            this->label150->TabIndex = 344;
            this->label150->Text = L"Rooms to be used(optional)";
            // 
            // editsubroomlist
            // 
            this->editsubroomlist->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::InputControlRibbon;
            this->editsubroomlist->BorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ContextMenuItemSplit;
            this->editsubroomlist->CheckOnClick = true;
            this->editsubroomlist->Location = System::Drawing::Point(162, 110);
            this->editsubroomlist->Name = L"editsubroomlist";
            this->editsubroomlist->Size = System::Drawing::Size(348, 182);
            this->editsubroomlist->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->editsubroomlist->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubroomlist->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubroomlist->StateCommon->Border->Rounding = 5;
            this->editsubroomlist->StateCommon->Border->Width = 1;
            this->editsubroomlist->TabIndex = 343;
            this->editsubroomlist->Enter += gcnew System::EventHandler(this, &MyForm::editsubroomlist_Enter);
            // 
            // editsubdelete
            // 
            this->editsubdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubdelete->Location = System::Drawing::Point(268, 35);
            this->editsubdelete->Name = L"editsubdelete";
            this->editsubdelete->Size = System::Drawing::Size(154, 58);
            this->editsubdelete->TabIndex = 309;
            this->editsubdelete->Text = L"Delete";
            this->editsubdelete->UseVisualStyleBackColor = false;
            this->editsubdelete->Click += gcnew System::EventHandler(this, &MyForm::editsubdelete_Click);
            // 
            // editsubsave
            // 
            this->editsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubsave->Location = System::Drawing::Point(69, 35);
            this->editsubsave->Name = L"editsubsave";
            this->editsubsave->Size = System::Drawing::Size(154, 58);
            this->editsubsave->TabIndex = 308;
            this->editsubsave->Text = L"Save";
            this->editsubsave->UseVisualStyleBackColor = false;
            this->editsubsave->Click += gcnew System::EventHandler(this, &MyForm::editsubsave_Click);
            // 
            // editsubcreditsgroup
            // 
            this->editsubcreditsgroup->CaptionOverlap = 1;
            this->editsubcreditsgroup->CaptionVisible = false;
            this->editsubcreditsgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubcreditsgroup->Location = System::Drawing::Point(23, 2318);
            this->editsubcreditsgroup->Name = L"editsubcreditsgroup";
            // 
            // editsubcreditsgroup.Panel
            // 
            this->editsubcreditsgroup->Panel->Controls->Add(this->editsubcredits);
            this->editsubcreditsgroup->Panel->Controls->Add(this->label101);
            this->editsubcreditsgroup->Size = System::Drawing::Size(1127, 194);
            this->editsubcreditsgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubcreditsgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubcreditsgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubcreditsgroup->StateCommon->Border->ColorAngle = 50;
            this->editsubcreditsgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubcreditsgroup->StateCommon->Border->Rounding = 7;
            this->editsubcreditsgroup->StateCommon->Border->Width = 1;
            this->editsubcreditsgroup->TabIndex = 341;
            // 
            // editsubcredits
            // 
            this->editsubcredits->Location = System::Drawing::Point(98, 96);
            this->editsubcredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->editsubcredits->Name = L"editsubcredits";
            this->editsubcredits->Size = System::Drawing::Size(304, 30);
            this->editsubcredits->StateCommon->Border->Color1 = System::Drawing::Color::Cyan;
            this->editsubcredits->StateCommon->Border->Color2 = System::Drawing::Color::Black;
            this->editsubcredits->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubcredits->TabIndex = 328;
            this->editsubcredits->Enter += gcnew System::EventHandler(this, &MyForm::editsubcredits_Enter);
            // 
            // label101
            // 
            this->label101->AutoSize = true;
            this->label101->BackColor = System::Drawing::Color::White;
            this->label101->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label101->ForeColor = System::Drawing::Color::Black;
            this->label101->Location = System::Drawing::Point(94, 39);
            this->label101->Name = L"label101";
            this->label101->Size = System::Drawing::Size(184, 28);
            this->label101->TabIndex = 327;
            this->label101->Text = L"Number Of Credits";
            // 
            // editsubelepanel
            // 
            this->editsubelepanel->BackColor = System::Drawing::Color::White;
            this->editsubelepanel->Controls->Add(this->label155);
            this->editsubelepanel->Controls->Add(this->panel39);
            this->editsubelepanel->Controls->Add(this->panel40);
            this->editsubelepanel->Controls->Add(this->editsubeletable);
            this->editsubelepanel->Controls->Add(this->panel52);
            this->editsubelepanel->Controls->Add(this->label75);
            this->editsubelepanel->Controls->Add(this->label76);
            this->editsubelepanel->Controls->Add(this->label77);
            this->editsubelepanel->Controls->Add(this->label120);
            this->editsubelepanel->Controls->Add(this->label123);
            this->editsubelepanel->Controls->Add(this->label124);
            this->editsubelepanel->Controls->Add(this->label125);
            this->editsubelepanel->Controls->Add(this->label147);
            this->editsubelepanel->Controls->Add(this->label148);
            this->editsubelepanel->Controls->Add(this->label149);
            this->editsubelepanel->Controls->Add(this->label151);
            this->editsubelepanel->Controls->Add(this->label153);
            this->editsubelepanel->Location = System::Drawing::Point(10, 475);
            this->editsubelepanel->Name = L"editsubelepanel";
            this->editsubelepanel->Size = System::Drawing::Size(1096, 641);
            this->editsubelepanel->TabIndex = 311;
            // 
            // label155
            // 
            this->label155->AutoSize = true;
            this->label155->BackColor = System::Drawing::Color::White;
            this->label155->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label155->Location = System::Drawing::Point(36, 76);
            this->label155->Name = L"label155";
            this->label155->Size = System::Drawing::Size(770, 28);
            this->label155->TabIndex = 344;
            this->label155->Text = L"Select the slots for the Elective or Common time subject from the available optio"
                L"ns";
            // 
            // panel39
            // 
            this->panel39->BackColor = System::Drawing::Color::White;
            this->panel39->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel39.BackgroundImage")));
            this->panel39->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel39->Location = System::Drawing::Point(743, 185);
            this->panel39->Name = L"panel39";
            this->panel39->Size = System::Drawing::Size(44, 420);
            this->panel39->TabIndex = 301;
            // 
            // panel40
            // 
            this->panel40->BackColor = System::Drawing::Color::White;
            this->panel40->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel40.BackgroundImage")));
            this->panel40->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel40->Location = System::Drawing::Point(408, 185);
            this->panel40->Name = L"panel40";
            this->panel40->Size = System::Drawing::Size(44, 430);
            this->panel40->TabIndex = 316;
            // 
            // editsubeletable
            // 
            this->editsubeletable->BackColor = System::Drawing::Color::White;
            this->editsubeletable->ColumnCount = 8;
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->editsubeletable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->editsubeletable->Location = System::Drawing::Point(121, 185);
            this->editsubeletable->Name = L"editsubeletable";
            this->editsubeletable->RowCount = 6;
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editsubeletable->Size = System::Drawing::Size(950, 431);
            this->editsubeletable->TabIndex = 303;
            // 
            // panel52
            // 
            this->panel52->BackColor = System::Drawing::Color::White;
            this->panel52->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel52.BackgroundImage")));
            this->panel52->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel52->Location = System::Drawing::Point(397, 185);
            this->panel52->Name = L"panel52";
            this->panel52->Size = System::Drawing::Size(82, 412);
            this->panel52->TabIndex = 302;
            // 
            // label75
            // 
            this->label75->AutoSize = true;
            this->label75->BackColor = System::Drawing::Color::White;
            this->label75->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label75->Location = System::Drawing::Point(21, 205);
            this->label75->Name = L"label75";
            this->label75->Size = System::Drawing::Size(85, 28);
            this->label75->TabIndex = 304;
            this->label75->Text = L"Monday";
            // 
            // label76
            // 
            this->label76->AutoSize = true;
            this->label76->BackColor = System::Drawing::Color::White;
            this->label76->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label76->Location = System::Drawing::Point(27, 274);
            this->label76->Name = L"label76";
            this->label76->Size = System::Drawing::Size(83, 28);
            this->label76->TabIndex = 305;
            this->label76->Text = L"Tuesday";
            // 
            // label77
            // 
            this->label77->AutoSize = true;
            this->label77->BackColor = System::Drawing::Color::White;
            this->label77->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label77->Location = System::Drawing::Point(139, 145);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(105, 28);
            this->label77->TabIndex = 310;
            this->label77->Text = L"9:00-10:00";
            // 
            // label120
            // 
            this->label120->AutoSize = true;
            this->label120->BackColor = System::Drawing::Color::White;
            this->label120->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label120->Location = System::Drawing::Point(11, 351);
            this->label120->Name = L"label120";
            this->label120->Size = System::Drawing::Size(113, 28);
            this->label120->TabIndex = 306;
            this->label120->Text = L"Wednesday";
            // 
            // label123
            // 
            this->label123->AutoSize = true;
            this->label123->BackColor = System::Drawing::Color::White;
            this->label123->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label123->Location = System::Drawing::Point(275, 145);
            this->label123->Name = L"label123";
            this->label123->Size = System::Drawing::Size(116, 28);
            this->label123->TabIndex = 311;
            this->label123->Text = L"10:00-11:00";
            // 
            // label124
            // 
            this->label124->AutoSize = true;
            this->label124->BackColor = System::Drawing::Color::White;
            this->label124->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label124->Location = System::Drawing::Point(11, 415);
            this->label124->Name = L"label124";
            this->label124->Size = System::Drawing::Size(91, 28);
            this->label124->TabIndex = 307;
            this->label124->Text = L"Thursday";
            // 
            // label125
            // 
            this->label125->AutoSize = true;
            this->label125->BackColor = System::Drawing::Color::White;
            this->label125->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label125->Location = System::Drawing::Point(461, 145);
            this->label125->Name = L"label125";
            this->label125->Size = System::Drawing::Size(116, 28);
            this->label125->TabIndex = 312;
            this->label125->Text = L"11:30-12:30";
            // 
            // label147
            // 
            this->label147->AutoSize = true;
            this->label147->BackColor = System::Drawing::Color::White;
            this->label147->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label147->Location = System::Drawing::Point(25, 491);
            this->label147->Name = L"label147";
            this->label147->Size = System::Drawing::Size(66, 28);
            this->label147->TabIndex = 308;
            this->label147->Text = L"Friday";
            // 
            // label148
            // 
            this->label148->AutoSize = true;
            this->label148->BackColor = System::Drawing::Color::White;
            this->label148->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label148->Location = System::Drawing::Point(615, 145);
            this->label148->Name = L"label148";
            this->label148->Size = System::Drawing::Size(105, 28);
            this->label148->TabIndex = 313;
            this->label148->Text = L"12:30-1:30";
            // 
            // label149
            // 
            this->label149->AutoSize = true;
            this->label149->BackColor = System::Drawing::Color::White;
            this->label149->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label149->Location = System::Drawing::Point(26, 547);
            this->label149->Name = L"label149";
            this->label149->Size = System::Drawing::Size(90, 28);
            this->label149->TabIndex = 309;
            this->label149->Text = L"Saturday";
            // 
            // label151
            // 
            this->label151->AutoSize = true;
            this->label151->BackColor = System::Drawing::Color::White;
            this->label151->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label151->Location = System::Drawing::Point(809, 141);
            this->label151->Name = L"label151";
            this->label151->Size = System::Drawing::Size(94, 28);
            this->label151->TabIndex = 314;
            this->label151->Text = L"2:30-3:30";
            // 
            // label153
            // 
            this->label153->AutoSize = true;
            this->label153->BackColor = System::Drawing::Color::White;
            this->label153->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label153->Location = System::Drawing::Point(939, 141);
            this->label153->Name = L"label153";
            this->label153->Size = System::Drawing::Size(94, 28);
            this->label153->TabIndex = 315;
            this->label153->Text = L"3:30-4:30";
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(712, 428);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(154, 46);
            this->button3->TabIndex = 310;
            this->button3->Text = L"Options";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // panel13
            // 
            this->panel13->Controls->Add(this->panel51);
            this->panel13->Controls->Add(this->editsubbfactorgroup);
            this->panel13->Controls->Add(this->editsubroomlistgroup);
            this->panel13->Controls->Add(this->editsubeleyesgroup);
            this->panel13->Controls->Add(this->kryptonLabel2);
            this->panel13->Controls->Add(this->editsubsearchgroup);
            this->panel13->Controls->Add(this->editsubcreditsgroup);
            this->panel13->Controls->Add(this->editsubtitlegroup);
            this->panel13->Controls->Add(this->editsubelegroup);
            this->panel13->Controls->Add(this->editsubnamegroup);
            this->panel13->Controls->Add(this->editsubcodegroup);
            this->panel13->Location = System::Drawing::Point(179, 13);
            this->panel13->Name = L"panel13";
            this->panel13->Size = System::Drawing::Size(1194, 2587);
            this->panel13->TabIndex = 340;
            // 
            // panel51
            // 
            this->panel51->Controls->Add(this->editsubdelete);
            this->panel51->Controls->Add(this->editsubsave);
            this->panel51->Location = System::Drawing::Point(631, 3164);
            this->panel51->Name = L"panel51";
            this->panel51->Size = System::Drawing::Size(455, 147);
            this->panel51->TabIndex = 345;
            // 
            // editsubeleyesgroup
            // 
            this->editsubeleyesgroup->CaptionOverlap = 1;
            this->editsubeleyesgroup->CaptionVisible = false;
            this->editsubeleyesgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubeleyesgroup->Location = System::Drawing::Point(23, 1357);
            this->editsubeleyesgroup->Name = L"editsubeleyesgroup";
            // 
            // editsubeleyesgroup.Panel
            // 
            this->editsubeleyesgroup->Panel->Controls->Add(this->editsubeleteacher);
            this->editsubeleyesgroup->Panel->Controls->Add(this->editsubcluster);
            this->editsubeleyesgroup->Panel->Controls->Add(this->editsubelepanel);
            this->editsubeleyesgroup->Panel->Controls->Add(this->button3);
            this->editsubeleyesgroup->Panel->Controls->Add(this->label95);
            this->editsubeleyesgroup->Panel->Controls->Add(this->label94);
            this->editsubeleyesgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editsubeleyesgroup_Panel_Enter);
            this->editsubeleyesgroup->Size = System::Drawing::Size(1127, 1155);
            this->editsubeleyesgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubeleyesgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubeleyesgroup->StateCommon->Border->ColorAngle = 50;
            this->editsubeleyesgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubeleyesgroup->StateCommon->Border->Rounding = 7;
            this->editsubeleyesgroup->StateCommon->Border->Width = 1;
            this->editsubeleyesgroup->TabIndex = 343;
            // 
            // editsubeleteacher
            // 
            this->editsubeleteacher->AllowUserToOrderColumns = true;
            this->editsubeleteacher->AllowUserToResizeColumns = false;
            this->editsubeleteacher->AllowUserToResizeRows = false;
            dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle31->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle31;
            this->editsubeleteacher->ColumnHeadersHeight = 36;
            this->editsubeleteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsubeleteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->editsubeleteachercombo,
                    this->dataGridViewButtonColumn10
            });
            this->editsubeleteacher->GridStyles->Style = ComponentFactory::Krypton::Toolkit::DataGridViewStyle::Sheet;
            this->editsubeleteacher->GridStyles->StyleBackground = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->editsubeleteacher->GridStyles->StyleColumn = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->editsubeleteacher->GridStyles->StyleDataCells = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->editsubeleteacher->GridStyles->StyleRow = ComponentFactory::Krypton::Toolkit::GridStyle::Sheet;
            this->editsubeleteacher->HideOuterBorders = true;
            this->editsubeleteacher->Location = System::Drawing::Point(71, 204);
            this->editsubeleteacher->Name = L"editsubeleteacher";
            this->editsubeleteacher->RowHeadersVisible = false;
            this->editsubeleteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle32->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->RowsDefaultCellStyle = dataGridViewCellStyle32;
            this->editsubeleteacher->RowTemplate->Height = 28;
            this->editsubeleteacher->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->editsubeleteacher->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->editsubeleteacher->Size = System::Drawing::Size(865, 194);
            this->editsubeleteacher->StateCommon->Background->Color1 = System::Drawing::Color::White;
            this->editsubeleteacher->StateCommon->BackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->editsubeleteacher->StateCommon->DataCell->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editsubeleteacher->StateCommon->DataCell->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editsubeleteacher.StateCommon.DataCell.Content.Image")));
            this->editsubeleteacher->StateCommon->DataCell->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::CenterMiddle;
            this->editsubeleteacher->StateCommon->DataCell->Content->TextV = ComponentFactory::Krypton::Toolkit::PaletteRelativeAlign::Far;
            this->editsubeleteacher->StateCommon->HeaderColumn->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->StateCommon->HeaderColumn->Back->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->StateCommon->HeaderColumn->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubeleteacher->StateCommon->HeaderColumn->Border->Width = 0;
            this->editsubeleteacher->StateCommon->HeaderColumn->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editsubeleteacher->StateCommon->HeaderColumn->Content->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editsubeleteacher.StateCommon.HeaderColumn.Content.Image")));
            this->editsubeleteacher->StateCommon->HeaderColumn->Content->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->editsubeleteacher->StateCommon->HeaderColumn->Content->Padding = System::Windows::Forms::Padding(0);
            this->editsubeleteacher->StateSelected->DataCell->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubeleteacher->TabIndex = 343;
            this->editsubeleteacher->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::kryptonDataGridView1_CellContentClick);
            // 
            // editsubeleteachercombo
            // 
            this->editsubeleteachercombo->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->editsubeleteachercombo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editsubeleteachercombo->HeaderText = L"Teacher Name";
            this->editsubeleteachercombo->MinimumWidth = 8;
            this->editsubeleteachercombo->Name = L"editsubeleteachercombo";
            this->editsubeleteachercombo->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->editsubeleteachercombo->Width = 350;
            // 
            // dataGridViewButtonColumn10
            // 
            this->dataGridViewButtonColumn10->HeaderText = L"";
            this->dataGridViewButtonColumn10->MinimumWidth = 8;
            this->dataGridViewButtonColumn10->Name = L"dataGridViewButtonColumn10";
            this->dataGridViewButtonColumn10->ReadOnly = true;
            this->dataGridViewButtonColumn10->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridViewButtonColumn10->Text = L"Delete";
            this->dataGridViewButtonColumn10->ToolTipText = L"Delete";
            this->dataGridViewButtonColumn10->UseColumnTextForButtonValue = true;
            this->dataGridViewButtonColumn10->Width = 150;
            // 
            // editsubcluster
            // 
            this->editsubcluster->DropDownWidth = 342;
            this->editsubcluster->Location = System::Drawing::Point(75, 93);
            this->editsubcluster->Name = L"editsubcluster";
            this->editsubcluster->Size = System::Drawing::Size(508, 29);
            this->editsubcluster->StateCommon->DropBack->Color1 = System::Drawing::Color::Cyan;
            this->editsubcluster->StateCommon->DropBack->Color2 = System::Drawing::Color::Cyan;
            this->editsubcluster->TabIndex = 342;
            // 
            // label95
            // 
            this->label95->AutoSize = true;
            this->label95->BackColor = System::Drawing::Color::White;
            this->label95->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label95->Location = System::Drawing::Point(70, 34);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(160, 28);
            this->label95->TabIndex = 341;
            this->label95->Text = L"Name of Cluster";
            // 
            // kryptonLabel2
            // 
            this->kryptonLabel2->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel2->Name = L"kryptonLabel2";
            this->kryptonLabel2->Size = System::Drawing::Size(217, 43);
            this->kryptonLabel2->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel2->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel2->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel2->TabIndex = 2;
            this->kryptonLabel2->Values->Text = L"Subject Details";
            // 
            // editsubsearchgroup
            // 
            this->editsubsearchgroup->CaptionOverlap = 1;
            this->editsubsearchgroup->CaptionVisible = false;
            this->editsubsearchgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubsearchgroup->Location = System::Drawing::Point(23, 168);
            this->editsubsearchgroup->Name = L"editsubsearchgroup";
            // 
            // editsubsearchgroup.Panel
            // 
            this->editsubsearchgroup->Panel->Controls->Add(this->editsubsearchbutton);
            this->editsubsearchgroup->Panel->Controls->Add(this->label99);
            this->editsubsearchgroup->Panel->Controls->Add(this->editsubsearch);
            this->editsubsearchgroup->Size = System::Drawing::Size(1127, 260);
            this->editsubsearchgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubsearchgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubsearchgroup->StateCommon->Border->ColorAngle = 50;
            this->editsubsearchgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubsearchgroup->StateCommon->Border->Rounding = 10;
            this->editsubsearchgroup->StateCommon->Border->Width = 1;
            this->editsubsearchgroup->TabIndex = 340;
            // 
            // editsubsearchbutton
            // 
            this->editsubsearchbutton->ButtonStyle = ComponentFactory::Krypton::Toolkit::ButtonStyle::Custom1;
            this->editsubsearchbutton->Location = System::Drawing::Point(767, 126);
            this->editsubsearchbutton->Name = L"editsubsearchbutton";
            this->editsubsearchbutton->Size = System::Drawing::Size(28, 28);
            this->editsubsearchbutton->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubsearchbutton->StateCommon->Back->Color2 = System::Drawing::Color::White;
            this->editsubsearchbutton->StateCommon->Back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editsubsearchbutton.StateCommon.Back.Image")));
            this->editsubsearchbutton->StateCommon->Back->ImageAlign = ComponentFactory::Krypton::Toolkit::PaletteRectangleAlign::Control;
            this->editsubsearchbutton->StateCommon->Back->ImageStyle = ComponentFactory::Krypton::Toolkit::PaletteImageStyle::Stretch;
            this->editsubsearchbutton->StateCommon->Border->Color1 = System::Drawing::Color::Silver;
            this->editsubsearchbutton->StateCommon->Border->Color2 = System::Drawing::Color::Silver;
            this->editsubsearchbutton->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->editsubsearchbutton->StateCommon->Border->Draw = ComponentFactory::Krypton::Toolkit::InheritBool::False;
            this->editsubsearchbutton->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubsearchbutton->StateCommon->Border->Rounding = 3;
            this->editsubsearchbutton->StateNormal->Back->Color1 = System::Drawing::Color::White;
            this->editsubsearchbutton->StateNormal->Back->Color2 = System::Drawing::Color::White;
            this->editsubsearchbutton->StatePressed->Back->Color1 = System::Drawing::Color::White;
            this->editsubsearchbutton->StatePressed->Back->Color2 = System::Drawing::Color::White;
            this->editsubsearchbutton->TabIndex = 324;
            this->editsubsearchbutton->Values->Text = L"";
            this->editsubsearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editsubsearchbutton_Click);
            // 
            // label99
            // 
            this->label99->AutoSize = true;
            this->label99->BackColor = System::Drawing::Color::White;
            this->label99->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label99->ForeColor = System::Drawing::Color::Black;
            this->label99->Location = System::Drawing::Point(372, 68);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(241, 28);
            this->label99->TabIndex = 264;
            this->label99->Text = L"Search the Subject Name";
            // 
            // editsubsearch
            // 
            this->editsubsearch->DropBackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->editsubsearch->DropButtonStyle = ComponentFactory::Krypton::Toolkit::ButtonStyle::ListItem;
            this->editsubsearch->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->editsubsearch->DropDownWidth = 356;
            this->editsubsearch->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editsubsearch->Location = System::Drawing::Point(236, 122);
            this->editsubsearch->Name = L"editsubsearch";
            this->editsubsearch->Size = System::Drawing::Size(563, 34);
            this->editsubsearch->StateCommon->ComboBox->Back->Color1 = System::Drawing::Color::White;
            this->editsubsearch->StateCommon->ComboBox->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubsearch->StateCommon->ComboBox->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubsearch->StateCommon->ComboBox->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Linear;
            this->editsubsearch->StateCommon->ComboBox->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubsearch->StateCommon->ComboBox->Border->Rounding = 5;
            this->editsubsearch->StateCommon->ComboBox->Border->Width = 2;
            this->editsubsearch->StateCommon->ComboBox->Content->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editsubsearch->StateCommon->ComboBox->Content->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
            this->editsubsearch->StateCommon->DropBack->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubsearch->StateCommon->Item->Content->ShortText->Color1 = System::Drawing::Color::DimGray;
            this->editsubsearch->StateCommon->Item->Content->ShortText->Color2 = System::Drawing::Color::DimGray;
            this->editsubsearch->StateCommon->Item->Content->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editsubsearch->TabIndex = 323;
            this->editsubsearch->Enter += gcnew System::EventHandler(this, &MyForm::editsubsearch_Enter);
            this->editsubsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownsubject);
            this->editsubsearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editsubtitlegroup
            // 
            this->editsubtitlegroup->CaptionOverlap = 1;
            this->editsubtitlegroup->CaptionVisible = false;
            this->editsubtitlegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubtitlegroup->Location = System::Drawing::Point(23, 685);
            this->editsubtitlegroup->Name = L"editsubtitlegroup";
            // 
            // editsubtitlegroup.Panel
            // 
            this->editsubtitlegroup->Panel->Controls->Add(this->kryptonPanel1);
            this->editsubtitlegroup->Panel->Controls->Add(this->label109);
            this->editsubtitlegroup->Panel->Controls->Add(this->editsubtitle);
            this->editsubtitlegroup->Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editsubtitlegroup_Panel_Paint);
            this->editsubtitlegroup->Size = System::Drawing::Size(1127, 194);
            this->editsubtitlegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubtitlegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubtitlegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editsubtitlegroup->StateCommon->Border->ColorAngle = 50;
            this->editsubtitlegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubtitlegroup->StateCommon->Border->Rounding = 7;
            this->editsubtitlegroup->StateCommon->Border->Width = 1;
            this->editsubtitlegroup->TabIndex = 338;
            // 
            // kryptonPanel1
            // 
            this->kryptonPanel1->Location = System::Drawing::Point(101, 128);
            this->kryptonPanel1->Name = L"kryptonPanel1";
            this->kryptonPanel1->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel1->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel1->TabIndex = 329;
            // 
            // label109
            // 
            this->label109->AutoSize = true;
            this->label109->BackColor = System::Drawing::Color::White;
            this->label109->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label109->ForeColor = System::Drawing::Color::Black;
            this->label109->Location = System::Drawing::Point(94, 39);
            this->label109->Name = L"label109";
            this->label109->Size = System::Drawing::Size(124, 28);
            this->label109->TabIndex = 327;
            this->label109->Text = L"Subject Title";
            this->label109->Click += gcnew System::EventHandler(this, &MyForm::label109_Click);
            // 
            // editsubtitle
            // 
            this->editsubtitle->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editsubtitle->Location = System::Drawing::Point(99, 86);
            this->editsubtitle->Name = L"editsubtitle";
            this->editsubtitle->Size = System::Drawing::Size(478, 44);
            this->editsubtitle->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editsubtitle->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubtitle->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubtitle->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editsubtitle->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editsubtitle->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editsubtitle->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubtitle->StateCommon->Border->Rounding = 10;
            this->editsubtitle->StateCommon->Border->Width = 3;
            this->editsubtitle->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editsubtitle->TabIndex = 328;
            this->editsubtitle->TextChanged += gcnew System::EventHandler(this, &MyForm::editsubtitle_TextChanged);
            this->editsubtitle->Enter += gcnew System::EventHandler(this, &MyForm::editsubtitle_Enter);
            this->editsubtitle->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editsubelegroup
            // 
            this->editsubelegroup->CaptionOverlap = 1;
            this->editsubelegroup->CaptionVisible = false;
            this->editsubelegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubelegroup->Location = System::Drawing::Point(23, 1134);
            this->editsubelegroup->Name = L"editsubelegroup";
            // 
            // editsubelegroup.Panel
            // 
            this->editsubelegroup->Panel->Controls->Add(this->label92);
            this->editsubelegroup->Panel->Controls->Add(this->panel10);
            this->editsubelegroup->Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::kryptonGroupBox2_Panel_Paint);
            this->editsubelegroup->Size = System::Drawing::Size(1127, 194);
            this->editsubelegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubelegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubelegroup->StateCommon->Border->ColorAngle = 50;
            this->editsubelegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubelegroup->StateCommon->Border->Rounding = 7;
            this->editsubelegroup->StateCommon->Border->Width = 1;
            this->editsubelegroup->TabIndex = 339;
            // 
            // label92
            // 
            this->label92->AutoSize = true;
            this->label92->BackColor = System::Drawing::Color::White;
            this->label92->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label92->Location = System::Drawing::Point(95, 44);
            this->label92->Name = L"label92";
            this->label92->Size = System::Drawing::Size(156, 28);
            this->label92->TabIndex = 266;
            this->label92->Text = L"Is it an Elective\?";
            // 
            // panel10
            // 
            this->panel10->BackColor = System::Drawing::Color::White;
            this->panel10->Controls->Add(this->editsubeleyes);
            this->panel10->Controls->Add(this->editsubeleno);
            this->panel10->ForeColor = System::Drawing::Color::Black;
            this->panel10->Location = System::Drawing::Point(162, 90);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(492, 60);
            this->panel10->TabIndex = 267;
            this->panel10->Enter += gcnew System::EventHandler(this, &MyForm::panel10_Enter);
            // 
            // editsubeleyes
            // 
            this->editsubeleyes->Location = System::Drawing::Point(16, 14);
            this->editsubeleyes->Name = L"editsubeleyes";
            this->editsubeleyes->Size = System::Drawing::Size(58, 32);
            this->editsubeleyes->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->editsubeleyes->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->editsubeleyes->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editsubeleyes->TabIndex = 328;
            this->editsubeleyes->Values->Text = L"YES";
            this->editsubeleyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsubeleyes_CheckedChanged_1);
            // 
            // editsubeleno
            // 
            this->editsubeleno->Location = System::Drawing::Point(230, 14);
            this->editsubeleno->Name = L"editsubeleno";
            this->editsubeleno->Size = System::Drawing::Size(56, 32);
            this->editsubeleno->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->editsubeleno->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->editsubeleno->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editsubeleno->TabIndex = 330;
            this->editsubeleno->Values->Text = L"NO";
            this->editsubeleno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsubeleno_CheckedChanged_1);
            // 
            // editsubnamegroup
            // 
            this->editsubnamegroup->CaptionOverlap = 1;
            this->editsubnamegroup->CaptionVisible = false;
            this->editsubnamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubnamegroup->Location = System::Drawing::Point(23, 458);
            this->editsubnamegroup->Name = L"editsubnamegroup";
            // 
            // editsubnamegroup.Panel
            // 
            this->editsubnamegroup->Panel->Controls->Add(this->kryptonPanel3);
            this->editsubnamegroup->Panel->Controls->Add(this->label93);
            this->editsubnamegroup->Panel->Controls->Add(this->editsubname);
            this->editsubnamegroup->Size = System::Drawing::Size(1127, 194);
            this->editsubnamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubnamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubnamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubnamegroup->StateCommon->Border->ColorAngle = 50;
            this->editsubnamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubnamegroup->StateCommon->Border->Rounding = 9;
            this->editsubnamegroup->StateCommon->Border->Width = 1;
            this->editsubnamegroup->TabIndex = 337;
            // 
            // kryptonPanel3
            // 
            this->kryptonPanel3->Location = System::Drawing::Point(97, 119);
            this->kryptonPanel3->Name = L"kryptonPanel3";
            this->kryptonPanel3->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel3->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel3->TabIndex = 326;
            // 
            // label93
            // 
            this->label93->AutoSize = true;
            this->label93->BackColor = System::Drawing::Color::White;
            this->label93->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label93->ForeColor = System::Drawing::Color::Black;
            this->label93->Location = System::Drawing::Point(93, 30);
            this->label93->Name = L"label93";
            this->label93->Size = System::Drawing::Size(139, 28);
            this->label93->TabIndex = 264;
            this->label93->Text = L"Subject Name";
            // 
            // editsubname
            // 
            this->editsubname->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editsubname->Location = System::Drawing::Point(105, 75);
            this->editsubname->Name = L"editsubname";
            this->editsubname->Size = System::Drawing::Size(478, 44);
            this->editsubname->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editsubname->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubname->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubname->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editsubname->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editsubname->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editsubname->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubname->StateCommon->Border->Rounding = 10;
            this->editsubname->StateCommon->Border->Width = 3;
            this->editsubname->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editsubname->TabIndex = 325;
            this->editsubname->Enter += gcnew System::EventHandler(this, &MyForm::editsubname_Enter);
            this->editsubname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editsubcodegroup
            // 
            this->editsubcodegroup->CaptionOverlap = 1;
            this->editsubcodegroup->CaptionVisible = false;
            this->editsubcodegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editsubcodegroup->Location = System::Drawing::Point(23, 906);
            this->editsubcodegroup->Name = L"editsubcodegroup";
            // 
            // editsubcodegroup.Panel
            // 
            this->editsubcodegroup->Panel->Controls->Add(this->kryptonPanel4);
            this->editsubcodegroup->Panel->Controls->Add(this->label15);
            this->editsubcodegroup->Panel->Controls->Add(this->editsubcode);
            this->editsubcodegroup->Size = System::Drawing::Size(1127, 194);
            this->editsubcodegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editsubcodegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editsubcodegroup->StateCommon->Border->ColorAngle = 50;
            this->editsubcodegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubcodegroup->StateCommon->Border->Rounding = 7;
            this->editsubcodegroup->StateCommon->Border->Width = 1;
            this->editsubcodegroup->TabIndex = 336;
            // 
            // kryptonPanel4
            // 
            this->kryptonPanel4->Location = System::Drawing::Point(99, 137);
            this->kryptonPanel4->Name = L"kryptonPanel4";
            this->kryptonPanel4->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel4->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel4->TabIndex = 329;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->BackColor = System::Drawing::Color::White;
            this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label15->ForeColor = System::Drawing::Color::Black;
            this->label15->Location = System::Drawing::Point(93, 46);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(132, 28);
            this->label15->TabIndex = 327;
            this->label15->Text = L"Subject Code";
            // 
            // editsubcode
            // 
            this->editsubcode->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editsubcode->Location = System::Drawing::Point(98, 92);
            this->editsubcode->Name = L"editsubcode";
            this->editsubcode->Size = System::Drawing::Size(478, 44);
            this->editsubcode->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editsubcode->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubcode->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubcode->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editsubcode->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editsubcode->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editsubcode->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editsubcode->StateCommon->Border->Rounding = 10;
            this->editsubcode->StateCommon->Border->Width = 3;
            this->editsubcode->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editsubcode->TabIndex = 328;
            this->editsubcode->Enter += gcnew System::EventHandler(this, &MyForm::editsubcode_Enter);
            this->editsubcode->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editsubjectpanel
            // 
            this->editsubjectpanel->AutoScroll = true;
            this->editsubjectpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjectpanel->Controls->Add(this->panel13);
            this->editsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editsubjectpanel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->editsubjectpanel->Name = L"editsubjectpanel";
            this->editsubjectpanel->Size = System::Drawing::Size(1924, 1050);
            this->editsubjectpanel->TabIndex = 259;
            this->editsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editsubjectpanel_Paint);
            // 
            // timer2
            // 
            this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
            // 
            // panel6
            // 
            this->panel6->Controls->Add(this->editroomsearchgroup);
            this->panel6->Controls->Add(this->kryptonGroupBox10);
            this->panel6->Controls->Add(this->panel14);
            this->panel6->Controls->Add(this->editroomdepartmentgroup);
            this->panel6->Controls->Add(this->kryptonLabel6);
            this->panel6->Controls->Add(this->editroomcapacitygroup);
            this->panel6->Controls->Add(this->editroomlabgroup);
            this->panel6->Controls->Add(this->editroomnamegroup);
            this->panel6->Location = System::Drawing::Point(179, 13);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(1194, 2451);
            this->panel6->TabIndex = 343;
            // 
            // editroomsearchgroup
            // 
            this->editroomsearchgroup->CaptionOverlap = 1;
            this->editroomsearchgroup->CaptionVisible = false;
            this->editroomsearchgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editroomsearchgroup->Location = System::Drawing::Point(23, 168);
            this->editroomsearchgroup->Name = L"editroomsearchgroup";
            // 
            // editroomsearchgroup.Panel
            // 
            this->editroomsearchgroup->Panel->Controls->Add(this->label242);
            this->editroomsearchgroup->Panel->Controls->Add(this->editroomsearchbutton);
            this->editroomsearchgroup->Panel->Controls->Add(this->editroomsearch);
            this->editroomsearchgroup->Size = System::Drawing::Size(1127, 260);
            this->editroomsearchgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editroomsearchgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomsearchgroup->StateCommon->Border->ColorAngle = 50;
            this->editroomsearchgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomsearchgroup->StateCommon->Border->Rounding = 10;
            this->editroomsearchgroup->StateCommon->Border->Width = 1;
            this->editroomsearchgroup->TabIndex = 347;
            // 
            // label242
            // 
            this->label242->AutoSize = true;
            this->label242->BackColor = System::Drawing::Color::White;
            this->label242->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label242->ForeColor = System::Drawing::Color::Black;
            this->label242->Location = System::Drawing::Point(372, 68);
            this->label242->Name = L"label242";
            this->label242->Size = System::Drawing::Size(268, 28);
            this->label242->TabIndex = 264;
            this->label242->Text = L"Search the Classroom Name";
            // 
            // editroomsearchbutton
            // 
            this->editroomsearchbutton->BackColor = System::Drawing::Color::White;
            this->editroomsearchbutton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editroomsearchbutton.BackgroundImage")));
            this->editroomsearchbutton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->editroomsearchbutton->FlatAppearance->BorderSize = 0;
            this->editroomsearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editroomsearchbutton->Location = System::Drawing::Point(767, 126);
            this->editroomsearchbutton->Name = L"editroomsearchbutton";
            this->editroomsearchbutton->Size = System::Drawing::Size(28, 28);
            this->editroomsearchbutton->TabIndex = 292;
            this->editroomsearchbutton->UseVisualStyleBackColor = false;
            this->editroomsearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editroomsearchbutton_Click);
            // 
            // editroomsearch
            // 
            this->editroomsearch->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->editroomsearch->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->editroomsearch->DropBackStyle = ComponentFactory::Krypton::Toolkit::PaletteBackStyle::GridBackgroundSheet;
            this->editroomsearch->DropButtonStyle = ComponentFactory::Krypton::Toolkit::ButtonStyle::ListItem;
            this->editroomsearch->DropDownWidth = 356;
            this->editroomsearch->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editroomsearch->Location = System::Drawing::Point(236, 122);
            this->editroomsearch->Name = L"editroomsearch";
            this->editroomsearch->Size = System::Drawing::Size(563, 34);
            this->editroomsearch->StateCommon->ComboBox->Back->Color1 = System::Drawing::Color::White;
            this->editroomsearch->StateCommon->ComboBox->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomsearch->StateCommon->ComboBox->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomsearch->StateCommon->ComboBox->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Linear;
            this->editroomsearch->StateCommon->ComboBox->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomsearch->StateCommon->ComboBox->Border->Rounding = 5;
            this->editroomsearch->StateCommon->ComboBox->Border->Width = 2;
            this->editroomsearch->StateCommon->ComboBox->Content->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editroomsearch->StateCommon->ComboBox->Content->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
            this->editroomsearch->StateCommon->DropBack->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomsearch->StateCommon->Item->Content->ShortText->Color1 = System::Drawing::Color::DimGray;
            this->editroomsearch->StateCommon->Item->Content->ShortText->Color2 = System::Drawing::Color::DimGray;
            this->editroomsearch->StateCommon->Item->Content->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editroomsearch->TabIndex = 323;
            this->editroomsearch->Enter += gcnew System::EventHandler(this, &MyForm::editroomsearch_Enter);
            this->editroomsearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocusRoom);
            this->editroomsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownRoom);
            this->editroomsearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            this->editroomsearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocusRoom);
            // 
            // kryptonGroupBox10
            // 
            this->kryptonGroupBox10->CaptionOverlap = 1;
            this->kryptonGroupBox10->CaptionVisible = false;
            this->kryptonGroupBox10->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->kryptonGroupBox10->Location = System::Drawing::Point(23, 1519);
            this->kryptonGroupBox10->Name = L"kryptonGroupBox10";
            // 
            // kryptonGroupBox10.Panel
            // 
            this->kryptonGroupBox10->Panel->Controls->Add(this->panel15);
            this->kryptonGroupBox10->Panel->Controls->Add(this->panel33);
            this->kryptonGroupBox10->Panel->Controls->Add(this->editroomtablepanel);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label114);
            this->kryptonGroupBox10->Panel->Controls->Add(this->panel34);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label4);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label78);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label79);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label80);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label81);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label103);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label104);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label105);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label106);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label107);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label108);
            this->kryptonGroupBox10->Panel->Controls->Add(this->label113);
            this->kryptonGroupBox10->Panel->Enter += gcnew System::EventHandler(this, &MyForm::kryptonGroupBox10_Panel_Enter);
            this->kryptonGroupBox10->Size = System::Drawing::Size(1127, 642);
            this->kryptonGroupBox10->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->kryptonGroupBox10->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->kryptonGroupBox10->StateCommon->Border->ColorAngle = 50;
            this->kryptonGroupBox10->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->kryptonGroupBox10->StateCommon->Border->Rounding = 7;
            this->kryptonGroupBox10->StateCommon->Border->Width = 1;
            this->kryptonGroupBox10->TabIndex = 346;
            // 
            // panel15
            // 
            this->panel15->BackColor = System::Drawing::Color::White;
            this->panel15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel15.BackgroundImage")));
            this->panel15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel15->Location = System::Drawing::Point(760, 141);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(44, 420);
            this->panel15->TabIndex = 1;
            // 
            // panel33
            // 
            this->panel33->BackColor = System::Drawing::Color::White;
            this->panel33->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel33.BackgroundImage")));
            this->panel33->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel33->Location = System::Drawing::Point(425, 141);
            this->panel33->Name = L"panel33";
            this->panel33->Size = System::Drawing::Size(44, 430);
            this->panel33->TabIndex = 300;
            // 
            // editroomtablepanel
            // 
            this->editroomtablepanel->BackColor = System::Drawing::Color::White;
            this->editroomtablepanel->ColumnCount = 8;
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->editroomtablepanel->Location = System::Drawing::Point(138, 141);
            this->editroomtablepanel->Name = L"editroomtablepanel";
            this->editroomtablepanel->RowCount = 6;
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->Size = System::Drawing::Size(950, 431);
            this->editroomtablepanel->TabIndex = 260;
            // 
            // label114
            // 
            this->label114->AutoSize = true;
            this->label114->BackColor = System::Drawing::Color::White;
            this->label114->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label114->Location = System::Drawing::Point(81, 36);
            this->label114->Name = L"label114";
            this->label114->Size = System::Drawing::Size(154, 28);
            this->label114->TabIndex = 344;
            this->label114->Text = L"Room Schedule";
            // 
            // panel34
            // 
            this->panel34->BackColor = System::Drawing::Color::White;
            this->panel34->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel34.BackgroundImage")));
            this->panel34->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel34->Location = System::Drawing::Point(414, 141);
            this->panel34->Name = L"panel34";
            this->panel34->Size = System::Drawing::Size(82, 412);
            this->panel34->TabIndex = 2;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::White;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(38, 161);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(85, 28);
            this->label4->TabIndex = 261;
            this->label4->Text = L"Monday";
            // 
            // label78
            // 
            this->label78->AutoSize = true;
            this->label78->BackColor = System::Drawing::Color::White;
            this->label78->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label78->Location = System::Drawing::Point(44, 230);
            this->label78->Name = L"label78";
            this->label78->Size = System::Drawing::Size(83, 28);
            this->label78->TabIndex = 262;
            this->label78->Text = L"Tuesday";
            // 
            // label79
            // 
            this->label79->AutoSize = true;
            this->label79->BackColor = System::Drawing::Color::White;
            this->label79->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label79->Location = System::Drawing::Point(156, 101);
            this->label79->Name = L"label79";
            this->label79->Size = System::Drawing::Size(105, 28);
            this->label79->TabIndex = 294;
            this->label79->Text = L"9:00-10:00";
            // 
            // label80
            // 
            this->label80->AutoSize = true;
            this->label80->BackColor = System::Drawing::Color::White;
            this->label80->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label80->Location = System::Drawing::Point(28, 307);
            this->label80->Name = L"label80";
            this->label80->Size = System::Drawing::Size(113, 28);
            this->label80->TabIndex = 263;
            this->label80->Text = L"Wednesday";
            // 
            // label81
            // 
            this->label81->AutoSize = true;
            this->label81->BackColor = System::Drawing::Color::White;
            this->label81->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label81->Location = System::Drawing::Point(292, 101);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(116, 28);
            this->label81->TabIndex = 295;
            this->label81->Text = L"10:00-11:00";
            // 
            // label103
            // 
            this->label103->AutoSize = true;
            this->label103->BackColor = System::Drawing::Color::White;
            this->label103->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label103->Location = System::Drawing::Point(28, 371);
            this->label103->Name = L"label103";
            this->label103->Size = System::Drawing::Size(91, 28);
            this->label103->TabIndex = 264;
            this->label103->Text = L"Thursday";
            // 
            // label104
            // 
            this->label104->AutoSize = true;
            this->label104->BackColor = System::Drawing::Color::White;
            this->label104->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label104->Location = System::Drawing::Point(478, 101);
            this->label104->Name = L"label104";
            this->label104->Size = System::Drawing::Size(116, 28);
            this->label104->TabIndex = 296;
            this->label104->Text = L"11:30-12:30";
            // 
            // label105
            // 
            this->label105->AutoSize = true;
            this->label105->BackColor = System::Drawing::Color::White;
            this->label105->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label105->Location = System::Drawing::Point(42, 447);
            this->label105->Name = L"label105";
            this->label105->Size = System::Drawing::Size(66, 28);
            this->label105->TabIndex = 265;
            this->label105->Text = L"Friday";
            // 
            // label106
            // 
            this->label106->AutoSize = true;
            this->label106->BackColor = System::Drawing::Color::White;
            this->label106->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label106->Location = System::Drawing::Point(632, 101);
            this->label106->Name = L"label106";
            this->label106->Size = System::Drawing::Size(105, 28);
            this->label106->TabIndex = 297;
            this->label106->Text = L"12:30-1:30";
            // 
            // label107
            // 
            this->label107->AutoSize = true;
            this->label107->BackColor = System::Drawing::Color::White;
            this->label107->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label107->Location = System::Drawing::Point(42, 524);
            this->label107->Name = L"label107";
            this->label107->Size = System::Drawing::Size(90, 28);
            this->label107->TabIndex = 266;
            this->label107->Text = L"Saturday";
            // 
            // label108
            // 
            this->label108->AutoSize = true;
            this->label108->BackColor = System::Drawing::Color::White;
            this->label108->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label108->Location = System::Drawing::Point(826, 97);
            this->label108->Name = L"label108";
            this->label108->Size = System::Drawing::Size(94, 28);
            this->label108->TabIndex = 298;
            this->label108->Text = L"2:30-3:30";
            // 
            // label113
            // 
            this->label113->AutoSize = true;
            this->label113->BackColor = System::Drawing::Color::White;
            this->label113->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label113->Location = System::Drawing::Point(956, 97);
            this->label113->Name = L"label113";
            this->label113->Size = System::Drawing::Size(94, 28);
            this->label113->TabIndex = 299;
            this->label113->Text = L"3:30-4:30";
            // 
            // panel14
            // 
            this->panel14->Controls->Add(this->editroomdelete);
            this->panel14->Controls->Add(this->editroomsave);
            this->panel14->Location = System::Drawing::Point(675, 2192);
            this->panel14->Name = L"panel14";
            this->panel14->Size = System::Drawing::Size(502, 137);
            this->panel14->TabIndex = 295;
            // 
            // editroomdelete
            // 
            this->editroomdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomdelete->Location = System::Drawing::Point(303, 38);
            this->editroomdelete->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomdelete->Name = L"editroomdelete";
            this->editroomdelete->Size = System::Drawing::Size(154, 58);
            this->editroomdelete->TabIndex = 180;
            this->editroomdelete->Text = L"Delete";
            this->editroomdelete->UseVisualStyleBackColor = false;
            this->editroomdelete->Click += gcnew System::EventHandler(this, &MyForm::editroomdelete_Click);
            // 
            // editroomsave
            // 
            this->editroomsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomsave->Location = System::Drawing::Point(53, 39);
            this->editroomsave->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomsave->Name = L"editroomsave";
            this->editroomsave->Size = System::Drawing::Size(154, 58);
            this->editroomsave->TabIndex = 124;
            this->editroomsave->Text = L"Save";
            this->editroomsave->UseVisualStyleBackColor = false;
            this->editroomsave->Click += gcnew System::EventHandler(this, &MyForm::editroomsave_Click);
            // 
            // editroomdepartmentgroup
            // 
            this->editroomdepartmentgroup->CaptionOverlap = 1;
            this->editroomdepartmentgroup->CaptionVisible = false;
            this->editroomdepartmentgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editroomdepartmentgroup->Location = System::Drawing::Point(23, 1210);
            this->editroomdepartmentgroup->Name = L"editroomdepartmentgroup";
            // 
            // editroomdepartmentgroup.Panel
            // 
            this->editroomdepartmentgroup->Panel->Controls->Add(this->label115);
            this->editroomdepartmentgroup->Panel->Controls->Add(this->editroomdepartment);
            this->editroomdepartmentgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editroomdepartmentgroup_Panel_Enter);
            this->editroomdepartmentgroup->Size = System::Drawing::Size(1127, 194);
            this->editroomdepartmentgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editroomdepartmentgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomdepartmentgroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editroomdepartmentgroup->StateCommon->Border->ColorAngle = 50;
            this->editroomdepartmentgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomdepartmentgroup->StateCommon->Border->Rounding = 7;
            this->editroomdepartmentgroup->StateCommon->Border->Width = 1;
            this->editroomdepartmentgroup->TabIndex = 342;
            // 
            // label115
            // 
            this->label115->AutoSize = true;
            this->label115->BackColor = System::Drawing::Color::White;
            this->label115->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label115->Location = System::Drawing::Point(94, 41);
            this->label115->Name = L"label115";
            this->label115->Size = System::Drawing::Size(122, 28);
            this->label115->TabIndex = 343;
            this->label115->Text = L"Department";
            // 
            // editroomdepartment
            // 
            this->editroomdepartment->DropDownWidth = 342;
            this->editroomdepartment->Location = System::Drawing::Point(87, 95);
            this->editroomdepartment->Name = L"editroomdepartment";
            this->editroomdepartment->Size = System::Drawing::Size(563, 29);
            this->editroomdepartment->StateCommon->DropBack->Color1 = System::Drawing::Color::Cyan;
            this->editroomdepartment->StateCommon->DropBack->Color2 = System::Drawing::Color::Cyan;
            this->editroomdepartment->TabIndex = 344;
            // 
            // kryptonLabel6
            // 
            this->kryptonLabel6->Location = System::Drawing::Point(456, 49);
            this->kryptonLabel6->Name = L"kryptonLabel6";
            this->kryptonLabel6->Size = System::Drawing::Size(264, 43);
            this->kryptonLabel6->StateCommon->ShortText->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->kryptonLabel6->StateCommon->ShortText->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::Dashed;
            this->kryptonLabel6->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->kryptonLabel6->TabIndex = 2;
            this->kryptonLabel6->Values->Text = L"ClassRoom Details";
            // 
            // editroomcapacitygroup
            // 
            this->editroomcapacitygroup->CaptionOverlap = 1;
            this->editroomcapacitygroup->CaptionVisible = false;
            this->editroomcapacitygroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editroomcapacitygroup->Location = System::Drawing::Point(23, 728);
            this->editroomcapacitygroup->Name = L"editroomcapacitygroup";
            // 
            // editroomcapacitygroup.Panel
            // 
            this->editroomcapacitygroup->Panel->Controls->Add(this->editroomcapacity);
            this->editroomcapacitygroup->Panel->Controls->Add(this->label116);
            this->editroomcapacitygroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editroomcapacitygroup_Panel_Enter);
            this->editroomcapacitygroup->Size = System::Drawing::Size(1127, 194);
            this->editroomcapacitygroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editroomcapacitygroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomcapacitygroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->editroomcapacitygroup->StateCommon->Border->ColorAngle = 50;
            this->editroomcapacitygroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomcapacitygroup->StateCommon->Border->Rounding = 7;
            this->editroomcapacitygroup->StateCommon->Border->Width = 1;
            this->editroomcapacitygroup->TabIndex = 341;
            // 
            // editroomcapacity
            // 
            this->editroomcapacity->Location = System::Drawing::Point(98, 96);
            this->editroomcapacity->Name = L"editroomcapacity";
            this->editroomcapacity->Size = System::Drawing::Size(304, 30);
            this->editroomcapacity->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomcapacity->TabIndex = 328;
            // 
            // label116
            // 
            this->label116->AutoSize = true;
            this->label116->BackColor = System::Drawing::Color::White;
            this->label116->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label116->ForeColor = System::Drawing::Color::Black;
            this->label116->Location = System::Drawing::Point(94, 39);
            this->label116->Name = L"label116";
            this->label116->Size = System::Drawing::Size(146, 28);
            this->label116->TabIndex = 327;
            this->label116->Text = L"Room Capacity";
            // 
            // editroomlabgroup
            // 
            this->editroomlabgroup->CaptionOverlap = 1;
            this->editroomlabgroup->CaptionVisible = false;
            this->editroomlabgroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editroomlabgroup->Location = System::Drawing::Point(23, 968);
            this->editroomlabgroup->Name = L"editroomlabgroup";
            // 
            // editroomlabgroup.Panel
            // 
            this->editroomlabgroup->Panel->Controls->Add(this->label117);
            this->editroomlabgroup->Panel->Controls->Add(this->panel45);
            this->editroomlabgroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editroomlabgroup_Panel_Enter);
            this->editroomlabgroup->Size = System::Drawing::Size(1127, 194);
            this->editroomlabgroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editroomlabgroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomlabgroup->StateCommon->Border->ColorAngle = 50;
            this->editroomlabgroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomlabgroup->StateCommon->Border->Rounding = 7;
            this->editroomlabgroup->StateCommon->Border->Width = 1;
            this->editroomlabgroup->TabIndex = 339;
            // 
            // label117
            // 
            this->label117->AutoSize = true;
            this->label117->BackColor = System::Drawing::Color::White;
            this->label117->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label117->Location = System::Drawing::Point(95, 44);
            this->label117->Name = L"label117";
            this->label117->Size = System::Drawing::Size(108, 28);
            this->label117->TabIndex = 266;
            this->label117->Text = L"Is it a Lab\?";
            // 
            // panel45
            // 
            this->panel45->BackColor = System::Drawing::Color::White;
            this->panel45->Controls->Add(this->editroomlabyes);
            this->panel45->Controls->Add(this->editroomlabno);
            this->panel45->ForeColor = System::Drawing::Color::Black;
            this->panel45->Location = System::Drawing::Point(162, 90);
            this->panel45->Name = L"panel45";
            this->panel45->Size = System::Drawing::Size(492, 60);
            this->panel45->TabIndex = 267;
            // 
            // editroomlabyes
            // 
            this->editroomlabyes->Location = System::Drawing::Point(16, 14);
            this->editroomlabyes->Name = L"editroomlabyes";
            this->editroomlabyes->Size = System::Drawing::Size(58, 32);
            this->editroomlabyes->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->editroomlabyes->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->editroomlabyes->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editroomlabyes->TabIndex = 328;
            this->editroomlabyes->Values->Text = L"YES";
            // 
            // editroomlabno
            // 
            this->editroomlabno->Location = System::Drawing::Point(230, 14);
            this->editroomlabno->Name = L"editroomlabno";
            this->editroomlabno->Size = System::Drawing::Size(56, 32);
            this->editroomlabno->StateCommon->ShortText->Color1 = System::Drawing::Color::Black;
            this->editroomlabno->StateCommon->ShortText->Color2 = System::Drawing::Color::Black;
            this->editroomlabno->StateCommon->ShortText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->editroomlabno->TabIndex = 330;
            this->editroomlabno->Values->Text = L"NO";
            // 
            // editroomnamegroup
            // 
            this->editroomnamegroup->CaptionOverlap = 1;
            this->editroomnamegroup->CaptionVisible = false;
            this->editroomnamegroup->GroupBorderStyle = ComponentFactory::Krypton::Toolkit::PaletteBorderStyle::ButtonCustom2;
            this->editroomnamegroup->Location = System::Drawing::Point(23, 475);
            this->editroomnamegroup->Name = L"editroomnamegroup";
            // 
            // editroomnamegroup.Panel
            // 
            this->editroomnamegroup->Panel->Controls->Add(this->kryptonPanel11);
            this->editroomnamegroup->Panel->Controls->Add(this->label118);
            this->editroomnamegroup->Panel->Controls->Add(this->editroomname);
            this->editroomnamegroup->Panel->Enter += gcnew System::EventHandler(this, &MyForm::editroomnamegroup_Panel_Enter);
            this->editroomnamegroup->Size = System::Drawing::Size(1127, 194);
            this->editroomnamegroup->StateCommon->Back->Color1 = System::Drawing::Color::White;
            this->editroomnamegroup->StateCommon->Border->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomnamegroup->StateCommon->Border->Color2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->editroomnamegroup->StateCommon->Border->ColorAngle = 50;
            this->editroomnamegroup->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomnamegroup->StateCommon->Border->Rounding = 9;
            this->editroomnamegroup->StateCommon->Border->Width = 1;
            this->editroomnamegroup->TabIndex = 337;
            // 
            // kryptonPanel11
            // 
            this->kryptonPanel11->Location = System::Drawing::Point(91, 121);
            this->kryptonPanel11->Name = L"kryptonPanel11";
            this->kryptonPanel11->Size = System::Drawing::Size(508, 2);
            this->kryptonPanel11->StateCommon->Color1 = System::Drawing::Color::Cyan;
            this->kryptonPanel11->TabIndex = 326;
            // 
            // label118
            // 
            this->label118->AutoSize = true;
            this->label118->BackColor = System::Drawing::Color::White;
            this->label118->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label118->ForeColor = System::Drawing::Color::Black;
            this->label118->Location = System::Drawing::Point(93, 30);
            this->label118->Name = L"label118";
            this->label118->Size = System::Drawing::Size(255, 28);
            this->label118->TabIndex = 264;
            this->label118->Text = L"Enter the Classroom Name";
            // 
            // editroomname
            // 
            this->editroomname->InputControlStyle = ComponentFactory::Krypton::Toolkit::InputControlStyle::Ribbon;
            this->editroomname->Location = System::Drawing::Point(97, 79);
            this->editroomname->Name = L"editroomname";
            this->editroomname->Size = System::Drawing::Size(478, 44);
            this->editroomname->StateActive->Back->Color1 = System::Drawing::Color::White;
            this->editroomname->StateActive->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomname->StateCommon->Back->Color1 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editroomname->StateCommon->Border->Color1 = System::Drawing::Color::White;
            this->editroomname->StateCommon->Border->Color2 = System::Drawing::Color::White;
            this->editroomname->StateCommon->Border->ColorStyle = ComponentFactory::Krypton::Toolkit::PaletteColorStyle::GlassFade;
            this->editroomname->StateCommon->Border->DrawBorders = static_cast<ComponentFactory::Krypton::Toolkit::PaletteDrawBorders>((((ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Top | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Bottom)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Left)
                | ComponentFactory::Krypton::Toolkit::PaletteDrawBorders::Right));
            this->editroomname->StateCommon->Border->Rounding = 10;
            this->editroomname->StateCommon->Border->Width = 3;
            this->editroomname->StateCommon->Content->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->editroomname->TabIndex = 325;
            this->editroomname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            // 
            // editroompanel
            // 
            this->editroompanel->AutoScroll = true;
            this->editroompanel->Controls->Add(this->panel6);
            this->editroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editroompanel->Location = System::Drawing::Point(0, 0);
            this->editroompanel->Name = L"editroompanel";
            this->editroompanel->Size = System::Drawing::Size(1924, 1050);
            this->editroompanel->TabIndex = 124;
            this->editroompanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editroompanel_Paint);
            // 
            // timer3
            // 
            this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
            // 
            // timer4
            // 
            this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
            // 
            // timer5
            // 
            this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
            // 
            // timer6
            // 
            this->timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
            // 
            // timer13
            // 
            this->timer13->Interval = 50;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(1924, 1050);
            this->Controls->Add(this->classpanel);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->kryptonPanel6);
            this->Controls->Add(this->editsubactivepanel);
            this->Controls->Add(this->deleteclasspanel);
            this->Controls->Add(this->editteacherpanel);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->settingspanel);
            this->Controls->Add(this->addteacherpanel);
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->editroompanel);
            this->Controls->Add(this->editsubjectpanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->Homepanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->KeyPreview = true;
            this->Name = L"MyForm";
            this->Text = L"TimeTable Architect";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->addsubjectpanel->ResumeLayout(false);
            this->panel11->ResumeLayout(false);
            this->panel11->PerformLayout();
            this->panel48->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactorgroup->Panel))->EndInit();
            this->addsubbfactorgroup->Panel->ResumeLayout(false);
            this->addsubbfactorgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactorgroup))->EndInit();
            this->addsubbfactorgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubroomlistgroup->Panel))->EndInit();
            this->addsubroomlistgroup->Panel->ResumeLayout(false);
            this->addsubroomlistgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubroomlistgroup))->EndInit();
            this->addsubroomlistgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubeleyesgroup->Panel))->EndInit();
            this->addsubeleyesgroup->Panel->ResumeLayout(false);
            this->addsubeleyesgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubeleyesgroup))->EndInit();
            this->addsubeleyesgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcluster))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcreditsgroup->Panel))->EndInit();
            this->addsubcreditsgroup->Panel->ResumeLayout(false);
            this->addsubcreditsgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcreditsgroup))->EndInit();
            this->addsubcreditsgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubtitlegroup->Panel))->EndInit();
            this->addsubtitlegroup->Panel->ResumeLayout(false);
            this->addsubtitlegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubtitlegroup))->EndInit();
            this->addsubtitlegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubelegroup->Panel))->EndInit();
            this->addsubelegroup->Panel->ResumeLayout(false);
            this->addsubelegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubelegroup))->EndInit();
            this->addsubelegroup->ResumeLayout(false);
            this->panel42->ResumeLayout(false);
            this->panel42->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubnamegroup->Panel))->EndInit();
            this->addsubnamegroup->Panel->ResumeLayout(false);
            this->addsubnamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubnamegroup))->EndInit();
            this->addsubnamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcodegroup->Panel))->EndInit();
            this->addsubcodegroup->Panel->ResumeLayout(false);
            this->addsubcodegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcodegroup))->EndInit();
            this->addsubcodegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel7))->EndInit();
            this->addclassroompanel->ResumeLayout(false);
            this->panel7->ResumeLayout(false);
            this->panel7->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox9->Panel))->EndInit();
            this->kryptonGroupBox9->Panel->ResumeLayout(false);
            this->kryptonGroupBox9->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox9))->EndInit();
            this->kryptonGroupBox9->ResumeLayout(false);
            this->panel9->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdeptgroup->Panel))->EndInit();
            this->roomdeptgroup->Panel->ResumeLayout(false);
            this->roomdeptgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdeptgroup))->EndInit();
            this->roomdeptgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomdept))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacitygroup->Panel))->EndInit();
            this->roomcapacitygroup->Panel->ResumeLayout(false);
            this->roomcapacitygroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacitygroup))->EndInit();
            this->roomcapacitygroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomlabgroup->Panel))->EndInit();
            this->roomlabgroup->Panel->ResumeLayout(false);
            this->roomlabgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomlabgroup))->EndInit();
            this->roomlabgroup->ResumeLayout(false);
            this->panel44->ResumeLayout(false);
            this->panel44->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomnamegroup->Panel))->EndInit();
            this->roomnamegroup->Panel->ResumeLayout(false);
            this->roomnamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomnamegroup))->EndInit();
            this->roomnamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel12))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->editteacherpanel->ResumeLayout(false);
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacheremailidgroup->Panel))->EndInit();
            this->editteacheremailidgroup->Panel->ResumeLayout(false);
            this->editteacheremailidgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacheremailidgroup))->EndInit();
            this->editteacheremailidgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel9))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachersearchgroup->Panel))->EndInit();
            this->editteachersearchgroup->Panel->ResumeLayout(false);
            this->editteachersearchgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachersearchgroup))->EndInit();
            this->editteachersearchgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->teachersearch))->EndInit();
            this->panel18->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachertablegroup->Panel))->EndInit();
            this->editteachertablegroup->Panel->ResumeLayout(false);
            this->editteachertablegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachertablegroup))->EndInit();
            this->editteachertablegroup->ResumeLayout(false);
            this->panel28->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartmentgroup->Panel))->EndInit();
            this->editteacherdepartmentgroup->Panel->ResumeLayout(false);
            this->editteacherdepartmentgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartmentgroup))->EndInit();
            this->editteacherdepartmentgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteacherdepartment))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachernamegroup->Panel))->EndInit();
            this->editteachernamegroup->Panel->ResumeLayout(false);
            this->editteachernamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editteachernamegroup))->EndInit();
            this->editteachernamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel8))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel6))->EndInit();
            this->kryptonPanel6->ResumeLayout(false);
            this->kryptonPanel6->PerformLayout();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
            this->settingspanel->ResumeLayout(false);
            this->settingspanel->PerformLayout();
            this->panel36->ResumeLayout(false);
            this->panel36->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox5->Panel))->EndInit();
            this->kryptonGroupBox5->Panel->ResumeLayout(false);
            this->kryptonGroupBox5->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox5))->EndInit();
            this->kryptonGroupBox5->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox3->Panel))->EndInit();
            this->kryptonGroupBox3->Panel->ResumeLayout(false);
            this->kryptonGroupBox3->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox3))->EndInit();
            this->kryptonGroupBox3->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox4->Panel))->EndInit();
            this->kryptonGroupBox4->Panel->ResumeLayout(false);
            this->kryptonGroupBox4->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox4))->EndInit();
            this->kryptonGroupBox4->ResumeLayout(false);
            this->panel59->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox6->Panel))->EndInit();
            this->kryptonGroupBox6->Panel->ResumeLayout(false);
            this->kryptonGroupBox6->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox6))->EndInit();
            this->kryptonGroupBox6->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            this->panel1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            this->classpanel->ResumeLayout(false);
            this->panel29->ResumeLayout(false);
            this->panel29->PerformLayout();
            this->panel27->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classgengroup->Panel))->EndInit();
            this->classgengroup->Panel->ResumeLayout(false);
            this->classgengroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classgengroup))->EndInit();
            this->classgengroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classroomgroup->Panel))->EndInit();
            this->classroomgroup->Panel->ResumeLayout(false);
            this->classroomgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classroomgroup))->EndInit();
            this->classroomgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classresgroup->Panel))->EndInit();
            this->classresgroup->Panel->ResumeLayout(false);
            this->classresgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classresgroup))->EndInit();
            this->classresgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabgroup->Panel))->EndInit();
            this->classlabgroup->Panel->ResumeLayout(false);
            this->classlabgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabgroup))->EndInit();
            this->classlabgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlab))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel14))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlabteachers))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classelegroup->Panel))->EndInit();
            this->classelegroup->Panel->ResumeLayout(false);
            this->classelegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classelegroup))->EndInit();
            this->classelegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classele))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcoregroup->Panel))->EndInit();
            this->classcoregroup->Panel->ResumeLayout(false);
            this->classcoregroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcoregroup))->EndInit();
            this->classcoregroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcore))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbatchgroup->Panel))->EndInit();
            this->classbatchgroup->Panel->ResumeLayout(false);
            this->classbatchgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbatchgroup))->EndInit();
            this->classbatchgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranchgroup->Panel))->EndInit();
            this->classbranchgroup->Panel->ResumeLayout(false);
            this->classbranchgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranchgroup))->EndInit();
            this->classbranchgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classbranch))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classnamegroup->Panel))->EndInit();
            this->classnamegroup->Panel->ResumeLayout(false);
            this->classnamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classnamegroup))->EndInit();
            this->classnamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel15))->EndInit();
            this->addteacherpanel->ResumeLayout(false);
            this->panel16->ResumeLayout(false);
            this->panel16->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacheremailidgroup->Panel))->EndInit();
            this->addteacheremailidgroup->Panel->ResumeLayout(false);
            this->addteacheremailidgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacheremailidgroup))->EndInit();
            this->addteacheremailidgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel10))->EndInit();
            this->panel17->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachertablegroup->Panel))->EndInit();
            this->addteachertablegroup->Panel->ResumeLayout(false);
            this->addteachertablegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachertablegroup))->EndInit();
            this->addteachertablegroup->ResumeLayout(false);
            this->panel35->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartmentgroup->Panel))->EndInit();
            this->addteacherdepartmentgroup->Panel->ResumeLayout(false);
            this->addteacherdepartmentgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartmentgroup))->EndInit();
            this->addteacherdepartmentgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteacherdepartment))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachernamegroup->Panel))->EndInit();
            this->addteachernamegroup->Panel->ResumeLayout(false);
            this->addteachernamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addteachernamegroup))->EndInit();
            this->addteachernamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel13))->EndInit();
            this->panel2->ResumeLayout(false);
            this->panel46->ResumeLayout(false);
            this->panel46->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptgroup->Panel))->EndInit();
            this->deptgroup->Panel->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptgroup))->EndInit();
            this->deptgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->EndInit();
            this->deleteclasspanel->ResumeLayout(false);
            this->panel47->ResumeLayout(false);
            this->panel47->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox2->Panel))->EndInit();
            this->kryptonGroupBox2->Panel->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox2))->EndInit();
            this->kryptonGroupBox2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectiondeletedatagridview))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactorgroup->Panel))->EndInit();
            this->editsubbfactorgroup->Panel->ResumeLayout(false);
            this->editsubbfactorgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactorgroup))->EndInit();
            this->editsubbfactorgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubroomlistgroup->Panel))->EndInit();
            this->editsubroomlistgroup->Panel->ResumeLayout(false);
            this->editsubroomlistgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubroomlistgroup))->EndInit();
            this->editsubroomlistgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcreditsgroup->Panel))->EndInit();
            this->editsubcreditsgroup->Panel->ResumeLayout(false);
            this->editsubcreditsgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcreditsgroup))->EndInit();
            this->editsubcreditsgroup->ResumeLayout(false);
            this->editsubelepanel->ResumeLayout(false);
            this->editsubelepanel->PerformLayout();
            this->panel13->ResumeLayout(false);
            this->panel13->PerformLayout();
            this->panel51->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleyesgroup->Panel))->EndInit();
            this->editsubeleyesgroup->Panel->ResumeLayout(false);
            this->editsubeleyesgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleyesgroup))->EndInit();
            this->editsubeleyesgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleteacher))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcluster))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearchgroup->Panel))->EndInit();
            this->editsubsearchgroup->Panel->ResumeLayout(false);
            this->editsubsearchgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearchgroup))->EndInit();
            this->editsubsearchgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubsearch))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubtitlegroup->Panel))->EndInit();
            this->editsubtitlegroup->Panel->ResumeLayout(false);
            this->editsubtitlegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubtitlegroup))->EndInit();
            this->editsubtitlegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubelegroup->Panel))->EndInit();
            this->editsubelegroup->Panel->ResumeLayout(false);
            this->editsubelegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubelegroup))->EndInit();
            this->editsubelegroup->ResumeLayout(false);
            this->panel10->ResumeLayout(false);
            this->panel10->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubnamegroup->Panel))->EndInit();
            this->editsubnamegroup->Panel->ResumeLayout(false);
            this->editsubnamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubnamegroup))->EndInit();
            this->editsubnamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcodegroup->Panel))->EndInit();
            this->editsubcodegroup->Panel->ResumeLayout(false);
            this->editsubcodegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcodegroup))->EndInit();
            this->editsubcodegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel4))->EndInit();
            this->editsubjectpanel->ResumeLayout(false);
            this->panel6->ResumeLayout(false);
            this->panel6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearchgroup->Panel))->EndInit();
            this->editroomsearchgroup->Panel->ResumeLayout(false);
            this->editroomsearchgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearchgroup))->EndInit();
            this->editroomsearchgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomsearch))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox10->Panel))->EndInit();
            this->kryptonGroupBox10->Panel->ResumeLayout(false);
            this->kryptonGroupBox10->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonGroupBox10))->EndInit();
            this->kryptonGroupBox10->ResumeLayout(false);
            this->panel14->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartmentgroup->Panel))->EndInit();
            this->editroomdepartmentgroup->Panel->ResumeLayout(false);
            this->editroomdepartmentgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartmentgroup))->EndInit();
            this->editroomdepartmentgroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomdepartment))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacitygroup->Panel))->EndInit();
            this->editroomcapacitygroup->Panel->ResumeLayout(false);
            this->editroomcapacitygroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacitygroup))->EndInit();
            this->editroomcapacitygroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomlabgroup->Panel))->EndInit();
            this->editroomlabgroup->Panel->ResumeLayout(false);
            this->editroomlabgroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomlabgroup))->EndInit();
            this->editroomlabgroup->ResumeLayout(false);
            this->panel45->ResumeLayout(false);
            this->panel45->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomnamegroup->Panel))->EndInit();
            this->editroomnamegroup->Panel->ResumeLayout(false);
            this->editroomnamegroup->Panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomnamegroup))->EndInit();
            this->editroomnamegroup->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kryptonPanel11))->EndInit();
            this->editroompanel->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        panel3->Height = button1->Height;
        panel3->Top = button1->Top;
        panel2->BringToFront();
        //close classroom suboptions
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close subject suboptions
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
        //close teacher suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close class suboptions
        button14->Visible = false;
        button13->Visible = false;
        textBox10->Visible = false;
        textBox11->Visible = true;
        editsubactivepanel->Height = 0;
        deptgroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        editsubactivepanel->Height = deptgroup->Height;
        deptgroup->SendToBack();
        editsubactivepanel->BringToFront();
        DisplayCSVInDataGridView(deptDataGridView, "details/dept_file.csv");
    }
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        if (!Directory::Exists("details"))
        {
            System::IO::Directory::CreateDirectory("details");
        }
        if (!Directory::Exists("timetables"))
        {
            System::IO::Directory::CreateDirectory("timetables");
        }
        if (!Directory::Exists("logs"))
        {
            System::IO::Directory::CreateDirectory("logs");
        }
        //username
        username->Left = int(panel4->Width / 3);
        //Side panel
        int panelWidth = (int)(this->ClientSize.Width * 0.165);
        panel1->Width = panelWidth;
        //Profile
        panel4->Width = panel1->Width;
        int labelX = panel4->Width + 12;
        //logo
        kryptonLabel1->Left = labelX;
        //dept
        panel46->Left = int((this->ClientSize.Width - (panel46->Width) * 1.5) / 2);
        //addroompanel
        panel7->Left = int((this->ClientSize.Width - (panel7->Width) * 1.5) / 2);
        roomcapacitygroup->Top = roomnamegroup->Bottom + 30;
        roomlabgroup->Top = roomcapacitygroup->Bottom + 30;
        roomdeptgroup->Top = roomlabgroup->Bottom + 30;
        kryptonGroupBox9->Top = roomdeptgroup->Bottom + 30;
        panel9->Top = kryptonGroupBox9->Bottom + 30;
        //editroompanel 
        panel6->Left = int((this->ClientSize.Width - (panel6->Width) * 1.5) / 2);
        editroomnamegroup->Top = editroomsearchgroup->Bottom + 30;
        editroomcapacitygroup->Top = editroomnamegroup->Bottom + 30;
        editroomlabgroup->Top = editroomcapacitygroup->Bottom + 30;
        editroomdepartmentgroup->Top = editroomlabgroup->Bottom + 30;
        kryptonGroupBox10->Top = editroomdepartmentgroup->Bottom + 30;
        panel14->Top = kryptonGroupBox10->Bottom + 30;
        //addteacherpanel
        panel16->Left = int((this->ClientSize.Width - (panel16->Width) * 1.5) / 2);
        addteacherdepartmentgroup->Top = addteachernamegroup->Bottom + 30;
        addteacheremailidgroup->Top = addteacherdepartmentgroup->Bottom + 30;
        addteachertablegroup->Top = addteacheremailidgroup->Bottom + 30;
        panel17->Top = addteachertablegroup->Bottom + 30;
        //editteacherpanel
        panel5->Left = int((this->ClientSize.Width - (panel5->Width) * 1.5) / 2);
        editteachernamegroup->Top = editteachersearchgroup->Bottom + 30;
        editteacherdepartmentgroup->Top = editteachernamegroup->Bottom + 30;
        editteacheremailidgroup->Top = editteacherdepartmentgroup->Bottom + 30;
        editteachertablegroup->Top = editteacheremailidgroup->Bottom + 30;
        panel18->Top = editteachertablegroup->Bottom + 30;
        //Addsubpanel
        panel11->Left = int((this->ClientSize.Width - (panel11->Width) * 1.5) / 2);
        addsubtitlegroup->Top = addsubnamegroup->Bottom + 30;
        addsubcodegroup->Top = addsubtitlegroup->Bottom + 30;
        addsubelegroup->Top = addsubcodegroup->Bottom + 30;
        addsubeleyes->Checked = false;
        addsubeleno->Checked = false;
        addsubeleyesgroup->Height = 0;
        addsubeleyesgroup->Top = addsubelegroup->Bottom + 30;
      //  addsubeleyesgroup->Height = 330;
        addsubcreditsgroup->Top = addsubelegroup->Bottom + 30;
        addsubroomlistgroup->Top = addsubcreditsgroup->Bottom + 30;
        addsubbfactorgroup->Top = addsubroomlistgroup->Bottom + 30;
        panel48->Top = addsubbfactorgroup->Bottom + 30;
        //editsubpanel
        int panelX = (this->ClientSize.Width - (panel13->Width) * 1.5) / 2;
        panel13->Left = panelX;
        editsubtitlegroup->Top = editsubnamegroup->Bottom + 30;
        editsubcodegroup->Top = editsubtitlegroup->Bottom + 30;
        editsubelegroup->Top = editsubcodegroup->Bottom + 30;
        editsubeleyes->Checked = false;
        editsubeleno->Checked = false;
        editsubeleyesgroup->Height = 0;
        editsubeleyesgroup->Top = editsubelegroup->Bottom + 30;
       // editsubeleyesgroup->Height = 330;
        editsubcreditsgroup->Top = editsubelegroup->Bottom + 30;
        editsubroomlistgroup->Top = editsubcreditsgroup->Bottom + 30;
        editsubbfactorgroup->Top = editsubroomlistgroup->Bottom + 30;
        panel51->Top = editsubbfactorgroup->Bottom + 30;
        //add class
        panel29->Left = int((this->ClientSize.Width - (panel29->Width) * 1.5) / 2);
        classbranchgroup->Top = classnamegroup->Bottom + 30;
        classbatchgroup->Top = classbranchgroup->Bottom + 30;
        classcoregroup->Top = classbatchgroup->Bottom + 30;
        classelegroup->Top = classcoregroup->Bottom + 30;
        classlabgroup->Top = classelegroup->Bottom + 30;
        classroomgroup->Top = classlabgroup->Bottom + 30;
        classgengroup->Height = 0;
        classresgroup->Height = 0;
        //delete class
        panel47->Left = int((this->ClientSize.Width - (panel47->Width) * 1.5) / 2);
        //Settings button
        int panelheight = (int)(this->ClientSize.Height * .85);
        button17->Top = panelheight;
        pictureBox11->Top = panelheight;
        button17->Width = panel1->Width;
        //Contact Button
        button18->Top = button17->Top - 40 - button18->Height;
        pictureBox12->Top = button18->Top;
        button18->Width = panel1->Width;
        //Other Buttons
        Homebutton1->Width = panel1->Width;
        button1->Width = panel1->Width;
        button6->Width = panel1->Width;
        button7->Width = panel1->Width;
        button8->Width = panel1->Width;
        button9->Width = panel1->Width;
        button10->Width = panel1->Width;
        button11->Width = panel1->Width;
        button12->Width = panel1->Width;
        button4->Width = panel1->Width;
        button10->Width = panel1->Width;
        button5->Width = panel1->Width;
        button13->Width = panel1->Width;
        button14->Width = panel1->Width;
        button15->Width = panel1->Width;
        textBox4->Left = int(panel1->Width) * 0.80;
        textBox5->Left = int(panel1->Width) * 0.80;
        textBox6->Left = int(panel1->Width) * 0.80;
        textBox7->Left = int(panel1->Width) * 0.80;
        textBox8->Left = int(panel1->Width) * 0.80;
        textBox9->Left = int(panel1->Width) * 0.80;
        textBox10->Left = int(panel1->Width) * 0.80;
        textBox11->Left = int(panel1->Width) * 0.80;
        Homepanel->BringToFront();
        panel1->BringToFront();
        InitializeMatrix(addroomtablepanel, "room", "Free", 1);
        InitializeMatrix(editroomtablepanel, "editroom", "Free", 1);
        InitializeMatrix(teachertablepanel, "teacher", "Free", 1);
        InitializeMatrix(editteachertablepanel, "editteacher", "Free", 1);
        InitializeMatrix(editsubeletable, "editele", "Available", 2);
    }

    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
        if (button4->Visible == false)
        {
            button5->Visible = true;
            button4->Visible = true;
            textBox5->Visible = false;
            textBox4->Visible = true;
        }
        else
        {
            button5->Visible = false;
            button4->Visible = false;
            textBox4->Visible = false;
            textBox5->Visible = true;
        }
        panel3->Height = button6->Height;
        panel3->Top = button6->Top;
        //close teachers suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close subject suboptions
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
        //close class suboptions
        button14->Visible = false;
        button13->Visible = false;
        textBox10->Visible = false;
        textBox11->Visible = true;
    }
    private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
        if (button8->Visible == false)
        {
            button8->Visible = true;
            button7->Visible = true;
            textBox7->Visible = false;
            textBox6->Visible = true;
        }

        else
        {
            button8->Visible = false;
            button7->Visible = false;
            textBox6->Visible = false;
            textBox7->Visible = true;
        }
        panel3->Height = button9->Height;
        panel3->Top = button9->Top;
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close subject suboptions
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
        //close class suboptions
        button14->Visible = false;
        button13->Visible = false;
        textBox10->Visible = false;
        textBox11->Visible = true;
    }
    private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel7->Controls[msclr::interop::marshal_as<String^>(addroomlastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);
        }
        catch (...)
        {
        }
        addroomlastpanel = "roomnamegroup";
        editsubactivepanel->Height = 0;
        roomnamegroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        roomnamegroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        roomnamegroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        roomnamegroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationaddroom();
        panel3->Height = button6->Height;
        panel3->Top = button6->Top;
        addclassroompanel->BringToFront();
        DisplayCSVInComboBoxkrypt("details/dept_file.csv", roomdept);
        button5->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
    }
    private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
        panel3->Height = Homebutton1->Height;
        panel3->Top = Homebutton1->Top;
        Homepanel->BringToFront();
        //close classroom suboptions
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close teacher suboptions
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close subject suboptions
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
        //close class suboptions
        button14->Visible = false;
        button13->Visible = false;
        textBox10->Visible = false;
        textBox11->Visible = true;
    }
    private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
        if (button10->Visible == false)
        {
            button10->Visible = true;
            button11->Visible = true;
            textBox9->Visible = false;
            textBox8->Visible = true;
        }

        else
        {
            button10->Visible = false;
            button11->Visible = false;
            textBox8->Visible = false;
            textBox9->Visible = true;
        }
        panel3->Height = button12->Height;
        panel3->Top = button12->Top;
        //close classroom suboptions
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close teachers suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close class suboptions
        button14->Visible = false;
        button13->Visible = false;
        textBox10->Visible = false;
        textBox11->Visible = true;
    }

    private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel16->Controls[msclr::interop::marshal_as<String^>(addteacherlastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);
        }
        catch (...)
        {
        }
        addteacherlastpanel = "addteachernamegroup";
        editsubactivepanel->Height = 0;
        addteachernamegroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        addteachernamegroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        addteachernamegroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        addteachernamegroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationaddteacher();
        panel3->Height = button9->Height;
        panel3->Top = button9->Top;
        addteacherpanel->BringToFront();
        DisplayCSVInComboBoxkrypt("details/dept_file.csv", addteacherdepartment);
        button8->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
    }
    private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
        string filePath = "details/dept_file.csv";
        deptcsvgen(deptDataGridView, filePath);
    }
    private: System::Void addteachersave_Click(System::Object^ sender, System::EventArgs^ e) {
        bool  flag = true;
        if (String::IsNullOrEmpty(addteachername->Text))
        {
            MessageBox::Show("Teacher Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(addteacherdepartment->Text))
        {
            MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(addteacheremailid->Text))
        {
            MessageBox::Show("Teacher's Email ID not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (flag)
        {
            addnamecsvgen("details/teacher_file.csv");
        }

    }
    private: System::Void saveroom_Click(System::Object^ sender, System::EventArgs^ e) {
        bool  flag = true;
        if (String::IsNullOrEmpty(roomname->Text))
        {
            MessageBox::Show("Room Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(roomdept->Text))
        {
            MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if ((!roomlabyes->Checked) && (!roomlabno->Checked))
        {
            MessageBox::Show("Select whether it is a lab or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (flag)
        {
            classroomcsvcreate("details/classroom.csv");
        }
    }
    private: System::Void clearroom_Click(System::Object^ sender, System::EventArgs^ e) {
        for (int i = 1; i <= 36; i++)
        {
            Button^ button = dynamic_cast<Button^>(addroomtablepanel->Controls[String::Format("buttonroom{0}", i)]);
            button->Text = "Free";
            button->BackColor = Color::FromArgb(210, 255, 255);
        }
        roomname->Clear();
        roomcapacity->Value = 0;
        roomlabyes->Checked = false;
        roomlabno->Checked = false;
        roomdept->Text = "";
    }
    private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
        panel3->Height = button12->Height;
        panel3->Top = button12->Top;
        addsubjectpanel->BringToFront();
        const std::string filePath = "details/classroom.csv";
        DisplayCSVInListBoxkrypt(filePath, addsubroomlist, 0);
        const std::string fileName = "details/teacher_file.csv";
        TeacherName->DataSource = CreateDataTableFromCSV1(fileName, "teacherName");
        TeacherName->DisplayMember = "TeacherName"; // Update to the correct column name
        TeacherName->ValueMember = "TeacherName";
        button11->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        DisplayCluster("details/Electivetimetable.csv", addsubcluster);
        InitializeMatrix(tableLayoutPanel1, "ele", "Available", 0);

        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel11->Controls[msclr::interop::marshal_as<String^>(addsublastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);  //(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);  
        }
        catch (...)
        {
        }
        addsublastpanel = "addsubnamegroup";
        editsubactivepanel->Height = 0;
        addsubnamegroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        addsubnamegroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        addsubnamegroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        addsubnamegroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationaddsub();

    }
    private: System::Void addsubsave_Click(System::Object^ sender, System::EventArgs^ e) {
        l.logs.log("Adding Subject");
        bool  flag = true;
        bool eleflag = true;
        if (String::IsNullOrEmpty(addsubname->Text))
        {
            MessageBox::Show("Subject Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
            eleflag = false;
        }
        else if ((!addsubeleyes->Checked) && (!addsubeleno->Checked))
        {
            MessageBox::Show("Select whether it is a elective or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (addsubeleyes->Checked)
        {
            if (String::IsNullOrEmpty(addsubcluster->Text))
            {
                MessageBox::Show("Elective name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                eleflag = false;
            }
            if (sedataGridView->RowCount == 1)
            {
                if (sedataGridView->Rows[0]->Cells[0]->Value == nullptr)
                    MessageBox::Show("Elective teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                eleflag = false;
            }
            bool xflag = false;
            if (xflag)
            {
                vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
                eleflag = false; string find = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
                string findclust = replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text));
                string str1;
                string str2;
                for (char& a : find)
                {
                    a = toupper(static_cast<unsigned char>(a));
                }
                for (char& a : findclust)
                {
                    a = toupper(static_cast<unsigned char>(a));
                }
                fstream file;
                file.open("details/Electivetimetable.csv");
                string line;
                while (getline(file, line))
                {
                    stringstream lineStream(line);
                    vector<string> rows;
                    string cell;
                    while (getline(lineStream, cell, ',')) {
                        rows.push_back(cell);
                    }
                    for (char& a : rows[0])
                    {
                        str1 += toupper(static_cast<unsigned char>(a));
                    }
                    if (replacewhitespace(str1) == findclust)
                    {
                        for (int i = 1; i < rows.size(); i++)
                        {
                            for (char& a : rows[i])
                            {
                                a = toupper(static_cast<unsigned char>(a));
                            }
                            if (rows[i] == find)
                            {
                                MessageBox::Show("Elective already exists.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                {
                                    goto x;
                                }
                            }
                        }
                    }
                }
                MessageBox::Show("Select eligible timeslots to block.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                onOptionClickedit(addsubcluster, sedataGridView, tableLayoutPanel1, "ele", addsubname);
            x:
                {
                }
            }
        }
        else if (addsubcredits->Value <= 0 && !addsubeleyes->Checked)
        {
            MessageBox::Show("Invalid Credits", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (addsubeleyes->Checked)
        {
            if (eleflag)
            {
                string find = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
                string findclust = replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text));
                string str1;
                string str2;
                for (char& a : find)
                {
                    a = toupper(static_cast<unsigned char>(a));
                }
                for (char& a : findclust)
                {
                    a = toupper(static_cast<unsigned char>(a));
                }
                fstream file;
                file.open("details/Electivetimetable.csv");
                string line;
                while (getline(file, line))
                {
                    stringstream lineStream(line);
                    vector<string> rows;
                    string cell;
                    while (getline(lineStream, cell, ',')) {
                        rows.push_back(cell);
                    }
                    for (char& a : rows[0])
                    {
                        str1 += toupper(static_cast<unsigned char>(a));
                    }
                    if (replacewhitespace(str1) == findclust)
                    {
                        for (int i = 1; i < rows.size(); i++)
                        {
                            for (char& a : rows[i])
                            {
                                a = toupper(static_cast<unsigned char>(a));
                            }
                            if (rows[i] == find)
                            {
                                if (MessageBox::Show("Elective already exists.", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::No)
                                {
                                    goto a;
                                }
                            }
                        }
                    }
                }
                file.close();
                vector < vector<string>> temp = ReadCSVFile("details/teacher_file.csv");
                bool nflag = false;
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i * 6 + j + 1)]);
                        if (button != nullptr)
                        {
                            if (button->Text == addsubname->Text)
                                nflag = true;
                        }
                    }

                }
                if (!nflag)
                {
                    MessageBox::Show("Block slots for the subject", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                else
                {
                    vector<vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
                    ofstream file("details/Electivetimetable.csv");
                    bool flags = true;
                    if (file.is_open())
                    {
                        for (const auto& row : data)
                        {
                            if (row[0] == replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text)))
                            {
                                flags = false;
                                file << row[0];
                                for (int i = 1; i <= 36; i++)
                                {
                                    Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i)]);
                                    if (button != nullptr)
                                    {
                                        if (button->Text == addsubname->Text)
                                        {
                                            file << "," << replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
                                            for (auto& row : temp)
                                            {
                                                for (int j = 0; j < sedataGridView->RowCount; j++)
                                                {
                                                    if (sedataGridView->Rows[j]->Cells[0]->Value != nullptr)
                                                    {
                                                        if (row[0] == replacewhitespace(msclr::interop::marshal_as<string>(sedataGridView->Rows[j]->Cells[0]->Value->ToString())))
                                                        {
                                                            row[(2 * i + 1)] = '1';
                                                            row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text)) + "(" + replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text)) + ")";
                                                        }
                                                        else
                                                        {
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                        else
                                            file << "," << row[i];
                                    }
                                }
                                file << endl;
                            }
                            else
                            {
                                for (int i = 0; i < row.size() - 1; i++)
                                {
                                    file << row[i] << ",";
                                }
                                file << row[row.size() - 1] << "\n";
                            }
                        }
                        if (flags)
                        {
                            file << replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text));
                            for (int i = 1; i <= 36; i++)
                            {
                                Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i)]);
                                if (button != nullptr)
                                {
                                    if (button->Text == addsubname->Text)
                                    {
                                        file << "," << replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
                                        for (auto& row : temp)
                                        {
                                            for (int j = 0; j < sedataGridView->RowCount; j++)
                                            {
                                                if (sedataGridView->Rows[j]->Cells[0]->Value != nullptr)
                                                {
                                                    if (row[0] == replacewhitespace(msclr::interop::marshal_as<string>(sedataGridView->Rows[j]->Cells[0]->Value->ToString())))
                                                    {
                                                        row[(2 * i) + 1] = '1';
                                                        row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text)) + "(" + replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text)) + ")";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                        file << ",0";
                                }
                            }
                            file << endl;
                        }
                    }
                    file.close();
                    ofstream tFile("details/teacher_file.csv");
                    if (tFile.is_open()) {
                        for (const auto& t : temp) {
                            for (int i = 0; i < t.size() - 1; i++) {
                                tFile << t[i] << ",";
                            }
                            tFile << t[t.size() - 1] << "\n";
                        }
                    }
                    tFile.close();
                    MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }
        else
        {
            if (flag)
                subcsvgen("details/subject_file.csv");
        }
    a:
        {}
        //DisplayCluster("details/Electivetimetable.csv", addsubcluster);
    }
    private: System::Void newaddsub_Click(System::Object^ sender, System::EventArgs^ e) {
        addsubname->Clear();
        addsubcluster->Text = "";
       sedataGridView->Rows->Clear();
        timer9->Start();
        addsubcredits->Value = 0;
        addsubbfactor->Value = 0;
        for (int i = 0; i < addsubroomlist->Items->Count; i++) {
            addsubroomlist->SetItemChecked(i, false);
        }
        addsubcredits->ReadOnly = false;
        addsubcredits->Cursor = Cursors::Arrow;
        addsubroomlist->Cursor = Cursors::Arrow;
        addsubroomlist->Enabled = true;
        addsubbfactor->ReadOnly = false;
        addsubbfactor->Cursor = Cursors::Arrow;
    }
    private: System::Void addsubeleno_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (addsubeleno->Checked)
        {

            addsubcluster->Text = "";
            addsubcluster->Cursor = Cursors::No;
            sedataGridView->Rows->Clear();
            sedataGridView->Cursor = Cursors::No;
            sedataGridView->ReadOnly = true;
            addsubclusteroptions->Cursor = Cursors::No;
            sedataGridView->ReadOnly = false;
            addsubcredits->Value = 0;
            addsubcredits->ReadOnly = false;
            addsubcredits->Cursor = Cursors::Arrow;
            addsubroomlist->Cursor = Cursors::Arrow;
            addsubroomlist->Enabled = true;
            addsubbfactor->Value = 0;
            addsubbfactor->ReadOnly = false;
            addsubbfactor->Cursor = Cursors::Arrow;
        }
    }
    private: System::Void addsubeleyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (addsubeleyes->Checked)
        {
            addsubcluster->Text = "";
            sedataGridView->Cursor = Cursors::Arrow;
            sedataGridView->ReadOnly = false;
            addsubcluster->Cursor = Cursors::Arrow;
            addsubclusteroptions->Cursor = Cursors::Arrow;
            addsubbfactor->Value = 0;
            addsubbfactor->ReadOnly = true;
            addsubbfactor->Cursor = Cursors::No;
            addsubcredits->Cursor = Cursors::No;
            addsubcredits->Value = 0;
            addsubcredits->ReadOnly = true;
            addsubroomlist->Cursor = Cursors::No;
            addsubroomlist->Enabled = false;
        }
    }
    private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
        if (button14->Visible == false)
        {
            button14->Visible = true;
          //  button13->Visible = true;
            textBox11->Visible = false;
            textBox10->Visible = true;
        }

        else
        {
            button13->Visible = false;
            button14->Visible = false;
            textBox10->Visible = false;
            textBox11->Visible = true;
        }
        panel3->Height = button15->Height;
        panel3->Top = button15->Top;
        //close classroom suboptions
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close subject suboptions
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
        //close teachers suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
    }
    private: System::Void classcore_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn6, classcore, sender, e);
    }
    private: System::Void classsave_Click(System::Object^ sender, System::EventArgs^ e) {

        bool  flag = true;
        if (String::IsNullOrEmpty(classname->Text))
        {
            MessageBox::Show("Section Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (String::IsNullOrEmpty(classbatch->Text))
        {
            MessageBox::Show("Batch(Year of admission not filled)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (String::IsNullOrEmpty(classbranch->Text))
        {
            MessageBox::Show("Branch not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (classcore->RowCount == 1)
        {
            if (classcore->Rows[0]->Cells[0]->Value == nullptr)
                MessageBox::Show("CoreSubjects and teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        if (classele->RowCount == 1)
        {
            if (classele->Rows[0]->Cells[0]->Value == nullptr)
            {
                if (MessageBox::Show("Are you Sure you do not want to fill any electives", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                    flag = false;
            }
        }
        if (classlab->RowCount == 1)
        {
            if (classlab->Rows[0]->Cells[0]->Value == nullptr)
            {
                if (MessageBox::Show("Are you Sure you do not want to fill any lab subjects", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                    flag = false;
            }
        }
        if (classdefaultrooms->CheckedItems->Count == 0)
        {
            MessageBox::Show("Default classes not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        //
        if (flag)
        {
            string x;
            if (MessageBox::Show("Are you Sure you want to save the generated timeTable", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
            {
                extern vector<section>allsections;
                {
                    section obj;
                    for (int i = 0; i < classele->RowCount; i++)
                    {
                        if (classele->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            vector<vector<string>> rowsOfElectives = ReadCSVFile("details/electivetimetable.csv");
                            for (auto name : rowsOfElectives) {
                                if (name[0] == replacewhitespace(msclr::interop::marshal_as<string>(classele->Rows[i]->Cells[0]->Value->ToString())))
                                {
                                    for (int ptr = 1; ptr < name.size(); ptr++) {
                                        if (name[ptr] != "0")
                                        {
                                            int day = (ptr - 1) / 6;
                                            int period = (ptr - 1) % 6;
                                            obj.block(day, period, name[ptr], name[ptr]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    String^ sec = classname->Text->ToString();
                    string Sec = replacewhitespace(msclr::interop::marshal_as<string>(sec));
                    String^ branch = classbranch->Text->ToString();
                    string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
                    String^ year = classbatch->Text->ToString();
                    string YEAR = msclr::interop::marshal_as<string>(year);
                    obj.name = Branch + Sec + YEAR;
                    allteachersfunction("details/teacher_file.csv", obj);
                    allroomsfunction("details/classroom.csv", obj);
                    //alloting default rooms
                    defaultroomallot(obj);
                    //alloting core teacher and subjects
                    loadcore(obj);
                    if(compactlabs->Checked)
                        obj.compactLab = true;
                    labcreate(labteachers, obj);
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            Button^ button = dynamic_cast<Button^>(classtablegen->Controls[String::Format("buttonres{0}", 6 * i + j + 1)]);
                            if (button->Text == "Reserved")
                            {
                                obj.block(i, j, "Reserved", "Reserved");
                            }
                        }
                    }
                    obj.makeTIMETABLE();
                    allsections.push_back(obj);
                    ofstream sfile;
                    sfile.open("details/section.csv", ios::app);
                    if (sfile.is_open())
                    {
                        sfile << obj.convertToString() << "\n";
                    }
                    sfile.close();
                }
                ofstream file;
                file.open(replacewhitespace("timetables/" + (msclr::interop::marshal_as<string>(classbranch->Text + (classname)->Text + classbatch->Text)) + ".csv"));
                if (file.is_open())
                {
                    string  tt;
                    tt += "TIMETABLE\n\n";
                    tt += "SUBJECTS\n";
                    for (auto day : allsections[allsections.size() - 1].timeTable)
                    {
                        for (auto period : day)
                        {
                            tt += replaceunderscore(period) + ",";
                        }
                        tt += "\n";
                    }
                    tt += "\n\n";
                    tt += "TEACHERS\n";
                    for (auto day : allsections[allsections.size() - 1].teacherTable)
                    {
                        for (auto period : day)
                        {
                            tt += replaceunderscore(period) + ",";
                        }
                        tt += "\n";
                    }
                    tt += "\n\n";
                    tt += "ROOM\n";
                    for (auto day : allsections[allsections.size() - 1].roomTable)
                    {
                        for (auto period : day)
                        {
                            tt += replaceunderscore(period) + ",";
                        }
                        tt += "\n";
                    }
                    tt += "\n\n";
                    file << tt;
                    file.close();
                }
                File::Copy("details/teacher_file.csv", "details/duplicate.csv", true);
                ofstream files("details/duplicate.csv");
                if (files.is_open())
                {
                    for (auto t : allsections[allsections.size() - 1].allTeachers)
                    {
                        if (t.name != "No_Teacher")
                            files << t.convertToString() << "\n";
                    }

                }
                files.close();
                File::Copy("details/duplicate.csv", "details/teacher_file.csv", true);
                File::Delete("details/duplicate.csv");
                ofstream fils("details/classroom.csv");
                if (fils.is_open())
                {
                    for (auto t : allsections[allsections.size() - 1].allRooms)
                    {
                        if (t.name != "No_Room")
                            fils << t.convertToString() << "\n";
                    }

                }
                fils.close();
                MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
    }

    private: System::Void textBox16_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
        if (File::Exists("details/duplicate.csv"))
        {
            MessageBox::Show("Data not saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        Application::Exit();
    }
    private: System::Void textBox11_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel5->Controls[msclr::interop::marshal_as<String^>(editteacherlastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);
        }
        catch (...)
        {
        }
        editteacherlastpanel = "editteachersearchgroup";
        editsubactivepanel->Height = 0;
        editteachersearchgroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        editteachersearchgroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        editteachersearchgroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        editteachersearchgroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationeditteacher();
        panel3->Height = button9->Height;
        panel3->Top = button9->Top;
        editteacherpanel->BringToFront();
        button7->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        DisplayCSVInComboBoxkrypt("details/dept_file.csv", editteacherdepartment);
        DisplayCSVInComboBoxkrypt("details/teacher_file.csv", teachersearch);
    }
    private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void panel5_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void editteacherpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void editteacherdelete_Click(System::Object^ sender, System::EventArgs^ e) {
        if (MessageBox::Show("Are you sure you want to delete", "Disclaimer", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
        {
            editteachercsvdelete("details/teacher_file.csv");

            editteachername->Clear();
            editteacheremailid->Clear();
            for (int i = 1; i <= 36; ++i)
            {
                String^ tagValue = i.ToString();
                Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
                if (button != nullptr)
                {
                    button->Text = "Free";
                    button->BackColor = Color::FromArgb(210, 255, 255);
                }
            }
            editteacherdepartment->Text = "";
            DisplayCSVInComboBoxkrypt("details/teacher_file.csv", teachersearch);
        }

    }

    private: System::Void editteachersave_Click(System::Object^ sender, System::EventArgs^ e) {
        bool flag = true;
        if (String::IsNullOrEmpty(editteachername->Text))
        {
            MessageBox::Show("Teacher Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(editteacherdepartment->Text))
        {
            MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(editteacheremailid->Text))
        {
            MessageBox::Show("Teacher's Email ID not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (flag)
        {
            if (MessageBox::Show("Are you sure you want to save the changes", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
            {
                editteachercsvsave("details/teacher_File.csv");

                editteachername->Clear();
                editteacheremailid->Clear();
                for (int i = 1; i <= 36; ++i)
                {
                    String^ tagValue = i.ToString();
                    Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
                    if (button != nullptr)
                    {
                        button->Text = "Free";
                        button->BackColor = Color::FromArgb(210, 255, 255);
                    }
                }
                editteacherdepartment->Text = "";
            }
        }
    }
    private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel6->Controls[msclr::interop::marshal_as<String^>(editroomlastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);
        }
        catch (...)
        {
        }
        editroomlastpanel = "editroomsearchgroup";
        editsubactivepanel->Height = 0;
        editroomsearchgroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        editroomsearchgroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        editroomsearchgroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        editroomsearchgroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationeditroom();
        editroompanel->BringToFront();
        panel3->Height = button6->Height;
        panel3->Top = button6->Top;
        button4->BackColor = Color::FromArgb(0, 0, 100);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        DisplayCSVInComboBoxkrypt("details/dept_file.csv", editroomdepartment);
        DisplayCSVInComboBoxkrypt("details/classroom.csv", editroomsearch);
    }
    private: System::Void editroomsearchbutton_Click(System::Object^ sender, System::EventArgs^ e) {

        editroomcsvshow("details/classroom.csv");
    }
    private: System::Void editroomdelete_Click(System::Object^ sender, System::EventArgs^ e) {
        if (MessageBox::Show("Are you sure you want to delete", "Disclaimer", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
        {
            editroomcsvdelete("details/classroom.csv");
            editroomname->Clear();
            editroomcapacity->Value = 0;
            editroomlabyes->Checked = false;
            editroomlabno->Checked = false;
            for (int i = 1; i <= 36; ++i)
            {
                String^ tagValue = i.ToString();
                Button^ button = dynamic_cast<Button^>(editroomtablepanel->Controls[String::Format("buttoneditroom{0}", tagValue)]);
                if (button != nullptr)
                {
                    button->Text = "Free";
                    button->BackColor = Color::FromArgb(210, 255, 255);
                }
            }
            editroomdepartment->Text = "";
        }

    }
    private: System::Void editroomsave_Click(System::Object^ sender, System::EventArgs^ e) {
        bool  flag = true;
        if (String::IsNullOrEmpty(editroomname->Text))
        {
            MessageBox::Show("Room Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (String::IsNullOrEmpty(editroomdepartment->Text))
        {
            MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if ((!editroomlabyes->Checked) && (!editroomlabno->Checked))
        {
            MessageBox::Show("Select whether it is a lab or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (flag)
        {

            if (MessageBox::Show("Are you sure you want to save the changes", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
            {
                editroomcsvsave("details/classroom.csv");
                editroomname->Clear();
                editroomcapacity->Value = 0;
                editroomlabyes->Checked = false;
                editroomlabno->Checked = false;
                for (int i = 1; i <= 36; ++i)
                {
                    String^ tagValue = i.ToString();
                    Button^ button = dynamic_cast<Button^>(editroomtablepanel->Controls[String::Format("buttoneditroom{0}", tagValue)]);
                    if (button != nullptr)
                    {
                        button->Text = "Free";
                        button->BackColor = Color::FromArgb(210, 255, 255);
                    }
                }
                editroomdepartment->Text = "";
            }
        }
    }
    private: System::Void pictureBox11_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
        pictureBox11->Height += 5;
        pictureBox11->Width += 5;
    }
    private: System::Void pictureBox11_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
        pictureBox11->Height -= 5;
        pictureBox11->Width -= 5;
    }
    private: System::Void editsubjectpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }

    private: System::Void panel9_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button10_Click_1(System::Object^ sender, System::EventArgs^ e) {

        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel13->Controls[msclr::interop::marshal_as<String^>(editsublastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);  //(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);  
        }
        catch (...)
        {
        }
        editsublastpanel = "editsubsearchgroup";
        editsubactivepanel->Height = 0;
        editsubsearchgroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        editsubsearchgroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        editsubsearchgroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        editsubsearchgroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimation();
        editsubsearch->Text = "";
        editsubname->Clear();
        editsubtitle->Clear();
        editsubcode->Clear();
        editsubeleyes->Checked = false;
        editsubeleno->Checked = false;
        editsubcluster->Text = "";
        editsubeleteacher->Rows->Clear();
        editsubcredits->Value = 0;
        editsubbfactor->Value = 0;
        for (int i = 0; i < editsubroomlist->Items->Count; i++) {
            editsubroomlist->SetItemChecked(i, false);
        }
        editsubeleteachercombo->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "editsubeleteachercombo");
        editsubeleteachercombo->DisplayMember = "editsubeleteachercombo"; // Update to the correct column name
        editsubeleteachercombo->ValueMember = "editsubeleteachercombo";
        DisplayCSVInListBoxkrypt("details/classroom.csv", editsubroomlist, 0);
        DisplayCSVInComboBoxkrypt("details/Electivetimetable.csv", editsubcluster);
        DisplayCSVInComboBoxsub("details/Electivetimetable.csv", editsubsearch);
        panel3->Height = button12->Height;
        panel3->Top = button12->Top;
        editsubjectpanel->BringToFront();
        button10->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        DisplayCluster("details/Electivetimetable.csv", editsubcluster);
        //
        InitializeMatrix(editsubeletable, "editele", "Available", 2);
        editsubelepanel->Visible = false;
        //  editpanelsub->Top = editsubelepanel->Top;
    }
    private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) {
        this->WindowState = FormWindowState::Minimized;
    }
    private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) {
        this->WindowState = FormWindowState::Maximized;
    }
    private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
        addnamecsvgen("details/teacher_file.csv");
    }
    private: System::Void pictureBox11_Click(System::Object^ sender, System::EventArgs^ e) {
        settingspanel->BringToFront();
        InitializeMatrix(settingstable, "set", "Open", 3);
    }
    private: System::Void addteachernew_Click(System::Object^ sender, System::EventArgs^ e) {
        addteachername->Clear();
        addteacheremailid->Clear();
        for (int i = 1; i <= 36; ++i)
        {
            String^ tagValue = i.ToString();
            Button^ button = dynamic_cast<Button^>(teachertablepanel->Controls[String::Format("buttonteacher{0}", tagValue)]);
            if (button != nullptr)
            {
                button->Text = "Free";
                button->BackColor = Color::FromArgb(210, 255, 255);
            }
        }
        addteacherdepartment->Text = "";
    }

    private: System::Void panel10_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button60_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void editsubsearchbutton_Click(System::Object^ sender, System::EventArgs^ e) {
        editsubjectcsvshow();
    }
    private: System::Void label99_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void editsubsave_Click(System::Object^ sender, System::EventArgs^ e) {
        bool  flag = true;
        if (String::IsNullOrEmpty(editsubname->Text))
        {
            MessageBox::Show("Subject Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if ((!editsubeleyes->Checked) && (!editsubeleno->Checked))
        {
            MessageBox::Show("Select whether it is a elective or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (editsubeleyes->Checked)
        {
            if (String::IsNullOrEmpty(editsubcluster->Text))
            {
                MessageBox::Show("Elective name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                flag = false;
            }
            else if (editsubeleteacher->RowCount == 1)
            {
                if (editsubeleteacher->Rows[0]->Cells[0]->Value == nullptr)
                    MessageBox::Show("Elective teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                flag = false;
            }
            bool xflag = false;
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector<vector<bool>>intersect = intersectionElective(valuetimetable("", editsubeleteacher, editsubname, editsubcluster));
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", i * 6 + j + 1)]);
                    if (button != nullptr)
                    {
                        if (intersect[i][j])
                        {
                            if (button->Text == editsubname->Text)
                            {
                                xflag = true;
                                goto fl;
                            }
                        }
                    }

                }
            }
        fl:
            {}
            if (xflag)
            {
                flag = false;
                MessageBox::Show("Select eligible timeslots to block.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                onOptionClickedit(editsubcluster, editsubeleteacher, editsubeletable, "editele", editsubname);
            }
        }
        if (editsubcredits->Value <= 0 && !editsubeleyes->Checked)
        {
            MessageBox::Show("Invalid Credits", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (editsubbfactor->Value == 0 && !editsubeleyes->Checked)
        {
            MessageBox::Show("Invalid bfactor Value", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (editsubtitle->Text == "" && !editsubeleyes->Checked)
        {
            MessageBox::Show("Enter the title", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (editsubcode->Text== "" && !editsubeleyes->Checked)
        {
            MessageBox::Show("Enter the code", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (flag)
        {
            string filePath = "details/subject_file.csv";
            editsubcsvsave(filePath);
        }
    }
    private: System::Void editsubdelete_Click(System::Object^ sender, System::EventArgs^ e) {
        if (MessageBox::Show("Are you sure you want to delete", "Disclaimer", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
        {
            timer12->Start();
            editsubcsvdelete("details/subject_file.csv");
            editsubname->Clear();
            editsubcluster->Text = "";
            editsubeleyes->Checked = false;
            editsubeleno->Checked = false;
            editsubeleteacher->Rows->Clear();
            editsubcredits->Value = 0;
            editsubbfactor->Value = 0;
            for (int i = 0; i < editsubroomlist->Items->Count; i++) {
                editsubroomlist->SetItemChecked(i, false);
            }
        }
    }
    private: System::Void editsubeleteacher_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn10, editsubeleteacher, sender, e);
    }
    private: System::Void editsubeleyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (editsubeleyes->Checked)
        {
            editsubcluster->Text = "";
            editsubeleteacher->Cursor = Cursors::Arrow;
            editsubeleteacher->ReadOnly = false;
            editsubcluster->Cursor = Cursors::Arrow;
            button3->Cursor = Cursors::Arrow;
            editsubbfactor->Value = 0;
            editsubbfactor->ReadOnly = true;
            editsubbfactor->Cursor = Cursors::No;
            editsubcredits->Cursor = Cursors::No;
            editsubcredits->Value = 0;
            editsubcredits->ReadOnly = true;
            editsubroomlist->Cursor = Cursors::No;
            editsubroomlist->Enabled = false;
        }
    }
    private: System::Void editsubeleno_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (editsubeleno->Checked)
        {
            editsubcluster->Text = "";
            editsubcluster->Cursor = Cursors::No;
            editsubeleteacher->Rows->Clear();
            editsubeleteacher->Cursor = Cursors::No;
            editsubeleteacher->ReadOnly = true;
            button3->Cursor = Cursors::No;
            if (editsubelepanel->Visible)
            {
                editsubelepanel->Visible = false;
                //  editpanelsub->Top = addsubeletablepanel->Top;
            }
            editsubeleteacher->ReadOnly = false;
            editsubcredits->Value = 0;
            editsubcredits->ReadOnly = false;
            editsubcredits->Cursor = Cursors::Arrow;
            editsubroomlist->Cursor = Cursors::Arrow;
            editsubroomlist->Enabled = true;
            editsubbfactor->Value = 0;
            editsubbfactor->ReadOnly = false;
            editsubbfactor->Cursor = Cursors::Arrow;
        }
    }
    private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void addsubclusteroptions_Click(System::Object^ sender, System::EventArgs^ e) {
        bool flag = true;
        if (addsubname->Text == "")
        {
            MessageBox::Show("Subject Name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (addsubeleyes->Checked == false)
        {
            MessageBox::Show("Only applicable for Electives", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        string find = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
        string findclust = replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text));
        string str1;
        string str2;
        for (char& a : find)
        {
            a = toupper(static_cast<unsigned char>(a));
        }
        for (char& a : findclust)
        {
            a = toupper(static_cast<unsigned char>(a));
        }
        fstream file;
        file.open("details/Electivetimetable.csv");
        string line;
        while (getline(file, line))
        {
            stringstream lineStream(line);
            vector<string> rows;
            string cell;
            while (getline(lineStream, cell, ',')) {
                rows.push_back(cell);
            }
            for (char& a : rows[0])
            {
                str1 += toupper(static_cast<unsigned char>(a));
            }
            if (replacewhitespace(str1) == findclust)
            {
                for (int i = 1; i < rows.size(); i++)
                {
                    for (char& a : rows[i])
                    {
                        a = toupper(static_cast<unsigned char>(a));
                    }
                    if (rows[i] == find)
                    {
                        MessageBox::Show("Elective already exists.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                        {
                            goto a;
                        }
                    }
                }
            }
        }
        if (flag)
        {
            InitializeMatrix(tableLayoutPanel1, "ele", "Available", 0);
            onOptionClickedit(addsubcluster, sedataGridView, tableLayoutPanel1, "ele", addsubname);
        }
    a:
        {}
    }
    private: System::Void classgenerate_Click(System::Object^ sender, System::EventArgs^ e) {
        bool  flag = true;
        if (String::IsNullOrEmpty(classname->Text))
        {
            MessageBox::Show("Section Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (String::IsNullOrEmpty(classbatch->Text))
        {
            MessageBox::Show("Batch(Year of admission not filled)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (String::IsNullOrEmpty(classbranch->Text))
        {
            MessageBox::Show("Branch not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (classcore->RowCount == 1)
        {
            if (classcore->Rows[0]->Cells[0]->Value == nullptr)
                MessageBox::Show("CoreSubjects and teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        if (classele->RowCount == 1)
        {
            if (classele->Rows[0]->Cells[0]->Value == nullptr)
            {
                if (MessageBox::Show("Are you Sure you do not want to fill any electives", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                    flag = false;
            }
        }
        if (classlab->RowCount == 1)
        {
            if (classlab->Rows[0]->Cells[0]->Value == nullptr)
            {
                if (MessageBox::Show("Are you Sure you do not want to fill any lab subjects", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                    flag = false;
            }
        }
        if (classdefaultrooms->CheckedItems->Count == 0)
        {
            MessageBox::Show("Default classes not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }

        if (flag) {
            //
            section obj;
            for (int i = 0; i < classele->RowCount; i++)
            {
                if (classele->Rows[i]->Cells[0]->Value != nullptr)
                {
                    vector<vector<string>> rowsOfElectives = ReadCSVFile("details/electivetimetable.csv");
                    for (auto name : rowsOfElectives) {
                        if (name[0] == replacewhitespace(msclr::interop::marshal_as<string>(classele->Rows[i]->Cells[0]->Value->ToString())))
                        {
                            for (int ptr = 1; ptr < name.size(); ptr++) {
                                if (name[ptr] != "0")
                                {
                                    int day = (ptr - 1) / 6;
                                    int period = (ptr - 1) % 6;
                                    obj.block(day, period, name[ptr], name[ptr]);
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 0; x < 6; x++)
            {
                for (int y = 0; y < 6; y++)
                {
                    Button^ button = dynamic_cast<Button^>(classtablegen->Controls[String::Format("buttonres{0}", x * 6 + y + 1)]);
                    if (button->Text == "Reserved")
                    {
                        obj.block(x, y, "Reserved", "Reserved");
                    }
                }
            }
            InitializeMatrix(classtablegen1, "g", "free", -1);
            classresgroup->Height = 0;
            classgengroup->Height = 500;
                classgengroup->Top = panel27->Bottom + 30;;
            String^ sec = (classname)->Text->ToString();
            string Sec = replacewhitespace(msclr::interop::marshal_as<string>(sec));
            String^ branch = classbranch->Text->ToString();
            string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
            String^ year = classbatch->Text->ToString();
            string YEAR = msclr::interop::marshal_as<string>(year);

            obj.name = Sec + YEAR + Branch;
            allteachersfunction("details/teacher_file.csv", obj);
            allroomsfunction("details/classroom.csv", obj);
            //alloting default rooms
            defaultroomallot(obj);
            //alloting core teacher and subjects
            loadcore(obj);
            if (compactlabs->Checked)
                obj.compactLab = true;
            labcreate(labteachers, obj);
            obj.makeTIMETABLE();
            if (obj.errorMessage != "")
            {
                MessageBox::Show(msclr::interop::marshal_as<String^>(obj.errorMessage), "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
            for (int i = 0; i < obj.timeTable.size(); i++)
            {
                for (int j = 0; j < obj.timeTable[i].size(); j++)
                {
                    Button^ button = dynamic_cast<Button^>(classtablegen1->Controls[String::Format("buttong{0}", 6 * i + j + 1)]);
                    if (obj.timeTable[i][j] != "f")
                        button->Text = msclr::interop::marshal_as<String^>(replaceunderscore(obj.timeTable[i][j]));
                    else
                        button->Text = "free";
                }
            }
        }
    }
    private: System::Void classreserve_Click_1(System::Object^ sender, System::EventArgs^ e) {
        InitializeMatrix(classtablegen, "res", "Open", 3);
        classresgroup->Height = 500;
        classgengroup->Height = 0;
       classresgroup->Top= panel27->Bottom + 30;

    }
    private: System::Void classclear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearReset();
        classbatch->Value = 2020;
        classname->Clear();
        classbranch->Text = "";
        classcore->Rows->Clear();
        classlab->Rows->Clear();
        classele->Rows->Clear();
        classsessions->Value = 0;
        classbatches->Value = 0;
        classlabcombo->Text = "";
        classlabteachers->Rows->Clear();
        for (int i = classdefaultrooms->Items->Count - 1; i >= 0; i--) {
            classdefaultrooms->SetItemChecked(i, false);
        }
        for (int i = classlabroomlist->Items->Count - 1; i >= 0; i--) {
            classlabroomlist->SetItemChecked(i, false);
        }
        classresgroup->Height = 0;
        classgengroup->Height = 0;
    }
    private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
        deptDataGridView->Rows->Clear();
    }
    private: System::Void editroompanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void panelsub_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            ComponentFactory::Krypton::Toolkit::KryptonGroupBox^ g = dynamic_cast <ComponentFactory::Krypton::Toolkit::KryptonGroupBox^>(panel29->Controls[msclr::interop::marshal_as<String^>(addclasslastpanel)]);
            g->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
            g->StateCommon->Border->Color2 = Color::FromArgb(224, 224, 224);
        }
        catch (...)
        {
        }
        addclasslastpanel = "classnamegroup";
        editsubactivepanel->Height = 0;
        classnamegroup->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        classnamegroup->StateCommon->Border->Color1 = Color::FromArgb(224, 224, 224);
        classnamegroup->StateCommon->Border->Color2 = Color::FromArgb(0, 0, 77);
        classnamegroup->SendToBack();
        editsubactivepanel->BringToFront();
        StartAnimationaddclass();
        button14->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        classpanel->BringToFront();
        DisplayCSVInListBoxkrypt("details/classroom.csv", classlabroomlist, 0);
        classlabroomlist->Items->Add("No Room");
        classlabroomlist->Items->Add("No Room");
        classlabroomlist->Items->Add("No Room");
        InitializeMatrix(classtablegen, "res", "Open", 3);
        InitializeMatrix(classtablegen1, "g", "free", -1);
        classbatch->Value = 2020;
        classname->Clear();
        classbranch->Text = "";
        classele->Rows->Clear();
        classdefaultrooms->Items->Clear();
        DisplayCSVInComboBoxkrypt("details/dept_file.csv", classbranch);
        DisplayCSVInListBoxkrypt("details/classroom.csv", classdefaultrooms, 3);
        classdefaultrooms->Items->Add("No Room");
        csubject->DataSource = CreateDataTableFromCSV1("details/subject_file.csv", "Core Subject");
        csubject->DisplayMember = "Core Subject"; // Update to the correct column name
        csubject->ValueMember = "Core Subject";
        cteacher->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "cteacher");
        cteacher->DisplayMember = "cteacher"; // Update to the correct column name
        cteacher->ValueMember = "cteacher";
        esubject->DataSource = CreateDataTableFromCSV1("details/electivetimetable.csv", "esubject");
        esubject->DisplayMember = "esubject"; // Update to the correct column name
        esubject->ValueMember = "esubject";
        Teacher1->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "lteacher1");
        Teacher1->DisplayMember = "lteacher1"; // Update to the correct column name
        Teacher1->ValueMember = "lteacher1";
        panel3->Height = button15->Height;
        panel3->Top = button15->Top;
        //close classroom suboption
        button5->Visible = false;
        button4->Visible = false;
        textBox4->Visible = false;
        textBox5->Visible = true;
        //close teachers suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close subject suboption
        button10->Visible = false;
        button11->Visible = false;
        textBox8->Visible = false;
        textBox9->Visible = true;
    }
    private: System::Void panel16_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        try
        {
            section obj;
            allteachersfunction("details/teacher_file.csv", obj);
            allroomsfunction("details/classroom.csv", obj);
            if (e->ColumnIndex == classdeletebutton->Index && e->RowIndex >= 0)
            {
                if (MessageBox::Show("Are you Sure you want to delete the class", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
                {
                    int rowIndexToDelete = e->RowIndex;
                    string find = msclr::interop::marshal_as<string>(sectiondeletedatagridview->Rows[rowIndexToDelete]->Cells[0]->Value->ToString());
                    string x = returnLine(find, "details/section.csv");
                    obj.readData(x);
                    obj.deAllocate();
                    ofstream files("details/teacher_file.csv");
                    if (files.is_open())
                    {
                        for (auto t : obj.allTeachers)
                        {
                            if (t.name == "No_Teacher")
                                continue;
                            files << t.convertToString() << "\n";
                        }

                    }
                    files.close();
                    ofstream fils("details/classroom.csv");
                    if (fils.is_open())
                    {
                        for (auto t : obj.allRooms)
                        {
                            if (t.name == "No_Room")
                                continue;
                            fils << t.convertToString() << "\n";
                        }

                    }
                    fils.close();
                    replacename(find, "details/section.csv", 0, "");
                    sectiondeletedatagridview->Rows->RemoveAt(rowIndexToDelete);
                    MessageBox::Show("Successfully Deleted", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }
        catch (...)
        {

        }
    }
    private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
        button13->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        deleteclasspanel->BringToFront();
        kryptonGroupBox2->Panel->Controls->Add(this->editsubactivepanel);
        editsubactivepanel->Location = System::Drawing::Point(0, 0);
        editsubactivepanel->Height = kryptonGroupBox2->Height;
        kryptonGroupBox2->SendToBack();
        editsubactivepanel->BringToFront();
        DisplayCSVInDataGridView(sectiondeletedatagridview, "details/section.csv");
    }
    private: System::Void editteachersearchbutton_Click(System::Object^ sender, System::EventArgs^ e) {
        editteachercsvshow("details/teacher_file.csv");
    }
    private: System::Void panel37_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        if (searchsubname == "")
        {
            MessageBox::Show("Select a subject", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            goto er;
        }
        else
        {
            string name, clust;
            bool e = false;
            for (char& n : searchsubname)
            {
                if (n == '(')
                {
                    e = true;
                    continue;
                }
                if (n == ')')
                    continue;
                if (e)
                {
                    clust += n;
                }
                else
                    name += n;
            }
            if (clust == "")
            {
                MessageBox::Show("Select an elective", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                goto er;
            }
            else if (msclr::interop::marshal_as<string>(editsubcluster->Text) != clust)
            {
                MessageBox::Show("Cluster name cannot be changed", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
                editsubname->Text = msclr::interop::marshal_as<String^>(replaceunderscore(clust));
                goto er;
            }
        }
            timer11->Start();
            InitializeMatrix(editsubeletable, "editele", "Available", 2);
            onOptionClickedit(editsubcluster, editsubeleteacher, editsubeletable, "editele", editsubname);
    er:
        {}
    }
    private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn3, classlabteachers, sender, e);
    }
    private: System::Void classlabsave_Click(System::Object^ sender, System::EventArgs^ e) {
        if (classlabcombo->Text == "")
        {
            MessageBox::Show("Select a lab subject", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else if (classbatches->Value == 0)
        {
            MessageBox::Show("Select number of batches", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else if (classoptrooms->Checked && classlabroomlist->CheckedItems->Count < classbatches->Value)
        {
                MessageBox::Show("Number of rooms selected should be atleast equal to number of batches", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else if (classoptrooms->Checked==false && classlabroomlist->CheckedItems->Count != classbatches->Value)
        {
            MessageBox::Show("Limit number of rooms to number of batches", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else if (classsessions->Value == 0)
        {
            MessageBox::Show("Select number of sessions", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            int x = classlabteachers->RowCount;
            bool flag = true;
            for (auto& row : labteachers)
            {
                if (row[0] == replacewhitespace(msclr::interop::marshal_as<string>(classlabcombo->Text)))
                {
                    flag = false;
                    row.clear();
                    row.push_back(replacewhitespace(msclr::interop::marshal_as<string>(classlabcombo->Text)));
                    row.push_back(msclr::interop::marshal_as<string>(classbatches->Text->ToString()));
                    row.push_back(msclr::interop::marshal_as<string>(classsessions->Text->ToString()));
                    for (int i = 0; i < classlabteachers->RowCount; i++)
                    {
                        if (classlabteachers->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            row.push_back(replacewhitespace(msclr::interop::marshal_as<string>(classlabteachers->Rows[i]->Cells[0]->Value->ToString())));
                        }
                    }
                    string x = "[";
                    for (int i = 0; i < classlabroomlist->CheckedItems->Count; ++i) {
                        String^ value = classlabroomlist->CheckedItems[i]->ToString();
                        std::string Value = replacewhitespace(msclr::interop::marshal_as<string>(value));
                        x += Value;
                        if (i < classlabroomlist->CheckedItems->Count - 1) {
                            x += ",";// Add a comma after each value, except the last one
                        }
                    }
                    x += "]\n";
                    row.push_back(x);
                }
            }
            if (flag)
            {
                vector<string>row;
                row.push_back(replacewhitespace(msclr::interop::marshal_as<string>(classlabcombo->Text)));
                row.push_back(msclr::interop::marshal_as<string>(classbatches->Text->ToString()));
                row.push_back(msclr::interop::marshal_as<string>(classsessions->Text->ToString()));
                for (int i = 0; i < classlabteachers->RowCount; i++)
                {
                    if (classlabteachers->Rows[i]->Cells[0]->Value != nullptr)
                    {
                        row.push_back(replacewhitespace(msclr::interop::marshal_as<string>(classlabteachers->Rows[i]->Cells[0]->Value->ToString())));
                    }
                }
                classlab->Rows->Add(msclr::interop::marshal_as< String^>(replaceunderscore(row[0])));
                string x = "[";
                for (int i = 0; i < classlabroomlist->CheckedItems->Count; ++i) {
                    String^ value = classlabroomlist->CheckedItems[i]->ToString();
                    std::string Value = replacewhitespace(msclr::interop::marshal_as<string>(value));
                    x += Value;
                    if (i < classlabroomlist->CheckedItems->Count - 1) {
                        x += ",";// Add a comma after each value, except the last one
                    }
                }
                x += "]\n";
                row.push_back(x);
                labteachers.push_back(row);
            }

            MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    private: System::Void classlabcombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        classlabteachers->Rows->Clear();
        for (const auto& row : labteachers)
        {
            if (row[0] == replacewhitespace(msclr::interop::marshal_as<string>(classlabcombo->Text)))
            {
                for (int i = 1; i < row.size(); i++)
                {
                    classlabteachers->Rows->Add(msclr::interop::marshal_as<String^>(replaceunderscore(row[i])));
                }
                break;
            }
        }
    }
    private: System::Void classlabcombo_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick_2(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        Process::Start("details/teacher_file.csv");
    }
    private: System::Void label101_Click(System::Object^ sender, System::EventArgs^ e) {
    }


    private: System::Void kryptonGroupBox2_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void panel13_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void editsubtitlegroup_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void editsubtitle_TextChanged(System::Object^ sender, System::EventArgs^ e) {

    }
    private: System::Void label109_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void kryptonDataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn10, editsubeleteacher, sender, e);
    }
    private: System::Void editsubtitle_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubtitlegroup", editsubtitlegroup, 6, editsublastpanel);
    }
    private: System::Void editsubname_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubnamegroup", editsubnamegroup, 6, editsublastpanel);
    }
    private: System::Void editsubsearch_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubsearchgroup", editsubsearchgroup, 6, editsublastpanel);
    }
    private: System::Void editsubcode_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubcodegroup", editsubcodegroup, 6, editsublastpanel);
    }
    private: System::Void panel10_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubelegroup", editsubelegroup, 6, editsublastpanel);
    }
    private: System::Void editsubeleyesgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubeleyesgroup", editsubeleyesgroup, 6, editsublastpanel);
    }
    private: System::Void editsubcredits_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubcreditsgroup", editsubcreditsgroup, 6, editsublastpanel);
    }
    private: System::Void editsubroomlist_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubroomlistgroup", editsubroomlistgroup, 6, editsublastpanel);
    }
    private: System::Void editsubbfactor_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel13, "editsubbfactorgroup", editsubbfactorgroup, 6, editsublastpanel);
    }
    private: System::Void kryptonDataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn4, sedataGridView, sender, e);
    }
    private: System::Void addsubnamegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubnamegroup", addsubnamegroup, 5, addsublastpanel);
    }
    private: System::Void addsubtitlegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubtitlegroup", addsubtitlegroup, 5, addsublastpanel);
    }
    private: System::Void addsubcode_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubcodegroup", addsubcodegroup, 5, addsublastpanel);
    }
    private: System::Void addsubelegroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubelegroup", addsubelegroup, 5, addsublastpanel);
    }
    private: System::Void addsubcreditsgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubcreditsgroup", addsubcreditsgroup, 5, addsublastpanel);
    }
    private: System::Void addsubeleyesgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubeleyesgroup", addsubeleyesgroup, 5, addsublastpanel);
    }
    private: System::Void addsubroomlistgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubroomlistgroup", addsubroomlistgroup, 5, addsublastpanel);
    }
    private: System::Void addsubbfactorgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel11, "addsubbfactorgroup", addsubbfactorgroup, 5, addsublastpanel);
    }
    private: System::Void addsubjectpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void panel7_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void roomdept_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label28_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void deptDataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn1, deptDataGridView, sender, e);
    }
    private: System::Void label33_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void classcore_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn6, classcore, sender, e);
    }
    private: System::Void classele_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebuttonkrypt(dataGridViewButtonColumn5, classele, sender, e);
    }
    private: System::Void editteachernamegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel5, "editteachernamegroup", editteachernamegroup, 4, editteacherlastpanel);
    }
    private: System::Void editteacherdepartmentgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel5, "editteacherdepartmentgroup", editteacherdepartmentgroup, 4, editteacherlastpanel);
    }
    private: System::Void editteacheremailidgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel5, "editteacheremailidgroup", editteacheremailidgroup, 4, editteacherlastpanel);
    }
    private: System::Void editteachertablegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel5, "editteachertablegroup", editteachertablegroup, 4, editteacherlastpanel);
    }
    private: System::Void addteachernamegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel16, "addteachernamegroup", addteachernamegroup, 3, addteacherlastpanel);
    }
    private: System::Void addteacherdepartmentgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel16, "addteacherdepartmentgroup", addteacherdepartmentgroup, 3, addteacherlastpanel);
    }
    private: System::Void addteacheremailid_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void addteacheremailid_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel16, "addteacheremailidgroup", addteacheremailidgroup, 3, addteacherlastpanel);
    }
    private: System::Void addteachertablegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel16, "addteachertablegroup", addteachertablegroup, 3, addteacherlastpanel);
    }
    private: System::Void editteachersearchgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel5, "editteachersearchgroup", editteachersearchgroup, 4, editteacherlastpanel);
    }
    private: System::Void editroomsearch_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel6, "editroomsearchgroup", editroomsearchgroup, 2, editroomlastpanel);
    }
    private: System::Void editroomnamegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel6, "editroomnamegroup", editroomnamegroup, 2, editroomlastpanel);
    }
    private: System::Void editroomcapacitygroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel6, "editroomcapacitygroup", editroomcapacitygroup, 2, editroomlastpanel);
    }
    private: System::Void kryptonGroupBox10_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel6, "kryptonGroupBox10", kryptonGroupBox10, 2, editroomlastpanel);
    }
    private: System::Void editroomlabgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
        coloredpanel(panel6, "editroomlabgroup", editroomlabgroup, 2, editroomlastpanel);
    }
private: System::Void editroomdepartmentgroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel6, "editroomdepartmentgroup", editroomdepartmentgroup, 2, editroomlastpanel);

}



private: System::Void roomlabgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel7, "roomlabgroup", roomlabgroup, 1, addroomlastpanel);
}
private: System::Void roomcapacitygroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel7, "roomcapacitygroup", roomcapacitygroup, 1, addroomlastpanel);
}
private: System::Void roomnamegroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel7, "roomnamegroup", roomnamegroup, 1, addroomlastpanel);
}

private: System::Void kryptonGroupBox9_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel7, "kryptonGroupBox9", kryptonGroupBox9, 1, addroomlastpanel);
}
private: System::Void roomdeptgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel7, "roomdeptgroup", roomdeptgroup, 1, addroomlastpanel);
}
private: System::Void addsubeleyes_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    timer7->Start();
}
private: System::Void addsubclusteroptions_Click_1(System::Object^ sender, System::EventArgs^ e) {
    
    bool flag = true;
    if (addsubname->Text == "")
    {
        MessageBox::Show("Subject Name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    else if (addsubeleyes->Checked == false)
    {
        MessageBox::Show("Only applicable for Electives", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    string find = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
    string findclust = replacewhitespace(msclr::interop::marshal_as<string>(addsubcluster->Text));
    string str1;
    string str2;
    for (char& a : find)
    {
        a = toupper(static_cast<unsigned char>(a));
    }
    for (char& a : findclust)
    {
        a = toupper(static_cast<unsigned char>(a));
    }
    fstream file;
    file.open("details/Electivetimetable.csv");
    string line;
    while (getline(file, line))
    {
        stringstream lineStream(line);
        vector<string> rows;
        string cell;
        while (getline(lineStream, cell, ',')) {
            rows.push_back(cell);
        }
        for (char& a : rows[0])
        {
            str1 += toupper(static_cast<unsigned char>(a));
        }
        if (replacewhitespace(str1) == findclust)
        {
            for (int i = 1; i < rows.size(); i++)
            {
                for (char& a : rows[i])
                {
                    a = toupper(static_cast<unsigned char>(a));
                }
                if (rows[i] == find)
                {
                    MessageBox::Show("Elective already exists.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    {
                        goto a;
                    }
                }
            }
        }
    }
    if (flag)
    {
        timer8->Start();
        InitializeMatrix(tableLayoutPanel1, "ele", "Available", 0);
        onOptionClickedit(addsubcluster, sedataGridView, tableLayoutPanel1, "ele", addsubname);
    }
a:
    {}

}
private: System::Void addsubeleno_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    timer9->Start();
}
private: System::Void editsubeleyes_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    timer10->Start();
}
private: System::Void editsubeleno_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    timer12->Start();
}
private: System::Void kryptonGroupBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel29_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void classlab_CellContentClick_2(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebuttonlab (dataGridViewButtonColumn7, classlab, sender, e);
    editbuttonlab(lsubject, classlab, sender, e);
}
private: System::Void classnamegroup_Panel_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classnamegroup", classnamegroup, 7, addclasslastpanel);
}
private: System::Void classbranchgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classbranchgroup", classbranchgroup, 7, addclasslastpanel);
}
private: System::Void classbatchgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classbatchgroup", classbatchgroup, 7, addclasslastpanel);
}
private: System::Void classcoregroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classcoregroup", classcoregroup, 7, addclasslastpanel);
}
private: System::Void classelegroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classelegroup", classelegroup, 7, addclasslastpanel);
}
private: System::Void classlabgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classlabgroup", classlabgroup, 7, addclasslastpanel);
}
private: System::Void classroomgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classroomgroup", classroomgroup, 7, addclasslastpanel);
}
private: System::Void classresgroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classresgroup", classresgroup, 7, addclasslastpanel);
}
private: System::Void classgengroup_Enter(System::Object^ sender, System::EventArgs^ e) {
    coloredpanel(panel29, "classgengroup", classgengroup, 7, addclasslastpanel);
}
private: System::Void classsessions_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addclassroompanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void settingssave_Click(System::Object^ sender, System::EventArgs^ e) {
    string x;
    x += msclr::interop::marshal_as<string>(filepath->Text) + ",";
    x += to_string(FLOAT(freefactor->Value)) + ",";
    x += to_string(FLOAT(busyfactor->Value));
    for (int i = 1; i < 37; i++)
    {
        Button^ button = dynamic_cast<Button^>(settingstable->Controls[String::Format("buttonset{0}", i)]);
        if (button != nullptr)
        {
            if (button->Text == "Reserved")
            {
                x += ",1";
            }
            else
                x += ",0";
        }
    }
    settings obj;
    obj.readData(x);
}

private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
    if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK);
    {
        filepath->Text = fbd->SelectedPath;
    }
}      
};
}