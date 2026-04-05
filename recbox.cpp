#include "recbox.h"
#include "ui_recbox.h"
#include "recboxitem.h"
#include<QJsonObject>
RecBox::RecBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBox),
    row(1),
    col(4)
{
    ui->setupUi(this);
}

void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    //如果是两行
    if(2 == row)
    {
        this->row=row;
        this->col=8;
    }else{
        ui->recListDown->hide();
    }
    imageList=data;
    count = data.size()/col;
    createRecItem();
}

void RecBox::createRecItem()
{
    //先清除残留的控件和对象
    QList<RecBoxItem*> recUpList = ui->recListUp->findChildren<RecBoxItem*>();
    for(auto e : recUpList)
    {
        ui->recListUpHLayout->removeWidget(e);
        delete e;

    }
    QList<RecBoxItem*> recDownList = ui->recListDown->findChildren<RecBoxItem*>();
    for(auto e : recDownList)
    {
        ui->recListDownHLayout->removeWidget(e);
        delete e;

    }

    //创建
    int index = 0;
    for(int i = currentIndex*col; i < col + currentIndex*col; ++i)
    {
        RecBoxItem* item = new RecBoxItem();

        QJsonObject obj = imageList[i].toObject();
        item->setText(obj.value("text").toString());
        item->setImage(obj.value("path").toString());

        if(index >= col/2 && row == 2)
        {
            ui->recListDownHLayout->addWidget(item);
        }else{
            ui->recListUpHLayout->addWidget(item);
        }
        index++;
    }
}

RecBox::~RecBox()
{
    delete ui;
}

//我通过ui设计界面中跳转到槽点击click的槽函数
void RecBox::on_downPage_clicked()
{
    currentIndex++;
    if(currentIndex>count)
    {
        currentIndex=0;
    }
    createRecItem();
}

void RecBox::on_upPage_clicked()
{
    currentIndex--;
    if(currentIndex<0)
    {
        currentIndex=count-1;
    }
    createRecItem();
}
