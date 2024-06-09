#include <iostream>
using namespace std;
#include "grafoBFS.cpp"

int main() {
    int cantParadas;
    cin >> cantParadas;
    grafo miGrafo(cantParadas);
    int cantLineas;
    cin >> cantLineas;
    int salida;
    int llegada;
    for (int i = 0; i < cantLineas; i++) {
        cin >> salida;
        cin >> llegada;
        miGrafo.insertar(salida, llegada);
        miGrafo.insertar(llegada, salida);
        int siguiente;
        cin >> siguiente;
        while (siguiente != 0) {
            miGrafo.insertar(llegada, siguiente);
            miGrafo.insertar(siguiente, llegada);
            llegada = siguiente;
            cin >> siguiente;
        }
    }

    NodoLista* importantes = miGrafo.vertImport();
    float menor = INT_MAX;
    int referenciaVec = -1;
    while (importantes != NULL) {
        float nuevo = miGrafo.BFS(importantes->vertice);
        if (nuevo < menor) {
            menor = nuevo;
            referenciaVec = importantes->vertice;
        } else if (nuevo == menor && importantes->vertice < referenciaVec) {
            referenciaVec = importantes->vertice;
        }
        importantes = importantes->sig;
    }

    cout << "El fugitivo está en: " << referenciaVec << endl;

    return 0;
}
