#include "Sucursal.h"
#include <iostream>
#include <limits>
using namespace std;

Sucursal Sucursal::sucursal[5];
int Sucursal::sucursalCount = 0;

Sucursal::Sucursal(int NumeroSucursal, string DomicilioSucursal, string CiudadSucursal, string EstadoSucursal, string NomGerSucursal)
{
    numeroSucursal = NumeroSucursal;
    domicilioSucursal = DomicilioSucursal;
    ciudadSucursal = CiudadSucursal;
    estadoSucursal = EstadoSucursal;
    nomGerSucursal = NomGerSucursal;
}

Sucursal::Sucursal() {}

int validarNumero() {
    int numero;
    while (true) {
        cin >> numero;
        if (cin.fail() || numero <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor ingrese un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            break;
        }
    }
    return numero;
}

string validarTexto() {
    string texto;
    while (true) {
        getline(cin, texto);
        if (texto.empty() || texto.find_first_not_of(' ') == string::npos) {
            cout << "Entrada invalida. Por favor ingrese un texto valido: ";
        } else {
            break;
        }
    }
    return texto;
}

int Sucursal::nuevaSucursal() {
    if (sucursalCount >= 5) {
        cout << "No se pueden registrar mas sucursales. Límite alcanzado." << endl;
        return -1;
    }

    int numeroSucursal;
    string domicilioSucursal, ciudadSucursal, estadoSucursal, nomGerSucursal;

    cout << "Ingrese el Numero de Sucursal: ";
    numeroSucursal = validarNumero();

    for (int i = 0; i < sucursalCount; i++) {
        if (sucursal[i].numeroSucursal == numeroSucursal) {
            cout << "El numero de sucursal ya existe. Por favor ingrese un numero diferente." << endl;
            return -1;
        }
    }

    cout << "Ingrese el Domicilio de la Sucursal: ";
    domicilioSucursal = validarTexto();

    cout << "Ingrese la ciudad de la Sucursal: ";
    ciudadSucursal = validarTexto();

    cout << "Ingrese el estado de la Sucursal: ";
    estadoSucursal = validarTexto();

    cout << "Ingrese el nombre del gerente de la Sucursal: ";
    nomGerSucursal = validarTexto();

    sucursal[sucursalCount] = Sucursal(numeroSucursal, domicilioSucursal, ciudadSucursal, estadoSucursal, nomGerSucursal);
    sucursalCount++;
    cout << "Sucursal registrada correctamente." << endl;

    return numeroSucursal;
}

void Sucursal::mostrarSucursal() {
    cout << "Numero de Sucursal: " << numeroSucursal << endl;
    cout << "Domicilio: " << domicilioSucursal << endl;
    cout << "Ciudad: " << ciudadSucursal << endl;
    cout << "Estado: " << estadoSucursal << endl;
    cout << "Nombre del Gerente: " << nomGerSucursal << endl;
}

int Sucursal::modificarSucursal() {
    if (sucursalCount == 0) {
        cout << "No hay sucursales registradas para modificar." << endl;
        return -1;
    }

    int numeroSucursal;
    string domicilioSucursal, ciudadSucursal, estadoSucursal, nomGerSucursal;

    cout << "Ingrese el numero de la Sucursal que desea modificar: ";
    numeroSucursal = validarNumero();

    bool encontrado = false;

    for (int i = 0; i < sucursalCount; i++) {
        if (sucursal[i].numeroSucursal == numeroSucursal) {
            encontrado = true;

            cout << "Sucursal encontrada. Ingrese los nuevos datos:" << endl;

            cout << "Domicilio actual: " << sucursal[i].domicilioSucursal << endl;
            cout << "Ingrese el nuevo Domicilio de la Sucursal: ";
            domicilioSucursal = validarTexto();

            cout << "Ciudad actual: " << sucursal[i].ciudadSucursal << endl;
            cout << "Ingrese la nueva ciudad de la Sucursal: ";
            ciudadSucursal = validarTexto();

            cout << "Estado actual: " << sucursal[i].estadoSucursal << endl;
            cout << "Ingrese el nuevo estado de la Sucursal: ";
            estadoSucursal = validarTexto();

            cout << "Gerente actual: " << sucursal[i].nomGerSucursal << endl;
            cout << "Ingrese el nuevo nombre del gerente de la Sucursal: ";
            nomGerSucursal = validarTexto();

            sucursal[i] = Sucursal(numeroSucursal, domicilioSucursal, ciudadSucursal, estadoSucursal, nomGerSucursal);

            cout << "Sucursal modificada correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Sucursal con numero " << numeroSucursal << " no encontrada." << endl;
    }

    return numeroSucursal;
}

int Sucursal::eliminarSucursal() {
    if (sucursalCount == 0) {
        cout << "No hay sucursales registradas para eliminar." << endl;
        return -1;
    }

    int numeroSucursal;
    cout << "Ingrese el numero de Sucursal que desea eliminar: ";
    numeroSucursal = validarNumero();

    bool encontradoEliminar = false;

    for (int i = 0; i < sucursalCount; i++) {
        if (sucursal[i].numeroSucursal == numeroSucursal) {
            encontradoEliminar = true;
            for (int j = i; j < sucursalCount - 1; j++) {
                sucursal[j] = sucursal[j + 1];
            }
            sucursalCount--;
            cout << "Sucursal eliminada correctamente." << endl;
            break;
        }
    }

    if (!encontradoEliminar) {
        cout << "Sucursal con numero " << numeroSucursal << " no encontrada." << endl;
    }

    return 0;
}