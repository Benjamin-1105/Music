#ifndef AI_MUSIC_H
#define AI_MUSIC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AI_Music; }
QT_END_NAMESPACE

class AI_Music : public QWidget
{
    Q_OBJECT

public:
    AI_Music(QWidget *parent = nullptr);
    ~AI_Music();

    void initUi();
    void connectSignalAndSlot();
    void onBtFormClick(int id);
    QJsonArray RandomPicture();

private slots:
    void on_quit_clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Ui::AI_Music *ui;
    QPoint dragPosition;
};
#endif // AI_MUSIC_H
