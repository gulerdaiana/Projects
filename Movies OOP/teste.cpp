//
// Created by Daiana Guler on 29.03.2022.
//
#include "teste.h"
void testFilm()
{
    Film x{"Fast and furious","Actiune",2009,"Paul Walker"};
    assert(x.getTitlu()=="Fast and furious");
    assert(x.getGen()=="Actiune");
    assert(x.getAn()==2009);
    assert(x.getActor()=="Paul Walker");
    x.setTitlu("Hangover");
    assert(x.getTitlu()=="Hangover");
    x.setGen("Comedie");
    assert(x.getGen()=="Comedie");
    x.setAn(2011);
    assert(x.getAn()==2011);
    x.setActor("Charlie Sheen");
    assert(x.getActor()=="Charlie Sheen");

}
void testAdaugare()
{
    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    assert(serv.verificare() == 1);
    const auto& filme =serv.afisare_serv();
    assert(filme.size()==1);
    assert(filme.begin()->getTitlu()=="Fast and furious");
    assert(filme.begin()->getGen()=="Actiune");
    assert(filme.begin()->getAn()==2009);
    assert(filme.begin()->getActor()=="Paul Walker");
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    const auto& filme2 =serv.afisare_serv();
    assert(filme2.size()==2);
    assert((filme2.begin()+1)->getTitlu()=="Pulp fiction");
    assert((filme2.begin()+1)->getGen()=="Comedie");
    assert((filme2.begin()+1)->getAn()==1994);
    assert((filme2.begin()+1)->getActor()=="John Travolta");
}
void testModificare()
{
    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.modificare_serv("Pulp fiction","Actiune",1996,"Bruce Willis");
    const auto & filme=serv.afisare_serv();
    assert(filme.begin()->getGen()=="Actiune");
    assert(filme.begin()->getAn()==1996);

}
void testStergere()
{
    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    serv.stergere_serv("Pulp fiction");
    const auto& filme =serv.afisare_serv();
    assert(filme.size()==1);
    assert(filme.begin()->getTitlu()=="Fast and furious");
}
void testCautare()
{
    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    Film x=serv.cautare_serv("Pulp fiction");
    assert(x.getAn()==1994);
}
void testFiltrare()
{

    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.adaugare_serv("Fast and furious","Actiune",2015,"Paul Walker");
    serv.adaugare_serv("Avatar","SF",2009,"Zoe Saldana");
    vector <Film> lista_filtrata=serv.filtrare_titlu_serv("Fast and furious");
    assert(lista_filtrata.size()==2);
    assert(lista_filtrata.begin()->getAn()==2009);

    vector <Film> lista_filtrata_an=serv.filtrare_an_serv(2009);
    assert(lista_filtrata_an.size()==2);
    assert(lista_filtrata_an.begin()->getGen()=="Actiune");
}
void testSortare()
{

    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Fast and furious","Actiune",2015,"Paul Walker");
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.adaugare_serv("Avatar","SF",2009,"Zoe Saldana");
    vector <Film> lista_sortata_titlu=serv.sortare_serv(1);
    assert(lista_sortata_titlu.begin()->getTitlu()=="Avatar");
    assert(lista_sortata_titlu.size()==4);
    assert(lista_sortata_titlu[3].getAn()==1994);

    vector <Film> lista_sortata_actor=serv.sortare_serv(2);
    assert(lista_sortata_actor.begin()->getAn()==1994);
    assert(lista_sortata_actor[1].getGen()=="Actiune");

    vector <Film> lista_sortata_an_gen=serv.sortare_serv(3);
    assert(lista_sortata_an_gen.begin()->getAn()==1994);
    assert(lista_sortata_an_gen[2].getGen()=="SF");

}
void testeCos() {

    FilmeRepo repo;
    FilmeServ serv{repo};
    serv.adaugare_serv("Fast and furious","Actiune",2009,"Paul Walker");
    serv.adaugare_serv("Pulp fiction","Comedie",1994,"John Travolta");
    serv.adaugare_serv("Avatar","SF",2009,"Zoe Saldana");
    serv.adaugaincos_serv("Avatar");
    const auto& lista = serv.getAlldincos_serv();
    assert(lista.size() == 1);
    assert(lista.begin()->getAn() == 2009);
    serv.golirecos_serv();
    const auto& lista2 = serv.getAlldincos_serv();
    assert(lista2.size() == 0);
    serv.generare_serv(2);
    const auto& lista3 = serv.getAlldincos_serv();
    assert(serv.cateincos_serv() == 2);
    assert(lista3[0].getTitlu() != lista3[1].getTitlu());
    //serv.export_serv("filme");
}
void testUndo() {
    FilmeRepo F;
    FilmeServ serv{ F };
    serv.adaugare_serv("Fast and furious", "Actiune", 2009, "Paul Walker");
    serv.adaugare_serv("Pulp fiction", "Comedie", 1994, "John Travolta");
    serv.adaugare_serv("Avatar", "SF", 2009, "Zoe Saldana");
    serv.undo();
    const auto& lista = serv.afisare_serv();
    assert(lista.size() == 2);
    assert(lista[0].getTitlu() == "Fast and furious" && lista[1].getAn() == 1994);
    serv.stergere_serv("Fast and furious");
    serv.undo();
    const auto& lista2 = serv.afisare_serv();
    assert(lista2.size() == 2);
    assert(lista2[1].getAn() == 2009 && lista2[0].getAn() == 1994);
    serv.modificare_serv("Pulp fiction", "Actiune", 1998, "John Travolta");
    serv.undo();
    const auto& lista3 = serv.afisare_serv();
    assert(lista3[0].getAn() == 1994);
    serv.undo();
    serv.undo();
    serv.undo();

}
void testAll()
{
    testFilm();
    testAdaugare();
    testModificare();
    testStergere();
    testCautare();
    testFiltrare();
    testSortare();
    testeCos();
    testUndo();
}
