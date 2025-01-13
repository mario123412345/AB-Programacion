#include "AB Programacion.h"
void buscar() {
	cout << "Has seleccionado buscar, aquí podrás buscar citas, pacientes o doctores o aplicar filtros en las busquedas de los mismos" << endl;
	cout << "Que quieres buscar?" << endl;
	cout << "1.Pacientes" << endl;
	cout << "2.Doctores" << endl;
	cout << "3.Citas" << endl;
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
