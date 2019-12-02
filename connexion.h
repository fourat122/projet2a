#ifndef CONNEXION_H
#define CONNEXION_H


#include <QtSql/QSqlDatabase>

class connexion
{
private : QSqlDatabase db;
public:
    connexion();
    bool ouvrirConnexion();
    void  fermerConnexion();
};

#endif // CONNEXION_H
