#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<cctype>
#include "section.h"
namespace TTA_ui {
    using namespace std;
    using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace Drawing2D;

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
			//
		}
        void textBox_KeyDown(Object^ sender, KeyEventArgs^ e)
        {
            // Check if the Enter key was pressed
            if (e->KeyCode == Keys::Enter)
            {
                // Perform the desired action (e.g., process the input)
                ComboBox^ textBox = dynamic_cast<ComboBox^>(sender);
                if (textBox != nullptr)
                {
                    string find = msclr::interop::marshal_as<string>(teachersearch->Text);

                    vector<vector<string>>data = ReadCSVFile("details/teacher_file.csv");
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
                            textBox1->Text = msclr::interop::marshal_as<String^>(str);
                            if (find == str)
                            {
                                editteachername->Text = msclr::interop::marshal_as<String^>(row[0]);
                                editteacherdepartment->Text = msclr::interop::marshal_as<String^>(row[1]);

                                for (int i = 2; i < row.size(); i += 2)
                                {
                                    int x = i / 2;
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
                    {	String^ name = addteachername->Text->ToString();
                    string Name = msclr::interop::marshal_as<string>(name);
                    string teachername = replacewhitespace(Name);
                    outputFile << teachername << ",";
                    String^ dep = addteacherdepartment->Text->ToString();
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

        void classroomcsvcreate(const string filePath)
        {
            try
            {
                ofstream outputFile;
                outputFile.open(filePath,ios::app);
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
                    outputFile << "2,";
                }
                else
                {
                    outputFile << "1,";
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

        System::Data::DataTable^ CreateDataTableFromCSV3(const std::string filePath) {
            System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
            dataTable->Columns->Add("csubject");
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data) {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ csubject = msclr::interop::marshal_as<String^>(row[0]);
                    dataTable->Rows->Add(csubject);
                }
            }
            return dataTable;
        }

        System::Data::DataTable^ CreateDataTableFromCSV4(const std::string filePath) {
            System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
            dataTable->Columns->Add("cteacher");
            vector<vector<string>> data = ReadCSVFile(filePath);
            for (const auto& row : data) {
                if (!row.empty()) {
                    // Display only the first word before the comma
                    String^ cteacher = msclr::interop::marshal_as<String^>(row[0]);
                    dataTable->Rows->Add(cteacher);
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
          
          private: System::Void button1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e) {
              Button^ button = dynamic_cast<Button^>(sender);
              // Define the rounded rectangle
              Drawing::Rectangle rect = Drawing::Rectangle(0, 0, button->Width - 1, button->Height - 1);
              Drawing::Drawing2D::GraphicsPath^ path = gcnew Drawing::Drawing2D::GraphicsPath();
              int radius = 20; // You can adjust the radius to control the roundness of the button

              // Add arcs to the path to create rounded corners
              path->AddArc(rect.X, rect.Y, radius, radius, 180, 90);
              path->AddArc(rect.Right - radius, rect.Y, radius, radius, 270, 90);
              path->AddArc(rect.Right - radius, rect.Bottom - radius, radius, radius, 0, 90);
              path->AddArc(rect.X, rect.Bottom - radius, radius, radius, 90, 90);
              path->CloseFigure();

              // Fill the rounded rectangle with the button's background color
              e->Graphics->FillPath(gcnew SolidBrush(button->BackColor), path);

              // Draw the button's text
              e->Graphics->DrawString(button->Text, button->Font, Brushes::Black,
                  (button->Width - e->Graphics->MeasureString(button->Text, button->Font).Width) / 2,
                  (button->Height - e->Graphics->MeasureString(button->Text, button->Font).Height) / 2);
          }

public:
   void labcreate(const string filename, section& t)
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
    }

   void editteachercsvshow(const string filename)
    {
        string find = msclr::interop::marshal_as<string>(teachersearch->Text);

        vector<vector<string>>data = ReadCSVFile(filename);
        {
            for ( auto& row : data)
            {
                string str;
                for (char& c : find) {
                    c = std::toupper(static_cast<unsigned char>(c)); // Cast char to unsigned char before calling toupper
                }
                for (char& c : row[0]) {
                     str += std::toupper(static_cast<unsigned char>(c)); // Cast char to unsigned char before calling toupper
                }
                textBox1->Text = msclr::interop::marshal_as<String^>(str);
                if (find ==str)
                {
                    editteachername->Text = msclr::interop::marshal_as<String^>(row[0]);
                    editteacherdepartment->Text = msclr::interop::marshal_as<String^>(row[1]);

                    for (int i = 2; i < row.size(); i += 2)
                    {
                        int x = i / 2;
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
    }

   void editteachercsvsave(const string filename)

   {
       try
       {
           string find = msclr::interop::marshal_as<string>(teachersearch->Text);

           vector<vector<string>>data = ReadCSVFile(filename);
           ofstream file(filename);
           {
               for (const auto& row : data)
               {
                   if (find == row[0])
                   {
                       file << msclr::interop::marshal_as<string>(editteachername->Text->ToString());
                       file << ",";
                       file << msclr::interop::marshal_as<string>(editteacherdepartment->Text->ToString());
                       file << ",";
                       for (int i = 1; i < 37; i++)
                       {

                           String^ tagValue = i.ToString();
                           Button^ button = dynamic_cast<Button^>(editteacherpanel->Controls[String::Format("buttont{0}", tagValue)]);
       
                           if (button != nullptr)
                           {
                               if (button->Text == "busy")
                               {
                                   file << "1,0";
                               }
                               else if (button->Text == "free")
                               {
                                   file << "0,0";
                               }
                               if (i != 36)
                               {
                                   file << ",";
                               }
                           }
                       }file << "\n";

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
           MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
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
           string find = msclr::interop::marshal_as<string>(teachersearch->Text);

           vector<vector<string>>data = ReadCSVFile(filename);
           ofstream file(filename);
           {
               for (const auto& row : data)
               {
                   if (find == row[0])
                   {
                   
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
           MessageBox::Show("Deleted successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
       }
       catch (...)
       {
           MessageBox::Show("Error deleting data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
       }
   }

   void editroomcsvshow(const string filename)
   {
       string find = msclr::interop::marshal_as<string>(editroomsearch->Text);

       vector<vector<string>>data = ReadCSVFile(filename);
       for ( auto& row : data)
       {
           string str;
           for (char& r : find)
           {
               r = toupper(static_cast<unsigned char>(r));
           }
           for (char& r :row[0])
           {
               str+= toupper(static_cast<unsigned char>(r));
           }
           if (find == str) {
               editroomname->Text = msclr::interop::marshal_as<String^>(row[0]);
               editroomcapacity->Text = msclr::interop::marshal_as<String^>(row[1]);
               if (row[2] == "0")
               {
                   editroomlabno->Checked;
               }
               else
               {
                   editroomlabyes->Checked;
               }
               editroomdepartment->Text = msclr::interop::marshal_as<String^>(row[3]);

               for (int i = 4; i < row.size(); i += 2)
               {
                   int x = (i / 2) - 1;
                   String^ tagValue = x.ToString();
                   Button^ button = dynamic_cast<Button^>(editroompanel->Controls[String::Format("buttonr{0}", tagValue)]);
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

   void editroomcsvsave(const string filename)
   {
       try {
           string find = msclr::interop::marshal_as<string>(editroomsearch->Text);

           vector<vector<string>>data = ReadCSVFile(filename);
           ofstream file(filename);
           {
               for (const auto& row : data)
               {
                   if (find == row[0]) {
                       file << msclr::interop::marshal_as<string>(editroomname->Text) << ",";
                       file << msclr::interop::marshal_as<string>(editroomcapacity->Text) << ",";
                       if (editroomlabyes->Checked)
                       {
                           file << "1,";
                       }
                       else
                       {
                           file << "0,";
                       }
                       file << msclr::interop::marshal_as<string>(editroomdepartment->Text) << ",";

                       for (int i = 1; i < 37; i++)
                       {
                           String^ tagValue = i.ToString();
                           Button^ button = dynamic_cast<Button^>(editroompanel->Controls[String::Format("buttonr{0}", tagValue)]);
                           if (button != nullptr)
                           {
                               if (button->Text == "free")
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
                           }
                       }

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
           MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
       }
       catch (...)
       {
           MessageBox::Show("Error displaying data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
       }
   }

   void editroomcsvdelete(const string filename)
   {
       string find = msclr::interop::marshal_as<string>(editroomsearch->Text);

       vector<vector<string>>data = ReadCSVFile(filename);
       ofstream file(filename);
       {
           for (const auto& row : data)
           {
               if (find == row[0]) {
                 
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
       }
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
       }
   }

   void loadcore(section &obj)
   {
       for (int i = 0; i < dataGridView6->RowCount; ++i)
       {
           if (dataGridView6->Rows[i]->Cells[1]->Value != nullptr)
           {
               subject sub;
               sub.readData(returnLine(msclr::interop::marshal_as<string>(dataGridView6->Rows[i]->Cells[0]->Value->ToString()), "details/subject_file.csv"));
               obj.addCore(msclr::interop::marshal_as<string>(dataGridView6->Rows[i]->Cells[1]->Value->ToString()), sub);
           }
       }
   }

   void defaultroomallot(section& obj)
   {
       vector<string>drooms;
       for each (int checkedIndex in checkedListBox1->CheckedIndices)
       {
           String^ itemRoom = checkedListBox1->Items[checkedIndex]->ToString();
           string ItemRoom = msclr::interop::marshal_as<string>(itemRoom);
           vector < vector<string>>data = ReadCSVFile("details/classroom.csv");

           for (const auto& row : data)
           {
               if (!row.empty())
               {
                   if (ItemRoom == row[3])
                   {
                       drooms.push_back(row[0]);
                   }
               }
           }
       }
       obj.defaultRooms = drooms;
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
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Panel^ editteacherpanel;
private: System::Windows::Forms::Label^ label39;
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
private: System::Windows::Forms::Button^ editteachersave;


private: System::Windows::Forms::Button^ buttont30;
private: System::Windows::Forms::Button^ buttont36;


private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ button18;

private: System::Windows::Forms::Button^ editteacherdelete;
private: System::Windows::Forms::Panel^ editroompanel;
private: System::Windows::Forms::RadioButton^ editroomlabno;


private: System::Windows::Forms::RadioButton^ editroomlabyes;
private: System::Windows::Forms::Button^ editroomdelete;


private: System::Windows::Forms::Label^ label66;
private: System::Windows::Forms::Label^ label67;
private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::Label^ label69;
private: System::Windows::Forms::Label^ label70;
private: System::Windows::Forms::Label^ label71;
private: System::Windows::Forms::Label^ label72;
private: System::Windows::Forms::Label^ label73;
private: System::Windows::Forms::Label^ label74;
private: System::Windows::Forms::Label^ label75;
private: System::Windows::Forms::Label^ label76;
private: System::Windows::Forms::Label^ label77;
private: System::Windows::Forms::Button^ buttonr36;
private: System::Windows::Forms::Button^ buttonr35;
private: System::Windows::Forms::Button^ buttonr34;
private: System::Windows::Forms::Button^ buttonr33;
private: System::Windows::Forms::Button^ buttonr32;
private: System::Windows::Forms::Button^ buttonr31;
private: System::Windows::Forms::Button^ buttonr30;

private: System::Windows::Forms::Button^ buttonr29;

private: System::Windows::Forms::Button^ buttonr28;

private: System::Windows::Forms::Button^ buttonr27;

private: System::Windows::Forms::Button^ buttonr26;

private: System::Windows::Forms::Button^ buttonr25;

private: System::Windows::Forms::Button^ buttonr24;

private: System::Windows::Forms::Button^ buttonr23;

private: System::Windows::Forms::Button^ buttonr22;

private: System::Windows::Forms::Button^ buttonr21;

private: System::Windows::Forms::Button^ buttonr20;

private: System::Windows::Forms::Button^ buttonr19;

private: System::Windows::Forms::Button^ buttonr18;

private: System::Windows::Forms::Button^ buttonr17;

private: System::Windows::Forms::Button^ buttonr16;

private: System::Windows::Forms::Button^ buttonr15;

private: System::Windows::Forms::Button^ buttonr14;

private: System::Windows::Forms::Button^ buttonr13;

private: System::Windows::Forms::Button^ buttonr12;

private: System::Windows::Forms::Button^ buttonr11;

private: System::Windows::Forms::Button^ buttonr10;

private: System::Windows::Forms::Button^ buttonr9;

private: System::Windows::Forms::Button^ buttonr8;

private: System::Windows::Forms::Button^ buttonr7;

private: System::Windows::Forms::Button^ buttonr6;
private: System::Windows::Forms::Button^ buttonr5;
private: System::Windows::Forms::Button^ buttonr4;

private: System::Windows::Forms::Button^ buttonr3;

private: System::Windows::Forms::Button^ buttonr2;

private: System::Windows::Forms::Button^ buttonr1;

private: System::Windows::Forms::ComboBox^ editroomdepartment;

private: System::Windows::Forms::Label^ label78;
private: System::Windows::Forms::Label^ label79;
private: System::Windows::Forms::Label^ label80;
private: System::Windows::Forms::NumericUpDown^ editroomcapacity;

private: System::Windows::Forms::TextBox^ editroomname;

private: System::Windows::Forms::Label^ label81;
private: System::Windows::Forms::Button^ editroomsave;

private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::Button^ editroomsearchbutton;
private: System::Windows::Forms::RichTextBox^ editroomsearch;
private: System::Windows::Forms::Label^ label82;
private: System::Windows::Forms::Panel^ editsubjectpanel;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::Button^ editsubjectsearchbutton;
private: System::Windows::Forms::RichTextBox^ editsubjectsearch;
private: System::Windows::Forms::Label^ label108;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::RadioButton^ editsubjecteleyes;
private: System::Windows::Forms::RadioButton^ editsubjecteleno;
private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::RadioButton^ editsubjectlabyes;
private: System::Windows::Forms::RadioButton^ editsubjectlabno;


private: System::Windows::Forms::Button^ button20;
private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::CheckedListBox^ editsubjectroom;

private: System::Windows::Forms::Label^ label83;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::NumericUpDown^ editsubjectbfactor;

private: System::Windows::Forms::TextBox^ editsubjectelename;
private: System::Windows::Forms::Label^ label84;
private: System::Windows::Forms::Label^ label85;
private: System::Windows::Forms::Label^ label86;
private: System::Windows::Forms::Label^ label87;
private: System::Windows::Forms::Label^ label88;
private: System::Windows::Forms::TextBox^ editsubjectname;
private: System::Windows::Forms::NumericUpDown^ editsubjectcredit;

private: System::Windows::Forms::DataGridView^ editsubjectlabteachers;

private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn7;
private: System::Windows::Forms::Label^ label89;
private: System::Windows::Forms::Label^ label91;
private: System::Windows::Forms::Label^ label90;
private: System::Windows::Forms::DataGridView^ editsubjecteleteacher;

private: System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn2;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn9;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::Button^ button23;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::Label^ label92;
private: System::Windows::Forms::Label^ label93;
private: System::Windows::Forms::Label^ label94;
private: System::Windows::Forms::Label^ label95;
private: System::Windows::Forms::Label^ label96;
private: System::Windows::Forms::Label^ label97;
private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::Label^ label99;
private: System::Windows::Forms::Label^ label100;
private: System::Windows::Forms::Label^ label101;
private: System::Windows::Forms::Label^ label102;
private: System::Windows::Forms::Button^ button24;
private: System::Windows::Forms::Button^ button25;
private: System::Windows::Forms::Button^ button26;
private: System::Windows::Forms::Button^ button27;
private: System::Windows::Forms::Button^ button28;
private: System::Windows::Forms::Button^ button29;
private: System::Windows::Forms::Button^ button30;
private: System::Windows::Forms::Button^ button31;
private: System::Windows::Forms::Button^ button32;
private: System::Windows::Forms::Button^ button33;
private: System::Windows::Forms::Button^ button34;
private: System::Windows::Forms::Button^ button35;
private: System::Windows::Forms::Button^ button36;
private: System::Windows::Forms::Button^ button39;
private: System::Windows::Forms::Button^ button40;
private: System::Windows::Forms::Button^ button41;
private: System::Windows::Forms::Button^ button42;
private: System::Windows::Forms::Button^ button43;
private: System::Windows::Forms::Button^ button44;
private: System::Windows::Forms::Button^ button45;
private: System::Windows::Forms::Button^ button46;
private: System::Windows::Forms::Button^ button47;
private: System::Windows::Forms::Button^ button48;
private: System::Windows::Forms::Button^ button49;
private: System::Windows::Forms::Button^ button50;
private: System::Windows::Forms::Button^ button51;
private: System::Windows::Forms::Button^ button52;
private: System::Windows::Forms::Button^ button53;
private: System::Windows::Forms::Button^ button54;
private: System::Windows::Forms::Button^ button55;
private: System::Windows::Forms::Button^ button56;
private: System::Windows::Forms::Button^ button57;
private: System::Windows::Forms::Button^ button58;
private: System::Windows::Forms::Button^ button59;
private: System::Windows::Forms::Label^ label103;
private: System::Windows::Forms::ComboBox^ comboBox4;
private: System::Windows::Forms::Label^ label104;
private: System::Windows::Forms::TextBox^ textBox20;
private: System::Windows::Forms::Button^ button60;
private: System::Windows::Forms::Button^ button61;
private: System::Windows::Forms::Button^ button62;
private: System::Windows::Forms::Label^ label105;
private: System::Windows::Forms::Label^ label106;
private: System::Windows::Forms::RichTextBox^ richTextBox1;
private: System::Windows::Forms::Label^ label107;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ csubject;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ cteacher;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;
private: System::Windows::Forms::PictureBox^ pictureBox13;

private: System::Windows::Forms::Panel^ addteacherpanel;
private: System::Windows::Forms::Label^ label50;
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
private: System::Windows::Forms::ComboBox^ addteacherdepartment;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ addteachername;
private: System::Windows::Forms::Button^ addteachersave;
private: System::Windows::Forms::Button^ addteachernew;



private: System::Windows::Forms::Button^ buttons30;
private: System::Windows::Forms::Button^ buttons36;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label109;
private: System::Windows::Forms::Panel^ settingspanel;
private: System::Windows::Forms::TrackBar^ trackBar1;
private: System::Windows::Forms::Label^ label110;

private: System::Windows::Forms::Label^ label112;
private: System::Windows::Forms::TrackBar^ trackBar2;
private: System::Windows::Forms::Label^ label111;
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
private: System::Windows::Forms::Button^ Homebutton1;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::Label^ textBox4;
private: System::Windows::Forms::Label^ textBox5;
private: System::Windows::Forms::Label^ textBox10;
private: System::Windows::Forms::Label^ textBox8;
private: System::Windows::Forms::Label^ textBox6;
private: System::Windows::Forms::Label^ textBox11;
private: System::Windows::Forms::Label^ textBox9;
private: System::Windows::Forms::Label^ textBox7;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::ComboBox^ teachersearch;



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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle43 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
            this->label109 = (gcnew System::Windows::Forms::Label());
            this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
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
            this->cteacher = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->editteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->editteacherdelete = (gcnew System::Windows::Forms::Button());
            this->button18 = (gcnew System::Windows::Forms::Button());
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
            this->editteachersave = (gcnew System::Windows::Forms::Button());
            this->buttont30 = (gcnew System::Windows::Forms::Button());
            this->buttont36 = (gcnew System::Windows::Forms::Button());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->teachersearch = (gcnew System::Windows::Forms::ComboBox());
            this->editroompanel = (gcnew System::Windows::Forms::Panel());
            this->editroomsearchbutton = (gcnew System::Windows::Forms::Button());
            this->editroomsearch = (gcnew System::Windows::Forms::RichTextBox());
            this->label82 = (gcnew System::Windows::Forms::Label());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->editroomlabyes = (gcnew System::Windows::Forms::RadioButton());
            this->editroomlabno = (gcnew System::Windows::Forms::RadioButton());
            this->editroomdelete = (gcnew System::Windows::Forms::Button());
            this->label66 = (gcnew System::Windows::Forms::Label());
            this->label67 = (gcnew System::Windows::Forms::Label());
            this->label68 = (gcnew System::Windows::Forms::Label());
            this->label69 = (gcnew System::Windows::Forms::Label());
            this->label70 = (gcnew System::Windows::Forms::Label());
            this->label71 = (gcnew System::Windows::Forms::Label());
            this->label72 = (gcnew System::Windows::Forms::Label());
            this->label73 = (gcnew System::Windows::Forms::Label());
            this->label74 = (gcnew System::Windows::Forms::Label());
            this->label75 = (gcnew System::Windows::Forms::Label());
            this->label76 = (gcnew System::Windows::Forms::Label());
            this->label77 = (gcnew System::Windows::Forms::Label());
            this->buttonr36 = (gcnew System::Windows::Forms::Button());
            this->buttonr35 = (gcnew System::Windows::Forms::Button());
            this->buttonr34 = (gcnew System::Windows::Forms::Button());
            this->buttonr33 = (gcnew System::Windows::Forms::Button());
            this->buttonr32 = (gcnew System::Windows::Forms::Button());
            this->buttonr31 = (gcnew System::Windows::Forms::Button());
            this->buttonr30 = (gcnew System::Windows::Forms::Button());
            this->buttonr29 = (gcnew System::Windows::Forms::Button());
            this->buttonr28 = (gcnew System::Windows::Forms::Button());
            this->buttonr27 = (gcnew System::Windows::Forms::Button());
            this->buttonr26 = (gcnew System::Windows::Forms::Button());
            this->buttonr25 = (gcnew System::Windows::Forms::Button());
            this->buttonr24 = (gcnew System::Windows::Forms::Button());
            this->buttonr23 = (gcnew System::Windows::Forms::Button());
            this->buttonr22 = (gcnew System::Windows::Forms::Button());
            this->buttonr21 = (gcnew System::Windows::Forms::Button());
            this->buttonr20 = (gcnew System::Windows::Forms::Button());
            this->buttonr19 = (gcnew System::Windows::Forms::Button());
            this->buttonr18 = (gcnew System::Windows::Forms::Button());
            this->buttonr17 = (gcnew System::Windows::Forms::Button());
            this->buttonr16 = (gcnew System::Windows::Forms::Button());
            this->buttonr15 = (gcnew System::Windows::Forms::Button());
            this->buttonr14 = (gcnew System::Windows::Forms::Button());
            this->buttonr13 = (gcnew System::Windows::Forms::Button());
            this->buttonr12 = (gcnew System::Windows::Forms::Button());
            this->buttonr11 = (gcnew System::Windows::Forms::Button());
            this->buttonr10 = (gcnew System::Windows::Forms::Button());
            this->buttonr9 = (gcnew System::Windows::Forms::Button());
            this->buttonr8 = (gcnew System::Windows::Forms::Button());
            this->buttonr7 = (gcnew System::Windows::Forms::Button());
            this->buttonr6 = (gcnew System::Windows::Forms::Button());
            this->buttonr5 = (gcnew System::Windows::Forms::Button());
            this->buttonr4 = (gcnew System::Windows::Forms::Button());
            this->buttonr3 = (gcnew System::Windows::Forms::Button());
            this->buttonr2 = (gcnew System::Windows::Forms::Button());
            this->buttonr1 = (gcnew System::Windows::Forms::Button());
            this->editroomdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label78 = (gcnew System::Windows::Forms::Label());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->label80 = (gcnew System::Windows::Forms::Label());
            this->editroomcapacity = (gcnew System::Windows::Forms::NumericUpDown());
            this->editroomname = (gcnew System::Windows::Forms::TextBox());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->editroomsave = (gcnew System::Windows::Forms::Button());
            this->editsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->button22 = (gcnew System::Windows::Forms::Button());
            this->button23 = (gcnew System::Windows::Forms::Button());
            this->textBox19 = (gcnew System::Windows::Forms::TextBox());
            this->label92 = (gcnew System::Windows::Forms::Label());
            this->label93 = (gcnew System::Windows::Forms::Label());
            this->label94 = (gcnew System::Windows::Forms::Label());
            this->label95 = (gcnew System::Windows::Forms::Label());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->label100 = (gcnew System::Windows::Forms::Label());
            this->label101 = (gcnew System::Windows::Forms::Label());
            this->label102 = (gcnew System::Windows::Forms::Label());
            this->button24 = (gcnew System::Windows::Forms::Button());
            this->button25 = (gcnew System::Windows::Forms::Button());
            this->button26 = (gcnew System::Windows::Forms::Button());
            this->button27 = (gcnew System::Windows::Forms::Button());
            this->button28 = (gcnew System::Windows::Forms::Button());
            this->button29 = (gcnew System::Windows::Forms::Button());
            this->button30 = (gcnew System::Windows::Forms::Button());
            this->button31 = (gcnew System::Windows::Forms::Button());
            this->button32 = (gcnew System::Windows::Forms::Button());
            this->button33 = (gcnew System::Windows::Forms::Button());
            this->button34 = (gcnew System::Windows::Forms::Button());
            this->button35 = (gcnew System::Windows::Forms::Button());
            this->button36 = (gcnew System::Windows::Forms::Button());
            this->button39 = (gcnew System::Windows::Forms::Button());
            this->button40 = (gcnew System::Windows::Forms::Button());
            this->button41 = (gcnew System::Windows::Forms::Button());
            this->button42 = (gcnew System::Windows::Forms::Button());
            this->button43 = (gcnew System::Windows::Forms::Button());
            this->button44 = (gcnew System::Windows::Forms::Button());
            this->button45 = (gcnew System::Windows::Forms::Button());
            this->button46 = (gcnew System::Windows::Forms::Button());
            this->button47 = (gcnew System::Windows::Forms::Button());
            this->button48 = (gcnew System::Windows::Forms::Button());
            this->button49 = (gcnew System::Windows::Forms::Button());
            this->button50 = (gcnew System::Windows::Forms::Button());
            this->button51 = (gcnew System::Windows::Forms::Button());
            this->button52 = (gcnew System::Windows::Forms::Button());
            this->button53 = (gcnew System::Windows::Forms::Button());
            this->button54 = (gcnew System::Windows::Forms::Button());
            this->button55 = (gcnew System::Windows::Forms::Button());
            this->button56 = (gcnew System::Windows::Forms::Button());
            this->button57 = (gcnew System::Windows::Forms::Button());
            this->button58 = (gcnew System::Windows::Forms::Button());
            this->button59 = (gcnew System::Windows::Forms::Button());
            this->label103 = (gcnew System::Windows::Forms::Label());
            this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
            this->label104 = (gcnew System::Windows::Forms::Label());
            this->textBox20 = (gcnew System::Windows::Forms::TextBox());
            this->button60 = (gcnew System::Windows::Forms::Button());
            this->button61 = (gcnew System::Windows::Forms::Button());
            this->button62 = (gcnew System::Windows::Forms::Button());
            this->label105 = (gcnew System::Windows::Forms::Label());
            this->label106 = (gcnew System::Windows::Forms::Label());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->label107 = (gcnew System::Windows::Forms::Label());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->editsubjectsearchbutton = (gcnew System::Windows::Forms::Button());
            this->editsubjectsearch = (gcnew System::Windows::Forms::RichTextBox());
            this->label108 = (gcnew System::Windows::Forms::Label());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->editsubjecteleyes = (gcnew System::Windows::Forms::RadioButton());
            this->editsubjecteleno = (gcnew System::Windows::Forms::RadioButton());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->editsubjectlabyes = (gcnew System::Windows::Forms::RadioButton());
            this->editsubjectlabno = (gcnew System::Windows::Forms::RadioButton());
            this->button20 = (gcnew System::Windows::Forms::Button());
            this->textBox18 = (gcnew System::Windows::Forms::TextBox());
            this->editsubjectroom = (gcnew System::Windows::Forms::CheckedListBox());
            this->label83 = (gcnew System::Windows::Forms::Label());
            this->button21 = (gcnew System::Windows::Forms::Button());
            this->editsubjectbfactor = (gcnew System::Windows::Forms::NumericUpDown());
            this->editsubjectelename = (gcnew System::Windows::Forms::TextBox());
            this->label84 = (gcnew System::Windows::Forms::Label());
            this->label85 = (gcnew System::Windows::Forms::Label());
            this->label86 = (gcnew System::Windows::Forms::Label());
            this->label87 = (gcnew System::Windows::Forms::Label());
            this->label88 = (gcnew System::Windows::Forms::Label());
            this->editsubjectname = (gcnew System::Windows::Forms::TextBox());
            this->editsubjectcredit = (gcnew System::Windows::Forms::NumericUpDown());
            this->editsubjectlabteachers = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn7 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label89 = (gcnew System::Windows::Forms::Label());
            this->label91 = (gcnew System::Windows::Forms::Label());
            this->label90 = (gcnew System::Windows::Forms::Label());
            this->editsubjecteleteacher = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewComboBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn9 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->addteacherpanel = (gcnew System::Windows::Forms::Panel());
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
            this->addteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->addteachername = (gcnew System::Windows::Forms::TextBox());
            this->addteachersave = (gcnew System::Windows::Forms::Button());
            this->addteachernew = (gcnew System::Windows::Forms::Button());
            this->buttons30 = (gcnew System::Windows::Forms::Button());
            this->buttons36 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->settingspanel = (gcnew System::Windows::Forms::Panel());
            this->label112 = (gcnew System::Windows::Forms::Label());
            this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
            this->label111 = (gcnew System::Windows::Forms::Label());
            this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
            this->label110 = (gcnew System::Windows::Forms::Label());
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
            this->Homebutton1 = (gcnew System::Windows::Forms::Button());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->textBox4 = (gcnew System::Windows::Forms::Label());
            this->textBox5 = (gcnew System::Windows::Forms::Label());
            this->textBox10 = (gcnew System::Windows::Forms::Label());
            this->textBox8 = (gcnew System::Windows::Forms::Label());
            this->textBox6 = (gcnew System::Windows::Forms::Label());
            this->textBox11 = (gcnew System::Windows::Forms::Label());
            this->textBox9 = (gcnew System::Windows::Forms::Label());
            this->textBox7 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
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
            this->panel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
            this->panel5->SuspendLayout();
            this->editteacherpanel->SuspendLayout();
            this->editroompanel->SuspendLayout();
            this->panel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->BeginInit();
            this->editsubjectpanel->SuspendLayout();
            this->panel10->SuspendLayout();
            this->panel9->SuspendLayout();
            this->panel7->SuspendLayout();
            this->panel8->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectbfactor))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectcredit))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectlabteachers))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjecteleteacher))->BeginInit();
            this->addteacherpanel->SuspendLayout();
            this->settingspanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            this->panel1->SuspendLayout();
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
            this->sldataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::sedataGridView_CellContentClick);
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
            this->sedataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::sedataGridView_CellContentClick);
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
            dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle15;
            this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle16;
            this->dataGridView2->ColumnHeadersHeight = 40;
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewButtonColumn1
            });
            dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle19->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle19->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle19->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle19->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle19;
            this->dataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView2->Location = System::Drawing::Point(372, 348);
            this->dataGridView2->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView2->Name = L"dataGridView2";
            dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
            this->dataGridView2->RowHeadersVisible = false;
            this->dataGridView2->RowHeadersWidth = 62;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView2->RowsDefaultCellStyle = dataGridViewCellStyle21;
            this->dataGridView2->RowTemplate->Height = 28;
            this->dataGridView2->Size = System::Drawing::Size(735, 300);
            this->dataGridView2->TabIndex = 233;
            this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick_1);
            // 
            // dataGridViewTextBoxColumn1
            // 
            dataGridViewCellStyle17->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle17->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle17;
            this->dataGridViewTextBoxColumn1->HeaderText = L"Department";
            this->dataGridViewTextBoxColumn1->MinimumWidth = 30;
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle18;
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
            this->textBox12->Location = System::Drawing::Point(643, 271);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(304, 32);
            this->textBox12->TabIndex = 4;
            this->textBox12->Text = L"Department List";
            // 
            // pictureBox1
            // 
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
            this->pictureBox9->Location = System::Drawing::Point(1689, 54);
            this->pictureBox9->Name = L"pictureBox9";
            this->pictureBox9->Size = System::Drawing::Size(39, 41);
            this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox9->TabIndex = 2;
            this->pictureBox9->TabStop = false;
            this->pictureBox9->Click += gcnew System::EventHandler(this, &MyForm::pictureBox9_Click);
            this->pictureBox9->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox9_MouseEnter);
            this->pictureBox9->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox9_MouseLeave);
            // 
            // pictureBox10
            // 
            this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
            this->pictureBox10->Location = System::Drawing::Point(1846, 54);
            this->pictureBox10->Name = L"pictureBox10";
            this->pictureBox10->Size = System::Drawing::Size(39, 41);
            this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox10->TabIndex = 3;
            this->pictureBox10->TabStop = false;
            this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
            this->pictureBox10->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox10_MouseEnter);
            this->pictureBox10->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox10_MouseLeave);
            // 
            // pictureBox11
            // 
            this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
            this->pictureBox11->Location = System::Drawing::Point(1609, 53);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(39, 41);
            this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox11->TabIndex = 4;
            this->pictureBox11->TabStop = false;
            this->pictureBox11->Click += gcnew System::EventHandler(this, &MyForm::pictureBox11_Click);
            this->pictureBox11->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox11_MouseEnter);
            this->pictureBox11->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox11_MouseLeave);
            // 
            // pictureBox12
            // 
            this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
            this->pictureBox12->InitialImage = nullptr;
            this->pictureBox12->Location = System::Drawing::Point(43, 12);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(143, 116);
            this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox12->TabIndex = 5;
            this->pictureBox12->TabStop = false;
            this->pictureBox12->Click += gcnew System::EventHandler(this, &MyForm::pictureBox12_Click);
            this->pictureBox12->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox12_MouseEnter);
            this->pictureBox12->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox12_MouseLeave);
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::White;
            this->panel4->Controls->Add(this->label109);
            this->panel4->Controls->Add(this->pictureBox13);
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
            // label109
            // 
            this->label109->AutoSize = true;
            this->label109->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label109->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->label109->Location = System::Drawing::Point(229, 41);
            this->label109->Name = L"label109";
            this->label109->Size = System::Drawing::Size(121, 32);
            this->label109->TabIndex = 8;
            this->label109->Text = L"Username";
            // 
            // pictureBox13
            // 
            this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
            this->pictureBox13->Location = System::Drawing::Point(1768, 54);
            this->pictureBox13->Name = L"pictureBox13";
            this->pictureBox13->Size = System::Drawing::Size(39, 41);
            this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox13->TabIndex = 7;
            this->pictureBox13->TabStop = false;
            this->pictureBox13->Click += gcnew System::EventHandler(this, &MyForm::pictureBox13_Click);
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
            dataGridViewCellStyle22->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle22;
            this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle23->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle23->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle23;
            this->dataGridView3->ColumnHeadersHeight = 40;
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->eSubject,
                    this->dataGridViewButtonColumn3
            });
            dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle26->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle26->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle26->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle26->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView3->DefaultCellStyle = dataGridViewCellStyle26;
            this->dataGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->Location = System::Drawing::Point(335, 939);
            this->dataGridView3->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView3->Name = L"dataGridView3";
            dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle27->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle27->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->RowHeadersDefaultCellStyle = dataGridViewCellStyle27;
            this->dataGridView3->RowHeadersVisible = false;
            this->dataGridView3->RowHeadersWidth = 62;
            dataGridViewCellStyle28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle28->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->RowsDefaultCellStyle = dataGridViewCellStyle28;
            this->dataGridView3->RowTemplate->Height = 28;
            this->dataGridView3->Size = System::Drawing::Size(735, 226);
            this->dataGridView3->TabIndex = 253;
            this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
            // 
            // eSubject
            // 
            dataGridViewCellStyle24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle24->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle24->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->DefaultCellStyle = dataGridViewCellStyle24;
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
            dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle25;
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
            dataGridViewCellStyle29->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle29;
            this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle30->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle30;
            this->dataGridView1->ColumnHeadersHeight = 40;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->lsubject,
                    this->dataGridViewButtonColumn2
            });
            dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle33->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle33->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle33->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle33->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle33->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle33;
            this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->Location = System::Drawing::Point(335, 1278);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle34->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle34->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle34->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle34;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 62;
            dataGridViewCellStyle35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle35->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle35->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle35->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle35;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(735, 211);
            this->dataGridView1->TabIndex = 254;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            // 
            // lsubject
            // 
            dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle31->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->lsubject->DefaultCellStyle = dataGridViewCellStyle31;
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
            dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle32;
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
            dataGridViewCellStyle36->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle36->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle36->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle36->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle36;
            this->dataGridView6->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView6->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView6->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle37->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle37->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle37->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle37;
            this->dataGridView6->ColumnHeadersHeight = 40;
            this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->csubject,
                    this->cteacher, this->dataGridViewButtonColumn6
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
            this->dataGridView6->DefaultCellStyle = dataGridViewCellStyle41;
            this->dataGridView6->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->Location = System::Drawing::Point(338, 642);
            this->dataGridView6->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView6->Name = L"dataGridView6";
            dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle42->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle42->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle42->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle42->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle42->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->RowHeadersDefaultCellStyle = dataGridViewCellStyle42;
            this->dataGridView6->RowHeadersVisible = false;
            this->dataGridView6->RowHeadersWidth = 62;
            dataGridViewCellStyle43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle43->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle43->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle43->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->RowsDefaultCellStyle = dataGridViewCellStyle43;
            this->dataGridView6->RowTemplate->Height = 28;
            this->dataGridView6->Size = System::Drawing::Size(735, 207);
            this->dataGridView6->TabIndex = 257;
            this->dataGridView6->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView6_CellContentClick);
            // 
            // csubject
            // 
            dataGridViewCellStyle38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle38->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle38->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle38->SelectionForeColor = System::Drawing::Color::Black;
            this->csubject->DefaultCellStyle = dataGridViewCellStyle38;
            this->csubject->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->csubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->csubject->HeaderText = L"csubject";
            this->csubject->MinimumWidth = 8;
            this->csubject->Name = L"csubject";
            this->csubject->Width = 150;
            // 
            // cteacher
            // 
            dataGridViewCellStyle39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle39->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle39->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle39->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle39->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle39->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->cteacher->DefaultCellStyle = dataGridViewCellStyle39;
            this->cteacher->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cteacher->HeaderText = L"cteacher";
            this->cteacher->MinimumWidth = 30;
            this->cteacher->Name = L"cteacher";
            this->cteacher->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->cteacher->Width = 150;
            // 
            // dataGridViewButtonColumn6
            // 
            this->dataGridViewButtonColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle40->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle40->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle40->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn6->DefaultCellStyle = dataGridViewCellStyle40;
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
            // panel5
            // 
            this->panel5->AutoScroll = true;
            this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel5->Controls->Add(this->label13);
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
            this->panel5->Controls->Add(this->dataGridView6);
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
            this->editteacherpanel->Controls->Add(this->editteacherdelete);
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
            this->editteacherpanel->Controls->Add(this->editteachersave);
            this->editteacherpanel->Controls->Add(this->buttont30);
            this->editteacherpanel->Controls->Add(this->buttont36);
            this->editteacherpanel->Controls->Add(this->label64);
            this->editteacherpanel->Controls->Add(this->label65);
            this->editteacherpanel->Controls->Add(this->label39);
            this->editteacherpanel->Controls->Add(this->teachersearch);
            this->editteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editteacherpanel->Location = System::Drawing::Point(0, 0);
            this->editteacherpanel->Name = L"editteacherpanel";
            this->editteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->editteacherpanel->TabIndex = 264;
            this->editteacherpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editteacherpanel_Paint);
            // 
            // editteacherdelete
            // 
            this->editteacherdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacherdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdelete->Location = System::Drawing::Point(1457, 1275);
            this->editteacherdelete->Name = L"editteacherdelete";
            this->editteacherdelete->Size = System::Drawing::Size(121, 45);
            this->editteacherdelete->TabIndex = 290;
            this->editteacherdelete->Text = L"Delete";
            this->editteacherdelete->UseVisualStyleBackColor = false;
            this->editteacherdelete->Click += gcnew System::EventHandler(this, &MyForm::editteacherdelete_Click);
            // 
            // button18
            // 
            this->button18->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button18->FlatAppearance->BorderColor = System::Drawing::Color::FloralWhite;
            this->button18->FlatAppearance->BorderSize = 0;
            this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button18->Location = System::Drawing::Point(1001, 275);
            this->button18->Name = L"button18";
            this->button18->Size = System::Drawing::Size(30, 38);
            this->button18->TabIndex = 289;
            this->button18->Text = L"🔍\r\n";
            this->button18->UseVisualStyleBackColor = false;
            this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click_2);
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
            this->buttont35->Click += gcnew System::EventHandler(this, &MyForm::buttont35_Click);
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
            this->buttont34->Click += gcnew System::EventHandler(this, &MyForm::buttont34_Click);
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
            this->buttont33->Click += gcnew System::EventHandler(this, &MyForm::buttont33_Click);
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
            this->buttont32->Click += gcnew System::EventHandler(this, &MyForm::buttont32_Click);
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
            this->buttont31->Click += gcnew System::EventHandler(this, &MyForm::buttont31_Click);
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
            this->buttont29->Click += gcnew System::EventHandler(this, &MyForm::buttont29_Click);
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
            this->buttont28->Click += gcnew System::EventHandler(this, &MyForm::buttont28_Click);
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
            this->buttont27->Click += gcnew System::EventHandler(this, &MyForm::buttont27_Click);
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
            this->buttont26->Click += gcnew System::EventHandler(this, &MyForm::buttont26_Click);
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
            this->buttont25->Click += gcnew System::EventHandler(this, &MyForm::buttont25_Click);
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
            this->buttont24->Click += gcnew System::EventHandler(this, &MyForm::buttont24_Click);
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
            this->buttont23->Click += gcnew System::EventHandler(this, &MyForm::buttont23_Click);
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
            this->buttont22->Click += gcnew System::EventHandler(this, &MyForm::buttont22_Click);
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
            this->buttont21->Click += gcnew System::EventHandler(this, &MyForm::buttont21_Click);
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
            this->buttont20->Click += gcnew System::EventHandler(this, &MyForm::buttont20_Click);
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
            this->buttont19->Click += gcnew System::EventHandler(this, &MyForm::buttont19_Click);
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
            this->buttont18->Click += gcnew System::EventHandler(this, &MyForm::buttont18_Click);
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
            this->buttont17->Click += gcnew System::EventHandler(this, &MyForm::buttont17_Click);
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
            this->buttont16->Click += gcnew System::EventHandler(this, &MyForm::buttont16_Click);
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
            this->buttont15->Click += gcnew System::EventHandler(this, &MyForm::buttont15_Click);
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
            this->buttont14->Click += gcnew System::EventHandler(this, &MyForm::buttont14_Click);
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
            this->buttont13->Click += gcnew System::EventHandler(this, &MyForm::buttont13_Click);
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
            this->buttont12->Click += gcnew System::EventHandler(this, &MyForm::buttont12_Click);
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
            this->buttont11->Click += gcnew System::EventHandler(this, &MyForm::buttont11_Click);
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
            this->buttont10->Click += gcnew System::EventHandler(this, &MyForm::buttont10_Click);
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
            this->buttont9->Click += gcnew System::EventHandler(this, &MyForm::buttont9_Click);
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
            this->buttont8->Click += gcnew System::EventHandler(this, &MyForm::buttont8_Click);
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
            this->buttont7->Click += gcnew System::EventHandler(this, &MyForm::buttont7_Click);
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
            this->buttont6->Click += gcnew System::EventHandler(this, &MyForm::buttont6_Click);
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
            this->buttont5->Click += gcnew System::EventHandler(this, &MyForm::buttont5_Click);
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
            this->buttont4->Click += gcnew System::EventHandler(this, &MyForm::buttont4_Click);
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
            this->buttont3->Click += gcnew System::EventHandler(this, &MyForm::buttont3_Click);
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
            this->buttont2->Click += gcnew System::EventHandler(this, &MyForm::buttont2_Click);
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
            this->buttont1->Click += gcnew System::EventHandler(this, &MyForm::buttont1_Click);
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
            // editteachersave
            // 
            this->editteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteachersave->Location = System::Drawing::Point(1277, 1275);
            this->editteachersave->Name = L"editteachersave";
            this->editteachersave->Size = System::Drawing::Size(121, 45);
            this->editteachersave->TabIndex = 273;
            this->editteachersave->Text = L"Save";
            this->editteachersave->UseVisualStyleBackColor = false;
            this->editteachersave->Click += gcnew System::EventHandler(this, &MyForm::editteachersave_Click);
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
            this->buttont30->Click += gcnew System::EventHandler(this, &MyForm::buttont30_Click);
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
            this->buttont36->Click += gcnew System::EventHandler(this, &MyForm::buttont36_Click);
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
            // teachersearch
            // 
            this->teachersearch->BackColor = System::Drawing::Color::White;
            this->teachersearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->teachersearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->teachersearch->FormattingEnabled = true;
            this->teachersearch->ImeMode = System::Windows::Forms::ImeMode::Off;
            this->teachersearch->Location = System::Drawing::Point(669, 275);
            this->teachersearch->Name = L"teachersearch";
            this->teachersearch->Size = System::Drawing::Size(362, 36);
            this->teachersearch->TabIndex = 100;
            this->teachersearch->Text = L"Search";
            this->teachersearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocus);
            this->teachersearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDown);
            this->teachersearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocus);
            // 
            // editroompanel
            // 
            this->editroompanel->AutoScroll = true;
            this->editroompanel->Controls->Add(this->editroomsearchbutton);
            this->editroompanel->Controls->Add(this->editroomsearch);
            this->editroompanel->Controls->Add(this->label82);
            this->editroompanel->Controls->Add(this->panel6);
            this->editroompanel->Controls->Add(this->editroomdelete);
            this->editroompanel->Controls->Add(this->label66);
            this->editroompanel->Controls->Add(this->label67);
            this->editroompanel->Controls->Add(this->label68);
            this->editroompanel->Controls->Add(this->label69);
            this->editroompanel->Controls->Add(this->label70);
            this->editroompanel->Controls->Add(this->label71);
            this->editroompanel->Controls->Add(this->label72);
            this->editroompanel->Controls->Add(this->label73);
            this->editroompanel->Controls->Add(this->label74);
            this->editroompanel->Controls->Add(this->label75);
            this->editroompanel->Controls->Add(this->label76);
            this->editroompanel->Controls->Add(this->label77);
            this->editroompanel->Controls->Add(this->buttonr36);
            this->editroompanel->Controls->Add(this->buttonr35);
            this->editroompanel->Controls->Add(this->buttonr34);
            this->editroompanel->Controls->Add(this->buttonr33);
            this->editroompanel->Controls->Add(this->buttonr32);
            this->editroompanel->Controls->Add(this->buttonr31);
            this->editroompanel->Controls->Add(this->buttonr30);
            this->editroompanel->Controls->Add(this->buttonr29);
            this->editroompanel->Controls->Add(this->buttonr28);
            this->editroompanel->Controls->Add(this->buttonr27);
            this->editroompanel->Controls->Add(this->buttonr26);
            this->editroompanel->Controls->Add(this->buttonr25);
            this->editroompanel->Controls->Add(this->buttonr24);
            this->editroompanel->Controls->Add(this->buttonr23);
            this->editroompanel->Controls->Add(this->buttonr22);
            this->editroompanel->Controls->Add(this->buttonr21);
            this->editroompanel->Controls->Add(this->buttonr20);
            this->editroompanel->Controls->Add(this->buttonr19);
            this->editroompanel->Controls->Add(this->buttonr18);
            this->editroompanel->Controls->Add(this->buttonr17);
            this->editroompanel->Controls->Add(this->buttonr16);
            this->editroompanel->Controls->Add(this->buttonr15);
            this->editroompanel->Controls->Add(this->buttonr14);
            this->editroompanel->Controls->Add(this->buttonr13);
            this->editroompanel->Controls->Add(this->buttonr12);
            this->editroompanel->Controls->Add(this->buttonr11);
            this->editroompanel->Controls->Add(this->buttonr10);
            this->editroompanel->Controls->Add(this->buttonr9);
            this->editroompanel->Controls->Add(this->buttonr8);
            this->editroompanel->Controls->Add(this->buttonr7);
            this->editroompanel->Controls->Add(this->buttonr6);
            this->editroompanel->Controls->Add(this->buttonr5);
            this->editroompanel->Controls->Add(this->buttonr4);
            this->editroompanel->Controls->Add(this->buttonr3);
            this->editroompanel->Controls->Add(this->buttonr2);
            this->editroompanel->Controls->Add(this->buttonr1);
            this->editroompanel->Controls->Add(this->editroomdepartment);
            this->editroompanel->Controls->Add(this->label78);
            this->editroompanel->Controls->Add(this->label79);
            this->editroompanel->Controls->Add(this->label80);
            this->editroompanel->Controls->Add(this->editroomcapacity);
            this->editroompanel->Controls->Add(this->editroomname);
            this->editroompanel->Controls->Add(this->label81);
            this->editroompanel->Controls->Add(this->editroomsave);
            this->editroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editroompanel->Location = System::Drawing::Point(0, 0);
            this->editroompanel->Name = L"editroompanel";
            this->editroompanel->Size = System::Drawing::Size(1946, 1106);
            this->editroompanel->TabIndex = 124;
            // 
            // editroomsearchbutton
            // 
            this->editroomsearchbutton->Location = System::Drawing::Point(1237, 289);
            this->editroomsearchbutton->Name = L"editroomsearchbutton";
            this->editroomsearchbutton->Size = System::Drawing::Size(132, 30);
            this->editroomsearchbutton->TabIndex = 292;
            this->editroomsearchbutton->Text = L"search";
            this->editroomsearchbutton->UseVisualStyleBackColor = true;
            this->editroomsearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editroomsearchbutton_Click);
            // 
            // editroomsearch
            // 
            this->editroomsearch->Location = System::Drawing::Point(865, 289);
            this->editroomsearch->Multiline = false;
            this->editroomsearch->Name = L"editroomsearch";
            this->editroomsearch->Size = System::Drawing::Size(361, 30);
            this->editroomsearch->TabIndex = 291;
            this->editroomsearch->Text = L"";
            // 
            // label82
            // 
            this->label82->AutoSize = true;
            this->label82->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label82->Location = System::Drawing::Point(930, 228);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(271, 30);
            this->label82->TabIndex = 290;
            this->label82->Text = L"Enter the Classroom Name";
            // 
            // panel6
            // 
            this->panel6->Controls->Add(this->editroomlabyes);
            this->panel6->Controls->Add(this->editroomlabno);
            this->panel6->Location = System::Drawing::Point(399, 675);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(207, 63);
            this->panel6->TabIndex = 182;
            // 
            // editroomlabyes
            // 
            this->editroomlabyes->AutoSize = true;
            this->editroomlabyes->Location = System::Drawing::Point(20, 16);
            this->editroomlabyes->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomlabyes->Name = L"editroomlabyes";
            this->editroomlabyes->Size = System::Drawing::Size(62, 24);
            this->editroomlabyes->TabIndex = 8;
            this->editroomlabyes->TabStop = true;
            this->editroomlabyes->Text = L"Yes";
            this->editroomlabyes->UseVisualStyleBackColor = true;
            // 
            // editroomlabno
            // 
            this->editroomlabno->AutoSize = true;
            this->editroomlabno->Location = System::Drawing::Point(131, 14);
            this->editroomlabno->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomlabno->Name = L"editroomlabno";
            this->editroomlabno->Size = System::Drawing::Size(54, 24);
            this->editroomlabno->TabIndex = 9;
            this->editroomlabno->TabStop = true;
            this->editroomlabno->Text = L"No";
            this->editroomlabno->UseVisualStyleBackColor = true;
            // 
            // editroomdelete
            // 
            this->editroomdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomdelete->Location = System::Drawing::Point(1349, 1430);
            this->editroomdelete->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomdelete->Name = L"editroomdelete";
            this->editroomdelete->Size = System::Drawing::Size(138, 54);
            this->editroomdelete->TabIndex = 180;
            this->editroomdelete->Text = L"Delete";
            this->editroomdelete->UseVisualStyleBackColor = false;
            this->editroomdelete->Click += gcnew System::EventHandler(this, &MyForm::editroomdelete_Click);
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label66->Location = System::Drawing::Point(561, 864);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(105, 28);
            this->label66->TabIndex = 179;
            this->label66->Text = L"9:00-10:00";
            // 
            // label67
            // 
            this->label67->AutoSize = true;
            this->label67->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label67->Location = System::Drawing::Point(724, 864);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(116, 28);
            this->label67->TabIndex = 178;
            this->label67->Text = L"10:00-11:00";
            // 
            // label68
            // 
            this->label68->AutoSize = true;
            this->label68->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label68->Location = System::Drawing::Point(876, 864);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(116, 28);
            this->label68->TabIndex = 177;
            this->label68->Text = L"11:30-12:30";
            // 
            // label69
            // 
            this->label69->AutoSize = true;
            this->label69->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label69->Location = System::Drawing::Point(1036, 864);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(105, 28);
            this->label69->TabIndex = 176;
            this->label69->Text = L"12:30-1:30";
            // 
            // label70
            // 
            this->label70->AutoSize = true;
            this->label70->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label70->Location = System::Drawing::Point(1199, 864);
            this->label70->Name = L"label70";
            this->label70->Size = System::Drawing::Size(94, 28);
            this->label70->TabIndex = 175;
            this->label70->Text = L"2:30-3:30";
            // 
            // label71
            // 
            this->label71->AutoSize = true;
            this->label71->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label71->Location = System::Drawing::Point(1344, 864);
            this->label71->Name = L"label71";
            this->label71->Size = System::Drawing::Size(94, 28);
            this->label71->TabIndex = 174;
            this->label71->Text = L"3:30-4:30";
            // 
            // label72
            // 
            this->label72->AutoSize = true;
            this->label72->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label72->Location = System::Drawing::Point(413, 938);
            this->label72->Name = L"label72";
            this->label72->Size = System::Drawing::Size(85, 28);
            this->label72->TabIndex = 173;
            this->label72->Text = L"Monday";
            // 
            // label73
            // 
            this->label73->AutoSize = true;
            this->label73->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label73->Location = System::Drawing::Point(418, 999);
            this->label73->Name = L"label73";
            this->label73->Size = System::Drawing::Size(83, 28);
            this->label73->TabIndex = 172;
            this->label73->Text = L"Tuesday";
            // 
            // label74
            // 
            this->label74->AutoSize = true;
            this->label74->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label74->Location = System::Drawing::Point(405, 1061);
            this->label74->Name = L"label74";
            this->label74->Size = System::Drawing::Size(113, 28);
            this->label74->TabIndex = 171;
            this->label74->Text = L"Wednesday";
            // 
            // label75
            // 
            this->label75->AutoSize = true;
            this->label75->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label75->Location = System::Drawing::Point(405, 1124);
            this->label75->Name = L"label75";
            this->label75->Size = System::Drawing::Size(91, 28);
            this->label75->TabIndex = 170;
            this->label75->Text = L"Thursday";
            // 
            // label76
            // 
            this->label76->AutoSize = true;
            this->label76->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label76->Location = System::Drawing::Point(421, 1181);
            this->label76->Name = L"label76";
            this->label76->Size = System::Drawing::Size(66, 28);
            this->label76->TabIndex = 169;
            this->label76->Text = L"Friday";
            // 
            // label77
            // 
            this->label77->AutoSize = true;
            this->label77->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label77->Location = System::Drawing::Point(413, 1239);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(90, 28);
            this->label77->TabIndex = 168;
            this->label77->Text = L"Saturday";
            // 
            // buttonr36
            // 
            this->buttonr36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr36->Location = System::Drawing::Point(1339, 1235);
            this->buttonr36->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr36->Name = L"buttonr36";
            this->buttonr36->Size = System::Drawing::Size(138, 54);
            this->buttonr36->TabIndex = 167;
            this->buttonr36->Text = L"free";
            this->buttonr36->UseVisualStyleBackColor = false;
            this->buttonr36->Click += gcnew System::EventHandler(this, &MyForm::buttonr36_Click);
            // 
            // buttonr35
            // 
            this->buttonr35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr35->Location = System::Drawing::Point(1179, 1234);
            this->buttonr35->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr35->Name = L"buttonr35";
            this->buttonr35->Size = System::Drawing::Size(138, 54);
            this->buttonr35->TabIndex = 166;
            this->buttonr35->Text = L"free";
            this->buttonr35->UseVisualStyleBackColor = false;
            this->buttonr35->Click += gcnew System::EventHandler(this, &MyForm::buttonr35_Click);
            // 
            // buttonr34
            // 
            this->buttonr34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr34->Location = System::Drawing::Point(1021, 1234);
            this->buttonr34->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr34->Name = L"buttonr34";
            this->buttonr34->Size = System::Drawing::Size(138, 54);
            this->buttonr34->TabIndex = 165;
            this->buttonr34->Text = L"free";
            this->buttonr34->UseVisualStyleBackColor = false;
            this->buttonr34->Click += gcnew System::EventHandler(this, &MyForm::buttonr34_Click);
            // 
            // buttonr33
            // 
            this->buttonr33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr33->Location = System::Drawing::Point(860, 1234);
            this->buttonr33->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr33->Name = L"buttonr33";
            this->buttonr33->Size = System::Drawing::Size(138, 54);
            this->buttonr33->TabIndex = 164;
            this->buttonr33->Text = L"free";
            this->buttonr33->UseVisualStyleBackColor = false;
            this->buttonr33->Click += gcnew System::EventHandler(this, &MyForm::buttonr33_Click);
            // 
            // buttonr32
            // 
            this->buttonr32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr32->Location = System::Drawing::Point(706, 1235);
            this->buttonr32->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr32->Name = L"buttonr32";
            this->buttonr32->Size = System::Drawing::Size(138, 54);
            this->buttonr32->TabIndex = 163;
            this->buttonr32->Text = L"free";
            this->buttonr32->UseVisualStyleBackColor = false;
            this->buttonr32->Click += gcnew System::EventHandler(this, &MyForm::buttonr32_Click);
            // 
            // buttonr31
            // 
            this->buttonr31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr31->Location = System::Drawing::Point(548, 1235);
            this->buttonr31->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr31->Name = L"buttonr31";
            this->buttonr31->Size = System::Drawing::Size(138, 54);
            this->buttonr31->TabIndex = 162;
            this->buttonr31->Text = L"free";
            this->buttonr31->UseVisualStyleBackColor = false;
            this->buttonr31->Click += gcnew System::EventHandler(this, &MyForm::buttonr31_Click);
            // 
            // buttonr30
            // 
            this->buttonr30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr30->Location = System::Drawing::Point(1339, 1173);
            this->buttonr30->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr30->Name = L"buttonr30";
            this->buttonr30->Size = System::Drawing::Size(138, 54);
            this->buttonr30->TabIndex = 161;
            this->buttonr30->Text = L"free";
            this->buttonr30->UseVisualStyleBackColor = false;
            this->buttonr30->Click += gcnew System::EventHandler(this, &MyForm::buttonr30_Click);
            // 
            // buttonr29
            // 
            this->buttonr29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr29->Location = System::Drawing::Point(1179, 1168);
            this->buttonr29->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr29->Name = L"buttonr29";
            this->buttonr29->Size = System::Drawing::Size(138, 54);
            this->buttonr29->TabIndex = 160;
            this->buttonr29->Text = L"free";
            this->buttonr29->UseVisualStyleBackColor = false;
            this->buttonr29->Click += gcnew System::EventHandler(this, &MyForm::buttonr29_Click);
            // 
            // buttonr28
            // 
            this->buttonr28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr28->Location = System::Drawing::Point(1021, 1168);
            this->buttonr28->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr28->Name = L"buttonr28";
            this->buttonr28->Size = System::Drawing::Size(138, 54);
            this->buttonr28->TabIndex = 159;
            this->buttonr28->Text = L"free";
            this->buttonr28->UseVisualStyleBackColor = false;
            this->buttonr28->Click += gcnew System::EventHandler(this, &MyForm::buttonr28_Click);
            // 
            // buttonr27
            // 
            this->buttonr27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr27->Location = System::Drawing::Point(860, 1168);
            this->buttonr27->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr27->Name = L"buttonr27";
            this->buttonr27->Size = System::Drawing::Size(138, 54);
            this->buttonr27->TabIndex = 158;
            this->buttonr27->Text = L"free";
            this->buttonr27->UseVisualStyleBackColor = false;
            this->buttonr27->Click += gcnew System::EventHandler(this, &MyForm::buttonr27_Click);
            // 
            // buttonr26
            // 
            this->buttonr26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr26->Location = System::Drawing::Point(706, 1169);
            this->buttonr26->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr26->Name = L"buttonr26";
            this->buttonr26->Size = System::Drawing::Size(138, 54);
            this->buttonr26->TabIndex = 157;
            this->buttonr26->Text = L"free";
            this->buttonr26->UseVisualStyleBackColor = false;
            this->buttonr26->Click += gcnew System::EventHandler(this, &MyForm::buttonr26_Click);
            // 
            // buttonr25
            // 
            this->buttonr25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr25->Location = System::Drawing::Point(548, 1169);
            this->buttonr25->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr25->Name = L"buttonr25";
            this->buttonr25->Size = System::Drawing::Size(138, 54);
            this->buttonr25->TabIndex = 156;
            this->buttonr25->Text = L"free";
            this->buttonr25->UseVisualStyleBackColor = false;
            this->buttonr25->Click += gcnew System::EventHandler(this, &MyForm::buttonr25_Click);
            // 
            // buttonr24
            // 
            this->buttonr24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr24->Location = System::Drawing::Point(1339, 1111);
            this->buttonr24->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr24->Name = L"buttonr24";
            this->buttonr24->Size = System::Drawing::Size(138, 54);
            this->buttonr24->TabIndex = 155;
            this->buttonr24->Text = L"free";
            this->buttonr24->UseVisualStyleBackColor = false;
            this->buttonr24->Click += gcnew System::EventHandler(this, &MyForm::buttonr24_Click);
            // 
            // buttonr23
            // 
            this->buttonr23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr23->Location = System::Drawing::Point(1179, 1110);
            this->buttonr23->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr23->Name = L"buttonr23";
            this->buttonr23->Size = System::Drawing::Size(138, 54);
            this->buttonr23->TabIndex = 154;
            this->buttonr23->Text = L"free";
            this->buttonr23->UseVisualStyleBackColor = false;
            this->buttonr23->Click += gcnew System::EventHandler(this, &MyForm::buttonr23_Click);
            // 
            // buttonr22
            // 
            this->buttonr22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr22->Location = System::Drawing::Point(1021, 1110);
            this->buttonr22->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr22->Name = L"buttonr22";
            this->buttonr22->Size = System::Drawing::Size(138, 54);
            this->buttonr22->TabIndex = 153;
            this->buttonr22->Text = L"free";
            this->buttonr22->UseVisualStyleBackColor = false;
            this->buttonr22->Click += gcnew System::EventHandler(this, &MyForm::buttonr22_Click);
            // 
            // buttonr21
            // 
            this->buttonr21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr21->Location = System::Drawing::Point(860, 1110);
            this->buttonr21->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr21->Name = L"buttonr21";
            this->buttonr21->Size = System::Drawing::Size(138, 54);
            this->buttonr21->TabIndex = 152;
            this->buttonr21->Text = L"free";
            this->buttonr21->UseVisualStyleBackColor = false;
            this->buttonr21->Click += gcnew System::EventHandler(this, &MyForm::buttonr21_Click);
            // 
            // buttonr20
            // 
            this->buttonr20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr20->Location = System::Drawing::Point(706, 1111);
            this->buttonr20->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr20->Name = L"buttonr20";
            this->buttonr20->Size = System::Drawing::Size(138, 54);
            this->buttonr20->TabIndex = 151;
            this->buttonr20->Text = L"free";
            this->buttonr20->UseVisualStyleBackColor = false;
            this->buttonr20->Click += gcnew System::EventHandler(this, &MyForm::buttonr20_Click);
            // 
            // buttonr19
            // 
            this->buttonr19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr19->Location = System::Drawing::Point(547, 1111);
            this->buttonr19->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr19->Name = L"buttonr19";
            this->buttonr19->Size = System::Drawing::Size(138, 54);
            this->buttonr19->TabIndex = 150;
            this->buttonr19->Text = L"free";
            this->buttonr19->UseVisualStyleBackColor = false;
            this->buttonr19->Click += gcnew System::EventHandler(this, &MyForm::buttonr19_Click);
            // 
            // buttonr18
            // 
            this->buttonr18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr18->Location = System::Drawing::Point(1339, 1049);
            this->buttonr18->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr18->Name = L"buttonr18";
            this->buttonr18->Size = System::Drawing::Size(138, 54);
            this->buttonr18->TabIndex = 149;
            this->buttonr18->Text = L"free";
            this->buttonr18->UseVisualStyleBackColor = false;
            this->buttonr18->Click += gcnew System::EventHandler(this, &MyForm::buttonr18_Click);
            // 
            // buttonr17
            // 
            this->buttonr17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr17->Location = System::Drawing::Point(1179, 1048);
            this->buttonr17->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr17->Name = L"buttonr17";
            this->buttonr17->Size = System::Drawing::Size(138, 54);
            this->buttonr17->TabIndex = 148;
            this->buttonr17->Text = L"free";
            this->buttonr17->UseVisualStyleBackColor = false;
            this->buttonr17->Click += gcnew System::EventHandler(this, &MyForm::buttonr17_Click);
            // 
            // buttonr16
            // 
            this->buttonr16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr16->Location = System::Drawing::Point(1021, 1048);
            this->buttonr16->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr16->Name = L"buttonr16";
            this->buttonr16->Size = System::Drawing::Size(138, 54);
            this->buttonr16->TabIndex = 147;
            this->buttonr16->Text = L"free";
            this->buttonr16->UseVisualStyleBackColor = false;
            this->buttonr16->Click += gcnew System::EventHandler(this, &MyForm::buttonr16_Click);
            // 
            // buttonr15
            // 
            this->buttonr15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr15->Location = System::Drawing::Point(860, 1048);
            this->buttonr15->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr15->Name = L"buttonr15";
            this->buttonr15->Size = System::Drawing::Size(138, 54);
            this->buttonr15->TabIndex = 146;
            this->buttonr15->Text = L"free";
            this->buttonr15->UseVisualStyleBackColor = false;
            this->buttonr15->Click += gcnew System::EventHandler(this, &MyForm::buttonr15_Click);
            // 
            // buttonr14
            // 
            this->buttonr14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr14->Location = System::Drawing::Point(706, 1049);
            this->buttonr14->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr14->Name = L"buttonr14";
            this->buttonr14->Size = System::Drawing::Size(138, 54);
            this->buttonr14->TabIndex = 145;
            this->buttonr14->Text = L"free";
            this->buttonr14->UseVisualStyleBackColor = false;
            this->buttonr14->Click += gcnew System::EventHandler(this, &MyForm::buttonr14_Click);
            // 
            // buttonr13
            // 
            this->buttonr13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr13->Location = System::Drawing::Point(547, 1049);
            this->buttonr13->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr13->Name = L"buttonr13";
            this->buttonr13->Size = System::Drawing::Size(138, 54);
            this->buttonr13->TabIndex = 144;
            this->buttonr13->Text = L"free";
            this->buttonr13->UseVisualStyleBackColor = false;
            this->buttonr13->Click += gcnew System::EventHandler(this, &MyForm::buttonr13_Click);
            // 
            // buttonr12
            // 
            this->buttonr12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr12->Location = System::Drawing::Point(1339, 987);
            this->buttonr12->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr12->Name = L"buttonr12";
            this->buttonr12->Size = System::Drawing::Size(138, 54);
            this->buttonr12->TabIndex = 143;
            this->buttonr12->Text = L"free";
            this->buttonr12->UseVisualStyleBackColor = false;
            this->buttonr12->Click += gcnew System::EventHandler(this, &MyForm::buttonr12_Click);
            // 
            // buttonr11
            // 
            this->buttonr11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr11->Location = System::Drawing::Point(1179, 986);
            this->buttonr11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr11->Name = L"buttonr11";
            this->buttonr11->Size = System::Drawing::Size(138, 54);
            this->buttonr11->TabIndex = 142;
            this->buttonr11->Text = L"free";
            this->buttonr11->UseVisualStyleBackColor = false;
            this->buttonr11->Click += gcnew System::EventHandler(this, &MyForm::buttonr11_Click);
            // 
            // buttonr10
            // 
            this->buttonr10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr10->Location = System::Drawing::Point(1021, 986);
            this->buttonr10->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr10->Name = L"buttonr10";
            this->buttonr10->Size = System::Drawing::Size(138, 54);
            this->buttonr10->TabIndex = 141;
            this->buttonr10->Text = L"free";
            this->buttonr10->UseVisualStyleBackColor = false;
            this->buttonr10->Click += gcnew System::EventHandler(this, &MyForm::buttonr10_Click);
            // 
            // buttonr9
            // 
            this->buttonr9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr9->Location = System::Drawing::Point(860, 986);
            this->buttonr9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr9->Name = L"buttonr9";
            this->buttonr9->Size = System::Drawing::Size(138, 54);
            this->buttonr9->TabIndex = 140;
            this->buttonr9->Text = L"free";
            this->buttonr9->UseVisualStyleBackColor = false;
            this->buttonr9->Click += gcnew System::EventHandler(this, &MyForm::buttonr9_Click);
            // 
            // buttonr8
            // 
            this->buttonr8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr8->Location = System::Drawing::Point(706, 987);
            this->buttonr8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr8->Name = L"buttonr8";
            this->buttonr8->Size = System::Drawing::Size(138, 54);
            this->buttonr8->TabIndex = 139;
            this->buttonr8->Text = L"free";
            this->buttonr8->UseVisualStyleBackColor = false;
            this->buttonr8->Click += gcnew System::EventHandler(this, &MyForm::buttonr8_Click);
            // 
            // buttonr7
            // 
            this->buttonr7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr7->Location = System::Drawing::Point(548, 987);
            this->buttonr7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr7->Name = L"buttonr7";
            this->buttonr7->Size = System::Drawing::Size(138, 54);
            this->buttonr7->TabIndex = 138;
            this->buttonr7->Text = L"free";
            this->buttonr7->UseVisualStyleBackColor = false;
            this->buttonr7->Click += gcnew System::EventHandler(this, &MyForm::buttonr7_Click);
            // 
            // buttonr6
            // 
            this->buttonr6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr6->Location = System::Drawing::Point(1339, 927);
            this->buttonr6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr6->Name = L"buttonr6";
            this->buttonr6->Size = System::Drawing::Size(138, 54);
            this->buttonr6->TabIndex = 137;
            this->buttonr6->Text = L"free";
            this->buttonr6->UseVisualStyleBackColor = false;
            this->buttonr6->Click += gcnew System::EventHandler(this, &MyForm::buttonr6_Click);
            // 
            // buttonr5
            // 
            this->buttonr5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr5->Location = System::Drawing::Point(1179, 926);
            this->buttonr5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr5->Name = L"buttonr5";
            this->buttonr5->Size = System::Drawing::Size(138, 54);
            this->buttonr5->TabIndex = 136;
            this->buttonr5->Text = L"free";
            this->buttonr5->UseVisualStyleBackColor = false;
            this->buttonr5->Click += gcnew System::EventHandler(this, &MyForm::buttonrs_Click);
            // 
            // buttonr4
            // 
            this->buttonr4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr4->Location = System::Drawing::Point(1021, 926);
            this->buttonr4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr4->Name = L"buttonr4";
            this->buttonr4->Size = System::Drawing::Size(138, 54);
            this->buttonr4->TabIndex = 135;
            this->buttonr4->Text = L"free";
            this->buttonr4->UseVisualStyleBackColor = false;
            this->buttonr4->Click += gcnew System::EventHandler(this, &MyForm::buttonr4_Click);
            // 
            // buttonr3
            // 
            this->buttonr3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr3->Location = System::Drawing::Point(860, 926);
            this->buttonr3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr3->Name = L"buttonr3";
            this->buttonr3->Size = System::Drawing::Size(138, 54);
            this->buttonr3->TabIndex = 134;
            this->buttonr3->Text = L"free";
            this->buttonr3->UseVisualStyleBackColor = false;
            this->buttonr3->Click += gcnew System::EventHandler(this, &MyForm::buttonr3_Click);
            // 
            // buttonr2
            // 
            this->buttonr2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr2->Location = System::Drawing::Point(706, 925);
            this->buttonr2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr2->Name = L"buttonr2";
            this->buttonr2->Size = System::Drawing::Size(138, 54);
            this->buttonr2->TabIndex = 133;
            this->buttonr2->Text = L"free";
            this->buttonr2->UseVisualStyleBackColor = false;
            this->buttonr2->Click += gcnew System::EventHandler(this, &MyForm::buttonr2_Click);
            // 
            // buttonr1
            // 
            this->buttonr1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttonr1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonr1->Location = System::Drawing::Point(547, 925);
            this->buttonr1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->buttonr1->Name = L"buttonr1";
            this->buttonr1->Size = System::Drawing::Size(138, 54);
            this->buttonr1->TabIndex = 132;
            this->buttonr1->Text = L"free";
            this->buttonr1->UseVisualStyleBackColor = false;
            this->buttonr1->Click += gcnew System::EventHandler(this, &MyForm::buttonr1_Click);
            // 
            // editroomdepartment
            // 
            this->editroomdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editroomdepartment->FormattingEnabled = true;
            this->editroomdepartment->Location = System::Drawing::Point(396, 792);
            this->editroomdepartment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomdepartment->Name = L"editroomdepartment";
            this->editroomdepartment->Size = System::Drawing::Size(294, 36);
            this->editroomdepartment->TabIndex = 131;
            // 
            // label78
            // 
            this->label78->AutoSize = true;
            this->label78->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label78->Location = System::Drawing::Point(393, 753);
            this->label78->Name = L"label78";
            this->label78->Size = System::Drawing::Size(117, 28);
            this->label78->TabIndex = 130;
            this->label78->Text = L"Department";
            // 
            // label79
            // 
            this->label79->AutoSize = true;
            this->label79->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label79->Location = System::Drawing::Point(399, 633);
            this->label79->Name = L"label79";
            this->label79->Size = System::Drawing::Size(98, 28);
            this->label79->TabIndex = 129;
            this->label79->Text = L"Is it a lab\?";
            // 
            // label80
            // 
            this->label80->AutoSize = true;
            this->label80->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label80->Location = System::Drawing::Point(399, 519);
            this->label80->Name = L"label80";
            this->label80->Size = System::Drawing::Size(158, 28);
            this->label80->TabIndex = 128;
            this->label80->Text = L"Capacity of Class";
            // 
            // editroomcapacity
            // 
            this->editroomcapacity->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomcapacity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editroomcapacity->Location = System::Drawing::Point(403, 568);
            this->editroomcapacity->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomcapacity->Name = L"editroomcapacity";
            this->editroomcapacity->Size = System::Drawing::Size(300, 34);
            this->editroomcapacity->TabIndex = 127;
            // 
            // editroomname
            // 
            this->editroomname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editroomname->Location = System::Drawing::Point(398, 458);
            this->editroomname->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomname->Name = L"editroomname";
            this->editroomname->Size = System::Drawing::Size(295, 34);
            this->editroomname->TabIndex = 126;
            // 
            // label81
            // 
            this->label81->AutoSize = true;
            this->label81->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label81->Location = System::Drawing::Point(394, 397);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(164, 28);
            this->label81->TabIndex = 125;
            this->label81->Text = L"ClassRoom Name";
            // 
            // editroomsave
            // 
            this->editroomsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomsave->Location = System::Drawing::Point(1086, 1429);
            this->editroomsave->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomsave->Name = L"editroomsave";
            this->editroomsave->Size = System::Drawing::Size(138, 54);
            this->editroomsave->TabIndex = 124;
            this->editroomsave->Text = L"Save";
            this->editroomsave->UseVisualStyleBackColor = false;
            this->editroomsave->Click += gcnew System::EventHandler(this, &MyForm::editroomsave_Click);
            // 
            // editsubjectpanel
            // 
            this->editsubjectpanel->Controls->Add(this->panel10);
            this->editsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->editsubjectpanel->Name = L"editsubjectpanel";
            this->editsubjectpanel->Size = System::Drawing::Size(1946, 1106);
            this->editsubjectpanel->TabIndex = 259;
            this->editsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editsubjectpanel_Paint);
            // 
            // panel10
            // 
            this->panel10->AutoScroll = true;
            this->panel10->Controls->Add(this->button22);
            this->panel10->Controls->Add(this->button23);
            this->panel10->Controls->Add(this->textBox19);
            this->panel10->Controls->Add(this->label92);
            this->panel10->Controls->Add(this->label93);
            this->panel10->Controls->Add(this->label94);
            this->panel10->Controls->Add(this->label95);
            this->panel10->Controls->Add(this->label96);
            this->panel10->Controls->Add(this->label97);
            this->panel10->Controls->Add(this->label98);
            this->panel10->Controls->Add(this->label99);
            this->panel10->Controls->Add(this->label100);
            this->panel10->Controls->Add(this->label101);
            this->panel10->Controls->Add(this->label102);
            this->panel10->Controls->Add(this->button24);
            this->panel10->Controls->Add(this->button25);
            this->panel10->Controls->Add(this->button26);
            this->panel10->Controls->Add(this->button27);
            this->panel10->Controls->Add(this->button28);
            this->panel10->Controls->Add(this->button29);
            this->panel10->Controls->Add(this->button30);
            this->panel10->Controls->Add(this->button31);
            this->panel10->Controls->Add(this->button32);
            this->panel10->Controls->Add(this->button33);
            this->panel10->Controls->Add(this->button34);
            this->panel10->Controls->Add(this->button35);
            this->panel10->Controls->Add(this->button36);
            this->panel10->Controls->Add(this->button39);
            this->panel10->Controls->Add(this->button40);
            this->panel10->Controls->Add(this->button41);
            this->panel10->Controls->Add(this->button42);
            this->panel10->Controls->Add(this->button43);
            this->panel10->Controls->Add(this->button44);
            this->panel10->Controls->Add(this->button45);
            this->panel10->Controls->Add(this->button46);
            this->panel10->Controls->Add(this->button47);
            this->panel10->Controls->Add(this->button48);
            this->panel10->Controls->Add(this->button49);
            this->panel10->Controls->Add(this->button50);
            this->panel10->Controls->Add(this->button51);
            this->panel10->Controls->Add(this->button52);
            this->panel10->Controls->Add(this->button53);
            this->panel10->Controls->Add(this->button54);
            this->panel10->Controls->Add(this->button55);
            this->panel10->Controls->Add(this->button56);
            this->panel10->Controls->Add(this->button57);
            this->panel10->Controls->Add(this->button58);
            this->panel10->Controls->Add(this->button59);
            this->panel10->Controls->Add(this->label103);
            this->panel10->Controls->Add(this->comboBox4);
            this->panel10->Controls->Add(this->label104);
            this->panel10->Controls->Add(this->textBox20);
            this->panel10->Controls->Add(this->button60);
            this->panel10->Controls->Add(this->button61);
            this->panel10->Controls->Add(this->button62);
            this->panel10->Controls->Add(this->label105);
            this->panel10->Controls->Add(this->label106);
            this->panel10->Controls->Add(this->richTextBox1);
            this->panel10->Controls->Add(this->label107);
            this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel10->Location = System::Drawing::Point(0, 0);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(1946, 1106);
            this->panel10->TabIndex = 266;
            // 
            // button22
            // 
            this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button22->Location = System::Drawing::Point(1457, 1275);
            this->button22->Name = L"button22";
            this->button22->Size = System::Drawing::Size(121, 45);
            this->button22->TabIndex = 290;
            this->button22->Text = L"Delete";
            this->button22->UseVisualStyleBackColor = false;
            // 
            // button23
            // 
            this->button23->Location = System::Drawing::Point(1030, 285);
            this->button23->Name = L"button23";
            this->button23->Size = System::Drawing::Size(132, 30);
            this->button23->TabIndex = 289;
            this->button23->Text = L"search";
            this->button23->UseVisualStyleBackColor = true;
            // 
            // textBox19
            // 
            this->textBox19->Location = System::Drawing::Point(1115, 589);
            this->textBox19->Name = L"textBox19";
            this->textBox19->Size = System::Drawing::Size(124, 26);
            this->textBox19->TabIndex = 286;
            // 
            // label92
            // 
            this->label92->AutoSize = true;
            this->label92->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label92->Location = System::Drawing::Point(1267, 780);
            this->label92->Name = L"label92";
            this->label92->Size = System::Drawing::Size(94, 28);
            this->label92->TabIndex = 285;
            this->label92->Text = L"3:30-4:30";
            // 
            // label93
            // 
            this->label93->AutoSize = true;
            this->label93->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label93->Location = System::Drawing::Point(956, 779);
            this->label93->Name = L"label93";
            this->label93->Size = System::Drawing::Size(116, 28);
            this->label93->TabIndex = 284;
            this->label93->Text = L"12:30-11:30";
            // 
            // label94
            // 
            this->label94->AutoSize = true;
            this->label94->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label94->Location = System::Drawing::Point(778, 779);
            this->label94->Name = L"label94";
            this->label94->Size = System::Drawing::Size(116, 28);
            this->label94->TabIndex = 282;
            this->label94->Text = L"11:30-12:30";
            // 
            // label95
            // 
            this->label95->AutoSize = true;
            this->label95->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label95->Location = System::Drawing::Point(638, 779);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(116, 28);
            this->label95->TabIndex = 281;
            this->label95->Text = L"10:00-11:00";
            // 
            // label96
            // 
            this->label96->AutoSize = true;
            this->label96->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label96->Location = System::Drawing::Point(497, 779);
            this->label96->Name = L"label96";
            this->label96->Size = System::Drawing::Size(105, 28);
            this->label96->TabIndex = 280;
            this->label96->Text = L"9:00-10:00";
            // 
            // label97
            // 
            this->label97->AutoSize = true;
            this->label97->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label97->Location = System::Drawing::Point(342, 906);
            this->label97->Name = L"label97";
            this->label97->Size = System::Drawing::Size(83, 28);
            this->label97->TabIndex = 279;
            this->label97->Text = L"Tuesday";
            // 
            // label98
            // 
            this->label98->AutoSize = true;
            this->label98->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label98->Location = System::Drawing::Point(328, 975);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(113, 28);
            this->label98->TabIndex = 278;
            this->label98->Text = L"Wednesday";
            // 
            // label99
            // 
            this->label99->AutoSize = true;
            this->label99->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label99->Location = System::Drawing::Point(338, 1036);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(91, 28);
            this->label99->TabIndex = 277;
            this->label99->Text = L"Thursday";
            // 
            // label100
            // 
            this->label100->AutoSize = true;
            this->label100->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label100->Location = System::Drawing::Point(359, 1098);
            this->label100->Name = L"label100";
            this->label100->Size = System::Drawing::Size(66, 28);
            this->label100->TabIndex = 276;
            this->label100->Text = L"Friday";
            // 
            // label101
            // 
            this->label101->AutoSize = true;
            this->label101->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label101->Location = System::Drawing::Point(345, 1153);
            this->label101->Name = L"label101";
            this->label101->Size = System::Drawing::Size(90, 28);
            this->label101->TabIndex = 275;
            this->label101->Text = L"Saturday";
            // 
            // label102
            // 
            this->label102->AutoSize = true;
            this->label102->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label102->Location = System::Drawing::Point(342, 849);
            this->label102->Name = L"label102";
            this->label102->Size = System::Drawing::Size(85, 28);
            this->label102->TabIndex = 274;
            this->label102->Text = L"Monday";
            // 
            // button24
            // 
            this->button24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button24->Location = System::Drawing::Point(1105, 1146);
            this->button24->Name = L"button24";
            this->button24->Size = System::Drawing::Size(138, 54);
            this->button24->TabIndex = 270;
            this->button24->Text = L"free";
            this->button24->UseVisualStyleBackColor = false;
            // 
            // button25
            // 
            this->button25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button25->Location = System::Drawing::Point(946, 1146);
            this->button25->Name = L"button25";
            this->button25->Size = System::Drawing::Size(138, 54);
            this->button25->TabIndex = 269;
            this->button25->Text = L"free";
            this->button25->UseVisualStyleBackColor = false;
            // 
            // button26
            // 
            this->button26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button26->Location = System::Drawing::Point(793, 1146);
            this->button26->Name = L"button26";
            this->button26->Size = System::Drawing::Size(138, 54);
            this->button26->TabIndex = 268;
            this->button26->Text = L"free";
            this->button26->UseVisualStyleBackColor = false;
            // 
            // button27
            // 
            this->button27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button27->Location = System::Drawing::Point(634, 1146);
            this->button27->Name = L"button27";
            this->button27->Size = System::Drawing::Size(138, 54);
            this->button27->TabIndex = 267;
            this->button27->Text = L"free";
            this->button27->UseVisualStyleBackColor = false;
            // 
            // button28
            // 
            this->button28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button28->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button28->Location = System::Drawing::Point(479, 1146);
            this->button28->Name = L"button28";
            this->button28->Size = System::Drawing::Size(138, 54);
            this->button28->TabIndex = 266;
            this->button28->Text = L"free";
            this->button28->UseVisualStyleBackColor = false;
            // 
            // button29
            // 
            this->button29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button29->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button29->Location = System::Drawing::Point(1105, 1085);
            this->button29->Name = L"button29";
            this->button29->Size = System::Drawing::Size(138, 55);
            this->button29->TabIndex = 264;
            this->button29->Text = L"free";
            this->button29->UseVisualStyleBackColor = false;
            // 
            // button30
            // 
            this->button30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button30->Location = System::Drawing::Point(946, 1085);
            this->button30->Name = L"button30";
            this->button30->Size = System::Drawing::Size(138, 55);
            this->button30->TabIndex = 263;
            this->button30->Text = L"free";
            this->button30->UseVisualStyleBackColor = false;
            // 
            // button31
            // 
            this->button31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button31->Location = System::Drawing::Point(793, 1085);
            this->button31->Name = L"button31";
            this->button31->Size = System::Drawing::Size(138, 55);
            this->button31->TabIndex = 262;
            this->button31->Text = L"free";
            this->button31->UseVisualStyleBackColor = false;
            // 
            // button32
            // 
            this->button32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button32->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button32->Location = System::Drawing::Point(634, 1085);
            this->button32->Name = L"button32";
            this->button32->Size = System::Drawing::Size(138, 55);
            this->button32->TabIndex = 261;
            this->button32->Text = L"free";
            this->button32->UseVisualStyleBackColor = false;
            // 
            // button33
            // 
            this->button33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button33->Location = System::Drawing::Point(479, 1085);
            this->button33->Name = L"button33";
            this->button33->Size = System::Drawing::Size(138, 55);
            this->button33->TabIndex = 260;
            this->button33->Text = L"free";
            this->button33->UseVisualStyleBackColor = false;
            // 
            // button34
            // 
            this->button34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button34->Location = System::Drawing::Point(1260, 1022);
            this->button34->Name = L"button34";
            this->button34->Size = System::Drawing::Size(138, 55);
            this->button34->TabIndex = 259;
            this->button34->Text = L"free";
            this->button34->UseVisualStyleBackColor = false;
            // 
            // button35
            // 
            this->button35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button35->Location = System::Drawing::Point(1105, 1023);
            this->button35->Name = L"button35";
            this->button35->Size = System::Drawing::Size(138, 55);
            this->button35->TabIndex = 258;
            this->button35->Text = L"free";
            this->button35->UseVisualStyleBackColor = false;
            // 
            // button36
            // 
            this->button36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button36->Location = System::Drawing::Point(946, 1022);
            this->button36->Name = L"button36";
            this->button36->Size = System::Drawing::Size(138, 55);
            this->button36->TabIndex = 257;
            this->button36->Text = L"free";
            this->button36->UseVisualStyleBackColor = false;
            // 
            // button39
            // 
            this->button39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button39->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button39->Location = System::Drawing::Point(793, 1023);
            this->button39->Name = L"button39";
            this->button39->Size = System::Drawing::Size(138, 55);
            this->button39->TabIndex = 256;
            this->button39->Text = L"free";
            this->button39->UseVisualStyleBackColor = false;
            // 
            // button40
            // 
            this->button40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button40->Location = System::Drawing::Point(634, 1023);
            this->button40->Name = L"button40";
            this->button40->Size = System::Drawing::Size(138, 55);
            this->button40->TabIndex = 255;
            this->button40->Text = L"free";
            this->button40->UseVisualStyleBackColor = false;
            // 
            // button41
            // 
            this->button41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button41->Location = System::Drawing::Point(479, 1022);
            this->button41->Name = L"button41";
            this->button41->Size = System::Drawing::Size(138, 55);
            this->button41->TabIndex = 254;
            this->button41->Text = L"free";
            this->button41->UseVisualStyleBackColor = false;
            // 
            // button42
            // 
            this->button42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button42->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button42->Location = System::Drawing::Point(1260, 965);
            this->button42->Name = L"button42";
            this->button42->Size = System::Drawing::Size(138, 55);
            this->button42->TabIndex = 253;
            this->button42->Text = L"free";
            this->button42->UseVisualStyleBackColor = false;
            // 
            // button43
            // 
            this->button43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button43->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button43->Location = System::Drawing::Point(1105, 962);
            this->button43->Name = L"button43";
            this->button43->Size = System::Drawing::Size(138, 55);
            this->button43->TabIndex = 252;
            this->button43->Text = L"free";
            this->button43->UseVisualStyleBackColor = false;
            // 
            // button44
            // 
            this->button44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button44->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button44->Location = System::Drawing::Point(946, 962);
            this->button44->Name = L"button44";
            this->button44->Size = System::Drawing::Size(138, 55);
            this->button44->TabIndex = 251;
            this->button44->Text = L"free";
            this->button44->UseVisualStyleBackColor = false;
            // 
            // button45
            // 
            this->button45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button45->Location = System::Drawing::Point(793, 962);
            this->button45->Name = L"button45";
            this->button45->Size = System::Drawing::Size(138, 55);
            this->button45->TabIndex = 250;
            this->button45->Text = L"free";
            this->button45->UseVisualStyleBackColor = false;
            // 
            // button46
            // 
            this->button46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button46->Location = System::Drawing::Point(634, 962);
            this->button46->Name = L"button46";
            this->button46->Size = System::Drawing::Size(138, 55);
            this->button46->TabIndex = 249;
            this->button46->Text = L"free";
            this->button46->UseVisualStyleBackColor = false;
            // 
            // button47
            // 
            this->button47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button47->Location = System::Drawing::Point(479, 962);
            this->button47->Name = L"button47";
            this->button47->Size = System::Drawing::Size(138, 55);
            this->button47->TabIndex = 248;
            this->button47->Text = L"free";
            this->button47->UseVisualStyleBackColor = false;
            // 
            // button48
            // 
            this->button48->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button48->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button48->Location = System::Drawing::Point(1260, 901);
            this->button48->Name = L"button48";
            this->button48->Size = System::Drawing::Size(138, 55);
            this->button48->TabIndex = 247;
            this->button48->Text = L"free";
            this->button48->UseVisualStyleBackColor = false;
            // 
            // button49
            // 
            this->button49->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button49->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button49->Location = System::Drawing::Point(1105, 901);
            this->button49->Name = L"button49";
            this->button49->Size = System::Drawing::Size(138, 55);
            this->button49->TabIndex = 246;
            this->button49->Text = L"free";
            this->button49->UseVisualStyleBackColor = false;
            // 
            // button50
            // 
            this->button50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button50->Location = System::Drawing::Point(946, 901);
            this->button50->Name = L"button50";
            this->button50->Size = System::Drawing::Size(138, 55);
            this->button50->TabIndex = 245;
            this->button50->Text = L"free";
            this->button50->UseVisualStyleBackColor = false;
            // 
            // button51
            // 
            this->button51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button51->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button51->Location = System::Drawing::Point(793, 901);
            this->button51->Name = L"button51";
            this->button51->Size = System::Drawing::Size(138, 55);
            this->button51->TabIndex = 244;
            this->button51->Text = L"free";
            this->button51->UseVisualStyleBackColor = false;
            // 
            // button52
            // 
            this->button52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button52->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button52->Location = System::Drawing::Point(634, 901);
            this->button52->Name = L"button52";
            this->button52->Size = System::Drawing::Size(138, 55);
            this->button52->TabIndex = 243;
            this->button52->Text = L"free";
            this->button52->UseVisualStyleBackColor = false;
            // 
            // button53
            // 
            this->button53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button53->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button53->Location = System::Drawing::Point(479, 901);
            this->button53->Name = L"button53";
            this->button53->Size = System::Drawing::Size(138, 55);
            this->button53->TabIndex = 242;
            this->button53->Text = L"free";
            this->button53->UseVisualStyleBackColor = false;
            // 
            // button54
            // 
            this->button54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button54->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button54->Location = System::Drawing::Point(1260, 841);
            this->button54->Name = L"button54";
            this->button54->Size = System::Drawing::Size(138, 55);
            this->button54->TabIndex = 241;
            this->button54->Text = L"free";
            this->button54->UseVisualStyleBackColor = false;
            // 
            // button55
            // 
            this->button55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button55->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button55->Location = System::Drawing::Point(1105, 841);
            this->button55->Name = L"button55";
            this->button55->Size = System::Drawing::Size(138, 55);
            this->button55->TabIndex = 240;
            this->button55->Text = L"free";
            this->button55->UseVisualStyleBackColor = false;
            // 
            // button56
            // 
            this->button56->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button56->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button56->Location = System::Drawing::Point(946, 841);
            this->button56->Name = L"button56";
            this->button56->Size = System::Drawing::Size(138, 55);
            this->button56->TabIndex = 239;
            this->button56->Text = L"free";
            this->button56->UseVisualStyleBackColor = false;
            // 
            // button57
            // 
            this->button57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button57->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button57->Location = System::Drawing::Point(793, 841);
            this->button57->Name = L"button57";
            this->button57->Size = System::Drawing::Size(138, 55);
            this->button57->TabIndex = 238;
            this->button57->Text = L"free";
            this->button57->UseVisualStyleBackColor = false;
            // 
            // button58
            // 
            this->button58->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button58->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button58->Location = System::Drawing::Point(634, 841);
            this->button58->Name = L"button58";
            this->button58->Size = System::Drawing::Size(138, 55);
            this->button58->TabIndex = 237;
            this->button58->Text = L"free";
            this->button58->UseVisualStyleBackColor = false;
            // 
            // button59
            // 
            this->button59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button59->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button59->Location = System::Drawing::Point(479, 841);
            this->button59->Name = L"button59";
            this->button59->Size = System::Drawing::Size(138, 55);
            this->button59->TabIndex = 236;
            this->button59->Text = L"free";
            this->button59->UseVisualStyleBackColor = false;
            // 
            // label103
            // 
            this->label103->AutoSize = true;
            this->label103->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label103->Location = System::Drawing::Point(334, 694);
            this->label103->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label103->Name = L"label103";
            this->label103->Size = System::Drawing::Size(161, 28);
            this->label103->TabIndex = 235;
            this->label103->Text = L"Teacher Schedule";
            // 
            // comboBox4
            // 
            this->comboBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->comboBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboBox4->FormattingEnabled = true;
            this->comboBox4->Location = System::Drawing::Point(338, 597);
            this->comboBox4->Name = L"comboBox4";
            this->comboBox4->Size = System::Drawing::Size(362, 36);
            this->comboBox4->TabIndex = 234;
            // 
            // label104
            // 
            this->label104->AutoSize = true;
            this->label104->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label104->Location = System::Drawing::Point(339, 552);
            this->label104->Name = L"label104";
            this->label104->Size = System::Drawing::Size(198, 28);
            this->label104->TabIndex = 233;
            this->label104->Text = L"Enter the department";
            // 
            // textBox20
            // 
            this->textBox20->AcceptsTab = true;
            this->textBox20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->textBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox20->ForeColor = System::Drawing::Color::Black;
            this->textBox20->Location = System::Drawing::Point(338, 471);
            this->textBox20->Name = L"textBox20";
            this->textBox20->Size = System::Drawing::Size(361, 27);
            this->textBox20->TabIndex = 232;
            // 
            // button60
            // 
            this->button60->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button60->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button60->Location = System::Drawing::Point(1277, 1275);
            this->button60->Name = L"button60";
            this->button60->Size = System::Drawing::Size(121, 45);
            this->button60->TabIndex = 273;
            this->button60->Text = L"Save";
            this->button60->UseVisualStyleBackColor = false;
            // 
            // button61
            // 
            this->button61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button61->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button61->Location = System::Drawing::Point(1260, 1085);
            this->button61->Name = L"button61";
            this->button61->Size = System::Drawing::Size(138, 55);
            this->button61->TabIndex = 265;
            this->button61->Text = L"free";
            this->button61->UseVisualStyleBackColor = false;
            // 
            // button62
            // 
            this->button62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button62->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button62->Location = System::Drawing::Point(1260, 1146);
            this->button62->Name = L"button62";
            this->button62->Size = System::Drawing::Size(138, 54);
            this->button62->TabIndex = 271;
            this->button62->Text = L"free";
            this->button62->UseVisualStyleBackColor = false;
            // 
            // label105
            // 
            this->label105->AutoSize = true;
            this->label105->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label105->Location = System::Drawing::Point(334, 425);
            this->label105->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label105->Name = L"label105";
            this->label105->Size = System::Drawing::Size(179, 28);
            this->label105->TabIndex = 231;
            this->label105->Text = L"Enter teacher name";
            // 
            // label106
            // 
            this->label106->AutoSize = true;
            this->label106->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label106->Location = System::Drawing::Point(1113, 779);
            this->label106->Name = L"label106";
            this->label106->Size = System::Drawing::Size(94, 28);
            this->label106->TabIndex = 283;
            this->label106->Text = L"2:30-3:30";
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(658, 285);
            this->richTextBox1->Multiline = false;
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(361, 30);
            this->richTextBox1->TabIndex = 1;
            this->richTextBox1->Text = L"";
            // 
            // label107
            // 
            this->label107->AutoSize = true;
            this->label107->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label107->Location = System::Drawing::Point(723, 224);
            this->label107->Name = L"label107";
            this->label107->Size = System::Drawing::Size(242, 30);
            this->label107->TabIndex = 0;
            this->label107->Text = L"Enter the teacher Name";
            // 
            // panel9
            // 
            this->panel9->AutoScroll = true;
            this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel9->Controls->Add(this->editsubjectsearchbutton);
            this->panel9->Controls->Add(this->editsubjectsearch);
            this->panel9->Controls->Add(this->label108);
            this->panel9->Controls->Add(this->panel7);
            this->panel9->Controls->Add(this->panel8);
            this->panel9->Controls->Add(this->button20);
            this->panel9->Controls->Add(this->textBox18);
            this->panel9->Controls->Add(this->editsubjectroom);
            this->panel9->Controls->Add(this->label83);
            this->panel9->Controls->Add(this->button21);
            this->panel9->Controls->Add(this->editsubjectbfactor);
            this->panel9->Controls->Add(this->editsubjectelename);
            this->panel9->Controls->Add(this->label84);
            this->panel9->Controls->Add(this->label85);
            this->panel9->Controls->Add(this->label86);
            this->panel9->Controls->Add(this->label87);
            this->panel9->Controls->Add(this->label88);
            this->panel9->Controls->Add(this->editsubjectname);
            this->panel9->Controls->Add(this->editsubjectcredit);
            this->panel9->Controls->Add(this->editsubjectlabteachers);
            this->panel9->Controls->Add(this->label89);
            this->panel9->Controls->Add(this->label91);
            this->panel9->Controls->Add(this->label90);
            this->panel9->Controls->Add(this->editsubjecteleteacher);
            this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel9->Location = System::Drawing::Point(0, 0);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(1946, 1106);
            this->panel9->TabIndex = 265;
            this->panel9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel9_Paint);
            // 
            // editsubjectsearchbutton
            // 
            this->editsubjectsearchbutton->Location = System::Drawing::Point(1031, 263);
            this->editsubjectsearchbutton->Name = L"editsubjectsearchbutton";
            this->editsubjectsearchbutton->Size = System::Drawing::Size(132, 30);
            this->editsubjectsearchbutton->TabIndex = 292;
            this->editsubjectsearchbutton->Text = L"search";
            this->editsubjectsearchbutton->UseVisualStyleBackColor = true;
            // 
            // editsubjectsearch
            // 
            this->editsubjectsearch->Location = System::Drawing::Point(659, 263);
            this->editsubjectsearch->Multiline = false;
            this->editsubjectsearch->Name = L"editsubjectsearch";
            this->editsubjectsearch->Size = System::Drawing::Size(361, 30);
            this->editsubjectsearch->TabIndex = 291;
            this->editsubjectsearch->Text = L"";
            // 
            // label108
            // 
            this->label108->AutoSize = true;
            this->label108->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label108->Location = System::Drawing::Point(724, 202);
            this->label108->Name = L"label108";
            this->label108->Size = System::Drawing::Size(241, 30);
            this->label108->TabIndex = 290;
            this->label108->Text = L"Enter the Subject Name";
            // 
            // panel7
            // 
            this->panel7->Controls->Add(this->editsubjecteleyes);
            this->panel7->Controls->Add(this->editsubjecteleno);
            this->panel7->ForeColor = System::Drawing::Color::Black;
            this->panel7->Location = System::Drawing::Point(402, 560);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(220, 56);
            this->panel7->TabIndex = 263;
            // 
            // editsubjecteleyes
            // 
            this->editsubjecteleyes->AutoSize = true;
            this->editsubjecteleyes->Location = System::Drawing::Point(5, 21);
            this->editsubjecteleyes->Name = L"editsubjecteleyes";
            this->editsubjecteleyes->Size = System::Drawing::Size(62, 24);
            this->editsubjecteleyes->TabIndex = 2;
            this->editsubjecteleyes->TabStop = true;
            this->editsubjecteleyes->Text = L"Yes";
            this->editsubjecteleyes->UseVisualStyleBackColor = true;
            // 
            // editsubjecteleno
            // 
            this->editsubjecteleno->AutoSize = true;
            this->editsubjecteleno->Location = System::Drawing::Point(139, 21);
            this->editsubjecteleno->Name = L"editsubjecteleno";
            this->editsubjecteleno->Size = System::Drawing::Size(54, 24);
            this->editsubjecteleno->TabIndex = 3;
            this->editsubjecteleno->TabStop = true;
            this->editsubjecteleno->Text = L"No";
            this->editsubjecteleno->UseVisualStyleBackColor = true;
            // 
            // panel8
            // 
            this->panel8->Controls->Add(this->editsubjectlabyes);
            this->panel8->Controls->Add(this->editsubjectlabno);
            this->panel8->ForeColor = System::Drawing::Color::Black;
            this->panel8->Location = System::Drawing::Point(411, 1145);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(219, 48);
            this->panel8->TabIndex = 262;
            // 
            // editsubjectlabyes
            // 
            this->editsubjectlabyes->AutoSize = true;
            this->editsubjectlabyes->Location = System::Drawing::Point(23, 14);
            this->editsubjectlabyes->Name = L"editsubjectlabyes";
            this->editsubjectlabyes->Size = System::Drawing::Size(62, 24);
            this->editsubjectlabyes->TabIndex = 10;
            this->editsubjectlabyes->TabStop = true;
            this->editsubjectlabyes->Text = L"Yes";
            this->editsubjectlabyes->UseVisualStyleBackColor = true;
            // 
            // editsubjectlabno
            // 
            this->editsubjectlabno->AutoSize = true;
            this->editsubjectlabno->Location = System::Drawing::Point(148, 14);
            this->editsubjectlabno->Name = L"editsubjectlabno";
            this->editsubjectlabno->Size = System::Drawing::Size(54, 24);
            this->editsubjectlabno->TabIndex = 11;
            this->editsubjectlabno->TabStop = true;
            this->editsubjectlabno->Text = L"No";
            this->editsubjectlabno->UseVisualStyleBackColor = true;
            // 
            // button20
            // 
            this->button20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button20->Location = System::Drawing::Point(1266, 2070);
            this->button20->Name = L"button20";
            this->button20->Size = System::Drawing::Size(116, 54);
            this->button20->TabIndex = 247;
            this->button20->Text = L" Add New";
            this->button20->UseVisualStyleBackColor = false;
            // 
            // textBox18
            // 
            this->textBox18->Location = System::Drawing::Point(1019, 510);
            this->textBox18->Name = L"textBox18";
            this->textBox18->Size = System::Drawing::Size(154, 26);
            this->textBox18->TabIndex = 248;
            // 
            // editsubjectroom
            // 
            this->editsubjectroom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjectroom->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubjectroom->CheckOnClick = true;
            this->editsubjectroom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectroom->FormattingEnabled = true;
            this->editsubjectroom->Location = System::Drawing::Point(426, 1699);
            this->editsubjectroom->Name = L"editsubjectroom";
            this->editsubjectroom->Size = System::Drawing::Size(224, 186);
            this->editsubjectroom->Sorted = true;
            this->editsubjectroom->TabIndex = 246;
            this->editsubjectroom->ThreeDCheckBoxes = true;
            // 
            // label83
            // 
            this->label83->AutoSize = true;
            this->label83->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label83->Location = System::Drawing::Point(373, 817);
            this->label83->Name = L"label83";
            this->label83->Size = System::Drawing::Size(330, 28);
            this->label83->TabIndex = 235;
            this->label83->Text = L"Teacher handling the elective subject";
            // 
            // button21
            // 
            this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button21->Location = System::Drawing::Point(1047, 2070);
            this->button21->Name = L"button21";
            this->button21->Size = System::Drawing::Size(116, 54);
            this->button21->TabIndex = 245;
            this->button21->Text = L"Save";
            this->button21->UseVisualStyleBackColor = false;
            // 
            // editsubjectbfactor
            // 
            this->editsubjectbfactor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->editsubjectbfactor->DecimalPlaces = 2;
            this->editsubjectbfactor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectbfactor->Location = System::Drawing::Point(425, 1951);
            this->editsubjectbfactor->Name = L"editsubjectbfactor";
            this->editsubjectbfactor->Size = System::Drawing::Size(170, 34);
            this->editsubjectbfactor->TabIndex = 244;
            // 
            // editsubjectelename
            // 
            this->editsubjectelename->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubjectelename->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectelename->ForeColor = System::Drawing::Color::Black;
            this->editsubjectelename->Location = System::Drawing::Point(378, 713);
            this->editsubjectelename->Name = L"editsubjectelename";
            this->editsubjectelename->Size = System::Drawing::Size(482, 34);
            this->editsubjectelename->TabIndex = 25;
            // 
            // label84
            // 
            this->label84->AutoSize = true;
            this->label84->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label84->Location = System::Drawing::Point(417, 1653);
            this->label84->Name = L"label84";
            this->label84->Size = System::Drawing::Size(255, 28);
            this->label84->TabIndex = 242;
            this->label84->Text = L"Rooms to be used(optional)";
            // 
            // label85
            // 
            this->label85->AutoSize = true;
            this->label85->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label85->Location = System::Drawing::Point(374, 659);
            this->label85->Name = L"label85";
            this->label85->Size = System::Drawing::Size(158, 28);
            this->label85->TabIndex = 24;
            this->label85->Text = L"Name of elective";
            // 
            // label86
            // 
            this->label86->AutoSize = true;
            this->label86->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label86->Location = System::Drawing::Point(434, 1897);
            this->label86->Name = L"label86";
            this->label86->Size = System::Drawing::Size(75, 28);
            this->label86->TabIndex = 243;
            this->label86->Text = L"bfactor";
            // 
            // label87
            // 
            this->label87->AutoSize = true;
            this->label87->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label87->Location = System::Drawing::Point(374, 508);
            this->label87->Name = L"label87";
            this->label87->Size = System::Drawing::Size(148, 28);
            this->label87->TabIndex = 23;
            this->label87->Text = L"Is it an elective\?";
            // 
            // label88
            // 
            this->label88->AutoSize = true;
            this->label88->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label88->Location = System::Drawing::Point(423, 1525);
            this->label88->Name = L"label88";
            this->label88->Size = System::Drawing::Size(125, 28);
            this->label88->TabIndex = 241;
            this->label88->Text = L"No of credits";
            // 
            // editsubjectname
            // 
            this->editsubjectname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubjectname->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectname->ForeColor = System::Drawing::Color::Black;
            this->editsubjectname->Location = System::Drawing::Point(385, 421);
            this->editsubjectname->Name = L"editsubjectname";
            this->editsubjectname->Size = System::Drawing::Size(480, 34);
            this->editsubjectname->TabIndex = 3;
            // 
            // editsubjectcredit
            // 
            this->editsubjectcredit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->editsubjectcredit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubjectcredit->Location = System::Drawing::Point(426, 1569);
            this->editsubjectcredit->Name = L"editsubjectcredit";
            this->editsubjectcredit->Size = System::Drawing::Size(170, 34);
            this->editsubjectcredit->TabIndex = 240;
            // 
            // editsubjectlabteachers
            // 
            this->editsubjectlabteachers->AllowUserToOrderColumns = true;
            dataGridViewCellStyle44->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle44->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle44->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle44->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubjectlabteachers->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle44;
            this->editsubjectlabteachers->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjectlabteachers->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubjectlabteachers->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsubjectlabteachers->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle45->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle45->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle45->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle45->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubjectlabteachers->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle45;
            this->editsubjectlabteachers->ColumnHeadersHeight = 40;
            this->editsubjectlabteachers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsubjectlabteachers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn1,
                    this->dataGridViewButtonColumn7
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
            this->editsubjectlabteachers->DefaultCellStyle = dataGridViewCellStyle48;
            this->editsubjectlabteachers->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjectlabteachers->Location = System::Drawing::Point(428, 1277);
            this->editsubjectlabteachers->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsubjectlabteachers->Name = L"editsubjectlabteachers";
            dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle49->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle49->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle49->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle49->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle49->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubjectlabteachers->RowHeadersDefaultCellStyle = dataGridViewCellStyle49;
            this->editsubjectlabteachers->RowHeadersVisible = false;
            this->editsubjectlabteachers->RowHeadersWidth = 62;
            dataGridViewCellStyle50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle50->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle50->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle50->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubjectlabteachers->RowsDefaultCellStyle = dataGridViewCellStyle50;
            this->editsubjectlabteachers->RowTemplate->Height = 28;
            this->editsubjectlabteachers->Size = System::Drawing::Size(735, 226);
            this->editsubjectlabteachers->TabIndex = 239;
            // 
            // dataGridViewComboBoxColumn1
            // 
            dataGridViewCellStyle46->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle46->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle46->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle46->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->DefaultCellStyle = dataGridViewCellStyle46;
            this->dataGridViewComboBoxColumn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn1->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn1->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn1->Name = L"dataGridViewComboBoxColumn1";
            this->dataGridViewComboBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
            this->dataGridViewComboBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn7
            // 
            this->dataGridViewButtonColumn7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle47->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn7->DefaultCellStyle = dataGridViewCellStyle47;
            this->dataGridViewButtonColumn7->DividerWidth = 1;
            this->dataGridViewButtonColumn7->HeaderText = L"";
            this->dataGridViewButtonColumn7->MinimumWidth = 100;
            this->dataGridViewButtonColumn7->Name = L"dataGridViewButtonColumn7";
            this->dataGridViewButtonColumn7->ReadOnly = true;
            this->dataGridViewButtonColumn7->Text = L"Delete";
            this->dataGridViewButtonColumn7->UseColumnTextForButtonValue = true;
            // 
            // label89
            // 
            this->label89->AutoSize = true;
            this->label89->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label89->Location = System::Drawing::Point(392, 1237);
            this->label89->Name = L"label89";
            this->label89->Size = System::Drawing::Size(299, 28);
            this->label89->TabIndex = 238;
            this->label89->Text = L"Teachers handling the lab subject";
            // 
            // label91
            // 
            this->label91->AutoSize = true;
            this->label91->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label91->Location = System::Drawing::Point(391, 1100);
            this->label91->Name = L"label91";
            this->label91->Size = System::Drawing::Size(98, 28);
            this->label91->TabIndex = 236;
            this->label91->Text = L"Is it a lab\?";
            // 
            // label90
            // 
            this->label90->AutoSize = true;
            this->label90->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label90->ForeColor = System::Drawing::Color::Black;
            this->label90->Location = System::Drawing::Point(380, 371);
            this->label90->Name = L"label90";
            this->label90->Size = System::Drawing::Size(134, 28);
            this->label90->TabIndex = 2;
            this->label90->Text = L"Subject Name";
            // 
            // editsubjecteleteacher
            // 
            this->editsubjecteleteacher->AllowUserToOrderColumns = true;
            dataGridViewCellStyle51->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle51->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle51->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle51->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubjecteleteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
            this->editsubjecteleteacher->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjecteleteacher->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubjecteleteacher->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsubjecteleteacher->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle52->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle52->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle52->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubjecteleteacher->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
            this->editsubjecteleteacher->ColumnHeadersHeight = 40;
            this->editsubjecteleteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsubjecteleteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewComboBoxColumn2,
                    this->dataGridViewButtonColumn9
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
            this->editsubjecteleteacher->DefaultCellStyle = dataGridViewCellStyle55;
            this->editsubjecteleteacher->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubjecteleteacher->Location = System::Drawing::Point(390, 871);
            this->editsubjecteleteacher->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsubjecteleteacher->Name = L"editsubjecteleteacher";
            dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle56->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle56->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle56->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle56->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle56->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubjecteleteacher->RowHeadersDefaultCellStyle = dataGridViewCellStyle56;
            this->editsubjecteleteacher->RowHeadersVisible = false;
            this->editsubjecteleteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle57->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle57->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle57->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubjecteleteacher->RowsDefaultCellStyle = dataGridViewCellStyle57;
            this->editsubjecteleteacher->RowTemplate->Height = 28;
            this->editsubjecteleteacher->Size = System::Drawing::Size(735, 226);
            this->editsubjecteleteacher->TabIndex = 234;
            // 
            // dataGridViewComboBoxColumn2
            // 
            dataGridViewCellStyle53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle53->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle53->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle53->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn2->DefaultCellStyle = dataGridViewCellStyle53;
            this->dataGridViewComboBoxColumn2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->dataGridViewComboBoxColumn2->HeaderText = L"Teacher Name";
            this->dataGridViewComboBoxColumn2->MinimumWidth = 30;
            this->dataGridViewComboBoxColumn2->Name = L"dataGridViewComboBoxColumn2";
            this->dataGridViewComboBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewComboBoxColumn2->Width = 350;
            // 
            // dataGridViewButtonColumn9
            // 
            this->dataGridViewButtonColumn9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle54->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn9->DefaultCellStyle = dataGridViewCellStyle54;
            this->dataGridViewButtonColumn9->DividerWidth = 1;
            this->dataGridViewButtonColumn9->HeaderText = L"";
            this->dataGridViewButtonColumn9->MinimumWidth = 100;
            this->dataGridViewButtonColumn9->Name = L"dataGridViewButtonColumn9";
            this->dataGridViewButtonColumn9->ReadOnly = true;
            this->dataGridViewButtonColumn9->Text = L"Delete";
            this->dataGridViewButtonColumn9->UseColumnTextForButtonValue = true;
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
            this->addteacherpanel->Controls->Add(this->addteacherdepartment);
            this->addteacherpanel->Controls->Add(this->label2);
            this->addteacherpanel->Controls->Add(this->addteachername);
            this->addteacherpanel->Controls->Add(this->addteachersave);
            this->addteacherpanel->Controls->Add(this->addteachernew);
            this->addteacherpanel->Controls->Add(this->buttons30);
            this->addteacherpanel->Controls->Add(this->buttons36);
            this->addteacherpanel->Controls->Add(this->label1);
            this->addteacherpanel->Controls->Add(this->label14);
            this->addteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addteacherpanel->Location = System::Drawing::Point(0, 0);
            this->addteacherpanel->Name = L"addteacherpanel";
            this->addteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->addteacherpanel->TabIndex = 293;
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(1266, 502);
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
            this->label40->Location = System::Drawing::Point(955, 501);
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
            this->label12->Location = System::Drawing::Point(777, 501);
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
            this->label11->Location = System::Drawing::Point(637, 501);
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
            this->label4->Location = System::Drawing::Point(496, 501);
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
            this->label10->Location = System::Drawing::Point(341, 628);
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
            this->label9->Location = System::Drawing::Point(327, 697);
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
            this->label8->Location = System::Drawing::Point(337, 758);
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
            this->label7->Location = System::Drawing::Point(358, 820);
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
            this->label6->Location = System::Drawing::Point(344, 875);
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
            this->label5->Location = System::Drawing::Point(341, 571);
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
            this->buttons35->Location = System::Drawing::Point(1104, 868);
            this->buttons35->Name = L"buttons35";
            this->buttons35->Size = System::Drawing::Size(138, 54);
            this->buttons35->TabIndex = 270;
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
            this->buttons34->Location = System::Drawing::Point(945, 868);
            this->buttons34->Name = L"buttons34";
            this->buttons34->Size = System::Drawing::Size(138, 54);
            this->buttons34->TabIndex = 269;
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
            this->buttons33->Location = System::Drawing::Point(792, 868);
            this->buttons33->Name = L"buttons33";
            this->buttons33->Size = System::Drawing::Size(138, 54);
            this->buttons33->TabIndex = 268;
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
            this->buttons32->Location = System::Drawing::Point(633, 868);
            this->buttons32->Name = L"buttons32";
            this->buttons32->Size = System::Drawing::Size(138, 54);
            this->buttons32->TabIndex = 267;
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
            this->buttons31->Location = System::Drawing::Point(478, 868);
            this->buttons31->Name = L"buttons31";
            this->buttons31->Size = System::Drawing::Size(138, 54);
            this->buttons31->TabIndex = 266;
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
            this->buttons29->Location = System::Drawing::Point(1104, 807);
            this->buttons29->Name = L"buttons29";
            this->buttons29->Size = System::Drawing::Size(138, 55);
            this->buttons29->TabIndex = 264;
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
            this->buttons28->Location = System::Drawing::Point(945, 807);
            this->buttons28->Name = L"buttons28";
            this->buttons28->Size = System::Drawing::Size(138, 55);
            this->buttons28->TabIndex = 263;
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
            this->buttons27->Location = System::Drawing::Point(792, 807);
            this->buttons27->Name = L"buttons27";
            this->buttons27->Size = System::Drawing::Size(138, 55);
            this->buttons27->TabIndex = 262;
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
            this->buttons26->Location = System::Drawing::Point(633, 807);
            this->buttons26->Name = L"buttons26";
            this->buttons26->Size = System::Drawing::Size(138, 55);
            this->buttons26->TabIndex = 261;
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
            this->buttons25->Location = System::Drawing::Point(478, 807);
            this->buttons25->Name = L"buttons25";
            this->buttons25->Size = System::Drawing::Size(138, 55);
            this->buttons25->TabIndex = 260;
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
            this->buttons24->Location = System::Drawing::Point(1259, 744);
            this->buttons24->Name = L"buttons24";
            this->buttons24->Size = System::Drawing::Size(138, 55);
            this->buttons24->TabIndex = 259;
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
            this->buttons23->Location = System::Drawing::Point(1104, 745);
            this->buttons23->Name = L"buttons23";
            this->buttons23->Size = System::Drawing::Size(138, 55);
            this->buttons23->TabIndex = 258;
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
            this->buttons22->Location = System::Drawing::Point(945, 744);
            this->buttons22->Name = L"buttons22";
            this->buttons22->Size = System::Drawing::Size(138, 55);
            this->buttons22->TabIndex = 257;
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
            this->buttons21->Location = System::Drawing::Point(792, 745);
            this->buttons21->Name = L"buttons21";
            this->buttons21->Size = System::Drawing::Size(138, 55);
            this->buttons21->TabIndex = 256;
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
            this->buttons20->Location = System::Drawing::Point(633, 745);
            this->buttons20->Name = L"buttons20";
            this->buttons20->Size = System::Drawing::Size(138, 55);
            this->buttons20->TabIndex = 255;
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
            this->buttons19->Location = System::Drawing::Point(478, 744);
            this->buttons19->Name = L"buttons19";
            this->buttons19->Size = System::Drawing::Size(138, 55);
            this->buttons19->TabIndex = 254;
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
            this->buttons18->Location = System::Drawing::Point(1259, 687);
            this->buttons18->Name = L"buttons18";
            this->buttons18->Size = System::Drawing::Size(138, 55);
            this->buttons18->TabIndex = 253;
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
            this->buttons17->Location = System::Drawing::Point(1104, 684);
            this->buttons17->Name = L"buttons17";
            this->buttons17->Size = System::Drawing::Size(138, 55);
            this->buttons17->TabIndex = 252;
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
            this->buttons16->Location = System::Drawing::Point(945, 684);
            this->buttons16->Name = L"buttons16";
            this->buttons16->Size = System::Drawing::Size(138, 55);
            this->buttons16->TabIndex = 251;
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
            this->buttons15->Location = System::Drawing::Point(792, 684);
            this->buttons15->Name = L"buttons15";
            this->buttons15->Size = System::Drawing::Size(138, 55);
            this->buttons15->TabIndex = 250;
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
            this->buttons14->Location = System::Drawing::Point(633, 684);
            this->buttons14->Name = L"buttons14";
            this->buttons14->Size = System::Drawing::Size(138, 55);
            this->buttons14->TabIndex = 249;
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
            this->buttons13->Location = System::Drawing::Point(478, 684);
            this->buttons13->Name = L"buttons13";
            this->buttons13->Size = System::Drawing::Size(138, 55);
            this->buttons13->TabIndex = 248;
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
            this->buttons12->Location = System::Drawing::Point(1259, 623);
            this->buttons12->Name = L"buttons12";
            this->buttons12->Size = System::Drawing::Size(138, 55);
            this->buttons12->TabIndex = 247;
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
            this->buttons11->Location = System::Drawing::Point(1104, 623);
            this->buttons11->Name = L"buttons11";
            this->buttons11->Size = System::Drawing::Size(138, 55);
            this->buttons11->TabIndex = 246;
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
            this->buttons10->Location = System::Drawing::Point(945, 623);
            this->buttons10->Name = L"buttons10";
            this->buttons10->Size = System::Drawing::Size(138, 55);
            this->buttons10->TabIndex = 245;
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
            this->buttons9->Location = System::Drawing::Point(792, 623);
            this->buttons9->Name = L"buttons9";
            this->buttons9->Size = System::Drawing::Size(138, 55);
            this->buttons9->TabIndex = 244;
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
            this->buttons8->Location = System::Drawing::Point(633, 623);
            this->buttons8->Name = L"buttons8";
            this->buttons8->Size = System::Drawing::Size(138, 55);
            this->buttons8->TabIndex = 243;
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
            this->buttons7->Location = System::Drawing::Point(478, 623);
            this->buttons7->Name = L"buttons7";
            this->buttons7->Size = System::Drawing::Size(138, 55);
            this->buttons7->TabIndex = 242;
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
            this->buttons6->Location = System::Drawing::Point(1259, 563);
            this->buttons6->Name = L"buttons6";
            this->buttons6->Size = System::Drawing::Size(138, 55);
            this->buttons6->TabIndex = 241;
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
            this->buttons5->Location = System::Drawing::Point(1104, 563);
            this->buttons5->Name = L"buttons5";
            this->buttons5->Size = System::Drawing::Size(138, 55);
            this->buttons5->TabIndex = 240;
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
            this->buttons4->Location = System::Drawing::Point(945, 563);
            this->buttons4->Name = L"buttons4";
            this->buttons4->Size = System::Drawing::Size(138, 55);
            this->buttons4->TabIndex = 239;
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
            this->buttons3->Location = System::Drawing::Point(792, 563);
            this->buttons3->Name = L"buttons3";
            this->buttons3->Size = System::Drawing::Size(138, 55);
            this->buttons3->TabIndex = 238;
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
            this->buttons2->Location = System::Drawing::Point(633, 563);
            this->buttons2->Name = L"buttons2";
            this->buttons2->Size = System::Drawing::Size(138, 55);
            this->buttons2->TabIndex = 237;
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
            this->buttons1->Location = System::Drawing::Point(478, 563);
            this->buttons1->Name = L"buttons1";
            this->buttons1->Size = System::Drawing::Size(138, 55);
            this->buttons1->TabIndex = 236;
            this->buttons1->Text = L"free";
            this->buttons1->UseVisualStyleBackColor = false;
            this->buttons1->Click += gcnew System::EventHandler(this, &MyForm::buttons1_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(333, 416);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(161, 28);
            this->label3->TabIndex = 235;
            this->label3->Text = L"Teacher Schedule";
            // 
            // addteacherdepartment
            // 
            this->addteacherdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteacherdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteacherdepartment->FormattingEnabled = true;
            this->addteacherdepartment->Location = System::Drawing::Point(337, 319);
            this->addteacherdepartment->Name = L"addteacherdepartment";
            this->addteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->addteacherdepartment->TabIndex = 234;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(338, 274);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(198, 28);
            this->label2->TabIndex = 233;
            this->label2->Text = L"Enter the department";
            // 
            // addteachername
            // 
            this->addteachername->AcceptsTab = true;
            this->addteachername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachername->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addteachername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachername->ForeColor = System::Drawing::Color::Black;
            this->addteachername->Location = System::Drawing::Point(337, 193);
            this->addteachername->Name = L"addteachername";
            this->addteachername->Size = System::Drawing::Size(361, 27);
            this->addteachername->TabIndex = 232;
            // 
            // addteachersave
            // 
            this->addteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachersave->Location = System::Drawing::Point(1037, 997);
            this->addteachersave->Name = L"addteachersave";
            this->addteachersave->Size = System::Drawing::Size(121, 45);
            this->addteachersave->TabIndex = 273;
            this->addteachersave->Text = L"Save";
            this->addteachersave->UseVisualStyleBackColor = false;
            this->addteachersave->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
            // 
            // addteachernew
            // 
            this->addteachernew->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachernew->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachernew->Location = System::Drawing::Point(1207, 997);
            this->addteachernew->Name = L"addteachernew";
            this->addteachernew->Size = System::Drawing::Size(121, 45);
            this->addteachernew->TabIndex = 272;
            this->addteachernew->Text = L"Add New";
            this->addteachernew->UseVisualStyleBackColor = false;
            this->addteachernew->Click += gcnew System::EventHandler(this, &MyForm::addteachernew_Click);
            // 
            // buttons30
            // 
            this->buttons30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->buttons30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttons30->Location = System::Drawing::Point(1259, 807);
            this->buttons30->Name = L"buttons30";
            this->buttons30->Size = System::Drawing::Size(138, 55);
            this->buttons30->TabIndex = 265;
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
            this->buttons36->Location = System::Drawing::Point(1259, 868);
            this->buttons36->Name = L"buttons36";
            this->buttons36->Size = System::Drawing::Size(138, 54);
            this->buttons36->TabIndex = 271;
            this->buttons36->Text = L"free";
            this->buttons36->UseVisualStyleBackColor = false;
            this->buttons36->Click += gcnew System::EventHandler(this, &MyForm::buttons36_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(333, 147);
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
            this->label14->Location = System::Drawing::Point(1112, 501);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(94, 28);
            this->label14->TabIndex = 283;
            this->label14->Text = L"2:30-3:30";
            // 
            // settingspanel
            // 
            this->settingspanel->AutoScroll = true;
            this->settingspanel->Controls->Add(this->label112);
            this->settingspanel->Controls->Add(this->trackBar2);
            this->settingspanel->Controls->Add(this->label111);
            this->settingspanel->Controls->Add(this->trackBar1);
            this->settingspanel->Controls->Add(this->label110);
            this->settingspanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->settingspanel->Location = System::Drawing::Point(0, 0);
            this->settingspanel->Name = L"settingspanel";
            this->settingspanel->Size = System::Drawing::Size(1946, 1106);
            this->settingspanel->TabIndex = 286;
            // 
            // label112
            // 
            this->label112->AutoSize = true;
            this->label112->Location = System::Drawing::Point(568, 593);
            this->label112->Name = L"label112";
            this->label112->Size = System::Drawing::Size(152, 20);
            this->label112->TabIndex = 4;
            this->label112->Text = L"TimeTable Structure";
            // 
            // trackBar2
            // 
            this->trackBar2->Location = System::Drawing::Point(556, 429);
            this->trackBar2->Maximum = 7;
            this->trackBar2->Minimum = 1;
            this->trackBar2->Name = L"trackBar2";
            this->trackBar2->Size = System::Drawing::Size(442, 69);
            this->trackBar2->TabIndex = 3;
            this->trackBar2->Value = 1;
            // 
            // label111
            // 
            this->label111->AutoSize = true;
            this->label111->Location = System::Drawing::Point(568, 386);
            this->label111->Name = L"label111";
            this->label111->Size = System::Drawing::Size(265, 20);
            this->label111->TabIndex = 2;
            this->label111->Text = L"Maximum number of classes per day";
            // 
            // trackBar1
            // 
            this->trackBar1->Location = System::Drawing::Point(550, 275);
            this->trackBar1->Maximum = 7;
            this->trackBar1->Minimum = 1;
            this->trackBar1->Name = L"trackBar1";
            this->trackBar1->Size = System::Drawing::Size(442, 69);
            this->trackBar1->TabIndex = 1;
            this->trackBar1->Value = 1;
            // 
            // label110
            // 
            this->label110->AutoSize = true;
            this->label110->Location = System::Drawing::Point(562, 232);
            this->label110->Name = L"label110";
            this->label110->Size = System::Drawing::Size(247, 20);
            this->label110->TabIndex = 0;
            this->label110->Text = L"Maximum number of working days";
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
            this->button1->Location = System::Drawing::Point(0, 199);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(324, 40);
            this->button1->TabIndex = 2;
            this->button1->Text = L"               Departments";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_MouseEnter);
            this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::button1_MouseLeave);
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
            this->button6->Location = System::Drawing::Point(58, 299);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(269, 40);
            this->button6->TabIndex = 12;
            this->button6->Text = L"Classrooms";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
            this->button6->MouseEnter += gcnew System::EventHandler(this, &MyForm::button6_MouseEnter);
            this->button6->MouseLeave += gcnew System::EventHandler(this, &MyForm::button6_MouseLeave);
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
            this->button9->Location = System::Drawing::Point(58, 405);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(271, 40);
            this->button9->TabIndex = 12;
            this->button9->Text = L"Teachers";
            this->button9->UseVisualStyleBackColor = false;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
            this->button9->MouseEnter += gcnew System::EventHandler(this, &MyForm::button9_MouseEnter);
            this->button9->MouseLeave += gcnew System::EventHandler(this, &MyForm::button9_MouseLeave);
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button5->FlatAppearance->BorderSize = 0;
            this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button5->ForeColor = System::Drawing::Color::White;
            this->button5->Location = System::Drawing::Point(21, 342);
            this->button5->Margin = System::Windows::Forms::Padding(0);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(306, 30);
            this->button5->TabIndex = 13;
            this->button5->Text = L"Add                 ";
            this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button8->Location = System::Drawing::Point(21, 449);
            this->button8->Margin = System::Windows::Forms::Padding(0);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(306, 30);
            this->button8->TabIndex = 13;
            this->button8->Text = L"Add                 ";
            this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button4->Location = System::Drawing::Point(21, 372);
            this->button4->Margin = System::Windows::Forms::Padding(0);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(306, 30);
            this->button4->TabIndex = 14;
            this->button4->Text = L"Edit                 ";
            this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button7->Location = System::Drawing::Point(18, 473);
            this->button7->Margin = System::Windows::Forms::Padding(0);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(309, 30);
            this->button7->TabIndex = 14;
            this->button7->Text = L"Edit                 ";
            this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button12->ForeColor = System::Drawing::Color::White;
            this->button12->Location = System::Drawing::Point(84, 511);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(246, 40);
            this->button12->TabIndex = 17;
            this->button12->Text = L"Subjects";
            this->button12->UseVisualStyleBackColor = false;
            this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
            this->button12->MouseEnter += gcnew System::EventHandler(this, &MyForm::button12_MouseEnter);
            this->button12->MouseLeave += gcnew System::EventHandler(this, &MyForm::button12_MouseLeave);
            // 
            // button11
            // 
            this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            this->button11->FlatAppearance->BorderSize = 0;
            this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button11->ForeColor = System::Drawing::Color::White;
            this->button11->Location = System::Drawing::Point(24, 557);
            this->button11->Margin = System::Windows::Forms::Padding(0);
            this->button11->Name = L"button11";
            this->button11->Size = System::Drawing::Size(305, 30);
            this->button11->TabIndex = 18;
            this->button11->Text = L"Add                 ";
            this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button10->Location = System::Drawing::Point(24, 587);
            this->button10->Margin = System::Windows::Forms::Padding(0);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(303, 30);
            this->button10->TabIndex = 19;
            this->button10->Text = L"Edit                 ";
            this->button10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button15->ForeColor = System::Drawing::Color::White;
            this->button15->Location = System::Drawing::Point(60, 611);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(267, 40);
            this->button15->TabIndex = 22;
            this->button15->Text = L"Classes";
            this->button15->UseVisualStyleBackColor = false;
            this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
            this->button15->MouseEnter += gcnew System::EventHandler(this, &MyForm::button15_MouseEnter);
            this->button15->MouseLeave += gcnew System::EventHandler(this, &MyForm::button15_MouseLeave);
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
            this->Homebutton1->Location = System::Drawing::Point(3, 84);
            this->Homebutton1->Name = L"Homebutton1";
            this->Homebutton1->Size = System::Drawing::Size(321, 40);
            this->Homebutton1->TabIndex = 26;
            this->Homebutton1->Text = L"    Home";
            this->Homebutton1->UseVisualStyleBackColor = false;
            this->Homebutton1->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            this->Homebutton1->MouseEnter += gcnew System::EventHandler(this, &MyForm::Homebutton1_MouseEnter);
            this->Homebutton1->MouseLeave += gcnew System::EventHandler(this, &MyForm::Homebutton1_MouseLeave);
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
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(68, 84);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(43, 40);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 6;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(68, 194);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(35, 40);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(68, 299);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(35, 40);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(68, 397);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(35, 40);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(68, 511);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(35, 40);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(68, 611);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(35, 40);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox7->TabIndex = 31;
            this->pictureBox7->TabStop = false;
            // 
            // textBox4
            // 
            this->textBox4->AutoSize = true;
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox4->Location = System::Drawing::Point(279, 308);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(28, 26);
            this->textBox4->TabIndex = 8;
            this->textBox4->Text = L"◤";
            // 
            // textBox5
            // 
            this->textBox5->AutoSize = true;
            this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox5->Location = System::Drawing::Point(279, 309);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(28, 26);
            this->textBox5->TabIndex = 7;
            this->textBox5->Text = L"◢";
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
            // textBox8
            // 
            this->textBox8->AutoSize = true;
            this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox8->Location = System::Drawing::Point(273, 519);
            this->textBox8->Name = L"textBox8";
            this->textBox8->Size = System::Drawing::Size(28, 26);
            this->textBox8->TabIndex = 33;
            this->textBox8->Text = L"◤";
            // 
            // textBox6
            // 
            this->textBox6->AutoSize = true;
            this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox6->Location = System::Drawing::Point(279, 413);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(28, 26);
            this->textBox6->TabIndex = 34;
            this->textBox6->Text = L"◤";
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
            // textBox9
            // 
            this->textBox9->AutoSize = true;
            this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox9->Location = System::Drawing::Point(272, 517);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(28, 26);
            this->textBox9->TabIndex = 36;
            this->textBox9->Text = L"◢";
            // 
            // textBox7
            // 
            this->textBox7->AutoSize = true;
            this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
            this->textBox7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->textBox7->Location = System::Drawing::Point(272, 413);
            this->textBox7->Name = L"textBox7";
            this->textBox7->Size = System::Drawing::Size(28, 26);
            this->textBox7->TabIndex = 37;
            this->textBox7->Text = L"◢";
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
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(1946, 1106);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->panel4);
            this->Controls->Add(this->editroompanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->Homepanel);
            this->Controls->Add(this->panel5);
            this->Controls->Add(this->editteacherpanel);
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->settingspanel);
            this->Controls->Add(this->addteacherpanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->KeyPreview = true;
            this->Name = L"MyForm";
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            this->editteacherpanel->ResumeLayout(false);
            this->editteacherpanel->PerformLayout();
            this->editroompanel->ResumeLayout(false);
            this->editroompanel->PerformLayout();
            this->panel6->ResumeLayout(false);
            this->panel6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->EndInit();
            this->editsubjectpanel->ResumeLayout(false);
            this->panel10->ResumeLayout(false);
            this->panel10->PerformLayout();
            this->panel9->ResumeLayout(false);
            this->panel9->PerformLayout();
            this->panel7->ResumeLayout(false);
            this->panel7->PerformLayout();
            this->panel8->ResumeLayout(false);
            this->panel8->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectbfactor))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectcredit))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjectlabteachers))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubjecteleteacher))->EndInit();
            this->addteacherpanel->ResumeLayout(false);
            this->addteacherpanel->PerformLayout();
            this->settingspanel->ResumeLayout(false);
            this->settingspanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
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
    
       pictureBox12->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
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
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button6->Height;
    panel3->Top = button6->Top;
    addclassroompanel->BringToFront();
    DisplayCSVInComboBox1("details/dept_file.csv", comboBox2);
    button5->BackColor = Color::FromArgb(0, 0, 90);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    panel3->Height = button6->Height;
    panel3->Top = button6->Top;
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
    DisplayCSVInComboBox1("details/dept_file.csv",addteacherdepartment);
    button8->BackColor = Color::FromArgb(0, 0, 90);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
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
            button->BackColor = Color::FromArgb(179, 255, 230);
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
    button11->BackColor = Color::FromArgb(0, 0, 90);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
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
    csubject->DataSource = CreateDataTableFromCSV3("details/subject_file.csv");
    csubject->DisplayMember = "csubject"; // Update to the correct column name
    csubject->ValueMember = "csubject";
    cteacher->DataSource = CreateDataTableFromCSV4("details/teacher_file.csv");
    cteacher->DisplayMember = "cteacher"; // Update to the correct column name
    cteacher->ValueMember = "cteacher";
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
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
   //section obj;
   // obj.name=10;
   // allteachersfunction("details/teacher_file.csv", obj);
   // allroomsfunction("details/classroom.csv",obj);
   // //alloting core teacher and subjects
   // loadcore(obj);
   // //alloting default rooms
   // defaultroomallot(obj);
   // labcreate("details/Labo.csv", obj);

   // obj.makeTIMETABLE();
   // ofstream file;
   // file.open("details/timetable.csv");
   // string output;
   // for (int i = 0; i < days; i++)
   // {
   //     for (int j = 0; j < periods; j++)
   //     {
   //         output += obj.timeTable[i][j]+",";
   //     }
   //   
   //     output += "\n";
   // }
   // file << output;
   // file.close();
    extern vector<section>allsections;
    if (allsections.size() == 0)
    {
        section obj;
        obj.name = 10;
         allteachersfunction("details/teacher_file.csv", obj);
        allroomsfunction("details/classroom.csv",obj);
         //alloting default rooms
         defaultroomallot(obj);
         //alloting core teacher and subjects
         loadcore(obj);
         labcreate("details/Labo.csv", obj);

         obj.makeTIMETABLE();
        allsections.push_back(obj);
    }
    else
    {
        section obj;
        obj.name = 5;
        obj.allTeachers = allsections[allsections.size() - 1].allTeachers;
        obj.allRooms = allsections[allsections.size() - 1].allRooms;
        defaultroomallot(obj);
        //alloting core teacher and subjects
        loadcore(obj);
        labcreate("details/Labo.csv", obj);

        obj.makeTIMETABLE();
        allsections.push_back(obj);
    }
 
}

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
    button7->BackColor = Color::FromArgb(0, 0, 90);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel5_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void editteacherpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button18_Click_2(System::Object^ sender, System::EventArgs^ e) {
    editteachercsvshow("details/teacher_file.csv");
}
private: System::Void editteacherdelete_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MessageBox::Show("Are you sure you want to delete", "Disclaimer", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
    {   editteachercsvdelete("details/teacher_File.csv");
     
        editteachername->Clear();
        for (int i = 1; i <= 36; ++i)
        {
            String^ tagValue = i.ToString();
            Button^ button = dynamic_cast<Button^>(addteacherpanel->Controls[String::Format("buttont{0}", tagValue)]);
            if (button != nullptr)
            {
                button->Text = "free";
            }
        }
        editteacherdepartment->Text = "";
    }
 
}

private: System::Void editteachersave_Click(System::Object^ sender, System::EventArgs^ e) {
    editteachercsvsave("details/teacher_file.csv");
}
private: System::Void buttont1_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont1);
}
private: System::Void buttont2_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont2);
}
private: System::Void buttont3_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont3);
}
private: System::Void buttont4_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont4);
}
private: System::Void buttont5_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont5);
}
private: System::Void buttont6_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont6);
}
private: System::Void buttont7_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont7);
}
private: System::Void buttont8_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont8);
}
private: System::Void buttont9_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont9);
}
private: System::Void buttont10_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont10);
}
private: System::Void buttont11_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont11);
}
private: System::Void buttont12_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont12);
}
private: System::Void buttont13_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont13);
}
private: System::Void buttont14_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont14);
}
private: System::Void buttont15_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont15);
}
private: System::Void buttont16_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont16);
}
private: System::Void buttont17_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont17);
}
private: System::Void buttont18_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont18);
}
private: System::Void buttont19_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont19);
}
private: System::Void buttont20_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont20);
}
private: System::Void buttont21_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont21);
}
private: System::Void buttont22_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont22);
}
private: System::Void buttont23_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont23);
}
private: System::Void buttont24_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont24);
}
private: System::Void buttont25_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont25);
}
private: System::Void buttont26_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont26);
}
private: System::Void buttont27_Click(System::Object^ sender, System::EventArgs^ e) {

    change(buttont27);
}
private: System::Void buttont28_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont28);
}
private: System::Void buttont29_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont29);
}
private: System::Void buttont30_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont30);
}
private: System::Void buttont31_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont31);
}
private: System::Void buttont32_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont32);
}
private: System::Void buttont33_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont33);
}
private: System::Void buttont34_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont34);
}
private: System::Void buttont35_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont35);
}
private: System::Void buttont36_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttont36);
}
private: System::Void buttonr1_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr1);
}
private: System::Void buttonr2_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr2);
}
private: System::Void buttonr3_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr3);
}
private: System::Void buttonr4_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr4);
}
private: System::Void buttonrs_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr5);
}
private: System::Void buttonr6_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr6);
}
private: System::Void buttonr7_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr7);
}
private: System::Void buttonr8_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr8);
}
private: System::Void buttonr9_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr9);
}
private: System::Void buttonr10_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr10);
}
private: System::Void buttonr11_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr11);
}
private: System::Void buttonr12_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr12);
}
private: System::Void buttonr13_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr13);
}
private: System::Void buttonr14_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr14);
}
private: System::Void buttonr15_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr15);
}
private: System::Void buttonr16_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr16);
}
private: System::Void buttonr17_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr17);
}
private: System::Void buttonr18_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr18);
}
private: System::Void buttonr19_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr19);
}
private: System::Void buttonr20_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr20);
}
private: System::Void buttonr21_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr21);
}
private: System::Void buttonr22_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr22);
}
private: System::Void buttonr23_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr23);
}
private: System::Void buttonr24_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr24);
}
private: System::Void buttonr25_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr25);
}
private: System::Void buttonr26_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr26);
}
private: System::Void buttonr27_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr27);
}
private: System::Void buttonr28_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr28);
}
private: System::Void buttonr29_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr29);
}
private: System::Void buttonr30_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr30);
}
private: System::Void buttonr31_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr31);
}
private: System::Void buttonr32_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr32);
}
private: System::Void buttonr33_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr33);
}
private: System::Void buttonr34_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr34);
}
private: System::Void buttonr35_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr35);
}
private: System::Void buttonr36_Click(System::Object^ sender, System::EventArgs^ e) {
    change(buttonr36);
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
    editroompanel->BringToFront();
    panel3->Height = button6->Height;
    panel3 -> Top = button6->Top;
    button4->BackColor = Color::FromArgb(0, 0, 90);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
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
            Button^ button = dynamic_cast<Button^>(editroompanel->Controls[String::Format("buttonr{0}", tagValue)]);
            if (button != nullptr)
            {
                button->Text = "free";
                button->BackColor = Color::FromArgb(179, 255, 230);
            }
        }
        editroomdepartment->Text = "";
        MessageBox::Show("Successfully deleted", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
    }

}
private: System::Void editroomsave_Click(System::Object^ sender, System::EventArgs^ e) {
    editroomcsvsave("details/classroom.csv");
}
private: System::Void pictureBox10_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    pictureBox10->Height += 5;
    pictureBox10->Width += 5;
}
private: System::Void pictureBox10_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    pictureBox10->Height -= 5;
    pictureBox10->Width -= 5;
}
private: System::Void pictureBox9_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    pictureBox9->Height += 5;
    pictureBox9->Width += 5;
}
private: System::Void pictureBox9_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    pictureBox9->Height -= 5;
    pictureBox9->Width -= 5;
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
    panel3->Height = button12->Height;
    panel3->Top = button12->Top;
    editsubjectpanel->BringToFront();
    button10->BackColor = Color::FromArgb(0, 0, 90);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
}
private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox12_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    pictureBox12->Height += 2;
    pictureBox12->Width += 2;
}
private: System::Void pictureBox12_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    pictureBox12->Height -= 2;
    pictureBox12->Width -= 2;
}
private: System::Void Homebutton1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    Homebutton1->Height += 1;
    Homebutton1->Width += 1;
}
private: System::Void Homebutton1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    Homebutton1->Height -= 1;
    Homebutton1->Width -= 1;
}
private: System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    button1->Height += 1;
    button1->Width += 1;
}
private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    button1->Height -= 1;
    button1->Width -= 1;
}
private: System::Void button6_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    button6->Height += 1;
    button6->Width += 1;
}
private: System::Void button6_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    button6->Height -= 1;
    button6->Width -= 1;
}
private: System::Void button9_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    button9->Height += 1;
    button9->Width += 1;
}
private: System::Void button9_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    button9->Height -= 1;
    button9->Width -= 1;
}
private: System::Void button12_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    button12->Height +=1;
    button12->Width += 1;
}
private: System::Void button12_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    button12->Height -= 1;
    button12->Width -= 1;
}
private: System::Void button15_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
    button15->Height += 1;
    button15->Width += 1;
}
private: System::Void button15_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    button15->Height -= 1;
    button15->Width -= 1;
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
}
private: System::Void addteachernew_Click(System::Object^ sender, System::EventArgs^ e) {
    addteachername->Clear();
    for (int i = 1; i <= 36; ++i)
    {
        String^ tagValue = i.ToString();
        Button^ button = dynamic_cast<Button^>(addteacherpanel->Controls[String::Format("buttons{0}", tagValue)]);
        if (button != nullptr)
        {
            button->Text = "free";
            button->BackColor = Color::FromArgb(179, 255, 230);
        }
    }
    addteacherdepartment->Text = "";
}

};
}

