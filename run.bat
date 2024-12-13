cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\kursiokai.txt Debug\kursiokai.txt
copy src\studentai_1000.txt Debug\studentai_1000.txt
copy src\studentai_10000.txt Debug\studentai_10000.txt
copy src\studentai_100000.txt Debug\studentai_100000.txt
copy src\studentai_1000000.txt Debug\studentai_1000000.txt
copy src\studentai_10000000.txt Debug\studentai_10000000.txt
cd Debug\
Studentu_skaiciuokle.exe
pause
