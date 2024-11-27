#include "AB Programacion.h"

void EliminarC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Has seleccionado eliminar" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol==1){

		eliminar();
	}
	else if (vol == 2) {
		inicio();
	}
	else {
		cout << "Error" << endl;
		EliminarC();
	}
}