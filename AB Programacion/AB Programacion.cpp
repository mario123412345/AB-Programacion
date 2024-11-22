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

	if (op == 1) {
		cout << "Has elegido editar" << endl;
		editar();
	}
	else if (op == 2) {
		cout << "Has elegido crear" << endl;
		crear();
	}
	else if (op == 3) {
		cout << "Has elegido eliminar" << endl;
		eliminar();
	}
	else {
		cout << "Error, valor no existente" << endl;
		cout << "Reiniciando busqueda" << endl;
		cout << "----------------------------" << endl;
		inicio();
	}


	
}
int main() {
	inicio();
}