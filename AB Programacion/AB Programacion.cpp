// AB Programacion.cpp: define el punto de entrada de la aplicación.
//

#include "AB Programacion.h"




class Persona {
public:
	Persona(std::string n, int e) :nombre(n), edad(e) {
		std::cout << "Se ha creado una persona" << std::endl;
	}
	~Persona() {
		std::cout << "Se ha destruido una persona" << std::endl;
	}
	void presentarse() {
		std::cout << "Hola, soy " << nombre << " y tengo" << edad << " años" << std::endl;
	}
private:
	std::string nombre;
	int edad;

};


int main() {
	Persona Angel("Angel", 18);
	Angel.presentarse();
	return 0;
}