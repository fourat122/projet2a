#include "Gestion_reclamation.h"
#include "ui_gestion_reclamation.h"
#include "reclamationclass.h"
#include <QString>
#include "notification.h"
#include "reservation.h"
#include <QMessageBox>
Gestion_reclamation::Gestion_reclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_reclamation)
{
    ui->setupUi(this);
    ui->tab_reclamation->setModel(tmprec.afficher());
    ui->comboBox->setModel(tmprec.afficher_list());
ui->comboBox_2->setModel(tmprec.afficher_list());
ui->tab_reservation->setModel(tmpreservation.afficher());
ui->comboBox_8->setModel(tmpreservation.afficher_list());
ui->comboBox_9->setModel(tmpreservation.afficher_list());

if(tmprec.date_limite()){
    notification n;
    n.afficher();
}
}

Gestion_reclamation::~Gestion_reclamation()
{
    delete ui;
}

void Gestion_reclamation::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString email = ui->lineEdit_email->text();
    QString cas = ui->lineEdit_cas->text();
    reclamationclass rec(id,email,cas,recajout.getdate());
   if(verif_formulaire()==false){
       QMessageBox::information(nullptr,QObject::tr("VERIFICATION"),"champs invalid");

   }else if( ui->mail_verif->text()==("mail invalid")){
       QMessageBox::information(nullptr,QObject::tr("VERIFICATION"),"Mail invalid");
   }else{
       bool ajout= rec.ajouter();

   if(ajout)
    {
        ui->tab_reclamation->setModel(tmprec.afficher());
    ui->comboBox->setModel(tmprec.afficher_list());
    ui->comboBox_2->setModel(tmprec.afficher_list());
    if(tmprec.date_limite()){
        notification n;
        n.afficher();   }

    }    else
    {
       QMessageBox::information(nullptr,QObject::tr("VERIFICATION"),"Reclamation déja existe");
    }
   }
}


void Gestion_reclamation::on_pushButton_supprimer_clicked()
{
    int idsupp = ui->lineEdit_IDSUP->text().toInt();
    bool test=tmprec.supprimer(idsupp);
    if(test)
    {
        ui->tab_reclamation->setModel(tmprec.afficher());
        ui->comboBox->setModel(tmprec.afficher_list());
    ui->comboBox_2->setModel(tmprec.afficher_list());
    if(tmprec.date_limite()){
        notification n;
        n.afficher(); } }else
        std::cout<<"Probleme suppression";
}

void Gestion_reclamation::on_pushButton_modifier_clicked()
{
    int idmodif=ui->lineEdit_idmodif->text().toInt();
    QString casnouveau=ui->lineEdit_casmodif->text();
    bool test = tmprec.modifier(idmodif , casnouveau);
    if(test)
    {
        ui->tab_reclamation->setModel(tmprec.afficher());
        ui->comboBox->setModel(tmprec.afficher_list());
    ui->comboBox_2->setModel(tmprec.afficher_list());
    if(tmprec.date_limite()){
        notification n;
        n.afficher();  } }
    else std::cout<<"Probleme modification";
}



void Gestion_reclamation::on_lineEdit_date_userDateChanged(const QDate &date)
{
    recajout.set_date(date);
}
void Gestion_reclamation::on_comboBox_activated(const QString &arg1){
    ui->lineEdit_IDSUP->setText(arg1);
}
void Gestion_reclamation::on_comboBox_2_activated(const QString &arg1){
    ui->lineEdit_idmodif->setText(arg1);
}
void Gestion_reclamation::on_comboBox_3_activated(const QString &arg1){
champ=arg1;
ui->recherche->setDisabled(false);
}
void Gestion_reclamation::on_recherche_textChanged(const QString &arg1){
    ui->tab_reclamation->setModel(recajout.recherche(champ,arg1,etat));

    recherche=arg1;
}

void Gestion_reclamation::on_checkBox_stateChanged(int arg1){
    etat=arg1;
    ui->tab_reclamation->setModel(recajout.recherche(champ,recherche,etat));
}
void Gestion_reclamation::on_lineEdit_email_textChanged(const QString &arg1){
    bool test=false;
    int i;
    for(i=0;i<arg1.length();i++){
        if(arg1[i]=='@')
            test=true;
    }
    if(test){
    ui->mail_verif->setStyleSheet("color : green;");
        ui->mail_verif->setText("mail valid");
    }
    else{
        ui->mail_verif->setStyleSheet("color : red;");
        ui->mail_verif->setText("mail invalid");

    }
}
bool  Gestion_reclamation::verif_formulaire(){
    return ((ui->lineEdit_id->text()!="")&&(ui->lineEdit_email->text()!="")&&(ui->lineEdit_cas->text()!="")&&(ui->lineEdit_date->text()!=""));
}
void Gestion_reclamation::on_pushButton_ajouter_3_clicked(){
 reservation r(ui->nom->text(),ui->prenom->text(),ui->adresse->text(),ui->ID->text().toInt(),ui->Produit->text().toInt());
 if(r.ajouter()){


     ui->tab_reservation->setModel(tmpreservation.afficher());
     ui->comboBox_8->setModel(tmpreservation.afficher_list());
     ui->comboBox_9->setModel(tmpreservation.afficher_list());
 };
}
void Gestion_reclamation::on_comboBox_8_activated(const QString &arg1){
    ui->ID_SUP->setText(arg1);
}
void Gestion_reclamation::on_pushButton_supprimer_3_clicked(){
    tmpreservation.setid(ui->ID_SUP->text().toInt());
    if( tmpreservation.supprimer()){
        ui->tab_reservation->setModel(tmpreservation.afficher());
        ui->comboBox_8->setModel(tmpreservation.afficher_list());
        ui->comboBox_9->setModel(tmpreservation.afficher_list());

    }
}
void Gestion_reclamation::on_comboBox_9_activated(const QString &arg1){
    tmpreservation.setid(arg1.toInt());

}
void Gestion_reclamation::on_pushButton_modifier_3_clicked(){
    reservation r(ui->nom_2->text(),ui->prenom_2->text(),ui->adresse_2->text(),tmpreservation.Getid(),ui->Produit_2->text().toInt());
    if(r.modifier()){
        ui->tab_reservation->setModel(tmpreservation.afficher());
        ui->comboBox_8->setModel(tmpreservation.afficher_list());
        ui->comboBox_9->setModel(tmpreservation.afficher_list());

    }
}
