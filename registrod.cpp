
#include "AB Programacion.h"

#include <iostream>
#include <string>


void registrod() {
	cout << "Refistro de doctores" << endl;
	cout << "-----------------------------------" << endl;
	ifstream archivo("doctores.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo doctores.json" << endl;
		return;
	}
	json doctoresjson;
	archivo >> doctoresjson;
	for (const auto& doctor:doctoresjson) {
		cout << "ID:" << doctor["ID"] << endl;
		cout << "Nombre: " << doctor["Nombre"];
		cout<< "Apellido:" << doctor["Apellido1"];
		cout << "SEgundo apellido:" << doctor["Apellido2"] << endl;;
		cout << "Especialidad del doctor:" << doctor["Especialidad"];
		cout << "Disponibilidad: " << doctor["Disponibilidad"];
		cout << "Estado:" << doctor["Estado"] << endl;
		cout << "Salario:" << doctor["Salario"] << endl;
		cout << "-----------------------------------" << endl;

	}
}
