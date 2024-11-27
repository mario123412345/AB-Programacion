
#include "AB Programacion.h"


void eliminar() {
	int elimi;
	cout << "----------------------------" << endl;
	cout << "¿Que quieres eliminar?" << endl;
	cout << "Paciente --> 1" << endl;
	cout << "Doctor --> 2" << endl;
	cout << "Cita -->3" << endl;
	cout << "Inicio --> 4" << endl;
	cout << "¿Que quieres eliminar?" << endl;
	cin >> elimi;
	if (elimi == 1) {
		cout << "Has seleccionado eliminar un Paciente" << endl;
		EliminarP();
	}
	else if (elimi == 2) {
		cout << "Has seleccionado eliminar un doctor" << endl;
		EliminarD();
	}
	else if (elimi == 3) {
		cout << "Has seleccionado eliminar una cita" << endl;
		EliminarC();
	}
	else if (elimi == 4){
		inicio();
	}
	else {
		cout << "Error, valor no existente" << endl;
		cout << "Reiniciando busqueda" << endl;
		cout << "----------------------------" << endl;
		eliminar();
	}
}