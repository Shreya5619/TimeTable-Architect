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
        System::Void EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
        {
            // Check if the current cell is in the TextBoxColumn
            if (deptDataGridView->CurrentCell->OwningColumn->Name =="dataGridViewTextBoxColumn1")
            {
                // Attach KeyPress event handler to the TextBox control
                System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(e->Control);
                textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::KeyPress);
            }
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

        void DisplayCSVInComboBox(DataGridView^ classlab, const string& filename) {
            classlab->Rows->Clear();
            vector<vector<string>> data = ReadCSVFile(filename);

            for (const auto& row : data) {
                string rowString;
                for (const auto& cell : row[0]) {
                    rowString += cell;
                }
                String^ rowStringManaged = msclr::interop::marshal_as<String^>(rowString);
                classlab->Rows->Add(rowStringManaged);
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
                it.push_back(replaceunderscore(rowString));
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

        void Button_click(Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr) {
                // Toggle the text of the clicked button
                if (clickedButton->Text == "Available")
                {
                    clickedButton->Text = addsubname->Text;
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == addsubname->Text)
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
                    clickedButton->Text = addsubname->Text;
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                if (clickedButton->Text == addsubname->Text)
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

        void Button_clickEle(Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr) {
                // Toggle the text of the clicked button
                if (clickedButton->Text == "Available")
                {
                    clickedButton->Text = addsubname->Text;
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "blocked" || clickedButton->Text == addsubname->Text)
                {
                    clickedButton->Text = "Available";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
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
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == editsubname->Text)
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
                    System::Windows::Forms::DialogResult Result = MessageBox::Show("Teacher name already exists.\nDo you want to replace the teacher.", "Warning", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Exclamation);
                    if (Result == System::Windows::Forms::DialogResult::Cancel)
                        flag = false;
                    else if (Result == System::Windows::Forms::DialogResult::OK)
                    {
                        string x;
                        String^ name = addteachername->Text->ToString();
                        string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                        x += Name + ",";
                        String^ cap = addteacherdepartment->Text->ToString();
                        string Cap = msclr::interop::marshal_as<string>(cap);
                        x += Cap + ",";
                        String^ ename = addteacheremailid->Text->ToString();
                        string eName = replacewhitespace(msclr::interop::marshal_as<string>(ename));
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
                        string eName = replacewhitespace(msclr::interop::marshal_as<string>(ename));
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
                    for (char& a : row[n])
                    {
                        a = toupper(static_cast<unsigned char>(a));
                    }
                    if (row[n] == find)
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
            MessageBox::Show("Successfully Replaced", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void classroomcsvcreate(const string filePath)
        {
            try
            {
                bool flag = true;
                string find = replacewhitespace(msclr::interop::marshal_as<string>(roomname->Text));
                if (searchname(find, "details/classroom.csv", 0))
                {
                    System::Windows::Forms::DialogResult Result = MessageBox::Show("Room name already exists.\nDo you want to replace the room.", "Warning", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Exclamation);
                    if (Result == System::Windows::Forms::DialogResult::Cancel)
                        flag = false;
                    else if (Result == System::Windows::Forms::DialogResult::OK)
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
                    System::Windows::Forms::DialogResult Result = MessageBox::Show("Subject already exists.\nDo you want to replace the subject", "Warning", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Exclamation);
                    if (Result == System::Windows::Forms::DialogResult::Cancel)
                        flag = false;
                    else if (Result == System::Windows::Forms::DialogResult::Yes)
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
                        if (addsublabyes->Checked)
                        {
                            if (searchname(find, "details/Labo.csv", 0))
                            {
                                string labteachers;
                                labteachers += Name;
                                for (int i = 0; i < sldataGridView->RowCount; i++)
                                {
                                    if (sldataGridView->Rows[i]->Cells[0]->Value != nullptr)
                                    {
                                        String^ Tname = sldataGridView->Rows[i]->Cells[0]->Value->ToString();
                                        string TName = replacewhitespace(msclr::interop::marshal_as<string>(Tname));
                                        labteachers += "," + TName;
                                    }
                                }
                                labteachers += "\n";
                                replacename(find, "details/Labo.csv", 0, labteachers);
                            }
                            else
                            {
                                csvlab("details/Labo.csv");
                            }
                            x = x + "1" + ",";
                        }
                        else
                        {
                            replacename(find, "details/Labo.csv", 0, "");
                            x = x + "0" + ",";
                        }
                        String^ cap = addsubcredits->Text->ToString();
                        string Cap = msclr::interop::marshal_as<string>(cap);
                        x += Cap + ",";
                        if (addsublabyes->Checked)
                        {
                            x += "2,";
                        }
                        else
                        {
                            x += "1,";
                        }
                        String^ Bfact = addsubbfactor->Text->ToString();
                        string BFact = msclr::interop::marshal_as<string>(Bfact);
                        x += BFact + ",";
                        x += "[";
                        bool y = true;
                        for (int i = 0; i < addsubroomlist->CheckedItems->Count; ++i) {
                            String^ value = addsubroomlist->CheckedItems[i]->ToString();
                            std::string Value = msclr::interop::marshal_as<string>(value);
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
                        {if (addsublabyes->Checked)
                        {
                            outputFile << "1,";
                            {
                                csvlab("details/Labo.csv");
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
            }
            catch (...)
            {
                MessageBox::Show("Error Occured while trying to save the data\nTry Closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void DisplayCSVInListBox(const string& filename, ListBox^ ListBox, int i) {
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


        void csvlab(System::String^ filePath)
        {
            try
            {
                std::ofstream outputFile;
                outputFile.open((msclr::interop::marshal_as<std::string>(filePath)), ios::app);
                {
                    System::String^ name = addsubname->Text->ToString();
                    std::string Name = replacewhitespace(msclr::interop::marshal_as<string>(name));
                    outputFile << Name;

                    for (int i = 0; i < sldataGridView->RowCount; ++i)
                    {
                        if (sldataGridView->Rows[i]->Cells[0]->Value != nullptr)
                        {
                            System::String^ cellvalue = sldataGridView->Rows[i]->Cells[0]->Value->ToString();
                            std::string CellValue = replacewhitespace(msclr::interop::marshal_as<string>(cellvalue));
                            outputFile << "," << CellValue;
                        }
                    }
                    outputFile << ",[";
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
                }outputFile.close();
            }
            catch (...)
            {
                MessageBox::Show("Error saving Data\nTry closing opened files", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
            vector<vector<string>>abc = ReadCSVFile(filename);
            for (int i = 0; i < classlab->RowCount; ++i)
            {
                if (classlab->Rows[i]->Cells[0]->Value != nullptr)
                {
                    System::String^ cellvalue = classlab->Rows[i]->Cells[0]->Value->ToString();
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
                                if (abc[j][x][0] == '[')
                                    break;
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
                            file << replacewhitespace(msclr::interop::marshal_as<string>(editteacheremailid->Text->ToString()));
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
            string find = replacewhitespace(msclr::interop::marshal_as<string>(editsubsearch->Text));
            for (char& a : find)
            {
                a = toupper(static_cast<unsigned char>(a));
            }
            bool flag = true;
            vector<vector<string>>data = ReadCSVFile("details/subject_file.csv");
            for (auto& row : data)
            {
                string str;
                for (char& a : row[0])
                {
                    str += toupper(static_cast<unsigned char>(a));
                }
                if (str == find)
                {
                    flag = false;
                    *a = row[0];
                    editsubname->Text = msclr::interop::marshal_as<String^>(row[0]);
                    editsubtitle->Text = msclr::interop::marshal_as<String^>(row[1]);
                    editsubcode->Text = msclr::interop::marshal_as<String^>(row[2]);
                    if (row[3] == "0")
                    {
                        editsubeleno->Checked = true;
                        editsubcluster->Text = "";
                        editsubeleteacher->Rows->Clear();
                    }
                    else
                    {
                        editsubeleyes->Checked = true;
                    }
                    if (row[4] == "0")
                    {
                        editsublabno->Checked = true;
                    }
                    else
                    {
                        editsublabyes->Checked = true;
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
                                    if (rows[i][0] == '[')
                                        break;
                                    else
                                    {
                                        String^ rowString = msclr::interop::marshal_as<String^>(replaceunderscore(rows[i]));
                                        editsublabteacher->Rows->Add(rowString);
                                    }
                                }
                                break;
                            }

                        }

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
                string str;
                for (auto& elerow : ele)
                {
                    for (int i = 1; i < elerow.size(); i++)
                    {
                        str = "";
                        for (char& a : elerow[i])
                        {
                            str += std::toupper(a);
                        }
                        if (find == str)
                        {
                            eleflag = false;
                            *a = elerow[i];
                            editsubelepanel->Visible = true;
                            editsubelepanel->Top = button3->Bottom;
                            editpanelsub->Top = editsubelepanel->Bottom;
                            editsubname->Text = msclr::interop::marshal_as<String^>(elerow[i]);
                            editsubeleyes->Checked = true;
                            editsubcluster->Text = msclr::interop::marshal_as<String^>(elerow[0]);
                            for (int k = 1; k < 37; k++)
                            {
                                Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", k)]);
                                if (elerow[k] == "0")
                                {
                                    button->Text = "Available";
                                }
                                else
                                {
                                    button->Text = msclr::interop::marshal_as<String^>(elerow[k]);
                                    button->BackColor = Color::FromArgb(102, 255, 204);
                                }
                            }
                            editsubeleteacher->Rows->Clear();
                            vector<vector<string>>teachers = ReadCSVFile("details/teacher_file.csv");
                            for (const auto& teach : teachers)
                            {
                                for (int n = 4; n < teach.size(); n += 2)
                                {
                                    if (teach[n] == elerow[i])
                                    {
                                        editsubeleteacher->Rows->Add(msclr::interop::marshal_as<String^>(teach[0]));
                                        break;
                                    }
                                }
                            }
                            goto out;
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
                                    for (int j = 0; j < editsubeleteacher->RowCount; j++)
                                    {
                                        if (editsubeleteacher->Rows[j]->Cells[0]->Value != nullptr)
                                        {
                                            for (auto& row : temp)
                                            {
                                                string s = msclr::interop::marshal_as<string>(editsubeleteacher->Rows[j]->Cells[0]->Value->ToString());
                                                if (row[0] == s)
                                                {
                                                    row[(2 * i) + 1] = '1';
                                                    row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(editsubname->Text));
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
                        if (editsublabyes->Checked)
                        {
                            x += "1,";
                            x += msclr::interop::marshal_as<string>(editsubcredits->Text) + ",2,";
                            string lab = searchsubname;
                            for (int i = 0; i < editsublabteacher->RowCount; i++)
                            {
                                if (editsublabteacher->Rows[i]->Cells[0]->Value != nullptr)
                                {
                                    lab += "," + msclr::interop::marshal_as<string>(editsublabteacher->Rows[i]->Cells[0]->Value->ToString());
                                }
                            }
                            lab += "\n";
                            replacename(searchsubname, "details/Labo.csv", 0, lab);
                        }
                        else
                        {
                            x += "0,";
                            x += msclr::interop::marshal_as<string>(editsubcredits->Text) + ",1,";
                            replacename(searchsubname, "details/Labo.csv", 0, "");
                        }

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

                    for (auto& row : ele)
                    {
                        for (int i = 1; i < row.size(); i++)
                        {
                            if (row[i] == find)
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
                                }
                                else
                                {
                                    string file;
                                        file += row[0];
                                        for (int i = 1; i <= 36; i++)
                                        {
                                            Button^ button = dynamic_cast<Button^>(editsubeletable->Controls[String::Format("buttoneditele{0}", i)]);
                                            if (button != nullptr)
                                            {
                                                if (button->Text == editsubname->Text)
                                                {
                                                    file += "," + msclr::interop::marshal_as<string>(editsubname->Text);
                                                    for (int j = 0; j < editsubeleteacher->RowCount; j++)
                                                    {
                                                        if (editsubeleteacher->Rows[j]->Cells[0]->Value != nullptr)
                                                        {
                                                            for (auto& row : temp)
                                                            {

                                                                for (int n = 4; n < row.size(); n += 2)
                                                                {
                                                                    if (row[n] == find)
                                                                    {
                                                                        row[n] = "0";
                                                                        row[n - 1] = "0";
                                                                    }
                                                                }
                                                                string s = msclr::interop::marshal_as<string>(editsubeleteacher->Rows[j]->Cells[0]->Value->ToString());
                                                                if (row[0] == s)
                                                                {
                                                                    row[(2 * i) + 1] = '1';
                                                                    row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(editsubname->Text));
                                                                }
                                                            }
                                                        }
                                                    }

                                                }
                                                else if (button->Text == "busy")
                                                {
                                                    file += ",0";
                                                }
                                                else
                                                    file += "," + row[i];
                                            }
                                        }
                                        file += "\n";
                                        replacename(msclr::interop::marshal_as<string>(addsubcluster->Text), "details/Electivetimetable.csv", 0, file);
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
                                    goto err;
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
                    sub.readData(returnLine(msclr::interop::marshal_as<string>(classcore->Rows[i]->Cells[0]->Value->ToString()), "details/subject_file.csv"));
                    obj.addCore(msclr::interop::marshal_as<string>(classcore->Rows[i]->Cells[1]->Value->ToString()), sub);
                }
            }
        }

        void defaultroomallot(section& obj)
        {
            vector<string>drooms;
            for each (int checkedIndex in classdefaultrooms->CheckedIndices)
            {
                String^ itemRoom = classdefaultrooms->Items[checkedIndex]->ToString();
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

        vector<vector<vector<bool>>>valuetimetable(string clustername, DataGridView^ sedataGridView)
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
                            for (int i = 3; i < row.size(); i += 2)
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

        void onOptionClick(ComboBox^ addsubcluster, DataGridView^ dgv, TableLayoutPanel^ t, String^ s)
        {
            string name = msclr::interop::marshal_as<string>(addsubcluster->Text);
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector<vector<vector<bool>>>tt = valuetimetable(name, dgv);
            vector<vector<bool>>intersecttt = intersectionElective(tt);
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    Button^ button = dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", i * 6 + j + 1)]);
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
                            button->BackColor = Color::FromArgb(179, 255, 240);
                        }
                    }
                    for (auto row : data)
                    {
                        if (row[0] == name)
                        {
                            if (row[i * 6 + j + 1] != "0")
                            {
                                button->Text = msclr::interop::marshal_as<String^>(row[i * 6 + j + 1]);
                                button->BackColor = Color::FromArgb(102, 255, 204);
                            }
                        }
                    }
                }
            }
        }
        void onOptionClickedit(ComboBox^ addsubcluster, DataGridView^ dgv, TableLayoutPanel^ t, String^ s)
        {
            string name = msclr::interop::marshal_as<string>(addsubcluster->Text);
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector < vector<string>> temp = ReadCSVFile("details/teacher_file.csv");
            vector<vector<vector<bool>>>tt = valuetimetable(name, dgv);
            vector<vector<bool>>intersecttt = intersectionElective(tt);
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {

                    Button^ button = dynamic_cast<Button^>(t->Controls[String::Format("button" + s + "{0}", i * 6 + j + 1)]);
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
                            button->BackColor = Color::FromArgb(179, 255, 240);
                        }
                    }
                    for (auto row : data)
                    {
                        if (row[0] == name)
                        {
                            if (row[i * 6 + j + 1] != "0")
                            {
                                button->Text = msclr::interop::marshal_as<String^>(row[i * 6 + j + 1]);
                                button->BackColor = Color::FromArgb(102, 255, 204);
                            }
                        }
                    }
                }
            }
            for (int x = 0; x < editsubeleteacher->RowCount; x++)
            {
                if (editsubeleteacher->Rows[x]->Cells[0]->Value != nullptr)
                {
                    string n = msclr::interop::marshal_as<string>(editsubeleteacher->Rows[x]->Cells[0]->Value->ToString());
                    for (auto cell : temp)
                    {
                        if (cell[0] == n)
                        {
                            for (int l = 3; l < cell.size(); l += 2)
                            {
                                if ((cell[l] == "1" && cell[l + 1] != msclr::interop::marshal_as<string>(editsubname->Text)) && (dynamic_cast<Button^>(t->Controls[String::Format("buttoneditele{0}", l / 2)])->Text == editsubname->Text))
                                {
                                    dynamic_cast<Button^>(t->Controls[String::Format("buttoneditele{0}", l / 2)])->Text = "busy";
                                    dynamic_cast<Button^>(t->Controls[String::Format("buttoneditele{0}", l / 2)])->BackColor = Color::FromArgb(224, 224, 224);
                                }
                            }
                        }
                    }
                }
            }
        }
        System::Void KeyPress(System::Object^ sender, KeyPressEventArgs^ e) {
            if (!Char::IsLetter(e->KeyChar) && e->KeyChar != (char)Keys::Back && !Char::IsDigit(e->KeyChar)) {
                e->Handled = true;
            }
        }
        System::Void KeyPressemail(System::Object^ sender, KeyPressEventArgs^ e) {
            // Filter out special characters
            if ((!Char::IsLetter(e->KeyChar) && e->KeyChar !='@' && !Char::IsDigit(e->KeyChar)) && e->KeyChar != (char)Keys::Back) {
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
                    clickedButton->BackColor = Color::FromArgb(102, 255, 204);
                }
                else if (clickedButton->Text == "Busy")
                {
                    clickedButton->Text = "Free";
                    clickedButton->BackColor = Color::FromArgb(179, 255, 230);
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
    private: System::Windows::Forms::ComboBox^ editsubcluster;
    private: System::Windows::Forms::Panel^ panel7;
    private: System::Windows::Forms::Button^ addsubclusteroptions;
    private: System::Windows::Forms::Panel^ panelsub;
    private: System::Windows::Forms::DataGridView^ classele;
    private: System::Windows::Forms::DataGridView^ classcore;
    private: System::Windows::Forms::Label^ label38;
    private: System::Windows::Forms::MaskedTextBox^ classname;
    private: System::Windows::Forms::ComboBox^ classbranch;
    private: System::Windows::Forms::Label^ label37;
    private: System::Windows::Forms::MaskedTextBox^ classbatch;
    private: System::Windows::Forms::Label^ label36;
    private: System::Windows::Forms::CheckedListBox^ classdefaultrooms;
    private: System::Windows::Forms::Label^ label34;
    private: System::Windows::Forms::Button^ classgenerate;
    private: System::Windows::Forms::Button^ classsave;
    private: System::Windows::Forms::Button^ classclear;
    private: System::Windows::Forms::DataGridView^ classlab;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ lsubject;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn2;
    private: System::Windows::Forms::Label^ label33;
    private: System::Windows::Forms::Label^ label32;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::Button^ classreserve;
    private: System::Windows::Forms::Panel^ classpanel;
    private: System::Windows::Forms::Panel^ panel9;
    private: System::Windows::Forms::Panel^ panel14;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ addteachername;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::ComboBox^ addteacherdepartment;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Panel^ addteacherpanel;
    private: System::Windows::Forms::Panel^ panel17;
    private: System::Windows::Forms::Button^ addteachersave;
    private: System::Windows::Forms::Button^ addteachernew;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Panel^ panel18;
    private: System::Windows::Forms::Label^ label51;
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
    private: System::Windows::Forms::Button^ editteachersearchbutton;
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
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ csubject;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ cteacher;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn6;
    private: System::Windows::Forms::DataGridViewComboBoxColumn^ eSubject;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn3;
    private: System::Windows::Forms::Panel^ finalttpanel;
    private: System::Windows::Forms::Panel^ panel8;
    private: System::Windows::Forms::Panel^ panel25;
    private: System::Windows::Forms::TableLayoutPanel^ classtablegen1;
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
    private: System::Windows::Forms::Panel^ classtablegenpanel;
    private: System::Windows::Forms::Panel^ panel26;
    private: System::Windows::Forms::Panel^ panel27;
    private: System::Windows::Forms::TableLayoutPanel^ classtablegen;
    private: System::Windows::Forms::Label^ label135;
    private: System::Windows::Forms::Label^ label136;
    private: System::Windows::Forms::Label^ label137;
    private: System::Windows::Forms::Label^ label138;
    private: System::Windows::Forms::Label^ label139;
    private: System::Windows::Forms::Label^ label140;
    private: System::Windows::Forms::Label^ label141;
    private: System::Windows::Forms::Label^ label142;
    private: System::Windows::Forms::Label^ label143;
    private: System::Windows::Forms::Label^ label144;
    private: System::Windows::Forms::Label^ label145;
    private: System::Windows::Forms::Label^ label146;
    private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::Panel^ panel28;
    private: System::Windows::Forms::TableLayoutPanel^ editteachertablepanel;
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
    private: System::Windows::Forms::Panel^ panel16;
    private: System::Windows::Forms::Panel^ panel29;
    private: System::Windows::Forms::Panel^ panel30;
    private: System::Windows::Forms::TableLayoutPanel^ teachertablepanel;
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
    private: System::Windows::Forms::Panel^ panel15;
    private: System::Windows::Forms::Panel^ panel31;
    private: System::Windows::Forms::Panel^ panel32;
    private: System::Windows::Forms::TableLayoutPanel^ editroomtablepanel;
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
    private: System::Windows::Forms::Panel^ panel33;
    private: System::Windows::Forms::Panel^ panel34;
    private: System::Windows::Forms::Panel^ panel35;
    private: System::Windows::Forms::TableLayoutPanel^ addroomtablepanel;
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
    private: System::Windows::Forms::TextBox^ deptlabel;
    private: System::Windows::Forms::DataGridView^ deptDataGridView;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
    private: System::Windows::Forms::DataGridViewButtonColumn^ dataGridViewButtonColumn1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button22;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::TextBox^ addteacheremailid;
    private: System::Windows::Forms::Label^ label147;
    private: System::Windows::Forms::TextBox^ addsubcode;
    private: System::Windows::Forms::Label^ label149;
    private: System::Windows::Forms::TextBox^ addsubtitle;
    private: System::Windows::Forms::Label^ label148;
    private: System::Windows::Forms::TextBox^ editteacheremailid;
    private: System::Windows::Forms::Label^ label151;
    private: System::Windows::Forms::Panel^ deleteclasspanel;
    private: System::Windows::Forms::DataGridView^ sectiondeletedatagridview;
    private: System::Windows::Forms::Panel^ panel36;
    private: System::Windows::Forms::Label^ label150;
    private: System::Windows::Forms::Label^ label152;
    private: System::Windows::Forms::TextBox^ editsubtitle;
    private: System::Windows::Forms::TextBox^ editsubcode;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ classcolumn;
    private: System::Windows::Forms::DataGridViewButtonColumn^ classdeletebutton;
    private: System::Windows::Forms::Panel^ panel19;
    private: System::Windows::Forms::Panel^ editpanelsub;

    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Panel^ editsubelepanel;
    private: System::Windows::Forms::Panel^ panel39;
    private: System::Windows::Forms::Panel^ panel40;
    private: System::Windows::Forms::TableLayoutPanel^ editsubeletable;
    private: System::Windows::Forms::Label^ label153;
    private: System::Windows::Forms::Label^ label154;
    private: System::Windows::Forms::Label^ label155;
    private: System::Windows::Forms::Label^ label156;
    private: System::Windows::Forms::Label^ label157;
    private: System::Windows::Forms::Label^ label158;
    private: System::Windows::Forms::Label^ label159;
    private: System::Windows::Forms::Label^ label160;
    private: System::Windows::Forms::Label^ label161;
    private: System::Windows::Forms::Label^ label162;
    private: System::Windows::Forms::Label^ label163;
    private: System::Windows::Forms::Label^ label164;
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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle58 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle59 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle62 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle63 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle64 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle60 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle61 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
            this->addsubcode = (gcnew System::Windows::Forms::TextBox());
            this->label149 = (gcnew System::Windows::Forms::Label());
            this->addsubtitle = (gcnew System::Windows::Forms::TextBox());
            this->label148 = (gcnew System::Windows::Forms::Label());
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
            this->panel33 = (gcnew System::Windows::Forms::Panel());
            this->panel34 = (gcnew System::Windows::Forms::Panel());
            this->panel35 = (gcnew System::Windows::Forms::Panel());
            this->addroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->panel9 = (gcnew System::Windows::Forms::Panel());
            this->panel7 = (gcnew System::Windows::Forms::Panel());
            this->Homepanel = (gcnew System::Windows::Forms::Panel());
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
            this->editteacheremailid = (gcnew System::Windows::Forms::TextBox());
            this->label151 = (gcnew System::Windows::Forms::Label());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->panel19 = (gcnew System::Windows::Forms::Panel());
            this->panel28 = (gcnew System::Windows::Forms::Panel());
            this->editteachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->editteachersearchbutton = (gcnew System::Windows::Forms::Button());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->panel18 = (gcnew System::Windows::Forms::Panel());
            this->editteacherdelete = (gcnew System::Windows::Forms::Button());
            this->editteachersave = (gcnew System::Windows::Forms::Button());
            this->editteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->editteachername = (gcnew System::Windows::Forms::TextBox());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->teachersearch = (gcnew System::Windows::Forms::ComboBox());
            this->editroompanel = (gcnew System::Windows::Forms::Panel());
            this->panel15 = (gcnew System::Windows::Forms::Panel());
            this->panel31 = (gcnew System::Windows::Forms::Panel());
            this->panel32 = (gcnew System::Windows::Forms::Panel());
            this->editroomtablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->panel14 = (gcnew System::Windows::Forms::Panel());
            this->editroomdelete = (gcnew System::Windows::Forms::Button());
            this->editroomsave = (gcnew System::Windows::Forms::Button());
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
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->editsubelepanel = (gcnew System::Windows::Forms::Panel());
            this->panel39 = (gcnew System::Windows::Forms::Panel());
            this->panel40 = (gcnew System::Windows::Forms::Panel());
            this->editsubeletable = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label153 = (gcnew System::Windows::Forms::Label());
            this->label154 = (gcnew System::Windows::Forms::Label());
            this->label155 = (gcnew System::Windows::Forms::Label());
            this->label156 = (gcnew System::Windows::Forms::Label());
            this->label157 = (gcnew System::Windows::Forms::Label());
            this->label158 = (gcnew System::Windows::Forms::Label());
            this->label159 = (gcnew System::Windows::Forms::Label());
            this->label160 = (gcnew System::Windows::Forms::Label());
            this->label161 = (gcnew System::Windows::Forms::Label());
            this->label162 = (gcnew System::Windows::Forms::Label());
            this->label163 = (gcnew System::Windows::Forms::Label());
            this->label164 = (gcnew System::Windows::Forms::Label());
            this->editpanelsub = (gcnew System::Windows::Forms::Panel());
            this->label96 = (gcnew System::Windows::Forms::Label());
            this->label97 = (gcnew System::Windows::Forms::Label());
            this->editsubcredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->editsubroomlist = (gcnew System::Windows::Forms::CheckedListBox());
            this->label100 = (gcnew System::Windows::Forms::Label());
            this->editsubbfactor = (gcnew System::Windows::Forms::NumericUpDown());
            this->editsubsave = (gcnew System::Windows::Forms::Button());
            this->editsubdelete = (gcnew System::Windows::Forms::Button());
            this->editsublabteacher = (gcnew System::Windows::Forms::DataGridView());
            this->editsublabteachercombo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn11 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->label98 = (gcnew System::Windows::Forms::Label());
            this->panel13 = (gcnew System::Windows::Forms::Panel());
            this->editsublabyes = (gcnew System::Windows::Forms::RadioButton());
            this->editsublabno = (gcnew System::Windows::Forms::RadioButton());
            this->editsubcode = (gcnew System::Windows::Forms::TextBox());
            this->editsubtitle = (gcnew System::Windows::Forms::TextBox());
            this->label150 = (gcnew System::Windows::Forms::Label());
            this->label152 = (gcnew System::Windows::Forms::Label());
            this->editsubcluster = (gcnew System::Windows::Forms::ComboBox());
            this->editsubsearchbutton = (gcnew System::Windows::Forms::Button());
            this->label101 = (gcnew System::Windows::Forms::Label());
            this->editsubsearch = (gcnew System::Windows::Forms::ComboBox());
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
            this->classele = (gcnew System::Windows::Forms::DataGridView());
            this->eSubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->classcore = (gcnew System::Windows::Forms::DataGridView());
            this->csubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->cteacher = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn6 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->classname = (gcnew System::Windows::Forms::MaskedTextBox());
            this->classbranch = (gcnew System::Windows::Forms::ComboBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->classbatch = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->classdefaultrooms = (gcnew System::Windows::Forms::CheckedListBox());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->classgenerate = (gcnew System::Windows::Forms::Button());
            this->classsave = (gcnew System::Windows::Forms::Button());
            this->classclear = (gcnew System::Windows::Forms::Button());
            this->classlab = (gcnew System::Windows::Forms::DataGridView());
            this->lsubject = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
            this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->classreserve = (gcnew System::Windows::Forms::Button());
            this->classpanel = (gcnew System::Windows::Forms::Panel());
            this->panel36 = (gcnew System::Windows::Forms::Panel());
            this->classtablegenpanel = (gcnew System::Windows::Forms::Panel());
            this->panel26 = (gcnew System::Windows::Forms::Panel());
            this->panel27 = (gcnew System::Windows::Forms::Panel());
            this->classtablegen = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label135 = (gcnew System::Windows::Forms::Label());
            this->label136 = (gcnew System::Windows::Forms::Label());
            this->label137 = (gcnew System::Windows::Forms::Label());
            this->label138 = (gcnew System::Windows::Forms::Label());
            this->label139 = (gcnew System::Windows::Forms::Label());
            this->label140 = (gcnew System::Windows::Forms::Label());
            this->label141 = (gcnew System::Windows::Forms::Label());
            this->label142 = (gcnew System::Windows::Forms::Label());
            this->label143 = (gcnew System::Windows::Forms::Label());
            this->label144 = (gcnew System::Windows::Forms::Label());
            this->label145 = (gcnew System::Windows::Forms::Label());
            this->label146 = (gcnew System::Windows::Forms::Label());
            this->finalttpanel = (gcnew System::Windows::Forms::Panel());
            this->panel8 = (gcnew System::Windows::Forms::Panel());
            this->panel25 = (gcnew System::Windows::Forms::Panel());
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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->addteachername = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->addteacherdepartment = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->addteacherpanel = (gcnew System::Windows::Forms::Panel());
            this->panel17 = (gcnew System::Windows::Forms::Panel());
            this->addteachersave = (gcnew System::Windows::Forms::Button());
            this->addteachernew = (gcnew System::Windows::Forms::Button());
            this->addteacheremailid = (gcnew System::Windows::Forms::TextBox());
            this->label147 = (gcnew System::Windows::Forms::Label());
            this->panel16 = (gcnew System::Windows::Forms::Panel());
            this->panel29 = (gcnew System::Windows::Forms::Panel());
            this->panel30 = (gcnew System::Windows::Forms::Panel());
            this->teachertablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
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
            this->deptlabel = (gcnew System::Windows::Forms::TextBox());
            this->deptDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button22 = (gcnew System::Windows::Forms::Button());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->deleteclasspanel = (gcnew System::Windows::Forms::Panel());
            this->sectiondeletedatagridview = (gcnew System::Windows::Forms::DataGridView());
            this->classcolumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->classdeletebutton = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
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
            this->panel33->SuspendLayout();
            this->panel9->SuspendLayout();
            this->panel7->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            this->panel4->SuspendLayout();
            this->editteacherpanel->SuspendLayout();
            this->panel5->SuspendLayout();
            this->panel18->SuspendLayout();
            this->editroompanel->SuspendLayout();
            this->panel15->SuspendLayout();
            this->panel14->SuspendLayout();
            this->panel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->BeginInit();
            this->editsubjectpanel->SuspendLayout();
            this->editsubelepanel->SuspendLayout();
            this->editpanelsub->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcredits))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactor))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsublabteacher))->BeginInit();
            this->panel13->SuspendLayout();
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classele))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcore))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlab))->BeginInit();
            this->classpanel->SuspendLayout();
            this->panel36->SuspendLayout();
            this->classtablegenpanel->SuspendLayout();
            this->finalttpanel->SuspendLayout();
            this->addteacherpanel->SuspendLayout();
            this->panel17->SuspendLayout();
            this->panel16->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->BeginInit();
            this->panel2->SuspendLayout();
            this->deleteclasspanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectiondeletedatagridview))->BeginInit();
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
            this->sldataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::sldataGridView_CellContentClick);
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
            this->label49->Location = System::Drawing::Point(192, 133);
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
            this->addsubjectpanel->Controls->Add(this->addsubcode);
            this->addsubjectpanel->Controls->Add(this->label149);
            this->addsubjectpanel->Controls->Add(this->addsubtitle);
            this->addsubjectpanel->Controls->Add(this->label148);
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
            // addsubcode
            // 
            this->addsubcode->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubcode->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubcode->ForeColor = System::Drawing::Color::Black;
            this->addsubcode->Location = System::Drawing::Point(200, 471);
            this->addsubcode->Name = L"addsubcode";
            this->addsubcode->Size = System::Drawing::Size(480, 34);
            this->addsubcode->TabIndex = 305;
            // 
            // label149
            // 
            this->label149->AutoSize = true;
            this->label149->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label149->ForeColor = System::Drawing::Color::Black;
            this->label149->Location = System::Drawing::Point(204, 422);
            this->label149->Name = L"label149";
            this->label149->Size = System::Drawing::Size(128, 28);
            this->label149->TabIndex = 304;
            this->label149->Text = L"Subject Code";
            // 
            // addsubtitle
            // 
            this->addsubtitle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubtitle->ForeColor = System::Drawing::Color::Black;
            this->addsubtitle->Location = System::Drawing::Point(201, 322);
            this->addsubtitle->Name = L"addsubtitle";
            this->addsubtitle->Size = System::Drawing::Size(480, 34);
            this->addsubtitle->TabIndex = 303;
            // 
            // label148
            // 
            this->label148->AutoSize = true;
            this->label148->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label148->ForeColor = System::Drawing::Color::Black;
            this->label148->Location = System::Drawing::Point(203, 276);
            this->label148->Name = L"label148";
            this->label148->Size = System::Drawing::Size(124, 28);
            this->label148->TabIndex = 302;
            this->label148->Text = L"Subject Title ";
            // 
            // addsubclusteroptions
            // 
            this->addsubclusteroptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addsubclusteroptions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addsubclusteroptions->Location = System::Drawing::Point(709, 1140);
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
            this->addsubeletablepanel->Location = System::Drawing::Point(200, 1202);
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
            this->addsubcluster->Location = System::Drawing::Point(209, 751);
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
            this->panel12->Location = System::Drawing::Point(228, 586);
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
            this->label46->Location = System::Drawing::Point(204, 857);
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
            this->label47->Location = System::Drawing::Point(205, 699);
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
            this->label48->Location = System::Drawing::Point(205, 548);
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
            this->addsubname->Location = System::Drawing::Point(197, 183);
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
            this->sedataGridView->Location = System::Drawing::Point(221, 912);
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
            this->panelsub->Location = System::Drawing::Point(177, 1847);
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
            this->label31->Location = System::Drawing::Point(254, 185);
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
            this->roomname->Location = System::Drawing::Point(258, 246);
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
            this->roomcapacity->Location = System::Drawing::Point(263, 356);
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
            this->label30->Location = System::Drawing::Point(259, 307);
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
            this->label29->Location = System::Drawing::Point(259, 421);
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
            this->label28->Location = System::Drawing::Point(253, 541);
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
            this->roomdept->Location = System::Drawing::Point(256, 580);
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
            this->addclassroompanel->Controls->Add(this->panel33);
            this->addclassroompanel->Controls->Add(this->label5);
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
            // panel33
            // 
            this->panel33->Controls->Add(this->panel34);
            this->panel33->Controls->Add(this->panel35);
            this->panel33->Controls->Add(this->addroomtablepanel);
            this->panel33->Controls->Add(this->label103);
            this->panel33->Controls->Add(this->label104);
            this->panel33->Controls->Add(this->label105);
            this->panel33->Controls->Add(this->label106);
            this->panel33->Controls->Add(this->label107);
            this->panel33->Controls->Add(this->label108);
            this->panel33->Controls->Add(this->label113);
            this->panel33->Controls->Add(this->label114);
            this->panel33->Controls->Add(this->label115);
            this->panel33->Controls->Add(this->label116);
            this->panel33->Controls->Add(this->label117);
            this->panel33->Controls->Add(this->label118);
            this->panel33->Location = System::Drawing::Point(249, 694);
            this->panel33->Name = L"panel33";
            this->panel33->Size = System::Drawing::Size(1183, 621);
            this->panel33->TabIndex = 304;
            // 
            // panel34
            // 
            this->panel34->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel34.BackgroundImage")));
            this->panel34->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel34->Location = System::Drawing::Point(416, 112);
            this->panel34->Name = L"panel34";
            this->panel34->Size = System::Drawing::Size(44, 413);
            this->panel34->TabIndex = 2;
            // 
            // panel35
            // 
            this->panel35->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel35.BackgroundImage")));
            this->panel35->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel35->Location = System::Drawing::Point(757, 110);
            this->panel35->Name = L"panel35";
            this->panel35->Size = System::Drawing::Size(44, 436);
            this->panel35->TabIndex = 1;
            // 
            // addroomtablepanel
            // 
            this->addroomtablepanel->ColumnCount = 8;
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66354F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66743F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                18.0212F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                15.19435F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                50)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66887F)));
            this->addroomtablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16.66976F)));
            this->addroomtablepanel->Location = System::Drawing::Point(140, 113);
            this->addroomtablepanel->Name = L"addroomtablepanel";
            this->addroomtablepanel->RowCount = 6;
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->addroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->addroomtablepanel->Size = System::Drawing::Size(949, 435);
            this->addroomtablepanel->TabIndex = 260;
            // 
            // label103
            // 
            this->label103->AutoSize = true;
            this->label103->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label103->Location = System::Drawing::Point(158, 72);
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
            this->label104->Location = System::Drawing::Point(294, 72);
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
            this->label105->Location = System::Drawing::Point(480, 72);
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
            this->label106->Location = System::Drawing::Point(635, 72);
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
            this->label107->Location = System::Drawing::Point(828, 68);
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
            this->label108->Location = System::Drawing::Point(958, 68);
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
            this->label113->Location = System::Drawing::Point(43, 495);
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
            this->label114->Location = System::Drawing::Point(43, 418);
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
            this->label115->Location = System::Drawing::Point(30, 342);
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
            this->label116->Location = System::Drawing::Point(20, 280);
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
            this->label117->Location = System::Drawing::Point(47, 201);
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
            this->label118->Location = System::Drawing::Point(41, 132);
            this->label118->Name = L"label118";
            this->label118->Size = System::Drawing::Size(85, 28);
            this->label118->TabIndex = 261;
            this->label118->Text = L"Monday";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(253, 667);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(148, 28);
            this->label5->TabIndex = 263;
            this->label5->Text = L"Room Schedule";
            // 
            // panel9
            // 
            this->panel9->Controls->Add(this->clearroom);
            this->panel9->Controls->Add(this->saveroom);
            this->panel9->Location = System::Drawing::Point(1079, 1321);
            this->panel9->Name = L"panel9";
            this->panel9->Size = System::Drawing::Size(376, 156);
            this->panel9->TabIndex = 124;
            // 
            // panel7
            // 
            this->panel7->Controls->Add(this->roomlabyes);
            this->panel7->Controls->Add(this->roomlabno);
            this->panel7->Location = System::Drawing::Point(259, 457);
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
            this->editteacherpanel->Controls->Add(this->editteacheremailid);
            this->editteacherpanel->Controls->Add(this->label151);
            this->editteacherpanel->Controls->Add(this->panel5);
            this->editteacherpanel->Controls->Add(this->editteachersearchbutton);
            this->editteacherpanel->Controls->Add(this->label51);
            this->editteacherpanel->Controls->Add(this->panel18);
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
            // editteacheremailid
            // 
            this->editteacheremailid->AcceptsTab = true;
            this->editteacheremailid->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacheremailid->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacheremailid->ForeColor = System::Drawing::Color::Black;
            this->editteacheremailid->Location = System::Drawing::Point(194, 642);
            this->editteacheremailid->Name = L"editteacheremailid";
            this->editteacheremailid->Size = System::Drawing::Size(361, 34);
            this->editteacheremailid->TabIndex = 306;
            // 
            // label151
            // 
            this->label151->AutoSize = true;
            this->label151->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label151->Location = System::Drawing::Point(191, 593);
            this->label151->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label151->Name = L"label151";
            this->label151->Size = System::Drawing::Size(215, 28);
            this->label151->TabIndex = 305;
            this->label151->Text = L"Enter teacher\'s Email ID";
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->panel19);
            this->panel5->Controls->Add(this->panel28);
            this->panel5->Controls->Add(this->editteachertablepanel);
            this->panel5->Controls->Add(this->label6);
            this->panel5->Controls->Add(this->label7);
            this->panel5->Controls->Add(this->label8);
            this->panel5->Controls->Add(this->label9);
            this->panel5->Controls->Add(this->label10);
            this->panel5->Controls->Add(this->label11);
            this->panel5->Controls->Add(this->label12);
            this->panel5->Controls->Add(this->label14);
            this->panel5->Controls->Add(this->label40);
            this->panel5->Controls->Add(this->label50);
            this->panel5->Controls->Add(this->label119);
            this->panel5->Controls->Add(this->label120);
            this->panel5->Location = System::Drawing::Point(204, 802);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1183, 621);
            this->panel5->TabIndex = 302;
            // 
            // panel19
            // 
            this->panel19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel19.BackgroundImage")));
            this->panel19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel19->Location = System::Drawing::Point(426, 110);
            this->panel19->Name = L"panel19";
            this->panel19->Size = System::Drawing::Size(44, 436);
            this->panel19->TabIndex = 2;
            // 
            // panel28
            // 
            this->panel28->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel28.BackgroundImage")));
            this->panel28->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel28->Location = System::Drawing::Point(757, 110);
            this->panel28->Name = L"panel28";
            this->panel28->Size = System::Drawing::Size(44, 436);
            this->panel28->TabIndex = 1;
            // 
            // editteachertablepanel
            // 
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
            this->editteachertablepanel->Location = System::Drawing::Point(140, 113);
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
            this->editteachertablepanel->Size = System::Drawing::Size(949, 435);
            this->editteachertablepanel->TabIndex = 260;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(158, 72);
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
            this->label7->Location = System::Drawing::Point(294, 72);
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
            this->label8->Location = System::Drawing::Point(480, 72);
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
            this->label9->Location = System::Drawing::Point(635, 72);
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
            this->label10->Location = System::Drawing::Point(828, 68);
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
            this->label11->Location = System::Drawing::Point(958, 68);
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
            this->label12->Location = System::Drawing::Point(43, 495);
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
            this->label14->Location = System::Drawing::Point(43, 418);
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
            this->label40->Location = System::Drawing::Point(30, 342);
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
            this->label50->Location = System::Drawing::Point(20, 280);
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
            this->label119->Location = System::Drawing::Point(47, 201);
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
            this->label120->Location = System::Drawing::Point(41, 132);
            this->label120->Name = L"label120";
            this->label120->Size = System::Drawing::Size(85, 28);
            this->label120->TabIndex = 261;
            this->label120->Text = L"Monday";
            // 
            // editteachersearchbutton
            // 
            this->editteachersearchbutton->BackColor = System::Drawing::Color::White;
            this->editteachersearchbutton->FlatAppearance->BorderSize = 0;
            this->editteachersearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editteachersearchbutton->Location = System::Drawing::Point(889, 165);
            this->editteachersearchbutton->Name = L"editteachersearchbutton";
            this->editteachersearchbutton->Size = System::Drawing::Size(26, 29);
            this->editteachersearchbutton->TabIndex = 301;
            this->editteachersearchbutton->Text = L"🔍";
            this->editteachersearchbutton->UseVisualStyleBackColor = false;
            this->editteachersearchbutton->Click += gcnew System::EventHandler(this, &MyForm::editteachersearchbutton_Click);
            // 
            // label51
            // 
            this->label51->AutoSize = true;
            this->label51->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(196, 747);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(161, 28);
            this->label51->TabIndex = 300;
            this->label51->Text = L"Teacher Schedule";
            // 
            // panel18
            // 
            this->panel18->Controls->Add(this->editteacherdelete);
            this->panel18->Controls->Add(this->editteachersave);
            this->panel18->Location = System::Drawing::Point(982, 1427);
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
            // editteacherdepartment
            // 
            this->editteacherdepartment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editteacherdepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteacherdepartment->FormattingEnabled = true;
            this->editteacherdepartment->Location = System::Drawing::Point(193, 498);
            this->editteacherdepartment->Name = L"editteacherdepartment";
            this->editteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->editteacherdepartment->TabIndex = 234;
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label63->Location = System::Drawing::Point(192, 450);
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
            this->editteachername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editteachername->ForeColor = System::Drawing::Color::Black;
            this->editteachername->Location = System::Drawing::Point(199, 356);
            this->editteachername->Name = L"editteachername";
            this->editteachername->Size = System::Drawing::Size(361, 34);
            this->editteachername->TabIndex = 232;
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label64->Location = System::Drawing::Point(195, 310);
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
            this->label39->Location = System::Drawing::Point(610, 112);
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
            this->teachersearch->Location = System::Drawing::Point(556, 163);
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
            this->editroompanel->Controls->Add(this->panel15);
            this->editroompanel->Controls->Add(this->label4);
            this->editroompanel->Controls->Add(this->panel14);
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
            // panel15
            // 
            this->panel15->Controls->Add(this->panel31);
            this->panel15->Controls->Add(this->panel32);
            this->panel15->Controls->Add(this->editroomtablepanel);
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
            this->panel15->Location = System::Drawing::Point(233, 822);
            this->panel15->Name = L"panel15";
            this->panel15->Size = System::Drawing::Size(1183, 621);
            this->panel15->TabIndex = 303;
            // 
            // panel31
            // 
            this->panel31->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel31.BackgroundImage")));
            this->panel31->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel31->Location = System::Drawing::Point(416, 112);
            this->panel31->Name = L"panel31";
            this->panel31->Size = System::Drawing::Size(44, 413);
            this->panel31->TabIndex = 2;
            // 
            // panel32
            // 
            this->panel32->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel32.BackgroundImage")));
            this->panel32->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel32->Location = System::Drawing::Point(757, 110);
            this->panel32->Name = L"panel32";
            this->panel32->Size = System::Drawing::Size(44, 436);
            this->panel32->TabIndex = 1;
            // 
            // editroomtablepanel
            // 
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
            this->editroomtablepanel->Location = System::Drawing::Point(140, 113);
            this->editroomtablepanel->Name = L"editroomtablepanel";
            this->editroomtablepanel->RowCount = 6;
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editroomtablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editroomtablepanel->Size = System::Drawing::Size(949, 435);
            this->editroomtablepanel->TabIndex = 260;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->Location = System::Drawing::Point(158, 72);
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
            this->label17->Location = System::Drawing::Point(294, 72);
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
            this->label18->Location = System::Drawing::Point(480, 72);
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
            this->label19->Location = System::Drawing::Point(635, 72);
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
            this->label20->Location = System::Drawing::Point(828, 68);
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
            this->label21->Location = System::Drawing::Point(958, 68);
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
            this->label22->Location = System::Drawing::Point(43, 495);
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
            this->label23->Location = System::Drawing::Point(43, 418);
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
            this->label24->Location = System::Drawing::Point(30, 342);
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
            this->label25->Location = System::Drawing::Point(20, 280);
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
            this->label26->Location = System::Drawing::Point(47, 201);
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
            this->label27->Location = System::Drawing::Point(41, 132);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(85, 28);
            this->label27->TabIndex = 261;
            this->label27->Text = L"Monday";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(232, 784);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(148, 28);
            this->label4->TabIndex = 297;
            this->label4->Text = L"Room Schedule";
            // 
            // panel14
            // 
            this->panel14->Controls->Add(this->editroomdelete);
            this->panel14->Controls->Add(this->editroomsave);
            this->panel14->Location = System::Drawing::Point(1102, 1451);
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
            // editroomsearchbutton
            // 
            this->editroomsearchbutton->BackColor = System::Drawing::Color::White;
            this->editroomsearchbutton->FlatAppearance->BorderSize = 0;
            this->editroomsearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editroomsearchbutton->Location = System::Drawing::Point(970, 183);
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
            this->label82->Location = System::Drawing::Point(678, 121);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(271, 30);
            this->label82->TabIndex = 290;
            this->label82->Text = L"Enter the Classroom Name";
            // 
            // panel6
            // 
            this->panel6->Controls->Add(this->editroomlabyes);
            this->panel6->Controls->Add(this->editroomlabno);
            this->panel6->Location = System::Drawing::Point(236, 586);
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
            this->editroomdepartment->Location = System::Drawing::Point(233, 702);
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
            this->label78->Location = System::Drawing::Point(230, 663);
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
            this->label79->Location = System::Drawing::Point(236, 543);
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
            this->label80->Location = System::Drawing::Point(236, 429);
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
            this->editroomcapacity->Location = System::Drawing::Point(240, 478);
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
            this->editroomname->Location = System::Drawing::Point(235, 368);
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
            this->label81->Location = System::Drawing::Point(231, 307);
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
            this->editroomsearch->Location = System::Drawing::Point(639, 178);
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
            this->editsubjectpanel->Controls->Add(this->button3);
            this->editsubjectpanel->Controls->Add(this->editsubelepanel);
            this->editsubjectpanel->Controls->Add(this->editpanelsub);
            this->editsubjectpanel->Controls->Add(this->editsubcode);
            this->editsubjectpanel->Controls->Add(this->editsubtitle);
            this->editsubjectpanel->Controls->Add(this->label150);
            this->editsubjectpanel->Controls->Add(this->label152);
            this->editsubjectpanel->Controls->Add(this->editsubcluster);
            this->editsubjectpanel->Controls->Add(this->editsubsearchbutton);
            this->editsubjectpanel->Controls->Add(this->label101);
            this->editsubjectpanel->Controls->Add(this->editsubsearch);
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
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(730, 1322);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(116, 46);
            this->button3->TabIndex = 310;
            this->button3->Text = L"Options";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // editsubelepanel
            // 
            this->editsubelepanel->Controls->Add(this->panel39);
            this->editsubelepanel->Controls->Add(this->panel40);
            this->editsubelepanel->Controls->Add(this->editsubeletable);
            this->editsubelepanel->Controls->Add(this->label153);
            this->editsubelepanel->Controls->Add(this->label154);
            this->editsubelepanel->Controls->Add(this->label155);
            this->editsubelepanel->Controls->Add(this->label156);
            this->editsubelepanel->Controls->Add(this->label157);
            this->editsubelepanel->Controls->Add(this->label158);
            this->editsubelepanel->Controls->Add(this->label159);
            this->editsubelepanel->Controls->Add(this->label160);
            this->editsubelepanel->Controls->Add(this->label161);
            this->editsubelepanel->Controls->Add(this->label162);
            this->editsubelepanel->Controls->Add(this->label163);
            this->editsubelepanel->Controls->Add(this->label164);
            this->editsubelepanel->Location = System::Drawing::Point(63, 1374);
            this->editsubelepanel->Name = L"editsubelepanel";
            this->editsubelepanel->Size = System::Drawing::Size(1183, 621);
            this->editsubelepanel->TabIndex = 311;
            // 
            // panel39
            // 
            this->panel39->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel39.BackgroundImage")));
            this->panel39->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel39->Location = System::Drawing::Point(416, 112);
            this->panel39->Name = L"panel39";
            this->panel39->Size = System::Drawing::Size(44, 413);
            this->panel39->TabIndex = 2;
            // 
            // panel40
            // 
            this->panel40->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel40.BackgroundImage")));
            this->panel40->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel40->Location = System::Drawing::Point(757, 110);
            this->panel40->Name = L"panel40";
            this->panel40->Size = System::Drawing::Size(44, 436);
            this->panel40->TabIndex = 1;
            // 
            // editsubeletable
            // 
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
            this->editsubeletable->Location = System::Drawing::Point(140, 113);
            this->editsubeletable->Name = L"editsubeletable";
            this->editsubeletable->RowCount = 6;
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->editsubeletable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->editsubeletable->Size = System::Drawing::Size(949, 435);
            this->editsubeletable->TabIndex = 260;
            // 
            // label153
            // 
            this->label153->AutoSize = true;
            this->label153->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label153->Location = System::Drawing::Point(158, 72);
            this->label153->Name = L"label153";
            this->label153->Size = System::Drawing::Size(105, 28);
            this->label153->TabIndex = 294;
            this->label153->Text = L"9:00-10:00";
            // 
            // label154
            // 
            this->label154->AutoSize = true;
            this->label154->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label154->Location = System::Drawing::Point(294, 72);
            this->label154->Name = L"label154";
            this->label154->Size = System::Drawing::Size(116, 28);
            this->label154->TabIndex = 295;
            this->label154->Text = L"10:00-11:00";
            // 
            // label155
            // 
            this->label155->AutoSize = true;
            this->label155->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label155->Location = System::Drawing::Point(480, 72);
            this->label155->Name = L"label155";
            this->label155->Size = System::Drawing::Size(116, 28);
            this->label155->TabIndex = 296;
            this->label155->Text = L"11:30-12:30";
            // 
            // label156
            // 
            this->label156->AutoSize = true;
            this->label156->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label156->Location = System::Drawing::Point(635, 72);
            this->label156->Name = L"label156";
            this->label156->Size = System::Drawing::Size(105, 28);
            this->label156->TabIndex = 297;
            this->label156->Text = L"12:30-1:30";
            // 
            // label157
            // 
            this->label157->AutoSize = true;
            this->label157->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label157->Location = System::Drawing::Point(828, 68);
            this->label157->Name = L"label157";
            this->label157->Size = System::Drawing::Size(94, 28);
            this->label157->TabIndex = 298;
            this->label157->Text = L"2:30-3:30";
            // 
            // label158
            // 
            this->label158->AutoSize = true;
            this->label158->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label158->Location = System::Drawing::Point(958, 68);
            this->label158->Name = L"label158";
            this->label158->Size = System::Drawing::Size(94, 28);
            this->label158->TabIndex = 299;
            this->label158->Text = L"3:30-4:30";
            // 
            // label159
            // 
            this->label159->AutoSize = true;
            this->label159->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label159->Location = System::Drawing::Point(43, 495);
            this->label159->Name = L"label159";
            this->label159->Size = System::Drawing::Size(90, 28);
            this->label159->TabIndex = 266;
            this->label159->Text = L"Saturday";
            // 
            // label160
            // 
            this->label160->AutoSize = true;
            this->label160->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label160->Location = System::Drawing::Point(43, 418);
            this->label160->Name = L"label160";
            this->label160->Size = System::Drawing::Size(66, 28);
            this->label160->TabIndex = 265;
            this->label160->Text = L"Friday";
            // 
            // label161
            // 
            this->label161->AutoSize = true;
            this->label161->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label161->Location = System::Drawing::Point(30, 342);
            this->label161->Name = L"label161";
            this->label161->Size = System::Drawing::Size(91, 28);
            this->label161->TabIndex = 264;
            this->label161->Text = L"Thursday";
            // 
            // label162
            // 
            this->label162->AutoSize = true;
            this->label162->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label162->Location = System::Drawing::Point(20, 280);
            this->label162->Name = L"label162";
            this->label162->Size = System::Drawing::Size(113, 28);
            this->label162->TabIndex = 263;
            this->label162->Text = L"Wednesday";
            // 
            // label163
            // 
            this->label163->AutoSize = true;
            this->label163->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label163->Location = System::Drawing::Point(47, 201);
            this->label163->Name = L"label163";
            this->label163->Size = System::Drawing::Size(83, 28);
            this->label163->TabIndex = 262;
            this->label163->Text = L"Tuesday";
            // 
            // label164
            // 
            this->label164->AutoSize = true;
            this->label164->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label164->Location = System::Drawing::Point(41, 132);
            this->label164->Name = L"label164";
            this->label164->Size = System::Drawing::Size(85, 28);
            this->label164->TabIndex = 261;
            this->label164->Text = L"Monday";
            // 
            // editpanelsub
            // 
            this->editpanelsub->Controls->Add(this->label96);
            this->editpanelsub->Controls->Add(this->label97);
            this->editpanelsub->Controls->Add(this->editsubcredits);
            this->editpanelsub->Controls->Add(this->editsubroomlist);
            this->editpanelsub->Controls->Add(this->label100);
            this->editpanelsub->Controls->Add(this->editsubbfactor);
            this->editpanelsub->Controls->Add(this->editsubsave);
            this->editpanelsub->Controls->Add(this->editsubdelete);
            this->editpanelsub->Controls->Add(this->editsublabteacher);
            this->editpanelsub->Controls->Add(this->label99);
            this->editpanelsub->Controls->Add(this->label98);
            this->editpanelsub->Controls->Add(this->panel13);
            this->editpanelsub->Location = System::Drawing::Point(161, 2432);
            this->editpanelsub->Name = L"editpanelsub";
            this->editpanelsub->Size = System::Drawing::Size(846, 1096);
            this->editpanelsub->TabIndex = 320;
            this->editpanelsub->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel37_Paint);
            // 
            // label96
            // 
            this->label96->AutoSize = true;
            this->label96->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label96->Location = System::Drawing::Point(50, 609);
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
            this->label97->Location = System::Drawing::Point(55, 462);
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
            this->editsubcredits->Location = System::Drawing::Point(80, 508);
            this->editsubcredits->Name = L"editsubcredits";
            this->editsubcredits->Size = System::Drawing::Size(123, 34);
            this->editsubcredits->TabIndex = 301;
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
            this->editsubroomlist->Location = System::Drawing::Point(61, 664);
            this->editsubroomlist->Name = L"editsubroomlist";
            this->editsubroomlist->Size = System::Drawing::Size(251, 124);
            this->editsubroomlist->Sorted = true;
            this->editsubroomlist->TabIndex = 304;
            this->editsubroomlist->ThreeDCheckBoxes = true;
            // 
            // label100
            // 
            this->label100->AutoSize = true;
            this->label100->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label100->Location = System::Drawing::Point(51, 834);
            this->label100->Name = L"label100";
            this->label100->Size = System::Drawing::Size(75, 28);
            this->label100->TabIndex = 306;
            this->label100->Text = L"bfactor";
            // 
            // editsubbfactor
            // 
            this->editsubbfactor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->editsubbfactor->DecimalPlaces = 2;
            this->editsubbfactor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubbfactor->Location = System::Drawing::Point(57, 876);
            this->editsubbfactor->Name = L"editsubbfactor";
            this->editsubbfactor->Size = System::Drawing::Size(135, 34);
            this->editsubbfactor->TabIndex = 307;
            // 
            // editsubsave
            // 
            this->editsubsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubsave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubsave->Location = System::Drawing::Point(393, 999);
            this->editsubsave->Name = L"editsubsave";
            this->editsubsave->Size = System::Drawing::Size(116, 58);
            this->editsubsave->TabIndex = 308;
            this->editsubsave->Text = L"Save";
            this->editsubsave->UseVisualStyleBackColor = false;
            this->editsubsave->Click += gcnew System::EventHandler(this, &MyForm::editsubsave_Click);
            // 
            // editsubdelete
            // 
            this->editsubdelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubdelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubdelete->Location = System::Drawing::Point(572, 998);
            this->editsubdelete->Name = L"editsubdelete";
            this->editsubdelete->Size = System::Drawing::Size(116, 58);
            this->editsubdelete->TabIndex = 309;
            this->editsubdelete->Text = L"Delete";
            this->editsubdelete->UseVisualStyleBackColor = false;
            this->editsubdelete->Click += gcnew System::EventHandler(this, &MyForm::editsubdelete_Click);
            // 
            // editsublabteacher
            // 
            this->editsublabteacher->AllowUserToOrderColumns = true;
            dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
            this->editsublabteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle15;
            this->editsublabteacher->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsublabteacher->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsublabteacher->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsublabteacher->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteacher->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle16;
            this->editsublabteacher->ColumnHeadersHeight = 40;
            this->editsublabteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsublabteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->editsublabteachercombo,
                    this->dataGridViewButtonColumn11
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
            this->editsublabteacher->DefaultCellStyle = dataGridViewCellStyle19;
            this->editsublabteacher->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsublabteacher->Location = System::Drawing::Point(53, 228);
            this->editsublabteacher->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsublabteacher->Name = L"editsublabteacher";
            dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteacher->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
            this->editsublabteacher->RowHeadersVisible = false;
            this->editsublabteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle21->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
            this->editsublabteacher->RowsDefaultCellStyle = dataGridViewCellStyle21;
            this->editsublabteacher->RowTemplate->Height = 28;
            this->editsublabteacher->Size = System::Drawing::Size(735, 230);
            this->editsublabteacher->TabIndex = 300;
            this->editsublabteacher->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::editsublabteacher_CellContentClick);
            // 
            // editsublabteachercombo
            // 
            dataGridViewCellStyle17->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle17->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsublabteachercombo->DefaultCellStyle = dataGridViewCellStyle17;
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
            dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn11->DefaultCellStyle = dataGridViewCellStyle18;
            this->dataGridViewButtonColumn11->DividerWidth = 1;
            this->dataGridViewButtonColumn11->HeaderText = L"";
            this->dataGridViewButtonColumn11->MinimumWidth = 100;
            this->dataGridViewButtonColumn11->Name = L"dataGridViewButtonColumn11";
            this->dataGridViewButtonColumn11->ReadOnly = true;
            this->dataGridViewButtonColumn11->Text = L"Delete";
            this->dataGridViewButtonColumn11->UseColumnTextForButtonValue = true;
            // 
            // label99
            // 
            this->label99->AutoSize = true;
            this->label99->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label99->Location = System::Drawing::Point(50, 25);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(98, 28);
            this->label99->TabIndex = 298;
            this->label99->Text = L"Is it a lab\?";
            this->label99->Click += gcnew System::EventHandler(this, &MyForm::label99_Click);
            // 
            // label98
            // 
            this->label98->AutoSize = true;
            this->label98->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label98->Location = System::Drawing::Point(48, 181);
            this->label98->Name = L"label98";
            this->label98->Size = System::Drawing::Size(299, 28);
            this->label98->TabIndex = 299;
            this->label98->Text = L"Teachers handling the lab subject";
            // 
            // panel13
            // 
            this->panel13->Controls->Add(this->editsublabyes);
            this->panel13->Controls->Add(this->editsublabno);
            this->panel13->ForeColor = System::Drawing::Color::Black;
            this->panel13->Location = System::Drawing::Point(56, 78);
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
            // editsubcode
            // 
            this->editsubcode->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubcode->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubcode->ForeColor = System::Drawing::Color::Black;
            this->editsubcode->Location = System::Drawing::Point(198, 620);
            this->editsubcode->Name = L"editsubcode";
            this->editsubcode->Size = System::Drawing::Size(480, 34);
            this->editsubcode->TabIndex = 319;
            // 
            // editsubtitle
            // 
            this->editsubtitle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubtitle->ForeColor = System::Drawing::Color::Black;
            this->editsubtitle->Location = System::Drawing::Point(206, 509);
            this->editsubtitle->Name = L"editsubtitle";
            this->editsubtitle->Size = System::Drawing::Size(480, 34);
            this->editsubtitle->TabIndex = 318;
            // 
            // label150
            // 
            this->label150->AutoSize = true;
            this->label150->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label150->Location = System::Drawing::Point(193, 574);
            this->label150->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label150->Name = L"label150";
            this->label150->Size = System::Drawing::Size(128, 28);
            this->label150->TabIndex = 316;
            this->label150->Text = L"Subject Code";
            // 
            // label152
            // 
            this->label152->AutoSize = true;
            this->label152->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label152->Location = System::Drawing::Point(198, 454);
            this->label152->Name = L"label152";
            this->label152->Size = System::Drawing::Size(119, 28);
            this->label152->TabIndex = 314;
            this->label152->Text = L"Subject Title";
            // 
            // editsubcluster
            // 
            this->editsubcluster->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
            this->editsubcluster->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->editsubcluster->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->editsubcluster->FormattingEnabled = true;
            this->editsubcluster->Location = System::Drawing::Point(166, 921);
            this->editsubcluster->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editsubcluster->Name = L"editsubcluster";
            this->editsubcluster->Size = System::Drawing::Size(294, 36);
            this->editsubcluster->TabIndex = 313;
            // 
            // editsubsearchbutton
            // 
            this->editsubsearchbutton->BackColor = System::Drawing::Color::White;
            this->editsubsearchbutton->FlatAppearance->BorderSize = 0;
            this->editsubsearchbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->editsubsearchbutton->Location = System::Drawing::Point(841, 229);
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
            this->label101->Location = System::Drawing::Point(544, 172);
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
            this->editsubsearch->Location = System::Drawing::Point(507, 223);
            this->editsubsearch->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->editsubsearch->Name = L"editsubsearch";
            this->editsubsearch->Size = System::Drawing::Size(360, 36);
            this->editsubsearch->TabIndex = 312;
            this->editsubsearch->Text = L"Search";
            this->editsubsearch->GotFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxFocusSub);
            this->editsubsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyDownsubject);
            this->editsubsearch->LostFocus += gcnew System::EventHandler(this, &MyForm::OnSearchBoxLostFocusSub);
            // 
            // label94
            // 
            this->label94->AutoSize = true;
            this->label94->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label94->Location = System::Drawing::Point(163, 1031);
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
            this->panel10->Location = System::Drawing::Point(181, 763);
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
            this->label92->Location = System::Drawing::Point(153, 710);
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
            this->label95->Location = System::Drawing::Point(164, 873);
            this->label95->Name = L"label95";
            this->label95->Size = System::Drawing::Size(152, 28);
            this->label95->TabIndex = 294;
            this->label95->Text = L"Name of Cluster";
            // 
            // editsubeleteacher
            // 
            this->editsubeleteacher->AllowUserToOrderColumns = true;
            dataGridViewCellStyle22->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle22->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle22->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle22;
            this->editsubeleteacher->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->editsubeleteacher->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->editsubeleteacher->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle23->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle23->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle23->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle23->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteacher->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle23;
            this->editsubeleteacher->ColumnHeadersHeight = 40;
            this->editsubeleteacher->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->editsubeleteacher->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->editsubeleteachercombo,
                    this->dataGridViewButtonColumn10
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
            this->editsubeleteacher->DefaultCellStyle = dataGridViewCellStyle26;
            this->editsubeleteacher->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->editsubeleteacher->Location = System::Drawing::Point(173, 1085);
            this->editsubeleteacher->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->editsubeleteacher->Name = L"editsubeleteacher";
            dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle27->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle27->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteacher->RowHeadersDefaultCellStyle = dataGridViewCellStyle27;
            this->editsubeleteacher->RowHeadersVisible = false;
            this->editsubeleteacher->RowHeadersWidth = 62;
            dataGridViewCellStyle28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle28->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle28->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
            dataGridViewCellStyle28->SelectionForeColor = System::Drawing::Color::Black;
            this->editsubeleteacher->RowsDefaultCellStyle = dataGridViewCellStyle28;
            this->editsubeleteacher->RowTemplate->Height = 28;
            this->editsubeleteacher->Size = System::Drawing::Size(735, 230);
            this->editsubeleteacher->TabIndex = 296;
            this->editsubeleteacher->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::editsubeleteacher_CellContentClick);
            // 
            // editsubeleteachercombo
            // 
            dataGridViewCellStyle24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle24->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle24->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle24->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->editsubeleteachercombo->DefaultCellStyle = dataGridViewCellStyle24;
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
            dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle25->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle25->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn10->DefaultCellStyle = dataGridViewCellStyle25;
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
            this->editsubname->Location = System::Drawing::Point(201, 391);
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
            this->label93->Location = System::Drawing::Point(196, 345);
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
            this->panel21->Size = System::Drawing::Size(44, 434);
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
            this->button14->Location = System::Drawing::Point(57, 652);
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
            this->button13->Location = System::Drawing::Point(55, 684);
            this->button13->Margin = System::Windows::Forms::Padding(0);
            this->button13->Name = L"button13";
            this->button13->Size = System::Drawing::Size(267, 34);
            this->button13->TabIndex = 24;
            this->button13->Text = L"Delete            ";
            this->button13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->button13->UseVisualStyleBackColor = false;
            this->button13->Visible = false;
            this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
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
            this->textBox10->Location = System::Drawing::Point(272, 622);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(28, 26);
            this->textBox10->TabIndex = 32;
            this->textBox10->Text = L"◤";
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
            this->textBox11->Location = System::Drawing::Point(272, 619);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(28, 26);
            this->textBox11->TabIndex = 35;
            this->textBox11->Text = L"◢";
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
            this->panel1->Controls->Add(this->textBox11);
            this->panel1->Controls->Add(this->textBox7);
            this->panel1->Controls->Add(this->textBox9);
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
            // classele
            // 
            this->classele->AllowUserToOrderColumns = true;
            this->classele->AllowUserToResizeColumns = false;
            this->classele->AllowUserToResizeRows = false;
            dataGridViewCellStyle29->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle29->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle29->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle29->SelectionForeColor = System::Drawing::Color::Black;
            this->classele->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle29;
            this->classele->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classele->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->classele->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->classele->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle30->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle30->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classele->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle30;
            this->classele->ColumnHeadersHeight = 40;
            this->classele->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->classele->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->eSubject, this->dataGridViewButtonColumn3 });
            dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle33->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle33->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle33->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle33->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle33->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->classele->DefaultCellStyle = dataGridViewCellStyle33;
            this->classele->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classele->Location = System::Drawing::Point(188, 910);
            this->classele->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->classele->Name = L"classele";
            dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle34->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle34->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle34->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classele->RowHeadersDefaultCellStyle = dataGridViewCellStyle34;
            this->classele->RowHeadersVisible = false;
            this->classele->RowHeadersWidth = 62;
            dataGridViewCellStyle35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle35->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle35->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle35->SelectionForeColor = System::Drawing::Color::Black;
            this->classele->RowsDefaultCellStyle = dataGridViewCellStyle35;
            this->classele->RowTemplate->Height = 28;
            this->classele->Size = System::Drawing::Size(735, 230);
            this->classele->TabIndex = 253;
            this->classele->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classele_CellContentClick);
            // 
            // eSubject
            // 
            dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle31->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->eSubject->DefaultCellStyle = dataGridViewCellStyle31;
            this->eSubject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->eSubject->HeaderText = L"Subject";
            this->eSubject->MinimumWidth = 30;
            this->eSubject->Name = L"eSubject";
            this->eSubject->Resizable = System::Windows::Forms::DataGridViewTriState::False;
            this->eSubject->Width = 350;
            // 
            // dataGridViewButtonColumn3
            // 
            this->dataGridViewButtonColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle32;
            this->dataGridViewButtonColumn3->DividerWidth = 1;
            this->dataGridViewButtonColumn3->HeaderText = L"";
            this->dataGridViewButtonColumn3->MinimumWidth = 100;
            this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
            this->dataGridViewButtonColumn3->ReadOnly = true;
            this->dataGridViewButtonColumn3->Text = L"Delete";
            this->dataGridViewButtonColumn3->UseColumnTextForButtonValue = true;
            // 
            // classcore
            // 
            this->classcore->AllowUserToOrderColumns = true;
            this->classcore->AllowUserToResizeColumns = false;
            this->classcore->AllowUserToResizeRows = false;
            dataGridViewCellStyle36->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle36->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle36->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle36->SelectionForeColor = System::Drawing::Color::Black;
            this->classcore->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle36;
            this->classcore->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classcore->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->classcore->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->classcore->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle37->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle37->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle37->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle37->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classcore->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle37;
            this->classcore->ColumnHeadersHeight = 40;
            this->classcore->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->classcore->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->csubject, this->cteacher,
                    this->dataGridViewButtonColumn6
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
            this->classcore->DefaultCellStyle = dataGridViewCellStyle41;
            this->classcore->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classcore->Location = System::Drawing::Point(190, 618);
            this->classcore->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->classcore->Name = L"classcore";
            dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle42->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle42->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle42->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle42->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle42->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classcore->RowHeadersDefaultCellStyle = dataGridViewCellStyle42;
            this->classcore->RowHeadersVisible = false;
            this->classcore->RowHeadersWidth = 62;
            dataGridViewCellStyle43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle43->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle43->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle43->SelectionForeColor = System::Drawing::Color::Black;
            this->classcore->RowsDefaultCellStyle = dataGridViewCellStyle43;
            this->classcore->RowTemplate->Height = 28;
            this->classcore->Size = System::Drawing::Size(735, 170);
            this->classcore->TabIndex = 257;
            this->classcore->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classcore_CellContentClick);
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
            this->csubject->HeaderText = L"Core Subject";
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
            this->cteacher->HeaderText = L"Teacher";
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
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->Location = System::Drawing::Point(180, 132);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(77, 28);
            this->label38->TabIndex = 240;
            this->label38->Text = L"Section";
            // 
            // classname
            // 
            this->classname->AllowPromptAsInput = false;
            this->classname->AsciiOnly = true;
            this->classname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classname->BeepOnError = true;
            this->classname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classname->Location = System::Drawing::Point(185, 173);
            this->classname->Name = L"classname";
            this->classname->PromptChar = ' ';
            this->classname->Size = System::Drawing::Size(410, 34);
            this->classname->TabIndex = 244;
            this->classname->TextMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
            // 
            // classbranch
            // 
            this->classbranch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classbranch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->classbranch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classbranch->FormattingEnabled = true;
            this->classbranch->Location = System::Drawing::Point(189, 298);
            this->classbranch->Name = L"classbranch";
            this->classbranch->Size = System::Drawing::Size(406, 36);
            this->classbranch->TabIndex = 245;
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->Location = System::Drawing::Point(183, 384);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(225, 28);
            this->label37->TabIndex = 241;
            this->label37->Text = L"Batch(year of admission)";
            // 
            // classbatch
            // 
            this->classbatch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classbatch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classbatch->HidePromptOnLeave = true;
            this->classbatch->HideSelection = false;
            this->classbatch->Location = System::Drawing::Point(191, 436);
            this->classbatch->Name = L"classbatch";
            this->classbatch->Size = System::Drawing::Size(404, 34);
            this->classbatch->SkipLiterals = false;
            this->classbatch->TabIndex = 242;
            this->classbatch->TextMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
            this->classbatch->ValidatingType = System::Int32::typeid;
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->Location = System::Drawing::Point(183, 522);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(520, 84);
            this->label36->TabIndex = 243;
            this->label36->Text = L"Select the subjects taught and their corresponding teacher\r\n\r\n For non-elective a"
                L"nd non-lab subjects";
            // 
            // classdefaultrooms
            // 
            this->classdefaultrooms->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classdefaultrooms->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->classdefaultrooms->CheckOnClick = true;
            this->classdefaultrooms->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
            this->classdefaultrooms->FormattingEnabled = true;
            this->classdefaultrooms->Location = System::Drawing::Point(191, 1472);
            this->classdefaultrooms->Name = L"classdefaultrooms";
            this->classdefaultrooms->Size = System::Drawing::Size(287, 124);
            this->classdefaultrooms->TabIndex = 250;
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label34->Location = System::Drawing::Point(198, 1432);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(136, 28);
            this->label34->TabIndex = 251;
            this->label34->Text = L"Default rooms";
            // 
            // classgenerate
            // 
            this->classgenerate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classgenerate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classgenerate->Location = System::Drawing::Point(164, 33);
            this->classgenerate->Name = L"classgenerate";
            this->classgenerate->Size = System::Drawing::Size(147, 48);
            this->classgenerate->TabIndex = 248;
            this->classgenerate->Text = L"Generate";
            this->classgenerate->UseVisualStyleBackColor = false;
            this->classgenerate->Click += gcnew System::EventHandler(this, &MyForm::classgenerate_Click);
            // 
            // classsave
            // 
            this->classsave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classsave->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classsave->Location = System::Drawing::Point(350, 31);
            this->classsave->Name = L"classsave";
            this->classsave->Size = System::Drawing::Size(104, 48);
            this->classsave->TabIndex = 247;
            this->classsave->Text = L"Save";
            this->classsave->UseVisualStyleBackColor = false;
            this->classsave->Click += gcnew System::EventHandler(this, &MyForm::classsave_Click);
            // 
            // classclear
            // 
            this->classclear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classclear->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classclear->Location = System::Drawing::Point(480, 30);
            this->classclear->Name = L"classclear";
            this->classclear->Size = System::Drawing::Size(132, 48);
            this->classclear->TabIndex = 246;
            this->classclear->Text = L"Clear";
            this->classclear->UseVisualStyleBackColor = false;
            this->classclear->Click += gcnew System::EventHandler(this, &MyForm::classclear_Click);
            // 
            // classlab
            // 
            this->classlab->AllowUserToOrderColumns = true;
            this->classlab->AllowUserToResizeColumns = false;
            this->classlab->AllowUserToResizeRows = false;
            dataGridViewCellStyle44->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle44->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle44->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle44->SelectionForeColor = System::Drawing::Color::Black;
            this->classlab->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle44;
            this->classlab->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlab->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->classlab->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->classlab->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle45->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle45->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle45->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle45->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle45->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classlab->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle45;
            this->classlab->ColumnHeadersHeight = 40;
            this->classlab->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->classlab->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->lsubject, this->dataGridViewButtonColumn2 });
            dataGridViewCellStyle48->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle48->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle48->ForeColor = System::Drawing::SystemColors::ControlText;
            dataGridViewCellStyle48->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle48->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle48->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->classlab->DefaultCellStyle = dataGridViewCellStyle48;
            this->classlab->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classlab->Location = System::Drawing::Point(195, 1219);
            this->classlab->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->classlab->Name = L"classlab";
            dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle49->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle49->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle49->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle49->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle49->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classlab->RowHeadersDefaultCellStyle = dataGridViewCellStyle49;
            this->classlab->RowHeadersVisible = false;
            this->classlab->RowHeadersWidth = 62;
            dataGridViewCellStyle50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle50->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle50->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle50->SelectionForeColor = System::Drawing::Color::Black;
            this->classlab->RowsDefaultCellStyle = dataGridViewCellStyle50;
            this->classlab->RowTemplate->Height = 28;
            this->classlab->Size = System::Drawing::Size(735, 215);
            this->classlab->TabIndex = 254;
            this->classlab->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::classlab_CellContentClick);
            // 
            // lsubject
            // 
            dataGridViewCellStyle46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle46->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle46->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle46->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle46->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->lsubject->DefaultCellStyle = dataGridViewCellStyle46;
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
            dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle47->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            dataGridViewCellStyle47->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle47;
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
            this->label33->Location = System::Drawing::Point(200, 867);
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
            this->label32->Location = System::Drawing::Point(194, 1167);
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
            this->label13->Location = System::Drawing::Point(184, 258);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(71, 28);
            this->label13->TabIndex = 258;
            this->label13->Text = L"Branch";
            // 
            // classreserve
            // 
            this->classreserve->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->classreserve->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->classreserve->Location = System::Drawing::Point(18, 30);
            this->classreserve->Name = L"classreserve";
            this->classreserve->Size = System::Drawing::Size(120, 48);
            this->classreserve->TabIndex = 260;
            this->classreserve->Text = L"Reserve";
            this->classreserve->UseVisualStyleBackColor = false;
            this->classreserve->Click += gcnew System::EventHandler(this, &MyForm::classreserve_Click_1);
            // 
            // classpanel
            // 
            this->classpanel->AutoScroll = true;
            this->classpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->classpanel->Controls->Add(this->panel36);
            this->classpanel->Controls->Add(this->classtablegenpanel);
            this->classpanel->Controls->Add(this->finalttpanel);
            this->classpanel->Controls->Add(this->label13);
            this->classpanel->Controls->Add(this->label32);
            this->classpanel->Controls->Add(this->label33);
            this->classpanel->Controls->Add(this->classlab);
            this->classpanel->Controls->Add(this->label34);
            this->classpanel->Controls->Add(this->classdefaultrooms);
            this->classpanel->Controls->Add(this->label36);
            this->classpanel->Controls->Add(this->classbatch);
            this->classpanel->Controls->Add(this->label37);
            this->classpanel->Controls->Add(this->classbranch);
            this->classpanel->Controls->Add(this->classname);
            this->classpanel->Controls->Add(this->label38);
            this->classpanel->Controls->Add(this->classcore);
            this->classpanel->Controls->Add(this->classele);
            this->classpanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->classpanel->Location = System::Drawing::Point(0, 0);
            this->classpanel->Name = L"classpanel";
            this->classpanel->Size = System::Drawing::Size(1946, 1106);
            this->classpanel->TabIndex = 230;
            this->classpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint_1);
            // 
            // panel36
            // 
            this->panel36->Controls->Add(this->classreserve);
            this->panel36->Controls->Add(this->classclear);
            this->panel36->Controls->Add(this->classsave);
            this->panel36->Controls->Add(this->classgenerate);
            this->panel36->Location = System::Drawing::Point(596, 1635);
            this->panel36->Name = L"panel36";
            this->panel36->Size = System::Drawing::Size(640, 97);
            this->panel36->TabIndex = 303;
            // 
            // classtablegenpanel
            // 
            this->classtablegenpanel->Controls->Add(this->panel26);
            this->classtablegenpanel->Controls->Add(this->panel27);
            this->classtablegenpanel->Controls->Add(this->classtablegen);
            this->classtablegenpanel->Controls->Add(this->label135);
            this->classtablegenpanel->Controls->Add(this->label136);
            this->classtablegenpanel->Controls->Add(this->label137);
            this->classtablegenpanel->Controls->Add(this->label138);
            this->classtablegenpanel->Controls->Add(this->label139);
            this->classtablegenpanel->Controls->Add(this->label140);
            this->classtablegenpanel->Controls->Add(this->label141);
            this->classtablegenpanel->Controls->Add(this->label142);
            this->classtablegenpanel->Controls->Add(this->label143);
            this->classtablegenpanel->Controls->Add(this->label144);
            this->classtablegenpanel->Controls->Add(this->label145);
            this->classtablegenpanel->Controls->Add(this->label146);
            this->classtablegenpanel->Location = System::Drawing::Point(162, 2411);
            this->classtablegenpanel->Name = L"classtablegenpanel";
            this->classtablegenpanel->Size = System::Drawing::Size(1183, 621);
            this->classtablegenpanel->TabIndex = 302;
            // 
            // panel26
            // 
            this->panel26->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel26.BackgroundImage")));
            this->panel26->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel26->Location = System::Drawing::Point(416, 112);
            this->panel26->Name = L"panel26";
            this->panel26->Size = System::Drawing::Size(44, 413);
            this->panel26->TabIndex = 2;
            // 
            // panel27
            // 
            this->panel27->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel27.BackgroundImage")));
            this->panel27->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel27->Location = System::Drawing::Point(757, 110);
            this->panel27->Name = L"panel27";
            this->panel27->Size = System::Drawing::Size(44, 436);
            this->panel27->TabIndex = 1;
            // 
            // classtablegen
            // 
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
            this->classtablegen->Location = System::Drawing::Point(140, 113);
            this->classtablegen->Name = L"classtablegen";
            this->classtablegen->RowCount = 6;
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen->Size = System::Drawing::Size(949, 435);
            this->classtablegen->TabIndex = 260;
            // 
            // label135
            // 
            this->label135->AutoSize = true;
            this->label135->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label135->Location = System::Drawing::Point(158, 72);
            this->label135->Name = L"label135";
            this->label135->Size = System::Drawing::Size(105, 28);
            this->label135->TabIndex = 294;
            this->label135->Text = L"9:00-10:00";
            // 
            // label136
            // 
            this->label136->AutoSize = true;
            this->label136->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label136->Location = System::Drawing::Point(294, 72);
            this->label136->Name = L"label136";
            this->label136->Size = System::Drawing::Size(116, 28);
            this->label136->TabIndex = 295;
            this->label136->Text = L"10:00-11:00";
            // 
            // label137
            // 
            this->label137->AutoSize = true;
            this->label137->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label137->Location = System::Drawing::Point(480, 72);
            this->label137->Name = L"label137";
            this->label137->Size = System::Drawing::Size(116, 28);
            this->label137->TabIndex = 296;
            this->label137->Text = L"11:30-12:30";
            // 
            // label138
            // 
            this->label138->AutoSize = true;
            this->label138->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label138->Location = System::Drawing::Point(635, 72);
            this->label138->Name = L"label138";
            this->label138->Size = System::Drawing::Size(105, 28);
            this->label138->TabIndex = 297;
            this->label138->Text = L"12:30-1:30";
            // 
            // label139
            // 
            this->label139->AutoSize = true;
            this->label139->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label139->Location = System::Drawing::Point(828, 68);
            this->label139->Name = L"label139";
            this->label139->Size = System::Drawing::Size(94, 28);
            this->label139->TabIndex = 298;
            this->label139->Text = L"2:30-3:30";
            // 
            // label140
            // 
            this->label140->AutoSize = true;
            this->label140->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label140->Location = System::Drawing::Point(958, 68);
            this->label140->Name = L"label140";
            this->label140->Size = System::Drawing::Size(94, 28);
            this->label140->TabIndex = 299;
            this->label140->Text = L"3:30-4:30";
            // 
            // label141
            // 
            this->label141->AutoSize = true;
            this->label141->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label141->Location = System::Drawing::Point(43, 495);
            this->label141->Name = L"label141";
            this->label141->Size = System::Drawing::Size(90, 28);
            this->label141->TabIndex = 266;
            this->label141->Text = L"Saturday";
            // 
            // label142
            // 
            this->label142->AutoSize = true;
            this->label142->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label142->Location = System::Drawing::Point(43, 418);
            this->label142->Name = L"label142";
            this->label142->Size = System::Drawing::Size(66, 28);
            this->label142->TabIndex = 265;
            this->label142->Text = L"Friday";
            // 
            // label143
            // 
            this->label143->AutoSize = true;
            this->label143->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label143->Location = System::Drawing::Point(30, 342);
            this->label143->Name = L"label143";
            this->label143->Size = System::Drawing::Size(91, 28);
            this->label143->TabIndex = 264;
            this->label143->Text = L"Thursday";
            // 
            // label144
            // 
            this->label144->AutoSize = true;
            this->label144->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label144->Location = System::Drawing::Point(20, 280);
            this->label144->Name = L"label144";
            this->label144->Size = System::Drawing::Size(113, 28);
            this->label144->TabIndex = 263;
            this->label144->Text = L"Wednesday";
            // 
            // label145
            // 
            this->label145->AutoSize = true;
            this->label145->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label145->Location = System::Drawing::Point(47, 201);
            this->label145->Name = L"label145";
            this->label145->Size = System::Drawing::Size(83, 28);
            this->label145->TabIndex = 262;
            this->label145->Text = L"Tuesday";
            // 
            // label146
            // 
            this->label146->AutoSize = true;
            this->label146->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label146->Location = System::Drawing::Point(41, 132);
            this->label146->Name = L"label146";
            this->label146->Size = System::Drawing::Size(85, 28);
            this->label146->TabIndex = 261;
            this->label146->Text = L"Monday";
            // 
            // finalttpanel
            // 
            this->finalttpanel->Controls->Add(this->panel8);
            this->finalttpanel->Controls->Add(this->panel25);
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
            this->finalttpanel->Location = System::Drawing::Point(160, 1751);
            this->finalttpanel->Name = L"finalttpanel";
            this->finalttpanel->Size = System::Drawing::Size(1183, 621);
            this->finalttpanel->TabIndex = 301;
            // 
            // panel8
            // 
            this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
            this->panel8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel8->Location = System::Drawing::Point(416, 112);
            this->panel8->Name = L"panel8";
            this->panel8->Size = System::Drawing::Size(44, 413);
            this->panel8->TabIndex = 2;
            // 
            // panel25
            // 
            this->panel25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel25.BackgroundImage")));
            this->panel25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel25->Location = System::Drawing::Point(757, 110);
            this->panel25->Name = L"panel25";
            this->panel25->Size = System::Drawing::Size(44, 436);
            this->panel25->TabIndex = 1;
            // 
            // classtablegen1
            // 
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
            this->classtablegen1->Location = System::Drawing::Point(140, 113);
            this->classtablegen1->Name = L"classtablegen1";
            this->classtablegen1->RowCount = 6;
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->classtablegen1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->classtablegen1->Size = System::Drawing::Size(949, 435);
            this->classtablegen1->TabIndex = 260;
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label35->Location = System::Drawing::Point(158, 72);
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
            this->label52->Location = System::Drawing::Point(294, 72);
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
            this->label53->Location = System::Drawing::Point(480, 72);
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
            this->label54->Location = System::Drawing::Point(635, 72);
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
            this->label55->Location = System::Drawing::Point(828, 68);
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
            this->label56->Location = System::Drawing::Point(958, 68);
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
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(195, 168);
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
            this->addteachername->Location = System::Drawing::Point(199, 214);
            this->addteachername->Name = L"addteachername";
            this->addteachername->Size = System::Drawing::Size(361, 34);
            this->addteachername->TabIndex = 232;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(200, 295);
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
            this->addteacherdepartment->Location = System::Drawing::Point(200, 346);
            this->addteacherdepartment->Name = L"addteacherdepartment";
            this->addteacherdepartment->Size = System::Drawing::Size(362, 36);
            this->addteacherdepartment->TabIndex = 234;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(203, 549);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(161, 28);
            this->label3->TabIndex = 235;
            this->label3->Text = L"Teacher Schedule";
            // 
            // addteacherpanel
            // 
            this->addteacherpanel->AutoScroll = true;
            this->addteacherpanel->Controls->Add(this->panel17);
            this->addteacherpanel->Controls->Add(this->addteacheremailid);
            this->addteacherpanel->Controls->Add(this->label147);
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
            this->panel17->Location = System::Drawing::Point(1020, 1223);
            this->panel17->Name = L"panel17";
            this->panel17->Size = System::Drawing::Size(326, 110);
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
            // addteacheremailid
            // 
            this->addteacheremailid->AcceptsTab = true;
            this->addteacheremailid->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->addteacheremailid->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->addteacheremailid->ForeColor = System::Drawing::Color::Black;
            this->addteacheremailid->Location = System::Drawing::Point(199, 461);
            this->addteacheremailid->Name = L"addteacheremailid";
            this->addteacheremailid->Size = System::Drawing::Size(361, 34);
            this->addteacheremailid->TabIndex = 304;
            // 
            // label147
            // 
            this->label147->AutoSize = true;
            this->label147->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label147->Location = System::Drawing::Point(195, 415);
            this->label147->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label147->Name = L"label147";
            this->label147->Size = System::Drawing::Size(223, 28);
            this->label147->TabIndex = 303;
            this->label147->Text = L"Enter teachers\'s Email ID";
            // 
            // panel16
            // 
            this->panel16->Controls->Add(this->panel29);
            this->panel16->Controls->Add(this->panel30);
            this->panel16->Controls->Add(this->teachertablepanel);
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
            this->panel16->Location = System::Drawing::Point(185, 591);
            this->panel16->Name = L"panel16";
            this->panel16->Size = System::Drawing::Size(1183, 621);
            this->panel16->TabIndex = 302;
            // 
            // panel29
            // 
            this->panel29->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel29.BackgroundImage")));
            this->panel29->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel29->Location = System::Drawing::Point(416, 112);
            this->panel29->Name = L"panel29";
            this->panel29->Size = System::Drawing::Size(44, 413);
            this->panel29->TabIndex = 2;
            // 
            // panel30
            // 
            this->panel30->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel30.BackgroundImage")));
            this->panel30->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->panel30->Location = System::Drawing::Point(757, 110);
            this->panel30->Name = L"panel30";
            this->panel30->Size = System::Drawing::Size(44, 436);
            this->panel30->TabIndex = 1;
            // 
            // teachertablepanel
            // 
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
            this->teachertablepanel->Location = System::Drawing::Point(140, 113);
            this->teachertablepanel->Name = L"teachertablepanel";
            this->teachertablepanel->RowCount = 6;
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66666F)));
            this->teachertablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
            this->teachertablepanel->Size = System::Drawing::Size(949, 435);
            this->teachertablepanel->TabIndex = 260;
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label66->Location = System::Drawing::Point(158, 72);
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
            this->label67->Location = System::Drawing::Point(294, 72);
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
            this->label68->Location = System::Drawing::Point(480, 72);
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
            this->label69->Location = System::Drawing::Point(635, 72);
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
            this->label70->Location = System::Drawing::Point(828, 68);
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
            this->label71->Location = System::Drawing::Point(958, 68);
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
            this->label72->Location = System::Drawing::Point(43, 495);
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
            this->label73->Location = System::Drawing::Point(43, 418);
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
            this->label74->Location = System::Drawing::Point(30, 342);
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
            this->label75->Location = System::Drawing::Point(20, 280);
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
            this->label76->Location = System::Drawing::Point(47, 201);
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
            this->label77->Location = System::Drawing::Point(41, 132);
            this->label77->Name = L"label77";
            this->label77->Size = System::Drawing::Size(85, 28);
            this->label77->TabIndex = 261;
            this->label77->Text = L"Monday";
            // 
            // deptlabel
            // 
            this->deptlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptlabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deptlabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
            this->deptlabel->Location = System::Drawing::Point(648, 200);
            this->deptlabel->Name = L"deptlabel";
            this->deptlabel->Size = System::Drawing::Size(304, 32);
            this->deptlabel->TabIndex = 4;
            this->deptlabel->Text = L"Department List";
            // 
            // deptDataGridView
            // 
            this->deptDataGridView->AllowUserToOrderColumns = true;
            this->deptDataGridView->AllowUserToResizeColumns = false;
            this->deptDataGridView->AllowUserToResizeRows = false;
            dataGridViewCellStyle51->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle51->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle51->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle51->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
            this->deptDataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->deptDataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->deptDataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle52->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle52->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle52->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle52->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->deptDataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
            this->deptDataGridView->ColumnHeadersHeight = 40;
            this->deptDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->deptDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->dataGridViewTextBoxColumn1,
                    this->dataGridViewButtonColumn1
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
            this->deptDataGridView->DefaultCellStyle = dataGridViewCellStyle55;
            this->deptDataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->deptDataGridView->Location = System::Drawing::Point(397, 272);
            this->deptDataGridView->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->deptDataGridView->Name = L"deptDataGridView";
            dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle56->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle56->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle56->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle56->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle56->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->deptDataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle56;
            this->deptDataGridView->RowHeadersVisible = false;
            this->deptDataGridView->RowHeadersWidth = 62;
            dataGridViewCellStyle57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
            dataGridViewCellStyle57->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle57->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle57->SelectionForeColor = System::Drawing::Color::Black;
            this->deptDataGridView->RowsDefaultCellStyle = dataGridViewCellStyle57;
            this->deptDataGridView->RowTemplate->Height = 28;
            this->deptDataGridView->Size = System::Drawing::Size(735, 257);
            this->deptDataGridView->TabIndex = 233;
            this->deptDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick_1);
            // 
            // dataGridViewTextBoxColumn1
            // 
            dataGridViewCellStyle53->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle53->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle53->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle53->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle53->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle53;
            this->dataGridViewTextBoxColumn1->HeaderText = L"Department";
            this->dataGridViewTextBoxColumn1->MinimumWidth = 30;
            this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
            this->dataGridViewTextBoxColumn1->Width = 350;
            // 
            // dataGridViewButtonColumn1
            // 
            this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle54->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle54->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle54->SelectionForeColor = System::Drawing::Color::Black;
            this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle54;
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
            this->button2->Location = System::Drawing::Point(888, 654);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(121, 49);
            this->button2->TabIndex = 234;
            this->button2->Text = L"Save";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // button22
            // 
            this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(230)));
            this->button22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button22->Location = System::Drawing::Point(1040, 654);
            this->button22->Name = L"button22";
            this->button22->Size = System::Drawing::Size(121, 49);
            this->button22->TabIndex = 235;
            this->button22->Text = L"Clear All";
            this->button22->UseVisualStyleBackColor = false;
            this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
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
            // deleteclasspanel
            // 
            this->deleteclasspanel->Controls->Add(this->sectiondeletedatagridview);
            this->deleteclasspanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->deleteclasspanel->Location = System::Drawing::Point(0, 0);
            this->deleteclasspanel->Name = L"deleteclasspanel";
            this->deleteclasspanel->Size = System::Drawing::Size(1946, 1106);
            this->deleteclasspanel->TabIndex = 236;
            // 
            // sectiondeletedatagridview
            // 
            this->sectiondeletedatagridview->AllowUserToOrderColumns = true;
            this->sectiondeletedatagridview->AllowUserToResizeColumns = false;
            this->sectiondeletedatagridview->AllowUserToResizeRows = false;
            dataGridViewCellStyle58->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle58->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle58->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle58->SelectionForeColor = System::Drawing::Color::Black;
            this->sectiondeletedatagridview->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle58;
            this->sectiondeletedatagridview->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sectiondeletedatagridview->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->sectiondeletedatagridview->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
            this->sectiondeletedatagridview->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            dataGridViewCellStyle59->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle59->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Bold));
            dataGridViewCellStyle59->ForeColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle59->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
            dataGridViewCellStyle59->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
            dataGridViewCellStyle59->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sectiondeletedatagridview->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle59;
            this->sectiondeletedatagridview->ColumnHeadersHeight = 40;
            this->sectiondeletedatagridview->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->sectiondeletedatagridview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->classcolumn,
                    this->classdeletebutton
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
            this->sectiondeletedatagridview->DefaultCellStyle = dataGridViewCellStyle62;
            this->sectiondeletedatagridview->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->sectiondeletedatagridview->Location = System::Drawing::Point(369, 345);
            this->sectiondeletedatagridview->Margin = System::Windows::Forms::Padding(8, 4, 4, 4);
            this->sectiondeletedatagridview->Name = L"sectiondeletedatagridview";
            dataGridViewCellStyle63->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle63->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle63->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle63->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle63->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle63->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->sectiondeletedatagridview->RowHeadersDefaultCellStyle = dataGridViewCellStyle63;
            this->sectiondeletedatagridview->RowHeadersVisible = false;
            this->sectiondeletedatagridview->RowHeadersWidth = 62;
            dataGridViewCellStyle64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
            dataGridViewCellStyle64->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle64->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            dataGridViewCellStyle64->SelectionForeColor = System::Drawing::Color::Black;
            this->sectiondeletedatagridview->RowsDefaultCellStyle = dataGridViewCellStyle64;
            this->sectiondeletedatagridview->RowTemplate->Height = 28;
            this->sectiondeletedatagridview->Size = System::Drawing::Size(735, 257);
            this->sectiondeletedatagridview->TabIndex = 234;
            this->sectiondeletedatagridview->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            // 
            // classcolumn
            // 
            dataGridViewCellStyle60->BackColor = System::Drawing::Color::White;
            dataGridViewCellStyle60->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle60->Padding = System::Windows::Forms::Padding(1);
            dataGridViewCellStyle60->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
            dataGridViewCellStyle60->SelectionForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle60->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classcolumn->DefaultCellStyle = dataGridViewCellStyle60;
            this->classcolumn->HeaderText = L"Section";
            this->classcolumn->MinimumWidth = 30;
            this->classcolumn->Name = L"classcolumn";
            this->classcolumn->Width = 350;
            // 
            // classdeletebutton
            // 
            this->classdeletebutton->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
            dataGridViewCellStyle61->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(196)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
            dataGridViewCellStyle61->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle61->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(194)));
            dataGridViewCellStyle61->SelectionForeColor = System::Drawing::Color::Black;
            this->classdeletebutton->DefaultCellStyle = dataGridViewCellStyle61;
            this->classdeletebutton->HeaderText = L"";
            this->classdeletebutton->MinimumWidth = 100;
            this->classdeletebutton->Name = L"classdeletebutton";
            this->classdeletebutton->ReadOnly = true;
            this->classdeletebutton->Text = L"Delete";
            this->classdeletebutton->UseColumnTextForButtonValue = true;
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
            this->Controls->Add(this->editsubjectpanel);
            this->Controls->Add(this->addclassroompanel);
            this->Controls->Add(this->Homepanel);
            this->Controls->Add(this->classpanel);
            this->Controls->Add(this->deleteclasspanel);
            this->Controls->Add(this->editteacherpanel);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->settingspanel);
            this->Controls->Add(this->addteacherpanel);
            this->Controls->Add(this->addsubjectpanel);
            this->Controls->Add(this->editroompanel);
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
            this->panel33->ResumeLayout(false);
            this->panel33->PerformLayout();
            this->panel9->ResumeLayout(false);
            this->panel7->ResumeLayout(false);
            this->panel7->PerformLayout();
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
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            this->panel18->ResumeLayout(false);
            this->editroompanel->ResumeLayout(false);
            this->editroompanel->PerformLayout();
            this->panel15->ResumeLayout(false);
            this->panel15->PerformLayout();
            this->panel14->ResumeLayout(false);
            this->panel6->ResumeLayout(false);
            this->panel6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editroomcapacity))->EndInit();
            this->editsubjectpanel->ResumeLayout(false);
            this->editsubjectpanel->PerformLayout();
            this->editsubelepanel->ResumeLayout(false);
            this->editsubelepanel->PerformLayout();
            this->editpanelsub->ResumeLayout(false);
            this->editpanelsub->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubcredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsubbfactor))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editsublabteacher))->EndInit();
            this->panel13->ResumeLayout(false);
            this->panel13->PerformLayout();
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classele))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classcore))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classlab))->EndInit();
            this->classpanel->ResumeLayout(false);
            this->classpanel->PerformLayout();
            this->panel36->ResumeLayout(false);
            this->classtablegenpanel->ResumeLayout(false);
            this->classtablegenpanel->PerformLayout();
            this->finalttpanel->ResumeLayout(false);
            this->finalttpanel->PerformLayout();
            this->addteacherpanel->ResumeLayout(false);
            this->addteacherpanel->PerformLayout();
            this->panel17->ResumeLayout(false);
            this->panel16->ResumeLayout(false);
            this->panel16->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deptDataGridView))->EndInit();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->deleteclasspanel->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectiondeletedatagridview))->EndInit();
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
        DisplayCSVInComboBox(deptDataGridView, "details/dept_file.csv");
    }
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        Homepanel->BringToFront();
        panel1->BringToFront();
        DisplayCSVInComboBox(deptDataGridView, "details/dept_file.csv");
        pictureBox12->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
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
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
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
        panel3->Height = button9->Height;
        panel3->Top = button9->Top;
        addteacherpanel->BringToFront();
        DisplayCSVInComboBox1("details/dept_file.csv", addteacherdepartment);
        button8->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
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
            button->BackColor = Color::FromArgb(179, 255, 230);
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
        DisplayCSVInListBox(filePath, addsubroomlist, 0);
        const std::string fileName = "details/teacher_file.csv";
        TeacherName->DataSource = CreateDataTableFromCSV1(fileName, "teacherName");
        TeacherName->DisplayMember = "TeacherName"; // Update to the correct column name
        TeacherName->ValueMember = "TeacherName";
        list<string> itemsList;
        Teacher_Name->DataSource = CreateDataTableFromCSV1(fileName, "Teacher_Name");
        Teacher_Name->DisplayMember = "Teacher_Name"; // Update to the correct column name
        Teacher_Name->ValueMember = "Teacher_Name";
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
        addsubeletablepanel->Visible = false;
        panelsub->Top = addsubeletablepanel->Top;
    }
    private: System::Void addsubsave_Click(System::Object^ sender, System::EventArgs^ e) {

        bool  flag = true;
        bool eleflag = true;
        if (String::IsNullOrEmpty(addsubname->Text))
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
        if (addsubeleyes->Checked)
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
            string name = msclr::interop::marshal_as<string>(addsubcluster->Text);
            vector < vector<string>> data = ReadCSVFile("details/Electivetimetable.csv");
            vector<vector<vector<bool>>>tt = valuetimetable(name, sedataGridView);
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
                            if (button->Text != "busy")
                                xflag = true;
                            break;
                            break;
                        }
                    }

                }
            }
            if (xflag)
            {
                eleflag = false;
                MessageBox::Show("Select eligible timeslots to block.", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
                                button->BackColor = Color::FromArgb(179, 255, 230);
                            }
                        }

                    }
                }
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
        if (addsubbfactor->Value <= 0 && !addsubeleyes->Checked)
        {
            MessageBox::Show("Invalid bfactor Value", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if (addsubeleyes->Checked)
        {
            if (eleflag)
            {
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
                            if (row[0] == msclr::interop::marshal_as<string>(addsubcluster->Text))
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
                                                            row[(2 * i) + 1] = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
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
                                    if (button->Text == addsubname->Text)
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
                                                        row[(2 * i) + 1] = '1';
                                                        row[(2 * i) + 2] = replacewhitespace(msclr::interop::marshal_as<string>(addsubname->Text));
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
        if (button14->Visible == false)
        {
            button14->Visible = true;
            button13->Visible = true;
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
        textBox6->Visible = false;
        textBox7->Visible = true;
        //close teachers suboption
        button8->Visible = false;
        button7->Visible = false;
        textBox6->Visible = false;
        textBox7->Visible = true;
    }
    private: System::Void classcore_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn6, classcore, sender, e);
    }
    private: System::Void classele_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn3, classele, sender, e);
    }
    private: System::Void classlab_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn2, classlab, sender, e);
    }
    private: System::Void addsubcluster_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void addsubjectpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void addsubclusteroptions_Click_1(System::Object^ sender, System::EventArgs^ e) {
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
                if (allsections.size() == 0)
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
                    int secval;
                    //Making class name
                    if (Sec[0] > 'Z')
                    {
                        secval = Sec[0] - 'a';
                    }
                    else
                        secval = Sec[0] - 'A';
                    String^ branch = classbranch->Text->ToString();
                    string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
                    int branchval = 0;
                    for (int i = 0; i < Branch.size(); i++)
                        if (Branch[i] > 'Z')
                        {
                            branchval = Branch[i] - 'a';
                        }
                        else
                            branchval = Branch[i] - 'A';
                    String^ year = classbatch->Text->ToString();
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
                    ofstream sfile;
                    sfile.open("details/section.csv", ios::app);
                    if (sfile.is_open())
                    {
                        sfile << obj.convertToString() << "\n";
                    }
                    sfile.close();
                }
                else
                {
                    section obj;
                    String^ sec = classname->Text->ToString();
                    string Sec = replacewhitespace(msclr::interop::marshal_as<string>(sec));
                    int secval;
                    //Making class name
                    if (Sec[0] > 'Z')
                    {
                        secval = Sec[0] - 'a';
                    }
                    else
                        secval = Sec[0] - 'A';
                    String^ branch = classbranch->Text->ToString();
                    string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
                    int branchval = 0;
                    for (int i = 0; i < Branch.size(); i++)
                        if (Branch[i] > 'Z')
                        {
                            branchval = Branch[i] - 'a';
                        }
                        else
                            branchval = Branch[i] - 'A';
                    String^ year = classbatch->Text->ToString();
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
                            tt += period + ",";
                        }
                        tt += "\n";
                    }
                    tt += "\n\n";
                    tt += "TEACHERS\n";
                    for (auto day : allsections[allsections.size() - 1].teacherTable)
                    {
                        for (auto period : day)
                        {
                            tt += period + ",";
                        }
                        tt += "\n";
                    }
                    tt += "\n\n";
                    tt += "ROOM\n";
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
                File::Copy("details/teacher_file.csv", "details/duplicate.csv", true);
                ofstream files("details/duplicate.csv");
                if (files.is_open())
                {
                    for (auto t : allsections[allsections.size() - 1].allTeachers)
                    {
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
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
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
        {
            editteachercsvdelete("details/teacher_File.csv");

            editteachername->Clear();
            editteacheremailid->Clear();
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
        panel3->Top = button6->Top;
        button4->BackColor = Color::FromArgb(0, 0, 100);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button14->BackColor = Color::FromArgb(0, 0, 77);
        DisplayCSVInComboBox1("details/dept_file.csv", editroomdepartment);
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
        editsubeleteachercombo->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "editsubeleteachercombo");
        editsubeleteachercombo->DisplayMember = "editsubeleteachercombo"; // Update to the correct column name
        editsubeleteachercombo->ValueMember = "editsubeleteachercombo";
        editsublabteachercombo->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "editsublabteachercombo");
        editsublabteachercombo->DisplayMember = "editsublabteachercombo"; // Update to the correct column name
        editsublabteachercombo->ValueMember = "editsublabteachercombo";
        DisplayCSVInListBox("details/classroom.csv", editsubroomlist, 0);
        DisplayCSVInComboBox1("details/Electivetimetable.csv", editsubcluster);
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
        editpanelsub->Top = editsubelepanel->Top;
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
        addteacheremailid->Clear();
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
            if (String::IsNullOrEmpty(editsubcluster->Text))
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
        if (editsubbfactor->Value == 0)
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
            editsubcluster->Text = "";
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
        deletebutton(dataGridViewButtonColumn10, editsubeleteacher, sender, e);
    }
    private: System::Void editsublabteacher_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        deletebutton(dataGridViewButtonColumn11, editsublabteacher, sender, e);
    }
    private: System::Void editsubeleyes_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
        if (editsubeleyes->Checked)
        {
            editsubcluster->Text = "";
            editsubeleteacher->Cursor = Cursors::Arrow;
            editsubeleteacher->ReadOnly = false;
            editsubcluster->Cursor = Cursors::Arrow;
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
        bool flag=true;
        if (addsubname->Text == "")
        {
            MessageBox::Show("Subject Name not filled", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        else if (addsubeleyes->Checked == false )
        {
            MessageBox::Show("Only applicable for Electives", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
            flag = false;
        }
        if(flag)
        {
            addsubeletablepanel->Visible = true;
            panelsub->Top = addsubeletablepanel->Bottom;
            InitializeMatrix(tableLayoutPanel1, "ele", "Available", 0);
            onOptionClick(addsubcluster, sedataGridView, tableLayoutPanel1, "ele");
        }
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
            classtablegenpanel->Visible = false;
            finalttpanel->Visible = true;
            finalttpanel->Top = panel36->Bottom;
            String^ sec = (classname)->Text->ToString();
            string Sec = replacewhitespace(msclr::interop::marshal_as<string>(sec));
            int secval;
            //Making class name
            if (Sec[0] > 'Z')
            {
                secval = Sec[0] - 'a';
            }
            else
                secval = Sec[0] - 'A';
            String^ branch = classbranch->Text->ToString();
            string Branch = replacewhitespace(msclr::interop::marshal_as<string>(branch));
            int branchval = 0;
            for (int i = 0; i < Branch.size(); i++)
                if (Branch[i] > 'Z')
                {
                    branchval = Branch[i] - 'a';
                }
                else
                    branchval = Branch[i] - 'A';
            String^ year = classbatch->Text->ToString();
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
                    Button^ button = dynamic_cast<Button^>(classtablegen1->Controls[String::Format("buttong{0}", 6 * i + j + 1)]);
                    if (obj.timeTable[i][j] != "f")
                        button->Text = msclr::interop::marshal_as<String^>(obj.timeTable[i][j]);
                    else
                        button->Text = "free";
                }
            }
        }
    }
    private: System::Void classreserve_Click_1(System::Object^ sender, System::EventArgs^ e) {
        InitializeMatrix(classtablegen, "res", "Open", 3);
        classtablegenpanel->Visible = true;
        classtablegenpanel->Top = panel36->Bottom;
        finalttpanel->Visible = false;
    }
    private: System::Void classclear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearReset();
        classtablegenpanel->Visible = false;
        finalttpanel->Visible = false;
        classbatch->Clear();
        classname->Clear();
        classbranch->Text = "";
        classlab->Rows->Clear();
        classele->Rows->Clear();
        for (int i = classdefaultrooms->Items->Count - 1; i >= 0; i--) {
            classdefaultrooms->SetItemChecked(i, false);
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
        button14->BackColor = Color::FromArgb(0, 0, 100);
        button4->BackColor = Color::FromArgb(0, 0, 77);
        button5->BackColor = Color::FromArgb(0, 0, 77);
        button8->BackColor = Color::FromArgb(0, 0, 77);
        button10->BackColor = Color::FromArgb(0, 0, 77);
        button11->BackColor = Color::FromArgb(0, 0, 77);
        button13->BackColor = Color::FromArgb(0, 0, 77);
        button7->BackColor = Color::FromArgb(0, 0, 77);
        classpanel->BringToFront();
        InitializeMatrix(classtablegen, "res", "Open", 3);
        InitializeMatrix(classtablegen1, "g", "free", -1);
        finalttpanel->Top = classsave->Bottom;
        finalttpanel->Visible = false;
        classtablegenpanel->Visible = false;
        classbatch->Clear();
        classname->Clear();
        classbranch->Text = "";
        classlab->Rows->Clear();
        classele->Rows->Clear();
        classdefaultrooms->Items->Clear();
        DisplayCSVInComboBox1("details/dept_file.csv", classbranch);
        DisplayCSVInListBox("details/classroom.csv", classdefaultrooms, 3);
        csubject->DataSource = CreateDataTableFromCSV1("details/subject_file.csv", "Core Subject");
        csubject->DisplayMember = "Core Subject"; // Update to the correct column name
        csubject->ValueMember = "Core Subject";
        cteacher->DataSource = CreateDataTableFromCSV1("details/teacher_file.csv", "cteacher");
        cteacher->DisplayMember = "cteacher"; // Update to the correct column name
        cteacher->ValueMember = "cteacher";
        eSubject->DataSource = CreateDataTableFromCSV1("details/electivetimetable.csv", "esubject");
        eSubject->DisplayMember = "eSubject"; // Update to the correct column name
        eSubject->ValueMember = "eSubject";
        lsubject->DataSource = CreateDataTableFromCSV1("details/Labo.csv", "lsubject");
        lsubject->DisplayMember = "lsubject"; // Update to the correct column name
        lsubject->ValueMember = "lsubject";
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
                File::Copy("details/teacher_file.csv", "details/duplicate.csv", true);
                ofstream files("details/duplicate.csv");
                if (files.is_open())
                {
                    for (auto t : obj.allTeachers)
                    {
                        files << t.convertToString() << "\n";
                    }

                }
                files.close();
                File::Copy("details/duplicate.csv", "details/teacher_file.csv", true);
                File::Delete("details/duplicate.csv");
                ofstream fils("details/classroom.csv");
                if (fils.is_open())
                {
                    for (auto t : obj.allRooms)
                    {
                        fils << t.convertToString() << "\n";
                    }

                }
                fils.close();
                replacename(find, "details/section.csv", 0, "");
                sectiondeletedatagridview->Rows->RemoveAt(rowIndexToDelete);
            }
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
        DisplayCSVInComboBox(sectiondeletedatagridview, "details/section.csv");
    }
    private: System::Void editteachersearchbutton_Click(System::Object^ sender, System::EventArgs^ e) {
        editteachercsvshow("details/teacher_file.csv");
    }
    private: System::Void panel37_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        if (editsubeleyes->Checked == true)
        {
            editsubelepanel->Visible = true;
            editpanelsub->Top = editsubelepanel->Bottom;
            InitializeMatrix(editsubeletable, "editele", "Available", 2);
            onOptionClickedit(editsubcluster, editsubeleteacher, editsubeletable, "editele");
        }
        else
        {
            MessageBox::Show("Only applicable for Electives", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    };
}
