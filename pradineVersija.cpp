#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::setprecision;
using std::setw;
using std::left;
using std::fixed;
using std::sort;
using std::ifstream;
using std::getline;
using std::istringstream;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int ndSkaicius;
    int egzaminas;
    double galutinisPazymys;
    double galutinisPazymysVid;
    double galutinisPazymysMed;
};

void ivestis(Studentas& Lok, bool generavimas);
void isvestis(Studentas Lok, int ivestiesPasirinkimas);
double rezultatai(Studentas Lok, string pasirinkimas, int ivestiesPasirinkimas);
int ivestisIsFailo(const string& failas, vector<Studentas>& Vec1);
bool rusiavimas(const Studentas& pavarde1, const Studentas& pavarde2);

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