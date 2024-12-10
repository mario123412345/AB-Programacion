
#include "AB Programacion.h"

#include <iostream>
#include <string>


void registrod() {
	cout << "Refistro de doctores" << endl;
	ifstream archivo("doctores.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo doctores.json" << endl;
	}
	json doctoresjson;
	archivo >> doctoresjson;
	for (const auto& doctor:doctoresjson) {
		cout << "ID:" << doctor["ID"] << endl;
		cout << "Nombre: " << doctor["Nombre"] << endl;
		cout<< "Apellido:" << doctor["Apellido1"] << endl;
		cout << "SEgundo apellido:" << doctor["Apellido2"] << endl;
		cout << "Especialidad del doctor:" << doctor["Especialidad"] << endl;
		cout << "Disponibilidad: " << doctor["Disponibilidad"] << endl;
		cout << "Estado:" << doctor["Estado"] << endl;
		cout << "Salario:" << doctor["Salario"] << endl;

	}
}
