// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#ifndef WIDGETOPENGL_H
#define WIDGETOPENGL_H

#include <QtGui>
#include <QOpenGLWidget>

class WidgetOpenGL : public QOpenGLWidget
{
    Q_OBJECT

public:
    WidgetOpenGL(QWidget* parent = nullptr);
    ~WidgetOpenGL();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

};

#endif // WIDGETOPENGL_H
