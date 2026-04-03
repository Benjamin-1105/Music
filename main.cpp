#include "ai_music.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AI_Music w;
    w.show();
    return a.exec();
}
