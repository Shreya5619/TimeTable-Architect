#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

std::vector<section> allsections;
std::string searchteachername="";
std::string searchroomname;
std::string searchsubname;
std::vector<std::vector<bool>> reserveMatrix;
std::vector<std::vector<std::string>> labteachers;;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TTA_ui::MyForm form;
	Application::Run(% form);
	
}