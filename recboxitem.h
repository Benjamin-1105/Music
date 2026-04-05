#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class RecBoxItem;
}

class RecBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit RecBoxItem(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);
    void setText(QString text);
    void setImage(QString imagePath);
    ~RecBoxItem();

private:
    Ui::RecBoxItem *ui;
};

#endif // RECBOXITEM_H
