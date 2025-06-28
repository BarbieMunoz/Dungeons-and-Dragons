#pragma once
#include "ListaD.h"

template <typename T>

class Vertice {
public:
	// tiene la lista de los ids
	ListaD<int> aristas;
	int size;
	T dato;
	bool visitado;

	Vertice(): size(0), dato(T()), visitado(false) {}
	Vertice(T dato): size(0), dato(dato), visitado(false) {}
	~Vertice() {}

	bool agregarVertice(int& vertice) {
		// si ya existe
		if (aristas.buscarApuntadorNodo(vertice)) {
			return false;
		}

		if (!aristas.insertarDatoPrincipio(vertice)) {
			return false;
		}

		setSize();
		return true;
	}

	bool eliminarVertice(int& vertice) {
		// no existe
		if (!aristas.buscarApuntadorNodo(vertice)) {
			return false;
		}

		if (!aristas.borrarDato(vertice)) {
			return false;
		}

		setSize();
		return true;
	}

	void setSize(void) {
		size = aristas.getSize();
	}

	void print(void) {
		aristas.printLista();
	}
};