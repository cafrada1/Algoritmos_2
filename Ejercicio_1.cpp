#include <iostream>

using namespace std;


int numero_global_1;
int numero_global_2;

void mostrar_locales(){

	int numero_local_1;
	int numero_local_2;

	cout << "Direccion local 1: " << &numero_local_1 << endl;
	cout << "Direccion local 2: " << &numero_local_2 << endl;
}

int main(){

	int numero_main_1;
	int numero_main_2;

	int *numero_puntero_1 = new int;
	int *numero_puntero_2 = new int;

	mostrar_locales();

	cout << "Direccion main 1: " << &numero_main_1 << endl;
	cout << "Direccion main 2: " << &numero_main_2 << endl;

	cout << "Direccion global 1: " << &numero_global_1 << endl;
	cout << "Direccion global 2: " << &numero_global_2 << endl;

	cout << "Direccion puntero 1: " << numero_puntero_1 << endl;
	cout << "Direccion puntero 2: " << numero_puntero_2 << endl;


	delete numero_puntero_1;
	delete numero_puntero_2;


	return 0;
}