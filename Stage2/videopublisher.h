#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H

#include <QWidget>
#include <QLineEdit>
#include "Publisher.h"

class VideoPublisher : public QWidget, public Publisher {
    Q_OBJECT
private:
    QLineEdit* urlField;
public:
    VideoPublisher(QWidget* parent = nullptr);
};

#endif
