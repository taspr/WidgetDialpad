#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    numberOfMessages = 0;

    countriesList = new CountriesPrefixListModel(this);
    prefixDelegate = new CountriesPrefixDelegate(this);

    ui->comboBox->setModel(countriesList);
    ui->comboBox->setItemDelegate(prefixDelegate);
    ui->comboBox->setCurrentIndex(-1);
    ui->comboBox->installEventFilter(ui->frame);
    ui->lineEdit->installEventFilter(ui->frame);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_messageInput_textChanged()
{
    if(ui->messageInput->toPlainText().length() < 161)
    {
        int charactersLeft = 160 - ui->messageInput->toPlainText().length();
        ui->charactersLeftLabel->setText(QString::number(charactersLeft) + "/" + QString::number(numberOfMessages));
    }
    else
    {
        QString oldMessage = ui->messageInput->toPlainText();
        oldMessage.chop(1);
        ui->messageInput->setText(oldMessage);
        ui->messageInput->moveCursor(QTextCursor::End);
    }

}

void Dialog::on_pushButton_clicked()
{
    numberOfMessages++;
    ui->messageInput->clear();
    int charactersLeft = 160 - ui->messageInput->toPlainText().length();
    ui->charactersLeftLabel->setText(QString::number(charactersLeft) + "/" + QString::number(numberOfMessages));
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1.count() > 0)
    {
        int index = countriesList->getItemIndex(arg1);
        ui->comboBox->setCurrentIndex(index);

        if (arg1[0] != "+")
            ui->lineEdit->setText("+" + ui->lineEdit->text());
    }
}


void Dialog::on_comboBox_activated(int index)
{
    Q_UNUSED(index);

    ui->lineEdit->setText("+" + ui->comboBox->currentData(countriesList->PrefixRole).toString());
}






