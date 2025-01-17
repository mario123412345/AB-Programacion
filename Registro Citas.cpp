
#include "AB Programacion.h"

#include <iostream>
#include <string>

void cita::registroc() {
    cout << "Registro de citas" << endl;
    cout << "-----------------------------------" << endl;
    ifstream archivo("citas.json");
    if (!archivo.is_open()) {
        cout << "Error para abrir el archivo" << endl;
    }
    json citasjson;
    try {
        archivo >> citasjson;
    }
    catch (const json::parse_error& e) {
        cout << "Error con el formato del archivo" << endl;
        return;
    }
    archivo.close();
    if (citasjson.empty()) {
        cout << "No hay citas" << endl;
        return;
    }
    ifstream archivopacientes("pacientes.json");
    if (!archivopacientes.is_open()) {
        cout << "Error para abrir el archivo de pacientes" << endl;
    }
    json pacientesjson;
    try {
        archivopacientes >> pacientesjson;
    }
    catch (const json::parse_error& e) {
        cout << "Error con el formato del archivo de pacientes" << endl;
        return;
    }
    ifstream archivodoctores("doctores.json");
    if (!archivodoctores.is_open()) {
        cout << "Error para abrir el archivo de doctores" << endl;
    }
    json doctoresjson;
    try {
        archivodoctores >> doctoresjson;
    }
    catch (const json::parse_error& e) {
        cout << "Error con el formato del archivo de doctores" << endl;
        return;
    }
    for (const auto& cita : citasjson) {
        cout << "ID: " << cita["ID"] << endl;
        cout << "Fecha de la cita(dd/mm/año): " << cita["Fecha"] << endl;
        cout << "Hora de la cita(24h): " << cita["Hora"] << endl;
        cout << "ID del paciente: " << cita["IDpac"] << endl;
        cout << "ID del doctor: " << cita["IDdoc"] << endl;
        cout << "-----------------------------------" << endl;
    }
}