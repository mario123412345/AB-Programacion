#include "AB Programacion.h"
void deliminar() {
    cout << "ID del doctor que quieres eliminar: ";
    int ide;
    cin >> ide;
    ifstream archivo("doctores.json");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo doctores.json" << endl;
        return;
    }
    json doc, doctoreseliminados;
    archivo >> doc;
    archivo.close();
    bool enc= false;
    for (auto it = doc.begin(); it != doc.end(); ++it) {
        if ((*it)["ID"] == to_string(ide)) {
            doctoreseliminados.push_back(*it);
            doc.erase(it);
            enc= true;
            cout << "Doctor eliminado" << endl;
            break;
        }
    }
    if (!enc) {
        cout << "No se encontró ningún doctor con el ID: " << ide << endl;
        return;
    }
    ofstream res("doctores.json");
    if (!res.is_open()) {
        cout << "Error al guardar los doctores actualizados en doctores.json" << endl;
        return;
    }
    res << doc.dump(4);
    res.close();
    ifstream leereliminados("doctoreselim.json");
    if (leereliminados.is_open()) {
        leereliminados >> doctoreseliminados;
        leereliminados.close();
    }
    ofstream elimi("doctoreselim.json");
    if (!elimi.is_open()) {
        cout << "Error al guardar los doctores eliminados en doctoreselim.json" << endl;
        return;
    }
    elimi << doctoreseliminados.dump(4);
    elimi.close();
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