// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"

#include <iostream>
#include <string>
//meter punteros
//Meter un buscador de pacientes/doctores
//Arreglas que si se introduce una letra en la selección , se genera un bucle infinito
void inicio() {
	int op;
	cout << "----------------------------" << endl;
	
	std::cout << "Que quieres hacer" << std::endl;
	std::cout << "Editar(paciente/doctor/cita) --> 1" << std::endl;
	std::cout << "Crear (paciente/doctor/cita)--> 2" << std::endl;
	std::cout << "Eliminar(paciente/doctor/cita) --> 3" << std::endl;
	cout << "Registros-->4" << endl;
	cout << "Cerrar el programa-->5" << endl;
	std::cout << "¿Que quieres hacer?"<<endl;
	
	cin >> op;
	switch (op) {
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
	cout << "Bienvenido al programa de administracion de Hospital de Mario" << endl;
	inicio();
	
	return 0;
}