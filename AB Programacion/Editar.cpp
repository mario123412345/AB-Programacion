

#include "AB Programacion.h"

void editar() {
	int ed;
	cout << "----------------------------" << endl;
	cout << "¿Que quieres editar?" << endl;
	cout << "Paciente --> 1" << endl;
	cout << "Doctor --> 2" << endl;
	cout << "Cita --> 3" << endl;
	cout << "Inicio -->4" << endl;
	cin >> ed;
	if (ed == 1) {
		cout << "Has seleccionado editar un Paciente" << endl;
			EditarP();
	}
	else if (ed==2){
		cout << "Has seleccionado editar un doctor" << endl;
		EditarD();
	}
	else if (ed == 3) {
		cout << "Has seleccionado editar una cita" << endl;
		EditarC();
	}
	else if (ed == 4){
		inicio();
	}
	else {
		cout << "Error, valor no existente" << endl;
		cout << "Reiniciando busqueda" << endl;
		cout << "----------------------------" << endl;
		editar();
	}

}