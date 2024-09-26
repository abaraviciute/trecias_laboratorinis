#include "Stud.h"

void ivestis(Studentas& Lok, bool generavimas)
{
    cout << "Iveskite varda: ";
    cin >> Lok.vardas;

    cout << "Iveskite pavarde: ";
    cin >> Lok.pavarde;

    if (generavimas) {
        Lok.ndSkaicius = 5;
        Lok.nd.clear();
        for (int i = 0; i < Lok.ndSkaicius; i++) {
            int pazymys = rand() % 10 + 1;
            Lok.nd.push_back(pazymys);
        }
        Lok.egzaminas = rand() % 10 + 1;
    }
    else {
        Lok.ndSkaicius = 0;
        cout << "Iveskite namu darbu pazymius (iveskite -1 noredami baigti): " << endl;
        Lok.nd.clear();
        while (true) {
            int pazymys;
            cout << "Pazymys " << (Lok.ndSkaicius + 1) << ": ";
            cin >> pazymys;

            if (pazymys == -1) {
                break;
            }

            if (cin.fail() || pazymys < 1 || pazymys>10) {
                cout << "Galima ivestis nuo 1 iki 10!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            Lok.nd.push_back(pazymys);
            Lok.ndSkaicius++;
        }


        while (true) {
            cout << "Iveskite egzamino pazymi: ";
            cin >> Lok.egzaminas;

            if (cin.fail() || Lok.egzaminas < 1 || Lok.egzaminas>10) {
                cout << "Galima ivestis nuo 1 iki 10!!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    }

}

double rezultatai(Studentas Lok, string pasirinkimas, int ivestiesPasirinkimas)
{
    if (pasirinkimas == "Vid") {
        double vidurkis = 0.0;

        for (int i = 0; i < Lok.ndSkaicius; i++) {
            vidurkis += Lok.nd[i];
        }
        vidurkis /= Lok.ndSkaicius;

        return 0.4 * vidurkis + 0.6 * Lok.egzaminas;
    }

    if (pasirinkimas == "Med") {
        double mediana;
        vector<int> pazymiai = Lok.nd;
        sort(pazymiai.begin(), pazymiai.end());

        if (Lok.ndSkaicius % 2 == 0) {
            mediana = (pazymiai[Lok.ndSkaicius / 2 - 1] + pazymiai[Lok.ndSkaicius / 2]) / 2.0;
        }
        else {
            mediana = pazymiai[Lok.ndSkaicius / 2];
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
        Temp.ndSkaicius = Temp.nd.size();

        Temp.galutinisPazymysVid = rezultatai(Temp, "Vid", 2);
        Temp.galutinisPazymysMed = rezultatai(Temp, "Med", 2);

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
