#ifndef SEQDESIGN_H
#define SEQDESIGN_H

#include <QMainWindow>
#include <QDomDocument>
#include <QtSerialPort/QSerialPort>
#include <QDateTime>
#include <QDialog>
#include <QFileDialog>
#include <QListWidgetItem>
#include <qDebug>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QMenu>


namespace Ui {
class seqdesign;
}

class ratedesign;
class GPIBdesign;
class USBdesign;
class SCdesign;
class Rename;

class seqdesign : public QWidget
{
    Q_OBJECT

public:
    explicit seqdesign(QWidget *parent = 0);
    ~seqdesign();

signals:
    void senddataUSB(QString);
    void senddataGPIB(QString);
    void senddataRS(QString);
    void senddataSC(QString);

private slots:  
    void on_intoseq_clicked();
    void on_outseq_clicked();
    void on_upbtn_clicked();
    void on_downbtn_clicked();

    void connectinit();
    void SCreceiveData(QString data);
    void GPIBreceiveData(QString data);
    void USBreceiveData(QString data);
    void ratereceiveData(QString data);
    void NamereceiveData(QString data);

    void on_outputorder_customContextMenuRequested(const QPoint &pos);
    void on_outputorder_itemDoubleClicked(QListWidgetItem *item);

    void on_SaveButton_clicked();
    void on_openbtn_clicked();

private:
    void initUIpart();
    void RemoveXml();
    void ReadXml();
    void openSerialPort();
    void readData();
    void updateallxml();
    void WriteXml(QString S1);
    void WriteXmlhead(QString S2);

private:
    Ui::seqdesign* ui;

    Rename* m_name;
    ratedesign* m_rate;
    GPIBdesign* m_GPIB;
    USBdesign* m_USB;
    SCdesign* m_SC;

    QList<QString> seqdata;
    QString PathName,current_File;
    //QSerialPort *m_serial = nullptr;
};

#endif // SEQDESIGN_H
