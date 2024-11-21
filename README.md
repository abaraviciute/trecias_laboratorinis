## Struktūra:
- pradineVersija.cpp pagrindinis vykdomasis taškas;
- Mylib.h bibliotekų failas;
- Stud.h studentų struktūros bei funkcijų deklaracijų failas;
- Stud.cpp funkcijų failas.  

|Parametras          |Virtual Machine (Windows 11)          |Host Machine (MacBook)           |
|--------------------|--------------------------------------|---------------------------------|
|Operacinė sistema   | Windows 11                           | macOS Sonoma 14.6.1             |
|CPU                 | 4 branduoliai (priskirti)            | 8 branduoliai                   |
|RAM                 | 8 GB                                 | 16 GB                           |
|Saugykla            | Virtualus diskas SSD                 | 512 GB SSD                      |
|VMware Version      | VMware Fusion 13                     | -                               |  
 

## Diegimas ir paleidimas

1. Atsisiųsti: Include, src, CMakeLists.txt, run.bat aplankus ir failus.
2. Atsisiųstus aplankus ir failus sudėti į vieną aplanką.
3. Paleisti run.bat failą.
4. Aplanke atsiradusiame Debug aplanke randamas .exe failas Studentu_skaiciuokle.exe paruoštas naudoti.



# v0.1 release

## Sukurtos funkcijos:
- ivestis() - duomenims įvesti ranka arba generuoti atsitiktinai;
- isvestisIsFailo() - duomenims nuskaityti iš .txt failo;
- rusiavimas() - studentų pavardėms rūšiuoti abėcėlės tvarka;
- rezultatai() - galutiniam pažymiui skaičiuoti;
- isvestis() - studentų pavardei, vardui bei galutiniam pažymiui išvesti.

## Funkcionalumas:
- galima studento duomenų įvestis terminale arba .txt failo nuskaitymas;
- pasirinkimas tarp keleto galimų nuskaityti failų;
- galimybė įvesti pažymius ranka arba generuoti atsitiktinai;
- neapribotas namų darbų pažymių įvedimo skaičius;
- pranešimai apie įvesties klaidas ir galimybė įvesti paskutinį vestą rodmenį naujai (exeption handling).  

# v0.2 release

## Naujos funkcijos:
- generuotiFaila() - generuoti atsitiktinių studentų duomenų .txt failą;
- studentoKategorija() - išskiria studentus į dvi grupes pagal galutinį pažymį;
- isvestisIFaila() - į dvi grupes padalinti studentai išvedami į .txt failą.  

## Naujas funkcionalumas:
- galimybė generuoti 5 skirtingo dydžio .txt failus su atsitiktiniais studentų duomenimis;
- studentų padalijimas į dvi grupes pagal galutinį pažymį, jų išvedimas į atskirus .txt failus;
- programos veikimo spartos analizė.

## Spartos analizė:
Pateiktas testavimų vidurkis:

|Failo eilučių |Nuskaitymas |Dalijimas į dvi grupes |Įrašymas galvociai.txt |Įrašymas nuskriaustukai.txt |Bendras veikimo laikas |Įrašymas į failą |
|--------------|------------|-----------------------|-----------------------|----------------------------|-----------------------|-----------------|
|1000          |0.02131653 s|0.00059168 s           |0.00992062 s           |0.00620507 s                |0.03803327 s           |0.0183877 s      |
|10000         |0.144208 s  |0.00439836 s           |0.0588816 s            |0.04473393 s                |0.25155567 s           |0.1003 s         |
|100000        |1.36194 s   |0.03765913 s           |0.5736883 s            |0.4084937 s                 |2.38045 s              |0.8448273 s      |
|1000000       |13.5593 s   |0.4072613 s            |5.66804 s              |4.02833 s                   |23.6636 s              |8.14784 s        |
|10000000      |137.6157 s  |6.3477 s               |55.94437 s             |39.38567 s                  |239.293 s              |80.41363 s       |  




# v0.3 release

## Naujas funkcionalumas:
- galimybė pasirinkti konteinerį duomenims saugoti (list/vector).

## Spartos analizė:

Prie v1.0 release S1 Vector ir S1 List stulpeliai.

Išvados:
- vector konteineriuose talpinami duomenys buvo apdorojami greičiau nei list;
- list konteineriai greičiau dalijami į dvi grupes kai dirbama su mažesniais failais;
- bendru atveju spartos skirtumas tarp vector ir list konteinerių nėra didelis.




# v1.0 release

Studentų galutinio pažymio skaičiavimo programa.

## Naujos funkcijos:
- studentoKategorija1() - išskiria studentus į dvi grupes (du naujus konteinerius galvociai ir nuskriaustukai);
- studentoKategorija2() - išskiria studentus į dvi grupes (naują konteinerį nuskriaustukai ir studentų konteinerį be nuskriaustukų);
- studentoKategorija3() - išskiria studentus į dvi grupes (studentoKategorija2() pagreitinta std::partition algoritmu);
- studentoKategorijaVector() - išskiria studentus į dvi grupes (studentoKategorija2() pagreitinta std::partition algoritmu, skirta tik vector konteineriams).

## Naujas funkcionalumas:
- galimybė pasirinkti duomenų rūšiavimo į dvi grupes strategiją.

## Spartos analizė: 

  
![Failų generavimo laikai](generavimas.png)

Pateiktas testavimų vidurkis:

S1 - 1 strategija,
S2 - 2 strategija,
S3 - 3 strategija.
 

|Failo eilučių  |Kriterijus                 |S1 Vector laikas |S1 List laikas  |S2 Vector laikas |S2 List laikas  |S3 Vector laikas |S3 List laikas  |Fiksuoto Vector laikas|
|---------------|---------------------------|-----------------|----------------|-----------------|----------------|-----------------|----------------|----------------------|
|1000           |Nuskaitymas                |0.0113095 s      |0.0138963 s     |0.0167558 s      |0.01712995 s    |0.01120315 s     |0.0107881 s     |0.0149814 s           |
|               |Dalijimas į dvi grupes     |0.00056075 s     |0.000387625 s   |0.0004033955 s   |0.000227021 s   |0.000259104 s    |0.0003652295 s  |0.000222041 s         |
|               |Įrašymas galvociai.txt     |0.00555825 s     |0.00592483 s    |0.007075 s       |0.008406995 s   |0.005477375 s    |0.005456125 s   |0.00677679 s          |
|               |Įrašymas nuskriaustukai.txt|0.00374054 s     |0.00366213 s    |0.004650525 s    |0.00543275 s    |0.003665085 s    |0.00384277 s    |0.00511758 s          |
|               |Bendras veikimo laikas     |0.021169 s       |0.0238708 s     |0.02888475 s     |0.0311967 s     |0.0206047 s      |0.02045225 s    |0.0270978 s           |
|10000          |Nuskaitymas                |0.10496 s        |0.125007 s      |0.140005 s       |0.10597165 s    |0.1018986 s      |0.09736675 s    |0.154275 s            |
|               |Dalijimas į dvi grupes     |0.00449438 s     |0.00265867 s    |0.00214002 s     |0.002315975 s   |0.001532895 s    |0.002043 s      |0.00102333 s          |
|               |Įrašymas galvociai.txt     |0.0474353 s      |0.0482639 s     |0.0602062 s      |0.05024755 s    |0.0498332 s      |0.05652305 s    |0.0581072 s           |
|               |Įrašymas nuskriaustukai.txt|0.0379377 s      |0.0340268 s     |0.04542225 s     |0.04073535 s    |0.0382545 s      |0.03880095 s    |0.0428352 s           |
|               |Bendras veikimo laikas     |0.194827 s       |0.209956 s      |0.247773 s       |0.1992705 s     |0.1915195 s      |0.1947335 s     |0.25624 s             |
|100000         |Nuskaitymas                |0.962287 s       |0.960303 s      |1.35193 s        |0.977143 s      |0.957694 s       |0.94800 s       |1.34642 s             |
|               |Dalijimas į dvi grupes     |0.0254281 s      |0.0367531 s     |0.0208332 s      |0.03807255 s    |0.01054007 s     |0.03119035 s    |0.0108586 s           |
|               |Įrašymas galvociai.txt     |0.496531 s       |0.510438 s      |0.5936945 s      |0.5196565 s     |0.489088 s       |0.506586 s      |0.57682 s             |
|               |Įrašymas nuskriaustukai.txt|0.344024 s       |0.342789 s      |0.4169465 s      |0.360138 s      |0.344018 s       |0.3397615 s     |0.405691 s            |
|               |Bendras veikimo laikas     |1.82827 s        |1.85028 s       |2.383405 s       |1.89501 s       |1.80134 s        |1.82554 s       |2.33979 s             |
|1000000        |Nuskaitymas                |9.57618 s        |9.45731 s       |14.28015 s       |9.69733 s       |9.75898 s        |9.637725 s      |14.0048 s             |
|               |Dalijimas į dvi grupes     |0.498318 s       |0.396237 s      |0.4309075 s      |1.09168 s       |0.1412185 s      |0.4371245 s     |0.131964 s            |
|               |Įrašymas galvociai.txt     |4.64819 s        |4.82819 s       |5.72546 s        |5.000735 s      |4.78187 s        |4.85823 s       |5.65232 s             |
|               |Įrašymas nuskriaustukai.txt|3.29679 s        |3.35625 s       |4.00987 s        |3.469655 s      |3.39245 s        |3.324935 s      |3.97346 s             |
|               |Bendras veikimo laikas     |18.0195 s        |18.038 s        |24.4464 s        |19.2594 s       |18.0745 s        |18.25805 s      |23.7625 s             |
|10000000       |Nuskaitymas                |101.191 s        |99.2413 s       |147.491 s        |107.877 s       |99.15715 s       |96.1321 s       |103.119 s             |
|               |Dalijimas į dvi grupes     |4.53757 s        |5.69798 s       |7.85074 s        |17.3161 s       |1.757185 s       |5.74999 s       |4.40295 s             |
|               |Įrašymas galvociai.txt     |46.4808 s        |48.4736 s       |59.9728 s        |50.7344 s       |48.2283 s        |49.0712 s       |48.4059 s             |
|               |Įrašymas nuskriaustukai.txt|32.7055 s        |33.2447 s       |40.1789 s        |34.7553 s       |33.4136 s        |32.9665 s       |33.6266 s             |
|               |Bendras veikimo laikas     |184.915 s        |186.658 s       |255.494 s        |210.683 s       |182.556 s        |183.92 s        |189.554 s             |  

Išvados:
- 1 strategijos atveju vector konteineriuose talpinami duomenys buvo apdorojami greičiau nei list;
- 2 strategijos atveju vector konteineriuose talpinami duomenys buvo apdorojami greičiau nei list;
- list konteinerių dalijimas į dvi grupes 2 strategijos atveju vyksta lėčiau nei 1 strategijos atveju dirbant su didesniais failais;
- vector konteinerių dalijimas į dvi grupes 2 strategijos atveju vyksta lėčiau nei 1 strategijos atveju dirbant su didesniais failais;
- 2 strategijos tobulinimas naudojant std::partition algoritmą leido pasiekti efektyviausią rūšiavimą abiems konteineriams (3 strategija);
- 3 strategijos atveju konteinerių dalijimas į dvi grupes vyksta greičiau nei 2 strategijos atveju, todėl darbas 3 strategijos atveju atliekamas efektyviausiai;
- strategija, skirta tik vektorių apdorojimui, vektorių išskirsto į dvi grupes greičiau nei 3 (greičiausia) strategija, kai failai yra mažesni;
- pagal išskirstymo į grupes greitį strategijos išsidėsto: (lėčiausia) 2 strategija -> 1 strategija -> fiksuoto vector -> 3 strategija (greičiausia).  


# v1.1 release  

|Flag'as |Failo eilučių  |Kriterijus                    |S3 Vector struct  |S3 Vector class  |
|--------|---------------|------------------------------|------------------|-----------------|
|O1      |100000         |Nuskaitymas                   |1.04574 s         ||
|        |               |Dalijimas į dvi grupes        |0.01400595 s      ||
|        |               |Įrašymas į galvociai.txt      |0.4991065 s       ||
|        |               |Įrašymas į nuskriaustukai.txt |0.365311 s        ||
|        |               |Bendras veikimo laikas        |1.92416 s         ||
|        |1000000        |Nuskaitymas                   |10.02568 s        ||
|        |               |Dalijimas į dvi grupes        |0.361507 s        ||
|        |               |Įrašymas į galvociai.txt      |5.40397 s         ||
|        |               |Įrašymas į nuskriaustukai.txt |3.55322 s         ||
|        |               |Bendras veikimo laikas        |19.34435 s        ||
|O2      |100000         |Nuskaitymas                   |||
|        |               |Dalijimas į dvi grupes        |||
|        |               |Įrašymas į galvociai.txt      |||
|        |               |Įrašymas į nuskriaustukai.txt |||
|        |               |Bendras veikimo laikas        |||
|        |1000000        |Nuskaitymas                   |||
|        |               |Dalijimas į dvi grupes        |||
|        |               |Įrašymas į galvociai.txt      |||
|        |               |Įrašymas į nuskriaustukai.txt |||
|        |               |Bendras veikimo laikas        |||
|O3      |100000         |Nuskaitymas                   |||
|        |               |Dalijimas į dvi grupes        |||
|        |               |Įrašymas į galvociai.txt      |||
|        |               |Įrašymas į nuskriaustukai.txt |||
|        |               |Bendras veikimo laikas        |||
|        |1000000        |Nuskaitymas                   |||
|        |               |Dalijimas į dvi grupes        |||
|        |               |Įrašymas į galvociai.txt      |||
|        |               |Įrašymas į nuskriaustukai.txt |||
|        |               |Bendras veikimo laikas        |||  


.exe failo dydis pagal flag'ą:

|Flag'as |struct  |class  |
|--------|--------|-------|
|O1      |504 KB  ||
|O2      |||
|O3      |||  
