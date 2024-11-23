#include "AB Programacion.h"

void EliminarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Eliminando paciente" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol == 1) {
		eliminar();

	}
	else if (vol == 2) {
		inicio();
	}
	else {
		cout << "Error;" << endl;
		EliminarP();
	}
}