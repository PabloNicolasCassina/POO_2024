#include <QWidget>

class Mapa : public QWidget  {
    Q_OBJECT

public:
    Mapa(QWidget *parent = nullptr); // Necesitamos un constructor con QWidget* parent para asegurarnos de que el widget se inicialice correctamente

protected:
    void paintEvent( QPaintEvent * ) override;

private:
    QImage imagen; // Para almacenar la imagen
};
