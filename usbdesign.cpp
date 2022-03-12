#include "usbdesign.h"
#include "ui_usbdesign.h"

#include <qDebug>

__declspec(dllimport) void OpenUSBlist();

USBdesign::USBdesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::USBdesign)
{
    ui->setupUi(this);

    this->setWindowTitle("Usb Design");

    findaddress();
}

USBdesign::~USBdesign()
{
    delete ui;
}

void USBdesign::findaddress()
{
    OpenUSBlist();

    ui->devicelist->clear();

    QFile f("D:\\information\\USBlist.txt");
    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))//打开指定文件
        {
            f.close();
            //qDebug()<<"error"<<"\n";
        }

        QTextStream txtInput(&f);
        QString lineStr;
        while (!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();  //读取数据
            ui->devicelist->addItem(lineStr);
        }

        f.close();
}

void USBdesign::on_refresh_clicked()
{
    findaddress();
}

void USBdesign::on_linebtn_clicked()
{
    //emit senddata(ui->lineEdit->text());
    int a=ui->devicelist->currentIndex();
    QString b=ui->orderline->text();

    QString str="USB-"+QString::number(a)+"-"+b+"-"+ui->cutup->text()+"-"+ui->cutdown->text();
    emit USBsenddata(str);

    this->hide();
}

void USBdesign::receivedata(QString data)
{
    //qDebug() << data ;
    ui->devicelist->clear();
    ui->orderline->clear();
    OpenUSBlist();

    QStringList str=data.split("-");
    QString s=str[1];

    QFile f("D:\\information\\USBlist.txt");
    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))//打开指定文件
    {
        f.close();
        //qDebug()<<"error"<<"\n";
    }

    QTextStream txtInput(&f);
    QString lineStr;

    int USBn=0;
    while (!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();  //读取数据

        if(USBn==s.toInt())
        {
            ui->devicelist->addItem(lineStr);
        }

        USBn=USBn+1;
    }

    f.close();

    s=str[2];
    ui->orderline->setText(s);   
    s=str[3];
    ui->cutup->setText(s);
    s=str[4];
    ui->cutdown->setText(s);
}
