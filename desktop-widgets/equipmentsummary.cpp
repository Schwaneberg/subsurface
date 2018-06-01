#include "equipmentsummary.h"
#include "ui_equipmentsummary.h"

equipmentSummary::equipmentSummary(QWidget *parent) :
QWidget(parent),
ui(new Ui::equipmentSummary)
{
	ui->setupUi(this);
}

equipmentSummary::~equipmentSummary()
{
	delete ui;
}
