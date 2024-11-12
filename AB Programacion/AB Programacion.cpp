// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>

void intercambiar(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

}
int main() {
	std::cout << "Dame un valor: ";
	int a;
	std::cin >> a;
	int b;
	std::cout << "Dame otro valor: ";
	std::cin >> b;

	intercambiar(a, b);
	std::cout << a << ""<< b;

}

