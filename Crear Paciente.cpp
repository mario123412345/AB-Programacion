#include "AB Programacion.h"

paciente::paciente(int id, const string& nombre, const string& apellido1,const string& apellido2, const string& enfermedad,const string& fechaalta, const string& fechabaja)
	: id(id), nombre(nombre), apellido1(apellido1), apellido2(apellido2),enfermedad(enfermedad), fechaalta(fechaalta), fechabaja(fechabaja) {}

void paciente::guardarpaciente()const {
	ifstream archivo("pacientes.json");
	nlohmann::json pacientesjson;
	if (archivo.is_open()) {
		archivo >> pacientesjson;
		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo de pacientes para guardar" << endl;
	}

	nlohmann::json pacientenuevo = {
		{"ID", id}, {"Nombre", nombre}, {"Apellido1", apellido1},{"Apellido2", apellido2}, {"Enfermedad", enfermedad},{"Fecha baja", fechabaja}, {"Fecha alta", fechaalta}
	};
	pacientesjson.push_back(pacientenuevo);
	ofstream archivosalida("pacientes.json");
	if (archivosalida.is_open()) {
		archivosalida << pacientesjson.dump(4);
		cout << "Paciente creado correctamente" << endl;

	}
	else {
		cout << "Error al guardar en paientes.json" << endl;
	}
}
paciente paciente::crearpaciente() {
	int id=1;
	string nombre;
	string apellido1;
	string apellido2;
	string enfermedad;
	string fechaalta;
	string fechabaja;
	ifstream archivo("pacientes.json");
	json pacientesjson;
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de pacientes" << endl;
	} else {
		archivo >> pacientesjson;
		archivo.close();

		if (!pacientesjson.empty()){
			id = pacientesjson.back()["ID"].get<int>()+1;
		}
	}
	cout << "Creando paciente con ID: " << id << endl;
	cout << "Nombre paciente: ";
	cin.ignore(); 
	getline(cin, nombre);
	cout << "Apellido 1 paciente: " << endl;
	getline(cin, apellido1);
	cout << "Apellido 2 paciente: " << endl;
	getline(cin, apellido2);
	cout << "Enfermedad paciente: " << endl;
	getline(cin, enfermedad);
	cout << "Fecha baja paciente:(dia/mes/año)" << endl;
	getline(cin, fechabaja);
	cout << "Fecha alta paciente:(dia/mes/año) " << endl;
	getline(cin, fechaalta);
	backup("pacientes.json");
	return paciente(id,nombre,apellido1,apellido2,enfermedad,fechabaja,fechaalta);
}
void pacientec() {
	cout << "Creando paciente" << endl;
	paciente paciente = paciente::crearpaciente();
	paciente.guardarpaciente();
}
void CrearP() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "Crear paciente" << endl;
	cout << "1.Volver" << endl;
	cout << "2.Inicio" << endl;
	cout << "3.COntinuar" << endl;
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
			crear();
			break;
		case 2:
			inicio();
			break;
		case 3:
			pacientec();
			break;
	default:
		cout << "Error" << endl;
		CrearP();
		break;
	}
	
}