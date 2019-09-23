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

			turno = true;
			defendido = false;
			item_defendido = false;

			malo1->setx(500);
			malo1->sety(200);
			malo1->setw(imagen_malo1->Width / 6);
			malo1->seth(imagen_malo1->Height / 6);
			malo1->setFuerza(35);
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
		Bitmap^imagen_malo1;
		bool turno;
		bool defendido;
		bool item_defendido = false;
	private: System::Windows::Forms::Button^  Atacar;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  Barra_Heroe;
	private: System::Windows::Forms::Button^  Defender;
	private: System::Windows::Forms::Button^  Inventario;
	private: System::Windows::Forms::Button^  Item_Vida;
	private: System::Windows::Forms::Button^  Item_Defensa;
	private: System::Windows::Forms::Button^  Regresar_btn;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;



			
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
				 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				 this->Barra_Heroe = (gcnew System::Windows::Forms::ProgressBar());
				 this->Defender = (gcnew System::Windows::Forms::Button());
				 this->Inventario = (gcnew System::Windows::Forms::Button());
				 this->Item_Vida = (gcnew System::Windows::Forms::Button());
				 this->Item_Defensa = (gcnew System::Windows::Forms::Button());
				 this->Regresar_btn = (gcnew System::Windows::Forms::Button());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
				 // progressBar1
				 // 
				 this->progressBar1->ForeColor = System::Drawing::Color::Red;
				 this->progressBar1->Location = System::Drawing::Point(547, 49);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(173, 23);
				 this->progressBar1->TabIndex = 2;
				 this->progressBar1->Click += gcnew System::EventHandler(this, &MainForm::progressBar1_Click_1);
				 // 
				 // Barra_Heroe
				 // 
				 this->Barra_Heroe->ForeColor = System::Drawing::Color::Lime;
				 this->Barra_Heroe->Location = System::Drawing::Point(35, 49);
				 this->Barra_Heroe->Name = L"Barra_Heroe";
				 this->Barra_Heroe->Size = System::Drawing::Size(172, 23);
				 this->Barra_Heroe->TabIndex = 3;
				 this->Barra_Heroe->Click += gcnew System::EventHandler(this, &MainForm::Barra_Heroe_Click);
				 // 
				 // Defender
				 // 
				 this->Defender->Location = System::Drawing::Point(315, 248);
				 this->Defender->Name = L"Defender";
				 this->Defender->Size = System::Drawing::Size(104, 36);
				 this->Defender->TabIndex = 4;
				 this->Defender->Text = L"Defender";
				 this->Defender->UseVisualStyleBackColor = true;
				 this->Defender->Click += gcnew System::EventHandler(this, &MainForm::Defender_Click);
				 // 
				 // Inventario
				 // 
				 this->Inventario->Location = System::Drawing::Point(557, 248);
				 this->Inventario->Name = L"Inventario";
				 this->Inventario->Size = System::Drawing::Size(110, 36);
				 this->Inventario->TabIndex = 5;
				 this->Inventario->Text = L"Inventario";
				 this->Inventario->UseVisualStyleBackColor = true;
				 this->Inventario->Click += gcnew System::EventHandler(this, &MainForm::Inventario_Click);
				 // 
				 // Item_Vida
				 // 
				 this->Item_Vida->Location = System::Drawing::Point(170, 277);
				 this->Item_Vida->Name = L"Item_Vida";
				 this->Item_Vida->Size = System::Drawing::Size(96, 23);
				 this->Item_Vida->TabIndex = 6;
				 this->Item_Vida->Text = L"Item Vida";
				 this->Item_Vida->UseVisualStyleBackColor = true;
				 this->Item_Vida->Visible = false;
				 this->Item_Vida->Click += gcnew System::EventHandler(this, &MainForm::Item_Vida_Click);
				 // 
				 // Item_Defensa
				 // 
				 this->Item_Defensa->Location = System::Drawing::Point(441, 277);
				 this->Item_Defensa->Name = L"Item_Defensa";
				 this->Item_Defensa->Size = System::Drawing::Size(107, 23);
				 this->Item_Defensa->TabIndex = 7;
				 this->Item_Defensa->Text = L"Item_Defensa";
				 this->Item_Defensa->UseVisualStyleBackColor = true;
				 this->Item_Defensa->Visible = false;
				 this->Item_Defensa->Click += gcnew System::EventHandler(this, &MainForm::Item_Defensa_Click);
				 // 
				 // Regresar_btn
				 // 
				 this->Regresar_btn->Location = System::Drawing::Point(328, 300);
				 this->Regresar_btn->Name = L"Regresar_btn";
				 this->Regresar_btn->Size = System::Drawing::Size(75, 23);
				 this->Regresar_btn->TabIndex = 8;
				 this->Regresar_btn->Text = L"Regresar";
				 this->Regresar_btn->UseVisualStyleBackColor = true;
				 this->Regresar_btn->Visible = false;
				 this->Regresar_btn->Click += gcnew System::EventHandler(this, &MainForm::Regresar_btn_Click);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(643, 78);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(77, 20);
				 this->textBox1->TabIndex = 9;
				 this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged_1);
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(35, 78);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(70, 20);
				 this->textBox2->TabIndex = 10;
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(795, 335);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->Regresar_btn);
				 this->Controls->Add(this->Item_Defensa);
				 this->Controls->Add(this->Item_Vida);
				 this->Controls->Add(this->Inventario);
				 this->Controls->Add(this->Defender);
				 this->Controls->Add(this->Barra_Heroe);
				 this->Controls->Add(this->progressBar1);
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
		Barra_Heroe->Increment(objHeroe->getvida());
		progressBar1->Increment(100);
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bc->Allocate(g, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		if (objHeroe->getvida() > 0) {
			objHeroe->mover(bg->Graphics, imagen);
		}
		if (malo1->getvida() > 0) {
			malo1->mover(bg->Graphics, imagen_malo1);
		}


		if (malo1->getvida() > 0 && turno == false) {
			if (defendido == true) {
				if (item_defendido == true) {
					objHeroe->setvida(objHeroe->getvida() - (malo1->getFuerza() / 4));
					Barra_Heroe->Increment((malo1->getFuerza() / 4) * -1);
					textBox2->Text = ((malo1->getFuerza() / 4)* -1).ToString();
				}
				else {
					objHeroe->setvida(objHeroe->getvida() - (malo1->getFuerza() / 2));
					Barra_Heroe->Increment((malo1->getFuerza() / 2) * -1);
					textBox2->Text = ((malo1->getFuerza()/2) * -1).ToString();
				}
			}
			else {
				objHeroe->setvida(objHeroe->getvida() - malo1->getFuerza());
				Barra_Heroe->Increment(malo1->getFuerza() * -1);
				textBox2->Text = (malo1->getFuerza() * -1).ToString();
			}

			

			turno = true;
		}
		
		bg->Render(g);
		delete bc; delete bg; delete g;

		

	}
	private: System::Void Atacar_Click(System::Object^  sender, System::EventArgs^  e) {
		malo1->setvida(malo1->getvida() - objHeroe->getFuerza());
		progressBar1->Increment(objHeroe->getFuerza()*-1);
		textBox1->Text = (objHeroe->getFuerza() * -1).ToString();
		turno = false;
	}
	private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void progressBar1_Click_1(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void Barra_Heroe_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Defender_Click(System::Object^  sender, System::EventArgs^  e) {
	turno = false;
	defendido = true;
}
private: System::Void Inventario_Click(System::Object^  sender, System::EventArgs^  e) {
	Atacar->Visible = false; Defender->Visible = false; Inventario->Visible = false;
	Item_Vida->Visible = true; Item_Defensa->Visible = true; Regresar_btn->Visible = true;
}
private: System::Void Regresar_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	Atacar->Visible = true; Defender->Visible = true; Inventario->Visible = true;
	Item_Vida->Visible = false; Item_Defensa->Visible = false; Regresar_btn->Visible = false;
}
private: System::Void Item_Vida_Click(System::Object^  sender, System::EventArgs^  e) {
	objHeroe->setvida(objHeroe->getvida() + 50);
	Barra_Heroe->Increment(50);
	textBox2->Text = "+50";
}
private: System::Void Item_Defensa_Click(System::Object^  sender, System::EventArgs^  e) {
	item_defendido = true;
	turno = false;
}
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
