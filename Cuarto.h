#pragma once
#include <string>
#include <iostream>
#include "Catalogo.h"

using namespace std;

class Cuarto {
private:
	Monstruo monstruo;

public:
	Cuarto();
	~Cuarto();

	// usa la referencia del catalogo para obtener el monstruo random
	bool insertMonster(Catalogo& catalogo);

	// apuntador? o referencia
	Monstruo getMonstruo(void);

	// funciones friend son funciones externas que tienen acceso a miembros privados
	friend ostream& operator<<(ostream& os, const Cuarto& cuarto);
};