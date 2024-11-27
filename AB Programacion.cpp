// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>


void inicio() {
	int op;
	cout << "----------------------------" << endl;
	std::cout << "Bienvenido al programa de administracion de Hospital de " << std::endl;
	std::cout << "Que quieres hacer" << std::endl;
	std::cout << "Editar --> 1" << std::endl;
	std::cout << "Crear --> 2" << std::endl;
	std::cout << "Eliminar --> 3" << std::endl;
	std::cout << "¿Que quieres hacer?"<<endl;
	
	cin >> op;
	switch (op) {
		case 1:
			cout << "Has elegido editar" << endl;
			editar();
			break;
		case 2:
			cout << "Has elegido crear" << endl;
			crear();
			break;
		case 3:
			cout << "Has elegido eliminar" << endl;
			eliminar();
			break;
		default:
			cout << "opción no válida" << endl;
			inicio();
	}

}
int main() {
	inicio();
	return 0;
}