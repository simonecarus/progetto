#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
struct info{
    string codcorso,descrizione,codmat,matricola,cognome,nome;
};
void stampamenu() {
    cout << "*************************************************\n";
    cout << "* 0 - Carica dati da file                       *\n";
    cout << "* 1 - Cerca corsi studente (matricola)          *\n";
    cout << "* 2 - Cerca corsi studente (cognome)            *\n";
    cout << "* 3 - Elenco studenti iscritti ad un corso      *\n";
    cout << "* 4 - Stampa dati esami di un corso             *\n";
    cout << "* 5 - Numero studenti per corso                 *\n";
    cout << "* 6 - Numero materie per corso                  *\n";
    cout << "* 7 - Cerca materie per descrizione             *\n";
    cout << "* 8 - Inserisci nuovo file                      *\n";
    cout << "* 9 - Salva i dati sul file                     *\n";
    cout << "                                                *\n";
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}
void caricadati(vector<info> &vet){
    ifstream fin("corsi_studenti.csv");
    string s;
    getline(fin,s);
    info i;
    while(!fin.eof()){

            getline(fin,i.codcorso,';');

    if(i.codcorso=="")break;

    getline(fin,i.descrizione,';');
    getline(fin,i.codmat,';');
    getline(fin,i.matricola,';');
    getline(fin,i.cognome,';');
    getline(fin,i.nome);
    vet.push_back(i);
    cout<<i.codcorso<<" "<<i.descrizione<<" "<<i.codmat<<" "<<i.matricola<<" "<<i.cognome<<" "<<i.nome<<endl;
    }
}
int main(){


    vector<info> vet;
    bool finito=false;
    char ch;

    while (!finito) {
        stampamenu();
        cin>>ch;

        switch (ch) {

            case '0':
                caricadati(vet);

                break;

            case '1':

                break;

            case '2':

                break;

            case '3':

                break;

            case '4':

                break;

            case '5':

                break;

            case '6':

                break;

            case '7':

                break;

            case '8':

                break;

            case '9':

                break;

            case 'X':
                finito = true;
                break;

            default:
                cout << "Opzione non valida\n";

        }
    }
}
