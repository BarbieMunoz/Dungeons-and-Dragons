#pragma once
#include <string>
#include <iostream>

using namespace std;
template <typename T>

class NodoArbol {
public:
	T dato;
	NodoArbol* left;
	NodoArbol* right;

	NodoArbol() : dato(T()), left(nullptr), right(nullptr) {}

	NodoArbol(T  dato) : dato(dato), left(nullptr), right(nullptr) {}

	~NodoArbol() {}
};