#include "Stud.h"

void ivestis(Studentas& Lok, bool generavimas)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);

    cout << "Iveskite varda: ";
    cin >> Lok.vardas;

    cout << "Iveskite pavarde: ";
    cin >> Lok.pavarde;

    if (generavimas) {
        int ndSkaicius = 5;
        Lok.nd.clear();
        for (int i = 0; i < ndSkaicius; i++) {
            int pazymys = dist(mt);
            Lok.nd.push_back(pazymys);
        }
        Lok.egzaminas = dist(mt);
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

double rezultatai(const Studentas& Lok, const string& pasirinkimas)
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

void isvestis(const Studentas& Lok, int ivestiesPasirinkimas)
{
    if (ivestiesPasirinkimas == 1) {
        cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas
            << setw(16) << left << fixed << setprecision(2) << Lok.galutinisPazymys
            << setw(17) << left << &Lok << endl;
    }
    else if (ivestiesPasirinkimas == 2) {
        cout << setw(15) << left << Lok.pavarde << setw(15) << left << Lok.vardas
            << setw(20) << left << fixed << setprecision(2) << Lok.galutinisPazymysVid
            << setw(10) << left << fixed << setprecision(2) << Lok.galutinisPazymysMed << endl;
    }
}

template <typename Struktura>
int ivestisIsFailo(const string& failas, Struktura& struktura)
{
    ifstream inFile(failas);

    if (!inFile) {
        cout << "Nepavyko atidaryti failo: " << failas << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    getline(inFile, line);

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

        struktura.push_back(Temp);
    }

    inFile.close();
    return 0;
}

bool rusiavimas(const Studentas& Lok1, const Studentas& Lok2)
{
    double pazymys1 = Lok1.galutinisPazymysVid;
    double pazymys2 = Lok2.galutinisPazymysVid;

    if (rikiavimoSalyga == 1) {
        return (pazymys1 == pazymys2) ? (Lok1.pavarde < Lok2.pavarde) : (pazymys1 < pazymys2);
    }
    else if (rikiavimoSalyga == 2) {
        return (pazymys1 == pazymys2) ? (Lok1.pavarde < Lok2.pavarde) : (pazymys1 > pazymys2);
    }
    else {
        return Lok1.pavarde < Lok2.pavarde;
    }
}

void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);

    ofstream out(failoPavadinimas);
    if (!out) {
        throw runtime_error("Nepavyko sukurti failo.");
    }

    auto pradzia = high_resolution_clock::now();

    out << left << setw(15) << "Vardas"
        << left << setw(15) << "Pavarde"
        << right << setw(5) << "ND1"
        << right << setw(5) << "ND2"
        << right << setw(5) << "ND3"
        << right << setw(5) << "ND4"
        << right << setw(5) << "ND5"
        << right << setw(5) << "Egz." << '\n';

    ostringstream studentoDuomenys;

    for (int i = 0; i < studentuSkaicius; i++) {
        studentoDuomenys << left << setw(15) << "Vardas" + to_string(i + 1)
            << left << setw(15) << "Pavarde" + to_string(i + 1);

        for (int j = 0; j < 6; j++) {
            studentoDuomenys << right << setw(5) << dist(mt);
        }

        studentoDuomenys << '\n';

        if ((i + 1) % 100 == 0 || i + 1 == studentuSkaicius) {
            out << studentoDuomenys.str();
            studentoDuomenys.str("");
            studentoDuomenys.clear();
        }
    }

    out.close();

    auto pabaiga = high_resolution_clock::now();
    duration<double> trukme = pabaiga - pradzia;
    cout << "Failas " << failoPavadinimas << " sugeneruotas. Failo kurimo trukme: " << trukme.count() << "\n";
}

template <typename Struktura>
void studentoKategorija1(const Struktura& struktura, int duomenuIvedimoBudas, Struktura& galvociai, Struktura& nuskriaustukai)
{
    for (const auto& studentas : struktura) {
        if ((duomenuIvedimoBudas == 2 && studentas.galutinisPazymysVid >= 5) ||
            (duomenuIvedimoBudas != 2 && studentas.galutinisPazymys >= 5)) {
            galvociai.push_back(studentas);
        }
        else {
            nuskriaustukai.push_back(studentas);
        }
    }
}

template <typename Struktura>
void studentoKategorija2(Struktura& struktura, int duomenuIvedimoBudas, Struktura& nuskriaustukai)
{
    if constexpr (is_same_v<Struktura, vector<typename Struktura::value_type>>) {

        sort(struktura.begin(), struktura.end(),
            [duomenuIvedimoBudas](const auto& a, const auto& b) {
                if (duomenuIvedimoBudas == 2) {
                    return a.galutinisPazymysVid > b.galutinisPazymysVid;
                }
                else {
                    return a.galutinisPazymys > b.galutinisPazymys;
                }
            });
    }
    else if constexpr (is_same_v<Struktura, list<typename Struktura::value_type>>) {

        struktura.sort(
            [duomenuIvedimoBudas](const auto& a, const auto& b) {
                if (duomenuIvedimoBudas == 2) {
                    return a.galutinisPazymysVid > b.galutinisPazymysVid;
                }
                else {
                    return a.galutinisPazymys > b.galutinisPazymys;
                }
            });
    }

    while (!struktura.empty() &&
        ((duomenuIvedimoBudas == 2 && struktura.back().galutinisPazymysVid < 5) ||
            (duomenuIvedimoBudas != 2 && struktura.back().galutinisPazymys < 5))) {
        nuskriaustukai.push_back(struktura.back());
        struktura.pop_back();
    }
}



template <typename Struktura>
void studentoKategorija3(Struktura& struktura, int duomenuIvedimoBudas, Struktura& nuskriaustukai)
{
    function<bool(const typename Struktura::value_type&)> condition;

    if (duomenuIvedimoBudas == 2) {
        condition = [](const auto& studentas) { return studentas.galutinisPazymysVid >= 5; };
    }
    else {
        condition = [](const auto& studentas) { return studentas.galutinisPazymys >= 5; };
    }

    auto it = partition(struktura.begin(), struktura.end(), condition);

    nuskriaustukai.insert(nuskriaustukai.end(), it, struktura.end());

    struktura.erase(it, struktura.end());
}

void studentoKategorijaVector(vector<Studentas>& struktura, int duomenuIvedimoBudas, vector<Studentas>& nuskriaustukai)
{
    function<bool(const Studentas&)> condition;

    if (duomenuIvedimoBudas == 2) {
        condition = [](const Studentas& studentas) { return studentas.galutinisPazymysVid < 5; };
    }
    else {
        condition = [](const Studentas& studentas) { return studentas.galutinisPazymys < 5; };
    }

    auto it = partition(struktura.begin(), struktura.end(), [condition](const Studentas& studentas) {
        return !condition(studentas);
        });

    nuskriaustukai.insert(nuskriaustukai.end(), it, struktura.end());

    struktura.erase(it, struktura.end());
}

template <typename Struktura>
void iFaila(const string& failas, const Struktura& studentai, int duomenuIvedimoBudas, const string& pazymioTipas, duration<double>& trukme) {
    ofstream ived(failas);
    if (!ived) {
        throw runtime_error("Nepavyko sukurti failo: " + failas);
    }

    auto pradzia = high_resolution_clock::now();

    if (duomenuIvedimoBudas == 2) {
        ived << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(20) << left << "Galutinis (Vid.)" << setw(10) << left << "Galutinis (Med.)" << endl;
        ived << "-------------------------------------------------------------" << endl;
    }
    else {
        ived << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
            << setw(3) << left << "Galutinis (" << pazymioTipas << ".)" << endl;
        ived << "-------------------------------------------------" << endl;
    }

    for (const auto& studentas : studentai) {
        ived << setw(15) << left << studentas.pavarde << setw(15) << left << studentas.vardas;
        if (duomenuIvedimoBudas == 2) {
            ived << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymysVid
                << setw(10) << left << fixed << setprecision(2) << studentas.galutinisPazymysMed;
        }
        else {
            ived << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymys;
        }
        ived << endl;
    }

    auto pabaiga = high_resolution_clock::now();
    trukme = pabaiga - pradzia;
}

template <typename Struktura>
void isvestisIFaila(const Struktura& galvociai, const Struktura& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas, duration<double>& trukmeGalvociu, duration<double>& trukmeNuskriaustuku) {
    iFaila("galvociai.txt", galvociai, duomenuIvedimoBudas, pazymioTipas, trukmeGalvociu);

    iFaila("nuskriaustukai.txt", nuskriaustukai, duomenuIvedimoBudas, pazymioTipas, trukmeNuskriaustuku);

    cout << "Failai \"galvociai.txt\" ir \"nuskriaustukai.txt\" sugeneruoti." << endl;
}

template int ivestisIsFailo<vector<Studentas>>(const string& failas, vector<Studentas>& struktura);
template int ivestisIsFailo<list<Studentas>>(const string& failas, list<Studentas>& struktura);
template void studentoKategorija1<vector<Studentas>>(const vector<Studentas> &struktura, int duomenuIvedimoBudas, vector<Studentas>& galvociai, vector<Studentas>& nuskriaustukai);
template void studentoKategorija1<list<Studentas>>(const list<Studentas>& struktura, int duomenuIvedimoBudas, list<Studentas>& galvociai, list<Studentas>& nuskriaustukai);
template void studentoKategorija2<vector<Studentas>>(vector<Studentas>& struktura, int duomenuIvedimoBudas, vector<Studentas>& nuskriaustukai);
template void studentoKategorija2<list<Studentas>>(list<Studentas>& struktura, int duomenuIvedimoBudas, list<Studentas>& nuskriaustukai);
template void studentoKategorija3<vector<Studentas>>(vector<Studentas>& struktura, int duomenuIvedimoBudas, vector<Studentas>& nuskriaustukai);
template void studentoKategorija3<list<Studentas>>(list<Studentas>& struktura, int duomenuIvedimoBudas, list<Studentas>& nuskriaustukai);
template void isvestisIFaila<vector<Studentas>>(const vector<Studentas>& galvociai, const vector<Studentas>& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas, duration<double>& trukmeGalvociu, duration<double>& trukmeNuskriaustuku);
template void isvestisIFaila<list<Studentas>>(const list<Studentas>& galvociai, const list<Studentas>& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas, duration<double>& trukmeGalvociu, duration<double>& trukmeNuskriaustuku);

