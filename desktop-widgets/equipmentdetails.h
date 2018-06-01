#ifndef EQUIPMENTDETAILS_H
#define EQUIPMENTDETAILS_H

#include <QWidget>

namespace Ui {
class equipmentDetails;
}

class equipmentDetails : public QWidget
{
	Q_OBJECT
	
public:
	explicit equipmentDetails(QWidget *parent = 0);
	~equipmentDetails();
	
private:
	Ui::equipmentDetails *ui;
};

#endif // EQUIPMENTDETAILS_H
