#include "numberinputframe.h"

NumberInputFrame::NumberInputFrame(QWidget *parent, Qt::WindowFlags f): QFrame(parent, f)
{

}

bool NumberInputFrame::eventFilter(QObject *watched, QEvent *event)
{
    if(watched->objectName() == "lineEdit")
    {
        switch (event -> type())
        {
        case QEvent::FocusIn:
            setStyleSheet("NumberInputFrame { border-color: rgb(15, 151, 255); border-width: 1px; border-radius: 3px; border-style: solid; background-color: rgb(255, 255, 255)}");
            break;
        case QEvent::FocusOut:
            setStyleSheet("NumberInputFrame { border-color: rgb(213, 213, 213); border-width: 1px; border-radius: 3px; border-style: solid; background-color: rgb(255, 255, 255)}");
            break;
        default:
            break;
        }
    }

    return false;
}
