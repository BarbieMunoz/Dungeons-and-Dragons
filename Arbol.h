#pragma once
#include <string>
#include <iostream>
#include "NodoArbol.h"

using namespace std;
template <typename T>

class Arbol {
private:
	NodoArbol<T>* raiz;

	bool insertarRecursivo(NodoArbol<T>*& nodo, T dato) {
		if (nodo == nullptr) {
			nodo = new(nothrow) NodoArbol<T>(dato);
			if (!nodo) {
				return false;
			}
			return true;
		}

		if (dato < nodo->dato) {
			return insertarRecursivo(nodo->left, dato);
		}

		if (dato > nodo->dato) {
			return insertarRecursivo(nodo->right, dato);
		}
		return false;
	}

	bool buscarRecursivo(NodoArbol<T>* nodo, T dato) {
		if (!nodo) {
			return false;
		}

		if (dato < nodo->dato) {
			return buscarRecursivo(nodo->left, dato);
		}
		if (dato > nodo->dato) {
			return buscarRecursivo(nodo->right, dato);
		}
		return true;
	}

	bool eliminarRecursivo(NodoArbol<T>*& nodo) {
		if (!nodo) {
			return false;
		}

		eliminarRecursivo(nodo->left);
		eliminarRecursivo(nodo->right);
		delete nodo;
		nodo = nullptr;
		return true;
	}

	bool eliminarDatoRecursivo(NodoArbol<T>*& nodo, T dato) {
		if (!nodo) {
			return false;
		}
		if (dato < nodo->dato) {
			return eliminarDatoRecursivo(nodo->left, dato);
		}
		else if (dato > nodo->dato) {
			return eliminarDatoRecursivo(nodo->right, dato);
		}
		else {
			NodoArbol<T>* borrar = nodo;

			// no hijo izq, toma valor de derecho
			if (!nodo->left) {
				nodo = nodo->right;
			}
			else if (!nodo->right) {
				nodo = nodo->left;
			}
			// tiene dos hijos
			else {
				borrar = buscarCambio(nodo);
			}
			// hoja y 2
			delete borrar;
		}

		return true;
	}

	NodoArbol<T>* buscarCambio(NodoArbol<T>*& nodo) {
		NodoArbol<T>* tmp = nodo->left;
		NodoArbol<T>* parent = nodo;
		while (tmp->right != nullptr) {
			parent = tmp;
			tmp = tmp->right;
		}

		nodo->dato = tmp->dato;

		// caso solo un hijo
		if (parent == nodo) {
			parent->left = tmp->left;
		}
		else {
			// caso de que 4 tmp->left  ya es nullptr
			// tambien cambia valor 
			parent->right = tmp->left;
		}
		return tmp;
	}

	bool printOrdenRecursivo(NodoArbol<T>* nodo) {
		if (!nodo) {
			return false;
		}
		printOrdenRecursivo(nodo->left);
		cout << nodo->dato << " ";
		printOrdenRecursivo(nodo->right);

		return true;
	}

	bool printPreOrdenRecursivo(NodoArbol<T>* nodo) {
		if (!nodo) {
			return false;
		}

		cout << nodo->dato << " ";
		printPreOrdenRecursivo(nodo->left);
		printPreOrdenRecursivo(nodo->right);

		return true;
	}

	bool printPostOrdenRecursivo(NodoArbol<T>* nodo) {
		if (!nodo) {
			return false;
		}
		printPostOrdenRecursivo(nodo->left);
		printPostOrdenRecursivo(nodo->right);
		cout << nodo->dato << " ";

		return true;
	}

	NodoArbol<T>* recorrerArbolRecursivo(NodoArbol<T>* nodo, int posicion, int &contador) {
		if (!nodo) {
			return nullptr;
		}

		// recorre todo el lado izquierdo hasta nullptr y guarda los nodos
		NodoArbol<T>* resultadoIzquierdo = recorrerArbolRecursivo(nodo->left, posicion, contador);
		if (resultadoIzquierdo) {
			return resultadoIzquierdo;
		}

		// se empieza a sumar contador cuando se haya pasado todo el lado izquierdo
		contador++;

		if (posicion == contador) {
			return nodo;
		}
		
		// si no se cumpli� la posici�n con el contador, pasa al arbol derecho
		return recorrerArbolRecursivo(nodo->right, posicion, contador);
	}

public:
	Arbol(): raiz(nullptr) {}

	~Arbol() {
		eliminar();
	}


	bool insertar(T dato) {
		return insertarRecursivo(raiz, dato);
	}

	bool buscar(T dato) {
		return buscarRecursivo(raiz, dato);
	}

	bool eliminar() {
		return eliminarRecursivo(raiz);
	}

	bool eliminarDato(T dato) {
		return eliminarDatoRecursivo(raiz, dato);
	}

	bool printOrden() {
		return printOrdenRecursivo(raiz);
	}

	bool printPreOrden() {
		return printPreOrdenRecursivo(raiz);
	}

	bool printPostOrden() {
		return printPostOrdenRecursivo(raiz);
	}

	NodoArbol<T>* recorrerArbol(int posicion) {
		int contador = 0;
		return recorrerArbolRecursivo(raiz, posicion, contador);
	}
};