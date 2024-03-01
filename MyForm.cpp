#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

std::vector<section> allsections;
std::string searchteachername="";
std::string searchroomname;
std::string searchsubname;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TTA_ui::MyForm form;
	Application::Run(% form);
	
}