#ifndef CUBEPOLYTECH_H
#define CUBEPOLYTECH_H

#include "drawable.h"

class CubePolytech : public Drawable
{
public:
    CubePolytech();
    QMatrix4x4 world();
    void initializeVAO();
    void setTexture(QString textureFilename);
    void draw();

private:
    QOpenGLTexture* m_texture;
};

#endif // CubePolytech_H
