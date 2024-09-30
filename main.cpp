#include <iostream>
#include "Contacto.cpp"
#include "listaDobleCircularContactos.cpp"
#include "menu.cpp"

using namespace std;

int main(){


    cout<< "Sitema de contactos"<<endl;
    //opcion agregar
    Contacto *ptrC = new Contacto();
    ptrC->leerContacto();

    ListaDobleCircularContactos ldr;
    ldr.insertaOrdenado( ptrC );


    return 0;
}
