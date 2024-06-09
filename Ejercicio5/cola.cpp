#include <iostream>
using namespace std;

class cola {
private:
    struct Nodo {
        int valor;
        Nodo* sig;
    };

    Nodo* prin;
    Nodo* fin;
    int cantidad;

public:
    cola() {
        fin = NULL;
        prin = NULL;
        cantidad = 0;
    }

    bool esVacia() {
        return (cantidad == 0);
    }

    void encolar(int vertice) {
        Nodo* nuevo = new Nodo;
        nuevo->valor = vertice;
        nuevo->sig = NULL;
        if (esVacia()) {
            prin = nuevo;
            fin = nuevo;
        } else {
            fin->sig = nuevo;
            fin = nuevo;
        }
        cantidad = cantidad + 1;
    }

    int pop() {
        if (esVacia()) {
            throw runtime_error("Cola vacía");
        }
        return prin->valor;
    }

    int desencolar() {
        if (esVacia()) {
            throw runtime_error("Cola vacía");
        }
        Nodo* aux = prin;
        int valor = prin->valor;
        prin = prin->sig;
        delete aux;
        cantidad = cantidad - 1;
        return valor;
    }
};