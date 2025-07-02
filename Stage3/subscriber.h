#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <QString>

class Subscriber {
public:
    Subscriber() {} // <-- constructor explícito
    virtual ~Subscriber() {}
    virtual void update(const QString& message) = 0;
};

#endif
