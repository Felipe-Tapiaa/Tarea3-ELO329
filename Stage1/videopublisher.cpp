#include "VideoPublisher.h"
#include <QVBoxLayout>

VideoPublisher::VideoPublisher(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    urlField = new QLineEdit;
    urlField->setPlaceholderText("Enter video URL and press ENTER");
    layout->addWidget(urlField);

    connect(urlField, &QLineEdit::returnPressed, [this]() {
        QString text = urlField->text();
        if (!text.isEmpty()) {
            notifyAll(text);
            urlField->clear();
        }
    });
}
