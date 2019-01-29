// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#include <QApplication>
#include "widgetopengl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetOpenGL w;
    w.setWindowTitle("Exemple 5 : Version Android");
    w.show();

    return a.exec();
}
