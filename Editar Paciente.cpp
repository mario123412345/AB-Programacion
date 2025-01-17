#include "AB Programacion.h"

void paciente::editarpaciente(int edp) {
    ifstream archivo("pacientes.json");
    if (!archivo.is_open()) {
        cout << "Error1, archivo de pacientes ya abierto" << endl;
        return;
    }
    json pacientes;
    archivo >> pacientes;
    archivo.close();
    bool encontrar = false;
    for (auto& paciente : pacientes) {
        if (paciente["ID"] == edp) {
            cout << "Pacientes encontrado  con id" << edp << endl;
            cout << "1.Nombre paciente: " << paciente["Nombre"] << endl;
            cout << "2.Apellido 1 paciente: " << paciente["Apellido1"] << endl;
            cout << "3.Apellido 2paciente: " << paciente["Apellido2"] << endl;
            cout << "4.Enfermedad paciente: " << paciente["Enfermedad"] << endl;
            cout << "5.Fecha baja paciente:(dia/mes/año)" << paciente["Fecha baja"] << endl;
            cout << "6.Fecha alta paciente:(dia/mes/año) " << paciente["Fecha alta"] << endl;
            int elect;
            cout << "Que opción quieres editar?";
            while (true) {
                string input;
                cin >> input;
                stringstream ss(input);
                if (ss >> elect && ss.eof()) {
                    break;
                }
                else {
                    cout << "Esscribe un numero valido ";
                }
            }
            string nuevovalor;

            getline(cin, nuevovalor);
            switch (elect) {
            case 1:
                cout << "Cambiando nombre" << endl;
                getline(cin, nuevovalor);
                paciente["Nombre"] = nuevovalor;
                break;
            case 2:
                cout << "Cambiando apellido1" << endl;
                getline(cin, nuevovalor);
                paciente["Apellido1"] = nuevovalor;
                break;
            case 3:
                cout << "Cambiando apellido2" << endl;
                getline(cin, nuevovalor);
                paciente["Apellido2"] = nuevovalor;
                break;
            case 4:
                cout << "Cambiando problema/enfermedad del paciente" << endl;
                getline(cin, nuevovalor);
                paciente["Enfermedad"] = nuevovalor;
                break;
            case 5:
                cout << "Cambiando la fecha de baja" << endl;
                getline(cin, nuevovalor);
                paciente["Fecha baja"] = nuevovalor;
                break;
            case 6:
                cout << "Cambiando la fecha de alta" << endl;
                getline(cin, nuevovalor);
                paciente["Fecha alta"] = nuevovalor;
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
    if (!archivo) {
        cout << "Error2" << endl;
    }
    ofstream nuevarch("pacientes.json");
    if (!nuevarch) {
        cout << "Errpr al guardar" << endl;
    }
    cout << "Se han guardado los cambios" << endl;
    nuevarch << pacientes.dump(4);
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