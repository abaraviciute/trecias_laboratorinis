/**
 * @file
 * @brief Header failas su apibrėžtomis Zmogus ir Studentas klasėmis bei funkcijų deklaracijomis.
 *
 * Faile implementuotas "Mylib.h" bibliotekų failas, apibrėžti globalieji kintamieji, abstrakti klasė Zmogus ir jos išvestinė klasė Studentas.
 * Taip pat yra funckijų deklaracija.
 */
#pragma once
#include "Mylib.h"

/**
* @brief Rikiavimo sąlyga.
*
* Kintamasis naudojamas nustatyti, kokia tvarka bus rikiuojami išvadami duomenys (pagal galutinį pažymį): didėjančia ar mažėjančia.
*/
extern int rikiavimoSalyga;

/**
* @brief Duomenų įvedimo būdas.
*
* Kintamasis naudojamas nustatyti, kokiu būdu bus įvesti duomenys ar kaip jais bus manipuliuojama:
* Įvestis ranka, nuskaitymas iš failo, failų generavimas, Rule of Three demonstracija.
*/
extern int duomenuIvedimoBudas;

/**
* @class Zmogus
* @brief Abstrakti klasė žmogui aprašyti.
*/
class Zmogus {
protected:
    string vardas_; ///< Žmogaus vardas
    string pavarde_; ///< Žmogaus pavardė

public:
    /**
    * @brief Konstruktorius su numatytomis parametrų reikšmėmis.
    * @param vardas Tuščias string.
    * @param pavarde Tuščias string.
    */
    Zmogus(const string& vardas = "", const string& pavarde = "")
        : vardas_(vardas), pavarde_(pavarde) {
    }

    /// Virtualus destruktorius.
    virtual ~Zmogus() = default;

    /**
    * @brief Žmogaus vardo Getter'is.
    * @return Grąžina string tipo žmogaus vardą.
    */
    string vardas() const { return vardas_; }

    /**
    * @brief Žmogaus pavardės Getter'is.
    * @return Grąžina string tipo žmogaus pavardę.
    */
    string pavarde() const { return pavarde_; }

    /**
    * @brief Žmogaus vardo Setter'is.
    * @param vardas Naujas nustatytas žmogaus vardas.
    */
    void setVardas(const string& vardas) { vardas_ = vardas; }

    /**
    * @brief Žmogaus pavardės Setter'is.
    * @param pavarde Nauja nustatyta žmogaus pavardė.
    */
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }

    /**
    * @brief Abstrakti funkcija, skirta klasei identifikuoti.
    *
    * Funkcija turi būti realizuota išvestinėse klasėse objekto klasės tipui nustatyti.
    */
    virtual void klase() const = 0;
};

/**
* @class Studentas
* @brief Išvestinė klasė iš klasės Zmogus studentui aprašyti.
* 
* Implementuota trijų metodų taisyklė (Rule of Three).
* Apibrėžti įvesties/išvesties operatoriai.
*/
class Studentas : public Zmogus {
private:
    vector<int> nd_; ///< Namų darbų įvertinimai (1-10)
    int egzaminas_; ///< Egzamino įvertinimas (1-10)
    double galutinisPazymys_; ///< Galutinis pažymys duomenų įvesties ranka atveju (pagal vidurkį arba medianą)
    double galutinisPazymysVid_; ///< Galutinis pažymys pagal vidurkį
    double galutinisPazymysMed_; ///< Galutinis pažymys pagal medianą

public:

    /**
    * @brief Studento namų darbų įvertinimų Getter'is.
    * @return Grąžina vector tipo namų darbų konteinerį.
    */
    inline vector<int> nd() const { return nd_; }

    /**
    * @brief Studento egzamino įvertinimo Getter'is.
    * @return Grąžina int tipo egzamino įvertinimą.
    */
    inline int egzaminas() const { return egzaminas_; }

    /**
    * @brief Studento galutinio pažymio Getter'is.
    * @return Grąžina double tipo galutinį pažymį.
    */
    inline double galutinisPazymys() const { return galutinisPazymys_; }

    /**
    * @brief Studento galutinio pažymio pagal vidurkį Getter'is.
    * @return Grąžina double tipo galutinį pažymį pagal vidurkį.
    */
    inline double galutinisPazymysVid() const { return galutinisPazymysVid_; }

    /**
    * @brief Studento galutinio pažymio pagal medianą Getter'is.
    * @return Grąžina double tipo galutinį pažymį pagal medianą.
    */
    inline double galutinisPazymysMed() const { return galutinisPazymysMed_; }


    /**
    * @brief Studento namų darbų įvertinimo Setter'is.
    * @param egzaminas Nauji įvesti namų darbų įvertinimai.
    */
    inline void setNd(const vector<int>& nd) { nd_ = nd; }

    /**
    * @brief Studento egzamino įvertinimo Setter'is.
    * @param egzaminas Naujas įvestas egzamino įvertinimas.
    */
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }

    /**
    * @brief Studento galutinio pažymio Setter'is.
    * @param galutinisPazymys Naujas apskaičiuotas galutinis pažymys.
    */
    inline void setGalutinisPazymys(double galutinisPazymys) { galutinisPazymys_ = galutinisPazymys; }

    /**
    * @brief Studento galutinio pažymio pagal vidurkį Setter'is.
    * @param galutinisPazymysVid Naujas apskaičiuotas galutinis pažymys pagal vidurkį.
    */
    inline void setGalutinisPazymysVid(double galutinisPazymysVid) { galutinisPazymysVid_ = galutinisPazymysVid; }

    /**
    * @brief Studento galutinio pažymio pagal medianą Setter'is.
    * @param galutinisPazymysMed Naujas apskaičiuotas galutinis pažymys pagal medianą.
    */
    inline void setGalutinisPazymysMed(double galutinisPazymysMed) { galutinisPazymysMed_ = galutinisPazymysMed; }


    /**
    * @brief Konstruktorius su numatytomis parametrų reikšmėmis.
    * @param vardas Tuščia eilutė (atributas paveldimas iš tėvinės klasės Zmogus).
    * @param pavarde Tuščia eilutė (atributas paveldimas iš tėvinės klasės Zmogus).
    * @param egzaminas Reikšmė 0.
    * @param galutinisPazymys Reikšmė 0.
    * @param galutinisPazymysVid Reikšmė 0.
    * @param galutinisPazymysMed Reikšmė 0.
    */
    Studentas()
        : Zmogus("", ""), egzaminas_(0),
        galutinisPazymys_(0), galutinisPazymysVid_(0), galutinisPazymysMed_(0) {}

    /**
     * @brief Konstruktorius su parametrais, kuris inicializuoja Studentas objektą su pateiktais duomenimis.
     * @param vardas Žmogaus vardas string tipo.
     * @param pavarde Žmogaus pavardė string tipo.
     * @param nd Namų darbų įvertinimai vector tipo konteineryje.
     * @param egzaminas Egzamino įvertinimas int tipo.
     */
    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egzaminas)
        : Zmogus(vardas, pavarde), nd_(nd), egzaminas_(egzaminas) {
        galutinisPazymysVid_ = rezultatai("Vid");
        galutinisPazymysMed_ = rezultatai("Med");
    }


    /**
     * @brief Kopijavimo konstruktorius, kuris sukuria kito Studentas objekto kopiją.
     * @param other Klasės Studentas objektas, kurio duomenys bus nukopijuoti.
     */
    Studentas(const Studentas& other)
        : Zmogus(other), nd_(other.nd_), egzaminas_(other.egzaminas_),
        galutinisPazymys_(other.galutinisPazymys_),
        galutinisPazymysVid_(other.galutinisPazymysVid_),
        galutinisPazymysMed_(other.galutinisPazymysMed_) {}


    /**
     * @brief Priskyrimo operatorius, kuris priskiria vieną Studentas objektą kitam.
     * @param other Klasės Studentas objektas, kurio reikšmės bus priskirtos šiam objektui.
     * @return Studentas& Grąžina nuorodą į objektą.
     */
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

    /// Destruktorius
    ~Studentas() {
        nd_.clear();
        egzaminas_ = 0;
    }


    /**
     * @brief Įvesties operatorius, skirtas klasės Studentas objekto duomenims nuskaityti.
     *
     * Operatorius nuskaitymo metu apdoroja studento vardą, pavardę, namų darbų įvertinimus
     * ir egzamino įvertinimą. Taip pat nustato galutinius pažymius.
     *
     * @param in Įvedimo srautas, iš kurio bus nuskaityti duomenys.
     * @param studentas Klasės Studentas objekto nuoroda, kur bus įrašyti duomenys.
     * @return Grąžina įvesties srautą.
     */
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


    /**
     * @brief Išvesties operatorius, skirtas klasės Studentas objekto duomenims išvesti.
     * 
     * Duomenys išvedami į ekraną arba į .txt failus.
     *
     * @param out Išvesties srautas, kuriuo bus atspausdinta studento informacija.
     * @param studentas Studentas, kurio duomenys bus išvedami.
     * @return Grąžina išvesties srautą.
     */
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


    /**
     * @brief Išveda informaciją apie klasę, kuriai priklauso objektas.
     *
     * Funkcija išveda tekstą, kad objektas priklauso "Studentas" klasei.
     */
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
