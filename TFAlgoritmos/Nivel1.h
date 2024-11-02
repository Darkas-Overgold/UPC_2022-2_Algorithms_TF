#pragma once
#include "Juego.h"
namespace TFAlgoritmos {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    /// <summary>
    /// Resumen de Nivel1
    /// </summary>
    public ref class Nivel1 : public System::Windows::Forms::Form {
    public:
        Nivel1(void) {
            InitializeComponent();
            srand(time(NULL));
            g = CreateGraphics();
            space = BufferedGraphicsManager::Current;
            buffer = space->Allocate(g, ClientRectangle);
            bmpDoctor = gcnew Bitmap("imagenes/Medic1.png");
            bmpEnfermera = gcnew Bitmap("imagenes/Enfermera.png");
            bmpEnemigo = gcnew Bitmap("imagenes/Enemigo.png");
            bmpJeringa = gcnew Bitmap("imagenes/Jeringa.png");
            bmpMap = gcnew Bitmap("imagenes/background1.png");
            objuego = new Juego(bmpDoctor->Width / 3, bmpDoctor->Height / 4, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, bmpEnfermera->Width / 3, bmpEnfermera->Height / 4,
                7, 1);
            //
            //TODO: agregar código de constructor aquí
            //
        }
    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~Nivel1() {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Timer^ timer1;
    protected:
    private: System::ComponentModel::IContainer^ components;
    private:
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        Graphics^ g;
        BufferedGraphicsContext^ space;
        BufferedGraphics^ buffer;
        Bitmap^ bmpDoctor;
        Bitmap^ bmpEnfermera;
        Bitmap^ bmpEnemigo;
        Bitmap^ bmpJeringa;
        Bitmap^ bmpMap;
        Juego* objuego;
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Tick += gcnew System::EventHandler(this, &Nivel1::timer1_Tick);
            // 
            // Nivel1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(900, 550);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"Inicio del fin";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Inicio del fin";
            this->Load += gcnew System::EventHandler(this, &Nivel1::Nivel1_Load);
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel1::Nivel1_KeyDown);
            this->ResumeLayout(false);
        }
#pragma endregion
        int cont = 0;
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        //Clear
        buffer->Graphics->Clear(Color::WhiteSmoke);
        //Collision
        //Move para el personaje se hará con teclas
        //Draw
        buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2.15, bmpMap->Height * 2.0);
        objuego->Dibujar_Todo(buffer->Graphics, bmpDoctor, bmpEnemigo, bmpEnfermera);
        objuego->mover_todo(buffer->Graphics, bmpJeringa);
        objuego->colision();
        objuego->Muestra_Contadores(buffer->Graphics);
        if (!objuego->ganar_perder()) {
            timer1->Enabled = false;
            if (objuego->devolver_cant_enemigo() == 0)
                MessageBox::Show("Felicidades, ganaste.");
            else
                MessageBox::Show("Es una pena, perdiste.");
            Close();
            return;
        }
        //Render
        buffer->Render(g);
    }
    private: System::Void Nivel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyCode == Keys::Space)
            objuego->generar_jeringa(bmpJeringa->Width, bmpJeringa->Height);
        objuego->Mover_Personaje(g, e->KeyCode); if (e->KeyCode == Keys::E && cont < 2) // Invoca una enfermera cada que presiona la tecla E, un máximo de dos veces
        {
            objuego->generar_enfermera(bmpEnfermera->Width / 3, bmpEnfermera->Height / 4);
            cont++;
        }
    }
    private: System::Void Nivel1_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}