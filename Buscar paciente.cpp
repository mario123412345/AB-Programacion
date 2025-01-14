#include "AB Programacion.h"
void buscarpaciente() {
	cout << "Has seleccionado buscar paciente" << endl;
	ifstream archivo("pacientes.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo" << endl;
	}
	json pacientesjson;
	archivo >> pacientesjson;
	archivo.close();
	int opcion;
	cout << "Por que filtro quieres buscar al paciente?" << endl;
	cout << "1.ID" << endl;
	cout << "2.Nombre" << endl;
	cout << "3.Enfermedad" << endl;
	cin >> opcion; 
	switch (opcion){
	//Case 1 funciona
	case 1:{
		int buscarporid;
		cout << "Introduce el ID del paciente"<<endl;
		cin >> buscarporid;
		bool encontrado = false;
		for (const auto& paciente : pacientesjson) {
			if (paciente["ID"] == buscarporid) {
				cout << "Paciente con ID " << buscarporid << "encontrado:" << endl;
				cout << "Nombre " << paciente["Nombre"] << endl;
				cout << "Apellido1 " << paciente["Apellido1"] << endl;
				cout << "Apellido2:" << paciente["Apellido2"] << endl;
				cout << "Enfermedad:" << paciente["Enfermedad"] << endl;
				cout << "Fecha de baja" << paciente["Fecha baja"] << endl;
				cout << "Fecha de alta" << paciente["Fecha alta"] << endl;
				encontrado = true;
				break;
			}
		}
		if (!encontrado) {
			cout << "No se encontró ningún paciente con ID" << buscarporid << endl;
		}
		break;
	}
		  //Case 2 funciona
	case 2:{
		string buscarpornombre;
		cout << "Introduce el nombre del paciente o de los pacientes"<<endl;
		cin.ignore();
		getline(cin, buscarpornombre);
		bool encontrado = false;
		for (const auto& paciente : pacientesjson) {
			if (paciente["Nombre"] == buscarpornombre) {
				cout << "Paciente con nombre" << buscarpornombre << " encontrado" << endl;
				cout << "ID" << paciente["ID"] << endl;
				cout << "Apellido1 " << paciente["Apellido1"] << endl;
				cout << "Apellido2 " << paciente["Apellido2"] << endl;
				cout << "Enfermedad " << paciente["Enfermedad"] << endl;
				encontrado = true;
				break;
			}
		}
		if (!encontrado) {
			cout << "No se ha encontrado ningun paciente llamado" << buscarpornombre << endl;
		}
		break;
	}
	//Case 3 funciona
	case 3:{
		string buscarporenfermedad;
		cout << "Introduce la enfermedad del paciente o de los pacientes" << endl;
		cin.ignore();
		getline(cin, buscarporenfermedad);
		bool encontrado = false;

		for (const auto& paciente : pacientesjson) {
			if (paciente["Enfermedad"] == buscarporenfermedad) {
				cout << "Paciente con enfermedad " << buscarporenfermedad << " encontrado:" << endl;
				cout << "ID" << paciente["ID"] << endl;
				cout << "Nombre " << paciente["Nombre"] << endl;
				cout << "Apellido1 " << paciente["Apellido1"] << endl;
				cout << "Apellido2 " << paciente["Apellido2"] << endl;
				encontrado = true;
			}
		}
		if (!encontrado) {
			cout << "No hay pacientes con esta enfermedad: " << buscarporenfermedad << endl;
		}
		break;
	}
	default:
		cout << "Selecciona una opción valida" << endl;
		break;
	}
}