/*
    Copyright © 2016 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

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

QString msgType(int msgType)
{
    if(msgType == 1)
        return "Action";
    if(msgType == 0)
        return "Speech";
}

void NotificationManager::hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize)
{
    QString Username = Nexus::getCore()->getFriendUsername(friendId);
    if (QApplication::focusWidget() <= 0)
    {
        if (cMessageSize <= 90)
        {
            qDebug() << "NMS: Friend ID: "+Username;
            qDebug() << "NMS: Message Type: "+msgType(type);
            qDebug() << "NMS: Message: "+CString::toString(cMessage,cMessageSize);
        }
        if (cMessageSize >= 91)
        {
            qDebug() << "NMS: Friend ID: "+Username;
            qDebug() << "NMS: Message Type: "+msgType(type);
            qDebug() << "NMS: Message: "+CString::toString(cMessage,86)+"...";
        }
    }
}

void NotificationManager::hookFriendStatus(uint32_t friendId, Status status)
{
    QString Userstatus;
    switch (status)
    {
    case Status::Online:
        Userstatus = "Online";
        break;
    case Status::Away:
        Userstatus = "Away";
        break;
    case Status::Busy:
        Userstatus = "Busy";
        break;
    case Status::Offline:
       Userstatus = "Offline";
        break;
    }

    QString Username = Nexus::getCore()->getFriendUsername(friendId);
    if (QApplication::focusWidget() <= 0)
    {
        qDebug() << "NMS: Friend ID: "+Username;
        qDebug() << "NMS: Status Type: "+Userstatus;
    }
}

//void NotificationManager::hookFileRecieved(uint32_t friendId, )