#include "ratedesign.h"
#include "ui_ratedesign.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>

#include <QDateTime>

#include <QFileDialog>
#include <QTextStream>
#include <QDomDocument>

ratedesign::ratedesign(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ratedesign)
{
    m_ui->setupUi(this);
    this->setWindowTitle("RS232 Design");

    connect(m_ui->Baudrate,  QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &ratedesign::checkCustomBaudRatePolicy);
    connect(m_ui->Serialport, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &ratedesign::checkCustomDevicePathPolicy);

    fillPortsParameters();
    fillPortsInfo();
}

ratedesign::~ratedesign()
{
    delete m_ui;
}

//
void ratedesign::checkCustomBaudRatePolicy(int idx)
//make BuadRate to be write
{
    const bool isCustomBaudRate = !m_ui->Baudrate->itemData(idx).isValid();
    m_ui->Baudrate->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        m_ui->Baudrate->clearEditText();
        QLineEdit* edit = m_ui->Baudrate->lineEdit();
        edit->setValidator(intValidator);
        //m_ui->Baudrate->setValidator(intValidator);
    }
}

//
void ratedesign::checkCustomDevicePathPolicy(int idx)
//make SerialPort to be write
{
    const bool isCustomPath = !m_ui->Serialport->itemData(idx).isValid();
    m_ui->Serialport->setEditable(isCustomPath);
    if (isCustomPath)
        m_ui->Serialport->clearEditText();
}

void ratedesign::fillPortsInfo()
{
    m_ui->Serialport->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        m_ui->Serialport->addItem(list.first(), list);
    }

    m_ui->Serialport->addItem(tr("Custom"));
}

void ratedesign::fillPortsParameters()
{
    m_ui->Baudrate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    m_ui->Baudrate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    m_ui->Baudrate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    m_ui->Baudrate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    m_ui->Baudrate->addItem(QStringLiteral("921600"),QSerialPort::Baud115200);
    m_ui->Baudrate->addItem(tr("Custom"));

    m_ui->Databits->addItem(QStringLiteral("5"), QSerialPort::Data5);
    m_ui->Databits->addItem(QStringLiteral("6"), QSerialPort::Data6);
    m_ui->Databits->addItem(QStringLiteral("7"), QSerialPort::Data7);
    m_ui->Databits->addItem(QStringLiteral("8"), QSerialPort::Data8);
    m_ui->Databits->setCurrentIndex(3);

    m_ui->Parity->addItem(tr("None"), QSerialPort::NoParity);
    m_ui->Parity->addItem(tr("Even"), QSerialPort::EvenParity);
    m_ui->Parity->addItem(tr("Odd"), QSerialPort::OddParity);
    m_ui->Parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    m_ui->Parity->addItem(tr("Space"), QSerialPort::SpaceParity);

    m_ui->Stopbits->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    m_ui->Stopbits->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    m_ui->Stopbits->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    m_ui->FlowControls->addItem(tr("None"), QSerialPort::NoFlowControl);
    m_ui->FlowControls->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    m_ui->FlowControls->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}
//[!]UI Designer

//按钮操作
void ratedesign::on_OKbtn_clicked()
{
    setelement.name=m_ui->Serialport->currentText();
    setelement.stringBaudRate=m_ui->Baudrate->currentText();
    setelement.stringDataBits=m_ui->Databits->currentText();
    setelement.stringParity=m_ui->Parity->currentText();
    setelement.stringStopBits=m_ui->Stopbits->currentText();
    setelement.stringFlowControl=m_ui->FlowControls->currentText();
    setelement.order=m_ui->orderline->text();

    QString str="RS232-"+setelement.name+"-"+setelement.stringBaudRate+"-"
            +setelement.stringDataBits+"-"+setelement.stringParity+"-"
            +setelement.stringStopBits+"-"+setelement.stringFlowControl+"-"
            +setelement.order+"-"+m_ui->cutup->text()+"-"+m_ui->cutdown->text();

    emit ratesenddata(str);

    this->hide();
}

void ratedesign::receivedata(QString data)
{
    m_ui->orderline->clear();

    QStringList str=data.split("-");

    m_ui->Serialport->setEditText(str[1]);

    m_ui->Baudrate->setEditText(str[2]);

    m_ui->Databits->setEditText(str[3]);

    m_ui->Parity->setEditText(str[4]);

    m_ui->Stopbits->setEditText(str[5]);

    m_ui->FlowControls->setEditText(str[6]);

    m_ui->orderline->setText(str[7]);

    m_ui->cutup->setText(str[8]);

    m_ui->cutdown->setText(str[9]);
}
