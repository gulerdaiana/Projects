//
// Created by Daiana Guler on 29.03.2022.
//
/*#include "Console.h"
#include<iostream>
#include <string>
#include "FilmeServ.h"
#include "FilmeRepo.h"
#include "filme.h"
using namespace std;
void meniu()
{
    cout<<"0.Iesire\n";
    cout<<"1.Adaugare\n";
    cout<<"2.Modificare\n";
    cout<<"3.Stergere\n";
    cout<<"4.Afisare\n";
    cout<<"5.Cauta film\n";
    cout<<"6.Filtrare\n";
    cout<<"7.Sortare\n";
    cout<<"8.Adauga in cos\n";
    cout<<"9.Sterge toate filmele din cos\n";
    cout<<"10.Genereaza filme random \n";
    cout<<"11.Export in fisier \n";
    cout << "12.Verificare daca filmele sunt din sec21\n";
    cout << "13.Undo\n";
    cout<<"Dati comanda: ";
}
void UI::afisareFilm(const Film& x)
{
    cout<<x.getTitlu()<<" "<<x.getGen()<<" "<<x.getAn()<<" "<<x.getActor()<<endl;
}
void UI::adaugareUI()
{
    string titlu,gen,actor;
    int an;
    cout<<"Titlul filmului: ";
    cin.get();
    getline(cin,titlu);
    cout<<"Genul filmului: ";
    getline(cin,gen);
    cout<<"Anul aparitiei: ";
    cin>>an;
    cout<<"Actorul principal: ";
    cin.get();
    getline(cin,actor);
    serv.adaugare_serv(titlu,gen,an,actor);
}
void UI::modificareUI()
{
    string titlu,gen,actor;
    int an;
    cout<<"Tilul filmului: ";
    cin.get();
    getline(cin,titlu);
    cout<<"Genul filmului: ";
    getline(cin,gen);
    cout<<"Anul aparitiei: ";
    cin>>an;
    cout<<"Actorul principal: ";
    cin.get();
    getline(cin,actor);
    serv.modificare_serv(titlu,gen,an,actor);
}
void UI::stergereUI()
{
    string titlu;
    cout<<"Titlul pentru stergere: ";
    cin.get();
    getline(cin,titlu);
    serv.stergere_serv(titlu);
}
void UI::cautareUI()
{
    string titlu;
    cout<<"Titlul filmului cautat: ";
    cin.get();
    getline(cin,titlu);
    Film x=serv.cautare_serv(titlu);
    afisareFilm(x);
}
void UI:: afisareUI()
{
    vector <Film> f=serv.afisare_serv();
    for(auto i:f)
        afisareFilm(i);
    cout<<endl;
}
void UI::filtrareUI()
{
    int comanda,an;
    string titlu;
    cout<<"Filtrare dupa: 1.Titlu.       2.Anul aparitiei.\nDati comanda pentru filtrare: ";
    cin>>comanda;
    if(comanda==1)
    {
        cout<<"Titlu pentru filtrare: ";
        cin.get();
        getline(cin,titlu);
        vector <Film> lista_filtrata=serv.filtrare_titlu_serv(titlu);
        for(auto i: lista_filtrata)
            afisareFilm(i);
    }
    if(comanda==2) {
        cout<<"An pentru filtrare: ";
        cin >> an;
        vector<Film> lista_filtrata = serv.filtrare_an_serv(an);
        for (auto i: lista_filtrata)
            afisareFilm(i);
    }
}
void UI::sortareUI() {
    int comanda;
    cout<<"Sortare dupa: 1.Titlu.    2.Actor.   3.Anul aparitiei si gen.\nDati comanda: ";
    cin>>comanda;
    vector <Film> lista_sortata=serv.sortare_serv(comanda);
    for(auto i: lista_sortata)
        afisareFilm(i);
}
//cos
void UI:: adaugaincosUI()
{
    string titlu;
    cout<<"Titlul filmului: ";
    cin.get();
    getline(cin,titlu);
    serv.adaugaincos_serv(titlu);

}
void UI:: cateincosUI()
{
    cout<<"Numarul filmelor din cos: ";
    cout<<serv.cateincos_serv()<<endl;
}
void UI:: golirecosUI()
{
    serv.golirecos_serv();
}
void UI::generareUI()
{
    int nr;
    cout<<"Dati numarul de filme generate random: ";
    cin>>nr;
    serv.generare_serv(nr);
}
void UI::exportUI() {
    string fisier;
    cout<<"Numele fisierului pentru export: ";
    cin>>fisier;
    serv.export_serv(fisier);
}
void UI:: startUI()
{
    while(1)
    {
        meniu();
        int cmd=0;
        cin>>cmd;
        if(cmd==0)
            break;
        if(cmd==1)
            adaugareUI();
        if(cmd==2)
            modificareUI();
        if(cmd==3)
            stergereUI();
        if(cmd==4)
            afisareUI();
        if(cmd==5)
            cautareUI();
        if(cmd==6)
            filtrareUI();
        if(cmd==7)
            sortareUI();
        if(cmd==8) {
            adaugaincosUI();
            cateincosUI();
        }
        if(cmd==9)
        {
            golirecosUI();
            cateincosUI();
        }
        if(cmd==10)
        {
            generareUI();
            cateincosUI();
        }
        if(cmd==11)
        {
            exportUI();
            cateincosUI();
        }
        if (cmd == 12) {
            int ok = serv.verificare();
            if (ok)
                cout << "Da\n";
            else
                cout << "Nu\n";
        }
        if (cmd == 13) {
            serv.undo();
        }
    }
}*/

#include "Console.h"
void GUI::initializeGUIComponents() {


    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    editTitlu = new QLineEdit;
    editGen = new QLineEdit;
    editAn = new QLineEdit;
    editActor = new QLineEdit;

    lyForm->addRow(lblTitlu, editTitlu);
    lyForm->addRow(lblGen, editGen);
    lyForm->addRow(lblAn, editAn);
    lyForm->addRow(lblActor, editActor);
    btnAddFilm = new QPushButton("Adauga film");
    lyForm->addWidget(btnAddFilm);
    btnModificare = new QPushButton("Modifica film");
    lyForm->addWidget(btnModificare);

    lyLeft->addWidget(form);

    QWidget* formStergere = new QWidget;
    QFormLayout* lyFormStergere = new QFormLayout;
    formStergere->setLayout(lyFormStergere);
    editStergere = new QLineEdit();
    btnStergere = new QPushButton("Sterge film");
    lyFormStergere->addRow(lblStergere, editStergere);
    lyFormStergere->addWidget(btnStergere);
    lyLeft->addWidget(formStergere);

    QVBoxLayout* lyRadioBox = new QVBoxLayout;
    this->groupBox->setLayout(lyRadioBox);
    lyRadioBox->addWidget(radioSrtTitlu);
    lyRadioBox->addWidget(radioSrtActor);
    lyRadioBox->addWidget(radioSrtGenAn);

    btnSortFilme = new QPushButton("Sorteaza filme");
    lyRadioBox->addWidget(btnSortFilme);

    lyLeft->addWidget(groupBox);

    QWidget* formFilter = new QWidget;
    QFormLayout* lyFormFilter = new QFormLayout;
    formFilter->setLayout(lyFormFilter);
    editFilterTitlu = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteria, editFilterTitlu);
    btnFilterFilme = new QPushButton("Filtreaza locatari dupa titlu");
    lyFormFilter->addWidget(btnFilterFilme);
    lyLeft->addWidget(formFilter);

    QWidget* formFilter2 = new QWidget;
    QFormLayout* lyFormFilter2 = new QFormLayout;
    formFilter2->setLayout(lyFormFilter2);
    editFilterAn = new QLineEdit();
    lyFormFilter2->addRow(lblFilterCriteria2, editFilterAn);
    btnFilterFilme2 = new QPushButton("Filtreaza filme dupa an");
    lyFormFilter2->addWidget(btnFilterFilme2);
    lyLeft->addWidget(formFilter2);

    btnUndo = new QPushButton("Undo");
    lyLeft->addWidget(btnUndo);

    btnReloadData = new QPushButton("Reload data");
    lyLeft->addWidget(btnReloadData);



    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);


    int noLines = 10;
    int noColumns = 4;
    this->tableFilme = new QTableWidget{ noLines, noColumns };

    QStringList tblHeaderList;
    tblHeaderList << "Titlu" << "Gen" << "An" << "Actor";
    this->tableFilme->setHorizontalHeaderLabels(tblHeaderList);

    this->tableFilme->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    lyRight->addWidget(tableFilme);

    QWidget* cos = new QWidget;
    QVBoxLayout* lyCos = new QVBoxLayout;
    cos->setLayout(lyCos);

    QWidget* formFilmInchiriat = new QWidget;
    QFormLayout* lyFormFilmInchiriat = new QFormLayout;
    formFilmInchiriat->setLayout(lyFormFilmInchiriat);
    editFilmInchiriat = new QLineEdit();
    lyFormFilmInchiriat->addRow(lblAddInchiriate, editFilmInchiriat);
    btnAddInchiriate = new QPushButton("Adauga film in cos");
    lyFormFilmInchiriat->addWidget(btnAddInchiriate);
    lyCos->addWidget(formFilmInchiriat);

    QWidget* formGen = new QWidget;
    QFormLayout* lyFormGen = new QFormLayout;
    formGen->setLayout(lyFormGen);
    editGenerare = new QLineEdit();
    lyFormGen->addRow(lblGenerare, editGenerare);
    btnGenerare = new QPushButton("Generare filme random");
    lyFormGen->addWidget(btnGenerare);
    lyCos->addWidget(formGen);



    QWidget* formExp = new QWidget;
    QFormLayout* lyFormExp = new QFormLayout;
    formExp->setLayout(lyFormExp);
    editExp = new QLineEdit();
    lyFormExp->addRow(lblExp, editExp);
    btnExp = new QPushButton("Export lista");
    lyFormExp->addWidget(btnExp);
    lyCos->addWidget(formExp);
    filme_inchiriate= new QListWidget{};
    //this->filme_inchiriate = new QListWidget{ noLines};
    /*this->filme_inchiriate->setHorizontalHeaderLabels(tblHeaderList);

    this->filme_inchiriate->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    reloadCosList(this->srv.getAlldincos_serv());
    lyCos->addWidget(filme_inchiriate);*/
    filme_inchiriate->setFixedWidth(320);
    filme_inchiriate->setSelectionMode(QAbstractItemView::SingleSelection);
    lyCos->addWidget(filme_inchiriate);

    btnGolireCos = new QPushButton("Golire lista");
    btnCosView=new QPushButton("Cos View");
    btnCos=new QPushButton("Cos");

    widgetDynamic = new QWidget{};
    lyBtnDynamic = new QVBoxLayout{};
    widgetDynamic->setLayout(lyBtnDynamic);
    reloadDynamicButtons();

    //wndCos= new QWidget;
    //meniu = new QPushButton("Meniu cos");
    //wndCos->setLayout(lyLeft);

    //lyMain->addWidget(meniu);
    lyCos->addWidget(btnGolireCos);
    lyCos->addWidget(btnCos);
    lyCos->addWidget(btnCosView);
    wndCos= new QWidget;
    meniu = new QPushButton("Meniu cos");
    wndCos->setLayout(lyCos);
    lyMain->addWidget(meniu);
    lyMain->addWidget(left);
    lyMain->addWidget(right);
    lyMain->addWidget(widgetDynamic);
    lyMain->addWidget(cos);


    model=new MyTableModel(srv.afisare_serv());
    tblView = new QTableView;
    tblView->setModel(model);
    lyRight->addWidget(tblView);
}



set<string> GUI::getFilme(const vector<Film>& all_filme) {
    set<string> filme;

    for (const auto& loc : all_filme) {
        filme.insert(loc.getGen());
    }
    return filme;
}

void clearLayout(QLayout* layout) {
    if (layout == NULL)
        return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

int howManyWithGen(const vector<Film>& all_filme, string gen) {
    int noFilm = count_if(all_filme.begin(), all_filme.end(), [&](Film film) {
        return film.getGen() == gen;
    });
    return noFilm;
}

void GUI::reloadDynamicButtons() {
    clearLayout(this->lyBtnDynamic);
    const vector<Film>& all_filme = this->srv.afisare_serv();
    set<string> genuri = this->getFilme(all_filme);

    for (string gen : genuri) {
        QPushButton* btn = new QPushButton{ QString::fromStdString(gen) };
        lyBtnDynamic->addWidget(btn);
        int howMany = howManyWithGen(all_filme, gen);
        QObject::connect(btn, &QPushButton::clicked, [gen, howMany]() {
            QMessageBox::information(nullptr, "Info", QString::fromStdString("Filme cu genul " + gen + " : " + to_string(howMany)));
        });
    }
}

void GUI::reloadFilmList(vector<Film> filme) {
    this->tableFilme->clearContents();
    this->tableFilme->setRowCount(filme.size());

    int lineNumber = 0;
    for (auto& film : filme) {
        this->tableFilme->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(film.getTitlu())));
        this->tableFilme->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(film.getGen())));
        this->tableFilme->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(film.getAn())));
        this->tableFilme->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(film.getActor())));
        lineNumber++;
    }
    model->setFilme(filme);
}

void GUI::connectSignalsSlots() {
    QObject::connect(btnAddFilm, &QPushButton::clicked, this, &GUI::guiAddFilm);
    QObject::connect(btnStergere, &QPushButton::clicked, this, &GUI::guiStergere);
    QObject::connect(btnModificare, &QPushButton::clicked, this, &GUI::guiModificare);
    QObject::connect(btnSortFilme, &QPushButton::clicked, [&]() {
        if (this->radioSrtTitlu->isChecked())
            this->reloadFilmList(srv.sortare_serv(1));
        else if (this->radioSrtActor->isChecked())
            this->reloadFilmList(srv.sortare_serv(2));
        else if (this->radioSrtGenAn->isChecked())
            this->reloadFilmList(srv.sortare_serv(3));
    });

    QObject::connect(btnFilterFilme, &QPushButton::clicked, [&]() {
        string filterC = this->editFilterTitlu->text().toStdString();
        this->reloadFilmList(srv.filtrare_titlu_serv(filterC));
    });

    QObject::connect(btnFilterFilme2, &QPushButton::clicked, [&]() {
        int filterC2 = this->editFilterAn->text().toInt();
        this->reloadFilmList(srv.filtrare_an_serv(filterC2));
    });

    QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
        this->reloadFilmList(srv.afisare_serv());
    });
    QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
        srv.undo();
        this->reloadFilmList(srv.afisare_serv());
        this->reloadDynamicButtons();
    });
    QObject::connect(meniu, &QPushButton::clicked, [this] {

        wndCos->show();
    });
    QObject::connect(btnAddInchiriate, &QPushButton::clicked, this, &GUI::guiAddInchiriate);
    QObject::connect(btnGenerare, &QPushButton::clicked, this, &GUI::guiGenerare);
    QObject::connect(btnGolireCos, &QPushButton::clicked, [&]() {
        srv.golirecos_serv();
        this->reloadCosList(srv.getAlldincos_serv());
    });
    QObject::connect(btnExp, &QPushButton::clicked, [&]() {
        string fisier = editExp->text().toStdString();
        srv.export_serv(fisier);
    });

    QObject::connect(btnCosView,&QPushButton::clicked, [&](){
        cosGuiViewOnly.show();
    });

}

void GUI::guiAddFilm() {
    try {
        string titlu = editTitlu->text().toStdString();
        string gen = editGen->text().toStdString();
        int an = editAn->text().toInt();
        string actor = editActor->text().toStdString();

        editTitlu->clear();
        editGen->clear();
        editAn->clear();
        editActor->clear();

        this->srv.adaugare_serv(titlu, gen, an, actor);
        this->reloadFilmList(this->srv.afisare_serv());
        this->reloadDynamicButtons();

    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMessage()));
    }
}

void GUI::guiStergere(){
    string titlu = editStergere->text().toStdString();
    //optional - golim QLineEdit-urile dupa apasarea butonului
    editStergere->clear();

    this->srv.stergere_serv(titlu);
    this->reloadFilmList(this->srv.afisare_serv());
    this->reloadDynamicButtons();
}

void GUI::guiModificare(){
    try {
        //preluare detalii din QLineEdit-uri
        string titlu = editTitlu->text().toStdString();
        string gen = editGen->text().toStdString();
        int an = editAn->text().toInt();
        string actor = editActor->text().toStdString();

        //optional - golim QLineEdit-urile dupa apasarea butonului
        editTitlu->clear();
        editGen->clear();
        editAn->clear();
        editActor->clear();

        this->srv.modificare_serv(titlu, gen, an, actor);
        this->reloadFilmList(this->srv.afisare_serv());
        this->reloadDynamicButtons();


    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(re.getMessage()));
    }
}


void GUI::guiAddInchiriate() {
    string titlu = editFilmInchiriat->text().toStdString();
    editFilmInchiriat->clear();

    this->srv.adaugaincos_serv(titlu);
    this->reloadCosList(this->srv.getAlldincos_serv());
}

void GUI::guiGenerare() {
    int nr = editGenerare->text().toInt();
    editGenerare->clear();

    this->srv.generare_serv(nr);
    this->reloadCosList(this->srv.getAlldincos_serv());
}


void GUI::reloadCosList(vector<Film> filme) {
    this->filme_inchiriate->clear();

    const vector<Film>& med = srv.getAlldincos_serv();
    for (auto& m : med) {
        QString currentItem = QString::fromStdString(m.getTitlu() + "\t" + m.getGen() + "\t" + std::to_string(m.getAn()) + "\t" + m.getActor());
        this->filme_inchiriate->addItem(currentItem);
    }

}