#ifndef EQUIPMENTTABLEMODEL_H
#define EQUIPMENTTABLEMODEL_H

#include <QObject>
#include "qt-models/cleanertablemodel.h"

class EquipmentTableModel : public CleanerTableModel
{
	Q_OBJECT
public:
	enum Column {
		REMOVE,
		DESCRIPTION,
		SERIAL,
		SERVICE_STATUS,
		NOTES,
		DETAILS
	};
	
	explicit EquipmentTableModel(QObject *parent = 0);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	
	void passInData(const QModelIndex &index, const QVariant &value);
	void add();
	void clear();
	void updateDive();
	//equipment_t *equipmentAt(const QModelIndex &index);
	bool changed;
	
	public
	slots:
	void remove(const QModelIndex &index);
private:
	int rows;
};

#endif // EQUIPMENTTABLEMODEL_H
