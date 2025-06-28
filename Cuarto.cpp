#include <iostream>
#include <string>
#include "Cuarto.h"

using namespace std;

Cuarto::Cuarto() {
}

Cuarto::~Cuarto() {
}

bool Cuarto::insertMonster(Catalogo& catalogo) {
	// caso en el que el cuarto ya ten�a un monstruo se verifica accediendo a su cr
	if (monstruo.getAc() > 0) {
		return false;
	}

	// se crea una copia para no modificar al monstruo del catalogo
	Monstruo* monstruoCatalogo = catalogo.randomMonster();

	// caso en el que monstruo no se haya creado bien
	if (!monstruoCatalogo) {
		return false;
	}

	// se realiza una copia del monstruo para evitar modificar los mosntruos del cat�logo
	monstruo = *monstruoCatalogo;

	return true;
}

Monstruo Cuarto::getMonstruo() {
	return monstruo;
}

// sobrecarga de operador << para imprimir el cuarto m�s el el monstruo desreferenciado
ostream& operator<<(ostream& os, const Cuarto& cuarto) {
	os << "Room with: " << "\n" << cuarto.monstruo;
	return os;
}