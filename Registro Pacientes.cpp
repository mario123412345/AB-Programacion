
#include "AB Programacion.h"

#include <iostream>
#include <string>

void paciente::registrop() {
        cout << "Registro de pacientes" << endl;
        cout << "-----------------------------------" << endl;
        ifstream archivo("pacientes.json");
        if (!archivo.is_open()) {
            cout << "Error" << endl;
            
        }
        json pacientesjson;
        try {
            archivo >> pacientesjson;
        }
        catch (const json::parse_error& e) {
            cout << "Error1" << endl;
            return;
        }
        if (pacientesjson.empty()) {
            cout << "No hay pacientes " << endl;
            return;
        }
        for (const auto& paciente : pacientesjson) {
            cout << "ID: " << paciente["ID"] << endl;
            cout << "Nombre: " << paciente["Nombre"] << endl;
            cout << "Apellido 1: " << paciente["Apellido1"] << endl;
            cout << "Apellido 2: " << paciente["Apellido2"] << endl;
            cout << "Enfermedad: " << paciente["Enfermedad"] << endl;
            cout << "Fecha de baja: " << paciente["Fecha baja"] << endl;
            cout << "Fecha de alta: " << paciente["Fecha alta"] << endl;
            cout << "-----------------------------------" << endl;
        }
}
