#pragma once
#include <string>
#include <iostream>

using namespace std;
template <typename T>

class NodoLista {
public:
	T dato;
	NodoLista* next;
	NodoLista* prev;

	NodoLista(): dato(T()), next(nullptr), prev(nullptr) {}

	NodoLista(T dato) : dato(dato), next(nullptr), prev(nullptr) {}

	~NodoLista() {}
};