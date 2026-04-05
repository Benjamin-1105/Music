#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QPropertyAnimation>
#include <QDebug>
RecBoxItem::RecBoxItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);

    //添加事件拦截器
    ui->musicImageBox->installEventFilter(this);
}

bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->musicImageBox)
    {
        int ImgWidget = ui->musicImageBox->width();
        int ImgHeight = ui->musicImageBox->height();

        if(event->type() == QEvent::Enter)
        {
            QPropertyAnimation* animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(100);
            animation->setStartValue(QRect(0,9,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(0,0,ImgWidget,ImgHeight));
            animation->start();
            //做完动画之后，删除animation
            connect(animation,&QPropertyAnimation::finished,this,[=](){
                delete animation;
            });
            return true;
        }else if(event->type() == QEvent::Leave)
        {
            QPropertyAnimation* animation = new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(100);
            animation->setStartValue(QRect(0,0,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(0,9,ImgWidget,ImgHeight));
            animation->start();
            //做完动画之后，删除animation
            connect(animation,&QPropertyAnimation::finished,this,[=](){
                delete animation;
            });
            return true;
        }
    }
    //如果不是自己要处理的控件，让QObject来执行eventFiler
    return QObject::eventFilter(watched,event);
}

void RecBoxItem::setText(QString text)
{
    ui->recBoxItemText->setText(text);
}

void RecBoxItem::setImage(QString imagePath)
{
    QString imgStyle = "border-image:url("+imagePath+");";
    ui->recMusicImage->setStyleSheet(imgStyle);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}
