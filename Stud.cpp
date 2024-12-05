#include "Stud.h"

void Studentas::ivestis(bool generavimas)
{
    if (generavimas) {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(1, 10);

        cout << "Iveskite varda: ";
        cin >> vardas_;

        cout << "Iveskite pavarde: ";
        cin >> pavarde_;

        int ndSkaicius = 5;
        nd_.clear();
        for (int i = 0; i < ndSkaicius; i++) {
            nd_.push_back(dist(mt));
        }
        egzaminas_ = dist(mt);
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite varda, pavarde, namu darbu pazymius, ir egzamino pazymi (atskirtus tarpu): " << endl;
        cin >> *this;
    }
}

double Studentas::rezultatai(const string& pasirinkimas)
{
    if (nd_.empty() && egzaminas_ == 0) {
        return 0.0; 
    }

    if (pasirinkimas == "Vid") {
        double vidurkis = 0.0;

        for (int i = 0; i < nd_.size(); i++) {
            vidurkis += nd_[i];
        }
        vidurkis /= nd_.size();

        return 0.4 * vidurkis + 0.6 * egzaminas_;
    }

    if (pasirinkimas == "Med") {
        double mediana;
        vector<int> pazymiai = nd_;
        sort(pazymiai.begin(), pazymiai.end());

        if (pazymiai.size() % 2 == 0) {
            mediana = (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2.0;
        }
        else {
            mediana = pazymiai[pazymiai.size() / 2];
        }

        return 0.4 * mediana + 0.6 * egzaminas_;
    }

    return 0;
}


void isvestis(const Studentas& Lok, int ivestiesPasirinkimas) {
    cout << Lok << &Lok << endl;
}


template <typename Struktura>
int ivestisIsFailo(const string& failas, Struktura& struktura)
{
    ifstream inFile(failas);

    if (!inFile) {
        cout << "Nepavyko atidaryti failo: " << failas << endl;
        return -1;
    }

    string line;
    getline(inFile, line);

    Studentas temp;
    while (inFile >> temp) {
        struktura.push_back(temp);
    }

    inFile.close();
    return 0;
}

bool rusiavimas(const Studentas& pavarde1, const Studentas& pavarde2)
{
    double pazymys1 = pavarde1.galutinisPazymysVid();
    double pazymys2 = pavarde2.galutinisPazymysVid();

    if (rikiavimoSalyga == 1) {
        return (pazymys1 == pazymys2) ? (pavarde1.pavarde_ < pavarde2.pavarde_) : (pazymys1 < pazymys2);
    }
    else if (rikiavimoSalyga == 2) {
        return (pazymys1 == pazymys2) ? (pavarde1.pavarde_ < pavarde2.pavarde_) : (pazymys1 > pazymys2);
    }
    else {
        return pavarde1.pavarde_ < pavarde2.pavarde_;
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
        if ((duomenuIvedimoBudas == 2 && studentas.galutinisPazymysVid() >= 5) ||
            (duomenuIvedimoBudas != 2 && studentas.galutinisPazymys() >= 5)) {
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
                    return a.galutinisPazymysVid() > b.galutinisPazymysVid();
                }
                else {
                    return a.galutinisPazymys() > b.galutinisPazymys();
                }
            });
    }
    else if constexpr (is_same_v<Struktura, list<typename Struktura::value_type>>) {

        struktura.sort(
            [duomenuIvedimoBudas](const auto& a, const auto& b) {
                if (duomenuIvedimoBudas == 2) {
                    return a.galutinisPazymysVid() > b.galutinisPazymysVid();
                }
                else {
                    return a.galutinisPazymys() > b.galutinisPazymys();
                }
            });
    }

    while (!struktura.empty() &&
        ((duomenuIvedimoBudas == 2 && struktura.back().galutinisPazymysVid() < 5) ||
            (duomenuIvedimoBudas != 2 && struktura.back().galutinisPazymys() < 5))) {
        nuskriaustukai.push_back(struktura.back());
        struktura.pop_back();
    }
}



template <typename Struktura>
void studentoKategorija3(Struktura& struktura, int duomenuIvedimoBudas, Struktura& nuskriaustukai)
{
    function<bool(const typename Struktura::value_type&)> condition;

    if (duomenuIvedimoBudas == 2) {
        condition = [](const auto& studentas) { return studentas.galutinisPazymysVid() >= 5; };
    }
    else {
        condition = [](const auto& studentas) { return studentas.galutinisPazymys() >= 5; };
    }

    auto it = partition(struktura.begin(), struktura.end(), condition);

    nuskriaustukai.insert(nuskriaustukai.end(), it, struktura.end());

    struktura.erase(it, struktura.end());
}

void studentoKategorijaVector(vector<Studentas>& struktura, int duomenuIvedimoBudas, vector<Studentas>& nuskriaustukai)
{
    function<bool(const Studentas&)> condition;

    if (duomenuIvedimoBudas == 2) {
        condition = [](const Studentas& studentas) { return studentas.galutinisPazymysVid() < 5; };
    }
    else {
        condition = [](const Studentas& studentas) { return studentas.galutinisPazymys() < 5; };
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
        ived << studentas << endl;
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

