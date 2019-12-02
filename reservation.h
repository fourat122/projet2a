#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQueryModel>
class reservation
{
public:
    reservation();

    reservation(QString,QString,QString,int,int);
    bool ajouter();
    bool modifier();
    bool supprimer();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_list();

    void setid(int id){
        this->id=id;
    }
    int Getid(){
        return  id;
    }
private:
    QString nom,prenom,adresse;
    int id,produit;
};

#endif // RESERVATION_H
