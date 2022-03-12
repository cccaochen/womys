#include "gpibdesign.h"
#include "ui_gpibdesign.h"

__declspec(dllimport) void OpenGPIBlist();

GPIBdesign::GPIBdesign(QWidget *parent):
    QWidget(parent),
    ui(new Ui::GPIBdesign)
{
    ui->setupUi(this);

    this->setWindowTitle("GPIB Design");

    findaddress();
}

GPIBdesign::~GPIBdesign()
{
    delete ui;
}

void GPIBdesign::findaddress()
{
    OpenGPIBlist();

    ui->devicelist->clear();

    QFile f("D:\\information\\GPIBlist.txt");
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

void GPIBdesign::on_Refresh_clicked()
{
     findaddress();
}

void GPIBdesign::on_linebtn_clicked()
{
    int a=ui->devicelist->currentIndex();
    QString b=ui->orderline->text();

    QString str="GPIB-"+QString::number(a)+"-"+b+"-"
            +ui->cutup->text()+"-"+ui->cutdown->text();
    emit GPIBsenddata(str);

    this->hide();
}

void GPIBdesign::receivedata(QString data)
{
    ui->devicelist->clear();

    ui->orderline->clear();

    OpenGPIBlist();

    QStringList str=data.split("-");
    QString s=str[1];

    QFile f("D:\\information\\GPIBlist.txt");
    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))//打开指定文件
    {
        f.close();
        //qDebug()<<"error"<<"\n";
    }

    QTextStream txtInput(&f);
    QString lineStr;

    int GPIBn=0;
    while (!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();  //读取数据

        if(GPIBn==s.toInt())
        {
            ui->devicelist->addItem(lineStr);
        }

        GPIBn=GPIBn+1;
    }

    f.close();

    ui->orderline->setText(str[2]);
    ui->cutup->setText(str[3]);
    ui->cutdown->setText(str[4]);
}
