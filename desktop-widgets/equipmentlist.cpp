#include <QBoxLayout>
#include <QLabel>
#include "equipmentlist.h"
#include "ui_equipmentlist.h"
#include "core/dive.h"
#include "core/helpers.h"

equipmentList::equipmentList(QWidget *parent) :
QWidget(parent),
ui(new Ui::equipmentList)
{
	//equipmentTable = new EquipmentTableModel();
	ui->setupUi(this);
	//ui->tableView->setModel(equipmentTable);
	
}

equipmentList::~equipmentList()
{
	delete ui;
}
