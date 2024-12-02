#include "AB Programacion.h"

void EditarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando paciente" << endl;
	cout << "Para editar un paciente se neesita saber el ID o el nombre/apellidos" << endl;
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
        EditarP();
        break;
    }
}