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
	cout << "5.Buscar por el nombre paciente" << endl;
	cout << "6.Buscar por la enfermedad paciente" << endl;
	cout << "7.Buscar por el ID del doctor" << endl;
	cout << "8.Buscar por el nombre del doctor" << endl;
	cout << "9.Buscar por la especialidad del doctor" << endl;
	cin >> opcion;
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
			cout << "No se encontró ninguan cita con ID" << buscarporid << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar citas por la fecha
		  //Funciona
	case 2: {
		cout << "Enfuentra las citas con una fecha (dd/mm/año)" << endl;
		string buscarporfecha;
		cout << "Introduce la fecha de las que quieres buscar la cita(dd/mm/año):";
		cin.ignore();
		getline(cin, buscarporfecha);
		cout << "----------------------------------------" << endl;
		bool encontrar = false;
		for (const auto& cita : citasjson) {
			if (cita["Fecha"] == buscarporfecha) {
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
			cout << "No se encontró ninguan cita con la fecha " << buscarporfecha << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar cita por la hora a la que es (Aparecerán todas las citas que sean a esa hora)
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
					cout << "No se encontró ninguan cita con la hora " << horacita << endl;
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
					cout << "No se encontró la información del paciente con ID" << buscaridpaciente << ", puede que haya sido eliminado" << endl;
				}
				int iddoctor = cita["IDdoc"];
				bool encontrardoctor = false;
				for (const auto& doctor : doctores) {
					if (doctor["ID"] == iddoctor){
						cout << "Información del docctor"<<endl;
						cout << "ID del doctor" << doctor["ID"]<<endl;
						cout << "Nombre del doctor" << doctor["Nombre"] << endl;
						cout << "Apellidos del doctor" << doctor["Apellido1"] <<  doctor["Apellido2"] << endl;
						cout << "Especialidad " << doctor["Especialidad"] << endl;
						encontrardoctor = true;
						break;
					}
				}
				if (!encontrardoctor) {
					cout << "No se encontró la información del doctor con ID" << iddoctor << "puede que haya sido eliminado" << endl;
				}
			}
		}
		if (!encontrarcita) {
			cout << "No se encontraron citas para el paciente con ID " << buscaridpaciente<< endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
		  /*
	//Buscar cita por el nombre de un paciente o de varios si tienen el mismo nombre
		  //Funciona pero debo implementar mejoras en la visualización y el orden
	case 5: {
		cout << "Busca todas las citas de uno o varios pacientes con un nombre" << endl;
		string nombrepaciente;
		cout << "Escribe el nombre del o los paciente/es de los que quieras encontrar citas:";
		cin.ignore();
		getline(cin, nombrepaciente);
		cout << "----------------------------------------" << endl;
		bool encontrarpaciente = false;
		for (const auto& paciente : pacientes) {
			if (nombrepaciente == paciente["Nombre"]) {
				encontrarpaciente = true;
				cout << "Citas encontradas con el nombre de paciente:" << nombrepaciente<< endl;
				bool encontrarcita = false;
				for (const auto& cita : citasjson) {
					int idpaciente = paciente["ID"];
					if (paciente["ID"] == cita["IDpac"]) {
						encontrarcita = true;
						cout << "ID de la cita" << cita["ID"] << endl;
						cout << "Fecha de la cita(dia/mes/año)" << cita["Fecha"] << endl;
						cout << "Hora de la cita(24h)" << cita["Hora"] << endl;
						cout << "ID del paciente" << paciente["ID"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
						int iddoctor = cita["IDdoc"];
						bool encontrardoctor = false;
						for (const auto& doctor : doctores) {
							if (doctor["ID"] == iddoctor) {
								encontrardoctor = true;
								cout << "ID del doctor" << doctor["ID"] << endl;
								cout << "Nombre del doctor" << doctor["Nombre"] << endl;
								cout << "Apellidos del doctor" << doctor["Apellido1"] << doctor["Apellido2"] << endl;
								cout << "Especialidad del doctor " << doctor["Especialidad"] << endl;
								break;
							}
						}
						if (!encontrardoctor) {
							cout << "No se ha encontrado al doctor asociado con esta cita." << endl;
						}
					}
				}
				if (!encontrarcita) {
					cout << "No se han encontrado citas para este paciente:"<<nombrepaciente << endl;
				}
			}
		}
		if (!encontrarpaciente) {
			cout << "No se ha encontrado ningún paciente con el nombre: " << nombrepaciente << "revisa las mayusculas o minusculas o que este bien escrito" << endl;
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar cita en base a la enfermedad del/los paciente/es(Una enfermedad puede esytar en varios pacientes)
	case 6: {
		cout << "Busca citas por la enfermedad del paciente" << endl;
		string enfermedadpaciente;
		cout << "Escribe la enfermedad del o los paciente/es de los que quieras encontrar citas(Ten cuidado con mayusculas y minusculas):";
		cin.ignore();
		getline(cin, enfermedadpaciente);
		cout << "----------------------------------------" << endl;
		bool encontrarpaciente = false;
		for (const auto& paciente : pacientes) {
			if(enfermedadpaciente==paciente["Enfermedad"]){
				encontrarpaciente = true;
				cout << "Citas encontradas de pacientes con esta enfermedad:" << enfermedadpaciente << endl;
				bool encontrarcita = false;
				for (const auto& cita : citasjson){
					if (cita["IDpac"] == paciente["ID"]) {
						encontrarcita = true;
						cout << "ID de la cita" << cita["ID"] << endl;
						cout << "Fecha de la cita(dia/mes/año)" << cita["Fecha"] << endl;
						cout << "Hora de la cita(24h)" << cita["Hora"] << endl;
						cout << "ID del paciente" << paciente["ID"] << endl;
						cout << "Nombre del paciente" << paciente["Nombre"] << endl;
						cout << "Apellidos del paciente" << paciente["Apellido1"] << paciente["Apellido2"] << endl;
						int iddoctor = cita["IDdoc"];
						bool encontrardoctor = false;
						for (const auto& doctor : doctores) {
							if (iddoctor = doctor["ID"]) {
								encontrardoctor = true;
								cout << "ID del doctor:" << doctor["ID"] << endl;
								cout << "Nombre del doctor" << doctor["Nombre"] << endl;
								cout << "Apellidos del doctor" << doctor["Apellido1"] << doctor["Apellido2"] << endl;
								cout << "Especialidad del doctor" << doctor["Especialidad"] << endl;
							}
						}
						if (!encontrardoctor) {
							cout << "No se he encontrado ningun doctor, es posible que se haya eliminado" << endl;
						}
					}
					if (!encontrarcita) {
						cout << "No se ha encontrado ninguna cita que involucre la enfermedad" << endl;
					}
				}
			}
			if (!encontrarpaciente) {
				cout << "No se ha encontrado ningun paciente con esta enfermedad:" << enfermedadpaciente << ",revisa las mayusculas o minusculas o que estye bien escrito" << endl;
			}
		}
		cout << "----------------------------------------" << endl;
		break;
	}
	//Buscar cita por el id de un doctor(Un doctor puede tener varias citas)
	case 7: {
		cout << "Busca citas que tiene un doctor por su ID" << endl;
		int buscariddoctor;
		cout << "Introduce el id del doctor del que quieres buscar citas:";
		cin >> buscariddoctor;
		bool encontrarcita = false;
		for (const auto& cita : citasjson) {
			if (buscariddoctor == cita["IDdoc"]) {
				cout << "Citas encontradas con ID de doctor " << buscariddoctor << endl;
				cout << "ID de la cita" << cita["ID"] << endl;
				cout << "Fecha de la cita" << cita["Fecha"] << endl;
				cout << "Hora de la cita" << cita["Hora"] << endl;
				int idpaciente = cita["IDpac"];
				bool encontrarpaciente = false;
				for (const auto& paciente : pacientes) {
					cout << "ID del paciente" << paciente["ID"] << endl;
					cout << "Nombre del paciente" << paciente["Nombre"] << endl;
					cout << "Apellidos del paciente"<<paciente["Apellid1"]<<paciente["Apellido2"];
					cout << "Enfermedad del paciente" << paciente["Enfermedad"] << endl;
				}
			}
		}
		break;
	}*/
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