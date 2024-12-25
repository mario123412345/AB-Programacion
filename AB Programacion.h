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
void deliminar();
void peliminar();
void EliminarC();
void CrearC();
void CrearD();
void CrearP();
void EditarP();
void EditarD();
void EditarC();
void peditar();
void visual();
void registroc();
void registrod();
void registrop();
void doctorc();
void pacientec();
void citac();
void creardocdetxt(const std::string& nombreArchivo);

class paciente {
public:
	int id;
	string nombre;
	string apellido1;
	string apellido2;
	string enfermedad;
	string fechabaja;
	string fechaalta;
	paciente(int id, const string& nombre, const string& apellido1,const string& apellido2, const string& enfermedad,const string& fechaalta, const string& fechabaja);
	void guardarpaciente() const;
	static paciente crearpaciente();
    static void eliminarpaciente(int id);
    static void editarpaciente(int id);
};

class doctor {
public:
    int id;
    string nombre;
    string apellido1;
    string apellido2;
    string especialidad;
    string disponibilidad;
    string estado;
    double salario;
    doctor(int id, const string& nombre, const string& apellido1, const string& apellido2,const string& especialidad, const string& disponibilidad, const string& estado, double salario);
    void guardardoctor() const;
    static doctor creardoctor();
};
