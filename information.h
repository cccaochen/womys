#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class information;
}

class information : public QWidget
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = 0);
    ~information();

signals:
    void senddata(QString);

private slots:
    void on_seqbtn_clicked();

    void on_OKbtn_clicked();

private:
    void initexcel();
    void Readxml(QString PathName);
    void Writexml(QString S);

private:
    QList<QString> Qlist;
    QStringList header;
    QStringList strtend;
    QString PathName;
    Ui::information *ui;
};

#endif // INFORMATION_H
