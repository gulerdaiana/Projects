//
// Created by Daiana Guler on 29.03.2022.
//
#pragma once
#include "filme.h"
#include "FilmeRepo.h"
#include "Undo.h"
#include <string>
#include <fstream>
#include <memory>
#include "Observer.h"
using namespace std;
#ifndef LAB6_8_FILMESERV_H
#define LAB6_8_FILMESERV_H

#endif //LAB6_8_FILMESERV_H
class FilmeServ:public Observable{
private:
    FilmeRepo& repo;
    vector<unique_ptr<ActiuneUndo>> undoActions;
public:
    FilmeServ(FilmeRepo& repo): repo{repo}
    {

    }
    FilmeServ(const FilmeServ& ot)=delete;
    void adaugare_serv(string titlu,string gen,int an,string actor);
    void modificare_serv(string titlu,string gen,int an,string actor);
    void stergere_serv(string titlu);
    Film cautare_serv(string titlu);
    vector<Film> afisare_serv();
    vector <Film> filtrare_titlu_serv(string titlu);
    vector <Film> filtrare_an_serv(int an);
    vector <Film> sortare_serv(int comanda);
    void adaugaincos_serv(string titlu);
    int cateincos_serv();
    void golirecos_serv();
    void generare_serv(int nr);
    void export_serv(string fisier);
    vector <Film> getAlldincos_serv();
    int verificare();
    void undo();
};