/**
 * @file
 * @brief Pagrindinis vykdomasis failas.
 *
 * Vartotojui leidžiama pasirinkti, kaip bus įvedami studentų duomenys, kokiuose konteineriuose jie bus saugomi, 
 * kokia tvarka rikiuojami duomenys, kokia strategija rūšiuojami į failus, pasirenkama išvestis.
 * Taip pat programa atlieka veikimo spartos analizę, yra klaidų valdymas.
 */

#include "Mylib.h"
#include "Stud.h"


/// Globalus kintamasis naudojamas nustatyti, kokia tvarka bus rikiuojami išvadami duomenys (pagal galutinį pažymį): didėjančia ar mažėjančia.
int rikiavimoSalyga = 0;

/// Globalus kintamasis naudojamas nustatyti, kokiu būdu bus įvesti duomenys ar kaip jais bus manipuliuojama: įvestis ranka, nuskaitymas iš failo, failų generavimas, Rule of Three demonstracija.
int duomenuIvedimoBudas = 0;

/**
 * @brief Programos pagrindinė vykdomoji funkcija.
 *
 * Funkcija apdoroja vartotojo pasirinkimus, tokius kaip duomenų įvedimo būdas, konteinerio tipas,
 * rikiavimo/rūšiavimo strategija, išvedimas.
 *
 * Programos struktūra priklauso nuo vartotojo pasirinkimų, todėl gali būti atliekami įvairūs veiksmai:
 * - Duomenų įvedimas rankiniu būdu arba iš failo;
 * - Generavimas ir studentų rūšiavimas pagal strategijas;
 * - Programos spartos analizė arba duomenų išvestis į ekraną.
 */
int main() {
    Studentas Temporary; /// Laikinas Studentas klasės objektas.
    int n = 0; /// Studentų skaičius.
    string pasirinkimas; /// Pasirinkimas galutinį pažymį skaičiuoti pagal "Vid." (vidurkį) ar "Med." (medianą) rankinio įvedimo metu.
    string pasirinkimasGeneravimo; /// Pasirinkimas, ar įvertinimai bus generuojami atsitiktinai, ar vedami ranka.
    bool generavimas; /// pasirinkimasGeneravimo bool tipo.
    int failoNr; /// Pasirenkamas failas nuskaityti.
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000}; /// Generuojamų failų dydžiai (kiek studentų bus generuojama).
    duration<double> trukmeNuskaitymo, trukmeRusiavimo, trukmeGalvociu, trukmeNuskriaustuku; /// Laiko kintamieji spartos analizei
    int rezultataiArTyrimas  = 0; /// Pasirinkimas išvesti į ekraną surikiuotus studentus su apskaičiuotais galutiniais įvertinimais ar spartos analizę.
    int konteineris = 0; /// Pasirinkimas, kokiame konteineryje (vector/list) bus saugomi duomenys.
    int strategija = 0; /// Pasirinkimas, kokia strategija bus naudojama studentams padalinti į galvočius ir nuskriaustukus.
    vector<string> failai; /// Galimų nuskaityti failų vektorius.
    int vektoriausSkirst = 0; /// Pasirinkimas vektoriuje saugomus duomenis rūšiuoti į dvi grupes naudojant universalią ar tik vektoriams pritaikytą funkciją.

    /** @brief Vartotojo pasirinkimas ką daryti su duomenimis */ 
    while (true) {
        try {
            cout << "Pasirinkite veiksma:\n";
            cout << "\"1\" Duomenu ivedimas rankiniu budu\n";
            cout << "\"2\" Duomenu skaitymas is failo\n";
            cout << "\"3\" Generuoti failus\n";
            cout << "\"4\" \"Rule of Three\" ir Studentas klases demonstracija\n";
        
            cin >> duomenuIvedimoBudas;

            if ((duomenuIvedimoBudas != 1 && duomenuIvedimoBudas != 2 && duomenuIvedimoBudas != 3 && duomenuIvedimoBudas != 4) || cin.fail()) {
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

    if (duomenuIvedimoBudas != 3 && duomenuIvedimoBudas != 4) {
        /** @brief Vartotojo pasirinkimas, kokį konteinerį naudoti duomenims saugoti */
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

        /** @brief Vartotojo pasirinkimas, kokią duomenų skirstymo į dvi grupes (galvočiai ir nuskriaustukai) strategiją naudoti */
        while (true) {
            try {
                cout << "Iveskite, kokia bus studentu rusiavimo strategija: \n";
                cout << "\"1\" 1 strategija (du konteineriai)\n";
                cout << "\"2\" 2 strategija (nuskriaustuku konteineris + studentu konteineris be nuskriaustuku)\n";
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

        /** @brief Vartotojo pasirinkimas, ar dirbant su vektoriumi duomenis į dvi grupes dalinti universalia ar tik vektoriui pritaikyta funkcija */
        if (strategija == 3 && konteineris == 1) {
            while (true) {
                try {
                    cout << "Iveskite, kaip skirstyti i dvi grupes: \n";
                    cout << "\"1\" Fiksuota funkcija vektoriui\n";
                    cout << "\"2\" Universalia funkcija\n";

                    cin >> vektoriausSkirst;

                    if ((vektoriausSkirst != 1 && vektoriausSkirst != 2 ) || cin.fail()) {
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
    }
        vector<Studentas> studentaiVector, galvociaiVector, nuskriaustukaiVector, studentaiVectorVisas;
        list<Studentas> studentaiList, galvociaiList, nuskriaustukaiList, studentaiListVisas;

        bool naudotiVektoriu = (konteineris == 1); /// Kintamasis nustatyti, ar toliau bus naudojamas vector (jei 'true'), ar list (jei 'false') konteineris.
    

    if (duomenuIvedimoBudas == 2) {
        /** @brief Vartotojo pasirinkimas, kokia tvarka rikiuoti studentus pagal pažymį (didėjančia/mažėjančia) */
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

        /** @brief Vartotojo pasirinkimas į ekraną išvesti studentų rezultatus ar spartos analizės rezultatus */
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
        /** @brief Vartotojo pasirinkimas pagal kokį rodiklį (vidurkį/medianą) skaičiuoti galutinį pažymį */
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

        /** @brief Vartotojo įvedamas studentų, kuriuos norės įvesti, skaičius */
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

        /** @brief Vartotojo pasirinkimas studento namų darbų ir egzamino įvertinimus vesti ranka ar sugeneruoti automatiškai */
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
            Temporary.ivestis(generavimas);

            Temporary.setGalutinisPazymys(Temporary.rezultatai(pasirinkimas));

            if (naudotiVektoriu) {
                studentaiVector.push_back(Temporary);
            }
            else {
                studentaiList.push_back(Temporary);
            }
        }
    }
    else if (duomenuIvedimoBudas == 2) {
        /** @brief Vartotojo pasirinkimas, kurio failo duomenis nuskaityti */
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
        /** @brief Failų generavimas */
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
    /** @brief Atliekama Rule of Three ir klasių (ne)veikimo demonstracija */
    else if (duomenuIvedimoBudas == 4) {
     //   Zmogus zmogus1("Vidas", "Vidauskas");
        
        Studentas studentas1("Jonas", "Jonauskas", {3, 4, 5, 6, 3, 4, 5}, 10);
        studentas1.klase();
        cout << left << setw(40) << "Studentas1: " << studentas1 << endl;

        Studentas studentas2;
        studentas2 = studentas1;
        studentas2.klase();
        cout << left << setw(40) << "Studentas2 (nukopijuotas Studentas1): " << studentas2 << endl;

        Studentas studentas3(studentas1);
        studentas3.klase();
        cout << left << setw(40) << "Studentas3 (priskirtas nuo Studentas1): " << studentas3 << endl;

        cout << endl;

        studentas1.~Studentas();
        cout << "Studentas1 po destruktoriaus panaudojimo: " << studentas1 << endl;
        cout << "Studentas2 po destruktoriaus panaudojimo: " << studentas2 << endl;
        cout << "Studentas3 po destruktoriaus panaudojimo: " << studentas3 << endl;

        return 0;
    }

    if (duomenuIvedimoBudas != 3 && duomenuIvedimoBudas != 4) {
        /** @brief vector konteineryje saugomi studentai išrikiuojami, išrūšiuojami pagal galutinį įvertinimą į dvi grupes ir išvedami į du failus 'galvociai.txt' ir 'nuskriaustukai.txt' */
        if (naudotiVektoriu) {
            sort(studentaiVector.begin(), studentaiVector.end(), rusiavimas);

            studentaiVectorVisas = studentaiVector;

            if (strategija == 1) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija1(studentaiVector, duomenuIvedimoBudas, galvociaiVector, nuskriaustukaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                isvestisIFaila(galvociaiVector, nuskriaustukaiVector, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
            else if (strategija == 2) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija2(studentaiVector, duomenuIvedimoBudas, nuskriaustukaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                sort(studentaiVector.begin(), studentaiVector.end(), rusiavimas);
                sort(nuskriaustukaiVector.begin(), nuskriaustukaiVector.end(), rusiavimas);

                isvestisIFaila(studentaiVector, nuskriaustukaiVector, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
            else if (strategija == 3 && vektoriausSkirst == 2) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija3(studentaiVector, duomenuIvedimoBudas, nuskriaustukaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                isvestisIFaila(studentaiVector, nuskriaustukaiVector, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
            else if (strategija == 3 && vektoriausSkirst == 1) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorijaVector(studentaiVector, duomenuIvedimoBudas, nuskriaustukaiVector);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                isvestisIFaila(studentaiVector, nuskriaustukaiVector, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
        }
        /** @brief list konteineryje saugomi studentai išrikiuojami, išrūšiuojami pagal galutinį įvertinimą į dvi grupes ir išvedami į du failus 'galvociai.txt' ir 'nuskriaustukai.txt' */
        else {
            studentaiList.sort(rusiavimas);

            studentaiListVisas = studentaiList;

            if (strategija == 1) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija1(studentaiList, duomenuIvedimoBudas, galvociaiList, nuskriaustukaiList);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                isvestisIFaila(galvociaiList, nuskriaustukaiList, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
            else if (strategija == 2) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija2(studentaiList, duomenuIvedimoBudas, nuskriaustukaiList);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                studentaiList.sort(rusiavimas);
                nuskriaustukaiList.sort(rusiavimas);

                isvestisIFaila(studentaiList, nuskriaustukaiList, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
            else if (strategija == 3) {
                auto pradzia = high_resolution_clock::now();
                studentoKategorija3(studentaiList, duomenuIvedimoBudas, nuskriaustukaiList);
                auto pabaiga = high_resolution_clock::now();
                trukmeRusiavimo = pabaiga - pradzia;

                isvestisIFaila(studentaiList, nuskriaustukaiList, duomenuIvedimoBudas, pasirinkimas, trukmeGalvociu, trukmeNuskriaustuku);
            }
        }

    }

    cout << "\n";

    /** @brief Studentų apdorotų duomenų išvedimas į ekraną priklausomai nuo duomenų įvedimo būdo (įvedus ranka papildomai rodomas objekto saugojimo adresas) */
    if (rezultataiArTyrimas == 1 || duomenuIvedimoBudas == 1) {
        if (duomenuIvedimoBudas == 1) {
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" 
                << setw(3) << left << "Galutinis (" << pasirinkimas << ".)" 
                << setw(17) << left << "Adresas" << endl;
            cout << "-------------------------------------------------------------" << endl;
            if (naudotiVektoriu) {
                for (const auto& studentas : studentaiVectorVisas)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
            else {
                for (const auto& studentas : studentaiListVisas)
                    isvestis(studentas, duomenuIvedimoBudas);
            }

        }
        else if (duomenuIvedimoBudas == 2) {
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
                << setw(20) << left << "Galutinis (Vid.)" 
                << setw(20) << left << "Galutinis (Med.)" << endl;
            cout << "-------------------------------------------------------------" << endl;
            if (naudotiVektoriu) {
                for (const auto& studentas : studentaiVectorVisas)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
            else {
                for (const auto& studentas : studentaiListVisas)
                    isvestis(studentas, duomenuIvedimoBudas);
            }
        }
    }
    /** @brief Į ekraną išvedami programos veikimo spartos analizės rezultatai */
    else if (rezultataiArTyrimas == 2) {
        if (duomenuIvedimoBudas != 1 && duomenuIvedimoBudas != 4) {
            cout << "Failo nuskaitymo laikas: " << trukmeNuskaitymo.count() << endl;
        }
        cout << "Irasu dalijimo i dvi grupes laikas: " << trukmeRusiavimo.count() << endl;
        cout << "Irasu irasymo i faila galvociai.txt laikas: " << trukmeGalvociu.count() << endl;
        cout << "Iraso irasymo i faila nuskriaustukai.txt laikas: " << trukmeNuskriaustuku.count() << endl;
        cout << "\n";
        cout << "Bendras programos veikimo laikas: " << trukmeNuskaitymo.count() + trukmeRusiavimo.count() + trukmeGalvociu.count() + trukmeNuskriaustuku.count() << endl;
    }

    system("pause");

    return 0;
}
