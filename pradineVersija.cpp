#include "Mylib.h"
#include "Stud.h"

int rikiavimoSalyga = 0;

int main() {
    Studentas Temporary;
    int n = 0; //studentu skaicius
    string pasirinkimas;
    string pasirinkimasGeneravimo;
    bool generavimas;
    int duomenuIvedimoBudas;
    int failoNr;
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    duration<double> trukmeNuskaitymo, trukmeRusiavimo, trukmeGalvociu, trukmeNuskriaustuku;
    int rezultataiArTyrimas  = 0;
    int konteineris;
    int strategija = 0;
    vector<string> failai;

    while (true) {
        try {
            cout << "Pasirinkite duomenu ivedimo buda:\n";
            cout << "\"1\" Rankiniu budu\n";
            cout << "\"2\" Skaityti is failo\n";
            cout << "\"3\" Generuoti failus\n";
        
            cin >> duomenuIvedimoBudas;

            if ((duomenuIvedimoBudas != 1 && duomenuIvedimoBudas != 2 && duomenuIvedimoBudas != 3) || cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Neteisingas pasirinkimas.Iveskite \"1\", \"2\" arba \"3\".\n");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << e.what();
        }
    }

    if (duomenuIvedimoBudas != 3) {
        while (true) {
            try {
                cout << "Pasirinkite duomenu konteinerio tipa \"1\" vector arba \"2\" list: ";
                cin >> konteineris;
                if ((konteineris != 1 && konteineris != 2) || cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Neteisingas pasirinkimas. Iveskite \"1\" arba \"2\".\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }

        while (true) {
            try {
                cout << "Iveskite, kokia bus studentu rusiavimo strategija: \n";
                cout << "\"1\" 1 strategija (nuskriaustukai ir galvociai)\n";
                cout << "\"2\" 2 strategija (nuskriaustukai ir studentu failas tik su galvociais)\n";
                cout << "\"3\" 3 strategija (efektyviausia strategija)\n";

                cin >> strategija;

                if ((strategija != 1 && strategija != 2 && strategija != 3) || cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Neteisingas pasirinkimas.Iveskite \"1\" arba \"2\", arba \"3\".\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }
    }
        vector<Studentas> studentaiVector, galvociaiVector, nuskriaustukaiVector;
        list<Studentas> studentaiList, galvociaiList, nuskriaustukaiList;

        bool naudotiVektoriu = (konteineris == 1);
    

    if (duomenuIvedimoBudas == 2) {
        while (true) {
            try {
                cout << "Iveskite, kokia tvarka rikiuoti pazymius: \n";
                cout << "\"1\" Didejancia\n";
                cout << "\"2\" Mazejancia\n";

                cin >> rikiavimoSalyga;

                if ((rikiavimoSalyga != 1 && rikiavimoSalyga != 2) || cin.fail()) {
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

        while (true) {
            try {
                cout << "Iveskite, ka daryti su duomenimis: \n";
                cout << "\"1\" Skaiciuoti galutini bala\n";
                cout << "\"2\" Vykdyti programos spartos analize\n";

                cin >> rezultataiArTyrimas;

                if ((rezultataiArTyrimas != 1 && rezultataiArTyrimas != 2) || cin.fail()) {
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

            Temporary.galutinisPazymys = rezultatai(Temporary, pasirinkimas);

            if (naudotiVektoriu) {
                studentaiVector.push_back(Temporary);
            }
            else {
                studentaiList.push_back(Temporary);
            }
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
                cout << "\"5\" - studentai_1000.txt\n";
                cout << "\"6\" - studentai_10000.txt\n";
                cout << "\"7\" - studentai_100000.txt\n";
                cout << "\"8\" - studentai_1000000.txt\n";
                cout << "\"9\" - studentai_10000000.txt\n";

                cin >> failoNr;

                if ((failoNr < 1 || failoNr > 9) || cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Neteisingas pasirinkimas.Iveskite sveikaji skaiciu nuo \"1\" iki \"9\".\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }

        auto pradzia = high_resolution_clock::now();

        try {
            failai = {
                "kursiokai.txt",
                "studentai10000.txt",
                "studentai100000.txt",
                "studentai1000000.txt",
                "studentai_1000.txt",
                "studentai_10000.txt",
                "studentai_100000.txt",
                "studentai_1000000.txt",
                "studentai_10000000.txt"
            };

            if (failoNr >= 1 && failoNr <= failai.size()) {
                if (naudotiVektoriu) {
                    ivestisIsFailo(failai[failoNr - 1], studentaiVector);
                }
                else {
                    ivestisIsFailo(failai[failoNr - 1], studentaiList);
                }
                
            }
        }
        catch (const runtime_error& e) {
            cerr << "Klaida: " << e.what() << endl;
        }

        auto pabaiga = high_resolution_clock::now();
        trukmeNuskaitymo = pabaiga - pradzia;
    }
    else if (duomenuIvedimoBudas == 3) {
        for (int dydis : dydziai) {
            string failoPavadinimas = "studentai_" + to_string(dydis) + ".txt";
            try {
                generuotiFaila(dydis, failoPavadinimas);
            }
            catch (const exception& e) {
                cout << "Klaida generuojant faila: " << e.what() << endl;
            }
        }
        return (0);
    }

    if (duomenuIvedimoBudas != 3) {
        if (naudotiVektoriu) {
            sort(studentaiVector.begin(), studentaiVector.end(), rusiavimas);

            if (strategija == 1) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija1(studentaiVector, duomenuIvedimoBudas, galvociaiVector, nuskriaustukaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;
            }
            else if (strategija == 2) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija2(studentaiVector, duomenuIvedimoBudas, nuskriaustukaiVector, galvociaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;
            }

            isvestisIFaila(galvociaiVector, nuskriaustukaiVector, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
        }
        else {
            studentaiList.sort(rusiavimas);

            if (strategija == 1) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija1(studentaiList, duomenuIvedimoBudas, galvociaiList, nuskriaustukaiList);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;
            }
            else if (strategija == 2) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija2(studentaiList, duomenuIvedimoBudas, nuskriaustukaiList, galvociaiList);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;
            }

            isvestisIFaila(galvociaiList, nuskriaustukaiList, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
        }

    }

    cout << "\n";

    if (rezultataiArTyrimas == 1 || duomenuIvedimoBudas == 1) {
        if (duomenuIvedimoBudas == 1) {
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" 
                << setw(3) << left << "Galutinis (" << pasirinkimas << ".)" 
                << setw(17) << left << "Adresas" << endl;
            cout << "-------------------------------------------------------------" << endl;
            if (naudotiVektoriu) {
                for (const auto& studentas : studentaiVector)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
            else {
                for (const auto& studentas : studentaiList)
                    isvestis(studentas, duomenuIvedimoBudas);
            }

        }
        else if (duomenuIvedimoBudas == 2) {
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
                << setw(20) << left << "Galutinis (Vid.)" 
                << setw(20) << left << "Galutinis (Med.)" << endl;
            cout << "-------------------------------------------------------------" << endl;
            if (naudotiVektoriu) {
                for (const auto& studentas : studentaiVector)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
            else {
                for (const auto& studentas : studentaiList)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
        }
    }
    else if (rezultataiArTyrimas == 2) {
        if (duomenuIvedimoBudas != 1) {
            cout << "Failo nuskaitymo laikas: " << trukmeNuskaitymo.count() << endl;
        }
        cout << "Irasu dalijimo i dvi grupes laikas: " << trukmeRusiavimo.count() << endl;
        cout << "Irasu irasymo i faila galvociai.txt laikas: " << trukmeGalvociu.count() << endl;
        cout << "Iraso irasymo i faila nuskriaustukai.txt laikas: " << trukmeNuskriaustuku.count() << endl;
        cout << "\n";
        cout << "Bendras programos veikimo laikas: " << trukmeNuskaitymo.count() + trukmeRusiavimo.count() + trukmeGalvociu.count() + trukmeNuskriaustuku.count() << endl;
    }
    return 0;
}
