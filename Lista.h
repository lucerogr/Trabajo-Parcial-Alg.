#pragma once
#include <functional>
using namespace std;
typedef unsigned uint;

template<typename T>
class Lista {
	class Nodo;
	typedef function<int(T*, char*)> Comp;
	Nodo*ini;
	uint size;
	Comp comparar;
public:
	Lista() {
		ini = nullptr;  size = 0; comparar = [](T* a, char*b)->int {return strcmp(a->getcodigomapa(), b); };
	}

	~Lista(){}

	uint longitud() {
		return size;
	}
	bool esvacia() {
		return size == nullptr;
	}
	void agregarinicial(T* elem) {
		Nodo*nuevo = new Nodo(elem, ini);
		if (nuevo != nullptr) {
			ini = nuevo;
			size++;
		}
	}
	T* obtenerposicion(uint pos) {
		if (pos >= 0 && pos < size) {
			Nodo*aux = ini;
			for (int i = 0; i < pos; i++) {
				aux = aux->sig;
			}
			return aux->elem;
		}
		else {
			return nullptr;
		}
	}
	T* buscarmapa(char *numero) {
		Nodo* aux = ini;
		while (aux != nullptr) {
			if (comparar(aux->elem, numero) == 0) {
				return aux->elem;
			}
			aux = aux->sig;
		}
		return nullptr;
	}

};
template<typename T>
class Lista<T>::Nodo {
public:
	T* elem;
	Nodo* sig = nullptr;
	Nodo(T*elem, Nodo*sig) :elem(elem), sig(sig) {}
};
