#include <iostream>
#include <string>
using namespace std;
#include "estructuras.cpp"

int main()
{
    int N;
    cin >> N;
    TablaHash MiTabla = TablaHash(N);
    string operacion;
    bool necesitoLectura = true;

    for (int i = 0; i < N; i++)
    {
        if (necesitoLectura)
        {
            cin >> operacion;
        }
        int codigo;
        cin >> codigo;


        string entrada;
        if (operacion == "A")
        {

            cin >> entrada;
            NodoLista *pedido = NULL;
            while (entrada != "A" && entrada != "E" && entrada != "Q")
            {
                MiTabla.agregarAPedido(entrada, pedido);
                cin >> entrada;
            }
            operacion = entrada;
            
            necesitoLectura = false;
            MiTabla.insertar(codigo, pedido);
        }

        else if (operacion == "E")
        {
            MiTabla.actualizar(codigo);
          
            necesitoLectura = true;
        }
        else if (operacion == "Q")
        {
            MiTabla.imprimirPedido(codigo);
            necesitoLectura = true;
        }
    }
}
