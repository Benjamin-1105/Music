#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include <QJsonArray>
namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    void initRecBoxUi(QJsonArray data,int row);
    void createRecItem();
    ~RecBox();

private slots:
    void on_downPage_clicked();

    void on_upPage_clicked();

private:
    Ui::RecBox *ui;
    int row; //总行数
    int col; //每行有多少个元素
    int currentIndex; //第几组
    int count; //总组数
    QJsonArray imageList;
};

#endif // RECBOX_H
