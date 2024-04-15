#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QByteArray>

#include <QImage>

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbIngresar; // Cambiando el nombre del QPushButton

    QNetworkAccessManager * manager;
    QImage im;

protected:
    void paintEvent( QPaintEvent * );

private slots:
    void slot_validarUsuario();
    void slot_descargaFinalizada( QNetworkReply * reply );
};

#endif // LOGIN_H
