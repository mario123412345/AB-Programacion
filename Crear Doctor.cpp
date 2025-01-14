#include "AB Programacion.h"
doctor::doctor(int id, const string& nombre, const string& apellido1, const string& apellido2,const string& especialidad, const string& disponibilidad, const string& estado, double salario)
	: id(id), nombre(nombre), apellido1(apellido1), apellido2(apellido2),especialidad(especialidad), disponibilidad(disponibilidad), estado(estado), salario(salario) {
}
void doctor::guardardoctor() const {
	ifstream archivo("doctores.json");
	nlohmann::json doctoresjson;
	if (archivo.is_open()) {
		archivo >> doctoresjson;
		archivo.close();
	}
	else {
		cout << "Error1" << endl;
	}
	nlohmann::json nuevodoctor = {{"ID", id},{"Nombre", nombre},{"Apellido1", apellido1},{"Apellido2", apellido2},{"Especialidad", especialidad},{"Disponibilidad", disponibilidad},{"Estado", estado},{"Salario", salario}
	};
	doctoresjson.push_back(nuevodoctor);
	ofstream nuevarch("doctores.json");
	if(nuevarch.is_open()){
		nuevarch << doctoresjson.dump(4);
		cout << "Doctor creado" << endl;
	}else{
		cout << "Error2" << endl;
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
		cin >> nombre;
		cout << "Apellido 1 del doctor:";
		cin >> apellido1;
		cout << "Apellido 2 del doctor:";
		cin >> apellido2;
		cout << "Especialidad del doctor:";
		cin >> especialidad;
		cout << "Disponibilidad del doctor:";
		cin >> disponibilidad;
		cout << "Estado del doctor(C-Contratado/D-Despedido):";
		cin >> estado;
		cout << "Salario del doctor:";
		cin >> salario;
		return doctor(id, nombre, apellido1, apellido2, especialidad, disponibilidad, estado, salario);
	}

void doctorc() {
	cout << "Creando doctror" << endl;
	doctor doctornuevo = doctor::creardoctor();
	doctornuevo.guardardoctor();
}

void CrearD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear Doctor";
	cout << "Continuar -->1" << endl;
	cout << "Inicio -->2" << endl;
	cout << "Volver-->3" << endl;
	
	cin >> vol;
	switch (vol) {
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