#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>    //libreria per sleep

using namespace std;

//Progetto Informatica
//Autori: Giacomo Garoffoli, Marco Leporati, Daniele Ragnoli, Matteo Betella

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

int scelta_binaria() //funzione eseguita per input di 0 o 1
{
  int n;
  while(1 != 0) //ciclo infinito che termina solo se l'utente inserisce 0 o 1
  {
  cin >> n;
   if(n == 0) //Controlla se la scelta è 0
      return 0;
   else if(n == 1) //Controlla se la scelta è 1
      return 1;
  cout << "Puoi inserire solo 0 o 1: ";
  }
}

int puntata (int credito) //Restituisce la scommessa dell'utente e controlla se questa sia plausibile
{
    int scommessa;
    //il giocatore fa la puntata
    cout << "Inserisci la scommessa in gettoni:  ";
    cin >> scommessa;
    //viene controllato il credito
    while (credito_sufficiente (credito, scommessa) == false || positivo (scommessa) == false)
    {
        cout << endl;
        cout << "Attenzione! Inserisci una scommessa valida." << endl;
        cout << "Il tuo credito vale " << credito << " gettoni." << endl;
        cout << "Inserisci la scommessa in gettoni:  ";
        cin >> scommessa;
        cout << endl;
    }
    return scommessa;
}

int scommessa_raddoppiata (int scommessa, int contagiri, int credito) //Funzione che chiede all'utente se vuole raddoppiare la scommessa
{
    int scelta;
    if (contagiri % 15 == 0 && credito > 0) //Controlla se il contagiri è divisibile per 15 e controlla se il credito è maggiore di 0
    {   
        cout << "La tua scommessa vale " << scommessa << " gettoni." << endl;
        if (scommessa * 2 > credito) //Controlla se ha abbastanza credito per raddoppiare
        {
            cout << "Non hai abbastanza credito per raddoppiare la scommessa, vuoi scommettere tutto il credito rimasto? Digita 1 se vuoi scommettere tutto, altrimenti digita 0: ";
            scelta = scelta_binaria(); //Funzione che controlla se la scelta è 0 o 1
            if (scelta == 1) //Controlla se l'utente ha scelto 0 o 1
                return credito; //Se è 1 scommette tutto il credito
            else
                return 0; //Ritorna 0 se l'utente non vuole scommettere tutto
        }
        else
        {
            cout << "Vuoi raddoppiare la scommessa? Inserisci 1 se vuoi raddoppiare, altrimenti digita 0: ";
            scelta = scelta_binaria(); //Funzione che controlla se la scelta è 0 o 1
            if (scelta == 1)
                return scommessa; //Se è 1 raddoppia la scommessa
            else
                return 0; //Se è 0 non raddoppia la scommessa
        }
    }
    else
        return 0;
}

void guadagno(int credito_finale, int credito_iniziale) //stampa quanti gettoni si ha vinto dall'inizio o si ha perso
{
    int differenza = credito_finale - credito_iniziale; //calcolo guadagno/perdita
    if (differenza < 0) //viene fatto il modulo
        differenza *= -1; 
    if (credito_finale > credito_iniziale)  //c'è stato un guadagno
        cout << "Hai guadagnato dall'inizio " << differenza << " gettoni!" << endl;
    else if (credito_finale < credito_iniziale) //c'è stata una perdita
        cout << "Hai perso dall'inizio " << differenza << " gettoni!" << endl;
    else  //si è rimasti in pari                                  
        cout << "Il tuo credito dall'inizio è rimasto invariato!" << endl;
}

int main()
{
    srand (time(NULL));

    int credito; //credito totale
    bool flag_giocare = true; //flag per riocare
    int passi_lepre = 0, passi_tarta = 0; //contatori passi
    const int passi_totali = 100; //passi totali
    const int intervallo_fotogrammi = 350; //intervallo dei fotogrammi
    int scelta; //scelta del giocatore su chi punture i gettoni (0 = Tartaruga, 1 = Lepre)
    int scommessa; //Gettoni scommessi
    int contagiri=0; //conta il numero di giri di una giocata
    int temp; //variabile temporanea
    bool flag_meta = false; //la variabile cambia in true quando la tartaruga o la lepre fanno più di 50 passi
    int credito_iniziale; //è il credito che si aveva inserito all'inizio
    int contatore_vittorie = 0, contatore_sconfitte = 0;

    system ("title Enimol Game : Turtle VS Rabbit Edition!");//viene richiamta la funzione title per visualizzare il titolo sul Command Prompt
    cout << "Ciao!" << endl << "Benvenuto in Enimol Game : Turtle VS Rabbit edition!" << endl << endl;
    system ("pause"); //viene richiamata la funzione pause per aspettare che l'utente abbia le regole

    system ("cls"); //viene richiamata la funzione cls per cancellare la shell
    system ("color 4");//viene riciamata la funzione color per modificare il color a rosso //color 7 per verde
    cout << "Il gioco è pensato per un pubblico adulto e non offre gioco d’azzardo con denaro reale o possibilità di vincere denaro reale o premi." << endl;
    cout << "Il gioco è volto esclusivamente all’intrattenimento e non esercitano alcuna influenza sull’eventuale futuro utilizzo di giochi d’azzardo con denaro reale." << endl;
    system ("pause"); //viene richiamata la funzione pause per aspettare che l'utente abbia letto le regole

    //Disclaimer
    system ("color 7"); //viene richiamata la funzione color per modificare il colore a bianco
    system ("cls");  //viene richiamata la funzione cls per cancellare la shell

    //Tutte le regole del gioco divise in Nome:Possibilità:Passi
    cout << "Puoi scommettere su uno delle due concorrenti e puoi raddoppiare durante la gara ogni 15 turni prima che una delle due passi mezzo campo." << endl;
    cout << "La tartaruga può fare le seguenti mosse: " << endl;
    cout << "Arrancata Rapida   : 50% di possibilità : 3 passi avanti" << endl;
    cout << "Scivolone          : 20% di possibilità : 6 passi indietro" << endl;
    cout << "Arrancata Lenta    : 30% di possibilità : 1 passo avanti" << endl;
    cout << endl;
    cout << "La lepre può fare le seguenti mosse: " << endl;
    cout << "Dormita            : 20% di possibilità : Nessun passo" << endl;
    cout << "Salto lungo        : 20% di possibilità : 9 passi avanti" << endl;
    cout << "Scivolone lungo    : 10% di possibilità : 12 passi indietro" << endl;
    cout << "Salto corto        : 30% di possibilità : 1 passo avanti" << endl;
    cout << "Scivolone corto    : 20% di possibilità : 2 passi avanti" << endl;
    cout << endl;

    system("pause"); //viene richiamata la funzione pause per aspettare che l'utente abbia letto le regole
    system("cls"); //viene richiamata la funzione cls per cancellare la shell


    cout << "Inserisci il tuo credito in gettoni: "; //input gettoni
    cin >> credito;
    while(credito<=0)   //controllo input credito
    {
        cout << "Attenzione! Inserisci un credito valido (positivo): ";
        cin >> credito;
    }
    credito_iniziale = credito;
    system("cls"); //viene richiamata la funzione cls per cancellare la shell

    while (credito > 0 && flag_giocare == true) //ciclo per fare più manche
    {
        cout << "Il tuo credito vale " << credito << " gettoni." << endl << endl;
        //il giocatore sceglie su chi puntaree
        cout << "Digita 0 se vuoi scommettere sula tartaruga oppure digita 1 se vuoi scommettere sulla lepre." << endl;
        cout << "La tua scelta e': " ;
        scelta = scelta_binaria(); //usiamo questa funzione di controllo

        if (scelta == 0)
            cout <<"Quanto vuoi scommettere sulla tartaruga?" << endl;
        else
            cout << "Quanto vuoi scommettere sulla lepre?" << endl;

        scommessa = puntata (credito); //la scommessa vine inserita tramite la funzione puntata
        credito -= scommessa;

        cout << "In bocca al lupo, buon divertimento!" << endl;
        system ("pause"); //viene richiamata la funzione pause per aspettare che l'utente sia pronto a giocare
        system ("cls"); //viene richiamata la funzione cls per cancellare la shell

        contagiri = 0;
        flag_meta = false;
        passi_lepre = 0;
        passi_tarta = 0;
        
        while (passi_lepre < passi_totali && passi_tarta < passi_totali) //ciclo stampa della corsa
        {
            system("cls");
            contagiri++;
            cout << "Il tuo credito vale " << credito << " gettoni." << endl;
            cout << "Nel caso vincesse la ";
            if (scelta == 0)
                cout << "tartaruga";
            else
                cout << "lepre";
            cout << " vinceresti " << scommessa*2 << " gettoni." << endl << endl;

            passi_lepre += spostamento_lepre(); //aggiornamento del contatore dei passi della lepre
            passi_tarta += spostamento_tarta(); //aggiornamento del contatore dei passi della tarta

            if (passi_lepre < 0)    //nel caso i pssi della lepre vadano sotto 0 vengono riportati a 0
                passi_lepre = 0;
            if (passi_tarta < 0)    //nel caso i pssi della tarta vadano sotto 0 vengono riportati a 0
                passi_tarta = 0;

            if (passi_lepre >= passi_totali && passi_tarta >= passi_totali) //nel caso entrambi passino il traguardo insieme
            {
                if (passi_lepre > passi_tarta)          //controllo se è arrivata prima la lepre
                {
                    passi_lepre = passi_totali;         //la lepre viene portata al traguardo
                    passi_tarta = passi_totali - 1;     //la tarta viene portata un passo indietro al tragurado      
                }
                else if (passi_lepre == passi_tarta)    //controllo se sono arrivate esattamente insieme
                {                                       //pareggio erfetto: entrambe tornano indietro di 5 passi dal traguardo
                    passi_lepre = passi_totali - 5;     
                    passi_tarta = passi_totali - 5;
                }
                else                                    //la tarta è arrivata prima
                {
                    passi_tarta = passi_totali;         //la tarta viene portata al traguardo
                    passi_lepre = passi_totali - 1;     //la lepre viene portata un passo indietro al tragurado 
                    
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

            cout << endl;
            
            if (passi_tarta >= passi_totali/2 || passi_lepre >= passi_totali/2) //controlla se qualcuno è arrivato a metà
                flag_meta = true; //aggiorna la variabile
            
            if (flag_meta != true) //si può ripuntare solo se nessono è mai andato oltre la metà
            {
                temp = scommessa_raddoppiata (scommessa, contagiri, credito); //temp assume il valore della riscommessa
                scommessa += temp; //viene aggiornata la scommessa
                credito -= temp; //viene aggiornato il credito
            }
            
            Sleep (intervallo_fotogrammi); //la funzione aspetta intervallo_fotogrammi millisecondi
        }

        
        //controllo chi ha vinto
        if (passi_tarta > passi_lepre)
        {
            if (scelta == 0)
            {
                cout << "Congratulazioni! Scommettendo sulla tartaruga hai raddoppiato la tua scommessa vincendo " << scommessa*2 << " gettoni!" << endl; 
                credito = credito + scommessa*2; //aggiornamento credito
                contatore_vittorie++;
            }
            else
            {
                cout << "Mi dispiace, la lepre non ha vinto..." << endl;
                contatore_sconfitte++;
            }
        }
        else
        {
            if (scelta == 1)
            {
                cout << "Congratulazioni! Scommettendo sulla lepre hai raddoppiato la tua scommessa vincendo " << scommessa*2 << " gettoni!" << endl; 
                credito = credito + scommessa*2; //aggiornamento credito
                contatore_vittorie++;
            }
            else
            {
                cout << "Mi dispiace, la tartaruga non ha vinto..." << endl;
                contatore_sconfitte++;
            }
        }
        
        //viene stampato quanto si ha guadagnato o meno dall'inizio
        guadagno (credito, credito_iniziale);
        
        //output quante partite si ha in totale, vinte e perse
        cout << "Hai vinto " << contatore_vittorie << " partite e hai perso " << contatore_sconfitte << " partite." << endl << endl;
        
        if (credito != 0)
        {
            cout <<"Il tuo credito vale " << credito << " gettoni." << endl; //vengono ribaditi i gettoni residui
            cout << "Se vuoi ritentare la Fortua premi 1, se non vuoi più giocare premi 0: " ; //il giocatore sceglie
            flag_giocare = scelta_binaria ();
            if (flag_giocare == 1)
                flag_giocare = true;
            else if (flag_giocare == 0)
                flag_giocare = false;
        }
        system("cls"); //viene richiamata la funzione cls per cancellare la shell

    }

    if (credito == 0) //non si ha più credito sufficiente
    {
        cout << "Mi dispiace hai finito il credito!";
    }
    else  //non si vuole più rigiocare
    {
        cout << "Non vuoi rigiocare? Nessun problema! Ci vediamo alla prossima!";
    }
    cout << endl;
    
    system("pause");
    
    return 0;
}
