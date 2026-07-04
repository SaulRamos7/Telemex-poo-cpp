#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
using namespace std;

class Contrato{
private:
    static Contrato contrato[15];
    static int contratoCount; 
    int folioServicio; 
    int telCasaServicio; 
    int telCelServicio; 
    int telOficinaServicio;
    int tipoServicio;
    string especificacionesServicio; 
    string nombreClienteServicio;
    string gdomicilioServicio; 
    string rfcServicio; 
    string refNombre; 
    string refTelefono;

public:
    Contrato();
    Contrato(int, int, int, int, int, string, string, string, string, string, string);

    static int getContratoCount() {
        return contratoCount;
    }

    static Contrato* getContrato() {
        return contrato;
    }
       
    static int nuevoContrato();
    static int modificarContrato();
    static int eliminarContrato();
    static void buscarContratoPorNumero();
    void mostrarContrato();
};

#endif // CONTRATO_H