// AB Programacion.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>
#include <sstream>
#include <ctime>
#include <vector>

// TODO: Haga referencia aquí a los encabezados adicionales que el programa requiere.

using namespace std;
using json = nlohmann::json;
//Inicio
void inicio();
void crear();
void editar();
void eliminar();
void buscar();
//Paciente
void EliminarP();
void peliminar();
void CrearP();
void pacientec();
void EditarP();
void peditar();
void registrop();
void buscarpaciente();
//Doctores
void EliminarD();
void deliminar();
void CrearD();
void doctorc();
void EditarD();
void deditar();
void registrod();
void buscardoctor();
//Citas
void celiminar();
void EliminarC();
void CrearC();
void EditarC();
void ceditar();
void visual();
void registroc();
void citac();

void creardocdetxt(const std::string& nombreArchivo);
void backup(const string& archivooriginal);
void restaurar(const string& archivooriginal);
void buscarcita();
void menureportes();
bool enfermedadcronica(const string enfermedad);

void citasespecialidad();
void citaspendientes();
class paciente {
public:
	int id;
	string nombre;
	string apellido1;
	string apellido2;
	string enfermedad;
	string fechabaja;//para poder incluir /
	string fechaalta;
public:
	paciente(int id, const string& nombre, const string& apellido1,const string& apellido2, const string& enfermedad,const string& fechaalta, const string& fechabaja);
	void guardarpaciente() const;
	static paciente crearpaciente();
    static void eliminarpaciente(int idp);
    static void editarpaciente(int edp);
    static void reportepacientes(const string& fechainicio, const string& fechafinal);
    static void reporteenfermedadescronicas();
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
public:
    doctor(int id, const string& nombre, const string& apellido1, const string& apellido2,const string& especialidad, const string& disponibilidad, const string& estado, double salario);
    void guardardoctor() const;
    static doctor creardoctor();
    static void eliminardoctor(int idd);
    static void editardoctor(int edd);
};
//Para cita meter id de la cita, fecha de la cita, id de paciente(con sus datos), id del doctor con sus datos y unz confirmación de ambos

class cita {
    int id;
    string fecha;
    string hora;
    int idp;
    int idd;
public:
    cita(int id, const string& fecha,const string& hora, int idp, int idd);
    void guardarcita() const;
    static cita crearcita();
    static void eliminarcita(int idc);
    static void editarcita(int idc);
};

//Deberia meter clase privada?
