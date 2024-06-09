#include <iostream>
#include <string>
using namespace std;
#include "AVL.cpp"


int main()
{
    int N;
    cin >> N;
    int *vec = new int[N];
    for (int i = 0; i < N; i++)
    {
        int valor;
        cin >> valor;
        vec[i] = valor;
    }
    int M;
    cin >> M;
    int primerNum;
    cin >> primerNum;
    AVL arbol;
    arbol.insertar(primerNum);
    for (int i = 0; i < M - 1; i++)
    {
        int valor;
        cin >> valor;
        arbol.insertar(valor);
    }
    int suma;
    cin >> suma;
    int respuesta = arbol.check(vec, N, suma);
    cout << respuesta << endl;
    delete[] vec;
    return 0;
}