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
#include <QJsonObject>

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);
    void setImagenFondo(const QString &url);

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLabel *lTemperatura;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbIngresar;
    QPushButton *pbOcultarTemperatura; // Nuevo botón para ocultar la temperatura
    QNetworkAccessManager *manager;

    int intentosFallidos;
    bool bloqueado; // Declaración de la variable bloqueado
    QStringList bloqueadoUsuarios; // Lista de usuarios bloqueados

    QImage im;

    void obtenerTemperatura();
    void obtenerImagen();
    void bloquearUsuario(const QString& usuario);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_validarUsuario();
    void slot_mostrarTemperatura(QNetworkReply *reply);
    void toggleTemperaturaVisible();
    void desbloquearUsuario(const QString& usuario); // Asegúrate de incluir este slot en la sección private slots
};

#endif // LOGIN_H
