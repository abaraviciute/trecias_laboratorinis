#include "Mylib.h"
#include "Stud.h"

int main() {

    srand(static_cast<unsigned>(std::time(0)));

    vector<Studentas> Vec1;
    Studentas Temporary;
    int n = 0; //studentu skaicius
    string pasirinkimas;
    bool generavimas;


    cout << "Pasirinkite duomenu ivedimo buda:\n";
    cout << "\"1\" Rankiniu budu\n";
    cout << "\"2\" Skaityti is failo\n";
    int duomenuIvedimoBudas;
    cin >> duomenuIvedimoBudas;

    if (duomenuIvedimoBudas == 1) {

        while (true) {
            cout << "Ar norite skaiciuoti galutini pazymi pagal \"Vid\" (vidurki) ar \"Med\" (mediana)?: ";
            cin >> pasirinkimas;

            if (pasirinkimas == "Vid" || pasirinkimas == "Med") {
                break;
            }
            else {
                cout << "Neteisingas pasirinkimas. Iveskite \"Vid\" arba \"Med\".\n";
            }
        }

        while (true) {
            cout << "Iveskite studentu skaiciu: ";
            cin >> n;

            if (cin.fail() || n <= 0) {
                cout << "Iveskite teigiama skaiciu!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << "Ar norite ivesti pazymius \"R\" (rankiniu) budu, ar juos sugeneruoti \"A\" (atsitiktinai)?: ";
            string pasirinkimasGeneravimo;
            cin >> pasirinkimasGeneravimo;

            generavimas = (pasirinkimasGeneravimo == "A");

            cout << "Iveskite studento duomenis: " << endl;
            ivestis(Temporary, generavimas);

            Temporary.galutinisPazymys = rezultatai(Temporary, pasirinkimas, duomenuIvedimoBudas);
            Vec1.push_back(Temporary);
        }
    }
    else if (duomenuIvedimoBudas == 2) {
        cout << "Iveskite, kuri faila skaityti:\n";
        cout << "\"1\" - kursiokai.txt\n";
        cout << "\"2\" - studentai10000.txt\n";
        cout << "\"3\" - studentai100000.txt\n";
        cout << "\"4\" - studentai1000000.txt\n";

        int failoNr;
        cin >> failoNr;

        if (failoNr == 1) {
            n = ivestisIsFailo("kursiokai.txt", Vec1);
        }
        else if (failoNr == 2) {
            n = ivestisIsFailo("studentai10000.txt", Vec1);
        }
        else if (failoNr == 3) {
            n = ivestisIsFailo("studentai100000.txt", Vec1);
        }
        else if (failoNr == 4) {
            n = ivestisIsFailo("studentai1000000.txt", Vec1);
        }
        else {
            cout << "Neteisingai pasirinktas failas!\n";
        }

        rezultatai(Temporary, "", duomenuIvedimoBudas);
        
    }
    else {
        cout << "Neteisingai pasirinktas ivedimo budas!\n";
    }


    string pazymiotipas;
    if (pasirinkimas == "Med") {
        pazymiotipas = "Med";
    }
    else {
        pazymiotipas = "Vid";
    }

    sort(Vec1.begin(), Vec1.end(), rusiavimas);

    cout << "\n";
    if (duomenuIvedimoBudas == 1) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" 
            << setw(3) << left << "Galutinis (" << pazymiotipas << ".)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            isvestis(Vec1.at(i), duomenuIvedimoBudas);
    }
    else if (duomenuIvedimoBudas == 2) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(20) << left << "Galutinis (Vid.)" 
            << setw(10) << left << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            isvestis(Vec1.at(i), duomenuIvedimoBudas);
    }
    cout << "\n";

    return 0;
}
