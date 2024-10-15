// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>

void añadir() {
	

}
int main() {
	int n;
	int factorial = 1;
	std::cout << "Ingrese un número: ";
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	std::cout << "El factorial de " << n << " es: " << factorial << std::endl;
		}
	return 0;

	
}

