#ifndef RATEDESIGN_H
#define RATEDESIGN_H

#include <QWidget>
#include <QDialog>
#include <QtSerialPort/QSerialPort>



namespace Ui {
class ratedesign;
}

class QIntValidator;

class seqdesign;

class ratedesign : public QWidget
{
    Q_OBJECT

public:
    explicit ratedesign(QWidget *parent = 0);
    ~ratedesign();

    typedef struct a{
            QString name;
            //qint32 baudRate;
            QString stringBaudRate;
            //QSerialPort::DataBits dataBits;
            QString stringDataBits;
            //QSerialPort::Parity parity;
            QString stringParity;
            //QSerialPort::StopBits stopBits;
            QString stringStopBits;
            //QSerialPort::FlowControl flowControl;
            QString stringFlowControl;
            QString order;
        }Settings;

    Settings setelement;

signals:
     void ratesenddata(QString);

private slots:
    //void on_pushButton_clicked();

     void on_OKbtn_clicked();

     void receivedata(QString data);

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);

    void WriteXml();
    void ReadXml();
    void AddXml();
    void UpdateXml();
    void Fillarr();
    void outarr();

private:
    Ui::ratedesign *m_ui;

    seqdesign* m_seq;

    QIntValidator *intValidator;
    QString blankString=nullptr;
};

#endif // RATEDESIGN_H
