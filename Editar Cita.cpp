#include "AB Programacion.h"
void cita::editarcita(int idc) {
    ifstream archivo("citas.json");
    if (!archivo.is_open()) {
        cout << "Error al abrir para editar las citas" << endl;
        return;
    }
    json citas;
    archivo >> citas;
    archivo.close();
    ifstream pacientesjson("pacientes.json");
    if (!pacientesjson.is_open()) {
        cout << "Error al abrir archivo de pacientes" << endl;
        return;
    }
    json pacientes;
    pacientesjson >> pacientes;
    pacientesjson.close();
    ifstream doctoresjson("doctores.json");
    if (!doctoresjson.is_open()) {
        cout << "Error al abrir el archivo de doctores" << endl;
        return;
    }
    json doctores;
    doctoresjson >> doctores;
    doctoresjson.close();

    bool encontrar = false;
    for (auto& cita : citas) {
        if (cita["ID"] == idc) {
            encontrar = true;
            cout << "Cita con id" << idc << "encontrada" << endl;
            cout << "1.Fecha de la cita" << cita["Fecha"]<<endl;
            cout << "2.Hora de la cita " << cita["Hora"]<<endl;
            int idpaciente = cita["IDpac"];
            auto pacienteencontrado = find_if(pacientes.begin(), pacientes.end(),
                [idpaciente](const json& paciente) {
                    return paciente["ID"] == idpaciente;
                });
            if (pacienteencontrado != pacientes.end()) {
                cout << "3.Paciente actual:" << endl;
                cout << "ID:" << (*pacienteencontrado)["ID"] << endl;
                cout << "Nombre" << (*pacienteencontrado)["Nombre"] << endl;
                cout << "Apellido1" << (*pacienteencontrado)["Apellido1"] << endl;
                cout << "Apellido2" << (*pacienteencontrado)["Apellido2"] << endl;
                cout << "Enfermedad" << (*pacienteencontrado)["Enfermedad"] << endl;
            }
            else {
                cout << "Ha habido un problema, no hay ya pacientes con id"<<idpaciente <<"Puede haberse eliminado por error" << endl;
            }
            int iddoctor = cita["IDdoc"];
            auto doctorencontrado = find_if(doctores.begin(), doctores.end(),
                [iddoctor](const json& doctor) {
                    return doctor["ID"] == iddoctor;
                });

            if (doctorencontrado != doctores.end()) {
                cout << "4.Doctor actual:" << endl;
                cout << "ID:" << (*doctorencontrado)["ID"] << endl;
                cout << "Nombr" << (*doctorencontrado)["Nombre"] << endl;
                cout << "Especialidad" << (*doctorencontrado)["Especialidad"] << endl;
                cout << "Disponibilidad" << (*doctorencontrado)["Disponibilidad"] << endl;
            }
            else {
                cout << "Doctor con id"<<iddoctor<< "no se ha encontrado, puede haberse eliminado por error" << endl;
            }
            int eleccion;
            int IDnuevo;
            string nuevodato;
            auto nuevopaciente = pacientes.end();
            auto nuevodoctor = doctores.end();
            cout << "Elige que opción quieres editar" << endl;
            while (true) {
                string input;
                cin >> input;
                stringstream ss(input);
                if (ss >> eleccion && ss.eof()) {
                    break;
                }
                else {
                    cout << "Esscribe un numero valido ";
                }
            }
            switch (eleccion) {
                case 1:
                    cout << "Escribe la nueva fecha(dd/mm/año) abajo" << endl;
                    cin.ignore();
                    getline(cin, nuevodato);
                    cita["Fecha"] = nuevodato;
                break;
                case 2:
                    cout << "Escribe debajo la hora de la cita(24h)" << endl;
                    cin.ignore();
                    getline(cin, nuevodato);
                    cita["Hora"] = nuevodato;
                break;
                case 3:
                    cout << "Escribe el id del paciente por el que quieras cambiar al actual" << endl;
                    cin >> IDnuevo;
                    cita["IDpac"] = IDnuevo;
                    nuevopaciente = std::find_if(pacientes.begin(), pacientes.end(),
                        [IDnuevo](const json& paciente) {
                            return paciente["ID"] == IDnuevo;
                        });
                    if (nuevopaciente != pacientes.end()) {
                        cout << "Nuevo paciente seleccionado con id " << IDnuevo << endl;
                        cout << "Nombre" << (*nuevopaciente)["Nombre"] << endl;
                        cout << "Apellido 1" << (*nuevopaciente)["Apellido1"] << endl;
                        cout << "Apellido 2" << (*nuevopaciente)["Apellido2"] << endl;
                        cout << "Enfermedad" << (*nuevopaciente)["Enfermedad"] << endl;
                    }
                    else {
                        cout << "Paciente con id" << IDnuevo << "no encontrado" << endl;
                    }
                    break;
                case 4:
                    cout << "Escribe el id del doctor por el que quieras cambiar al actual" << endl;
                    cin >> IDnuevo;
                    cita["IDdoc"] = IDnuevo;
                    nuevodoctor = std::find_if(doctores.begin(), doctores.end(),
                        [IDnuevo](const json& doctor) {
                            return doctor["ID"] == IDnuevo;
                        });
                    if (nuevodoctor != doctores.end()) {
                        cout << "Nuevo doctor seleccionado con el i"<< IDnuevo << endl;
                        cout << "Nombre" << (*nuevodoctor)["Nombre"] << endl;
                        cout << "Apellido 1" << (*nuevodoctor)["Apellido1"] << endl;
                        cout << "Apellido 2" << (*nuevodoctor)["Apellido2"] << endl;
                        cout << "Especialidad" << (*nuevodoctor)["Especialidad"] << endl;
                    }
                    else {
                        cout << "Doctor con id" << IDnuevo << "no encontrado" << endl;
                    }
                    break;
                default:
                    cout << "No hay citas con el id" << idc << endl;
                    break;
            } 
        }
    }
    if (!encontrar) {
        cout << "No se encontró ninguna cita con el ID proporcionado." << endl;
        return;
    }
    ofstream nuevoarchivo("citas.json");
    if (!nuevoarchivo.is_open()) {
        cout << "Error al guardar los cambios en el archivo de citas." << endl;
        return;
    }
    nuevoarchivo << citas.dump(4);
    nuevoarchivo.close();
    backup("citas.json");
    cout << "La cita se ha editado y se ha guardado" << endl;
}
void ceditar() {
    int idc;
    cout << "Cual es el id de la cita que quieres editar?" << endl;
    cin >> idc;
    cita::editarcita(idc);
}
void EditarC() {
	int opcion;
	cout << "----------------------------" << endl;
	cout << "Editando cita" << endl;
	cout << "Selecciona una" << endl;
	cout << "1.Volver a la sección anterior(Selecciona que se quiere editar)" << endl;
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
            editar();
            break;
        case 2:
            inicio();
            break;
        case 3:
            ceditar();
            break;

    default:
        cout << "Error" << endl;
        EditarC();
        break;
    }
}