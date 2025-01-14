#include "AB Programacion.h"
//Reporte de pacientes en un rango de fecha
//Funciona
tm convertirfecha(const string& fecha) {
	tm tmFecha = {};
	istringstream ss(fecha);
	ss >>get_time(&tmFecha, "%d/%m/%Y");  
	if (ss.fail()) {
		cerr << "Error al convertir la fecha" << endl;
	}
	return tmFecha;
}
bool compararFechas(const string& fecha1,const string& fecha2){
	tm tmFecha1=convertirfecha(fecha1);
	tm tmFecha2=convertirfecha(fecha2);
	time_t t1=mktime(&tmFecha1);
	time_t t2=mktime(&tmFecha2);
	return t1<=t2;
}
void paciente::reportepacientes(const string& fechainicio,const string&fechafinal) {
	ifstream archivo("pacientes.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de pacientes" << endl;
	}
	json pacientesjson;
	archivo >> pacientesjson;
	archivo.close();
	cout << "Pacientes atendidos entre la fecha" << fechainicio << "y" << fechafinal << endl;
	for (const auto& paciente : pacientesjson) {
		string fechaalta = paciente["Fecha alta"];
		if (fechaalta >= fechainicio && fechaalta <= fechafinal) {
			cout << "ID" << paciente["ID"] << endl;
			cout << "Nombre" << paciente["Nombre"] << endl;
			cout << "Apellidos" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
			cout << "Enfermedad" << paciente["Enfermedad"] << endl;
			cout << "------------------------------" << endl;
		}
	}
}
//Citas pendientes por medico

string fechaactual() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char fecha[10];  
	strftime(fecha, sizeof(fecha),"%d/%m/%Y",ltm);
	return string(fecha);
}
void citaspendientes() {
	ifstream archivo("citas.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de citas" << endl;
	}
	json citasjson;
	archivo >> citasjson;
	archivo.close();
	string fechahoy = fechaactual();
	tm tmfechahoy = convertirfecha(fechahoy);
	map<string, vector<json>> citasmedico;
	for (const auto& cita : citasjson) {
		string fechacita = cita["Fecha"];
		tm tmfechacita = convertirfecha(fechacita);
		time_t t1 = mktime(&tmfechahoy);
		time_t t2 = mktime(&tmfechacita);
		if (t2 > t1) {
			string idmedico=cita["idd"]; 
			citasmedico[idmedico].push_back(cita);
		}
	}
	cout << "Citas pendientes por médico:" << endl;
	for (const auto& entry : citasmedico) {
		cout << "ID del medico: " << entry.first << endl;
		for (const auto& cita : entry.second) {
			cout << "ID dela cita" << cita["ID_cita"] << endl;
			cout << "Fecha de la cita" << cita["Fecha"] << endl;
			cout << "-------------------------------------------" << endl;
		}
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
	for (const auto& paciente : pacientesjson) {
		string enfermedad = paciente["Enfermedad"];
		if (enfermedadcronica(enfermedad)) {
			cout << "ID" << paciente["ID"] << endl;
			cout << "Nombre" << paciente["Nombre"] << endl;
			cout << "Apellidos" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
			cout << "Enferemdad" << paciente["Enfermedad"] << endl;
		}
	}
}

void menureportes() {
	cout << "Selecciona de que quieres hacer un reporte" << endl;
	cout << "1.Listado de pacientes por rango de fechas" << endl;
	cout << "2.Citas pendientes por médico" << endl;
	cout << "3.Citas pendientes por especialidad" << endl;
	cout << "4.Reporte de pacientes con enfermedades crónicas" << endl;
	int seleccion;
	cin >> seleccion;
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
	case 2:{
		citaspendientes();
	}
		break;
	case 3:

		break;
		//funciona 
	case 4: {
		paciente::reporteenfermedadescronicas();
	}
		break;
	default:
		break;
	}
}