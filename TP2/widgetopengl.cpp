// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// Tanguy Invernizzi
// EPU 2018-19

#include "widgetopengl.h"

#define BUFFER_OFFSET(i)   ((char *)NULL + (i))

WidgetOpenGL::WidgetOpenGL(QWidget* parent)
    :QOpenGLWidget(parent),QOpenGLFunctions()
{
    m_programme = new QOpenGLShaderProgram(this);
    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vao = new QOpenGLVertexArrayObject(this);
    m_angleZ = 0;
    m_angleY = 0;
    isAnimationStarted = false;
    currentFov = 30;
    m_timer = new QTimer();
    u_opacity = 1;
}

WidgetOpenGL::~WidgetOpenGL()
{
    m_programme->removeAllShaders();
    delete m_programme;
    delete m_vbo;
    delete m_vao;
}

void WidgetOpenGL::initializeGL()
{
    initializeOpenGLFunctions();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(1);

    glClearColor(0.8f,0.8f,0.8f,1.0f);  //gris clair

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initializeShader();
    initializeVAO();
}

void WidgetOpenGL::initializeShader()
{
    bool resultat;
    m_programme->create();

    //Vertex Shader
    resultat = m_programme->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert");
    if (!resultat)     {
        QMessageBox msg;
        msg.setWindowTitle("Vertex shader");
        msg.setText(m_programme->log());
        msg.exec();
    }

    //Fragment Shader
    resultat = m_programme->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag");
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

void WidgetOpenGL::initializeVAO()
{
    // Initialisation des couleurs
    QVector3D rouge(1,0,0);
    QVector3D bleu(0,0,1);
    QVector3D vert(0,1,0);
    QVector3D rose(1,0,1);

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
        bleu,bleu,bleu,bleu,
        rose,rose,rose,rose,
        vert,vert,vert,vert,
        vert,vert,vert,vert,
        rose,rose,rose,rose,
        rouge,rouge,rouge,rouge
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
            m_programme->setAttributeArray("col", GL_FLOAT, BUFFER_OFFSET(24*sizeof(QVector3D)),3);

            //Activation des attributs
            m_programme->enableAttributeArray("pos");
            m_programme->enableAttributeArray("col");

        m_programme->release();

        //Liberation
        m_vbo->release();
    m_vao->release();

}



void WidgetOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Définition de la matrice de placement
    QMatrix4x4 model = QMatrix4x4();

    model.rotate(m_angleY,0,1,0);
    model.rotate(m_angleZ,0,0,1);
    model.translate(-0.5,-0.5,-0.5);

    //Définition de la matrice de projection
    QMatrix4x4 proj = QMatrix4x4();
    GLfloat aspect = GLfloat(width())/height();
    proj.perspective(currentFov, aspect, 0.1f, 100.0f);

    //Définition de la matrice de vue
    QMatrix4x4 vue = QMatrix4x4();
    vue.translate(0, 0, -5);

    //Produit des trois matrices (dans ce sens!)
    QMatrix4x4 matrix = proj * vue * model;

    m_programme->bind();
    m_programme->setUniformValue("u_ModelViewProjectionMatrix", matrix);
    m_programme->setUniformValue("u_opacity", u_opacity);

    m_vao->bind();

    for (int var = 0; var < 6; ++var) {
        glDrawArrays(GL_QUADS, var * 4, 4);
    }

    m_vao->release();
    m_programme->release();
}


void WidgetOpenGL::resizeGL(int width, int height)
{
    //transformation de viewport
    glViewport(0, 0, width, height);
}


void WidgetOpenGL::update()
{
    if(isAnimationStarted) {
        m_angleY = m_angleY + 0.1f;
        m_angleZ = m_angleZ + 0.05f;
    }
    QOpenGLWidget::update();
}

void WidgetOpenGL::startAnimation()
{
    isAnimationStarted = !isAnimationStarted;
}

void WidgetOpenGL::changeFov(int fov)
{
    currentFov = fov;
}

void WidgetOpenGL::changeOpacity(int opacity)
{
    u_opacity = opacity / 100.0;
}
