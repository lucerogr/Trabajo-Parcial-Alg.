#pragma once
#include"Personaje.h"
#include"Mapas.h"

namespace pruebajuego12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			imagen_heroe = gcnew Bitmap("heroe.jpg");//se tiene que corregir los sprites, no todos tienen el mismo ancho
			imagen_malo = gcnew Bitmap("esqueleto.png");
			objHeroe = new Heroe();
			malo1 = new Enemigo();
			//-------------------------------------------------------------------------
			mapa1 = new Mapas(1, 0, 0, 625, 384, 0, 0, "fondazo1_last.jpg", 11, false);
			mapa2 = new Mapas(2, 0, 0, 625, 384, 0, 0, "fondazo2_last.jpg", 35, false);
			mapa3 = new Mapas(3, 0, 0, 625, 384, 0, 0, "fondazo3_last.jpg", 15, false);
			mapa4 = new Mapas(4, 0, 0, 625, 384, 0, 0, "fondazo4_last.jpg", 23, false);
			mapa5 = new Mapas(5, 0, 0, 625, 384, 0, 0, "fondazo5_last.jpg", 15, false);
			//-------------------------------------------------------------------------
			objHeroe->setx(200);
			objHeroe->sety(200);
			objHeroe->setw(imagen_heroe->Width / 14);
			objHeroe->seth(imagen_heroe->Height / 6);
			objHeroe->setFuerza(50);

			malo1->setx(500);
			malo1->sety(200);
			malo1->setw(imagen_malo->Width / 6);
			malo1->seth(imagen_malo->Height / 6);
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private:
		Heroe*objHeroe;
		Enemigo*malo1;
		Bitmap^imagen_heroe;
		Mapas *mapa1;
		Mapas *mapa2;
		Mapas *mapa3;
		Mapas *mapa4;
		Mapas *mapa5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
			 Bitmap^imagen_malo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(495, 303);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->Enabled = false;
			//this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 364);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bc->Allocate(g, this->ClientRectangle);

		bg->Graphics->Clear(Color::White);

		//mapa1->Mover(bg->Graphics);
		//mapa2->Mover(bg->Graphics);
		//mapa3->Mover(bg->Graphics);
		//mapa4->Mover(bg->Graphics);
		mapa5->Mover(bg->Graphics);

		objHeroe->mover(bg->Graphics, imagen_heroe);
		malo1->mover(bg->Graphics, imagen_malo);

		bg->Render(g);

		delete bc; delete bg; delete g;
	
	}
	//private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {}
	};
}
