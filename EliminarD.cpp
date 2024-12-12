#include "AB Programacion.h"
void deliminar() {
    cout << "ID del doctor quieres eliminar:";
    int ide;
    cin >> ide;
    cout << "Eliminando doctor" << endl;
    ifstream archivo("doctores.json");
    if (!archivo.is_open()) {
        cout << "ERROR" << endl;
    }
    json doctores;
    archivo >> doctores;
    archivo.close();
    //añadir un booleano?
        bool doc = false;
        for (auto it=doctores.begin(); it !=doctores.end(); ++it) {
            if ((*it)["ID"] == "ID") {
                doc=true;
                doctores.erase(it);
                cout << "Doctor eliminado" << endl;
                break;
            }
        }
        if (!doc) {
            cout << "Error, el id del doctor no existee" << endl;
        }
        ofstream nuevarchivo("doctores.json");
        if (!nuevarchivo.is_open()) {
            cout << "Error, volver a intentar";
        }
    

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