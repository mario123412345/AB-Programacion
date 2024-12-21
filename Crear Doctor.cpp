#include "AB Programacion.h"

void CrearD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear Doctor";
	cout << "Continuar -->1" << endl;
	cout << "Inicio -->2" << endl;
	cout << "Volver-->3" << endl;
	
	cin >> vol;
	switch (vol) {
		case 1:
			doctorc();
			break;
		case 2:
			inicio();
			break;
		case 3:
			crear();
			break;
	default:
		cout << "Error" << endl;
		CrearD();
		break;
	}
	
}