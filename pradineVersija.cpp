#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
};

void ivestis(Studentas& Lok);

int main() {
    vector<Studentas> Vec1;
    Studentas Temporary;

    cout << "Iveskite studentu skaiciu: ";
    int n;
    cin >> n;

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

    cout << "Iveskite paskutiniu 5 namu darbu pazymius: ";
    Lok.nd.resize(5);
    for (int i = 0; i < 5; i++) {
        cin >> Lok.nd[i];
    }

    cout << "Iveskite egzamino pazymi: ";
    cin >> Lok.egzaminas;
}