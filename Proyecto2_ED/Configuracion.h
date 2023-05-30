#pragma once

namespace Proyecto2_ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Configuracion : public System::Windows::Forms::Form
	{
	public:
		Configuracion(void)
		{
			InitializeComponent();
		}

	protected:

		~Configuracion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^ T_BinCosto;
	private: System::Windows::Forms::TrackBar^ T_BinCosecha;
	private: System::Windows::Forms::TrackBar^ T_BinCrece;
	private: System::Windows::Forms::TrackBar^ T_BinFrutos;
	private: System::Windows::Forms::TrackBar^ T_SplayCosto;
	private: System::Windows::Forms::TrackBar^ T_SplayCrece;
	private: System::Windows::Forms::TrackBar^ T_SplayCosecha;
	private: System::Windows::Forms::TrackBar^ T_SplayFrutos;
	private: System::Windows::Forms::TrackBar^ T_HeapCosto;
	private: System::Windows::Forms::TrackBar^ T_HeapCrece;
	private: System::Windows::Forms::TrackBar^ T_HeapCosecha;
	private: System::Windows::Forms::TrackBar^ T_HeapFrutos;
	private: System::Windows::Forms::TrackBar^ T_AvlCosto;
	private: System::Windows::Forms::TrackBar^ T_AvlCrece;
	private: System::Windows::Forms::TrackBar^ T_AvlCosecha;
	private: System::Windows::Forms::TrackBar^ T_AvlFrutos;
	private: System::Windows::Forms::TrackBar^ T_OvejasAparicion;
	private: System::Windows::Forms::TrackBar^ T_OvejasFrutos;
	private: System::Windows::Forms::TrackBar^ T_CuervosAparicion;
	private: System::Windows::Forms::TrackBar^ T_CuervosFrutos;
	private: System::Windows::Forms::TrackBar^ T_PlagasAparicion;
	private: System::Windows::Forms::TrackBar^ T_PlagasArboles;
	private: System::Windows::Forms::TrackBar^ T_EspantaCosto;
	private: System::Windows::Forms::TrackBar^ T_EspantaMax;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ Espantapájaros;
	private: System::Windows::Forms::TextBox^ BinCosto;
	private: System::Windows::Forms::TextBox^ BinCrece;
	private: System::Windows::Forms::TextBox^ BinCosecha;
	private: System::Windows::Forms::TextBox^ BinFfrutos;
	private: System::Windows::Forms::TextBox^ SplayCosto;
	private: System::Windows::Forms::TextBox^ SplayCrece;
	private: System::Windows::Forms::TextBox^ SplayCosecha;
	private: System::Windows::Forms::TextBox^ SplayFrutos;
	private: System::Windows::Forms::TextBox^ HeapCosto;
	private: System::Windows::Forms::TextBox^ HeapCrece;
	private: System::Windows::Forms::TextBox^ HeapCosecha;
	private: System::Windows::Forms::TextBox^ HeapFrutos;
	private: System::Windows::Forms::TextBox^ AvlCosto;
	private: System::Windows::Forms::TextBox^ AvlCrece;
	private: System::Windows::Forms::TextBox^ AvlCosecha;
	private: System::Windows::Forms::TextBox^ AvlFrutos;
	private: System::Windows::Forms::TextBox^ OvejaAparicion;
	private: System::Windows::Forms::TextBox^ OvejaFrutos;
	private: System::Windows::Forms::TextBox^ CuervoAparicion;
	private: System::Windows::Forms::TextBox^ CuervoFrutos;
	private: System::Windows::Forms::TextBox^ PlagaAparicion;
	private: System::Windows::Forms::TextBox^ PlagaArbol;
	private: System::Windows::Forms::TextBox^ EspantaCosto;
	private: System::Windows::Forms::TextBox^ EspantaMax;
	private: System::Windows::Forms::Button^ B_GuardarConfiguracion;
	private:System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->T_BinCosto = (gcnew System::Windows::Forms::TrackBar());
			this->T_BinCosecha = (gcnew System::Windows::Forms::TrackBar());
			this->T_BinCrece = (gcnew System::Windows::Forms::TrackBar());
			this->T_BinFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_SplayCosto = (gcnew System::Windows::Forms::TrackBar());
			this->T_SplayCrece = (gcnew System::Windows::Forms::TrackBar());
			this->T_SplayCosecha = (gcnew System::Windows::Forms::TrackBar());
			this->T_SplayFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_HeapCosto = (gcnew System::Windows::Forms::TrackBar());
			this->T_HeapCrece = (gcnew System::Windows::Forms::TrackBar());
			this->T_HeapCosecha = (gcnew System::Windows::Forms::TrackBar());
			this->T_HeapFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_AvlCosto = (gcnew System::Windows::Forms::TrackBar());
			this->T_AvlCrece = (gcnew System::Windows::Forms::TrackBar());
			this->T_AvlCosecha = (gcnew System::Windows::Forms::TrackBar());
			this->T_AvlFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_OvejasAparicion = (gcnew System::Windows::Forms::TrackBar());
			this->T_OvejasFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_CuervosAparicion = (gcnew System::Windows::Forms::TrackBar());
			this->T_CuervosFrutos = (gcnew System::Windows::Forms::TrackBar());
			this->T_PlagasAparicion = (gcnew System::Windows::Forms::TrackBar());
			this->T_PlagasArboles = (gcnew System::Windows::Forms::TrackBar());
			this->T_EspantaCosto = (gcnew System::Windows::Forms::TrackBar());
			this->T_EspantaMax = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->BinCosto = (gcnew System::Windows::Forms::TextBox());
			this->BinCrece = (gcnew System::Windows::Forms::TextBox());
			this->BinCosecha = (gcnew System::Windows::Forms::TextBox());
			this->BinFfrutos = (gcnew System::Windows::Forms::TextBox());
			this->SplayCosto = (gcnew System::Windows::Forms::TextBox());
			this->SplayCrece = (gcnew System::Windows::Forms::TextBox());
			this->SplayCosecha = (gcnew System::Windows::Forms::TextBox());
			this->SplayFrutos = (gcnew System::Windows::Forms::TextBox());
			this->HeapCosto = (gcnew System::Windows::Forms::TextBox());
			this->HeapCrece = (gcnew System::Windows::Forms::TextBox());
			this->HeapCosecha = (gcnew System::Windows::Forms::TextBox());
			this->HeapFrutos = (gcnew System::Windows::Forms::TextBox());
			this->AvlCosto = (gcnew System::Windows::Forms::TextBox());
			this->AvlCrece = (gcnew System::Windows::Forms::TextBox());
			this->AvlCosecha = (gcnew System::Windows::Forms::TextBox());
			this->AvlFrutos = (gcnew System::Windows::Forms::TextBox());
			this->OvejaAparicion = (gcnew System::Windows::Forms::TextBox());
			this->OvejaFrutos = (gcnew System::Windows::Forms::TextBox());
			this->CuervoAparicion = (gcnew System::Windows::Forms::TextBox());
			this->CuervoFrutos = (gcnew System::Windows::Forms::TextBox());
			this->PlagaAparicion = (gcnew System::Windows::Forms::TextBox());
			this->PlagaArbol = (gcnew System::Windows::Forms::TextBox());
			this->EspantaCosto = (gcnew System::Windows::Forms::TextBox());
			this->EspantaMax = (gcnew System::Windows::Forms::TextBox());
			this->Espantapájaros = (gcnew System::Windows::Forms::Label());
			this->B_GuardarConfiguracion = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCosto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCosecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCrece))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCosto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCrece))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCosecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCosto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCrece))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCosecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCosto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCrece))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCosecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_OvejasAparicion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_OvejasFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_CuervosAparicion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_CuervosFrutos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_PlagasAparicion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_PlagasArboles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_EspantaCosto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_EspantaMax))->BeginInit();
			this->SuspendLayout();
			// 
			// T_BinCosto
			// 
			this->T_BinCosto->LargeChange = 10;
			this->T_BinCosto->Location = System::Drawing::Point(220, 160);
			this->T_BinCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_BinCosto->Maximum = 100;
			this->T_BinCosto->Name = L"T_BinCosto";
			this->T_BinCosto->Size = System::Drawing::Size(104, 56);
			this->T_BinCosto->TabIndex = 1;
			this->T_BinCosto->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar1_Scroll);
			// 
			// T_BinCosecha
			// 
			this->T_BinCosecha->LargeChange = 10;
			this->T_BinCosecha->Location = System::Drawing::Point(223, 234);
			this->T_BinCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_BinCosecha->Maximum = 60;
			this->T_BinCosecha->Name = L"T_BinCosecha";
			this->T_BinCosecha->Size = System::Drawing::Size(104, 56);
			this->T_BinCosecha->TabIndex = 3;
			this->T_BinCosecha->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar3_Scroll);
			// 
			// T_BinCrece
			// 
			this->T_BinCrece->LargeChange = 10;
			this->T_BinCrece->Location = System::Drawing::Point(220, 197);
			this->T_BinCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_BinCrece->Maximum = 60;
			this->T_BinCrece->Name = L"T_BinCrece";
			this->T_BinCrece->Size = System::Drawing::Size(104, 56);
			this->T_BinCrece->TabIndex = 16;
			this->T_BinCrece->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar2_Scroll);
			// 
			// T_BinFrutos
			// 
			this->T_BinFrutos->LargeChange = 10;
			this->T_BinFrutos->Location = System::Drawing::Point(220, 263);
			this->T_BinFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_BinFrutos->Maximum = 70;
			this->T_BinFrutos->Name = L"T_BinFrutos";
			this->T_BinFrutos->Size = System::Drawing::Size(104, 56);
			this->T_BinFrutos->TabIndex = 17;
			this->T_BinFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar4_Scroll);
			// 
			// T_SplayCosto
			// 
			this->T_SplayCosto->Location = System::Drawing::Point(220, 347);
			this->T_SplayCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_SplayCosto->Name = L"T_SplayCosto";
			this->T_SplayCosto->Size = System::Drawing::Size(104, 56);
			this->T_SplayCosto->TabIndex = 18;
			this->T_SplayCosto->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar5_Scroll);
			// 
			// T_SplayCrece
			// 
			this->T_SplayCrece->LargeChange = 10;
			this->T_SplayCrece->Location = System::Drawing::Point(220, 379);
			this->T_SplayCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_SplayCrece->Maximum = 60;
			this->T_SplayCrece->Name = L"T_SplayCrece";
			this->T_SplayCrece->Size = System::Drawing::Size(104, 56);
			this->T_SplayCrece->TabIndex = 19;
			this->T_SplayCrece->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar6_Scroll);
			// 
			// T_SplayCosecha
			// 
			this->T_SplayCosecha->LargeChange = 10;
			this->T_SplayCosecha->Location = System::Drawing::Point(220, 423);
			this->T_SplayCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_SplayCosecha->Maximum = 60;
			this->T_SplayCosecha->Name = L"T_SplayCosecha";
			this->T_SplayCosecha->Size = System::Drawing::Size(104, 56);
			this->T_SplayCosecha->TabIndex = 20;
			this->T_SplayCosecha->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar7_Scroll);
			// 
			// T_SplayFrutos
			// 
			this->T_SplayFrutos->LargeChange = 10;
			this->T_SplayFrutos->Location = System::Drawing::Point(220, 468);
			this->T_SplayFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_SplayFrutos->Maximum = 70;
			this->T_SplayFrutos->Name = L"T_SplayFrutos";
			this->T_SplayFrutos->Size = System::Drawing::Size(104, 56);
			this->T_SplayFrutos->TabIndex = 21;
			this->T_SplayFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar8_Scroll);
			// 
			// T_HeapCosto
			// 
			this->T_HeapCosto->LargeChange = 10;
			this->T_HeapCosto->Location = System::Drawing::Point(664, 154);
			this->T_HeapCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_HeapCosto->Maximum = 100;
			this->T_HeapCosto->Name = L"T_HeapCosto";
			this->T_HeapCosto->Size = System::Drawing::Size(104, 56);
			this->T_HeapCosto->TabIndex = 22;
			this->T_HeapCosto->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar9_Scroll);
			// 
			// T_HeapCrece
			// 
			this->T_HeapCrece->LargeChange = 10;
			this->T_HeapCrece->Location = System::Drawing::Point(664, 194);
			this->T_HeapCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_HeapCrece->Maximum = 60;
			this->T_HeapCrece->Name = L"T_HeapCrece";
			this->T_HeapCrece->Size = System::Drawing::Size(104, 56);
			this->T_HeapCrece->TabIndex = 23;
			this->T_HeapCrece->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar10_Scroll);
			// 
			// T_HeapCosecha
			// 
			this->T_HeapCosecha->LargeChange = 10;
			this->T_HeapCosecha->Location = System::Drawing::Point(664, 234);
			this->T_HeapCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_HeapCosecha->Maximum = 60;
			this->T_HeapCosecha->Name = L"T_HeapCosecha";
			this->T_HeapCosecha->Size = System::Drawing::Size(104, 56);
			this->T_HeapCosecha->TabIndex = 24;
			this->T_HeapCosecha->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar11_Scroll);
			// 
			// T_HeapFrutos
			// 
			this->T_HeapFrutos->LargeChange = 10;
			this->T_HeapFrutos->Location = System::Drawing::Point(664, 263);
			this->T_HeapFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_HeapFrutos->Maximum = 70;
			this->T_HeapFrutos->Name = L"T_HeapFrutos";
			this->T_HeapFrutos->Size = System::Drawing::Size(104, 56);
			this->T_HeapFrutos->TabIndex = 25;
			this->T_HeapFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar12_Scroll);
			// 
			// T_AvlCosto
			// 
			this->T_AvlCosto->Location = System::Drawing::Point(664, 347);
			this->T_AvlCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_AvlCosto->Name = L"T_AvlCosto";
			this->T_AvlCosto->Size = System::Drawing::Size(104, 56);
			this->T_AvlCosto->TabIndex = 26;
			this->T_AvlCosto->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar13_Scroll);
			// 
			// T_AvlCrece
			// 
			this->T_AvlCrece->LargeChange = 10;
			this->T_AvlCrece->Location = System::Drawing::Point(664, 379);
			this->T_AvlCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_AvlCrece->Maximum = 60;
			this->T_AvlCrece->Name = L"T_AvlCrece";
			this->T_AvlCrece->Size = System::Drawing::Size(104, 56);
			this->T_AvlCrece->TabIndex = 27;
			this->T_AvlCrece->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar14_Scroll);
			// 
			// T_AvlCosecha
			// 
			this->T_AvlCosecha->LargeChange = 10;
			this->T_AvlCosecha->Location = System::Drawing::Point(664, 423);
			this->T_AvlCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_AvlCosecha->Maximum = 60;
			this->T_AvlCosecha->Name = L"T_AvlCosecha";
			this->T_AvlCosecha->Size = System::Drawing::Size(104, 56);
			this->T_AvlCosecha->TabIndex = 28;
			this->T_AvlCosecha->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar15_Scroll);
			// 
			// T_AvlFrutos
			// 
			this->T_AvlFrutos->LargeChange = 10;
			this->T_AvlFrutos->Location = System::Drawing::Point(664, 468);
			this->T_AvlFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_AvlFrutos->Maximum = 70;
			this->T_AvlFrutos->Name = L"T_AvlFrutos";
			this->T_AvlFrutos->Size = System::Drawing::Size(104, 56);
			this->T_AvlFrutos->TabIndex = 45;
			this->T_AvlFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar16_Scroll);
			// 
			// T_OvejasAparicion
			// 
			this->T_OvejasAparicion->LargeChange = 20;
			this->T_OvejasAparicion->Location = System::Drawing::Point(1077, 142);
			this->T_OvejasAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_OvejasAparicion->Maximum = 100;
			this->T_OvejasAparicion->Name = L"T_OvejasAparicion";
			this->T_OvejasAparicion->Size = System::Drawing::Size(104, 56);
			this->T_OvejasAparicion->TabIndex = 56;
			this->T_OvejasAparicion->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar17_Scroll);
			// 
			// T_OvejasFrutos
			// 
			this->T_OvejasFrutos->LargeChange = 10;
			this->T_OvejasFrutos->Location = System::Drawing::Point(1077, 178);
			this->T_OvejasFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_OvejasFrutos->Maximum = 60;
			this->T_OvejasFrutos->Name = L"T_OvejasFrutos";
			this->T_OvejasFrutos->Size = System::Drawing::Size(104, 56);
			this->T_OvejasFrutos->TabIndex = 57;
			this->T_OvejasFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar18_Scroll);
			// 
			// T_CuervosAparicion
			// 
			this->T_CuervosAparicion->LargeChange = 10;
			this->T_CuervosAparicion->Location = System::Drawing::Point(1077, 286);
			this->T_CuervosAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_CuervosAparicion->Maximum = 100;
			this->T_CuervosAparicion->Name = L"T_CuervosAparicion";
			this->T_CuervosAparicion->Size = System::Drawing::Size(104, 56);
			this->T_CuervosAparicion->TabIndex = 58;
			this->T_CuervosAparicion->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar19_Scroll);
			// 
			// T_CuervosFrutos
			// 
			this->T_CuervosFrutos->LargeChange = 10;
			this->T_CuervosFrutos->Location = System::Drawing::Point(1077, 322);
			this->T_CuervosFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_CuervosFrutos->Maximum = 60;
			this->T_CuervosFrutos->Name = L"T_CuervosFrutos";
			this->T_CuervosFrutos->Size = System::Drawing::Size(104, 56);
			this->T_CuervosFrutos->TabIndex = 59;
			this->T_CuervosFrutos->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar20_Scroll);
			// 
			// T_PlagasAparicion
			// 
			this->T_PlagasAparicion->LargeChange = 10;
			this->T_PlagasAparicion->Location = System::Drawing::Point(1077, 423);
			this->T_PlagasAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_PlagasAparicion->Maximum = 100;
			this->T_PlagasAparicion->Name = L"T_PlagasAparicion";
			this->T_PlagasAparicion->Size = System::Drawing::Size(104, 56);
			this->T_PlagasAparicion->TabIndex = 60;
			this->T_PlagasAparicion->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar21_Scroll);
			// 
			// T_PlagasArboles
			// 
			this->T_PlagasArboles->LargeChange = 10;
			this->T_PlagasArboles->Location = System::Drawing::Point(1077, 468);
			this->T_PlagasArboles->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_PlagasArboles->Maximum = 60;
			this->T_PlagasArboles->Name = L"T_PlagasArboles";
			this->T_PlagasArboles->Size = System::Drawing::Size(104, 56);
			this->T_PlagasArboles->TabIndex = 61;
			this->T_PlagasArboles->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar22_Scroll);
			// 
			// T_EspantaCosto
			// 
			this->T_EspantaCosto->LargeChange = 10;
			this->T_EspantaCosto->Location = System::Drawing::Point(220, 560);
			this->T_EspantaCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_EspantaCosto->Maximum = 200;
			this->T_EspantaCosto->Name = L"T_EspantaCosto";
			this->T_EspantaCosto->Size = System::Drawing::Size(104, 56);
			this->T_EspantaCosto->TabIndex = 64;
			this->T_EspantaCosto->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar23_Scroll);
			// 
			// T_EspantaMax
			// 
			this->T_EspantaMax->LargeChange = 1;
			this->T_EspantaMax->Location = System::Drawing::Point(220, 604);
			this->T_EspantaMax->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->T_EspantaMax->Maximum = 5;
			this->T_EspantaMax->Name = L"T_EspantaMax";
			this->T_EspantaMax->Size = System::Drawing::Size(104, 56);
			this->T_EspantaMax->TabIndex = 65;
			this->T_EspantaMax->Scroll += gcnew System::EventHandler(this, &Configuracion::trackBar24_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(109, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(425, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Configuración de los árboles y espantapájaros";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkOrange;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(512, 322);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 18);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Árbol AVL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkOrange;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(512, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 18);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Árbol HEAP";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DarkOrange;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(43, 322);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 18);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Árbol SPLAY";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(21, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 16);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Costo:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(21, 197);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(169, 16);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Crece cada(segundos):";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(703, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(394, 22);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Configuración de las diversas afectaciones";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::DarkOrange;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(67, 133);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(103, 18);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Árbol binario";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(21, 238);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(193, 16);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Cosecha cada (segundos):";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(21, 274);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 16);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Precio frutos:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(21, 363);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 16);
			this->label11->TabIndex = 33;
			this->label11->Text = L"Costo:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(21, 398);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(169, 16);
			this->label12->TabIndex = 34;
			this->label12->Text = L"Crece cada(segundos):";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(21, 438);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(193, 16);
			this->label13->TabIndex = 35;
			this->label13->Text = L"Cosecha cada (segundos):";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(21, 480);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(98, 16);
			this->label14->TabIndex = 36;
			this->label14->Text = L"Precio frutos:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(439, 363);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(51, 16);
			this->label15->TabIndex = 37;
			this->label15->Text = L"Costo:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(439, 398);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(169, 16);
			this->label16->TabIndex = 38;
			this->label16->Text = L"Crece cada(segundos):";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(439, 197);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(169, 16);
			this->label17->TabIndex = 39;
			this->label17->Text = L"Crece cada(segundos):";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(439, 160);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(51, 16);
			this->label18->TabIndex = 40;
			this->label18->Text = L"Costo:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(439, 438);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(193, 16);
			this->label19->TabIndex = 41;
			this->label19->Text = L"Cosecha cada (segundos):";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(439, 238);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(193, 16);
			this->label20->TabIndex = 42;
			this->label20->Text = L"Cosecha cada (segundos):";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(439, 274);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(98, 16);
			this->label21->TabIndex = 43;
			this->label21->Text = L"Precio frutos:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(439, 480);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(98, 16);
			this->label22->TabIndex = 44;
			this->label22->Text = L"Precio frutos:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(937, 130);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(67, 20);
			this->label23->TabIndex = 47;
			this->label23->Text = L"Ovejas";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(949, 383);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(66, 20);
			this->label24->TabIndex = 48;
			this->label24->Text = L"Plagas";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(937, 249);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(78, 20);
			this->label25->TabIndex = 49;
			this->label25->Text = L"Cuervos";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(837, 160);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(192, 16);
			this->label26->TabIndex = 50;
			this->label26->Text = L"Probabilidad de aparición:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(837, 423);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(192, 16);
			this->label27->TabIndex = 51;
			this->label27->Text = L"Probabilidad de aparición:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(837, 304);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(192, 16);
			this->label28->TabIndex = 52;
			this->label28->Text = L"Probabilidad de aparición:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(837, 197);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(210, 16);
			this->label29->TabIndex = 53;
			this->label29->Text = L"Come frutos cada(segundos):";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(837, 338);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(210, 16);
			this->label30->TabIndex = 54;
			this->label30->Text = L"Come frutos cada(segundos):";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(837, 468);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(247, 16);
			this->label31->TabIndex = 55;
			this->label31->Text = L"Destruye el árbol cada(segundos):";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(21, 586);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(51, 16);
			this->label32->TabIndex = 62;
			this->label32->Text = L"Costo:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(21, 622);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(146, 16);
			this->label33->TabIndex = 63;
			this->label33->Text = L"Máximos en terreno:";
			// 
			// BinCosto
			// 
			this->BinCosto->Location = System::Drawing::Point(331, 154);
			this->BinCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BinCosto->Name = L"BinCosto";
			this->BinCosto->ReadOnly = true;
			this->BinCosto->Size = System::Drawing::Size(47, 22);
			this->BinCosto->TabIndex = 4;
			this->BinCosto->TextChanged += gcnew System::EventHandler(this, &Configuracion::textBox1_TextChanged);
			// 
			// BinCrece
			// 
			this->BinCrece->Location = System::Drawing::Point(331, 194);
			this->BinCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BinCrece->Name = L"BinCrece";
			this->BinCrece->Size = System::Drawing::Size(47, 22);
			this->BinCrece->TabIndex = 66;
			// 
			// BinCosecha
			// 
			this->BinCosecha->Location = System::Drawing::Point(331, 234);
			this->BinCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BinCosecha->Name = L"BinCosecha";
			this->BinCosecha->Size = System::Drawing::Size(47, 22);
			this->BinCosecha->TabIndex = 67;
			// 
			// BinFfrutos
			// 
			this->BinFfrutos->Location = System::Drawing::Point(331, 268);
			this->BinFfrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BinFfrutos->Name = L"BinFfrutos";
			this->BinFfrutos->Size = System::Drawing::Size(47, 22);
			this->BinFfrutos->TabIndex = 68;
			// 
			// SplayCosto
			// 
			this->SplayCosto->Location = System::Drawing::Point(331, 347);
			this->SplayCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SplayCosto->Name = L"SplayCosto";
			this->SplayCosto->Size = System::Drawing::Size(47, 22);
			this->SplayCosto->TabIndex = 69;
			// 
			// SplayCrece
			// 
			this->SplayCrece->Location = System::Drawing::Point(331, 383);
			this->SplayCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SplayCrece->Name = L"SplayCrece";
			this->SplayCrece->Size = System::Drawing::Size(47, 22);
			this->SplayCrece->TabIndex = 70;
			// 
			// SplayCosecha
			// 
			this->SplayCosecha->Location = System::Drawing::Point(331, 421);
			this->SplayCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SplayCosecha->Name = L"SplayCosecha";
			this->SplayCosecha->Size = System::Drawing::Size(47, 22);
			this->SplayCosecha->TabIndex = 71;
			// 
			// SplayFrutos
			// 
			this->SplayFrutos->Location = System::Drawing::Point(331, 462);
			this->SplayFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SplayFrutos->Name = L"SplayFrutos";
			this->SplayFrutos->Size = System::Drawing::Size(47, 22);
			this->SplayFrutos->TabIndex = 72;
			// 
			// HeapCosto
			// 
			this->HeapCosto->Location = System::Drawing::Point(773, 142);
			this->HeapCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HeapCosto->Name = L"HeapCosto";
			this->HeapCosto->Size = System::Drawing::Size(49, 22);
			this->HeapCosto->TabIndex = 73;
			this->HeapCosto->TextChanged += gcnew System::EventHandler(this, &Configuracion::HeapCosto_TextChanged);
			// 
			// HeapCrece
			// 
			this->HeapCrece->Location = System::Drawing::Point(773, 183);
			this->HeapCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HeapCrece->Name = L"HeapCrece";
			this->HeapCrece->Size = System::Drawing::Size(49, 22);
			this->HeapCrece->TabIndex = 74;
			// 
			// HeapCosecha
			// 
			this->HeapCosecha->Location = System::Drawing::Point(773, 217);
			this->HeapCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HeapCosecha->Name = L"HeapCosecha";
			this->HeapCosecha->Size = System::Drawing::Size(49, 22);
			this->HeapCosecha->TabIndex = 75;
			// 
			// HeapFrutos
			// 
			this->HeapFrutos->Location = System::Drawing::Point(773, 251);
			this->HeapFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HeapFrutos->Name = L"HeapFrutos";
			this->HeapFrutos->Size = System::Drawing::Size(49, 22);
			this->HeapFrutos->TabIndex = 76;
			// 
			// AvlCosto
			// 
			this->AvlCosto->Location = System::Drawing::Point(773, 347);
			this->AvlCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AvlCosto->Name = L"AvlCosto";
			this->AvlCosto->Size = System::Drawing::Size(49, 22);
			this->AvlCosto->TabIndex = 77;
			// 
			// AvlCrece
			// 
			this->AvlCrece->Location = System::Drawing::Point(773, 383);
			this->AvlCrece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AvlCrece->Name = L"AvlCrece";
			this->AvlCrece->Size = System::Drawing::Size(49, 22);
			this->AvlCrece->TabIndex = 78;
			// 
			// AvlCosecha
			// 
			this->AvlCosecha->Location = System::Drawing::Point(773, 421);
			this->AvlCosecha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AvlCosecha->Name = L"AvlCosecha";
			this->AvlCosecha->Size = System::Drawing::Size(49, 22);
			this->AvlCosecha->TabIndex = 79;
			this->AvlCosecha->TextChanged += gcnew System::EventHandler(this, &Configuracion::textBox15_TextChanged);
			// 
			// AvlFrutos
			// 
			this->AvlFrutos->Location = System::Drawing::Point(773, 465);
			this->AvlFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AvlFrutos->Name = L"AvlFrutos";
			this->AvlFrutos->Size = System::Drawing::Size(49, 22);
			this->AvlFrutos->TabIndex = 80;
			// 
			// OvejaAparicion
			// 
			this->OvejaAparicion->Location = System::Drawing::Point(1187, 142);
			this->OvejaAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->OvejaAparicion->Name = L"OvejaAparicion";
			this->OvejaAparicion->Size = System::Drawing::Size(49, 22);
			this->OvejaAparicion->TabIndex = 81;
			// 
			// OvejaFrutos
			// 
			this->OvejaFrutos->Location = System::Drawing::Point(1187, 183);
			this->OvejaFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->OvejaFrutos->Name = L"OvejaFrutos";
			this->OvejaFrutos->Size = System::Drawing::Size(49, 22);
			this->OvejaFrutos->TabIndex = 81;
			// 
			// CuervoAparicion
			// 
			this->CuervoAparicion->Location = System::Drawing::Point(1187, 268);
			this->CuervoAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CuervoAparicion->Name = L"CuervoAparicion";
			this->CuervoAparicion->Size = System::Drawing::Size(49, 22);
			this->CuervoAparicion->TabIndex = 82;
			// 
			// CuervoFrutos
			// 
			this->CuervoFrutos->Location = System::Drawing::Point(1187, 322);
			this->CuervoFrutos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CuervoFrutos->Name = L"CuervoFrutos";
			this->CuervoFrutos->Size = System::Drawing::Size(49, 22);
			this->CuervoFrutos->TabIndex = 83;
			// 
			// PlagaAparicion
			// 
			this->PlagaAparicion->Location = System::Drawing::Point(1187, 423);
			this->PlagaAparicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PlagaAparicion->Name = L"PlagaAparicion";
			this->PlagaAparicion->Size = System::Drawing::Size(49, 22);
			this->PlagaAparicion->TabIndex = 84;
			// 
			// PlagaArbol
			// 
			this->PlagaArbol->Location = System::Drawing::Point(1187, 474);
			this->PlagaArbol->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PlagaArbol->Name = L"PlagaArbol";
			this->PlagaArbol->Size = System::Drawing::Size(49, 22);
			this->PlagaArbol->TabIndex = 85;
			// 
			// EspantaCosto
			// 
			this->EspantaCosto->Location = System::Drawing::Point(333, 560);
			this->EspantaCosto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->EspantaCosto->Name = L"EspantaCosto";
			this->EspantaCosto->Size = System::Drawing::Size(44, 22);
			this->EspantaCosto->TabIndex = 86;
			// 
			// EspantaMax
			// 
			this->EspantaMax->Location = System::Drawing::Point(333, 604);
			this->EspantaMax->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->EspantaMax->Name = L"EspantaMax";
			this->EspantaMax->Size = System::Drawing::Size(47, 22);
			this->EspantaMax->TabIndex = 87;
			// 
			// Espantapájaros
			// 
			this->Espantapájaros->AutoSize = true;
			this->Espantapájaros->BackColor = System::Drawing::Color::Cyan;
			this->Espantapájaros->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Espantapájaros->Location = System::Drawing::Point(21, 535);
			this->Espantapájaros->Name = L"Espantapájaros";
			this->Espantapájaros->Size = System::Drawing::Size(125, 18);
			this->Espantapájaros->TabIndex = 46;
			this->Espantapájaros->Text = L"Espantapájaros";
			// 
			// B_GuardarConfiguracion
			// 
			this->B_GuardarConfiguracion->BackColor = System::Drawing::Color::LimeGreen;
			this->B_GuardarConfiguracion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->B_GuardarConfiguracion->Location = System::Drawing::Point(685, 596);
			this->B_GuardarConfiguracion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->B_GuardarConfiguracion->Name = L"B_GuardarConfiguracion";
			this->B_GuardarConfiguracion->Size = System::Drawing::Size(399, 57);
			this->B_GuardarConfiguracion->TabIndex = 88;
			this->B_GuardarConfiguracion->Text = L"Guardar configuración";
			this->B_GuardarConfiguracion->UseVisualStyleBackColor = false;
			this->B_GuardarConfiguracion->Click += gcnew System::EventHandler(this, &Configuracion::B_GuardarConfiguracion_Click);
			// 
			// Configuracion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1301, 743);
			this->Controls->Add(this->B_GuardarConfiguracion);
			this->Controls->Add(this->EspantaMax);
			this->Controls->Add(this->EspantaCosto);
			this->Controls->Add(this->PlagaArbol);
			this->Controls->Add(this->PlagaAparicion);
			this->Controls->Add(this->CuervoFrutos);
			this->Controls->Add(this->CuervoAparicion);
			this->Controls->Add(this->OvejaFrutos);
			this->Controls->Add(this->OvejaAparicion);
			this->Controls->Add(this->AvlFrutos);
			this->Controls->Add(this->AvlCosecha);
			this->Controls->Add(this->AvlCrece);
			this->Controls->Add(this->AvlCosto);
			this->Controls->Add(this->HeapFrutos);
			this->Controls->Add(this->HeapCosecha);
			this->Controls->Add(this->HeapCrece);
			this->Controls->Add(this->HeapCosto);
			this->Controls->Add(this->SplayFrutos);
			this->Controls->Add(this->SplayCosecha);
			this->Controls->Add(this->SplayCrece);
			this->Controls->Add(this->SplayCosto);
			this->Controls->Add(this->BinFfrutos);
			this->Controls->Add(this->BinCosecha);
			this->Controls->Add(this->BinCrece);
			this->Controls->Add(this->T_EspantaMax);
			this->Controls->Add(this->T_EspantaCosto);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->T_PlagasArboles);
			this->Controls->Add(this->T_PlagasAparicion);
			this->Controls->Add(this->T_CuervosFrutos);
			this->Controls->Add(this->T_CuervosAparicion);
			this->Controls->Add(this->T_OvejasFrutos);
			this->Controls->Add(this->T_OvejasAparicion);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->Espantapájaros);
			this->Controls->Add(this->T_AvlFrutos);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->T_BinFrutos);
			this->Controls->Add(this->T_BinCosecha);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->T_AvlCosecha);
			this->Controls->Add(this->T_AvlCrece);
			this->Controls->Add(this->T_AvlCosto);
			this->Controls->Add(this->T_HeapFrutos);
			this->Controls->Add(this->T_HeapCosecha);
			this->Controls->Add(this->T_HeapCrece);
			this->Controls->Add(this->T_HeapCosto);
			this->Controls->Add(this->T_SplayFrutos);
			this->Controls->Add(this->T_SplayCosecha);
			this->Controls->Add(this->T_SplayCrece);
			this->Controls->Add(this->T_SplayCosto);
			this->Controls->Add(this->T_BinCrece);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BinCosto);
			this->Controls->Add(this->T_BinCosto);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Configuracion";
			this->Text = L"Configuracion";
			this->Load += gcnew System::EventHandler(this, &Configuracion::Configuracion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCosto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCosecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinCrece))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_BinFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCosto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCrece))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayCosecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_SplayFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCosto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCrece))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapCosecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_HeapFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCosto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCrece))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlCosecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_AvlFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_OvejasAparicion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_OvejasFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_CuervosAparicion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_CuervosFrutos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_PlagasAparicion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_PlagasArboles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_EspantaCosto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->T_EspantaMax))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {


			// Actualizar el valor del control TextBox con el valor actual del control TrackBar
			this->BinCosto->Text = this->T_BinCosto->Value.ToString();
		}

		private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
			// Actualizar el valor del control TextBox con el valor actual del control TrackBar
			this->BinCrece->Text = this->T_BinCrece->Value.ToString();
		}


	private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
		// Actualizar el valor del control TextBox con el valor actual del control TrackBar
		this->BinCosecha->Text = this->T_BinCosecha->Value.ToString();
	}


	private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
		// Actualizar el valor del control TextBox con el valor actual del control TrackBar
		this->BinFfrutos->Text = this->T_BinFrutos->Value.ToString();
	}


	private: System::Void trackBar5_Scroll(System::Object^ sender, System::EventArgs^ e) {

		this->SplayCosto->Text = this->T_SplayCosto->Value.ToString();
	}

	private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->SplayCrece->Text = this->T_SplayCrece->Value.ToString();
	}


	private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {

		this->SplayCosecha->Text = this->T_SplayCosecha->Value.ToString();
	}


	private: System::Void trackBar8_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->SplayFrutos->Text = this->T_SplayFrutos->Value.ToString();
	}


	private: System::Void trackBar9_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->EspantaCosto->Text = this->T_EspantaCosto->Value.ToString();
	}

	private: System::Void trackBar10_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->EspantaMax->Text = this->T_EspantaMax->Value.ToString();
	}
	private: System::Void trackBar11_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->HeapCosto->Text = this->T_HeapCosto->Value.ToString();
		   }

	private: System::Void trackBar12_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->HeapCrece->Text = this->T_HeapCrece->Value.ToString();
	}

	private: System::Void trackBar13_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->HeapCosecha->Text = this->T_HeapCosecha->Value.ToString();
	}

	 private: System::Void trackBar14_Scroll(System::Object^ sender, System::EventArgs^ e) {
		 this->HeapFrutos->Text = this->T_HeapFrutos->Value.ToString();

	 }
	private: System::Void trackBar15_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->AvlCosto->Text = this->T_AvlCosto->Value.ToString();
	}
	private: System::Void trackBar16_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->AvlCrece->Text = this->T_AvlCrece->Value.ToString();
	}
	private: System::Void trackBar17_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->AvlCosecha->Text = this->T_AvlCosecha->Value.ToString();
		   }
	private: System::Void trackBar18_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->AvlFrutos->Text = this->T_AvlFrutos->Value.ToString();
				  }
	private: System::Void trackBar19_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->OvejaAparicion->Text = this->T_OvejasAparicion->Value.ToString();
	}
	private: System::Void trackBar20_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->OvejaFrutos->Text = this->T_OvejasFrutos->Value.ToString();
	}
	private: System::Void trackBar21_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->CuervoAparicion->Text = this->T_CuervosAparicion->Value.ToString();
	}
	private: System::Void trackBar22_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->CuervoFrutos->Text = this->T_CuervosFrutos->Value.ToString();
		   }
	private: System::Void trackBar23_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->PlagaArbol->Text = this->T_PlagasAparicion->Value.ToString();
	}

	private: System::Void trackBar24_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->PlagaArbol->Text = this->T_PlagasArboles->Value.ToString();
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox12_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox13_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox15_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox16_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox17_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox18_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox19_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox20_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox21_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox22_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox23_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox24_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Configuracion_Load(System::Object^ sender, System::EventArgs^ e) {
}




	private: System::Void B_GuardarConfiguracion_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void HeapCosto_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
	}
