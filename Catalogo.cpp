#include <iostream>
#include <string>
#include "Catalogo.h"

using namespace std;

Catalogo::Catalogo() {
    sizeCatalogo = 0;
    // semilla para la función random
    srand(time(0));
}

Catalogo::~Catalogo() {
    arbolMonstruo.eliminar();
}

bool Catalogo::cargarCsv(const string& fileName) {
    // abre el archivo
	ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error, the file can't be opened." << endl;
        return false;
    }

    string celda;

    // descartar primera fila porque es el encabezado
    getline(file, celda);

    // se empieza un loop while para que lea todas las lineas y las agregue al arbol binario
    while (getline(file, celda)) {
        // ayuda a la extracción de datos como string y separa los valores por comas en este caso
        stringstream ss(celda);

        // declaración de variables a usar, todas se establecen primero como str para despues hacer validación
        string name, type, size, align, crString, acString, hpString, error;
        double cr;
        int ac, hp;

        getline(ss, name, ',');
        // si está vació el input se salta a la siguiente fila y se omite esta fila del mosntruo;
        if (isEmpty(name)) {
            continue;
        }

        getline(ss, crString, ',');
        if (!isEmpty(crString)) {
            // se verifica si es válido
            if (!validDouble(crString)) {
                cerr << "Error, the input is not a double." << endl;
                continue;
            }
        }
        else {
            continue;
        }

        getline(ss, type, ',');
        if (isEmpty(type)) {
            continue;
        }

        getline(ss, size, ',');
        if (isEmpty(size)) {
            continue;
        }

        getline(ss, acString, ',');
        if (!isEmpty(acString)) {
            // se verifica si es válido
            if (!validInt(acString)) {
                cerr << "Error, the input is not an int." << endl;
                continue;
            }
        }
        else {
            continue;
        }

        getline(ss, hpString, ',');
        if (!isEmpty(hpString)) {
            // se verifica si es válido y se convierte a int
            if (!validInt(hpString)) {
                cerr << "Error, the input is not an int." << endl;
                continue;
            }
        }
        else {
            continue;
        }

        getline(ss, align, ',');
        if (isEmpty(align)) {
            continue;
        }

        // si se leyó otra celda, se pasa a la siguiente fila
        if (getline(ss, error, ',')) {
            cerr << "There´s an error in the catalog. Excessive number of cells. " << endl;
            continue;
        }

        // se cambian de strings a int y double
        cr = stod(crString);
        ac = stoi(acString);
        hp = stoi(hpString);

        // se crea el objeto de monstruo con lo leido de csv
        Monstruo nuevoMonstruo(name, cr, type, size, ac, hp, align);

        // se añade al arbol usando las sobrecargas de operadores de clase Monstruo y compara su nombre en orden
        arbolMonstruo.insertar(nuevoMonstruo);
        sizeCatalogo++;
    }

    file.close();
    return true;
}

// función para ver si las celdas estaban vacías o no
bool Catalogo::isEmpty(const string& variable) {
    if (variable.empty()) {
        cerr << "There´s an error in the catalog. Insufficient number of cells." << endl;
        return true;
    }
    return false;
}

// función para verificar si el dato es un entero
bool Catalogo::validInt(const string& variable) {
    for (int i = 0; i < variable.length(); i++) {
        // si en la posición de la variable string no es un número, es incorrecto el valor
        if (!isdigit(variable[i])) {
            return false;
        }
    }
    return true;
}

// función para verificar si el dato es un double
bool Catalogo::validDouble(const string& variable) {
    bool puntoDecimal = false;
    for (int i = 0; i < variable.length(); i++) {
        // condición de cuando ya se había visto un punto decimal en la variable
        if (variable[i] == '.') {
            // si puntoDecial = true significa que la variable no es double pues tiene más de 1 punto
            if (puntoDecimal) {
                return false;
            }

            // si pasa no había un punto decimal, ahora puntoDecimal se vuelve true para decir que ya hay un punto en la vaiable
            puntoDecimal = true;
            // pasa a la siguiente iteración
            continue;
        }
        if (!isdigit(variable[i])) {
            return false;
        }
    }
    return true;
}

int Catalogo::getSize() {
    return sizeCatalogo;
}

Monstruo* Catalogo::randomMonster() {
    // condición de que no hay monstruos
    if (sizeCatalogo == 0) {
        return nullptr;
    }

    // empieza desde 0 hasta (en este caso del csv) 762-1
    int valorAleatorio = rand() % sizeCatalogo;
    
    NodoArbol<Monstruo>* monstruo = arbolMonstruo.recorrerArbol(valorAleatorio);
    if (monstruo) {
        //  sin el ->dato, estaría regresando el nodo y con & devuelve la dirección del monstruo
        return &monstruo->dato;
    }

    return nullptr;
}