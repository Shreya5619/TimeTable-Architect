#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include "section.h"
#include<list>
extern std::string searchteachername;
extern std::string searchroomname;
extern std::string searchsubname;
extern std::vector<std::vector<bool>>reserveMatrix;
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
                    editteachercsvshow("details/teacher_file.csv");
                }
            }
        }
        
        void textBox_KeyDownRoom(Object^ sender, KeyEventArgs^ e)
        {
            if (e->KeyCode == Keys::Enter)
            {
                ComboBox^ textBox = dynamic_cast<ComboBox^>(sender);
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
                ComboBox^ textBox = dynamic_cast<ComboBox^>(sender);
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
            dataGridView1->Rows->Clear();
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
            vector<string> it;
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                string rowString;
                for (const auto& cell : row) {
                    rowString += cell;
                }
                it.push_back(rowString);
            }
            std::sort(it.begin(), it.end());
            for (int i = 0; i < it.size(); i++)
            {
                comboBox->Items->Add(msclr::interop::marshal_as<String^>(it[i]));
            }
        }

        void DisplayCluster(const string& filename, ComboBox^ comboBox) {
            comboBox->Items->Clear();
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                bool bools = true;
                String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[0]);
                for each (Object^ item in comboBox->Items)
                {
                    if (item ->ToString() == rowStringManaged)
                        bools = false;
                }
                if (bools)
                {
                    comboBox->Items->Add(rowStringManaged);
                }
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
 
        void Button_click(Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr) {
                // Toggle the text of the clicked button
                if (clickedButton->Text == "Available")
                {
                    clickedButton->Text = "blocked";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "blocked")
                {
                    clickedButton->Text = "Available";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
                }
                else if (clickedButton->Text == "free")
                {
                    clickedButton->Text = "busy";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "busy")
                {
                    clickedButton->Text = "free";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
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
                    clickedButton->Text = "blocked";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                if (clickedButton->Text == "blocked")
                {
                    clickedButton->Text = "Available";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
                }
                if (clickedButton->Text == "Open")
                {
                    clickedButton->Text = "Reserved";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "Reserved")
                {
                    clickedButton->Text = "Open";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
                }
            }
        }

        void Button_clickEle (Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr) {
                // Toggle the text of the clicked button
                if (clickedButton->Text == "Available")
                {
                    clickedButton->Text = "blocked";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "blocked")
                {
                    clickedButton->Text = "Available";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
                }

            }
        }

        void change(Button^ clickedButton)
        { // Toggle the text of the clicked button
                if (clickedButton->Text == "free")
                {
                    clickedButton->Text = "busy";
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else
                {
                    clickedButton->Text = "free";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
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
                    if (MessageBox::Show("Teacher name already exists.\nAre you sure you want to replace the teacher.", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::No)
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
                      replacename(find, filePath, 0, x);
                    }
                    flag = false;
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

        int searchname(string find, string filename,int n)
        {
            for (char& a :find)
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
            if (file.is_open())// Temporary file
            {
                for ( auto &row : data)
                {
                    for (char &a : row[n])
                    {
                        a = toupper(static_cast<unsigned char>(a));
                    }
                    if (row[n] == find)
                    {
                        file<< x<<"\n";
                    }
                    else
                    {
                        for (int i = 0; i < row.size() - 1; i++)
                        {
                            file << row[i]<<",";
                        }
                        file << row[row.size() - 1] <<"\n";
                    }
                }
            }
            MessageBox::Show("Successfully Replaced", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void classroomcsvcreate(const string filePath)
        {
            try
            {
                bool flag = true;
                string find =replacewhitespace( msclr::interop::marshal_as<string>(roomname->Text));
                if (searchname(find,"details/classroom.csv", 0))
                {
                   if( MessageBox::Show("Room name already exists.\nAre you sure you want to replace the room.", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation)== System::Windows::Forms::DialogResult::No)
                    flag = false;
                   else
                   {
                       string x;
                       String^ name = roomname->Text->ToString();
                       string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                       x+= Name + ",";
                       String^ cap = roomcapacity->Text->ToString();
                       string Cap = msclr::interop::marshal_as<string>(cap);
                       x+= Cap +",";
                       if (roomlabyes->Checked)
                       {
                           x =x+ "1" + ",";
                       }
                       else
                       {
                           x =x+"0" + ",";
                       }
                       System::String^ dep = roomdept->Text->ToString();
                       std::string Dep = replacewhitespace(msclr::interop::marshal_as<string>(dep));
                       x+= Dep + ",";
                       for (int i = 1; i <= 36; ++i)
                       {
                           String^ tagValue = i.ToString();
                           Button^ button = dynamic_cast<Button^>(addroomtablepanel->Controls[String::Format("buttonroom{0}", tagValue)]);
                           if (button != nullptr)
                           {
                               if (button->Text == "Busy")
                               {
                                   x+= "1,0";
                               }
                               else if (button->Text == "Free")
                               {
                                 x+= "0,0";
                               }
                               if (i != 36)
                               {
                                   x+= ",";
                               }
                           }
                       }
                       replacename(find, filePath, 0, x);
                   }
                   flag = false;
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
            try{
            ofstream outputFile;
            outputFile.open((msclr::interop::marshal_as<string>(filePath)), ios::app);
            if (outputFile.is_open())
            {
                String^ name = addsubname->Text->ToString();
                string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                outputFile << Name << ",";
                {if (addsubeleyes->Checked)
                {
                    String^ ele = addsubcluster->Text->ToString();
                    string Ele = replacewhitespace(msclr::interop::marshal_as<string>(ele));
                    outputFile << Ele << ",";

                    vector<string> teachers;
                    for (int i = 0; i < sedataGridView->RowCount-1; ++i)
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
                {if (addsublabyes->Checked)
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
                System::String^ credits = addsubcredits->Text->ToString();
                std::string Credits = msclr::interop::marshal_as<string>(credits);
                outputFile << Credits << ",";
                if (addsublabyes->Checked)
                {
                    outputFile << "2,";
                }
                else
                {
                    outputFile << "1,";
                }
                System::String^ bfactor = addsubbfactor->Text->ToString();
                std::string Bfactor = msclr::interop::marshal_as<string>(bfactor);
                outputFile << Bfactor << ",";
                //code to add roomlist
                outputFile << "[";
                bool x = true;
                for (int i = 0; i < addsubroomlist->CheckedItems->Count; ++i) {
                    String^ value = addsubroomlist->CheckedItems[i]->ToString();
                    std::string Value = msclr::interop::marshal_as<string>(value);
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
        catch (...)
        {
            MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
            }

        void DisplayCSVInListBox(const string& filename, ListBox^ ListBox,int i) {
                ListBox->Items->Clear();
                vector<vector<string>> data = ReadCSVFile(filename);

                for (const auto& row : data) {
                    String^ rowStringManaged = msclr::interop::marshal_as<String^>(row[i]);
                    if(!ListBox->Items->Contains(rowStringManaged))
                    ListBox->Items->Add(rowStringManaged);
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
                            System::String^ elename = editsubelename->Text->ToString();
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

        void editcsvlab()
        {
            try
            {
                string find = msclr::interop::marshal_as<string>(editsubsearch->Text);

                vector<vector<string>>data = ReadCSVFile("details/Labo.csv");
                ofstream outputfile;
                outputfile.open("details/Labo.csv");

                {
                    for (const auto& row : data)
                    {
                        if (find == row[0])
                        {
                            {
                                System::String^ Name = editsubname->Text->ToString();
                                std::string name = replacewhitespace(msclr::interop::marshal_as<string>(Name));
                                outputfile << name << ",";
                                if (editsublabteacher->Rows[0]->Cells[0]->Value != nullptr)
                                    outputfile << msclr::interop::marshal_as<string>(editsublabteacher->Rows[0]->Cells[0]->Value->ToString());
                                for (int i = 1; i < editsublabteacher->RowCount; ++i)
                                {

                                    if (editsublabteacher->Rows[i]->Cells[0]->Value != nullptr)
                                    {
                                        System::String^ cellvalue = editsublabteacher->Rows[i]->Cells[0]->Value->ToString();
                                        std::string Cellvalue = msclr::interop::marshal_as<string>(cellvalue);
                                        outputfile << "," << Cellvalue;


                                    }
                                }

                            }
                                outputfile << "\n";
                        }
                        else
                        {

                            for (int i = 0; i < row.size() - 1; i++)
                            {
                                outputfile << row[i] + ",";
                            }
                            outputfile << row[row.size() - 1] << "\n";

                        }
                    }
                    outputfile.close();
                }

            }
            catch (...)
            {
                MessageBox::Show("error saving data\ntry closing opened files", "error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        
        void csvlab(System::String^ filePath)
        {
            try
            {
                std::ofstream outputFile;
                outputFile.open((msclr::interop::marshal_as<std::string>(filePath)), ios::app);
                {
                    System::String^ name = addsubname->Text->ToString();
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
                    outputFile << "[";
                    bool x = true;
                    for (int i = 0; i < addsubroomlist->CheckedItems->Count; ++i) {
                        String^ value = addsubroomlist->CheckedItems[i]->ToString();
                        std::string Value = msclr::interop::marshal_as<string>(value);
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
                }outputFile.close();
            }
            catch (...)
            {
                MessageBox::Show("Error saving Data\nTry closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Data::DataTable^ CreateDataTableFromCSV1(const std::string filePath,String^ name) {
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
       bool flag = true;
       string*a = &searchteachername;
        string find = replacewhitespace(msclr::interop::marshal_as<string>(teachersearch->Text));
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
                if (find ==str)
                {
                    flag = false;
                    *a = row[0];
                    editteachername->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
                    editteacherdepartment->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[1]));

                    for (int i = 2; i < row.size(); i += 2)
                    {
                        int x = i / 2;
                        String^ tagValue = x.ToString();
                        Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
                        if (row[i] == "1")
                        {
                            button->Text = "Busy";
                            button->BackColor = Color::FromArgb(102, 255, 204);
                        }
                        else
                        {
                            button->Text = "Free";
                            button->BackColor = Color::FromArgb(179, 255, 230);
                        }
                    }

                }
                
            }
        }
        if(flag)
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
                       DeleteTeacherFromCSV(row[0], "details/Elective.csv");
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
               flag = false;
               *a = row[0];
               editroomname->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[0]));
               editroomcapacity->Text = msclr::interop::marshal_as<String^>(row[1]);
               if (row[2] == "0")
               {
                   editroomlabno->Checked=true;
               }
               else
               {
                   editroomlabyes->Checked=true;
               }
               editroomdepartment->Text = msclr::interop::marshal_as<String^>(replaceunderscore(row[3]));

               for (int i = 4; i <row.size(); i += 2)
               {
                   int x = (i / 2) - 1;
                   String^ tagValue = x.ToString();
                   Button^ button = dynamic_cast<Button^>(editroomtablepanel->Controls[String::Format("buttoneditroom{0}", tagValue)]);
                   if (row[i] == "1")
                   {
                       button->Text = "Busy";
                       button->BackColor = Color::FromArgb(102, 255, 204);
                   }
                   else
                   {
                       button->Text = "Free";
                       button->BackColor = Color::FromArgb(179, 255, 230);
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
       string find = msclr::interop::marshal_as<string>(editsubsearch->Text);
       bool flag = true;
       vector<vector<string>>data = ReadCSVFile("details/subject_file.csv");
       for (auto& row : data)
       {
           string str;
           for (char& a : row[0])
           {
               str += toupper(static_cast<unsigned char>(a));
           }
           for (char& a : find)
           {
               a = toupper(static_cast<unsigned char>(a));
           }
           if (str == find)
           {
               flag = false;
               *a = row[0];
               editsubname->Text = msclr::interop::marshal_as<String^>(row[0]);
               if (row[1] == "0")
               {
                   editsubeleno->Checked=true;
                   editsubelename->Text = "";
                   editsubeleteacher->Rows->Clear();
               }
               else
               {
                   editsubeleyes->Checked=true;
                   fstream file;
                   file.open("details/elective.csv");
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
                           a = toupper(static_cast<unsigned char>(a));
                       }
                       if (rows[0] == find)
                       {
                           editsubelename->Text = msclr::interop::marshal_as<String^>(rows[1]);
                           
                           editsubeleteacher->Rows->Clear();
                               for (int i = 2; i < rows.size(); i++)
                               {
                                   editsubeleteacher->Rows->Add();
                                   editsubeleteacher->Rows[i-2]->Cells[0]->Value = (msclr::interop::marshal_as<String^>(rows[i]));
                               }
                               break;
                       }
                       
                   }
                   file.close();
                   
               }
               if (row[2] == "0")
               {
                   editsublabno->Checked=true;
               }
               else
               {
                   editsublabyes->Checked=true;
                   fstream file;
                   file.open("details/Labo.csv");
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
                           a = toupper(static_cast<unsigned char>(a));
                       }
                       if (rows[0] == find)
                       {
                           editsublabteacher->Rows->Clear();
                           for (int i = 1; i < rows.size(); i++)
                           {
                               editsublabteacher->Rows->Add();
                               editsublabteacher->Rows[i - 1]->Cells[0]->Value = (msclr::interop::marshal_as<String^>(rows[i]));
                           }
                           break;
                       }

                   }

               }
               editsubcredits->Text= msclr::interop::marshal_as<String^>(row[3]);
               editsubbfactor->Text= msclr::interop::marshal_as<String^>(row[5]);
               for (int i = 0; i < editsubroomlist->Items->Count; i++) {
                   editsubroomlist->SetItemChecked(i, false);
               }
                   if (!row[6].empty()) {
                      String^ y = msclr::interop::marshal_as<String^>( row[6].erase(0, 1));
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
                   if (row.size() > 7)
                   {
                      for (int j = 7; j < row.size()-1; j++)
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
                      
                      String^ searchString = msclr::interop::marshal_as<String^>(row[row.size() - 1].substr(0, row[row.size()-1].length() - 1));
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
       if(flag)
       {
           MessageBox::Show("Subject not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
       }
   }

   void editsubcsvsave(const string filename)
   {
       try {
           string find = searchsubname;

           vector<vector<string>>data = ReadCSVFile(filename);
           bool flag = true;
           ofstream file(filename);
           {
               for (const auto& row : data)
               {
                   if (find == row[0]) {
                       file << msclr::interop::marshal_as<string>(editsubname->Text) << ",";
                       if (editsubeleyes->Checked)
                       {
                           String^ ele = editsubelename->Text->ToString();
                           string Ele = replacewhitespace(msclr::interop::marshal_as<string>(ele));
                           file << Ele << ",";
                           string FilePath = "details/Elective.csv";
                           editcsvelectivee(FilePath);
                       }
                       else
                       {
                           file << "0,";
                       }

                       {if (editsublabyes->Checked)
                       {
                           file << "1,";
                           {
                              editcsvlab();
                           }
                       }
                       else
                       {
                           file << "0,";
                       }
                       }
                       System::String^ credits = editsubcredits->Text->ToString();
                       std::string Credits = msclr::interop::marshal_as<string>(credits);
                       file << Credits << ",";
                       if (editsublabyes->Checked)
                       {
                           file << "2,";
                       }
                       else
                       {
                           file << "1,";
                       }
                       System::String^ bfactor = editsubbfactor->Text->ToString();
                       std::string Bfactor = msclr::interop::marshal_as<string>(bfactor);
                       file << Bfactor << ",";
                       //code to add roomlist
                       file << "[";
                       bool x = true;
                       for (int i = 0; i < editsubroomlist->CheckedItems->Count; ++i) {
                           String^ value = editsubroomlist->CheckedItems[i]->ToString();
                           std::string Value = msclr::interop::marshal_as<string>(value);
                           file << Value;
                           x = false;
                           if (i < editsubroomlist->CheckedItems->Count - 1) {
                               file << ",";// Add a comma after each value, except the last one
                           }
                       }
                       if (x)
                       {
                           file << "0";
                       }
                       file << "]\n";
                       MessageBox::Show("Saved successfully", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
                       flag = false;
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
               MessageBox::Show("Subject not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
           }
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
       bool flag=true;
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
           MessageBox::Show("Subject not found", "Message", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
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

   void DeleteTeacherFromCSV(string teacherName,string filename) {
       vector < vector<string>>data = ReadCSVFile(filename);
       ofstream file(filename);
       if (file.is_open())
       {
           for (auto& row : data)
           {
               file << row[0] << "," << row[1];
               for (int i = 2; i < row.size()-1; i++)
               {
                   if(teacherName==row[i])
                   { }
                   else
                   {
                       file << ","<<row[i];
                   }
               }
               if(teacherName==row[row.size() - 1])
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

    vector<vector<vector<bool>>>valuetimetable(string clustername)
    {
        vector < vector < vector<bool>>>allt;
        vector<vector<bool>>tt;
        vector<bool>ttval;
        allt.push_back(returntimetable(clustername));
        vector<vector<string>>data = ReadCSVFile("details/teacher_file.csv");
        for (int i = 0; i < sedataGridView->RowCount; i++)
        {
            if (sedataGridView->Rows[i]->Cells[0]->Value != nullptr)
            {
                string name = msclr::interop::marshal_as<string>(sedataGridView->Rows[i]->Cells[0]->Value->ToString());
                for (const auto& row : data)
                {
                    if (name == row[0])
                    {
                        int count = 0;
                        for (int i = 2; i < row.size(); i+=2)
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

    void onOptionClick()
    {
        string name = msclr::interop::marshal_as<string>(addsubcluster->Text);
        vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
        vector<vector<vector<bool>>>tt = valuetimetable(name);
        vector<vector<bool>>intersecttt = intersectionElective(tt);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i * 6 + j + 1)]);
                if (button != nullptr)
                {
                    if (intersecttt[i][j])
                    {
                        button->Text = "busy";
                        button->BackColor = Color::FromArgb(224, 224, 224);
                    }
                    else
                    {
                        button->Text = "Available";
                    }
                }
                
            }
        }

    }

    void Button_Click(Object^ sender, EventArgs^ e) {
        Button^ clickedButton = dynamic_cast<Button^>(sender);
        if (clickedButton != nullptr) {
            // Toggle the text of the clicked button
            if (clickedButton->Text == "Open")
            {
                clickedButton->Text = "Reserved";
                clickedButton->BackColor = Color::FromArgb(102,255,204);
            }
            else if(clickedButton->Text == "Reserved")
            {
                clickedButton->Text = "Open";
                clickedButton->BackColor = Color::FromArgb(179, 255, 230);
            }
            else if (clickedButton->Text == "free")
            {
                clickedButton->Text = "Busy";
                clickedButton->BackColor = Color::FromArgb(102, 255, 204);
            }
            else if (clickedButton->Text == "Busy")
            {
                clickedButton->Text = "free";
                clickedButton->BackColor = Color::FromArgb(179, 255, 230);
            }
        }
    }

    void Button_ClickFreeBusy(Object^ sender, EventArgs^ e) {
        Button^ clickedButton = dynamic_cast<Button^>(sender);
        if (clickedButton != nullptr) {
            // Toggle the text of the clicked button
            if (clickedButton->Text == "Free")
            {
                clickedButton->Text = "Busy";
                clickedButton->BackColor = Color::FromArgb(102, 255, 204);
            }
            else if (clickedButton->Text == "Busy")
            {
                clickedButton->Text = "Free";
                clickedButton->BackColor = Color::FromArgb(179, 255, 230);
            }
        }
    }
    void InitializeMatrix(TableLayoutPanel^ tableLayoutPanel,Button^ addsubsaves,String^ s) {
        
        tableLayoutPanel->RowCount =6;
        tableLayoutPanel->ColumnCount = 6;
        tableLayoutPanel->Height =(addsubsaves->Height+7) * 6;
        tableLayoutPanel->Width = (addsubsaves->Width+7)* 6;
        // Clear existing buttons if any
        tableLayoutPanel->Controls->Clear();

        // Create buttons and add them to the TableLayoutPanel
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                Button^ button = gcnew Button();
                button->Text = String::Format("Available");
                button->BackColor = Color::FromArgb(179, 255, 230);
                button->Dock = DockStyle::Fill;
                button->Font= (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(0)));
                button->Width = addsubsaves->Width; // Set the width of the button
                button->Height = addsubsaves->Height;
                button->AutoSize = false;
                button->Name = String::Format("button"+s+"{0}", i * 6 + j + 1);
                tableLayoutPanel->Controls->Add(button, j, i);
                button->Click += gcnew EventHandler(this, &MyForm::Button_clickEle);
                tableLayoutPanel->Controls->Add(button, j, i);
            }
        }
    }

    void InitializeMatrix1(TableLayoutPanel^ tableLayoutPanel, Button^ addsubsaves, String^ s,String^ Texts) {

        tableLayoutPanel->RowCount = 6;
        tableLayoutPanel->ColumnCount = 6;
        tableLayoutPanel->Height = (addsubsaves->Height +7) *6;
        tableLayoutPanel->Width = (addsubsaves->Width + 7) * 6;
        // Clear existing buttons if any
        tableLayoutPanel->Controls->Clear();
        // Create buttons and add them to the TableLayoutPanel

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                Button^ button = gcnew Button();
                button->Text = Texts;
                button->BackColor = Color::FromArgb(179, 255, 230);
                button->Dock = DockStyle::Fill;
                button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(0)));
                button->Width = addsubsaves->Width; // Set the width of the button
                button->Height = addsubsaves->Height;
                button->AutoSize = false;
                button->Name = String::Format("button" + s + "{0}", i * 6 + j + 1);
                tableLayoutPanel->Controls->Add(button, j, i);
                button->Click += gcnew EventHandler(this, &MyForm::Button_clicks);
                tableLayoutPanel->Controls->Add(button, j, i);
            }
        }
    }
    void InitializeMatrix2(TableLayoutPanel^ tableLayoutPanel, Button^ addsubsaves, String^ s, String^ Texts) {

        tableLayoutPanel->RowCount = 6;
        tableLayoutPanel->ColumnCount = 6;
        // Clear existing buttons if any
        tableLayoutPanel->Controls->Clear();
        // Create buttons and add them to the TableLayoutPanel

        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 6; j++) 
                {
                    Button^ button = gcnew Button();
                    button->Text = Texts;
                    button->BackColor = Color::FromArgb(179, 255, 230);
                    button->Dock = DockStyle::Fill;
                    button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                        static_cast<System::Byte>(0)));
                    button->Name = String::Format("button" + s + "{0}", i * 6 + j + 1);
                    tableLayoutPanel->Controls->Add(button, j, i);
                    tableLayoutPanel->Controls->Add(button, j, i);
                }
        }
    }


    void InitializeMatrix3(TableLayoutPanel^ tableLayoutPanel, String^ s, String^ Texts) {

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
                    button->BackColor = Color::FromArgb(179, 255, 230);
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
                    button->Click += gcnew EventHandler(this, &MyForm::Button_clickEle);
                    tableLayoutPanel->Controls->Add(button, j, i);
                }
            }
        }
    }

    void InitializeMatrixfreebusy(TableLayoutPanel^ tableLayoutPanel, String^ s, String^ Texts) {

        tableLayoutPanel->RowCount = 6;
        tableLayoutPanel->ColumnCount = 6;
        // Clear existing buttons if any
        tableLayoutPanel->Controls->Clear();
        // Create buttons and add them to the TableLayoutPanel

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                Button^ button = gcnew Button();
                button->Text = Texts;
                button->BackColor = Color::FromArgb(179, 255, 230);
                button->Dock = DockStyle::Fill;
                button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(0)));
                button->Name = String::Format("button" + s + "{0}", i * 6 + j + 1);
                tableLayoutPanel->Controls->Add(button, j, i);
                button->Click += gcnew EventHandler(this, &MyForm::Button_ClickFreeBusy);
                tableLayoutPanel->Controls->Add(button, j, i);
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
        private: System::Windows::Forms::Label^ label45;
        private: System::Windows::Forms::Label^ label44;
        private: System::Windows::Forms::DataGridView^ sldataGridView;

        private: System::Windows::Forms::DataGridViewComboBoxColumn^ Teacher_Name;
        private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn4;
        private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::NumericUpDown^ addsubcredits;

        private: System::Windows::Forms::Label^ label43;
        private: System::Windows::Forms::Label^ label42;
        private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::NumericUpDown^ addsubbfactor;

        private: System::Windows::Forms::Button^ addsubsave;
private: System::Windows::Forms::CheckedListBox^ addsubroomlist;

        private: System::Windows::Forms::Button^ newaddsub;
        private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::RadioButton^ addsublabyes;
private: System::Windows::Forms::RadioButton^ addsublabno;


        private: System::Windows::Forms::Panel^ addsubjectpanel;
        private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::RadioButton^ addsubeleyes;
private: System::Windows::Forms::RadioButton^ addsubeleno;


private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::DataGridView^ sedataGridView;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::TextBox^ addsubname;

private: System::Windows::Forms::Button^ saveroom;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::TextBox^ roomname;
private: System::Windows::Forms::NumericUpDown^ roomcapacity;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::ComboBox^ roomdept;
private: System::Windows::Forms::Button^ clearroom;
private: System::Windows::Forms::RadioButton^ roomlabno;
private: System::Windows::Forms::RadioButton^ roomlabyes;
private: System::Windows::Forms::Panel^ addclassroompanel;
private: System::Windows::Forms::Panel^ Homepanel;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::DataGridView^ deptDataGridView;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
private: System::Windows::Forms::TextBox^ deptlabel;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::PictureBox^ pictureBox9;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::PictureBox^ pictureBox11;
private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Panel^ editteacherpanel;
private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::Label^ label62;
private: System::Windows::Forms::ComboBox^ editteacherdepartment;
private: System::Windows::Forms::Label^ label63;
private: System::Windows::Forms::TextBox^ editteachername;
private: System::Windows::Forms::Button^ editteachersave;
private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::Button^ editteacherdelete;
private: System::Windows::Forms::Panel^ editroompanel;
private: System::Windows::Forms::RadioButton^ editroomlabno;
private: System::Windows::Forms::RadioButton^ editroomlabyes;
private: System::Windows::Forms::Button^ editroomdelete;
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
private: System::Windows::Forms::Label^ label82;
private: System::Windows::Forms::Panel^ editsubjectpanel;
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
private: System::Windows::Forms::ComboBox^ editroomsearch;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::RadioButton^ editsubeleyes;
private: System::Windows::Forms::RadioButton^ editsubeleno;
private: System::Windows::Forms::Label^ label92;
private: System::Windows::Forms::TextBox^ editsubname;
private: System::Windows::Forms::Label^ label93;
private: System::Windows::Forms::Label^ label94;
private: System::Windows::Forms::Label^ label95;
private: System::Windows::Forms::DataGridView^ editsubeleteacher;
private: System::Windows::Forms::Panel^ panel13;
private: System::Windows::Forms::RadioButton^ editsublabyes;
private: System::Windows::Forms::RadioButton^ editsublabno;
private: System::Windows::Forms::CheckedListBox^ editsubroomlist;
private: System::Windows::Forms::Label^ label96;
private: System::Windows::Forms::Label^ label97;
private: System::Windows::Forms::NumericUpDown^ editsubcredits;
private: System::Windows::Forms::DataGridView^ editsublabteacher;
private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::Label^ label99;
private: System::Windows::Forms::Button^ editsubdelete;
private: System::Windows::Forms::Button^ editsubsave;
private: System::Windows::Forms::NumericUpDown^ editsubbfactor;
private: System::Windows::Forms::Label^ label100;
private: System::Windows::Forms::Button^ editsubsearchbutton;
private: System::Windows::Forms::Label^ label101;
private: System::Windows::Forms::ComboBox^ editsubsearch;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ editsubeleteachercombo;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn10;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ editsublabteachercombo;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn11;
private: System::Windows::Forms::ComboBox^ addsubcluster;

private: System::Windows::Forms::ComboBox^ editsubelename;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::Button^ addsubclusteroptions;



private: System::Windows::Forms::Panel^ panelsub;

private: System::Windows::Forms::DataGridView^ dataGridView3;
private: System::Windows::Forms::DataGridView^ dataGridView6;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::Button^ button16;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ lsubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ eSubject;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn3;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ csubject;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ cteacher;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::Panel^ addroompanel;
private: System::Windows::Forms::Label^ label103;
private: System::Windows::Forms::Label^ label104;
private: System::Windows::Forms::Label^ label105;
private: System::Windows::Forms::Label^ label106;
private: System::Windows::Forms::Label^ label107;
private: System::Windows::Forms::Label^ label108;
private: System::Windows::Forms::Label^ label113;
private: System::Windows::Forms::Label^ label114;
private: System::Windows::Forms::Label^ label115;
private: System::Windows::Forms::Label^ label116;
private: System::Windows::Forms::Label^ label117;
private: System::Windows::Forms::Label^ label118;
private: System::Windows::Forms::TableLayoutPanel^ addroomtablepanel;
private: System::Windows::Forms::Panel^ panel14;
private: System::Windows::Forms::Panel^ panel15;
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
private: System::Windows::Forms::TableLayoutPanel^ editroomtablepanel;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ addteachername;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::ComboBox^ addteacherdepartment;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Panel^ panel16;
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
private: System::Windows::Forms::TableLayoutPanel^ teachertablepanel;
private: System::Windows::Forms::Panel^ addteacherpanel;
private: System::Windows::Forms::Panel^ panel17;
private: System::Windows::Forms::Button^ addteachersave;
private: System::Windows::Forms::Button^ addteachernew;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Panel^ panel18;
private: System::Windows::Forms::Panel^ panel19;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Label^ label119;
private: System::Windows::Forms::Label^ label120;
private: System::Windows::Forms::TableLayoutPanel^ editteachertablepanel;
private: System::Windows::Forms::Label^ label51;
private: System::Windows::Forms::Panel^ finalttpanel;
private: System::Windows::Forms::Label^ label35;
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
private: System::Windows::Forms::TableLayoutPanel^ classtablegen1;
private: System::Windows::Forms::TableLayoutPanel^ classtablegen;
private: System::Windows::Forms::Panel^ panel20;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
private: System::Windows::Forms::Label^ label83;
private: System::Windows::Forms::Label^ label84;
private: System::Windows::Forms::Label^ label85;
private: System::Windows::Forms::Label^ label86;
private: System::Windows::Forms::Label^ label87;
private: System::Windows::Forms::Label^ label88;
private: System::Windows::Forms::Label^ label89;
private: System::Windows::Forms::Label^ label90;
private: System::Windows::Forms::Label^ label91;
private: System::Windows::Forms::Label^ label102;
private: System::Windows::Forms::Label^ label121;
private: System::Windows::Forms::Label^ label122;
private: System::Windows::Forms::Panel^ panel22;
private: System::Windows::Forms::Panel^ panel21;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ TeacherName;
private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn5;
private: System::Windows::Forms::Panel^ addsubeletablepanel;
private: System::Windows::Forms::Panel^ panel23;
private: System::Windows::Forms::Panel^ panel24;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

private: System::Windows::Forms::Label^ label123;
private: System::Windows::Forms::Label^ label124;
private: System::Windows::Forms::Label^ label125;
private: System::Windows::Forms::Label^ label126;
private: System::Windows::Forms::Label^ label127;
private: System::Windows::Forms::Label^ label128;
private: System::Windows::Forms::Label^ label129;
private: System::Windows::Forms::Label^ label130;
private: System::Windows::Forms::Label^ label131;
private: System::Windows::Forms::Label^ label132;
private: System::Windows::Forms::Label^ label133;
private: System::Windows::Forms::Label^ label134;


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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle43 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle44 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle48 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle49 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle50 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle45 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
            this->addsubcredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->addsubbfactor = (gcnew System::Windows::Forms::NumericUpDown());
            this->addsubsave = (gcnew System::Windows::Forms::Button());
            this->addsubroomlist = (gcnew System::Windows::Forms::CheckedListBox());
            this->newaddsub = (gcnew System::Windows::Forms::Button());
            this->panel11 = (gcnew System::Windows::Forms::Panel());
            this->addsublabyes = (gcnew System::Windows::Forms::RadioButton());
            this->addsublabno = (gcnew System::Windows::Forms::RadioButton());
            this->addsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->addsubclusteroptions = (gcnew System::Windows::Forms::Button());
            this->addsubeletablepanel = (gcnew System::Windows::Forms::Panel());
            this->panel23 = (gcnew System::Windows::Forms::Panel());
            this->panel24 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label123 = (gcnew System::Windows::Forms::Label());
            this->label124 = (gcnew System::Windows::Forms::Label());
            this->label125 = (gcnew System::Windows::Forms::Label());
            this->label126 = (gcnew System::Windows::Forms::Label());
            this->label127 = (gcnew System::Windows::Forms::Label());
            this->label128 = (gcnew System::Windows::Forms::Label());
            this->label129 = (gcnew System::Windows::Forms::Label());
            this->label130 = (gcnew System::Windows::Forms::Label());
            this->label131 = (gcnew System::Windows::Forms::Label());
            this->label132 = (gcnew System::Windows::Forms::Label());
            this->label133 = (gcnew System::Windows::Forms::Label());
            this->label134 = (gcnew System::Windows::Forms::Label());
            this->addsubcluster = (gcnew System::Windows::Forms::ComboBox());
            this->panel12 = (gcnew System::Windows::Forms::Panel());
            this->addsubeleyes = (gcnew System::Windows::Forms::RadioButton());
            this->addsubeleno = (gcnew System::Windows::Forms::RadioButton());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->addsubname = (gcnew System::Windows::Forms::TextBox());
            this->sedataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->panelsub = (gcnew System::Windows::Forms::Panel());
            this->saveroom = (gcnew System::Windows::Forms::Button());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->roomname = (gcnew System::Windows::Forms::TextBox());
            this->roomcapacity = (gcnew System::Windows::Forms::NumericUpDown());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->roomdept = (gcnew System::Windows::Forms::ComboBox());
            this->clearroom = (gcnew System::Windows::Forms::Button());
            this->roomlabno = (gcnew System::Windows::Forms::RadioButton());
            this->roomlabyes = (gcnew System::Windows::Forms::RadioButton());
            this->addclassroompanel = (gcnew System::Windows::Forms::Panel());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->addroompanel = (gcnew System::Windows::Forms::Panel());
            this->label103 = (gcnew System::Windows::Forms::Label());
            this->label104 = (gcnew System::Windows::Forms::Label());
            this->label105 = (gcnew System::Windows::Forms::Label());
            this->label106 = (gcnew System::Windows::Forms::Label());
            this->label107 = (gcnew System::Windows::Forms::Label());
            this->label108 = (gcnew System::Windows::Forms::Label());
            this->label113 = (gcnew System::Windows::Forms::Label());
            this->label114 = (gcnew System::Windows::Forms::Label());
            this->label115 = (gcnew System::Windows::Forms::Label());
            this->label116 = (gcnew System::Windows::Forms::Label());
            this->label117 = (gcnew System::Windows::Forms::Label());
            this->label118 = (gcnew System::Windows::Forms::Label());
            this->addroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->Homepanel = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->button22 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->deptDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->deptlabel = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->label109 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->editteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->editteacherdelete = (gcnew System::Windows::Forms::Button());
            this->editteachersave = (gcnew System::Windows::Forms::Button());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->label119 = (gcnew System::Windows::Forms::Label());
            this->label120 = (gcnew System::Windows::Forms::Label());
            this->editteachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->editteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->editteachername = (gcnew System::Windows::Forms::TextBox());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->teachersearch = (gcnew System::Windows::Forms::ComboBox());
            this->editroompanel = (gcnew System::Windows::Forms::Panel());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->editroomdelete = (gcnew System::Windows::Forms::Button());
            this->editroomsave = (gcnew System::Windows::Forms::Button());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
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
            this->editroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->editroomsearchbutton = (gcnew System::Windows::Forms::Button());
            this->label82 = (gcnew System::Windows::Forms::Label());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->editroomlabyes = (gcnew System::Windows::Forms::RadioButton());
            this->editroomlabno = (gcnew System::Windows::Forms::RadioButton());
            this->editroomdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label78 = (gcnew System::Windows::Forms::Label());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->label80 = (gcnew System::Windows::Forms::Label());
            this->editroomcapacity = (gcnew System::Windows::Forms::NumericUpDown());
            this->editroomname = (gcnew System::Windows::Forms::TextBox());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->editroomsearch = (gcnew System::Windows::Forms::ComboBox());
            this->editsubjectpanel = (gcnew System::Windows::Forms::Panel());
            this->editsubelename = (gcnew System::Windows::Forms::ComboBox());
            this->editsubsearchbutton = (gcnew System::Windows::Forms::Button());
            this->label101 = (gcnew System::Windows::Forms::Label());
            this->editsubsearch = (gcnew System::Windows::Forms::ComboBox());
            this->editsubdelete = (gcnew System::Windows::Forms::Button());
            this->editsubsave = (gcnew System::Windows::Forms::Button());
            this->editsubbfactor = (gcnew System::Windows::Forms::NumericUpDown());
            this->label100 = (gcnew System::Windows::Forms::Label());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->editsublabyes = (gcnew System::Windows::Forms::RadioButton());
            this->editsublabno = (gcnew System::Windows::Forms::RadioButton());
            this->editsubroomlist = (gcnew System::Windows::Forms::CheckedListBox());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->editsubcredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->editsublabteacher = (gcnew System::Windows::Forms::DataGridView());
            this->editsublabteachercombo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn11 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->label94 = (gcnew System::Windows::Forms::Label());
            this->panel10 = (gcnew System::Windows::Forms::Panel());
            this->editsubeleyes = (gcnew System::Windows::Forms::RadioButton());
            this->editsubeleno = (gcnew System::Windows::Forms::RadioButton());
            this->label92 = (gcnew System::Windows::Forms::Label());
            this->label95 = (gcnew System::Windows::Forms::Label());
            this->editsubeleteacher = (gcnew System::Windows::Forms::DataGridView());
            this->editsubeleteachercombo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn10 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->editsubname = (gcnew System::Windows::Forms::TextBox());
            this->label93 = (gcnew System::Windows::Forms::Label());
            this->settingspanel = (gcnew System::Windows::Forms::Panel());
            this->panel20 = (gcnew System::Windows::Forms::Panel());
            this->panel21 = (gcnew System::Windows::Forms::Panel());
            this->panel22 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label83 = (gcnew System::Windows::Forms::Label());
            this->label84 = (gcnew System::Windows::Forms::Label());
            this->label85 = (gcnew System::Windows::Forms::Label());
            this->label86 = (gcnew System::Windows::Forms::Label());
            this->label87 = (gcnew System::Windows::Forms::Label());
            this->label88 = (gcnew System::Windows::Forms::Label());
            this->label89 = (gcnew System::Windows::Forms::Label());
            this->label90 = (gcnew System::Windows::Forms::Label());
            this->label91 = (gcnew System::Windows::Forms::Label());
            this->label102 = (gcnew System::Windows::Forms::Label());
            this->label121 = (gcnew System::Windows::Forms::Label());
            this->label122 = (gcnew System::Windows::Forms::Label());
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
            this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
            this->eSubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
            this->csubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->cteacher = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->button19 = (gcnew System::Windows::Forms::Button());
            this->button17 = (gcnew System::Windows::Forms::Button());
            this->button16 = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->lsubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->button21 = (gcnew System::Windows::Forms::Button());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->finalttpanel = (gcnew System::Windows::Forms::Panel());
            this->classtablegen1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label35 = (gcnew System::Windows::Forms::Label());
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
            this->classtablegen = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->addteachername = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->addteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
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
            this->teachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->addteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->addteachersave = (gcnew System::Windows::Forms::Button());
            this->addteachernew = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sldataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcredits))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactor))->BeginInit();
            this->panel11->SuspendLayout();
            this->addsubjectpanel->SuspendLayout();
            this->addsubeletablepanel->SuspendLayout();
            this->panel12->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->BeginInit();
            this->panelsub->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacity))->BeginInit();
            this->addclassroompanel->SuspendLayout();
            this->addroompanel->SuspendLayout();
            this->panel9->SuspendLayout();
            this->panel7->SuspendLayout();
            this->panel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            this->panel4->SuspendLayout();
            this->editteacherpanel->SuspendLayout();
            this->panel18->SuspendLayout();
            this->panel19->SuspendLayout();
            this->editroompanel->SuspendLayout();
            this->panel14->SuspendLayout();
            this->panel15->SuspendLayout();
            this->panel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->BeginInit();
            this->editsubjectpanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactor))->BeginInit();
            this->panel13->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcredits))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsublabteacher))->BeginInit();
            this->panel10->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleteacher))->BeginInit();
            this->settingspanel->SuspendLayout();
            this->panel20->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->panel5->SuspendLayout();
            this->finalttpanel->SuspendLayout();
            this->panel16->SuspendLayout();
            this->addteacherpanel->SuspendLayout();
            this->panel17->SuspendLayout();
            this->SuspendLayout();
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label45->Location = System::Drawing::Point(32, 31);
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
            this->label44->Location = System::Drawing::Point(42, 162);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(299, 28);
            this->label44->TabIndex = 238;
            this->label44->Text = L"Teachers handling the lab subject";
            // 
            // sldataGridView
            // 
            this->sldataGridView->AllowUserToOrderColumns = true;
            this->sldataGridView->AllowUserToResizeColumns = false;
            this->sldataGridView->AllowUserToResizeRows = false;
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
            this->sldataGridView->Location = System::Drawing::Point(45, 212);
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
            dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
            dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
            this->sldataGridView->RowsDefaultCellStyle = dataGridViewCellStyle7;
            this->sldataGridView->RowTemplate->Height = 28;
            this->sldataGridView->Size = System::Drawing::Size(735, 230);
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
            this->label49->Location = System::Drawing::Point(221, 100);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(134, 28);
            this->label49->TabIndex = 2;
            this->label49->Text = L"Subject Name";
            // 
            // addsubcredits
            // 
            this->addsubcredits->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->addsubcredits->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubcredits->Location = System::Drawing::Point(47, 508);
            this->addsubcredits->Name = L"addsubcredits";
            this->addsubcredits->Size = System::Drawing::Size(170, 34);
            this->addsubcredits->TabIndex = 240;
            // 
            // label43
            // 
            this->label43->AutoSize = true;
            this->label43->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label43->Location = System::Drawing::Point(44, 464);
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
            this->label42->Location = System::Drawing::Point(48, 875);
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
            this->label41->Location = System::Drawing::Point(38, 592);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(255, 28);
            this->label41->TabIndex = 242;
            this->label41->Text = L"Rooms to be used(optional)";
            // 
            // addsubbfactor
            // 
            this->addsubbfactor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->addsubbfactor->DecimalPlaces = 2;
            this->addsubbfactor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubbfactor->Location = System::Drawing::Point(50, 938);
            this->addsubbfactor->Name = L"addsubbfactor";
            this->addsubbfactor->Size = System::Drawing::Size(170, 34);
            this->addsubbfactor->TabIndex = 244;
            // 
            // addsubsave
            // 
            this->addsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubsave->Location = System::Drawing::Point(590, 1072);
            this->addsubsave->Name = L"addsubsave";
            this->addsubsave->Size = System::Drawing::Size(116, 58);
            this->addsubsave->TabIndex = 245;
            this->addsubsave->Text = L"Save";
            this->addsubsave->UseVisualStyleBackColor = false;
            this->addsubsave->Click += gcnew System::EventHandler(this, &MyForm::addsubsave_Click);
            // 
            // addsubroomlist
            // 
            this->addsubroomlist->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubroomlist->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->addsubroomlist->CheckOnClick = true;
            this->addsubroomlist->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubroomlist->FormattingEnabled = true;
            this->addsubroomlist->Location = System::Drawing::Point(51, 703);
            this->addsubroomlist->Name = L"addsubroomlist";
            this->addsubroomlist->Size = System::Drawing::Size(224, 155);
            this->addsubroomlist->Sorted = true;
            this->addsubroomlist->TabIndex = 246;
            this->addsubroomlist->ThreeDCheckBoxes = true;
            // 
            // newaddsub
            // 
            this->newaddsub->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->newaddsub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->newaddsub->Location = System::Drawing::Point(790, 1069);
            this->newaddsub->Name = L"newaddsub";
            this->newaddsub->Size = System::Drawing::Size(116, 58);
            this->newaddsub->TabIndex = 247;
            this->newaddsub->Text = L"Clear";
            this->newaddsub->UseVisualStyleBackColor = false;
            this->newaddsub->Click += gcnew System::EventHandler(this, &MyForm::newaddsub_Click);
            // 
            // panel11
            // 
            this->panel11->Controls->Add(this->addsublabyes);
            this->panel11->Controls->Add(this->addsublabno);
            this->panel11->ForeColor = System::Drawing::Color::Black;
            this->panel11->Location = System::Drawing::Point(53, 69);
            this->panel11->Name = L"panel11";
            this->panel11->Size = System::Drawing::Size(219, 52);
            this->panel11->TabIndex = 262;
            // 
            // addsublabyes
            // 
            this->addsublabyes->AutoSize = true;
            this->addsublabyes->Location = System::Drawing::Point(23, 14);
            this->addsublabyes->Name = L"addsublabyes";
            this->addsublabyes->Size = System::Drawing::Size(62, 24);
            this->addsublabyes->TabIndex = 10;
            this->addsublabyes->TabStop = true;
            this->addsublabyes->Text = L"Yes";
            this->addsublabyes->UseVisualStyleBackColor = true;
            this->addsublabyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsublabyes_CheckedChanged);
            // 
            // addsublabno
            // 
            this->addsublabno->AutoSize = true;
            this->addsublabno->Location = System::Drawing::Point(148, 14);
            this->addsublabno->Name = L"addsublabno";
            this->addsublabno->Size = System::Drawing::Size(54, 24);
            this->addsublabno->TabIndex = 11;
            this->addsublabno->TabStop = true;
            this->addsublabno->Text = L"No";
            this->addsublabno->UseVisualStyleBackColor = true;
            this->addsublabno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsublabno_CheckedChanged);
            // 
            // addsubjectpanel
            // 
            this->addsubjectpanel->AutoScroll = true;
            this->addsubjectpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->addsubjectpanel->Controls->Add(this->addsubclusteroptions);
            this->addsubjectpanel->Controls->Add(this->addsubeletablepanel);
            this->addsubjectpanel->Controls->Add(this->addsubcluster);
            this->addsubjectpanel->Controls->Add(this->panel12);
            this->addsubjectpanel->Controls->Add(this->label46);
            this->addsubjectpanel->Controls->Add(this->label47);
            this->addsubjectpanel->Controls->Add(this->label48);
            this->addsubjectpanel->Controls->Add(this->addsubname);
            this->addsubjectpanel->Controls->Add(this->label49);
            this->addsubjectpanel->Controls->Add(this->sedataGridView);
            this->addsubjectpanel->Controls->Add(this->panelsub);
            this->addsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->addsubjectpanel->Name = L"addsubjectpanel";
            this->addsubjectpanel->Size = System::Drawing::Size(1946, 1106);
            this->addsubjectpanel->TabIndex = 124;
            this->addsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addsubjectpanel_Paint);
            // 
            // addsubclusteroptions
            // 
            this->addsubclusteroptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubclusteroptions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubclusteroptions->Location = System::Drawing::Point(719, 829);
            this->addsubclusteroptions->Name = L"addsubclusteroptions";
            this->addsubclusteroptions->Size = System::Drawing::Size(116, 46);
            this->addsubclusteroptions->TabIndex = 265;
            this->addsubclusteroptions->Text = L"Options";
            this->addsubclusteroptions->UseVisualStyleBackColor = false;
            this->addsubclusteroptions->Click += gcnew System::EventHandler(this, &MyForm::addsubclusteroptions_Click);
            // 
            // addsubeletablepanel
            // 
            this->addsubeletablepanel->Controls->Add(this->panel23);
            this->addsubeletablepanel->Controls->Add(this->panel24);
            this->addsubeletablepanel->Controls->Add(this->tableLayoutPanel1);
            this->addsubeletablepanel->Controls->Add(this->label123);
            this->addsubeletablepanel->Controls->Add(this->label124);
            this->addsubeletablepanel->Controls->Add(this->label125);
            this->addsubeletablepanel->Controls->Add(this->label126);
            this->addsubeletablepanel->Controls->Add(this->label127);
            this->addsubeletablepanel->Controls->Add(this->label128);
            this->addsubeletablepanel->Controls->Add(this->label129);
            this->addsubeletablepanel->Controls->Add(this->label130);
            this->addsubeletablepanel->Controls->Add(this->label131);
            this->addsubeletablepanel->Controls->Add(this->label132);
            this->addsubeletablepanel->Controls->Add(this->label133);
            this->addsubeletablepanel->Controls->Add(this->label134);
            this->addsubeletablepanel->Location = System::Drawing::Point(210, 891);
            this->addsubeletablepanel->Name = L"addsubeletablepanel";
            this->addsubeletablepanel->Size = System::Drawing::Size(1183, 621);
            this->addsubeletablepanel->TabIndex = 301;
            // 
            // panel23
            // 
            this->panel23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel23.BackgroundImage")));
            this->panel23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel23->Location = System::Drawing::Point(416, 112);
            this->panel23->Name = L"panel23";
            this->panel23->Size = System::Drawing::Size(44, 413);
            this->panel23->TabIndex = 2;
            // 
            // panel24
            // 
            this->panel24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel24.BackgroundImage")));
            this->panel24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel24->Location = System::Drawing::Point(757, 110);
            this->panel24->Name = L"panel24";
            this->panel24->Size = System::Drawing::Size(44, 436);
            this->panel24->TabIndex = 1;
            // 
            // tableLayoutPanel1
            // 
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
            this->tableLayoutPanel1->Location = System::Drawing::Point(140, 113);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 6;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(949, 435);
            this->tableLayoutPanel1->TabIndex = 260;
            // 
            // label123
            // 
            this->label123->AutoSize = true;
            this->label123->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label123->Location = System::Drawing::Point(158, 72);
            this->label123->Name = L"label123";
            this->label123->Size = System::Drawing::Size(105, 28);
            this->label123->TabIndex = 294;
            this->label123->Text = L"9:00-10:00";
            // 
            // label124
            // 
            this->label124->AutoSize = true;
            this->label124->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label124->Location = System::Drawing::Point(294, 72);
            this->label124->Name = L"label124";
            this->label124->Size = System::Drawing::Size(116, 28);
            this->label124->TabIndex = 295;
            this->label124->Text = L"10:00-11:00";
            // 
            // label125
            // 
            this->label125->AutoSize = true;
            this->label125->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label125->Location = System::Drawing::Point(480, 72);
            this->label125->Name = L"label125";
            this->label125->Size = System::Drawing::Size(116, 28);
            this->label125->TabIndex = 296;
            this->label125->Text = L"11:30-12:30";
            // 
            // label126
            // 
            this->label126->AutoSize = true;
            this->label126->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label126->Location = System::Drawing::Point(635, 72);
            this->label126->Name = L"label126";
            this->label126->Size = System::Drawing::Size(105, 28);
            this->label126->TabIndex = 297;
            this->label126->Text = L"12:30-1:30";
            // 
            // label127
            // 
            this->label127->AutoSize = true;
            this->label127->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label127->Location = System::Drawing::Point(828, 68);
            this->label127->Name = L"label127";
            this->label127->Size = System::Drawing::Size(94, 28);
            this->label127->TabIndex = 298;
            this->label127->Text = L"2:30-3:30";
            // 
            // label128
            // 
            this->label128->AutoSize = true;
            this->label128->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label128->Location = System::Drawing::Point(958, 68);
            this->label128->Name = L"label128";
            this->label128->Size = System::Drawing::Size(94, 28);
            this->label128->TabIndex = 299;
            this->label128->Text = L"3:30-4:30";
            // 
            // label129
            // 
            this->label129->AutoSize = true;
            this->label129->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label129->Location = System::Drawing::Point(43, 495);
            this->label129->Name = L"label129";
            this->label129->Size = System::Drawing::Size(90, 28);
            this->label129->TabIndex = 266;
            this->label129->Text = L"Saturday";
            // 
            // label130
            // 
            this->label130->AutoSize = true;
            this->label130->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label130->Location = System::Drawing::Point(43, 418);
            this->label130->Name = L"label130";
            this->label130->Size = System::Drawing::Size(66, 28);
            this->label130->TabIndex = 265;
            this->label130->Text = L"Friday";
            // 
            // label131
            // 
            this->label131->AutoSize = true;
            this->label131->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label131->Location = System::Drawing::Point(30, 342);
            this->label131->Name = L"label131";
            this->label131->Size = System::Drawing::Size(91, 28);
            this->label131->TabIndex = 264;
            this->label131->Text = L"Thursday";
            // 
            // label132
            // 
            this->label132->AutoSize = true;
            this->label132->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label132->Location = System::Drawing::Point(20, 280);
            this->label132->Name = L"label132";
            this->label132->Size = System::Drawing::Size(113, 28);
            this->label132->TabIndex = 263;
            this->label132->Text = L"Wednesday";
            // 
            // label133
            // 
            this->label133->AutoSize = true;
            this->label133->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label133->Location = System::Drawing::Point(47, 201);
            this->label133->Name = L"label133";
            this->label133->Size = System::Drawing::Size(83, 28);
            this->label133->TabIndex = 262;
            this->label133->Text = L"Tuesday";
            // 
            // label134
            // 
            this->label134->AutoSize = true;
            this->label134->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label134->Location = System::Drawing::Point(41, 132);
            this->label134->Name = L"label134";
            this->label134->Size = System::Drawing::Size(85, 28);
            this->label134->TabIndex = 261;
            this->label134->Text = L"Monday";
            // 
            // addsubcluster
            // 
            this->addsubcluster->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->addsubcluster->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubcluster->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubcluster->FormattingEnabled = true;
            this->addsubcluster->Location = System::Drawing::Point(219, 440);
            this->addsubcluster->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->addsubcluster->Name = L"addsubcluster";
            this->addsubcluster->Size = System::Drawing::Size(294, 36);
            this->addsubcluster->TabIndex = 264;
            // 
            // panel12
            // 
            this->panel12->Controls->Add(this->addsubeleyes);
            this->panel12->Controls->Add(this->addsubeleno);
            this->panel12->ForeColor = System::Drawing::Color::Black;
            this->panel12->Location = System::Drawing::Point(238, 275);
            this->panel12->Name = L"panel12";
            this->panel12->Size = System::Drawing::Size(220, 60);
            this->panel12->TabIndex = 263;
            // 
            // addsubeleyes
            // 
            this->addsubeleyes->AutoSize = true;
            this->addsubeleyes->Location = System::Drawing::Point(5, 21);
            this->addsubeleyes->Name = L"addsubeleyes";
            this->addsubeleyes->Size = System::Drawing::Size(62, 24);
            this->addsubeleyes->TabIndex = 2;
            this->addsubeleyes->TabStop = true;
            this->addsubeleyes->Text = L"Yes";
            this->addsubeleyes->UseVisualStyleBackColor = true;
            this->addsubeleyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsubeleyes_CheckedChanged);
            // 
            // addsubeleno
            // 
            this->addsubeleno->AutoSize = true;
            this->addsubeleno->Location = System::Drawing::Point(139, 21);
            this->addsubeleno->Name = L"addsubeleno";
            this->addsubeleno->Size = System::Drawing::Size(54, 24);
            this->addsubeleno->TabIndex = 3;
            this->addsubeleno->TabStop = true;
            this->addsubeleno->Text = L"No";
            this->addsubeleno->UseVisualStyleBackColor = true;
            this->addsubeleno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addsubeleno_CheckedChanged);
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(214, 546);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(330, 28);
            this->label46->TabIndex = 235;
            this->label46->Text = L"Teacher handling the elective subject";
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(215, 388);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(152, 28);
            this->label47->TabIndex = 24;
            this->label47->Text = L"Name of Cluster";
            // 
            // label48
            // 
            this->label48->AutoSize = true;
            this->label48->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(215, 237);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(148, 28);
            this->label48->TabIndex = 23;
            this->label48->Text = L"Is it an elective\?";
            // 
            // addsubname
            // 
            this->addsubname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubname->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubname->ForeColor = System::Drawing::Color::Black;
            this->addsubname->Location = System::Drawing::Point(226, 150);
            this->addsubname->Name = L"addsubname";
            this->addsubname->Size = System::Drawing::Size(480, 34);
            this->addsubname->TabIndex = 3;
            this->addsubname->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox16_TextChanged);
            // 
            // sedataGridView
            // 
            this->sedataGridView->AllowUserToOrderColumns = true;
            this->sedataGridView->AllowUserToResizeColumns = false;
            this->sedataGridView->AllowUserToResizeRows = false;
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
            this->sedataGridView->Location = System::Drawing::Point(231, 601);
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
            dataGridViewCellStyle14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle14->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::Black;
            this->sedataGridView->RowsDefaultCellStyle = dataGridViewCellStyle14;
            this->sedataGridView->RowTemplate->Height = 28;
            this->sedataGridView->Size = System::Drawing::Size(735, 230);
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
            // panelsub
            // 
            this->panelsub->Controls->Add(this->panel11);
            this->panelsub->Controls->Add(this->label41);
            this->panelsub->Controls->Add(this->label43);
            this->panelsub->Controls->Add(this->addsubcredits);
            this->panelsub->Controls->Add(this->addsubroomlist);
            this->panelsub->Controls->Add(this->addsubbfactor);
            this->panelsub->Controls->Add(this->newaddsub);
            this->panelsub->Controls->Add(this->label44);
            this->panelsub->Controls->Add(this->label42);
            this->panelsub->Controls->Add(this->label45);
            this->panelsub->Controls->Add(this->sldataGridView);
            this->panelsub->Controls->Add(this->addsubsave);
            this->panelsub->Location = System::Drawing::Point(187, 1536);
            this->panelsub->Name = L"panelsub";
            this->panelsub->Size = System::Drawing::Size(1086, 1161);
            this->panelsub->TabIndex = 267;
            this->panelsub->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelsub_Paint);
            // 
            // saveroom
            // 
            this->saveroom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->saveroom->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->saveroom->Location = System::Drawing::Point(28, 47);
            this->saveroom->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->saveroom->Name = L"saveroom";
            this->saveroom->Size = System::Drawing::Size(138, 58);
            this->saveroom->TabIndex = 66;
            this->saveroom->Text = L"Save";
            this->saveroom->UseVisualStyleBackColor = false;
            this->saveroom->Click += gcnew System::EventHandler(this, &MyForm::saveroom_Click);
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label31->Location = System::Drawing::Point(237, -86);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(164, 28);
            this->label31->TabIndex = 67;
            this->label31->Text = L"ClassRoom Name";
            // 
            // roomname
            // 
            this->roomname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->roomname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomname->Location = System::Drawing::Point(241, -25);
            this->roomname->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->roomname->Name = L"roomname";
            this->roomname->Size = System::Drawing::Size(295, 34);
            this->roomname->TabIndex = 68;
            // 
            // roomcapacity
            // 
            this->roomcapacity->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->roomcapacity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomcapacity->Location = System::Drawing::Point(246, 85);
            this->roomcapacity->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->roomcapacity->Name = L"roomcapacity";
            this->roomcapacity->Size = System::Drawing::Size(300, 34);
            this->roomcapacity->TabIndex = 69;
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(242, 36);
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
            this->label29->Location = System::Drawing::Point(242, 150);
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
            this->label28->Location = System::Drawing::Point(236, 270);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(117, 28);
            this->label28->TabIndex = 72;
            this->label28->Text = L"Department";
            // 
            // roomdept
            // 
            this->roomdept->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->roomdept->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->roomdept->FormattingEnabled = true;
            this->roomdept->Location = System::Drawing::Point(239, 309);
            this->roomdept->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->roomdept->Name = L"roomdept";
            this->roomdept->Size = System::Drawing::Size(294, 36);
            this->roomdept->TabIndex = 73;
            // 
            // clearroom
            // 
            this->clearroom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->clearroom->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->clearroom->Location = System::Drawing::Point(227, 47);
            this->clearroom->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->clearroom->Name = L"clearroom";
            this->clearroom->Size = System::Drawing::Size(138, 58);
            this->clearroom->TabIndex = 122;
            this->clearroom->Text = L"Clear All";
            this->clearroom->UseVisualStyleBackColor = false;
            this->clearroom->Click += gcnew System::EventHandler(this, &MyForm::clearroom_Click);
            // 
            // roomlabno
            // 
            this->roomlabno->AutoSize = true;
            this->roomlabno->Location = System::Drawing::Point(149, 20);
            this->roomlabno->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->roomlabno->Name = L"roomlabno";
            this->roomlabno->Size = System::Drawing::Size(54, 24);
            this->roomlabno->TabIndex = 9;
            this->roomlabno->TabStop = true;
            this->roomlabno->Text = L"No";
            this->roomlabno->UseVisualStyleBackColor = true;
            // 
            // roomlabyes
            // 
            this->roomlabyes->AutoSize = true;
            this->roomlabyes->Location = System::Drawing::Point(10, 18);
            this->roomlabyes->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->roomlabyes->Name = L"roomlabyes";
            this->roomlabyes->Size = System::Drawing::Size(62, 24);
            this->roomlabyes->TabIndex = 8;
            this->roomlabyes->TabStop = true;
            this->roomlabyes->Text = L"Yes";
            this->roomlabyes->UseVisualStyleBackColor = true;
            // 
            // addclassroompanel
            // 
            this->addclassroompanel->AutoScroll = true;
            this->addclassroompanel->Controls->Add(this->label5);
            this->addclassroompanel->Controls->Add(this->addroompanel);
            this->addclassroompanel->Controls->Add(this->panel9);
            this->addclassroompanel->Controls->Add(this->panel7);
            this->addclassroompanel->Controls->Add(this->roomdept);
            this->addclassroompanel->Controls->Add(this->label28);
            this->addclassroompanel->Controls->Add(this->label29);
            this->addclassroompanel->Controls->Add(this->label30);
            this->addclassroompanel->Controls->Add(this->roomcapacity);
            this->addclassroompanel->Controls->Add(this->roomname);
            this->addclassroompanel->Controls->Add(this->label31);
            this->addclassroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addclassroompanel->Location = System::Drawing::Point(0, 0);
            this->addclassroompanel->Name = L"addclassroompanel";
            this->addclassroompanel->Size = System::Drawing::Size(1946, 1106);
            this->addclassroompanel->TabIndex = 230;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(236, 396);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(148, 28);
            this->label5->TabIndex = 263;
            this->label5->Text = L"Room Schedule";
            // 
            // addroompanel
            // 
            this->addroompanel->Controls->Add(this->label103);
            this->addroompanel->Controls->Add(this->label104);
            this->addroompanel->Controls->Add(this->label105);
            this->addroompanel->Controls->Add(this->label106);
            this->addroompanel->Controls->Add(this->label107);
            this->addroompanel->Controls->Add(this->label108);
            this->addroompanel->Controls->Add(this->label113);
            this->addroompanel->Controls->Add(this->label114);
            this->addroompanel->Controls->Add(this->label115);
            this->addroompanel->Controls->Add(this->label116);
            this->addroompanel->Controls->Add(this->label117);
            this->addroompanel->Controls->Add(this->label118);
            this->addroompanel->Controls->Add(this->addroomtablepanel);
            this->addroompanel->Location = System::Drawing::Point(230, 426);
            this->addroompanel->Name = L"addroompanel";
            this->addroompanel->Size = System::Drawing::Size(1066, 542);
            this->addroompanel->TabIndex = 262;
            // 
            // label103
            // 
            this->label103->AutoSize = true;
            this->label103->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label103->Location = System::Drawing::Point(139, 46);
            this->label103->Name = L"label103";
            this->label103->Size = System::Drawing::Size(105, 28);
            this->label103->TabIndex = 294;
            this->label103->Text = L"9:00-10:00";
            // 
            // label104
            // 
            this->label104->AutoSize = true;
            this->label104->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label104->Location = System::Drawing::Point(297, 46);
            this->label104->Name = L"label104";
            this->label104->Size = System::Drawing::Size(116, 28);
            this->label104->TabIndex = 295;
            this->label104->Text = L"10:00-11:00";
            // 
            // label105
            // 
            this->label105->AutoSize = true;
            this->label105->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label105->Location = System::Drawing::Point(452, 46);
            this->label105->Name = L"label105";
            this->label105->Size = System::Drawing::Size(116, 28);
            this->label105->TabIndex = 296;
            this->label105->Text = L"11:30-12:30";
            // 
            // label106
            // 
            this->label106->AutoSize = true;
            this->label106->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label106->Location = System::Drawing::Point(624, 46);
            this->label106->Name = L"label106";
            this->label106->Size = System::Drawing::Size(105, 28);
            this->label106->TabIndex = 297;
            this->label106->Text = L"12:30-1:30";
            // 
            // label107
            // 
            this->label107->AutoSize = true;
            this->label107->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label107->Location = System::Drawing::Point(772, 46);
            this->label107->Name = L"label107";
            this->label107->Size = System::Drawing::Size(94, 28);
            this->label107->TabIndex = 298;
            this->label107->Text = L"2:30-3:30";
            // 
            // label108
            // 
            this->label108->AutoSize = true;
            this->label108->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label108->Location = System::Drawing::Point(929, 46);
            this->label108->Name = L"label108";
            this->label108->Size = System::Drawing::Size(94, 28);
            this->label108->TabIndex = 299;
            this->label108->Text = L"3:30-4:30";
            // 
            // label113
            // 
            this->label113->AutoSize = true;
            this->label113->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label113->Location = System::Drawing::Point(26, 481);
            this->label113->Name = L"label113";
            this->label113->Size = System::Drawing::Size(90, 28);
            this->label113->TabIndex = 266;
            this->label113->Text = L"Saturday";
            // 
            // label114
            // 
            this->label114->AutoSize = true;
            this->label114->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label114->Location = System::Drawing::Point(26, 404);
            this->label114->Name = L"label114";
            this->label114->Size = System::Drawing::Size(66, 28);
            this->label114->TabIndex = 265;
            this->label114->Text = L"Friday";
            // 
            // label115
            // 
            this->label115->AutoSize = true;
            this->label115->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label115->Location = System::Drawing::Point(13, 328);
            this->label115->Name = L"label115";
            this->label115->Size = System::Drawing::Size(91, 28);
            this->label115->TabIndex = 264;
            this->label115->Text = L"Thursday";
            // 
            // label116
            // 
            this->label116->AutoSize = true;
            this->label116->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label116->Location = System::Drawing::Point(3, 266);
            this->label116->Name = L"label116";
            this->label116->Size = System::Drawing::Size(113, 28);
            this->label116->TabIndex = 263;
            this->label116->Text = L"Wednesday";
            // 
            // label117
            // 
            this->label117->AutoSize = true;
            this->label117->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label117->Location = System::Drawing::Point(30, 187);
            this->label117->Name = L"label117";
            this->label117->Size = System::Drawing::Size(83, 28);
            this->label117->TabIndex = 262;
            this->label117->Text = L"Tuesday";
            // 
            // label118
            // 
            this->label118->AutoSize = true;
            this->label118->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label118->Location = System::Drawing::Point(24, 118);
            this->label118->Name = L"label118";
            this->label118->Size = System::Drawing::Size(85, 28);
            this->label118->TabIndex = 261;
            this->label118->Text = L"Monday";
            // 
            // addroomtablepanel
            // 
            this->addroomtablepanel->ColumnCount = 6;
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->addroomtablepanel->Location = System::Drawing::Point(123, 99);
            this->addroomtablepanel->Name = L"addroomtablepanel";
            this->addroomtablepanel->RowCount = 6;
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->Size = System::Drawing::Size(940, 426);
            this->addroomtablepanel->TabIndex = 260;
            // 
            // panel9
            // 
            this->panel9->Controls->Add(this->clearroom);
            this->panel9->Controls->Add(this->saveroom);
            this->panel9->Location = System::Drawing::Point(1129, 963);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(376, 156);
            this->panel9->TabIndex = 124;
            // 
            // panel7
            // 
            this->panel7->Controls->Add(this->roomlabyes);
            this->panel7->Controls->Add(this->roomlabno);
            this->panel7->Location = System::Drawing::Point(242, 186);
            this->panel7->Name = L"panel7";
            this->panel7->Size = System::Drawing::Size(237, 58);
            this->panel7->TabIndex = 123;
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
            this->panel2->Controls->Add(this->button22);
            this->panel2->Controls->Add(this->button2);
            this->panel2->Controls->Add(this->deptDataGridView);
            this->panel2->Controls->Add(this->deptlabel);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel2->Location = System::Drawing::Point(0, 0);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(1946, 1106);
            this->panel2->TabIndex = 5;
            this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
            // 
            // button22
            // 
            this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button22->Location = System::Drawing::Point(1276, 803);
            this->button22->Name = L"button22";
            this->button22->Size = System::Drawing::Size(121, 49);
            this->button22->TabIndex = 235;
            this->button22->Text = L"Clear All";
            this->button22->UseVisualStyleBackColor = false;
            this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(1102, 803);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(121, 49);
            this->button2->TabIndex = 234;
            this->button2->Text = L"Save";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // deptDataGridView
            // 
            this->deptDataGridView->AllowUserToOrderColumns = true;
            this->deptDataGridView->AllowUserToResizeColumns = false;
            this->deptDataGridView->AllowUserToResizeRows = false;
            dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle15;
            this->deptDataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deptDataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->deptDataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->deptDataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle16;
            this->deptDataGridView->ColumnHeadersHeight = 40;
            this->deptDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->deptDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
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
            this->deptDataGridView->DefaultCellStyle = dataGridViewCellStyle19;
            this->deptDataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->Location = System::Drawing::Point(372, 349);
            this->deptDataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->deptDataGridView->Name = L"deptDataGridView";
            dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->deptDataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
            this->deptDataGridView->RowHeadersVisible = false;
            this->deptDataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->RowsDefaultCellStyle = dataGridViewCellStyle21;
            this->deptDataGridView->RowTemplate->Height = 28;
            this->deptDataGridView->Size = System::Drawing::Size(735, 304);
            this->deptDataGridView->TabIndex = 233;
            this->deptDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick_1);
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
            // deptlabel
            // 
            this->deptlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptlabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deptlabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
            this->deptlabel->Location = System::Drawing::Point(643, 271);
            this->deptlabel->Name = L"deptlabel";
            this->deptlabel->Size = System::Drawing::Size(304, 32);
            this->deptlabel->TabIndex = 4;
            this->deptlabel->Text = L"Department List";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(292, -3);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(207, 140);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // pictureBox8
            // 
            this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
            this->pictureBox8->Location = System::Drawing::Point(716, 0);
            this->pictureBox8->Name = L"pictureBox8";
            this->pictureBox8->Size = System::Drawing::Size(137, 136);
            this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox8->TabIndex = 1;
            this->pictureBox8->TabStop = false;
            // 
            // pictureBox9
            // 
            this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
            this->pictureBox9->Location = System::Drawing::Point(1761, 55);
            this->pictureBox9->Name = L"pictureBox9";
            this->pictureBox9->Size = System::Drawing::Size(39, 45);
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
            this->pictureBox10->Location = System::Drawing::Point(1846, 55);
            this->pictureBox10->Name = L"pictureBox10";
            this->pictureBox10->Size = System::Drawing::Size(39, 45);
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
            this->pictureBox11->Location = System::Drawing::Point(1672, 55);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(39, 45);
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
            this->pictureBox12->Location = System::Drawing::Point(43, 13);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(143, 120);
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
            this->panel4->Size = System::Drawing::Size(1946, 139);
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
            // editteacherpanel
            // 
            this->editteacherpanel->AutoScroll = true;
            this->editteacherpanel->Controls->Add(this->button3);
            this->editteacherpanel->Controls->Add(this->label51);
            this->editteacherpanel->Controls->Add(this->panel18);
            this->editteacherpanel->Controls->Add(this->panel19);
            this->editteacherpanel->Controls->Add(this->editteacherdepartment);
            this->editteacherpanel->Controls->Add(this->label63);
            this->editteacherpanel->Controls->Add(this->editteachername);
            this->editteacherpanel->Controls->Add(this->label64);
            this->editteacherpanel->Controls->Add(this->label39);
            this->editteacherpanel->Controls->Add(this->teachersearch);
            this->editteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editteacherpanel->Location = System::Drawing::Point(0, 0);
            this->editteacherpanel->Name = L"editteacherpanel";
            this->editteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->editteacherpanel->TabIndex = 264;
            this->editteacherpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editteacherpanel_Paint);
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::White;
            this->button3->FlatAppearance->BorderSize = 0;
            this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button3->Location = System::Drawing::Point(910, 148);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(26, 29);
            this->button3->TabIndex = 301;
            this->button3->Text = L"🔍";
            this->button3->UseVisualStyleBackColor = false;
            // 
            // label51
            // 
            this->label51->AutoSize = true;
            this->label51->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(227, 588);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(161, 28);
            this->label51->TabIndex = 300;
            this->label51->Text = L"Teacher Schedule";
            // 
            // panel18
            // 
            this->panel18->Controls->Add(this->editteacherdelete);
            this->panel18->Controls->Add(this->editteachersave);
            this->panel18->Location = System::Drawing::Point(1037, 1209);
            this->panel18->Name = L"panel18";
            this->panel18->Size = System::Drawing::Size(368, 115);
            this->panel18->TabIndex = 291;
            // 
            // editteacherdelete
            // 
            this->editteacherdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacherdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdelete->Location = System::Drawing::Point(233, 35);
            this->editteacherdelete->Name = L"editteacherdelete";
            this->editteacherdelete->Size = System::Drawing::Size(121, 49);
            this->editteacherdelete->TabIndex = 290;
            this->editteacherdelete->Text = L"Delete";
            this->editteacherdelete->UseVisualStyleBackColor = false;
            this->editteacherdelete->Click += gcnew System::EventHandler(this, &MyForm::editteacherdelete_Click);
            // 
            // editteachersave
            // 
            this->editteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteachersave->Location = System::Drawing::Point(53, 35);
            this->editteachersave->Name = L"editteachersave";
            this->editteachersave->Size = System::Drawing::Size(121, 49);
            this->editteachersave->TabIndex = 273;
            this->editteachersave->Text = L"Save";
            this->editteachersave->UseVisualStyleBackColor = false;
            this->editteachersave->Click += gcnew System::EventHandler(this, &MyForm::editteachersave_Click);
            // 
            // panel19
            // 
            this->panel19->Controls->Add(this->label6);
            this->panel19->Controls->Add(this->label7);
            this->panel19->Controls->Add(this->label8);
            this->panel19->Controls->Add(this->label9);
            this->panel19->Controls->Add(this->label10);
            this->panel19->Controls->Add(this->label11);
            this->panel19->Controls->Add(this->label12);
            this->panel19->Controls->Add(this->label14);
            this->panel19->Controls->Add(this->label40);
            this->panel19->Controls->Add(this->label50);
            this->panel19->Controls->Add(this->label119);
            this->panel19->Controls->Add(this->label120);
            this->panel19->Controls->Add(this->editteachertablepanel);
            this->panel19->Location = System::Drawing::Point(118, 617);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(1163, 550);
            this->panel19->TabIndex = 298;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(221, 56);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(105, 28);
            this->label6->TabIndex = 294;
            this->label6->Text = L"9:00-10:00";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(379, 56);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(116, 28);
            this->label7->TabIndex = 295;
            this->label7->Text = L"10:00-11:00";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(534, 56);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(116, 28);
            this->label8->TabIndex = 296;
            this->label8->Text = L"11:30-12:30";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(706, 56);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(105, 28);
            this->label9->TabIndex = 297;
            this->label9->Text = L"12:30-1:30";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(854, 56);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(94, 28);
            this->label10->TabIndex = 298;
            this->label10->Text = L"2:30-3:30";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(1011, 56);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(94, 28);
            this->label11->TabIndex = 299;
            this->label11->Text = L"3:30-4:30";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(108, 491);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(90, 28);
            this->label12->TabIndex = 266;
            this->label12->Text = L"Saturday";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(108, 414);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(66, 28);
            this->label14->TabIndex = 265;
            this->label14->Text = L"Friday";
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(95, 338);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(91, 28);
            this->label40->TabIndex = 264;
            this->label40->Text = L"Thursday";
            // 
            // label50
            // 
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(85, 276);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(113, 28);
            this->label50->TabIndex = 263;
            this->label50->Text = L"Wednesday";
            // 
            // label119
            // 
            this->label119->AutoSize = true;
            this->label119->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label119->Location = System::Drawing::Point(112, 197);
            this->label119->Name = L"label119";
            this->label119->Size = System::Drawing::Size(83, 28);
            this->label119->TabIndex = 262;
            this->label119->Text = L"Tuesday";
            // 
            // label120
            // 
            this->label120->AutoSize = true;
            this->label120->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label120->Location = System::Drawing::Point(106, 128);
            this->label120->Name = L"label120";
            this->label120->Size = System::Drawing::Size(85, 28);
            this->label120->TabIndex = 261;
            this->label120->Text = L"Monday";
            // 
            // editteachertablepanel
            // 
            this->editteachertablepanel->ColumnCount = 6;
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->Location = System::Drawing::Point(205, 109);
            this->editteachertablepanel->Name = L"editteachertablepanel";
            this->editteachertablepanel->RowCount = 6;
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editteachertablepanel->Size = System::Drawing::Size(940, 426);
            this->editteachertablepanel->TabIndex = 260;
            // 
            // editteacherdepartment
            // 
            this->editteacherdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacherdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdepartment->FormattingEnabled = true;
            this->editteacherdepartment->Location = System::Drawing::Point(220, 465);
            this->editteacherdepartment->Name = L"editteacherdepartment";
            this->editteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->editteacherdepartment->TabIndex = 234;
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label63->Location = System::Drawing::Point(221, 420);
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
            this->editteachername->Location = System::Drawing::Point(220, 339);
            this->editteachername->Name = L"editteachername";
            this->editteachername->Size = System::Drawing::Size(361, 27);
            this->editteachername->TabIndex = 232;
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label64->Location = System::Drawing::Point(216, 293);
            this->label64->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(179, 28);
            this->label64->TabIndex = 231;
            this->label64->Text = L"Enter teacher name";
            // 
            // label39
            // 
            this->label39->AutoSize = true;
            this->label39->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label39->Location = System::Drawing::Point(631, 95);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(242, 30);
            this->label39->TabIndex = 0;
            this->label39->Text = L"Enter the teacher Name";
            // 
            // teachersearch
            // 
            this->teachersearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->teachersearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->teachersearch->ForeColor = System::Drawing::SystemColors::WindowFrame;
            this->teachersearch->FormattingEnabled = true;
            this->teachersearch->ImeMode = System::Windows::Forms::ImeMode::Off;
            this->teachersearch->Location = System::Drawing::Point(577, 146);
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
            this->editroompanel->Controls->Add(this->label4);
            this->editroompanel->Controls->Add(this->panel14);
            this->editroompanel->Controls->Add(this->panel15);
            this->editroompanel->Controls->Add(this->editroomsearchbutton);
            this->editroompanel->Controls->Add(this->label82);
            this->editroompanel->Controls->Add(this->panel6);
            this->editroompanel->Controls->Add(this->editroomdepartment);
            this->editroompanel->Controls->Add(this->label78);
            this->editroompanel->Controls->Add(this->label79);
            this->editroompanel->Controls->Add(this->label80);
            this->editroompanel->Controls->Add(this->editroomcapacity);
            this->editroompanel->Controls->Add(this->editroomname);
            this->editroompanel->Controls->Add(this->label81);
            this->editroompanel->Controls->Add(this->editroomsearch);
            this->editroompanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editroompanel->Location = System::Drawing::Point(0, 0);
            this->editroompanel->Name = L"editroompanel";
            this->editroompanel->Size = System::Drawing::Size(1946, 1106);
            this->editroompanel->TabIndex = 124;
            this->editroompanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editroompanel_Paint);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(236, 757);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(148, 28);
            this->label4->TabIndex = 297;
            this->label4->Text = L"Room Schedule";
            // 
            // panel14
            // 
            this->panel14->Controls->Add(this->editroomdelete);
            this->panel14->Controls->Add(this->editroomsave);
            this->panel14->Location = System::Drawing::Point(1093, 1380);
            this->panel14->Name = L"panel14";
            this->panel14->Size = System::Drawing::Size(464, 141);
            this->panel14->TabIndex = 295;
            // 
            // editroomdelete
            // 
            this->editroomdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomdelete->Location = System::Drawing::Point(274, 35);
            this->editroomdelete->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomdelete->Name = L"editroomdelete";
            this->editroomdelete->Size = System::Drawing::Size(138, 58);
            this->editroomdelete->TabIndex = 180;
            this->editroomdelete->Text = L"Delete";
            this->editroomdelete->UseVisualStyleBackColor = false;
            this->editroomdelete->Click += gcnew System::EventHandler(this, &MyForm::editroomdelete_Click);
            // 
            // editroomsave
            // 
            this->editroomsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->editroomsave->Location = System::Drawing::Point(50, 38);
            this->editroomsave->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomsave->Name = L"editroomsave";
            this->editroomsave->Size = System::Drawing::Size(138, 58);
            this->editroomsave->TabIndex = 124;
            this->editroomsave->Text = L"Save";
            this->editroomsave->UseVisualStyleBackColor = false;
            this->editroomsave->Click += gcnew System::EventHandler(this, &MyForm::editroomsave_Click);
            // 
            // panel15
            // 
            this->panel15->Controls->Add(this->label16);
            this->panel15->Controls->Add(this->label17);
            this->panel15->Controls->Add(this->label18);
            this->panel15->Controls->Add(this->label19);
            this->panel15->Controls->Add(this->label20);
            this->panel15->Controls->Add(this->label21);
            this->panel15->Controls->Add(this->label22);
            this->panel15->Controls->Add(this->label23);
            this->panel15->Controls->Add(this->label24);
            this->panel15->Controls->Add(this->label25);
            this->panel15->Controls->Add(this->label26);
            this->panel15->Controls->Add(this->label27);
            this->panel15->Controls->Add(this->editroomtablepanel);
            this->panel15->Location = System::Drawing::Point(232, 785);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(1066, 550);
            this->panel15->TabIndex = 296;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(139, 46);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(105, 28);
            this->label16->TabIndex = 294;
            this->label16->Text = L"9:00-10:00";
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label17->Location = System::Drawing::Point(297, 46);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(116, 28);
            this->label17->TabIndex = 295;
            this->label17->Text = L"10:00-11:00";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(452, 46);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(116, 28);
            this->label18->TabIndex = 296;
            this->label18->Text = L"11:30-12:30";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label19->Location = System::Drawing::Point(624, 46);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(105, 28);
            this->label19->TabIndex = 297;
            this->label19->Text = L"12:30-1:30";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(772, 46);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(94, 28);
            this->label20->TabIndex = 298;
            this->label20->Text = L"2:30-3:30";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->Location = System::Drawing::Point(929, 46);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(94, 28);
            this->label21->TabIndex = 299;
            this->label21->Text = L"3:30-4:30";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(26, 481);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(90, 28);
            this->label22->TabIndex = 266;
            this->label22->Text = L"Saturday";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(26, 404);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(66, 28);
            this->label23->TabIndex = 265;
            this->label23->Text = L"Friday";
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(13, 328);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(91, 28);
            this->label24->TabIndex = 264;
            this->label24->Text = L"Thursday";
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label25->Location = System::Drawing::Point(3, 266);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(113, 28);
            this->label25->TabIndex = 263;
            this->label25->Text = L"Wednesday";
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(30, 187);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(83, 28);
            this->label26->TabIndex = 262;
            this->label26->Text = L"Tuesday";
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label27->Location = System::Drawing::Point(24, 118);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(85, 28);
            this->label27->TabIndex = 261;
            this->label27->Text = L"Monday";
            // 
            // editroomtablepanel
            // 
            this->editroomtablepanel->ColumnCount = 6;
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->editroomtablepanel->Location = System::Drawing::Point(123, 99);
            this->editroomtablepanel->Name = L"editroomtablepanel";
            this->editroomtablepanel->RowCount = 6;
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->Size = System::Drawing::Size(940, 426);
            this->editroomtablepanel->TabIndex = 260;
            // 
            // editroomsearchbutton
            // 
            this->editroomsearchbutton->BackColor = System::Drawing::Color::White;
            this->editroomsearchbutton->FlatAppearance->BorderSize = 0;
            this->editroomsearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editroomsearchbutton->Location = System::Drawing::Point(969, 178);
            this->editroomsearchbutton->Name = L"editroomsearchbutton";
            this->editroomsearchbutton->Size = System::Drawing::Size(26, 29);
            this->editroomsearchbutton->TabIndex = 292;
            this->editroomsearchbutton->Text = L"🔍";
            this->editroomsearchbutton->UseVisualStyleBackColor = false;
            this->editroomsearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editroomsearchbutton_Click);
            // 
            // label82
            // 
            this->label82->AutoSize = true;
            this->label82->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label82->Location = System::Drawing::Point(677, 116);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(271, 30);
            this->label82->TabIndex = 290;
            this->label82->Text = L"Enter the Classroom Name";
            // 
            // panel6
            // 
            this->panel6->Controls->Add(this->editroomlabyes);
            this->panel6->Controls->Add(this->editroomlabno);
            this->panel6->Location = System::Drawing::Point(235, 581);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(207, 67);
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
            // editroomdepartment
            // 
            this->editroomdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editroomdepartment->FormattingEnabled = true;
            this->editroomdepartment->Location = System::Drawing::Point(232, 697);
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
            this->label78->Location = System::Drawing::Point(229, 658);
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
            this->label79->Location = System::Drawing::Point(235, 538);
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
            this->label80->Location = System::Drawing::Point(235, 424);
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
            this->editroomcapacity->Location = System::Drawing::Point(239, 473);
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
            this->editroomname->Location = System::Drawing::Point(234, 363);
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
            this->label81->Location = System::Drawing::Point(230, 302);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(164, 28);
            this->label81->TabIndex = 125;
            this->label81->Text = L"ClassRoom Name";
            // 
            // editroomsearch
            // 
            this->editroomsearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editroomsearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editroomsearch->ForeColor = System::Drawing::SystemColors::WindowFrame;
            this->editroomsearch->FormattingEnabled = true;
            this->editroomsearch->Location = System::Drawing::Point(638, 173);
            this->editroomsearch->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editroomsearch->Name = L"editroomsearch";
            this->editroomsearch->Size = System::Drawing::Size(360, 36);
            this->editroomsearch->TabIndex = 293;
            this->editroomsearch->Text = L"Search";
            this->editroomsearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocusRoom);
            this->editroomsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownRoom);
            this->editroomsearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocusRoom);
            // 
            // editsubjectpanel
            // 
            this->editsubjectpanel->AutoScroll = true;
            this->editsubjectpanel->Controls->Add(this->editsubelename);
            this->editsubjectpanel->Controls->Add(this->editsubsearchbutton);
            this->editsubjectpanel->Controls->Add(this->label101);
            this->editsubjectpanel->Controls->Add(this->editsubsearch);
            this->editsubjectpanel->Controls->Add(this->editsubdelete);
            this->editsubjectpanel->Controls->Add(this->editsubsave);
            this->editsubjectpanel->Controls->Add(this->editsubbfactor);
            this->editsubjectpanel->Controls->Add(this->label100);
            this->editsubjectpanel->Controls->Add(this->panel13);
            this->editsubjectpanel->Controls->Add(this->editsubroomlist);
            this->editsubjectpanel->Controls->Add(this->label96);
            this->editsubjectpanel->Controls->Add(this->label97);
            this->editsubjectpanel->Controls->Add(this->editsubcredits);
            this->editsubjectpanel->Controls->Add(this->editsublabteacher);
            this->editsubjectpanel->Controls->Add(this->label98);
            this->editsubjectpanel->Controls->Add(this->label99);
            this->editsubjectpanel->Controls->Add(this->label94);
            this->editsubjectpanel->Controls->Add(this->panel10);
            this->editsubjectpanel->Controls->Add(this->label92);
            this->editsubjectpanel->Controls->Add(this->label95);
            this->editsubjectpanel->Controls->Add(this->editsubeleteacher);
            this->editsubjectpanel->Controls->Add(this->editsubname);
            this->editsubjectpanel->Controls->Add(this->label93);
            this->editsubjectpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->editsubjectpanel->Location = System::Drawing::Point(0, 0);
            this->editsubjectpanel->Name = L"editsubjectpanel";
            this->editsubjectpanel->Size = System::Drawing::Size(1946, 1106);
            this->editsubjectpanel->TabIndex = 259;
            this->editsubjectpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::editsubjectpanel_Paint);
            // 
            // editsubelename
            // 
            this->editsubelename->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->editsubelename->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubelename->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubelename->FormattingEnabled = true;
            this->editsubelename->Location = System::Drawing::Point(335, 729);
            this->editsubelename->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editsubelename->Name = L"editsubelename";
            this->editsubelename->Size = System::Drawing::Size(294, 36);
            this->editsubelename->TabIndex = 313;
            // 
            // editsubsearchbutton
            // 
            this->editsubsearchbutton->BackColor = System::Drawing::Color::White;
            this->editsubsearchbutton->FlatAppearance->BorderSize = 0;
            this->editsubsearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editsubsearchbutton->Location = System::Drawing::Point(972, 254);
            this->editsubsearchbutton->Name = L"editsubsearchbutton";
            this->editsubsearchbutton->Size = System::Drawing::Size(26, 29);
            this->editsubsearchbutton->TabIndex = 311;
            this->editsubsearchbutton->Text = L"🔍";
            this->editsubsearchbutton->UseVisualStyleBackColor = false;
            this->editsubsearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editsubsearchbutton_Click);
            // 
            // label101
            // 
            this->label101->AutoSize = true;
            this->label101->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label101->Location = System::Drawing::Point(676, 197);
            this->label101->Name = L"label101";
            this->label101->Size = System::Drawing::Size(241, 30);
            this->label101->TabIndex = 310;
            this->label101->Text = L"Enter the Subject Name";
            // 
            // editsubsearch
            // 
            this->editsubsearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubsearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubsearch->ForeColor = System::Drawing::SystemColors::WindowFrame;
            this->editsubsearch->FormattingEnabled = true;
            this->editsubsearch->Location = System::Drawing::Point(639, 248);
            this->editsubsearch->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editsubsearch->Name = L"editsubsearch";
            this->editsubsearch->Size = System::Drawing::Size(360, 36);
            this->editsubsearch->TabIndex = 312;
            this->editsubsearch->Text = L"Search";
            this->editsubsearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocusSub);
            this->editsubsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownsubject);
            this->editsubsearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocusSub);
            // 
            // editsubdelete
            // 
            this->editsubdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubdelete->Location = System::Drawing::Point(1230, 2211);
            this->editsubdelete->Name = L"editsubdelete";
            this->editsubdelete->Size = System::Drawing::Size(116, 58);
            this->editsubdelete->TabIndex = 309;
            this->editsubdelete->Text = L"Delete";
            this->editsubdelete->UseVisualStyleBackColor = false;
            this->editsubdelete->Click += gcnew System::EventHandler(this, &MyForm::editsubdelete_Click);
            // 
            // editsubsave
            // 
            this->editsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubsave->Location = System::Drawing::Point(1064, 2211);
            this->editsubsave->Name = L"editsubsave";
            this->editsubsave->Size = System::Drawing::Size(116, 58);
            this->editsubsave->TabIndex = 308;
            this->editsubsave->Text = L"Save";
            this->editsubsave->UseVisualStyleBackColor = false;
            this->editsubsave->Click += gcnew System::EventHandler(this, &MyForm::editsubsave_Click);
            // 
            // editsubbfactor
            // 
            this->editsubbfactor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->editsubbfactor->DecimalPlaces = 2;
            this->editsubbfactor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubbfactor->Location = System::Drawing::Point(389, 2091);
            this->editsubbfactor->Name = L"editsubbfactor";
            this->editsubbfactor->Size = System::Drawing::Size(170, 34);
            this->editsubbfactor->TabIndex = 307;
            // 
            // label100
            // 
            this->label100->AutoSize = true;
            this->label100->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label100->Location = System::Drawing::Point(398, 2037);
            this->label100->Name = L"label100";
            this->label100->Size = System::Drawing::Size(75, 28);
            this->label100->TabIndex = 306;
            this->label100->Text = L"bfactor";
            // 
            // panel13
            // 
            this->panel13->Controls->Add(this->editsublabyes);
            this->panel13->Controls->Add(this->editsublabno);
            this->panel13->ForeColor = System::Drawing::Color::Black;
            this->panel13->Location = System::Drawing::Point(367, 1234);
            this->panel13->Name = L"panel13";
            this->panel13->Size = System::Drawing::Size(219, 52);
            this->panel13->TabIndex = 305;
            // 
            // editsublabyes
            // 
            this->editsublabyes->AutoSize = true;
            this->editsublabyes->Location = System::Drawing::Point(23, 14);
            this->editsublabyes->Name = L"editsublabyes";
            this->editsublabyes->Size = System::Drawing::Size(62, 24);
            this->editsublabyes->TabIndex = 10;
            this->editsublabyes->TabStop = true;
            this->editsublabyes->Text = L"Yes";
            this->editsublabyes->UseVisualStyleBackColor = true;
            this->editsublabyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsublabyes_CheckedChanged);
            // 
            // editsublabno
            // 
            this->editsublabno->AutoSize = true;
            this->editsublabno->Location = System::Drawing::Point(148, 14);
            this->editsublabno->Name = L"editsublabno";
            this->editsublabno->Size = System::Drawing::Size(54, 24);
            this->editsublabno->TabIndex = 11;
            this->editsublabno->TabStop = true;
            this->editsublabno->Text = L"No";
            this->editsublabno->UseVisualStyleBackColor = true;
            this->editsublabno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsublabno_CheckedChanged);
            // 
            // editsubroomlist
            // 
            this->editsubroomlist->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubroomlist->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubroomlist->CheckOnClick = true;
            this->editsubroomlist->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubroomlist->FormattingEnabled = true;
            this->editsubroomlist->Location = System::Drawing::Point(393, 1830);
            this->editsubroomlist->Name = L"editsubroomlist";
            this->editsubroomlist->Size = System::Drawing::Size(224, 155);
            this->editsubroomlist->Sorted = true;
            this->editsubroomlist->TabIndex = 304;
            this->editsubroomlist->ThreeDCheckBoxes = true;
            // 
            // label96
            // 
            this->label96->AutoSize = true;
            this->label96->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label96->Location = System::Drawing::Point(384, 1753);
            this->label96->Name = L"label96";
            this->label96->Size = System::Drawing::Size(255, 28);
            this->label96->TabIndex = 303;
            this->label96->Text = L"Rooms to be used(optional)";
            // 
            // label97
            // 
            this->label97->AutoSize = true;
            this->label97->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label97->Location = System::Drawing::Point(390, 1625);
            this->label97->Name = L"label97";
            this->label97->Size = System::Drawing::Size(125, 28);
            this->label97->TabIndex = 302;
            this->label97->Text = L"No of credits";
            // 
            // editsubcredits
            // 
            this->editsubcredits->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->editsubcredits->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubcredits->Location = System::Drawing::Point(393, 1669);
            this->editsubcredits->Name = L"editsubcredits";
            this->editsubcredits->Size = System::Drawing::Size(170, 34);
            this->editsubcredits->TabIndex = 301;
            // 
            // editsublabteacher
            // 
            this->editsublabteacher->AllowUserToOrderColumns = true;
            dataGridViewCellStyle22->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->editsublabteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle22;
            this->editsublabteacher->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsublabteacher->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsublabteacher->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsublabteacher->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle23->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle23->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteacher->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle23;
            this->editsublabteacher->ColumnHeadersHeight = 40;
            this->editsublabteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsublabteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->editsublabteachercombo,
                    this->dataGridViewButtonColumn11
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
            this->editsublabteacher->DefaultCellStyle = dataGridViewCellStyle26;
            this->editsublabteacher->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsublabteacher->Location = System::Drawing::Point(395, 1378);
            this->editsublabteacher->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsublabteacher->Name = L"editsublabteacher";
            dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle27->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle27->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteacher->RowHeadersDefaultCellStyle = dataGridViewCellStyle27;
            this->editsublabteacher->RowHeadersVisible = false;
            this->editsublabteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle28->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
            this->editsublabteacher->RowsDefaultCellStyle = dataGridViewCellStyle28;
            this->editsublabteacher->RowTemplate->Height = 28;
            this->editsublabteacher->Size = System::Drawing::Size(735, 230);
            this->editsublabteacher->TabIndex = 300;
            this->editsublabteacher->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::editsublabteacher_CellContentClick);
            // 
            // editsublabteachercombo
            // 
            dataGridViewCellStyle24->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle24->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle24->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteachercombo->DefaultCellStyle = dataGridViewCellStyle24;
            this->editsublabteachercombo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editsublabteachercombo->HeaderText = L"Teacher Name";
            this->editsublabteachercombo->MinimumWidth = 30;
            this->editsublabteachercombo->Name = L"editsublabteachercombo";
            this->editsublabteachercombo->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteachercombo->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
            this->editsublabteachercombo->Width = 350;
            // 
            // dataGridViewButtonColumn11
            // 
            this->dataGridViewButtonColumn11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn11->DefaultCellStyle = dataGridViewCellStyle25;
            this->dataGridViewButtonColumn11->DividerWidth = 1;
            this->dataGridViewButtonColumn11->HeaderText = L"";
            this->dataGridViewButtonColumn11->MinimumWidth = 100;
            this->dataGridViewButtonColumn11->Name = L"dataGridViewButtonColumn11";
            this->dataGridViewButtonColumn11->ReadOnly = true;
            this->dataGridViewButtonColumn11->Text = L"Delete";
            this->dataGridViewButtonColumn11->UseColumnTextForButtonValue = true;
            // 
            // label98
            // 
            this->label98->AutoSize = true;
            this->label98->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label98->Location = System::Drawing::Point(359, 1337);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(299, 28);
            this->label98->TabIndex = 299;
            this->label98->Text = L"Teachers handling the lab subject";
            // 
            // label99
            // 
            this->label99->AutoSize = true;
            this->label99->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label99->Location = System::Drawing::Point(361, 1181);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(98, 28);
            this->label99->TabIndex = 298;
            this->label99->Text = L"Is it a lab\?";
            this->label99->Click += gcnew System::EventHandler(this, &MyForm::label99_Click);
            // 
            // label94
            // 
            this->label94->AutoSize = true;
            this->label94->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label94->Location = System::Drawing::Point(332, 839);
            this->label94->Name = L"label94";
            this->label94->Size = System::Drawing::Size(330, 28);
            this->label94->TabIndex = 297;
            this->label94->Text = L"Teacher handling the elective subject";
            // 
            // panel10
            // 
            this->panel10->Controls->Add(this->editsubeleyes);
            this->panel10->Controls->Add(this->editsubeleno);
            this->panel10->ForeColor = System::Drawing::Color::Black;
            this->panel10->Location = System::Drawing::Point(350, 571);
            this->panel10->Name = L"panel10";
            this->panel10->Size = System::Drawing::Size(220, 60);
            this->panel10->TabIndex = 267;
            // 
            // editsubeleyes
            // 
            this->editsubeleyes->AutoSize = true;
            this->editsubeleyes->Location = System::Drawing::Point(5, 21);
            this->editsubeleyes->Name = L"editsubeleyes";
            this->editsubeleyes->Size = System::Drawing::Size(62, 24);
            this->editsubeleyes->TabIndex = 2;
            this->editsubeleyes->TabStop = true;
            this->editsubeleyes->Text = L"Yes";
            this->editsubeleyes->UseVisualStyleBackColor = true;
            this->editsubeleyes->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsubeleyes_CheckedChanged);
            // 
            // editsubeleno
            // 
            this->editsubeleno->AutoSize = true;
            this->editsubeleno->Location = System::Drawing::Point(139, 21);
            this->editsubeleno->Name = L"editsubeleno";
            this->editsubeleno->Size = System::Drawing::Size(54, 24);
            this->editsubeleno->TabIndex = 3;
            this->editsubeleno->TabStop = true;
            this->editsubeleno->Text = L"No";
            this->editsubeleno->UseVisualStyleBackColor = true;
            this->editsubeleno->CheckedChanged += gcnew System::EventHandler(this, &MyForm::editsubeleno_CheckedChanged);
            // 
            // label92
            // 
            this->label92->AutoSize = true;
            this->label92->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label92->Location = System::Drawing::Point(322, 518);
            this->label92->Name = L"label92";
            this->label92->Size = System::Drawing::Size(148, 28);
            this->label92->TabIndex = 266;
            this->label92->Text = L"Is it an elective\?";
            // 
            // label95
            // 
            this->label95->AutoSize = true;
            this->label95->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label95->Location = System::Drawing::Point(333, 681);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(158, 28);
            this->label95->TabIndex = 294;
            this->label95->Text = L"Name of elective";
            // 
            // editsubeleteacher
            // 
            this->editsubeleteacher->AllowUserToOrderColumns = true;
            dataGridViewCellStyle29->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle29;
            this->editsubeleteacher->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubeleteacher->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsubeleteacher->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle30->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteacher->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle30;
            this->editsubeleteacher->ColumnHeadersHeight = 40;
            this->editsubeleteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsubeleteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->editsubeleteachercombo,
                    this->dataGridViewButtonColumn10
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
            this->editsubeleteacher->DefaultCellStyle = dataGridViewCellStyle33;
            this->editsubeleteacher->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->Location = System::Drawing::Point(342, 893);
            this->editsubeleteacher->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsubeleteacher->Name = L"editsubeleteacher";
            dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle34->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle34->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle34->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteacher->RowHeadersDefaultCellStyle = dataGridViewCellStyle34;
            this->editsubeleteacher->RowHeadersVisible = false;
            this->editsubeleteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle35->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle35->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle35->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->RowsDefaultCellStyle = dataGridViewCellStyle35;
            this->editsubeleteacher->RowTemplate->Height = 28;
            this->editsubeleteacher->Size = System::Drawing::Size(735, 230);
            this->editsubeleteacher->TabIndex = 296;
            this->editsubeleteacher->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::editsubeleteacher_CellContentClick);
            // 
            // editsubeleteachercombo
            // 
            dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle31->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteachercombo->DefaultCellStyle = dataGridViewCellStyle31;
            this->editsubeleteachercombo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editsubeleteachercombo->HeaderText = L"Teacher Name";
            this->editsubeleteachercombo->MinimumWidth = 30;
            this->editsubeleteachercombo->Name = L"editsubeleteachercombo";
            this->editsubeleteachercombo->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteachercombo->Width = 350;
            // 
            // dataGridViewButtonColumn10
            // 
            this->dataGridViewButtonColumn10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn10->DefaultCellStyle = dataGridViewCellStyle32;
            this->dataGridViewButtonColumn10->DividerWidth = 1;
            this->dataGridViewButtonColumn10->HeaderText = L"";
            this->dataGridViewButtonColumn10->MinimumWidth = 100;
            this->dataGridViewButtonColumn10->Name = L"dataGridViewButtonColumn10";
            this->dataGridViewButtonColumn10->ReadOnly = true;
            this->dataGridViewButtonColumn10->Text = L"Delete";
            this->dataGridViewButtonColumn10->UseColumnTextForButtonValue = true;
            // 
            // editsubname
            // 
            this->editsubname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubname->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubname->ForeColor = System::Drawing::Color::Black;
            this->editsubname->Location = System::Drawing::Point(333, 431);
            this->editsubname->Name = L"editsubname";
            this->editsubname->Size = System::Drawing::Size(480, 34);
            this->editsubname->TabIndex = 265;
            // 
            // label93
            // 
            this->label93->AutoSize = true;
            this->label93->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label93->ForeColor = System::Drawing::Color::Black;
            this->label93->Location = System::Drawing::Point(328, 370);
            this->label93->Name = L"label93";
            this->label93->Size = System::Drawing::Size(134, 28);
            this->label93->TabIndex = 264;
            this->label93->Text = L"Subject Name";
            // 
            // settingspanel
            // 
            this->settingspanel->AutoScroll = true;
            this->settingspanel->Controls->Add(this->panel20);
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
            // panel20
            // 
            this->panel20->Controls->Add(this->panel21);
            this->panel20->Controls->Add(this->panel22);
            this->panel20->Controls->Add(this->tableLayoutPanel2);
            this->panel20->Controls->Add(this->label83);
            this->panel20->Controls->Add(this->label84);
            this->panel20->Controls->Add(this->label85);
            this->panel20->Controls->Add(this->label86);
            this->panel20->Controls->Add(this->label87);
            this->panel20->Controls->Add(this->label88);
            this->panel20->Controls->Add(this->label89);
            this->panel20->Controls->Add(this->label90);
            this->panel20->Controls->Add(this->label91);
            this->panel20->Controls->Add(this->label102);
            this->panel20->Controls->Add(this->label121);
            this->panel20->Controls->Add(this->label122);
            this->panel20->Location = System::Drawing::Point(350, 494);
            this->panel20->Name = L"panel20";
            this->panel20->Size = System::Drawing::Size(1183, 621);
            this->panel20->TabIndex = 300;
            // 
            // panel21
            // 
            this->panel21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel21.BackgroundImage")));
            this->panel21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel21->Location = System::Drawing::Point(416, 112);
            this->panel21->Name = L"panel21";
            this->panel21->Size = System::Drawing::Size(44, 413);
            this->panel21->TabIndex = 2;
            // 
            // panel22
            // 
            this->panel22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel22.BackgroundImage")));
            this->panel22->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel22->Location = System::Drawing::Point(757, 110);
            this->panel22->Name = L"panel22";
            this->panel22->Size = System::Drawing::Size(44, 436);
            this->panel22->TabIndex = 1;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->ColumnCount = 8;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66686F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->tableLayoutPanel2->Location = System::Drawing::Point(140, 113);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 6;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(949, 435);
            this->tableLayoutPanel2->TabIndex = 260;
            this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel2_Paint);
            // 
            // label83
            // 
            this->label83->AutoSize = true;
            this->label83->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label83->Location = System::Drawing::Point(158, 72);
            this->label83->Name = L"label83";
            this->label83->Size = System::Drawing::Size(105, 28);
            this->label83->TabIndex = 294;
            this->label83->Text = L"9:00-10:00";
            // 
            // label84
            // 
            this->label84->AutoSize = true;
            this->label84->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label84->Location = System::Drawing::Point(294, 72);
            this->label84->Name = L"label84";
            this->label84->Size = System::Drawing::Size(116, 28);
            this->label84->TabIndex = 295;
            this->label84->Text = L"10:00-11:00";
            // 
            // label85
            // 
            this->label85->AutoSize = true;
            this->label85->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label85->Location = System::Drawing::Point(480, 72);
            this->label85->Name = L"label85";
            this->label85->Size = System::Drawing::Size(116, 28);
            this->label85->TabIndex = 296;
            this->label85->Text = L"11:30-12:30";
            // 
            // label86
            // 
            this->label86->AutoSize = true;
            this->label86->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label86->Location = System::Drawing::Point(635, 72);
            this->label86->Name = L"label86";
            this->label86->Size = System::Drawing::Size(105, 28);
            this->label86->TabIndex = 297;
            this->label86->Text = L"12:30-1:30";
            // 
            // label87
            // 
            this->label87->AutoSize = true;
            this->label87->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label87->Location = System::Drawing::Point(828, 68);
            this->label87->Name = L"label87";
            this->label87->Size = System::Drawing::Size(94, 28);
            this->label87->TabIndex = 298;
            this->label87->Text = L"2:30-3:30";
            // 
            // label88
            // 
            this->label88->AutoSize = true;
            this->label88->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label88->Location = System::Drawing::Point(958, 68);
            this->label88->Name = L"label88";
            this->label88->Size = System::Drawing::Size(94, 28);
            this->label88->TabIndex = 299;
            this->label88->Text = L"3:30-4:30";
            // 
            // label89
            // 
            this->label89->AutoSize = true;
            this->label89->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label89->Location = System::Drawing::Point(43, 495);
            this->label89->Name = L"label89";
            this->label89->Size = System::Drawing::Size(90, 28);
            this->label89->TabIndex = 266;
            this->label89->Text = L"Saturday";
            // 
            // label90
            // 
            this->label90->AutoSize = true;
            this->label90->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label90->Location = System::Drawing::Point(43, 418);
            this->label90->Name = L"label90";
            this->label90->Size = System::Drawing::Size(66, 28);
            this->label90->TabIndex = 265;
            this->label90->Text = L"Friday";
            // 
            // label91
            // 
            this->label91->AutoSize = true;
            this->label91->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label91->Location = System::Drawing::Point(30, 342);
            this->label91->Name = L"label91";
            this->label91->Size = System::Drawing::Size(91, 28);
            this->label91->TabIndex = 264;
            this->label91->Text = L"Thursday";
            // 
            // label102
            // 
            this->label102->AutoSize = true;
            this->label102->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label102->Location = System::Drawing::Point(20, 280);
            this->label102->Name = L"label102";
            this->label102->Size = System::Drawing::Size(113, 28);
            this->label102->TabIndex = 263;
            this->label102->Text = L"Wednesday";
            // 
            // label121
            // 
            this->label121->AutoSize = true;
            this->label121->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label121->Location = System::Drawing::Point(47, 201);
            this->label121->Name = L"label121";
            this->label121->Size = System::Drawing::Size(83, 28);
            this->label121->TabIndex = 262;
            this->label121->Text = L"Tuesday";
            // 
            // label122
            // 
            this->label122->AutoSize = true;
            this->label122->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label122->Location = System::Drawing::Point(41, 132);
            this->label122->Name = L"label122";
            this->label122->Size = System::Drawing::Size(85, 28);
            this->label122->TabIndex = 261;
            this->label122->Text = L"Monday";
            // 
            // label112
            // 
            this->label112->AutoSize = true;
            this->label112->Location = System::Drawing::Point(449, 454);
            this->label112->Name = L"label112";
            this->label112->Size = System::Drawing::Size(152, 20);
            this->label112->TabIndex = 4;
            this->label112->Text = L"TimeTable Structure";
            // 
            // trackBar2
            // 
            this->trackBar2->Location = System::Drawing::Point(437, 290);
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
            this->label111->Location = System::Drawing::Point(449, 247);
            this->label111->Name = L"label111";
            this->label111->Size = System::Drawing::Size(265, 20);
            this->label111->TabIndex = 2;
            this->label111->Text = L"Maximum number of classes per day";
            // 
            // trackBar1
            // 
            this->trackBar1->Location = System::Drawing::Point(431, 136);
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
            this->label110->Location = System::Drawing::Point(443, 93);
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
            this->button1->Location = System::Drawing::Point(0, 200);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(324, 44);
            this->button1->TabIndex = 2;
            this->button1->Text = L"               Departments";
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
            this->button6->ForeColor = System::Drawing::Color::White;
            this->button6->Location = System::Drawing::Point(58, 300);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(269, 44);
            this->button6->TabIndex = 12;
            this->button6->Text = L"Classrooms";
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
            this->button9->ForeColor = System::Drawing::Color::White;
            this->button9->Location = System::Drawing::Point(58, 406);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(271, 44);
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
            this->button5->Location = System::Drawing::Point(21, 343);
            this->button5->Margin = System::Windows::Forms::Padding(0);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(306, 34);
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
            this->button8->Location = System::Drawing::Point(21, 450);
            this->button8->Margin = System::Windows::Forms::Padding(0);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(306, 34);
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
            this->button4->Location = System::Drawing::Point(21, 373);
            this->button4->Margin = System::Windows::Forms::Padding(0);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(306, 34);
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
            this->button7->Location = System::Drawing::Point(18, 474);
            this->button7->Margin = System::Windows::Forms::Padding(0);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(309, 34);
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
            this->button12->Location = System::Drawing::Point(84, 512);
            this->button12->Name = L"button12";
            this->button12->Size = System::Drawing::Size(246, 44);
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
            this->button11->Location = System::Drawing::Point(24, 558);
            this->button11->Margin = System::Windows::Forms::Padding(0);
            this->button11->Name = L"button11";
            this->button11->Size = System::Drawing::Size(305, 34);
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
            this->button10->Location = System::Drawing::Point(24, 588);
            this->button10->Margin = System::Windows::Forms::Padding(0);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(303, 34);
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
            this->button15->Location = System::Drawing::Point(60, 612);
            this->button15->Name = L"button15";
            this->button15->Size = System::Drawing::Size(267, 44);
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
            this->button14->Location = System::Drawing::Point(-3, 654);
            this->button14->Margin = System::Windows::Forms::Padding(0);
            this->button14->Name = L"button14";
            this->button14->Size = System::Drawing::Size(267, 34);
            this->button14->TabIndex = 23;
            this->button14->Text = L"Add                 ";
            this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
            this->button13->Location = System::Drawing::Point(-3, 684);
            this->button13->Margin = System::Windows::Forms::Padding(0);
            this->button13->Name = L"button13";
            this->button13->Size = System::Drawing::Size(267, 34);
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
            this->Homebutton1->Location = System::Drawing::Point(3, 85);
            this->Homebutton1->Name = L"Homebutton1";
            this->Homebutton1->Size = System::Drawing::Size(321, 44);
            this->Homebutton1->TabIndex = 26;
            this->Homebutton1->Text = L"    Home";
            this->Homebutton1->UseVisualStyleBackColor = false;
            this->Homebutton1->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->panel3->Location = System::Drawing::Point(15, 85);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(4, 44);
            this->panel3->TabIndex = 6;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(68, 85);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(43, 44);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 6;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(68, 195);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(35, 44);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(68, 300);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(35, 44);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            // 
            // pictureBox5
            // 
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(68, 398);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(35, 44);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            // 
            // pictureBox6
            // 
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(68, 512);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(35, 44);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            // 
            // pictureBox7
            // 
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(68, 612);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(35, 44);
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
            this->panel1->Location = System::Drawing::Point(0, 139);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(324, 967);
            this->panel1->TabIndex = 259;
            // 
            // dataGridView3
            // 
            this->dataGridView3->AllowUserToOrderColumns = true;
            dataGridViewCellStyle36->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle36->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle36->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle36->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle36;
            this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle37->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle37->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle37->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle37;
            this->dataGridView3->ColumnHeadersHeight = 40;
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->eSubject,
                    this->dataGridViewButtonColumn3
            });
            dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle40->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle40->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle40->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle40->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle40->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView3->DefaultCellStyle = dataGridViewCellStyle40;
            this->dataGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView3->Location = System::Drawing::Point(364, 858);
            this->dataGridView3->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView3->Name = L"dataGridView3";
            dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle41->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle41->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle41->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle41->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle41->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView3->RowHeadersDefaultCellStyle = dataGridViewCellStyle41;
            this->dataGridView3->RowHeadersVisible = false;
            this->dataGridView3->RowHeadersWidth = 62;
            dataGridViewCellStyle42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle42->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle42->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle42->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView3->RowsDefaultCellStyle = dataGridViewCellStyle42;
            this->dataGridView3->RowTemplate->Height = 28;
            this->dataGridView3->Size = System::Drawing::Size(735, 230);
            this->dataGridView3->TabIndex = 253;
            this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
            // 
            // eSubject
            // 
            dataGridViewCellStyle38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle38->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle38->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle38->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle38->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle38->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->DefaultCellStyle = dataGridViewCellStyle38;
            this->eSubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->eSubject->HeaderText = L"eSubject";
            this->eSubject->MinimumWidth = 30;
            this->eSubject->Name = L"eSubject";
            this->eSubject->Resizable = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->Width = 350;
            // 
            // dataGridViewButtonColumn3
            // 
            this->dataGridViewButtonColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle39->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle39->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle39->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle39;
            this->dataGridViewButtonColumn3->DividerWidth = 1;
            this->dataGridViewButtonColumn3->HeaderText = L"";
            this->dataGridViewButtonColumn3->MinimumWidth = 100;
            this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
            this->dataGridViewButtonColumn3->ReadOnly = true;
            this->dataGridViewButtonColumn3->Text = L"Delete";
            this->dataGridViewButtonColumn3->UseColumnTextForButtonValue = true;
            // 
            // dataGridView6
            // 
            this->dataGridView6->AllowUserToOrderColumns = true;
            dataGridViewCellStyle43->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle43->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle43->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle43->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle43;
            this->dataGridView6->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView6->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView6->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle44->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle44->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle44->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle44->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle44->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle44->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle44;
            this->dataGridView6->ColumnHeadersHeight = 40;
            this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->csubject,
                    this->cteacher, this->dataGridViewButtonColumn6
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
            this->dataGridView6->DefaultCellStyle = dataGridViewCellStyle48;
            this->dataGridView6->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView6->Location = System::Drawing::Point(366, 566);
            this->dataGridView6->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView6->Name = L"dataGridView6";
            dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle49->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle49->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle49->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle49->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle49->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView6->RowHeadersDefaultCellStyle = dataGridViewCellStyle49;
            this->dataGridView6->RowHeadersVisible = false;
            this->dataGridView6->RowHeadersWidth = 62;
            dataGridViewCellStyle50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle50->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle50->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle50->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView6->RowsDefaultCellStyle = dataGridViewCellStyle50;
            this->dataGridView6->RowTemplate->Height = 28;
            this->dataGridView6->Size = System::Drawing::Size(735, 170);
            this->dataGridView6->TabIndex = 257;
            this->dataGridView6->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView6_CellContentClick);
            // 
            // csubject
            // 
            dataGridViewCellStyle45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle45->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle45->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle45->SelectionForeColor = System::Drawing::Color::Black;
            this->csubject->DefaultCellStyle = dataGridViewCellStyle45;
            this->csubject->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
            this->csubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->csubject->HeaderText = L"Core Subject";
            this->csubject->MinimumWidth = 8;
            this->csubject->Name = L"csubject";
            this->csubject->Width = 150;
            // 
            // cteacher
            // 
            dataGridViewCellStyle46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle46->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle46->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle46->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->cteacher->DefaultCellStyle = dataGridViewCellStyle46;
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
            dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle47->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn6->DefaultCellStyle = dataGridViewCellStyle47;
            this->dataGridViewButtonColumn6->DividerWidth = 1;
            this->dataGridViewButtonColumn6->HeaderText = L"";
            this->dataGridViewButtonColumn6->MinimumWidth = 100;
            this->dataGridViewButtonColumn6->Name = L"dataGridViewButtonColumn6";
            this->dataGridViewButtonColumn6->ReadOnly = true;
            this->dataGridViewButtonColumn6->Text = L"Delete";
            this->dataGridViewButtonColumn6->UseColumnTextForButtonValue = true;
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(356, 80);
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
            this->maskedTextBox2->Location = System::Drawing::Point(361, 121);
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
            this->comboBox3->Location = System::Drawing::Point(365, 246);
            this->comboBox3->Name = L"comboBox3";
            this->comboBox3->Size = System::Drawing::Size(406, 36);
            this->comboBox3->TabIndex = 245;
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->Location = System::Drawing::Point(359, 332);
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
            this->maskedTextBox1->Location = System::Drawing::Point(367, 384);
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
            this->label36->Location = System::Drawing::Point(359, 470);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(520, 84);
            this->label36->TabIndex = 243;
            this->label36->Text = L"Select the subjects taught and their corresponding teacher\r\n\r\n for non-elective a"
                L"nd non-lab subjects";
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Location = System::Drawing::Point(371, 1477);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(287, 124);
            this->checkedListBox1->TabIndex = 250;
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label34->Location = System::Drawing::Point(378, 1404);
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
            this->button19->Location = System::Drawing::Point(997, 1599);
            this->button19->Name = L"button19";
            this->button19->Size = System::Drawing::Size(147, 48);
            this->button19->TabIndex = 248;
            this->button19->Text = L"Generate";
            this->button19->UseVisualStyleBackColor = false;
            this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
            // 
            // button17
            // 
            this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button17->Location = System::Drawing::Point(1166, 1599);
            this->button17->Name = L"button17";
            this->button17->Size = System::Drawing::Size(104, 48);
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
            this->button16->Location = System::Drawing::Point(1296, 1597);
            this->button16->Name = L"button16";
            this->button16->Size = System::Drawing::Size(132, 48);
            this->button16->TabIndex = 246;
            this->button16->Text = L"Clear";
            this->button16->UseVisualStyleBackColor = false;
            this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToOrderColumns = true;
            dataGridViewCellStyle51->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle51->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle51->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle51->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
            this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle52->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle52->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle52->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
            this->dataGridView1->ColumnHeadersHeight = 40;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->lsubject,
                    this->dataGridViewButtonColumn2
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
            this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle55;
            this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->dataGridView1->Location = System::Drawing::Point(371, 1167);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle56->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle56->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle56->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle56->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle56->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle56;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->RowHeadersWidth = 62;
            dataGridViewCellStyle57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle57->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle57->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle57->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle57;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(735, 215);
            this->dataGridView1->TabIndex = 254;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            // 
            // lsubject
            // 
            dataGridViewCellStyle53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle53->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle53->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle53->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->lsubject->DefaultCellStyle = dataGridViewCellStyle53;
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
            dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle54->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle54->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle54;
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
            this->label33->Location = System::Drawing::Point(376, 815);
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
            this->label32->Location = System::Drawing::Point(370, 1115);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(118, 28);
            this->label32->TabIndex = 256;
            this->label32->Text = L"Lab subjects";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(360, 206);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(71, 28);
            this->label13->TabIndex = 258;
            this->label13->Text = L"Branch";
            // 
            // button21
            // 
            this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button21->Location = System::Drawing::Point(851, 1596);
            this->button21->Name = L"button21";
            this->button21->Size = System::Drawing::Size(120, 48);
            this->button21->TabIndex = 260;
            this->button21->Text = L"Reserve";
            this->button21->UseVisualStyleBackColor = false;
            this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click_1);
            // 
            // panel5
            // 
            this->panel5->AutoScroll = true;
            this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panel5->Controls->Add(this->finalttpanel);
            this->panel5->Controls->Add(this->button21);
            this->panel5->Controls->Add(this->classtablegen);
            this->panel5->Controls->Add(this->label13);
            this->panel5->Controls->Add(this->label32);
            this->panel5->Controls->Add(this->button16);
            this->panel5->Controls->Add(this->label33);
            this->panel5->Controls->Add(this->dataGridView1);
            this->panel5->Controls->Add(this->button17);
            this->panel5->Controls->Add(this->label34);
            this->panel5->Controls->Add(this->checkedListBox1);
            this->panel5->Controls->Add(this->button19);
            this->panel5->Controls->Add(this->label36);
            this->panel5->Controls->Add(this->maskedTextBox1);
            this->panel5->Controls->Add(this->label37);
            this->panel5->Controls->Add(this->comboBox3);
            this->panel5->Controls->Add(this->maskedTextBox2);
            this->panel5->Controls->Add(this->label38);
            this->panel5->Controls->Add(this->dataGridView6);
            this->panel5->Controls->Add(this->dataGridView3);
            this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel5->Location = System::Drawing::Point(0, 0);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1946, 1106);
            this->panel5->TabIndex = 230;
            this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint_1);
            // 
            // finalttpanel
            // 
            this->finalttpanel->Controls->Add(this->classtablegen1);
            this->finalttpanel->Controls->Add(this->label35);
            this->finalttpanel->Controls->Add(this->label52);
            this->finalttpanel->Controls->Add(this->label53);
            this->finalttpanel->Controls->Add(this->label54);
            this->finalttpanel->Controls->Add(this->label55);
            this->finalttpanel->Controls->Add(this->label56);
            this->finalttpanel->Controls->Add(this->label57);
            this->finalttpanel->Controls->Add(this->label58);
            this->finalttpanel->Controls->Add(this->label59);
            this->finalttpanel->Controls->Add(this->label60);
            this->finalttpanel->Controls->Add(this->label61);
            this->finalttpanel->Controls->Add(this->label65);
            this->finalttpanel->Location = System::Drawing::Point(405, 1721);
            this->finalttpanel->Name = L"finalttpanel";
            this->finalttpanel->Size = System::Drawing::Size(1183, 621);
            this->finalttpanel->TabIndex = 299;
            // 
            // classtablegen1
            // 
            this->classtablegen1->ColumnCount = 6;
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66466F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66856F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66467F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66467F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66799F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66944F)));
            this->classtablegen1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->classtablegen1->Location = System::Drawing::Point(140, 113);
            this->classtablegen1->Name = L"classtablegen1";
            this->classtablegen1->RowCount = 6;
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->Size = System::Drawing::Size(940, 426);
            this->classtablegen1->TabIndex = 260;
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label35->Location = System::Drawing::Point(156, 60);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(105, 28);
            this->label35->TabIndex = 294;
            this->label35->Text = L"9:00-10:00";
            // 
            // label52
            // 
            this->label52->AutoSize = true;
            this->label52->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label52->Location = System::Drawing::Point(314, 60);
            this->label52->Name = L"label52";
            this->label52->Size = System::Drawing::Size(116, 28);
            this->label52->TabIndex = 295;
            this->label52->Text = L"10:00-11:00";
            // 
            // label53
            // 
            this->label53->AutoSize = true;
            this->label53->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label53->Location = System::Drawing::Point(469, 60);
            this->label53->Name = L"label53";
            this->label53->Size = System::Drawing::Size(116, 28);
            this->label53->TabIndex = 296;
            this->label53->Text = L"11:30-12:30";
            // 
            // label54
            // 
            this->label54->AutoSize = true;
            this->label54->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label54->Location = System::Drawing::Point(641, 60);
            this->label54->Name = L"label54";
            this->label54->Size = System::Drawing::Size(105, 28);
            this->label54->TabIndex = 297;
            this->label54->Text = L"12:30-1:30";
            // 
            // label55
            // 
            this->label55->AutoSize = true;
            this->label55->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label55->Location = System::Drawing::Point(789, 60);
            this->label55->Name = L"label55";
            this->label55->Size = System::Drawing::Size(94, 28);
            this->label55->TabIndex = 298;
            this->label55->Text = L"2:30-3:30";
            // 
            // label56
            // 
            this->label56->AutoSize = true;
            this->label56->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label56->Location = System::Drawing::Point(946, 60);
            this->label56->Name = L"label56";
            this->label56->Size = System::Drawing::Size(94, 28);
            this->label56->TabIndex = 299;
            this->label56->Text = L"3:30-4:30";
            // 
            // label57
            // 
            this->label57->AutoSize = true;
            this->label57->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label57->Location = System::Drawing::Point(43, 495);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(90, 28);
            this->label57->TabIndex = 266;
            this->label57->Text = L"Saturday";
            // 
            // label58
            // 
            this->label58->AutoSize = true;
            this->label58->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label58->Location = System::Drawing::Point(43, 418);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(66, 28);
            this->label58->TabIndex = 265;
            this->label58->Text = L"Friday";
            // 
            // label59
            // 
            this->label59->AutoSize = true;
            this->label59->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label59->Location = System::Drawing::Point(30, 342);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(91, 28);
            this->label59->TabIndex = 264;
            this->label59->Text = L"Thursday";
            // 
            // label60
            // 
            this->label60->AutoSize = true;
            this->label60->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label60->Location = System::Drawing::Point(20, 280);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(113, 28);
            this->label60->TabIndex = 263;
            this->label60->Text = L"Wednesday";
            // 
            // label61
            // 
            this->label61->AutoSize = true;
            this->label61->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label61->Location = System::Drawing::Point(47, 201);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(83, 28);
            this->label61->TabIndex = 262;
            this->label61->Text = L"Tuesday";
            // 
            // label65
            // 
            this->label65->AutoSize = true;
            this->label65->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label65->Location = System::Drawing::Point(41, 132);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(85, 28);
            this->label65->TabIndex = 261;
            this->label65->Text = L"Monday";
            // 
            // classtablegen
            // 
            this->classtablegen->ColumnCount = 2;
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->classtablegen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->classtablegen->Location = System::Drawing::Point(398, 3464);
            this->classtablegen->Name = L"classtablegen";
            this->classtablegen->RowCount = 2;
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->classtablegen->Size = System::Drawing::Size(278, 246);
            this->classtablegen->TabIndex = 259;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(196, 167);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(179, 28);
            this->label1->TabIndex = 231;
            this->label1->Text = L"Enter teacher name";
            // 
            // addteachername
            // 
            this->addteachername->AcceptsTab = true;
            this->addteachername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachername->ForeColor = System::Drawing::Color::Black;
            this->addteachername->Location = System::Drawing::Point(200, 213);
            this->addteachername->Name = L"addteachername";
            this->addteachername->Size = System::Drawing::Size(361, 34);
            this->addteachername->TabIndex = 232;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(201, 294);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(198, 28);
            this->label2->TabIndex = 233;
            this->label2->Text = L"Enter the department";
            // 
            // addteacherdepartment
            // 
            this->addteacherdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteacherdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteacherdepartment->FormattingEnabled = true;
            this->addteacherdepartment->Location = System::Drawing::Point(200, 339);
            this->addteacherdepartment->Name = L"addteacherdepartment";
            this->addteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->addteacherdepartment->TabIndex = 234;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(201, 465);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(161, 28);
            this->label3->TabIndex = 235;
            this->label3->Text = L"Teacher Schedule";
            // 
            // panel16
            // 
            this->panel16->Controls->Add(this->label66);
            this->panel16->Controls->Add(this->label67);
            this->panel16->Controls->Add(this->label68);
            this->panel16->Controls->Add(this->label69);
            this->panel16->Controls->Add(this->label70);
            this->panel16->Controls->Add(this->label71);
            this->panel16->Controls->Add(this->label72);
            this->panel16->Controls->Add(this->label73);
            this->panel16->Controls->Add(this->label74);
            this->panel16->Controls->Add(this->label75);
            this->panel16->Controls->Add(this->label76);
            this->panel16->Controls->Add(this->label77);
            this->panel16->Controls->Add(this->teachertablepanel);
            this->panel16->Location = System::Drawing::Point(204, 491);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(1177, 550);
            this->panel16->TabIndex = 297;
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label66->Location = System::Drawing::Point(221, 56);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(105, 28);
            this->label66->TabIndex = 294;
            this->label66->Text = L"9:00-10:00";
            // 
            // label67
            // 
            this->label67->AutoSize = true;
            this->label67->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label67->Location = System::Drawing::Point(379, 56);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(116, 28);
            this->label67->TabIndex = 295;
            this->label67->Text = L"10:00-11:00";
            // 
            // label68
            // 
            this->label68->AutoSize = true;
            this->label68->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label68->Location = System::Drawing::Point(534, 56);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(116, 28);
            this->label68->TabIndex = 296;
            this->label68->Text = L"11:30-12:30";
            // 
            // label69
            // 
            this->label69->AutoSize = true;
            this->label69->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label69->Location = System::Drawing::Point(706, 56);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(105, 28);
            this->label69->TabIndex = 297;
            this->label69->Text = L"12:30-1:30";
            // 
            // label70
            // 
            this->label70->AutoSize = true;
            this->label70->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label70->Location = System::Drawing::Point(854, 56);
            this->label70->Name = L"label70";
            this->label70->Size = System::Drawing::Size(94, 28);
            this->label70->TabIndex = 298;
            this->label70->Text = L"2:30-3:30";
            // 
            // label71
            // 
            this->label71->AutoSize = true;
            this->label71->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label71->Location = System::Drawing::Point(1011, 56);
            this->label71->Name = L"label71";
            this->label71->Size = System::Drawing::Size(94, 28);
            this->label71->TabIndex = 299;
            this->label71->Text = L"3:30-4:30";
            // 
            // label72
            // 
            this->label72->AutoSize = true;
            this->label72->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label72->Location = System::Drawing::Point(108, 491);
            this->label72->Name = L"label72";
            this->label72->Size = System::Drawing::Size(90, 28);
            this->label72->TabIndex = 266;
            this->label72->Text = L"Saturday";
            // 
            // label73
            // 
            this->label73->AutoSize = true;
            this->label73->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label73->Location = System::Drawing::Point(108, 414);
            this->label73->Name = L"label73";
            this->label73->Size = System::Drawing::Size(66, 28);
            this->label73->TabIndex = 265;
            this->label73->Text = L"Friday";
            // 
            // label74
            // 
            this->label74->AutoSize = true;
            this->label74->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label74->Location = System::Drawing::Point(95, 338);
            this->label74->Name = L"label74";
            this->label74->Size = System::Drawing::Size(91, 28);
            this->label74->TabIndex = 264;
            this->label74->Text = L"Thursday";
            // 
            // label75
            // 
            this->label75->AutoSize = true;
            this->label75->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label75->Location = System::Drawing::Point(85, 276);
            this->label75->Name = L"label75";
            this->label75->Size = System::Drawing::Size(113, 28);
            this->label75->TabIndex = 263;
            this->label75->Text = L"Wednesday";
            // 
            // label76
            // 
            this->label76->AutoSize = true;
            this->label76->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label76->Location = System::Drawing::Point(112, 197);
            this->label76->Name = L"label76";
            this->label76->Size = System::Drawing::Size(83, 28);
            this->label76->TabIndex = 262;
            this->label76->Text = L"Tuesday";
            // 
            // label77
            // 
            this->label77->AutoSize = true;
            this->label77->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label77->Location = System::Drawing::Point(106, 128);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(85, 28);
            this->label77->TabIndex = 261;
            this->label77->Text = L"Monday";
            // 
            // teachertablepanel
            // 
            this->teachertablepanel->ColumnCount = 6;
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66667F)));
            this->teachertablepanel->Location = System::Drawing::Point(205, 109);
            this->teachertablepanel->Name = L"teachertablepanel";
            this->teachertablepanel->RowCount = 6;
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->Size = System::Drawing::Size(940, 426);
            this->teachertablepanel->TabIndex = 260;
            // 
            // addteacherpanel
            // 
            this->addteacherpanel->AutoScroll = true;
            this->addteacherpanel->Controls->Add(this->panel17);
            this->addteacherpanel->Controls->Add(this->panel16);
            this->addteacherpanel->Controls->Add(this->label3);
            this->addteacherpanel->Controls->Add(this->addteacherdepartment);
            this->addteacherpanel->Controls->Add(this->label2);
            this->addteacherpanel->Controls->Add(this->addteachername);
            this->addteacherpanel->Controls->Add(this->label1);
            this->addteacherpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addteacherpanel->Location = System::Drawing::Point(0, 0);
            this->addteacherpanel->Name = L"addteacherpanel";
            this->addteacherpanel->Size = System::Drawing::Size(1946, 1106);
            this->addteacherpanel->TabIndex = 293;
            // 
            // panel17
            // 
            this->panel17->Controls->Add(this->addteachersave);
            this->panel17->Controls->Add(this->addteachernew);
            this->panel17->Location = System::Drawing::Point(1063, 1109);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(367, 114);
            this->panel17->TabIndex = 298;
            // 
            // addteachersave
            // 
            this->addteachersave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachersave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachersave->Location = System::Drawing::Point(14, 29);
            this->addteachersave->Name = L"addteachersave";
            this->addteachersave->Size = System::Drawing::Size(121, 49);
            this->addteachersave->TabIndex = 273;
            this->addteachersave->Text = L"Save";
            this->addteachersave->UseVisualStyleBackColor = false;
            this->addteachersave->Click += gcnew System::EventHandler(this, &MyForm::addteachersave_Click);
            // 
            // addteachernew
            // 
            this->addteachernew->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteachernew->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteachernew->Location = System::Drawing::Point(184, 29);
            this->addteachernew->Name = L"addteachernew";
            this->addteachernew->Size = System::Drawing::Size(121, 49);
            this->addteachernew->TabIndex = 272;
            this->addteachernew->Text = L"Clear All";
            this->addteachernew->UseVisualStyleBackColor = false;
            this->addteachernew->Click += gcnew System::EventHandler(this, &MyForm::addteachernew_Click);
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
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->editroompanel);
            this->Controls->Add(this->editsubjectpanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->Homepanel);
            this->Controls->Add(this->panel5);
            this->Controls->Add(this->editteacherpanel);
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubcredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addsubbfactor))->EndInit();
            this->panel11->ResumeLayout(false);
            this->panel11->PerformLayout();
            this->addsubjectpanel->ResumeLayout(false);
            this->addsubjectpanel->PerformLayout();
            this->addsubeletablepanel->ResumeLayout(false);
            this->addsubeletablepanel->PerformLayout();
            this->panel12->ResumeLayout(false);
            this->panel12->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sedataGridView))->EndInit();
            this->panelsub->ResumeLayout(false);
            this->panelsub->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->roomcapacity))->EndInit();
            this->addclassroompanel->ResumeLayout(false);
            this->addclassroompanel->PerformLayout();
            this->addroompanel->ResumeLayout(false);
            this->addroompanel->PerformLayout();
            this->panel9->ResumeLayout(false);
            this->panel7->ResumeLayout(false);
            this->panel7->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            this->editteacherpanel->ResumeLayout(false);
            this->editteacherpanel->PerformLayout();
            this->panel18->ResumeLayout(false);
            this->panel19->ResumeLayout(false);
            this->panel19->PerformLayout();
            this->editroompanel->ResumeLayout(false);
            this->editroompanel->PerformLayout();
            this->panel14->ResumeLayout(false);
            this->panel15->ResumeLayout(false);
            this->panel15->PerformLayout();
            this->panel6->ResumeLayout(false);
            this->panel6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->EndInit();
            this->editsubjectpanel->ResumeLayout(false);
            this->editsubjectpanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactor))->EndInit();
            this->panel13->ResumeLayout(false);
            this->panel13->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsublabteacher))->EndInit();
            this->panel10->ResumeLayout(false);
            this->panel10->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubeleteacher))->EndInit();
            this->settingspanel->ResumeLayout(false);
            this->settingspanel->PerformLayout();
            this->panel20->ResumeLayout(false);
            this->panel20->PerformLayout();
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            this->finalttpanel->ResumeLayout(false);
            this->finalttpanel->PerformLayout();
            this->panel16->ResumeLayout(false);
            this->panel16->PerformLayout();
            this->addteacherpanel->ResumeLayout(false);
            this->addteacherpanel->PerformLayout();
            this->panel17->ResumeLayout(false);
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
        DisplayCSVInComboBox(deptDataGridView, "details/dept_file.csv");
    }
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    Homepanel->BringToFront();
    panel1->BringToFront();
    DisplayCSVInComboBox(deptDataGridView,"details/dept_file.csv");
    pictureBox12->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
    InitializeMatrixfreebusy(addroomtablepanel, "room", "Free");
    InitializeMatrixfreebusy(editroomtablepanel, "editroom", "Free");
    InitializeMatrixfreebusy(teachertablepanel, "teacher", "Free");
    InitializeMatrixfreebusy(editteachertablepanel, "editteacher", "Free");
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
    DisplayCSVInComboBox1("details/dept_file.csv", roomdept);
    button5->BackColor = Color::FromArgb(0, 0, 100);
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
    button8->BackColor = Color::FromArgb(0, 0, 100);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
}
private: System::Void dataGridView2_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn1, deptDataGridView, sender, e);
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
    if (String::IsNullOrEmpty(addteacherdepartment->Text))
    {
        MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
    if (String::IsNullOrEmpty(roomdept->Text))
    {
        MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if ((!roomlabyes->Checked) && (!roomlabno->Checked))
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
        button->Text="Free";
        button->BackColor= Color::FromArgb(179, 255, 230);
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
    DisplayCSVInListBox(filePath, addsubroomlist,0);
    const std::string fileName = "details/teacher_file.csv";
    TeacherName->DataSource = CreateDataTableFromCSV1(fileName,"teacherName");
    TeacherName->DisplayMember = "TeacherName"; // Update to the correct column name
    TeacherName->ValueMember = "TeacherName";
    list<string> itemsList;
    Teacher_Name->DataSource = CreateDataTableFromCSV1(fileName,"Teacher_Name");
    Teacher_Name->DisplayMember = "Teacher_Name"; // Update to the correct column name
    Teacher_Name->ValueMember = "Teacher_Name";
    button11->BackColor = Color::FromArgb(0, 0, 100);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    DisplayCluster("details/Electivetimetable.csv", addsubcluster);
    InitializeMatrix3(tableLayoutPanel1, "ele", "Available");
    addsubeletablepanel->Visible = false;
    panelsub->Top = addsubeletablepanel ->Top;
}
private: System::Void addsubsave_Click(System::Object^ sender, System::EventArgs^ e) {
    
    bool  flag = true;
    bool eleflag = true;
    if(String::IsNullOrEmpty(addsubname->Text))
    {
        MessageBox::Show("Subject Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
        eleflag = false;
    }
    if ((!addsubeleyes->Checked) && (!addsubeleno->Checked))
    {
        MessageBox::Show("Select whether it is a elective or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
     if(addsubeleyes->Checked)
    {
        if (String::IsNullOrEmpty(addsubcluster->Text))
        {
            MessageBox::Show("Elective name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            eleflag = false;
        }
        if (sedataGridView->RowCount==1)
        {if(sedataGridView->Rows[0]->Cells[0]->Value==nullptr)
            MessageBox::Show("Elective teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            eleflag = false;
        }
    }
     if ((!addsublabyes->Checked) && (!addsublabno->Checked) && (!addsubeleyes->Checked))
     {
         MessageBox::Show("Select whether it is a lab or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
         flag = false;
     }
     if (addsublabyes->Checked)
     {
         if (sldataGridView->RowCount == 1)
         {
             if (sldataGridView->Rows[0]->Cells[0]->Value == nullptr)
                 MessageBox::Show("Lab teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
             flag = false;
         }
         if (addsubroomlist->CheckedItems->Count == 0)
         {
             MessageBox::Show("Select Default rooms for lab", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
             flag = false;
         }
     }
     if (addsubbfactor->Value <= 0 &&  !addsubeleyes->Checked)
     {
         MessageBox::Show("Invalid bfactor Value", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
         flag = false;
     }
    String^ filePath = "details/subject_file.csv";
    if (addsubeleyes->Checked)
    {
        if (eleflag)
        {
            vector < vector<string>> temp = ReadCSVFile("details/teacher_file.csv");
            bool flag = false;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i * 6 + j + 1)]);
                    if (button != nullptr)
                    {
                        if (button->Text == "blocked")
                            flag = true;
                    }
                }

            }
            if (!flag)
            {
                MessageBox::Show("Block slots for the subject", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else
            {
                vector<vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
                try {
                    File::Copy("details/Electivetimetable.csv", "details/duplicate.csv", true);
                }
                catch (Exception^ e)
                {
                    MessageBox::Show("Other process is running in the background", "Message", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    goto a;
                }
                ofstream file("details/duplicate.csv");
                bool flags = true;

                if (file.is_open())
                {
                    for (const auto& row : data)
                    {
                        if (row[0] == msclr::interop::marshal_as<string>(addsubcluster->Text))
                        {
                            flags = false;
                            file << row[0];
                            for (int i = 1; i <= 36; i++)
                            {
                                Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i)]);
                                if (button != nullptr)
                                {
                                    if (button->Text == "blocked")
                                    {
                                        file << "," << msclr::interop::marshal_as<string>(addsubname->Text);
                                        for (int j = 0; j < sedataGridView->RowCount; j++)
                                        {
                                            if (sedataGridView->Rows[j]->Cells[0]->Value != nullptr)
                                            {
                                                for (auto& row : temp)
                                                {
                                                    string s = msclr::interop::marshal_as<string>(sedataGridView->Rows[j]->Cells[0]->Value->ToString());
                                                    if (row[0] == s)
                                                    {
                                                        row[(2 * i)] = '1';
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
                        file << msclr::interop::marshal_as<string>(addsubcluster->Text);
                        for (int i = 1; i <= 36; i++)
                        {
                            Button^ button = dynamic_cast<Button^>(tableLayoutPanel1->Controls[String::Format("buttonele{0}", i)]);
                            if (button != nullptr)
                            {
                                if (button->Text == "blocked")
                                {
                                    file << "," << msclr::interop::marshal_as<string>(addsubname->Text);
                                    for (int j = 0; j < sedataGridView->RowCount; j++)
                                    {
                                        if (sedataGridView->Rows[j]->Cells[0]->Value != nullptr)
                                        {
                                            for (auto& row : temp)
                                            {
                                                if (row[0] == msclr::interop::marshal_as<string>(sedataGridView->Rows[j]->Cells[0]->Value->ToString()))
                                                {
                                                    row[2 * i] = '1';
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                    file << ",0";
                            }
                        }

                    }
                }
                file.close();
                File::Copy("details/duplicate.csv", "details/Electivetimetable.csv", true);
                File::Delete("details/duplicate.csv");
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
        if(flag)
        subcsvgen(filePath);
    }
a:
    {}
 DisplayCluster("details/Electivetimetable.csv", addsubcluster);
}

private: System::Void sldataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn4, sldataGridView, sender, e);
}
private: System::Void newaddsub_Click(System::Object^ sender, System::EventArgs^ e) {
    addsubname->Clear();
    addsubcluster->Text = "";
    addsubeleyes->Checked = false;
    addsubeleno->Checked = false;
    addsubcluster->Cursor = Cursors::No;
    sedataGridView->Rows->Clear();
    sedataGridView->Cursor = Cursors::No;
    sedataGridView->ReadOnly = true;
    sldataGridView->Rows->Clear();
    sedataGridView->Rows->Clear();
    addsubcredits->Value = 0;
    addsubbfactor->Value = 0;
    for (int i = 0; i < addsubroomlist->Items->Count; i++) {
        addsubroomlist->SetItemChecked(i, false);
    }
    if (addsubeletablepanel->Visible)
    {
        addsubeletablepanel->Visible = false;
        panelsub->Top = addsubeletablepanel->Top;
    }
    addsublabyes->Enabled = true;
    addsublabno->Enabled = true;
    sldataGridView->Cursor = Cursors::No;
    addsublabyes->Cursor = Cursors::Arrow;
    addsublabno->Cursor = Cursors::Arrow;
    addsubcredits->ReadOnly = false;
    addsubcredits->Cursor = Cursors::Arrow;
    addsubroomlist->Cursor = Cursors::Arrow;
    addsubroomlist->Enabled = true;
    addsubbfactor->ReadOnly = false;
    addsubbfactor->Cursor = Cursors::Arrow;
}
private: System::Void sedataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn5, sedataGridView, sender, e);
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
        if (addsubeletablepanel->Visible)
        {
            addsubeletablepanel->Visible = false;
            panelsub->Top = addsubeletablepanel->Top;
        }
        addsublabyes->Enabled = true;
        addsublabno->Enabled = true;
        sldataGridView->Rows->Clear();
        sldataGridView->Cursor = Cursors::Arrow;
        addsublabyes->Cursor = Cursors::Arrow;
        addsublabno->Cursor = Cursors::Arrow;
        sedataGridView->ReadOnly = false;
        addsubcredits->Value = 0;
        addsubcredits->ReadOnly = false;
        addsubcredits->Cursor = Cursors::Arrow;
        addsubroomlist->Cursor = Cursors::Arrow;
        addsubroomlist->Enabled = true;
        addsubbfactor->Value = 0;
        addsubbfactor->ReadOnly = true;
        addsubbfactor->Cursor = Cursors::Arrow;
    }
}
private: System::Void addsubeleyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (addsubeleyes->Checked)
    {
        addsubcluster->Text="";
        sedataGridView->Cursor = Cursors::Arrow;
        sedataGridView->ReadOnly = false;
        addsubcluster->Cursor = Cursors::Arrow;
        addsubclusteroptions->Cursor = Cursors::Arrow;
        addsubbfactor->Value = 0;
        addsubbfactor->ReadOnly = true;
        addsublabno->Checked = false;
        addsublabyes->Checked = false;
        addsublabyes->Enabled = false;
        addsublabno->Enabled = false;
        sldataGridView->Rows->Clear();
        sldataGridView->ReadOnly = true;
        sldataGridView->Cursor = Cursors::No;
        addsublabyes->Cursor = Cursors::No;
        addsublabno->Cursor = Cursors::No;
        addsubbfactor->Cursor = Cursors::No;
        addsubcredits->Cursor = Cursors::No;
        addsubcredits->Value = 0;
        addsubcredits->ReadOnly = true;
        addsubroomlist->Cursor = Cursors::No;
        addsubroomlist->Enabled = false;
    }
}
private: System::Void addsublabno_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    sldataGridView->Rows->Clear();
    sldataGridView->Cursor = Cursors::No;
    sldataGridView->ReadOnly = true;
}
private: System::Void addsublabyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    sldataGridView->Cursor = Cursors::Arrow;
    sldataGridView->ReadOnly = false;
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
    panel5->BringToFront();
    InitializeMatrix1(classtablegen, button17, "res", "Open");
    InitializeMatrix2(classtablegen1, button17, "g", "free");
    classtablegen->Visible=false;
    finalttpanel->Top = button17->Bottom;
    finalttpanel->Visible = false;
    maskedTextBox1->Clear();
    maskedTextBox2->Clear();
    comboBox3->Text="";
    dataGridView1->Rows->Clear();
    dataGridView3->Rows->Clear();
    checkedListBox1->Items->Clear();
    DisplayCSVInComboBox1("details/dept_file.csv", comboBox3);
    DisplayCSVInListBox("details/classroom.csv", checkedListBox1,3);
    displaylabs("details/subject_file.csv");
    csubject->DataSource = CreateDataTableFromCSV1("details/subject_file.csv","Core Subject");
    csubject->DisplayMember = "Core Subject"; // Update to the correct column name
    csubject->ValueMember = "Core Subject";
    cteacher->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv","cteacher");
    cteacher->DisplayMember = "cteacher"; // Update to the correct column name
    cteacher->ValueMember = "cteacher";
    eSubject->DataSource = CreateDataTableFromCSV1("details/electivetimetable.csv","esubject");
    eSubject->DisplayMember = "eSubject"; // Update to the correct column name
    eSubject->ValueMember = "eSubject";
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
private: System::Void dataGridView6_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn6,dataGridView6 , sender, e);
}
private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn3, dataGridView3, sender, e);
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn2, dataGridView1, sender, e);
}
private: System::Void addsubcluster_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addsubjectpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void addsubclusteroptions_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
    
    bool  flag = true;
    if(String::IsNullOrEmpty(maskedTextBox2->Text))
    {
        MessageBox::Show("Section Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (String::IsNullOrEmpty(maskedTextBox1->Text))
    {
        MessageBox::Show("Batch(Year of admission not filled)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (String::IsNullOrEmpty(comboBox3->Text))
    {
        MessageBox::Show("Branch not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (dataGridView6->RowCount == 1)
    {
        if (dataGridView6->Rows[0]->Cells[0]->Value == nullptr)
         MessageBox::Show("CoreSubjects and teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        
    }
    if (dataGridView3->RowCount == 1)
    {
        if (dataGridView3->Rows[0]->Cells[0]->Value == nullptr)
        {
            if (MessageBox::Show("Are you Sure you do not want to fill any electives", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                flag = false;
        }
    }
    if (dataGridView1->RowCount == 1)
    {
        if (dataGridView1->Rows[0]->Cells[0]->Value == nullptr)
        {
            if (MessageBox::Show("Are you Sure you do not want to fill any lab subjects", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                flag = false;
        }
    }
    if (checkedListBox1->CheckedItems->Count == 0)
    {
        MessageBox::Show("Default classes not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
//
    if (flag)
    {
        if (MessageBox::Show("Are you Sure you want to save the generated timeTable", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
        {  
             extern vector<section>allsections;
            if (allsections.size() == 0)
            {
                section obj;
                for (int i = 0; i < dataGridView3->RowCount; i++)
                {
                    if (dataGridView3->Rows[i]->Cells[0]->Value != nullptr)
                    {
                        vector<vector<string>> rowsOfElectives = ReadCSVFile("details/electivetimetable.csv");
                        for (auto name : rowsOfElectives) {
                            if (name[0] == msclr::interop::marshal_as<string>(dataGridView3->Rows[i]->Cells[0]->Value->ToString()))
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
                String^ sec = maskedTextBox2->Text->ToString();
                string Sec = msclr::interop::marshal_as<string>(sec);
                int secval;
                //Making class name
                if (Sec[0] > 'Z')
                {
                    secval = Sec[0] - 'a';
                }
                else
                    secval = Sec[0] - 'A';
                String^ branch = comboBox3->Text->ToString();
                string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
                int branchval = 0;
                for (int i = 0; i < Branch.size(); i++)
                    if (Branch[i] > 'Z')
                    {
                        branchval = Branch[i] - 'a';
                    }
                    else
                        branchval = Branch[i] - 'A';
                String^ year = maskedTextBox1->Text->ToString();
                string YEAR = msclr::interop::marshal_as<string>(year);
                int intyear = 0;

                for (int i = 0; i < YEAR.size(); i++) {
                    intyear *= 10;
                    intyear += YEAR[i] - '0';
                }
                int idClass = intyear * 10000 + branchval * 10 + secval;
                obj.name = idClass;
                allteachersfunction("details/teacher_file.csv", obj);
                allroomsfunction("details/classroom.csv", obj);
                //alloting default rooms
                defaultroomallot(obj);
                //alloting core teacher and subjects
                loadcore(obj);
                labcreate("details/Labo.csv", obj);
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
            }
            else
            {
                section obj;
                String^ sec = maskedTextBox2->Text->ToString();
                string Sec = msclr::interop::marshal_as<string>(sec);
                int secval;
                //Making class name
                if (Sec[0] > 'Z')
                {
                    secval = Sec[0] - 'a';
                }
                else
                    secval = Sec[0] - 'A';
                String^ branch = comboBox3->Text->ToString();
                string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
                int branchval = 0;
                for (int i = 0; i < Branch.size(); i++)
                    if (Branch[i] > 'Z')
                    {
                        branchval = Branch[i] - 'a';
                    }
                    else
                        branchval = Branch[i] - 'A';
                String^ year = maskedTextBox1->Text->ToString();
                string YEAR = msclr::interop::marshal_as<string>(year);
                int intyear = 0;

                for (int i = 0; i < YEAR.size(); i++) {
                    intyear *= 10;
                    intyear += YEAR[i] - '0';
                }
                int idClass = intyear * 10000 + branchval * 10 + secval;
                obj.name = idClass;
                obj.allTeachers = allsections[allsections.size() - 1].allTeachers;
                obj.allRooms = allsections[allsections.size() - 1].allRooms;
                defaultroomallot(obj);
                //alloting core teacher and subjects
                loadcore(obj);
                labcreate("details/Labo.csv", obj);
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
            }
            ofstream file;
            file.open("timetables/" + (msclr::interop::marshal_as<string>(comboBox3->Text+maskedTextBox2->Text+maskedTextBox1->Text)) + ".csv");
            if (file.is_open())
            {
                string  tt;
                tt+="TIMETABLE\n\n";
                tt+="SUBJECTS\n";
                for (auto day : allsections[allsections.size() - 1].timeTable)
                {
                    for (auto period : day)
                    {
                        tt += period + ",";
                    }
                    tt += "\n";
                }
                tt += "\n\n";
                tt+="TEACHERS\n";
                for (auto day : allsections[allsections.size() - 1].teacherTable)
                {
                    for (auto period : day)
                    {
                        tt += period + ",";
                    }
                    tt += "\n";
                }
                tt += "\n\n";
                tt+="ROOM\n";
                for (auto day : allsections[allsections.size() - 1].roomTable)
                {
                    for (auto period : day)
                    {
                        tt += period + ",";
                    }
                    tt += "\n";
                }
                tt += "\n\n";
                file << tt;
                file.close();
            }
            File::Copy("details/teacher_file.csv","details/duplicate.csv",true);
            ofstream files("details/duplicate.csv");
            if (files.is_open())
            {
                for (auto t : allsections[allsections.size() - 1].allTeachers)
                {
                    files << t.convertToString() << "\n";
                }

            }
            files.close();
            File::Copy("details/duplicate.csv", "details/teacher_file.csv",true);
            File::Delete("details/duplicate.csv");
            ofstream fils("details/classroom.csv");
            if (fils.is_open())
            {
                for (auto t : allsections[allsections.size() - 1].allRooms)
                {
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
    panel3->Height = button9->Height;
    panel3->Top = button9->Top;
    editteacherpanel->BringToFront();
    button7->BackColor = Color::FromArgb(0, 0, 100);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
    DisplayCSVInComboBox1("details/dept_file.csv", editteacherdepartment);
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel5_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void editteacherpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void editteacherdelete_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MessageBox::Show("Are you sure you want to delete", "Disclaimer", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
    {   editteachercsvdelete("details/teacher_File.csv");
     
        editteachername->Clear();
        for (int i = 1; i <= 36; ++i)
        {
            String^ tagValue = i.ToString();
            Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
            if (button != nullptr)
            {
                button->Text = "Free";
                button->BackColor = Color::FromArgb(179, 255, 230);
            }
        }
        editteacherdepartment->Text = "";
    }
 
}

private: System::Void editteachersave_Click(System::Object^ sender, System::EventArgs^ e) {
    bool flag = true;
    if (String::IsNullOrEmpty(editteachername->Text))
    {
        MessageBox::Show("Teacher Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (String::IsNullOrEmpty(editteacherdepartment->Text))
    {
        MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (flag)
    {
        if (MessageBox::Show("Are you sure you want to save the changes", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::Yes)
        {
            editteachercsvsave("details/teacher_File.csv");

            editteachername->Clear();
            for (int i = 1; i <= 36; ++i)
            {
                String^ tagValue = i.ToString();
                Button^ button = dynamic_cast<Button^>(editteachertablepanel->Controls[String::Format("buttoneditteacher{0}", tagValue)]);
                if (button != nullptr)
                {
                    button->Text = "Free";
                    button->BackColor = Color::FromArgb(179, 255, 230);
                }
            }
            editteacherdepartment->Text = "";
        }
    }
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {

    editroompanel->BringToFront();
    panel3->Height = button6->Height;
    panel3 -> Top = button6->Top;
    button4->BackColor = Color::FromArgb(0, 0, 100);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button10->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
    DisplayCSVInComboBox1("details/dept_file.csv",editroomdepartment);
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
                button->BackColor = Color::FromArgb(179, 255, 230);
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
    if (String::IsNullOrEmpty(editroomdepartment->Text))
    {
        MessageBox::Show("Department not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if ((!editroomlabyes->Checked) && (!editroomlabno->Checked))
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
                    button->BackColor = Color::FromArgb(179, 255, 230);
                }
            }
            editroomdepartment->Text = "";
        }
    }
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
    editsubeleteachercombo->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv","editsubeleteachercombo");
    editsubeleteachercombo->DisplayMember = "editsubeleteachercombo"; // Update to the correct column name
    editsubeleteachercombo->ValueMember = "editsubeleteachercombo";
    editsublabteachercombo->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv","editsublabteachercombo");
    editsublabteachercombo->DisplayMember = "editsublabteachercombo"; // Update to the correct column name
    editsublabteachercombo->ValueMember = "editsublabteachercombo";
    DisplayCSVInListBox("details/classroom.csv",editsubroomlist,0);
    panel3->Height = button12->Height;
    panel3->Top = button12->Top;
    editsubjectpanel->BringToFront();
    button10->BackColor = Color::FromArgb(0, 0, 100);
    button4->BackColor = Color::FromArgb(0, 0, 77);
    button7->BackColor = Color::FromArgb(0, 0, 77);
    button8->BackColor = Color::FromArgb(0, 0, 77);
    button5->BackColor = Color::FromArgb(0, 0, 77);
    button11->BackColor = Color::FromArgb(0, 0, 77);
    DisplayCluster("details/Electivetimetable.csv", editsubelename);
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
        Button^ button = dynamic_cast<Button^>(teachertablepanel->Controls[String::Format("buttonteacher{0}", tagValue)]);
        if (button != nullptr)
        {
            button->Text = "Free";
            button->BackColor = Color::FromArgb(179, 255, 230);
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
        if (String::IsNullOrEmpty(editsubelename->Text))
        {
            MessageBox::Show("Elective name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (editsubeleteacher->RowCount == 1)
        {
            if (editsubeleteacher->Rows[0]->Cells[0]->Value == nullptr)
                MessageBox::Show("Elective teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
    }
    if ((!editsublabyes->Checked) && (!editsublabno->Checked))
    {
        MessageBox::Show("Select whether it is a lab or not", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (editsublabyes->Checked)
    {
        if (editsublabteacher->RowCount == 1)
        {
            if (editsublabteacher->Rows[0]->Cells[0]->Value == nullptr)
                MessageBox::Show("Lab teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
    }
    if (editsubbfactor->Value <= 1)
    {
        MessageBox::Show("Invalid bfactor Value", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
        editsubcsvdelete("details/subject_file.csv");
        editsubname->Clear();
        editsubelename->Text="";
        editsubeleyes->Checked = false;
        editsubeleno->Checked = false;
        editsublabyes->Checked = false;
        editsublabno->Checked = false;
        editsubeleteacher->Rows->Clear();
        editsublabteacher->Rows->Clear();
        editsubcredits->Value = 0;
        editsubbfactor->Value = 0;
        for (int i = 0; i < editsubroomlist->Items->Count; i++) {
            editsubroomlist->SetItemChecked(i, false);
        }
    }
}
private: System::Void editsubeleteacher_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn10,editsubeleteacher, sender, e);
}
private: System::Void editsublabteacher_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    deletebutton(dataGridViewButtonColumn11, editsublabteacher, sender, e);
}
private: System::Void editsubeleyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (editsubeleyes->Checked)
    {
        editsubelename->Text = "";
        editsubeleteacher->Cursor = Cursors::Arrow;
        editsubeleteacher->ReadOnly = false;
        editsubelename->Cursor = Cursors::Arrow;
    }
}
private: System::Void editsubeleno_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (editsubeleno->Checked)
    {
        editsubelename->Text = "";
        editsubelename->Cursor = Cursors::No;
        editsubeleteacher->Rows->Clear();
        editsubeleteacher->Cursor = Cursors::No;
        editsubeleteacher->ReadOnly = true;
    }
}
private: System::Void editsublabyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (editsublabyes->Checked)
    {
        editsublabteacher->Cursor = Cursors::Arrow;
        editsublabteacher->ReadOnly = false;
    }
}
private: System::Void editsublabno_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (editsublabno->Checked)
    {
        editsublabteacher->Rows->Clear();
        editsublabteacher->Cursor = Cursors::No;
        editsublabteacher->ReadOnly = true;
    }
}
private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void addsubclusteroptions_Click(System::Object^ sender, System::EventArgs^ e) {
    if (addsubeleyes->Checked == true)
    {
        addsubeletablepanel->Visible = true;
        panelsub->Top = addsubeletablepanel->Bottom;
        InitializeMatrix3(tableLayoutPanel1, "ele", "Available");
        onOptionClick();
    }
    else
    {
        MessageBox::Show("Only applicable for Electives", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
    bool  flag = true;
    if (String::IsNullOrEmpty(maskedTextBox2->Text))
    {
        MessageBox::Show("Section Name not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (String::IsNullOrEmpty(maskedTextBox1->Text))
    {
        MessageBox::Show("Batch(Year of admission not filled)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (String::IsNullOrEmpty(comboBox3->Text))
    {
        MessageBox::Show("Branch not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }
    if (dataGridView6->RowCount == 1)
    {
        if (dataGridView6->Rows[0]->Cells[0]->Value == nullptr)
            MessageBox::Show("CoreSubjects and teachers not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);

    }
    if (dataGridView3->RowCount == 1)
    {
        if (dataGridView3->Rows[0]->Cells[0]->Value == nullptr)
        {
            if (MessageBox::Show("Are you Sure you do not want to fill any electives", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                flag = false;
        }
    }
    if (dataGridView1->RowCount == 1)
    {
        if (dataGridView1->Rows[0]->Cells[0]->Value == nullptr)
        {
            if (MessageBox::Show("Are you Sure you do not want to fill any lab subjects", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::No)
                flag = false;
        }
    }
    if (checkedListBox1->CheckedItems->Count == 0)
    {
        MessageBox::Show("Default classes not filled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
        flag = false;
    }

    if (flag) {
        //
        section obj;
        for (int i = 0; i < dataGridView3->RowCount; i++)
        {
            if (dataGridView3->Rows[i]->Cells[0]->Value != nullptr)
            {
                vector<vector<string>> rowsOfElectives = ReadCSVFile("details/electivetimetable.csv");
                for (auto name : rowsOfElectives) {
                    if (name[0] == msclr::interop::marshal_as<string>(dataGridView3->Rows[i]->Cells[0]->Value->ToString()))
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
        InitializeMatrix2(classtablegen1, button17, "g", "free");
        classtablegen->Visible = false;
        finalttpanel->Visible = true;

        String^ sec = maskedTextBox2->Text->ToString();
        string Sec = msclr::interop::marshal_as<string>(sec);
        int secval;
        //Making class name
        if (Sec[0] > 'Z')
        {
            secval = Sec[0] - 'a';
        }
        else
            secval = Sec[0] - 'A';
        String^ branch = comboBox3->Text->ToString();
        string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
        int branchval = 0;
        for (int i = 0; i < Branch.size(); i++)
            if (Branch[i] > 'Z')
            {
                branchval = Branch[i] - 'a';
            }
            else
                branchval = Branch[i] - 'A';
        String^ year = maskedTextBox1->Text->ToString();
        string YEAR = msclr::interop::marshal_as<string>(year);
        int intyear = 0;

        for (int i = 0; i < YEAR.size(); i++) {
            intyear *= 10;
            intyear += YEAR[i] - '0';
        }
        int idClass = intyear * 10000 + branchval * 10 + secval;
        obj.name = idClass;
        allteachersfunction("details/teacher_file.csv", obj);
        allroomsfunction("details/classroom.csv", obj);
        //alloting default rooms
        defaultroomallot(obj);
        //alloting core teacher and subjects
        loadcore(obj);
        labcreate("details/Labo.csv", obj);

        obj.makeTIMETABLE();
        for (int i = 0; i < obj.timeTable.size(); i++)
        {
            for (int j = 0; j < obj.timeTable[i].size(); j++)
            {
                if (j != 2)
                {
                    Button^ button = dynamic_cast<Button^>(classtablegen1->Controls[String::Format("buttong{0}", 6 * i + j + 1)]);
                    if (obj.timeTable[i][j] != "f")
                        button->Text = msclr::interop::marshal_as<String^>(obj.timeTable[i][j]);
                    else
                        button->Text = "free";
                }
            }
        }
    }
}
private: System::Void button21_Click_1(System::Object^ sender, System::EventArgs^ e) {
    InitializeMatrix1(classtablegen, button17, "res", "Open");
    classtablegen->Visible = true;
    finalttpanel ->Visible = false;
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
    ClearReset();
    classtablegen->Visible = false;
    finalttpanel->Visible = false;
    maskedTextBox1->Clear();
    maskedTextBox2->Clear();
    comboBox3->Text = "";
    dataGridView1->Rows->Clear();
    dataGridView3->Rows->Clear();
    for (int i = checkedListBox1->Items->Count - 1; i >= 0; i--) {
        checkedListBox1->SetItemChecked(i, false);
    }
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
}
};
}

