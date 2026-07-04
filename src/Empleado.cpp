#include "Empleado.h"
#include <iostream>
#include <limits>
using namespace std;

Empleado Empleado::empleado[10];
int Empleado::empleadoCount = 0;

Empleado::Empleado(int NumeroEmpleado, int CodigoEmpleado, string NombreEmpleado, string RfcEmpleado, string FingresoEmpleado) {
    numeroEmpleado = NumeroEmpleado;
    codigoEmpleado = CodigoEmpleado;
    nombreEmpleado = NombreEmpleado;
    rfcEmpleado = RfcEmpleado;
    FIngresoEmpleado = FingresoEmpleado;
}

Empleado::Empleado() {}

int validarNumeroEmpleado() {
    int numero;
    while (true) {
        cin >> numero;
        if (cin.fail() || numero <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor ingrese un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
    }
    return numero;
}

string validarTextoEmpleado() {
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

int Empleado::nuevoEmpleado() {
    if (empleadoCount >= 10) {
        cout << "No se pueden registrar mas empleados. Límite alcanzado." << endl;
        return -1;
    }

    int numeroEmpleado, codigoEmpleado;
    string nombreEmpleado, rfcEmpleado, FIngresoEmpleado;

    cout << "Ingrese el numero de empleado: ";
    numeroEmpleado = validarNumeroEmpleado();


    for (int i = 0; i < empleadoCount; i++) {
        if (empleado[i].numeroEmpleado == numeroEmpleado) {
            cout << "El numero de empleado ya existe. Por favor ingrese un numero diferente." << endl;
            return -1;
        }
    }

    cout << "Ingrese el C\242digo del Empleado: ";
    codigoEmpleado = validarNumeroEmpleado();

    cout << "Ingrese el Nombre del Empleado: ";
    nombreEmpleado = validarTextoEmpleado();

    cout << "Ingrese el RFC del Empleado: ";
    rfcEmpleado = validarTextoEmpleado();

    cout << "Ingrese la Fecha de Ingreso del Empleado (dd/mm/yyyy): ";
    FIngresoEmpleado = validarTextoEmpleado();

    empleado[empleadoCount] = Empleado(numeroEmpleado, codigoEmpleado, nombreEmpleado, rfcEmpleado, FIngresoEmpleado);
    empleadoCount++;
    cout << "Empleado registrado correctamente." << endl;

    return numeroEmpleado;
}

void Empleado::mostrarEmpleado() {
    cout << "Numero de Empleado: " << numeroEmpleado << endl;
    cout << "C\242digo de Empleado: " << codigoEmpleado << endl;
    cout << "Nombre del Empleado: " << nombreEmpleado << endl;
    cout << "RFC del Empleado: " << rfcEmpleado << endl;
    cout << "Fecha de Ingreso: " << FIngresoEmpleado << endl;
}

int Empleado::modificarEmpleado() {
    if (empleadoCount == 0) {
        cout << "No hay empleados registrados para modificar." << endl;
        return -1;
    }

    int numeroEmpleado, codigoEmpleado;
    string nombreEmpleado, rfcEmpleado, FIngresoEmpleado;

    cout << "Ingrese el numero de empleado que desea modificar: ";
    numeroEmpleado = validarNumeroEmpleado();

    bool encontrado = false;

    for (int i = 0; i < empleadoCount; i++) {
        if (empleado[i].numeroEmpleado == numeroEmpleado) {
            encontrado = true;

            cout << "Empleado encontrado. Ingrese los nuevos datos:" << endl;

            cout << "C\242digo actual: " << empleado[i].codigoEmpleado << endl;
            cout << "Ingrese el nuevo C\242digo: ";
            codigoEmpleado = validarNumeroEmpleado();

            cout << "Nombre actual: " << empleado[i].nombreEmpleado << endl;
            cout << "Ingrese el nuevo Nombre: ";
            nombreEmpleado = validarTextoEmpleado();

            cout << "RFC actual: " << empleado[i].rfcEmpleado << endl;
            cout << "Ingrese el nuevo RFC: ";
            rfcEmpleado = validarTextoEmpleado();

            cout << "Fecha de Ingreso actual: " << empleado[i].FIngresoEmpleado << endl;
            cout << "Ingrese la nueva Fecha de Ingreso: ";
            FIngresoEmpleado = validarTextoEmpleado();

            empleado[i] = Empleado(numeroEmpleado, codigoEmpleado, nombreEmpleado, rfcEmpleado, FIngresoEmpleado);

            cout << "Empleado modificado correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Empleado con numero " << numeroEmpleado << " no encontrado." << endl;
    }

    return numeroEmpleado;
}

int Empleado::eliminarEmpleado() {
    if (empleadoCount == 0) {
        cout << "No hay empleados registrados para eliminar." << endl;
        return -1;
    }

    int numeroEmpleado;
    cout << "Ingrese el numero de empleado que desea eliminar: ";
    numeroEmpleado = validarNumeroEmpleado();

    bool encontradoEliminar = false;

    for (int i = 0; i < empleadoCount; i++) {
        if (empleado[i].numeroEmpleado == numeroEmpleado) {
            encontradoEliminar = true;
            for (int j = i; j < empleadoCount - 1; j++) {
                empleado[j] = empleado[j + 1];
            }
            empleadoCount--;
            cout << "Empleado eliminado correctamente." << endl;
            break;
        }
    }

    if (!encontradoEliminar) {
        cout << "Empleado con numero " << numeroEmpleado << " no encontrado." << endl;
    }

    return 0;
}

void Empleado::buscarEmpleadoPorNumero() {
    int numeroEmpleado;
    cout << "Ingrese el numero del empleado que desea buscar: ";
    cin >> numeroEmpleado;

    for (int i = 0; i < empleadoCount; i++) {
        if (empleado[i].numeroEmpleado == numeroEmpleado) {
            cout << "Empleado encontrado:" << endl;
            empleado[i].mostrarEmpleado();
            return;
        }
    }
    cout << "Empleado con número " << numeroEmpleado << " no encontrado." << endl;
}