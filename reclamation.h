#ifndef RECLAMATION_H
#define RECLAMATION_H
#include "reclamationclass.h"
#include <QDialog>

namespace Ui {
class reclamation;
}

class reclamation : public QDialog
{
    Q_OBJECT

public:
    explicit reclamation(QWidget *parent = nullptr);
    ~reclamation();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_lineEdit_date_userDateChanged(const QDate &date);

private:
    Ui::reclamation *ui;
    reclamationclass tmprec;
    reclamationclass recajout;
};

#endif // RECLAMATION_H
