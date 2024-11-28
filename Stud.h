#pragma once
#include "Mylib.h"

extern int rikiavimoSalyga;
extern int duomenuIvedimoBudas;

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egzaminas_;
public:
    double galutinisPazymys;
    double galutinisPazymysVid;
    double galutinisPazymysMed;

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline vector<int> nd() const { return nd_; }
    inline int egzaminas() const { return egzaminas_; }

    inline void setVardas(const string& vardas) { vardas_ = vardas; }
    inline void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    inline void setNd(const vector<int>& nd) { nd_ = nd; }
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }

    Studentas()
        : vardas_(""), pavarde_(""),  egzaminas_(0),
        galutinisPazymys(0), galutinisPazymysVid(0), galutinisPazymysMed(0) {}

    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egzaminas)
        : vardas_(vardas), pavarde_(pavarde), nd_(nd), egzaminas_(egzaminas) {
        galutinisPazymysVid = rezultatai("Vid");
        galutinisPazymysMed = rezultatai("Med");
    }

    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), nd_(other.nd_), egzaminas_(other.egzaminas_),
        galutinisPazymys(other.galutinisPazymys),
        galutinisPazymysVid(other.galutinisPazymysVid),
        galutinisPazymysMed(other.galutinisPazymysMed) {}

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            nd_ = other.nd_;
            egzaminas_ = other.egzaminas_;
            galutinisPazymys = other.galutinisPazymys;
            galutinisPazymysVid = other.galutinisPazymysVid;
            galutinisPazymysMed = other.galutinisPazymysMed;
        }
        return *this;
    }

    ~Studentas() {
        vardas_.clear();
        pavarde_.clear();
        nd_.clear();
    }

    friend istream& operator>>(istream& in, Studentas& studentas) {
        string line;
        getline(in, line);
        if (line.empty()) return in;

        istringstream iss(line);
        iss >> studentas.vardas_;
        if (!(iss >> studentas.pavarde_)) studentas.pavarde_ = "";
        studentas.nd_.clear();

        int pazymys;
        while (iss >> pazymys) {
            studentas.nd_.push_back(pazymys);
        }

        if (!studentas.nd_.empty()) {
            studentas.egzaminas_ = studentas.nd_.back();
            studentas.nd_.pop_back();
        }
        else {
            studentas.egzaminas_ = 0;
        }

        if (studentas.nd_.empty() && studentas.egzaminas_ != 0) {
            studentas.nd_.push_back(0);
        }

        studentas.galutinisPazymysVid = studentas.rezultatai("Vid");
        studentas.galutinisPazymysMed = studentas.rezultatai("Med");

        return in;
    }

    friend ostream& operator<<(ostream& out, const Studentas& studentas) {
        out << setw(15) << left << studentas.pavarde_
            << setw(15) << left << studentas.vardas_;

        if (duomenuIvedimoBudas == 1) {
            out << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymys;
        }
        else if (duomenuIvedimoBudas == 2) {
            out << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymysVid
                << setw(10) << left << fixed << setprecision(2) << studentas.galutinisPazymysMed;
        }

        return out;
    }

    void ivestis(bool generavimas);
    friend void isvestis(const Studentas& Lok, int ivestiesPasirinkimas);
    double rezultatai(const string& pasirinkimas);
    friend bool rusiavimas(const Studentas & pavarde1, const Studentas & pavarde2);

};

template <typename Struktura>
int ivestisIsFailo(const string& failas, Struktura& struktura);
bool rusiavimas(const Studentas& pavarde1, const Studentas& pavarde2);
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);
template <typename Struktura>
void studentoKategorija1(const Struktura& struktura, int duomenuIvedimoBudas, Struktura& galvociai, Struktura& nuskriaustukai);
template <typename Struktura>
void studentoKategorija2(Struktura& struktura, int duomenuIvedimoBudas, Struktura& nuskriaustukai);
template <typename Struktura>
void studentoKategorija3(Struktura& struktura, int duomenuIvedimoBudas, Struktura& nuskriaustukai);
void studentoKategorijaVector(vector<Studentas>& struktura, int duomenuIvedimoBudas, vector<Studentas>& nuskriaustukai);
template <typename Struktura>
void isvestisIFaila(const Struktura& galvociai, const Struktura& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas, duration<double>& trukmeGalvociu, duration<double>& trukmeNuskriaustuku);
