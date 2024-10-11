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

1000 įrašų įrašymo į failą laikas: 0.00756 s  
10000 įrašų įrašymo į failą laikas: 0.05991 s  
100000 įrašų įrašymo į failą laikas: 0.56480 s  
1000000 įrašų įrašymo į failą laikas: 5.64466 s  
10000000 įrašų įrašymo į failą laikas: 58.82430 s  
  
1000 įrašų failas:  
Failo nuskaitymo laikas:  0.01379 s  
Įrašų dalijimo į dvi grupes laikas: 0.00048 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.00705 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.00469 s  
  
10000 įrašų failas:  
Failo nuskaitymo laikas: 0.10443 s  
Įrašų dalijimo į dvi grupes laikas: 0.00383 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.04805 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.03432 s  
  
100000 įrašų failas:  
Failo nuskaitymo laikas: 0.87280 s  
Įrašų dalijimo į dvi grupes laikas: 0.03935 s  
Įrašų įrašymo į failą galvociai.txt laikas: 0.48109 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 0.33130 s  
   
1000000 įrašų failas:    
Failo nuskaitymo laikas: 8.85528 s   
Įrašų dalijimo į dvi grupes laikas: 0.38581 s  
Įrašų įrašymo į failą galvociai.txt laikas: 4.61546 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas:  3.24841 s  
  
10000000 įrašų failas:  
Failo nuskaitymo laikas:  89.4631 s  
Įrašų dalijimo į dvi grupes laikas: 5.86115 s  
Įrašų įrašymo į failą galvociai.txt laikas: 47.19767 s  
Įrašų įrašymo į failą nuskriaustukai.txt laikas: 32.88093 s  
