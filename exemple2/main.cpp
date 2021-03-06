// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#include <QApplication>
#include "widgetopengl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setDepthBufferSize(24);
    format.setVersion(3, 3);          // cible OpenGL 3.3
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    WidgetOpenGL w;
    w.setWindowTitle("Réalité virtuelle - exemple 2 : openGL 3.3 avec VAO");
    w.show();

    return a.exec();
}
