#include <iostream>
using namespace std;

struct NodoLista {
    int vertice;
    NodoLista* sig;

    NodoLista(int v) : vertice(v), sig(NULL) {}
};

class grafo
{
private:
    int cantVertices;
    NodoLista** vec;

    NodoLista* crearNodo(int num) {
        return new NodoLista(num);
    }

public:
    grafo(int cant) {
        cantVertices = cant + 1;
        vec = new NodoLista * [cantVertices]();
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
    }

    void insertar(int salida, int llegada) {
        NodoLista* nuevo = crearNodo(llegada);
        if (vec[salida] == NULL) {
            vec[salida] = nuevo;
        }
        else {
            NodoLista* iter = vec[salida];
            while (iter->sig != NULL) {
                iter = iter->sig;
            }
            iter->sig = nuevo;
        }
    }

    void DFS(int NodoInicial, bool* visitados) {
        visitados[NodoInicial] = true;
        NodoLista* ady = vec[NodoInicial];
        while (ady != NULL) {
            if (!visitados[ady->vertice]) {
                DFS(ady->vertice, visitados);
            }
            ady = ady->sig;
        }
    }
};
