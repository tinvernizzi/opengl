#include "cubepolytech.h"

CubePolytech::CubePolytech():Drawable()
{

}

void CubePolytech::setTexture(QString textureFilename)
{
    m_texture = new QOpenGLTexture(QImage(textureFilename).mirrored());
}

QMatrix4x4 CubePolytech::world()
{
    //Définition de la matrice de placement
    QMatrix4x4 model = QMatrix4x4();

    model.translate(-0.5,-0.5,-0.5);

    model.translate(this->position().x(),this->position().y(),this->position().z());

    model.rotate(this->m_roulis,1,0,0);
    model.rotate(this->m_tangage,0,1,0);
    model.rotate(this->m_lacet,0,0,1);
    return model;
}


void CubePolytech::initializeVAO()
{
    initializeOpenGLFunctions();
    initializeShader(":/shaders/texture.vert", ":/shaders/texture.frag");

    // Coordonées
    QVector3D NW(0,1,0);
    QVector3D NE(1,1,0);
    QVector3D SW(0,0,0);
    QVector3D SE(1,0,0);

    // Initialisation des sommets
    QVector3D A(0,0,0);
    QVector3D B(1,0,0);
    QVector3D C(0,0,1);
    QVector3D D(1,0,1);
    QVector3D E(0,1,0);
    QVector3D F(1,1,0);
    QVector3D H(1,1,1);
    QVector3D G(0,1,1);

    //Tableau des données
    QVector3D vertex_data[] = {
        A, B, D, C,
        E, F, B, A,
        F, H, D, B,
        E, A, C, G,
        C, D, H, G,
        G, H, F, E,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE,
        NE, NW, SW, SE
    };

    // Polytech : NE, NW,SW, SE

    //creation du VA0 et du VBO
    m_vao->create();
    m_vbo->create();

    //Lien du VAO
    m_vao->bind();

        //lien du VBO
        m_vbo->bind();

        //Ecriture des données dans le VBO
        m_vbo->allocate(vertex_data,sizeof(vertex_data));
        m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);

        //Lien entre VBO et les variables d'attribut du vertex shader
        m_programme->bind();

            //Lien avec les attributs du programme
            m_programme->setAttributeArray("pos", GL_FLOAT, BUFFER_OFFSET(0), 3);
            m_programme->setAttributeArray("tex", GL_FLOAT, BUFFER_OFFSET(24*sizeof(QVector3D)),3);

            //Activation des attributs
            m_programme->enableAttributeArray("pos");
            m_programme->enableAttributeArray("tex");

        m_programme->release();

        //Liberation
        m_vbo->release();
    m_vao->release();
}


void CubePolytech::draw()
{
    //Produit des trois matrices (dans ce sens!)
    QMatrix4x4 matrix = this->camera()->projection() * this->camera()->view() * this->world();

    m_programme->bind();
    m_programme->setUniformValue("u_ModelViewProjectionMatrix", matrix);

    m_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);      //Liaison de la texture
    m_texture->bind();     //Activation de la tetxure
    glEnable(GL_TEXTURE_2D);
    m_programme->setUniformValue("texture0",0);

    m_vao->bind();

    for (int var = 0; var < 6; ++var) {
        glDrawArrays(GL_QUADS, var * 4, 4);
    }

    m_vao->release();
    m_programme->release();
}
