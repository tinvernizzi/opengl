// Cours de Réalité Virtuelle
// leo.donati@unice.fr
//
// 2017_2018
//
// Correction TP3

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QMessageBox>

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QVector3D>

#include "camera.h"

#define BUFFER_OFFSET(i)   ((char *)NULL + (i))


class Drawable: public QOpenGLFunctions
{
public:
    Drawable();
    ~Drawable();
    virtual void initializeVAO(){}
    virtual void draw(){}
    virtual QMatrix4x4 world(){
        QMatrix4x4 model = QMatrix4x4();
        model.translate(-0.5,-0.5,-0.5);
        return model;
    }

    void initializeShader(QString vs, QString fs);

    void setPosition(GLfloat x, GLfloat y, GLfloat z);
    void setOrientation(GLfloat roulis, GLfloat tangage, GLfloat lacet);

    Camera *camera() const;
    void setCamera(Camera *camera);
    void tourne(float a, float b, float c);

    QVector3D position() const;

protected:
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLBuffer* m_vbo;
    QOpenGLShaderProgram* m_programme;

    Camera* m_camera;

    QVector3D m_position;
    GLfloat m_roulis, m_tangage, m_lacet;
};

#endif // DRAWABLE_H
