#ifndef __NODO_H__
#define __NODO_H__
#include<iostream>
template<class T>
class Nodo {
	
public:
	T valor;
	Nodo<T> *siguiente;
	Nodo<T> *anterior;

	Nodo(T val = NULL, Nodo<T> *sig = NULL, Nodo<T> *ant = NULL) {
		valor = val;
		siguiente = sig;
		anterior = ant;
	}
};

#endif // !__NODO_H__
