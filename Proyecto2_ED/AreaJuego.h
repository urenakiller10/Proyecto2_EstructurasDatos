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
                    matrizLabels[i][j]->Left = 10 + j * 60; // Posición horizontal
                    matrizLabels[i][j]->Top = 10 + i * 60; // Posición vertical
                }
            }
        
        
            
            // Crear el label rojo
            labelRojo->Width = 50;
            labelRojo->Height = 50;
            labelRojo->BackColor = Color::White;
 ;
            MoverLabelSobreLabel(0, 0); // Mover el label sobre el label en la posición (0,0)
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
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tipo_Arbol;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ubicacion;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Frutos;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Monto;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vendidos;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Perdidos;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;


    protected:

    public:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void initCustom() {
            labelRojo = gcnew Label();
            this->labelRojo->Image = Image::FromFile("recursos/granjero.png");

        }

        //---------------------------------------------Métodos de la tabla de datos--------------------------------------------------------------



         void SetupDataGridView()
            {
            // Configurar la cantidad de filas del DataGridView
  
             dataGridView1->RowCount = 4; // Por ejemplo maaeee establece 10 filas fijas

            }

     //-------------------METODO QUE SE PUEDE USAR MÁS ADELANTE----------------------

         void ActualizarInformacionFilas()
         {
             // Actualizar información en las filas existentes
             for (int fila = 0; fila < dataGridView1->RowCount; fila++)
             {
                 dataGridView1->Rows[fila]->Cells[0]->Value = "Valor 1";
                 dataGridView1->Rows[fila]->Cells[1]->Value = "Valor 2";
                 dataGridView1->Rows[fila]->Cells[2]->Value = "Valor 3";
             }
         }
         


         void OcultarColumnaSeleccionada()
         {
             dataGridView1->ColumnHeadersVisible = false;
         }

         void EstablecerTextoFilas()
         {
             DataGridViewCellStyle^ rowStyle = gcnew DataGridViewCellStyle();
             rowStyle->Font = gcnew System::Drawing::Font(dataGridView1->Font->FontFamily, 10, FontStyle::Bold);

             dataGridView1->Rows[0]->Cells[0]->Value = "Binario";
             dataGridView1->Rows[0]->DefaultCellStyle = rowStyle;

             dataGridView1->Rows[1]->Cells[0]->Value = "AVL";
             dataGridView1->Rows[1]->DefaultCellStyle = rowStyle;

             dataGridView1->Rows[2]->Cells[0]->Value = "Splay";
             dataGridView1->Rows[2]->DefaultCellStyle = rowStyle;

             dataGridView1->Rows[3]->Cells[0]->Value = "Heap";
             dataGridView1->Rows[3]->DefaultCellStyle = rowStyle;
         }
    //---------------------------------------------------------------------------------------------------------------------------------------------

        void InitializeComponent(void)
        {   
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->Tipo_Arbol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Ubicacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Frutos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Monto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Vendidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Perdidos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Yellow;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(1469, 631);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(169, 87);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Guardar juego";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &AreaJuego::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Red;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(1368, 743);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(169, 87);
            this->button2->TabIndex = 1;
            this->button2->Text = L"Pausa";
            this->button2->UseVisualStyleBackColor = false;
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::LawnGreen;
            this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(982, 533);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(169, 87);
            this->button3->TabIndex = 2;
            this->button3->Text = L"Plantar";
            this->button3->UseVisualStyleBackColor = false;
            // 
            // dataGridView1
            // 
            this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView1->BackgroundColor = System::Drawing::Color::ForestGreen;
            this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::PaleGreen;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->dataGridView1->ColumnHeadersHeight = 31;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->Tipo_Arbol,
                    this->Ubicacion, this->Frutos, this->Monto, this->Vendidos, this->Perdidos
            });
            this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->dataGridView1->Location = System::Drawing::Point(982, 268);
            this->dataGridView1->MultiSelect = false;
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RightToLeft = System::Windows::Forms::RightToLeft::No;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::ForestGreen;
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
            this->dataGridView1->ShowRowErrors = false;
            this->dataGridView1->Size = System::Drawing::Size(884, 58);
            this->dataGridView1->TabIndex = 3;
            this->dataGridView1->TabStop = false;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AreaJuego::dataGridView1_CellContentClick);
            // 
            // Tipo_Arbol
            // 
            this->Tipo_Arbol->HeaderText = L"Tipo árbol";
            this->Tipo_Arbol->MinimumWidth = 6;
            this->Tipo_Arbol->Name = L"Tipo_Arbol";
            this->Tipo_Arbol->ReadOnly = true;
            this->Tipo_Arbol->Width = 125;
            // 
            // Ubicacion
            // 
            this->Ubicacion->HeaderText = L"Ubicación";
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
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::Cyan;
            this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button4->Location = System::Drawing::Point(1595, 743);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(169, 87);
            this->button4->TabIndex = 4;
            this->button4->Text = L"Plantar";
            this->button4->UseVisualStyleBackColor = false;
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::Color::OrangeRed;
            this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button5->Location = System::Drawing::Point(1469, 470);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(169, 87);
            this->button5->TabIndex = 5;
            this->button5->Text = L"VENDER TODO";
            this->button5->UseVisualStyleBackColor = false;
            // 
            // AreaJuego
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::PaleGreen;
            this->ClientSize = System::Drawing::Size(1924, 878);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->dataGridView1);
            this->KeyPreview = true;
            this->Name = L"AreaJuego";
            this->Text = L"AreaJuego";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

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

            // Verificar si la nueva posición del label está vacía (no hay otro label en esa posición)
            if (matrizLabels[newLabelX][newLabelY]->BackColor == Color::LimeGreen)
            {
                // Mover el label rojo a la nueva posición
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

     //   Proyecto2_ED::Mercado^ ventMercado = gcnew Proyecto2_ED::Mercado();
      //  ventMercado->Show();

    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
};
}