#include "information.h"
#include "ui_information.h"

#include <QFileDialog>
#include <QDebug>
#include <QDomDocument>

information::information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);

    this->setWindowTitle("Infor Design");

    initexcel();
}

information::~information()
{
    delete ui;
}

void information::initexcel()
{
    header << "project" << "value" << "uplimit" << "downlimit" << "statues" << "result";
    ui->displaytable->setRowCount(10);
    ui->displaytable->setColumnCount(header.size());
    ui->displaytable->resize(200,250);
    ui->displaytable->setHorizontalHeaderLabels(header);
}

void information::Readxml(QString PathName)
{
    QFile file(PathName);

    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        qDebug() << "filefail" <<endl;
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

    ui->displaytable->setRowCount(RowCount);
    ui->displaytable->setColumnCount(header.size());
    ui->displaytable->setHorizontalHeaderLabels(header);

    node=root.firstChild(); //获得第一个子节点

    RowCount=0;

    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            QDomElement e=node.toElement();
            ui->displaytable->setItem(RowCount,0,new QTableWidgetItem(e.tagName()));

            QDomNodeList list=e.childNodes();
            for(int i=0;i<list.count();i++)//遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode n=list.at(i);

                for(int j=0;j<header.size();j++)
                {
                    if(header[j]==n.nodeName())
                    {
                        ui->displaytable->setItem(RowCount,j,new QTableWidgetItem(n.toElement().text()));
                    }
                }
            }

            RowCount=RowCount+1;
        }
        node=node.nextSibling();
        //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
    }

    //file.close();
}

void information::on_seqbtn_clicked()
{
    Qlist.clear();

    for(int i=0;i<ui->displaytable->rowCount();i++)
    {
        for(int j=0;j<ui->displaytable->columnCount();j++)
        {
            if(ui->displaytable->item(i,j)!=NULL)
            {
                delete (ui->displaytable->item(i,j));
            }
        }
    }

    ui->displaytable->clear();

    PathName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/test",
                       tr("Text files (*.txt);;XML files (*.xml)"));
    PathName.replace("/","\\");

    Readxml(PathName);
}

void information::Writexml(QString S)
{
    QFile file(S);

    if(!file.open(QFile::WriteOnly | QFile::Truncate))
    {
        return;
    }

    QDomProcessingInstruction instruction; //添加处理命令
    QDomDocument doc;
    QDomElement root;

    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    root=doc.createElement("UIform");
    doc.appendChild(root);

    QDomElement book;
    QDomElement title;
    QDomText text;

    for(int i=0;i < ui->displaytable->rowCount();i++)
    {
        for(int j=0;j < ui->displaytable->columnCount();j++)
        {
            if(ui->displaytable->item(i,j) != NULL)
            {
                if(j==0)
                {
                    book=doc.createElement(ui->displaytable->item(i,j)->text());
                    //book.setAttribute("time",current_date);
                }
                else
                {
                    title=doc.createElement(header[j]);
                    text=doc.createTextNode(ui->displaytable->item(i,j)->text());
                    title.appendChild(text);
                    book.appendChild(title);
                }
            }
        }

        root.appendChild(book);
    }

    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();
}

void information::on_OKbtn_clicked()
{
    QString S=PathName;

    Writexml(S);
    /*
    QFile file(S);

    //qDebug() << S << endl;

    if(!file.open(QFile::WriteOnly))
    {
        //qDebug()<<"return";
        return;
    }


    QTextStream stream(&file);

    for(int i=0;i < ui->displaytable->rowCount();i++)
    {
        for(int j=0;j < ui->displaytable->columnCount();j++)
        {
            if(ui->displaytable->item(i,j) != NULL &&
                    !ui->displaytable->item(i,j)->text().isEmpty())
            {
                stream << ui->displaytable->item(i,j)->text()+"-";
            }
            else
            {
                stream << "?-";
            }
        }
        stream << endl;
    }

    file.close();
    */

    emit senddata(S);

    this->hide();
}
