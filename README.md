# v0.3 release

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
- programos veikimo spartos analizė;
- galimybė pasirinkti konteinerį duomenims saugoti (list/vector).

## Spartos analizė:

|Parametras          |Virtual Machine (Windows 11)          |Host Machine (MacBook)           |
|--------------------|--------------------------------------|---------------------------------|
|Operacinė sistema   | Windows 11                           | macOS Sonoma 14.6.1             |
|CPU                 | 4 branduoliai (priskirti)            | 8 branduoliai                   |
|RAM                 | 8 GB                                 | 16 GB                           |
|Saugykla            | Virtualus diskas SSD                 | 512 GB SSD                      |
|VMware Version      | VMware Fusion 13                     | -                               |  
  

  
![Failų generavimo laikai](generavimas.png)

Pateiktas testavimų vidurkis:

S1 - 1 strategija,
S2 - 2 strategija,
S3 - 3 strategija.
 

|Failo eilučių  |Kriterijus                 |S1 Vector laikas |S1 List laikas  |S2 Vector laikas |S2 List laikas  |S3 Vector laikas |S3 List laikas  |
|---------------|---------------------------|-----------------|----------------|-----------------|----------------|-----------------|----------------|
|1000           |Nuskaitymas                |0.0113095 s      |0.0138963 s     |0.0128903 s      |0.0114 s        |     |    |
|               |Dalijimas į dvi grupes     |0.00056075 s     |0.000387625 s   |0.0011806 s      |0.000175 s      |     |    |
|               |Įrašymas galvociai.txt     |0.00555825 s     |0.00592483 s    |0.0058243 s      |0.0057 s        |     |    |
|               |Įrašymas nuskriaustukai.txt|0.00374054 s     |0.00366213 s    |0.0040350 s      |0.0040 s        |     |    |
|               |Bendras veikimo laikas     |0.021169 s       |0.0238708 s     |0.0239302 s      |0.0213 s        |     |    |
|10000          |Nuskaitymas                |0.10496 s        |0.125007 s      |0.115564 s       |0.1047 s        |     |    |
|               |Dalijimas į dvi grupes     |0.00449438 s     |0.00265867 s    |0.103454 s       |0.0027 s        |     |    |
|               |Įrašymas galvociai.txt     |0.0474353 s      |0.0482639 s     |0.0470380 s      |0.0511 s        |     |    |
|               |Įrašymas nuskriaustukai.txt|0.0379377 s      |0.0340268 s     |0.0360647 s      |0.0351 s        |     |    |
|               |Bendras veikimo laikas     |0.194827 s       |0.209956 s      |0.302121 s       |0.1936 s        |     |    |
|100000         |Nuskaitymas                |0.962287 s       |0.960303 s      |0.970482 s       |0.9570 s        |     |    |
|               |Dalijimas į dvi grupes     |0.0254281 s      |0.0367531 s     |10.00948 s       |0.0182 s        |     |    |
|               |Įrašymas galvociai.txt     |0.496531 s       |0.510438 s      |0.480666 s       |0.5062 s        |     |    |
|               |Įrašymas nuskriaustukai.txt|0.344024 s       |0.342789 s      |0.334662 s       |0.3516 s        |     |    |
|               |Bendras veikimo laikas     |1.82827 s        |1.85028 s       |11.7953 s        |1.8329 s        |     |    |
|1000000        |Nuskaitymas                |9.57618 s        |9.45731 s       |9.70472 s        |9.5409 s        |     |    |
|               |Dalijimas į dvi grupes     |0.498318 s       |0.396237 s      |100.0948 s       |0.3173 s        |     |    |
|               |Įrašymas galvociai.txt     |4.64819 s        |4.82819 s       |4.806655 s       |4.9353 s        |     |    |
|               |Įrašymas nuskriaustukai.txt|3.29679 s        |3.35625 s       |3.346625 s       |3.4494 s        |     |    |
|               |Bendras veikimo laikas     |18.0195 s        |18.038 s        |117.953 s        |18.2429 s       |     |    |
|10000000       |Nuskaitymas                |101.191 s        |99.2413 s       |97.0472 s        |98.9798 s       |     |    |
|               |Dalijimas į dvi grupes     |4.53757 s        |5.69798 s       |1000.948 s       |4.45889 s       |     |    |
|               |Įrašymas galvociai.txt     |46.4808 s        |48.4736 s       |48.06655 s       |49.1071 s       |     |    |
|               |Įrašymas nuskriaustukai.txt|32.7055 s        |33.2447 s       |33.46625 s       |33.9666 s       |     |    |
|               |Bendras veikimo laikas     |184.915 s        |186.658 s       |1179.53 s        |186.512 s       |     |    |  

Išvados:
- 1 strategijos atveju vector konteineriuose talpinami duomenys buvo apdorojami greičiau nei list;
- 2 strategijos atveju list konteineriuose talpinami duomenys buvo apdorojami greičiau nei vector (trynimo operacija vector kont. brangi laiko atžvilgiu);
- list konteinerių dalijimas į dvi grupes 1 strategijos atveju vyksta neženkliai lėčiau nei 2 strategijos atveju;
- vector konteinerių dalijimas į dvi grupes 1 strategijos atveju vyksta keliskart greičiau nei 2 strategijos atveju;
- 2 strategijos tobulinimas naudojant std::remove_if algoritmą leido pasiekti efektyviausią rūšiavimą abiems konteineriams (3 strategija);
- list konteineriai greičiau dalijami į dvi grupes kai dirbama su mažesniais failais;
- bendru atveju spartos skirtumas tarp vector ir list konteinerių nėra didelis.
