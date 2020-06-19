#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TheLastStand.h"
#include "Service.h"
#include <QTableView>
#include <string>
#include <QShortcut>
#include "MylistTableModel.h"
//#include "../../../Documents/OOP/Lab8/Lab8/Service.h"
using std::string;
class TheLastStand : public QMainWindow
{
    Q_OBJECT

private:
    Ui::TheLastStandClass ui;
    bool memOrfile;
    
    Service& service;
    std::string fileType, file, fileRepoName = "";
    QDialog* listDialog;
    QTableView* modelView;
    void init();
    
public:
    QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
   // MylistTableModel* tableModel;
    /*QTableView* view = new QTableView;
    UserModel* model = new UserModel;*/
    
    TheLastStand( Service _service,bool check, QWidget* parent = Q_NULLPTR) ;
    void addItemButtonHandler();
    void deleteItemButtonHandler();
    void updateItemButtonHandler();
    void fileRepoSelectorButtonHandler();
    void saveButtonHandler();
    //void listButtonHandler();
    void htmlCsvRepoButtonHandler();
    void nextButtonHandler();
    void filterButtonHandler();
    void undoButtonHandler();
    void redoButtonHandler();
    void modeAButtonHandler();
    void modeBButtonHandler();

    
    
    int getSelectedIndex();

    void populateItemsList();
    
    void connectSignalsAndSlots();
    void listItemChanged();

signals:
    void itemsUpdatedSignal();
    void myListUpdatedSignal();
    void addItemSignal(const int& _age, const string& _name, const string& _form, const string& _material);

public slots:
    void updateItem(const int& _age, const string& _name, const string& _form, const string& _material);
    void addItem(const int& _age, const string& _name, const string& _form, const string& _material);
    void saveItem(const string& _name);
    void listMyList();

};
