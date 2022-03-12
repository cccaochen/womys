#ifndef GPIBDESIGN_H
#define GPIBDESIGN_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class GPIBdesign;
}

class seqdesign;

class GPIBdesign : public QWidget
{
    Q_OBJECT

public:
    explicit GPIBdesign(QWidget *parent = 0);
    ~GPIBdesign();

signals:
    void GPIBsenddata(QString);

private slots:
    void on_Refresh_clicked();

    void on_linebtn_clicked();

    void receivedata(QString data);

private:
    void findaddress();

private:
    seqdesign* m_seq;

    Ui::GPIBdesign *ui;
};

#endif // GPIBDESIGN_H
