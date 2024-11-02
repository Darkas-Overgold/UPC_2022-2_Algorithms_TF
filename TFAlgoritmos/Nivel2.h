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
	/// Resumen de Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form {
	public:
		Nivel2(void) {
			InitializeComponent();
			srand(time(NULL));
			g = CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, ClientRectangle);
			bmpDoctor = gcnew Bitmap("imagenes/Medic1.png");
			bmpEnfermera = gcnew Bitmap("imagenes/Enfermera.png");
			bmpEnemigo = gcnew Bitmap("imagenes/Enemigo.png");
			bmpJeringa = gcnew Bitmap("imagenes/Jeringa.png");
			bmpMap = gcnew Bitmap("imagenes/background2.png");
			objuego = new Juego(bmpDoctor->Width / 3, bmpDoctor->Height / 4, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, bmpEnfermera->Width / 3, bmpEnfermera->Height / 4,
				8, 2);
			//
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel2() {
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
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
	private: System::Windows::Forms::Timer^ timer1;
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
			   this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
			   // 
			   // Nivel2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(900, 550);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Name = L"Pesadilla contrarreloj";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Pesadilla contrarreloj";
			   this->Load += gcnew System::EventHandler(this, &Nivel2::Nivel2_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			   this->ResumeLayout(false);
		   }
#pragma endregion
	private: System::Void Nivel2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)
			objuego->generar_jeringa(bmpJeringa->Width, bmpJeringa->Height);
		objuego->Mover_Personaje(g, e->KeyCode);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Collision
		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 3, bmpMap->Height * 3.5);
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
	};
}