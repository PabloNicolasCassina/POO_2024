#include "htmlviewer.h"
#include <QUrl>
#include <QNetworkRequest>

HtmlViewer::HtmlViewer(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    urlLabel = new QLabel("URL:");
    urlLineEdit = new QLineEdit;
    htmlTextEdit = new QTextEdit;
    htmlTextEdit->setReadOnly(true);
    manager = new QNetworkAccessManager(this);

    layout->addWidget(urlLabel);
    layout->addWidget(urlLineEdit);
    layout->addWidget(htmlTextEdit);

    connect(urlLineEdit, &QLineEdit::returnPressed, this, &HtmlViewer::fetchHtml);
}

HtmlViewer::~HtmlViewer() {}

void HtmlViewer::fetchHtml() {
    QUrl url(urlLineEdit->text());
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            htmlTextEdit->setHtml(reply->readAll());
        } else {
            htmlTextEdit->setPlainText("Error fetching HTML: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
