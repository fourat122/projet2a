#ifndef RECLAMATIONCLASS_H
#define RECLAMATIONCLASS_H
#include <QString>
#include <QDate>
#include <QtSql/QSqlQueryModel>
#include <iostream>
class reclamationclass
{
public:
    reclamationclass();
    reclamationclass(int,QString,QString,QDate);
    //SETTERS
    void set_id(int idreclamation) {this->idreclamation=idreclamation;}
    void set_email(QString email){this->email=email;}
    void set_cas(QString cas){this->cas=cas;}
    void set_date(QDate datereclamation){this->datereclamation=datereclamation;}
    QDate getdate(){
        return datereclamation;
    }
    //GETTERS

    //CRUD
    bool ajouter();
    bool modifier(int, QString);
    bool supprimer(int);
    QSqlQueryModel * afficher();

    QSqlQueryModel * afficher_list();
QString generate_date(QString,QString,QString);
QSqlQueryModel * recherche(QString,QString,int);
bool date_limite();
    //METIERS




private:
    QString email,cas;
    QDate datereclamation;
    int idreclamation; // CLE PRIMAIRE
};

#endif // RECLAMATIONCLASS_H
