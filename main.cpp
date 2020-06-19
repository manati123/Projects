#include "TheLastStand.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/qmessagebox.h>
#include "qdebug.h"
#include <fstream>
#include <sstream>
#include "iostream"
#include "Repo.h"
//#include "Tests.h"

int main(int argc, char *argv[])
{
    
    bool fileOrSys;
    std::string typeOfRepo;
    std::ifstream read("Config.txt");
    read >> typeOfRepo;
    if (typeOfRepo == "sys")
        fileOrSys = true;
    else
        fileOrSys = false;
    QApplication a(argc, argv);
    Repo repo{};
    FileRepo fileRepo{};
    Service service{ repo, fileRepo };
    /*QMessageBox messageBox;
    messageBox.setText("ye");
    if (fileOrSys)
        messageBox.show();*/
    //qDebug() << "sdfsdfds";
    TheLastStand w{service, fileOrSys};
    w.show();
    return a.exec();
}
