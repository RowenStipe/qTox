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

#include <math.h>

QString msgType(int msgType)
{
    if(msgType == 1)
        return "Action";
    if(msgType == 0)
        return "Speech";
    else
        return "???";
}

void NotificationManager::hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize)
{
    QString friendName = Nexus::getCore()->getFriendUsername(friendId);
    if (QApplication::focusWidget() <= 0)
    {
        if (cMessageSize <= 90)
        {
            qDebug() << "NMS: Friend ID: "+friendName;
            qDebug() << "NMS: Message Type: "+msgType(type);
            qDebug() << "NMS: Message: "+CString::toString(cMessage,cMessageSize);
        }
        if (cMessageSize >= 91)
        {
            qDebug() << "NMS: Friend ID: "+friendName;
            qDebug() << "NMS: Message Type: "+msgType(type);
            qDebug() << "NMS: Message: "+CString::toString(cMessage,86)+"...";
        }
    }
}

void NotificationManager::hookFriendStatus(uint32_t friendId, Status status)
{
    QString friendStatus;
    switch (status)
    {
    case Status::Online:
        friendStatus = "Online";
        break;
    case Status::Away:
        friendStatus = "Away";
        break;
    case Status::Busy:
        friendStatus = "Busy";
        break;
    case Status::Offline:
       friendStatus = "Offline";
        break;
    }

    QString friendName = Nexus::getCore()->getFriendUsername(friendId);
    if (QApplication::focusWidget() <= 0)
    {
        qDebug() << "NMS: Friend ID: "+friendName;
        qDebug() << "NMS: Status Type: "+friendStatus;
    }
}

void NotificationManager::hookFileRecieved(uint32_t friendId, uint32_t fileId, uint32_t kind, uint64_t filesize, const uint8_t *fname, size_t fnameLen)
{
    QString friendName = Nexus::getCore()->getFriendUsername(friendId);
    QString fileSize = getHumanReadableSize(filesize);

    qDebug() << "NMS: Transfer from:"+friendName;
    qDebug() << "NMS: File Size:"+fileSize;
}

//copied from filetransferwidget.cpp
QString NotificationManager::getHumanReadableSize(qint64 size)
{
    static const char* suffix[] = {"B","kiB","MiB","GiB","TiB"};
    int exp = 0;

    if (size > 0)
        exp = std::min( (int) (log(size) / log(1024)), (int) (sizeof(suffix) / sizeof(suffix[0]) - 1));

    return QString().setNum(size / pow(1024, exp), 'f', exp > 1 ? 2 : 0).append(suffix[exp]);
}
