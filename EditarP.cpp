#include "AB Programacion.h"

void EditarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando paciente" << endl;
	cout << "Para editar un paciente se neesita saber el ID o el nombre/apellidos" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
	cin >> vol;
	if (vol == 1){
		editar();
	}else if(vol==2){
		inicio();
	}
	else {
		cout << "Error" << endl;
		EditarP();
	}
}