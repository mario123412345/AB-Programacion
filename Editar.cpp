

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
	switch (ed) {
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