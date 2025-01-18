#include "AB Programacion.h"
//Reporte de pacientes en un rango de fecha

tm convertirfecha(const string& fecha) {
	tm tmFecha = {};
	istringstream ss(fecha);
	ss >>get_time(&tmFecha, "%d/%m/%Y");  
	if (ss.fail()) {
		cerr << "Error al convertir la fecha" << endl;
		tmFecha = {};
	}
	return tmFecha;
}

void paciente::reportepacientes(const string& fechainicio, const string& fechafinal) {
	ifstream archivo("pacientes.json");
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo de pacientes" << endl;
		return;
	}
	json pacientesjson;
	archivo >> pacientesjson;
	archivo.close();
	tm tmInicio = convertirfecha(fechainicio);
	tm tmFinal = convertirfecha(fechafinal);
	if (tmInicio.tm_year ==0 || tmFinal.tm_year==0) {
		cerr << "Fecha o fechas introducidas no son valiidas" << endl;
		return;
	}
	time_t tInicio = mktime(&tmInicio);
	time_t tFinal = mktime(&tmFinal);
	cout << "Pacientes atendidos entre"<<fechainicio<<"y"<<fechafinal<< endl;
	bool encontrado = false;
	for (const auto& paciente : pacientesjson) {
		if (!paciente.contains("Fecha alta") || !paciente.contains("Fecha baja")) {
			cerr << "Error,el paciente con ID"<<paciente["ID"]<<"no tiene fechas válidas" << endl;
			continue;
		}
		string fechaalta=paciente["Fecha alta"];
		string fechabaja=paciente["Fecha baja"];
		tm tmFechaAlta = convertirfecha(fechaalta);
		tm tmFechaBaja = convertirfecha(fechabaja);
		if (tmFechaAlta.tm_year==0 || tmFechaBaja.tm_year==0) {
			cerr << "Error al convertir las fechas del paciente con ID"<<paciente["ID"] << endl;
			continue;
		}
		time_t tFechaAlta = mktime(&tmFechaAlta);
		time_t tFechaBaja = mktime(&tmFechaBaja);
		if (tFechaAlta <= tFinal && tFechaBaja >= tInicio) {
			cout << "ID del paciente" << paciente["ID"] << endl;
			cout << "Nombre " << paciente["Nombre"] << endl;
			cout << "Apellidos " << paciente["Apellido1"] <<  paciente["Apellido2"] << endl;
			cout << "Enfermedad " << paciente["Enfermedad"] << endl;
			cout << "Fecha de alta:" << paciente["Fecha alta"] << endl;
			cout << "Fecha de baja:" << fechabaja << endl;
			cout << "-----------------------------------------" << endl;
			encontrado = true;
		}
	}

	if (!encontrado) {
		cout << "No se encontraron pacientes en el rango de fechas especificado." << endl;
	}
}
//Citas pendientes por medico
void citaspendientes() {
	ifstream archivocitas("citas.json");
	if (!archivocitas.is_open()) {
		cout << "Error al abrir el archivo de citas" << endl;
	}
	ifstream archivodoctores("doctores.json");
	if (!archivodoctores.is_open()) {
		cout << "Error al abrir el archivo de doctores" << endl;
	}
	json doctoresjson;
	archivodoctores >> doctoresjson;
	archivodoctores.close();
	json citasjson;
	archivocitas >> citasjson;
	archivocitas.close();
	string fechahoy;
	cout << "Esscribe la fecha actual(dia/mes/año)";
	cin >> fechahoy;
	if (fechahoy.length() != 10 || fechahoy[2] != '/' || fechahoy[5] != '/') {
		cout << "La fecha debe seguir este orden dd/mm/yyyy." << endl;
	}
	tm tmfechahoy = convertirfecha(fechahoy);
	map<int, vector<json>> citaspendientesmedico;
	for (const auto& cita:citasjson) {
		string fechacita=cita["Fecha"];
		tm tmfechacita=convertirfecha(fechacita);
		time_t t1 = mktime(&tmfechahoy);
		time_t t2 = mktime(&tmfechacita);
		if (t2 > t1) {
			int iddoctor=cita["IDdoc"];
			citaspendientesmedico[iddoctor].push_back(cita);
		}
	}
	cout << "Citas pendientes por médico:" << endl;
	for (const auto& doctor : doctoresjson) {
		int iddoctor = doctor["ID"];
		string nombredoctor = doctor["Nombre"];
		string apellido1doctor = doctor["Apellido1"];
		string apellido2doctor = doctor["Apellido2"];
		string especialidad = doctor["Especialidad"];
		if (citaspendientesmedico.count(iddoctor)) {
			cout << "Doctor: " << nombredoctor << " " << apellido1doctor << " " << apellido2doctor << endl;
			cout << "Especialidad: " << especialidad << endl;
			cout << "-------------------------------------------" << endl;
			for (const auto& cita : citaspendientesmedico[iddoctor]) {
				cout << "  ID de la cita " << cita["ID"] << endl;
				cout << "  Fecha de la cita " << cita["Fecha"] << endl;
				cout << "  Hora de la cita" << cita["Hora"] << endl;
				cout << "  ID del paciente" << cita["IDpac"] << endl;
				cout << "-------------------------------------------" << endl;
			}
		}
	}
}
//Reporte citas pendientes por especialidad
void citasespecialidad() {
	ifstream archivodoctores("doctores.json");
	if (!archivodoctores.is_open()) {
		cout << "Error al abrir el archivo de doctores" << endl;
		return;
	}
	ifstream archivocitas("citas.json");
	if (!archivocitas.is_open()) {
		cout << "Error al abrir el archivo de citas" << endl;
		return;
	}
	json doctoresjson;
	json citasjson;
	archivodoctores >> doctoresjson;
	archivocitas >> citasjson;
	archivodoctores.close();
	archivocitas.close();
	map<string, vector<string>> citasporespecialidad;
	for (const auto& doctor : doctoresjson) {
		string especialidad = doctor["Especialidad"];
		string nombredoctor = doctor["Nombre"];
		string apellido1doctor = doctor["Apellido1"];
		string apellido2doctor = doctor["Apellido2"];
		for (const auto& cita : citasjson) {
			int iddoctor = cita["IDdoc"];  
			int idpaciente = cita["IDpac"];  
			string fechacita = cita["Fecha"];
			string horacita = cita["Hora"];
			if (iddoctor == doctor["ID"]) {
				string citadetalle = "ID del paciente" + to_string(idpaciente) + ", fecha de la cita" + fechacita +
					", hora de la cita" + horacita + ", datos del doctor:" + nombredoctor + " " + apellido1doctor + " " + apellido2doctor;
				citasporespecialidad[especialidad].push_back(citadetalle);
			}
		}
	}
	cout << "Reporte de citas pendientes por especialidad" << endl;
	for (const auto& especialidad : citasporespecialidad) {
		cout << "Especialidad" << especialidad.first << endl;
		for (const auto& cita : especialidad.second) {
			cout << cita << endl;
		}
		cout << "-------------------------------" << endl;
	}
}

//Reporte enfermedades cronicas
bool enfermedadcronica(const string enfermedad) {
	vector enfermedadescronicas = { "Diabetes","diabetes","Cancer","cancer","Hipertension","hipertension","Asma","asma" };
	return find(enfermedadescronicas.begin(), enfermedadescronicas.end(), enfermedad) != enfermedadescronicas.end();
}
void paciente::reporteenfermedadescronicas() {
	ifstream archivo("pacientes.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de pacientes" << endl;
	}
	json pacientesjson;
	archivo >> pacientesjson;
	archivo.close();
	cout << "Pacientes con enfermedades cronicas:" << endl;
	cout << "-------------------------------------" << endl;
	for (const auto& paciente : pacientesjson) {
		string enfermedad = paciente["Enfermedad"];
		if (enfermedadcronica(enfermedad)) {
			cout << "ID" << paciente["ID"] << endl;
			cout << "Nombre" << paciente["Nombre"] << endl;
			cout << "Apellidos" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
			cout << "Enferemdad" << paciente["Enfermedad"] << endl;
			cout << "-------------------------------------" << endl;
		}
	}
}
//Reporte doctores disponibles
bool estadisponible(const string disponibilidad) {
	vector<string> opcionesdisponibles={"Si", "si", "S", "s" };
	return find(opcionesdisponibles.begin(), opcionesdisponibles.end(),disponibilidad) != opcionesdisponibles.end();
}
void doctor::reportedisponibilidad() {
	ifstream archivo("doctores.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de doctores" << endl;
	}
	json doctoresjson;
	archivo >> doctoresjson;
	archivo.close();
	cout << "Disponibilidad de los doctores" << endl;
	cout << "-------------------------------------" << endl;
	bool encontrar = false;
	for (const auto& doctor : doctoresjson) {
		string disponibilidad = doctor["Disponibilidad"];
		if (estadisponible(disponibilidad)){
		cout << "Disponibilidad" << doctor["Disponibilidad"] << endl;
		cout << "ID del doctor" << doctor["ID"] << endl;
		cout << "Nombre del doctor" << doctor["Nombre"] << endl;
		cout << "Apellidos del doctor" << doctor["Apellido1"] << doctor["Apellido2"] << endl;
		cout << "Especialidad del doctor" << doctor["Especialidad"] << endl;
		cout << "-------------------------------------" << endl;
		encontrar = true;
		}
	}
	if (!encontrar) {
		cout << "No hay doctores disponibles " << endl;
	}
}
void menureportes() {
	cout << "Selecciona de que quieres hacer un reporte" << endl;
	cout << "1.Listado de pacientes por rango de fechas" << endl;
	cout << "2.Citas pendientes por médico" << endl;
	cout << "3.Citas pendientes por especialidad" << endl;
	cout << "4.Reporte de pacientes con enfermedades crónicas" << endl;
	cout << "5.Reporte de doctores disponibles" << endl;
	int seleccion;
	while (true) {
		string input;
		cin >> input;
		stringstream ss(input);
		if (ss >> seleccion && ss.eof()) {
			break;
		}
		else {
			cout << "Esscribe un numero valido ";
		}
	}
	switch (seleccion){
		//funciona
	case 1: {
		string fechainicio;
		string fechafinal;
		cout << "Ingresa la fecha de inicio(dia/mes/año):";
		cin >> fechainicio;
		cout << "Ingresa la fecha final(dia/mes/año): ";
		cin >> fechafinal;
		paciente::reportepacientes(fechainicio, fechafinal);
	}
		break;
		//funciona
	case 2:{
		citaspendientes();
	}
		break;
		//Funciona
	case 3: {
		citasespecialidad();
	}
		break;
		//funciona 
	case 4: {
		paciente::reporteenfermedadescronicas();
	}
		break;
	case 5: {
		doctor::reportedisponibilidad();
	}
		break;
	default:
		cout << "Elige una opción valida" << endl;
		menureportes();
		break;
	}
}