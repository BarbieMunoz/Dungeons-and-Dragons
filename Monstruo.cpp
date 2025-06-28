#include <iostream>
#include <string>
#include "Monstruo.h"

using namespace std;

Monstruo::Monstruo(string name, double cr, string type, string size, int ac, int hp, string align) {
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

string Monstruo::getName() {
	return name;
}

// se usa funci�n miembro porque solo necesita un parametro (en este caso el otro monstruo a comprar)
bool Monstruo::operator<(const Monstruo& monstruoLeft) const {
	// cambia la condici�n para que se verifique el nombre de los monstruos al insertarlos
	return this->name < monstruoLeft.name;
}

bool Monstruo::operator>(const Monstruo& monstruoRight) const {
	// se verifica el nombre con el nombre monstruo derecho
	return this->name > monstruoRight.name;
}

bool Monstruo::operator==(const Monstruo& monstruo) const {
	// true si son iguales
	return  name == monstruo.name;
}

bool Monstruo::operator!=(const Monstruo& monstruo) const {
	// se niega la sobrecarga de ==
	return !(*this == monstruo);
}

// no es Monstruo:: porque es funci�n amiga por lo que es como una funci�n global
ostream& operator<<(ostream& os, const Monstruo& monstruo) {
	os << "Name: " << monstruo.name
		<< "\nChallenge rating: " << monstruo.cr
		<< endl;
	return os;
}

bool Monstruo::printMonstruo() {
	cout << "\nName: " << name << endl;
	cout << "Challenge rating: " << cr << endl;
	cout << "Type: " << type << endl;
	cout << "Size: " << size << endl;
	cout << "Armor class: " << ac << endl;
	cout << "Hit points: " << hp << endl;
	cout << "Behavior: " << align << endl;
	return true;
}