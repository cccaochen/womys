#ifndef LANDESIGN_H
#define LANDESIGN_H

#include <QWidget>

namespace Ui {
class LANdesign;
}

class LANdesign : public QWidget
{
    Q_OBJECT

public:
    explicit LANdesign(QWidget *parent = 0);
    ~LANdesign();

private:
    Ui::LANdesign *ui;
};

#endif // LANDESIGN_H
