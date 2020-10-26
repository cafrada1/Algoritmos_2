#include <iostream>

using namespace std;

int main(){

	for (int i = 0; i < 5; i++){

		int numero;

		cout << "Direccion memoria variable " << i+1 << ": " << &numero << endl;
	}

	for (int i = 0; i < 5; i++){

		int *puntero = new int;

		cout << "Direccion memoria puntero " << i+1 << ": " << puntero << endl;

		delete puntero;
	}


	return 0;
}