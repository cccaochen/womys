#ifndef USBDESIGN_H
#define USBDESIGN_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class USBdesign;
}

class seqdesign;

class USBdesign : public QWidget
{
    Q_OBJECT

public:
    explicit USBdesign(QWidget *parent = 0);
    ~USBdesign();

signals:
    void USBsenddata(QString);

private slots:
    void on_refresh_clicked();

    void on_linebtn_clicked();

    void receivedata(QString data);

private:
    void initorder();
    void findaddress();

private:
    Ui::USBdesign *ui;

    seqdesign* m_seq;
};

#endif // USBDESIGN_H
