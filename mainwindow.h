#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <information.h>
#include <seqdesign.h>
#include <QTime>

namespace Ui {
class MainWindow;
}

class information;
class seqdesign;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    typedef struct a{
            QString name;
            qint32 baudRate;
            QString stringBaudRate;
            QSerialPort::DataBits dataBits;
            QString stringDataBits;
            QSerialPort::Parity parity;
            QString stringParity;
            QSerialPort::StopBits stopBits;
            QString stringStopBits;
            QSerialPort::FlowControl flowControl;
            QString stringFlowControl;
            QString order;
        }Settings;

    typedef struct b{
        int upvalue;
        int downvalue;
    }cutvalue;

    Settings setelement;

    cutvalue getthevalue;

private slots:
    void on_seqopenbtn_clicked();

    void on_seqrunbtn_clicked();

    void receivedata(QString);

    //void on_openSC_clicked();

    void on_openinfor_clicked();

private:
    void openRSSerial();
    void displayGPIB();
    void displayUSB();
    void displaySC();
    void displayRS();

    void dependres(QString strint,int i);
    void display();
    void savetheresult();
    void Sleep(int msec);
    void AddXml(QString path);
    void ReadXml(QString S1);

    void gettwo(QString S1,QString flag);

private:
    Ui::MainWindow *ui;
    information* m_infor;
    seqdesign* m_seq;

    QList<QString> header;
    //QList<QString> Qlist;
    QList<QString> Qresult;
    QList<QString> QUSBlist;
    QList<QString> QGPIBlist;
    QList<QString> QRSlist;
    QList<QString> QSClist;
    QSerialPort *serial=new QSerialPort(this);

    int sumi=4;
    int resultn=1;
    int uplimtn=2;
    int downlimitn=3;
    int disendn=5;

    QTime Time;
    double timen=0;
    double passn=0;
    double failn=0;
    double raten=0;

    QString Pathtorun;
};

#endif // MAINWINDOW_H
