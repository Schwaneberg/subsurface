#include <QStyleOptionButton>
#include "core/dive.h"
#include "core/gettextfromc.h"
#include "core/metrics.h"
#include "core/helpers.h"
#include "qt-models/equipmenttablemodel.h"

EquipmentTableModel::EquipmentTableModel(QObject *parent) : CleanerTableModel(parent),
changed(false), rows(0)
{
	/* First column is for delete button and last for details button */
	setHeaderDataStrings(QStringList() << tr("") << tr("Description") 
	<< tr("Serial") << tr("Service status") << tr("Notes") << tr(""));
}

void EquipmentTableModel::clear()
{
	if (rows > 0) {
		beginRemoveRows(QModelIndex(), 0, rows - 1);
		endRemoveRows();
	}
}

void EquipmentTableModel::remove(const QModelIndex &index)
{
	if (index.column() != REMOVE) {
		return;
	}
	beginRemoveRows(QModelIndex(), index.row(), index.row()); // yah, know, ugly.
	rows--;
	//remove_regulator(&displayed_dive, index.row());
	changed = true;
	endRemoveRows();
}

QVariant EquipmentTableModel::data(const QModelIndex &index, int role) const
{
	QVariant ret;
	//TODO OLLI
	switch (role) {
		case Qt::DecorationRole:
			if (index.column() == REMOVE)
				ret = trashIcon();
				
			break;
	}

	return ret;
}

bool EquipmentTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	//TODO OLLI
	return true;
}

int EquipmentTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return rows;
}

void EquipmentTableModel::add()
{
	int row = rows;
	beginInsertRows(QModelIndex(), row, row);
	rows++;
	changed = true;
	endInsertRows();
}
