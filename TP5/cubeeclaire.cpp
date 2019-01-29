#include "cubeeclaire.h"

CubeEclaire::CubeEclaire():Drawable()
{
}

void CubeEclaire::setTexture(QString textureFilename)
{
    m_texture = new QOpenGLTexture(QImage(textureFilename).mirrored());
}


QMatrix4x4 CubeEclaire::world()
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

void CubeEclaire::initializeVAO()
{
    initializeOpenGLFunctions();
    initializeShader(":/shaders/lumiere.vert", ":/shaders/lumiere.frag");

    QVector3D pp1(0,-1,0);
    QVector3D pp2(0,0,-1);
    QVector3D pp3(1,0,0);
    QVector3D pp4(-1,0,0);
    QVector3D pp5(0,0,1);
    QVector3D pp6(0,1,0);

    // Coordonées
    QVector3D NW1(0,0.75,0);
    QVector3D NE1(0.25,0.75,0);
    QVector3D SW1(0,0.5,0);
    QVector3D SE1(0.25,0.5,0);

    QVector3D NW2(0.75,0.75,0);
    QVector3D NE2(1,0.75,0);
    QVector3D SW2(0.75,0.5,0);
    QVector3D SE2(1,0.5,0);

    QVector3D NW3(0,1,0);
    QVector3D NE3(0.25,1,0);
    QVector3D SW3(0,0.75,0);
    QVector3D SE3(0.25,0.75,0);

    QVector3D NW4(0,0.5,0);
    QVector3D NE4(0.25,0.5,0);
    QVector3D SW4(0,0.25,0);
    QVector3D SE4(0.25,0.25,0);

    QVector3D NW5(0.25,0.75,0);
    QVector3D NE5(0.5,0.75,0);
    QVector3D SW5(0.25,0.5,0);
    QVector3D SE5(0.5,0.5,0);

    QVector3D NW6(0.5,0.75,0);
    QVector3D NE6(0.75,0.75,0);
    QVector3D SW6(0.5,0.5,0);
    QVector3D SE6(0.75,0.5,0);

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
        NE1, NW1, SW1, SE1,
        NE2, NW2, SW2, SE2,
        NE3, NW3, SW3, SE3,
        NE4, NW4, SW4, SE4,
        NE5, NW5, SW5, SE5,
        NE6, NW6, SW6, SE6,
        pp1, pp2, pp3, pp4, pp5, pp6
    };

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
            m_programme->setAttributeArray("normal", GL_FLOAT, BUFFER_OFFSET(48*sizeof(QVector3D)),3);

            //Activation des attributs
            m_programme->enableAttributeArray("pos");
            m_programme->enableAttributeArray("tex");
            m_programme->enableAttributeArray("normal");

        m_programme->release();

        //Liberation
        m_vbo->release();
    m_vao->release();
}


void CubeEclaire::draw()
{
    //Produit des trois matrices (dans ce sens!)
    QMatrix4x4 matrix = this->camera()->projection() * this->camera()->view() * this->world();

    m_programme->bind();
    m_programme->setUniformValue("u_ModelViewProjectionMatrix", matrix);
    m_programme->setUniformValue("u_view", this->camera()->view());
    m_programme->setUniformValue("u_model", this->world());
    m_programme->setUniformValue("u_projection", this->camera()->projection());

    qInfo( "C Style Info Message" );
    m_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    qInfo( "C Style Info Message" );
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear); // Liaison de la texture
    m_texture->bind();     //Activation de la tetxure
    m_programme->setUniformValue("texture0",0);


    m_vao->bind();

    for (int var = 0; var < 6; ++var) {
        glDrawArrays(GL_QUADS, var * 4, 4);
    }

    m_vao->release();
    m_programme->release();
}
