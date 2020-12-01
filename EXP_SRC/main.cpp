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

int spostamento_tarta () 
{
    int n;  //variabile di appoggio
    
    n = rand () % 10 + 1    //genera un numero da 1 a 10
    
    if (n <= 5)         //5/10 possibilità sono il 50%
        return 3        //arrancata rapida
    else if (n <= 7)    //2/10 possibilità sono il 20%
        return -6       //scivolone
    else                //(10-5-2)/10 possibilità sono il 30%
        return 1        //arrancata lenta
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
