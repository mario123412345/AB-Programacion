
#include "AB Programacion.h"

#include <iostream>
#include <string>


void registrod() {
    cout << "Registro de doctores" << endl;
    cout << "-----------------------------------" << endl;

    ifstream archivo("doctores.json");
    if (!archivo.is_open()) {
        cout << "Error1" << endl;
        return;
    }
    json doctoresjson;
    try {
        archivo >> doctoresjson;
    }
    catch (const json::parse_error& e) {
        cout << "Error2" <<  endl;
        return;
    }
    if (doctoresjson.empty()) {
        cout << "No hay doctores " << endl;
        return;
    }
    for (const auto& doctor : doctoresjson) {
        cout << "ID:" << doctor.value("ID", "N/A") << endl;
        cout << "Nombre: " << doctor.value("Nombre", "N/A") << endl;
        cout << "Apellido:" << doctor.value("Apellido1", "N/A") << endl;
        cout << "Segundo apellido: " << doctor.value("Apellido2", "N/A") << endl;
        cout << "Especialidad del doctor: " << doctor.value("Especialidad", "N/A") << endl;
        cout << "Disponibilidad: " << doctor.value("Disponibilidad", "N/A") << endl;
        cout << "Estado: " << doctor.value("Estado", "N/A") << endl;
        cout << "Salario: " << doctor.value("Salario", "N/A") << endl;
        cout << "-----------------------------------" << endl;
    }
}
