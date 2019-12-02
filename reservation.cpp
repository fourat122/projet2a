#include "reservation.h"
#include <QSqlQuery>
reservation::reservation()
{

}

reservation::reservation(QString nom,QString prenom,QString adresse ,int id,int produit)
{
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->id=id;
    this->produit=produit;
}
bool reservation::ajouter(){
    QSqlQuery query;
    query.prepare("insert into reservation values(:nom,:prenom,:adresse,:id,:produit)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":id",id);
    query.bindValue(":produit",produit);
    return query.exec();
}
bool reservation::modifier(){
    QSqlQuery query;
    query.prepare("update reservation set nom=:nom,prenom=:prenom,adresse=:adresse,produit=:produit where id=:id");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":id",id);
    query.bindValue(":produit",produit);
    return query.exec();
}
bool reservation::supprimer(){
    QSqlQuery query;
    query.prepare("delete from reservation where id=:id");
    query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel * reservation::afficher(){
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("select * from reservation ");
return model;
}
QSqlQueryModel * reservation::afficher_list(){
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("select id from reservation ");
return model;
}
