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
			imagen_malo1 = gcnew Bitmap("esqueleto.jpg");
			obj = new Heroe();
			malo1 = new Enemigo();
//			obj->setancho_alto(imagen);
			obj->setx(200);
			obj->sety(200);
			obj->setw(imagen->Width / 14);
			obj->seth(imagen->Height / 6);

			
			malo1->setx(700);
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
		Heroe*obj;
		Enemigo*malo1;
		Bitmap^imagen;
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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 485);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bc->Allocate(g, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		obj->mover(bg->Graphics, imagen);
		malo1->mover(bg->Graphics, imagen_malo1);
		bg->Render(g);
		delete bc; delete bg; delete g;
	}
	};
}
