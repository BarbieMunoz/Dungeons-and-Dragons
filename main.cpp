#include <iostream>
#include <string>
#include "Monstruo.h"
#include "Catalogo.h"
#include "Cuarto.h"
#include "Calabozo.h"
#include "Jugador.h"

#define fileName "monsters.csv"

int main() {
	Catalogo obj1;
	
	if (!obj1.cargarCsv(fileName)) {
		std::cerr << "Error al cargar el archivo CSV." << std::endl;
		return 1;
	}

	//obj1.printCatalogo();
	//cout << obj1.getSize();

	/*
	Monstruo* monstruoRandom = obj1.randomMonster();
	cout << "\nMonstruo random:" << endl;
	monstruoRandom->printInfo();

	delete monstruoRandom;
	*/

	/*
	Cuarto cuarto1(obj1);
	Cuarto cuarto2(obj1);
	cout << *cuarto1.getMonstruo() << endl;
	cout << *cuarto2.getMonstruo() << endl;
	*/

	Calabozo calabozoNuevo;
	calabozoNuevo.createCalabozo(obj1);
	calabozoNuevo.printCalabozo();
	
	
	Jugador jugador1("Barbie");
	jugador1.incrementHp(10);
	jugador1.decrementMp(30);
	jugador1.printJugador();

	jugador1.addMonstruosDerrotados(calabozoNuevo, 1);
	jugador1.addMonstruosDerrotados(calabozoNuevo, 3);
	jugador1.addMonstruosDerrotados(calabozoNuevo, 7);

	jugador1.printMonstruosDerrotados();

	return 0;
}