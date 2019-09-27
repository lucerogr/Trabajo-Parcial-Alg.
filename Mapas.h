#pragma once
#include <string.h>

using namespace System;
using namespace System::Drawing;

class Mapas {
private:
	int nro_mapa;
	int posx;
	int posy;
	int ancho;
	int alto;
	int indice_ancho;
	int indice_alto;
	char* nombre;
	int limite_indice;
	bool transparente;

public:
	//Mapas();
	Mapas(int pnro, int pposx, int pposy, int pancho, int palto, int pindice_ancho,int pindice_alto,char* pnombre, int plimite ,bool ptrans);
	int get_nro_mapa();
	void Mostrar(Graphics ^gr);
	void Mover(Graphics^gr);
	~Mapas();
};

Mapas::Mapas(int pnro, int pposx, int pposy, int pancho, int palto, int pindice_ancho, int pindice_alto, char* pnombre, int plimite, bool ptrans) {
	nro_mapa = pnro;
	posx = pposx;
	posy = pposy;
	ancho = pancho;
	alto = palto;
	indice_ancho = pindice_ancho;
	indice_alto = pindice_alto;
	nombre = new char[100];
	strcpy(nombre, pnombre);
	limite_indice = plimite;
	transparente = ptrans;
}
void Mapas::Mostrar(Graphics ^gr) {
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(nombre));
	Rectangle porcion = Rectangle(ancho*indice_ancho, alto*indice_alto, ancho, alto);
	Rectangle zoom = Rectangle(posx, posy, ancho, alto);
	if (transparente)
		bmp->MakeTransparent(bmp->GetPixel(33, 33));
	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	delete bmp;
}
void Mapas::Mover(Graphics ^gr) {
	indice_ancho++;
	if (indice_ancho > limite_indice)indice_ancho = 0;
	Mostrar(gr);
}
int Mapas::get_nro_mapa() {
	return nro_mapa;
}
Mapas::~Mapas() {}
