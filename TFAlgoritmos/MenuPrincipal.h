#pragma once
#include "Creditos.h"
#include "Instrucciones.h"
#include "Nivel1.h"
#include "Nivel2.h"
namespace TFAlgoritmos {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnJuego01;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::Button^ btnInstrucciones;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnJuego01 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::SystemColors::Info;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(918, 692);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(200, 55);
			this->btnCreditos->TabIndex = 0;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCreditos_Click);
			// 
			// btnJuego01
			// 
			this->btnJuego01->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnJuego01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnJuego01->ForeColor = System::Drawing::Color::Blue;
			this->btnJuego01->Location = System::Drawing::Point(281, 577);
			this->btnJuego01->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnJuego01->Name = L"btnJuego01";
			this->btnJuego01->Size = System::Drawing::Size(289, 55);
			this->btnJuego01->TabIndex = 1;
			this->btnJuego01->Text = L"Inicio del fin";
			this->btnJuego01->UseVisualStyleBackColor = false;
			this->btnJuego01->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnJuego01_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(413, 142);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(491, 69);
			this->label1->TabIndex = 2;
			this->label1->Text = L"To Be Continued";
			this->label1->Click += gcnew System::EventHandler(this, &MenuPrincipal::label1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::Color::Red;
			this->btnNivel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnNivel2->ForeColor = System::Drawing::Color::SpringGreen;
			this->btnNivel2->Location = System::Drawing::Point(236, 692);
			this->btnNivel2->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(399, 55);
			this->btnNivel2->TabIndex = 3;
			this->btnNivel2->Text = L"Pesadilla contrarreloj";
			this->btnNivel2->UseVisualStyleBackColor = false;
			//this->btnNivel2->Visible = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnJuego2_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(897, 577);
			this->btnInstrucciones->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(236, 55);
			this->btnInstrucciones->TabIndex = 4;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstrucciones_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1320, 963);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnJuego01);
			this->Controls->Add(this->btnCreditos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"Menú Principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menú Principal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ credi = gcnew Creditos();
		Hide();
		credi->ShowDialog();
		Show();
		delete credi;
	}
	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ credi = gcnew Instrucciones();
		Hide();
		credi->ShowDialog();
		Show();
		delete credi;
	}
	private: System::Void btnJuego01_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ nivel1 = gcnew Nivel1();
		Hide();
		nivel1->ShowDialog();
		Show();
		delete nivel1;
		//btnNivel2->Visible = false;
	}
	private: System::Void btnJuego2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ nivel2 = gcnew Nivel2();
		Hide();
		nivel2->ShowDialog();
		Show();
		delete nivel2;
		//btnNivel2->Visible = false;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}