#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include "reclamation.h"
#include "gestion_reclamation.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test = c.ouvrirConnexion();
    MainWindow w;


    if(test){
        QMessageBox::information(nullptr,QObject::tr("Connexion"),"Connecté");
    w.show();
        return a.exec();
}else
    return 0;
}
