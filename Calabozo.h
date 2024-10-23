#pragma once
#include <string>
#include <iostream>
#include "Cuarto.h"
#include "ListaD.h"

using namespace std;

class Calabozo {
private:
	ListaD<Cuarto> listaCuartos;
	// constante del tama�o de la lista que siempre ser� 20
	const int SIZE_LISTA = 5;

public:
	Calabozo();
	~Calabozo();

	// crea el calabozo usando el cat�logo de monstruos
	bool createCalabozo(Catalogo& catalogo);
	bool printCalabozo(void);

	ListaD<Cuarto>& getCalabozo(void);
};