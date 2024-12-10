// AB Programacion.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

// TODO: Haga referencia aquí a los encabezados adicionales que el programa requiere.

using namespace std;
using json = nlohmann::json;

void inicio();
void crear();
void editar();
void eliminar();
void EliminarP();
void EliminarD();
void EliminarC();
void CrearC();
void CrearD();
void CrearP();
void EditarP();
void EditarD();
void EditarC();
void visual();
void registroc();
void registrod();
void registrop();
void doctorc();
void creardocdetxt(const std::string& nombreArchivo);


