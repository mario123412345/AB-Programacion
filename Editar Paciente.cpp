#include "AB Programacion.h"
/*void peditar() {
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
            string nuevovalor;
            
            getline(cin, nuevovalor);
            switch (elect) {
            case 1:
                cout << "Cambiando nombre" << endl;
                getline(cin, nuevovalor);
                pacient["Nombre"] = nuevovalor;
            break;
            case 2:
                cout << "Cambiando apellido1" << endl;
                getline(cin, nuevovalor);
                pacient["Apellido1"] = nuevovalor;
                break;
            case 3:
                cout << "Cambiando apellido2" << endl;
                getline(cin, nuevovalor);
                pacient["Apellido2"] = nuevovalor;
                break;
            case 4:
                cout << "Cambiando problema/enfermedad del paciente" << endl;
                getline(cin, nuevovalor);
                pacient["Enfermedad"] = nuevovalor;
                break;
            case 5:
                cout << "Cambiando la fecha de baja" << endl;
                getline(cin, nuevovalor);
                pacient["Fecha baja"] = nuevovalor;
                break;
            case 6:
                cout << "Cambiando la fecha de alta" << endl;
                getline(cin, nuevovalor);
                pacient["Fecha alta"] = nuevovalor;
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
    
}*/
void paciente::editarpaciente(int edp) {
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
            cout << "Pacientes encontrado  con id" << edp << endl;
            cout << "1.Nombre paciente: " << pacient["Nombre"] << endl;
            cout << "2.Apellido 1 paciente: " << pacient["Apellido1"] << endl;
            cout << "3.Apellido 2paciente: " << pacient["Apellido2"] << endl;
            cout << "4.Enfermedad paciente: " << pacient["Enfermedad"] << endl;
            cout << "5.Fecha baja paciente:(dia/mes/año)" << pacient["Fecha baja"] << endl;
            cout << "6.Fecha alta paciente:(dia/mes/año) " << pacient["Fecha alta"] << endl;
            int elect;
            cout << "Que opción quieres editar?";
            cin >> elect;
            string nuevovalor;

            getline(cin, nuevovalor);
            switch (elect) {
            case 1:
                cout << "Cambiando nombre" << endl;
                getline(cin, nuevovalor);
                pacient["Nombre"] = nuevovalor;
                break;
            case 2:
                cout << "Cambiando apellido1" << endl;
                getline(cin, nuevovalor);
                pacient["Apellido1"] = nuevovalor;
                break;
            case 3:
                cout << "Cambiando apellido2" << endl;
                getline(cin, nuevovalor);
                pacient["Apellido2"] = nuevovalor;
                break;
            case 4:
                cout << "Cambiando problema/enfermedad del paciente" << endl;
                getline(cin, nuevovalor);
                pacient["Enfermedad"] = nuevovalor;
                break;
            case 5:
                cout << "Cambiando la fecha de baja" << endl;
                getline(cin, nuevovalor);
                pacient["Fecha baja"] = nuevovalor;
                break;
            case 6:
                cout << "Cambiando la fecha de alta" << endl;
                getline(cin, nuevovalor);
                pacient["Fecha alta"] = nuevovalor;
                break;
            default:
                cout << "No se puede editar algo que no existe" << endl;
                break;
            }
            encontrar = true;
            break;
        }

    }
    if (!encontrar) {
        cout << "No hay pacientes con el ID" << edp << endl;
    }
    if (!arch) {
        cout << "Error2" << endl;
    }
    ofstream nuevarch("pacientes.json");
    if (!nuevarch) {
        cout << "Errpr al guardar" << endl;
    }
    cout << "Si veo esto funciona y se guarda" << endl;
    nuevarch << paci.dump(4);
    nuevarch.close();
}
void peditar() {
    int edp;
    cout << "Cual es el id del pacientes que quieres editar?";
    cin >> edp;
    paciente::editarpaciente(edp);
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