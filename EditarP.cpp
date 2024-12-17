#include "AB Programacion.h"
void peditar() {
    cout << "Esditando oacuentres" << endl;
    int edp;
    cout << "Cual es el id del pacientes que quieres editar?" << endl;
    cin >> edp;
    ifstream arch("paciente.json");
    if (!arch.is_open()) {
        cout << "Error1, archivo de pacientes ya abierto" << endl;
        return;
    }
    json paci;
    arch >> paci;
    arch.close();
    bool encontrar = false;
    for (auto& pacient : paci) {
        if (pacient["ID"] == edp) {
            cout << "Pacientes encontrado  con id" <<edp<< endl;
            cout << "Nombre paciente: ";
            cin >> pacient["nombre"];
            cout << "Apellido 1 paciente: ";
            cin >> pacient["apellido1"];
            cout << "Apellido 2paciente: ";
            cin >> pacient["apellido2"];
            cout << "Enfermedad paciente: ";
            cin >> pacient["enfermedad"];
            cout << "Fecha baja paciente:(dia/mes/año)";
            cin >> pacient["fechabaja"];
            cout << "Fecha alta paciente:(dia/mes/año) ";
            cin >> pacient["fechaalta"];
            encontrar = true;
            break;
        }
       
    }
    if (!arch) {
        cout << "Error2" << endl;
    }
    ofstream nuevarch("pacientes.json");
    if (!nuevarch.is_open()) {
        cout << "Errpr al gardar" << endl;
    }
    nuevarch << paci.dump(4);
    nuevarch.close();
    cout << "Se ha editado al pactiente" << endl;

}
void EditarP() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando paciente" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
    cout << "Continuar -->3" << endl;
	cin >> vol;
    switch (vol) {
        case 1:
            editar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            peditar();
            break;
    default:
        cout << "Error" << endl;
        EditarP();
        break;
    }
}