#include "AB Programacion.h"

void CrearD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear Doctor";
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol == 1) {
		crear();
	}else if(vol==2){
		inicio();
	}
	else {
		cout << "Error" << endl;
		CrearD();
	}
}