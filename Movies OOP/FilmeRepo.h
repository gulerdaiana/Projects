//
// Created by Daiana Guler on 29.03.2022.
//
#pragma once
#ifndef LAB6_8_FILMEREPO_H
#define LAB6_8_FILMEREPO_H

#endif //LAB6_8_FILMEREPO_H
#include <vector>
#include "filme.h"
#include<random>
#include <chrono>
using namespace std;
class RepoException
{
    string msg;
public:
    RepoException(string m):msg{msg}
    {

    }
    string getMessage()
    {
        return msg;
    }
};
class FilmeRepo
{
private:
    vector<Film> filme;
    vector<Film> filme_inchiriate;
public:
    FilmeRepo()=default;
    FilmeRepo(const FilmeRepo& ot)=delete;
    void adauga(Film &film);
    void modificare(Film f);
    void stergere(Film f);
    const Film& cauta(string titlu);
    const vector<Film> getAll();
    const vector<Film> getAlldincos();
    void adaugaincos(Film film);
    int cateincos();
    void golirecos();
    void generare(int nr);
};