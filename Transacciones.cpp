//
// Created by ASUS on 1/15/2019.
//

#include "Transacciones.h"
#include "Cuentas.h"
#include <iostream>
#include <fstream>

using namespace std;

void Transacciones::agregarDeposito() {
    ofstream transfile("transacciones.dat", ios::app | ios::out | ios::binary);

    if(!transfile) {
        cout<<"Error al abrir archivo"<<endl;
    }

    transacciones nuevo;
    cout<<endl<<"*** D E P O S I T O  ***\n";

    cout<<"Ingrese numero de cuenta:"<<endl;
    cin>>nuevo.n_cuenta;
    cout<<"Ingrese tipo de transacciones:"<<endl;
    cin>>nuevo.t_transac;
    cout<<"Ingrese monto de transacciones:"<<endl;
    cin>>nuevo.monto_transac;


    transfile.seekp(0, ios::end );
    transfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(transacciones));
    transfile.close();

    cliente temporal;
    ifstream lecturaA("MaestroCuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);

    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));

    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevo.n_cuenta){
            ofstream escrituraA("MaestroCuentas.dat" , ios::out | ios::binary);

            temporal.saldo=temporal.saldo+nuevo.monto_transac;

            escrituraA.write((char*) &temporal , sizeof(cliente));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    }

    return;

}

void Transacciones::agregarRetiro() {
    ofstream transfile("transacciones.dat", ios::app | ios::out | ios::binary);

    if(!transfile) {
        cout<<"Error al abrir archivo"<<endl;
    }

    transacciones nuevo;
    cout<<endl<<"*** R E T I R O ***\n";

    cout<<"Ingrese numero de cuenta:"<<endl;
    cin>>nuevo.n_cuenta;
    cout<<"Ingrese tipo de transacciones:"<<endl;
    cin>>nuevo.t_transac;
    cout<<"Ingrese monto de transacciones:"<<endl;
    cin>>nuevo.monto_transac;


    transfile.seekp(0, ios::end );
    transfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(transacciones));
    transfile.close();

    cliente temporal;
    ifstream lecturaA("MaestroCuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);

    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));

    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevo.n_cuenta){
            ofstream escrituraA("MaestroCuentas.dat" , ios::out | ios::binary);

            temporal.saldo=temporal.saldo-nuevo.monto_transac;

            escrituraA.write((char*) &temporal , sizeof(cliente));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    }

    return;
}

void Transacciones::consultarHisto() {
    ifstream empleadoIn("transacciones.dat", ios::in | ios::binary);

    if(!empleadoIn){
        cout<<"Error al intentar abrir el archivo Empleados.dat"<<endl;
        return;
    }

    transacciones temporal;
    cout<<endl<<"*** C O N S U L T A  D E  T R A N S A C C I O N E S ***\n";
    empleadoIn.seekg(0,ios::beg);
    empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(transacciones));
    while(!empleadoIn.eof()){
        cout<<" { # Cuenta:" << temporal.n_cuenta << ", Tipo de Transaccion:" << temporal.t_transac << ", Monto: " << temporal.monto_transac<< "}\n";
        empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(transacciones));
    }
    cout<<endl;

    empleadoIn.close();
}



