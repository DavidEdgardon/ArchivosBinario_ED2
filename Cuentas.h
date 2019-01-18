//
// Created by ASUS on 1/15/2019.
//

#ifndef ARCHIVOSBINARIOS_CUENTAS_H
#define ARCHIVOSBINARIOS_CUENTAS_H

struct cliente{
    int n_cuenta;
    char nombre[20];
    double saldo;

    //32 bits
};

class cuentas {
public:
    static void agregarCliente();
    static void consultarCliente();
};




#endif //ARCHIVOSBINARIOS_CUENTAS_H
