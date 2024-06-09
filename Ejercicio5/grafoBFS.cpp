#include <iostream>
using namespace std;
#include "cola.cpp"

struct NodoLista {
    int vertice;
    NodoLista* sig;

    NodoLista() : vertice(0), sig(NULL) {}
};

class grafo {
private:
    int cantVertices;
    NodoLista** vec;
    int* adyPorVertice;

    NodoLista* crearNodo(int num) {
        NodoLista* nuevo = new NodoLista;
        nuevo->vertice = num;
        nuevo->sig = NULL;
        return nuevo;
    }

public:
    grafo(int cant) {
        cantVertices = cant + 1;
        vec = new NodoLista * [cantVertices]();
        adyPorVertice = new int[cantVertices]();
    }

    NodoLista* adyacentes(int vertice) {
        return vec[vertice];
    }

    ~grafo() {
        for (int i = 0; i < cantVertices; i++) {
            NodoLista* nodo = vec[i];
            while (nodo != NULL) {
                NodoLista* temp = nodo;
                nodo = nodo->sig;
                delete temp;
            }
        }
        delete[] vec;
        delete[] adyPorVertice;
    }

    void insertar(int salida, int llegada) {
        NodoLista* nuevo = crearNodo(llegada);
        if (vec[salida] == NULL) {
            vec[salida] = nuevo;
            adyPorVertice[salida] = 1;
        } else {
            NodoLista* iter = vec[salida];
            while (iter->sig != NULL) {
                iter = iter->sig;
            }
            iter->sig = nuevo;
            adyPorVertice[salida] = adyPorVertice[salida] + 1;
        }
    }

    float BFS(int NodoInicial) {
        cola miCola;
        bool* encolados = new bool[cantVertices]();
        encolados[NodoInicial] = true;
        miCola.encolar(NodoInicial);
        int* costos = new int[cantVertices]();
        costos[NodoInicial] = 0;
        while (!miCola.esVacia()) {
            int n = miCola.desencolar();
            NodoLista* ady = adyacentes(n);
            NodoLista* iter = ady;
            while (iter != NULL) {
                if (!encolados[iter->vertice]) {
                    encolados[iter->vertice] = true;
                    miCola.encolar(iter->vertice);
                    costos[iter->vertice] = costos[n] + 1;
                }
                iter = iter->sig;
            }
        }
        float suma = 0;
        for (int i = 1; i < cantVertices; i++) {
            if (i != NodoInicial) {
                suma += costos[i];
            }
        }
        delete[] costos;
        delete[] encolados;
        float promedio = (suma) / (cantVertices - 2);
        return promedio;
    }

    NodoLista* vertImport() {
        NodoLista* ret = NULL;
        NodoLista* ult = NULL;
        for (int i = 1; i < cantVertices; i++) {
            if (adyPorVertice[i] >= 2) {
                NodoLista* nuevo = new NodoLista;
                nuevo->vertice = i;
                if (ret == NULL) {
                    ret = nuevo;
                } else {
                    ult->sig = nuevo;
                }
                ult = nuevo;
            }
        }
        return ret;
    }
};
