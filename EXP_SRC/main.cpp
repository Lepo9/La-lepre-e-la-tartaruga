#include <iostream>

using namespace std;

//Progetto Informatica
//Autori: Giacomo Garoffoli, Marco Leporati, Daniele Ragnoli, Matteo Betella
//Revisione 0.1

//Funzione per controllare se il credito è sufficente per la puntata
bool credito_sufficiente (int credito, int puntata)
{
    if (puntata >= credito)
        return true; //Il credito è sufficiente
    else
        return false; //Il credito non è sufficiente
}

//Controlla se il numero è postivo
bool positivo (int n)
{
    if (n>=0)
        return true;
    else 
        return false;
}


int main()
{

    return 0;
}
