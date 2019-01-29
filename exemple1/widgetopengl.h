// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#ifndef WIDGETOPENGL_H
#define WIDGETOPENGL_H

#include <QtGui>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>


class WidgetOpenGL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    WidgetOpenGL(QWidget* parent = nullptr);
    ~WidgetOpenGL();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void initializeVBO();
    void initializeShader();

private:
    GLuint m_programme;          //identifiant du shader program
    GLuint m_vbo;               //identifiant du Vertex Buffer Object
};

#endif // WIDGETOPENGL_H
