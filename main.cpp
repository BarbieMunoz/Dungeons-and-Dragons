#include <iostream>
#include <string>
#include "Monstruo.h"
#include "Catalogo.h"
#include "Cuarto.h"
#include "Calabozo.h"
#include "Jugador.h"

using namespace std;

#define fileName "monsters.csv"
#define fileDungeon "dungeon.txt"

int main() {
	// se crea catalogo
	Catalogo catalogoNuevo;

	if (!catalogoNuevo.cargarCsv(fileName)) {
		cout << "There was an error while opening the csv file." << endl;
		return 1;
	}

	cout << "\nCreating your dungeon..." << endl;

	// se crea el calabozo
	Calabozo calabozoNuevo;

	if (!calabozoNuevo.createCalabozo(catalogoNuevo, fileDungeon)) {
		cout << "There was an error creating the dungeon." << endl;
		return 1;
	}
	calabozoNuevo.printCalabozo();

	cout << "\n\nDungeon created succesfully." << endl;

	// parte de "juego" solo para ver funcionamiento y simulacion
	cout << "\n************************************ Starting your game ************************************" << endl;

	string name;
	cout << "\nInsert your player's name: ";
	cin >> name;

	Jugador jugador1(name);
	jugador1.printJugador();

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