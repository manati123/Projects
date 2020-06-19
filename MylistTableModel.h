#pragma once
#include <QAbstractItemModel>
#include "Repo.h"
#include "Domain.h"
#include "Service.h"
#include <QVariant>

class PaginatedTableModel : public QAbstractTableModel
{
private:
	Service& service;
	static const int ITEMS_PER_PAGE;

	int loadedRows; // count how many rows were loaded

public:
	PaginatedTableModel(Service& _service, QObject* parent = NULL);
	~PaginatedTableModel();

	// number of rows
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;

	// number of columns
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;

	// Value at a given position
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	// add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


protected:
	bool canFetchMore(const QModelIndex& parent) const override;
	void fetchMore(const QModelIndex& parent) override;



};
