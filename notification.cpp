#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}

void notification::afficher()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Rappel","une reclamation a depassé la date limite (7 JOURS ) ",QSystemTrayIcon::Information,15000);
}
