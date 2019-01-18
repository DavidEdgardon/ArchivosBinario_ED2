//
// Created by ASUS on 1/15/2019.
//

#include "Cuentas.h"
#include <fstream>
#include <iostream>
using namespace std;



void cuentas::agregarCliente() {
    ofstream binaryfile("MaestroCuentas.dat", ios::app | ios::out | ios::binary);

    if(!binaryfile) {
    cout<<"Error al abrir archivo"<<endl;
    }

    cliente nuevo;
    cout<<endl<<"*** I N G R E S O  D E  C U E N T A S  ***\n";
    cout<<"Ingrese codigo:"<<endl;
    cin>>nuevo.n_cuenta;
    cout<<"Ingrese nombre:"<<endl;
    cin>>nuevo.nombre;

    nuevo.saldo = 0;

    binaryfile.seekp(0, ios::end );
    binaryfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(cliente));
    binaryfile.close();
}

void cuentas::consultarCliente() {
        ifstream empleadoIn("MaestroCuentas.dat", ios::in | ios::binary);
        if(!empleadoIn){
            cout<<"Error al intentar abrir el archivo Empleados.dat"<<endl;
            return;
        }

        cliente temporal;
        cout<<endl<<"*** C O N S U L T A R  D E  C L I E N T E S ***\n";
        empleadoIn.seekg(0,ios::beg);
        empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
        while(!empleadoIn.eof()){
            cout<<"Cliente { codigo:" << temporal.n_cuenta << ", Nombre:" << temporal.nombre << ", Saldo: " << temporal.saldo<< "}\n";
            empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
        }
        empleadoIn.close();
    }
