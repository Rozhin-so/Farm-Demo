#include "mymodel.h"

mymodel::mymodel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int mymodel::rowCount(const QModelIndex &parent) const
{
//    if (parent.isValid())
        return 2;

    // FIXME: Implement me!
}

int mymodel::columnCount(const QModelIndex &parent) const
{
//    if (parent.isValid())
        return 3;

    // FIXME: Implement me!
}

QVariant mymodel::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();

//    // FIXME: Implement me!
    if (role == Qt::DisplayRole)
           return QString("Row%1, Column%2")
                       .arg(index.row() + 1)
                       .arg(index.column() +1);
    return QVariant();
}
