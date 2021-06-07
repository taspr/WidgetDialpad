#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "countriesprefixlistmodel.h"
#include "countriesprefixdelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_messageInput_textChanged();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_activated(int index);

private:
    Ui::Dialog *ui;
    CountriesPrefixListModel *countriesList;
    CountriesPrefixDelegate  *prefixDelegate;
    int numberOfMessages;
};
#endif // DIALOG_H
