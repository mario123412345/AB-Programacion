

#include "AB Programacion.h"

#include <iostream>
#include <string>


void visual() {
	int op;
    cout << "Aqui puedes ver todo el registro de pacientes/doctores/citas de seguido , si quieres buscar algo especifico ve a la opción de buscar" << endl;
	cout << "Que quieres visualizar" << endl;
	cout << "1.Pacientes --> 1" << endl;
	cout << "2.Doctores --> 2" << endl;
	cout << "3.Citas --> 3" << endl;
    while (true) {
        string input;
        cin >> input;
        stringstream ss(input);
        if (ss >> op && ss.eof()) {
            break;
        }
        else {
            cout << "Esscribe un numero valido ";
        }
    }
    switch (op) {
        case 1:
            paciente::registrop();
            break;
        case 2:
            doctor::registrod();
            break;
        case 3:
            cita::registroc();
            break;
    default:
        cout << "Error" << endl;
        visual();
        break;
    }

}