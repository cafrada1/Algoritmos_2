#ifndef COMPLICADO_1_H
#define COMPLICADO_1_H
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * PRE: rango mayor a 0. largo mayor a 0.
 * POST: -
 * FUNCIONAMIENTO: Carga los elementos del vector con valores random entre inicio y (random-inicio).
 */
void cargar_vector(int *vector,int largo,int rango, int inicio) {

    int numero;

    for (int i = 0; i < largo; i++) {

        numero = rand() % rango + inicio ;

        vector[i] = numero;
    }
}

/*
 * PRE: -
 * POST: -
 * FUNCIONAMIENTO: Pide al usuario el ingreso de una opcion.
 */
void pedir_opcion(char &opcion){
    cout << "Ingrese una opcion: ";
    cin >> opcion;
}

#endif //TP1_COMPLICADO_1_H
