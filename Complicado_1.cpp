#include "Complicado_1.h"

const int RANGO = 101;
const int INICIO = 0;

const char INICIAL = '0';
const char MOSTRAR_VECTOR = 'a';
const char SUMATORIA = 'b';
const char MOSTRAR_MAXIMO = 'c';
const char MOSTRAR_MINIMO = 'd';
const char PROMEDIO = 'e';
const char BUSCAR = 'f';
const char SALIR = 'g';

/*
 * PRE: largo mayor a 0
 * POST: Devuelve el maximo elemento del vector
 * FUNCIONAMIENTO: Recorre el vector y guarda el meximo elemento del mismo.
 */
int maximo(int *vector, int largo){

    int numero_maximo = vector[0];

    for (int i = 1; i < largo; i++) {

        if (vector[i] > numero_maximo) {
            numero_maximo = vector[i];
        }
    }
    return numero_maximo;
}

/*
 * PRE: largo mayor a 0
 * POST: Devuelve el minimo elemento del vector
 * FUNCIONAMIENTO: Recorre el vector y guarda el minimo elemento del mismo.
 */
int minimo(int *vector, int largo){

    int numero_minimo = vector[0];

    for (int i = 1; i < largo; i++) {

        if (vector[i] < numero_minimo) {
            numero_minimo = vector[i];
        }
    }
    return numero_minimo;
}

/*
 * PRE: largo mayor a 0
 * POST: Devuelve un entero mayor o igual a 0.
 * FUNCIONAMIENTO: Recorre el vector cuenta las veces que se repite numero en el vector.
 */
int repeticiones(int *vector, int largo, int numero){

    int repeticiones = 0;

    for (int i = 0; i < largo; i++){
        if (vector[i] == numero){
            repeticiones++;
        }
    }
    return repeticiones;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra el valor maximo del vector y las veces que se repite en el mismo.
 */
void valor_maximo(int *vector, int largo){

    int max = maximo(vector,largo);

    int repetido = repeticiones(vector,largo,max);

    cout << "\n----- MAXIMO VALOR -----" << endl;
    cout << "\nEl maximo es: " << max << endl;
    cout << "Se repite: " << repetido << endl;
    cout << "\n_______________________" << endl;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra el valor minimo del vector y las veces que se repite en el mismo.
 */
void valor_minimo(int *vector, int largo){

    int min = minimo(vector,largo);

    int repetido = repeticiones(vector,largo,min);

    cout << "\n----- MINIMO VALOR -----" << endl;
    cout << "\nEl minimo es: " << min << endl;
    cout << "Se repite: " << repetido << endl;
    cout << "\n_______________________" << endl;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Calcula la suma de los elementos del vector.
 */
int sumatoria(int *vector, int largo){
    int suma = 0;

    for (int i = 0; i < largo; i++){
        suma += vector[i];
    }

    return suma;
}

/*
 * PRE: largo mayor a 0
 * POST: True si buscado se encuentra en vector
 * FUNCIONAMIENTO: Recorre el vector hasta encontrar la primer coincidencia o llegar
 *  al final del vector.
 */
bool encuentra_valor(int *vector, int largo, int buscado){
    bool encontrado = false;

    int i = 0;
    while ((!encontrado) && (i<largo)){

        if (vector[i] == buscado){
            encontrado = true;
        }
        i++;
    }

    return encontrado;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Pide un valor a buscar en el vector y muestra si se encuentra o no.
 */
void buscar_valor(int *vector, int largo){

    int buscado;

    cout << "\n----- BUSCAR UN VALOR -----" << endl;
    cout << "\nIngrese el numero que desea buscar: ";
    cin >> buscado;

    bool encontrado = encuentra_valor(vector, largo, buscado);

    if (encontrado){
        cout << "\nEl valor se encuentra en el vector\n" << endl;
    }
    else{
        cout << "\nEl valor no se encuentra en el vector\n" << endl;
    }
    cout << "---------------------------" << endl;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra la suma de los elementos del vector.
 */
void mostrar_suma(int *vector, int largo){

    int suma = sumatoria(vector, largo);
    cout << "\n----- SUMA DEL VECTOR -----" << endl;
    cout << "\nLa sumatoria es: " << suma << endl;
    cout << "\n---------------------------" << endl;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra el promedio de los elementos del vector.
 */
void mostrar_promedio(int *vector, int largo){
    int suma = sumatoria(vector, largo);

    cout << "\n------ PROMEDIO DEL VECTOR -----" << endl;
    cout << "\nEl promedio es: " << (float) suma/largo << endl;
    cout << "\n--------------------------------" << endl;
}

/*
 * PRE: largo mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra todos los elementos que componen al vector.
 */
void mostrar_vector(int *vector, int largo) {

    cout << "\n----- Numeros del vector -----\n" << endl;

    for (int i = 0; i < largo; i++) {

        cout << "\t Numero " << i + 1 << ": " << vector[i] << endl;
    }

    cout << "\n--------------------------------"<<endl;
}

/*
 * PRE: -
 * POST: -
 * FUNCIONAMIENTO: Muestra el menu con las opciones.
 */
void mostar_menu(){
    cout << "\na) Mostrar el vector" << endl;
    cout << "b) Calcular la sumatoria del vector"<< endl;
    cout << "c) Indicar el valor maximo y cuantas veces se repite" << endl;
    cout << "d) Indicar el valor minimo y cuantas veces se repite"<< endl;
    cout << "e) Indicar el promedio de todos los valores" << endl;
    cout << "f) Indicar si un valor se encuentra en el vector o no"<< endl;
    cout << "g) Salir\n"<< endl;
}

/*
 * PRE: -
 * POST: -
 * FUNCIONAMIENTO: Pide al usuario el ingreso de un numero para el largo. Debe ser mayor a 0.
 */
void pedir_largo(int &largo){

    cout << "Ingrese el largo del vector: ";
    cin >> largo;

    while (largo <= 0){
        cout << "Ingrese un numero mayor a 0" << endl;
        cout << "Ingrese el largo del vector: ";
        cin >> largo;
    }
}

/*
 * PRE: largo mayor a 0.
 * POST: -
 * FUNCIONAMIENTO: Determina la opcion elegida y las acciones a realizar.
 */
void opcion_elegida(int *vector, int largo, char opcion){

    if (opcion == MOSTRAR_VECTOR){
        mostrar_vector(vector, largo);
    }
    else if (opcion == SUMATORIA){
        mostrar_suma(vector, largo);
    }
    else if (opcion == MOSTRAR_MAXIMO){
        valor_maximo(vector, largo);
    }
    else if (opcion == MOSTRAR_MINIMO){
        valor_minimo(vector, largo);
    }
    else if (opcion == PROMEDIO){
        mostrar_promedio(vector, largo);
    }
    else if (opcion == BUSCAR){
        buscar_valor(vector, largo);
    }
    else if (opcion != SALIR){
        cout << "Ingrese una opcion valida." << enld;
    }
}

int main() {

    srand(time(0));

    system("clear");

    int largo;

    pedir_largo(largo);

    int *vector = new int[largo];

    cargar_vector(vector,largo, RANGO, INICIO);

    char opcion = INICIAL;

    while (opcion != SALIR){

        mostar_menu();

        pedir_opcion(opcion);

        opcion_elegida(vector, largo, opcion);
    }
    delete[] vector;

    system("clear");

    return 0;
}