#pragma once
#include <string.h>
#include "MainForm.h"
using namespace System;
using namespace System::Drawing;
//#include "Personaje.h"
class Controlador {
protected:
public:
	Controlador() {}
	~Controlador() {}
	void Comprobar(Graphics^g, Heroe *objHeroe, Enemigo *malo1, Bitmap^heroeimg, Bitmap^maloimg, bool turno, bool defendido, bool item_defendido, System::Windows::Forms::ProgressBar^ Barra_Heroe, System::Windows::Forms::TextBox^  textBox2, System::Windows::Forms::PictureBox^  pictureBox1){
		if (objHeroe->getvida() > 0) {
			objHeroe->mover(g, heroeimg);
		}
		if (malo1->getvida() > 0) {
			malo1->mover(g, maloimg);
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
	}
};
