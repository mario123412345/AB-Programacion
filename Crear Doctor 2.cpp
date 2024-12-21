#include "AB Programacion.h"

void doctorc() {
	cout << "Creando doctor" << endl;
	//almacenar: id, nombre, apellidos, especialidad, disponibilidad, ¿Despido?, salario
	int id;
	string nombre;
	string apellido1;
	string apellido2;
	string especialidad;
	string disponibilidad;
	string estado;
	double salario;
	
	cout << "ID doctor" << endl;
	cin>> id;
	cin.ignore();
	cout << "Nombre doctor: ";
	cin >> nombre;
	cout << "Apellido 1 doctor: " << endl;
	cin >> apellido1;
	cout << "Apellido 2 doctor: " << endl;
	cin >> apellido2;
	cout << "Especialidad del doctor: " << endl;
	cin >> especialidad;
	cout << "Disponibilidad doctor: " << endl;
	cin >> disponibilidad;
	cout << "Estado doetor: " << endl;
	cin >> estado;
	cout << "Salario doctor: " << endl;
	cin >> salario;
	
	ifstream archivo("doctores.json");
		nlohmann::json doctoresjson;
	if (archivo.is_open()) {
		archivo >> doctoresjson; 
		archivo.close();
	}
	else {
		cout << "Error" << endl;
	}
	nlohmann::json doctornuevo={
		{"ID", id},{"Nombre", nombre},{"Apellido1", apellido1},{"Apellido2", apellido2},{"Especialidad", especialidad},{"Disponibilidad", disponibilidad},{"Estado", estado },{"Salario", salario}
	};
	doctoresjson.push_back(doctornuevo);
	ofstream archivoSalida("doctores.json");
	if (archivoSalida.is_open()) {
		archivoSalida << doctoresjson.dump(4); 
		cout << "Doctor agregado correctamente" << endl;
	}
	else {
		cerr << "Errot" << endl;
	}

		
}