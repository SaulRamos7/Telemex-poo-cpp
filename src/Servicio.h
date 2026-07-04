#ifndef SERVICIO_H
#define SERVICIO_H

#include <iostream>
using namespace std;

class Servicio
{

private:
   
    int costoServicio;
    int comisionServicio;
    string politicasServicio;

public:
    
    Servicio();
    Servicio(int, int, string);

    static int mostrarServiciosCBas();
    static int mostrarServiciosCTot();
    static int mostrarServiciosCaCTotPl();
    static int mostrarServiciosInMasCa();
    static int mostrarServiciosCaMasTe();
    static int mostrarServiciosCaInTel();

};

#endif // SERVICIO_H