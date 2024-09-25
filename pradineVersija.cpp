#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

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
using std::right;
using std::fixed;

const int MAX_ND = 10;

struct Studentas {
    string vardas;
    string pavarde;
    int nd[MAX_ND];
    int ndSkaicius;
    int egzaminas;
    double galutinisPazymys;
};

void ivestis(Studentas& Lok);
void isvestis(Studentas Lok);
double rezultatai(Studentas Lok, string pasirinkimas);

int main() {
    vector<Studentas> Vec1;
    Studentas Temporary;
    int n; //studentu skaicius

    string pasirinkimas;

    while (true) {
        cout << "Ar norite skaiciuoti galutini pazymi pagal \"Vid\" (vidurki) ar \"Med\" (mediana)? ";
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
            cout << "Prasome ivesti teigiama skaiciu!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento duomenis: " << endl;
        ivestis(Temporary);

        Temporary.galutinisPazymys = rezultatai(Temporary, pasirinkimas);
        Vec1.push_back(Temporary);
    }

    string pazymioTipas;
    if (pasirinkimas == "Med") {
        pazymioTipas = "Med";
    }
    else {
        pazymioTipas = "Vid";
    }

    cout << "\n";
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" 
        << setw(3) << right << "Galutinis (" << pazymioTipas << ".)" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
        isvestis(Vec1.at(i));
    cout << "\n";

    return 0;
}


void ivestis(Studentas& Lok)
{
    cout << "Iveskite varda: ";
    cin >> Lok.vardas;

    cout << "Iveskite pavarde: ";
    cin >> Lok.pavarde;

    while (true) {
        cout << "Iveskite atliktu namu darbu skaiciu: ";
        cin >> Lok.ndSkaicius;

        if (cin.fail() || Lok.ndSkaicius < 1) {
            cout << "Iveskite bent 1 namu darbus!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            if (Lok.ndSkaicius > MAX_ND) {
                Lok.ndSkaicius = MAX_ND;
                cout << "Iveskite tik " << MAX_ND << " namu darbu pazymius.\n";
            }
            break;
        }
    }

    cout << "Iveskite namu darbu pazymius: " << endl;
    for (int i = 0; i < Lok.ndSkaicius; i++) {
        while (true) {
            cout << "Pazymys " << (i + 1) << ": ";
            cin >> Lok.nd[i];

            if (cin.fail() || Lok.nd[i]<1 || Lok.nd[i]>10) {
                cout << "Galima ivestis nuo 1 iki 10!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    }

    while (true) {
        cout << "Iveskite egzamino pazymi: ";
        cin >> Lok.egzaminas;

        if (cin.fail() || Lok.egzaminas<1 || Lok.egzaminas>10) {
            cout << "Galima ivestis nuo 1 iki 10!!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
}

double rezultatai(Studentas Lok, string pasirinkimas)
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
        vector<int> pazymiai(Lok.nd, Lok.nd + Lok.ndSkaicius);
        std::sort(pazymiai.begin(), pazymiai.end());

        if (Lok.ndSkaicius % 2 == 0) {
            mediana = (pazymiai[Lok.ndSkaicius / 2 - 1] + pazymiai[Lok.ndSkaicius / 2]) / 2.0;
        }
        else {
            mediana = pazymiai[Lok.ndSkaicius / 2];
        }

        return 0.4 * mediana + 0.6 * Lok.egzaminas;
    }

    return 0.0;
}

void isvestis(Studentas Lok)
{
    cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas 
        << setw(3) << right << fixed << setprecision(2) << Lok.galutinisPazymys << endl;
}