#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QString>
#include "src/core/core.h"
#include "tox/tox.h"


class NotificationManager
{
public:
    NotificationManager();
    ~NotificationManager();

    static void hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize);
    static void hookFriendStatus(uint32_t friendId, Status status);
    static void hookFileRecieved(uint32_t friendId, uint32_t fileId, uint32_t kind, uint64_t filesize, const uint8_t *fname, size_t fnameLen);

    static QString getHumanReadableSize(qint64 size);
};

#endif // NOTIFICATIONMANAGER_H
