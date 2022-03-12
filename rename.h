#ifndef RENAME_H
#define RENAME_H

#include <QWidget>

namespace Ui {
class Rename;
}

class Rename : public QWidget
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    ~Rename();

signals:
    void Namesenddata(QString);

private slots:
    void on_Okbtn_clicked();

private:
    Ui::Rename *ui;
};

#endif // RENAME_H
