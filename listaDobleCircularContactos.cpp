#include <iostream>
#include <string>
#include "Contacto.cpp"

#ifndef _LDC
#define _LDC

class ListaDobleCircularContactos {
private:
    NodoLDC *inicio;
    NodoLDC *fin;
    NodoLDC *Actual;
    int sizeList;

public:
    // Constructor
    ListaDobleCircularContactos() : inicio(nullptr), fin(nullptr), Actual(nullptr) {
        sizeList = 0;
    }

    bool estaVacia() {
        return inicio == nullptr;
    }

    int getSize() {
        return sizeList;
    }

    // insertar por orden alfabetico
    void insertaOrdenado(Contacto* dato) {
        NodoLDC* nuevo = new NodoLDC(dato);

        // Si la lista esta vacia
        if (estaVacia()) {
            inicio = fin = Actual = nuevo;
            inicio->sig = inicio;
            inicio->ant = inicio;
        }
        // Si el nuevo dato es menor o igual que el primer dato de la lista
        else if (dato->getNombre() <= inicio->dato->getNombre()) {
            nuevo->sig = inicio;
            nuevo->ant = fin;
            inicio->ant = nuevo;
            fin->sig = nuevo;
            inicio = nuevo;
        }
        // Si el nuevo dato es mayor que el ultimo dato de la lista
        else if (dato->getNombre() >= fin->dato->getNombre()) {
            fin->sig = nuevo;
            nuevo->ant = fin;
            nuevo->sig = inicio;
            inicio->ant = nuevo;
            fin = nuevo;
        }
        // Si el nuevo dato va en un lugar intermedio
        else {
            NodoLDC* actual = inicio;

            //recorrer la lista
            while (actual->sig != inicio && actual->sig->dato->getNombre() < dato->getNombre()) {
                actual = actual->sig;
            } //mientras no vuelva al inicio y el nombre del actual sea menor que el nuevo, entonces el actual se vuelve el siguiente, sigo comparando


            //nuevo nodo entre 'actual' y 'actual->sig'
            nuevo->sig = actual->sig;
            nuevo->ant = actual;
            actual->sig->ant = nuevo;
            actual->sig = nuevo;
        }
        sizeList++;
    }

//eliminar contacto por nombre
void eliminarPorNombre(const string &nombre) {
    if (estaVacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    NodoLDC *actual = inicio;
    
    // Recorrer la lista
    do {
        //si el actual coincide con el nombre buscado
        if (actual->dato->getNombre() == nombre) {
            
            // Si es el unico nodo en la lista
            if (actual == inicio && actual == fin) {
                inicio = fin = Actual = nullptr; 
            }
            // Si el nodo a eliminar es el primero
            else if (actual == inicio) {
                inicio = inicio->sig; //mover el incio
                inicio->ant = fin; 
                fin->sig = inicio; // Conectar el ultimo nodo al nuevo inicio
            }
            // Si es el ultimo
            else if (actual == fin) {
                fin = fin->ant; // Retroceder el fin
                fin->sig = inicio; 
                inicio->ant = fin; // Conectar el nuevo fin con el inicio
            }
            // Si el nodo a eliminar esta en el medio
            else {
              // Conectar el nodo anterior del actual al siguiente, saltando al actual
                actual->ant->sig = actual->sig; 

            // Conectar el nodo siguiente del actual al anterior, saltando al actual
                actual->sig->ant = actual->ant;
            }

            // Si el nodo eliminado era el nodo actual, movemos el apuntador del actual
            if (Actual == actual) {
                Actual = actual->sig; 
            }

            // Eliminar y reducir el tamaño de la lista
            delete actual;
            sizeList--;
            cout << "Contacto eliminado" << endl;
            return;
        }
        actual = actual->sig; // Avanzar al siguiente nodo
    } while (actual != inicio); // Chasta volver al inicio

    cout << "Contacto no encontrado" << endl;
}


//metodo buscar contacto por nombree
void buscarContacto(const string &nombre) {
    if (estaVacia()) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    NodoLDC *actual = inicio;
    
    // Recorrer la lista
    do {
        // si el contacto actual coincide con el nombre buscado
        if (actual->dato->getNombre() == nombre) {
            actual->dato->mostrar(); 
            return;
        }
        actual = actual->sig; 
    } while (actual != inicio); 

    cout << "Contacto no encontrado" << endl;
}


    // Recuperar el contacto actual
    void mostrarActual() {
        if (estaVacia()) {
            cout << "La lista esta vacia" << endl;
            return;
        }
        Actual->dato->mostrar();
    }

    // Avanzar al siguiente contacto

    // Retroceder al contacto anterior

}; // Fin de clase ListaDobleCircularContactos

#endif // _LDC


