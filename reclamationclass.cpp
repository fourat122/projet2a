#include "reclamationclass.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
reclamationclass::reclamationclass()
{

}

reclamationclass::reclamationclass(int id,QString email,QString cas ,QDate date)
{
    this->cas=cas;
    this->datereclamation=date;
    this->email=email;
    this->idreclamation=id;
}

bool reclamationclass::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(idreclamation);
    query.prepare("insert into reclamation(idreclamation,email,cas,datereclamation) VALUES (:idreclamation,:email,:cas,:datereclamation)");
    query.bindValue(":idreclamation",idreclamation);
    query.bindValue(":email",email);
    query.bindValue(":cas",cas);
    query.bindValue(":datereclamation",generate_date(QString::number(datereclamation.day()),QString::number(datereclamation.month()),QString::number(datereclamation.year())));
    return query.exec();
}



QSqlQueryModel *reclamationclass::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from reclamation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cas"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
    return model;
}
QSqlQueryModel *reclamationclass::afficher_list()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select idreclamation from reclamation");
    return model;
}

bool reclamationclass::supprimer(int idreclamation)
{

    QSqlQuery query;
    QString idsupp=QString::number(idreclamation);
    query.prepare("delete from reclamation where idreclamation=:idsupp");
    query.bindValue(":idsupp",idreclamation);
    return query.exec();

}

bool reclamationclass::modifier(int idreclamation, QString cas)
{
    QSqlQuery query;
    query.prepare("update reclamation set cas=:cas where idreclamation =:id");
    query.bindValue(":cas",cas);
    query.bindValue(":id",idreclamation);

    return query.exec();
}
QString reclamationclass::generate_date(QString j,QString m, QString a){
    if(j.length()==1){
        j='0'+j;
    }
    if(m.length()==1){
        m='0'+m;
    }
    return j+'-'+m+'-'+a;
}

QSqlQueryModel * reclamationclass::recherche(QString champ,QString recherche,int etat){
QSqlQuery query;
QSqlQueryModel *model = new QSqlQueryModel();
recherche="%"+recherche+"%";
if(etat==0){
query.prepare("select * from reclamation where "+champ+" like :recherche order by "+champ);
}else{
    query.prepare("select * from reclamation where "+champ+" like :recherche order by "+champ+" desc");

}query.bindValue(":recherche",recherche);
query.exec();
model->setQuery(query);

return model;
}
bool reclamationclass::date_limite(){
    QSqlQuery query;
    QDate q;
    q=q.currentDate();
    qDebug()<<q;
    q=q.addDays(7);
    query.prepare("select * from reclamation where datereclamation<=:q");
    query.bindValue(":q",generate_date(QString::number(q.day()),QString::number(q.month()),QString::number(q.year())));
    query.exec();
    return  query.first();

}
