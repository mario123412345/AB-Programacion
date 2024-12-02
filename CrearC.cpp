#include "AB Programacion.h"

void CrearC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear Cita";
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	switch (vol) {
		case 1:
			crear();
			break;
		case 2:
			inicio();
			break;
		case 3:
			cout << "Error" << endl;
			CrearC();
			break;
		default:
			CrearC();
			break;

	}
	
}