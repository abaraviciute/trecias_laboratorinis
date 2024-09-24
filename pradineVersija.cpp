#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

const int MAX_ND = 10;

struct Studentas {
    string vardas;
    string pavarde;
    int nd[MAX_ND];
    int ndSkaicius;
    int egzaminas;
};

void ivestis(Studentas& Lok);

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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento duomenis: " << endl;
        ivestis(Temporary);
        Vec1.push_back(Temporary);
    }

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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
}