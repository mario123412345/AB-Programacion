#include "AB Programacion.h"

void doctor::editardoctor(int edd) {
    ifstream archivo("doctores.json");
    if (!archivo.is_open()) {
        cout << "Error,el archivo de doctores no pudo abrirse" << endl;
        return;
    }
    json doctores;
    archivo >> doctores;
    archivo.close();
    bool encontrar = false;
    for(auto& doctor:doctores){
        if (doctor["ID"]==edd) {
            cout << "Doctore encontrado con id" << edd << endl;
            cout << "1.Nombre del doctor: " << doctor["Nombre"] << endl;
            cout << "2.Apellido 1 del doctor: " << doctor["Apellido1"] << endl;
            cout << "3.Apellido 2 del doctor: " << doctor["Apellido2"] << endl;
            cout << "4.Especialidad del doctor: " << doctor["Especialidad"] << endl;
            cout << "5.Disponibilidad del doctor" << doctor["Disponibilidad"] << endl;
            cout << "6.Estado del doctor(C-Contratado/D-Despedido)"<<doctor["Estado"] << endl;
            cout << "7.Salario del doctor" << doctor["Salario"] << endl;
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
            string nuevodato;
            getline(cin, nuevodato);
            switch (elect) {
            case 1:
                cout << "Cambia el nombre:" << endl;
                getline(cin, nuevodato);
                doctor["Nombre"] = nuevodato;
                break;
            case 2:
                cout << "Cambia el apellido1:" << endl;
                getline(cin, nuevodato);
                doctor["Apellido1"] = nuevodato;
                break;
            case 3:
                cout << "Cambia el apellido2:" << endl;
                getline(cin, nuevodato);
                doctor["Apellido2"] = nuevodato;
                break;
            case 4:
                cout << "Cambia la especialidad del doctor:" << endl;
                getline(cin, nuevodato);
                doctor["Especialidad"] = nuevodato;
                break;
            case 5:
                cout << "Cambia la disponibilidad(S/N):" << endl;
                getline(cin, nuevodato);
                doctor["Disponibilidad"] = nuevodato;
                break;
            case 6:
                cout << "Cambia el estado actual del doctor:" << endl;
                getline(cin, nuevodato);
                doctor["Estado"] = nuevodato;
                break;
            case 7:
                cout << "Cambia el salario:" << endl;
                getline(cin, nuevodato);
                doctor["Salario"] = nuevodato;
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
        cout << "No hay ningun doctor con el ID" << edd << endl;
        return;
    }
    ofstream nuevarch("doctores.json");
    if (!nuevarch.is_open()) {
        cout << "Error al guardar" << endl;
        return;
    }
    nuevarch << doctores.dump(4);
    nuevarch.close();
    cout << "Se han guardado los cambios del doctor" << endl;
}
void deditar() {
    int edd;
    cout << "Cual es el id del doctor que quieres editar?";
    cin >> edd;
    doctor::editardoctor(edd);
}
void EditarD() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Editando Doctor" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
    cout << "Continuar-->3" << endl;
    while (true) {
        string input;
        cin >> input;
        stringstream ss(input);
        if (ss >> vol && ss.eof()) {
            break;
        }
        else {
            cout << "Esscribe un numero valido ";
        }
    }
    switch (vol) {
    case 1:
        cout << "Regresando al menú anterior..." << endl;
        editar();
        break;
    case 2:
        inicio();
        break;
    case 3:
        deditar();
        break;
    default:
        cout << "Opción no válida." << endl;
        EditarD();
        break;
    }
}