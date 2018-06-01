#ifndef EQUIPMENTUSE_H
#define EQUIPMENTUSE_H

#include <QWidget>

namespace Ui {
class equipmentUse;
}

class equipmentUse : public QWidget
{
	Q_OBJECT
	
public:
	explicit equipmentUse(QWidget *parent = 0);
	~equipmentUse();
	
private:
	Ui::equipmentUse *ui;
};

#endif // EQUIPMENTUSE_H
