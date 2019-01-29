#include "camera.h"

Camera::Camera()
{
    m_position = QVector3D(0,0,4);
    m_target = QVector3D(0,0,0);
    m_up = QVector3D(0,1,0);
    m_fov = 30.0;
    m_aspect_ratio = 100.0;
    m_zmin = 0.0;
    m_zmax = 0.0;
}

Camera::Camera(GLfloat aspect)
{
    m_position = QVector3D(0,0,4);
    m_target = QVector3D(0,0,0);
    m_up = QVector3D(0,1,0);
    m_fov = 30.0;
    m_aspect_ratio = aspect;
    m_zmin = 0.0;
    m_zmax = 0.0;
}

QMatrix4x4 Camera::view()
{
    QMatrix4x4 view = QMatrix4x4();
    view.lookAt(m_position, m_target, m_up);
    return view;
}

QMatrix4x4 Camera::projection()
{
    QMatrix4x4 proj = QMatrix4x4();
    proj.perspective(m_fov, m_aspect_ratio, 0.1f, 100.0f);
    return proj;
}

QVector3D Camera::up() const
{
    return m_up;
}

void Camera::setUp(const QVector3D &up)
{
    m_up = up;
}

QVector3D Camera::target() const
{
    return m_target;
}

void Camera::setTarget(const QVector3D &target)
{
    m_target = target;
}

QVector3D Camera::position() const
{
    return m_position;
}

void Camera::setPosition(const QVector3D &position)
{
    m_position = position;
}

float Camera::zmax() const
{
    return m_zmax;
}

void Camera::setZmax(float zmax)
{
    m_zmax = zmax;
}

float Camera::zmin() const
{
    return m_zmin;
}

void Camera::setZmin(float zmin)
{
    m_zmin = zmin;
}

float Camera::aspect_ratio() const
{
    return m_aspect_ratio;
}

void Camera::setAspect_ratio(float aspect_ratio)
{
    m_aspect_ratio = aspect_ratio;
}

float Camera::fov() const
{
    return m_fov;
}

void Camera::setFov(float fov)
{
    m_fov = fov;
}
