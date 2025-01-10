

#include "AB Programacion.h"

#include <iostream>
#include <string>


void visual() {
	int op;
    cout << "Aqui puedes ver todo el registro de pacientes/doctores/citas de seguido , si quieres buscar algo especifico ve a la opción de buscar" << endl;
	cout << "Que quieres visualizar" << endl;
	cout << "Pacientes --> 1" << endl;
	cout << "Doctores --> 2" << endl;
	cout << "Citas --> 3" << endl;
	cin>> op;
    switch (op) {
        case 1:
            registrop();
            break;
        case 2:
            registrod();
            break;
        case 3:
            registroc();
            break;
    default:
        cout << "Error" << endl;
        visual();
        break;
    }

}