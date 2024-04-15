#include "login.h"

#include <QDebug>
#include <QPainter>
#include <QJsonDocument>
#include <QSettings>
#include <QTimer>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    // Crear los elementos de la interfaz
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    lTemperatura = new QLabel("Temperatura: Desconocida");
    leUsuario = new QLineEdit();
    leClave = new QLineEdit();
    leClave->setEchoMode(QLineEdit::Password);
    pbIngresar = new QPushButton("Ingresar");
    pbOcultarTemperatura = new QPushButton("Mostrar/ocultar Temperatura");

    // Crear el layout y añadir los elementos
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(lUsuario, 0, 0);
    gridLayout->addWidget(leUsuario, 0, 1, 1, 2);
    gridLayout->addWidget(lClave, 1, 0);
    gridLayout->addWidget(leClave, 1, 1, 1, 2);
    gridLayout->addWidget(pbIngresar, 2, 1, 1, 1);
    gridLayout->addWidget(lTemperatura, 3, 0, 1, 3);
    gridLayout->addWidget(pbOcultarTemperatura, 4, 0, 1, 3);

    // Conectar el clic del botón al slot_validarUsuario
    connect(pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_mostrarTemperatura(QNetworkReply*)));

    // Obtener la temperatura al iniciar la ventana
    obtenerTemperatura();
    obtenerImagen();

    // Dentro del constructor de Login en login.cpp
    connect(pbOcultarTemperatura, SIGNAL(pressed()), this, SLOT(toggleTemperaturaVisible()));

}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
}

void Login::slot_validarUsuario() {
    if (bloqueadoUsuarios.contains(leUsuario->text())) {
        qDebug() << "Usuario bloqueado. Intente de nuevo más tarde.";
        return;
    }

    if ((leUsuario->text() == "admin" && leClave->text() == "1234") || (leUsuario->text() == "nico" && leClave->text() == "1234")) {
        qDebug() << "Usuario válido";
    } else {
        leClave->clear();
        intentosFallidos++;

        if (intentosFallidos >= 3) {
            qDebug() << "Usuario" << leUsuario->text() << "bloqueado por 5 minutos debido a múltiples intentos fallidos.";
            bloquearUsuario(leUsuario->text());
        }
    }
}

void Login::slot_mostrarTemperatura(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        im = QImage::fromData(data);
        this->repaint();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        if (obj.contains("current")) {
            QJsonObject currentObj = obj["current"].toObject();
            if (currentObj.contains("temp_c")) {
                double temperatura = currentObj["temp_c"].toDouble();
                lTemperatura->setText(QString("Temperatura: %1°C").arg(temperatura));
            }
        }
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
    }
}

void Login::obtenerTemperatura() {
    QString url = QString("https://api.weatherapi.com/v1/current.json?key=8ab276a6f3f24bc8987184908231805&q=Cordoba");
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    manager->get(request);
}

void Login::obtenerImagen() {
    QString url = QString("https://upload.wikimedia.org/wikipedia/commons/b/b5/800x600_Wallpaper_Blue_Sky.png?20091002171555");
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    manager->get(request);
}

void Login::toggleTemperaturaVisible() {
    lTemperatura->setVisible(!lTemperatura->isVisible());
}

void Login::bloquearUsuario(const QString& usuario) {
    bloqueadoUsuarios.append(usuario);
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("bloqueadoUsuarios", bloqueadoUsuarios);
    settings.setValue("tiempoBloqueo", 300000); // 5 minutos en milisegundos
    QTimer::singleShot(300000, this, [this, usuario]() { desbloquearUsuario(usuario); }); // Desbloquear después de 5 minutos
}

void Login::desbloquearUsuario(const QString& usuario) {
    qDebug() << "Usuario" << usuario << "desbloqueado. Puede intentar iniciar sesión nuevamente.";
    bloqueadoUsuarios.removeAll(usuario);
    intentosFallidos = 0;
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("bloqueadoUsuarios", bloqueadoUsuarios);
}

