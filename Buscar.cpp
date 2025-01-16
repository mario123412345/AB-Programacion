#include "AB Programacion.h"
void buscar() {
	cout << "Has seleccionado buscar, aquí podrás buscar citas, pacientes o doctores o aplicar filtros en las busquedas de los mismos" << endl;
	cout << "Que quieres buscar?" << endl;
	cout << "1.Pacientes" << endl;
	cout << "2.Doctores" << endl;
	cout << "3.Citas" << endl;
	int eleccion;
	while (true) {
		string input;
		cin >> input;
		stringstream ss(input);
		if (ss >> eleccion && ss.eof()) {
			break;
		}
		else {
			cout << "Esscribe un numero valido ";
		}
	}
	switch (eleccion){
	case 1:
		buscarpaciente();
			break;
	case 2:
		buscardoctor();
		break;
	case 3:
		buscarcita();
		break;
	default:
		cout << "Error" << endl;
		break;
	}
}
