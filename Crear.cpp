
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
	while (true) {
		string input;
		cin >> input;
		stringstream ss(input);
		if (ss >> crea && ss.eof()) {
			break;
		}
		else {
			cout << "Esscribe un numero valido ";
		}
	}
	switch (crea) {
		case 1:
			cout << "Has seleccionado crear un paciente" << endl;
			CrearP();
			break;
		case 2:
			cout << "Has seleccionado crear un nuevo doctor" << endl;
			CrearD();
			break;
		case 3:
			cout << "Has seleccionado crear una nueva cita" << endl;
			CrearC();
			break;
		case 4:
			inicio();
			break;
	
	default:
		break;
	}
	
}
