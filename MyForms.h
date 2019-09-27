#pragma once
#include "Personaje.h"
#include "Mapas.h"
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
			num_mapa = 1;
			//-------------------------------------------------------------------------
			mapa1 = new Mapas(1, 0, 0, 625, 384, 0, 0, "fondazo1_last.jpg", 11, false);
			mapa2 = new Mapas(2, 0, 0, 625, 384, 0, 0, "fondazo2_last.jpg", 35, false);
			mapa3 = new Mapas(3, 0, 0, 625, 384, 0, 0, "fondazo3_last.jpg", 15, false);
			mapa4 = new Mapas(4, 0, 0, 625, 384, 0, 0, "fondazo4_last.jpg", 23, false);
			mapa5 = new Mapas(5, 0, 0, 625, 384, 0, 0, "fondazo5_last.jpg", 15, false);
			//-------------------------------------------------------------------------

			imagen = gcnew Bitmap("heroe.jpg");//se tiene que corregir los sprites, no todos tienen el mismo ancho
			imagen_malo1 = gcnew Bitmap("esqueleto.png");
			imagen_malo2 = gcnew Bitmap("Orcos.jpg");
			objHeroe = new Heroe();
			malo1 = new Enemigo();
			malo2 = new Enemigo();
			//			obj->setancho_alto(imagen);
			objHeroe->setx(150);
			objHeroe->sety(315);
			objHeroe->setw(imagen->Width / 14);
			objHeroe->seth(imagen->Height / 6);
			objHeroe->setFuerza(50);

			turno = true;
			defendido = false;
			item_defendido = false;

			malo1->setx(415);
			malo1->sety(330);
			malo1->setw(imagen_malo1->Width / 6);
			malo1->seth(imagen_malo1->Height / 6);
			malo1->setFuerza(35);

			malo2->setx(415);
			malo2->sety(330);
			malo2->setw(imagen_malo1->Width / 14);
			malo2->seth(imagen_malo1->Height / 1);
			malo2->setFuerza(35);
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
		Enemigo*malo2;
		Bitmap^imagen;
		Bitmap^imagen_malo1;
		Bitmap^imagen_malo2;
		bool turno;
		bool defendido;
		bool item_defendido = false;
		int num_mapa;
		/////////////////////////////////////////////

		Mapas *mapa1;
		Mapas *mapa2;
		Mapas *mapa3;
		Mapas *mapa4;
		Mapas *mapa5;
	private: System::Windows::Forms::Button^  Atacar;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  Barra_Heroe;
	private: System::Windows::Forms::Button^  Defender;
	private: System::Windows::Forms::Button^  Inventario;
	private: System::Windows::Forms::Button^  Item_Vida;
	private: System::Windows::Forms::Button^  Item_Defensa;
	private: System::Windows::Forms::Button^  Regresar_btn;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
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
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
				 // 
				 // Atacar
				 // 
				 this->Atacar->Location = System::Drawing::Point(12, 404);
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
				 this->progressBar1->Location = System::Drawing::Point(440, 49);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(173, 23);
				 this->progressBar1->TabIndex = 2;
				 this->progressBar1->Click += gcnew System::EventHandler(this, &MainForm::progressBar1_Click_1);
				 // 
				 // Barra_Heroe
				 // 
				 this->Barra_Heroe->ForeColor = System::Drawing::Color::Lime;
				 this->Barra_Heroe->Location = System::Drawing::Point(12, 49);
				 this->Barra_Heroe->Name = L"Barra_Heroe";
				 this->Barra_Heroe->Size = System::Drawing::Size(172, 23);
				 this->Barra_Heroe->TabIndex = 3;
				 this->Barra_Heroe->Click += gcnew System::EventHandler(this, &MainForm::Barra_Heroe_Click);
				 // 
				 // Defender
				 // 
				 this->Defender->Location = System::Drawing::Point(267, 404);
				 this->Defender->Name = L"Defender";
				 this->Defender->Size = System::Drawing::Size(104, 36);
				 this->Defender->TabIndex = 4;
				 this->Defender->Text = L"Defender";
				 this->Defender->UseVisualStyleBackColor = true;
				 this->Defender->Click += gcnew System::EventHandler(this, &MainForm::Defender_Click);
				 // 
				 // Inventario
				 // 
				 this->Inventario->Location = System::Drawing::Point(503, 404);
				 this->Inventario->Name = L"Inventario";
				 this->Inventario->Size = System::Drawing::Size(110, 36);
				 this->Inventario->TabIndex = 5;
				 this->Inventario->Text = L"Inventario";
				 this->Inventario->UseVisualStyleBackColor = true;
				 this->Inventario->Click += gcnew System::EventHandler(this, &MainForm::Inventario_Click);
				 // 
				 // Item_Vida
				 // 
				 this->Item_Vida->Location = System::Drawing::Point(165, 411);
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
				 this->Item_Defensa->Location = System::Drawing::Point(377, 411);
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
				 this->Regresar_btn->Location = System::Drawing::Point(521, 411);
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
				 this->textBox1->Location = System::Drawing::Point(558, 78);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(55, 20);
				 this->textBox1->TabIndex = 9;
				 this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged_1);
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(12, 78);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(41, 20);
				 this->textBox2->TabIndex = 10;
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(530, 141);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(83, 64);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox1->TabIndex = 12;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Visible = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(625, 462);
				 this->Controls->Add(this->pictureBox1);
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
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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

		//mapa2->Mover(bg->Graphics);
		//mapa3->Mover(bg->Graphics);
		//mapa4->Mover(bg->Graphics);
		//mapa5->Mover(bg->Graphics);
		switch (num_mapa) {
		case 1:
			mapa1->Mover(bg->Graphics);
			break;
		case 2:
			
			mapa2->Mover(bg->Graphics);
			break;
		case 3:
			mapa3->Mover(bg->Graphics);
			break;
		case 4:
			mapa4->Mover(bg->Graphics);
			break;
		case 5:
			mapa5->Mover(bg->Graphics);
			break;
		default:
			break;
		}
		

		if (objHeroe->getvida() > 0) {
			objHeroe->mover(bg->Graphics, imagen);
		}
		if (malo1->getvida() > 0) {
			malo1->mover(bg->Graphics, imagen_malo1);
		}
		
		if (malo1->getvida() <= 0) {
			malo1->~Enemigo();
			pictureBox1->Visible = true;
		}
		else {
			if (turno == false) {
				if (defendido == true) {
					if (item_defendido == true) {
						objHeroe->setvida(objHeroe->getvida() - (malo1->getFuerza() / 4));
						Barra_Heroe->Increment((malo1->getFuerza() / 4) * -1);
						textBox2->Text = ((malo1->getFuerza() / 4)* -1).ToString();
					}
					else {
						objHeroe->setvida(objHeroe->getvida() - (malo1->getFuerza() / 2));
						Barra_Heroe->Increment((malo1->getFuerza() / 2) * -1);
						textBox2->Text = ((malo1->getFuerza() / 2) * -1).ToString();
					}
				}
				else {
					objHeroe->setvida(objHeroe->getvida() - malo1->getFuerza());
					Barra_Heroe->Increment(malo1->getFuerza() * -1);
					textBox2->Text = (malo1->getFuerza() * -1).ToString();
				}
				turno = true;
			}
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
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	//Pasar a siguiente nivel
	num_mapa++;

}
};
}
