#include <iostream>
#include <string>
#include "Calabozo.h"

using namespace std;

Calabozo::Calabozo() {}

Calabozo::~Calabozo() {
	// elimina el grafo
	grafoCuartos.eraseGrafo();
}

bool Calabozo::createCalabozo(Catalogo& catalogo, const string& file) {
	// se lee el txt
	if (!grafoCuartos.cargarArchivo(file)) {
		return false;
	}

	for (int i = 0; i < grafoCuartos.getSize(); i++) {
		// se crea nuevo cuarto cada iteraci�n para tener diferentes
		Cuarto newCuarto;

		// caso en el que hubo un error en insertar el monstruo
		if (!newCuarto.insertMonster(catalogo)) {
			return false;
		}

		// se conecta el cuarto al v�rtice
		if (!grafoCuartos.asignaVertice(i, newCuarto)) {
			return false;
		}
	}
	return true;
}


// CAMBIAR
bool Calabozo::printCalabozo() {
	grafoCuartos.imprimir();
	return true;
}

// regresa la referencia al grafo para no hacer copias
Grafo<Cuarto>& Calabozo::getCalabozo() {
	return grafoCuartos;
}