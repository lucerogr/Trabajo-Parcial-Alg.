#ifndef __LISTA_H__
#define __LISTA_H__
#include "Nodo.h"

using namespace std;

template<class T>
class Lista{
private:
	Nodo<T> *inicio;
	T lon;
public:
	Lista();
	void AgregarInicio(T v);
	void AgregarFinal(T v);
	void AgregarPosicion(T pos, T val);
	void EliminarInicio();
	void EliminarFinal();
	void EliminarPosicion(T pos);
	void EliminarNodos();
	void BuscarElemento(T v);
	void ConcatenarListas(Lista<T> *list);
	T Longitud();
	T ObtenerPosicion(T pos);
};
template <class T>
Lista<T>::Lista(){
	inicio = NULL;
	lon = 0;
}
//----------------------------------
template<class T>
void Lista<T>::AgregarInicio(T v){
	Nodo<T> *nodo = new Nodo<T>(v);
	if (lon == 0) inicio = nodo; 
	else{
		nodo->siguiente = inicio;
		inicio->anterior = nodo;
	}
	lon++;
	inicio = nodo;
	nodo = NULL;
}
//-----------------------------------
template<class T>
void Lista<T>::AgregarFinal(T v) {
	if (lon == 0) AgregarInicio(v);
	else {
		Nodo<T> *nodo = new Nodo<T>(v);
		Nodo<T> *aux = inicio;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente = nodo;
		nodo->anterior = aux;
		lon++;
		aux=NULL;
	}

}

//----------------------------------
template<class T>
void Lista<T>::AgregarPosicion(T pos, T val) {
	if (pos == 1) AgregarInicio(val);
	else {
		Nodo<T> *aux = inicio;
		Nodo<T> *nodo = new Nodo<T>(val);
		int cont = 1;
		while (cont != pos-1) {
			aux = aux->siguiente;
			cont++;
		}
		nodo->siguiente = aux->siguiente;
		aux->siguiente->anterior = nodo;
		aux->siguiente = nodo;
		nodo->anterior = aux;
		lon++;
		aux = NULL;
	}
}
//---------------------------------------
template<class T>
void Lista<T>::EliminarInicio() {
	if (inicio == NULL) return;
	else if (lon == 1) {
		inicio = NULL;
		lon = 0;
	}
	else {
		inicio->siguiente->anterior = NULL;
		inicio = inicio->siguiente;
		lon--;
	}
}
//---------------------------------------
template<class T>
void Lista<T>::EliminarFinal() {
	if (lon == 1 || lon == 0) EliminarInicio();
	else {
		Nodo<T> *aux = inicio;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->anterior->siguiente = NULL;
		aux->anterior = NULL;
		aux = NULL;
		lon--;
	}
}
//---------------------------------------
template<class T>
void Lista<T>::EliminarPosicion(T pos){
	if (pos == 1) EliminarInicio();
	else if (pos < 1 || pos > lon) return; 
	else if (pos == lon) EliminarFinal();
	else{
		Nodo<T>*aux = inicio;
		T cont = 1;
		while (cont != pos) {
			aux = aux->siguiente;
			cont++;
		}
		aux->anterior->siguiente = aux->siguiente;
		aux->siguiente->anterior = aux->anterior;
		aux = NULL;
		lon--;
	}
}
//----------------------------------------
template<class T>
void Lista<T>::EliminarNodos() {
	inicio->BorrarNodos();
	inicio = NULL;
	lon = 0;
}
//-----------------------------------------
template<class T>
void Lista<T>::ConcatenarListas(Lista<T> *list) {
	Nodo<T> *aux = list->inicio;
	T cont = 0;
	T lon2 = list->Longitud();
	while (aux!=NULL) {
		AgregarFinal(aux->valor);
		aux = aux->siguiente;
		cont++;
	}
	aux = NULL;
}
//----------------------------------------
template<class T>
void Lista<T>::BuscarElemento(T v) {
	Nodo<T> *aux = inicio;
	T cont = 1;
	while (aux->valor != v && cont < lon) {
		aux = aux->siguiente;
		cont++;
	}
	if (aux->valor!=v)
		cout << "El elemento no se encuentra en la lista!" << endl;
	else
		cout << "El elemento " << v << " esta en la posicion: " << cont << endl;
}
//----------------------------------------
template<class T>
T Lista<T>::ObtenerPosicion(T pos) {
	if (pos == 1) return inicio->valor;
	else {
		Nodo<T> *aux = inicio;
		int cont = 1;
		while (cont != pos) {
			cont++;
			aux = aux->siguiente;
		}
		return aux->valor;
		aux = NULL;
	}
}
//-----------------------------------------
template<class T>
T Lista<T>::Longitud() {
	return lon;
}
#endif // !__LISTA_H__
//asdas
//ghjghjgh
