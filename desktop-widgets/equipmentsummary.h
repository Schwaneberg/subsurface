#ifndef EQUIPMENTSUMMARY_H
#define EQUIPMENTSUMMARY_H

#include <QWidget>

namespace Ui {
class equipmentSummary;
}

class equipmentSummary : public QWidget
{
	Q_OBJECT
	
public:
	explicit equipmentSummary(QWidget *parent = 0);
	~equipmentSummary();
	
private:
	Ui::equipmentSummary *ui;
};

#endif // EQUIPMENTSUMMARY_H
