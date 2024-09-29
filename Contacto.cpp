#include <iostream>
#include <string>
using namespace std;

#ifndef _CONTACTO
#define _CONTACTO
class Contacto{
private:
    string nombre;
    string tel;
    string email;
public:
    Contacto(string n, string t, string em){
        nombre = n;
        tel = t;
        email = em;
    }

    string getNombre(){
        return nombre;
    }

    Contacto(){
        nombre = "";
        tel = "";
        email = "";

    }
    void leerContacto(){
        cout<<"Nombre: ";
        getline(cin,nombre);
        cout<<"Telefono: ";
        getline(cin,tel);
        cout<<"email: ";
        getline(cin,email);
    }

    void mostrar(){
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Telefono: "<<tel<<endl;
        cout<<"email: "<<email<<endl;
    }
};

class NodoLDC{
public:
    Contacto *dato;
    NodoLDC *sig;
    NodoLDC *ant;

    NodoLDC(Contacto *d){
        dato = d;
        sig = nullptr;
        ant = nullptr;
    }

    ~NodoLDC(){
        delete dato;
    }
};

#endif // _CONTACTO
