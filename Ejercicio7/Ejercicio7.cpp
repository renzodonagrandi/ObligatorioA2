#include <iostream>
using namespace std;
#include "minHeap.cpp"

int main() {

    int potencia;
    cin >> potencia;
    int numVirus;
    cin >> numVirus;
    minHeap miHeap(numVirus);
    for (int i = 0; i < numVirus; i++){
        int virus;
        cin >> virus;
        miHeap.insertar(virus);
    }
    bool esSuperado = false;
    for (int i = 0; (i < numVirus) && !esSuperado; i++){
        if (potencia >= miHeap.tope()){
            potencia = potencia + miHeap.tope();
            miHeap.eliminar();
        } else {
            esSuperado = true;
        }
    }
    if (esSuperado){
        cout << "false";
    } else {
        cout << "true";
    }
    

    return 0;
}