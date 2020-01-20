#include <QApplication>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // The application of the game

    FindDialog	*dialog	=	new	FindDialog; // The main object of the game
    dialog->show(); // Shows the game

    return app.exec(); // Keeps the game open
}
