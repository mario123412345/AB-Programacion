#include "AB Programacion.h"

void buscarcita() {
	cout << "Has seleccionado buscar una cita" << endl;
	ifstream archivo("citas.json");
	if (archivo.is_open()) {
		cout << "Error al abrir el archivo" << endl;
	}
	json citasjson;
	archivo >> citasjson;
	archivo.close();
	ifstream archivopacientes("pacientes.json");
	if (!archivopacientes.is_open()) {
		cout << "Error al abrir archivo de pacientes" << endl;
		return;
	}
	json pacientes;
	archivopacientes >> pacientes;
	archivopacientes.close();
	ifstream archivodoctores("doctores.json");
	if (!archivodoctores.is_open()) {
		cout << "Error al abrir el archivo de doctores" << endl;
		return;
	}
	json doctores;
	archivodoctores >> doctores;
	archivodoctores.close();
	int opcion;
	cout << "Por que caracteristica  quieres buscar la cita?" << endl;
	cout << "1.ID (Cita)" << endl;
	cout << "2.Fecha" << endl;
	cout << "3.Hora(24h)" << endl;
	cout << "4.ID paciente" << endl;
	cout << "5.Nombre paciente" << endl;
	cout << "6.Enfermedad paciente" << endl;
	cout << "7.ID doctor" << endl;
	cout << "8.Nombre doctor" << endl;
	cout << "9.Especialidad doctor" << endl;
	cin >> opcion;
	switch (opcion) {
	//Buscar las citas ppor el id de la cita
	case 1: {
		int buscarporid;
		cout << "Introduce el ID del de la cita para buscarla" << endl;
		cin >> buscarporid;
		bool encontrado = false;
		for (const auto& cita : citasjson) {
			if (cita["ID"] == buscarporid) {
				cout << "Cita con ID " << buscarporid << "encontrada" << endl;
				cout << "Fecha " << cita["Fecha"] << endl;
				cout << "Hora " << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (!pacientes["ID"] == idpaciente) {
						cout << "ID paciente " << idpaciente << endl;
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						encontrarpaciente = true;
						break;
					}
				}
				if (!encontrarpaciente) {
					cout << "Error, a lo mejor el paciente ha sido eliminado, porque no se encuentra" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctores["ID"] == iddoctor) {
						cout << "Nombre doctor " << doctor["Nombre"] << endl;
						cout << "Apellidos doctor " << doctor["Apellido1"]<<doctor["Apellido2"] << endl;
						cout << "Especialidad doctor " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "Error, a lo mejor el doctor se ha eliminado y no se encuentra" << endl;
				}
			}
		}
		if (!encontrado) {
			cout << "No se encontró ninguan cita con ID" << buscarporid << endl;
		}

	}
	//Buscar citas por la fecha
	case 2: {
		cout << "Enfuentra las citas con una fecha (dd/mm/año)" << endl;
		string buscarporfecha;
		cout << "Introduce la fecha de las que quieres buscar la cita(dd/mm/año)" << endl;
		getline(cin, buscarporfecha);
		bool encontrar = false;
		for (const auto& cita : citasjson) {
			if (cita["Fecha"] == buscarporfecha) {
				cout << "Cita con fecha " << buscarporfecha << "encontrada" << endl;
				cout << "ID cita " << cita["ID"] << endl;
				cout << "Hora " << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (!pacientes["ID"] == idpaciente) {
						cout << "ID paciente " << idpaciente << endl;
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						encontrarpaciente = true;
						break;
					}
				}
				if (!encontrarpaciente) {
					cout << "Error, a lo mejor el paciente ha sido eliminado, porque no se encuentra" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctores["ID"] == iddoctor) {
						cout << "Nombre doctor " << doctor["Nombre"] << endl;
						cout << "Apellidos doctor " << doctor["Apellido1"] << doctor["Apellido2"] << endl;
						cout << "Especialidad doctor " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "Error, a lo mejor el doctor se ha eliminado y no se encuentra" << endl;
				}
			}
		}
		if (!encontrar) {
			cout << "No se encontró ninguan cita con la fecha " << buscarporfecha << endl;
		}

		break;
	}
	//Buscar cita por la hora a la que es 
	case 3: {
		cout << "Mira todas las citas a cierta hora(24h)" << endl;
		int horacita;
		cout << "Introduce la hora de las que quieres buscar la cita(24h)" << endl;
		cin >> horacita;
		bool encontrar = false;
		for (const auto& cita : citasjson) {
			if (cita["Fecha"] == horacita) {
				cout << "Cita con hora " << horacita << "encontrada" << endl;
				cout << "ID cita " << cita["ID"] << endl;
				cout << "Fecha " << cita["Fecha"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (!pacientes["ID"] == idpaciente) {
						cout << "ID paciente " << idpaciente << endl;
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						encontrarpaciente = true;
						break;
					}
				}
				if (!encontrarpaciente) {
					cout << "Error, a lo mejor el paciente ha sido eliminado, porque no se encuentra" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctores["ID"] == iddoctor) {
						cout << "Nombre doctor " << doctor["Nombre"] << endl;
						cout << "Apellidos doctor " << doctor["Apellido1"] << doctor["Apellido2"] << endl;
						cout << "Especialidad doctor " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "Error, a lo mejor el doctor se ha eliminado y no se encuentra" << endl;
				}
			}
		}
		if (!encontrar) {
			cout << "No se encontró ninguan cita con la fecha " << horacita << endl;
		}
		break;
	}
	//Buscar cita por el ID del paciente que tiene la cita(Un paciente puede tener varias citas con diferente id)
	case 4: {
		cout << "Busca las citas que tiene un paciente por su ID" << endl;

		break;
	}
	//Buscar cita por el nombre de un paciente
	case 5: {
		cout << "Busca todas las citas de uno o varios pacientes con un nombre" << endl;
		break;
	}
	//Buscar cita en base a la enfermedad del/los paciente/es(Una enfermedad puede esytar en varios pacientes)
	case 6: {
		cout << "Busca citas por la enfermedad del paciente" << endl;
		break;
	}
	//Buscar cita por el id de un doctor(Un doctor puede tener varias citas)
	case 7: {
		cout << "Busca citas que tiene un doctor por su ID" << endl;
		break;
	}
	//Buscar citas en base al nombre del doctor
	case 8: {
		cout << "Busca las citas que tienen uno o varios doctores por su nombre" << endl;
		break;
	}
	//Buscar cita en base a la especialidad de el/lso doctores(Una especialidad se puede tener por varios doctores)
	case 9: {
		cout << "Busca citas en base a la especialidad de uno o varios doctores" << endl;
		break;
	}
	default:
		cout << "Selecciona una opción valida" << endl;
		break;
	}
}