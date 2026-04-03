#include "btform.h"
#include "ui_btform.h"
#include <QMouseEvent>

BtForm::BtForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtForm)
{
    ui->setupUi(this);

    //隐藏linebox + 跳动音符的动画
    QSizePolicy sp = ui->lineBox->sizePolicy();// 1. 获取当前的 policy 策略
    sp.setRetainSizeWhenHidden(true);// 2. 修改这个 policy 策略副本，将控件给预留下来。不能被其他控件挤占
    ui->lineBox->setSizePolicy(sp);// 3. 将修改后的 policy 重新设置给控件
    ui->lineBox->hide();
    jump_animal();

}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::setIconAndText(const QString &Icon, const QString &text, int postId)
{
    ui->btIcon->setPixmap(QPixmap(Icon));
    ui->btText->setText(text);
    this->id=postId;
}

int BtForm::getId()
{
    return this->id;
}

void BtForm::clearBackGroundAndAnimal()
{
    ui->btStyle->setStyleSheet("#btStyle:hover{background:#D8D8D8;}");
    ui->lineBox->hide();
}

void BtForm::showAnimal()
{
    ui->lineBox->show();
}

//这个setActivePage函数目的，让ai_music主界面，在初始化/切换时候，可以设置显示哪一个界面，哪一个按钮变色，哪一个按钮显示动画条
void BtForm::setActivePage()
{
    // 1. 改变背景颜色和文字颜色
    ui->btStyle->setStyleSheet("#btStyle{background:rgba(30,206,154,0.6);}");

    // 2. 显示动画条
    ui->lineBox->show();

    // 3. 发送信号通知父窗口切换页面
    emit btClick(this->id);
}

void BtForm::mousePressEvent(QMouseEvent *event)
{
    //背景变为绿色，文字变为白色
    ui->btStyle->setStyleSheet("#btStyle{background:rgba(30,206,154,0.6);}");
    ui->lineBox->show();//显示动画条
    emit btClick(this->id); //发送鼠标点击信号
    event->accept(); //3. 关键：接受事件，阻止它传递给父窗口 AI_Music
}

void BtForm::mouseMoveEvent(QMouseEvent *event)
{
    // 关键：拦截移动事件，什么都不做，直接 accept
    // 这样父窗口 AI_Music 就收不到这个移动信号，也就不会触发 move()
    event->accept();
}

void BtForm::jump_animal()
{
    line1Animal = new QPropertyAnimation(ui->line1,"geometry",this);
    line1Animal->setDuration(1500); //一次动画的持续时间，1.5秒
    line1Animal->setKeyValueAt(0,QRect(0,30,2,0)); //起始状态
    line1Animal->setKeyValueAt(0.5,QRect(0,10,2,20)); //中间状态
    line1Animal->setKeyValueAt(1,QRect(0,30,2,0)); //最终状态
    line1Animal->setLoopCount(-1); //无限循环
    line1Animal->start();

    line2Animal = new QPropertyAnimation(ui->line2,"geometry",this);
    line2Animal->setDuration(1700); //一次动画的持续时间
    line2Animal->setKeyValueAt(0,QRect(7,30,2,0)); //起始状态
    line2Animal->setKeyValueAt(0.5,QRect(7,10,2,20)); //中间状态
    line2Animal->setKeyValueAt(1,QRect(7,30,2,0)); //最终状态
    line2Animal->setLoopCount(-1); //无限循环
    line2Animal->start();

    line3Animal = new QPropertyAnimation(ui->line3,"geometry",this);
    line3Animal->setDuration(1900); //一次动画的持续时间
    line3Animal->setKeyValueAt(0,QRect(14,30,2,0)); //起始状态
    line3Animal->setKeyValueAt(0.5,QRect(14,10,2,20)); //中间状态
    line3Animal->setKeyValueAt(1,QRect(14,30,2,0)); //最终状态
    line3Animal->setLoopCount(-1); //无限循环
    line3Animal->start();

    line4Animal = new QPropertyAnimation(ui->line4,"geometry",this);
    line4Animal->setDuration(2100); //一次动画的持续时间
    line4Animal->setKeyValueAt(0,QRect(21,30,2,0)); //起始状态
    line4Animal->setKeyValueAt(0.5,QRect(21,10,2,20)); //中间状态
    line4Animal->setKeyValueAt(1,QRect(21,30,2,0)); //最终状态
    line4Animal->setLoopCount(-1); //无限循环
    line4Animal->start();
}
