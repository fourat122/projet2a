#ifndef Gestion_reclamation_H
#define Gestion_reclamation_H
#include "reclamationclass.h"
#include "reservation.h"
#include <QDialog>

namespace Ui {
class Gestion_reclamation;
}

class Gestion_reclamation : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_reclamation(QWidget *parent = nullptr);
    ~Gestion_reclamation();
    bool verif_formulaire();


private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_lineEdit_date_userDateChanged(const QDate &date);


    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_recherche_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_lineEdit_email_textChanged(const QString &arg1);

    void on_pushButton_ajouter_3_clicked();

    void on_comboBox_8_activated(const QString &arg1);

    void on_pushButton_supprimer_3_clicked();

    void on_comboBox_9_activated(const QString &arg1);

    void on_pushButton_modifier_3_clicked();

private:
    Ui::Gestion_reclamation *ui;
   reclamationclass tmprec;
   reclamationclass recajout;
   QString champ;
   int etat=0;
   QString recherche;
   reservation tmpreservation;
};

#endif // Gestion_reclamation_H
