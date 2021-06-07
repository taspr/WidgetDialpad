#ifndef COUNTRIESPREFIXDELEGATE_H
#define COUNTRIESPREFIXDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CountriesPrefixDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CountriesPrefixDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // COUNTRIESPREFIXDELEGATE_H
