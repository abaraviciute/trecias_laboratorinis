# v0.2 release

Studentų galutinio pažymio skaičiavimo programa.

## Struktūra:
- pradineVersija.cpp pagrindinis vykdomasis taškas;
- Mylib.h bibliotekų failas;
- Stud.h studentų struktūros bei funkcijų deklaracijų failas;
- Stud.cpp funkcijų failas.

## Sukurtos funkcijos:
- ivestis() - duomenims įvesti ranka arba generuoti atsitiktinai;
- isvestisIsFailo() - duomenims nuskaityti iš .txt failo;
- rusiavimas() - studentų pavardėms rūšiuoti abėcėlės tvarka;
- rezultatai() - galutiniam pažymiui skaičiuoti;
- isvestis() - studentų pavardei, vardui bei galutiniam pažymiui išvesti;
- generuotiFaila() - generuoti atsitiktinių studentų duomenų .txt failą;
- studentoKategorija() - išskiria studentus į dvi grupes pagal galutinį pažymį;
- isvestisIFaila() - į dvi grupes padalinti studentai išvedami į .txt failą.

## Funkcionalumas:
- galima studento duomenų įvestis terminale arba .txt failo nuskaitymas;
- pasirinkimas tarp keleto galimų nuskaityti failų;
- galimybė įvesti pažymius ranka arba generuoti atsitiktinai;
- neapribotas namų darbų pažymių įvedimo skaičius;
- pranešimai apie įvesties klaidas ir galimybė įvesti paskutinį vestą rodmenį naujai (exception handling);
- galimybė generuoti 5 skirtingo dydžio .txt failus su atsitiktiniais studentų duomenimis;
- studentų padalijimas į dvi grupes pagal galutinį pažymį, jų išvedimas į atskirus .txt failus;
- programos veikimo spartos analizė.

## Spartos analizė:
Pateiktas testavimų vidurkis:

1000 įrašų įrašymo į failą laikas: 0.0183877 s  
10000 įrašų įrašymo į failą laikas: 0.1003 s  
100000 įrašų įrašymo į failą laikas: 0.8448273 s  
1000000 įrašų įrašymo į failą laikas: 8.14784 s  
10000000 įrašų įrašymo į failą laikas: 80.41363 s  
  
1000 įrašų failas:  
Failo nuskaitymo laikas:  0.02131653 s  
Įrašų dalijimo į dvi grupes laikas: 0.00059168 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.00992062 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.00620507 s  
Bendras testo vykdymo laikas: 0.03803327 s  
  
10000 įrašų failas:  
Failo nuskaitymo laikas: 0.144208 s  
Įrašų dalijimo į dvi grupes laikas: 0.00439836 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.0588816 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.04473393 s  
Bendras testo vykdymo laikas: 0.25155567 s  
  
100000 įrašų failas:  
Failo nuskaitymo laikas: 1.36194 s  
Įrašų dalijimo į dvi grupes laikas: 0.03765913 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.5736883 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.4084937 s  
Bendras testo vykdymo laikas: 2.38045 s  
   
1000000 įrašų failas:    
Failo nuskaitymo laikas: 13.5593 s   
Įrašų dalijimo į dvi grupes laikas: 0.4072613 s  
Įrašų įrašymo į failą galvociai.txt laikas: 5.66804 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas:  4.02833 s  
Bendras testo vykdymo laikas: 23.6636 s  
  
10000000 įrašų failas:  
Failo nuskaitymo laikas:  137.6157 s  
Įrašų dalijimo į dvi grupes laikas: 6.3477 s  
Įrašų įrašymo į failą galvociai.txt laikas: 55.94437 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 39.38567 s  
Bendras testo vykdymo laikas: 239.293 s  
