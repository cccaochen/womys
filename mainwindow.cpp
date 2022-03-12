
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTimer>

__declspec(dllimport) void opensequence(char** seq);
__declspec(dllimport) void OpenUSB(int* a,char** b);
__declspec(dllimport) void OpenGPIB(int* a,char** b);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_infor(new information),
    m_seq(new seqdesign)
{
    ui->setupUi(this);

    header << "project" << "value" << "uplimit" << "downlimit" << "statues" << "result";

    connect(ui->inforaction,&QAction::triggered,m_infor,&information::show);
    connect(ui->seqaction,&QAction::triggered,m_seq,&seqdesign::show);
    connect(m_infor,SIGNAL(senddata(QString)),this,SLOT(receivedata(QString)));

    ui->operateress->setMinimum(0);
    ui->operateress->setMaximum(100);
    ui->operateress->setValue(0);

    ui->displaylist->setRowCount(10);
    ui->displaylist->setColumnCount(header.size());

    for(int i=0;i<header.size();i++)
    {
        ui->displaylist->setColumnWidth(i,137);
    }
}

MainWindow::~MainWindow()
{
    delete serial;
    delete ui;
}

void MainWindow::openRSSerial()
{
    serial->setPortName(setelement.name);
    serial->setBaudRate(setelement.baudRate);
    serial->setDataBits(setelement.dataBits);
    serial->setParity(setelement.parity);
    serial->setStopBits(setelement.stopBits);
    serial->setFlowControl(setelement.flowControl);

    //qDebug()<<"判定serial是否可以打开"<<endl;

    if (serial->open(QIODevice::ReadWrite)) {
        serial->write(setelement.order.toUtf8());
        QByteArray data=serial->readAll();

        serial->close();

        QDateTime curDateTime=QDateTime::currentDateTime();
        QString S=curDateTime.toString("hh:mm:ss");

        QFile file("D:\\information\\RS232order.txt");
        if(!file.open(QFile::WriteOnly | QFile::Truncate))
            return;

        QTextStream stream(&file);
        stream<<data<<S<<endl;
        //将数据保存在txt中函数，读取对比结果函数

        file.close();
    } else {
        QDateTime curDateTime=QDateTime::currentDateTime();
        QString S=curDateTime.toString("hh:mm:ss");
       //QMessageBox::critical(this, tr("Error"), serial->errorString());
        QFile file("D:\\information\\RS232order.txt");

        if(!file.open(QFile::WriteOnly | QFile::Truncate))
            return;

        QTextStream stream1(&file);

        stream1<<serial->errorString()<<S<<"\n";

        file.close();
    }
}

void MainWindow::displayRS()
{
    //QRSlist.clear();

    QFile file("D:\\information\\RS232order.txt");

    if(!file.open(QFile::ReadWrite))
        return;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        QString S=str.left(str.size()-1);
        QRSlist.append(S);
    }

    file.close();
}

void MainWindow::displayGPIB()
{
    //QGPIBlist.clear();

    QFile file("D:\\information\\GPIBorder.txt");

    if(!file.open(QFile::ReadWrite))
        return;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        QString S=str.left(str.size()-1);
        QGPIBlist.append(S);
    }

    file.close();
}

void MainWindow::displayUSB()
{
    //QUSBlist.clear();

    QFile file("D:\\information\\usborder.txt");

    if(!file.open(QFile::ReadWrite))
        return;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        QString S=str.left(str.size()-1);
        QUSBlist.append(S);
        //ui->displaylist->setItem(site,1,new QTableWidgetItem(strtend[0]));
    }

    file.close();
}

void MainWindow::displaySC()
{
    //QSClist.clear();

    QFile file("D:\\information\\SCorder.txt");

    if(!file.open(QFile::ReadOnly))
        return;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);

        QString S=str.left(str.size()-1);
        QSClist.append(S);
        //ui->displaylist->setItem(site,1,new QTableWidgetItem(strtend[0]));
    }

    file.close();
}

void MainWindow::dependres(QString strint,int i)
{
    //将获取的结果输入到result内
    //&& !ui->displaylist->item(i,resultn)->text().isEmpty()
    if(ui->displaylist->item(i,resultn)!=NULL)
    {
        ui->displaylist->item(i,resultn)->setText(strint);
    }
    else
    {
        ui->displaylist->setItem(i,resultn,new QTableWidgetItem(strint));
    }

    //当判断结果为空时
    if(strint=="")
    {
        //输入到result结果内
        if(ui->displaylist->item(i,disendn)!=NULL)
        {
            ui->displaylist->item(i,disendn)->setText("Fail");
        }
        else
        {
            ui->displaylist->setItem(i,disendn,new QTableWidgetItem("Fail"));
        }
    }
    else
    {
        //对于result的判断
        int resint=strint.toInt();
        int upint=ui->displaylist->item(i,uplimtn)->text().toInt();
        int downint=ui->displaylist->item(i,downlimitn)->text().toInt();

        if(resint <= upint && resint >= downint)
        {
            if(ui->displaylist->item(i,disendn)!=NULL)
            {
                ui->displaylist->item(i,disendn)->setText("Pass");
            }
            else
            {
                ui->displaylist->setItem(i,disendn,new QTableWidgetItem("Pass"));
            }
        }
        else
        {
            if(ui->displaylist->item(i,disendn)!=NULL)
            {
                ui->displaylist->item(i,disendn)->setText("Fail");
            }
            else
            {
                ui->displaylist->setItem(i,disendn,new QTableWidgetItem("Fail"));
            }
        }
     }
}

void MainWindow::display()
{
    int rsnum=0;
    int usbnum=0;
    int gpibnum=0;
    int scnum=0;

    for(int i=0;i<Qresult.size();i++)
    {
        //qDebug()<<"Qresult="<<Qresult.at(i)<<"i="<<i;
        gettwo(Pathtorun,Qresult.at(i));
        if(Qresult.at(i)=="SC")
        {
            QString scstr=QSClist.at(scnum).mid(getthevalue.downvalue,getthevalue.upvalue);
            //qDebug()<< "str=" << scstr;
            dependres(scstr,i);

            scnum=scnum+1;
        }
        else if(Qresult.at(i)=="USB")
        {
            QString usbstr="";
            usbstr=QUSBlist.at(usbnum).mid(getthevalue.downvalue,getthevalue.upvalue);
            //qDebug()<< "str=" << usbstr;
            dependres(usbstr,i);

            usbnum=usbnum+1;
        }
        else if(Qresult.at(i)=="GPIB")
        {
            QString gpibstr="";
            gpibstr=QGPIBlist.at(gpibnum).mid(getthevalue.downvalue,getthevalue.upvalue);
            //qDebug()<< "str=" << gpibstr;
            dependres(gpibstr,i);

            gpibnum=gpibnum+1;
        }
        else if(Qresult.at(i)=="RS232")
        {
            QString rsstr="";
            rsstr=QRSlist.at(rsnum).mid(getthevalue.downvalue,getthevalue.upvalue);
            //qDebug()<< "str=" << rsstr;
            dependres(rsstr,i);
            rsnum=rsnum+1;
        }
    }
}

void MainWindow::AddXml(QString path)
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm::ss.zzz");
    //打开文件
    QFile file(path); //相对路径、绝对路径、资源路径都可以

    if(!file.open(QIODevice::Append | QIODevice::ReadWrite))
        return;

    //增加一个一级子节点以及元素
    QDomProcessingInstruction instruction;
    QDomDocument doc;
    QDomElement root;

    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    if(!doc.setContent(&file))
    {
         //添加处理命令
        doc.appendChild(instruction);

        root=doc.createElement("result"+current_date);
        doc.appendChild(root);
    }
    file.close();


    QDomElement book;
    QDomElement title;
    QDomText text;

    root=doc.documentElement();

    for(int i=0;i<ui->displaylist->rowCount();i++)
    {
        for(int j=0;j<ui->displaylist->columnCount();j++)
        {
            if(ui->displaylist->item(i,j) != NULL &&
                    !ui->displaylist->item(i,j)->text().isEmpty())
            {
                if(j==0)
                {
                    book=doc.createElement(ui->displaylist->item(i,j)->text());
                    book.setAttribute("time",current_date);
                }
                else
                {
                    title=doc.createElement(header[j]);
                    text=doc.createTextNode(ui->displaylist->item(i,j)->text());
                    title.appendChild(text);
                    book.appendChild(title);
                }
            }
        }

        root.appendChild(book);
    }

    //root.appendChild(instruction);

    if(!file.open(QIODevice::Append|QIODevice::ReadWrite))
       return;

    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    doc.appendChild(instruction);

    file.close();
}

void MainWindow::savetheresult()
{
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm::ss.zzz");
        QString timestr=current_date_time.toString("yyyy.MM.dd");

        QString PathName="D:\\information\\result\\"+timestr+".txt";

        AddXml(PathName);
}

void MainWindow::receivedata(QString PathName)
{
    QFile file(PathName);

    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        qDebug() << "filefail" << endl;
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement(); //返回根节点
    //qDebug()<<root.nodeName();

    QDomNode node=root.firstChild(); //获得第一个子节点

    int RowCount=0;

    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            RowCount=RowCount+1;
        }
        node=node.nextSibling();
        //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    ui->displaylist->setRowCount(RowCount);
    ui->displaylist->setColumnCount(header.size());
    ui->displaylist->setHorizontalHeaderLabels(header);

    QDomNode node2=root.firstChild(); //获得第一个子节点

    RowCount=0;

    while(!node2.isNull())  //如果节点不空
    {
        if(node2.isElement()) //如果节点是元素
        {
            QDomElement e=node2.toElement();
            ui->displaylist->setItem(RowCount,0,new QTableWidgetItem(e.tagName()));

            QDomNodeList list=e.childNodes();
            for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);

                //qDebug() << "n.nodename" << n.nodeName() <<endl;
                //qDebug() << "n.text=" << n.toElement().text() <<endl;
                for(int j=0;j<header.size();j++)
                {
                    if(n.nodeName()==header[j])
                    {
                        ui->displaylist->setItem(RowCount,j,new QTableWidgetItem(n.toElement().text()));
                    }
                }
            }

            RowCount=RowCount+1;
        }
        node2=node2.nextSibling();
        //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    //file.close();
}

void MainWindow::ReadXml(QString S1)
{
    //打开或创建文件
    QFile file(S1); //相对路径、绝对路径、资源路径都行

    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        qDebug() << "txtwrong"<<endl;
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement(); //返回根节点
    //qDebug() << root.nodeName();

    QDomNode node = root.firstChild(); //获得第一个子节点
    double bar=1;

    //节点姓名，USB，RS232，GPIB，SC
    while(!node.isNull())
    {
        Qresult.append(node.toElement().tagName());
        node=node.nextSibling();
    }

    node=root.firstChild();

    while(!node.isNull())  //如果节点不空
    {

        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement();
            //转换为元素，注意元素和节点是两个数据结构，其实差不多
            QString nodename = e.tagName();
            //qDebug() << "nodename" << nodename << endl;
            //打印键值对，tagName和nodeName是一个东西
            QDomNodeList list=e.childNodes();

            QString number;
            QString command;

            for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);
                if(node.isElement())
                {
                    if(n.nodeName()=="command")
                    {
                        setelement.order=n.toElement().text();
                        command = n.toElement().text();
                    }
                    else if(n.nodeName()=="equipment")
                        number = n.toElement().text();
                    else if(n.nodeName()=="COM端口")
                        setelement.name=n.toElement().text();
                    else if(n.nodeName()=="Baudrate")
                        setelement.stringBaudRate=n.toElement().text();
                    else if(n.nodeName()=="Databits")
                        setelement.stringDataBits=n.toElement().text();
                    else if(n.nodeName()=="Parity")
                        setelement.stringParity=n.toElement().text();
                    else if(n.nodeName()=="Stopbits")
                        setelement.stringStopBits=n.toElement().text();
                    else if(n.nodeName()=="Flowcontrol")
                        setelement.stringFlowControl=n.toElement().text();
                }

            }

            if(nodename=="SC")
            {
                char* path=command.toLatin1().data();
                try
                {
                    opensequence(&path);
                }
                catch(...)
                {
                    QMessageBox::critical(this, tr("Error"), "Soundcheck error");
                }
            }
            else if(nodename=="USB")
            {
                int num1=-1;
                char* num2=command.toLocal8Bit().data();

                //qDebug()<<"size="<<strtend.size()<<endl;

                if(number!="" && number!="0")
                {
                    num1=number.toInt();
                }

                try
                {
                   OpenUSB(&num1,&num2);
                }
                catch(...)
                {
                   QMessageBox::critical(this, tr("Error"), "USB error");
                }
            }
            else if(nodename=="RS232")
            {
                QVariant setrsbaud(setelement.stringBaudRate);
                QVariant setrsdata(setelement.stringDataBits);
                QVariant setrspar(setelement.stringParity);
                QVariant setrsstop(setelement.stringStopBits);
                QVariant setrsflow(setelement.stringFlowControl);


                setelement.baudRate=static_cast<QSerialPort::BaudRate>(setrsbaud.toInt());
                setelement.dataBits=static_cast<QSerialPort::DataBits>(setrsdata.toInt());
                setelement.parity=static_cast<QSerialPort::Parity>(setrspar.toInt());
                setelement.stopBits=static_cast<QSerialPort::StopBits>(setrsstop.toInt());
                setelement.flowControl= static_cast<QSerialPort::FlowControl>(setrsflow.toInt());

                openRSSerial();
            }
            else if(nodename=="GPIB")
            {
                int num1=-1;
                char* num2=command.toLocal8Bit().data();

                if(number!="" && number!="0")
                {
                    num1=number.toInt();
                }

                try
                {
                    OpenGPIB(&num1,&num2);
                }
                catch(...)
                {
                   QMessageBox::critical(this, tr("Error"), "GPIB error");
                }
            }
        }

        double barto=bar/Qresult.size()*100;
        ui->operateress->setValue(barto);
        bar=bar+1;

        node=node.nextSibling();
        //下一个兄弟节点,节点元素
        //Sleep(1000);
    }
}

void MainWindow::gettwo(QString S1,QString flag)
{
    //打开或创建文件
    QFile file(S1); //相对路径、绝对路径、资源路径都行

    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        qDebug() << "txtwrong"<<endl;
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement(); //返回根节点
    //qDebug() << root.nodeName();

    QDomNode node = root.firstChild(); //获得第一个子节点

    node=root.firstChild();

    while(!node.isNull())  //如果节点不空
    {

        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement();
            //转换为元素，注意元素和节点是两个数据结构，其实差不多
            QString nodename = e.tagName();
            //qDebug() << "nodename" << nodename << endl;
            //打印键值对，tagName和nodeName是一个东西
            QDomNodeList list=e.childNodes();

            //QString number;
            //QString command;
            if(nodename==flag)
            {
                for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
                {
                    QDomNode n=list.at(i);
                    if(node.isElement())
                    {
                        if(n.nodeName()=="upsite")
                        {
                            getthevalue.upvalue=n.toElement().text().toInt();
                        }
                        else if(n.nodeName()=="downsite")
                        {
                            getthevalue.downvalue=n.toElement().text().toInt();
                        }
                    }

                }

                return;
            }

        node=node.nextSibling();
        //下一个兄弟节点,节点元素
        //Sleep(1000);
        }
    }
}

//seq打开路径
void MainWindow::on_seqopenbtn_clicked()
{
    QString S1="D:\\information\\sequence\\XML.txt";
    ui->seqpath->setText(S1);

    Pathtorun=S1;
}

//infor打开路径
void MainWindow::on_openinfor_clicked()
{
    QString PathName="D:\\information\\sequence\\XML.2.txt";
    QFile file(PathName);

    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        qDebug() << "filefail" << endl;
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement(); //返回根节点
    //qDebug()<<root.nodeName();

    QDomNode node=root.firstChild(); //获得第一个子节点

    int RowCount=0;

    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            RowCount=RowCount+1;
        }
        node=node.nextSibling();
        //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    ui->displaylist->setRowCount(RowCount);
    ui->displaylist->setColumnCount(header.size());
    ui->displaylist->setHorizontalHeaderLabels(header);

    node=root.firstChild(); //获得第一个子节点

    RowCount=0;

    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement();
            ui->displaylist->setItem(RowCount,0,new QTableWidgetItem(e.tagName()));

            QDomNodeList list=e.childNodes();
            for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);

                for(int j=0;j<header.size();j++)
                {
                    if(header[j]==n.nodeName())
                    {
                        ui->displaylist->setItem(RowCount,j,new QTableWidgetItem(n.toElement().text()));
                    }
                }
            }

            RowCount=RowCount+1;
        }
        node=node.nextSibling();
        //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    //还原Passn,Failn,time,yield
    passn=0;
    failn=0;
    timen=0;
    raten=0;
}

void MainWindow::Sleep(int msec)
{
     QTime dieTime = QTime::currentTime().addMSecs(msec);
     while( QTime::currentTime() < dieTime )
             QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

//计时加失败成功次数加通过率计算
void MainWindow::on_seqrunbtn_clicked()
{
    Time.start();

    Qresult.clear();

    ReadXml(Pathtorun);

    //运行程序
    displayUSB();
    displayRS();
    displayGPIB();
    displaySC();

    display();

    QRSlist.clear();
    QGPIBlist.clear();
    QUSBlist.clear();
    QSClist.clear();

    savetheresult();

    //判断结果使fail还是pass
    int flag=0;
    for(int i=0;i<ui->displaylist->rowCount();i++)
    {
       if(ui->displaylist->item(i,disendn)->text() == "Fail"){
           failn=failn+1;
           flag=1;
           break;
       }
    }

    if(!flag){
        passn=passn+1;
    }

    timen+=(double)Time.elapsed();
    //qDebug()<<Time.elapsed()/1000.0<<"s";

    ui->Passline->clear();
    ui->Falseline->clear();
    ui->Yieldline->clear();
    ui->Timeline->clear();

    ui->Passline->insert(QString::number(passn,'f',2));
    ui->Falseline->insert(QString::number(failn,'f',2));
    ui->Yieldline->insert(QString::number(passn/(passn+failn),'f',2));
    ui->Timeline->insert(QString::number(timen/1000,'f',4));
}
