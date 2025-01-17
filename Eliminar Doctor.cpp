#include "AB Programacion.h"

void doctor::eliminardoctor(int idd) {
    ifstream doctoresj("doctores.json");
    if (!doctoresj.is_open()) {
        cout << "Archivo de doctores ya abierto" << endl;
    }
    json doctores;
    doctoresj >> doctores;
    doctoresj.close();
    json doctoreselim;
    ifstream doctoreselimjson("doctoreselim.json");
    if (!doctoreselimjson.is_open()) {
        doctoreselimjson >> doctoreselim;
        doctoreselimjson.close();
    }
    bool encontrar = false;
    for (auto enc = doctores.begin(); enc != doctores.end();
        ++enc) {
        if ((*enc)["ID"] == idd) {
            doctoreselim.push_back(*enc);
            enc = doctores.erase(enc);
            cout << "Doctor con el id:" << idd << "se ha eliminado" << endl;
            encontrar = true;
            break;
        }
    }
    if (!encontrar) {
        cout << "Error. doctor" << idd << "no encontrado" << endl;
    }
    ofstream cambio("doctores.json");
    if (!cambio.is_open()) {
        cout << "Error1" << endl;
    }
    cambio << doctores.dump(4);
    cambio.close();
    ofstream cambioelim("doctoreselim.json");
    if (!cambioelim.is_open()) {
        cout << "Error al guardar eliminado" << endl;
    }
    cambioelim << doctoreselim.dump(4);
    cambioelim.close();
    backup("doctores.json");
}
void deliminar() {
    int idd;
    cout << "Cual es el id del doctor que quieres eliminar?" << endl;
    cin >> idd;
    doctor::eliminardoctor(idd);
}
void EliminarD() {
	int opcion;
	cout << "----------------------------" << endl;
    cout << "Has elegido Eliminar un docotr" << endl;
    cout << "1.Volver a la seccion anterior" << endl;
    cout << "2.Volver al inicio" << endl;
    cout << "3.Continuar" << endl;
    while (true) {
        string input;
        cin >> input;
        stringstream ss(input);
        if (ss >> opcion && ss.eof()) {
            break;
        }
        else {
            cout << "Esscribe un numero valido ";
        }
    }
    switch (opcion) {
        case 1:
            eliminar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            deliminar();
            break;
    default:
        cout << "Error" << endl;
        EliminarD();
        break;
    }
}