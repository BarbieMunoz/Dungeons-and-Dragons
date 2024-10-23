#include <iostream>
#include <string>
#include "Calabozo.h"

using namespace std;

Calabozo::Calabozo() {}

Calabozo::~Calabozo() {
	// elimina la lista en el momento en el que el destructor se ejecuta para evitar memory leaks
	listaCuartos.eliminarLista();
}

bool Calabozo::createCalabozo(Catalogo& catalogo) {
	// caso en el que el calabozo ya estaba lleno
	if (listaCuartos.getSize() >= SIZE_LISTA) {
		return false;
	}
	for (int i = 0; i < SIZE_LISTA; i++) {
		// se crea nuevo cuarto cada iteración para tener diferentes
		Cuarto newCuarto;

		// caso en el que hubo un error en insertar el monstruo
		// condición en la que revisa si el método de insertar el monstruo es true o false
		if (!newCuarto.insertMonster(catalogo)) {
			return false;
		}

		// se inserta al calabozo
		listaCuartos.insertarDatoPrincipio(newCuarto);
	}
	return true;
}

bool Calabozo::printCalabozo() {
	// se utiliza el método de la lista doblemente ligada para imprimir los datos
	// con la sobrecarga del operador << hace que se pueda imprimir el cuarto con su monstruo
	listaCuartos.printLista();
	return true;
}

// regresa la referencia a la lista para no hace copias
ListaD<Cuarto>& Calabozo::getCalabozo() {
	return listaCuartos;
}