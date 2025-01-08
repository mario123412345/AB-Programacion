#include "AB Programacion.h"

void buscardoctor() {
	cout << "Has seleccionado buscar doctores" << endl;
	ifstream archivo("doctores.json");
	if (archivo.is_open()) {
		cout << "Error al abrir el archivo" << endl;
	}
	json doctoresjson;
	archivo >> doctoresjson;
	archivo.close();
	int opcion;
	cout << "Por que filtro quieres buscar al o a los doctor/es?" << endl;
	cout << "1.ID" << endl;
	cout << "2.Nombre" << endl;
	cout << "3.Especialidad" << endl;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		int buscarporid;
		cout << "Introduce el ID del doctor" << endl;
		cin >> buscarporid;
		bool encontrado = false;
		for (const auto& doctor : doctoresjson) {
			if (doctor["ID"] == buscarporid) {
				cout << "Doctor con ID " << buscarporid << "encontrado:" << endl;
				cout << "Nombre " << doctor["Nombre"] << endl;
				cout << "Apellido1 " << doctor["Apellido1"] << endl;
				cout << "Apellido2:" << doctor["Apellido2"] << endl;
				cout << "Enfermedad:" << doctor["Especialidad"] << endl;
				encontrado = true;
				break;
			}
		}
		if (!encontrado) {
			cout << "No se encontró ningún doctor con ID" << buscarporid << endl;
		}
		break;
	}
	case 2: {
		string buscarpornombre;
		cout << "Introduce el nombre del doctor/es" << endl;
		cin.ignore();
		getline(cin, buscarpornombre);
		bool encontrado = false;
		for (const auto& doctor : doctoresjson) {
			if (doctor["Nombre"] == buscarpornombre) {
				cout << "Doctor con nombre" << buscarpornombre << " encontrado" << endl;
				cout << "ID" << doctor["ID"] << endl;
				cout << "Apellido1 " << doctor["Apellido1"] << endl;
				cout << "Apellido2 " << doctor["Apellido2"] << endl;
				cout << "Enfermedad " << doctor["Especialidad"] << endl;
				encontrado = true;
				break;
			}
		}
		if (!encontrado) {
			cout << "No se ha encontrado ningun doctor llamado" << buscarpornombre << endl;
		}
		break;
	}
	case 3: {
		string buscarporespecialidad;
		cout << "Introduce la especialidad del doctor/es" << endl;
		cin.ignore();
		getline(cin, buscarporespecialidad);
		bool encontrado = false;

		for (const auto& doctor : doctoresjson) {
			if (doctor["Especialidad"] == buscarporespecialidad) {
				cout << "Doctor con especialidad " << buscarporespecialidad << " encontrado:" << endl;
				cout << "ID" << doctor["ID"] << endl;
				cout << "Nombre " << doctor["Nombre"] << endl;
				cout << "Apellido1 " << doctor["Apellido1"] << endl;
				cout << "Apellido2 " << doctor["Apellido2"] << endl;
				encontrado = true;
			}
		}
		if (!encontrado) {
			cout << "No hay doctores con esta especialidad: " << buscarporespecialidad << endl;
		}
		break;
	}
	default:
		cout << "Selecciona una opción valida" << endl;
		break;
	}
}