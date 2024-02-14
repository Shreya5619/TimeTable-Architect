#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
//#include "header.h"
namespace TTA_ui {
    using namespace std;
    using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Collections::Generic;

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
            try
            {
                ofstream outputFile(filePath);
                if (outputFile.is_open())
                {
                    for (int i = 0; i < dataGridView1->RowCount - 1; ++i)
                    {

                        if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            System::String^ cellvalue = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
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
                button->Text = "busy";
                button->BackColor = Color::FromArgb(102,255,204);
            }
            else {
                button->Text = "free";
                button->BackColor = Color::FromArgb(179, 255, 230);
            }

        }

        string replacewhitespace(string text)
        {
            replace(text.begin(), text.end(), ' ', '_');
            return text;
        }

        void addnamecsvgen(String^ filePath)
        {
            try
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
                        Button^ button = dynamic_cast<Button^>(addteacherpanel->Controls[String::Format("buttons{0}", tagValue)]);
                        if (button != nullptr)
                        {
                            if (button->Text == "busy")
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
                MessageBox::Show("Saved Successfully","Message",MessageBoxButtons::OK,MessageBoxIcon::Information);
            }
            catch (...)
            {
                MessageBox::Show("Error occured while saving Data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void classroomcsvcreate(String^ filePath)
        {try
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
                        if (button->Text == "busy")
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
            }                MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (...)
        {
            MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        }

      
//functions for subject.h
        void subcsvgen(String^ filePath)
        {
            try{
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
                    String^ FilePath = "details/Elective.csv";
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
                        String^ filepath = "details/Labo.csv";
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
                if (radioButton8->Checked)
                {
                    outputFile << "2";
                }
                else
                {
                    outputFile << "1";
                }
                System::String^ bfactor = bfactorupdown->Text->ToString();
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
                  MessageBox::Show("Saved Successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (...)
        {
            MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
            }

        void DisplayCSVInListBox(const string& filename, ListBox^ ListBox) {
            ListBox->Items->Clear();
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[0]);
                ListBox->Items->Add(rowStringManaged);
            }
        }

        void csvelective(System::String^ filePath)
        {
            try
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
                    for (int i = 0; i < sedataGridView->RowCount - 1; ++i)
                    {
                        if (sedataGridView->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            System::String^ cellvalue = sedataGridView->Rows[i]->Cells[0]->Value->ToString();
                            std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                            outputFile << CellValue << ",";
                        }

                    }outputFile << "\n";
                }outputFile.close();
            }
            catch (...)
            {
            }                MessageBox::Show("Error saving Data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        
        void csvlab(System::String^ filePath)
        {
            try
            {
                std::ofstream outputFile;
                outputFile.open((msclr::interop::marshal_as<std::string>(filePath)), ios::app);
                {
                    System::String^ name = textBox16->Text->ToString();
                    std::string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                    outputFile << Name << ",";
                    if (sldataGridView->Rows[0]->Cells[0]->Value != nullptr)
                        outputFile << msclr::interop::marshal_as<string>(sldataGridView->Rows[0]->Cells[0]->Value->ToString());
                    for (int i = 1; i < sldataGridView->RowCount; ++i)
                    {

                        if (sldataGridView->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            System::String^ cellvalue = sldataGridView->Rows[i]->Cells[0]->Value->ToString();
                            std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                            outputFile << "," << CellValue;


                        }
                    }


                    outputFile << "\n";
                }outputFile.close();
            }
            catch(...)
            {
            }                MessageBox::Show("Error saving Data\nTry closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

        void displayelectives(const string filename)
        {
            eSubject->Items->Clear();
            vector<vector<string>>data = ReadCSVFile(filename);
            for (const auto& row : data)
            {

                if (row[1] != "0")
                {
                   bool flag = true;
                   for each (Object ^ item in eSubject->Items) {
                       if (item->ToString() == msclr::interop::marshal_as<String^>(row[1])) {
                           flag = false;
                           break;
                       }
                   }
                    if (flag)
                        {
                            String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[1]);
                            eSubject->Items->Add(rowStringManaged);
              
                    }
                }
            }
        }
      void displaylabs(const string filename)
        {
            lsubject->Items->Clear();
            vector<vector<string>>data = ReadCSVFile(filename);
            for (const auto& row : data)
            {

                if (row[2] != "0")
                {
                    bool flag = true;
                    for each (Object ^ item in lsubject->Items) {
                        if (item->ToString() == msclr::interop::marshal_as<String^>(row[0])) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[0]);
                        lsubject->Items->Add(rowStringManaged);

                    }
                }
            }
        }
        /*std::string returnLine(std::string name, std::string path) {
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
        }*/
       System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
          // Clear the existing graphics
          e->Graphics->Clear(pictureBox12->BackColor);

          // Get the image from the PictureBox
          Image^ image = pictureBox12->Image;
          if (image == nullptr)
              return;

          // Calculate the square area to draw the circular image within
          int size = Math::Min(pictureBox12->Width, pictureBox12->Height);
          Drawing::Rectangle rect = Drawing::Rectangle((pictureBox12->Width - size) / 2, (pictureBox12->Height - size) / 2, size, size);

          // Create a GraphicsPath to define the circular region
          Drawing::Drawing2D::GraphicsPath^ path = gcnew Drawing::Drawing2D::GraphicsPath();
          path->AddEllipse(rect);

          // Set the clipping region to the circular area
          e->Graphics->SetClip(path);

          // Draw the image within the circular region
          e->Graphics->DrawImage(image, rect);
      }
    System::Void panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Panel^ panel = dynamic_cast<Panel^>(sender);
        Drawing::Rectangle rect = Drawing::Rectangle(0, 0, panel->Width - 1, panel->Height - 1);
        int radius = 20; // Adjust the radius to control the roundness of the panel

        // Create a GraphicsPath to define the rounded rectangle
        Drawing::Drawing2D::GraphicsPath^ path = gcnew Drawing::Drawing2D::GraphicsPath();
        path->StartFigure();
        path->AddArc(rect.X, rect.Y, radius * 2, radius * 2, 180, 90);
        path->AddArc(rect.Right - radius * 2, rect.Y, radius * 2, radius * 2, 270, 90);
        path->AddArc(rect.Right - radius * 2, rect.Bottom - radius * 2, radius * 2, radius * 2, 0, 90);
        path->AddArc(rect.X, rect.Bottom - radius * 2, radius * 2, radius * 2, 90, 90);
        path->CloseFigure();

        // Fill the rounded rectangle with the panel's background color
        e->Graphics->FillPath(gcnew SolidBrush(panel->BackColor), path);
    }
   /* void labcreate(const string filename, section& t)
    {
        vector<vector<string>>abc =ReadCSVFile(filename);
        for (int i = 0; i < dataGridView1->RowCount; ++i)
        {
            if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr)
            {
                System::String^ cellvalue = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
                std::string CellValue = msclr::interop::marshal_as<string>(cellvalue);
                vector<string> a;
                int j;
                for (j = 0; j < abc.size(); j++)
                {
                    
                    if (CellValue == (abc[j][0]))
                    {
                        ::subject  subj;
                        subj.readData(returnLine(abc[j][0], "details/subject_file.csv"));
                        for (int x = 1; x < abc[j].size(); x++)
                        {
                            a.push_back(abc[j][x]);
                        }
                        t.addLab(a, subj, 2, 2);
                        break;
                    }
                }
            }

        }
    }*/
    void editteachercsv(const string filename)
    {
        string find = msclr::interop::marshal_as<string>(teachersearch->Text);

        vector<vector<string>>data = ReadCSVFile(filename);
        for (const auto& row : data)
            {
                if (find == row[0]){
                    editteachername->Text = msclr::interop::marshal_as<String^>(row[0]);
                    editteacherdepartment->Text = msclr::interop::marshal_as<String^>(row[1]);

                    for (int i = 2;i<row.size(); i+=2)
                    {
                        int x = i/2;
                        String^ tagValue = x.ToString();
                        Button^ button = dynamic_cast<Button^>(editteacherpanel->Controls[String::Format("buttont{0}", tagValue)]);
                     textBox1->Text = button->Name;
                        if (row[i] == "1")
                        {
                            button->Text = "busy";
                            button->BackColor = Color::FromArgb(102, 255, 204);
                        }
                        else
                        {
                            button->Text = "free";
                            button->BackColor = Color::FromArgb(179, 255, 230);
                        }
                    }
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
private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::DataGridView^ sldataGridView;

private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher_Name;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn4;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::NumericUpDown^ numericUpDown5;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::Label^ label42;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::NumericUpDown^ bfactorupdown;


private: System::Windows::Forms::Button^ addsubsave;
private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
private: System::Windows::Forms::Button^ newaddsub;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::RadioButton^ radioButton8;
private: System::Windows::Forms::RadioButton^ radioButton7;
private: System::Windows::Forms::Panel^ addsubjectpanel;
private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::RadioButton^ radioButton10;
private: System::Windows::Forms::RadioButton^ radioButton9;


private: System::Windows::Forms::TextBox^ textBox13;
private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::DataGridView^ sedataGridView;


private: System::Windows::Forms::DataGridViewComboBoxColumn^ TeacherName;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;
private: System::Windows::Forms::TextBox^ textBox15;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::TextBox^ textBox16;
private: System::Windows::Forms::Button^ Save;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::Button^ buttona1;
private: System::Windows::Forms::Button^ buttona2;
private: System::Windows::Forms::Button^ buttona3;
private: System::Windows::Forms::Button^ buttona4;
private: System::Windows::Forms::Button^ buttona5;
private: System::Windows::Forms::Button^ buttona6;
private: System::Windows::Forms::Button^ buttona7;
private: System::Windows::Forms::Button^ buttona8;
private: System::Windows::Forms::Button^ buttona9;
private: System::Windows::Forms::Button^ buttona10;
private: System::Windows::Forms::Button^ buttona11;
private: System::Windows::Forms::Button^ buttona12;
private: System::Windows::Forms::Button^ buttona13;
private: System::Windows::Forms::Button^ buttona14;
private: System::Windows::Forms::Button^ buttona15;
private: System::Windows::Forms::Button^ buttona16;
private: System::Windows::Forms::Button^ buttona17;
private: System::Windows::Forms::Button^ buttona18;
private: System::Windows::Forms::Button^ buttona19;
private: System::Windows::Forms::Button^ buttona20;
private: System::Windows::Forms::Button^ buttona21;
private: System::Windows::Forms::Button^ buttona22;
private: System::Windows::Forms::Button^ buttona23;
private: System::Windows::Forms::Button^ buttona24;
private: System::Windows::Forms::Button^ buttona25;
private: System::Windows::Forms::Button^ buttona26;
private: System::Windows::Forms::Button^ buttona27;
private: System::Windows::Forms::Button^ buttona28;
private: System::Windows::Forms::Button^ buttona29;
private: System::Windows::Forms::Button^ buttona30;
private: System::Windows::Forms::Button^ buttona31;
private: System::Windows::Forms::Button^ buttona32;
private: System::Windows::Forms::Button^ buttona33;
private: System::Windows::Forms::Button^ buttona34;
private: System::Windows::Forms::Button^ buttona35;
private: System::Windows::Forms::Button^ buttona36;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::Panel^ addclassroompanel;
private: System::Windows::Forms::Panel^ Homepanel;





























private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Button^ buttons36;
private: System::Windows::Forms::Button^ buttons30;
private: System::Windows::Forms::Button^ button38;
private: System::Windows::Forms::Button^ button37;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Button^ buttons1;
private: System::Windows::Forms::Button^ buttons2;
private: System::Windows::Forms::Button^ buttons3;
private: System::Windows::Forms::Button^ buttons4;
private: System::Windows::Forms::Button^ buttons5;
private: System::Windows::Forms::Button^ buttons6;
private: System::Windows::Forms::Button^ buttons7;
private: System::Windows::Forms::Button^ buttons8;
private: System::Windows::Forms::Button^ buttons9;
private: System::Windows::Forms::Button^ buttons10;
private: System::Windows::Forms::Button^ buttons11;
private: System::Windows::Forms::Button^ buttons12;
private: System::Windows::Forms::Button^ buttons13;
private: System::Windows::Forms::Button^ buttons14;
private: System::Windows::Forms::Button^ buttons15;
private: System::Windows::Forms::Button^ buttons16;
private: System::Windows::Forms::Button^ buttons17;
private: System::Windows::Forms::Button^ buttons18;
private: System::Windows::Forms::Button^ buttons19;
private: System::Windows::Forms::Button^ buttons20;
private: System::Windows::Forms::Button^ buttons21;
private: System::Windows::Forms::Button^ buttons22;
private: System::Windows::Forms::Button^ buttons23;
private: System::Windows::Forms::Button^ buttons24;
private: System::Windows::Forms::Button^ buttons25;
private: System::Windows::Forms::Button^ buttons26;
private: System::Windows::Forms::Button^ buttons27;
private: System::Windows::Forms::Button^ buttons28;
private: System::Windows::Forms::Button^ buttons29;
private: System::Windows::Forms::Button^ buttons31;
private: System::Windows::Forms::Button^ buttons32;
private: System::Windows::Forms::Button^ buttons33;
private: System::Windows::Forms::Button^ buttons34;
private: System::Windows::Forms::Button^ buttons35;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Panel^ addteacherpanel;

private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
private: System::Windows::Forms::TextBox^ textBox12;



private: System::Windows::Forms::PictureBox^ pictureBox1;
































































private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::PictureBox^ pictureBox9;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::PictureBox^ pictureBox11;
private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::Button^ button16;
private: System::Windows::Forms::DataGridView^ dataGridView3;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ eSubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn3;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ lsubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::DataGridView^ dataGridView6;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ csubject;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn3;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Button^ Homebutton1;




private: System::Windows::Forms::Button^ button13;
private: System::Windows::Forms::Button^ button14;
private: System::Windows::Forms::Button^ button15;


private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::Button^ button11;

private: System::Windows::Forms::Button^ button12;


private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ textBox4;
private: System::Windows::Forms::Label^ textBox5;


private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ textBox7;
private: System::Windows::Forms::Label^ textBox9;
private: System::Windows::Forms::Label^ textBox11;
private: System::Windows::Forms::Label^ textBox6;
private: System::Windows::Forms::Label^ textBox8;
private: System::Windows::Forms::Label^ textBox10;
private: System::Windows::Forms::Panel^ editteacherpanel;



private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::RichTextBox^ teachersearch;

private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Label^ label51;
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
private: System::Windows::Forms::Button^ buttont35;

private: System::Windows::Forms::Button^ buttont34;

private: System::Windows::Forms::Button^ buttont33;

private: System::Windows::Forms::Button^ buttont32;

private: System::Windows::Forms::Button^ buttont31;

private: System::Windows::Forms::Button^ buttont29;

private: System::Windows::Forms::Button^ buttont28;

private: System::Windows::Forms::Button^ buttont27;

private: System::Windows::Forms::Button^ buttont26;

private: System::Windows::Forms::Button^ buttont25;

private: System::Windows::Forms::Button^ buttont24;

private: System::Windows::Forms::Button^ buttont23;

private: System::Windows::Forms::Button^ buttont22;

private: System::Windows::Forms::Button^ buttont21;

private: System::Windows::Forms::Button^ buttont20;

private: System::Windows::Forms::Button^ buttont19;

private: System::Windows::Forms::Button^ buttont18;

private: System::Windows::Forms::Button^ buttont17;

private: System::Windows::Forms::Button^ buttont16;

private: System::Windows::Forms::Button^ buttont15;

private: System::Windows::Forms::Button^ buttont14;

private: System::Windows::Forms::Button^ buttont13;

private: System::Windows::Forms::Button^ buttont12;
private: System::Windows::Forms::Button^ buttont11;
private: System::Windows::Forms::Button^ buttont10;
private: System::Windows::Forms::Button^ buttont9;
private: System::Windows::Forms::Button^ buttont8;
private: System::Windows::Forms::Button^ buttont7;
private: System::Windows::Forms::Button^ buttont6;
private: System::Windows::Forms::Button^ buttont5;
private: System::Windows::Forms::Button^ buttont4;
private: System::Windows::Forms::Button^ buttont3;
private: System::Windows::Forms::Button^ buttont2;
private: System::Windows::Forms::Button^ buttont1;
private: System::Windows::Forms::Label^ label62;
private: System::Windows::Forms::ComboBox^ editteacherdepartment;


private: System::Windows::Forms::Label^ label63;
private: System::Windows::Forms::TextBox^ editteachername;

private: System::Windows::Forms::Button^ button55;
private: System::Windows::Forms::Button^ buttont30;
private: System::Windows::Forms::Button^ buttont36;


private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::PictureBox^ pictureBox13;
private: System::Windows::Forms::Button^ button18;





























































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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle44 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle45 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle48 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle49 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle50 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle46 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle47 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle51 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle52 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle55 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle56 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle57 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle53 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle54 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle58 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle59 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle62 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle63 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle64 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle60 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle61 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle65 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle66 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle69 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle70 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle71 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle67 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle68 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle72 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle73 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle76 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle77 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle78 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle74 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle75 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle79 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle80 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle84 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle85 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle86 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle81 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle82 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle83 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->sldataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->Teacher_Name = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->bfactorupdown = (gcnew System::Windows::Forms::NumericUpDown());
            this->addsubsave = (gcnew System::Windows::Forms::Button());
            this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
            this->newaddsub = (gcnew System::Windows::Forms::Button());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
            this->addsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
            this->textBox13 = (gcnew System::Windows::Forms::TextBox());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->textBox15 = (gcnew System::Windows::Forms::TextBox());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->textBox16 = (gcnew System::Windows::Forms::TextBox());
            this->sedataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->Save = (gcnew System::Windows::Forms::Button());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->buttona1 = (gcnew System::Windows::Forms::Button());
            this->buttona2 = (gcnew System::Windows::Forms::Button());
            this->buttona3 = (gcnew System::Windows::Forms::Button());
            this->buttona4 = (gcnew System::Windows::Forms::Button());
            this->buttona5 = (gcnew System::Windows::Forms::Button());
            this->buttona6 = (gcnew System::Windows::Forms::Button());
            this->buttona7 = (gcnew System::Windows::Forms::Button());
            this->buttona8 = (gcnew System::Windows::Forms::Button());
            this->buttona9 = (gcnew System::Windows::Forms::Button());
            this->buttona10 = (gcnew System::Windows::Forms::Button());
            this->buttona11 = (gcnew System::Windows::Forms::Button());
            this->buttona12 = (gcnew System::Windows::Forms::Button());
            this->buttona13 = (gcnew System::Windows::Forms::Button());
            this->buttona14 = (gcnew System::Windows::Forms::Button());
            this->buttona15 = (gcnew System::Windows::Forms::Button());
            this->buttona16 = (gcnew System::Windows::Forms::Button());
            this->buttona17 = (gcnew System::Windows::Forms::Button());
            this->buttona18 = (gcnew System::Windows::Forms::Button());
            this->buttona19 = (gcnew System::Windows::Forms::Button());
            this->buttona20 = (gcnew System::Windows::Forms::Button());
            this->buttona21 = (gcnew System::Windows::Forms::Button());
            this->buttona22 = (gcnew System::Windows::Forms::Button());
            this->buttona23 = (gcnew System::Windows::Forms::Button());
            this->buttona24 = (gcnew System::Windows::Forms::Button());
            this->buttona25 = (gcnew System::Windows::Forms::Button());
            this->buttona26 = (gcnew System::Windows::Forms::Button());
            this->buttona27 = (gcnew System::Windows::Forms::Button());
            this->buttona28 = (gcnew System::Windows::Forms::Button());
            this->buttona29 = (gcnew System::Windows::Forms::Button());
            this->buttona30 = (gcnew System::Windows::Forms::Button());
            this->buttona31 = (gcnew System::Windows::Forms::Button());
            this->buttona32 = (gcnew System::Windows::Forms::Button());
            this->buttona33 = (gcnew System::Windows::Forms::Button());
            this->buttona34 = (gcnew System::Windows::Forms::Button());
            this->buttona35 = (gcnew System::Windows::Forms::Button());
            this->buttona36 = (gcnew System::Windows::Forms::Button());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->addclassroompanel = (gcnew System::Windows::Forms::Panel());
            this->Homepanel = (gcnew System::Windows::Forms::Panel());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->buttons36 = (gcnew System::Windows::Forms::Button());
            this->buttons30 = (gcnew System::Windows::Forms::Button());
            this->button38 = (gcnew System::Windows::Forms::Button());
            this->button37 = (gcnew System::Windows::Forms::Button());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->buttons1 = (gcnew System::Windows::Forms::Button());
            this->buttons2 = (gcnew System::Windows::Forms::Button());
            this->buttons3 = (gcnew System::Windows::Forms::Button());
            this->buttons4 = (gcnew System::Windows::Forms::Button());
            this->buttons5 = (gcnew System::Windows::Forms::Button());
            this->buttons6 = (gcnew System::Windows::Forms::Button());
            this->buttons7 = (gcnew System::Windows::Forms::Button());
            this->buttons8 = (gcnew System::Windows::Forms::Button());
            this->buttons9 = (gcnew System::Windows::Forms::Button());
            this->buttons10 = (gcnew System::Windows::Forms::Button());
            this->buttons11 = (gcnew System::Windows::Forms::Button());
            this->buttons12 = (gcnew System::Windows::Forms::Button());
            this->buttons13 = (gcnew System::Windows::Forms::Button());
            this->buttons14 = (gcnew System::Windows::Forms::Button());
            this->buttons15 = (gcnew System::Windows::Forms::Button());
            this->buttons16 = (gcnew System::Windows::Forms::Button());
            this->buttons17 = (gcnew System::Windows::Forms::Button());
            this->buttons18 = (gcnew System::Windows::Forms::Button());
            this->buttons19 = (gcnew System::Windows::Forms::Button());
            this->buttons20 = (gcnew System::Windows::Forms::Button());
            this->buttons21 = (gcnew System::Windows::Forms::Button());
            this->buttons22 = (gcnew System::Windows::Forms::Button());
            this->buttons23 = (gcnew System::Windows::Forms::Button());
            this->buttons24 = (gcnew System::Windows::Forms::Button());
            this->buttons25 = (gcnew System::Windows::Forms::Button());
            this->buttons26 = (gcnew System::Windows::Forms::Button());
            this->buttons27 = (gcnew System::Windows::Forms::Button());
            this->buttons28 = (gcnew System::Windows::Forms::Button());
            this->buttons29 = (gcnew System::Windows::Forms::Button());
            this->buttons31 = (gcnew System::Windows::Forms::Button());
            this->buttons32 = (gcnew System::Windows::Forms::Button());
            this->buttons33 = (gcnew System::Windows::Forms::Button());
            this->buttons34 = (gcnew System::Windows::Forms::Button());
            this->buttons35 = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->addteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->textBox12 = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->button19 = (gcnew System::Windows::Forms::Button());
            this->button17 = (gcnew System::Windows::Forms::Button());
            this->button16 = (gcnew System::Windows::Forms::Button());
            this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
            this->eSubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->lsubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
            this->csubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewComboBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->textBox7 = (gcnew System::Windows::Forms::Label());
            this->textBox9 = (gcnew System::Windows::Forms::Label());
            this->textBox11 = (gcnew System::Windows::Forms::Label());
            this->textBox6 = (gcnew System::Windows::Forms::Label());
            this->textBox8 = (gcnew System::Windows::Forms::Label());
            this->textBox10 = (gcnew System::Windows::Forms::Label());
            this->textBox5 = (gcnew System::Windows::Forms::Label());
            this->textBox4 = (gcnew System::Windows::Forms::Label());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->Homebutton1 = (gcnew System::Windows::Forms::Button());
            this->button13 = (gcnew System::Windows::Forms::Button());
            this->button14 = (gcnew System::Windows::Forms::Button());
            this->button15 = (gcnew System::Windows::Forms::Button());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->button11 = (gcnew System::Windows::Forms::Button());
            this->button12 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->editteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label51 = (gcnew System::Windows::Forms::Label());
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
            this->buttont35 = (gcnew System::Windows::Forms::Button());
            this->buttont34 = (gcnew System::Windows::Forms::Button());
            this->buttont33 = (gcnew System::Windows::Forms::Button());
            this->buttont32 = (gcnew System::Windows::Forms::Button());
            this->buttont31 = (gcnew System::Windows::Forms::Button());
            this->buttont29 = (gcnew System::Windows::Forms::Button());
            this->buttont28 = (gcnew System::Windows::Forms::Button());
            this->buttont27 = (gcnew System::Windows::Forms::Button());
            this->buttont26 = (gcnew System::Windows::Forms::Button());
            this->buttont25 = (gcnew System::Windows::Forms::Button());
            this->buttont24 = (gcnew System::Windows::Forms::Button());
            this->buttont23 = (gcnew System::Windows::Forms::Button());
            this->buttont22 = (gcnew System::Windows::Forms::Button());
            this->buttont21 = (gcnew System::Windows::Forms::Button());
            this->buttont20 = (gcnew System::Windows::Forms::Button());
            this->buttont19 = (gcnew System::Windows::Forms::Button());
            this->buttont18 = (gcnew System::Windows::Forms::Button());
            this->buttont17 = (gcnew System::Windows::Forms::Button());
            this->buttont16 = (gcnew System::Windows::Forms::Button());
            this->buttont15 = (gcnew System::Windows::Forms::Button());
            this->buttont14 = (gcnew System::Windows::Forms::Button());
            this->buttont13 = (gcnew System::Windows::Forms::Button());
            this->buttont12 = (gcnew System::Windows::Forms::Button());
            this->buttont11 = (gcnew System::Windows::Forms::Button());
            this->buttont10 = (gcnew System::Windows::Forms::Button());
            this->buttont9 = (gcnew System::Windows::Forms::Button());
            this->buttont8 = (gcnew System::Windows::Forms::Button());
            this->buttont7 = (gcnew System::Windows::Forms::Button());
            this->buttont6 = (gcnew System::Windows::Forms::Button());
            this->buttont5 = (gcnew System::Windows::Forms::Button());
            this->buttont4 = (gcnew System::Windows::Forms::Button());
            this->buttont3 = (gcnew System::Windows::Forms::Button());
            this->buttont2 = (gcnew System::Windows::Forms::Button());
            this->buttont1 = (gcnew System::Windows::Forms::Button());
            this->label62 = (gcnew System::Windows::Forms::Label());
            this->editteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->editteachername = (gcnew System::Windows::Forms::TextBox());
            this->button55 = (gcnew System::Windows::Forms::Button());
            this->buttont30 = (gcnew System::Windows::Forms::Button());
            this->buttont36 = (gcnew System::Windows::Forms::Button());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->teachersearch = (gcnew System::Windows::Forms::RichTextBox());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->button18 = (gcnew System::Windows::Forms::Button());
            this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sldataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bfactorupdown))->BeginInit();
            this->panel11->SuspendLayout();
            this->addsubjectpanel->SuspendLayout();
            this->panel12->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            this->groupBox1->SuspendLayout();
            this->addclassroompanel->SuspendLayout();
            this->addteacherpanel->SuspendLayout();
            this->panel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->panel5->SuspendLayout();
            this->editteacherpanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
            this->SuspendLayout();
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
            // sldataGridView
            // 
            this->sldataGridView->AllowUserToOrderColumns = true;
            dataGridViewCellStyle44->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle44->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle44->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle44->SelectionForeColor = System::Drawing::Color::Black;
            this->sldataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle44;
            this->sldataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sldataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->sldataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->sldataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle45->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle45->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle45->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle45->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sldataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle45;
            this->sldataGridView->ColumnHeadersHeight = 40;
            this->sldataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sldataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->Teacher_Name,
                    this->dataGridViewButtonColumn4
            });
            dataGridViewCellStyle48->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle48->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle48->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle48->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle48->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle48->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->sldataGridView->DefaultCellStyle = dataGridViewCellStyle48;
            this->sldataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sldataGridView->Location = System::Drawing::Point(373, 1043);
            this->sldataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->sldataGridView->Name = L"sldataGridView";
            dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle49->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle49->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle49->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle49->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle49->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sldataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle49;
            this->sldataGridView->RowHeadersVisible = false;
            this->sldataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle50->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle50->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle50->SelectionForeColor = System::Drawing::Color::Black;
            this->sldataGridView->RowsDefaultCellStyle = dataGridViewCellStyle50;
            this->sldataGridView->RowTemplate->Height = 28;
            this->sldataGridView->Size = System::Drawing::Size(735, 226);
            this->sldataGridView->TabIndex = 239;
            this->sldataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::sedataGridView_CellContentClick);
            // 
            // Teacher_Name
            // 
            dataGridViewCellStyle46->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle46->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle46->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle46->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Teacher_Name->DefaultCellStyle = dataGridViewCellStyle46;
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
            dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle47->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn4->DefaultCellStyle = dataGridViewCellStyle47;
            this->dataGridViewButtonColumn4->DividerWidth = 1;
            this->dataGridViewButtonColumn4->HeaderText = L"";
            this->dataGridViewButtonColumn4->MinimumWidth = 100;
            this->dataGridViewButtonColumn4->Name = L"dataGridViewButtonColumn4";
            this->dataGridViewButtonColumn4->ReadOnly = true;
            this->dataGridViewButtonColumn4->Text = L"Delete";
            this->dataGridViewButtonColumn4->UseColumnTextForButtonValue = true;
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
            this->addsubsave->Click += gcnew System::EventHandler(this, &MyForm::addsubsave_Click);
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
            this->newaddsub->Click += gcnew System::EventHandler(this, &MyForm::newaddsub_Click);
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
            this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton8_CheckedChanged);
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
            this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton7_CheckedChanged);
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
            this->addsubjectpanel->Size = System::Drawing::Size(1946, 1106);
            this->addsubjectpanel->TabIndex = 124;
            this->addsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addsubjectpanel_Paint);
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
            this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton10_CheckedChanged);
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
            this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton9_CheckedChanged);
            // 
            // textBox13
            // 
            this->textBox13->Location = System::Drawing::Point(964, 276);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(154, 26);
            this->textBox13->TabIndex = 248;
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
            this->textBox15->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox15_TextChanged);
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
            this->textBox16->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox16_TextChanged);
            // 
            // sedataGridView
            // 
            this->sedataGridView->AllowUserToOrderColumns = true;
            dataGridViewCellStyle51->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle51->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle51->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle51->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
            this->sedataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->sedataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->sedataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle52->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle52->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle52->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sedataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
            this->sedataGridView->ColumnHeadersHeight = 40;
            this->sedataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sedataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->TeacherName,
                    this->dataGridViewButtonColumn5
            });
            dataGridViewCellStyle55->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle55->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle55->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle55->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle55->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle55->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->sedataGridView->DefaultCellStyle = dataGridViewCellStyle55;
            this->sedataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sedataGridView->Location = System::Drawing::Point(335, 637);
            this->sedataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->sedataGridView->Name = L"sedataGridView";
            dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle56->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle56->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle56->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle56->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle56->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sedataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle56;
            this->sedataGridView->RowHeadersVisible = false;
            this->sedataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle57->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle57->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle57->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->RowsDefaultCellStyle = dataGridViewCellStyle57;
            this->sedataGridView->RowTemplate->Height = 28;
            this->sedataGridView->Size = System::Drawing::Size(735, 226);
            this->sedataGridView->TabIndex = 234;
            this->sedataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::sedataGridView_CellContentClick);
            // 
            // TeacherName
            // 
            dataGridViewCellStyle53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle53->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle53->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle53->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->TeacherName->DefaultCellStyle = dataGridViewCellStyle53;
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
            dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle54->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn5->DefaultCellStyle = dataGridViewCellStyle54;
            this->dataGridViewButtonColumn5->DividerWidth = 1;
            this->dataGridViewButtonColumn5->HeaderText = L"";
            this->dataGridViewButtonColumn5->MinimumWidth = 100;
            this->dataGridViewButtonColumn5->Name = L"dataGridViewButtonColumn5";
            this->dataGridViewButtonColumn5->ReadOnly = true;
            this->dataGridViewButtonColumn5->Text = L"Delete";
            this->dataGridViewButtonColumn5->UseColumnTextForButtonValue = true;
            // 
            // Save
            // 
            this->Save->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->Save->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->Save->Location = System::Drawing::Point(862, 1140);
            this->Save->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Save->Name = L"Save";
            this->Save->Size = System::Drawing::Size(138, 54);
            this->Save->TabIndex = 66;
            this->Save->Text = L"Save";
            this->Save->UseVisualStyleBackColor = false;
            this->Save->Click += gcnew System::EventHandler(this, &MyForm::Save_Click);
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
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->button3->Location = System::Drawing::Point(1125, 1141);
            this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(138, 54);
            this->button3->TabIndex = 122;
            this->button3->Text = L"Add New";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
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
            this->addclassroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addclassroompanel->Location = System::Drawing::Point(0, 0);
            this->addclassroompanel->Name = L"addclassroompanel";
            this->addclassroompanel->Size = System::Drawing::Size(1946, 1106);
            this->addclassroompanel->TabIndex = 230;
            this->addclassroompanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addclassroompanel_Paint);
            // 
            // Homepanel
            // 
            this->Homepanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Homepanel->Location = System::Drawing::Point(0, 0);
            this->Homepanel->Name = L"Homepanel";
            this->Homepanel->Size = System::Drawing::Size(1946, 1106);
            this->Homepanel->TabIndex = 258;
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(1116, 510);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(94, 28);
            this->label14->TabIndex = 228;
            this->label14->Text = L"2:30-3:30";
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
            // buttons36
            // 
            this->buttons36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons36->Location = System::Drawing::Point(1263, 877);
            this->buttons36->Name = L"buttons36";
            this->buttons36->Size = System::Drawing::Size(138, 54);
            this->buttons36->TabIndex = 215;
            this->buttons36->Text = L"free";
            this->buttons36->UseVisualStyleBackColor = false;
            this->buttons36->Click += gcnew System::EventHandler(this, &MyForm::buttons36_Click);
            // 
            // buttons30
            // 
            this->buttons30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons30->Location = System::Drawing::Point(1263, 816);
            this->buttons30->Name = L"buttons30";
            this->buttons30->Size = System::Drawing::Size(138, 55);
            this->buttons30->TabIndex = 209;
            this->buttons30->Text = L"free";
            this->buttons30->UseVisualStyleBackColor = false;
            this->buttons30->Click += gcnew System::EventHandler(this, &MyForm::buttons30_Click);
            // 
            // button38
            // 
            this->button38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button38->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button38->Location = System::Drawing::Point(1211, 1006);
            this->button38->Name = L"button38";
            this->button38->Size = System::Drawing::Size(121, 45);
            this->button38->TabIndex = 216;
            this->button38->Text = L"Add New";
            this->button38->UseVisualStyleBackColor = false;
            this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click_1);
            // 
            // button37
            // 
            this->button37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button37->Location = System::Drawing::Point(1041, 1006);
            this->button37->Name = L"button37";
            this->button37->Size = System::Drawing::Size(121, 45);
            this->button37->TabIndex = 217;
            this->button37->Text = L"Save";
            this->button37->UseVisualStyleBackColor = false;
            this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click_1);
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
            // buttons1
            // 
            this->buttons1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons1->Location = System::Drawing::Point(482, 572);
            this->buttons1->Name = L"buttons1";
            this->buttons1->Size = System::Drawing::Size(138, 55);
            this->buttons1->TabIndex = 180;
            this->buttons1->Text = L"free";
            this->buttons1->UseVisualStyleBackColor = false;
            this->buttons1->Click += gcnew System::EventHandler(this, &MyForm::buttons1_Click);
            // 
            // buttons2
            // 
            this->buttons2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons2->Location = System::Drawing::Point(637, 572);
            this->buttons2->Name = L"buttons2";
            this->buttons2->Size = System::Drawing::Size(138, 55);
            this->buttons2->TabIndex = 181;
            this->buttons2->Text = L"free";
            this->buttons2->UseVisualStyleBackColor = false;
            this->buttons2->Click += gcnew System::EventHandler(this, &MyForm::buttons2_Click);
            // 
            // buttons3
            // 
            this->buttons3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons3->Location = System::Drawing::Point(796, 572);
            this->buttons3->Name = L"buttons3";
            this->buttons3->Size = System::Drawing::Size(138, 55);
            this->buttons3->TabIndex = 182;
            this->buttons3->Text = L"free";
            this->buttons3->UseVisualStyleBackColor = false;
            this->buttons3->Click += gcnew System::EventHandler(this, &MyForm::buttons3_Click);
            // 
            // buttons4
            // 
            this->buttons4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons4->Location = System::Drawing::Point(949, 572);
            this->buttons4->Name = L"buttons4";
            this->buttons4->Size = System::Drawing::Size(138, 55);
            this->buttons4->TabIndex = 183;
            this->buttons4->Text = L"free";
            this->buttons4->UseVisualStyleBackColor = false;
            this->buttons4->Click += gcnew System::EventHandler(this, &MyForm::buttons4_Click);
            // 
            // buttons5
            // 
            this->buttons5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons5->Location = System::Drawing::Point(1108, 572);
            this->buttons5->Name = L"buttons5";
            this->buttons5->Size = System::Drawing::Size(138, 55);
            this->buttons5->TabIndex = 184;
            this->buttons5->Text = L"free";
            this->buttons5->UseVisualStyleBackColor = false;
            this->buttons5->Click += gcnew System::EventHandler(this, &MyForm::buttons5_Click);
            // 
            // buttons6
            // 
            this->buttons6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons6->Location = System::Drawing::Point(1263, 572);
            this->buttons6->Name = L"buttons6";
            this->buttons6->Size = System::Drawing::Size(138, 55);
            this->buttons6->TabIndex = 185;
            this->buttons6->Text = L"free";
            this->buttons6->UseVisualStyleBackColor = false;
            this->buttons6->Click += gcnew System::EventHandler(this, &MyForm::buttons6_Click);
            // 
            // buttons7
            // 
            this->buttons7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons7->Location = System::Drawing::Point(482, 632);
            this->buttons7->Name = L"buttons7";
            this->buttons7->Size = System::Drawing::Size(138, 55);
            this->buttons7->TabIndex = 186;
            this->buttons7->Text = L"free";
            this->buttons7->UseVisualStyleBackColor = false;
            this->buttons7->Click += gcnew System::EventHandler(this, &MyForm::buttons7_Click);
            // 
            // buttons8
            // 
            this->buttons8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons8->Location = System::Drawing::Point(637, 632);
            this->buttons8->Name = L"buttons8";
            this->buttons8->Size = System::Drawing::Size(138, 55);
            this->buttons8->TabIndex = 187;
            this->buttons8->Text = L"free";
            this->buttons8->UseVisualStyleBackColor = false;
            this->buttons8->Click += gcnew System::EventHandler(this, &MyForm::buttons8_Click);
            // 
            // buttons9
            // 
            this->buttons9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons9->Location = System::Drawing::Point(796, 632);
            this->buttons9->Name = L"buttons9";
            this->buttons9->Size = System::Drawing::Size(138, 55);
            this->buttons9->TabIndex = 188;
            this->buttons9->Text = L"free";
            this->buttons9->UseVisualStyleBackColor = false;
            this->buttons9->Click += gcnew System::EventHandler(this, &MyForm::buttons9_Click);
            // 
            // buttons10
            // 
            this->buttons10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons10->Location = System::Drawing::Point(949, 632);
            this->buttons10->Name = L"buttons10";
            this->buttons10->Size = System::Drawing::Size(138, 55);
            this->buttons10->TabIndex = 189;
            this->buttons10->Text = L"free";
            this->buttons10->UseVisualStyleBackColor = false;
            this->buttons10->Click += gcnew System::EventHandler(this, &MyForm::buttons10_Click);
            // 
            // buttons11
            // 
            this->buttons11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons11->Location = System::Drawing::Point(1108, 632);
            this->buttons11->Name = L"buttons11";
            this->buttons11->Size = System::Drawing::Size(138, 55);
            this->buttons11->TabIndex = 190;
            this->buttons11->Text = L"free";
            this->buttons11->UseVisualStyleBackColor = false;
            this->buttons11->Click += gcnew System::EventHandler(this, &MyForm::buttons11_Click);
            // 
            // buttons12
            // 
            this->buttons12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons12->Location = System::Drawing::Point(1263, 632);
            this->buttons12->Name = L"buttons12";
            this->buttons12->Size = System::Drawing::Size(138, 55);
            this->buttons12->TabIndex = 191;
            this->buttons12->Text = L"free";
            this->buttons12->UseVisualStyleBackColor = false;
            this->buttons12->Click += gcnew System::EventHandler(this, &MyForm::buttons12_Click);
            // 
            // buttons13
            // 
            this->buttons13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons13->Location = System::Drawing::Point(482, 693);
            this->buttons13->Name = L"buttons13";
            this->buttons13->Size = System::Drawing::Size(138, 55);
            this->buttons13->TabIndex = 192;
            this->buttons13->Text = L"free";
            this->buttons13->UseVisualStyleBackColor = false;
            this->buttons13->Click += gcnew System::EventHandler(this, &MyForm::buttons13_Click);
            // 
            // buttons14
            // 
            this->buttons14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons14->Location = System::Drawing::Point(637, 693);
            this->buttons14->Name = L"buttons14";
            this->buttons14->Size = System::Drawing::Size(138, 55);
            this->buttons14->TabIndex = 193;
            this->buttons14->Text = L"free";
            this->buttons14->UseVisualStyleBackColor = false;
            this->buttons14->Click += gcnew System::EventHandler(this, &MyForm::buttons14_Click);
            // 
            // buttons15
            // 
            this->buttons15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons15->Location = System::Drawing::Point(796, 693);
            this->buttons15->Name = L"buttons15";
            this->buttons15->Size = System::Drawing::Size(138, 55);
            this->buttons15->TabIndex = 194;
            this->buttons15->Text = L"free";
            this->buttons15->UseVisualStyleBackColor = false;
            this->buttons15->Click += gcnew System::EventHandler(this, &MyForm::buttons15_Click);
            // 
            // buttons16
            // 
            this->buttons16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons16->Location = System::Drawing::Point(949, 693);
            this->buttons16->Name = L"buttons16";
            this->buttons16->Size = System::Drawing::Size(138, 55);
            this->buttons16->TabIndex = 195;
            this->buttons16->Text = L"free";
            this->buttons16->UseVisualStyleBackColor = false;
            this->buttons16->Click += gcnew System::EventHandler(this, &MyForm::buttons16_Click);
            // 
            // buttons17
            // 
            this->buttons17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons17->Location = System::Drawing::Point(1108, 693);
            this->buttons17->Name = L"buttons17";
            this->buttons17->Size = System::Drawing::Size(138, 55);
            this->buttons17->TabIndex = 196;
            this->buttons17->Text = L"free";
            this->buttons17->UseVisualStyleBackColor = false;
            this->buttons17->Click += gcnew System::EventHandler(this, &MyForm::buttons17_Click);
            // 
            // buttons18
            // 
            this->buttons18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons18->Location = System::Drawing::Point(1263, 696);
            this->buttons18->Name = L"buttons18";
            this->buttons18->Size = System::Drawing::Size(138, 55);
            this->buttons18->TabIndex = 197;
            this->buttons18->Text = L"free";
            this->buttons18->UseVisualStyleBackColor = false;
            this->buttons18->Click += gcnew System::EventHandler(this, &MyForm::buttons18_Click);
            // 
            // buttons19
            // 
            this->buttons19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons19->Location = System::Drawing::Point(482, 753);
            this->buttons19->Name = L"buttons19";
            this->buttons19->Size = System::Drawing::Size(138, 55);
            this->buttons19->TabIndex = 198;
            this->buttons19->Text = L"free";
            this->buttons19->UseVisualStyleBackColor = false;
            this->buttons19->Click += gcnew System::EventHandler(this, &MyForm::buttons19_Click);
            // 
            // buttons20
            // 
            this->buttons20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons20->Location = System::Drawing::Point(637, 754);
            this->buttons20->Name = L"buttons20";
            this->buttons20->Size = System::Drawing::Size(138, 55);
            this->buttons20->TabIndex = 199;
            this->buttons20->Text = L"free";
            this->buttons20->UseVisualStyleBackColor = false;
            this->buttons20->Click += gcnew System::EventHandler(this, &MyForm::buttons20_Click);
            // 
            // buttons21
            // 
            this->buttons21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons21->Location = System::Drawing::Point(796, 754);
            this->buttons21->Name = L"buttons21";
            this->buttons21->Size = System::Drawing::Size(138, 55);
            this->buttons21->TabIndex = 200;
            this->buttons21->Text = L"free";
            this->buttons21->UseVisualStyleBackColor = false;
            this->buttons21->Click += gcnew System::EventHandler(this, &MyForm::buttons21_Click);
            // 
            // buttons22
            // 
            this->buttons22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons22->Location = System::Drawing::Point(949, 753);
            this->buttons22->Name = L"buttons22";
            this->buttons22->Size = System::Drawing::Size(138, 55);
            this->buttons22->TabIndex = 201;
            this->buttons22->Text = L"free";
            this->buttons22->UseVisualStyleBackColor = false;
            this->buttons22->Click += gcnew System::EventHandler(this, &MyForm::buttons22_Click);
            // 
            // buttons23
            // 
            this->buttons23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons23->Location = System::Drawing::Point(1108, 754);
            this->buttons23->Name = L"buttons23";
            this->buttons23->Size = System::Drawing::Size(138, 55);
            this->buttons23->TabIndex = 202;
            this->buttons23->Text = L"free";
            this->buttons23->UseVisualStyleBackColor = false;
            this->buttons23->Click += gcnew System::EventHandler(this, &MyForm::buttons23_Click);
            // 
            // buttons24
            // 
            this->buttons24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons24->Location = System::Drawing::Point(1263, 753);
            this->buttons24->Name = L"buttons24";
            this->buttons24->Size = System::Drawing::Size(138, 55);
            this->buttons24->TabIndex = 203;
            this->buttons24->Text = L"free";
            this->buttons24->UseVisualStyleBackColor = false;
            this->buttons24->Click += gcnew System::EventHandler(this, &MyForm::buttons24_Click);
            // 
            // buttons25
            // 
            this->buttons25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons25->Location = System::Drawing::Point(482, 816);
            this->buttons25->Name = L"buttons25";
            this->buttons25->Size = System::Drawing::Size(138, 55);
            this->buttons25->TabIndex = 204;
            this->buttons25->Text = L"free";
            this->buttons25->UseVisualStyleBackColor = false;
            this->buttons25->Click += gcnew System::EventHandler(this, &MyForm::buttons25_Click);
            // 
            // buttons26
            // 
            this->buttons26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons26->Location = System::Drawing::Point(637, 816);
            this->buttons26->Name = L"buttons26";
            this->buttons26->Size = System::Drawing::Size(138, 55);
            this->buttons26->TabIndex = 205;
            this->buttons26->Text = L"free";
            this->buttons26->UseVisualStyleBackColor = false;
            this->buttons26->Click += gcnew System::EventHandler(this, &MyForm::buttons26_Click);
            // 
            // buttons27
            // 
            this->buttons27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons27->Location = System::Drawing::Point(796, 816);
            this->buttons27->Name = L"buttons27";
            this->buttons27->Size = System::Drawing::Size(138, 55);
            this->buttons27->TabIndex = 206;
            this->buttons27->Text = L"free";
            this->buttons27->UseVisualStyleBackColor = false;
            this->buttons27->Click += gcnew System::EventHandler(this, &MyForm::buttons27_Click);
            // 
            // buttons28
            // 
            this->buttons28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons28->Location = System::Drawing::Point(949, 816);
            this->buttons28->Name = L"buttons28";
            this->buttons28->Size = System::Drawing::Size(138, 55);
            this->buttons28->TabIndex = 207;
            this->buttons28->Text = L"free";
            this->buttons28->UseVisualStyleBackColor = false;
            this->buttons28->Click += gcnew System::EventHandler(this, &MyForm::buttons28_Click);
            // 
            // buttons29
            // 
            this->buttons29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons29->Location = System::Drawing::Point(1108, 816);
            this->buttons29->Name = L"buttons29";
            this->buttons29->Size = System::Drawing::Size(138, 55);
            this->buttons29->TabIndex = 208;
            this->buttons29->Text = L"free";
            this->buttons29->UseVisualStyleBackColor = false;
            this->buttons29->Click += gcnew System::EventHandler(this, &MyForm::buttons29_Click);
            // 
            // buttons31
            // 
            this->buttons31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons31->Location = System::Drawing::Point(482, 877);
            this->buttons31->Name = L"buttons31";
            this->buttons31->Size = System::Drawing::Size(138, 54);
            this->buttons31->TabIndex = 210;
            this->buttons31->Text = L"free";
            this->buttons31->UseVisualStyleBackColor = false;
            this->buttons31->Click += gcnew System::EventHandler(this, &MyForm::buttons31_Click);
            // 
            // buttons32
            // 
            this->buttons32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons32->Location = System::Drawing::Point(637, 877);
            this->buttons32->Name = L"buttons32";
            this->buttons32->Size = System::Drawing::Size(138, 54);
            this->buttons32->TabIndex = 211;
            this->buttons32->Text = L"free";
            this->buttons32->UseVisualStyleBackColor = false;
            this->buttons32->Click += gcnew System::EventHandler(this, &MyForm::buttons32_Click);
            // 
            // buttons33
            // 
            this->buttons33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons33->Location = System::Drawing::Point(796, 877);
            this->buttons33->Name = L"buttons33";
            this->buttons33->Size = System::Drawing::Size(138, 54);
            this->buttons33->TabIndex = 212;
            this->buttons33->Text = L"free";
            this->buttons33->UseVisualStyleBackColor = false;
            this->buttons33->Click += gcnew System::EventHandler(this, &MyForm::buttons33_Click);
            // 
            // buttons34
            // 
            this->buttons34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons34->Location = System::Drawing::Point(949, 877);
            this->buttons34->Name = L"buttons34";
            this->buttons34->Size = System::Drawing::Size(138, 54);
            this->buttons34->TabIndex = 213;
            this->buttons34->Text = L"free";
            this->buttons34->UseVisualStyleBackColor = false;
            this->buttons34->Click += gcnew System::EventHandler(this, &MyForm::buttons34_Click);
            // 
            // buttons35
            // 
            this->buttons35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons35->Location = System::Drawing::Point(1108, 877);
            this->buttons35->Name = L"buttons35";
            this->buttons35->Size = System::Drawing::Size(138, 54);
            this->buttons35->TabIndex = 214;
            this->buttons35->Text = L"free";
            this->buttons35->UseVisualStyleBackColor = false;
            this->buttons35->Click += gcnew System::EventHandler(this, &MyForm::buttons35_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(345, 580);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(85, 28);
            this->label5->TabIndex = 218;
            this->label5->Text = L"Monday";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(348, 884);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(90, 28);
            this->label6->TabIndex = 219;
            this->label6->Text = L"Saturday";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(362, 829);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(66, 28);
            this->label7->TabIndex = 220;
            this->label7->Text = L"Friday";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(341, 767);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(91, 28);
            this->label8->TabIndex = 221;
            this->label8->Text = L"Thursday";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(331, 706);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(113, 28);
            this->label9->TabIndex = 222;
            this->label9->Text = L"Wednesday";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(345, 637);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(83, 28);
            this->label10->TabIndex = 223;
            this->label10->Text = L"Tuesday";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(500, 510);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(105, 28);
            this->label4->TabIndex = 224;
            this->label4->Text = L"9:00-10:00";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(641, 510);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(116, 28);
            this->label11->TabIndex = 225;
            this->label11->Text = L"10:00-11:00";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(781, 510);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(116, 28);
            this->label12->TabIndex = 226;
            this->label12->Text = L"11:30-12:30";
            // 
            // addteacherpanel
            // 
            this->addteacherpanel->AutoScroll = true;
            this->addteacherpanel->Controls->Add(this->label50);
            this->addteacherpanel->Controls->Add(this->label40);
            this->addteacherpanel->Controls->Add(this->label12);
            this->addteacherpanel->Controls->Add(this->label11);
            this->addteacherpanel->Controls->Add(this->label4);
            this->addteacherpanel->Controls->Add(this->label10);
            this->addteacherpanel->Controls->Add(this->label9);
            this->addteacherpanel->Controls->Add(this->label8);
            this->addteacherpanel->Controls->Add(this->label7);
            this->addteacherpanel->Controls->Add(this->label6);
            this->addteacherpanel->Controls->Add(this->label5);
            this->addteacherpanel->Controls->Add(this->buttons35);
            this->addteacherpanel->Controls->Add(this->buttons34);
            this->addteacherpanel->Controls->Add(this->buttons33);
            this->addteacherpanel->Controls->Add(this->buttons32);
            this->addteacherpanel->Controls->Add(this->buttons31);
            this->addteacherpanel->Controls->Add(this->buttons29);
            this->addteacherpanel->Controls->Add(this->buttons28);
            this->addteacherpanel->Controls->Add(this->buttons27);
            this->addteacherpanel->Controls->Add(this->buttons26);
            this->addteacherpanel->Controls->Add(this->buttons25);
            this->addteacherpanel->Controls->Add(this->buttons24);
            this->addteacherpanel->Controls->Add(this->buttons23);
            this->addteacherpanel->Controls->Add(this->buttons22);
            this->addteacherpanel->Controls->Add(this->buttons21);
            this->addteacherpanel->Controls->Add(this->buttons20);
            this->addteacherpanel->Controls->Add(this->buttons19);
            this->addteacherpanel->Controls->Add(this->buttons18);
            this->addteacherpanel->Controls->Add(this->buttons17);
            this->addteacherpanel->Controls->Add(this->buttons16);
            this->addteacherpanel->Controls->Add(this->buttons15);
            this->addteacherpanel->Controls->Add(this->buttons14);
            this->addteacherpanel->Controls->Add(this->buttons13);
            this->addteacherpanel->Controls->Add(this->buttons12);
            this->addteacherpanel->Controls->Add(this->buttons11);
            this->addteacherpanel->Controls->Add(this->buttons10);
            this->addteacherpanel->Controls->Add(this->buttons9);
            this->addteacherpanel->Controls->Add(this->buttons8);
            this->addteacherpanel->Controls->Add(this->buttons7);
            this->addteacherpanel->Controls->Add(this->buttons6);
            this->addteacherpanel->Controls->Add(this->buttons5);
            this->addteacherpanel->Controls->Add(this->buttons4);
            this->addteacherpanel->Controls->Add(this->buttons3);
            this->addteacherpanel->Controls->Add(this->buttons2);
            this->addteacherpanel->Controls->Add(this->buttons1);
            this->addteacherpanel->Controls->Add(this->label3);
            this->addteacherpanel->Controls->Add(this->comboBox1);
            this->addteacherpanel->Controls->Add(this->label2);
            this->addteacherpanel->Controls->Add(this->textBox2);
            this->addteacherpanel->Controls->Add(this->button37);
            this->addteacherpanel->Controls->Add(this->button38);
            this->addteacherpanel->Controls->Add(this->buttons30);
            this->addteacherpanel->Controls->Add(this->buttons36);
            this->addteacherpanel->Controls->Add(this->label1);
            this->addteacherpanel->Controls->Add(this->label14);
            this->addteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addteacherpanel->Location = System::Drawing::Point(0, 0);
            this->addteacherpanel->Name = L"addteacherpanel";
            this->addteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->addteacherpanel->TabIndex = 175;
            this->addteacherpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint);
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(1270, 511);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(94, 28);
            this->label50->TabIndex = 230;
            this->label50->Text = L"3:30-4:30";
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(959, 510);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(116, 28);
            this->label40->TabIndex = 229;
            this->label40->Text = L"12:30-11:30";
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
            // dataGridView2
            // 
            this->dataGridView2->AllowUserToOrderColumns = true;
            dataGridViewCellStyle58->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle58->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle58->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle58->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle58;
            this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle59->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle59->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle59->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle59->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle59->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle59->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle59;
            this->dataGridView2->ColumnHeadersHeight = 40;
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewButtonColumn1
            });
            dataGridViewCellStyle62->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle62->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle62->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle62->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle62->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle62->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle62;
            this->dataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->Location = System::Drawing::Point(372, 348);
            this->dataGridView2->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView2->Name = L"dataGridView2";
            dataGridViewCellStyle63->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle63->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle63->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle63->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle63->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle63->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle63;
            this->dataGridView2->RowHeadersVisible = false;
            this->dataGridView2->RowHeadersWidth = 62;
            dataGridViewCellStyle64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle64->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle64->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle64->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->RowsDefaultCellStyle = dataGridViewCellStyle64;
            this->dataGridView2->RowTemplate->Height = 28;
            this->dataGridView2->Size = System::Drawing::Size(735, 300);
            this->dataGridView2->TabIndex = 233;
            this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick_1);
            // 
            // dataGridViewTextBoxColumn1
            // 
            dataGridViewCellStyle60->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle60->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle60->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle60->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle60->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle60->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle60;
            this->dataGridViewTextBoxColumn1->HeaderText = L"Department";
            this->dataGridViewTextBoxColumn1->MinimumWidth = 30;
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle61->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle61->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle61->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle61->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle61;
            this->dataGridViewButtonColumn1->HeaderText = L"";
            this->dataGridViewButtonColumn1->MinimumWidth = 100;
            this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
            this->dataGridViewButtonColumn1->ReadOnly = true;
            this->dataGridViewButtonColumn1->Text = L"Delete";
            this->dataGridViewButtonColumn1->UseColumnTextForButtonValue = true;
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
            // pictureBox8
            // 
            this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
            this->pictureBox8->Location = System::Drawing::Point(716, -1);
            this->pictureBox8->Name = L"pictureBox8";
            this->pictureBox8->Size = System::Drawing::Size(137, 132);
            this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox8->TabIndex = 1;
            this->pictureBox8->TabStop = false;
            // 
            // pictureBox9
            // 
            this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
            this->pictureBox9->Location = System::Drawing::Point(1753, 53);
            this->pictureBox9->Name = L"pictureBox9";
            this->pictureBox9->Size = System::Drawing::Size(39, 41);
            this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox9->TabIndex = 2;
            this->pictureBox9->TabStop = false;
            // 
            // pictureBox10
            // 
            this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
            this->pictureBox10->Location = System::Drawing::Point(1827, 53);
            this->pictureBox10->Name = L"pictureBox10";
            this->pictureBox10->Size = System::Drawing::Size(39, 41);
            this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox10->TabIndex = 3;
            this->pictureBox10->TabStop = false;
            this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
            // 
            // pictureBox11
            // 
            this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
            this->pictureBox11->Location = System::Drawing::Point(1673, 54);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(39, 41);
            this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox11->TabIndex = 4;
            this->pictureBox11->TabStop = false;
            // 
            // pictureBox12
            // 
            this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
            this->pictureBox12->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.InitialImage")));
            this->pictureBox12->Location = System::Drawing::Point(44, -1);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(187, 137);
            this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox12->TabIndex = 5;
            this->pictureBox12->TabStop = false;
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::White;
            this->panel4->Controls->Add(this->label15);
            this->panel4->Controls->Add(this->pictureBox12);
            this->panel4->Controls->Add(this->pictureBox11);
            this->panel4->Controls->Add(this->pictureBox10);
            this->panel4->Controls->Add(this->pictureBox9);
            this->panel4->Controls->Add(this->pictureBox8);
            this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->panel4->Location = System::Drawing::Point(0, 0);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(1946, 134);
            this->panel4->TabIndex = 2;
            this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->label15->Location = System::Drawing::Point(881, 41);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(383, 54);
            this->label15->TabIndex = 6;
            this->label15->Text = L"TimetableArchitect";
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(330, 137);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(77, 28);
            this->label38->TabIndex = 240;
            this->label38->Text = L"Section";
            // 
            // maskedTextBox2
            // 
            this->maskedTextBox2->AllowPromptAsInput = false;
            this->maskedTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox2->Location = System::Drawing::Point(335, 178);
            this->maskedTextBox2->Mask = L"A";
            this->maskedTextBox2->Name = L"maskedTextBox2";
            this->maskedTextBox2->Size = System::Drawing::Size(410, 34);
            this->maskedTextBox2->TabIndex = 244;
            // 
            // comboBox3
            // 
            this->comboBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->comboBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox3->FormattingEnabled = true;
            this->comboBox3->Location = System::Drawing::Point(339, 303);
            this->comboBox3->Name = L"comboBox3";
            this->comboBox3->Size = System::Drawing::Size(406, 36);
            this->comboBox3->TabIndex = 245;
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->Location = System::Drawing::Point(333, 389);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(225, 28);
            this->label37->TabIndex = 241;
            this->label37->Text = L"Batch(year of admission)";
            // 
            // maskedTextBox1
            // 
            this->maskedTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->maskedTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maskedTextBox1->HidePromptOnLeave = true;
            this->maskedTextBox1->HideSelection = false;
            this->maskedTextBox1->Location = System::Drawing::Point(341, 441);
            this->maskedTextBox1->Mask = L"0000";
            this->maskedTextBox1->Name = L"maskedTextBox1";
            this->maskedTextBox1->Size = System::Drawing::Size(404, 27);
            this->maskedTextBox1->SkipLiterals = false;
            this->maskedTextBox1->TabIndex = 242;
            this->maskedTextBox1->ValidatingType = System::Int32::typeid;
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->Location = System::Drawing::Point(333, 527);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(520, 84);
            this->label36->TabIndex = 243;
            this->label36->Text = L"Select the subjects taught and their corresponding teacher\r\n\r\n for non-elective a"
                L"nd non-lab subjects";
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->label35->Location = System::Drawing::Point(334, 1137);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(124, 28);
            this->label35->TabIndex = 249;
            this->label35->Text = L"Lab subjects";
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Location = System::Drawing::Point(338, 1555);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(287, 155);
            this->checkedListBox1->TabIndex = 250;
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label34->Location = System::Drawing::Point(345, 1513);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(136, 28);
            this->label34->TabIndex = 251;
            this->label34->Text = L"Default rooms";
            // 
            // button19
            // 
            this->button19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button19->Location = System::Drawing::Point(727, 1754);
            this->button19->Name = L"button19";
            this->button19->Size = System::Drawing::Size(147, 44);
            this->button19->TabIndex = 248;
            this->button19->Text = L"Generate";
            this->button19->UseVisualStyleBackColor = false;
            // 
            // button17
            // 
            this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button17->Location = System::Drawing::Point(921, 1754);
            this->button17->Name = L"button17";
            this->button17->Size = System::Drawing::Size(104, 44);
            this->button17->TabIndex = 247;
            this->button17->Text = L"Save";
            this->button17->UseVisualStyleBackColor = false;
            this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
            // 
            // button16
            // 
            this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button16->Location = System::Drawing::Point(1083, 1754);
            this->button16->Name = L"button16";
            this->button16->Size = System::Drawing::Size(132, 44);
            this->button16->TabIndex = 246;
            this->button16->Text = L"Add New";
            this->button16->UseVisualStyleBackColor = false;
            // 
            // dataGridView3
            // 
            this->dataGridView3->AllowUserToOrderColumns = true;
            dataGridViewCellStyle65->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle65->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle65->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle65->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle65;
            this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle66->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle66->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle66->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle66->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle66->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle66->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle66->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle66;
            this->dataGridView3->ColumnHeadersHeight = 40;
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->eSubject,
                    this->dataGridViewButtonColumn3
            });
            dataGridViewCellStyle69->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle69->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle69->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle69->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle69->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle69->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView3->DefaultCellStyle = dataGridViewCellStyle69;
            this->dataGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->Location = System::Drawing::Point(335, 939);
            this->dataGridView3->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView3->Name = L"dataGridView3";
            dataGridViewCellStyle70->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle70->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle70->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle70->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle70->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle70->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->RowHeadersDefaultCellStyle = dataGridViewCellStyle70;
            this->dataGridView3->RowHeadersVisible = false;
            this->dataGridView3->RowHeadersWidth = 62;
            dataGridViewCellStyle71->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle71->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle71->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle71->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->RowsDefaultCellStyle = dataGridViewCellStyle71;
            this->dataGridView3->RowTemplate->Height = 28;
            this->dataGridView3->Size = System::Drawing::Size(735, 226);
            this->dataGridView3->TabIndex = 253;
            this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
            // 
            // eSubject
            // 
            dataGridViewCellStyle67->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle67->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle67->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle67->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle67->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle67->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->DefaultCellStyle = dataGridViewCellStyle67;
            this->eSubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->eSubject->HeaderText = L"Subject";
            this->eSubject->MinimumWidth = 30;
            this->eSubject->Name = L"eSubject";
            this->eSubject->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->Width = 350;
            // 
            // dataGridViewButtonColumn3
            // 
            this->dataGridViewButtonColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle68->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle68->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle68->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle68->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle68->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle68;
            this->dataGridViewButtonColumn3->DividerWidth = 1;
            this->dataGridViewButtonColumn3->HeaderText = L"";
            this->dataGridViewButtonColumn3->MinimumWidth = 100;
            this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
            this->dataGridViewButtonColumn3->ReadOnly = true;
            this->dataGridViewButtonColumn3->Text = L"Delete";
            this->dataGridViewButtonColumn3->UseColumnTextForButtonValue = true;
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToOrderColumns = true;
            dataGridViewCellStyle72->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle72->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle72->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle72->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle72;
            this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle73->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle73->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle73->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle73->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle73->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle73->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle73->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle73;
            this->dataGridView1->ColumnHeadersHeight = 40;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->lsubject,
                    this->dataGridViewButtonColumn2
            });
            dataGridViewCellStyle76->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle76->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle76->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle76->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle76->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle76->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle76->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle76;
            this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->Location = System::Drawing::Point(335, 1278);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            dataGridViewCellStyle77->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle77->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle77->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle77->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle77->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle77->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle77->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle77;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 62;
            dataGridViewCellStyle78->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle78->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle78->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle78->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle78;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(735, 211);
            this->dataGridView1->TabIndex = 254;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            // 
            // lsubject
            // 
            dataGridViewCellStyle74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle74->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle74->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle74->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle74->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle74->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->lsubject->DefaultCellStyle = dataGridViewCellStyle74;
            this->lsubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->lsubject->HeaderText = L"Subject";
            this->lsubject->MinimumWidth = 30;
            this->lsubject->Name = L"lsubject";
            this->lsubject->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->lsubject->Width = 350;
            // 
            // dataGridViewButtonColumn2
            // 
            this->dataGridViewButtonColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle75->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle75->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle75->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle75->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle75->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle75;
            this->dataGridViewButtonColumn2->DividerWidth = 1;
            this->dataGridViewButtonColumn2->HeaderText = L"";
            this->dataGridViewButtonColumn2->MinimumWidth = 100;
            this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
            this->dataGridViewButtonColumn2->ReadOnly = true;
            this->dataGridViewButtonColumn2->Text = L"Delete";
            this->dataGridViewButtonColumn2->UseColumnTextForButtonValue = true;
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label33->Location = System::Drawing::Point(334, 894);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(153, 28);
            this->label33->TabIndex = 255;
            this->label33->Text = L"Elective subjects";
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label32->Location = System::Drawing::Point(334, 1227);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(118, 28);
            this->label32->TabIndex = 256;
            this->label32->Text = L"Lab subjects";
            // 
            // dataGridView6
            // 
            this->dataGridView6->AllowUserToOrderColumns = true;
            dataGridViewCellStyle79->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle79->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle79->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle79->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle79;
            this->dataGridView6->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView6->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView6->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle80->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle80->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle80->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle80->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle80->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle80->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle80->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle80;
            this->dataGridView6->ColumnHeadersHeight = 40;
            this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->csubject,
                    this->dataGridViewComboBoxColumn3, this->dataGridViewButtonColumn6
            });
            dataGridViewCellStyle84->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle84->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle84->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle84->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle84->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle84->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView6->DefaultCellStyle = dataGridViewCellStyle84;
            this->dataGridView6->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->Location = System::Drawing::Point(338, 642);
            this->dataGridView6->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView6->Name = L"dataGridView6";
            dataGridViewCellStyle85->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle85->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle85->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle85->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle85->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle85->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->RowHeadersDefaultCellStyle = dataGridViewCellStyle85;
            this->dataGridView6->RowHeadersVisible = false;
            this->dataGridView6->RowHeadersWidth = 62;
            dataGridViewCellStyle86->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle86->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle86->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle86->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->RowsDefaultCellStyle = dataGridViewCellStyle86;
            this->dataGridView6->RowTemplate->Height = 28;
            this->dataGridView6->Size = System::Drawing::Size(735, 207);
            this->dataGridView6->TabIndex = 257;
            this->dataGridView6->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView6_CellContentClick);
            // 
            // csubject
            // 
            dataGridViewCellStyle81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle81->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle81->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle81->SelectionForeColor = System::Drawing::Color::Black;
            this->csubject->DefaultCellStyle = dataGridViewCellStyle81;
            this->csubject->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->csubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->csubject->HeaderText = L"Subject";
            this->csubject->MinimumWidth = 8;
            this->csubject->Name = L"csubject";
            this->csubject->Width = 150;
            // 
            // dataGridViewComboBoxColumn3
            // 
            dataGridViewCellStyle82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle82->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle82->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle82->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle82->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle82->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn3->DefaultCellStyle = dataGridViewCellStyle82;
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
            dataGridViewCellStyle83->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle83->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle83->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle83->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn6->DefaultCellStyle = dataGridViewCellStyle83;
            this->dataGridViewButtonColumn6->DividerWidth = 1;
            this->dataGridViewButtonColumn6->HeaderText = L"";
            this->dataGridViewButtonColumn6->MinimumWidth = 100;
            this->dataGridViewButtonColumn6->Name = L"dataGridViewButtonColumn6";
            this->dataGridViewButtonColumn6->ReadOnly = true;
            this->dataGridViewButtonColumn6->Text = L"Delete";
            this->dataGridViewButtonColumn6->UseColumnTextForButtonValue = true;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(334, 263);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(71, 28);
            this->label13->TabIndex = 258;
            this->label13->Text = L"Branch";
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->panel1->Controls->Add(this->textBox7);
            this->panel1->Controls->Add(this->textBox9);
            this->panel1->Controls->Add(this->textBox11);
            this->panel1->Controls->Add(this->textBox6);
            this->panel1->Controls->Add(this->textBox8);
            this->panel1->Controls->Add(this->textBox10);
            this->panel1->Controls->Add(this->textBox5);
            this->panel1->Controls->Add(this->textBox4);
            this->panel1->Controls->Add(this->pictureBox7);
            this->panel1->Controls->Add(this->pictureBox6);
            this->panel1->Controls->Add(this->pictureBox5);
            this->panel1->Controls->Add(this->pictureBox4);
            this->panel1->Controls->Add(this->pictureBox3);
            this->panel1->Controls->Add(this->pictureBox2);
            this->panel1->Controls->Add(this->panel3);
            this->panel1->Controls->Add(this->Homebutton1);
            this->panel1->Controls->Add(this->button13);
            this->panel1->Controls->Add(this->button14);
            this->panel1->Controls->Add(this->button15);
            this->panel1->Controls->Add(this->button10);
            this->panel1->Controls->Add(this->button11);
            this->panel1->Controls->Add(this->button12);
            this->panel1->Controls->Add(this->button7);
            this->panel1->Controls->Add(this->button4);
            this->panel1->Controls->Add(this->button8);
            this->panel1->Controls->Add(this->button5);
            this->panel1->Controls->Add(this->button9);
            this->panel1->Controls->Add(this->button6);
            this->panel1->Controls->Add(this->button1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel1->Location = System::Drawing::Point(0, 134);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(324, 972);
            this->panel1->TabIndex = 259;
            // 
            // textBox7
            // 
            this->textBox7->AutoSize = true;
            this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox7->Location = System::Drawing::Point(251, 413);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(28, 26);
            this->textBox7->TabIndex = 37;
            this->textBox7->Text = L"◢";
            // 
            // textBox9
            // 
            this->textBox9->AutoSize = true;
            this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox9->Location = System::Drawing::Point(251, 517);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(28, 26);
            this->textBox9->TabIndex = 36;
            this->textBox9->Text = L"◢";
            // 
            // textBox11
            // 
            this->textBox11->AutoSize = true;
            this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox11->Location = System::Drawing::Point(245, 628);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(28, 26);
            this->textBox11->TabIndex = 35;
            this->textBox11->Text = L"◢";
            this->textBox11->Visible = false;
            this->textBox11->Click += gcnew System::EventHandler(this, &MyForm::textBox11_Click);
            // 
            // textBox6
            // 
            this->textBox6->AutoSize = true;
            this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox6->Location = System::Drawing::Point(258, 413);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(28, 26);
            this->textBox6->TabIndex = 34;
            this->textBox6->Text = L"◤";
            // 
            // textBox8
            // 
            this->textBox8->AutoSize = true;
            this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox8->Location = System::Drawing::Point(252, 519);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(28, 26);
            this->textBox8->TabIndex = 33;
            this->textBox8->Text = L"◤";
            // 
            // textBox10
            // 
            this->textBox10->AutoSize = true;
            this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox10->Location = System::Drawing::Point(251, 628);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(28, 26);
            this->textBox10->TabIndex = 32;
            this->textBox10->Text = L"◤";
            this->textBox10->Visible = false;
            // 
            // textBox5
            // 
            this->textBox5->AutoSize = true;
            this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox5->Location = System::Drawing::Point(258, 308);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(28, 26);
            this->textBox5->TabIndex = 7;
            this->textBox5->Text = L"◢";
            // 
            // textBox4
            // 
            this->textBox4->AutoSize = true;
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox4->Location = System::Drawing::Point(258, 308);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(28, 26);
            this->textBox4->TabIndex = 8;
            this->textBox4->Text = L"◤";
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(47, 611);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(56, 40);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox7->TabIndex = 31;
            this->pictureBox7->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(47, 511);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(56, 40);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(47, 397);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(56, 40);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(47, 299);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(56, 40);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(47, 199);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(56, 40);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(47, 84);
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
            this->panel3->Location = System::Drawing::Point(15, 84);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(4, 40);
            this->panel3->TabIndex = 6;
            // 
            // Homebutton1
            // 
            this->Homebutton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
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
            this->Homebutton1->ForeColor = System::Drawing::Color::White;
            this->Homebutton1->Location = System::Drawing::Point(6, 84);
            this->Homebutton1->Name = L"Homebutton1";
            this->Homebutton1->Size = System::Drawing::Size(267, 40);
            this->Homebutton1->TabIndex = 26;
            this->Homebutton1->Text = L"    Home";
            this->Homebutton1->UseVisualStyleBackColor = false;
            this->Homebutton1->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            // 
            // button13
            // 
            this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button13->FlatAppearance->BorderSize = 0;
            this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button13->ForeColor = System::Drawing::Color::White;
            this->button13->Location = System::Drawing::Point(-3, 683);
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
            this->button14->Location = System::Drawing::Point(-3, 653);
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
            this->button15->Location = System::Drawing::Point(60, 611);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(267, 40);
            this->button15->TabIndex = 22;
            this->button15->Text = L"Classes";
            this->button15->UseVisualStyleBackColor = false;
            this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
            // 
            // button10
            // 
            this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button10->FlatAppearance->BorderSize = 0;
            this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button10->ForeColor = System::Drawing::Color::White;
            this->button10->Location = System::Drawing::Point(3, 587);
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
            this->button11->Location = System::Drawing::Point(3, 557);
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
            this->button12->Location = System::Drawing::Point(63, 511);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(267, 40);
            this->button12->TabIndex = 17;
            this->button12->Text = L"Subjects";
            this->button12->UseVisualStyleBackColor = false;
            this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button7->FlatAppearance->BorderSize = 0;
            this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button7->ForeColor = System::Drawing::Color::White;
            this->button7->Location = System::Drawing::Point(-3, 473);
            this->button7->Margin = System::Windows::Forms::Padding(0);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(267, 30);
            this->button7->TabIndex = 14;
            this->button7->Text = L"Edit                 ";
            this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Visible = false;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click_1);
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button4->FlatAppearance->BorderSize = 0;
            this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button4->ForeColor = System::Drawing::Color::White;
            this->button4->Location = System::Drawing::Point(0, 372);
            this->button4->Margin = System::Windows::Forms::Padding(0);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(267, 30);
            this->button4->TabIndex = 14;
            this->button4->Text = L"Edit                 ";
            this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Visible = false;
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button8->FlatAppearance->BorderSize = 0;
            this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button8->ForeColor = System::Drawing::Color::White;
            this->button8->Location = System::Drawing::Point(0, 449);
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
            this->button5->Location = System::Drawing::Point(0, 342);
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
            this->button9->Location = System::Drawing::Point(37, 405);
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
            this->button6->Location = System::Drawing::Point(37, 299);
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
            this->button1->Location = System::Drawing::Point(37, 199);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(290, 40);
            this->button1->TabIndex = 2;
            this->button1->Text = L"Departments";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // panel5
            // 
            this->panel5->AutoScroll = true;
            this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel5->Controls->Add(this->label13);
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
            this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint_1);
            // 
            // editteacherpanel
            // 
            this->editteacherpanel->AutoScroll = true;
            this->editteacherpanel->Controls->Add(this->pictureBox13);
            this->editteacherpanel->Controls->Add(this->button18);
            this->editteacherpanel->Controls->Add(this->textBox1);
            this->editteacherpanel->Controls->Add(this->label51);
            this->editteacherpanel->Controls->Add(this->label52);
            this->editteacherpanel->Controls->Add(this->label53);
            this->editteacherpanel->Controls->Add(this->label54);
            this->editteacherpanel->Controls->Add(this->label55);
            this->editteacherpanel->Controls->Add(this->label56);
            this->editteacherpanel->Controls->Add(this->label57);
            this->editteacherpanel->Controls->Add(this->label58);
            this->editteacherpanel->Controls->Add(this->label59);
            this->editteacherpanel->Controls->Add(this->label60);
            this->editteacherpanel->Controls->Add(this->label61);
            this->editteacherpanel->Controls->Add(this->buttont35);
            this->editteacherpanel->Controls->Add(this->buttont34);
            this->editteacherpanel->Controls->Add(this->buttont33);
            this->editteacherpanel->Controls->Add(this->buttont32);
            this->editteacherpanel->Controls->Add(this->buttont31);
            this->editteacherpanel->Controls->Add(this->buttont29);
            this->editteacherpanel->Controls->Add(this->buttont28);
            this->editteacherpanel->Controls->Add(this->buttont27);
            this->editteacherpanel->Controls->Add(this->buttont26);
            this->editteacherpanel->Controls->Add(this->buttont25);
            this->editteacherpanel->Controls->Add(this->buttont24);
            this->editteacherpanel->Controls->Add(this->buttont23);
            this->editteacherpanel->Controls->Add(this->buttont22);
            this->editteacherpanel->Controls->Add(this->buttont21);
            this->editteacherpanel->Controls->Add(this->buttont20);
            this->editteacherpanel->Controls->Add(this->buttont19);
            this->editteacherpanel->Controls->Add(this->buttont18);
            this->editteacherpanel->Controls->Add(this->buttont17);
            this->editteacherpanel->Controls->Add(this->buttont16);
            this->editteacherpanel->Controls->Add(this->buttont15);
            this->editteacherpanel->Controls->Add(this->buttont14);
            this->editteacherpanel->Controls->Add(this->buttont13);
            this->editteacherpanel->Controls->Add(this->buttont12);
            this->editteacherpanel->Controls->Add(this->buttont11);
            this->editteacherpanel->Controls->Add(this->buttont10);
            this->editteacherpanel->Controls->Add(this->buttont9);
            this->editteacherpanel->Controls->Add(this->buttont8);
            this->editteacherpanel->Controls->Add(this->buttont7);
            this->editteacherpanel->Controls->Add(this->buttont6);
            this->editteacherpanel->Controls->Add(this->buttont5);
            this->editteacherpanel->Controls->Add(this->buttont4);
            this->editteacherpanel->Controls->Add(this->buttont3);
            this->editteacherpanel->Controls->Add(this->buttont2);
            this->editteacherpanel->Controls->Add(this->buttont1);
            this->editteacherpanel->Controls->Add(this->label62);
            this->editteacherpanel->Controls->Add(this->editteacherdepartment);
            this->editteacherpanel->Controls->Add(this->label63);
            this->editteacherpanel->Controls->Add(this->editteachername);
            this->editteacherpanel->Controls->Add(this->button55);
            this->editteacherpanel->Controls->Add(this->buttont30);
            this->editteacherpanel->Controls->Add(this->buttont36);
            this->editteacherpanel->Controls->Add(this->label64);
            this->editteacherpanel->Controls->Add(this->label65);
            this->editteacherpanel->Controls->Add(this->teachersearch);
            this->editteacherpanel->Controls->Add(this->label39);
            this->editteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editteacherpanel->Location = System::Drawing::Point(0, 0);
            this->editteacherpanel->Name = L"editteacherpanel";
            this->editteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->editteacherpanel->TabIndex = 264;
            this->editteacherpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editteacherpanel_Paint);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(1115, 589);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(124, 26);
            this->textBox1->TabIndex = 286;
            // 
            // label51
            // 
            this->label51->AutoSize = true;
            this->label51->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(1267, 780);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(94, 28);
            this->label51->TabIndex = 285;
            this->label51->Text = L"3:30-4:30";
            // 
            // label52
            // 
            this->label52->AutoSize = true;
            this->label52->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label52->Location = System::Drawing::Point(956, 779);
            this->label52->Name = L"label52";
            this->label52->Size = System::Drawing::Size(116, 28);
            this->label52->TabIndex = 284;
            this->label52->Text = L"12:30-11:30";
            // 
            // label53
            // 
            this->label53->AutoSize = true;
            this->label53->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label53->Location = System::Drawing::Point(778, 779);
            this->label53->Name = L"label53";
            this->label53->Size = System::Drawing::Size(116, 28);
            this->label53->TabIndex = 282;
            this->label53->Text = L"11:30-12:30";
            // 
            // label54
            // 
            this->label54->AutoSize = true;
            this->label54->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label54->Location = System::Drawing::Point(638, 779);
            this->label54->Name = L"label54";
            this->label54->Size = System::Drawing::Size(116, 28);
            this->label54->TabIndex = 281;
            this->label54->Text = L"10:00-11:00";
            // 
            // label55
            // 
            this->label55->AutoSize = true;
            this->label55->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label55->Location = System::Drawing::Point(497, 779);
            this->label55->Name = L"label55";
            this->label55->Size = System::Drawing::Size(105, 28);
            this->label55->TabIndex = 280;
            this->label55->Text = L"9:00-10:00";
            // 
            // label56
            // 
            this->label56->AutoSize = true;
            this->label56->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label56->Location = System::Drawing::Point(342, 906);
            this->label56->Name = L"label56";
            this->label56->Size = System::Drawing::Size(83, 28);
            this->label56->TabIndex = 279;
            this->label56->Text = L"Tuesday";
            // 
            // label57
            // 
            this->label57->AutoSize = true;
            this->label57->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label57->Location = System::Drawing::Point(328, 975);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(113, 28);
            this->label57->TabIndex = 278;
            this->label57->Text = L"Wednesday";
            // 
            // label58
            // 
            this->label58->AutoSize = true;
            this->label58->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label58->Location = System::Drawing::Point(338, 1036);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(91, 28);
            this->label58->TabIndex = 277;
            this->label58->Text = L"Thursday";
            // 
            // label59
            // 
            this->label59->AutoSize = true;
            this->label59->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label59->Location = System::Drawing::Point(359, 1098);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(66, 28);
            this->label59->TabIndex = 276;
            this->label59->Text = L"Friday";
            // 
            // label60
            // 
            this->label60->AutoSize = true;
            this->label60->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label60->Location = System::Drawing::Point(345, 1153);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(90, 28);
            this->label60->TabIndex = 275;
            this->label60->Text = L"Saturday";
            // 
            // label61
            // 
            this->label61->AutoSize = true;
            this->label61->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label61->Location = System::Drawing::Point(342, 849);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(85, 28);
            this->label61->TabIndex = 274;
            this->label61->Text = L"Monday";
            // 
            // buttont35
            // 
            this->buttont35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont35->Location = System::Drawing::Point(1105, 1146);
            this->buttont35->Name = L"buttont35";
            this->buttont35->Size = System::Drawing::Size(138, 54);
            this->buttont35->TabIndex = 270;
            this->buttont35->Text = L"free";
            this->buttont35->UseVisualStyleBackColor = false;
            // 
            // buttont34
            // 
            this->buttont34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont34->Location = System::Drawing::Point(946, 1146);
            this->buttont34->Name = L"buttont34";
            this->buttont34->Size = System::Drawing::Size(138, 54);
            this->buttont34->TabIndex = 269;
            this->buttont34->Text = L"free";
            this->buttont34->UseVisualStyleBackColor = false;
            // 
            // buttont33
            // 
            this->buttont33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont33->Location = System::Drawing::Point(793, 1146);
            this->buttont33->Name = L"buttont33";
            this->buttont33->Size = System::Drawing::Size(138, 54);
            this->buttont33->TabIndex = 268;
            this->buttont33->Text = L"free";
            this->buttont33->UseVisualStyleBackColor = false;
            // 
            // buttont32
            // 
            this->buttont32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont32->Location = System::Drawing::Point(634, 1146);
            this->buttont32->Name = L"buttont32";
            this->buttont32->Size = System::Drawing::Size(138, 54);
            this->buttont32->TabIndex = 267;
            this->buttont32->Text = L"free";
            this->buttont32->UseVisualStyleBackColor = false;
            // 
            // buttont31
            // 
            this->buttont31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont31->Location = System::Drawing::Point(479, 1146);
            this->buttont31->Name = L"buttont31";
            this->buttont31->Size = System::Drawing::Size(138, 54);
            this->buttont31->TabIndex = 266;
            this->buttont31->Text = L"free";
            this->buttont31->UseVisualStyleBackColor = false;
            // 
            // buttont29
            // 
            this->buttont29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont29->Location = System::Drawing::Point(1105, 1085);
            this->buttont29->Name = L"buttont29";
            this->buttont29->Size = System::Drawing::Size(138, 55);
            this->buttont29->TabIndex = 264;
            this->buttont29->Text = L"free";
            this->buttont29->UseVisualStyleBackColor = false;
            // 
            // buttont28
            // 
            this->buttont28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont28->Location = System::Drawing::Point(946, 1085);
            this->buttont28->Name = L"buttont28";
            this->buttont28->Size = System::Drawing::Size(138, 55);
            this->buttont28->TabIndex = 263;
            this->buttont28->Text = L"free";
            this->buttont28->UseVisualStyleBackColor = false;
            // 
            // buttont27
            // 
            this->buttont27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont27->Location = System::Drawing::Point(793, 1085);
            this->buttont27->Name = L"buttont27";
            this->buttont27->Size = System::Drawing::Size(138, 55);
            this->buttont27->TabIndex = 262;
            this->buttont27->Text = L"free";
            this->buttont27->UseVisualStyleBackColor = false;
            // 
            // buttont26
            // 
            this->buttont26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont26->Location = System::Drawing::Point(634, 1085);
            this->buttont26->Name = L"buttont26";
            this->buttont26->Size = System::Drawing::Size(138, 55);
            this->buttont26->TabIndex = 261;
            this->buttont26->Text = L"free";
            this->buttont26->UseVisualStyleBackColor = false;
            // 
            // buttont25
            // 
            this->buttont25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont25->Location = System::Drawing::Point(479, 1085);
            this->buttont25->Name = L"buttont25";
            this->buttont25->Size = System::Drawing::Size(138, 55);
            this->buttont25->TabIndex = 260;
            this->buttont25->Text = L"free";
            this->buttont25->UseVisualStyleBackColor = false;
            // 
            // buttont24
            // 
            this->buttont24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont24->Location = System::Drawing::Point(1260, 1022);
            this->buttont24->Name = L"buttont24";
            this->buttont24->Size = System::Drawing::Size(138, 55);
            this->buttont24->TabIndex = 259;
            this->buttont24->Text = L"free";
            this->buttont24->UseVisualStyleBackColor = false;
            // 
            // buttont23
            // 
            this->buttont23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont23->Location = System::Drawing::Point(1105, 1023);
            this->buttont23->Name = L"buttont23";
            this->buttont23->Size = System::Drawing::Size(138, 55);
            this->buttont23->TabIndex = 258;
            this->buttont23->Text = L"free";
            this->buttont23->UseVisualStyleBackColor = false;
            // 
            // buttont22
            // 
            this->buttont22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont22->Location = System::Drawing::Point(946, 1022);
            this->buttont22->Name = L"buttont22";
            this->buttont22->Size = System::Drawing::Size(138, 55);
            this->buttont22->TabIndex = 257;
            this->buttont22->Text = L"free";
            this->buttont22->UseVisualStyleBackColor = false;
            // 
            // buttont21
            // 
            this->buttont21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont21->Location = System::Drawing::Point(793, 1023);
            this->buttont21->Name = L"buttont21";
            this->buttont21->Size = System::Drawing::Size(138, 55);
            this->buttont21->TabIndex = 256;
            this->buttont21->Text = L"free";
            this->buttont21->UseVisualStyleBackColor = false;
            // 
            // buttont20
            // 
            this->buttont20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont20->Location = System::Drawing::Point(634, 1023);
            this->buttont20->Name = L"buttont20";
            this->buttont20->Size = System::Drawing::Size(138, 55);
            this->buttont20->TabIndex = 255;
            this->buttont20->Text = L"free";
            this->buttont20->UseVisualStyleBackColor = false;
            // 
            // buttont19
            // 
            this->buttont19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont19->Location = System::Drawing::Point(479, 1022);
            this->buttont19->Name = L"buttont19";
            this->buttont19->Size = System::Drawing::Size(138, 55);
            this->buttont19->TabIndex = 254;
            this->buttont19->Text = L"free";
            this->buttont19->UseVisualStyleBackColor = false;
            // 
            // buttont18
            // 
            this->buttont18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont18->Location = System::Drawing::Point(1260, 965);
            this->buttont18->Name = L"buttont18";
            this->buttont18->Size = System::Drawing::Size(138, 55);
            this->buttont18->TabIndex = 253;
            this->buttont18->Text = L"free";
            this->buttont18->UseVisualStyleBackColor = false;
            // 
            // buttont17
            // 
            this->buttont17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont17->Location = System::Drawing::Point(1105, 962);
            this->buttont17->Name = L"buttont17";
            this->buttont17->Size = System::Drawing::Size(138, 55);
            this->buttont17->TabIndex = 252;
            this->buttont17->Text = L"free";
            this->buttont17->UseVisualStyleBackColor = false;
            // 
            // buttont16
            // 
            this->buttont16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont16->Location = System::Drawing::Point(946, 962);
            this->buttont16->Name = L"buttont16";
            this->buttont16->Size = System::Drawing::Size(138, 55);
            this->buttont16->TabIndex = 251;
            this->buttont16->Text = L"free";
            this->buttont16->UseVisualStyleBackColor = false;
            // 
            // buttont15
            // 
            this->buttont15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont15->Location = System::Drawing::Point(793, 962);
            this->buttont15->Name = L"buttont15";
            this->buttont15->Size = System::Drawing::Size(138, 55);
            this->buttont15->TabIndex = 250;
            this->buttont15->Text = L"free";
            this->buttont15->UseVisualStyleBackColor = false;
            // 
            // buttont14
            // 
            this->buttont14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont14->Location = System::Drawing::Point(634, 962);
            this->buttont14->Name = L"buttont14";
            this->buttont14->Size = System::Drawing::Size(138, 55);
            this->buttont14->TabIndex = 249;
            this->buttont14->Text = L"free";
            this->buttont14->UseVisualStyleBackColor = false;
            // 
            // buttont13
            // 
            this->buttont13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont13->Location = System::Drawing::Point(479, 962);
            this->buttont13->Name = L"buttont13";
            this->buttont13->Size = System::Drawing::Size(138, 55);
            this->buttont13->TabIndex = 248;
            this->buttont13->Text = L"free";
            this->buttont13->UseVisualStyleBackColor = false;
            // 
            // buttont12
            // 
            this->buttont12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont12->Location = System::Drawing::Point(1260, 901);
            this->buttont12->Name = L"buttont12";
            this->buttont12->Size = System::Drawing::Size(138, 55);
            this->buttont12->TabIndex = 247;
            this->buttont12->Text = L"free";
            this->buttont12->UseVisualStyleBackColor = false;
            // 
            // buttont11
            // 
            this->buttont11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont11->Location = System::Drawing::Point(1105, 901);
            this->buttont11->Name = L"buttont11";
            this->buttont11->Size = System::Drawing::Size(138, 55);
            this->buttont11->TabIndex = 246;
            this->buttont11->Text = L"free";
            this->buttont11->UseVisualStyleBackColor = false;
            // 
            // buttont10
            // 
            this->buttont10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont10->Location = System::Drawing::Point(946, 901);
            this->buttont10->Name = L"buttont10";
            this->buttont10->Size = System::Drawing::Size(138, 55);
            this->buttont10->TabIndex = 245;
            this->buttont10->Text = L"free";
            this->buttont10->UseVisualStyleBackColor = false;
            // 
            // buttont9
            // 
            this->buttont9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont9->Location = System::Drawing::Point(793, 901);
            this->buttont9->Name = L"buttont9";
            this->buttont9->Size = System::Drawing::Size(138, 55);
            this->buttont9->TabIndex = 244;
            this->buttont9->Text = L"free";
            this->buttont9->UseVisualStyleBackColor = false;
            // 
            // buttont8
            // 
            this->buttont8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont8->Location = System::Drawing::Point(634, 901);
            this->buttont8->Name = L"buttont8";
            this->buttont8->Size = System::Drawing::Size(138, 55);
            this->buttont8->TabIndex = 243;
            this->buttont8->Text = L"free";
            this->buttont8->UseVisualStyleBackColor = false;
            // 
            // buttont7
            // 
            this->buttont7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont7->Location = System::Drawing::Point(479, 901);
            this->buttont7->Name = L"buttont7";
            this->buttont7->Size = System::Drawing::Size(138, 55);
            this->buttont7->TabIndex = 242;
            this->buttont7->Text = L"free";
            this->buttont7->UseVisualStyleBackColor = false;
            // 
            // buttont6
            // 
            this->buttont6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont6->Location = System::Drawing::Point(1260, 841);
            this->buttont6->Name = L"buttont6";
            this->buttont6->Size = System::Drawing::Size(138, 55);
            this->buttont6->TabIndex = 241;
            this->buttont6->Text = L"free";
            this->buttont6->UseVisualStyleBackColor = false;
            // 
            // buttont5
            // 
            this->buttont5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont5->Location = System::Drawing::Point(1105, 841);
            this->buttont5->Name = L"buttont5";
            this->buttont5->Size = System::Drawing::Size(138, 55);
            this->buttont5->TabIndex = 240;
            this->buttont5->Text = L"free";
            this->buttont5->UseVisualStyleBackColor = false;
            // 
            // buttont4
            // 
            this->buttont4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont4->Location = System::Drawing::Point(946, 841);
            this->buttont4->Name = L"buttont4";
            this->buttont4->Size = System::Drawing::Size(138, 55);
            this->buttont4->TabIndex = 239;
            this->buttont4->Text = L"free";
            this->buttont4->UseVisualStyleBackColor = false;
            // 
            // buttont3
            // 
            this->buttont3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont3->Location = System::Drawing::Point(793, 841);
            this->buttont3->Name = L"buttont3";
            this->buttont3->Size = System::Drawing::Size(138, 55);
            this->buttont3->TabIndex = 238;
            this->buttont3->Text = L"free";
            this->buttont3->UseVisualStyleBackColor = false;
            // 
            // buttont2
            // 
            this->buttont2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont2->Location = System::Drawing::Point(634, 841);
            this->buttont2->Name = L"buttont2";
            this->buttont2->Size = System::Drawing::Size(138, 55);
            this->buttont2->TabIndex = 237;
            this->buttont2->Text = L"free";
            this->buttont2->UseVisualStyleBackColor = false;
            // 
            // buttont1
            // 
            this->buttont1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont1->Location = System::Drawing::Point(479, 841);
            this->buttont1->Name = L"buttont1";
            this->buttont1->Size = System::Drawing::Size(138, 55);
            this->buttont1->TabIndex = 236;
            this->buttont1->Text = L"free";
            this->buttont1->UseVisualStyleBackColor = false;
            // 
            // label62
            // 
            this->label62->AutoSize = true;
            this->label62->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label62->Location = System::Drawing::Point(334, 694);
            this->label62->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label62->Name = L"label62";
            this->label62->Size = System::Drawing::Size(161, 28);
            this->label62->TabIndex = 235;
            this->label62->Text = L"Teacher Schedule";
            // 
            // editteacherdepartment
            // 
            this->editteacherdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacherdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdepartment->FormattingEnabled = true;
            this->editteacherdepartment->Location = System::Drawing::Point(338, 597);
            this->editteacherdepartment->Name = L"editteacherdepartment";
            this->editteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->editteacherdepartment->TabIndex = 234;
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label63->Location = System::Drawing::Point(339, 552);
            this->label63->Name = L"label63";
            this->label63->Size = System::Drawing::Size(198, 28);
            this->label63->TabIndex = 233;
            this->label63->Text = L"Enter the department";
            // 
            // editteachername
            // 
            this->editteachername->AcceptsTab = true;
            this->editteachername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteachername->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editteachername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteachername->ForeColor = System::Drawing::Color::Black;
            this->editteachername->Location = System::Drawing::Point(338, 471);
            this->editteachername->Name = L"editteachername";
            this->editteachername->Size = System::Drawing::Size(361, 27);
            this->editteachername->TabIndex = 232;
            // 
            // button55
            // 
            this->button55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button55->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button55->Location = System::Drawing::Point(1277, 1275);
            this->button55->Name = L"button55";
            this->button55->Size = System::Drawing::Size(121, 45);
            this->button55->TabIndex = 273;
            this->button55->Text = L"Save";
            this->button55->UseVisualStyleBackColor = false;
            // 
            // buttont30
            // 
            this->buttont30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont30->Location = System::Drawing::Point(1260, 1085);
            this->buttont30->Name = L"buttont30";
            this->buttont30->Size = System::Drawing::Size(138, 55);
            this->buttont30->TabIndex = 265;
            this->buttont30->Text = L"free";
            this->buttont30->UseVisualStyleBackColor = false;
            // 
            // buttont36
            // 
            this->buttont36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttont36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttont36->Location = System::Drawing::Point(1260, 1146);
            this->buttont36->Name = L"buttont36";
            this->buttont36->Size = System::Drawing::Size(138, 54);
            this->buttont36->TabIndex = 271;
            this->buttont36->Text = L"free";
            this->buttont36->UseVisualStyleBackColor = false;
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label64->Location = System::Drawing::Point(334, 425);
            this->label64->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(179, 28);
            this->label64->TabIndex = 231;
            this->label64->Text = L"Enter teacher name";
            // 
            // label65
            // 
            this->label65->AutoSize = true;
            this->label65->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label65->Location = System::Drawing::Point(1113, 779);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(94, 28);
            this->label65->TabIndex = 283;
            this->label65->Text = L"2:30-3:30";
            // 
            // teachersearch
            // 
            this->teachersearch->Location = System::Drawing::Point(658, 285);
            this->teachersearch->Multiline = false;
            this->teachersearch->Name = L"teachersearch";
            this->teachersearch->Size = System::Drawing::Size(361, 30);
            this->teachersearch->TabIndex = 1;
            this->teachersearch->Text = L"";
            // 
            // label39
            // 
            this->label39->AutoSize = true;
            this->label39->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label39->Location = System::Drawing::Point(723, 224);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(242, 30);
            this->label39->TabIndex = 0;
            this->label39->Text = L"Enter the teacher Name";
            // 
            // button18
            // 
            this->button18->Location = System::Drawing::Point(1024, 285);
            this->button18->Name = L"button18";
            this->button18->Size = System::Drawing::Size(72, 30);
            this->button18->TabIndex = 287;
            this->button18->Text = L"search";
            this->button18->UseVisualStyleBackColor = true;
            this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click_1);
            // 
            // pictureBox13
            // 
            this->pictureBox13->BackColor = System::Drawing::Color::White;
            this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
            this->pictureBox13->Location = System::Drawing::Point(683, 286);
            this->pictureBox13->Name = L"pictureBox13";
            this->pictureBox13->Size = System::Drawing::Size(35, 25);
            this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox13->TabIndex = 288;
            this->pictureBox13->TabStop = false;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(1946, 1106);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->editteacherpanel);
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->addteacherpanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->Homepanel);
            this->Controls->Add(this->panel5);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->KeyPreview = true;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MyForm";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sldataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bfactorupdown))->EndInit();
            this->panel11->ResumeLayout(false);
            this->panel11->PerformLayout();
            this->addsubjectpanel->ResumeLayout(false);
            this->addsubjectpanel->PerformLayout();
            this->panel12->ResumeLayout(false);
            this->panel12->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->addclassroompanel->ResumeLayout(false);
            this->addclassroompanel->PerformLayout();
            this->addteacherpanel->ResumeLayout(false);
            this->addteacherpanel->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            this->editteacherpanel->ResumeLayout(false);
            this->editteacherpanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
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
    Homepanel->BringToFront();
    panel1->BringToFront();
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
    
     //  pictureBox12->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
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
    panel3->Height = button6->Height;
    panel3->Top = button6->Top;
    addclassroompanel->BringToFront();
    DisplayCSVInComboBox1("details/dept_file.csv", comboBox2);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button6->Height;
    panel3->Top = button6->Top;
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = Homebutton1->Height;
    panel3->Top = Homebutton1->Top;
    Homepanel->BringToFront();
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
    panel3->Height = button9->Height;
    panel3->Top = button9->Top;
    addteacherpanel->BringToFront();
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
        Button^ button = dynamic_cast<Button^>(addteacherpanel->Controls[String::Format("buttons{0}", tagValue)]);
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
    panel3->Height = button12->Height;
    panel3->Top = button12->Top;
    addsubjectpanel->BringToFront();
    const std::string filePath = "details/classroom.csv";
    DisplayCSVInListBox(filePath, checkedListBox2);
    const std::string fileName = "details/teacher_file.csv";
    TeacherName->DataSource = CreateDataTableFromCSV1(fileName);
    TeacherName->DisplayMember = "TeacherName"; // Update to the correct column name
    TeacherName->ValueMember = "TeacherName";
    Teacher_Name->DataSource = CreateDataTableFromCSV2(fileName);
    Teacher_Name->DisplayMember = "Teacher_Name"; // Update to the correct column name
    Teacher_Name->ValueMember = "Teacher_Name";
   // addsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_Paint);
}
private: System::Void addsubsave_Click(System::Object^ sender, System::EventArgs^ e) {
    bool  flag = true;
    if(String::IsNullOrEmpty(textBox16->Text))
    {
        MessageBox::Show("Subject Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if ((!radioButton10->Checked) && (!radioButton9->Checked))
    {
        MessageBox::Show("Select whether it is a elective or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
     if(radioButton10->Checked)
    {
        if (String::IsNullOrEmpty(textBox15->Text))
        {
            MessageBox::Show("Elective name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (sedataGridView->RowCount==1)
        {if(sedataGridView->Rows[1]->Cells[0]->Value==nullptr)
            MessageBox::Show("Elective teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
    }
     if ((!radioButton8->Checked) && (!radioButton7->Checked))
     {
         MessageBox::Show("Select whether it is a lab or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
         flag = false;
     }
     if (radioButton8->Checked)
     {
         if (sldataGridView->RowCount == 1)
         {
             if (sldataGridView->Rows[1]->Cells[0]->Value == nullptr)
                 MessageBox::Show("Lab teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
             flag = false;
         }
     }
     if (bfactorupdown->Value <= 1)
     {
         MessageBox::Show("Invalid bfactor Value", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
         flag = false;
     }
 if(flag)
{
    String^ filePath = "details/subject_file.csv";
    subcsvgen(filePath);
}
}
private: System::Void sldataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn4, sldataGridView, sender, e);
}
private: System::Void newaddsub_Click(System::Object^ sender, System::EventArgs^ e) {
    textBox16->Clear();
    textBox15->Clear();
    radioButton10->Checked = false;
    radioButton9->Checked = false;
    radioButton8->Checked = false;
    radioButton7->Checked = false;
    sldataGridView->Rows->Clear();
    sedataGridView->Rows->Clear();
    numericUpDown5->Value = 0;
    bfactorupdown->Value = 0;
    for (int i = 0; i < checkedListBox2->Items->Count; i++) {
        checkedListBox2->SetItemChecked(i, false);
    }
}
private: System::Void sedataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn5, sedataGridView, sender, e);
}
private: System::Void radioButton9_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton9->Checked)
    {
        textBox15->ReadOnly = true;
        textBox15->Clear();
        textBox15->Cursor = Cursors::No;
        sedataGridView->Rows->Clear();
        sedataGridView->Cursor = Cursors::No;
        sedataGridView->ReadOnly = true;
    }
}
private: System::Void radioButton10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton10->Checked)
    {
        textBox15->ReadOnly = false;
        textBox15->Clear();
        sedataGridView->Cursor = Cursors::Arrow;
        sedataGridView->ReadOnly = false;
        textBox15->Cursor = Cursors::Arrow;
    }
}
private: System::Void radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    sldataGridView->Rows->Clear();
    sldataGridView->Cursor = Cursors::No;
    sldataGridView->ReadOnly = true;;
}
private: System::Void radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    sldataGridView->Cursor = Cursors::Arrow;
    sldataGridView->ReadOnly = false;
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
    panel5->BringToFront();
    DisplayCSVInComboBox1("details/dept_file.csv", comboBox3);
    DisplayCSVInListBox("details/dept_file.csv", checkedListBox1);
    displayelectives("details/subject_file.csv");
    displaylabs("details/subject_file.csv");
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button12->Height;
    panel3->Top = button12->Top;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button9->Height;
    panel3->Top = button9->Top;
}
private: System::Void dataGridView6_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn6,dataGridView6 , sender, e);
}
private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn3, dataGridView3, sender, e);
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn2, dataGridView1, sender, e);
}
private: System::Void textBox15_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addsubjectpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button20_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {}
   /*section obj;
    obj.name=10;
    
    for (int i = 0; i < dataGridView6->RowCount; ++i)
    {
        if (dataGridView6->Rows[i]->Cells[1]->Value != nullptr)
        {
            string file = "";
            string filePath = "details/teacher_file.csv";
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data)
            {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ teach = msclr::interop::marshal_as<String^>(row[1]);
                    String^ s = dataGridView6->Rows[i]->Cells[1]->Value->ToString();
                    if (s == teach)
                    {
                        for (int i = 0; i < row.size() - 1; i++)
                            file += row[i] + ",";
                        file += row[row.size() - 1];
                    }
                }
            }
            teacher temp;
            temp.readData(file);
            obj.allTeachers.push_back(temp);
        }
    }
    for (int i = 0; i < dataGridView3->RowCount; ++i)
    {
        if (dataGridView3->Rows[i]->Cells[1]->Value != nullptr)
        {
            string file = "";
            string filePath = "details/classroom.csv";
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data)
            {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ teach = msclr::interop::marshal_as<String^>(row[0]);
                    String^ s = dataGridView3->Rows[i]->Cells[1]->Value->ToString();
                    if (s == teach)
                    {
                        for (int i = 0; i < row.size() - 1; i++)
                            file += row[i] + ",";
                        file += row[row.size() - 1];
                    }
                }
            }
            room temp;
            temp.readData(file);
            obj.allRooms.push_back(temp);
        }
    }
    //labcreate("details/Labo.csv", obj);
}
*/

private: System::Void textBox16_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
}
private: System::Void textBox11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button9->Height;
    panel3->Top = button9->Top;
    editteacherpanel->BringToFront();
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel5_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void editteacherpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button18_Click_1(System::Object^ sender, System::EventArgs^ e) {
    editteachercsv("details/teacher_file.csv");
}
};
}
