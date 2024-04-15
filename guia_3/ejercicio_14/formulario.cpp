#include "formulario.h"

void Formulario::slot_guardar_informacion() {
    // Aquí puedes escribir la lógica para guardar la información del formulario
    // Por ejemplo:
    QString legajo = leLegajo->text();
    QString nombre = leNombre->text();
    QString apellido = leApellido->text();

    QMessageBox::information(this, "Éxito", "La información se ha guardado correctamente.");
    // Lógica para guardar la información...
}



Formulario::Formulario() {
    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    pbGuardar = new QPushButton("Guardar");
    layout = new QGridLayout;

    layout->addWidget(lLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(pbGuardar, 3, 1);

    this->setLayout(layout);

    connect(pbGuardar, SIGNAL(clicked()), this, SLOT(slot_guardar_informacion()));
    connect( leApellido, SIGNAL( returnPressed() ), this, SLOT( slot_guardar_informacion() ) );
}
