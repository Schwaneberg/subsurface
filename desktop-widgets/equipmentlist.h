#ifndef EQUIPMENTLIST_H
#define EQUIPMENTLIST_H

#include <QWidget>
#include "qt-models/equipmenttablemodel.h"

namespace Ui {
class equipmentList;
}

class equipmentList : public QWidget
{
public:
	explicit equipmentList(QWidget *parent = 0);
	~equipmentList();
	
private:
	Ui::equipmentList *ui;
	EquipmentTableModel *equipmentTable;
};

#endif // EQUIPMENTLIST_H
