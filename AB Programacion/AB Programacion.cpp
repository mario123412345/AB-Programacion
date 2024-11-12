// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>

int main() {
	int n;
	std::cout << "Dame una cantidad: ";
	std::cin >> n;
	int suma=0;
	for (int i = 0; i < n; i++) {
		float x;
		std::cout<<"Ingrese un número: ";
		std::cin >> x;
		suma += x;
	}
	double media = suma / n;
	std::cout<< "La meida es "<< media ;
	
}

