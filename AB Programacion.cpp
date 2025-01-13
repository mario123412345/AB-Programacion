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
	
	cout << "Que quieres hacer" << endl;
	cout << "1.Editar(paciente/doctor/cita)" << endl;
	cout << "2.Crear (paciente/doctor/cita)" << endl;
	cout << "3.Eliminar(paciente/doctor/cita)" << endl;
	cout << "4.Registros" << endl;
	cout << "5.Buscar" << endl;
	cout << "6.Restaurar desde un backup" << endl;
	cout << "7.Cerrar el programa" << endl;
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
			cout << "Has elegido buscar" << endl;
			buscar();
			break;
		case 6:
			cout << "Has elegido restaurar" << endl;
			restaurar();
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
	cout << "Bienvenido al programa de administracion de Hospital de Mario" << endl;
	inicio();
	
	return 0;
}