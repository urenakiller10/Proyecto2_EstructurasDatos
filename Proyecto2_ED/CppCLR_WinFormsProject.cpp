#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

float dinero = 9999;

using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinFormsProject::Form1());
	return 0;
}
