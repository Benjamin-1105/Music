#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include <QWidget>

namespace Ui {
class listItemBox;
}

class listItemBox : public QWidget
{
    Q_OBJECT

public:
    explicit listItemBox(QWidget *parent = nullptr);
    ~listItemBox();

private:
    Ui::listItemBox *ui;
};

#endif // LISTITEMBOX_H
