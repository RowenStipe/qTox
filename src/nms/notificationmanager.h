#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QString>


class NotificationManager
{
public:
    void hookFriendMessage(uint32_t friendId, int type, const uint8_t* cMessage, int cMessageSize);
};

#endif // NOTIFICATIONMANAGER_H
