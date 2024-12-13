#include "pch.h"
#include <gtest/gtest.h>
#include "Stud.h"
#include "Stud.cpp"
#include <sstream>
#include <vector>

int duomenuIvedimoBudas = 4;
int rikiavimoSalyga = 1;

TEST(StudentasTest, KonstruktoriusGetteriaiSetteriai) {
    vector<int> nd = { 8, 7, 9 };
    int egzaminas = 6;

    Studentas studentas("Petras", "Petraitis", nd, egzaminas);

    EXPECT_EQ(studentas.vardas(), "Petras");
    EXPECT_EQ(studentas.pavarde(), "Petraitis");
    EXPECT_EQ(studentas.nd().size(), 3);
    EXPECT_EQ(studentas.egzaminas(), 6);

    studentas.setVardas("Jonas");
    studentas.setPavarde("Jonaitis");
    vector<int> naujiNd = { 5, 6, 7 };
    studentas.setNd(naujiNd);
    studentas.setEgzaminas(8);

    EXPECT_EQ(studentas.vardas(), "Jonas");
    EXPECT_EQ(studentas.pavarde(), "Jonaitis");
    EXPECT_EQ(studentas.nd().size(), 3);
    EXPECT_EQ(studentas.nd()[0], 5);
    EXPECT_EQ(studentas.egzaminas(), 8);
}


TEST(StudentasTest, IvestiesOperatorius) {
    string duomenys = "Petras Petraitis 8 7 9 6";
    istringstream input(duomenys);
    Studentas studentas;

    input >> studentas;

    EXPECT_EQ(studentas.vardas(), "Petras");
    EXPECT_EQ(studentas.pavarde(), "Petraitis");
    EXPECT_EQ(studentas.nd().size(), 3);
    EXPECT_EQ(studentas.egzaminas(), 6);
}

TEST(StudentasTest, GalutinisPazymys) {
    vector<int> nd = { 8, 7, 9 };
    int egzaminas = 6;

    Studentas studentas("Petras", "Petraitis", nd, egzaminas);

    double vidurkis = studentas.rezultatai("Vid");
    double mediana = studentas.rezultatai("Med");

    EXPECT_NEAR(vidurkis, 6.8, 0.01);
    EXPECT_NEAR(mediana, 6.8, 0.01);
}

TEST(StudentasTest, ObjektasBeDuomenu) {
    Studentas studentas;

    studentas.setNd({});
    studentas.setEgzaminas(0);

    EXPECT_EQ(studentas.vardas(), "");
    EXPECT_EQ(studentas.pavarde(), "");
    EXPECT_DOUBLE_EQ(studentas.rezultatai("Vid"), 0.0);
    EXPECT_DOUBLE_EQ(studentas.rezultatai("Med"), 0.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
