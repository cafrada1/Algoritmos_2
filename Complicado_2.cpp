#include <math.h>
#include "Complicado_1.h"

const int RANGO = 11;
const int INICIO = -5;

const int TERMINO_LINEAL = 1;
const int TERMINO_INDEPENDIENTE = 0;

const char INICIAL = '0';
const char MOSTRAR_POLINOMIOS = 'a';
const char ESPECIFICAR_POLINOMIO = 'b';
const char SUMA_POLINOMIOS = 'c';
const char PRODUCTO_POLINOMIOS = 'd';
const char SALIR = 'e';


/*
 * PRE:
 * POST: -
 * FUNCIONAMIENTO: Muestra el coeficiente del polinomio. Si es el primer
 *  termino a mostrar y es positivo no
 *  muesta el signo mas (mostrar_mas == false).
 */
void mostrar_coeficiente(int coeficiente, bool mostrar_mas){
    if (coeficiente > 0 && mostrar_mas){
        cout << "+"  << coeficiente;
    }
    else if (coeficiente < 0){
        cout << coeficiente;
    }
}

/*
 * PRE: i mayor a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra la x y el exponente del termino si este es mayor a 1
 *  Si es igual a 1 muestra solo la x.
 *  Si es menor o igual a 0 no muestra nada.
 */
void mostrar_exponente(int i){
    if (i > TERMINO_LINEAL){
        cout << "x^" << i;
    }
    else if (i == TERMINO_LINEAL){
        cout << "x";
    }
}

/*
 * PRE: termino mayor o igual 0
 * POST: Si muestra el primer termino mostrar_mas pasa a true
 * FUNCIONAMIENTO: Muestra el termino del polinomio y si el coeficiente es positivo
 *  y mostrar_mas es true muestra el signo mas. Sino muestra el termino y cambia
 *  mostrar_mas a true
 */
void mostrar_termino(int *vector, int termino, bool &mostrar_mas){

    if (termino != TERMINO_INDEPENDIENTE) {

        mostrar_coeficiente(vector[termino],mostrar_mas);
        mostrar_exponente(termino);
        mostrar_mas = true;
    }
    else {
        cout << vector[termino];
        mostrar_mas = true;
    }
}

/*
 * PRE: largo mayor o igual a 0
 * POST: -
 * FUNCIONAMIENTO: Muestra los elementos del polinomio en su formato correspondiente.
 */
void mostrar_polinomio(int *vector, int largo){
    bool mostrar_mas = false;

    for (int i = 0; i < largo; i++){
        if (vector[i] != 0) {
            mostrar_termino(vector,i,mostrar_mas);
        }
    }
    cout << endl;
}

/*
 * PRE: largo mayor a 0.
 * POST: -
 * FUNCIONAMIENTO: Recorre el vector acumulando el valor de cada termino. Finalmente lo muestra.
 */

void mostrar_especificacion(int *vector, int largo,int valor){
    int suma = 0;

    for (int i = 0; i < largo; i++){
        suma += vector[i] * pow(valor,i);
    }
    cout << "El resultado es: " << suma << endl;
}

/*
 * PRE: -
 * POST: -
 * FUNCIONAMIENTO: Determina el mayor de dos numeros
 */
int mayor_numero(int num_1, int num_2){
    int mayor_num;

    if (num_1 > num_2){
        mayor_num = num_1;
    }
    else{
        mayor_num = num_2;
    }

    return mayor_num;
}
/*
 * PRE: largo_1 y largo_2 mayores a 0
 * POST: -
 * FUNCIONAMIENTO: Suma dos polinomios y muestra el resultado.
 */
void mostrar_suma(int *vector_1,int  largo_1, int *vector_2, int largo_2){

    int largo_suma = mayor_numero(largo_1,largo_2);

    int *vector_suma = new int[largo_suma];

    for (int i = 0; i < largo_suma; i++){
        if ((i < largo_1)  && (i < largo_2)){
            vector_suma[i] = vector_1[i] + vector_2[i];
        }
        else if (i < largo_1){
            vector_suma[i] = vector_1[i];
        }
        else{
            vector_suma[i] = vector_2[i];
        }
    }
    cout << "\nEl la suma de polinomios es: ";

    mostrar_polinomio(vector_suma,largo_suma);

    delete [] vector_suma;
}

/*
 * PRE: largo_1 y largo_2 mayores a 0
 * POST: -
 * FUNCIONAMIENTO: Multiplica dos polinomios y muestra el resultado.
 */
void mostrar_producto(int *vector_1, int largo_1, int *vector_2, int largo_2){

    int largo_producto = largo_1 + largo_2;

    int *vector_producto = new int[largo_producto];

    for (int i = 0; i < largo_producto; i++){
        vector_producto[i] = 0;
    }
    for (int i = 0; i < largo_1; i++){
        for (int j = 0; j < largo_2; j++){
            vector_producto[i+j] += vector_1[i] * vector_2[j];
        }

    }
    cout << "\nEl producto de los polinomios es: ";
    mostrar_polinomio(vector_producto, largo_producto);
    delete [] vector_producto;
}

/*
 * PRE: largo_1 y largo_2 mayores a 0
 * POST: -
 * FUNCIONAMIENTO: Determina la opcion elegida y realiza la accion correspondiente.
 */
void opcion_elegida(int *vector_1, int largo_1, int *vector_2, int largo_2, char opcion){

    if (opcion == MOSTRAR_POLINOMIOS){
        cout << "\nPolinomio 1: ";
        mostrar_polinomio(vector_1,largo_1);
        cout << "\nPolinomio 2: ";
        mostrar_polinomio(vector_2,largo_2);
    }
    else if (opcion == ESPECIFICAR_POLINOMIO){

        int valor;
        cout << "\nIngrese un valor para la especificacion: ";
        cin >> valor;

        cout << "\nPrimer polinomio evaluado en: " << valor << endl;
        mostrar_especificacion(vector_1,largo_1,valor);
        cout << "\nSegundo polinomio evaluado en: " << valor << endl;
        mostrar_especificacion(vector_2,largo_2,valor);
    }
    else if (opcion == SUMA_POLINOMIOS){
        mostrar_suma(vector_1,largo_1,vector_2,largo_2);
    }
    else if (opcion == PRODUCTO_POLINOMIOS){
        mostrar_producto(vector_1,largo_1,vector_2,largo_2);
    }
    else if (opcion != SALIR){
        cout << "Ingrese una opcion valida" << endl;
    }
}

/*
 * PRE: -
 * POST: -
 * FUNCIONAMIENTO: Muestra las opciones del menu.
 */
void menu(){
    cout << "\n\nMenu" <<endl;
    cout << "a) Mostrar los polinomios" << endl;
    cout << "b) Calcular la especificacion para esos polinomios para cierto valor de x" << endl;
    cout << "c) Calcular y mostrar la suma de ambos polinomios" << endl;
    cout << "d) Calcular y mostrar el producto de ambos polinomios" << endl;
    cout << "e) Salir\n\n" << endl;
}

/*
 * PRE: .
 * POST: largo mayor a 0.
 * FUNCIONAMIENTO: Pide el ingreso del grado del polinomio hasta que este sea mayor a 0.
 */
void pedir_grado(int &largo){
    int ingreso;
    cout << "Ingrese el grado del polinomino: ";
    cin >> ingreso;
    while (ingreso <= 0){
        cout << "Se debe ingresar un numero mayor a 0.";
        cout << "Ingrese la dimension del primer polinomino: ";
        cin >> ingreso;
    }
    largo = ingreso + 1;
}

int main(){

    system("clear");

    srand(time(0));

    int largo_1;
    int largo_2;

    cout << "Primer polinomio " << endl;
    pedir_grado(largo_1);
    cout << "\nSegundo polinomio " << endl;
    pedir_grado(largo_2);

    int *vector_1 = new int[largo_1];
    int *vector_2 = new int[largo_2];

    cargar_vector(vector_1,largo_1,RANGO,INICIO);
    cargar_vector(vector_2,largo_2,RANGO,INICIO);

    char opcion = INICIO;
    while (opcion != SALIR){
        menu();
        pedir_opcion(opcion);
        opcion_elegida(vector_1, largo_1, vector_2, largo_2, opcion);
    }

    delete [] vector_1;
    delete [] vector_2;

    system("clear");
    return 0;
}