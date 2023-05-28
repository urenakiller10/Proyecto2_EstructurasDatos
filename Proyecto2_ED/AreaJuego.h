#pragma once

#include "vcclr.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Mercado.h"
#include "ImputForm.h"
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <thread>
#include <chrono>
#include "Administrador.h"
#include "Confi.h"
#include "ArbolBinario.h"
//#include "Heap.h"
#include <Thread>
#include <cstdlib>
#include <list>
#include <vcclr.h>
#include "ListaSimple.h"

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
        Administrador* admin; // Declarar una referencia a Administrador
        Confi* config;

        //Esto quedara como un vestigio de nuestro sufrimiento
    public: int cantidadFrutos = 0;

    private:
        List<Thread^>^ listaHilosBinarios = gcnew List<Thread^>();
        Lista<ArbolBinario*>* lista = new Lista<ArbolBinario*>();

        List<Thread^>^ listaHilosHeap = gcnew List<Thread^>();
        Dictionary<Thread^, System::IntPtr>^ datosHilosHeap;

        List<Thread^>^ listaHilosAvl = gcnew List<Thread^>();
        Dictionary<Thread^, System::IntPtr>^ datosHilosAvl;

        List<Thread^>^ listaHilosSplay = gcnew List<Thread^>();
        Dictionary<Thread^, System::IntPtr>^ datosHilosSplay;

    private:
        array<array<Label^, 1>^>^ matrizLabels;

        int labelX;
        int labelY;
        int contEspanta = 0;
        bool mercadoVisible;
        bool running = true;

        Label^ labelGranjero;
        Label^ LabelCuervo;
        Label^ LabelOveja;
        Label^ LabelGusano;

        System::Windows::Forms::Timer^ timer;
        System::Windows::Forms::Timer^ temporizador;

        System::Windows::Forms::Label^ SinPlantar;
        System::Windows::Forms::Label^ Arboles_Pendientes;
        private: System::Windows::Forms::Button^ B_PlantarBinario;
        private: System::Windows::Forms::Button^ B_PlantarSplay;
        private: System::Windows::Forms::Button^ B_PlantarHeap;
    private: System::Windows::Forms::Button^ B_Espanta;

        private: System::Windows::Forms::Label^ label1;
        private: System::Windows::Forms::Label^ label2;
        private: System::Windows::Forms::Label^ label3;
        private: System::Windows::Forms::TextBox^ T_CantBinarios;
        private: System::Windows::Forms::TextBox^ T_CantAvl;
        private: System::Windows::Forms::TextBox^ T_CantSplay;        //Se declaran los Text Box donde se guardan la cantidad de árboles
        private: System::Windows::Forms::TextBox^ T_CantHeap;
        private: System::Windows::Forms::TextBox^ T_CantidadEspanta;
        private: System::Windows::Forms::Label^ label4;

    private:
        System::Threading::Thread^ hiloFrutos;

    public:
        AreaJuego(Administrador* adminRef,Confi* configRef) : admin(adminRef), config (configRef)
        {
            InitializeComponent();
            SetupDataGridView();
            initCustom();
            CrearMatriz();
            updateStock(admin);
            mercadoVisible = false;
            confBotones(admin);
            Thread^ hiloActu = gcnew Thread(gcnew System::Threading::ThreadStart(this, &AreaJuego::controlActu));
            hiloActu->Start();

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
    private: System::Windows::Forms::Button^ B_PlantarAVL;

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
            int filaInicio = Math::Max(espantaX - 2, 0);
            int filaFin = Math::Min(espantaX + 2, 11);
            int columnaInicio = Math::Max(espantaY - 2, 0);
            int columnaFin = Math::Min(espantaY + 2, 11);

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


            B_Espanta->Text = "Colocar espantapájaros";
            B_Espanta->Location = System::Drawing::Point(790, 460);
            B_Espanta->Click += gcnew EventHandler(this, &AreaJuego::B_Espanta_Click);

        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //---------------------------------------------Métodos de la tabla de datos--------------------------------------------------------------



        void SetupDataGridView()
        {
            // Configurar la cantidad de filas del DataGridView

            TablaJuego->RowCount = 1; // Por ejemplo maaeee establece 10 filas fijas

            TablaJuego->KeyDown += gcnew KeyEventHandler(this, &AreaJuego::TablaJuego_KeyDown);


        }

        //----------****-METODO QUE SE PUEDE USAR MÁS ADELANTE----******------------

        void ActualizarInformacionNuevo(std::string tipo, int x, int y)
        {
            int rowIndex = TablaJuego->Rows->Add();

            //Formatear el string de las coords
            std::string ubicacion = "(" + std::to_string(x) + "," + std::to_string(y) + ")";

            //Convertir los datos al tipo necesario
            System::String^ tipoA = gcnew System::String(tipo.c_str());
            System::String^ ubi = gcnew System::String(ubicacion.c_str());

            // Obtener la fila agregada
            DataGridViewRow^ nuevaFila = TablaJuego->Rows[rowIndex];

            // Asignar los valores a las celdas de la nueva fila
            nuevaFila->Cells[0]->Value = tipoA;
            nuevaFila->Cells[1]->Value = ubi;
            nuevaFila->Cells[2]->Value = "0";
            nuevaFila->Cells[3]->Value = "0.0";
            nuevaFila->Cells[4]->Value = "0";
        }

        void actualizarInfo(){
            int x = 0; int y = 0;
            for (int fila = 0; fila < TablaJuego->Rows->Count; fila++)
            {
                DataGridViewRow^ dataGridViewRow = TablaJuego->Rows[fila];

                // Acceder a la segunda celda de la fila
                DataGridViewCell^ cell = dataGridViewRow->Cells[1];

                // Verificar si la celda es nula
                if (cell->Value == nullptr)
                {
                    // Celda nula encontrada, salir del ciclo
                    break;
                }

                // Obtener el valor de la celda
                String^ valor = cell->Value->ToString();
                valor = valor->Replace("(", "");
                valor = valor->Replace(")", "");

                // Dividir la cadena en dos partes separadas por la coma
                array<String^>^ partes = valor->Split(',');

                // Obtener los números como cadenas
                String^ strX = partes[0]->Trim();
                String^ strY = partes[1]->Trim();

                // Convertir las cadenas a enteros
                x = System::Int32::Parse(strX);
                y = System::Int32::Parse(strY);
                NodoLista<ArbolBinario*>* nodo = lista->cabeza;
                while (nodo != nullptr) {
                    ArbolBinario* arbol = nodo->dato;

                    if (arbol->x == x && arbol->y == y) {
                        //Agarrar los frutos
                        std::string cantidadFrutos = std::to_string(arbol->calcularTotalNodos());
                        System::String^ canFrutos = gcnew System::String(cantidadFrutos.c_str());
                        dataGridViewRow->Cells[2]->Value = canFrutos;

                        std::string sumaFrutos = std::to_string(arbol->calcularTotalNodos());
                        System::String^ sumFrutos = gcnew System::String(sumaFrutos.c_str());
                        dataGridViewRow->Cells[3]->Value = canFrutos;
                    }

                    nodo = nodo->siguiente;
                }
            }

            
        }

        void controlActu() {
            while (true) {
                System::Threading::Thread::Sleep(30000);
                actualizarInfo();
            }
        }

        void AgregarFrutosPeriodicamente()
        {
            while (true)
            {
                AgregarFrutosAleatorios();

                // Pausa el hilo durante 30 segundos
                System::Threading::Thread::Sleep(30000);
                
            }
        }

        void AgregarFrutosAleatorios()
        {
            int cantidad = rand() % 10 + 1;  // Genera un número aleatorio entre 1 y 10
            cantidadFrutos += cantidad;
        }



        void hiloBinario() {
            ArbolBinario* ab = new ArbolBinario(labelGranjero->Top, labelGranjero->Left);
            // Agregar el árbol binario al diccionario
            if (ab->listo == false) {
                System::Threading::Thread::Sleep(config->getCreceBinario()*1000);
            }
            while (running) {
                float fruto = config->getMinValue() + static_cast<float>(rand()) * static_cast<float>(config->getPrecioFrutosBinario() - config->getMinValue()) / RAND_MAX;
                System::Threading::Thread::Sleep(config->getCosechaBinario()*1000);
                ab->insertar(fruto);
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
        //---------------------------------------------------Mostrar Ventana Mercado en Area de Juego cada cierto tiempo---------------------------------------------------------------------------------

        void MostrarVentanaMercado(Object^ sender, EventArgs^ e)
        {
            // Detiene el temporizador
            System::Windows::Forms::Timer^ timer = dynamic_cast<System::Windows::Forms::Timer^>(sender);
            timer->Stop();

            // Crea y muestra la ventana de mercado
            Mercado^ mercado = gcnew Mercado(admin,config);
            mercado->Show();


            // Deshabilita el botón de cierre de la ventana de mercado
            mercado->ControlBox = false;


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

                updateStock(admin);
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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->B_GuardarJuego = (gcnew System::Windows::Forms::Button());
            this->B_Pausa = (gcnew System::Windows::Forms::Button());
            this->B_PlantarAVL = (gcnew System::Windows::Forms::Button());
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
            this->B_PlantarBinario = (gcnew System::Windows::Forms::Button());
            this->B_PlantarSplay = (gcnew System::Windows::Forms::Button());
            this->B_PlantarHeap = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->T_CantBinarios = (gcnew System::Windows::Forms::TextBox());
            this->T_CantAvl = (gcnew System::Windows::Forms::TextBox());
            this->T_CantSplay = (gcnew System::Windows::Forms::TextBox());
            this->T_CantHeap = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->T_CantidadEspanta = (gcnew System::Windows::Forms::TextBox());
            this->B_Espanta = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaJuego))->BeginInit();
            this->SuspendLayout();
            // 
            // B_GuardarJuego
            // 
            this->B_GuardarJuego->BackColor = System::Drawing::Color::Yellow;
            this->B_GuardarJuego->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_GuardarJuego->Location = System::Drawing::Point(1429, 626);
            this->B_GuardarJuego->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
            this->B_Pausa->Location = System::Drawing::Point(1301, 758);
            this->B_Pausa->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_Pausa->Name = L"B_Pausa";
            this->B_Pausa->Size = System::Drawing::Size(209, 108);
            this->B_Pausa->TabIndex = 1;
            this->B_Pausa->Text = L"Pausa";
            this->B_Pausa->UseVisualStyleBackColor = false;
            this->B_Pausa->Click += gcnew System::EventHandler(this, &AreaJuego::button2_Click);
            // 
            // B_PlantarAVL
            // 
            this->B_PlantarAVL->BackColor = System::Drawing::Color::DarkOrange;
            this->B_PlantarAVL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_PlantarAVL->Location = System::Drawing::Point(1213, 162);
            this->B_PlantarAVL->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_PlantarAVL->Name = L"B_PlantarAVL";
            this->B_PlantarAVL->Size = System::Drawing::Size(169, 57);
            this->B_PlantarAVL->TabIndex = 2;
            this->B_PlantarAVL->Text = L"Plantar AVL";
            this->B_PlantarAVL->UseVisualStyleBackColor = false;
            this->B_PlantarAVL->Click += gcnew System::EventHandler(this, &AreaJuego::B_PlantarAVL_Click);
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
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
            this->TablaJuego->Location = System::Drawing::Point(981, 268);
            this->TablaJuego->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->TablaJuego->MultiSelect = false;
            this->TablaJuego->Name = L"TablaJuego";
            this->TablaJuego->ReadOnly = true;
            this->TablaJuego->RightToLeft = System::Windows::Forms::RightToLeft::No;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::ForestGreen;
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
            this->TablaJuego->Size = System::Drawing::Size(1531, 31);
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
            this->B_Salir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_Salir->Name = L"B_Salir";
            this->B_Salir->Size = System::Drawing::Size(209, 108);
            this->B_Salir->TabIndex = 4;
            this->B_Salir->Text = L"SALIR";
            this->B_Salir->UseVisualStyleBackColor = false;
            this->B_Salir->Click += gcnew System::EventHandler(this, &AreaJuego::B_Salir_Click);
            // 
            // B_VenderTodo
            // 
            this->B_VenderTodo->BackColor = System::Drawing::Color::Red;
            this->B_VenderTodo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_VenderTodo->Location = System::Drawing::Point(1270, 473);
            this->B_VenderTodo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_VenderTodo->Name = L"B_VenderTodo";
            this->B_VenderTodo->Size = System::Drawing::Size(291, 38);
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
            this->SinPlantar->Location = System::Drawing::Point(1013, 57);
            this->SinPlantar->Name = L"SinPlantar";
            this->SinPlantar->Size = System::Drawing::Size(91, 26);
            this->SinPlantar->TabIndex = 7;
            this->SinPlantar->Text = L"Binarios";
            // 
            // Arboles_Pendientes
            // 
            this->Arboles_Pendientes->AutoSize = true;
            this->Arboles_Pendientes->BackColor = System::Drawing::Color::White;
            this->Arboles_Pendientes->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Arboles_Pendientes->Location = System::Drawing::Point(1489, 142);
            this->Arboles_Pendientes->Name = L"Arboles_Pendientes";
            this->Arboles_Pendientes->Size = System::Drawing::Size(0, 26);
            this->Arboles_Pendientes->TabIndex = 8;
            // 
            // B_PlantarBinario
            // 
            this->B_PlantarBinario->BackColor = System::Drawing::Color::OrangeRed;
            this->B_PlantarBinario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_PlantarBinario->Location = System::Drawing::Point(981, 162);
            this->B_PlantarBinario->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_PlantarBinario->Name = L"B_PlantarBinario";
            this->B_PlantarBinario->Size = System::Drawing::Size(169, 57);
            this->B_PlantarBinario->TabIndex = 9;
            this->B_PlantarBinario->Text = L"Plantar binario";
            this->B_PlantarBinario->UseVisualStyleBackColor = false;
            this->B_PlantarBinario->Click += gcnew System::EventHandler(this, &AreaJuego::B_PlantarBinario_Click);
            // 
            // B_PlantarSplay
            // 
            this->B_PlantarSplay->BackColor = System::Drawing::Color::OrangeRed;
            this->B_PlantarSplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_PlantarSplay->Location = System::Drawing::Point(1469, 162);
            this->B_PlantarSplay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_PlantarSplay->Name = L"B_PlantarSplay";
            this->B_PlantarSplay->Size = System::Drawing::Size(169, 57);
            this->B_PlantarSplay->TabIndex = 10;
            this->B_PlantarSplay->Text = L"Plantar Splay";
            this->B_PlantarSplay->UseVisualStyleBackColor = false;
            this->B_PlantarSplay->Click += gcnew System::EventHandler(this, &AreaJuego::B_PlantarSplay_Click);
            // 
            // B_PlantarHeap
            // 
            this->B_PlantarHeap->BackColor = System::Drawing::Color::DarkOrange;
            this->B_PlantarHeap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_PlantarHeap->Location = System::Drawing::Point(1687, 162);
            this->B_PlantarHeap->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_PlantarHeap->Name = L"B_PlantarHeap";
            this->B_PlantarHeap->Size = System::Drawing::Size(169, 57);
            this->B_PlantarHeap->TabIndex = 11;
            this->B_PlantarHeap->Text = L"Plantar Heap";
            this->B_PlantarHeap->UseVisualStyleBackColor = false;
            this->B_PlantarHeap->Click += gcnew System::EventHandler(this, &AreaJuego::B_PlantarHeap_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Blue;
            this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(1267, 57);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(54, 26);
            this->label1->TabIndex = 12;
            this->label1->Text = L"AVL";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Blue;
            this->label2->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(1501, 57);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(66, 26);
            this->label2->TabIndex = 13;
            this->label2->Text = L"Splay";
            this->label2->Click += gcnew System::EventHandler(this, &AreaJuego::label2_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Blue;
            this->label3->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(1728, 57);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(62, 26);
            this->label3->TabIndex = 14;
            this->label3->Text = L"Heap";
            // 
            // T_CantBinarios
            // 
            this->T_CantBinarios->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->T_CantBinarios->Location = System::Drawing::Point(1039, 110);
            this->T_CantBinarios->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->T_CantBinarios->Name = L"T_CantBinarios";
            this->T_CantBinarios->ReadOnly = true;
            this->T_CantBinarios->Size = System::Drawing::Size(48, 28);
            this->T_CantBinarios->TabIndex = 15;
            // 
            // T_CantAvl
            // 
            this->T_CantAvl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->T_CantAvl->Location = System::Drawing::Point(1271, 110);
            this->T_CantAvl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->T_CantAvl->Name = L"T_CantAvl";
            this->T_CantAvl->ReadOnly = true;
            this->T_CantAvl->Size = System::Drawing::Size(48, 28);
            this->T_CantAvl->TabIndex = 16;
            // 
            // T_CantSplay
            // 
            this->T_CantSplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->T_CantSplay->Location = System::Drawing::Point(1513, 110);
            this->T_CantSplay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->T_CantSplay->Name = L"T_CantSplay";
            this->T_CantSplay->ReadOnly = true;
            this->T_CantSplay->Size = System::Drawing::Size(48, 28);
            this->T_CantSplay->TabIndex = 17;
            // 
            // T_CantHeap
            // 
            this->T_CantHeap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->T_CantHeap->Location = System::Drawing::Point(1745, 110);
            this->T_CantHeap->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->T_CantHeap->Name = L"T_CantHeap";
            this->T_CantHeap->ReadOnly = true;
            this->T_CantHeap->Size = System::Drawing::Size(45, 28);
            this->T_CantHeap->TabIndex = 18;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Blue;
            this->label4->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(1864, 57);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(163, 26);
            this->label4->TabIndex = 19;
            this->label4->Text = L"Espantapájaros";
            // 
            // T_CantidadEspanta
            // 
            this->T_CantidadEspanta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->T_CantidadEspanta->Location = System::Drawing::Point(1905, 110);
            this->T_CantidadEspanta->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->T_CantidadEspanta->Name = L"T_CantidadEspanta";
            this->T_CantidadEspanta->ReadOnly = true;
            this->T_CantidadEspanta->Size = System::Drawing::Size(48, 28);
            this->T_CantidadEspanta->TabIndex = 20;
            this->T_CantidadEspanta->TextChanged += gcnew System::EventHandler(this, &AreaJuego::textBox1_TextChanged_1);
            // 
            // B_Espanta
            // 
            this->B_Espanta->BackColor = System::Drawing::Color::MediumPurple;
            this->B_Espanta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->B_Espanta->Location = System::Drawing::Point(277, 407);
            this->B_Espanta->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->B_Espanta->Name = L"B_Espanta";
            this->B_Espanta->Size = System::Drawing::Size(199, 82);
            this->B_Espanta->TabIndex = 2;
            this->B_Espanta->UseVisualStyleBackColor = false;
            this->B_Espanta->Click += gcnew System::EventHandler(this, &AreaJuego::B_Espanta_Click_1);
            // 
            // AreaJuego
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::PaleGreen;
            this->ClientSize = System::Drawing::Size(1924, 844);
            this->Controls->Add(this->T_CantidadEspanta);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->T_CantHeap);
            this->Controls->Add(this->T_CantSplay);
            this->Controls->Add(this->T_CantAvl);
            this->Controls->Add(this->T_CantBinarios);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->B_PlantarHeap);
            this->Controls->Add(this->B_PlantarSplay);
            this->Controls->Add(this->B_PlantarBinario);
            this->Controls->Add(this->B_Espanta);
            this->Controls->Add(this->Arboles_Pendientes);
            this->Controls->Add(this->SinPlantar);
            this->Controls->Add(this->B_VenderTodo);
            this->Controls->Add(this->B_Salir);
            this->Controls->Add(this->B_PlantarAVL);
            this->Controls->Add(this->B_Pausa);
            this->Controls->Add(this->B_GuardarJuego);
            this->Controls->Add(this->TablaJuego);
            this->KeyPreview = true;
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
               // Crear una ventana de diálogo para ingresar el nombre
               Proyecto2_ED::InputForm^ inputForm = gcnew Proyecto2_ED::InputForm();

               // Mostrar la ventana de diálogo y obtener el nombre ingresado
               if (inputForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                   System::String^ nombre = inputForm->GetNombre();

                   // Verificar si el nombre es un string válido
                   if (System::String::IsNullOrEmpty(nombre)) {
                       MessageBox::Show("Nombre inválido. Inténtelo de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                       return;
                   }

                   // Convertir el contenido de nombre a std::string
                   pin_ptr<const wchar_t> nombreChars = PtrToStringChars(nombre);
                   const wchar_t* nombreRaw = static_cast<const wchar_t*>(nombreChars);
                   std::wstring nombreWStr(nombreRaw);
                   std::string nombreStr(nombreWStr.begin(), nombreWStr.end());



                   // Obtener el dinero disponible desde Mercado.h
                   int dineroDisponible = Mercado::ObtenerDineroDisponible();

                   // Concatenar el dinero disponible al final del nombre
                   //nombreStr += " --- " + std::to_string(dineroDisponible);

                   // Abrir el archivo en modo de escritura
                   std::ofstream archivo("Top10.txt", std::ios::app);

                   // Verificar si el archivo se abrió correctamente
                   if (archivo.is_open()) {
                       // Escribir en el archivo
                       archivo << std::left << std::setw(20) << nombreStr << std::right << std::setw(10) << dineroDisponible << std::endl;

                       // Cerrar el archivo
                       archivo.close();

                       MessageBox::Show("El archivo ha sido guardado correctamente.", "Guardar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                   }
                   else {
                       MessageBox::Show("Error al abrir el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                       return;
                   }
               }
               else {
                   // El usuario canceló la entrada del nombre
                   return;
               }
           }


    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }

           void updateStock(Administrador* admin) {
               this->T_CantBinarios->Text = formato(admin->getCantidadBinario());
               this->T_CantHeap->Text = formato(admin->getCantidadHEAP());
               this->T_CantAvl->Text = formato(admin->getCantidadAVL());
               this->T_CantSplay->Text = formato(admin->getCantidadSPLAY());
               this->T_CantidadEspanta->Text = formato(admin->getCantidadEspanta());
               confBotones(admin);
           }


           System::String^ formato(int n) {
               std::string cadena = std::to_string(n);
               System::String^ texto = gcnew System::String(cadena.c_str());
               return texto;
           }

           void confBotones(Administrador* admin) {
               if (admin->getCantidadBinario() == 0) {
                   B_PlantarBinario->Enabled = false;
               }else {
                   B_PlantarBinario->Enabled = true;
               }

               if (admin->getCantidadAVL() == 0) {
                   B_PlantarAVL->Enabled = false;
               }else {
                   B_PlantarAVL->Enabled = true;
               }

               if (admin->getCantidadHEAP() == 0) {
                   B_PlantarHeap->Enabled = false;
               }else {
                   B_PlantarHeap->Enabled = true;
               }

               if (admin->getCantidadSPLAY() == 0) {
                   B_PlantarSplay->Enabled = false;
               }else {
                   B_PlantarSplay->Enabled = true;
               }

               //Que hayan 2 plantados o no hayan en stock
               if(admin->getCantidadEspantaPlantados() == 2 || admin->getCantidadEspanta() == 0){
                   B_Espanta->Enabled = false;
               }else {
                   B_Espanta->Enabled = true;
               }
           }


//------------------------------------------------------Metodos de los botones de PLANTAR---------------------------------------------------------------------

private: System::Void B_PlantarBinario_Click(System::Object^ sender, System::EventArgs^ e) {    
    admin->setCantidadBinario(-1);
    updateStock(admin);

    // Obtener las coordenadas del LabelGranjero
    int granjeroX = labelGranjero->Top;
    int granjeroY = labelGranjero->Left;

    // Verificar si la casilla está vacía (no tiene imagen y el color de fondo no es gris ni lime green)
    if (labelGranjero->BackColor != Color::Gray && labelGranjero->BackColor != Color::LimeGreen)
    {
        // Crear un nuevo label
        Label^ labelBinario = gcnew Label();
        labelBinario->BackgroundImage = Image::FromFile("recursos/arbol1.png");
        labelBinario->BackgroundImageLayout = ImageLayout::Stretch;
        labelBinario->Width = 50;
        labelBinario->Height = 50;
        labelBinario->Left = granjeroY;
        labelBinario->Top = granjeroX;

        // Agregar el nuevo label al formulario
        this->Controls->Add(labelBinario);
        labelBinario->BringToFront();
        

        //Crear el hilo
        Thread^ nuevoHiloBinario = gcnew Thread(gcnew System::Threading::ThreadStart(this, &AreaJuego::hiloBinario));
        nuevoHiloBinario->Start();
        //Agregar el hilo a la lista
        listaHilosBinarios->Add(nuevoHiloBinario);
        ActualizarInformacionNuevo("Arbol Binario", granjeroX, granjeroX);


    }
 

}
private: System::Void B_PlantarAVL_Click(System::Object^ sender, System::EventArgs^ e) {
    admin->setCantidadAVL(-1);
    updateStock(admin);


    // Obtener las coordenadas del LabelGranjero
    int granjeroX = labelGranjero->Top;
    int granjeroY = labelGranjero->Left;

    // Verificar si la casilla está vacía (no tiene imagen y el color de fondo no es gris ni lime green)
    if (labelGranjero->BackColor != Color::Gray && labelGranjero->BackColor != Color::LimeGreen)
    {
        // Crear un nuevo label
        Label^ labelAvl = gcnew Label();
        labelAvl->BackgroundImage = Image::FromFile("recursos/arbol41.png");
        labelAvl->BackgroundImageLayout = ImageLayout::Stretch;
        labelAvl->Width = 50;
        labelAvl->Height = 50;
        labelAvl->Left = granjeroY;
        labelAvl->Top = granjeroX;

        // Agregar el nuevo label al formulario
        this->Controls->Add(labelAvl);
        labelAvl->BringToFront();
        //ActualizarInformacionNuevo("Arbol AVL", granjeroX, granjeroX);
    }





}
private: System::Void B_PlantarSplay_Click(System::Object^ sender, System::EventArgs^ e) {
    admin->setCantidadSPLAY(-1);
    updateStock(admin);

    // Obtener las coordenadas del LabelGranjero
    int granjeroX = labelGranjero->Top;
    int granjeroY = labelGranjero->Left;

    // Verificar si la casilla está vacía (no tiene imagen y el color de fondo no es gris ni lime green)
    if (labelGranjero->BackColor != Color::Gray && labelGranjero->BackColor != Color::LimeGreen)
    {
        // Crear un nuevo label
        Label^ labelSplay = gcnew Label();
        labelSplay->BackgroundImage = Image::FromFile("recursos/arbol31.png");
        labelSplay->BackgroundImageLayout = ImageLayout::Stretch;
        labelSplay->Width = 50;
        labelSplay->Height = 50;
        labelSplay->Left = granjeroY;
        labelSplay->Top = granjeroX;

        // Agregar el nuevo label al formulario
        this->Controls->Add(labelSplay);
        labelSplay->BringToFront();
        //ActualizarInformacionNuevo("Arbol Splay", granjeroX, granjeroX);
    }




}
private: System::Void B_PlantarHeap_Click(System::Object^ sender, System::EventArgs^ e) {
    admin->setCantidadHEAP(-1);
    updateStock(admin);



    // Obtener las coordenadas del LabelGranjero
    int granjeroX = labelGranjero->Top;
    int granjeroY = labelGranjero->Left;

    // Verificar si la casilla está vacía (no tiene imagen y el color de fondo no es gris ni lime green)
    if (labelGranjero->BackColor != Color::Gray && labelGranjero->BackColor != Color::LimeGreen)
    {
        // Crear un nuevo label
        Label^ labelHeap = gcnew Label();
        labelHeap->BackgroundImage = Image::FromFile("recursos/arbol2.png");
        labelHeap->BackgroundImageLayout = ImageLayout::Stretch;
        labelHeap->Width = 50;
        labelHeap->Height = 50;
        labelHeap->Left = granjeroY;
        labelHeap->Top = granjeroX;

        // Agregar el nuevo label al formulario
        this->Controls->Add(labelHeap);
        labelHeap->BringToFront();
        //ActualizarInformacionNuevo("Heap", granjeroX, granjeroX);
    }

}
private: System::Void B_Espanta_Click_1(System::Object^ sender, System::EventArgs^ e) {
    admin->setCantidadEspanta(-1);
    updateStock(admin);
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void B_Salir_Click(System::Object^ sender, System::EventArgs^ e) {

    // Cerrar el programa actual
    Application::Exit();

    // Volver a ejecutar el programa
    System::Diagnostics::Process::Start(Application::ExecutablePath);                                                                             }
    };
};
