#ifndef HTMLVIEWER_H
#define HTMLVIEWER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HtmlViewer : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *urlLabel;
    QLineEdit *urlLineEdit;
    QTextEdit *htmlTextEdit;
    QNetworkAccessManager *manager;

private slots:
    void fetchHtml();

public:
    HtmlViewer(QWidget *parent = nullptr);
    ~HtmlViewer();
};

#endif // HTMLVIEWER_H
