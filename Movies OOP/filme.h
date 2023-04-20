//
// Created by Daiana Guler on 29.03.2022.
//
#pragma once
#include <string>
using namespace std;
#ifndef LAB6_8_FILME_H
#define LAB6_8_FILME_H

#endif //LAB6_8_FILME_H

class Film
{
private:
    string titlu;
    string gen;
    int an;
    string actor;
public:
    Film()=default;
    string getTitlu() const;
    string getGen() const;
    int getAn() const;
    string getActor() const;
    Film(string titlu,string gen, int an, string actor): titlu{titlu},gen{gen},an{an},actor{actor}
    {

    }
    Film(const Film& ot): titlu{ot.titlu},gen{ot.gen},an{ot.an},actor{ot.actor}
    {

    }
    void setTitlu(string titlu);
    void setGen(string gen);
    void setAn(int an);
    void setActor(string actor);
};
