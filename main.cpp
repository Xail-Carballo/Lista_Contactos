#include <iostream>
#include <cstdlib>
#include "Contacto.cpp"
#include "listaDobleCircularContactos.cpp"


int main() {
    ListaDobleCircularContactos lista;
    int opcion;

    do {
        system ("cls");
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
                lista.agregarContacto();
                system("pause");
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
                system("pause");
                break;
            }
            case 5: {
                // Avanzar al siguiente contacto
                lista.avanzar();
                lista.mostrarActual();
                system("pause");
                break;
            }
            case 6: {
                // Retroceder al contacto anterior
                lista.retroceder();
                lista.mostrarActual();
                system("pause");
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
