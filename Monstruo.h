#pragma once
#include <string>
#include <iostream>

using namespace std;

class Monstruo {
private:
	string name;
	double cr;
	string type;
	string size;
	int ac;
	int hp;
	string align;

public:
	Monstruo(string name, double cr, string type, string size, int ac, int hp, string align);
	Monstruo();
	~Monstruo();

	int getAc(void);

	// sobrecarga de operadores para poder comparar en "insertar" del arbol
	bool operator<(const Monstruo& monstruoLeft) const;
	bool operator>(const Monstruo& monstruoRight) const;

	// funciones friend son funciones externas que tienen acceso a miembros privados
	friend ostream& operator<<(ostream& os, const Monstruo& monster);

	bool printMonstruo(void);
};