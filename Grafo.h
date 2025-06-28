#pragma once
#include "Vertice.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
template <typename T>

class Grafo {
private:
	Vertice<T>* grafo;
	int size;

public:
	Grafo() : grafo(nullptr), size(0) {}
	~Grafo() {
		eraseGrafo();
	}

	bool eraseGrafo(void) {
		if (grafo) {
			delete[] grafo;
			grafo = nullptr;
			size = 0;
			return true;
		}
		return false;
	}

	bool createGrafo(int size) {
		if (grafo || !size) {
			return false;
		}

		// se crea el arrreglo
		grafo = new(nothrow) Vertice<T>[size];
		if (!grafo) {
			return false;
		}

		// size del grafo
		this->size = size;
		return true;
	}

	// se asigna un dato al vertice
	bool asignaVertice(int indice, T dato) {
		// se pasa del limite
		if (indice >= size) {
			return false;
		}
		grafo[indice].dato = dato;
		return true;
	}

	bool conectar(int verticeUno, int verticeDos) {
		if (!grafo || !size) {
			return false;
		}

		// si no coinciden con el size
		if (verticeUno >= size || verticeDos >= size)
			return false;

		if (!grafo[verticeUno].agregarVertice(verticeDos)) {
			return false;
		}
		return true;
	}

	bool desconectar(int verticeUno, int verticeDos) {
		if (!grafo || !size) {
			return false;
		}

		// si no coinciden con el size
		if (verticeUno >= size || verticeDos >= size)
			return false;

		if (!grafo[verticeUno].eliminarVertice(verticeDos)) {
			return false;
		}
		return true;
	}


	bool guardarArchivo(void) {
		if (!size) {
			return false;
		}

		ofstream file("grafo.txt");
		if (!file.is_open()) {
			return false;
		}
		file << "Grafo" << endl;
		// primero el tama�o
		file << size << endl;

		for (int i = 0; i < size; i++) {
			ListaD<int>::Iterator j(nullptr);
			for (j = grafo[i].aristas.begin(); j != grafo[i].aristas.end(); ++j)
				file << *j << " ";
			file << "\n";
		}

		file.close();
		return true;
	}

	bool cargarArchivo(const string& fileName) {
		ifstream file(fileName);
		if (!file.is_open()) {
			return false;
		}

		// linea que dice "Grafo"
		string tipoArchivo;
		file >> tipoArchivo;

		// tama�o para el arreglo
		int size;
		file >> size;

		if (!createGrafo(size)) {
			return false;
		}

		string celda;
		// guarda el vertice de cada linea y as� se conecta con conexiones
		int verticeActual = -1;
		while (getline(file, celda)) {
			stringstream ss(celda);
			int conexionID;

			// se conecta el vertice actual con cada arista
			while (ss >> conexionID) {
				if (!conectar(verticeActual, conexionID)) {
					return false;
				}
			}
			// pasa al siguiente vertice
			verticeActual++;
		}

		file.close();
		return true;
	}

	void imprimir(void) {
		for (int i = 0; i < size; i++) {
			cout << "\n\n[" << i << "] " << grafo[i].dato;
			cout << "CONNECTED WITH: ";
			grafo[i].print();
		}
	}

	// empieza desde el vertice que se asigna (el que sea poruq de todos modos va a pasar por todos)
	bool DFS(int vertice) {
		// ya se marca como visitado
		grafo[vertice].visitado = true;
		cout << vertice << " ";

		// para las aristas
		ListaD<int>::Iterator i(nullptr);
		// se itera en el grafo con begin y end para recorrer por cada vertice 
		for (i = grafo[vertice].aristas.begin(); i != grafo[vertice].aristas.end(); ++i) {
			// *i es la arista desreferenciada
			// si no est� visitado, recursi�n 
			if (!grafo[*i].visitado) {
				// ayuda a que explore todo antes de pasar a la artista del actual
				DFS(*i);
			}
		}
		return true;
	}

	int getSize() {
		return size;
	}

	T* obtenerVertice(int indice) {
		// fuera de size
		if (indice >= size) {
			return nullptr;
		}

		return &grafo[indice].dato;
	}
};