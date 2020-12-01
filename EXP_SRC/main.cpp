#include <iostream>

using namespace std;

bool credito_sufficiente (int puntata)

{
   int credito = 20;
if (puntata >= credito)
    return true;

  else
    return false;

}



int main()
{
  int credito, credito_s;
  cout << "inserisci il credito che vuoi scommetere: " << endl;
       cin >> credito;
  credito_s = credito_sufficiente(credito);
  if (credito_s == false)
     cout << "il credito inserito non è sufficiente per la scommessa..." << endl;
  if (credito_s == true)
     cout << "il credito inserito è sufficiente per la scommessa!" << endl;


return 0;
}
