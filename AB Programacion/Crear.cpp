
#include "AB Programacion.h"

void crear() {
	int crea;
	cout << "----------------------------" << endl;
	cout << "Has seleccionado Crear" << endl;
	cout << "¿Qué quieres crear?"<<endl;
	cout << "Paciente--> 1"<<endl;
	cout << "Doctor--> 2" << endl;
	cout << "Cita --> 3" << endl;
	cout << "Inicio -->4" << endl;
	cout << "¿Que quieres crear?" << endl;
	cin >> crea;
	if (crea == 1) {
		cout << "Has seleccionado crear un paciente" << endl;
		CrearP();
	}
	else if (crea == 2) {
		cout << "Has seleccionado crear un nuevo doctor" << endl;
		CrearD();
	}
	else if (crea == 3) {
		cout << "Has seleccionado crear una nueva cita" << endl;
		CrearC();
	}
	else if (crea == 4) {
		inicio();
	}
	else {
		cout << "Error, valor no existente" << endl;
		cout << "Reiniciando busqueda" << endl;
		cout << "----------------------------" << endl;
		crear();
	}
}
