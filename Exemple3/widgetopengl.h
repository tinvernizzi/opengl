// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#ifndef WIDGETOPENGL_H
#define WIDGETOPENGL_H

#include <QtGui>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QMatrix4x4>

class WidgetOpenGL : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    WidgetOpenGL(QWidget* parent = nullptr);
    ~WidgetOpenGL();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void initializeVAO();
    void initializeShader();

private:
    GLuint m_programme;          //identifiant du shader program
    GLuint m_vbo;               //identifiant du Vertex Buffer Object
    GLuint m_ibo;               //identifiant de l'index buffer
    GLuint m_vao;               //identifiant du Vertex Array Object
};

#endif // WIDGETOPENGL_H
