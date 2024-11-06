#pragma once
#include "Mylib.h"

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    double galutinisPazymys;
    double galutinisPazymysVid;
    double galutinisPazymysMed;
};

extern int rikiavimoSalyga;

void ivestis(Studentas& Lok, bool generavimas);
void isvestis(const Studentas& Lok, int ivestiesPasirinkimas);
double rezultatai(const Studentas& Lok, const string& pasirinkimas);
template <typename Struktura>
int ivestisIsFailo(const string& failas, Struktura& struktura);
bool rusiavimas(const Studentas& pavarde1, const Studentas& pavarde2);
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);
template <typename Struktura>
void studentoKategorija1(const Struktura& struktura, int duomenuIvedimoBudas, Struktura& galvociai, Struktura& nuskriaustukai);
template <typename Struktura>
void isvestisIFaila(const Struktura& galvociai, const Struktura& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas, duration<double>& trukmeGalvociu, duration<double>& trukmeNuskriaustuku);
