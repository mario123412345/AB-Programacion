#include "AB Programacion.h"

void EditarD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando Doctor" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
    switch (vol) {
        case 1:
            editar();
            break;
        case 2:
            inicio();
            break;
    default:
        cout << "Error" << endl;
        EditarD();
        break;
    }
}