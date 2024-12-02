
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
    switch (elimi) {
        case 1:
            cout << "Has seleccionado eliminar un Paciente" << endl;
            EliminarP();
            break;
        case 2:
            cout << "Has seleccionado eliminar un doctor" << endl;
            EliminarD();
            break;
        case 3:
            cout << "Has seleccionado eliminar una cita" << endl;
            EliminarC();
            break;
        case 4:
            inicio();
            break;
    default:
        cout << "Error, valor no existente" << endl;
        cout << "Reiniciando busqueda" << endl;
        cout << "----------------------------" << endl;
        eliminar();
        break;
    }
}