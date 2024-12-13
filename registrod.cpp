
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
        cout << "ID:" << doctor["ID"] << endl;
        cout << "Nombre:" << doctor["Nombre"] << endl;
        cout << "Apellido 1:" << doctor["Apellido1"] << endl;
        cout << "Apellido 2:" << doctor["Apellido2"] << endl;
        cout << "Especialidad:" << doctor["Especialidad"] << endl;
        cout << "Disponibilidad:" << doctor["Disponibilidad"] << endl;
        cout << "Estado:" << doctor["Estado"] << endl;
        cout << "Salario:" << doctor["Salario"] << endl;
        cout << "-----------------------------------" << endl;
    }
}
