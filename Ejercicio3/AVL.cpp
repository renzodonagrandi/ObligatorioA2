#include <iostream>

struct AVLaux {
        int num;
        AVLaux * izq;
        AVLaux * der;
        int alt; 

AVLaux(int dato){
    this->num = dato;
    this->izq = NULL;
    this->der = NULL;
    this->alt = 1;
}
};


class AVL
{
    private:
        
        AVLaux * raiz;

        int mayor(int x, int y){
            if (x>y)
            {
                return x;
            }else{
                return y;
            }
        }

        int altura(AVLaux * nodo){
            if(nodo == NULL) return 0;
            return 1 + mayor(altura(nodo->izq), altura(nodo->der));
        }

        int obtenerBalance(AVLaux * nodo){
        if(nodo == NULL) return 0;
        return (altura(nodo->izq) - altura(nodo->der));
    }

    AVLaux * rotacionHoraria(AVLaux * A){
        AVLaux * B = A->izq;
        AVLaux * T2 = B->der;
        B->der = A;
        A->izq = T2;
        A->alt = altura(A);
        B->alt = altura(B);
        return B;
    }

    AVLaux * rotacionAntihoraria(AVLaux * B) {
        AVLaux * A = B->der;
        AVLaux * T2 = A->izq;
        A->izq = B;
        B->der = T2;
        B->alt = altura(B);
        A->alt = altura(A);
        return A;
    }

    AVLaux* insertarAux(AVLaux * nodo, int dato){
        if(nodo == NULL){
            return new AVLaux(dato);
        }
        if(dato < nodo->num){
            nodo->izq = insertarAux(nodo->izq, dato);
        }else if(dato > nodo->num){
            nodo->der = insertarAux(nodo->der, dato);
        }else{
            return nodo;
        }
        nodo->alt = altura(nodo);
        int balance = obtenerBalance(nodo);
        if(balance > 1 && dato < nodo->izq->num){
            return rotacionHoraria(nodo);
        }
        if(balance < -1 && dato > nodo->der->num){
            return rotacionAntihoraria(nodo);
        }
        if(balance > 1 && dato > nodo->izq->num){
            nodo->izq = rotacionAntihoraria(nodo->izq);
            return rotacionHoraria(nodo);
        }
        if(balance < -1 && dato < nodo->der->num){
            nodo->der = rotacionHoraria(nodo->der);
            return rotacionAntihoraria(nodo);
        }
        return nodo;
    }
    
        bool estaEnAVL(AVLaux* nodo, int numero) {
        if (nodo == NULL) return false;
        if (nodo->num == numero) return true;
        if (numero < nodo->num) {
            return estaEnAVL(nodo->izq, numero);
        } else {
            return estaEnAVL(nodo->der, numero);
        }
    }
    
    public:

        AVL() : raiz(NULL) {}

        void insertar(int num){
            raiz = insertarAux(raiz, num);
        }

        int check(int * vec, int largo, int suma){
            int contador = 0;
            for (int i = 0; i < largo; i++)
            {
                int aBuscar = suma - vec[i];
                if (estaEnAVL(raiz, aBuscar))
                {
                    contador++;
                }
            }
            return contador;
        }

};