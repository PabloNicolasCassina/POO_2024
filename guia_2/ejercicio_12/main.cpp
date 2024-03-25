#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLabel label;

    QPixmap imagen("C:/UBP/POO_2024/guia_2/ejercicio_12/hoja.jpg");

    label.setPixmap(imagen.scaled(label.size(), Qt::KeepAspectRatio));

    label.showMaximized();

    QTimer::singleShot(3000, [&]() {
        label.close();
        qApp->quit();
    });

    return a.exec();
}
