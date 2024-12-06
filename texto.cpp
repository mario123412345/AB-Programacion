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
        cout << "Archivp ya existe" << endl;
    }
    
}