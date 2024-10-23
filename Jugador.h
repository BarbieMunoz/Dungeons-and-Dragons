#pragma once
#include <string>
#include <iostream>
#include "ListaD.h"
#include "Monstruo.h"
#include "Calabozo.h"

using namespace std;

class Jugador {
private:
	ListaD<Monstruo> monstruosDerrotados;
	string name;
	int hp;
	string race;
	int mp;

public:
	Jugador();
	Jugador(string name);
	~Jugador();

	void setName(string name);
	string setRace(void);

	void addMonstruosDerrotados(Calabozo& calabozo, int numCuarto);

	string getName(void);
	int getHp(void);
	string getRace(void);
	int getMp(void);

	void incrementHp(int increment);
	void decrementMp(int decrement);
	void incrememtMp(int increment);

	bool printMonstruosDerrotados(void);
	bool printJugador(void);
};