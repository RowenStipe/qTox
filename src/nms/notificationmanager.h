#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QString>
#include "src/core/core.h"
#include "tox/tox.h"


class NotificationManager
{
public:
    void hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize);
    void hookFriendStatus(uint32_t friendId, TOX_USER_STATUS status);
};

#endif // NOTIFICATIONMANAGER_H
