#include "reclamation.h"
#include "ui_reclamation.h"
#include "reclamationclass.h"
#include <QString>
reclamation::reclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamation)
{
    ui->setupUi(this);
    ui->tab_reclamation->setModel(tmprec.afficher());
}

reclamation::~reclamation()
{
    delete ui;
}

void reclamation::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString email = ui->lineEdit_email->text();
    QString cas = ui->lineEdit_cas->text();
    QDate date = QDate::fromString(ui->lineEdit_date->text());
    reclamationclass rec(id,email,cas,date);
    rec.ajouter();

    recajout.set_cas(cas);
    recajout.set_email(email);
    recajout.set_id(id);
    bool ajout=recajout.ajouter();
    if(ajout)
    {

        ui->tab_reclamation->setModel(tmprec.afficher());
        std::cout<<"Added";}
    else
    {
        std::cout<<"Probleme ajout";
    }
}


void reclamation::on_pushButton_supprimer_clicked()
{
    int idsupp = ui->lineEdit_IDSUP->text().toInt();
    bool test=tmprec.supprimer(idsupp);
    if(test)
    {

        ui->tab_reclamation->setModel(tmprec.afficher());
        std::cout<<"Supprimé";}
    else
        std::cout<<"Probleme suppression";
}

void reclamation::on_pushButton_modifier_clicked()
{
    int idmodif=ui->lineEdit_idmodif->text().toInt();
    QString casnouveau=ui->lineEdit_casmodif->text();
    bool test = tmprec.modifier(idmodif , casnouveau);
    if(test)
    {
        ui->tab_reclamation->setModel(tmprec.afficher());
        std::cout<<"Modifié";
    }
    else std::cout<<"Probleme modification";
}



void reclamation::on_lineEdit_date_userDateChanged(const QDate &date)
{
    recajout.set_date(date);
}
