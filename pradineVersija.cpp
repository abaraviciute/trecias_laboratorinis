#include "Mylib.h"
#include "Stud.h"

int main() {

    srand(static_cast<unsigned>(std::time(0)));

    vector<Studentas> Vec1;
    Studentas Temporary;
    int n = 0; //studentu skaicius
    string pasirinkimas;
    string pasirinkimasGeneravimo;
    bool generavimas;
    int duomenuIvedimoBudas;
    int failoNr;

    while (true) {
        try {
            cout << "Pasirinkite duomenu ivedimo buda:\n";
            cout << "\"1\" Rankiniu budu\n";
            cout << "\"2\" Skaityti is failo\n";
        
            cin >> duomenuIvedimoBudas;

            if ((duomenuIvedimoBudas != 1 && duomenuIvedimoBudas != 2) || cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Neteisingas pasirinkimas.Iveskite \"1\" arba \"2\".\n");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << e.what();
        }
    }

    if (duomenuIvedimoBudas == 1) {

        while (true) {
            try {
                cout << "Ar norite skaiciuoti galutini pazymi pagal \"Vid\" (vidurki) ar \"Med\" (mediana)?: ";
                cin >> pasirinkimas;

                if (pasirinkimas != "Vid" && pasirinkimas != "Med") {
                    throw invalid_argument("Neteisingas pasirinkimas. Iveskite \"Vid\" arba \"Med\".\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }

        while (true) {
            try {
                cout << "Iveskite studentu skaiciu: ";
                cin >> n;

                if (cin.fail() || n < 1) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Neteisingas ivedimas. Iveskite sveikaji skaiciu > 1.\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }

        for (int i = 0; i < n; i++) {
            while (true) {
                try {
                    cout << "Ar norite ivesti pazymius \"R\" (rankiniu) budu, ar juos sugeneruoti \"A\" (atsitiktinai)?: ";
                    cin >> pasirinkimasGeneravimo;

                    if (pasirinkimasGeneravimo != "R" && pasirinkimasGeneravimo != "A") {
                        throw invalid_argument("Neteisingas pasirinkimas. Iveskite \"R\" arba \"A\".\n");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cout << e.what();
                }
            }
            generavimas = (pasirinkimasGeneravimo == "A");

            cout << "Iveskite studento duomenis: " << endl;
            ivestis(Temporary, generavimas);

            Temporary.galutinisPazymys = rezultatai(Temporary, pasirinkimas, duomenuIvedimoBudas);
            Vec1.push_back(Temporary);
        }
    }
    else if (duomenuIvedimoBudas == 2) {

        while (true) {
            try {
                cout << "Iveskite, kuri faila skaityti:\n";
                cout << "\"1\" - kursiokai.txt\n";
                cout << "\"2\" - studentai10000.txt\n";
                cout << "\"3\" - studentai100000.txt\n";
                cout << "\"4\" - studentai1000000.txt\n";

                cin >> failoNr;

                if ((failoNr < 1 || failoNr > 4) || cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Neteisingas pasirinkimas.Iveskite sveikaji skaiciu nuo \"1\" iki \"4\".\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }

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

        rezultatai(Temporary, "", duomenuIvedimoBudas);
        
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
