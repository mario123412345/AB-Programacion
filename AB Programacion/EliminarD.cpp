#include "AB Programacion.h"

void EliminarD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Eliminando doctor" << endl;
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
		cout << "Error" << endl;
		EliminarD();
	}
}