#include <iostream>
#include <string>
#include "Contactos.cpp"
#include "ListaDobleCircularContactos.cpp"
using namespace std;

int main() {
	ListaDobleCircularContactos lista;
	int opcion;
	
	do {
		// Mostrar el men� de opciones
		cout << "1. Agregar contacto" << endl;
		cout << "2. Eliminar contacto" << endl;
		cout << "3. Buscar contacto" << endl;
		cout << "4. Imprimir lista de contactos" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una opci�n: ";
		cin >> opcion;
		cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
		
		switch(opcion) {
		case 1: {
			// Agregar un nuevo contacto
			string nombre, telefono, email;
			cout << "Ingrese el nombre: ";
			getline(cin, nombre);
			cout << "Ingrese el telefono: ";
			getline(cin, telefono);
			cout << "Ingrese el email: ";
			getline(cin, email);
			
			Contacto* nuevoContacto = new Contacto(nombre, telefono, email);
			lista.insertaOrdenado(nuevoContacto);
			cout << "Contacto agregado correctamente." << endl;
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
			// Imprimir la lista de contactos de izquierda a derecha
			lista.recorreDerecha();
			break;
		}
		case 5: {
			cout << "Saliendo..." << endl;
			break;
		}
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
		}
		cout << endl; // L�nea en blanco para mejorar la legibilidad del men�
	} while (opcion != 5);
	
	return 0;
}

