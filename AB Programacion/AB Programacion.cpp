// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>


void tablamultiplicar(int x) {
	int i;
	for (int i = 0; i <= 10;i++) {
		std::cout <<x <<"*"<<i <<"="<< x * i << "\n";
	}
}
int main() {
	int x;
	std::cout << "Dame un número: ";
	std::cin >> x;
	tablamultiplicar(x);


}

