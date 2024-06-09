#include <iostream>
#include <string>
using namespace std;

struct NodoLista
{
    NodoLista *sig;
    string comida;
};
struct NodoHash
{
    int id;
    NodoLista *pedido;
    NodoHash *sig;
};

class TablaHash
{

private:
    int cantInstrucciones;
    NodoHash **tabla;

    int obtenerPosicion(int key, int largo)
    {
        return (key % largo);
    }

    void borrarLista(NodoLista *listaComidas)
    {
        NodoLista *actual = listaComidas;
        NodoLista *siguiente;
        while (actual != NULL)
        {
            siguiente = actual->sig;
            delete actual;
            actual = siguiente;
        }
    }

    NodoHash *crearNodo(int unaId, NodoLista *unPedido)
    {
        NodoHash *nuevo = new NodoHash;
        nuevo->pedido = unPedido;
        nuevo->sig = NULL;
        nuevo->id = unaId;
        return nuevo;
    }

public:
    NodoLista *crearPedido(string unaComida)
    {
        NodoLista *nuevo = new NodoLista;
        nuevo->comida = unaComida;
        nuevo->sig = NULL;
        return nuevo;
    }

    void agregarAPedido(string unaComida, NodoLista *&unPedido)
    {
        NodoLista *nuevo = crearPedido(unaComida);
        if (unPedido == NULL)
        {
            unPedido = nuevo;
        }
        
        else{
        NodoLista* iter = unPedido;
        while (iter->sig != NULL)
        {
            iter = iter->sig;
        }
        iter->sig = nuevo;
        }
    }

    void insertar(int unaId, NodoLista *unPedido)
    {
        int pos = obtenerPosicion(unaId, cantInstrucciones);
        NodoHash *nuevo = crearNodo(unaId, unPedido);
        if (tabla[pos] == NULL)
        {
            tabla[pos] = nuevo;
        }
        else
        {
            NodoHash *iter = tabla[pos];
            while (iter->sig != NULL)
            {
                iter = iter->sig;
            }
            iter->sig = nuevo;
        }
    }

    TablaHash(int N)
    {
        cantInstrucciones = N;
        tabla = new NodoHash *[cantInstrucciones]();
    }

    void actualizar(int unaId)
    {
        int pos = obtenerPosicion(unaId, cantInstrucciones);
        NodoHash *iter = tabla[pos];
        bool encontro = false;
        while (!encontro)
        {
            if (iter->id == unaId)
            {
                borrarLista(iter->pedido);
                NodoLista *nuevo = new NodoLista;
                nuevo->comida = "Entregado";
                iter->pedido = nuevo;
                encontro = true;
            }
            else
            {
                iter = iter->sig;
            }
        }
    }

    void imprimirPedido(int unaId)
    {
        int pos = obtenerPosicion(unaId, cantInstrucciones);
        NodoHash *iter = tabla[pos];
        bool encontro = false;
        while (!encontro)
        {
            if (iter->id == unaId)
            {
                NodoLista *buscador = iter->pedido;
                while (buscador != NULL)
                {
                    cout << buscador->comida << " ";
                    buscador = buscador->sig;
                }
                cout << endl;
                encontro = true;
            }
            else
            {
                iter = iter->sig;
            }
        }
    }
};
