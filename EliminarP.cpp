#include "AB Programacion.h"

void EliminarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Eliminando paciente" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
    switch (vol) {
        case 1:
            eliminar();
            break;
        case 2:
            inicio();
            break;
    default:
        cout << "Error;" << endl;
        EliminarP();
        break;
    }
}