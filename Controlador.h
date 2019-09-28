#pragma once
#include <string.h>
#include "MainForm.h"
using namespace System;
using namespace System::Drawing;

//#include "Personaje.h"
class Controlador {
protected:
	bool turno;
	Heroe*objHeroe;
	int cont_item_Vida;
	int cont_item_Defendido;
	bool defendido, item_Defendido;
public:
	Controlador() { turno = true; objHeroe = new Heroe();	cont_item_Vida = 0; cont_item_Defendido = 0; defendido = false; item_Defendido = false; }
	~Controlador() {}
	
	void Start(int it, Enemigo** arrMalo, Graphics^g, Heroe *objHeroe, Bitmap^heroeimg, Bitmap^maloimg, bool defendido, bool item_defendido, System::Windows::Forms::ProgressBar^ Barra_Heroe, System::Windows::Forms::TextBox^  textBox2, System::Windows::Forms::PictureBox^  pictureBox1){

		objHeroe->mover(g, heroeimg);
		
		if (arrMalo[it]->getvida() > 0) {
			arrMalo[it]->mover(g, maloimg);
		}

		if (arrMalo[it]->getvida() <= 0) {
			arrMalo[it]->~Enemigo();
			pictureBox1->Visible = true;
		}
		else {
			if (turno == false) {
				//-----------------------Comprueba si ha clickeado Boton defendido-------------------//
				if (getDefendido()) {
					if (getItem_Def() == true){
						objHeroe->setvida(objHeroe->getvida() - (arrMalo[it]->getFuerza() / 4));
						Barra_Heroe->Increment((arrMalo[it]->getFuerza() / 4) * -1);      
						textBox2->Text = ((arrMalo[it]->getFuerza() / 4)* -1).ToString();
						setItem_Def(false);
					}
					else {
						objHeroe->setvida(objHeroe->getvida() - (arrMalo[it]->getFuerza() / 2));
						Barra_Heroe->Increment((arrMalo[it]->getFuerza() / 2) * -1);
						textBox2->Text = ((arrMalo[it]->getFuerza() / 2) * -1).ToString();
					}
					setDefendido(false);
				}
				//-----------------------------------------------------------------------------------//
				else {
					objHeroe->setvida(objHeroe->getvida() - arrMalo[it]->getFuerza());
					Barra_Heroe->Increment(arrMalo[it]->getFuerza() * -1);
					textBox2->Text = (arrMalo[it]->getFuerza() * -1).ToString();

				}
				turno = true;
			}
		}
	}

	Heroe *getHeroe() { return objHeroe; }
	bool getTurno() { return turno; }
	void setTurno(bool _turno) { this->turno = _turno; }

	int getCont_item_Vida() { return cont_item_Vida; }
	void setCont_item_Vida(int _cont) { this->cont_item_Vida = _cont; }

	int getCont_item_Defendido() { return cont_item_Defendido; }
	void setCont_item_Defendido(int _cont) { this->cont_item_Defendido = _cont; }

	bool getDefendido() { return defendido; }
	void setDefendido(bool _defendido) { this->defendido = _defendido; }

	bool getItem_Def() { return item_Defendido; }
	void setItem_Def(bool _item_def) { this->item_Defendido = _item_def; }
};
