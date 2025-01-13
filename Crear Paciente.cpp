#include "AB Programacion.h"
/*void pacientec() {
	cout << "Creando paciente" << endl;
	//almacenar: id, nombre, apellidos, enfermedad, f.baja,f.alta
	int id;
	string nombre;
	string apellido1;
	string apellido2;
	string enfermedad;
	string fechaalta;
	string fechabaja;

	cout << "ID paciente" << endl;
	cin >> id;
	cin.ignore();
	cout << "Nombre paciente: ";
	cin >> nombre;
	cout << "Apellido 1 paciente: " << endl;
	cin >> apellido1;
	cout << "Apellido 2 paciente: " << endl;
	cin >> apellido2;
	cout << "Enfermedad paciente: " << endl;
	cin >> enfermedad;
	cout << "Fecha baja paciente:(dia/mes/año)" << endl;
	cin >> fechabaja;
	cout << "Fecha alta paciente:(dia/mes/año) " << endl;
	cin >> fechaalta;

	ifstream archivo("pacientes.json");
	nlohmann::json pacientesjson;
	if (archivo.is_open()) {
		archivo >> pacientesjson;
		archivo.close();
	}
	else {
		cout << "Error" << endl;
	}
	nlohmann::json pacientenuevo={
		{"ID", id},{"Nombre", nombre},{"Apellido1", apellido1},{"Apellido2", apellido2},{"Enfermedad", enfermedad},{"Fecha baja", fechabaja},{"Fecha alta", fechaalta }
	};
	pacientesjson.push_back(pacientenuevo);
	ofstream archivosalida("pacientes.json");
	if (archivosalida.is_open()) {
		archivosalida << pacientesjson.dump(4);
		cout << "Paciente agregado correctamente" << endl;
	}
	else{
		cerr << "Error" << endl;
	}
}*/
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
		cout << "Error1" << endl;
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
		cout << "Error" << endl;
	}
}
paciente paciente::crearpaciente() {
	int id=0;
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
	cin >> nombre;
	cout << "Apellido 1 paciente: " << endl;
	cin >> apellido1;
	cout << "Apellido 2 paciente: " << endl;
	cin >> apellido2;
	cout << "Enfermedad paciente: " << endl;
	cin >> enfermedad;
	cout << "Fecha baja paciente:(dia/mes/año)" << endl;
	cin >> fechabaja;
	cout << "Fecha alta paciente:(dia/mes/año) " << endl;
	cin >> fechaalta;

	return paciente(id,nombre,apellido1,apellido2,enfermedad,fechabaja,fechaalta);
}
void pacientec() {
	cout << "Creando paciente" << endl;
	paciente paciente = paciente::crearpaciente();
	paciente.guardarpaciente();
}
void CrearP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear paciente";
	cout << "1.Volver" << endl;
	cout << "2.Inicio" << endl;
	cout << "3.COntinuar" << endl;
	cin >> vol;
	switch (vol) {
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