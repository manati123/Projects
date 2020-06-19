#include "TheLastStand.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "RepositoryExceptions.h"
#include "DomainValidator.h"
#include <QLabel>
#include <qwidget.h>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>

TheLastStand::TheLastStand( Service _service, bool check,  QWidget* parent)
    : QMainWindow(parent), service{_service}, memOrfile{check}
{
    ui.setupUi(this);
    this->init();
    this->connectSignalsAndSlots();
    this->populateItemsList();
}

void TheLastStand::addItemButtonHandler()
{
    try {
        QString name = ui.Name->text();
        QString form = ui.Form->text();
        QString material = ui.Material->text();
        QString age = ui.Age->text();
        ui.Name->clear();
        ui.Form->clear();
        ui.Age->clear();
        ui.Material->clear();
        if (fileRepoName != "" && this->memOrfile == false)
            this->service.writeToFile(this->fileRepoName);
        emit addItemSignal(age.toInt(), name.toStdString(), form.toStdString(), material.toStdString());
    }
    catch (RepositoryExceptionsInherited exception) {
        QMessageBox msgBox;
        msgBox.setText(exception.what());
        msgBox.exec();
    }
    catch (ValidationExceptionInherited exception) {
        QMessageBox msgBox;
        msgBox.setText(exception.what());
        msgBox.exec();

    }
}

void TheLastStand::deleteItemButtonHandler()
{
    int index = this->getSelectedIndex();

    if (index < 0 || index >= this->service.getRepoService().size())
        return;

    Domain item = this->service.getRepoService()[index];
    this->service.deleteService(item.getName());
    ui.Name->clear();
    ui.Form->clear();
    ui.Age->clear();
    ui.Material->clear();
    if (fileRepoName != "" && this->memOrfile == false)
        this->service.writeToFile(this->fileRepoName);
    emit itemsUpdatedSignal();
}

void TheLastStand::updateItemButtonHandler()
{
    QString name = ui.Name->text();
    QString form = ui.Form->text();
    QString material = ui.Material->text();
    QString age = ui.Age->text();
    this->service.updateService( name.toStdString(), form.toStdString(), material.toStdString(), age.toInt());
    ui.Name->clear();
    ui.Form->clear();
    ui.Age->clear();
    ui.Material->clear();
    if (fileRepoName != "" && this->memOrfile == false)
        this->service.writeToFile(this->fileRepoName);
        
    emit itemsUpdatedSignal();
}

void TheLastStand::fileRepoSelectorButtonHandler()
{
   /* QMessageBox box;
    box.setText(ui.fileRepoEdit->text());*/
    //box.exec();
    try {
        this->service.readFromFile(ui.fileRepoEdit->text().toStdString());
        fileRepoName = ui.fileRepoEdit->text().toStdString();
        emit itemsUpdatedSignal();
    }
    catch (RepositoryExceptionsInherited exception) {
        QMessageBox box;
        box.setText(QString::fromStdString(exception.what()));
        box.exec();
    }
}




void TheLastStand::htmlCsvRepoButtonHandler()
{
    
    std::string file = ui.htmlOrCSVEdit->text().toStdString();
    this->file = file;
    char buffer[6];
    std::size_t length = file.copy(buffer, -1, file.size() - 4);
    buffer[length] = '\0';
    if (strcmp(buffer, "html") == 0)
        this->fileType = "html";
    else
        if (strcmp(buffer, ".csv") == 0)
            this->fileType = "csv";

    QMessageBox box;
    box.setText(QString::fromStdString(this->file));
    box.exec();
}

void TheLastStand::nextButtonHandler()
{
    QMessageBox box;
    //Domain item;
    box.setText(QString::fromStdString(this->service.nextService().toString().str()));
    box.exec();

}

void TheLastStand::saveButtonHandler()
{
    if(ui.modeBItem->count() != 0)
        ui.modeBItem->clear();
    std::vector<Domain> vector = this->service.getMyVectorService();
    this->service.saveService(ui.Name->text().toStdString());
    for (auto& item : vector) {
        QString itemInList = QString::fromStdString(item.toString().str());
        QFont font{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(font);
        ui.modeBItem->addItem(item);
    }
}

void TheLastStand::filterButtonHandler()
{
    if (ui.modeBItem->count() != 0)
        ui.modeBItem->clear();

    int age = ui.Age->text().toInt();
    std::string material = ui.Material->text().toStdString();
    QMessageBox box;
    box.setText(QString::fromStdString(material));
    box.exec();
    std::vector<Domain> vector = this->service.getAllByMaterialAndLesserValueService(material, age);
    for (auto& item : vector) {
        QString itemInList = QString::fromStdString(item.toString().str());
        QFont font{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(font);
        ui.modeBItem->addItem(item);
    }
}

void TheLastStand::undoButtonHandler()
{
    this->service.undo();

    emit itemsUpdatedSignal();
}
void TheLastStand::redoButtonHandler()
{
    this->service.redo();
    emit itemsUpdatedSignal();
}

void TheLastStand::modeAButtonHandler()
{
    ui.listButton->hide();
    ui.filterButton->hide();
    ui.nextButton->hide();
    ui.modeBItem->hide();
    ui.saveButton->show();
    ui.deleteButton->show();
    ui.updateButton->show();
    ui.addButton->show();
    ui.itemsList->show();
    ui.Name->show();
    ui.Form->show();
    ui.Age->show();
    ui.Material->show();
    
}

void TheLastStand::modeBButtonHandler()
{
    ui.saveButton->hide();
    ui.deleteButton->hide();
    ui.updateButton->hide();
    ui.addButton->hide();
    ui.itemsList->hide();
    ui.Name->hide();
    ui.Form->hide();
    ui.Age->hide();
    ui.Material->hide();
    ui.listButton->show();
    ui.filterButton->show();
    ui.nextButton->show();
    ui.modeBItem->show();
}

int TheLastStand::getSelectedIndex()
{
    if (ui.itemsList->count() == 0)
        return -1;

    QModelIndexList index = ui.itemsList->selectionModel()->selectedIndexes();

    if (index.size() == 0) {
        ui.Age->clear();
        ui.Form->clear();
        ui.Material->clear();
        ui.Name->clear();
        return -1;
    }
    int indexAtRow = index.at(0).row();
    return indexAtRow;

}

void TheLastStand::populateItemsList()
{
    if (ui.itemsList->count() > 0)
        ui.itemsList->clear();
    //this->service.addService("f", "f", "f", 234);
    for (auto& item : this->service.getRepoService())
    {
        QString itemInList = QString::fromStdString(item.toString().str());
        QFont font{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(font);
        ui.itemsList->addItem(item);
    }

    if (this->service.getRepoService().size() > 0)
        ui.itemsList->setCurrentRow(0);
}

void TheLastStand::connectSignalsAndSlots()
{
    QObject::connect(this, &TheLastStand::itemsUpdatedSignal, this, &TheLastStand::populateItemsList);
    QObject::connect(ui.itemsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });


    //buttons
    QObject::connect(ui.modeBButton, &QPushButton::clicked, this, &TheLastStand::modeBButtonHandler);
    QObject::connect(ui.modeAButton, &QPushButton::clicked, this, &TheLastStand::modeAButtonHandler);
    QObject::connect(ui.fileRepo, &QPushButton::clicked, this, &TheLastStand::fileRepoSelectorButtonHandler);
    QObject::connect(ui.addButton, &QPushButton::clicked, this, &TheLastStand::addItemButtonHandler);
    QObject::connect(ui.updateButton, &QPushButton::clicked, this, &TheLastStand::updateItemButtonHandler);
    QObject::connect(ui.deleteButton, &QPushButton::clicked, this, &TheLastStand::deleteItemButtonHandler);
    QObject::connect(ui.saveButton, &QPushButton::clicked, this, &TheLastStand::saveButtonHandler);
    QObject::connect(ui.filterButton, &QPushButton::clicked, this, &TheLastStand::filterButtonHandler);
    QObject::connect(ui.listButton, &QPushButton::clicked, this, &TheLastStand::listMyList);
    QObject::connect(ui.HTML_CSVREPO, &QPushButton::clicked, this, &TheLastStand::htmlCsvRepoButtonHandler);
    QObject::connect(ui.nextButton, &QPushButton::clicked, this, &TheLastStand::nextButtonHandler);
    QObject::connect(ui.UndoButton, &QPushButton::clicked, this, &TheLastStand::undoButtonHandler);
    QObject::connect(ui.RedoButton, &QPushButton::clicked, this, &TheLastStand::redoButtonHandler);
    QObject::connect(this->undoShortcut, &QShortcut::activated, this, &TheLastStand::undoButtonHandler);
    QObject::connect(this->redoShortcut, &QShortcut::activated, this, &TheLastStand::redoButtonHandler);


    //connect addItem signal to addItem slot, which adds an item to the vector
    QObject::connect(this, SIGNAL(addItemSignal(const int&, const string&, const string&, const string&)),
        this, SLOT(addItem(const int&, const string&, const string&, const string&)));
    
    QObject::connect(this, SIGNAL(myListUpdatedSignal(std::string& _name)), this, SLOT(saveItem(const string& _name)));
    //QObject::connect(this, SIGNAL(listMyList()), this, SLOT)

    QObject::connect(this, SIGNAL(itemsUpdatedSignal(const int&, const string&, const string&, const string&)),
        this, SLOT(updateItem(const int& _age, const string & _name, const string & _form, const string & _material)));

}

void TheLastStand::listItemChanged()
{
    int index = this->getSelectedIndex();
    if (index == -1)
        return;

    if (index >= this->service.getRepoService().size())
        return;
    Domain item = this->service.getRepoService()[index];
    ui.Name->setText(QString::fromStdString(item.getName()));
    ui.Form->setText(QString::fromStdString(item.getForm()));
    ui.Material->setText(QString::fromStdString(item.getMaterial()));
    ui.Age->setText(QString::fromStdString(std::to_string(item.getAge())));

}

void TheLastStand::addItem(const int& _age, const string& _name, const string& _form, const string& _material)
{
    this->service.addService(_name, _material, _form, _age);

    emit itemsUpdatedSignal();
}

void TheLastStand::saveItem(const string& _name)
{
    this->service.saveService(_name);

}

void TheLastStand::listMyList()
{

   //PaginatedGenesTableModel* tableModel = new PaginatedGenesTableModel;
   // PaginatedTableModel* tableModel = new PaginatedTableModel{this->service};
    
    this->listDialog->show();
    if (this->fileType == "csv")
        this->service.writeToCSV(this->file);
    else if (this->fileType == "html")
        this->service.writeToHTML(file);
    system(file.c_str());
}

void TheLastStand::updateItem(const int& _age, const string& _name, const string& _form, const string& _material)
{
    this->service.updateService(_name, _material, _form, _age);

    emit itemsUpdatedSignal();
}

void TheLastStand::init()
{
    if (this->memOrfile) {
        ui.fileRepoEdit->setVisible(false);
        ui.fileRepo->setVisible(false);
    }

    this->listDialog = new QDialog;
    /*QHBoxLayout* dialogLayout = new QHBoxLayout{ listDialog };
    QTableView* tableView = new QTableView{ listDialog };
    PaginatedTableModel* model = new PaginatedTableModel{ this->service };
    tableView->resizeColumnsToContents();
    tableView->setModel(model);
    tableView->verticalHeader()->hide();
    dialogLayout->addWidget(tableView);*/
    QHBoxLayout* layout = new QHBoxLayout{ listDialog };
    this->modelView = new QTableView{ listDialog };
    PaginatedTableModel* tableModel = new PaginatedTableModel{ this->service };
   // this->modelView.setModel(tableModel);
   // this->modelView = new QTableVIew{}
    //this->listDialog->setModal(true);
    this->modelView->setModel(tableModel);
    layout->addWidget(modelView);
    
}
