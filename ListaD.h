#pragma once
#include <string>
#include <iostream>
#include "NodoLista.h"

using namespace std;
template <typename T>

class ListaD {
private:
	NodoLista<T>* head;
	int size = 0;

public:
	ListaD() : head(nullptr) {}

	~ListaD() {
		eliminarLista();
	}

	void printLista() {
		NodoLista<T>* tmp = head;
		// variable que ayuda a tener orden al imprimir los datos
		int contador = 1;

		// mientras no sea nullptr
		while (tmp) {
			cout << "\n" << contador << "." << endl;
			cout << tmp->dato << " ";
			tmp = tmp->next;
			contador++;
		}
		cout << "\n";
	}

	void eliminarLista() {
		while (head) {
			NodoLista<T>* current = head->next;
			delete head;
			head = current;
		}
	}

	bool insertarDatoPrincipio(T dato) {
		NodoLista<T>* newNodo = nullptr;
		newNodo = new(nothrow) NodoLista<T>;
		if (newNodo == nullptr) {
			return false;
		}
		newNodo->dato = dato;

		newNodo->next = head;
		if (head) {
			head->prev = newNodo;
		}
		head = newNodo;

		return true;
	}

	bool borrarUltimo() {
		NodoLista<T>* tmp = head;
		NodoLista<T>* anterior = nullptr;
		while (tmp->next != nullptr) {
			anterior = tmp;
			tmp = tmp->next;
		}

		anterior->next = nullptr;
		delete tmp;
		tmp = nullptr;
		return true;
	}

	bool insertarFinal(T dato) {
		NodoLista<T>* newNodo = nullptr;
		newNodo = new(nothrow) NodoLista<T>;
		if (newNodo == nullptr) {
			return false;
		}
		newNodo->dato = dato;

		if (!head) {
			head = newNodo;
			return true;
		}

		NodoLista<T>* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}

		tmp->next = newNodo;
		newNodo->prev = tmp;
		return true;
	}

	bool insertarOrden(T dato) {
		// se crea nuevo nodo
		NodoLista<T>* newNodo = nullptr;
		newNodo = new(nothrow) NodoLista<T>;
		if (newNodo == nullptr) {
			return false;
		}
		newNodo->dato = dato;

		// caso en el que la lista esté vacía
		if (!head) {
			head = newNodo;
			return true;
		}

		// caso en el que se debe insertar en el primer nodo
		if (dato < head->dato) {
			newNodo->next = head;
			head->prev = newNodo;
			head = newNodo;
			return true;
		}

		// se recorre la lista hasta encontrar el nodo mayor al dato
		NodoLista<T>* tmp = head;
		while (tmp->next != nullptr && dato > tmp->dato) {
			tmp = tmp->next;
		}

		// caso de inserción en último nodo
		if (tmp->next == nullptr && dato > tmp->dato) {
			tmp->next = newNodo;
			newNodo->prev = tmp;
			return true;
		}

		// se inserta en medio de la lista
		NodoLista<T>* anterior = tmp->prev;
		newNodo->next = tmp;
		newNodo->prev = anterior;
		tmp->prev = newNodo;
		anterior->next = newNodo;
		return true;
	}

	bool borrarDato(T dato) {
		if (dato == head->dato) {
			NodoLista<T>* tmp = head;
			head = tmp->next;
			delete tmp;
			tmp = nullptr;

			return true;
		}

		NodoLista<T>* current = head;
		while (current) {
			NodoLista<T>* eliminar = current->next;
			if (eliminar != nullptr && dato != eliminar->dato) {
				current = eliminar;
			}
			else if (eliminar == nullptr) {
				return false;
			}
			else {
				current->next = eliminar->next;
				eliminar->prev = current;
				delete eliminar;
				eliminar = nullptr;
				return true;
			}
		}
		return false;
	}
	bool borrarInicio() {
		NodoLista<T>* tmp = head;
		head = tmp->next;
		delete tmp;
		tmp = nullptr;

		return true;
	}

	bool borrarTodosDatosEspecifico(T dato) {
		NodoLista<T>* current = head;
		while (current) {
			NodoLista<T>* tmp = current->next;
			if (dato == current->dato) {
				NodoLista<T>* pasado = current->prev;
				pasado->next = tmp;
				tmp->prev = pasado;
				delete current;
				current = nullptr;
			}
			else if (dato == current->dato && tmp == nullptr) {
				NodoLista<T>* pasado = current->prev;
				pasado->next = nullptr;
				delete current;
				current = nullptr;
				return true;
			}
			else if (tmp == nullptr) {
				return true;
			}
			current = tmp;
		}
		return true;
	}

	int getSize() {
		return size;
	}

	// regresa el dato del nodo en lugar del nodo
	T* buscarNodo(int indice) {
		// caso en el que no hay nada en la lista
		if (!head) {
			return nullptr;
		}

		int contador = 1;
		NodoLista<T>* tmp = head;
		while (tmp != nullptr && contador != indice) {
			tmp = tmp->next;
			contador++;
		}

		// caso en el que el indice era mayor al size
		if (!tmp) {
			return nullptr;
		}

		// se devuelve la referencia del dato del tmp
		return &tmp->dato;
	}
};