// formulario.cpp
#include "formulario.h"
#include <QMessageBox>
#include <QApplication>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRandomGenerator>

Formulario::Formulario() {
    // Create labels and line edits
    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    lCaptcha = new QLabel("Captcha:");
    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    leCaptcha = new QLineEdit;

    // Create the "Guardar" button
    pbGuardar = new QPushButton("Guardar");

    // Create the layout
    layout = new QGridLayout;

    // Create the "Captcha" group box
    groupBoxCaptcha = new QGroupBox("Captcha:");
    QVBoxLayout *layoutCaptcha = new QVBoxLayout;

    // Generate a random captcha value
    int captchaValue = QRandomGenerator::global()->bounded(1, 10001);

    // Create a label to display the captcha value (cast to QString for text)
    QLabel *captchaValueLabel = new QLabel(QString::number(captchaValue));
    layoutCaptcha->addWidget(captchaValueLabel);

    // Add the captcha line edit to the layout
    layoutCaptcha->addWidget(leCaptcha);

    // Set the layout for the group box
    groupBoxCaptcha->setLayout(layoutCaptcha);

    // Add widgets to the main layout
    layout->addWidget(lLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(groupBoxCaptcha, 3, 0, 1, 2);
    layout->addWidget(pbGuardar, 4, 1);

    // Set the application's main layout
    this->setLayout(layout);

    // Connect the "Guardar" button's clicked signal to the slot
    connect(pbGuardar, &QPushButton::clicked, this, &Formulario::slot_guardar_informacion);
    connect( leCaptcha, SIGNAL( returnPressed() ), this, SLOT( slot_guardar_informacion() ) );
}

void Formulario::slot_guardar_informacion() {
    // Get the entered captcha
    QString captchaIngresado = leCaptcha->text();

    // Get the correct captcha value from the label's text (assuming it's the first child)
    QLabel *captchaLabel = static_cast<QLabel*>(groupBoxCaptcha->layout()->itemAt(0)->widget());
    QString captchaCorrecto = captchaLabel->text();

    // Validate the captcha
    if (captchaIngresado == captchaCorrecto) {
        QMessageBox::information(this, "Validación Exitosa", "Captcha correcto. La información se ha guardado correctamente.");
        QApplication::quit(); // Close the application
    } else {
        QMessageBox::critical(this, "Error", "Captcha incorrecto. Inténtelo de nuevo.");
        leCaptcha->clear(); // Clear the captcha line edit
    }
}
