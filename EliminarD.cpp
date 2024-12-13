#include "AB Programacion.h"
void deliminar() {
    cout << "ID del doctor que quieres eliminar: ";
    int ide;
    cin >> ide;
    ifstream archivo("doctores.json");
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo doctores.json" << endl;
        return;
    }
    json doctores, doctoreselim;
    archivo >> doctores;
    archivo.close();

    bool encontrado = false;
    for (auto it = doctores.begin(); it != doctores.end(); ++it) {
        if ((*it)["ID"] == ide) {  
            doctoreselim.push_back(*it); 
            doctores.erase(it);          
            encontrado = true;
            cout << "Doctor eliminado " << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ningún doctor con el ID: " << ide << endl;
        return;
    }
    ofstream res("doctores.json");
    if (!res.is_open()) {
        cout << "Error1" << endl;
        return;
    }
    res << doctores.dump(4);
    res.close();
    ofstream elimi("doctoreselim.json", ios::app);
    if (!elimi.is_open()) {
        cout << "ERror2" << endl;
        return;
    }
    elimi << doctoreselim.dump(4);
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