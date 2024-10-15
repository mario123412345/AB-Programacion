// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>

void añadir() {
	

}
int main() {
	int i;
	std::cout << "Introduce un número positivo";
	std::cin >> i;
	for (int n = 0; n <= i; n++) {
		std::cout << n<<" ";
	}
	std::cout << std::endl;
	return 0;
}

