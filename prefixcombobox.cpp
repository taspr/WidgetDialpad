#include "prefixcombobox.h"

PrefixComboBox::PrefixComboBox(QWidget *parent) : QComboBox(parent)
{

}

void PrefixComboBox::showPopup()
{
    this->view()->setMinimumWidth(220);
    QComboBox::showPopup();

}
