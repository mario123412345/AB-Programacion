#include "AB Programacion.h"

void buscarcita() {
	cout << "Has seleccionado buscar una cita" << endl;
	ifstream archivo("citas.json");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de citas" << endl;
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
	cout << "1.Buscar por ID (Cita)" << endl;
	cout << "2.Buscar por fecha" << endl;
	cout << "3.Buscar por hora(24h)" << endl;
	cout << "4.Buscar por el ID del paciente" << endl;
	cout << "5.Buscar por el ID del doctor" << endl;
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
	//Buscar las citas ppor el id de la cita
		//Funciona
	case 1: {
		int buscarporid;
		cout << "Introduce el ID del de la cita para buscarla:";
		cin >> buscarporid;
		cout << "----------------------------------------" << endl;
		bool encontrado = false;
		for (const auto& cita : citasjson) {
			if (cita["ID"] == buscarporid) {
				cout << "----------------------------------------" << endl;
				cout << "Cita con ID " << buscarporid << "encontrada" << endl;
				cout << "Fecha " << cita["Fecha"] << endl;
				cout << "Hora " << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (paciente["ID"] == idpaciente) {
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
					if (doctor["ID"] == iddoctor) {
						cout << "ID del doctor" << doctor["ID"] << endl;
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
			cout << "No se encontr� ninguan cita con ID" << buscarporid << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar citas por la fecha
		  //Funciona
	case 2: {
		cout << "Enfuentra las citas con una fecha (dd/mm/a�o)" << endl;
		string buscarporfecha;
		cout << "Introduce la fecha de las que quieres buscar la cita(dd/mm/a�o):";
		cin.ignore();
		getline(cin, buscarporfecha);
		cout << "----------------------------------------" << endl;
		bool encontrar = false;
		for (const auto& cita : citasjson) {
			if (cita["Fecha"] == buscarporfecha) {
				cout << "----------------------------------------" << endl;
				cout << "Cita con fecha " << buscarporfecha << "encontrada" << endl;
				cout << "ID cita " << cita["ID"] << endl;
				cout << "Hora " << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (paciente["ID"] == idpaciente) {
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
					if (doctor["ID"] == iddoctor) {
						cout << "ID del doctor" << doctor["ID"] << endl;
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
			cout << "No se encontr� ninguan cita con la fecha " << buscarporfecha << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar cita por la hora a la que es (Aparecer�n todas las citas que sean a esa hora)
		  //Funciona
	case 3: {
		cout << "Mira todas las citas a cierta hora(24h)" << endl;
		string horacita;
		cout << "Introduce la hora de las que quieres buscar la cita(24h):";
		cin.ignore();
		getline(cin, horacita);
		cout << "----------------------------------------" << endl;
		bool encontrar = false;
		for (const auto& cita : citasjson) {
			if (cita["Hora"] == horacita) {
				cout << "----------------------------------------" << endl;
				cout << "Cita con hora " << horacita << " horas encontrada" << endl;
				cout << "ID cita " << cita["ID"] << endl;
				cout << "Fecha " << cita["Fecha"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (paciente["ID"] == idpaciente) {
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
					if (doctor["ID"] == iddoctor) {
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
				if (!encontrar) {
					cout << "No se encontr� ninguan cita con la hora " << horacita << endl;
				}
			}
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar cita por el ID del paciente que tiene la cita(Unn paciente puede tener varias citas con diferente id)
		  //Funciona
	case 4: {
		cout << "Busca las citas que tienen un paciente por su id" << endl;
		int buscaridpaciente;
		cout << "Introduce el ID del paciente del que quieres ver las citas:";
		cin >> buscaridpaciente;
		cout << "----------------------------------------" << endl;
		bool encontrarcita = false;
		for (const auto& cita : citasjson) {
			if (cita["IDpac"] == buscaridpaciente) {
				encontrarcita = true;
				cout << "----------------------------------------" << endl;
				cout << "Citas encontrada por medio del paciente con id" << buscaridpaciente << endl;
				cout << "ID de la cita" << cita["ID"] << endl;
				cout << "Fecha de la cita" << cita["Fecha"] << endl;
				cout << "Hora de la cita(24h)" << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (paciente["ID"] == idpaciente) {
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						encontrarpaciente = true;
						break;
					}
				}
				if (!encontrarpaciente) {
					cout << "No se encontr� la informaci�n del paciente con ID" << buscaridpaciente << ", puede que haya sido eliminado" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctor["ID"] == iddoctor){
						cout << "Informaci�n del docctor"<<endl;
						cout << "ID del doctor" << doctor["ID"]<<endl;
						cout << "Nombre del doctor" << doctor["Nombre"] << endl;
						cout << "Apellidos del doctor" << doctor["Apellido1"] <<  doctor["Apellido2"] << endl;
						cout << "Especialidad " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "No se encontr� la informaci�n del doctor con ID" << iddoctor << "puede que haya sido eliminado" << endl;
				}
			}
		}
		if (!encontrarcita) {
			cout << "No se encontraron citas para el paciente con ID " << buscaridpaciente<< endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	
	//Buscar citas en base al id del doctor
	case 5: {
		cout << "Busca las citas que tiene un doctor por su id" << endl;
		int buscariddoctor;
		cout << "Introduce el ID del doctor del que quieres ver las citas:";
		cin >> buscariddoctor;
		cout << "----------------------------------------" << endl;
		bool encontrarcita = false;
		for (const auto& cita : citasjson) {
			if (cita["IDdoc"] == buscariddoctor) {
				encontrarcita = true;
				cout << "----------------------------------------" << endl;
				cout << "Citas encontrada por medio del doctor con id" << buscariddoctor << endl;
				cout << "ID de la cita" << cita["ID"] << endl;
				cout << "Fecha de la cita" << cita["Fecha"] << endl;
				cout << "Hora de la cita(24h)" << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					if (paciente["ID"] == idpaciente) {
						cout << "ID del paciente:" << paciente["ID"] << endl;
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						encontrarpaciente = true;
						break;
					}
				}
				if (!encontrarpaciente) {
					cout << "No se encontr� la informaci�n del paciente con ID" <<idpaciente << ", puede que haya sido eliminado" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctor["ID"] == iddoctor) {
						cout << "Informaci�n del docctor" << endl;
						cout << "ID del doctor" << doctor["ID"] << endl;
						cout << "Nombre del doctor" << doctor["Nombre"] << endl;
						cout << "Apellidos del doctor" << doctor["Apellido1"] << doctor["Apellido2"] << endl;
						cout << "Especialidad " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "No se encontr� la informaci�n del doctor con ID" << iddoctor << "puede que haya sido eliminado" << endl;
				}
			}
		}
		if (!encontrarcita) {
			cout << "No se encontraron citas para el doctor con ID " << buscariddoctor << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	
	default:
		cout << "Selecciona una opci�n valida" << endl;
		break;
	}
	inicio();
}