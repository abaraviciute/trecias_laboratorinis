#pragma once
#include "Mylib.h"

extern int rikiavimoSalyga;
extern int duomenuIvedimoBudas;

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus(const string& vardas = "", const string& pavarde = "")
        : vardas_(vardas), pavarde_(pavarde) {
    }

    virtual ~Zmogus() = default;

    string vardas() const { return vardas_; }
    string pavarde() const { return pavarde_; }

    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }

    virtual void klase() const = 0;
};

class Studentas : public Zmogus {
private:
    vector<int> nd_;
    int egzaminas_;
    double galutinisPazymys_;
    double galutinisPazymysVid_;
    double galutinisPazymysMed_;

public:


    inline vector<int> nd() const { return nd_; }
    inline int egzaminas() const { return egzaminas_; }
    inline double galutinisPazymys() const { return galutinisPazymys_; }
    inline double galutinisPazymysVid() const { return galutinisPazymysVid_; }
    inline double galutinisPazymysMed() const { return galutinisPazymysMed_; }

    inline void setNd(const vector<int>& nd) { nd_ = nd; }
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    inline void setGalutinisPazymys(double galutinisPazymys) { galutinisPazymys_ = galutinisPazymys; }
    inline void setGalutinisPazymysVid(double galutinisPazymysVid) { galutinisPazymysVid_ = galutinisPazymysVid; }
    inline void setGalutinisPazymysMed(double galutinisPazymysMed) { galutinisPazymysMed_ = galutinisPazymysMed; }

    Studentas()
        : Zmogus("", ""), egzaminas_(0),
        galutinisPazymys_(0), galutinisPazymysVid_(0), galutinisPazymysMed_(0) {}

    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egzaminas)
        : Zmogus(vardas, pavarde), nd_(nd), egzaminas_(egzaminas) {
        galutinisPazymysVid_ = rezultatai("Vid");
        galutinisPazymysMed_ = rezultatai("Med");
    }

    Studentas(const Studentas& other)
        : Zmogus(other), nd_(other.nd_), egzaminas_(other.egzaminas_),
        galutinisPazymys_(other.galutinisPazymys_),
        galutinisPazymysVid_(other.galutinisPazymysVid_),
        galutinisPazymysMed_(other.galutinisPazymysMed_) {}

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            nd_ = other.nd_;
            egzaminas_ = other.egzaminas_;
            galutinisPazymys_ = other.galutinisPazymys_; 
            galutinisPazymysVid_ = other.galutinisPazymysVid_;
            galutinisPazymysMed_ = other.galutinisPazymysMed_;
        }
        return *this;
    }

    ~Studentas() {
        nd_.clear();
        egzaminas_ = 0;
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

        studentas.galutinisPazymysVid_ = studentas.rezultatai("Vid");
        studentas.galutinisPazymysMed_ = studentas.rezultatai("Med");

        return in;
    }

    friend ostream& operator<<(ostream& out, const Studentas& studentas) {
        out << setw(15) << left << studentas.pavarde_
            << setw(15) << left << studentas.vardas_;

        if (duomenuIvedimoBudas == 1) {
            out << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymys_;
        }
        else if (duomenuIvedimoBudas == 2) {
            out << setw(20) << left << fixed << setprecision(2) << studentas.galutinisPazymysVid_
                << setw(10) << left << fixed << setprecision(2) << studentas.galutinisPazymysMed_;
        }
        else if (duomenuIvedimoBudas == 4) {
            for (const auto& nd : studentas.nd_) {
                out << nd << " ";
            }
            out << studentas.egzaminas_ << " ";
        }

        return out;
    }

    void klase() const override { cout << "Studentas klase\n"; }

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
