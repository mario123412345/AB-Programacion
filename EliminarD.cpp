#include "AB Programacion.h"
void deliminar() {
    cout << "ID del doctor que quieres eliminar: ";
    int ide;
    cin >> ide;
   
}

void EliminarD() {
	int vol;
	cout << "----------------------------" << endl;
    cout << "Has elegido Eliminar un docotr" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
    cout << "Continuar-->3" << endl;
	cin >> vol;
    switch (vol) {
        case 1:
            eliminar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            deliminar();
            break;
    default:
        cout << "Error" << endl;
        EliminarD();
        break;
    }
}