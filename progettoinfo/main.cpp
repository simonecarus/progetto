#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include<vector>
#include<map>
using namespace std;

struct info{
string codcorso, descrizione, codmat, desc_corso, matricola, cognome, nome;

};

/*struct studente{
    string matricola_studente, cognome_studente, nome_studente;
};
struct materia{
    string codice_materia, descrizione_materia,
};
struct corso{
    string codice_corso, descrizione_corso
};
*/
vector<info> vett;
map<string,info>studente_per_matricola;
vector<info> elenco;


void stampamenu(){
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
void caricadati(vector<info>& vet,map<string,info>&matri){
    ifstream fin("corsi_studenti.csv");
    string s;
    getline(fin,s);
    info i;
    while(!fin.eof()){

    getline(fin,i.codcorso,',');

    if(i.codcorso=="") break;

    getline(fin,i.descrizione,',');
    getline(fin,i.codmat,',');
    getline(fin,i.desc_corso,',');
    getline(fin,i.matricola,',');
    getline(fin,i.cognome,',');
    getline(fin,i.nome);
    vet.push_back(i);
    matri[i.matricola] = i;

    cout<<i.codcorso<<" "<<i.descrizione<<" "<<i.codmat<<" "<<i.desc_corso<<" "<<i.matricola<<" "<<i.cognome<<" "<<i.nome<<endl;
    }
    fin.close();
}
void cercaMatri(map<string,info>matri){
    string m2;
    cin>>m2;
    for(auto& x : matri) {
        info i=x.second;
        if(m2==i.matricola){
            cout << x.first<<" = ";
            cout<<i.codcorso<<" "<<i.descrizione<<" "<<i.codmat<<" "<<i.desc_corso<<" "<<i.matricola<<" "<<i.cognome<<" "<<i.nome<<endl;
            cout << endl;
        }
    }
}

void elencoStudenti(vector<info> elen, string corso){
    bool trovato = false;
    for (auto x : elen){
        info i;
        if (i.codcorso == corso){
            cout << "Studente: " << x.nome << " " << x.cognome << endl;
            trovato = true;
        }
    }
}
int main(){

    string corso;
    bool finito=false;
    char ch;

    while (!finito) {
        stampamenu();
        cin>>ch;

        switch (ch) {

            case '0':
                caricadati(vett, studente_per_matricola);

                break;

            case '1':
                cercaMatri(studente_per_matricola);
                break;

            case '2':

                break;

            case '3':
                cout << "Inserisci corso di cui si vuole visualizzare l'elenco di studenti: " << endl;
                elencoStudenti(vett, corso);
                getline(cin, corso);
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
