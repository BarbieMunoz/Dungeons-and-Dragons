#pragma once
#include <string>
#include <iostream>
#include "Cuarto.h"
#include "Grafo.h"

using namespace std;

class Calabozo {
private:
	Grafo<Cuarto> grafoCuartos;

public:
	Calabozo();
	~Calabozo();

	// crea el calabozo usando el cat�logo de monstruos
	bool createCalabozo(Catalogo& catalogo, const string& file);
	bool printCalabozo(void);

	Grafo<Cuarto>& getCalabozo(void);
};