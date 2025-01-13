#include "AB Programacion.h"


void creardocdetxt(const string& nombrearchivo) {
    
    ifstream archivo(nombrearchivo);
    if (!archivo.is_open()) {
        ofstream nuevo(nombrearchivo);
        if (nuevo.is_open()) {
            nlohmann::json jsonVacio = nlohmann::json::array(); 
            nuevo << jsonVacio.dump(4);
            cout << "Archivo creado --> " << nombrearchivo << endl;
        }
        else {
            cout << "Errpr" << endl;
        }
    }else {
        cout << "Archivp "<< nombrearchivo<< "ya existe" << endl;
    }
    
}

void backup(const string& archivooriginal) {
    string archivobackup = "backup_" + archivooriginal;
    ifstream archivo(archivooriginal);
    if (archivo.is_open()) {
        ofstream nuevobackup(archivobackup);
        if (nuevobackup.is_open()) {
            json contenidoarchivo;
            archivo >> contenidoarchivo;
            nuevobackup << contenidoarchivo.dump(4);
            cout << "Backup " << archivobackup <<"actualizado" << endl;
        }
        else {
            cout << "Error al crear el archivo de backup" << archivobackup << endl;
        }
    }
    else {
        cout<<"Error al conseguir la información del archivo original"<< archivooriginal<<endl;

    }
}