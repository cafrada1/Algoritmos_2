#include <iostream>

using namespace std;

const int LARGO = 10;

int main(){

    int *vector = new int[LARGO];

    delete [] vector;
    //delete vector;
    //delete vec[0];
    //for (int i = 0; i < LARGO; I++) delete vec[i];

    return 0;
}
