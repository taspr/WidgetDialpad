#ifndef NUMBERINPUTFRAME_H
#define NUMBERINPUTFRAME_H

#include <QFrame>
#include <QEvent>
#include <QDebug>

class NumberInputFrame : public QFrame
{
    Q_OBJECT
public:
    NumberInputFrame(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
    ~NumberInputFrame() {};

    virtual bool eventFilter(QObject *watched, QEvent *event);
};

#endif // NUMBERINPUTFRAME_H
