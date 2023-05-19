#pragma once
//Includes necesarios

#include "Configuracion.h"


namespace Proyecto2_ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	public ref class Mercado : public System::Windows::Forms::Form
	{

	public:

		static int disponible =5000;
		int PendAVL;
		int PendSplay;
		int PendHeap;
		int PendEspanta;

	public:
		Mercado(void)
		{
			InitializeComponent();
			initCustom();
			DineroDisponible->Text = disponible.ToString();

		}

	protected:

		~Mercado()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::NumericUpDown^ Up_Binario;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Button^ B_Comprar;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::PictureBox^ pictureBox2;
		private: System::Windows::Forms::PictureBox^ pictureBox3;
		private: System::Windows::Forms::PictureBox^ pictureBox4;
		private: System::Windows::Forms::PictureBox^ pictureBox5;
		private: System::Windows::Forms::NumericUpDown^ Up_AVL;
		private: System::Windows::Forms::NumericUpDown^ Up_SPLAY;
		private: System::Windows::Forms::NumericUpDown^ Up_HEAP;
		private: System::Windows::Forms::NumericUpDown^ Up_Espanta;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::Label^ label9;
		private: System::Windows::Forms::Label^ label10;
		private: System::Windows::Forms::Label^ label11;
		private: System::Windows::Forms::Label^ label12;
		private: System::Windows::Forms::Label^ DineroDisponible;


		private:


			System::ComponentModel::Container^ components;



			void ActualizarLabelDisponible() {
				DineroDisponible->Text = disponible.ToString();
			}

			void initCustom() {
				this->pictureBox1->Image = Image::FromFile("recursos//espantapajaros1.png");
				this->pictureBox2->Image = Image::FromFile("recursos//arbol1.png");
				this->pictureBox3->Image = Image::FromFile("recursos//arbol2.png");
				this->pictureBox4->Image = Image::FromFile("recursos//arbol31.png");
				this->pictureBox5->Image = Image::FromFile("recursos//arbol41.png");
			}

	#pragma region Windows Form Designer generated code

			void InitializeComponent(void)
			{	
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->Up_Binario = (gcnew System::Windows::Forms::NumericUpDown());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->label10 = (gcnew System::Windows::Forms::Label());
				this->label11 = (gcnew System::Windows::Forms::Label());
				this->label12 = (gcnew System::Windows::Forms::Label());
				this->DineroDisponible = (gcnew System::Windows::Forms::Label());
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
				this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
				this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
				this->Up_AVL = (gcnew System::Windows::Forms::NumericUpDown());
				this->Up_SPLAY = (gcnew System::Windows::Forms::NumericUpDown());
				this->Up_HEAP = (gcnew System::Windows::Forms::NumericUpDown());
				this->Up_Espanta = (gcnew System::Windows::Forms::NumericUpDown());
				this->B_Comprar = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_Binario))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_AVL))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_SPLAY))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_HEAP))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_Espanta))->BeginInit();
				this->SuspendLayout();
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->BackColor = System::Drawing::Color::Firebrick;
				this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(462, 47);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(417, 105);
				this->label1->TabIndex = 0;
				this->label1->Text = L"MercaTEC";
				this->label1->Click += gcnew System::EventHandler(this, &Mercado::label1_Click);
				// 
				// Up_Binario
				// 
				this->Up_Binario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Up_Binario->Location = System::Drawing::Point(86, 618);
				this->Up_Binario->Name = L"Up_Binario";
				this->Up_Binario->Size = System::Drawing::Size(50, 34);
				this->Up_Binario->TabIndex = 1;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->Location = System::Drawing::Point(59, 256);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(163, 29);
				this->label2->TabIndex = 2;
				this->label2->Text = L"Árbol binario";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label3->Location = System::Drawing::Point(360, 256);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(128, 29);
				this->label3->TabIndex = 3;
				this->label3->Text = L"Árbol AVL";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label4->Location = System::Drawing::Point(612, 256);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(163, 29);
				this->label4->TabIndex = 4;
				this->label4->Text = L"Árbol SPLAY";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label5->Location = System::Drawing::Point(872, 256);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(150, 29);
				this->label5->TabIndex = 5;
				this->label5->Text = L"Árbol HEAP";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label6->Location = System::Drawing::Point(1086, 256);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(194, 29);
				this->label6->TabIndex = 6;
				this->label6->Text = L"Espantapájaros";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label7->Location = System::Drawing::Point(37, 579);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(80, 25);
				this->label7->TabIndex = 20;
				this->label7->Text = L"Precio:";
				// 
				// label8
				// 
				this->label8->AutoSize = true;
				this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label8->Location = System::Drawing::Point(294, 579);
				this->label8->Name = L"label8";
				this->label8->Size = System::Drawing::Size(80, 25);
				this->label8->TabIndex = 21;
				this->label8->Text = L"Precio:";
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label9->Location = System::Drawing::Point(582, 579);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(80, 25);
				this->label9->TabIndex = 22;
				this->label9->Text = L"Precio:";
				// 
				// label10
				// 
				this->label10->AutoSize = true;
				this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label10->Location = System::Drawing::Point(820, 579);
				this->label10->Name = L"label10";
				this->label10->Size = System::Drawing::Size(80, 25);
				this->label10->TabIndex = 23;
				this->label10->Text = L"Precio:";
				// 
				// label11
				// 
				this->label11->AutoSize = true;
				this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label11->Location = System::Drawing::Point(1086, 579);
				this->label11->Name = L"label11";
				this->label11->Size = System::Drawing::Size(80, 25);
				this->label11->TabIndex = 24;
				this->label11->Text = L"Precio:";
				// 
				// label12
				// 
				this->label12->AutoSize = true;
				this->label12->Font = (gcnew System::Drawing::Font(L"MV Boli", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label12->Location = System::Drawing::Point(985, 33);
				this->label12->Name = L"label12";
				this->label12->Size = System::Drawing::Size(220, 29);
				this->label12->TabIndex = 25;
				this->label12->Text = L"Dinero disponible:";
				this->label12->Click += gcnew System::EventHandler(this, &Mercado::label12_Click);
				// 
				// DineroDisponible
				// 
				this->DineroDisponible->AutoSize = true;
				this->DineroDisponible->BackColor = System::Drawing::Color::White;
				this->DineroDisponible->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->DineroDisponible->Location = System::Drawing::Point(1219, 37);
				this->DineroDisponible->Name = L"DineroDisponible";
				this->DineroDisponible->Size = System::Drawing::Size(67, 25);
				this->DineroDisponible->TabIndex = 26;
				this->DineroDisponible->Text = L"Monto";
				// 
				// pictureBox1
				// 
				this->pictureBox1->Location = System::Drawing::Point(1073, 300);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(230, 265);
				this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox1->TabIndex = 8;
				this->pictureBox1->TabStop = false;
				// 
				// pictureBox2
				// 
				this->pictureBox2->Location = System::Drawing::Point(12, 300);
				this->pictureBox2->Name = L"pictureBox2";
				this->pictureBox2->Size = System::Drawing::Size(230, 265);
				this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox2->TabIndex = 9;
				this->pictureBox2->TabStop = false;
				// 
				// pictureBox3
				// 
				this->pictureBox3->Location = System::Drawing::Point(825, 300);
				this->pictureBox3->Name = L"pictureBox3";
				this->pictureBox3->Size = System::Drawing::Size(230, 265);
				this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox3->TabIndex = 13;
				this->pictureBox3->TabStop = false;
				this->pictureBox3->Click += gcnew System::EventHandler(this, &Mercado::pictureBox3_Click);
				// 
				// pictureBox4
				// 
				this->pictureBox4->Location = System::Drawing::Point(574, 300);
				this->pictureBox4->Name = L"pictureBox4";
				this->pictureBox4->Size = System::Drawing::Size(230, 265);
				this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox4->TabIndex = 14;
				this->pictureBox4->TabStop = false;
				// 
				// pictureBox5
				// 
				this->pictureBox5->Location = System::Drawing::Point(277, 300);
				this->pictureBox5->Name = L"pictureBox5";
				this->pictureBox5->Size = System::Drawing::Size(251, 265);
				this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox5->TabIndex = 15;
				this->pictureBox5->TabStop = false;
				// 
				// Up_AVL
				// 
				this->Up_AVL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Up_AVL->Location = System::Drawing::Point(375, 618);
				this->Up_AVL->Name = L"Up_AVL";
				this->Up_AVL->Size = System::Drawing::Size(50, 34);
				this->Up_AVL->TabIndex = 16;
				// 
				// Up_SPLAY
				// 
				this->Up_SPLAY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Up_SPLAY->Location = System::Drawing::Point(668, 606);
				this->Up_SPLAY->Name = L"Up_SPLAY";
				this->Up_SPLAY->Size = System::Drawing::Size(50, 34);
				this->Up_SPLAY->TabIndex = 17;
				// 
				// Up_HEAP
				// 
				this->Up_HEAP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Up_HEAP->Location = System::Drawing::Point(920, 618);
				this->Up_HEAP->Name = L"Up_HEAP";
				this->Up_HEAP->Size = System::Drawing::Size(50, 34);
				this->Up_HEAP->TabIndex = 18;
				// 
				// Up_Espanta
				// 
				this->Up_Espanta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Up_Espanta->Location = System::Drawing::Point(1171, 618);
				this->Up_Espanta->Name = L"Up_Espanta";
				this->Up_Espanta->Size = System::Drawing::Size(50, 34);
				this->Up_Espanta->TabIndex = 19;
				// 
				// B_Comprar
				// 
				this->B_Comprar->BackColor = System::Drawing::Color::Firebrick;
				this->B_Comprar->Font = (gcnew System::Drawing::Font(L"MV Boli", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->B_Comprar->Location = System::Drawing::Point(574, 677);
				this->B_Comprar->Name = L"B_Comprar";
				this->B_Comprar->Size = System::Drawing::Size(214, 76);
				this->B_Comprar->TabIndex = 7;
				this->B_Comprar->Text = L"Comprar";
				this->B_Comprar->UseVisualStyleBackColor = false;
				this->B_Comprar->Click += gcnew System::EventHandler(this, &Mercado::B_Comprar_Click);
				// 
				// Mercado
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::LightSalmon;
				this->ClientSize = System::Drawing::Size(1324, 765);
				this->Controls->Add(this->DineroDisponible);
				this->Controls->Add(this->label12);
				this->Controls->Add(this->label11);
				this->Controls->Add(this->label10);
				this->Controls->Add(this->label9);
				this->Controls->Add(this->label8);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->Up_Espanta);
				this->Controls->Add(this->Up_HEAP);
				this->Controls->Add(this->Up_SPLAY);
				this->Controls->Add(this->Up_AVL);
				this->Controls->Add(this->pictureBox5);
				this->Controls->Add(this->pictureBox4);
				this->Controls->Add(this->pictureBox3);
				this->Controls->Add(this->pictureBox2);
				this->Controls->Add(this->pictureBox1);
				this->Controls->Add(this->B_Comprar);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->Up_Binario);
				this->Controls->Add(this->label1);
				this->Name = L"Mercado";
				this->Text = L"Mercado";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_Binario))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_AVL))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_SPLAY))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_HEAP))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Up_Espanta))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}

	#pragma endregion
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}

	//------------------------------------------------------------Lógica de la compra de arboles---------------------------------------------------------------



		private: System::Void B_Comprar_Click(System::Object^ sender, System::EventArgs^ e) {
			
			int precioBinario = 500;
			int precioAVL = 500;
			int precioSPLAY = 500;
			int precioHEAP = 500;
			int precioEspanta = 500;

			int cantBinario = Convert::ToInt32(Up_Binario->Value);
			int cantAVL = Convert::ToInt32(Up_AVL->Value);
			int cantSPLAY = Convert::ToInt32(Up_SPLAY->Value);
			int cantHEAP = Convert::ToInt32(Up_HEAP->Value);
			int cantEspanta = Convert::ToInt32(Up_Espanta->Value);

			int precioTotal = (precioBinario * cantBinario) + (precioAVL * cantAVL) + (precioSPLAY * cantSPLAY) + (precioHEAP * cantHEAP)+ (precioEspanta * cantEspanta);

			if (precioTotal <= disponible) {
				disponible -= precioTotal;
				DineroDisponible->Text = disponible.ToString();
				ActualizarLabelDisponible();

				// Debe de ir lo de agregar al inventario de árboles sin sembrar aquí
			}
			else {
				MessageBox::Show("No tienes suficiente dinero disponible", "Error de compra", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			//Aquí va que actualice el "inventario de arboles"
			
			//this->Close();
		}

		public: System::Windows::Forms::Button^ ObtenerButton1() {
			return B_Comprar;
		}
		private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};

	}


