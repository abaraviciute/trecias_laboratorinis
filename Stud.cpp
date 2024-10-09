#include "Stud.h"

void ivestis(Studentas& Lok, bool generavimas)
{
    cout << "Iveskite varda: ";
    cin >> Lok.vardas;

    cout << "Iveskite pavarde: ";
    cin >> Lok.pavarde;

    if (generavimas) {
        int ndSkaicius = 5;
        Lok.nd.clear();
        for (int i = 0; i < ndSkaicius; i++) {
            int pazymys = rand() % 10 + 1;
            Lok.nd.push_back(pazymys);
        }
        Lok.egzaminas = rand() % 10 + 1;
    }
    else {
            Lok.nd.clear();
            cout << "Iveskite namu darbu pazymius (iveskite -1 noredami baigti): " << endl;

            while (true) {
            int pazymys;

                try {
                    cout << "Pazymys " << (Lok.nd.size() + 1) << ": ";
                    cin >> pazymys;

                    if (pazymys == -1) {
                        break;
                    }

                    if (cin.fail() || pazymys < 1 || pazymys>10) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw  invalid_argument("Galima ivestis nuo 1 iki 10!\n");
                    }
                    Lok.nd.push_back(pazymys);
                }
                catch (const invalid_argument& e) {
                        cout << e.what();
                } 
            }

        while (true) {
            try {
                cout << "Iveskite egzamino pazymi: ";
                cin >> Lok.egzaminas;

                if (cin.fail() || Lok.egzaminas < 1 || Lok.egzaminas>10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Galima ivestis nuo 1 iki 10!\n");
                }
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what();
            }
        }
    }
}

double rezultatai(Studentas Lok, string pasirinkimas)
{
    if (pasirinkimas == "Vid") {
        double vidurkis = 0.0;

        for (int i = 0; i < Lok.nd.size(); i++) {
            vidurkis += Lok.nd[i];
        }
        vidurkis /= Lok.nd.size();

        return 0.4 * vidurkis + 0.6 * Lok.egzaminas;
    }

    if (pasirinkimas == "Med") {
        double mediana;
        vector<int> pazymiai = Lok.nd;
        sort(pazymiai.begin(), pazymiai.end());

        if (Lok.nd.size() % 2 == 0) {
            mediana = (pazymiai[Lok.nd.size() / 2 - 1] + pazymiai[Lok.nd.size() / 2]) / 2.0;
        }
        else {
            mediana = pazymiai[Lok.nd.size() / 2];
        }

        return 0.4 * mediana + 0.6 * Lok.egzaminas;
    }

    return 0;
}

void isvestis(Studentas Lok, int ivestiesPasirinkimas)
{
    if (ivestiesPasirinkimas == 1) {
        cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas
            << setw(10) << left << fixed << setprecision(2) << Lok.galutinisPazymys << endl;
    }
    else if (ivestiesPasirinkimas == 2) {
        cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas
            << setw(20) << left << fixed << setprecision(2) << Lok.galutinisPazymysVid
            << setw(10) << left << fixed << setprecision(2) << Lok.galutinisPazymysMed << endl;
    }
}

int ivestisIsFailo(const string& failas, vector<Studentas>& Vec1)
{
    ifstream inFile(failas);

    if (!inFile) {
        cout << "Nepavyko atidaryti failo: " << failas << endl;
        return 0;
    }

    string line;
    getline(inFile, line);

    int studentu = 0;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Studentas Temp;

        iss >> Temp.vardas >> Temp.pavarde;

        int pazymys;
        Temp.nd.clear();
        while (iss >> pazymys) {
            Temp.nd.push_back(pazymys);
        }

        Temp.egzaminas = Temp.nd.back();
        Temp.nd.pop_back();

        Temp.galutinisPazymysVid = rezultatai(Temp, "Vid");
        Temp.galutinisPazymysMed = rezultatai(Temp, "Med");

        Vec1.push_back(Temp);

        studentu++;
    }

    inFile.close();

    return studentu;
}

bool rusiavimas(const Studentas& Lok1, const Studentas& Lok2)
{
    return Lok1.pavarde < Lok2.pavarde;
}

void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas) 
{
    vector<Studentas> studentas(studentuSkaicius);

    srand(time(nullptr));

    for (int i = 0; i < studentuSkaicius; i++) {
        studentas[i].vardas = "Vardas" + to_string(i + 1);
        studentas[i].pavarde = "Pavarde" + to_string(i + 1);

        for (int j = 0; j < 5; j++) {
            studentas[i].nd.push_back(rand() % 10 + 1);
        }
        studentas[i].egzaminas = rand() % 10 + 1;
    }

    ofstream out(failoPavadinimas);
    if (!out) {
        throw runtime_error("Nepavyko sukurti failo.");
    }

    auto pradzia = high_resolution_clock::now();

    out << "Vardas " << "Pavarde " << "ND1 " << "ND2 " << "ND3 " << "ND4 " << "ND5 " << "Egz." << endl;  

    for (int i = 0; i < studentuSkaicius; i++) {
        out << studentas[i].vardas << " " << studentas[i].pavarde;

        for (int j = 0; j < 5; j++) {
            out << " " << studentas[i].nd[j];
        }
        out << " " << studentas[i].egzaminas << endl;
    }

    out.close();

    auto pabaiga = high_resolution_clock::now();

    duration<double> trukme = pabaiga - pradzia;
    cout << "Failas " << failoPavadinimas << " sugeneruotas. Failo kurimo trukme: " << trukme.count() << endl;
}

void isvestisIFaila(int studentuSkaicius, const vector<Studentas>& Vec1, int duomenuIvedimoBudas, string pazymioTipas)
{
    ofstream galvociai("galvociai.txt");
    ofstream nuskriaustukai("nuskriaustukai.txt");

    if (!galvociai || !nuskriaustukai) {
        throw runtime_error("Nepavyko sukurti failo.");
    }

    if (duomenuIvedimoBudas == 2 || duomenuIvedimoBudas == 3) {
        galvociai << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(20) << left << "Galutinis (Vid.)" << setw(10) << left << "Galutinis (Med.)" << endl;
        galvociai << "-------------------------------------------------------------" << endl;

        nuskriaustukai << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(20) << left << "Galutinis (Vid.)" << setw(10) << left << "Galutinis (Med.)" << endl;
        nuskriaustukai << "-------------------------------------------------------------" << endl;

        for (int i = 0; i < studentuSkaicius; i++) {
            if (Vec1[i].galutinisPazymysVid >= 5.0) {
                galvociai << setw(15) << left << Vec1[i].pavarde << setw(15) << left << Vec1[i].vardas
                    << setw(20) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymysVid
                    << setw(10) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymysMed << endl;
            }
            else {
                nuskriaustukai << setw(15) << left << Vec1[i].pavarde << setw(15) << left << Vec1[i].vardas
                    << setw(20) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymysVid
                    << setw(10) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymysMed << endl;
            }
        }
    }
    else if (duomenuIvedimoBudas == 1) {
        galvociai << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(3) << left << "Galutinis (" << pazymioTipas << ".)" << endl;
        galvociai << "-------------------------------------------------" << endl;

        nuskriaustukai << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(3) << left << "Galutinis (" << pazymioTipas << ".)" << endl;
        nuskriaustukai << "-------------------------------------------------" << endl;

        for (int i = 0; i < studentuSkaicius; i++) {
            if (Vec1[i].galutinisPazymys >= 5.0) {
                galvociai << setw(15) << left << Vec1[i].pavarde << setw(15) << left << Vec1[i].vardas
                    << setw(20) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymys << endl;
            }
            else {
                nuskriaustukai << setw(15) << left << Vec1[i].pavarde << setw(15) << left << Vec1[i].vardas
                    << setw(20) << left << fixed << setprecision(2) << Vec1[i].galutinisPazymys << endl;
            }
        }
    }


    galvociai.close();
    nuskriaustukai.close();

    cout << "Failai \"galvociai.txt\" ir \"nuskriaustukai.txt\" sugeneruoti." << endl;
}
