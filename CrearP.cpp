#include "AB Programacion.h"

void CrearP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear paciente";
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol == 1) {
		crear();
	}
	else if (vol == 2) {
		inicio();
	}
	else {
		cout << "Error" << endl;
		CrearP();
	}
}