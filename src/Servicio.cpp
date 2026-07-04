#include "Servicio.h"
#include <iostream>

using namespace std;


Servicio::Servicio(int CostoServicio, int ComisionServicio, string PoliticasServicio){
    
    costoServicio = CostoServicio;
    comisionServicio = ComisionServicio;
    politicasServicio = PoliticasServicio;
}

Servicio::Servicio(){
}

    Servicio::mostrarServiciosCBas(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO" << endl;
    cout << "Cable Basico: " << endl;
    cout << "Costo $150 " << endl;
    cout << "Comision de paga de empleado $5%" << endl;
    cout << "--------------------------------" << endl;
    return 0;
    }

    Servicio::mostrarServiciosCTot(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO" << endl;
    cout << "Cable Total: " << endl;
    cout << "costo $300 " << endl;
    cout << "Comision de paga de empleado $10%" << endl;
    cout << "--------------------------------" << endl;
    return 0;
    }

    Servicio::mostrarServiciosCaCTotPl(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO" << endl;
    cout << "Cable Total Plus: " << endl;
    cout << "costo $550 " << endl;
    cout << "Comision de paga de empleado $10%" << endl;
    cout << "--------------------------------" << endl;
    return 0;
    }

    Servicio::mostrarServiciosInMasCa(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO " << endl;
    cout << "Internet + Cable: " << endl;
    cout << "costo $449 " << endl;
    cout << "Comision de paga de empleado $10%" << endl;
    cout << "--------------------------------" << endl;
     return 0;
    }

    Servicio::mostrarServiciosCaMasTe(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO " << endl;
    cout << "Cable + Teléfono: " << endl;
    cout << "Costo $500 " << endl;
    cout << "Comision de paga de empleado $12%" << endl;
    cout << "--------------------------------" << endl;
     return 0;
    }

    Servicio::mostrarServiciosCaInTel(){
    cout << "--------------------------------" << endl;
    cout << "POLITICAS DE SERVICIO " << endl;
    cout << "Cable + Internet + Telefono: " << endl;
    cout << "Costo $635 " << endl;
    cout << "Comision de paga de empleado $15%" << endl;
    cout << "--------------------------------" << endl;
     return 0;
    }