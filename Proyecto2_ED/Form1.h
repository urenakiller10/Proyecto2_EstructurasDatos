
#include "Configuracion.h"
#include "AreaJuego.h"


#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	/// 
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ T�tulo;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->T�tulo = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// T�tulo
			// 
			this->T�tulo->AutoSize = true;
			this->T�tulo->BackColor = System::Drawing::Color::ForestGreen;
			this->T�tulo->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->T�tulo->Location = System::Drawing::Point(371, 117);
			this->T�tulo->Name = L"T�tulo";
			this->T�tulo->Size = System::Drawing::Size(341, 83);
			this->T�tulo->TabIndex = 0;
			this->T�tulo->Text = L"TEC Farm";
			this->T�tulo->Click += gcnew System::EventHandler(this, &Form1::T�tulo_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(195, 407);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(251, 132);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(630, 407);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(296, 126);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Configuraciones";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("animales.jpg")));
			this->label1->Location = System::Drawing::Point(510, 301);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleGreen;
			this->ClientSize = System::Drawing::Size(1092, 680);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->T�tulo);
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//boton de "Configuraciones"
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


		Proyecto2_ED::Configuracion^ ventaConfi = gcnew Proyecto2_ED::Configuracion();
		ventaConfi->Show();


	}
		   //boton de "JUGAR"

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Proyecto2_ED::AreaJuego^ ventJuego = gcnew Proyecto2_ED::AreaJuego();
		ventJuego->Show();

	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void T�tulo_Click(System::Object^ sender, System::EventArgs^ e) {
}
};

	};

