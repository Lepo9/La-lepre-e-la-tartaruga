#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Progetto Informatica
//Autori: Giacomo Garoffoli, Marco Leporati, Daniele Ragnoli, Matteo Betella
//Revisione 0.3

//se positivo restituisce valore true, se il numero è postivo altrimenti false
bool positivo (int n)
{
    if (n>0)    //controllo se n è positivo
        return true;
    else 
        return false;
}


//la funzione stampa un numero di spazi n (utile nel disegno)
void spazi (int n)
{
    for (int i = 0; i < n; i ++) //numero giri = n
        cout << " ";
}


//la funzione restituisce true se il credito è sufficiente altrimenti false
bool credito_sufficiente (int credito, int puntata)
{
    if (credito >=puntata)
        return true; //Il credito è sufficiente
    else
        return false; //Il credito non è sufficiente
}

//la funzione genera un numero corrispondente al numero di passi che la 
//tartaruga deve fare tenendo conto delle probabilità
int spostamento_tarta ()
{
    int n;  //variabile di appoggio

    n = rand () % 10 + 1;    //genera un numero da 1 a 10

    if (n <= 5)         //  5/10 possibilità sono il 50%
        return 3;       //  arrancata rapida
    else if (n <= 7)    //  2/10 possibilità sono il 20%
        return -6;      //  scivolone
    else                //  (10-5-2)/10 possibilità sono il 30%
        return 1;       //  arrancata lenta
}


//la funzione genera un numero corrispondente al numero di passi che la 
//lepre deve fare tenendo conto delle probabilità
int spostamento_lepre () 
{
    int n;  //variabile di appoggio

    n = rand () % 10 + 1;    //genera un numero da 1 a 10

    if (n <= 2)         //  2/10 possibilità sono il 20%
        return 0;       //  dormita
    else if (n <= 4)    //  (4-2)/10 possibilità sono il 20%
        return 9;       //  salto lungo
    else if (n == 5)     //  1/10 possibilità sono il 10%
        return -12;     //  scivolone lungo
    else if (n <= 8)    //  (8-5)/10 possibilità sono il 30%
        return 1;       //  salto corto
    else                //  (10-8)/10 possibilità sono il 20%
        return -2;      //  scivolone corto
}
    
//la funzione restuisce i gettoni vinti   
int gettoni_vinti (int gettoni_puntati, bool flag_scommessa, bool flag_vincitore) 
  //bool flag_scommessa: su chi scommetto (true=tarta; false=lepre)
  //bool flag_vincitore: chi vince (true=tarta; false=lepre)
{
    if(flag_vincitore == flag_scomessa) //se il vincitore è lo stesso di chi abbiamo puntato
        return gettoni_puntati * 2;     //vinciamo il doppio dei gettoni
    return 0;  //altrimenti non vinciamo niente
}

int main()
{
    srand (time(NULL));
    return 0;
}
