#pragma once
#ifndef FORM1_H
#define FORM1_H


//-----Includes necesarios en el programa-------

#include "Configuracion.h"
#include "AreaJuego.h"
#include "ImputForm.h"
#include <regex>
#include <sstream>
#include "Administrador.h"
#include "Confi.h"

using namespace System::Windows::Forms;


Administrador* admin = new Administrador();
Confi* config = new Confi();

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
	private: System::Windows::Forms::Label^ Título;
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
			this->Título = (gcnew System::Windows::Forms::Label());
			this->B_Jugar = (gcnew System::Windows::Forms::Button());
			this->B_Configuracion = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->B_Top = (gcnew System::Windows::Forms::Button());
			this->B_Cargar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Título
			// 
			this->Título->AutoSize = true;
			this->Título->BackColor = System::Drawing::Color::Blue;
			this->Título->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Título->Location = System::Drawing::Point(76, 64);
			this->Título->Name = L"Título";
			this->Título->Size = System::Drawing::Size(341, 83);
			this->Título->TabIndex = 0;
			this->Título->Text = L"TEC Farm";
			this->Título->Click += gcnew System::EventHandler(this, &Form1::Título_Click);
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
			this->B_Top->Click += gcnew System::EventHandler(this, &Form1::B_Top_Click);
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
			this->Controls->Add(this->Título);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion


		//-------------Boton de "Configuraciones"--------------
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


			Proyecto2_ED::Configuracion^ ventaConfi = gcnew Proyecto2_ED::Configuracion();
			ventaConfi->Show();

		}

		//--------------Boton de "JUGAR"----------------------

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


			//Se abre primero mercado y luego ya el juego

				Proyecto2_ED::AreaJuego^ ventJuego = gcnew Proyecto2_ED::AreaJuego(admin,config);
				ventJuego->Show();


				//Esto va a valer verga y no se muestra al inicio, que se esperen.
				//Proyecto2_ED::Mercado^ ventMercado = gcnew Proyecto2_ED::Mercado(admin);
				//ventMercado->Show();

	};
	
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Título_Click(System::Object^ sender, System::EventArgs^ e) {
	}


		   // Función estática para comparar los pares (nombre, dinero) en función de la cantidad de dinero (orden descendente)
		   static bool Comparador(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
			   return a.second > b.second;
		   }


	private: System::Void B_Top_Click(System::Object^ sender, System::EventArgs^ e) 

		{
		// Crear una ventana para mostrar el contenido de Top10.txt
		System::Windows::Forms::Form^ ventanaTop10 = gcnew System::Windows::Forms::Form();
		ventanaTop10->Text = "TOP";
		ventanaTop10->Width = 210;
		ventanaTop10->Height = 350;
		ventanaTop10->BackColor = System::Drawing::Color::Green;

		// Crear un control ListView
		System::Windows::Forms::ListView^ listView = gcnew System::Windows::Forms::ListView();
		listView->Dock = System::Windows::Forms::DockStyle::Fill;
		listView->View = System::Windows::Forms::View::Details;
		listView->BackColor = System::Drawing::Color::LimeGreen;

		// Agregar las columnas "Nombre" y "Dinero" al ListView
		listView->Columns->Add(" Nombre", 100);
		listView->Columns->Add(" Dinero", 100);

// Leer el contenido del archivo Top10.txt
		std::ifstream archivo("Top10.txt");
		if (archivo.is_open()) {
			std::vector<std::pair<std::string, int>> datos; // Vector para almacenar los datos

			std::string linea;
			while (std::getline(archivo, linea)) {
				// Dividir la línea en nombre y dinero
				std::string nombre, dinero;
				std::istringstream iss(linea);
				iss >> nombre >> dinero;

				// Convertir el dinero a entero
				int dineroInt = std::stoi(dinero);

				// Agregar los datos al vector
				datos.push_back(std::make_pair(nombre, dineroInt));
			}

			archivo.close();

			// Ordenar el vector en función de la cantidad de dinero (orden descendente) usando el comparador estático
			std::sort(datos.begin(), datos.end(), Comparador);

			// Agregar los elementos al ListView en el orden correcto
			for (const auto& dato : datos) {
				System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(gcnew System::String(dato.first.c_str()));
				item->SubItems->Add(gcnew System::String(std::to_string(dato.second).c_str()));
				listView->Items->Add(item);
			}
		}
		else {
			MessageBox::Show("Error al abrir el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Ajustar el tamaño de fuente del ListView
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font(listView->Font->FontFamily, 13);
		listView->Font = fuente;

		// Agregar el ListView a la ventana
		ventanaTop10->Controls->Add(listView);

		// Mostrar la ventana
		ventanaTop10->Show();
	}
		 
	};

	};

#endif