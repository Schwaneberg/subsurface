#include "equipmentuse.h"
#include "ui_equipmentuse.h"

equipmentUse::equipmentUse(QWidget *parent) :
QWidget(parent),
ui(new Ui::equipmentUse)
{
	ui->setupUi(this);
}

equipmentUse::~equipmentUse()
{
	delete ui;
}
