#include "login.h"
#include "htmlviewer.h"

void Login::slot_validar_usuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        HtmlViewer *htmlViewer = new HtmlViewer;
        htmlViewer->show();
        this->close();
    } else {
        leClave->clear();
    }
}

Login::Login() {
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave -> setEchoMode(QLineEdit::Password);
    pbEntrar = new QPushButton("Entrar");
    layout = new QGridLayout;
    layout -> addWidget(lUsuario, 0, 0, 1, 1);
    layout -> addWidget(lClave, 1, 0, 1, 1);
    layout -> addWidget(leUsuario, 0, 1, 1, 2);
    layout -> addWidget(leClave, 1, 1, 1, 2);
    layout -> addWidget(pbEntrar, 2, 1, 1, 1); // fila, columna, alto, ancho. El layout siempre va dentro de un QWidget. En este caso Login es un Qwidget
    this -> setLayout(layout);
    connect( pbEntrar, SIGNAL( pressed() ), this, SLOT( slot_validar_usuario() ) );
    connect( leClave, SIGNAL( returnPressed() ), this, SLOT( slot_validar_usuario() ) );
}

