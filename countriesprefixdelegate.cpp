#include "countriesprefixdelegate.h"
#include "countriesprefixlistmodel.h"

CountriesPrefixDelegate::CountriesPrefixDelegate(QObject *parent): QStyledItemDelegate(parent)
{

}

void CountriesPrefixDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const CountriesPrefixListModel *prefixModel = qobject_cast<const CountriesPrefixListModel*>(index.model());
    QVariant flag = prefixModel->data(index, prefixModel->FlagRole);
    QVariant country = prefixModel->data(index, prefixModel->CountryRole);
    QVariant prefix = prefixModel->data(index, prefixModel->PrefixRole);
    painter->save();

    if (option.state & QStyle::State_Selected)
        painter->fillRect(option.rect, QBrush(QColor("lightgray"), Qt::SolidPattern));

    QRect rect = option.rect;

    QImage image(":/resources/countries/flags/"+ QString::number(flag.toInt()) +".jpg");
    QRect imgSize(0, 0, image.width(), image.height());
    int middleOffset = (rect.height() - image.height()) / 2;
    painter->drawImage(QRect(rect.x() + 4, rect.y() + middleOffset, image.width(), image.height()), image, imgSize);

    painter->drawText(QRect(rect.left()+ image.width() + 8, rect.y(), 134, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, country.toString());
    painter->drawText(QRect(rect.right()- 32, rect.y(), 30, rect.height()), Qt::AlignRight | Qt::AlignVCenter, "+" + prefix.toString());

    painter->restore();
}


