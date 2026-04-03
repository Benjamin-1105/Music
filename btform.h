#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>
#include<QPropertyAnimation>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();
    void setIconAndText(const QString& Icon,const QString& text,int postId);
    int getId();
    void clearBackGroundAndAnimal();
    void showAnimal();
    void setActivePage();
signals: //每一个信号，必须在这里声明
    void btClick(int id);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    void jump_animal();
private:
    QPropertyAnimation* line1Animal;
    QPropertyAnimation* line2Animal;
    QPropertyAnimation* line3Animal;
    QPropertyAnimation* line4Animal;
    Ui::BtForm *ui;
    int id;
};

#endif // BTFORM_H
