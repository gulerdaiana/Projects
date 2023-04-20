//
// Created by Daiana Guler on 29.03.2022.
//

#include "FilmeServ.h"
#include "FilmeRepo.h"
#include "Undo.h"
#include <string>
#define COMPARATOR(code) [](auto && l, auto && r) -> bool { return code ; }
#include <algorithm>
using namespace std;
void FilmeServ::adaugare_serv(string titlu,string gen,int an,string actor)
{
    Film f{titlu,gen,an,actor};
    repo.adauga(f);
    undoActions.push_back(make_unique<UndoAdauga>(repo, f));
}
void FilmeServ:: modificare_serv(string titlu,string gen,int an,string actor)
{
    Film f{titlu,gen,an,actor};
    undoActions.push_back(make_unique<UndoModifica>(repo, cautare_serv(titlu)));
    repo.modificare(f);
}
void FilmeServ::stergere_serv(string titlu)
{   
    Film f = cautare_serv(titlu);
    repo.stergere(f);
    undoActions.push_back(make_unique<UndoSterge>(repo, f));
}
Film FilmeServ::cautare_serv(string titlu) {
    return repo.cauta(titlu);
}
vector<Film> FilmeServ:: afisare_serv()
{
    return repo.getAll();
}
vector <Film> FilmeServ:: filtrare_titlu_serv(string titlu)
{
    vector <Film> lista = repo.getAll();
    vector <Film> lista_filtrata(lista.size());
    copy_if(lista.begin(), lista.end(), lista_filtrata.begin(), [&](Film x) { return (x.getTitlu() == titlu); });
    for (auto i : lista_filtrata)
        if (i.getTitlu() != titlu)
            lista_filtrata.pop_back();
    return lista_filtrata;
}
vector <Film> FilmeServ::filtrare_an_serv(int an)
{
    
    vector <Film> lista =repo.getAll();
    vector <Film> lista_filtrata(lista.size());
    copy_if(lista.begin(), lista.end(), lista_filtrata.begin(), [&](Film x) { return (x.getAn() == an); });
    for (auto i : lista_filtrata)
        if (i.getAn() != an)
            lista_filtrata.pop_back();
    return lista_filtrata;
}
vector <Film> FilmeServ:: sortare_serv(int comanda)
{
    vector<Film> lista = repo.getAll();
    if(comanda==1)
        sort(lista.begin(), lista.end(), COMPARATOR(l.getTitlu() < r.getTitlu()));
    if (comanda == 2)
        sort(lista.begin(), lista.end(), COMPARATOR(l.getActor() < r.getActor()));
    if (comanda == 3)
        sort(lista.begin(), lista.end(), COMPARATOR(l.getAn() == r.getAn() ? l.getGen() < r.getGen() : l.getAn() < r.getAn()));
    return lista;
}
int FilmeServ::verificare() {
    vector<Film> v = repo.getAll();
    return all_of(v.cbegin(), v.cend(), [&](Film i) { return i.getAn() >= 2000; });
}
//cos
vector <Film> FilmeServ::getAlldincos_serv() {
    return repo.getAlldincos();
}

void FilmeServ::adaugaincos_serv(string titlu)
{
    repo.adaugaincos(repo.cauta(titlu));
    notify();
}

int FilmeServ:: cateincos_serv()
{
    return repo.cateincos();
}
void FilmeServ:: golirecos_serv()
{
    repo.golirecos();
    notify();
}
void FilmeServ::generare_serv(int nr) {
    repo.generare(nr);
    notify();
}
void FilmeServ::export_serv(string fisier) {
    ofstream fout(fisier + ".csv");
    vector<Film> cos = repo.getAlldincos();
    for (auto film : cos) {
        fout << film.getTitlu() << "," << film.getGen() << "," << film.getAn() << "," << film.getActor() << "\n";
    }
}
void FilmeServ::undo() {
    if (undoActions.empty())
        return;

    undoActions.back()->doUndo();
    undoActions.pop_back();
}
