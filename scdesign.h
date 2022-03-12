#ifndef SCDESIGN_H
#define SCDESIGN_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class SCdesign;
}

class seqdesign;

class SCdesign : public QWidget
{
    Q_OBJECT

public:
    explicit SCdesign(QWidget *parent = 0);
    ~SCdesign();

signals:
   void SCsenddata(QString);

private slots:
    void on_OpenPath_clicked();

    void on_decide_clicked();

    void receivedata(QString data);

private:
    Ui::SCdesign *ui;

    seqdesign* m_seq;
};

#endif // SCDESIGN_H
