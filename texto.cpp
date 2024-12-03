#include "AB Programacion.h"


void creardocdetxt(const std::string& nombreArchivo) {
    
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
    }
    else {
        std::cout << "Archivo creado con éxito: " << nombreArchivo << std::endl;
    }
    archivo.close();
}