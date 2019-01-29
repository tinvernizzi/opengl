// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#ifndef WIDGETOPENGL_H
#define WIDGETOPENGL_H

#include <QtGui>
#include <QMessageBox>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>

#include <QTimer>

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
    void initializeVAO();
    void initializeShader();

private slots: void update();

private:
    QTimer* m_timer;
    GLfloat m_angleY;
    GLfloat m_angleZ;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLBuffer* m_vbo;
    QOpenGLShaderProgram* m_programme;
};

#endif // WIDGETOPENGL_H
