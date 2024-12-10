#include "AB Programacion.h"

void EliminarD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Eliminando doctor" << endl;
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

            break;
    default:
        cout << "Error" << endl;
        EliminarD();
        break;
    }
}