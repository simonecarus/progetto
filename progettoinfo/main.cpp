#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct info {
    string codcorso, descrizione, codmat, desc_corso, matricola, cognome, nome;
};

vector<info> vett;
map<string, info> studente_per_matricola;

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
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}

void caricadati(vector<info>& vet, map<string, info>& matri) {
    ifstream fin("corsi_studenti.csv");
    if (!fin) {
        cout << "Errore apertura file\n";
        return;
    }
    string s;
    getline(fin, s); // intestazione

    info i;
    vet.clear();
    matri.clear();

    while (true) {
        getline(fin, i.codcorso, ',');
        if (i.codcorso == "") break;
        getline(fin, i.descrizione, ',');
        getline(fin, i.codmat, ',');
        getline(fin, i.desc_corso, ',');
        getline(fin, i.matricola, ',');
        getline(fin, i.cognome, ',');
        getline(fin, i.nome);
        vet.push_back(i);
        matri[i.matricola] = i;
    }
    fin.close();
}

void cercaMatri(map<string, info>& matri, const string& matricola) {
    bool trovato = false;
    for (auto x : matri) {
        if (x.second.matricola == matricola) {
            info i = x.second;
            cout << i.codcorso << " " << i.descrizione << " " << i.codmat << " "
                 << i.desc_corso << " " << i.matricola << " " << i.cognome << " " << i.nome << "\n\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Matricola non trovata.\n";
}

void cercaCognome(vector<info>& vet, const string& cognome) {
    bool trovato = false;
    for (auto x : vet) {
        if (x.cognome == cognome) {
            cout << x.codcorso << " " << x.descrizione << " " << x.codmat << " "
                 << x.desc_corso << " " << x.matricola << " " << x.cognome << " " << x.nome << "\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Cognome non trovato.\n";
}

void elencoStudenti(vector<info>& vet, const string& corso) {
    bool trovato = false;
    for (auto x : vet) {
        if (x.codcorso == corso) {
            cout << "Studente: " << x.nome << " " << x.cognome << "\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Corso non trovato o nessuno studente iscritto.\n";
}

void stampaEsamiDiCorso(vector<info>& vet, const string& corso) {
    bool trovato = false;
    for (auto x : vet) {
        if (x.codcorso == corso) {
            cout << "Materia: " << x.codmat << " - " << x.desc_corso << "\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Corso non trovato o nessun esame disponibile.\n";
}

void numeroStudentiPerCorso(vector<info>& vet, const string& corso) {
    int conta = 0;
    for (auto x : vet) {
        if (x.codcorso == corso) {
            conta = conta + 1;
        }
    }
    cout << "Corso: " << corso << " -> " << conta << " studenti\n";
}

void numeroMateriePerCorso(vector<info>& vet, const string& corso) {
    map<string, bool> materie;
    for (auto x : vet) {
        if (x.codcorso == corso) {
            materie[x.codmat] = true;
        }
    }
    cout << "Corso: " << corso << " -> " << materie.size() << " materie\n";
}

void cercaMateriePerDescrizione(vector<info>& vet, const string& parola) {
    bool trovato = false;
    for (auto x : vet) {
        if (x.desc_corso.find(parola) != string::npos) {
            cout << x.codmat << " - " << x.desc_corso << "\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Nessuna materia trovata con quella descrizione.\n";
}
#include <fstream>
#include <string>
using namespace std;

void creaFile(string nomefile) {

    ofstream fout(nomefile, ios::app);
    if (!fout) {
        cout << "Errore apertura file\n";
    }

    fout << "file";
    fout.close();

}

void salvaDatiSuFile(vector<info> vetttor){
    //info i;
    ofstream fout("copia.csv",ios::app);
    string labels;
    for(auto i:vetttor)
        fout << i.codcorso << " " << i.descrizione << " " << i.codmat << " "<< i.desc_corso << " " << i.matricola << " " << i.cognome << " " << i.nome <<endl;


}


int main() {
    bool finito = false;
    char ch;
    string matricola, cognome, corso, parola, nomefile;

    while (!finito) {
        stampamenu();
        cout << "Scelta: ";
        cin >> ch;


        switch (ch) {
            case '0':
                caricadati(vett, studente_per_matricola);
                cout << "Dati caricati.\n";
                break;

            case '1':
                cout << "Inserisci matricola: ";
                cin >> matricola;
                cercaMatri(studente_per_matricola, matricola);
                break;

            case '2':
                cout << "Inserisci cognome: ";
                cin >> cognome;
                cercaCognome(vett, cognome);
                break;

            case '3':
                cout << "Inserisci codice corso: ";
                cin >> corso;
                elencoStudenti(vett, corso);
                break;

            case '4':
                cout << "Inserisci codice corso: ";
                cin >> corso;
                stampaEsamiDiCorso(vett, corso);
                break;

            case '5':
                cout << "Inserisci codice corso: ";
                cin.ignore();
                getline(cin, corso);
                numeroStudentiPerCorso(vett, corso);
                break;

            case '6':
                cout << "Inserisci codice corso: ";
                cin.ignore();
                getline(cin, corso);
                numeroMateriePerCorso(vett, corso);
                break;

            case '7':
                cout << "Inserisci parola descrizione materia: ";
                cin.ignore();
                getline(cin, parola);
                cercaMateriePerDescrizione(vett, parola);
                break;

            case '8':
                cout << "Inserisci nome file da creare: ";
                cin >> nomefile;
                creaFile(nomefile);
                break;

            case '9':
                salvaDatiSuFile(vett);
                cout << "Dati salvati.\n";
                break;

            case 'X':
                finito = true;
                break;

            default:
                cout << "Opzione non valida\n";
        }
    }
    return 0;
}
