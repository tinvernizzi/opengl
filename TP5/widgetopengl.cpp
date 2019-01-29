// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#include "widgetopengl.h"

#define BUFFER_OFFSET(i)   ((char *)NULL + (i))

WidgetOpenGL::WidgetOpenGL(QWidget* parent)
    :QOpenGLWidget(parent),QOpenGLFunctions()
{
    m_angleY = 0;
    m_angleY = 0;
    isAnimationStarted = false;
    currentFov = 30;
    m_timer = new QTimer();
    u_opacity = 1;
}

WidgetOpenGL::~WidgetOpenGL()
{
}

void WidgetOpenGL::initializeGL()
{
    initializeOpenGLFunctions();

    GLfloat aspect = GLfloat(width())/height();
    m_camera = new Camera(aspect);

    //Cube *m_cube = new Cube();
    //m_cube->initializeVAO();
   // m_cube->setCamera(m_camera);
   // m_objets.append(m_cube);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(1);

    glClearColor(0.8f,0.8f,0.8f,1.0f);  //gris clair

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void WidgetOpenGL::resizeGL(int width, int height)
{
    //transformation de viewport
    glViewport(0, 0, width, height);
}

void WidgetOpenGL::addDrawable(Drawable *d)
{
    this->makeCurrent();
    d->initializeVAO();
    d->setCamera(m_camera);
    m_objets.append(d);
}


void WidgetOpenGL::update()
{
    if(isAnimationStarted) {
        for (auto &objet : m_objets) // access by reference to avoid copying
        {
            objet->tourne(0.05,0.05,0.05);
        }

    }
    QOpenGLWidget::update();
}

void WidgetOpenGL::startAnimation()
{
    isAnimationStarted = !isAnimationStarted;
}

void WidgetOpenGL::changeFov(int fov)
{
    m_camera->setFov(fov);
}

void WidgetOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto &objet : m_objets) // access by reference to avoid copying
    {
        objet->draw();
    }
}

