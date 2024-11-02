#pragma once
namespace TFAlgoritmos {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(void)
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
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ button1;

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
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Instrucciones::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Aqua;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 240);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1384, 192);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->Text = L"El doctor Charles Phillips se desplaza con las teclas direccionales y cuenta con 3 vidas,\n" 
				L"disparará jeringas contenedoras del compuesto con la barra espaciadora, hacia las\n" 
				L"bacterias de tuberculosis, perderá una vida al colisionar con dichas bacterias.\n" 
				L"Sin embargo, contará con el apoyo de las enfermeras, Choco, de las cuales puede generar\n" L"con la letra “E” hasta un máximo de dos, con la finalidad de apoyarlo.\n";
				L"Aquellas desarrollaron inmunidad a la enfermedad, por lo tanto, eliminarán a las bacterias al colisionar.\n";
			this->label1->Click += gcnew System::EventHandler(this, &Instrucciones::label1_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Lime;
			this->btnVolver->Location = System::Drawing::Point(1128, 648);
			this->btnVolver->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(200, 91);
			this->btnVolver->TabIndex = 1;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Instrucciones::btnVolver_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Goldenrod;
			this->button1->Location = System::Drawing::Point(331, 55);
			this->button1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(707, 118);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Bienvenidos a To Be Continued";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Instrucciones::btnBienvenidos_Click);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1411, 1033);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->Load += gcnew System::EventHandler(this, &Instrucciones::Instrucciones_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Instrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
		return;
	}
	private: System::Void btnBienvenidos_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
		return;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}