#pragma once
namespace TFAlgoritmos {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
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
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ btnVolver;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Aqua;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(237, 243);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(490, 96);
			this->label1->TabIndex = 0;
			this->label1->Text = L"-Chávez Antón Manuel Stephano\n-Cóndor Velásquez Angela Bibiana\n-Dextre Miguel Kev"
				L"in Cosner";
			this->label1->Click += gcnew System::EventHandler(this, &Creditos::label1_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Lime;
			this->btnVolver->Location = System::Drawing::Point(1119, 638);
			this->btnVolver->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(200, 91);
			this->btnVolver->TabIndex = 1;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Creditos::btnVolver_Click);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(1411, 1033);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"Creditos";
			this->Text = L"Créditos";
			this->Load += gcnew System::EventHandler(this, &Creditos::Creditos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Creditos_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
		return;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}