#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>


class Formulario : public QWidget {
    Q_OBJECT
private:
    QLabel *lLegajo, *lNombre, *lApellido;
    QLineEdit *leLegajo, *leNombre, *leApellido;
    QPushButton *pbGuardar;
    QGridLayout *layout;

private slots:
    void slot_guardar_informacion();

public:
    Formulario();
};

#endif // FORMULARIO_H
