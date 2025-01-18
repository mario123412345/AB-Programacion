#include "AB Programacion.h"

void paciente::eliminarpaciente(int idp) {
    ifstream pacientesj("pacientes.json");
    if (!pacientesj.is_open()) {
        cout << "Error , archivo de paacientes ya abierto";
    }
    json pacientes;
    pacientesj >> pacientes;
    pacientesj.close();
    json pacienteselim;
    ifstream pacienteselimjson("pacienteselim.json");
    if (pacienteselimjson.is_open()) {
        pacienteselimjson >> pacienteselim;
        pacienteselimjson.close();
    }
    bool encontrar = false;
    for (auto pac = pacientes.begin();
        pac != pacientes.end();
        ++pac) {
        if ((*pac)["ID"] == idp) {
            pacienteselim.push_back(*pac);
            pac = pacientes.erase(pac);
            cout << "Paciente con el id" << idp << "eliminado" << endl;
            encontrar = true;
            break;
        }
    }
    if (!encontrar) {
        cout << "Paciente" << idp << "no encontrado" << endl;
    }
    ofstream cambio("pacientes.json");
    if (!cambio.is_open()) {
        cout << "Error al guardar documento 1" << endl;
    }
    cambio << pacientes.dump(4);
    cambio.close();
    ofstream cambiodep("pacienteselim.json");
    if (!cambiodep.is_open()) {
        cout << "Error a guardar paciente eliminado" << endl;
    }
    cambiodep << pacienteselim.dump(4);
    cambiodep.close();
    backup("pacientes.json");
}
void peliminar() {
    int idp;
    cout << "ID del paciente que quieres eliminar:";
    cin >> idp;
    paciente::eliminarpaciente(idp);
}
void EliminarP() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "Eliminando paciente" << endl;
    cout << "1.Volver a la seccion anterior" << endl;
    cout << "2.Volver al inicio" << endl;
    cout << "3.Continuar" << endl;
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
            eliminar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            peliminar();
            break;
    default:
        cout << "Error;" << endl;
        EliminarP();
        break;
    }
}