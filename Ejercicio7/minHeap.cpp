#include <iostream>
#include <cassert>
using namespace std;

class minHeap {

private:

    int * potVirus;
    int posTope;
    int cantVirus;

    void intercambiar(int pos1, int pos2) {
        int aux = this->potVirus[pos1];
        this->potVirus[pos1] = this->potVirus[pos2];
        this->potVirus[pos2] = aux;
    }

    int funcionComp(int valor1, int valor2){
        return valor1 - valor2;
    }

    void flotar(int pos) {
    if (pos > 1) {            
        int posPadre = pos / 2;
        if (funcionComp(potVirus[posPadre], potVirus[pos]) > 0) {
            intercambiar(posPadre, pos);
            flotar(posPadre);
            }
        }
    }

    void hundir(int pos) {
        int posHijoIzq = pos * 2;
        int posHijoDer = (pos * 2) + 1;

        if ((posHijoIzq < posTope) && (posHijoDer < posTope)) {
            int posHijoMenor;
            if (funcionComp(potVirus[posHijoIzq], potVirus[posHijoDer]) < 0){
                posHijoMenor = posHijoIzq;
            } else {
                posHijoMenor = posHijoDer;
            }
            if (funcionComp(potVirus[pos], potVirus[posHijoMenor]) > 0) {
                intercambiar(pos, posHijoMenor);
                hundir(posHijoMenor);
            }
        } else if (posHijoIzq < posTope) {
            if (funcionComp(potVirus[pos], potVirus[posHijoIzq]) > 0) {
                intercambiar(pos, posHijoIzq);
                hundir(posHijoIzq);
            }
        }
    }

public:

    minHeap(int cant){
        potVirus = new int[cant +1];
        cantVirus = cant;
        posTope = 1;
    }

    bool estaVacio() {
        return posTope == 1;
    }

    bool tieneUnElemento() {
        return posTope == 2;
    }

    void eliminar() {
        assert(!estaVacio());
        potVirus[1] = potVirus[posTope - 1];
        posTope = posTope - 1;
        hundir(1);
    }

    int tope() {
        return potVirus[1];
    }

    void insertar(int potencia) {
        potVirus[posTope] = potencia;
        flotar(posTope);
        posTope = posTope + 1;
    }

};