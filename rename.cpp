#include "rename.h"
#include "ui_rename.h"

Rename::Rename(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);

    this->setWindowTitle("Rename the Seq");
}

Rename::~Rename()
{
    delete ui;
}

void Rename::on_Okbtn_clicked()
{
    if(ui->Name->text() != NULL)
    {
        emit Namesenddata(ui->Name->text());
    }

    this->hide();
}
