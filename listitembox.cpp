#include "listitembox.h"
#include "ui_listitembox.h"

listItemBox::listItemBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listItemBox)
{
    ui->setupUi(this);
}

listItemBox::~listItemBox()
{
    delete ui;
}
