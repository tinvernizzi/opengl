#ifndef CUBE_H
#define CUBE_H

#include "drawable.h"

class Cube : public Drawable
{
public:
    Cube();
    void initializeVAO();
    void draw();
    QMatrix4x4 world();
    float u_opacity;
};

#endif // CUBE_H
