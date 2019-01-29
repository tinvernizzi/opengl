#ifndef CAMERA_H
#define CAMERA_H
    
#include <QtGui>
#include <QMessageBox>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>

class Camera
{
public:
    Camera();
    Camera(GLfloat aspect);

    float fov() const;
    void setFov(float fov);

    float aspect_ratio() const;
    void setAspect_ratio(float aspect_ratio);

    float zmin() const;
    void setZmin(float zmin);

    float zmax() const;
    void setZmax(float zmax);

    QVector3D position() const;
    void setPosition(const QVector3D &position);

    QVector3D target() const;
    void setTarget(const QVector3D &target);

    QVector3D up() const;
    void setUp(const QVector3D &up);

    QMatrix4x4 view();
    QMatrix4x4 projection();

private:
    float m_fov;
    float m_aspect_ratio;
    float m_zmin;
    float m_zmax;
    QVector3D m_position;
    QVector3D m_target;
    QVector3D m_up;
};

#endif // CAMERA_H
