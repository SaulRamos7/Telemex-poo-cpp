#include "Contrato.h"
#include <iostream>
#include <limits>
#include "Servicio.h"  

using namespace std;

Contrato Contrato::contrato[15];
int Contrato::contratoCount = 0;

Contrato::Contrato(int FolioServicio, int TelCasaServicio, int TelCelServicio, int TelOficinaServicio,
                   int TipoServicio, string EspecificacionesServicio, string NombreClienteServicio,
                   string DomicilioServicio, string RfcServicio, string RefNombre, string efTelefono) {

    folioServicio = FolioServicio;
    telCasaServicio = TelCasaServicio;
    telCelServicio = TelCelServicio;
    telOficinaServicio = TelOficinaServicio;
    tipoServicio = TipoServicio;
    especificacionesServicio = EspecificacionesServicio;
    nombreClienteServicio = NombreClienteServicio;
    gdomicilioServicio = DomicilioServicio;
    rfcServicio = RfcServicio;
    refNombre = RefNombre;
    refTelefono = efTelefono;
}

Contrato::Contrato() {}

int Contrato::nuevoContrato() {
    int folioServicio, telCasaServicio, telCelServicio, telOficinaServicio, tipoServicio;
    string especificacionesServicio, nombreClienteServicio, gdomicilioServicio, rfcServicio, refNombre, refTelefono;


    cout << "Ingrese el folio que se le fue asignado: ";
    while (!(cin >> folioServicio) || folioServicio <= 0) {
        cout << "Error: El folio debe ser un numero positivo." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el folio nuevamente: ";
    }


    cout << "Ingrese el telefono de Casa que anexará a su servicio: ";
    while (!(cin >> telCasaServicio)) {
        cout << "Error: El telefono debe ser un numero válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el telefono de casa nuevamente: ";
    }

    cout << "Ingrese el teléfono del celular que anexará a su servicio: ";
    while (!(cin >> telCelServicio)) {
        cout << "Error: El telefono debe ser un nemero válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el telefono del celular nuevamente: ";
    }

    cout << "Ingrese el teléfono de oficina que anexará a su servicio: ";
    while (!(cin >> telOficinaServicio)) {
        cout << "Error: El telefono debe ser un número válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el telefono de oficina nuevamente: ";
    }

    cout << "Ingrese el tipo de servicio que desea (1: Cable Básico, 2: Cable Total, 3: Cable Total Plus, 4: Internet + Cable, 5: Cable + Teléfono, 6:Cable + Internet + Telefono.): ";
    while (!(cin >> tipoServicio)) {
        cout << "Error: El tipo de servicio debe ser un número válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el tipo de servicio nuevamente: ";
    }
    switch (tipoServicio)
    {
    case 1:
        Servicio::mostrarServiciosCBas();
        break;

    case 2:
        Servicio::mostrarServiciosCTot();
    break;

    case 3:
        Servicio::mostrarServiciosCaCTotPl();
    break;

    case 4:
        Servicio::mostrarServiciosInMasCa();
    break;

    case 5:
        Servicio::mostrarServiciosCaMasTe();
    break;

    case 6:
        Servicio::mostrarServiciosCaInTel();
    break;
    
    default:
        break;
    }
    

    cout << "Ingrese su nombre por favor: ";
    cin >> nombreClienteServicio;

    cout << "Ingrese su domicilio por favor: ";
    cin >> gdomicilioServicio;

    cout << "Ingrese su RFC: ";
    cin >> rfcServicio;

    cout << "Ingrese un nombre de referencia: ";
    cin >> refNombre;

    cout << "Ingrese un telefono de referencia: ";
    cin >> refTelefono;


    contrato[contratoCount] = Contrato(folioServicio, telCasaServicio, telCelServicio, telOficinaServicio, tipoServicio,
                                       especificacionesServicio, nombreClienteServicio, gdomicilioServicio, rfcServicio,
                                       refNombre, refTelefono);
    contratoCount++;

    cout << "Contrato registrado exitosamente." << endl;
    cout << "El contrato con folio " << folioServicio << " ha sido creado." << endl;

    return folioServicio;
}

void Contrato::mostrarContrato() {
    cout << "Folio de contrato: " << folioServicio << endl;
    cout << "Tipo de servicio: " << tipoServicio << endl;
        switch (tipoServicio)
    {
    case 1:
        Servicio::mostrarServiciosCBas();
        break;

    case 2:
        Servicio::mostrarServiciosCTot();
    break;

    case 3:
        Servicio::mostrarServiciosCaCTotPl();
    break;

    case 4:
        Servicio::mostrarServiciosInMasCa();
    break;

    case 5:
        Servicio::mostrarServiciosCaMasTe();
    break;

    case 6:
        Servicio::mostrarServiciosCaInTel();
    break;
    
    default:
        break;
    }
    cout << "Especificaciones de servicio: " << endl;
    cout << "Tel202fono de Casa: " << telCasaServicio << endl;
    cout << "Telefono del celular: " << telCelServicio << endl;
    cout << "Telefono de oficina: " << telOficinaServicio << endl;
    cout << "Nombre del cliente: " << nombreClienteServicio << endl;
    cout << "Domicilio: " << gdomicilioServicio << endl;
    cout << "RFC: " << rfcServicio << endl;
    cout << "Nombre de referencia: " << refNombre << endl;
    cout << "Telefono de referencia: " << refTelefono << endl;

}

int Contrato::modificarContrato() {
    int folioServicio;
    bool encontrado = false;

    cout << "Ingrese el número de contrato que desea modificar: ";
    cin >> folioServicio;

    for (int i = 0; i < contratoCount; i++) {
        if (contrato[i].folioServicio == folioServicio) {
            encontrado = true;
            cout << "Contrato encontrado. Ingrese los nuevos datos o presione Enter para dejar el valor actual:" << endl;

            cout << "Teléfono de casa (" << contrato[i].telCasaServicio << "): ";
            int nuevoTelCasa;
            if (cin >> nuevoTelCasa) 
                contrato[i].telCasaServicio = nuevoTelCasa;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Teléfono celular (" << contrato[i].telCelServicio << "): ";
            int nuevoTelCel;
            if (cin >> nuevoTelCel) 
                contrato[i].telCelServicio = nuevoTelCel;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Teléfono de oficina (" << contrato[i].telOficinaServicio << "): ";
            int nuevoTelOficina;
            if (cin >> nuevoTelOficina) 
                contrato[i].telOficinaServicio = nuevoTelOficina;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nombre del cliente (" << contrato[i].nombreClienteServicio << "): ";
            string nuevoNombre;
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) 
                contrato[i].nombreClienteServicio = nuevoNombre;

            cout << "Domicilio (" << contrato[i].gdomicilioServicio << "): ";
            string nuevoDomicilio;
            getline(cin, nuevoDomicilio);
            if (!nuevoDomicilio.empty()) 
                contrato[i].gdomicilioServicio = nuevoDomicilio;

            cout << "RFC (" << contrato[i].rfcServicio << "): ";
            string nuevoRFC;
            getline(cin, nuevoRFC);
            if (!nuevoRFC.empty()) 
                contrato[i].rfcServicio = nuevoRFC;

            cout << "Nombre de referencia (" << contrato[i].refNombre << "): ";
            string nuevoRefNombre;
            getline(cin, nuevoRefNombre);
            if (!nuevoRefNombre.empty()) 
                contrato[i].refNombre = nuevoRefNombre;

            cout << "Teléfono de referencia (" << contrato[i].refTelefono << "): ";
            string nuevoRefTel;
            getline(cin, nuevoRefTel);
            if (!nuevoRefTel.empty()) 
                contrato[i].refTelefono = nuevoRefTel;

            cout << "Tipo de servicio actual (" << contrato[i].tipoServicio << "): ";
            cout << "Ingrese el nuevo tipo de servicio (1: Cable Básico, 2: Cable Total, 3: Cable Total Plus, "
                    "4: Internet + Cable, 5: Cable + Teléfono, 6: Cable + Internet + Teléfono): ";
            int nuevoTipoServicio;
            if (cin >> nuevoTipoServicio && nuevoTipoServicio >= 1 && nuevoTipoServicio <= 6) {
                contrato[i].tipoServicio = nuevoTipoServicio;
                switch (nuevoTipoServicio) {
                case 1:
                    Servicio::mostrarServiciosCBas();
                    break;
                case 2:
                    Servicio::mostrarServiciosCTot();
                    break;
                case 3:
                    Servicio::mostrarServiciosCaCTotPl();
                    break;
                case 4:
                    Servicio::mostrarServiciosInMasCa();
                    break;
                case 5:
                    Servicio::mostrarServiciosCaMasTe();
                    break;
                case 6:
                    Servicio::mostrarServiciosCaInTel();
                    break;
                default:
                    break;
                }
            } else {
                cout << "Tipo de servicio no válido. Se mantendrá el actual." << endl;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Contrato modificado correctamente." << endl;
            return folioServicio;
        }
    }

    if (!encontrado) {
        cout << "Contrato con folio " << folioServicio << " no encontrado." << endl;
    }

    return folioServicio;
}


void Contrato::buscarContratoPorNumero() {
    int folioServicio;
    cout << "Ingrese el folio del contrato que desea buscar: ";
    cin >> folioServicio;

    for (int i = 0; i < contratoCount; i++) {
        if (contrato[i].folioServicio == folioServicio) {
            cout << "Contrato encontrado:" << endl;
            contrato[i].mostrarContrato();
            return;
        }
    }
    cout << "Contrato con folio " << folioServicio << " no encontrado." << endl;
}

int Contrato::eliminarContrato() {
    int folioServicio;
    bool encontradoEliminar = false;

    cout << "Ingrese el numero de contrato que desea eliminar: ";
    cin >> folioServicio;

    for (int i = 0; i < contratoCount; i++) {
        if (contrato[i].folioServicio == folioServicio) {
            encontradoEliminar = true;
            for (int j = i; j < contratoCount - 1; j++) {
                contrato[j] = contrato[j + 1];
            }
            contratoCount--;
            cout << "Contrato eliminado correctamente." << endl;
            break;
        }
    }

    if (!encontradoEliminar) {
        cout << "Contrato con folio " << folioServicio << " no encontrado." << endl;
    }

    return 0;
}

