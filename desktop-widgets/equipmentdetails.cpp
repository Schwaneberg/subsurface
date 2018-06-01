#include "equipmentdetails.h"
#include "ui_equipmentdetails.h"

equipmentDetails::equipmentDetails(QWidget *parent) :
QWidget(parent),
ui(new Ui::equipmentDetails)
{
	ui->setupUi(this);
}

equipmentDetails::~equipmentDetails()
{
	delete ui;
}
