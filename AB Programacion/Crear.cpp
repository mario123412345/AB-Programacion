
#include "AB Programacion.h"

void crear() {
	int crea;
	cout << "----------------------------" << endl;
	cout << "Has seleccionado Crear" << endl;
	cout << "¿Qué quieres crear?"<<endl;
	cout << "Paciente--> 1"<<endl;
	cout << "Doctor--> 2" << endl;
	cout << "Cita --> 3" << endl;
	cout << "¿Que quieres crear?" << endl;
	cin >> crea;
	if (crea == 1) {
		CrearP();
	}
	else if (crea == 2) {
		CrearD();
	}
	else if (crea == 3) {
		CrearC();
	}
	else {
		cout << "Error, saliendo";
	}
}
