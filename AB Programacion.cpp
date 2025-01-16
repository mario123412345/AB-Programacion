// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>
//Meter un buscador de pacientes/doctores
//Arreglas que si se introduce una letra en la selección , se genera un bucle infinito
void inicio() {
	int opcion;
	cout << "----------------------------" << endl;
	
	cout << "¿Que quieres hacer ahora?" << endl;
	cout << "1.Editar" << endl;
	cout << "2.Crear" << endl;
	cout << "3.Eliminar" << endl;
	cout << "4.Registros" << endl;
	cout << "5.Buscar" << endl;
	cout << "6.Generar reporte" << endl;
	cout << "7.Cerrar el programa" << endl;
	std::cout << "¿Que quieres hacer?"<<endl;
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
			cout << "Has elegido editar" << endl;
			editar();
			break;
		case 2:
			cout << "Has elegido crear" << endl;
			crear();
			break;
		case 3:
			cout << "Has elegido eliminar" << endl;
			eliminar();
			break;
		case 4:
			cout << "Has elegido visualizar" << endl;
			visual();
			break;
		case 5:
			cout << "Has elegido buscar" << endl;
			buscar();
			break;
		case 6:
			menureportes();
			break;
		case 7:
			exit;
			break;

		default:
			cout << "opción no válida" << endl;
			inicio();
	}

}
int main() {
	creardocdetxt("doctores.json");
	creardocdetxt("pacientes.json");
	creardocdetxt("citas.json");
	creardocdetxt("doctoreselim.json");
	creardocdetxt("pacienteselim.json");
	creardocdetxt("citaselim.json");
	backup("doctores.json");
	backup("pacientes.json");
	backup("citas.json");
	restaurar("doctores.json");
	restaurar("pacientes.json");
	restaurar("citas.json");
	cout << "---------------------------------" << endl;
	cout << "Bienvenido al programa de administracion de Hospital de Mario" << endl;
	inicio();
	
	return 0;
}