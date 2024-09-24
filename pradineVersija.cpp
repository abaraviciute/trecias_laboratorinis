#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    double galutinisVid;
};

void ivestis(Studentas& Lok);
void isvestis(Studentas Lok);
double rezultatai(Studentas Lok);

int main() {
    vector<Studentas> Vec1;
    Studentas Temporary;
    int n; //studentu skaicius

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
        Temporary.galutinisVid = rezultatai(Temporary);
        Vec1.push_back(Temporary);
    }

    cout << "\n";
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" 
        << setw(3) << right << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
        isvestis(Vec1.at(i));
    cout << "\n";

    system("pause");

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

            if (cin.fail() || Lok.nd[i]<1) {
                cout << "Galima ivesti tik skaitmenis (teigiamus)!\n";
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

        if (cin.fail() || Lok.egzaminas<1) {
            cout << "Galima ivesti tik skaitmenis (teigiamus)!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
}

double rezultatai(Studentas Lok)
{
    double vidurkis = 0.0;

    for (int i = 0; i < Lok.ndSkaicius; i++) {
        vidurkis += Lok.nd[i];
    }
    vidurkis /= Lok.ndSkaicius;

    return 0.4 * vidurkis + 0.6 * Lok.egzaminas;
}

void isvestis(Studentas Lok)
{
    cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas 
        << setw(3) << right << fixed << setprecision(2) << Lok.galutinisVid << endl;
}