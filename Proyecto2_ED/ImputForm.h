#pragma once

#include <string>


namespace Proyecto2_ED {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class InputForm : public Form
	{
	public:
		Label^ label;
		TextBox^ textBox;
		Button^ buttonAceptar;
		System::String^ nombreGlobal;

	public:
		InputForm()
		{
			InitializeComponent();
		}

		System::String^ GetNombre()
		{
			return nombreGlobal;
		}

	private:
		void InitializeComponent()
		{
			label = gcnew Label();
			textBox = gcnew TextBox();
			buttonAceptar = gcnew Button();

			SuspendLayout();

			label->Location = Drawing::Point(10, 10);
			label->Text = "Ingrese su nombre:";
			label->AutoSize = true;

			textBox->Location = Drawing::Point(10, 30);
			textBox->Size = Drawing::Size(200, 20);

			buttonAceptar->Location = Drawing::Point(10, 60);
			buttonAceptar->Size = Drawing::Size(80, 23);
			buttonAceptar->Text = "Aceptar";
			buttonAceptar->Click += gcnew EventHandler(this, &InputForm::buttonAceptar_Click);

			ClientSize = Drawing::Size(220, 100);
			Controls->Add(label);
			Controls->Add(textBox);
			Controls->Add(buttonAceptar);

			ResumeLayout(false);
			PerformLayout();
		}

		void buttonAceptar_Click(Object^ sender, EventArgs^ e)
		{
			if (System::String::IsNullOrEmpty(textBox->Text))
			{
				MessageBox::Show("Nombre inválido. Inténtelo de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				nombreGlobal = textBox->Text;
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}
	};
}
