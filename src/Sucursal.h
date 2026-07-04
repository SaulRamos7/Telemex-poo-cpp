#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <string>
using namespace std;

class Sucursal {
private:
    static Sucursal sucursal[5];
    static int sucursalCount; 
    int numeroSucursal;
    string domicilioSucursal;
    string ciudadSucursal;
    string estadoSucursal;
    string nomGerSucursal;

public:
    Sucursal();
    Sucursal(int NumeroSucursal, string DomicilioSucursal, string CiudadSucursal, string EstadoSucursal, string NomGerSucursal);

    static int getSucursalCount() {
        return sucursalCount;
    }

    static Sucursal* getSucursales() {
        return sucursal;
    }

    static int nuevaSucursal();
    static int modificarSucursal();

    static int eliminarSucursal();
    void mostrarSucursal();
};

#endif