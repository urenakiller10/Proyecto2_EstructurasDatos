#include "pch.h"
#include "Mercado.h"

using namespace System;
using namespace System::Windows::Forms;

void mercado()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Proyecto2_ED::Mercado^ mercadoForm = gcnew Proyecto2_ED::Mercado();
	Application::Run(mercadoForm);
}

