//
// Created by Daiana Guler on 29.03.2022.
//
#include "filme.h"
#include <iostream>
#include <string>
using namespace std;
string Film:: getTitlu() const
{
    return titlu;
}
string Film:: getGen() const
{
    return gen;
}
int Film:: getAn() const
{
    return an;
}
string Film:: getActor() const
{
    return actor;
}
void Film::setTitlu(string titluNou) {
    this->titlu=titluNou;
}
void Film::setGen(string genNou) {
    this->gen=genNou;
}
void Film::setAn(int anNou) {
    this->an=anNou;
}
void Film::setActor(string actorNou) {
    this->actor=actorNou;
}

