#include "notificationmanager.h"
#include "src/friend.h"
#include "src/nexus.h"
#include "src/core/core.h"
#include "src/core/cdata.h"
#include "src/core/cstring.h"
#include "tox/tox.h"

#include <QString>
#include <QDebug>
#include <QApplication>



void NotificationManager::hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize)
{
    sleep(2);
    QString Username = Nexus::getCore()->getFriendUsername(friendId);
    if (QApplication::focusWidget() <= 0)
    {
        qDebug() << "NMS: Friend ID: "+Username;
        qDebug() << "NMS: Message Type: "+QString(type);
        qDebug() << "NMS: Message: "+CString::toString(cMessage,cMessageSize);
    }
}
