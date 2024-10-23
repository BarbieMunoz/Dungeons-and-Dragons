#include <iostream>
#include <string>
#include "Monstruo.h"
#include "Catalogo.h"
#include "Cuarto.h"
#include "Calabozo.h"
#include "Jugador.h"

using namespace std;

#define fileName "monsters.csv"

int main() {
	Catalogo catalogoNuevo;

	if (!catalogoNuevo.cargarCsv(fileName)) {
		cout << "There was an error while opening the csv file." << endl;
		return 1;
	}

	cout << "\nCreating your dungeon..." << endl;

	Calabozo calabozoNuevo;
	if (!calabozoNuevo.createCalabozo(catalogoNuevo)) {
		cout << "There was an error creating the dungeon." << endl;
	}
	calabozoNuevo.printCalabozo();

	cout << "Dungeon created succesfully." << endl;
	cout << "\n************************************ Starting your game ************************************" << endl;

	string name;
	cout << "\nInsert your player's name: ";
	cin >> name;

	Jugador jugador1(name);
	jugador1.printJugador();

	// se incrementa el mp solo para que se observe su funcionamiento
	cout << "\nYou have gained a bonus and your magic points have increased by 30!" << endl;
	jugador1.incrememtMp(30);
	jugador1.printJugador();

	cout << "\nYou just defeated the monster from the second and fifth room, congratulations!" << endl;

	jugador1.addMonstruosDerrotados(calabozoNuevo, 2);
	jugador1.addMonstruosDerrotados(calabozoNuevo, 5);

	cout << "Here are your results: " << endl;
	jugador1.printJugador();
	jugador1.printMonstruosDerrotados();

	return 0;
}