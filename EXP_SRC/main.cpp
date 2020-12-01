#include <iostream>

using namespace std;

//Progetto Informatica
//Autori: Giacomo Garoffoli, Marco Leporati, Daniele Ragnoli, Matteo Betella
//Revisione 0.1

bool credito_sufficiente (int credito, int puntata)
{
    if (puntata >= credito)
        return true; //Il credito è sufficiente
    else
        return false; //Il credito non è sufficiente
}


int main()
{

    return 0;
}
