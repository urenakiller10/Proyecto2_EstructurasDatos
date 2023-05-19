
//-----Includes necesarios en el programa-------

#include "Configuracion.h"
#include "AreaJuego.h"
using namespace System::Windows::Forms;
#include "Mercado.h"
#include "ImputForm.h"
#include <regex>


#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// 
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			initCustom();

		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ T�tulo;
	private: System::Windows::Forms::Button^ B_Jugar;
	private: System::Windows::Forms::Button^ B_Configuracion;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ B_Top;
	private: System::Windows::Forms::Button^ B_Cargar;
	private:System::ComponentModel::Container^ components;

		
		void initCustom() {
			this->pictureBox1->Image = Image::FromFile("recursos//animales.jpg");
	
						}

	#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->T�tulo = (gcnew System::Windows::Forms::Label());
			this->B_Jugar = (gcnew System::Windows::Forms::Button());
			this->B_Configuracion = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Top = (gcnew System::Windows::Forms::Button());
			this->B_Cargar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// T�tulo
			// 
			this->T�tulo->AutoSize = true;
			this->T�tulo->BackColor = System::Drawing::Color::Blue;
			this->T�tulo->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->T�tulo->Location = System::Drawing::Point(76, 64);
			this->T�tulo->Name = L"T�tulo";
			this->T�tulo->Size = System::Drawing::Size(341, 83);
			this->T�tulo->TabIndex = 0;
			this->T�tulo->Text = L"TEC Farm";
			this->T�tulo->Click += gcnew System::EventHandler(this, &Form1::T�tulo_Click);
			// 
			// Boton_Jugar
			// 
			this->B_Jugar->BackColor = System::Drawing::Color::Red;
			this->B_Jugar->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B_Jugar->Location = System::Drawing::Point(490, 406);
			this->B_Jugar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->B_Jugar->Name = L"B_Jugar";
			this->B_Jugar->Size = System::Drawing::Size(307, 132);
			this->B_Jugar->TabIndex = 1;
			this->B_Jugar->Text = L"Jugar";
			this->B_Jugar->UseVisualStyleBackColor = false;
			this->B_Jugar->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Boton_Configuracion
			// 
			this->B_Configuracion->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->B_Configuracion->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B_Configuracion->Location = System::Drawing::Point(833, 409);
			this->B_Configuracion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->B_Configuracion->Name = L"B_Configuracion";
			this->B_Configuracion->Size = System::Drawing::Size(300, 129);
			this->B_Configuracion->TabIndex = 2;
			this->B_Configuracion->Text = L"Configuraciones";
			this->B_Configuracion->UseVisualStyleBackColor = false;
			this->B_Configuracion->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Imagen de fondo
			// 
			this->pictureBox1->Location = System::Drawing::Point(-3, -58);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1224, 780);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Boton_Top10
			// 
			this->B_Top->BackColor = System::Drawing::Color::Gold;
			this->B_Top->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B_Top->Location = System::Drawing::Point(490, 568);
			this->B_Top->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->B_Top->Name = L"B_Top";
			this->B_Top->Size = System::Drawing::Size(307, 132);
			this->B_Top->TabIndex = 5;
			this->B_Top->Text = L"Mostrar TOP 10";
			this->B_Top->UseVisualStyleBackColor = false;
			this->B_Top->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Boton_CargarPartida
			// 
			this->B_Cargar->BackColor = System::Drawing::Color::CornflowerBlue;
			this->B_Cargar->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B_Cargar->Location = System::Drawing::Point(833, 568);
			this->B_Cargar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->B_Cargar->Name = L"B_Cargar";
			this->B_Cargar->Size = System::Drawing::Size(290, 132);
			this->B_Cargar->TabIndex = 6;
			this->B_Cargar->Text = L"Cargar partida";
			this->B_Cargar->UseVisualStyleBackColor = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleGreen;
			this->ClientSize = System::Drawing::Size(1216, 723);
			this->Controls->Add(this->B_Cargar);
			this->Controls->Add(this->B_Top);
			this->Controls->Add(this->B_Configuracion);
			this->Controls->Add(this->B_Jugar);
			this->Controls->Add(this->T�tulo);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion


		//Boton de "Configuraciones"
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


			Proyecto2_ED::Configuracion^ ventaConfi = gcnew Proyecto2_ED::Configuracion();
			ventaConfi->Show();


		}

		//Boton de "JUGAR"

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			//--- Crear una ventana de di�logo para ingresar el nombre---

			Proyecto2_ED::InputForm^ inputForm = gcnew Proyecto2_ED::InputForm();

			//--- Mostrar la ventana de di�logo y obtener el nombre ingresado--

			if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::String^ nombre = inputForm->GetNombre();

			// Verificar si el nombre es un string v�lido
				if (System::String::IsNullOrEmpty(nombre)) {
					MessageBox::Show("Nombre inv�lido. Int�ntelo de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			//Se abre primero mercado y luego ya el juego

				Proyecto2_ED::AreaJuego^ ventaJuego = gcnew Proyecto2_ED::AreaJuego();
				ventaJuego->Show();

				Proyecto2_ED::Mercado^ ventMercado = gcnew Proyecto2_ED::Mercado();
				ventMercado->Show();


			}
			else {
				// El usuario cancel� la entrada del nombre
				return;
			}
	
	};
	
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void T�tulo_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {


	}
		 
	};

	};

