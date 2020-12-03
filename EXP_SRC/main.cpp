#include <iostream> 
#include <ctime>    
#include <cstdlib>
#include <windows.h>    //libreria per sleep 

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
    if(flag_vincitore == flag_scommessa) //se il vincitore è lo stesso di chi abbiamo puntato
        return gettoni_puntati * 2;     //vinciamo il doppio dei gettoni
    return 0;  //altrimenti non vinciamo niente
}

//la funzione muove la tartaruga di avanzamento_tarta spazi e
//disegna il traguardo i base ai passi totali che la tartaruga deve fare
void disegno_tarta (int avanzamento_tarta, int passi_totali)
{
    int spazi_dopo = passi_totali - avanzamento_tarta - 1;  //trovo a quanti passi dista il traguardo
    spazi (avanzamento_tarta);      //sfalsa la tarta di avanzamento_tarta spazi
    cout << "  _____     ____  ";   //stampa il primo livello della tartaruga
    spazi (spazi_dopo);             //stampa gli spazi che mancano per raggiungere il traguardo
    cout << "x" << endl;            //stampa il carattere del traguardo e va a capo
    spazi (avanzamento_tarta);
    cout << " /      \\  |  o | ";  //secondo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_tarta);
    cout << "|        |/ ___\\| ";  //terzo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_tarta);
    cout << "|_________/       ";   //quarto livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_tarta);
    cout << "|_|_| |_|_|       ";   //quinto livello
    spazi (spazi_dopo);
    cout << "x" << endl;
}

//la funzione muove la lepre di avanzamento_lepre spazi e
//disegna il traguardo i base ai passi totali che la lepre deve fare
void disegno_lepre (int avanzamento_lepre, int passi_totali)
{
    int spazi_dopo = passi_totali - avanzamento_lepre - 1;  //trovo a quanti passi dista il traguardo
    spazi (avanzamento_lepre);      //sfalsa la lepre di avanzamento_lepre spazi
    cout << "        /\\ /|     ";   //stampa il primo livello della lepre
    spazi (spazi_dopo);             //stampa gli spazi che mancano per raggiungere il traguardo
    cout << "x" << endl;            //stampa il carattere del traguardo e va a capo
    spazi (avanzamento_lepre);
    cout << "       |||| |     ";  //secondo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "        \\| \\      ";  //terzo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "    _ _ /  @ @    ";   //quarto livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "  /    \\  ==>X<== ";   //quinto livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "/|      |   /     ";   //sesto livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "\\|     /__| |     ";   //settimo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
    spazi (avanzamento_lepre);
    cout << "  \\_____\\ \\__\\    ";   //ottavo livello
    spazi (spazi_dopo);
    cout << "x" << endl;
}

int main()
{
    srand (time(NULL));

    int credito; //credito totale
    bool flag_giocare = true; //flag per riocare
    int passi_lepre = 0, passi_tarta = 0; //contatori passi
    const int passi_totali = 100; //passi totali
    const int intervallo_fotogrammi = 350; //intervallo dei fotogrammi

    //inserire titolo
    cout << "Ciao!" << endl << "Benvenuto in Enimol Game Turtle Vs Rabbit edition!" << endl;
    //inserire disclamer
    //inserire regole

    cout << endl;

    system ("pause"); //viene richiamata la funzione pause per aspettare che l'utente abbia le regole
    system ("cls"); //viene richiamata la funzione cls per cancellare la shell

    cout << "Inserisci il tuo credito in gettoni: "; //input gettoni
    cin >> credito;
    
    while (credito > 0 && flag_giocare == true) //ciclo per fare più manche
    {
        
        //input su chi si scommette
        //input quanto si scommette
        while (passi_lepre < passi_totali && passi_tarta < passi_totali) //ciclo stampa della corsa
        {         
            cout << "Il tuo credito residuo vale " << credito << " gettoni." << endl << endl;

            passi_lepre += spostamento_lepre(); //aggiornamento del contatore dei passi della lepre
            passi_tarta += spostamento_tarta(); //aggiornamento del contatore dei passi della tarta

            if (passi_lepre < 0)    //nel caso i pssi della lepre vadano sotto 0 vengono riportati a 0
                passi_lepre = 0;
            if (passi_tarta < 0)    //nel caso i pssi della tarta vadano sotto 0 vengono riportati a 0
                passi_tarta = 0;

            if (passi_lepre > passi_totali && passi_tarta > passi_totali) //nel caso entrambi passino il traguardo insieme
            {
                if (passi_lepre > passi_tarta)          //controllo se è arrivata prima la lepre
                {
                    //vince tarta
                }
                else if (passi_lepre == passi_tarta)    //controllo se sono arrivate esattamente insieme
                {
                    //pareggio
                }
                else                                    //la tarta è arrivata prima
                {
                    //vince lepre
                }
            }
            else    //controllo se una delle due è arrivata prima
            {
                if (passi_lepre > passi_totali) //controllo se è arrivata prima la lepre
                {
                    passi_lepre = passi_totali;
                    //vince lepre
                }
                if (passi_tarta > passi_totali) //controllo se è arrivata prima la tarta
                {
                    passi_tarta = passi_totali;
                    //vince tarta
                }
            }

            disegno_lepre (passi_lepre, passi_totali); //viene disegnata la lepre
            disegno_tarta (passi_tarta, passi_totali); //viene disegnata la tarta

            Sleep (intervallo_fotogrammi); //la funzione aspetta intervallo_fotogrammi millisecondi
            
            //parte ririchiesta credito
        }
        
        //controllo chi ha vinto
        //output quanto si ha vinto e a quante partite si ha in totale, vinte e perse
        //vuoi rigiocaare
        
    }


    if (credito == 0) //non si ha più credito sufficiente
    {
        cout << "Mi dispiace hai finito il credito!";
    }
    else  //non si vuole più rigiocare
    {
        cout << "Non vuoi rigiocare? Nessun problema! Ci vediamo alla prossima!";
    }
    



    return 0;
}
