#include "AB Programacion.h"
void deliminar() {
    cout << "ID del doctor que quieres eliminar: ";
    int idd;
    cin >> idd;
    ifstream doctoresj("doctores.json");
    if (!doctoresj.is_open()) {
        cout << "Archovo de doctores ya abierto" << endl;


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


}

void EliminarD() {
	int vol;
	cout << "----------------------------" << endl;
    cout << "Has elegido Eliminar un docotr" << endl;
	cout << "Volver-->1" << endl;
	cout << "Inicio -->2" << endl;
    cout << "Continuar-->3" << endl;
	cin >> vol;
    switch (vol) {
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