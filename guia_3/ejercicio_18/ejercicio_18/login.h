#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class Login : public QWidget{
    Q_OBJECT
    private:
        QLabel *lUsuario, *lClave;
        QLineEdit *leUsuario, *leClave;
        QPushButton *pbEntrar;
        QGridLayout * layout;

    private slots:
        void slot_validar_usuario();

    public:
        Login();
};

#endif // LOGIN_H
