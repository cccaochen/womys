#include "landesign.h"
#include "ui_landesign.h"

LANdesign::LANdesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LANdesign)
{
    ui->setupUi(this);
}

LANdesign::~LANdesign()
{
    delete ui;
}
