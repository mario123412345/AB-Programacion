#include "AB Programacion.h"

void EliminarC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Has seleccionado eliminar" << endl;
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
        cout << "Error" << endl;
        EliminarC();
        break;
    }
}