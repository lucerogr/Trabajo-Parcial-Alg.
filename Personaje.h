#pragma once
using namespace System::Drawing;
class Personaje {
protected:
	float x, y, xinicial, yinicial, ancho, alto, indice_ancho, indice_alto, vida;
public:
	Personaje() {
		xinicial = yinicial = 0;
		x = y = 0;
		indice_alto = indice_ancho = 0;
		//vida = 10;
	}
	~Personaje() {}
	float getx() { return x; }
	float gety() { return y; }
	float getvida() { return vida; }
	void setx(float nuevo) { x = nuevo; }
	void sety(float nuevo) { y = nuevo; }
	void setw(float nuevo) { ancho = nuevo; }
	void seth(float nuevo) { alto = nuevo; }
	void setvida(float nuevo) { vida = nuevo; }
	void mover(Graphics^g, Bitmap^imagen) {}

	void mostrar(Graphics ^g, Bitmap^imagen) {
		Rectangle porcion = Rectangle(indice_ancho*ancho, indice_alto*alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(imagen, zoom, porcion, GraphicsUnit::Pixel);
	}
	
};
class Heroe : public Personaje {
private:
public: 
	Heroe():Personaje(){}
	~Heroe(){}
	void mover(Graphics^g, Bitmap^imagen) {
		indice_alto = 5;
		indice_ancho++;
		if (indice_ancho > 13) indice_ancho = 0;
		mostrar(g, imagen);

	}
};
class Enemigo : public Personaje {
private:
	int dx;
public:
	Enemigo():Personaje(){
		dx = -5;
	}
	~Enemigo(){}
	void mover(Graphics^g, Bitmap^imagen) {
		indice_alto = 5;
		indice_ancho++;
		if (indice_ancho > 5) indice_ancho = 0;
		x += dx;
		mostrar(g, imagen);
	}
};
