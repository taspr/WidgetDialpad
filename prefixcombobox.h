#ifndef PREFIXCOMBOBOX_H
#define PREFIXCOMBOBOX_H

#include <QComboBox>
#include <QAbstractItemView>

class PrefixComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit PrefixComboBox(QWidget *parent = nullptr);
        ~PrefixComboBox() {}

    void showPopup();
};

#endif // PREFIXCOMBOBOX_H
