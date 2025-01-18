#include "AB Programacion.h"
doctor::doctor(int id, const string& nombre, const string& apellido1, const string& apellido2,const string& especialidad, const string& disponibilidad, const string& estado, double salario)
	: id(id),nombre(nombre),apellido1(apellido1),apellido2(apellido2),
	especialidad(especialidad), disponibilidad(disponibilidad),estado(estado),salario(salario){}

void doctor::guardardoctor() const {
	ifstream archivo("doctores.json");
	nlohmann::json doctoresjson;
	if (archivo.is_open()) {
		archivo >> doctoresjson;
		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo de doctores.json" << endl;
	}
	nlohmann::json nuevodoctor = { {"ID", id},{"Nombre", nombre},{"Apellido1", apellido1},{"Apellido2", apellido2},{"Especialidad", especialidad},{"Disponibilidad", disponibilidad},{"Estado", estado},{"Salario", salario}
	};
	doctoresjson.push_back(nuevodoctor);
	ofstream nuevoarchivo("doctores.json");
	if (nuevoarchivo.is_open()) {
		nuevoarchivo << doctoresjson.dump(4);
		cout << "Doctor creado" << endl;

	}
	else {
		cout << "Error al guardar al doctor creado" << endl;
	}
}

doctor doctor::creardoctor() {
	int id=1;
	string nombre;
	string apellido1;
	string apellido2;
	string especialidad;
	string disponibilidad;
	string estado;
	double salario;
	ifstream archivo("doctores.json");
	json doctoresjson;
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de doctores" << endl;
	}
	else {
		archivo >> doctoresjson;
		archivo.close();

		if (!doctoresjson.empty()) {
			id = doctoresjson.back()["ID"].get<int>() + 1;
		}
	}
	cout << "Creando dcotor con ID: " << id << endl;
	cout << "Nombre doctor:";
	cin.ignore();
	getline(cin, nombre);
	cout << "Apellido 1 del doctor:";
	getline(cin, apellido1);
	cout << "Apellido 2 del doctor:";
	getline(cin, apellido2);
	cout << "Especialidad del doctor:";
	getline(cin, especialidad);
	cout << "Disponibilidad del doctor:";
	getline(cin, disponibilidad);
	cout << "Estado del doctor(C-Contratado/D-Despedido):";
	getline(cin, estado);
	cout << "Salario del doctor:";
	cin >> salario;
	backup("doctores.json");
	return doctor(id, nombre, apellido1, apellido2, especialidad, disponibilidad, estado, salario);
}

void doctorc() {
	cout << "Creando doctror" << endl;
	doctor doctornuevo = doctor::creardoctor();
	doctornuevo.guardardoctor();
}

void CrearD() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "Crear Doctor" << endl;
	cout << "1.Continuar" << endl;
	cout << "2.Inicio" << endl;
	cout << "3.Volver" << endl;
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
			doctorc();
			break;
		case 2:
			inicio();
			break;
		case 3:
			crear();
			break;
	default:
		cout << "Error" << endl;
		CrearD();
		break;
	}
	
}