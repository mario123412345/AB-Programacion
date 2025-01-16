#include "AB Programacion.h"

void cita::eliminarcita(int idc) {
    ifstream citasj("citas.json");
    if (citasj.is_open()) {
        cout << "Error al abrir" << endl;
    }
    json citas;
    citasj >> citas;
    citasj.close();
    json citaselim;
    ifstream citaseliminadasjson("citaselim.json");
    if (!citaseliminadasjson.is_open()) {
        citaseliminadasjson >> citaselim;
        citaseliminadasjson.close();
    }

    bool encontrar = false;
    for (auto enc = citas.begin(); enc != citas.end();
        ++enc) {
        if ((*enc)["ID"] == idc) {
            citaselim.push_back(*enc);
            enc = citas.erase(enc);
            cout << "Cita con el id" << idc << "se ha eliminado" << endl;
            encontrar = true;
            break;
        }
    }
    if (!encontrar) {
        cout << "Error, cita con" << idc << "no encontrada" << endl;
    }
    ofstream cambio("citas.json");
    if (!cambio.is_open()) {
        cout << "Error1" << endl;
    }
    cambio << citas.dump(4);
    cambio.close();
    ofstream cambioelim("citaselim.json");
    if (!cambioelim.is_open()) {
        cout << "Error al guardar eliminado" << endl;
    }
    cambioelim << citaselim.dump(4);
    cambioelim.close();
}
void celiminar(){
    int idc;
    cout << "Cual es el id de la cita que quieres eliminar?" << endl;
    cin >> idc;
    cita::eliminarcita(idc);
}
void EliminarC() {
	int vol;
	cout << "----------------------------" << endl;
	cout << "Has seleccionado eliminar" << endl;
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
            eliminar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            celiminar();
            break;
    default:
        cout << "Error" << endl;
        EliminarC();
        break;
    }
}