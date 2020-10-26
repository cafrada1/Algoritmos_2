#include <iostream>

using namespace std;

const int CANT_FILAS = 3;
const int CANT_COLUMNAS = 5;

int main(){

    int **matriz;

    matriz = new int* [CANT_FILAS];

    for (int i = 0; i < CANT_FILAS; i++){

        matriz[i] = new int[CANT_COLUMNAS];  //84 bytes
    }

    for (int i = 0; i < CANT_FILAS; i++){

        //delete [] matriz[i]; //24 bytes

        if (i < CANT_FILAS-1){
            delete []  matriz[i]; //44 bytes
        }
    }
   //delete [] matriz; //60 bytes

    return 0;
}

