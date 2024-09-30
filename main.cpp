#include <iostream>
#include <string>
#include "Contacto.cpp"
#include "listaDobleCircularContactos.cpp"

using namespace std;

int main() {
    ListaDobleCircularContactos lista;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Buscar contacto" << endl;
        cout << "4. Mostrar contacto actual" << endl;
        cout << "5. Avanzar al siguiente contacto" << endl;
        cout << "6. Retroceder al contacto anterior" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();  // Limpiar el buffer

        switch (opcion) {
            case 1: {
               
                string nombre, telefono, email;
                cout << "Ingrese el nombre: ";
                getline(cin, nombre);
                cout << "Ingrese el telefono: ";
                getline(cin, telefono);
                cout << "Ingrese el email: ";
                getline(cin, email);

                Contacto* nuevoContacto = new Contacto(nombre, telefono, email);
                lista.insertaOrdenado(nuevoContacto);
                cout << "Contacto agregado correctamente" << endl;
                break;
            }
            case 2: {
                // Eliminar contacto por nombre
                string nombre;
                cout << "Ingrese el nombre del contacto a eliminar: ";
                getline(cin, nombre);
                lista.eliminarPorNombre(nombre);
                break;
            }
            case 3: {
                // Buscar un contacto por nombre
                string nombre;
                cout << "Ingrese el nombre del contacto a buscar: ";
                getline(cin, nombre);
                lista.buscarContacto(nombre);
                break;
            }
            case 4: {
                // Mostrar contacto actual
                lista.mostrarActual();
                break;
            }
            case 5: {
                // Avanzar al siguiente contacto
               // lista.avanzar();
                lista.mostrarActual();
                break;
            }
            case 6: {
                // Retroceder al contacto anterior
               // lista.retroceder();
                lista.mostrarActual();
                break;
            }
            case 7: {
                cout << "Saliendo..." << endl;
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        }

        cout << endl;
    } while (opcion != 7);

    return 0;
}
