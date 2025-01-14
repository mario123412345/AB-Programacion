#include "AB Programacion.h"

void restaurar(const string& archivooriginal) {
	string archivobackup = "backup_"+archivooriginal;
	ifstream backup(archivobackup);
	if (backup.is_open()) {
		ofstream restaurar(archivooriginal);
		if (restaurar.is_open()) {
			json infobackup;
			backup >> infobackup;
				if(!infobackup.empty()){
					restaurar <<infobackup.dump(4);
					cout << "Archivo" << archivooriginal << "restaurado" << endl;
				}else{
					cout << "El backup de" << archivooriginal << " esta vacio" << endl;
				}
		}else{
			cout << "Error al restaurar " << archivooriginal << endl;
		}
	}
	else {
		cout << "No se puede abrir el backup para restaurar" << archivooriginal << endl;
	}
}