#include "AB Programacion.h"
void peliminar() {
    int idp;
    cout << "ID del paciente que quieres eliminar:";
    cin >> idp;
    ifstream pacientesj("pacientes.json");
        if (!pacientesj.is_open()){
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
        for (auto it = pacientes.begin();
            it != pacientes.end();
            ++it) {
            if ((*it)["ID"] == idp) {
                pacienteselim.push_back(*it);
                it = pacientes.erase(it);
                cout << "Paciente con el id" << idp << "eliminado"<<endl;
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
 }


void EliminarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Eliminando paciente" << endl;
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
            peliminar();
            break;
    default:
        cout << "Error;" << endl;
        EliminarP();
        break;
    }
}