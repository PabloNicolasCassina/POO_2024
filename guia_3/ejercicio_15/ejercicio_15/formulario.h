#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QGroupBox>


class Formulario : public QWidget {
    Q_OBJECT
private:
    QLabel *lLegajo, *lNombre, *lApellido, *lCaptcha, *lLabCaptcha;
    QLineEdit *leLegajo, *leNombre, *leApellido, *leCaptcha;
    QPushButton *pbGuardar;
    QGridLayout *layout;
    QGroupBox *groupBoxCaptcha; // Agregamos el groupBox para el captcha

private slots:
    void slot_guardar_informacion();
public:
    Formulario();
};

#endif // FORMULARIO_H
