#include <iostream>
#include <string>
#include "Contacto.cpp"
using namespace std;

#ifndef _LDC
#define _LDC

class ListaDobleCircularContactos {
private:
NodoLDC* inicio; // Puntero al primer nodo de la lista
NodoLDC* fin; // Puntero al último nodo de la lista
int sizeList;

public:
// Constructor
ListaDobleCircularContactos() : inicio(nullptr), fin(nullptr) {
sizeList=0;
}

//Metodos a implementar

bool estaVacia(){
return inicio==nullptr;
}

int getSize(){
return sizeList;
}

void insertaInicio(Contacto *dato){
NodoLDC *aux=new NodoLDC( dato );
if( estaVacia() ){
inicio=aux;
fin=aux;
}
else{
aux->sig=inicio;
inicio->ant=aux;
inicio=aux;
}
sizeList++;
}

// Metodo para mostrar la lista de izq a derecha
void recorreDerecha() {
NodoLDC* temp = inicio;
while (temp != nullptr) {
temp->dato->mostrar();
temp = temp->sig; // Moverse al siguiente nodo
}
cout << "nullptr" << endl;
}

// Metodo para mostrar la lista de derecha a izq
void recorreIzquierda() {
NodoLDC* temp = fin;
while (temp != nullptr) {
temp->dato->mostrar();
temp = temp->ant; // Moverse al siguiente nodo
}
cout << "nullptr" << endl;
}



void insertaOrdenado(Contacto *dato) {
    NodoLDC* nuevo = new NodoLDC( dato );

    //Si la lista esta vacia
    if (!inicio) {
        inicio = fin = nuevo;
    }
    // Si el nuevo dato es menor o igual que el primer dato de la lista
    else if (dato->getNombre() <= inicio->dato->getNombre()) {
        nuevo->sig = inicio;
        inicio->ant = nuevo;
        inicio = nuevo;
    }
    // Si el nuevo dato es mayor que el último dato de la lista
    else if (dato->getNombre() >= fin->dato->getNombre()) {
        fin->sig = nuevo;
        nuevo->ant = fin;
        fin = nuevo;
    }
    // Si el nuevo dato va en algún lugar intermedio
    else {
        NodoLDC* actual = inicio;
    // Encontrar la posicion correcta
        while (actual->sig && actual->sig->dato < dato) {
            actual = actual->sig;
    }

    // Insertar el nuevo nodo entre 'actual' y 'actual->sig'
    nuevo->sig = actual->sig;
    if (actual->sig) {
    actual->sig->ant = nuevo;
    }
    nuevo->ant = actual;
    actual->sig = nuevo;
    }

    // Aumentar el tamaño de la lista
    sizeList++;
}

}; //Fin de clase ListaDoble

#endif // _LDC
