#include "AB Programacion.h"
void pacientec() {
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
	cout << "Apellido 2paciente: " << endl;
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
}
void CrearP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear paciente";
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cout << "COntinuar-->3" << endl;
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