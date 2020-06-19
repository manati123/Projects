#include "MylistTableModel.h"
#include <QFont>
#include <QBrush>
#include <QColor>

const int PaginatedTableModel::ITEMS_PER_PAGE = 10;


PaginatedTableModel::PaginatedTableModel(Service& _service, QObject* parent) : QAbstractTableModel{ parent }, service{_service}
{
	this->loadedRows = 0;
}

PaginatedTableModel::~PaginatedTableModel()
{
	
}

int PaginatedTableModel::rowCount(const QModelIndex& parent) const
{
	int size = this->service.getSizeOfMyVectorService();
	if (size <= this->loadedRows)
		return size;
	return this->loadedRows;
}

int PaginatedTableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant PaginatedTableModel::data(const QModelIndex& index, int role) const
{
	std::vector<Domain> items = this->service.getMyVectorService();
	int row = index.row();
	int column = index.column();

	Domain item = items[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column) {
		case 0:
			return QString::fromStdString(item.getName());
		case 1:
			return QString::fromStdString(item.getMaterial());
		case 2:
			return item.getAge();
		case 3:
			return QString::fromStdString(item.getForm());
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}

	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{ 110, 0, 154 } };
		}
	}

	return QVariant{};
}

QVariant PaginatedTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section) {
			case 0:
				return QString{ "Name " };
			case 1:
				return QString{ "Material " };
			case 2:
				return QString{ "Age " };
			case 3:
				return QString{ "Form " };
			default:
				break;
			
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}

	return QVariant{};
}

bool PaginatedTableModel::canFetchMore(const QModelIndex& parent) const
{
	return this->service.getSizeOfMyVectorService() - this->loadedRows;
}

void PaginatedTableModel::fetchMore(const QModelIndex& parent)
{
	int remainedItems = this->service.getSizeOfMyVectorService() - this->loadedRows;

	int itemsToFetch = std::min(remainedItems, ITEMS_PER_PAGE);
	this->beginInsertRows(QModelIndex{}, this->loadedRows, this->loadedRows + itemsToFetch - 1);
	this->loadedRows += itemsToFetch;
	this->endInsertRows();

	// Uncomment - to show how many items were fetched
	//QMessageBox::information(NULL, "Time", "<font size = 20 > " + QString::number(this->loadedRows) + " items were fetched." + "</font>");
	//qDebug() << "Fetched: " << this->loadedRows;
}

