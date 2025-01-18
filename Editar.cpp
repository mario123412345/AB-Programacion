

#include "AB Programacion.h"

void editar() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "¿Que quieres editar?" << endl;
	cout << "1.Paciente" << endl;
	cout << "2.Doctor" << endl;
	cout << "3.Cita" << endl;
	cout << "4.Volver al inicio" << endl;
	while (true) {
		string input;
		cin >> input;
		stringstream ss(input);
		if (ss >> opcion && ss.eof()) {
			break;
		}
		else {
			cout << "Esscribe un numero valido ";
		}
	}
	switch (opcion) {
	case 1:
		cout << "Has seleccionado editar un Paciente" << endl;
		EditarP();
		break;
	case 2:
		cout << "Has seleccionado editar un doctor" << endl;
		EditarD();
		break;
	case 3:
		cout << "Has seleccionado editar una cita" << endl;
		EditarC();
		break;
	case 4:
		inicio();
		break;
	default:
		cout << "Error, valor no existente" << endl;
		cout << "Reiniciando busqueda" << endl;
		cout << "----------------------------" << endl;
		editar();
		break;
	}
	

}