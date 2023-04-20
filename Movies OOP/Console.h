//
// Created by Daiana Guler on 29.03.2022.
//

/*#ifndef LAB6_8_CONSOLE_H
#define LAB6_8_CONSOLE_H

#endif //LAB6_8_CONSOLE_H
#include "FilmeServ.h"
#pragma once
class UI{
    FilmeServ& serv;
public:
    UI(FilmeServ& serv): serv{serv}{
    };
    UI(const UI& ot)=delete;
    void startUI();
    void afisareUI();
    void adaugareUI();
    void modificareUI();
    void stergereUI();
    void cautareUI();
    void afisareFilm(const Film& x);
    void filtrareUI();
    void sortareUI();
    void adaugaincosUI();
    void cateincosUI();
    void golirecosUI();
    void generareUI();
    void afisarecosUI();
    void exportUI();
};*/

#pragma once
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include "FilmeServ.h"
#include<set>
#include<QPainter>
#include "Observer.h"
#include<QComboBox>
#include <QListWidget>
#include "MyTableModel.h"

using std::vector;
using std::string;
using std::set;

class CosGUIViewOnly :public QWidget, public Observer {
    FilmeServ& serv;
    void initialize() {
        serv.addObserver(this);
    }
    void paintEvent(QPaintEvent*) override {
        QPainter painter{ this };

        for (auto film : serv.getAlldincos_serv())
        {
            int x, y;

            x = rand() % 400 + 1;
            y = rand() % 400 + 1;
            qDebug() << x << " " << y;
            QRectF target(x, y, 100, 94);
            QRectF source(0, 0, 732, 720);
            QImage image("film.jpg");

            //painter.fillRect(x,y,50,50,Qt::GlobalColor::red);

            painter.drawImage(target, image, source);

            x += 40;

        }
    }
    void update() override {
        repaint();
    }

public:
    CosGUIViewOnly(FilmeServ& serv) :serv{serv} {
        initialize();
    };

    ~CosGUIViewOnly() {
        serv.removeObserver(this);
    }
};

/*class CosGUI: public QWidget,public Observer{
private:
    FilmeServ& srv;
    QTableWidget* filme_inchiriate;

    QPushButton* btnAddInchiriate;
    QLineEdit* editFilmInchiriat;
    QLabel* lblAddInchiriate = new QLabel{ "Titlu:" };

    QPushButton* btnGenerare;
    QLineEdit* editGenerare;
    QLabel* lblGenerare = new QLabel{ "Numar filme:" };

    QPushButton* btnExp;
    QLineEdit* editExp;
    QLabel* lblExp = new QLabel{ "Nume fisier .csv" };
    QPushButton* btnGolireCos;


    void initializeGUIComponents();
    void connectSignalsSlots();
    void reloadCosList(vector<Film> filme);

public:
    CosGUI(FilmeServ &srv): srv{srv} {
        initializeGUIComponents();
        connectSignalsSlots();
    }
};*/


class GUI : public QWidget {
private:

    FilmeServ& srv;
    CosGUIViewOnly cosGuiViewOnly{srv};

    QLabel* lblTitlu = new QLabel{ "Titlu:" };
    QLabel* lblGen = new QLabel{ "Gen:" };
    QLabel* lblAn = new QLabel{ "An:" };
    QLabel* lblActor = new QLabel{ "Actor:" };

    QLineEdit* editTitlu;
    QLineEdit* editGen;
    QLineEdit* editAn;
    QLineEdit* editActor;

    QPushButton* btnAddFilm;
    QPushButton* btnModificare;

    QLabel* lblStergere = new QLabel{ "Titlu:" };
    QLineEdit* editStergere;
    QPushButton* btnStergere;

    QGroupBox* groupBox = new QGroupBox(tr("Sortare"));

    QRadioButton* radioSrtTitlu = new QRadioButton(QString::fromStdString("Titlu"));
    QRadioButton* radioSrtActor = new QRadioButton(QString::fromStdString("Actor"));
    QRadioButton* radioSrtGenAn = new QRadioButton(QString::fromStdString("Gen+An"));
    QPushButton* btnSortFilme;

    QLabel* lblFilterCriteria = new QLabel{ "Titlul dupa care se filtreaza:" };
    QLineEdit* editFilterTitlu;
    QPushButton* btnFilterFilme;
    QLabel* lblFilterCriteria2 = new QLabel{ "Anul dupa care se filtreaza:" };
    QLineEdit* editFilterAn;
    QPushButton* btnFilterFilme2;
    QPushButton* btnUndo;
    QPushButton* btnReloadData;

    QTableWidget* tableFilme;
    QListWidget* filme_inchiriate;

    QWidget* wndCos;
    QPushButton* meniu;
    QPushButton* btnAddInchiriate;
    QLineEdit* editFilmInchiriat;
    QLabel* lblAddInchiriate = new QLabel{ "Titlu:" };

    QPushButton* btnGenerare;
    QLineEdit* editGenerare;
    QLabel* lblGenerare = new QLabel{ "Numar filme:" };

    QPushButton* btnExp;
    QLineEdit* editExp;
    QLabel* lblExp = new QLabel{ "Nume fisier .csv" };
    QPushButton* btnGolireCos;

    QWidget* widgetDynamic;
    QVBoxLayout* lyBtnDynamic;

    QPushButton* btnCos=new QPushButton;
    QPushButton* btnCosView=new QPushButton;

    MyTableModel* model;
    QTableView* tblView;

    void initializeGUIComponents();
    void reloadCosList(vector<Film> filme);
    void connectSignalsSlots();
    void reloadFilmList(vector<Film> filme);
public:
    GUI(FilmeServ& Filmsrv) : srv{ Filmsrv } {
        initializeGUIComponents();
        connectSignalsSlots();
        reloadFilmList(srv.afisare_serv());
    }
    void guiAddFilm();
    void guiStergere();
    void guiModificare();
    void guiAddInchiriate();
    void guiGenerare();
    void reloadDynamicButtons();
    set<string>getFilme(const vector<Film>& all_filme);
};
