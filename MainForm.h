#pragma once
#include "Personaje.h"
#include "Mapas.h"
#include "Controlador.h"
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
			arrMalo = new Enemigo*[5];
			for (int i = 0; i < 5; i++) {
				arrMalo[i] = new Enemigo();
			}
		
			InitializeComponent();

			objControla = new Controlador();

			//
			objMapa = new Mapas();
			iterador = 0;
			//-------------------------------------------------------------------------

			mapa1 = new Mapas(1, 0, 0, 625, 384, 0, 0, "fondazo1_last.jpg", 11, false);
			mapa2 = new Mapas(2, 0, 0, 625, 384, 0, 0, "fondazo2_last.jpg", 35, false);
			mapa3 = new Mapas(3, 0, 0, 625, 384, 0, 0, "fondazo3_last.jpg", 15, false);
			mapa4 = new Mapas(4, 0, 0, 625, 384, 0, 0, "fondazo4_last.jpg", 23, false);
			mapa5 = new Mapas(5, 0, 0, 625, 384, 0, 0, "fondazo5_last.jpg", 15, false);
			//-------------------------------------------------------------------------

			imagen = gcnew Bitmap("heroe.jpg");//se tiene que corregir los sprites, no todos tienen el mismo ancho
			imagen_malo = gcnew Bitmap("esqueleto.png");
			imagen_malo2 = gcnew Bitmap("Orcos.png");
			game_over = gcnew Bitmap("Game_Over.png");
			objControla->getHeroe()->setx(150);
			objControla->getHeroe()->sety(315);
			objControla->getHeroe()->setw(imagen->Width / 14);
			objControla->getHeroe()->seth(imagen->Height / 6);
			objControla->getHeroe()->setFuerza(50);
			
			num_mapa = 1;
			
			objControla->setItem_Def(false);
			objControla->setDefendido(false);
		
			

			
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
		Controlador *objControla;
		
		Enemigo** arrMalo;
		Mapas* objMapa;

		int iterador;
		int num_mapa;
		Bitmap^imagen;
		Bitmap^imagen_malo;
		Bitmap^imagen_malo2;
		Bitmap^plantilla;
		Bitmap^game_over;
		
		
		bool dificultad = true;
		/////////////////////////////////////////////

		Mapas *mapa1;
		Mapas *mapa2;
		Mapas *mapa3;
		Mapas *mapa4;
		Mapas *mapa5;
	private: System::Windows::Forms::Button^  Atacar;

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ProgressBar^ Barra_Heroe;
	private: System::Windows::Forms::Button^      Defender;
	private: System::Windows::Forms::Button^      Inventario;
	private: System::Windows::Forms::Button^      Item_Vida;
	private: System::Windows::Forms::Button^      Item_Defensa;
	private: System::Windows::Forms::Button^      Regresar_btn;
	private: System::Windows::Forms::TextBox^     textBox1;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  mensaje;
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
				 this->mensaje = (gcnew System::Windows::Forms::TextBox());
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
				 // mensaje
				 // 
				 this->mensaje->Location = System::Drawing::Point(240, 52);
				 this->mensaje->Name = L"mensaje";
				 this->mensaje->Size = System::Drawing::Size(147, 20);
				 this->mensaje->TabIndex = 13;
				 this->mensaje->Visible = false;
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(625, 462);
				 this->Controls->Add(this->mensaje);
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
		Barra_Heroe->Increment(objControla->getHeroe()->getvida());
		progressBar1->Increment(100);
		
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bc->Allocate(g, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		if (dificultad) {
			arrMalo[iterador]->setFuerza(10);
		}
		else {
			arrMalo[iterador]->setFuerza(35);
		}

		switch (num_mapa) {
		case 1:
			plantilla = imagen_malo;
			mapa1->Mover(bg->Graphics);
			arrMalo[iterador]->setx(415);
			arrMalo[iterador]->sety(330);
			arrMalo[iterador]->setw(plantilla->Width / 6);
			arrMalo[iterador]->seth(plantilla->Height / 1);
			break;
		case 2:
			plantilla = imagen_malo2;
			mapa2->Mover(bg->Graphics);
			arrMalo[iterador]->setx(415);
			arrMalo[iterador]->sety(300);
			arrMalo[iterador]->setw(plantilla->Width / 13);
			arrMalo[iterador]->seth(plantilla->Height / 1);
			break;
		case 3:

			plantilla = imagen_malo;
			mapa3->Mover(bg->Graphics);
			arrMalo[iterador]->setx(415);
			arrMalo[iterador]->sety(330);
			arrMalo[iterador]->setw(plantilla->Width / 6);
			arrMalo[iterador]->seth(plantilla->Height / 1);
			break;
		case 4:
			plantilla = imagen_malo2;
			mapa4->Mover(bg->Graphics);
			arrMalo[iterador]->setx(415);
			arrMalo[iterador]->sety(330);
			arrMalo[iterador]->setw(plantilla->Width / 13);
			arrMalo[iterador]->seth(plantilla->Height / 1);
			break;
		case 5:
			plantilla = imagen_malo;
			mapa5->Mover(bg->Graphics);
			arrMalo[iterador]->setx(415);
			arrMalo[iterador]->sety(330);
			arrMalo[iterador]->setw(plantilla->Width / 6);
			arrMalo[iterador]->seth(plantilla->Height / 1);
			break;
		default:
			break;
		}
		
		if (objControla->getHeroe()->getvida() > 0) {
			objControla->Start(iterador, arrMalo, bg->Graphics, objControla->getHeroe(), imagen, plantilla, objControla->getDefendido(), objControla->getItem_Def(), Barra_Heroe, textBox2, pictureBox1);
		}
		else {
			bg->Graphics->DrawImage(game_over, 0,0, 625, 462);
			progressBar1->Visible = false;
			Barra_Heroe->Visible = false;
			Defender->Visible = false;
			Inventario->Visible = false;
			textBox1->Visible = false;
			textBox2->Visible = false;
			Atacar->Visible = false;
		}

		bg->Render(g);
		delete bc; delete bg; delete g;

	}
	private: System::Void Atacar_Click(System::Object^  sender, System::EventArgs^  e) {
		arrMalo[iterador]->setvida(arrMalo[iterador]->getvida() - objControla->getHeroe()->getFuerza());
		progressBar1->Increment(objControla->getHeroe()->getFuerza()*-1);
		textBox1->Text = (objControla->getHeroe()->getFuerza() * -1).ToString();
		objControla->setTurno(false);
	}
	private: System::Void progressBar1_Click_1(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void Barra_Heroe_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Defender_Click(System::Object^  sender, System::EventArgs^  e) {
	objControla->setTurno(false);
	objControla->setDefendido(true);
}
private: System::Void Inventario_Click(System::Object^  sender, System::EventArgs^  e) {
	Atacar->Visible = false; Defender->Visible = false; Inventario->Visible = false;
	Item_Vida->Visible = true; Item_Defensa->Visible = true; Regresar_btn->Visible = true;
}
private: System::Void Regresar_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	Atacar->Visible = true; Defender->Visible = true; Inventario->Visible = true;
	Item_Vida->Visible = false; Item_Defensa->Visible = false; Regresar_btn->Visible = false;
	mensaje->Visible = false;
}


//----------------------------------------ITEM VIDA----------------------------------------//

private: System::Void Item_Vida_Click(System::Object^  sender, System::EventArgs^  e) {
	if (objControla->getCont_item_Vida() > 0) {
		objControla->getHeroe()->setvida(objControla->getHeroe()->getvida() + 50);
		Barra_Heroe->Increment(50);
		textBox2->Text = "+50";
		objControla->setCont_item_Vida(objControla->getCont_item_Vida() - 1);
		
	}
	else {
		mensaje->Visible = true;
		mensaje->Text = "Tienes 0 item vida";
	}
	Atacar->Visible = true; Defender->Visible = true; Inventario->Visible = true;
	Item_Vida->Visible = false; Item_Defensa->Visible = false; Regresar_btn->Visible = false;
}


//----------------------------------------ITEM DEFENSA----------------------------------------//
private: System::Void Item_Defensa_Click(System::Object^  sender, System::EventArgs^  e) {
	if (objControla->getCont_item_Defendido() > 0) {
		objControla->setItem_Def(true);
		/*objControla->setTurno(false);*/

		objControla->setCont_item_Defendido(objControla->getCont_item_Defendido() - 1);
	}
	else {
		mensaje->Visible = true;
		mensaje->Text = "Tienes 0 item defensa";
	}
	
	Atacar->Visible = true; Defender->Visible = true; Inventario->Visible = true;
	Item_Vida->Visible = false; Item_Defensa->Visible = false; Regresar_btn->Visible = false;
}
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Pasar a siguiente iterador
		/*objMapa->set_nromapa(objMapa->get_nro_mapa() + 1);*/
	
		num_mapa++;
		iterador++;
		pictureBox1->Visible = false;
		objControla->setTurno(true);
		progressBar1->Increment(100);
		mensaje->Visible = false;
		if (num_mapa % 2 == 0) {
			objControla->setCont_item_Vida(objControla->getCont_item_Vida() + 1);
		}
		else {
			objControla->setCont_item_Defendido(objControla->getCont_item_Defendido() + 1);
		}
}
};
}
