#include "pch.h"

using namespace System;

#include "Form1.h"

float dinero = 90000;

using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinFormsProject::Form1());
	return 0;
}
