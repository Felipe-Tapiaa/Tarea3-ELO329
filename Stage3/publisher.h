#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Subscriber.h"
#include <vector>

class Publisher {
protected:
    std::vector<Subscriber*> subscribers;
public:
    Publisher() {} // <-- agrega este constructor explícito
    void addSubscriber(Subscriber* s) {
        subscribers.push_back(s);
    }

    void notifyAll(const QString& message) {
        for (Subscriber* s : subscribers) {
            s->update(message);
        }
    }
};

#endif
