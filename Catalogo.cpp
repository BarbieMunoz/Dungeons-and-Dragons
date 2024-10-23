#include <iostream>
#include <string>
#include "Catalogo.h"

using namespace std;

Catalogo::Catalogo() {
    sizeCatalogo = 0;
    // semilla para la funci�n random
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
        // ayuda a la extracci�n de datos como string y separa los valores por comas en este caso
        stringstream ss(celda);

        // declaraci�n de variables a usar, todas se establecen primero como str para despues hacer validaci�n
        string name, type, size, align, crString, acString, hpString, error;
        double cr;
        int ac, hp;

        getline(ss, name, ',');
        // si est� vaci� el input se salta a la siguiente fila y se omite esta fila del mosntruo;
        if (isEmpty(name)) {
            continue;
        }

        getline(ss, crString, ',');
        if (!isEmpty(crString)) {
            // se verifica si es v�lido
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
            // se verifica si es v�lido
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
            // se verifica si es v�lido y se convierte a int
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

        // si se ley� otra celda, se pasa a la siguiente fila
        if (getline(ss, error, ',')) {
            cerr << "There�s an error in the catalog. Excessive number of cells. " << endl;
            continue;
        }

        // se cambian de strings a int y double
        cr = stod(crString);
        ac = stoi(acString);
        hp = stoi(hpString);

        // se crea el objeto de monstruo con lo leido de csv
        Monstruo nuevoMonstruo(name, cr, type, size, ac, hp, align);

        // se a�ade al arbol usando las sobrecargas de operadores de clase Monstruo y compara su nombre en orden
        arbolMonstruo.insertar(nuevoMonstruo);
        sizeCatalogo++;
    }

    file.close();
    return true;
}

// funci�n para ver si las celdas estaban vac�as o no
bool Catalogo::isEmpty(const string& variable) {
    if (variable.empty()) {
        cerr << "There�s an error in the catalog. Insufficient number of cells." << endl;
        return true;
    }
    return false;
}

// funci�n para verificar si el dato es un entero
bool Catalogo::validInt(const string& variable) {
    for (int i = 0; i < variable.length(); i++) {
        // si en la posici�n de la variable string no es un n�mero, es incorrecto el valor
        if (!isdigit(variable[i])) {
            return false;
        }
    }
    return true;
}

// funci�n para verificar si el dato es un double
bool Catalogo::validDouble(const string& variable) {
    bool puntoDecimal = false;
    for (int i = 0; i < variable.length(); i++) {
        // condici�n de cuando ya se hab�a visto un punto decimal en la variable
        if (variable[i] == '.') {
            // si puntoDecial = true significa que la variable no es double pues tiene m�s de 1 punto
            if (puntoDecimal) {
                return false;
            }

            // si pasa no hab�a un punto decimal, ahora puntoDecimal se vuelve true para decir que ya hay un punto en la vaiable
            puntoDecimal = true;
            // pasa a la siguiente iteraci�n
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
    // condici�n de que no hay monstruos
    if (sizeCatalogo == 0) {
        return nullptr;
    }

    // empieza desde 0 hasta (en este caso del csv) 762-1
    int valorAleatorio = rand() % sizeCatalogo;
    
    NodoArbol<Monstruo>* monstruo = arbolMonstruo.recorrerArbol(valorAleatorio);
    if (monstruo) {
        //  sin el ->dato, estar�a regresando el nodo y con & devuelve la direcci�n del monstruo
        return &monstruo->dato;
    }

    return nullptr;
}