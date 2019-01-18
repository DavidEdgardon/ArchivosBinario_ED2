//
// Created by ASUS on 1/15/2019.
//

#ifndef ARCHIVOSBINARIOS_TRANSACCIONES_H
#define ARCHIVOSBINARIOS_TRANSACCIONES_H


struct transacciones{
    int n_cuenta;
    int t_transac;
    double monto_transac;
};

class Transacciones {
public:
    static void agregarDeposito();
    static void agregarRetiro();
    static void consultarHisto();

};


#endif //ARCHIVOSBINARIOS_TRANSACCIONES_H
