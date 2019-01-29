#ifndef CUBEECLAIRE_H
#define CUBEECLAIRE_H

#include "drawable.h"

class CubeEclaire : public Drawable
{
public:
    CubeEclaire();
    QMatrix4x4 world();
    void initializeVAO();
    void setTexture(QString textureFilename);
    void draw();

private:
    QOpenGLTexture* m_texture;
};

#endif // CubeEclaire_H
