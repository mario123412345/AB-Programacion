#include "AB Programacion.h"

void EditarC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando cita" << endl;
	cout << "Para editar una" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin>> vol;
	if (vol == 1) {
		editar();
	}
	else if (vol == 2){
		inicio();
	}
	else {
		cout << "Error" << endl;
		EditarC();
	}
}