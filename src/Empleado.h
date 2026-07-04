#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using namespace std;

class Empleado {
private:
    static Empleado empleado[10];
    static int empleadoCount;
    int numeroEmpleado;
    int codigoEmpleado;
    string nombreEmpleado;
    string rfcEmpleado;
    string FIngresoEmpleado;


public:
    Empleado();
    Empleado(int NumeroEmpleado, int CodigoEmpleado, string NombreEmpleado, string RfcEmpleado, string FingresoEmpleado);

    static int getEmpleadoCount() {
        return empleadoCount;
    }

    static Empleado* getEmpleado() {
        return empleado;
    }

    static int nuevoEmpleado();
    static int modificarEmpleado();
    static void buscarEmpleadoPorNumero();
    static int eliminarEmpleado();
    void mostrarEmpleado();
};

#endif