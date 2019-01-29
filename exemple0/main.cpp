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
    format.setVersion(1, 2);          // cible OpenGL 1.2
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    QSurfaceFormat::setDefaultFormat(format);

    WidgetOpenGL w;
    w.setWindowTitle("Réalité virtuelle - exemple 0 : openGL 1.2");
    w.show();

    return a.exec();
}
