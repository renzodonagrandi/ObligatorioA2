#include <iostream>
using namespace std;
#include "grafo.cpp"

int main()
{
    int cantV;
    cin >> cantV;
    grafo miGrafo(cantV);
    int cantA;
    cin >> cantA;
    for (int i = 0; i < cantA; i++)
    {
        int salida, llegada;
        cin >> salida >> llegada;
        miGrafo.insertar(salida, llegada);
    }
    int cantABuscar;
    cin >> cantABuscar;
    int *verABuscar = new int[cantABuscar];
    for (int j = 0; j < cantABuscar; j++)
    {
        int ver;
        cin >> ver;
        verABuscar[j] = ver;
    }
    bool *visita = new bool[cantV + 1]();
    miGrafo.DFS(1, visita);
    for (int i = 0; i < cantABuscar; i++)
    {
        if (visita[verABuscar[i]])
        {
            cout << verABuscar[i] << " si\n";
        }
        else
        {
            cout << verABuscar[i] << " no\n";
        }
    }
    delete[] verABuscar;
    delete[] visita;
    return 0;
}
