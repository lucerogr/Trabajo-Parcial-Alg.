#pragma once
#include "Personaje.h"
namespace parcial1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí

			imagen = gcnew Bitmap("heroe.jpg");//se tiene que corregir los sprites, no todos tienen el mismo ancho
			imagen_malo1 = gcnew Bitmap("esqueleto.png");
			objHeroe = new Heroe();
			malo1 = new Enemigo();
			//			obj->setancho_alto(imagen);
			objHeroe->setx(200);
			objHeroe->sety(200);
			objHeroe->setw(imagen->Width / 14);
			objHeroe->seth(imagen->Height / 6);
			objHeroe->setFuerza(50);

			malo1->setx(500);
			malo1->sety(200);
			malo1->setw(imagen_malo1->Width / 6);
			malo1->seth(imagen_malo1->Height / 6);

			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		Heroe*objHeroe;
		Enemigo*malo1;
		Bitmap^imagen;
	private: System::Windows::Forms::Button^  Atacar;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;


			 Bitmap^imagen_malo1;
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Atacar = (gcnew System::Windows::Forms::Button());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
				 // 
				 // Atacar
				 // 
				 this->Atacar->Location = System::Drawing::Point(35, 248);
				 this->Atacar->Name = L"Atacar";
				 this->Atacar->Size = System::Drawing::Size(93, 36);
				 this->Atacar->TabIndex = 0;
				 this->Atacar->Text = L"Atacar";
				 this->Atacar->UseVisualStyleBackColor = true;
				 this->Atacar->Click += gcnew System::EventHandler(this, &MainForm::Atacar_Click);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(567, 12);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(100, 20);
				 this->textBox1->TabIndex = 1;
				 this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
				 // 
				 // progressBar1
				 // 
				 this->progressBar1->Location = System::Drawing::Point(567, 49);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(100, 23);
				 this->progressBar1->TabIndex = 2;
				 this->progressBar1->Click += gcnew System::EventHandler(this, &MainForm::progressBar1_Click_1);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(795, 335);
				 this->Controls->Add(this->progressBar1);
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->Atacar);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				 this->Name = L"MainForm";
				 this->Text = L"MainForm";
				 this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		textBox1->Text = malo1->getvida().ToString();

		progressBar1->Increment(100);
		//
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bc->Allocate(g, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		objHeroe->mover(bg->Graphics, imagen);
		malo1->mover(bg->Graphics, imagen_malo1);
		bg->Render(g);
		delete bc; delete bg; delete g;
	}
	private: System::Void Atacar_Click(System::Object^  sender, System::EventArgs^  e) {
		malo1->setvida(malo1->getvida() - objHeroe->getFuerza());
		progressBar1->Increment(-50);
		textBox1->Text = malo1->getvida().ToString();

	}
	private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void progressBar1_Click_1(System::Object^  sender, System::EventArgs^  e) {

	}
};
}
