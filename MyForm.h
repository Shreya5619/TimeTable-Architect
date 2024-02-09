#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
namespace TTA_ui {
    using namespace std;
    using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

        void deptcsvgen(DataGridView^ dataGridView1, const string filePath) {
            ofstream outputFile(filePath);
            if (outputFile.is_open())
            {
                for (int i = 0; i < dataGridView1->RowCount-1; ++i)
                {

                    if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr)
                    {
                        System::String^ cellvalue = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
                        string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                        outputFile << CellValue;

                    }outputFile << '\n';

                }outputFile.close();
            }
        }

        vector<vector<string>> ReadCSVFile(const string& filename) {
            ifstream file(filename);
            vector<vector<string>> data;
            string line;

            while (getline(file, line)) {
                stringstream lineStream(line);
                vector<string> row;
                string cell;

                while (getline(lineStream, cell, ',')) {
                    row.push_back(cell);
                }

                data.push_back(row);
            }
            file.close();

            return data;
        }

        void DisplayCSVInComboBox(DataGridView^ dataGridView1,const string& filename) {
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                string rowString;
                for (const auto& cell : row) {
                    rowString += cell;
                }
                String^ rowStringManaged = msclr::interop::marshal_as<String^>(rowString);
                dataGridView1->Rows->Add(rowStringManaged);
            }
        }

        void DisplayCSVInComboBox1(const string& filename, ComboBox^ comboBox) {
            comboBox->Items->Clear();
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                string rowString;
                for (const auto& cell : row) {
                    rowString += cell;
                }
                String^ rowStringManaged = msclr::interop::marshal_as<String^>(rowString);
                comboBox->Items->Add(rowStringManaged);
            }
        }

        void deletebutton(DataGridViewButtonColumn^ x,DataGridView^ dataGridView1, System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
            {
            try
            {
                if (e->ColumnIndex == x->Index && e->RowIndex >= 0)
                {
                    int rowIndexToDelete = e->RowIndex;
                    dataGridView1->Rows->RemoveAt(rowIndexToDelete);
                }
            }
            catch (...)
            {

            }
        }
 
        void change(Button^ button)
        {
            if (button->Text == "free") {
                button->Text = "occupied";
            }
            else {
                button->Text = "free";
            }

        }

        string replacewhitespace(string text)
        {
            replace(text.begin(), text.end(), ' ', '_');
            return text;
        }

        void addnamecsvgen(String^ filePath)
        {
            ofstream outputFile;
            outputFile.open(msclr::interop::marshal_as<string>(filePath), ios::app);
            if (outputFile.is_open())
            {
                {	String^ name = textBox2->Text->ToString();
                string Name = msclr::interop::marshal_as<string>(name);
                string teachername = replacewhitespace(Name);
                outputFile << teachername << ",";
                String^ dep = comboBox1->Text->ToString();
                string Dep = msclr::interop::marshal_as<string>(dep);
                string Depname = replacewhitespace(Dep);
                outputFile << Depname << ",";
                for (int i = 1; i <= 36; ++i)
                {
                    String^ tagValue = i.ToString();
                    Button^ button = dynamic_cast<Button^>(addclasspanel->Controls[String::Format("buttons{0}", tagValue)]);
                    if (button != nullptr)
                    {
                        if (button->Text == "occupied")
                        {
                            outputFile << "1,0";
                        }
                        else if (button->Text == "free")
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
        }

        void classroomcsvcreate(String^ filePath)
        {
            ofstream outputFile;
            outputFile.open(msclr::interop::marshal_as<string>(filePath), ios::app);
            if (outputFile.is_open())
            {
                {	String^ name = textBox3->Text->ToString();
                string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                outputFile << Name << ",";
                String^ cap = numericUpDown1->Text->ToString();
                string Cap = msclr::interop::marshal_as<string>(cap);
                outputFile << Cap << ",";
                if (radioButton1->Checked)
                {
                    outputFile << "1" << ",";
                }
                else
                {
                    outputFile << "0" << ",";
                }
                System::String^ dep = comboBox2->Text->ToString();
                std::string Dep = replacewhitespace(msclr::interop::marshal_as<string>(dep));
                outputFile << Dep << ",";
                for (int i = 1; i <= 36; ++i)
                {
                    String^ tagValue = i.ToString();
                    Button^ button = dynamic_cast<Button^>(addclassroompanel->Controls[String::Format("buttona{0}", tagValue)]);
                    if (button != nullptr)
                    {
                        if (button->Text == "occupied")
                        {
                            outputFile << "1,0";
                        }
                        else if (button->Text == "free")
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
        }
//functions for subject.h
        void subcsvgen(String^ filePath)
        {

            ofstream outputFile;
            outputFile.open((msclr::interop::marshal_as<string>(filePath)), ios::app);
            if (outputFile.is_open())
            {
                String^ name = textBox16->Text->ToString();
                string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                outputFile << Name << ",";
                {if (radioButton10->Checked)
                {
                    String^ ele = textBox15->Text->ToString();
                    string Ele = replacewhitespace(msclr::interop::marshal_as<string>(ele));
                    outputFile << Ele << ",";
                    String^ FilePath = "Elective.csv";
                    csvelective(FilePath);
                }
                else if (radioButton9->Checked)
                {
                    outputFile << "0,";
                }}
                {if (radioButton8->Checked)
                {
                    outputFile << "1,";
                    {
                        String^ filepath = "Labo.csv";
                        csvlab(filepath);
                    }
                }
                else
                {
                    outputFile << "0,";
                }}
                System::String^ credits = numericUpDown5->Text->ToString();
                std::string Credits = msclr::interop::marshal_as<string>(credits);
                outputFile << Credits << ",";
                System::String^ bfactor = numericUpDown4->Text->ToString();
                std::string Bfactor = msclr::interop::marshal_as<string>(bfactor);
                outputFile << Bfactor << ",";
                //code to add roomlist
                outputFile << "[";
                bool x = true;
                for (int i = 0; i < checkedListBox2->CheckedItems->Count; ++i) {
                    String^ value = checkedListBox2->CheckedItems[i]->ToString();
                    std::string Value = msclr::interop::marshal_as<string>(value);
                    outputFile << Value;
                    x = false;
                    if (i < checkedListBox2->CheckedItems->Count - 1) {
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
        }
        void DisplayCSVInListBox(const string& filename, ListBox^ ListBox) {
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                if (!row.empty()) {
                    String^ firstWord = msclr::interop::marshal_as<String^>(row[0]);
                    ListBox->Items->Add(firstWord);
                }
            }
        }
        void csvelective(System::String^ filePath)
        {

            std::ofstream outputFile;
            outputFile.open((msclr::interop::marshal_as<std::string>(filePath)), ios::app);
            {
                System::String^ name = textBox16->Text->ToString();
                std::string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                outputFile << Name << ",";
                System::String^ elename = textBox15->Text->ToString();
                std::string eleName = replacewhitespace(msclr::interop::marshal_as<string>(elename));
                outputFile << eleName << ",";
                for (int i = 0; i < dataGridView5->RowCount - 1; ++i)
                {
                    if (dataGridView5->Rows[i]->Cells[0]->Value != nullptr)
                    {
                        System::String^ cellvalue = dataGridView5->Rows[i]->Cells[0]->Value->ToString();
                        std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                        outputFile << CellValue << ",";
                    }

                }outputFile << "\n";
            }outputFile.close();
        }
        void csvlab(System::String^ filePath)
        {

            std::ofstream outputFile;
            outputFile.open((msclr::interop::marshal_as<std::string>(filePath)), ios::app);
            {
                System::String^ name = textBox16->Text->ToString();
                std::string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                outputFile << Name << ",";
                if (dataGridView4->Rows[0]->Cells[0]->Value != nullptr)
                    outputFile << msclr::interop::marshal_as<string>(dataGridView4->Rows[0]->Cells[0]->Value->ToString());
                for (int i = 1; i < dataGridView4->RowCount; ++i)
                {

                    if (dataGridView4->Rows[i]->Cells[0]->Value != nullptr)
                    {
                        System::String^ cellvalue = dataGridView4->Rows[i]->Cells[0]->Value->ToString();
                        std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                        outputFile << "," << CellValue;


                    }
                }


                outputFile << "\n";
            }outputFile.close();
        }
        System::Data::DataTable^ CreateDataTableFromCSV1(const std::string filePath) {
            System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
            dataTable->Columns->Add("teacherName");
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data) {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ teacherName = msclr::interop::marshal_as<String^>(row[0]);
                    dataTable->Rows->Add(teacherName);
                }
            }
            return dataTable;
        }
        System::Data::DataTable^ CreateDataTableFromCSV2(const std::string filePath) {
            System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
            dataTable->Columns->Add("teacher_Name");
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data) {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ teacher_Name = msclr::interop::marshal_as<String^>(row[0]);
                    dataTable->Rows->Add(teacher_Name);
                }
            }
            return dataTable;
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;


    private: System::Windows::Forms::TextBox^ textBox11;

    private: System::Windows::Forms::Button^ button13;

    private: System::Windows::Forms::Button^ button14;

    private: System::Windows::Forms::Button^ button15;
    private: System::Windows::Forms::TextBox^ textBox8;
    private: System::Windows::Forms::TextBox^ textBox9;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Button^ button11;
    private: System::Windows::Forms::Button^ button12;
    private: System::Windows::Forms::TextBox^ textBox6;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::TextBox^ textBox7;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::TextBox^ textBox10;
    private: System::Windows::Forms::Panel^ panel3;


    private: System::Windows::Forms::Button^ button18;
    private: System::Windows::Forms::PictureBox^ pictureBox2;



    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::PictureBox^ pictureBox7;
    private: System::Windows::Forms::PictureBox^ pictureBox6;
    private: System::Windows::Forms::PictureBox^ pictureBox5;
    private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::TextBox^ textBox12;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ addclasspanel;
private: System::Windows::Forms::Panel^ addclassroompanel;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Button^ buttona36;
private: System::Windows::Forms::Button^ buttona35;
private: System::Windows::Forms::Button^ buttona34;
private: System::Windows::Forms::Button^ buttona33;
private: System::Windows::Forms::Button^ buttona32;
private: System::Windows::Forms::Button^ buttona31;
private: System::Windows::Forms::Button^ buttona30;
private: System::Windows::Forms::Button^ buttona29;
private: System::Windows::Forms::Button^ buttona28;
private: System::Windows::Forms::Button^ buttona27;
private: System::Windows::Forms::Button^ buttona26;
private: System::Windows::Forms::Button^ buttona25;
private: System::Windows::Forms::Button^ buttona24;
private: System::Windows::Forms::Button^ buttona23;
private: System::Windows::Forms::Button^ buttona22;
private: System::Windows::Forms::Button^ buttona21;
private: System::Windows::Forms::Button^ buttona20;
private: System::Windows::Forms::Button^ buttona19;
private: System::Windows::Forms::Button^ buttona18;
private: System::Windows::Forms::Button^ buttona17;
private: System::Windows::Forms::Button^ buttona16;
private: System::Windows::Forms::Button^ buttona15;
private: System::Windows::Forms::Button^ buttona14;
private: System::Windows::Forms::Button^ buttona13;
private: System::Windows::Forms::Button^ buttona12;
private: System::Windows::Forms::Button^ buttona11;
private: System::Windows::Forms::Button^ buttona10;
private: System::Windows::Forms::Button^ buttona9;
private: System::Windows::Forms::Button^ buttona8;
private: System::Windows::Forms::Button^ buttona7;
private: System::Windows::Forms::Button^ buttona6;
private: System::Windows::Forms::Button^ buttona5;
private: System::Windows::Forms::Button^ buttona4;
private: System::Windows::Forms::Button^ buttona3;
private: System::Windows::Forms::Button^ buttona2;
private: System::Windows::Forms::Button^ buttona1;
private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Button^ Save;
private: System::Windows::Forms::Button^ Back;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label13;
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
private: System::Windows::Forms::Panel^ addsubjectpanel;
private: System::Windows::Forms::Button^ newaddsub;

private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
private: System::Windows::Forms::Button^ addsubsave;

private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::Label^ label42;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::NumericUpDown^ numericUpDown5;
private: System::Windows::Forms::DataGridView^ dataGridView4;


private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::RadioButton^ radioButton7;
private: System::Windows::Forms::RadioButton^ radioButton8;
private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::DataGridView^ dataGridView5;


private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::RadioButton^ radioButton9;
private: System::Windows::Forms::RadioButton^ radioButton10;
private: System::Windows::Forms::TextBox^ textBox15;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::TextBox^ textBox16;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ TeacherName;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher_Name;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn4;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ SubjectName;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn8;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn2;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
private: System::Windows::Forms::DataGridView^ dataGridView3;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn3;


private: System::Windows::Forms::Button^ button16;
private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::DataGridView^ dataGridView6;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Subject_Name;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn3;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;




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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle43 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->button18 = (gcnew System::Windows::Forms::Button());
            this->textBox10 = (gcnew System::Windows::Forms::TextBox());
            this->textBox11 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->button13 = (gcnew System::Windows::Forms::Button());
            this->button14 = (gcnew System::Windows::Forms::Button());
            this->button15 = (gcnew System::Windows::Forms::Button());
            this->textBox8 = (gcnew System::Windows::Forms::TextBox());
            this->textBox9 = (gcnew System::Windows::Forms::TextBox());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->button11 = (gcnew System::Windows::Forms::Button());
            this->button12 = (gcnew System::Windows::Forms::Button());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->textBox7 = (gcnew System::Windows::Forms::TextBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->textBox12 = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->addclasspanel = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->button16 = (gcnew System::Windows::Forms::Button());
            this->button17 = (gcnew System::Windows::Forms::Button());
            this->button19 = (gcnew System::Windows::Forms::Button());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
            this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
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
            this->addclassroompanel = (gcnew System::Windows::Forms::Panel());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->buttona36 = (gcnew System::Windows::Forms::Button());
            this->buttona35 = (gcnew System::Windows::Forms::Button());
            this->buttona34 = (gcnew System::Windows::Forms::Button());
            this->buttona33 = (gcnew System::Windows::Forms::Button());
            this->buttona32 = (gcnew System::Windows::Forms::Button());
            this->buttona31 = (gcnew System::Windows::Forms::Button());
            this->buttona30 = (gcnew System::Windows::Forms::Button());
            this->buttona29 = (gcnew System::Windows::Forms::Button());
            this->buttona28 = (gcnew System::Windows::Forms::Button());
            this->buttona27 = (gcnew System::Windows::Forms::Button());
            this->buttona26 = (gcnew System::Windows::Forms::Button());
            this->buttona25 = (gcnew System::Windows::Forms::Button());
            this->buttona24 = (gcnew System::Windows::Forms::Button());
            this->buttona23 = (gcnew System::Windows::Forms::Button());
            this->buttona22 = (gcnew System::Windows::Forms::Button());
            this->buttona21 = (gcnew System::Windows::Forms::Button());
            this->buttona20 = (gcnew System::Windows::Forms::Button());
            this->buttona19 = (gcnew System::Windows::Forms::Button());
            this->buttona18 = (gcnew System::Windows::Forms::Button());
            this->buttona17 = (gcnew System::Windows::Forms::Button());
            this->buttona16 = (gcnew System::Windows::Forms::Button());
            this->buttona15 = (gcnew System::Windows::Forms::Button());
            this->buttona14 = (gcnew System::Windows::Forms::Button());
            this->buttona13 = (gcnew System::Windows::Forms::Button());
            this->buttona12 = (gcnew System::Windows::Forms::Button());
            this->buttona11 = (gcnew System::Windows::Forms::Button());
            this->buttona10 = (gcnew System::Windows::Forms::Button());
            this->buttona9 = (gcnew System::Windows::Forms::Button());
            this->buttona8 = (gcnew System::Windows::Forms::Button());
            this->buttona7 = (gcnew System::Windows::Forms::Button());
            this->buttona6 = (gcnew System::Windows::Forms::Button());
            this->buttona5 = (gcnew System::Windows::Forms::Button());
            this->buttona4 = (gcnew System::Windows::Forms::Button());
            this->buttona3 = (gcnew System::Windows::Forms::Button());
            this->buttona2 = (gcnew System::Windows::Forms::Button());
            this->buttona1 = (gcnew System::Windows::Forms::Button());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->Save = (gcnew System::Windows::Forms::Button());
            this->Back = (gcnew System::Windows::Forms::Button());
            this->addsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->newaddsub = (gcnew System::Windows::Forms::Button());
            this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
            this->addsubsave = (gcnew System::Windows::Forms::Button());
            this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
            this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
            this->Teacher_Name = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
            this->textBox15 = (gcnew System::Windows::Forms::TextBox());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->textBox16 = (gcnew System::Windows::Forms::TextBox());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
            this->Subject_Name = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewComboBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            this->panel2->SuspendLayout();
            this->addclasspanel->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            this->addclassroompanel->SuspendLayout();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            this->addsubjectpanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
            this->groupBox4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
            this->groupBox5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
            this->SuspendLayout();
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->panel1->Controls->Add(this->pictureBox7);
            this->panel1->Controls->Add(this->pictureBox6);
            this->panel1->Controls->Add(this->pictureBox5);
            this->panel1->Controls->Add(this->pictureBox4);
            this->panel1->Controls->Add(this->pictureBox3);
            this->panel1->Controls->Add(this->pictureBox2);
            this->panel1->Controls->Add(this->panel3);
            this->panel1->Controls->Add(this->button18);
            this->panel1->Controls->Add(this->textBox10);
            this->panel1->Controls->Add(this->textBox11);
            this->panel1->Controls->Add(this->textBox4);
            this->panel1->Controls->Add(this->button13);
            this->panel1->Controls->Add(this->button14);
            this->panel1->Controls->Add(this->button15);
            this->panel1->Controls->Add(this->textBox8);
            this->panel1->Controls->Add(this->textBox9);
            this->panel1->Controls->Add(this->button10);
            this->panel1->Controls->Add(this->button11);
            this->panel1->Controls->Add(this->button12);
            this->panel1->Controls->Add(this->textBox6);
            this->panel1->Controls->Add(this->textBox7);
            this->panel1->Controls->Add(this->textBox5);
            this->panel1->Controls->Add(this->button7);
            this->panel1->Controls->Add(this->button4);
            this->panel1->Controls->Add(this->button8);
            this->panel1->Controls->Add(this->button5);
            this->panel1->Controls->Add(this->button9);
            this->panel1->Controls->Add(this->button6);
            this->panel1->Controls->Add(this->button1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(324, 1106);
            this->panel1->TabIndex = 0;
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(44, 710);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(56, 40);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox7->TabIndex = 31;
            this->pictureBox7->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(44, 610);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(56, 40);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(44, 496);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(56, 40);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(44, 398);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(56, 40);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(44, 298);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(56, 40);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(44, 183);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(56, 40);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 6;
            this->pictureBox2->TabStop = false;
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->panel3->Location = System::Drawing::Point(12, 183);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(4, 40);
            this->panel3->TabIndex = 6;
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
            this->button18->ForeColor = System::Drawing::Color::White;
            this->button18->Location = System::Drawing::Point(3, 183);
            this->button18->Name = L"button18";
            this->button18->Size = System::Drawing::Size(267, 40);
            this->button18->TabIndex = 26;
            this->button18->Text = L"    Home";
            this->button18->UseVisualStyleBackColor = false;
            this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            // 
            // textBox10
            // 
            this->textBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox10->Location = System::Drawing::Point(254, 716);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(44, 25);
            this->textBox10->TabIndex = 25;
            this->textBox10->Text = L"◤";
            this->textBox10->Visible = false;
            // 
            // textBox11
            // 
            this->textBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox11->Location = System::Drawing::Point(254, 716);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(44, 25);
            this->textBox11->TabIndex = 21;
            this->textBox11->Text = L"◢";
            // 
            // textBox4
            // 
            this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox4->Location = System::Drawing::Point(254, 405);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(44, 25);
            this->textBox4->TabIndex = 15;
            this->textBox4->Text = L"◤";
            this->textBox4->Visible = false;
            this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
            // 
            // button13
            // 
            this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button13->FlatAppearance->BorderSize = 0;
            this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button13->ForeColor = System::Drawing::Color::White;
            this->button13->Location = System::Drawing::Point(-6, 782);
            this->button13->Margin = System::Windows::Forms::Padding(0);
            this->button13->Name = L"button13";
            this->button13->Size = System::Drawing::Size(267, 30);
            this->button13->TabIndex = 24;
            this->button13->Text = L"Edit                 ";
            this->button13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button13->UseVisualStyleBackColor = false;
            this->button13->Visible = false;
            // 
            // button14
            // 
            this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button14->FlatAppearance->BorderSize = 0;
            this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button14->ForeColor = System::Drawing::Color::White;
            this->button14->Location = System::Drawing::Point(-6, 752);
            this->button14->Margin = System::Windows::Forms::Padding(0);
            this->button14->Name = L"button14";
            this->button14->Size = System::Drawing::Size(267, 30);
            this->button14->TabIndex = 23;
            this->button14->Text = L"Add                 ";
            this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button14->UseVisualStyleBackColor = false;
            this->button14->Visible = false;
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
            this->button15->ForeColor = System::Drawing::Color::White;
            this->button15->Location = System::Drawing::Point(57, 710);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(267, 40);
            this->button15->TabIndex = 22;
            this->button15->Text = L"Classes";
            this->button15->UseVisualStyleBackColor = false;
            this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
            // 
            // textBox8
            // 
            this->textBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox8->Location = System::Drawing::Point(254, 625);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(44, 25);
            this->textBox8->TabIndex = 20;
            this->textBox8->Text = L"◤";
            this->textBox8->Visible = false;
            // 
            // textBox9
            // 
            this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox9->Location = System::Drawing::Point(254, 620);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(44, 25);
            this->textBox9->TabIndex = 16;
            this->textBox9->Text = L"◢";
            // 
            // button10
            // 
            this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button10->FlatAppearance->BorderSize = 0;
            this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button10->ForeColor = System::Drawing::Color::White;
            this->button10->Location = System::Drawing::Point(0, 686);
            this->button10->Margin = System::Windows::Forms::Padding(0);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(267, 30);
            this->button10->TabIndex = 19;
            this->button10->Text = L"Edit                 ";
            this->button10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button10->UseVisualStyleBackColor = false;
            this->button10->Visible = false;
            // 
            // button11
            // 
            this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button11->FlatAppearance->BorderSize = 0;
            this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button11->ForeColor = System::Drawing::Color::White;
            this->button11->Location = System::Drawing::Point(0, 656);
            this->button11->Margin = System::Windows::Forms::Padding(0);
            this->button11->Name = L"button11";
            this->button11->Size = System::Drawing::Size(267, 30);
            this->button11->TabIndex = 18;
            this->button11->Text = L"Add                 ";
            this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button11->UseVisualStyleBackColor = false;
            this->button11->Visible = false;
            this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
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
            this->button12->ForeColor = System::Drawing::Color::White;
            this->button12->Location = System::Drawing::Point(60, 610);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(267, 40);
            this->button12->TabIndex = 17;
            this->button12->Text = L"Subjects";
            this->button12->UseVisualStyleBackColor = false;
            this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
            // 
            // textBox6
            // 
            this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox6->Location = System::Drawing::Point(254, 512);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(44, 25);
            this->textBox6->TabIndex = 15;
            this->textBox6->Text = L"◤";
            this->textBox6->Visible = false;
            // 
            // textBox7
            // 
            this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox7->Location = System::Drawing::Point(254, 512);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(44, 25);
            this->textBox7->TabIndex = 11;
            this->textBox7->Text = L"◢";
            // 
            // textBox5
            // 
            this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox5->Location = System::Drawing::Point(254, 405);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(44, 25);
            this->textBox5->TabIndex = 11;
            this->textBox5->Text = L"◢";
            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button7->FlatAppearance->BorderSize = 0;
            this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button7->ForeColor = System::Drawing::Color::White;
            this->button7->Location = System::Drawing::Point(-3, 578);
            this->button7->Margin = System::Windows::Forms::Padding(0);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(267, 30);
            this->button7->TabIndex = 14;
            this->button7->Text = L"Edit                 ";
            this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Visible = false;
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button4->FlatAppearance->BorderSize = 0;
            this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button4->ForeColor = System::Drawing::Color::White;
            this->button4->Location = System::Drawing::Point(-3, 471);
            this->button4->Margin = System::Windows::Forms::Padding(0);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(267, 30);
            this->button4->TabIndex = 14;
            this->button4->Text = L"Edit                 ";
            this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Visible = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button8->FlatAppearance->BorderSize = 0;
            this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button8->ForeColor = System::Drawing::Color::White;
            this->button8->Location = System::Drawing::Point(-3, 548);
            this->button8->Margin = System::Windows::Forms::Padding(0);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(267, 30);
            this->button8->TabIndex = 13;
            this->button8->Text = L"Add                 ";
            this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Visible = false;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button5->FlatAppearance->BorderSize = 0;
            this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button5->ForeColor = System::Drawing::Color::White;
            this->button5->Location = System::Drawing::Point(-3, 441);
            this->button5->Margin = System::Windows::Forms::Padding(0);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(267, 30);
            this->button5->TabIndex = 13;
            this->button5->Text = L"Add                 ";
            this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button5->UseVisualStyleBackColor = false;
            this->button5->Visible = false;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
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
            this->button9->ForeColor = System::Drawing::Color::White;
            this->button9->Location = System::Drawing::Point(34, 504);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(292, 40);
            this->button9->TabIndex = 12;
            this->button9->Text = L"Teachers";
            this->button9->UseVisualStyleBackColor = false;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
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
            this->button6->ForeColor = System::Drawing::Color::White;
            this->button6->Location = System::Drawing::Point(34, 398);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(290, 40);
            this->button6->TabIndex = 12;
            this->button6->Text = L"Classrooms";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
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
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(34, 298);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(290, 40);
            this->button1->TabIndex = 2;
            this->button1->Text = L"Departments";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::White;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(178)));
            this->textBox1->Location = System::Drawing::Point(506, 44);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(488, 54);
            this->textBox1->TabIndex = 0;
            this->textBox1->Text = L"TIMETABLE ARCHITECT";
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(292, -4);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(207, 136);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::White;
            this->panel4->Controls->Add(this->textBox1);
            this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel4->Location = System::Drawing::Point(324, 0);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(1622, 132);
            this->panel4->TabIndex = 2;
            this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
            // 
            // textBox12
            // 
            this->textBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
            this->textBox12->Location = System::Drawing::Point(636, 295);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(304, 32);
            this->textBox12->TabIndex = 4;
            this->textBox12->Text = L"Department List";
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
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewButtonColumn1
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
            this->dataGridView2->Location = System::Drawing::Point(372, 348);
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
            this->dataGridView2->Size = System::Drawing::Size(735, 300);
            this->dataGridView2->TabIndex = 233;
            this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick_1);
            // 
            // dataGridViewTextBoxColumn1
            // 
            dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle3;
            this->dataGridViewTextBoxColumn1->HeaderText = L"Department";
            this->dataGridViewTextBoxColumn1->MinimumWidth = 30;
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle4;
            this->dataGridViewButtonColumn1->DividerWidth = 1;
            this->dataGridViewButtonColumn1->HeaderText = L"";
            this->dataGridViewButtonColumn1->MinimumWidth = 100;
            this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
            this->dataGridViewButtonColumn1->ReadOnly = true;
            this->dataGridViewButtonColumn1->Text = L"Delete";
            this->dataGridViewButtonColumn1->UseColumnTextForButtonValue = true;
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(1100, 743);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(121, 45);
            this->button2->TabIndex = 234;
            this->button2->Text = L"Save";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel2->Controls->Add(this->button2);
            this->panel2->Controls->Add(this->dataGridView2);
            this->panel2->Controls->Add(this->textBox12);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel2->Location = System::Drawing::Point(0, 0);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(1946, 1106);
            this->panel2->TabIndex = 5;
            this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
            // 
            // addclasspanel
            // 
            this->addclasspanel->AutoScroll = true;
            this->addclasspanel->Controls->Add(this->label15);
            this->addclasspanel->Controls->Add(this->label13);
            this->addclasspanel->Controls->Add(this->label12);
            this->addclasspanel->Controls->Add(this->label11);
            this->addclasspanel->Controls->Add(this->label4);
            this->addclasspanel->Controls->Add(this->label10);
            this->addclasspanel->Controls->Add(this->label9);
            this->addclasspanel->Controls->Add(this->label8);
            this->addclasspanel->Controls->Add(this->label7);
            this->addclasspanel->Controls->Add(this->label6);
            this->addclasspanel->Controls->Add(this->label5);
            this->addclasspanel->Controls->Add(this->buttons35);
            this->addclasspanel->Controls->Add(this->buttons34);
            this->addclasspanel->Controls->Add(this->buttons33);
            this->addclasspanel->Controls->Add(this->buttons32);
            this->addclasspanel->Controls->Add(this->buttons31);
            this->addclasspanel->Controls->Add(this->buttons29);
            this->addclasspanel->Controls->Add(this->buttons28);
            this->addclasspanel->Controls->Add(this->buttons27);
            this->addclasspanel->Controls->Add(this->buttons26);
            this->addclasspanel->Controls->Add(this->buttons25);
            this->addclasspanel->Controls->Add(this->buttons24);
            this->addclasspanel->Controls->Add(this->buttons23);
            this->addclasspanel->Controls->Add(this->buttons22);
            this->addclasspanel->Controls->Add(this->buttons21);
            this->addclasspanel->Controls->Add(this->buttons20);
            this->addclasspanel->Controls->Add(this->buttons19);
            this->addclasspanel->Controls->Add(this->buttons18);
            this->addclasspanel->Controls->Add(this->buttons17);
            this->addclasspanel->Controls->Add(this->buttons16);
            this->addclasspanel->Controls->Add(this->buttons15);
            this->addclasspanel->Controls->Add(this->buttons14);
            this->addclasspanel->Controls->Add(this->buttons13);
            this->addclasspanel->Controls->Add(this->buttons12);
            this->addclasspanel->Controls->Add(this->buttons11);
            this->addclasspanel->Controls->Add(this->buttons10);
            this->addclasspanel->Controls->Add(this->buttons9);
            this->addclasspanel->Controls->Add(this->buttons8);
            this->addclasspanel->Controls->Add(this->buttons7);
            this->addclasspanel->Controls->Add(this->buttons6);
            this->addclasspanel->Controls->Add(this->buttons5);
            this->addclasspanel->Controls->Add(this->buttons4);
            this->addclasspanel->Controls->Add(this->buttons3);
            this->addclasspanel->Controls->Add(this->buttons2);
            this->addclasspanel->Controls->Add(this->buttons1);
            this->addclasspanel->Controls->Add(this->label3);
            this->addclasspanel->Controls->Add(this->comboBox1);
            this->addclasspanel->Controls->Add(this->label2);
            this->addclasspanel->Controls->Add(this->textBox2);
            this->addclasspanel->Controls->Add(this->button37);
            this->addclasspanel->Controls->Add(this->button38);
            this->addclasspanel->Controls->Add(this->buttons30);
            this->addclasspanel->Controls->Add(this->buttons36);
            this->addclasspanel->Controls->Add(this->label1);
            this->addclasspanel->Controls->Add(this->label14);
            this->addclasspanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addclasspanel->Location = System::Drawing::Point(0, 0);
            this->addclasspanel->Name = L"addclasspanel";
            this->addclasspanel->Size = System::Drawing::Size(1946, 1106);
            this->addclasspanel->TabIndex = 175;
            this->addclasspanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint);
            // 
            // panel5
            // 
            this->panel5->AutoScroll = true;
            this->panel5->Controls->Add(this->dataGridView6);
            this->panel5->Controls->Add(this->label32);
            this->panel5->Controls->Add(this->label33);
            this->panel5->Controls->Add(this->dataGridView1);
            this->panel5->Controls->Add(this->dataGridView3);
            this->panel5->Controls->Add(this->button16);
            this->panel5->Controls->Add(this->button17);
            this->panel5->Controls->Add(this->button19);
            this->panel5->Controls->Add(this->label34);
            this->panel5->Controls->Add(this->checkedListBox1);
            this->panel5->Controls->Add(this->label35);
            this->panel5->Controls->Add(this->label36);
            this->panel5->Controls->Add(this->maskedTextBox1);
            this->panel5->Controls->Add(this->label37);
            this->panel5->Controls->Add(this->comboBox3);
            this->panel5->Controls->Add(this->maskedTextBox2);
            this->panel5->Controls->Add(this->label38);
            this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel5->Location = System::Drawing::Point(0, 0);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1946, 1106);
            this->panel5->TabIndex = 230;
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label32->Location = System::Drawing::Point(578, 1282);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(118, 28);
            this->label32->TabIndex = 256;
            this->label32->Text = L"Lab subjects";
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label33->Location = System::Drawing::Point(554, 952);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(153, 28);
            this->label33->TabIndex = 255;
            this->label33->Text = L"Elective subjects";
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToOrderColumns = true;
            dataGridViewCellStyle16->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle16->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle16->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle16;
            this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle17->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle17->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
            this->dataGridView1->ColumnHeadersHeight = 40;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn2,
                    this->dataGridViewButtonColumn2
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
            this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle20;
            this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->Location = System::Drawing::Point(539, 1335);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle21;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 62;
            dataGridViewCellStyle22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle22;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(735, 226);
            this->dataGridView1->TabIndex = 254;
            // 
            // dataGridViewComboBoxColumn2
            // 
            dataGridViewCellStyle18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn2->DefaultCellStyle = dataGridViewCellStyle18;
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
            dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle19->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle19;
            this->dataGridViewButtonColumn2->DividerWidth = 1;
            this->dataGridViewButtonColumn2->HeaderText = L"";
            this->dataGridViewButtonColumn2->MinimumWidth = 100;
            this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
            this->dataGridViewButtonColumn2->ReadOnly = true;
            this->dataGridViewButtonColumn2->Text = L"Delete";
            this->dataGridViewButtonColumn2->UseColumnTextForButtonValue = true;
            // 
            // dataGridView3
            // 
            this->dataGridView3->AllowUserToOrderColumns = true;
            dataGridViewCellStyle23->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle23->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle23->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle23;
            this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle24->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle24->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle24->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle24;
            this->dataGridView3->ColumnHeadersHeight = 40;
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn1,
                    this->dataGridViewButtonColumn3
            });
            dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle27->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle27->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView3->DefaultCellStyle = dataGridViewCellStyle27;
            this->dataGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->Location = System::Drawing::Point(555, 997);
            this->dataGridView3->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView3->Name = L"dataGridView3";
            dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle28->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle28->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle28->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->RowHeadersDefaultCellStyle = dataGridViewCellStyle28;
            this->dataGridView3->RowHeadersVisible = false;
            this->dataGridView3->RowHeadersWidth = 62;
            dataGridViewCellStyle29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->RowsDefaultCellStyle = dataGridViewCellStyle29;
            this->dataGridView3->RowTemplate->Height = 28;
            this->dataGridView3->Size = System::Drawing::Size(735, 226);
            this->dataGridView3->TabIndex = 253;
            // 
            // dataGridViewComboBoxColumn1
            // 
            dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->DefaultCellStyle = dataGridViewCellStyle25;
            this->dataGridViewComboBoxColumn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn1->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn1->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn1->Name = L"dataGridViewComboBoxColumn1";
            this->dataGridViewComboBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn3
            // 
            this->dataGridViewButtonColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle26->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle26->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle26;
            this->dataGridViewButtonColumn3->DividerWidth = 1;
            this->dataGridViewButtonColumn3->HeaderText = L"";
            this->dataGridViewButtonColumn3->MinimumWidth = 100;
            this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
            this->dataGridViewButtonColumn3->ReadOnly = true;
            this->dataGridViewButtonColumn3->Text = L"Delete";
            this->dataGridViewButtonColumn3->UseColumnTextForButtonValue = true;
            // 
            // button16
            // 
            this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button16->Location = System::Drawing::Point(1303, 1812);
            this->button16->Name = L"button16";
            this->button16->Size = System::Drawing::Size(132, 44);
            this->button16->TabIndex = 246;
            this->button16->Text = L"Add New";
            this->button16->UseVisualStyleBackColor = false;
            // 
            // button17
            // 
            this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button17->Location = System::Drawing::Point(1141, 1812);
            this->button17->Name = L"button17";
            this->button17->Size = System::Drawing::Size(104, 44);
            this->button17->TabIndex = 247;
            this->button17->Text = L"Save";
            this->button17->UseVisualStyleBackColor = false;
            // 
            // button19
            // 
            this->button19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button19->Location = System::Drawing::Point(947, 1812);
            this->button19->Name = L"button19";
            this->button19->Size = System::Drawing::Size(147, 44);
            this->button19->TabIndex = 248;
            this->button19->Text = L"Generate";
            this->button19->UseVisualStyleBackColor = false;
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label34->Location = System::Drawing::Point(565, 1571);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(142, 28);
            this->label34->TabIndex = 251;
            this->label34->Text = L"Default rooms";
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Location = System::Drawing::Point(558, 1613);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(287, 155);
            this->checkedListBox1->TabIndex = 250;
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label35->Location = System::Drawing::Point(554, 1195);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(124, 28);
            this->label35->TabIndex = 249;
            this->label35->Text = L"Lab subjects";
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->Location = System::Drawing::Point(553, 570);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(520, 84);
            this->label36->TabIndex = 243;
            this->label36->Text = L"Select the subjects taught and their corresponding teacher\r\n\r\n for non-elective a"
                L"nd non-lab subjects";
            // 
            // maskedTextBox1
            // 
            this->maskedTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox1->Location = System::Drawing::Point(559, 504);
            this->maskedTextBox1->Mask = L"0000";
            this->maskedTextBox1->Name = L"maskedTextBox1";
            this->maskedTextBox1->Size = System::Drawing::Size(401, 34);
            this->maskedTextBox1->TabIndex = 242;
            this->maskedTextBox1->ValidatingType = System::Int32::typeid;
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->Location = System::Drawing::Point(553, 447);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(225, 28);
            this->label37->TabIndex = 241;
            this->label37->Text = L"Batch(year of admission)";
            // 
            // comboBox3
            // 
            this->comboBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox3->FormattingEnabled = true;
            this->comboBox3->Location = System::Drawing::Point(559, 372);
            this->comboBox3->Name = L"comboBox3";
            this->comboBox3->Size = System::Drawing::Size(269, 36);
            this->comboBox3->TabIndex = 245;
            // 
            // maskedTextBox2
            // 
            this->maskedTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox2->Location = System::Drawing::Point(555, 242);
            this->maskedTextBox2->Mask = L"A";
            this->maskedTextBox2->Name = L"maskedTextBox2";
            this->maskedTextBox2->Size = System::Drawing::Size(434, 34);
            this->maskedTextBox2->TabIndex = 244;
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(549, 178);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(77, 28);
            this->label38->TabIndex = 240;
            this->label38->Text = L"Section";
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label15->Location = System::Drawing::Point(1078, 512);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(94, 28);
            this->label15->TabIndex = 229;
            this->label15->Text = L"3:30-4:30";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(860, 512);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(105, 28);
            this->label13->TabIndex = 227;
            this->label13->Text = L"12:30-1:30";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(736, 512);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(116, 28);
            this->label12->TabIndex = 226;
            this->label12->Text = L"11:30-12:30";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(604, 512);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(116, 28);
            this->label11->TabIndex = 225;
            this->label11->Text = L"10:00-11:00";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(484, 512);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(105, 28);
            this->label4->TabIndex = 224;
            this->label4->Text = L"9:00-10:00";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(347, 629);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(83, 28);
            this->label10->TabIndex = 223;
            this->label10->Text = L"Tuesday";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(323, 678);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(113, 28);
            this->label9->TabIndex = 222;
            this->label9->Text = L"Wednesday";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(337, 732);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(91, 28);
            this->label8->TabIndex = 221;
            this->label8->Text = L"Thursday";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(347, 779);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(66, 28);
            this->label7->TabIndex = 220;
            this->label7->Text = L"Friday";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(337, 842);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(90, 28);
            this->label6->TabIndex = 219;
            this->label6->Text = L"Saturday";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(347, 571);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(85, 28);
            this->label5->TabIndex = 218;
            this->label5->Text = L"Monday";
            // 
            // buttons35
            // 
            this->buttons35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons35->Location = System::Drawing::Point(961, 842);
            this->buttons35->Name = L"buttons35";
            this->buttons35->Size = System::Drawing::Size(98, 49);
            this->buttons35->TabIndex = 214;
            this->buttons35->Text = L"free";
            this->buttons35->UseVisualStyleBackColor = false;
            this->buttons35->Click += gcnew System::EventHandler(this, &MyForm::buttons35_Click);
            // 
            // buttons34
            // 
            this->buttons34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons34->Location = System::Drawing::Point(845, 842);
            this->buttons34->Name = L"buttons34";
            this->buttons34->Size = System::Drawing::Size(98, 49);
            this->buttons34->TabIndex = 213;
            this->buttons34->Text = L"free";
            this->buttons34->UseVisualStyleBackColor = false;
            this->buttons34->Click += gcnew System::EventHandler(this, &MyForm::buttons34_Click);
            // 
            // buttons33
            // 
            this->buttons33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons33->Location = System::Drawing::Point(726, 842);
            this->buttons33->Name = L"buttons33";
            this->buttons33->Size = System::Drawing::Size(98, 49);
            this->buttons33->TabIndex = 212;
            this->buttons33->Text = L"free";
            this->buttons33->UseVisualStyleBackColor = false;
            this->buttons33->Click += gcnew System::EventHandler(this, &MyForm::buttons33_Click);
            // 
            // buttons32
            // 
            this->buttons32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons32->Location = System::Drawing::Point(609, 842);
            this->buttons32->Name = L"buttons32";
            this->buttons32->Size = System::Drawing::Size(98, 49);
            this->buttons32->TabIndex = 211;
            this->buttons32->Text = L"free";
            this->buttons32->UseVisualStyleBackColor = false;
            this->buttons32->Click += gcnew System::EventHandler(this, &MyForm::buttons32_Click);
            // 
            // buttons31
            // 
            this->buttons31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons31->Location = System::Drawing::Point(488, 842);
            this->buttons31->Name = L"buttons31";
            this->buttons31->Size = System::Drawing::Size(98, 49);
            this->buttons31->TabIndex = 210;
            this->buttons31->Text = L"free";
            this->buttons31->UseVisualStyleBackColor = false;
            this->buttons31->Click += gcnew System::EventHandler(this, &MyForm::buttons31_Click);
            // 
            // buttons29
            // 
            this->buttons29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons29->Location = System::Drawing::Point(961, 787);
            this->buttons29->Name = L"buttons29";
            this->buttons29->Size = System::Drawing::Size(98, 49);
            this->buttons29->TabIndex = 208;
            this->buttons29->Text = L"free";
            this->buttons29->UseVisualStyleBackColor = false;
            this->buttons29->Click += gcnew System::EventHandler(this, &MyForm::buttons29_Click);
            // 
            // buttons28
            // 
            this->buttons28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons28->Location = System::Drawing::Point(845, 787);
            this->buttons28->Name = L"buttons28";
            this->buttons28->Size = System::Drawing::Size(98, 49);
            this->buttons28->TabIndex = 207;
            this->buttons28->Text = L"free";
            this->buttons28->UseVisualStyleBackColor = false;
            this->buttons28->Click += gcnew System::EventHandler(this, &MyForm::buttons28_Click);
            // 
            // buttons27
            // 
            this->buttons27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons27->Location = System::Drawing::Point(726, 787);
            this->buttons27->Name = L"buttons27";
            this->buttons27->Size = System::Drawing::Size(98, 49);
            this->buttons27->TabIndex = 206;
            this->buttons27->Text = L"free";
            this->buttons27->UseVisualStyleBackColor = false;
            this->buttons27->Click += gcnew System::EventHandler(this, &MyForm::buttons27_Click);
            // 
            // buttons26
            // 
            this->buttons26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons26->Location = System::Drawing::Point(609, 787);
            this->buttons26->Name = L"buttons26";
            this->buttons26->Size = System::Drawing::Size(98, 49);
            this->buttons26->TabIndex = 205;
            this->buttons26->Text = L"free";
            this->buttons26->UseVisualStyleBackColor = false;
            this->buttons26->Click += gcnew System::EventHandler(this, &MyForm::buttons26_Click);
            // 
            // buttons25
            // 
            this->buttons25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons25->Location = System::Drawing::Point(488, 787);
            this->buttons25->Name = L"buttons25";
            this->buttons25->Size = System::Drawing::Size(98, 49);
            this->buttons25->TabIndex = 204;
            this->buttons25->Text = L"free";
            this->buttons25->UseVisualStyleBackColor = false;
            this->buttons25->Click += gcnew System::EventHandler(this, &MyForm::buttons25_Click);
            // 
            // buttons24
            // 
            this->buttons24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons24->Location = System::Drawing::Point(1074, 732);
            this->buttons24->Name = L"buttons24";
            this->buttons24->Size = System::Drawing::Size(98, 49);
            this->buttons24->TabIndex = 203;
            this->buttons24->Text = L"free";
            this->buttons24->UseVisualStyleBackColor = false;
            this->buttons24->Click += gcnew System::EventHandler(this, &MyForm::buttons24_Click);
            // 
            // buttons23
            // 
            this->buttons23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons23->Location = System::Drawing::Point(961, 733);
            this->buttons23->Name = L"buttons23";
            this->buttons23->Size = System::Drawing::Size(98, 49);
            this->buttons23->TabIndex = 202;
            this->buttons23->Text = L"free";
            this->buttons23->UseVisualStyleBackColor = false;
            this->buttons23->Click += gcnew System::EventHandler(this, &MyForm::buttons23_Click);
            // 
            // buttons22
            // 
            this->buttons22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons22->Location = System::Drawing::Point(845, 732);
            this->buttons22->Name = L"buttons22";
            this->buttons22->Size = System::Drawing::Size(98, 49);
            this->buttons22->TabIndex = 201;
            this->buttons22->Text = L"free";
            this->buttons22->UseVisualStyleBackColor = false;
            this->buttons22->Click += gcnew System::EventHandler(this, &MyForm::buttons22_Click);
            // 
            // buttons21
            // 
            this->buttons21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons21->Location = System::Drawing::Point(726, 733);
            this->buttons21->Name = L"buttons21";
            this->buttons21->Size = System::Drawing::Size(98, 49);
            this->buttons21->TabIndex = 200;
            this->buttons21->Text = L"free";
            this->buttons21->UseVisualStyleBackColor = false;
            this->buttons21->Click += gcnew System::EventHandler(this, &MyForm::buttons21_Click);
            // 
            // buttons20
            // 
            this->buttons20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons20->Location = System::Drawing::Point(609, 733);
            this->buttons20->Name = L"buttons20";
            this->buttons20->Size = System::Drawing::Size(98, 49);
            this->buttons20->TabIndex = 199;
            this->buttons20->Text = L"free";
            this->buttons20->UseVisualStyleBackColor = false;
            this->buttons20->Click += gcnew System::EventHandler(this, &MyForm::buttons20_Click);
            // 
            // buttons19
            // 
            this->buttons19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons19->Location = System::Drawing::Point(488, 732);
            this->buttons19->Name = L"buttons19";
            this->buttons19->Size = System::Drawing::Size(98, 49);
            this->buttons19->TabIndex = 198;
            this->buttons19->Text = L"free";
            this->buttons19->UseVisualStyleBackColor = false;
            this->buttons19->Click += gcnew System::EventHandler(this, &MyForm::buttons19_Click);
            // 
            // buttons18
            // 
            this->buttons18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons18->Location = System::Drawing::Point(1074, 681);
            this->buttons18->Name = L"buttons18";
            this->buttons18->Size = System::Drawing::Size(98, 49);
            this->buttons18->TabIndex = 197;
            this->buttons18->Text = L"free";
            this->buttons18->UseVisualStyleBackColor = false;
            this->buttons18->Click += gcnew System::EventHandler(this, &MyForm::buttons18_Click);
            // 
            // buttons17
            // 
            this->buttons17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons17->Location = System::Drawing::Point(961, 678);
            this->buttons17->Name = L"buttons17";
            this->buttons17->Size = System::Drawing::Size(98, 49);
            this->buttons17->TabIndex = 196;
            this->buttons17->Text = L"free";
            this->buttons17->UseVisualStyleBackColor = false;
            this->buttons17->Click += gcnew System::EventHandler(this, &MyForm::buttons17_Click);
            // 
            // buttons16
            // 
            this->buttons16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons16->Location = System::Drawing::Point(845, 678);
            this->buttons16->Name = L"buttons16";
            this->buttons16->Size = System::Drawing::Size(98, 49);
            this->buttons16->TabIndex = 195;
            this->buttons16->Text = L"free";
            this->buttons16->UseVisualStyleBackColor = false;
            this->buttons16->Click += gcnew System::EventHandler(this, &MyForm::buttons16_Click);
            // 
            // buttons15
            // 
            this->buttons15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons15->Location = System::Drawing::Point(726, 678);
            this->buttons15->Name = L"buttons15";
            this->buttons15->Size = System::Drawing::Size(98, 49);
            this->buttons15->TabIndex = 194;
            this->buttons15->Text = L"free";
            this->buttons15->UseVisualStyleBackColor = false;
            this->buttons15->Click += gcnew System::EventHandler(this, &MyForm::buttons15_Click);
            // 
            // buttons14
            // 
            this->buttons14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons14->Location = System::Drawing::Point(609, 678);
            this->buttons14->Name = L"buttons14";
            this->buttons14->Size = System::Drawing::Size(98, 49);
            this->buttons14->TabIndex = 193;
            this->buttons14->Text = L"free";
            this->buttons14->UseVisualStyleBackColor = false;
            this->buttons14->Click += gcnew System::EventHandler(this, &MyForm::buttons14_Click);
            // 
            // buttons13
            // 
            this->buttons13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons13->Location = System::Drawing::Point(488, 678);
            this->buttons13->Name = L"buttons13";
            this->buttons13->Size = System::Drawing::Size(98, 49);
            this->buttons13->TabIndex = 192;
            this->buttons13->Text = L"free";
            this->buttons13->UseVisualStyleBackColor = false;
            this->buttons13->Click += gcnew System::EventHandler(this, &MyForm::buttons13_Click);
            // 
            // buttons12
            // 
            this->buttons12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons12->Location = System::Drawing::Point(1074, 626);
            this->buttons12->Name = L"buttons12";
            this->buttons12->Size = System::Drawing::Size(98, 49);
            this->buttons12->TabIndex = 191;
            this->buttons12->Text = L"free";
            this->buttons12->UseVisualStyleBackColor = false;
            this->buttons12->Click += gcnew System::EventHandler(this, &MyForm::buttons12_Click);
            // 
            // buttons11
            // 
            this->buttons11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons11->Location = System::Drawing::Point(961, 626);
            this->buttons11->Name = L"buttons11";
            this->buttons11->Size = System::Drawing::Size(98, 49);
            this->buttons11->TabIndex = 190;
            this->buttons11->Text = L"free";
            this->buttons11->UseVisualStyleBackColor = false;
            this->buttons11->Click += gcnew System::EventHandler(this, &MyForm::buttons11_Click);
            // 
            // buttons10
            // 
            this->buttons10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons10->Location = System::Drawing::Point(845, 626);
            this->buttons10->Name = L"buttons10";
            this->buttons10->Size = System::Drawing::Size(98, 49);
            this->buttons10->TabIndex = 189;
            this->buttons10->Text = L"free";
            this->buttons10->UseVisualStyleBackColor = false;
            this->buttons10->Click += gcnew System::EventHandler(this, &MyForm::buttons10_Click);
            // 
            // buttons9
            // 
            this->buttons9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons9->Location = System::Drawing::Point(726, 626);
            this->buttons9->Name = L"buttons9";
            this->buttons9->Size = System::Drawing::Size(98, 49);
            this->buttons9->TabIndex = 188;
            this->buttons9->Text = L"free";
            this->buttons9->UseVisualStyleBackColor = false;
            this->buttons9->Click += gcnew System::EventHandler(this, &MyForm::buttons9_Click);
            // 
            // buttons8
            // 
            this->buttons8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons8->Location = System::Drawing::Point(609, 626);
            this->buttons8->Name = L"buttons8";
            this->buttons8->Size = System::Drawing::Size(98, 49);
            this->buttons8->TabIndex = 187;
            this->buttons8->Text = L"free";
            this->buttons8->UseVisualStyleBackColor = false;
            this->buttons8->Click += gcnew System::EventHandler(this, &MyForm::buttons8_Click);
            // 
            // buttons7
            // 
            this->buttons7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons7->Location = System::Drawing::Point(488, 626);
            this->buttons7->Name = L"buttons7";
            this->buttons7->Size = System::Drawing::Size(98, 49);
            this->buttons7->TabIndex = 186;
            this->buttons7->Text = L"free";
            this->buttons7->UseVisualStyleBackColor = false;
            this->buttons7->Click += gcnew System::EventHandler(this, &MyForm::buttons7_Click);
            // 
            // buttons6
            // 
            this->buttons6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons6->Location = System::Drawing::Point(1074, 571);
            this->buttons6->Name = L"buttons6";
            this->buttons6->Size = System::Drawing::Size(98, 49);
            this->buttons6->TabIndex = 185;
            this->buttons6->Text = L"free";
            this->buttons6->UseVisualStyleBackColor = false;
            this->buttons6->Click += gcnew System::EventHandler(this, &MyForm::buttons6_Click);
            // 
            // buttons5
            // 
            this->buttons5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons5->Location = System::Drawing::Point(961, 571);
            this->buttons5->Name = L"buttons5";
            this->buttons5->Size = System::Drawing::Size(98, 49);
            this->buttons5->TabIndex = 184;
            this->buttons5->Text = L"free";
            this->buttons5->UseVisualStyleBackColor = false;
            this->buttons5->Click += gcnew System::EventHandler(this, &MyForm::buttons5_Click);
            // 
            // buttons4
            // 
            this->buttons4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons4->Location = System::Drawing::Point(845, 571);
            this->buttons4->Name = L"buttons4";
            this->buttons4->Size = System::Drawing::Size(98, 49);
            this->buttons4->TabIndex = 183;
            this->buttons4->Text = L"free";
            this->buttons4->UseVisualStyleBackColor = false;
            this->buttons4->Click += gcnew System::EventHandler(this, &MyForm::buttons4_Click);
            // 
            // buttons3
            // 
            this->buttons3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons3->Location = System::Drawing::Point(726, 571);
            this->buttons3->Name = L"buttons3";
            this->buttons3->Size = System::Drawing::Size(98, 49);
            this->buttons3->TabIndex = 182;
            this->buttons3->Text = L"free";
            this->buttons3->UseVisualStyleBackColor = false;
            this->buttons3->Click += gcnew System::EventHandler(this, &MyForm::buttons3_Click);
            // 
            // buttons2
            // 
            this->buttons2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons2->Location = System::Drawing::Point(609, 571);
            this->buttons2->Name = L"buttons2";
            this->buttons2->Size = System::Drawing::Size(98, 49);
            this->buttons2->TabIndex = 181;
            this->buttons2->Text = L"free";
            this->buttons2->UseVisualStyleBackColor = false;
            this->buttons2->Click += gcnew System::EventHandler(this, &MyForm::buttons2_Click);
            // 
            // buttons1
            // 
            this->buttons1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons1->Location = System::Drawing::Point(488, 571);
            this->buttons1->Name = L"buttons1";
            this->buttons1->Size = System::Drawing::Size(98, 49);
            this->buttons1->TabIndex = 180;
            this->buttons1->Text = L"free";
            this->buttons1->UseVisualStyleBackColor = false;
            this->buttons1->Click += gcnew System::EventHandler(this, &MyForm::buttons1_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(337, 425);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(161, 28);
            this->label3->TabIndex = 179;
            this->label3->Text = L"Teacher Schedule";
            // 
            // comboBox1
            // 
            this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(341, 328);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(362, 36);
            this->comboBox1->TabIndex = 178;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(342, 283);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(198, 28);
            this->label2->TabIndex = 177;
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
            this->textBox2->Location = System::Drawing::Point(341, 202);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(361, 27);
            this->textBox2->TabIndex = 176;
            // 
            // button37
            // 
            this->button37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button37->Location = System::Drawing::Point(999, 960);
            this->button37->Name = L"button37";
            this->button37->Size = System::Drawing::Size(121, 45);
            this->button37->TabIndex = 217;
            this->button37->Text = L"Save";
            this->button37->UseVisualStyleBackColor = false;
            this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click_1);
            // 
            // button38
            // 
            this->button38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button38->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button38->Location = System::Drawing::Point(1180, 960);
            this->button38->Name = L"button38";
            this->button38->Size = System::Drawing::Size(121, 45);
            this->button38->TabIndex = 216;
            this->button38->Text = L"Add";
            this->button38->UseVisualStyleBackColor = false;
            this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click_1);
            // 
            // buttons30
            // 
            this->buttons30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons30->Location = System::Drawing::Point(1074, 787);
            this->buttons30->Name = L"buttons30";
            this->buttons30->Size = System::Drawing::Size(98, 49);
            this->buttons30->TabIndex = 209;
            this->buttons30->Text = L"free";
            this->buttons30->UseVisualStyleBackColor = false;
            this->buttons30->Click += gcnew System::EventHandler(this, &MyForm::buttons30_Click);
            // 
            // buttons36
            // 
            this->buttons36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons36->Location = System::Drawing::Point(1074, 842);
            this->buttons36->Name = L"buttons36";
            this->buttons36->Size = System::Drawing::Size(98, 49);
            this->buttons36->TabIndex = 215;
            this->buttons36->Text = L"free";
            this->buttons36->UseVisualStyleBackColor = false;
            this->buttons36->Click += gcnew System::EventHandler(this, &MyForm::buttons36_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(337, 156);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(179, 28);
            this->label1->TabIndex = 175;
            this->label1->Text = L"Enter teacher name";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(970, 512);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(94, 28);
            this->label14->TabIndex = 228;
            this->label14->Text = L"2:30-3:30";
            // 
            // addclassroompanel
            // 
            this->addclassroompanel->AutoScroll = true;
            this->addclassroompanel->Controls->Add(this->groupBox1);
            this->addclassroompanel->Controls->Add(this->button3);
            this->addclassroompanel->Controls->Add(this->label16);
            this->addclassroompanel->Controls->Add(this->label17);
            this->addclassroompanel->Controls->Add(this->label18);
            this->addclassroompanel->Controls->Add(this->label19);
            this->addclassroompanel->Controls->Add(this->label20);
            this->addclassroompanel->Controls->Add(this->label21);
            this->addclassroompanel->Controls->Add(this->label22);
            this->addclassroompanel->Controls->Add(this->label23);
            this->addclassroompanel->Controls->Add(this->label24);
            this->addclassroompanel->Controls->Add(this->label25);
            this->addclassroompanel->Controls->Add(this->label26);
            this->addclassroompanel->Controls->Add(this->label27);
            this->addclassroompanel->Controls->Add(this->buttona36);
            this->addclassroompanel->Controls->Add(this->buttona35);
            this->addclassroompanel->Controls->Add(this->buttona34);
            this->addclassroompanel->Controls->Add(this->buttona33);
            this->addclassroompanel->Controls->Add(this->buttona32);
            this->addclassroompanel->Controls->Add(this->buttona31);
            this->addclassroompanel->Controls->Add(this->buttona30);
            this->addclassroompanel->Controls->Add(this->buttona29);
            this->addclassroompanel->Controls->Add(this->buttona28);
            this->addclassroompanel->Controls->Add(this->buttona27);
            this->addclassroompanel->Controls->Add(this->buttona26);
            this->addclassroompanel->Controls->Add(this->buttona25);
            this->addclassroompanel->Controls->Add(this->buttona24);
            this->addclassroompanel->Controls->Add(this->buttona23);
            this->addclassroompanel->Controls->Add(this->buttona22);
            this->addclassroompanel->Controls->Add(this->buttona21);
            this->addclassroompanel->Controls->Add(this->buttona20);
            this->addclassroompanel->Controls->Add(this->buttona19);
            this->addclassroompanel->Controls->Add(this->buttona18);
            this->addclassroompanel->Controls->Add(this->buttona17);
            this->addclassroompanel->Controls->Add(this->buttona16);
            this->addclassroompanel->Controls->Add(this->buttona15);
            this->addclassroompanel->Controls->Add(this->buttona14);
            this->addclassroompanel->Controls->Add(this->buttona13);
            this->addclassroompanel->Controls->Add(this->buttona12);
            this->addclassroompanel->Controls->Add(this->buttona11);
            this->addclassroompanel->Controls->Add(this->buttona10);
            this->addclassroompanel->Controls->Add(this->buttona9);
            this->addclassroompanel->Controls->Add(this->buttona8);
            this->addclassroompanel->Controls->Add(this->buttona7);
            this->addclassroompanel->Controls->Add(this->buttona6);
            this->addclassroompanel->Controls->Add(this->buttona5);
            this->addclassroompanel->Controls->Add(this->buttona4);
            this->addclassroompanel->Controls->Add(this->buttona3);
            this->addclassroompanel->Controls->Add(this->buttona2);
            this->addclassroompanel->Controls->Add(this->buttona1);
            this->addclassroompanel->Controls->Add(this->comboBox2);
            this->addclassroompanel->Controls->Add(this->label28);
            this->addclassroompanel->Controls->Add(this->label29);
            this->addclassroompanel->Controls->Add(this->label30);
            this->addclassroompanel->Controls->Add(this->numericUpDown1);
            this->addclassroompanel->Controls->Add(this->textBox3);
            this->addclassroompanel->Controls->Add(this->label31);
            this->addclassroompanel->Controls->Add(this->Save);
            this->addclassroompanel->Controls->Add(this->Back);
            this->addclassroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addclassroompanel->Location = System::Drawing::Point(0, 0);
            this->addclassroompanel->Name = L"addclassroompanel";
            this->addclassroompanel->Size = System::Drawing::Size(1946, 1106);
            this->addclassroompanel->TabIndex = 230;
            this->addclassroompanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addclassroompanel_Paint);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->radioButton2);
            this->groupBox1->Controls->Add(this->radioButton1);
            this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groupBox1->Location = System::Drawing::Point(172, 385);
            this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBox1->Size = System::Drawing::Size(269, 57);
            this->groupBox1->TabIndex = 123;
            this->groupBox1->TabStop = false;
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Location = System::Drawing::Point(164, 20);
            this->radioButton2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(64, 32);
            this->radioButton2->TabIndex = 9;
            this->radioButton2->TabStop = true;
            this->radioButton2->Text = L"No";
            this->radioButton2->UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Location = System::Drawing::Point(24, 20);
            this->radioButton1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(64, 32);
            this->radioButton1->TabIndex = 8;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Yes";
            this->radioButton1->UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button3->Location = System::Drawing::Point(945, 1153);
            this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(138, 54);
            this->button3->TabIndex = 122;
            this->button3->Text = L"Add";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(337, 575);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(105, 28);
            this->label16->TabIndex = 121;
            this->label16->Text = L"9:00-10:00";
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label17->Location = System::Drawing::Point(500, 575);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(116, 28);
            this->label17->TabIndex = 120;
            this->label17->Text = L"10:00-11:00";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(652, 575);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(116, 28);
            this->label18->TabIndex = 119;
            this->label18->Text = L"11:30-12:30";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label19->Location = System::Drawing::Point(812, 575);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(105, 28);
            this->label19->TabIndex = 118;
            this->label19->Text = L"12:30-1:30";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(975, 575);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(94, 28);
            this->label20->TabIndex = 117;
            this->label20->Text = L"2:30-3:30";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->Location = System::Drawing::Point(1120, 575);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(94, 28);
            this->label21->TabIndex = 116;
            this->label21->Text = L"3:30-4:30";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(189, 649);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(85, 28);
            this->label22->TabIndex = 115;
            this->label22->Text = L"Monday";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(194, 710);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(83, 28);
            this->label23->TabIndex = 114;
            this->label23->Text = L"Tuesday";
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(181, 772);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(113, 28);
            this->label24->TabIndex = 113;
            this->label24->Text = L"Wednesday";
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label25->Location = System::Drawing::Point(181, 835);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(91, 28);
            this->label25->TabIndex = 112;
            this->label25->Text = L"Thursday";
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(197, 892);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(66, 28);
            this->label26->TabIndex = 111;
            this->label26->Text = L"Friday";
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label27->Location = System::Drawing::Point(189, 950);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(90, 28);
            this->label27->TabIndex = 110;
            this->label27->Text = L"Saturday";
            // 
            // buttona36
            // 
            this->buttona36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona36->Location = System::Drawing::Point(1115, 946);
            this->buttona36->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona36->Name = L"buttona36";
            this->buttona36->Size = System::Drawing::Size(138, 54);
            this->buttona36->TabIndex = 109;
            this->buttona36->Text = L"free";
            this->buttona36->UseVisualStyleBackColor = false;
            this->buttona36->Click += gcnew System::EventHandler(this, &MyForm::buttona36_Click);
            // 
            // buttona35
            // 
            this->buttona35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona35->Location = System::Drawing::Point(955, 945);
            this->buttona35->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona35->Name = L"buttona35";
            this->buttona35->Size = System::Drawing::Size(138, 54);
            this->buttona35->TabIndex = 108;
            this->buttona35->Text = L"free";
            this->buttona35->UseVisualStyleBackColor = false;
            this->buttona35->Click += gcnew System::EventHandler(this, &MyForm::buttona35_Click);
            // 
            // buttona34
            // 
            this->buttona34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona34->Location = System::Drawing::Point(797, 945);
            this->buttona34->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona34->Name = L"buttona34";
            this->buttona34->Size = System::Drawing::Size(138, 54);
            this->buttona34->TabIndex = 107;
            this->buttona34->Text = L"free";
            this->buttona34->UseVisualStyleBackColor = false;
            this->buttona34->Click += gcnew System::EventHandler(this, &MyForm::buttona34_Click);
            // 
            // buttona33
            // 
            this->buttona33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona33->Location = System::Drawing::Point(636, 945);
            this->buttona33->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona33->Name = L"buttona33";
            this->buttona33->Size = System::Drawing::Size(138, 54);
            this->buttona33->TabIndex = 106;
            this->buttona33->Text = L"free";
            this->buttona33->UseVisualStyleBackColor = false;
            this->buttona33->Click += gcnew System::EventHandler(this, &MyForm::buttona33_Click);
            // 
            // buttona32
            // 
            this->buttona32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona32->Location = System::Drawing::Point(482, 946);
            this->buttona32->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona32->Name = L"buttona32";
            this->buttona32->Size = System::Drawing::Size(138, 54);
            this->buttona32->TabIndex = 105;
            this->buttona32->Text = L"free";
            this->buttona32->UseVisualStyleBackColor = false;
            this->buttona32->Click += gcnew System::EventHandler(this, &MyForm::buttona32_Click);
            // 
            // buttona31
            // 
            this->buttona31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona31->Location = System::Drawing::Point(324, 946);
            this->buttona31->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona31->Name = L"buttona31";
            this->buttona31->Size = System::Drawing::Size(138, 54);
            this->buttona31->TabIndex = 104;
            this->buttona31->Text = L"free";
            this->buttona31->UseVisualStyleBackColor = false;
            this->buttona31->Click += gcnew System::EventHandler(this, &MyForm::buttona31_Click);
            // 
            // buttona30
            // 
            this->buttona30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona30->Location = System::Drawing::Point(1115, 884);
            this->buttona30->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona30->Name = L"buttona30";
            this->buttona30->Size = System::Drawing::Size(138, 54);
            this->buttona30->TabIndex = 103;
            this->buttona30->Text = L"free";
            this->buttona30->UseVisualStyleBackColor = false;
            this->buttona30->Click += gcnew System::EventHandler(this, &MyForm::buttona30_Click);
            // 
            // buttona29
            // 
            this->buttona29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona29->Location = System::Drawing::Point(955, 879);
            this->buttona29->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona29->Name = L"buttona29";
            this->buttona29->Size = System::Drawing::Size(138, 54);
            this->buttona29->TabIndex = 102;
            this->buttona29->Text = L"free";
            this->buttona29->UseVisualStyleBackColor = false;
            this->buttona29->Click += gcnew System::EventHandler(this, &MyForm::buttona29_Click);
            // 
            // buttona28
            // 
            this->buttona28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona28->Location = System::Drawing::Point(797, 879);
            this->buttona28->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona28->Name = L"buttona28";
            this->buttona28->Size = System::Drawing::Size(138, 54);
            this->buttona28->TabIndex = 101;
            this->buttona28->Text = L"free";
            this->buttona28->UseVisualStyleBackColor = false;
            this->buttona28->Click += gcnew System::EventHandler(this, &MyForm::buttona28_Click);
            // 
            // buttona27
            // 
            this->buttona27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona27->Location = System::Drawing::Point(636, 879);
            this->buttona27->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona27->Name = L"buttona27";
            this->buttona27->Size = System::Drawing::Size(138, 54);
            this->buttona27->TabIndex = 100;
            this->buttona27->Text = L"free";
            this->buttona27->UseVisualStyleBackColor = false;
            this->buttona27->Click += gcnew System::EventHandler(this, &MyForm::buttona27_Click);
            // 
            // buttona26
            // 
            this->buttona26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona26->Location = System::Drawing::Point(482, 880);
            this->buttona26->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona26->Name = L"buttona26";
            this->buttona26->Size = System::Drawing::Size(138, 54);
            this->buttona26->TabIndex = 99;
            this->buttona26->Text = L"free";
            this->buttona26->UseVisualStyleBackColor = false;
            this->buttona26->Click += gcnew System::EventHandler(this, &MyForm::buttona26_Click);
            // 
            // buttona25
            // 
            this->buttona25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona25->Location = System::Drawing::Point(324, 880);
            this->buttona25->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona25->Name = L"buttona25";
            this->buttona25->Size = System::Drawing::Size(138, 54);
            this->buttona25->TabIndex = 98;
            this->buttona25->Text = L"free";
            this->buttona25->UseVisualStyleBackColor = false;
            this->buttona25->Click += gcnew System::EventHandler(this, &MyForm::buttona25_Click);
            // 
            // buttona24
            // 
            this->buttona24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona24->Location = System::Drawing::Point(1115, 822);
            this->buttona24->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona24->Name = L"buttona24";
            this->buttona24->Size = System::Drawing::Size(138, 54);
            this->buttona24->TabIndex = 97;
            this->buttona24->Text = L"free";
            this->buttona24->UseVisualStyleBackColor = false;
            this->buttona24->Click += gcnew System::EventHandler(this, &MyForm::buttona24_Click);
            // 
            // buttona23
            // 
            this->buttona23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona23->Location = System::Drawing::Point(955, 821);
            this->buttona23->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona23->Name = L"buttona23";
            this->buttona23->Size = System::Drawing::Size(138, 54);
            this->buttona23->TabIndex = 96;
            this->buttona23->Text = L"free";
            this->buttona23->UseVisualStyleBackColor = false;
            this->buttona23->Click += gcnew System::EventHandler(this, &MyForm::buttona23_Click);
            // 
            // buttona22
            // 
            this->buttona22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona22->Location = System::Drawing::Point(797, 821);
            this->buttona22->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona22->Name = L"buttona22";
            this->buttona22->Size = System::Drawing::Size(138, 54);
            this->buttona22->TabIndex = 95;
            this->buttona22->Text = L"free";
            this->buttona22->UseVisualStyleBackColor = false;
            this->buttona22->Click += gcnew System::EventHandler(this, &MyForm::buttona22_Click);
            // 
            // buttona21
            // 
            this->buttona21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona21->Location = System::Drawing::Point(636, 821);
            this->buttona21->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona21->Name = L"buttona21";
            this->buttona21->Size = System::Drawing::Size(138, 54);
            this->buttona21->TabIndex = 94;
            this->buttona21->Text = L"free";
            this->buttona21->UseVisualStyleBackColor = false;
            this->buttona21->Click += gcnew System::EventHandler(this, &MyForm::buttona21_Click);
            // 
            // buttona20
            // 
            this->buttona20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona20->Location = System::Drawing::Point(482, 822);
            this->buttona20->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona20->Name = L"buttona20";
            this->buttona20->Size = System::Drawing::Size(138, 54);
            this->buttona20->TabIndex = 93;
            this->buttona20->Text = L"free";
            this->buttona20->UseVisualStyleBackColor = false;
            this->buttona20->Click += gcnew System::EventHandler(this, &MyForm::buttona20_Click);
            // 
            // buttona19
            // 
            this->buttona19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona19->Location = System::Drawing::Point(323, 822);
            this->buttona19->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona19->Name = L"buttona19";
            this->buttona19->Size = System::Drawing::Size(138, 54);
            this->buttona19->TabIndex = 92;
            this->buttona19->Text = L"free";
            this->buttona19->UseVisualStyleBackColor = false;
            this->buttona19->Click += gcnew System::EventHandler(this, &MyForm::buttona19_Click);
            // 
            // buttona18
            // 
            this->buttona18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona18->Location = System::Drawing::Point(1115, 760);
            this->buttona18->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona18->Name = L"buttona18";
            this->buttona18->Size = System::Drawing::Size(138, 54);
            this->buttona18->TabIndex = 91;
            this->buttona18->Text = L"free";
            this->buttona18->UseVisualStyleBackColor = false;
            this->buttona18->Click += gcnew System::EventHandler(this, &MyForm::buttona18_Click);
            // 
            // buttona17
            // 
            this->buttona17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona17->Location = System::Drawing::Point(955, 759);
            this->buttona17->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona17->Name = L"buttona17";
            this->buttona17->Size = System::Drawing::Size(138, 54);
            this->buttona17->TabIndex = 90;
            this->buttona17->Text = L"free";
            this->buttona17->UseVisualStyleBackColor = false;
            this->buttona17->Click += gcnew System::EventHandler(this, &MyForm::buttona17_Click);
            // 
            // buttona16
            // 
            this->buttona16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona16->Location = System::Drawing::Point(797, 759);
            this->buttona16->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona16->Name = L"buttona16";
            this->buttona16->Size = System::Drawing::Size(138, 54);
            this->buttona16->TabIndex = 89;
            this->buttona16->Text = L"free";
            this->buttona16->UseVisualStyleBackColor = false;
            this->buttona16->Click += gcnew System::EventHandler(this, &MyForm::buttona16_Click);
            // 
            // buttona15
            // 
            this->buttona15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona15->Location = System::Drawing::Point(636, 759);
            this->buttona15->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona15->Name = L"buttona15";
            this->buttona15->Size = System::Drawing::Size(138, 54);
            this->buttona15->TabIndex = 88;
            this->buttona15->Text = L"free";
            this->buttona15->UseVisualStyleBackColor = false;
            this->buttona15->Click += gcnew System::EventHandler(this, &MyForm::buttona15_Click);
            // 
            // buttona14
            // 
            this->buttona14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona14->Location = System::Drawing::Point(482, 760);
            this->buttona14->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona14->Name = L"buttona14";
            this->buttona14->Size = System::Drawing::Size(138, 54);
            this->buttona14->TabIndex = 87;
            this->buttona14->Text = L"free";
            this->buttona14->UseVisualStyleBackColor = false;
            this->buttona14->Click += gcnew System::EventHandler(this, &MyForm::buttona14_Click);
            // 
            // buttona13
            // 
            this->buttona13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona13->Location = System::Drawing::Point(323, 760);
            this->buttona13->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona13->Name = L"buttona13";
            this->buttona13->Size = System::Drawing::Size(138, 54);
            this->buttona13->TabIndex = 86;
            this->buttona13->Text = L"free";
            this->buttona13->UseVisualStyleBackColor = false;
            this->buttona13->Click += gcnew System::EventHandler(this, &MyForm::buttona13_Click);
            // 
            // buttona12
            // 
            this->buttona12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona12->Location = System::Drawing::Point(1115, 698);
            this->buttona12->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona12->Name = L"buttona12";
            this->buttona12->Size = System::Drawing::Size(138, 54);
            this->buttona12->TabIndex = 85;
            this->buttona12->Text = L"free";
            this->buttona12->UseVisualStyleBackColor = false;
            this->buttona12->Click += gcnew System::EventHandler(this, &MyForm::buttona12_Click);
            // 
            // buttona11
            // 
            this->buttona11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona11->Location = System::Drawing::Point(955, 697);
            this->buttona11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona11->Name = L"buttona11";
            this->buttona11->Size = System::Drawing::Size(138, 54);
            this->buttona11->TabIndex = 84;
            this->buttona11->Text = L"free";
            this->buttona11->UseVisualStyleBackColor = false;
            this->buttona11->Click += gcnew System::EventHandler(this, &MyForm::buttona11_Click);
            // 
            // buttona10
            // 
            this->buttona10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona10->Location = System::Drawing::Point(797, 697);
            this->buttona10->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona10->Name = L"buttona10";
            this->buttona10->Size = System::Drawing::Size(138, 54);
            this->buttona10->TabIndex = 83;
            this->buttona10->Text = L"free";
            this->buttona10->UseVisualStyleBackColor = false;
            this->buttona10->Click += gcnew System::EventHandler(this, &MyForm::buttona10_Click);
            // 
            // buttona9
            // 
            this->buttona9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona9->Location = System::Drawing::Point(636, 697);
            this->buttona9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona9->Name = L"buttona9";
            this->buttona9->Size = System::Drawing::Size(138, 54);
            this->buttona9->TabIndex = 82;
            this->buttona9->Text = L"free";
            this->buttona9->UseVisualStyleBackColor = false;
            this->buttona9->Click += gcnew System::EventHandler(this, &MyForm::buttona9_Click);
            // 
            // buttona8
            // 
            this->buttona8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona8->Location = System::Drawing::Point(482, 698);
            this->buttona8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona8->Name = L"buttona8";
            this->buttona8->Size = System::Drawing::Size(138, 54);
            this->buttona8->TabIndex = 81;
            this->buttona8->Text = L"free";
            this->buttona8->UseVisualStyleBackColor = false;
            this->buttona8->Click += gcnew System::EventHandler(this, &MyForm::buttona8_Click);
            // 
            // buttona7
            // 
            this->buttona7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona7->Location = System::Drawing::Point(324, 698);
            this->buttona7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona7->Name = L"buttona7";
            this->buttona7->Size = System::Drawing::Size(138, 54);
            this->buttona7->TabIndex = 80;
            this->buttona7->Text = L"free";
            this->buttona7->UseVisualStyleBackColor = false;
            this->buttona7->Click += gcnew System::EventHandler(this, &MyForm::buttona7_Click);
            // 
            // buttona6
            // 
            this->buttona6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona6->Location = System::Drawing::Point(1115, 638);
            this->buttona6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona6->Name = L"buttona6";
            this->buttona6->Size = System::Drawing::Size(138, 54);
            this->buttona6->TabIndex = 79;
            this->buttona6->Text = L"free";
            this->buttona6->UseVisualStyleBackColor = false;
            this->buttona6->Click += gcnew System::EventHandler(this, &MyForm::buttona6_Click);
            // 
            // buttona5
            // 
            this->buttona5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona5->Location = System::Drawing::Point(955, 637);
            this->buttona5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona5->Name = L"buttona5";
            this->buttona5->Size = System::Drawing::Size(138, 54);
            this->buttona5->TabIndex = 78;
            this->buttona5->Text = L"free";
            this->buttona5->UseVisualStyleBackColor = false;
            this->buttona5->Click += gcnew System::EventHandler(this, &MyForm::buttona5_Click);
            // 
            // buttona4
            // 
            this->buttona4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona4->Location = System::Drawing::Point(797, 637);
            this->buttona4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona4->Name = L"buttona4";
            this->buttona4->Size = System::Drawing::Size(138, 54);
            this->buttona4->TabIndex = 77;
            this->buttona4->Text = L"free";
            this->buttona4->UseVisualStyleBackColor = false;
            this->buttona4->Click += gcnew System::EventHandler(this, &MyForm::buttona4_Click);
            // 
            // buttona3
            // 
            this->buttona3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona3->Location = System::Drawing::Point(636, 637);
            this->buttona3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona3->Name = L"buttona3";
            this->buttona3->Size = System::Drawing::Size(138, 54);
            this->buttona3->TabIndex = 76;
            this->buttona3->Text = L"free";
            this->buttona3->UseVisualStyleBackColor = false;
            this->buttona3->Click += gcnew System::EventHandler(this, &MyForm::buttona3_Click);
            // 
            // buttona2
            // 
            this->buttona2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona2->Location = System::Drawing::Point(482, 636);
            this->buttona2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona2->Name = L"buttona2";
            this->buttona2->Size = System::Drawing::Size(138, 54);
            this->buttona2->TabIndex = 75;
            this->buttona2->Text = L"free";
            this->buttona2->UseVisualStyleBackColor = false;
            this->buttona2->Click += gcnew System::EventHandler(this, &MyForm::buttona2_Click);
            // 
            // buttona1
            // 
            this->buttona1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttona1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttona1->Location = System::Drawing::Point(323, 636);
            this->buttona1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttona1->Name = L"buttona1";
            this->buttona1->Size = System::Drawing::Size(138, 54);
            this->buttona1->TabIndex = 74;
            this->buttona1->Text = L"free";
            this->buttona1->UseVisualStyleBackColor = false;
            this->buttona1->Click += gcnew System::EventHandler(this, &MyForm::buttona1_Click);
            // 
            // comboBox2
            // 
            this->comboBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Location = System::Drawing::Point(172, 503);
            this->comboBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(294, 36);
            this->comboBox2->TabIndex = 73;
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label28->Location = System::Drawing::Point(169, 464);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(117, 28);
            this->label28->TabIndex = 72;
            this->label28->Text = L"Department";
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label29->Location = System::Drawing::Point(175, 344);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(98, 28);
            this->label29->TabIndex = 71;
            this->label29->Text = L"Is it a lab\?";
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(175, 230);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(158, 28);
            this->label30->TabIndex = 70;
            this->label30->Text = L"Capacity of Class";
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->numericUpDown1->Location = System::Drawing::Point(179, 279);
            this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(300, 34);
            this->numericUpDown1->TabIndex = 69;
            // 
            // textBox3
            // 
            this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox3->Location = System::Drawing::Point(174, 169);
            this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(295, 34);
            this->textBox3->TabIndex = 68;
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label31->Location = System::Drawing::Point(170, 108);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(164, 28);
            this->label31->TabIndex = 67;
            this->label31->Text = L"ClassRoom Name";
            // 
            // Save
            // 
            this->Save->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->Save->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->Save->Location = System::Drawing::Point(727, 1153);
            this->Save->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Save->Name = L"Save";
            this->Save->Size = System::Drawing::Size(138, 54);
            this->Save->TabIndex = 66;
            this->Save->Text = L"Save";
            this->Save->UseVisualStyleBackColor = false;
            this->Save->Click += gcnew System::EventHandler(this, &MyForm::Save_Click);
            // 
            // Back
            // 
            this->Back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->Back->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Back->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->Back->Location = System::Drawing::Point(1160, 1153);
            this->Back->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Back->Name = L"Back";
            this->Back->Size = System::Drawing::Size(138, 54);
            this->Back->TabIndex = 65;
            this->Back->Text = L"Back";
            this->Back->UseVisualStyleBackColor = false;
            // 
            // addsubjectpanel
            // 
            this->addsubjectpanel->AutoScroll = true;
            this->addsubjectpanel->Controls->Add(this->newaddsub);
            this->addsubjectpanel->Controls->Add(this->checkedListBox2);
            this->addsubjectpanel->Controls->Add(this->addsubsave);
            this->addsubjectpanel->Controls->Add(this->numericUpDown4);
            this->addsubjectpanel->Controls->Add(this->label41);
            this->addsubjectpanel->Controls->Add(this->label42);
            this->addsubjectpanel->Controls->Add(this->label43);
            this->addsubjectpanel->Controls->Add(this->numericUpDown5);
            this->addsubjectpanel->Controls->Add(this->dataGridView4);
            this->addsubjectpanel->Controls->Add(this->label44);
            this->addsubjectpanel->Controls->Add(this->groupBox4);
            this->addsubjectpanel->Controls->Add(this->label45);
            this->addsubjectpanel->Controls->Add(this->label46);
            this->addsubjectpanel->Controls->Add(this->dataGridView5);
            this->addsubjectpanel->Controls->Add(this->groupBox5);
            this->addsubjectpanel->Controls->Add(this->textBox15);
            this->addsubjectpanel->Controls->Add(this->label47);
            this->addsubjectpanel->Controls->Add(this->label48);
            this->addsubjectpanel->Controls->Add(this->textBox16);
            this->addsubjectpanel->Controls->Add(this->label49);
            this->addsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->addsubjectpanel->Name = L"addsubjectpanel";
            this->addsubjectpanel->Size = System::Drawing::Size(1946, 1106);
            this->addsubjectpanel->TabIndex = 124;
            // 
            // newaddsub
            // 
            this->newaddsub->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->newaddsub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newaddsub->Location = System::Drawing::Point(810, 1966);
            this->newaddsub->Name = L"newaddsub";
            this->newaddsub->Size = System::Drawing::Size(116, 54);
            this->newaddsub->TabIndex = 247;
            this->newaddsub->Text = L" Add New";
            this->newaddsub->UseVisualStyleBackColor = false;
            this->newaddsub->Click += gcnew System::EventHandler(this, &MyForm::newaddsub_Click);
            // 
            // checkedListBox2
            // 
            this->checkedListBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->checkedListBox2->FormattingEnabled = true;
            this->checkedListBox2->Location = System::Drawing::Point(367, 1560);
            this->checkedListBox2->Name = L"checkedListBox2";
            this->checkedListBox2->Size = System::Drawing::Size(224, 186);
            this->checkedListBox2->TabIndex = 246;
            // 
            // addsubsave
            // 
            this->addsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubsave->Location = System::Drawing::Point(658, 1969);
            this->addsubsave->Name = L"addsubsave";
            this->addsubsave->Size = System::Drawing::Size(116, 54);
            this->addsubsave->TabIndex = 245;
            this->addsubsave->Text = L"Save";
            this->addsubsave->UseVisualStyleBackColor = false;
            this->addsubsave->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
            // 
            // numericUpDown4
            // 
            this->numericUpDown4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->numericUpDown4->DecimalPlaces = 2;
            this->numericUpDown4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->numericUpDown4->Location = System::Drawing::Point(367, 1847);
            this->numericUpDown4->Name = L"numericUpDown4";
            this->numericUpDown4->Size = System::Drawing::Size(170, 34);
            this->numericUpDown4->TabIndex = 244;
            // 
            // label41
            // 
            this->label41->AutoSize = true;
            this->label41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label41->Location = System::Drawing::Point(358, 1514);
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
            this->label42->Location = System::Drawing::Point(376, 1793);
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
            this->label43->Location = System::Drawing::Point(364, 1386);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(125, 28);
            this->label43->TabIndex = 241;
            this->label43->Text = L"No of credits";
            // 
            // numericUpDown5
            // 
            this->numericUpDown5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->numericUpDown5->Location = System::Drawing::Point(367, 1430);
            this->numericUpDown5->Name = L"numericUpDown5";
            this->numericUpDown5->Size = System::Drawing::Size(170, 34);
            this->numericUpDown5->TabIndex = 240;
            // 
            // dataGridView4
            // 
            this->dataGridView4->AllowUserToOrderColumns = true;
            dataGridViewCellStyle30->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle30->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle30->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView4->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle30;
            this->dataGridView4->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView4->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView4->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle31->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle31->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView4->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle31;
            this->dataGridView4->ColumnHeadersHeight = 40;
            this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->Teacher_Name,
                    this->dataGridViewButtonColumn4
            });
            dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle34->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle34->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle34->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView4->DefaultCellStyle = dataGridViewCellStyle34;
            this->dataGridView4->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView4->Location = System::Drawing::Point(367, 1109);
            this->dataGridView4->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView4->Name = L"dataGridView4";
            dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle35->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle35->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle35->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle35->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle35->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView4->RowHeadersDefaultCellStyle = dataGridViewCellStyle35;
            this->dataGridView4->RowHeadersVisible = false;
            this->dataGridView4->RowHeadersWidth = 62;
            dataGridViewCellStyle36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle36->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle36->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle36->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView4->RowsDefaultCellStyle = dataGridViewCellStyle36;
            this->dataGridView4->RowTemplate->Height = 28;
            this->dataGridView4->Size = System::Drawing::Size(735, 226);
            this->dataGridView4->TabIndex = 239;
            this->dataGridView4->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView4_CellContentClick);
            // 
            // Teacher_Name
            // 
            dataGridViewCellStyle32->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle32->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Teacher_Name->DefaultCellStyle = dataGridViewCellStyle32;
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
            dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle33->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle33->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle33->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn4->DefaultCellStyle = dataGridViewCellStyle33;
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
            this->label44->Location = System::Drawing::Point(362, 1040);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(299, 28);
            this->label44->TabIndex = 238;
            this->label44->Text = L"Teachers handling the lab subject";
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->radioButton7);
            this->groupBox4->Controls->Add(this->radioButton8);
            this->groupBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groupBox4->Location = System::Drawing::Point(396, 937);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(265, 41);
            this->groupBox4->TabIndex = 237;
            this->groupBox4->TabStop = false;
            // 
            // radioButton7
            // 
            this->radioButton7->AutoSize = true;
            this->radioButton7->Location = System::Drawing::Point(170, 9);
            this->radioButton7->Name = L"radioButton7";
            this->radioButton7->Size = System::Drawing::Size(64, 32);
            this->radioButton7->TabIndex = 11;
            this->radioButton7->TabStop = true;
            this->radioButton7->Text = L"No";
            this->radioButton7->UseVisualStyleBackColor = true;
            this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton7_CheckedChanged);
            // 
            // radioButton8
            // 
            this->radioButton8->AutoSize = true;
            this->radioButton8->Location = System::Drawing::Point(33, 9);
            this->radioButton8->Name = L"radioButton8";
            this->radioButton8->Size = System::Drawing::Size(64, 32);
            this->radioButton8->TabIndex = 10;
            this->radioButton8->TabStop = true;
            this->radioButton8->Text = L"Yes";
            this->radioButton8->UseVisualStyleBackColor = true;
            this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton8_CheckedChanged);
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label45->Location = System::Drawing::Point(363, 887);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(98, 28);
            this->label45->TabIndex = 236;
            this->label45->Text = L"Is it a lab\?";
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(348, 563);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(330, 28);
            this->label46->TabIndex = 235;
            this->label46->Text = L"Teacher handling the elective subject";
            // 
            // dataGridView5
            // 
            this->dataGridView5->AllowUserToOrderColumns = true;
            dataGridViewCellStyle37->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle37->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle37->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle37->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView5->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle37;
            this->dataGridView5->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView5->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView5->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle38->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle38->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle38->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle38->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle38->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle38->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView5->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle38;
            this->dataGridView5->ColumnHeadersHeight = 40;
            this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->TeacherName,
                    this->dataGridViewButtonColumn5
            });
            dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle41->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle41->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle41->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle41->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle41->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView5->DefaultCellStyle = dataGridViewCellStyle41;
            this->dataGridView5->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView5->Location = System::Drawing::Point(353, 626);
            this->dataGridView5->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView5->Name = L"dataGridView5";
            dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle42->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle42->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle42->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle42->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle42->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView5->RowHeadersDefaultCellStyle = dataGridViewCellStyle42;
            this->dataGridView5->RowHeadersVisible = false;
            this->dataGridView5->RowHeadersWidth = 62;
            dataGridViewCellStyle43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle43->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle43->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle43->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView5->RowsDefaultCellStyle = dataGridViewCellStyle43;
            this->dataGridView5->RowTemplate->Height = 28;
            this->dataGridView5->Size = System::Drawing::Size(735, 226);
            this->dataGridView5->TabIndex = 234;
            this->dataGridView5->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView5_CellContentClick);
            // 
            // TeacherName
            // 
            dataGridViewCellStyle39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle39->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle39->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle39->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle39->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle39->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->TeacherName->DefaultCellStyle = dataGridViewCellStyle39;
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
            dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle40->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle40->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle40->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn5->DefaultCellStyle = dataGridViewCellStyle40;
            this->dataGridViewButtonColumn5->DividerWidth = 1;
            this->dataGridViewButtonColumn5->HeaderText = L"";
            this->dataGridViewButtonColumn5->MinimumWidth = 100;
            this->dataGridViewButtonColumn5->Name = L"dataGridViewButtonColumn5";
            this->dataGridViewButtonColumn5->ReadOnly = true;
            this->dataGridViewButtonColumn5->Text = L"Delete";
            this->dataGridViewButtonColumn5->UseColumnTextForButtonValue = true;
            // 
            // groupBox5
            // 
            this->groupBox5->Controls->Add(this->radioButton9);
            this->groupBox5->Controls->Add(this->radioButton10);
            this->groupBox5->Location = System::Drawing::Point(339, 309);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(326, 63);
            this->groupBox5->TabIndex = 26;
            this->groupBox5->TabStop = false;
            // 
            // radioButton9
            // 
            this->radioButton9->AutoSize = true;
            this->radioButton9->Location = System::Drawing::Point(220, 12);
            this->radioButton9->Name = L"radioButton9";
            this->radioButton9->Size = System::Drawing::Size(54, 24);
            this->radioButton9->TabIndex = 3;
            this->radioButton9->TabStop = true;
            this->radioButton9->Text = L"No";
            this->radioButton9->UseVisualStyleBackColor = true;
            this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton9_CheckedChanged);
            // 
            // radioButton10
            // 
            this->radioButton10->AutoSize = true;
            this->radioButton10->Location = System::Drawing::Point(14, 12);
            this->radioButton10->Name = L"radioButton10";
            this->radioButton10->Size = System::Drawing::Size(62, 24);
            this->radioButton10->TabIndex = 2;
            this->radioButton10->TabStop = true;
            this->radioButton10->Text = L"Yes";
            this->radioButton10->UseVisualStyleBackColor = true;
            this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton10_CheckedChanged);
            // 
            // textBox15
            // 
            this->textBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox15->Location = System::Drawing::Point(339, 470);
            this->textBox15->Name = L"textBox15";
            this->textBox15->Size = System::Drawing::Size(482, 34);
            this->textBox15->TabIndex = 25;
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(334, 418);
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
            this->label48->Location = System::Drawing::Point(341, 267);
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
            this->textBox16->Location = System::Drawing::Point(339, 177);
            this->textBox16->Name = L"textBox16";
            this->textBox16->Size = System::Drawing::Size(482, 34);
            this->textBox16->TabIndex = 3;
            // 
            // label49
            // 
            this->label49->AutoSize = true;
            this->label49->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label49->Location = System::Drawing::Point(334, 137);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(127, 28);
            this->label49->TabIndex = 2;
            this->label49->Text = L"subject name";
            // 
            // dataGridView6
            // 
            this->dataGridView6->AllowUserToOrderColumns = true;
            dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle8->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle8;
            this->dataGridView6->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView6->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView6->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
            this->dataGridView6->ColumnHeadersHeight = 40;
            this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->Subject_Name,
                    this->dataGridViewComboBoxColumn3, this->dataGridViewButtonColumn6
            });
            dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle13->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle13->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle13->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle13->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView6->DefaultCellStyle = dataGridViewCellStyle13;
            this->dataGridView6->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->Location = System::Drawing::Point(558, 681);
            this->dataGridView6->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView6->Name = L"dataGridView6";
            dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle14->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle14->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->RowHeadersDefaultCellStyle = dataGridViewCellStyle14;
            this->dataGridView6->RowHeadersVisible = false;
            this->dataGridView6->RowHeadersWidth = 62;
            dataGridViewCellStyle15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->RowsDefaultCellStyle = dataGridViewCellStyle15;
            this->dataGridView6->RowTemplate->Height = 28;
            this->dataGridView6->Size = System::Drawing::Size(735, 226);
            this->dataGridView6->TabIndex = 257;
            // 
            // Subject_Name
            // 
            dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle10->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Black;
            this->Subject_Name->DefaultCellStyle = dataGridViewCellStyle10;
            this->Subject_Name->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->Subject_Name->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Subject_Name->HeaderText = L"Subject";
            this->Subject_Name->MinimumWidth = 8;
            this->Subject_Name->Name = L"Subject_Name";
            this->Subject_Name->Width = 150;
            // 
            // dataGridViewComboBoxColumn3
            // 
            dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle11->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle11->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle11->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn3->DefaultCellStyle = dataGridViewCellStyle11;
            this->dataGridViewComboBoxColumn3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn3->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn3->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn3->Name = L"dataGridViewComboBoxColumn3";
            this->dataGridViewComboBoxColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn3->Width = 150;
            // 
            // dataGridViewButtonColumn6
            // 
            this->dataGridViewButtonColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle12->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle12->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle12->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn6->DefaultCellStyle = dataGridViewCellStyle12;
            this->dataGridViewButtonColumn6->DividerWidth = 1;
            this->dataGridViewButtonColumn6->HeaderText = L"";
            this->dataGridViewButtonColumn6->MinimumWidth = 100;
            this->dataGridViewButtonColumn6->Name = L"dataGridViewButtonColumn6";
            this->dataGridViewButtonColumn6->ReadOnly = true;
            this->dataGridViewButtonColumn6->Text = L"Delete";
            this->dataGridViewButtonColumn6->UseColumnTextForButtonValue = true;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(1946, 1106);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel5);
            this->Controls->Add(this->addclasspanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->panel2);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MyForm";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->addclasspanel->ResumeLayout(false);
            this->addclasspanel->PerformLayout();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            this->addclassroompanel->ResumeLayout(false);
            this->addclassroompanel->PerformLayout();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            this->addsubjectpanel->ResumeLayout(false);
            this->addsubjectpanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
            this->groupBox4->ResumeLayout(false);
            this->groupBox4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
            this->groupBox5->ResumeLayout(false);
            this->groupBox5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        panel3->Height = button1->Height;
        panel3->Top = button1->Top;
        panel2->BringToFront();
    }
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    String^ folderPath = "details"; //folder name
    try
    {
        if (!Directory::Exists(folderPath))
        {
            Directory::CreateDirectory(folderPath);
        }
        else
        {
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error creating folder: " + ex->Message);
    }

    DisplayCSVInComboBox(dataGridView2,"details/dept_file.csv");
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
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    addclassroompanel->BringToFront();
    DisplayCSVInComboBox1("details/dept_file.csv", comboBox2);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button18->Height;
    panel3->Top = button18->Top;

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
    panel3->Height = button9->Height;
    panel3->Top = button9->Top;
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
    addclasspanel->BringToFront();
    DisplayCSVInComboBox1("details/dept_file.csv",comboBox1);
}
private: System::Void dataGridView2_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn1, dataGridView2, sender, e);
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
    string filePath = "details/dept_file.csv";
    deptcsvgen(dataGridView2, filePath);
}
private: System::Void button37_Click_1(System::Object^ sender, System::EventArgs^ e) {
    String^ filePath = "details/teacher_file.csv";
    addnamecsvgen(filePath);
}
private: System::Void button38_Click_1(System::Object^ sender, System::EventArgs^ e) {
    textBox2->Clear();
    for (int i = 1; i <= 36; ++i)
    {
        String^ tagValue = i.ToString();
        Button^ button = dynamic_cast<Button^>(addclasspanel->Controls[String::Format("buttons{0}", tagValue)]);
        if (button != nullptr)
        {
            button->Text = "free";
        }
    }
    comboBox1->Text = "";
}
private: System::Void buttons1_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons1);
}
private: System::Void buttons2_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons2);
}
private: System::Void buttons3_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons3);
}
private: System::Void buttons4_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons4);
}
private: System::Void buttons5_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons5);
}
private: System::Void buttons6_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons6);
}
private: System::Void buttons7_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons7);
}
private: System::Void buttons8_Click(System::Object^ sender, System::EventArgs^ e)  {
    change(buttons8);
}
private: System::Void buttons9_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons9);
}
private: System::Void buttons10_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons10);
}
private: System::Void buttons11_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons11);
}
private: System::Void buttons12_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons12);
}
private: System::Void buttons13_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons13);
}
private: System::Void buttons14_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons14);
}
private: System::Void buttons15_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons15);
}
private: System::Void buttons16_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons16);
}
private: System::Void buttons17_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons17);
}
private: System::Void buttons18_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons18);
}
private: System::Void buttons19_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons19);
}
private: System::Void buttons20_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons20);
}
private: System::Void buttons21_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons21);
}
private: System::Void buttons22_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons22);
}
private: System::Void buttons23_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons23);
}
private: System::Void buttons24_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons24);
}
private: System::Void buttons25_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons25);
}
private: System::Void buttons26_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons26);
}
private: System::Void buttons27_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons27);
}
private: System::Void buttons28_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons28);
}
private: System::Void buttons29_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons29);
}
private: System::Void buttons30_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons30);
}
private: System::Void buttons31_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons31);
}
private: System::Void buttons32_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons32);
}
private: System::Void buttons33_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons33);
}
private: System::Void buttons34_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons34);
}
private: System::Void buttons35_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons35);
}
private: System::Void buttons36_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttons36);
}

private: System::Void addclassroompanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void buttona1_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona1);
}
private: System::Void buttona2_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona2);
}
private: System::Void buttona3_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona3);
}
private: System::Void buttona4_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona4);
}
private: System::Void buttona5_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona5);
}
private: System::Void buttona6_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona6);
}
private: System::Void buttona7_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona7);
}
private: System::Void buttona8_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona8);
}
private: System::Void buttona9_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona9);
}
private: System::Void buttona10_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona10);
}
private: System::Void buttona11_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona11);
}
private: System::Void buttona12_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona12);
}
private: System::Void buttona13_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona13);
}
private: System::Void buttona14_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona14);
}
private: System::Void buttona15_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona15);
}
private: System::Void buttona16_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona16);
}
private: System::Void buttona17_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona17);
}
private: System::Void buttona18_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona18);
}
private: System::Void buttona19_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona19);
}
private: System::Void buttona20_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona20);
}
private: System::Void buttona21_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona21);
}
private: System::Void buttona22_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona22);
}
private: System::Void buttona23_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona23);
}
private: System::Void buttona24_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona24);
}
private: System::Void buttona25_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona25);
}
private: System::Void buttona26_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona26);
}
private: System::Void buttona27_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona27);
}
private: System::Void buttona28_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona28);
}
private: System::Void buttona29_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona29);
}
private: System::Void buttona30_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona30);
}
private: System::Void buttona31_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona31);
}
private: System::Void buttona32_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona32);
}
private: System::Void buttona33_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona33);
}
private: System::Void buttona34_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona34);
}
private: System::Void buttona35_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona35);
}
private: System::Void buttona36_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttona36);
}
private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
    classroomcsvcreate("details/classroom.csv");
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    textBox3->Clear();
    numericUpDown1->Value = 0;
    radioButton1->Checked = false;
    radioButton2->Checked = false;
    for (int i = 1; i <= 36; ++i)
    {
        String^ tagValue = i.ToString();
        Button^ button = dynamic_cast<Button^>(addclassroompanel->Controls[String::Format("buttona{0}", tagValue)]);
        if (button != nullptr)
        {
            button->Text = "free";
        }
    }
    comboBox2->Text = "";
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
    addsubjectpanel->BringToFront();
    const std::string filePath = "details/addclass.csv";
    DisplayCSVInListBox(filePath, checkedListBox2);
    const std::string fileName = "details/teacher_file.csv";
    TeacherName->DataSource = CreateDataTableFromCSV1(fileName);
    TeacherName->DisplayMember = "TeacherName"; // Update to the correct column name
    TeacherName->ValueMember = "TeacherName";
    Teacher_Name->DataSource = CreateDataTableFromCSV2(fileName);
    Teacher_Name->DisplayMember = "Teacher_Name"; // Update to the correct column name
    Teacher_Name->ValueMember = "Teacher_Name";
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ filePath = "details/subject_file.csv";
    subcsvgen(filePath);
}
private: System::Void dataGridView4_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn4, dataGridView4, sender, e);
}
private: System::Void newaddsub_Click(System::Object^ sender, System::EventArgs^ e) {
    textBox16->Clear();
    textBox15->Clear();
    radioButton10->Checked = false;
    radioButton9->Checked = false;
    radioButton8->Checked = false;
    radioButton7->Checked = false;
    dataGridView4->Rows->Clear();
    dataGridView5->Rows->Clear();
    numericUpDown5->Value = 0;
    numericUpDown4->Value = 0;
    for (int i = 0; i < checkedListBox2->Items->Count; i++) {
        checkedListBox2->SetItemChecked(i, false);
    }
}
private: System::Void dataGridView5_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn5, dataGridView5, sender, e);
}
private: System::Void radioButton9_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton9->Checked)
    {
        textBox15->ReadOnly = true;
        textBox15->Clear();
        textBox15->Cursor = Cursors::No;
        dataGridView5->Rows->Clear();
        dataGridView5->Cursor = Cursors::No;
    }
}
private: System::Void radioButton10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton10->Checked)
    {
        textBox15->ReadOnly = false;
        textBox15->Clear();
        dataGridView5->Cursor = Cursors::Arrow;
        textBox15->Cursor = Cursors::Arrow;
    }
}
private: System::Void radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    dataGridView4->Rows->Clear();
    dataGridView4->Cursor = Cursors::No;
}
private: System::Void radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    dataGridView4->Cursor = Cursors::Arrow;
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
    panel5->BringToFront();
}
};
}
