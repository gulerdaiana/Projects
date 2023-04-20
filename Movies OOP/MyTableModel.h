//
// Created by Daiana Guler on 03.06.2022.
//

#ifndef LAB10OOP_MYTABLEMODEL_H
#define LAB10OOP_MYTABLEMODEL_H
#include <QAbstractTableModel>
#include "filme.h"
#include <vector>
#include <qdebug.h>
#include<QBrush>

class MyTableModel : public QAbstractTableModel {
    std::vector<Film> filme;
public:
    MyTableModel(const std::vector<Film> &filme) : filme{filme} {
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return filme.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {

        if (role == Qt::ForegroundRole) {
            Film film = filme[index.row()];
            if (film.getGen()=="actiune") {
                return QBrush{Qt::red};
            }
            else if (film.getGen()=="comedie"){
                return QBrush{Qt::yellow};
            }
            else if(film.getGen()=="drama"){
                return QBrush{Qt::green};
            }
        }
        if (role == Qt::DisplayRole) {

            Film film = filme[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(film.getTitlu());
            } else if (index.column() == 1) {
                return QString::fromStdString(film.getGen());
            } else if (index.column() == 2) {
                return QString::number(film.getAn());
            } else if (index.column() == 3) {
                return QString::fromStdString(film.getActor());
            }
        }

        return QVariant{};
    }

    void setFilme(const vector<Film> &filme) {
        this->filme = filme;
        auto topLeft = createIndex(0, 0);
        auto bottomR = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomR);
    }
};
#endif //LAB10OOP_MYTABLEMODEL_H
