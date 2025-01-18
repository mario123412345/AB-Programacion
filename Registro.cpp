

#include "AB Programacion.h"

#include <iostream>
#include <string>


void visual() {
	int opcion;
    cout << "Aqui puedes ver todo el registro de pacientes/doctores/citas de seguido , si quieres buscar algo especifico ve a la opción de buscar" << endl;
	cout << "Que quieres visualizar" << endl;
	cout << "1.Pacientes" << endl;
	cout << "2.Doctores" << endl;
	cout << "3.Citas" << endl;
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