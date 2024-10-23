#include <iostream>
#include <string>
#include <fstream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador() {
	name = "";
	hp = 100;
	race = setRace();
	mp = 100;

	// semilla para la función de establecer la raza
	srand(time(0));
}

// constructor parametrizado solamente con el nombre pues los demás valores ya son asignados
Jugador::Jugador(string name) {
	this->name = name;
	hp = 100;
	race = setRace();
	mp = 100;

	srand(time(0));
}

Jugador::~Jugador() {
	monstruosDerrotados.eliminarLista();
}

void Jugador::setName(string name) {
	this->name = name;
}

// la raza del jugador se seleccionará de manera aleatoria
string Jugador::setRace() {
	// número aleatorio de 0 a 2
	int valorAleatorio = rand() % 3;

	switch (valorAleatorio) {
	case 0:
		race = "elf";
		break;
	case 1:
		race = "human";
		break;
	case 2:
		race = "dwarf";
		break;
	defualt:
		cerr << "There was an error initializing the race." << endl;
		break;
	}

	return race;
}

void Jugador::addMonstruosDerrotados(Calabozo& calabozo, int numCuarto) {
	// se crea una lista doblemente ligada que va a almacenar la lista de los cuartos del calabozo y se refencia al objeto de la lista
	ListaD<Cuarto>& listaCalabozo = calabozo.getCalabozo();

	// se regresa el dato del nodo de la lista, porque lo que se quiere es el cuarto, no el nodoCuarto
	Cuarto* cuartoEncontrado;
	cuartoEncontrado = listaCalabozo.buscarNodo(numCuarto);

	// caso en el que se devolvió un nullptr
	if (!cuartoEncontrado) {
		return;
	}

	Monstruo monstruoEcontrado;
	monstruoEcontrado = cuartoEncontrado->getMonstruo();
	// si  hubo un error en encontrar el monstruo
	if (monstruoEcontrado.getAc() <= 0) {
		return;
	}

	cout << "Monstruo encontrado" << endl;
	// se agrega el monstruo en orden de acuerdo a sus nombres
	monstruosDerrotados.insertarOrden(monstruoEcontrado);
	cout << "Monstruo agregadoo" << endl;
}

string Jugador::getName() {
	return name;
}

int Jugador::getHp() {
	return hp;
}

string Jugador::getRace() {
	return race;
}

int Jugador::getMp() {
	return mp;
}

void Jugador::incrementHp(int increment) {
	int updatedHp = hp + increment;
	hp = updatedHp;
}

void Jugador::decrementMp(int decrement) {
	int updatedMp = mp - decrement;
	mp = updatedMp;
}

void Jugador::incrememtMp(int increment) {
	int updatedMp = mp + increment;
	// solo puede llegar hasta 999
	if (updatedMp > 999) {
		updatedMp = 999;
	}
	mp = updatedMp;
}

bool Jugador::printMonstruosDerrotados() {
	monstruosDerrotados.printLista();
	return true;
}

bool Jugador::printJugador() {
	cout << "\nPlayer Name: " << getName() << endl;
	cout << "Hit points: " << getHp() << endl;
	cout << "Player Race: " << getRace() << endl;
	cout << "Magic Points: " << getMp() << endl;
	cout << "Monsters defeated: " << endl;
	printMonstruosDerrotados();
	return true;
}