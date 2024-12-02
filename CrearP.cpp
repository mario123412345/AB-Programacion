#include "AB Programacion.h"

void CrearP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear paciente";
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
	default:
		cout << "Error" << endl;
		CrearP();
		break;
	}
	
}