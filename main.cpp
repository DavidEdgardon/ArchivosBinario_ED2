#include <iostream>
#include <fstream>
#include "Cuentas.h"
#include "Transacciones.h"

using namespace std;
int opc;

int main() {
    do {
        cout << " B A N C O   N A C I O N A L " << endl;
        cout << "1. Ingresar Cuenta" << endl;
        cout << "2. Depositos" << endl;
        cout << "3. Retiros" << endl;
        cout << "4. Consultar Historial" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion:" << endl;

        cin >> opc;
        switch (opc) {
            case 1:
                cuentas::agregarCliente();
                break;
            case 2:
                Transacciones::agregarDeposito();
                break;
            case 3:
                Transacciones::agregarRetiro();
                break;
            case 4:
                cuentas::consultarCliente();
                Transacciones::consultarHisto();
                break;
            default:
                break;
        }
    }while(opc!=0);
    return 0;
}