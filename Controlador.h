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
public:
	Controlador() { turno = true;	objHeroe = new Heroe();	}
	~Controlador() {}
	
	void Start(int it, bool dificultad, Enemigo** arrMalo, Graphics^g, Heroe *objHeroe, Bitmap^heroeimg, Bitmap^maloimg, bool defendido, bool item_defendido, System::Windows::Forms::ProgressBar^ Barra_Heroe, System::Windows::Forms::TextBox^  textBox2, System::Windows::Forms::PictureBox^  pictureBox1){

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
				if (defendido == true) {
					if (item_defendido == true) {
						objHeroe->setvida(objHeroe->getvida() - (arrMalo[it]->getFuerza() / 4));
						Barra_Heroe->Increment((arrMalo[it]->getFuerza() / 4) * -1);      
						textBox2->Text = ((arrMalo[it]->getFuerza() / 4)* -1).ToString();
					}
					else {
						objHeroe->setvida(objHeroe->getvida() - (arrMalo[it]->getFuerza() / 2));
						Barra_Heroe->Increment((arrMalo[it]->getFuerza() / 2) * -1);
						textBox2->Text = ((arrMalo[it]->getFuerza() / 2) * -1).ToString();
					}
				}
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
};
