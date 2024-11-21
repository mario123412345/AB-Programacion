// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>


void inicio() {
	int op;
	std::cout << "Bienvenido al programa de administracion de Hospital de " << std::endl;
	std::cout << "Que quieres hacer" << std::endl;
	std::cout << "Editar--> 1" << std::endl;
	std::cout << "Crear--> 2" << std::endl;
	std::cout << "Eliminar--> 3" << std::endl;
	std::cout << "¿Que quieres hacer?"<<endl;
	
	cin >> op;

	if (op == 1) {
		editar();
	}
	else if (op == 2) {
		crear();
	}
	else if (op == 3) {
		eliminar();
	}
	else {
		cout << "Error, valor no existente";
	}


	
}
int main() {
	inicio();
}