// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>

void numeros(int x, int y) {
	std::cout << "Hola";
	int res = x + y;
	int i = 0;
	for (i <= res; i++) {
		std::cout << "Los numeros son: " << i << std::endl;
	}
	std::cout << "Hola212";
}
int main() {
	std::cout << "Introduce un valor: ";
	int x;
	std::cin >> x;
	std::cout << "Introduce otro: ";
	int y;
	std::cin >> y;
	std::cout << "la suma da " << x + y;
	numeros(x,y);

}

