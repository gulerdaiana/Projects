//
// Created by Daiana Guler on 29.03.2022.
//

#include "FilmeRepo.h"
#include<iostream>
using namespace std;

void FilmeRepo::adauga(Film &film)
{
    filme.push_back(film);
}
const vector<Film> FilmeRepo::getAll()
{
    return filme;
}
const vector<Film> FilmeRepo::getAlldincos()
{
    return filme_inchiriate;
}
void FilmeRepo::modificare(Film f) {
    for (auto &i: filme)
        if(i.getTitlu()==f.getTitlu()) {
            i.setGen(f.getGen());
            i.setAn(f.getAn());
            i.setActor(f.getActor());
        }
}
void FilmeRepo::stergere(Film f) {
    for (size_t i=0;i<filme.size();i++)
        if(filme[i].getTitlu()==f.getTitlu())
        {
            filme.erase(filme.begin()+i);
        }
}
const Film& FilmeRepo:: cauta(string titlu)
{
    return *find_if(filme.begin(), filme.end(), [&](Film x) { return (x.getTitlu() == titlu); });
}
int FilmeRepo:: cateincos()
{
    return filme_inchiriate.size();
}
void FilmeRepo::adaugaincos(Film film)
{
    filme_inchiriate.push_back(film);
}
void FilmeRepo:: golirecos()
{
    filme_inchiriate.clear();
}
void FilmeRepo:: generare(int nr)
{
    filme_inchiriate = filme;
    auto seed = (int)chrono::system_clock::now().time_since_epoch().count();
    shuffle(filme_inchiriate.begin(), filme_inchiriate.end(), default_random_engine(seed));
    for (size_t i = nr; i < filme.size(); i++) {
        filme_inchiriate.pop_back();
    }
    /*for (auto i : filme_inchiriate) {
        cout << i.getTitlu()<<" "<<i.getGen()<<" "<<i.getAn()<<" "<<i.getActor()<<"\n";
    }*/
}