#include "AB Programacion.h"
void buscar() {
	cout << "Has seleccionado buscar, aquí podrás buscar citas, pacientes o doctores o aplicar filtros en las busquedas de los mismos" << endl;
	cout << "Que quieres buscar?" << endl;
	cout << "Pacientes-->1" << endl;
	cout << "Doctores-->2" << endl;
	cout << "Citas-->3" << endl;
	int eleccion;
	cin >> eleccion;
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
