#pragma once
#include <vector>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> 
#include "Mercado.h"
#include "ImputForm.h"
#include <iostream>
#include <fstream>


// Resto de tus inclusiones de archivos de encabezado

using namespace System::Collections::Generic;

namespace Proyecto2_ED {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Threading;



    /// <summary>
    /// Resumen de AreaJuego
    /// </summary>
    public ref class AreaJuego : public System::Windows::Forms::Form
    {

    private:

        array<array<Label^, 1>^>^ matrizLabels;

        int labelX;
        int labelY;
        int contEspanta = 0;
        bool mercadoVisible;

        Label^ labelGranjero;
        Label^ LabelCuervo;
        Label^ LabelOveja;
        Label^ LabelGusano;

        System::Windows::Forms::Timer^ timer;
        System::Windows::Forms::Timer^ temporizador;

        System::Windows::Forms::Label^ SinPlantar;
        System::Windows::Forms::Label^ Arboles_Pendientes;

        System::Windows::Forms::Button^ B_Espanta;

    public:
        AreaJuego(void)
        {
            InitializeComponent();
            SetupDataGridView();
            EstablecerTextoFilas();
            initCustom();
            CrearMatriz();


            mercadoVisible = false;

            //Tiempo para que la fucking ventana de mercado aparezca cada cierto tiempo en AreaJuego


            System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
            timer->Interval = 8000; // 15000 ms = 15 s 

            timer->Tick += gcnew EventHandler(this, &AreaJuego::MostrarVentanaMercado);
            timer->Start();

            B_Espanta->Click += gcnew EventHandler(this, &AreaJuego::B_Espanta_Click);

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

    
    //---------------------------------------------------Poner espantapajaros en la matriz-----------------------------------------------------------

        void AreaJuego::B_Espanta_Click(Object^ sender, EventArgs^ e)
        {
            // Crear un nuevo label

            Label^ labelEspanta = gcnew Label();

            labelEspanta->BackgroundImage = Image::FromFile("recursos/espant.png");
            labelEspanta->BackgroundImageLayout = ImageLayout::Stretch;

            labelEspanta->Width = 50;
            labelEspanta->Height = 50;

            labelEspanta->Left = labelGranjero->Left;
            labelEspanta->Top = labelGranjero->Top;

            // Agregar el nuevo label al formulario
            this->Controls->Add(labelEspanta);
            labelEspanta->BringToFront();

            // Incrementar el contador de labels
            contEspanta++;

            // Obtener las coordenadas del LabelEspanta
            int espantaX = labelEspanta->Top / 60;
            int espantaY = labelEspanta->Left / 60;

            // Cambiar el color de las casillas adyacentes al LabelEspanta a gris
            int filaInicio = Math::Max(espantaX - 1, 0);
            int filaFin = Math::Min(espantaX + 1, 11);
            int columnaInicio = Math::Max(espantaY - 1, 0);
            int columnaFin = Math::Min(espantaY + 1, 11);

            for (int i = filaInicio; i <= filaFin; i++)
            {
                for (int j = columnaInicio; j <= columnaFin; j++)
                {
                    // Verificar si la casilla no es la posición actual del LabelEspanta
                    if (i != espantaX || j != espantaY)
                    {
                        // Verificar si la casilla tiene una imagen
                        if (matrizLabels[i][j]->BackgroundImage != nullptr)
                        {
                            // Eliminar la imagen de la casilla
                            matrizLabels[i][j]->BackgroundImage = nullptr;
                            matrizLabels[i][j]->BackgroundImageLayout = ImageLayout::None;
                        }

                        // Cambiar el color de fondo de la casilla a gris
                        matrizLabels[i][j]->BackColor = Color::Gray;
                    }
                }
            }

        }

        //-------------------------------------------------------------------------------------------------------------------------------------------

        //------------------------------------------------------Matriz de botones---------------------------------------------------------

        void AreaJuego::CrearMatriz()
        {
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

            // Posicionar los label en el formulario
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    matrizLabels[i][j]->Left = 10 + j * 60; // Posición horizontal
                    matrizLabels[i][j]->Top = 10 + i * 60; // Posición vertical
                }
            }
            labelGranjero = gcnew Label();
            labelGranjero->Width = 50;
            labelGranjero->Height = 50;
            labelGranjero->BackgroundImage = Image::FromFile("recursos/granje.png");
            labelGranjero->BackgroundImageLayout = ImageLayout::Stretch;
            this->Controls->Add(labelGranjero);


            // Inicializar las coordenadas del granjero
            labelX = 0;
            labelY = 0;

            // Suscribir el formulario al evento KeyDown
            this->KeyDown += gcnew KeyEventHandler(this, &AreaJuego::Form_KeyDown);

            //---------------------------------------------------------------------------------------------------------------------------------------

            //------------------------------------------------------Aparezcan plagas cada cierto tiempo-------------------------------------------------------
            
            // Crear el temporizador
            System::Windows::Forms::Timer^ temporizador = gcnew System::Windows::Forms::Timer();
            temporizador->Interval = 8000; // Intervalo de 10 segundos
            temporizador->Tick += gcnew EventHandler(this, &AreaJuego::Temporizador_Tick);
            temporizador->Start();
        }

            void AreaJuego::Temporizador_Tick(Object^ sender, EventArgs^ e)
            {
                // Obtener una casilla vacía aleatoria
                int fila, columna;
                bool esCasillaValida;

                do
                {
                    fila = rand() % 12;
                    columna = rand() % 12;

                    // Verificar si la casilla está vacía y no hay un "LabelEspanta" en un radio de 1
                    esCasillaValida = (matrizLabels[fila][columna]->BackColor == Color::LimeGreen) &&
                        hayLabelEspantaCerca(fila, columna) != true;
                } while (!esCasillaValida);

                // Crear una lista de los tres labels
                List<Label^>^ listaLabels = gcnew List<Label^>();
                listaLabels->Add(LabelCuervo);
                listaLabels->Add(LabelOveja);
                listaLabels->Add(LabelGusano);

                // Obtener un número aleatorio para seleccionar uno de los tres labels
                int indiceAleatorio = rand() % listaLabels->Count;

                // Obtener el label correspondiente al índice aleatorio
                Label^ labelImagen = listaLabels[indiceAleatorio];

                // Clonar la imagen del label y asignarla a la casilla vacía en la matriz
                matrizLabels[fila][columna]->BackgroundImage = labelImagen->Image;
                matrizLabels[fila][columna]->Name = labelImagen->Name;

                // Redimensionar la imagen para que se ajuste al tamaño del label
                matrizLabels[fila][columna]->BackgroundImageLayout = ImageLayout::Stretch;
            }

            //----------------------------Verificar si hay un "LabelEspanta" en un radio de 1 alrededor de la casilla especificada---------------------
            bool AreaJuego::hayLabelEspantaCerca(int fila, int columna)
            {


                int filaInicio = Math::Max(fila - 1, 0);
                int filaFin = Math::Min(fila + 1, 11);
                int columnaInicio = Math::Max(columna - 1, 0);
                int columnaFin = Math::Min(columna + 1, 11);

                for (int i = filaInicio; i <= filaFin; i++)
                {
                    for (int j = columnaInicio; j <= columnaFin; j++)
                    {
                        // Verificar si la casilla actual contiene un "LabelEspanta"
                        if (matrizLabels[i][j]->Name == "labelEspanta")
                        {
                            return true;
                        }
                    }
                }

                return false;
            }



            //------------------------------------------------------------Movimiento granjero a traves de matriz--------------------------------------------------

            //Perro esto es para mover granjero a traves de la matriz de Labels

            void MoverLabelSobreLabel(int x, int y)
            {
                labelGranjero->Left = matrizLabels[x][y]->Left;
                labelGranjero->Top = matrizLabels[x][y]->Top;
                labelGranjero->BringToFront();
            }

            //Esto es para mover el granjero, pero utilizando las teclas del bendito teclado de la compu

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
                if (matrizLabels[newLabelX][newLabelY]->BackColor != Color::Black)
                {
                    // Mover el label rojo a la nueva posición
                    MoverLabelSobreLabel(newLabelX, newLabelY);

                    // Verificar si hay una plaga en la nueva posición
                    if (matrizLabels[newLabelX][newLabelY]->BackgroundImage != nullptr)
                    {
                        // Eliminar la plaga de la matriz
                        matrizLabels[newLabelX][newLabelY]->BackgroundImage = nullptr;
                        matrizLabels[newLabelX][newLabelY]->BackgroundImageLayout = ImageLayout::None;
                    }

                    // Actualizar las coordenadas del label rojo
                    labelX = newLabelX;
                    labelY = newLabelY;
                }
            }

            //------------------------------------------Se colocan imágenes de los labels y otros elementos del área de juego------------------------------------

            void initCustom() {


                labelGranjero = gcnew Label();
                this->labelGranjero->Image = Image::FromFile("recursos/granje.png");
                this->labelGranjero->Width = 50;
                this->labelGranjero->Height = 50;
                this->labelGranjero->BackgroundImageLayout = ImageLayout::Stretch;


                LabelGusano = gcnew Label();
                this->LabelGusano->Image = Image::FromFile("recursos/oruga.png");

                LabelCuervo = gcnew Label();
                this->LabelCuervo->Image = Image::FromFile("recursos/cuervo.png");

                LabelOveja = gcnew Label();
                this->LabelOveja->Image = Image::FromFile("recursos/oveja.png");


            }

            //-----------------------------------------------------------------------------------------------------------------------------------------------------


            //---------------------------------------------Métodos de la tabla de datos--------------------------------------------------------------



            void SetupDataGridView()
            {
                // Configurar la cantidad de filas del DataGridView

                TablaJuego->RowCount = 4; // Por ejemplo maaeee establece 10 filas fijas

                TablaJuego->KeyDown += gcnew KeyEventHandler(this, &AreaJuego::TablaJuego_KeyDown);


            }

            //----------****-METODO QUE SE PUEDE USAR MÁS ADELANTE----******------------

             void ActualizarInformacionFilas()
             {
                 // Actualizar información en las filas existentes
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
        //---------------------------------------------------Mostrar Ventana Mercado en Area de Juego cada cierto tiempo---------------------------------------------------------------------------------

             void MostrarVentanaMercado(Object^ sender, EventArgs^ e)
             {
                 // Detiene el temporizador
                 System::Windows::Forms::Timer^ timer = dynamic_cast<System::Windows::Forms::Timer^>(sender);
                 timer->Stop();

                 // Crea y muestra la ventana de mercado
                 Mercado^ mercado = gcnew Mercado();
                 mercado->Show();

                 // Configura un temporizador para cerrar la ventana de mercado después de 30 segundos
                 System::Windows::Forms::Timer^ timerCerrar = gcnew System::Windows::Forms::Timer();
                 timerCerrar->Interval = 15000; // 30000 ms = 30 segundos
                 timerCerrar->Tick += gcnew EventHandler(this, &AreaJuego::CerrarVentanaMercado);
                 timerCerrar->Start();
             }

             // Método para cerrar la ventana de mercado
             void CerrarVentanaMercado(Object^ sender, EventArgs^ e)
             {
                 // Detiene el temporizador
                 System::Windows::Forms::Timer^ timer = dynamic_cast<System::Windows::Forms::Timer^>(sender);
                 timer->Stop();

                 // Cierra la ventana de mercado
                 Mercado^ mercado = dynamic_cast<Mercado^>(Application::OpenForms["Mercado"]);
                 if (mercado != nullptr)
                 {
                     mercado->Close();
                 }


                 // Configura un temporizador para mostrar la ventana de mercado nuevamente después de cierto tiempo
                 System::Windows::Forms::Timer^ timerMostrar = gcnew System::Windows::Forms::Timer();
                 timerMostrar->Interval = 15000; // 60000 ms = 1 minuto
                 timerMostrar->Tick += gcnew EventHandler(this, &AreaJuego::MostrarVentanaMercado);
                 timerMostrar->Start();
             }

             //----------------------------------------------------------------------------------------------------------------------------------------------------

            void InitializeComponent(void)
            {   
                System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
                System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
                this->SinPlantar = (gcnew System::Windows::Forms::Label());
                this->Arboles_Pendientes = (gcnew System::Windows::Forms::Label());
                this->B_Espanta = (gcnew System::Windows::Forms::Button());
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
                this->B_GuardarJuego->Click += gcnew System::EventHandler(this, &AreaJuego::B_GuardarJuego_Click);
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
                this->B_Plantar->Location = System::Drawing::Point(1010, 553);
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
                dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
                dataGridViewCellStyle3->BackColor = System::Drawing::Color::PaleGreen;
                dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
                dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
                dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::PaleGreen;
                dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::PaleGreen;
                dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
                this->TablaJuego->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
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
                dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
                dataGridViewCellStyle4->BackColor = System::Drawing::Color::ForestGreen;
                dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
                dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
                dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
                dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
                dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
                this->TablaJuego->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
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
                this->B_VenderTodo->Location = System::Drawing::Point(1271, 432);
                this->B_VenderTodo->Name = L"B_VenderTodo";
                this->B_VenderTodo->Size = System::Drawing::Size(290, 38);
                this->B_VenderTodo->TabIndex = 5;
                this->B_VenderTodo->Text = L"VENDER TODO";
                this->B_VenderTodo->UseVisualStyleBackColor = false;
                // 
                // SinPlantar
                // 
                this->SinPlantar->AutoSize = true;
                this->SinPlantar->BackColor = System::Drawing::Color::Blue;
                this->SinPlantar->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(0)));
                this->SinPlantar->Location = System::Drawing::Point(1241, 141);
                this->SinPlantar->Name = L"SinPlantar";
                this->SinPlantar->Size = System::Drawing::Size(210, 26);
                this->SinPlantar->TabIndex = 7;
                this->SinPlantar->Text = L"Árboles sin plantar";
                // 
                // Arboles_Pendientes
                // 
                this->Arboles_Pendientes->AutoSize = true;
                this->Arboles_Pendientes->BackColor = System::Drawing::Color::White;
                this->Arboles_Pendientes->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(0)));
                this->Arboles_Pendientes->Location = System::Drawing::Point(1489, 141);
                this->Arboles_Pendientes->Name = L"Arboles_Pendientes";
                this->Arboles_Pendientes->Size = System::Drawing::Size(40, 26);
                this->Arboles_Pendientes->TabIndex = 8;
                // 
                // B_Espanta
                // 


                B_Espanta = gcnew System::Windows::Forms::Button();
                this->B_Espanta->BackColor = System::Drawing::Color::MediumPurple;
                B_Espanta->Text = "Colocar espantapájaros";
                this->B_Espanta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
                this->B_Espanta->Size = System::Drawing::Size(199, 82);
                this->B_Espanta->TabIndex = 2;
                B_Espanta->Location = System::Drawing::Point(999, 440);
                this->B_Espanta->UseVisualStyleBackColor = false;
                B_Espanta->Click += gcnew EventHandler(this, &AreaJuego::B_Espanta_Click);

                // 
                // AreaJuego
                // 
                this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
                this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                this->BackColor = System::Drawing::Color::PaleGreen;
                this->ClientSize = System::Drawing::Size(1924, 878);
                this->Controls->Add(this->B_Espanta);
                this->Controls->Add(this->Arboles_Pendientes);
                this->Controls->Add(this->SinPlantar);
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

            #pragma endregion

            private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            }
 
            private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            }
            private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
            }
            private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            }

           void B_GuardarJuego_Click(Object^ sender, EventArgs^ e)
           {
               std::string filePath = "Top10.txt";

               // Abrir el archivo en modo de escritura
               std::ofstream archivo(filePath, std::ios::app); // std::ios::app para agregar contenido al final del archivo

               // Verificar si el archivo se abrió correctamente
               if (!archivo)
               {
                   MessageBox::Show("Error al abrir el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               // Escribir en el archivo
               archivo << "Hola mundo 10" << std::endl;

               // Cerrar el archivo
               archivo.close();

               MessageBox::Show("El archivo ha sido guardado correctamente.", "Guardar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }

        };
    }