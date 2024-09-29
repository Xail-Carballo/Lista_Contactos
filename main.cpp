#include <iostream>
#include "Contacto.cpp"
#include "listaDobleCircularContactos.cpp"

using namespace std;

int main(){
    cout<< "Sitema de contactos"<<endl;
    Contacto pepe("Jose", "999-123456", "pp@mail.com");
    pepe.mostrar();

    //opcion agregar
    Contacto *ptrC = new Contacto();
    ptrC->leerContacto();

    ListaDobleCircularContactos ldr;
    ldr.insertaOrdenado( ptrC );


    return 0;
}
