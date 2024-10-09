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

void ivestis(Studentas& Lok, bool generavimas);
void isvestis(Studentas Lok, int ivestiesPasirinkimas);
double rezultatai(Studentas Lok, string pasirinkimas);
int ivestisIsFailo(const string& failas, vector<Studentas>& Vec1);
bool rusiavimas(const Studentas& pavarde1, const Studentas& pavarde2);
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);
void studentoKategorija(const vector<Studentas>& Vec1, int duomenuIvedimoBudas, vector<Studentas>& galvociai, vector<Studentas>& nuskriaustukai);
void isvestisIFaila(const vector<Studentas>& galvociai, const vector<Studentas>& nuskriaustukai, int duomenuIvedimoBudas, string pazymioTipas);
