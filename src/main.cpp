#include <iostream>
#include <string>
#include "Empleado.h"
#include "Sucursal.h"
#include "Contrato.h"
#include "Servicio.h"

using namespace std;

int main()
{
    int menuopcion, empleadoOpcion, sucursalOpcion, contratoOpcion, servicioOpcion;
    bool menu = true;

    do
    {
        cout << "Bienvenido al sistema de Telemex. A que apartado desea acceder?" << endl;
        cout << "1. Acceder a Empleado" << endl;
        cout << "2. Acceder a Sucursales" << endl;
        cout << "3. Acceder a Servicios" << endl;
        cout << "4. Acceder a Contratos" << endl;
        cout << "5. Salir" << endl;

        cin >> menuopcion;

        switch (menuopcion)
        {
        case 1:
            do
            {
                system("CLS");
                cout << "Ingresaste a Empleado:" << endl;
                cout << "1. Nuevo Empleado" << endl;
                cout << "2. Ver Empleados" << endl;
                cout << "3. Modificar Empleado" << endl;
                cout << "4. Eliminar Empleado" << endl;
                cout << "5. Buscar Empleado" << endl;
                cout << "6. Salir" << endl;
                cin >> empleadoOpcion;

                switch (empleadoOpcion)
                {
                case 1:
                    system("CLS");
                    if (Empleado::getEmpleadoCount() < 10)
                    {
                        cout << "Nuevo Empleado" << endl;
                        int numeroEmpleado = Empleado::nuevoEmpleado();
                        cout << "El empleado con número " << numeroEmpleado << " ha sido creado." << endl;
                    }
                    else
                    {
                        cout << "No se pueden registrar más empleados. Límite alcanzado." << endl;
                    }
                    break;

                case 2:

                    if (Empleado::getEmpleadoCount() > 0)
                    {
                        cout << "Lista de empleados registrados:" << endl;
                        for (int i = 0; i < Empleado::getEmpleadoCount(); i++)
                        {
                            cout << "-----------------------------------" << endl;
                            Empleado::getEmpleado()[i].mostrarEmpleado();
                            cout << "-----------------------------------" << endl;
                        }
                    }
                    else
                    {
                        cout << "No hay empleados registrados." << endl;
                    }
                    system("PAUSE");
                    break;

                case 3:
                    system("CLS");
                    cout << "Modificacion de Empleado" << endl;
                    Empleado::modificarEmpleado();
                    break;

                case 4:
                    system("CLS");
                    cout << "Eliminar Empleado" << endl;
                    Empleado::eliminarEmpleado();
                    break;
                    
                case 5:
                    cout << "Buscar empleado por numero" << endl;
                    Empleado::buscarEmpleadoPorNumero();
                    system("PAUSE");
                    break;

                case 6:
                    cout << "Saliendo de Empleado..." << endl;
                    break;

                default:
                    cout << "Opcion no valida en Empleados." << endl;
                    break;
                }
            } while (empleadoOpcion != 6);
            break;

        case 2:
            do
            {
                system("CLS");
                cout << "Ingresaste a Sucursal:" << endl;
                cout << "1. Nueva Sucursal" << endl;
                cout << "2. Ver Sucursales" << endl;
                cout << "3. Modificar Sucursal" << endl;
                cout << "4. Eliminar Sucursal" << endl;
                cout << "5. Salir" << endl;
                cin >> sucursalOpcion;

                switch (sucursalOpcion)
                {
                case 1:
                    system("CLS");
                    if (Sucursal::getSucursalCount() < 5)
                    {
                        cout << "Nueva Sucursal" << endl;
                        int numeroSucursal = Sucursal::nuevaSucursal();
                        cout << "La sucursal con número " << numeroSucursal << " ha sido creada." << endl;
                    }
                    else
                    {
                        cout << "No se pueden registrar más sucursales. Límite alcanzado." << endl;
                    }
                    break;

                case 2:
                    system("CLS");
                    if (Sucursal::getSucursalCount() > 0)
                    {
                        cout << "Lista de sucursales registradas:" << endl;
                        for (int i = 0; i < Sucursal::getSucursalCount(); i++)
                        {
                            cout << "-----------------------------------" << endl;
                            Sucursal::getSucursales()[i].mostrarSucursal();
                            cout << "-----------------------------------" << endl;
                        }
                    }
                    else
                    {
                        cout << "No hay sucursales registradas." << endl;
                    }
                    system("PAUSE");
                    break;

                case 3:
                    system("CLS");
                    cout << "Modificacion de Sucursal" << endl;
                    Sucursal::modificarSucursal();
                    break;

                case 4:
                    system("CLS");
                    cout << "Eliminar Sucursal" << endl;
                    Sucursal::eliminarSucursal();
                    break;

                case 5:
                    cout << "Saliendo de Sucursal..." << endl;
                    break;

                default:
                    cout << "Opcion no valida en Sucursales." << endl;
                    break;
                }
            } while (sucursalOpcion != 5);
            break;

        case 3:
            do
            {
                system("CLS");
                cout << "Ingresaste a Servicios:" << endl;
                cout << "1. Ver Servicios" << endl;
                cout << "2. Salir" << endl;
                cin >> servicioOpcion;

                switch (servicioOpcion)
                {
                case 1:
                    Servicio::mostrarServiciosCBas();
                    Servicio::mostrarServiciosCTot();
                    Servicio::mostrarServiciosCaCTotPl();
                    Servicio::mostrarServiciosInMasCa();
                    Servicio::mostrarServiciosCaMasTe();
                    Servicio::mostrarServiciosCaInTel();
                    system("PAUSE");
                    break;

                case 2:
                    cout << "Saliendo de Servicios..." << endl;
                    break;

                default:
                    cout << "Opcion no valida en Servicios." << endl;
                    break;
                }
            } while (servicioOpcion != 2);
            
            break;

        case 4:
            do
            {
                system("CLS");
                cout << "Ingresaste a Contratos:" << endl;
                cout << "1. Nuevo Contrato" << endl;
                cout << "2. Ver Contratos" << endl;
                cout << "3. Modificar Contrato" << endl;
                cout << "4. Eliminar Contrato" << endl;
                cout << "5. Buscar Contrato por número" << endl;
                cout << "6. Salir" << endl;
                cin >> contratoOpcion;

                switch (contratoOpcion)
                {
                case 1:
                    system("CLS");
                    if (Contrato::getContratoCount() < 15)
                    {
                        cout << "Nuevo Contrato" << endl;
                        int folioServicio = Contrato::nuevoContrato();
                        cout << "El contrato con folio " << folioServicio << " ha sido creado." << endl;
                    }
                    else
                    {
                        cout << "No se pueden registrar más contratos. Límite alcanzado." << endl;
                    }
                    break;

                case 2:
                    system("CLS");
                    if (Contrato::getContratoCount() > 0)
                    {
                        cout << "Lista de contratos registrados:" << endl;
                        for (int i = 0; i < Contrato::getContratoCount(); i++)
                        {
                            cout << "-----------------------------------" << endl;
                            Contrato::getContrato()[i].mostrarContrato();
                            cout << "-----------------------------------" << endl;
                        }
                    }
                    else
                    {
                        cout << "No hay contratos registrados." << endl;
                    }
                    system("PAUSE");
                    break;

                case 3:
                    system("CLS");
                    cout << "Modificacion de Contrato" << endl;
                    Contrato::modificarContrato();
                    
                    break;

                case 4:
                    cout << "Eliminar Contrato" << endl;
                    Contrato::eliminarContrato();
                    break;

                case 5:
                    cout << "Buscar Contrato" << endl;
                    Contrato::buscarContratoPorNumero();
                    system("PAUSE");
                    break;

                case 6:
                    cout << "Saliendo de Contratos..." << endl;
                    break;

                default:
                    cout << "Opcion no valida en Contratos." << endl;
                    break;
                }
            } while (contratoOpcion != 6);
            break;

        case 5:
            menu = false;
            cout << "Saliendo del sistema. Hasta pronto!" << endl;
            break;

        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }
    } while (menu);

    return 0;
}
