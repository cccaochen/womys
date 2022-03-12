#include "seqdesign.h"
#include "ui_seqdesign.h"

#include <rename.h>
#include <ratedesign.h>
#include <usbdesign.h>
#include <gpibdesign.h>
#include <scdesign.h>

seqdesign::seqdesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seqdesign),
    m_name(new Rename),
    m_rate(new ratedesign),
    m_GPIB(new GPIBdesign),
    m_USB(new USBdesign),
    m_SC(new SCdesign)
{
    ui->setupUi(this);

    this->setWindowTitle("Sequence Design");

    connectinit();
}

seqdesign::~seqdesign()
{
    delete ui;
}

void seqdesign::connectinit()
{
    ui->outputorder->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_name,SIGNAL(Namesenddata(QString)),this,SLOT(NamereceiveData(QString)));
    connect(m_rate,SIGNAL(ratesenddata(QString)),this,SLOT(ratereceiveData(QString)));
    connect(m_GPIB,SIGNAL(GPIBsenddata(QString)),this,SLOT(GPIBreceiveData(QString)));
    connect(m_USB,SIGNAL(USBsenddata(QString)),this,SLOT(USBreceiveData(QString)));
    connect(m_SC,SIGNAL(SCsenddata(QString)),this,SLOT(SCreceiveData(QString)));

    connect(this,SIGNAL(senddataGPIB(QString)),m_GPIB,SLOT(receivedata(QString)));
    connect(this,SIGNAL(senddataUSB(QString)),m_USB,SLOT(receivedata(QString)));
    connect(this,SIGNAL(senddataSC(QString)),m_SC,SLOT(receivedata(QString)));
    connect(this,SIGNAL(senddataRS(QString)),m_rate,SLOT(receivedata(QString)));
}

//init the UIPart
void seqdesign::initUIpart()
{
    setWindowTitle("Sequence Programming Interface");

    ui->outputorder->setStyleSheet("background-color : white;border-color : yellow");
    ui->outputorder->setStyleSheet("font-size : 20px;");

    ui->inputorder->setStyleSheet("background-color : white;border-color : yellow");
    ui->inputorder->setStyleSheet("font-size : 20px;");

    ui->intoseq->setStyleSheet("background-color:beige;border-color : white");
    ui->outseq->setStyleSheet("background-color:beige;border-color : white");
    ui->SaveButton->setStyleSheet("background-color:beige;border-color : white");
}

void seqdesign::WriteXml(QString S1)
{
    //打开文件
    QFile file(S1); //相对路径、绝对路径、资源路径都可以

    if(!file.open(QIODevice::Truncate | QIODevice::ReadWrite))
        return;

    //增加一个一级子节点以及元素
    QDomDocument doc;//xml header
    QDomElement root;//xml body(树状结构根节点)

    QDomElement seq;
    QDomElement title;//子元素
    QDomText text; //子元素标签

    //写入xml头部
    QDomProcessingInstruction instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    root=doc.createElement("sequence");
    doc.appendChild(root);

    //qDebug()<<"seqdata.size="<<seqdata.size()<<endl;
    for(int i=0;i<seqdata.size();i++)
    {
        //stream<<seqdata[i]<<endl;文件存储改用XML格式制作
        QString str=seqdata[i];
        QStringList strtend=str.split("-");

        if(strtend[0]=="SC")
        {
            //存储结构位SC+执行程序的字符串
            seq=doc.createElement(strtend[0]);

            title=doc.createElement("command"); //添加command
            text=doc.createTextNode(strtend[1]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);//节点添加子元素

            title=doc.createElement("upsite");//添加upsite
            text=doc.createTextNode(strtend[2]);
            title.appendChild(text);

            seq.appendChild(title);

            title=doc.createElement("downsite");//添加downsite
            text=doc.createTextNode(strtend[3]);
            title.appendChild(text);

            seq.appendChild(title);
        }
        else if(strtend[0]=="USB")
        {
            //存储结构USB+设备序列号+执行命令
            seq=doc.createElement(strtend[0]);

            title=doc.createElement("equipment"); //创建子元素
            text=doc.createTextNode(strtend[1]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);

            QDomElement title2=doc.createElement("command");//子元素
            text=doc.createTextNode(strtend[2]); //子元素标签
            title2.appendChild(text);

            seq.appendChild(title2);//节点添加子元素

            title=doc.createElement("upsite"); //创建子元素
            text=doc.createTextNode(strtend[3]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);

            title=doc.createElement("downsite"); //创建子元素
            text=doc.createTextNode(strtend[4]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);
        }
        else if(strtend[0]=="GPIB")
        {
            //存储结构GPIB+设备序列号+执行命令
            seq=doc.createElement(strtend[0]);

            title=doc.createElement("equipment"); //创建子元素
            text=doc.createTextNode(strtend[1]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);

            QDomElement title2=doc.createElement("command");//子元素
            text=doc.createTextNode(strtend[2]); //子元素标签
            title2.appendChild(text);

            seq.appendChild(title2);//节点添加子元素

            title=doc.createElement("upsite"); //创建子元素
            text=doc.createTextNode(strtend[3]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);

            title=doc.createElement("downsite"); //创建子元素
            text=doc.createTextNode(strtend[4]);//文本创建
            title.appendChild(text);//子元素添加文本

            seq.appendChild(title);
        }
        else if(strtend[0]=="RS232")
        {
            //存储结构RS232+COM口+波特率+data位+奇偶位+停止位+流控制方法+执行命令
            seq=doc.createElement(strtend[0]);

            title=doc.createElement("COM端口");
            text=doc.createTextNode(strtend[1]);
            title.appendChild(text);

            seq.appendChild(title);

            QDomElement title2=doc.createElement("Baudrate");
            text=doc.createTextNode(strtend[2]);
            title2.appendChild(text);

            seq.appendChild(title2);//节点添加子元素

            QDomElement title3=doc.createElement("Databits");//子元素
            text=doc.createTextNode(strtend[3]); //子元素标签
            title3.appendChild(text);

            seq.appendChild(title3);//节点添加子元素

            QDomElement title4=doc.createElement("Parity");//子元素
            text=doc.createTextNode(strtend[4]); //子元素标签
            title4.appendChild(text);

            seq.appendChild(title4);//节点添加子元素

            QDomElement title5=doc.createElement("Stopbits");//子元素
            text=doc.createTextNode(strtend[5]); //子元素标签
            title5.appendChild(text);

            seq.appendChild(title5);//节点添加子元素

            QDomElement title6=doc.createElement("Flowcontrol");//子元素
            text=doc.createTextNode(strtend[6]); //子元素标签
            title6.appendChild(text);

            seq.appendChild(title6);//节点添加子元素

            QDomElement title7=doc.createElement("command");//子元素
            text=doc.createTextNode(strtend[7]); //子元素标签
            title7.appendChild(text);

            seq.appendChild(title7);//节点添加子元素

            QDomElement title8=doc.createElement("upsite");//子元素
            text=doc.createTextNode(strtend[8]); //子元素标签
            title8.appendChild(text);

            seq.appendChild(title8);//节点添加子元素

            QDomElement title9=doc.createElement("downsite");//子元素
            text=doc.createTextNode(strtend[9]); //子元素标签
            title9.appendChild(text);

            seq.appendChild(title9);//节点添加子元素
        }

        root.appendChild(seq);
    }
    //解决文件存储问题
    QTextStream out_stream(&file);
    doc.save(out_stream,4);

    file.close();
}

void seqdesign::WriteXmlhead(QString S2)
{
    //打开文件
    QFile file(S2); //相对路径、绝对路径、资源路径都可以

    if(!file.open(QIODevice::Truncate | QIODevice::ReadWrite))
        return;

    //增加一个一级子节点以及元素
    QDomDocument doc;//xml header
    QDomElement root;//xml body(树状结构根节点)

    QDomElement title;//子元素
    //QDomText text; //子元素标签

    //写入xml头部
    QDomProcessingInstruction instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    root=doc.createElement("sequence");
    doc.appendChild(root);

    for(int i=0;i < ui->outputorder->count();i++)
    {
        title=doc.createElement(ui->outputorder->item(i)->text());
        root.appendChild(title);
    }

    //解决文件存储问题
    QTextStream out_stream(&file);
    doc.save(out_stream,4);

    file.close();
}

//最后存储的步骤
void seqdesign::on_SaveButton_clicked()
{
    QString PathName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                "/test",
              tr("Text files (*.txt);;XML files (*.xml)"));
    PathName.replace("/","\\");

    QString S1=PathName;
    ui->SavePath->setText(S1);

    //seq的存储结构++++
    WriteXml(S1);
    //seq的存储XML类型

    //将information里面的变为XML格式存储
    QString S2=S1.left(S1.count()-3)+"2.txt";

    //qDebug()<<"S2="<<S2<<endl;
    WriteXmlhead(S2);

    //clear
    seqdata.clear();

    for(int i=0;i<ui->outputorder->count();i++)
    {
        delete (ui->outputorder->item(i));
    }

    ui->outputorder->clear();
}

//seqdata操作
void seqdesign::on_intoseq_clicked()
{
    qDebug() << ui->inputorder->currentRow();

    if(ui->inputorder->currentRow() != -1)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(ui->inputorder->currentItem()->text());
        int tend= 0;

        qDebug() << "tend=" << tend;

        if(ui->outputorder->currentRow()!=-1)
        {
            tend=ui->outputorder->currentRow()+1;
        }
        else
        {
            if(ui->outputorder->count()!= 0)
            {
                tend=ui->outputorder->count();
            }
        }

        qDebug() << "tend=" << tend;

        ui->outputorder->insertItem(tend,item);

        seqdata.append(ui->outputorder->item(tend)->text());
    }
}

void seqdesign::on_outseq_clicked()
{
    int tend=ui->outputorder->currentRow();
    if(tend != -1)
    {
        if(seqdata.size() == ui->outputorder->count())
        {
               seqdata.removeAt(tend);
        }

        QListWidgetItem* item=ui->outputorder->takeItem(tend);
        delete item;
    }
}

void seqdesign::on_upbtn_clicked()
{
    int tend=ui->outputorder->currentRow()-1;

    if(tend >= 0)
    {
        if(seqdata.size() == ui->outputorder->count())
        {
            seqdata.swap(tend,tend+1);
        }

        QListWidgetItem* item1=ui->outputorder->item(tend);

        QListWidgetItem* item2=ui->outputorder->item(tend+1);

        QString tendstr=item1->text();
        ui->outputorder->item(tend)->setText(item2->text());
        ui->outputorder->item(tend+1)->setText(tendstr);

        item1=nullptr;
        item2=nullptr;
    }
}

void seqdesign::on_downbtn_clicked()
{
    int tend=ui->outputorder->currentRow()+1;

    if(tend > 0 && tend < ui->outputorder->count())
    {
        if(seqdata.size() == ui->outputorder->count())
        {
            seqdata.swap(tend,tend-1);
        }

        QListWidgetItem* item1=ui->outputorder->item(tend);

        QListWidgetItem* item2=ui->outputorder->item(tend-1);

        QString tendstr=item1->text();

        item1->setText(item2->text());
        item2->setText(tendstr);
    }
}

//传递data参数
void seqdesign::NamereceiveData(QString data)
{
    if(ui->outputorder->currentRow()!=-1)
    {
        QListWidgetItem* item1=ui->outputorder->currentItem();
        QString stra=item1->text();

        QStringList list=stra.split("-");
        QString str=list[0]+"-"+data;
        ui->outputorder->currentItem()->setText(str);
    }
}

void seqdesign::SCreceiveData(QString data)
{
     int n=ui->outputorder->currentRow();

     qDebug()<<"n="<<n<<endl;

     if(seqdata.count() >= ui->outputorder->currentRow())
     {
         seqdata.replace(n,data);
     }
     else
     {
         seqdata.insert(n,data);
     }
}

void seqdesign::GPIBreceiveData(QString data)
{
     int n=ui->outputorder->currentRow();

     if(seqdata.count() >= ui->outputorder->currentRow())
     {
         seqdata.replace(n,data);
     }
     else
     {
         seqdata.insert(n,data);
     }
}

void seqdesign::USBreceiveData(QString data)
{
    int n=ui->outputorder->currentRow();

    if(seqdata.count() >= ui->outputorder->currentRow())
    {
        seqdata.replace(n,data);
    }
    else
    {
        seqdata.insert(n,data);
    }
}

void seqdesign::ratereceiveData(QString data)
{
    int n=ui->outputorder->currentRow();

    if(seqdata.count() >= ui->outputorder->currentRow())
    {
        seqdata.replace(n,data);
    }
    else
    {
        seqdata.insert(n,data);
    }
}

void seqdesign::on_outputorder_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu* menu=new QMenu(this);
    QAction* mname=new QAction("remane",this);
    connect(mname,&QAction::triggered,m_name,&Rename::show);

    menu->addAction(mname);
    menu->move(QCursor::pos());
    menu->show();
}

void seqdesign::on_outputorder_itemDoubleClicked(QListWidgetItem *item)
{
    //int i=ui->outputorder->currentRow();

    QString str=item->text();
    QStringList strlist=str.split("-");
    QString strd=strlist[0];

    if(strd == "RS232")
    {
        //emit senddataRS(str);

        m_rate->show(); 
    }
    else if(strd == "SC")
    {
        //emit senddataSC(str);

        m_SC->show();
    }
    else if(strd == "USB")
    {
        //emit senddataUSB(str);

        m_USB->show();
    }
    else if(strd == "GPIB")
    {
        //emit senddataGPIB(str);//修改为当前对应列

        m_GPIB->show();
    }
}

void seqdesign::on_openbtn_clicked()
{
    seqdata.clear();

    QString PathName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/test",
                       tr("Text files (*.txt);;XML files (*.xml)"));
    PathName.replace("/","\\");

    QString S1=PathName;
    ui->openline->setText(S1);

    //将xml的文件内容转化为seqdata的字符串数组
    QFile file1(S1);

    if(!file1.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file1))
    {
        qDebug() << "txtwrong"<<endl;
        file1.close();
        return;
    }

    file1.close();

    QDomElement root=doc.documentElement(); //返回根节点
    //qDebug() << root.nodeName();

    QDomNode node = root.firstChild(); //获得第一个子节点

    int num=0;
    while(!node.isNull())  //如果节点不空
    {
        QString strtend="";
        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement();
            //转换为元素，注意元素和节点是两个数据结构，其实差不多
            QString nodename = e.tagName();
            //qDebug() << "nodename" << nodename << endl;
            //打印键值对，tagName和nodeName是一个东西
            strtend=strtend+nodename+"-";

            QDomNodeList list=e.childNodes();

            for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);
                strtend=strtend+n.toElement().text()+"-";
            }
        }

        qDebug() << "strtend=" << strtend << endl;
        seqdata.append(strtend);

        QStringList str=strtend.split("-");
        QString s=str[0];

        if(s=="SC")
        {
            emit senddataSC(seqdata.at(num));
        }
        else if(s=="RS232")
        {
            emit senddataRS(seqdata.at(num));
        }
        else if(s=="USB")
        {
            emit senddataUSB(seqdata.at(num));
        }
        else if(s=="GPIB")
        {
            emit senddataGPIB(seqdata.at(num));
        }

        num=num+1;

        node=node.nextSibling();
    }

    QString S2=S1.left(S1.count()-3)+"2.txt";

    QFile file2(S2);

    if(!file2.open(QFile::ReadOnly))
        return;

     QDomDocument doc2;
    if(!doc2.setContent(&file2))
    {
        qDebug() << "txtwrong"<<endl;
        file2.close();
        return;
    }
    file2.close();

    //将outputorder填写完成

    QDomElement root2=doc2.documentElement(); //返回根节点
    //qDebug() << root.nodeName();

    QDomNode node2 = root2.firstChild(); //获得第一个子节点

    int ordern=0;
    while(!node2.isNull())  //如果节点不空
    {

        if(node2.isElement()) //如果节点是元素
        {
            QDomElement e=node2.toElement();
            //转换为元素，注意元素和节点是两个数据结构，其实差不多
            QString nodename = e.tagName();
            //qDebug() << "nodename" << nodename << endl;
            //打印键值对，tagName和nodeName是一个东西
            ui->outputorder->insertItem(ordern,new QListWidgetItem(nodename));

            ordern=ordern+1;
        }
        node2=node2.nextSibling();
    }
}
