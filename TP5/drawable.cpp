// Cours de Réalité Virtuelle
// leo.donati@unice.fr
//
// 2016_2017
//
// Correction TP3


#include "drawable.h"

Drawable::Drawable()
    : QOpenGLFunctions(),
      m_position(0.0f,0.0f,0.0f),
      m_roulis(0.0f),
      m_tangage(0.0f),
      m_lacet(0.0f)
{
    m_programme = new QOpenGLShaderProgram();
    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vao = new QOpenGLVertexArrayObject();
}

Drawable::~Drawable()
{
    m_programme->removeAllShaders();
    delete m_programme;
    delete m_vbo;
    delete m_vao;
}

void Drawable::initializeShader(QString vs, QString fs)
{
    initializeOpenGLFunctions();

    m_programme->create();
    bool resultat;

    //Vertex Shader
    resultat = m_programme->addShaderFromSourceFile(QOpenGLShader::Vertex, vs);
    if (!resultat)     {
        QMessageBox msg;
        msg.setWindowTitle("Vertex shader");
        msg.setText(m_programme->log());
        msg.exec();
    }

    //Fragment Shader
    resultat = m_programme->addShaderFromSourceFile(QOpenGLShader::Fragment, fs);
    if (!resultat)     {
        QMessageBox msg;
        msg.setWindowTitle("Fragment shader");
        msg.setText(m_programme->log());
        msg.exec();
    }

    //Link
    resultat = m_programme->link();
    if (!resultat)     {
        QMessageBox msg;
        msg.setWindowTitle("Link du shader program");
        msg.setText(m_programme->log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    //Libération
    m_programme->release();
}



void Drawable::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
    m_position.setX(x);
    m_position.setY(y);
    m_position.setZ(z);
}

void Drawable::setOrientation(GLfloat roulis, GLfloat tangage, GLfloat lacet)
{
    m_roulis = roulis;
    m_tangage = tangage;
    m_lacet = lacet;
}

Camera *Drawable::camera() const
{
    return m_camera;
}

void Drawable::setCamera(Camera *camera)
{
    m_camera = camera;
}

QVector3D Drawable::position() const
{
    return m_position;
}

void Drawable::tourne(GLfloat a, GLfloat b, GLfloat c)
{
    m_roulis = m_roulis + a;
    m_tangage = m_tangage + b;
    m_lacet = m_lacet + c;
}
