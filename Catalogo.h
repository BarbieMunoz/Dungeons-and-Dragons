#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Monstruo.h"
#include "Arbol.h"
#include "NodoArbol.h"

using namespace std;

class Catalogo {
private:
	Arbol<Monstruo> arbolMonstruo;
	int sizeCatalogo;

public:
	Catalogo();
	~Catalogo();

	// método para cargar el csv al arbol. Se usa & para no tener copias y const para no modificar los datos.
	bool cargarCsv(const string& file);
	bool isEmpty(const string& variable);
	bool validInt(const string& variable);
	bool validDouble(const string& variable);

	int getSize(void);
	Monstruo* randomMonster(void);
};