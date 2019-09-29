#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_Ok_clicked()
{
    if (ui->checkBox_Bold->isChecked() == true) {
        ui->textEdit->setFontWeight(QFont::Bold);
    }
    else {
        ui->textEdit->setFontWeight(QFont::Normal);
    }
    ui->textEdit->setFontItalic(ui->checkBox_Italic->isChecked());
    ui->textEdit->setFontUnderline(ui->checkBox_UnderLine->isChecked());

    if (ui->radioButton_Black->isChecked() == true) {
        ui->textEdit->setTextColor(QColor("black"));
    }
    else if (ui->radioButton_Green->isChecked() == true) {
        ui->textEdit->setTextColor(QColor("green"));
    }
    else if (ui->radioButton_Red->isChecked() == true) {
        ui->textEdit->setTextColor(QColor("red"));
    }
    ui->textEdit->setFocus();
}

void Widget::on_checkBox_UnderLine_clicked()
{
    if (ui->checkBox_UnderLine->isChecked()) {
        ui->textEdit->setFontWeight(QFont::Bold);
    }
    else {
        ui->textEdit->setFontWeight(QFont::Normal);
    }
    ui->textEdit->setFocus();
}

void Widget::on_checkBox_Italic_clicked()
{
    ui->textEdit->setFontItalic(ui->checkBox_Italic->isChecked());
    ui->textEdit->setFocus();
}

void Widget::on_checkBox_Bold_clicked()
{
    ui->textEdit->setFontUnderline(ui->checkBox_UnderLine->isChecked());
    ui->textEdit->setFocus();
}

void Widget::on_radioButton_Black_clicked()
{
    if (ui->radioButton_Black->isChecked() == true) {
        ui->textEdit->setTextColor(QColor("black"));
    }
    ui->textEdit->setFocus();
}

void Widget::on_radioButton_Green_clicked()
{
    if (ui->radioButton_Green->isChecked() == true) {
            ui->textEdit->setTextColor(QColor("green"));
    }
    ui->textEdit->setFocus();
}

void Widget::on_radioButton_Red_clicked()
{
    if (ui->radioButton_Red->isChecked() == true) {
        ui->textEdit->setTextColor(QColor("red"));
    }
    ui->textEdit->setFocus();
}

void Widget::on_pushButton_Exit_clicked()
{
    exit(0);
}

void Widget::on_pushButton_Cancel_clicked()
{
    ui->textEdit->setFontWeight(QFont::Normal);
    ui->textEdit->setTextColor(QColor("black"));
    ui->textEdit->setFocus();
}
