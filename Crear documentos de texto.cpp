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
        json contenidoarchivo;
        archivo >> contenidoarchivo;
        if (contenidoarchivo.empty()) {
            cout << "El archivo original" << archivooriginal << "esta vacio" << endl;
        }
        else {
            ofstream nuevobackup(archivobackup);
            if (nuevobackup.is_open()) {
                nuevobackup << contenidoarchivo.dump(4);
                cout << "Backup de" << archivooriginal << "ha sido actualizado" << endl;
            }
            else {
                cout << "Error al crear el backup" << archivobackup << endl;
            }
        }
    }
    else {
        cout << "Error al abrir el archivo original" << archivooriginal << endl;
    }
}