#include "scdesign.h"
#include "ui_scdesign.h"

__declspec(dllimport) void opensequence(const char* seq);

SCdesign::SCdesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCdesign)
{
    ui->setupUi(this);

    this->setWindowTitle("Soundcheck Design");
}

SCdesign::~SCdesign()
{
    delete ui;
}

void SCdesign::on_OpenPath_clicked()
{
    ui->SeqPath->clear();

    QString s = QFileDialog::getOpenFileName(
                    this, "选择要运行的程序",
                    "/",
                    ".音频文件 (*.sqc );; 所有文件 (*.*);; ");

    s.replace("/","\\");

    ui->SeqPath->insert(s);
}



void SCdesign::on_decide_clicked()
{
    QString str="SC-"+ui->SeqPath->text()+"-"+ui->cutup->text()+"-"+ui->cutdown->text();

    emit SCsenddata(str);

    this->hide();
}

void SCdesign::receivedata(QString data)
{
    ui->SeqPath->clear();

    QStringList str=data.split("-");

    QString s=str[1];
    ui->SeqPath->setText(s);
    s=str[2];
    ui->cutup->setText(s);
    s=str[3];
    ui->cutdown->setText(s);
}
