
#include "AB Programacion.h"


void eliminar() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "¿Que quieres eliminar?" << endl;
	cout << "1.Paciente " << endl;
	cout << "2.Doctor " << endl;
	cout << "3.Cita" << endl;
	cout << "4.Volver al inicio " << endl;
	cout << "¿Que quieres eliminar?" << endl;
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