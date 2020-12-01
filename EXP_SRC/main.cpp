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


//Funzione per stampare i numeri di spazi (utile nel disegno)
int spazi (int n)
{
    for (i = 0; i < n; i ++)
  {
     cout << " ";
  }
return 0;
}

int gettoni_vinti(int gettoni_puntati, int flag_scommessa, int flag_vincitore)
{
    //FLAG_SCOMMESSA (1 LEPRE - 0 TARTARUGA)
    //FLAG_VINCITORE (1 HA VINTO - 0 HA PERSO)
    //GETTONI_PUNTATI (NUMERO GETTONI)
    //WIP IN PROGRESS 01/12/2020 10:51 <-- GAROFFOLI
    
}

int main()
{

    return 0;
}
