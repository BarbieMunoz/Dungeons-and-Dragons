#include <iostream>
#include <string>
#include "Monstruo.h"

using namespace std;

Monstruo::Monstruo(string name, float cr, string type, string size, int ac, int hp, string align) {
	this->name = name;
	this->cr = cr;
	this->type = type;
	this->size = size;
	this->ac = ac;
	this->hp = hp;
	this->align = align;
}
	
Monstruo::~Monstruo() {}

Monstruo::Monstruo() {
	name = "";
	cr = 0.0;
	type = "";
	size = "";
	ac = 0;
	hp = 0;
	align = "";
}

int Monstruo::getAc() {
	return ac;
}

// se usa funci�n miembro porque solo necesita un parametro (en este caso el otro monstruo a comprar)
bool Monstruo::operator<(const Monstruo& monstruoLeft) const {
	// cambia la condici�n para que se verifique el nombre de los monstruos al insertarlos al arbol
	// seleccion� el nombre porque los par�metros como cr o ar tienen valores iguales
	// y mi arbol solo acepta insertar nodos diferentes
	return this->name < monstruoLeft.name;
}

bool Monstruo::operator>(const Monstruo& monstruoRight) const {
	// se verifica el nombre con el nombre monstruo derecho
	return this->name > monstruoRight.name;
}

// no es Monstruo:: porque es funci�n amiga por lo que es como una funci�n global
ostream& operator<<(ostream& os, const Monstruo& monstruo) {
	os << "Name: " << monstruo.name
		<< "\nChallenge rating: " << monstruo.cr
		<< "\nType: " << monstruo.type
		<< "\nSize: " << monstruo.size
		<< "\nArmor class: " << monstruo.ac
		<< "\nHit points: " << monstruo.hp
		<< "\nBehavior: " << monstruo.align
		<< endl;
	return os;
}