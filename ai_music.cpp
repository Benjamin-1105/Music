#include "ai_music.h"
#include "ui_ai_music.h"
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QDebug>
#include<QJsonArray>
#include<QJsonObject>
#include <algorithm> // 包含 std::shuffle
#include <random>    // 包含 std::default_random_engine
#include <ctime>     // 包含 std::time
AI_Music::AI_Music(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AI_Music)
{
    ui->setupUi(this);
    initUi();
    connectSignalAndSlot();
    //默认启动“本地下载”的跳动字符 + 页面
    //这个动作必须在connectSignalAndSlot建立信号与槽的连接之后
    ui->local->setActivePage();

    QJsonArray data = RandomPicture();
    ui->recMusicBox->initRecBoxUi(data,1);
    ui->supplyMusicBox->initRecBoxUi(data,2);
}

AI_Music::~AI_Music()
{
    delete ui;
}

void AI_Music::initUi()
{
    this->setWindowFlag(Qt::FramelessWindowHint);

    //设置窗口属性 -- 透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    //设置阴影效果
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#000000");
    shadowEffect->setBlurRadius(10);
    this->setGraphicsEffect(shadowEffect);

    //设置btform的图片和文本
    ui->Rec->setIconAndText(":/images/rec.png","推荐",0);
    ui->audio->setIconAndText(":/images/radio.png","电台",1);
    ui->music->setIconAndText(":/images/music.png","音乐馆",2);
    ui->like->setIconAndText(":/images/like.png","我喜欢",3);
    ui->local->setIconAndText(":/images/local.png","本地下载",4);
    ui->recent->setIconAndText(":/images/recent.png","最佳播放",5);
}

void AI_Music::connectSignalAndSlot()
{
    connect(ui->Rec,&BtForm::btClick,this,&AI_Music::onBtFormClick);
    connect(ui->audio,&BtForm::btClick,this,&AI_Music::onBtFormClick);
    connect(ui->music,&BtForm::btClick,this,&AI_Music::onBtFormClick);
    connect(ui->like,&BtForm::btClick,this,&AI_Music::onBtFormClick);
    connect(ui->local,&BtForm::btClick,this,&AI_Music::onBtFormClick);
    connect(ui->recent,&BtForm::btClick,this,&AI_Music::onBtFormClick);
}

void AI_Music::onBtFormClick(int id)
{
    //恢复其他界面的样式
    QList<BtForm*> buttonList = this->findChildren<BtForm*>(); //获取到所有BtForm类型的按键对象
    for(auto btitem : buttonList)
    {
        if(id != btitem->getId())
        {
            btitem->clearBackGroundAndAnimal();
        }
    }
    //切换界面
    ui->stackedWidget->setCurrentIndex(id);
}

QJsonArray AI_Music::RandomPicture()
{
    QVector<QString> vecImageName;
    vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"<<"008.png"
                <<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"<<"014.png"<<"015.png"
                <<"016.png"<<"017.png"<<"018.png"<<"019.png"<<"020.png"<<"021.png"<<"022.png"
                <<"023.png"<<"024.png"<<"025.png"<<"026.png"<<"027.png"<<"028.png"<<"029.png"
                <<"030.png"<<"031.png"<<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"
                <<"037.png"<<"038.png"<<"039.png"<<"040.png";
    // 1. 创建一个随机数生成器引擎。   使用当前时间作为种子 (seed)，确保每次启动程序时种子都不同
    std::default_random_engine engine(static_cast<unsigned int>(std::time(0)));

    // 2. 使用 std::shuffle 进行乱序。  它需要三个参数：起始迭代器、结束迭代器、随机引擎
    std::shuffle(vecImageName.begin(), vecImageName.end(), engine);

    QJsonArray objArray;
    for(int i=0;i<vecImageName.size();i++)
    {
        QJsonObject obj;
        obj.insert("path", ":/images/rec/"+vecImageName[i]);
        QString text = QString("推荐-%1").arg(i, 3, 10, QChar('0'));
        obj.insert("text",text);
        objArray.append(obj);
    }
    return objArray;
}


void AI_Music::on_quit_clicked()
{
    close();
}

void AI_Music::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button()){
        dragPosition = event->globalPos() - geometry().topLeft();
        return;
    }
    //这个的意思是，我重写了左键按下的响应，对于其他响应，我不做处理，交给父类来完成。我不抹除父类的实现。
    QWidget::mousePressEvent(event);
}

void AI_Music::mouseMoveEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->buttons()){
        move(event->globalPos() - dragPosition);
        return;
    }
    QWidget::mouseMoveEvent(event);
}
