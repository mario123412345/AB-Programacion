#include "AB Programacion.h"
cita::cita(int id, const string& fecha, const string& hora, int idp, int idd)
	:id(id),fecha(fecha),hora(hora),idp(idp),idd(idd){}
void cita::guardarcita() const {
	ifstream archivo("citas.json");
	nlohmann::json citasjson;
	if (archivo.is_open()) {
		archivo >> citasjson;
		archivo.close();
	}
	else {
		cout << "Error1" << endl;
	}
	nlohmann::json nuevacita = { {"ID",id},{"Fecha",fecha},{"Hora",hora},{"IDpac",idp},{"IDdoc",idd}
	};
	citasjson.push_back(nuevacita);
	ofstream nuevarch("citas.json");
	if (nuevarch.is_open()) {
		nuevarch <<citasjson.dump(4);
		cout << "Cita creada" << endl;
	}
	else {
		cout << "Error2" << endl;
	}
}
cita cita ::crearcita() {
	int id=1;
	string fecha;
	string hora;
	int idp;
	int idd;
	ifstream archivo("citas.json");
	json citasjson;
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de citas" << endl;
	}
	else {
		archivo >> citasjson;
		archivo.close();
		if (!citasjson.empty()) {
			id = citasjson.back()["ID"].get<int>() + 1;
		}
	}
	cout << "Creando cita con ID: " << id << endl;
	cout << "Fecha de la cita(dd/mm/año): ";
	cin >> fecha;
	cout << "Hora de la cita: " << endl;
	cin >> hora;
	cout << "ID del paciente de la cita: " << endl;
	cin >> idp;
		ifstream paciente("pacientes.json");
		if (paciente.is_open()) {
			cout << "Error con el archivo de pacientes" << endl;
		}
		json pacientesjson;
		paciente >> pacientesjson;
		paciente.close();
		bool encontrarpaciente = false;
		json pacienteusado;
		for (const auto& paci : pacientesjson) {
			if (paci["ID"] == idp) {
				cout << "Información de paciente con id" << idp << endl;
				cout << "Nombre: " << paci["Nombre"] << endl;
				cout << "Apellido 1: " << paci["Apellido1"] << endl;
				cout << "Apellido 2: " << paci["Apellido2"] << endl;
				cout << "Enfermedad: " << paci["Enfermedad"] << endl;
				cout << "Fecha de baja: " << paci["Fecha baja"] << endl;
				cout << "Fecha de alta: " << paci["Fecha alta"] << endl;
				encontrarpaciente = true;
				break;
			}
		}
		if (!encontrarpaciente) {
			cout << "Error, paciente con id" << idp << "no encontrado" << endl;
			return cita(id, fecha, hora, idp, idd);
		}

	cout << "ID del doctor de la cita: " << endl;
	cin >> idd;
		ifstream doctor("doctores.json");
		if (doctor.is_open()) {
			cout << "Error con el archivo de doctores" << endl;
		}
		json doctoresjson;
		doctor >> doctoresjson;
		doctor.close();
		bool encontrardoctor = false;
		json doctorusado;
		for (const auto& doc : doctoresjson) {
			if (doc["ID"]==idd){
				cout << "Información del doctor con id" << idd << endl;
				cout << "Nombre:" << doc["Nombre"] << endl;
				cout << "Apellido 1:" << doc["Apellido1"] << endl;
				cout << "Apellido 2:" << doc["Apellido2"] << endl;
				cout << "Especialidad:" << doc["Especialidad"] << endl;
				cout << "Disponibilidad:" << doc["Disponibilidad"] << endl;
				cout << "Estado:" << doc["Estado"] << endl;
				cout << "Salario:" << doc["Salario"] << endl;
				encontrardoctor = true;
				break;
			}
		}
		if (!encontrardoctor) {
			cout << "Error, doctor con el id" << idd << "no encontrado" << endl;
			return cita(id, fecha, hora, idp, idd);
		}
	//Poner algun condicionante que no permita poner a cualquier doctor con cualquier paciente en la cita
	cita nuevacita(id, fecha, hora, idp, idd);
	nuevacita.guardarcita();
	return nuevacita;
}
void citac() {
	cout << "Creando cita" << endl;
	cita nuevaCita = cita::crearcita();
}
void CrearC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Crear Cita";
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cout << "Continuar-->3" << endl;
	cin >> vol;
	switch (vol) {
		case 1:
			crear();
			break;
		case 2:
			inicio();
			break;
		case 3:
			citac();
			break;
		default:
			CrearC();
			break;

	}
	
}