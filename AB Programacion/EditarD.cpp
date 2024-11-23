#include "AB Programacion.h"

void EditarD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando Doctor" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol == 1) {
		editar();
	}
	else if (vol == 2) {
		inicio();
	}
	else {
		cout << "Error" << endl;
		EditarD();
	}
}