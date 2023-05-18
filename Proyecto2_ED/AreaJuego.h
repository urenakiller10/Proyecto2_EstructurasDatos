#pragma once
#include "Mercado.h"
#include <vector>
namespace Proyecto2_ED {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Resumen de AreaJuego
    /// </summary>
    public ref class AreaJuego : public System::Windows::Forms::Form
    {

    private: 
        array<array<Label^, 1>^>^ matrizLabels;
        Label^ labelRojo;
        int labelX;
    private: System::Windows::Forms::TextBox^ ArbolesSinPlantar;

    private: System::Windows::Forms::Label^ SinPlantar;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ Dinero;

           int labelY;

    public:
        AreaJuego(void)
        {
            InitializeComponent();
            SetupDataGridView();
            EstablecerTextoFilas();
            initCustom();






            //------------------------------------------------------Matriz de botones---------------------------------------------------------
// Crear la matriz de etiquetas
            matrizLabels = gcnew array<array<Label^, 1>^>(12);
            for (int i = 0; i < 12; i++)
            {
                matrizLabels[i] = gcnew array<Label^>(12);
            }

            // Crear y agregar las etiquetas a la matriz
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    Label^ label = gcnew Label();
                    label->Width = 50;
                    label->Height = 50;
                    label->BackColor = Color::LimeGreen;
                    matrizLabels[i][j] = label;
                    this->Controls->Add(label);
                }
            }

            // Posicionar las etiquetas en el formulario
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    matrizLabels[i][j]->Left = 10 + j * 60; // Posici�n horizontal
                    matrizLabels[i][j]->Top = 10 + i * 60; // Posici�n vertical
                }
            }
        
        
            
            // Crear el label rojo
            labelRojo->Width = 50;
            labelRojo->Height = 50;
            labelRojo->BackColor = Color::White;
 ;
            MoverLabelSobreLabel(0, 0); // Mover el label sobre el label en la posici�n (0,0)
            this->Controls->Add(labelRojo);


            // Inicializar las coordenadas del label rojo
            labelX = 0;
            labelY = 0;

            // Suscribir el formulario al evento KeyDown
            this->KeyDown += gcnew KeyEventHandler(this, &AreaJuego::Form_KeyDown); 

        
        }



    public:

        ~AreaJuego()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ B_GuardarJuego;
    public:

    private: System::Windows::Forms::Button^ B_Pausa;

    private: System::Windows::Forms::Button^ B_Plantar;

    private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
    private: System::Windows::Forms::DataGridView^ TablaJuego;

    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tipo_Arbol;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ubicacion;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Frutos;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Monto;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vendidos;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Perdidos;
private: System::Windows::Forms::Button^ B_Salir;

private: System::Windows::Forms::Button^ B_VenderTodo;



    protected:

    public:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void initCustom() {
            labelRojo = gcnew Label();
            this->labelRojo->Image = Image::FromFile("recursos/granjero.png");

        }

        //---------------------------------------------M�todos de la tabla de datos--------------------------------------------------------------



        void SetupDataGridView()
        {
            // Configurar la cantidad de filas del DataGridView

            TablaJuego->RowCount = 4; // Por ejemplo maaeee establece 10 filas fijas

            TablaJuego->KeyDown += gcnew KeyEventHandler(this, &AreaJuego::TablaJuego_KeyDown);


        }

     //-------------------METODO QUE SE PUEDE USAR M�S ADELANTE----------------------

         void ActualizarInformacionFilas()
         {
             // Actualizar informaci�n en las filas existentes
             for (int fila = 0; fila < TablaJuego->RowCount; fila++)
             {
                 TablaJuego->Rows[fila]->Cells[0]->Value = "Valor 1";
                 TablaJuego->Rows[fila]->Cells[1]->Value = "Valor 2";
                 TablaJuego->Rows[fila]->Cells[2]->Value = "Valor 3";
             }
         }
         
         void AreaJuego::TablaJuego_KeyDown(Object^ sender, KeyEventArgs^ e)
         {
             // Verificar si la tecla presionada es una tecla de flecha
             if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right)
             {
                 // Anular el evento de tecla para evitar que se procese
                 e->SuppressKeyPress = true;
             }
         }

         void OcultarColumnaSeleccionada()
         {
             TablaJuego->ColumnHeadersVisible = false;
         }

         void EstablecerTextoFilas()
         {
             DataGridViewCellStyle^ rowStyle = gcnew DataGridViewCellStyle();
             rowStyle->Font = gcnew System::Drawing::Font(TablaJuego->Font->FontFamily, 10, FontStyle::Bold);

             TablaJuego->Rows[0]->Cells[0]->Value = "Binario";
             TablaJuego->Rows[0]->DefaultCellStyle = rowStyle;

             TablaJuego->Rows[1]->Cells[0]->Value = "AVL";
             TablaJuego->Rows[1]->DefaultCellStyle = rowStyle;

             TablaJuego->Rows[2]->Cells[0]->Value = "Splay";
             TablaJuego->Rows[2]->DefaultCellStyle = rowStyle;

             TablaJuego->Rows[3]->Cells[0]->Value = "Heap";
             TablaJuego->Rows[3]->DefaultCellStyle = rowStyle;
         }
    //---------------------------------------------------------------------------------------------------------------------------------------------

        void InitializeComponent(void)
        {   
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->B_GuardarJuego = (gcnew System::Windows::Forms::Button());
            this->B_Pausa = (gcnew System::Windows::Forms::Button());
            this->B_Plantar = (gcnew System::Windows::Forms::Button());
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->TablaJuego = (gcnew System::Windows::Forms::DataGridView());
            this->Tipo_Arbol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Ubicacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Frutos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Monto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Vendidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Perdidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->B_Salir = (gcnew System::Windows::Forms::Button());
            this->B_VenderTodo = (gcnew System::Windows::Forms::Button());
            this->ArbolesSinPlantar = (gcnew System::Windows::Forms::TextBox());
            this->SinPlantar = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->Dinero = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaJuego))->BeginInit();
            this->SuspendLayout();
            // 
            // B_GuardarJuego
            // 
            this->B_GuardarJuego->BackColor = System::Drawing::Color::Yellow;
            this->B_GuardarJuego->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_GuardarJuego->Location = System::Drawing::Point(1430, 626);
            this->B_GuardarJuego->Name = L"B_GuardarJuego";
            this->B_GuardarJuego->Size = System::Drawing::Size(209, 108);
            this->B_GuardarJuego->TabIndex = 0;
            this->B_GuardarJuego->Text = L"Guardar juego";
            this->B_GuardarJuego->UseVisualStyleBackColor = false;
            this->B_GuardarJuego->Click += gcnew System::EventHandler(this, &AreaJuego::button1_Click);
            // 
            // B_Pausa
            // 
            this->B_Pausa->BackColor = System::Drawing::Color::RoyalBlue;
            this->B_Pausa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_Pausa->Location = System::Drawing::Point(1302, 758);
            this->B_Pausa->Name = L"B_Pausa";
            this->B_Pausa->Size = System::Drawing::Size(209, 108);
            this->B_Pausa->TabIndex = 1;
            this->B_Pausa->Text = L"Pausa";
            this->B_Pausa->UseVisualStyleBackColor = false;
            this->B_Pausa->Click += gcnew System::EventHandler(this, &AreaJuego::button2_Click);
            // 
            // B_Plantar
            // 
            this->B_Plantar->BackColor = System::Drawing::Color::OrangeRed;
            this->B_Plantar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_Plantar->Location = System::Drawing::Point(982, 565);
            this->B_Plantar->Name = L"B_Plantar";
            this->B_Plantar->Size = System::Drawing::Size(169, 57);
            this->B_Plantar->TabIndex = 2;
            this->B_Plantar->Text = L"Plantar";
            this->B_Plantar->UseVisualStyleBackColor = false;
            // 
            // TablaJuego
            // 
            this->TablaJuego->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->TablaJuego->BackgroundColor = System::Drawing::Color::ForestGreen;
            this->TablaJuego->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->TablaJuego->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->TablaJuego->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->TablaJuego->ColumnHeadersHeight = 31;
            this->TablaJuego->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->TablaJuego->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->Tipo_Arbol,
                    this->Ubicacion, this->Frutos, this->Monto, this->Vendidos, this->Perdidos
            });
            this->TablaJuego->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->TablaJuego->Location = System::Drawing::Point(982, 268);
            this->TablaJuego->MultiSelect = false;
            this->TablaJuego->Name = L"TablaJuego";
            this->TablaJuego->ReadOnly = true;
            this->TablaJuego->RightToLeft = System::Windows::Forms::RightToLeft::No;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::ForestGreen;
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->TablaJuego->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->TablaJuego->RowHeadersWidth = 51;
            this->TablaJuego->RowTemplate->Height = 24;
            this->TablaJuego->ScrollBars = System::Windows::Forms::ScrollBars::None;
            this->TablaJuego->ShowRowErrors = false;
            this->TablaJuego->Size = System::Drawing::Size(884, 58);
            this->TablaJuego->TabIndex = 3;
            this->TablaJuego->TabStop = false;
            this->TablaJuego->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AreaJuego::dataGridView1_CellContentClick);
            // 
            // Tipo_Arbol
            // 
            this->Tipo_Arbol->HeaderText = L"Tipo �rbol";
            this->Tipo_Arbol->MinimumWidth = 6;
            this->Tipo_Arbol->Name = L"Tipo_Arbol";
            this->Tipo_Arbol->ReadOnly = true;
            this->Tipo_Arbol->Width = 125;
            // 
            // Ubicacion
            // 
            this->Ubicacion->HeaderText = L"Ubicaci�n";
            this->Ubicacion->MinimumWidth = 6;
            this->Ubicacion->Name = L"Ubicacion";
            this->Ubicacion->ReadOnly = true;
            this->Ubicacion->Width = 125;
            // 
            // Frutos
            // 
            this->Frutos->HeaderText = L"Cant.Frutos";
            this->Frutos->MinimumWidth = 6;
            this->Frutos->Name = L"Frutos";
            this->Frutos->ReadOnly = true;
            this->Frutos->Width = 125;
            // 
            // Monto
            // 
            this->Monto->HeaderText = L"Monto Total";
            this->Monto->MinimumWidth = 6;
            this->Monto->Name = L"Monto";
            this->Monto->ReadOnly = true;
            this->Monto->Width = 125;
            // 
            // Vendidos
            // 
            this->Vendidos->HeaderText = L"Vendidos";
            this->Vendidos->MinimumWidth = 6;
            this->Vendidos->Name = L"Vendidos";
            this->Vendidos->ReadOnly = true;
            this->Vendidos->Width = 125;
            // 
            // Perdidos
            // 
            this->Perdidos->HeaderText = L"Perdidos";
            this->Perdidos->MinimumWidth = 6;
            this->Perdidos->Name = L"Perdidos";
            this->Perdidos->ReadOnly = true;
            this->Perdidos->Width = 125;
            // 
            // B_Salir
            // 
            this->B_Salir->BackColor = System::Drawing::SystemColors::ButtonShadow;
            this->B_Salir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_Salir->Location = System::Drawing::Point(1569, 758);
            this->B_Salir->Name = L"B_Salir";
            this->B_Salir->Size = System::Drawing::Size(209, 108);
            this->B_Salir->TabIndex = 4;
            this->B_Salir->Text = L"SALIR";
            this->B_Salir->UseVisualStyleBackColor = false;
            // 
            // B_VenderTodo
            // 
            this->B_VenderTodo->BackColor = System::Drawing::Color::Red;
            this->B_VenderTodo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_VenderTodo->Location = System::Drawing::Point(1302, 455);
            this->B_VenderTodo->Name = L"B_VenderTodo";
            this->B_VenderTodo->Size = System::Drawing::Size(290, 57);
            this->B_VenderTodo->TabIndex = 5;
            this->B_VenderTodo->Text = L"VENDER TODO";
            this->B_VenderTodo->UseVisualStyleBackColor = false;
            // 
            // ArbolesSinPlantar
            // 
            this->ArbolesSinPlantar->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->ArbolesSinPlantar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ArbolesSinPlantar->ForeColor = System::Drawing::SystemColors::WindowText;
            this->ArbolesSinPlantar->Location = System::Drawing::Point(1327, 145);
            this->ArbolesSinPlantar->Name = L"ArbolesSinPlantar";
            this->ArbolesSinPlantar->ReadOnly = true;
            this->ArbolesSinPlantar->Size = System::Drawing::Size(82, 30);
            this->ArbolesSinPlantar->TabIndex = 6;
            this->ArbolesSinPlantar->TextChanged += gcnew System::EventHandler(this, &AreaJuego::textBox1_TextChanged);
            // 
            // SinPlantar
            // 
            this->SinPlantar->AutoSize = true;
            this->SinPlantar->BackColor = System::Drawing::Color::Blue;
            this->SinPlantar->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->SinPlantar->Location = System::Drawing::Point(1077, 145);
            this->SinPlantar->Name = L"SinPlantar";
            this->SinPlantar->Size = System::Drawing::Size(210, 26);
            this->SinPlantar->TabIndex = 7;
            this->SinPlantar->Text = L"�rboles sin plantar";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Yellow;
            this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(1514, 149);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(78, 26);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Dinero";
            // 
            // Dinero
            // 
            this->Dinero->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->Dinero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Dinero->ForeColor = System::Drawing::SystemColors::WindowText;
            this->Dinero->Location = System::Drawing::Point(1619, 149);
            this->Dinero->Name = L"Dinero";
            this->Dinero->ReadOnly = true;
            this->Dinero->Size = System::Drawing::Size(82, 30);
            this->Dinero->TabIndex = 9;
            // 
            // AreaJuego
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::PaleGreen;
            this->ClientSize = System::Drawing::Size(1924, 878);
            this->Controls->Add(this->Dinero);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->SinPlantar);
            this->Controls->Add(this->ArbolesSinPlantar);
            this->Controls->Add(this->B_VenderTodo);
            this->Controls->Add(this->B_Salir);
            this->Controls->Add(this->B_Plantar);
            this->Controls->Add(this->B_Pausa);
            this->Controls->Add(this->B_GuardarJuego);
            this->Controls->Add(this->TablaJuego);
            this->KeyPreview = true;
            this->Name = L"AreaJuego";
            this->Text = L"AreaJuego";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaJuego))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        void MoverLabelSobreLabel(int x, int y)
        {
            labelRojo->Left = matrizLabels[x][y]->Left;
            labelRojo->Top = matrizLabels[x][y]->Top;
            labelRojo->BringToFront();
        }

        void Form_KeyDown(Object^ sender, KeyEventArgs^ e)
        {
            int newLabelX = labelX;
            int newLabelY = labelY;

            // Mover hacia arriba
            if (e->KeyCode == Keys::Up)
            {
                newLabelX = Math::Max(0, labelX - 1);

            }
            // Mover hacia abajo

            else if (e->KeyCode == Keys::Down)
            {
                newLabelX = Math::Min(11, labelX + 1);
            }
            // Mover hacia la izquierda
            else if (e->KeyCode == Keys::Left)
            {
                newLabelY = Math::Max(0, labelY - 1);
            }
            // Mover hacia la derecha
            else if (e->KeyCode == Keys::Right)
            {
                newLabelY = Math::Min(11, labelY + 1);

            }

            // Verificar si la nueva posici�n del label est� vac�a (no hay otro label en esa posici�n)
            if (matrizLabels[newLabelX][newLabelY]->BackColor == Color::LimeGreen)
            {
                // Mover el label rojo a la nueva posici�n
                MoverLabelSobreLabel(newLabelX, newLabelY);

                // Actualizar las coordenadas del label rojo
                labelX = newLabelX;
                labelY = newLabelY;
            }
        }


#pragma endregion
    private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

      Proyecto2_ED::Mercado^ ventMercado = gcnew Proyecto2_ED::Mercado();
      ventMercado->Show();

    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}