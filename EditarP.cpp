#include "AB Programacion.h"
void peditar() {
    cout << "Esditando oacuentres" << endl;
    int edp;
    cout << "Cual es el id del pacientes que quieres editar?" << endl;
    cin >> edp;
    ifstream arch("pacientes.json");
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
            cout << "1.Nombre paciente: " << pacient["Nombre"] << endl ;
            cout << "2.Apellido 1 paciente: "<< pacient["Apellido1"]<<endl;
            cout << "3.Apellido 2paciente: "<< pacient["Apellido2"] << endl;
            cout << "4.Enfermedad paciente: "<< pacient["Enfermedad"] << endl;
            cout << "5.Fecha baja paciente:(dia/mes/año)"<< pacient["Fecha baja"] << endl;
            cout << "6.Fecha alta paciente:(dia/mes/año) "<< pacient["Fecha alta"] << endl;
            int elect;
            cout << "Que opción quieres editar?";
            cin >> elect;
            switch (elect) {
            case 1:
                cout << "Cambiar nombre" << endl;
                cin >> pacient["Nombre"];
            break;
            case 2:
                cout << "Cambiar apellido1" << endl;
                cin >> pacient["Apellido1"];
                break;
            case 3:
                cout << "Cambiar apellido2" << endl;
                cin >> pacient["Apellido2"];
                break;
            case 4:
                cout << "Cambiar problema/enfermedad del paciente" << endl;
                cin >> pacient["Enfermedad"];
                break;
            case 5:
                cout << "Cambiar la fecha de baja" << endl;
                cin >> pacient["Fecha baja"];
                break;
            case 6:
                cout << "Cambiar la fecha de alta" << endl;
                cin >> pacient["Fecha alta"];
                break;
            default:
                cout << "No se puede editar algo que no existe"<<endl;
                break;
            }
            encontrar = true;
            break;
        }
       
    }
    if (!encontrar) {
        cout << "No hay pacientes con id" << edp << endl;
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