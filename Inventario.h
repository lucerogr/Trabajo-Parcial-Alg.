#pragma once
#include "Personaje,h"
using namespace System::Drawing;
class Inventario {
protected:
  Heroe* objeto;
	int x, y, ancho, alto, indice_ancho, indice_alto;
  int itemvida, itemdaño;
public:
	Inventario() {
    objeto=new Heroe();
		x = y = 0;
		indice_alto = indice_ancho = 0;
	}
	~Inventario() {}
	int getx() { return x; }
	int gety() { return y; }
  int getitem_vida() {return itemvida;}
	int getitem_daño() { return itemdaño; }
	void setx(int nuevo) { x = nuevo; }
	void sety(int nuevo) { y = nuevo; }
	void setw(int nuevo) { ancho = nuevo; }
	void seth(int nuevo) { alto = nuevo; }
	void setitem_vida(int nuevo) { itemvida = nuevo; }
  void setitem_daño(int nuevo) {itemdaño = nuevo; }

	void mostrar(Graphics ^g, Bitmap^imagen) {//en el controlador se elije que arma se utiliza
		Rectangle porcion = Rectangle(indice_ancho*ancho, indice_alto*alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(imagen, zoom, porcion, GraphicsUnit::Pixel);
	}
  void mover(Graphics ^g, Bitmap^imagen){
    setx(objeto->getx());//o puede ser +5, para que el arma se encuentre en la "mano del heroe"
    sety(objeto->gety());
    mostrar(g, imagen);
  }
  bool escolision_Enemigo (Enemigo* malo){//en el controlador se llama a la funcion y si retorna true, la vida disminuye, etc
    Rectangle r1=Rectangle(malo->getx(), malo->gety(), malo->getw(), malo->geth());
    Rectangle r2=Rectangle(x, y, w, h);
    return r1.Intersectswith(r2);
  }
  
};
