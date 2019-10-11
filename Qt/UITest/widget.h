#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_Ok_clicked();

    void on_checkBox_UnderLine_clicked();

    void on_checkBox_Italic_clicked();

    void on_checkBox_Bold_clicked();

    void on_radioButton_Black_clicked();

    void on_radioButton_Green_clicked();

    void on_radioButton_Red_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
