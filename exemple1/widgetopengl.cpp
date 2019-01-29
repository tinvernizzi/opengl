// Cours de Réalité Virtuelle
// leo.donati@univ-cotedazur.fr
//
// EPU 2018-19

#include "widgetopengl.h"
#include <QMessageBox>

#define BUFFER_OFFSET(i)   ((char *)NULL + (i))

WidgetOpenGL::WidgetOpenGL(QWidget* parent)
    :QOpenGLWidget(parent),QOpenGLFunctions()
{  }

WidgetOpenGL::~WidgetOpenGL()
{
    glDeleteProgram(m_programme);
    glDeleteBuffers(1, &m_vbo);
}

void WidgetOpenGL::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0.8f,0.8f,0.8f,1.0f);  //gris clair

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    initializeShader();
    initializeVBO();
}

void WidgetOpenGL::initializeShader()
{
    m_programme = glCreateProgram();

    //Vertex Shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    const char* vs_source = "attribute vec3 pos;\n"
            "attribute vec3 col;\n"
            "uniform mat4 u_ModelViewProjectionMatrix;\n"
            "varying vec4 color;\n"
            "\n"
            "void main(void)\n"
            "{\n"
            "    gl_Position = u_ModelViewProjectionMatrix * vec4(pos, 1);\n"
            "    color = vec4(col, 1);\n"
            "}\n";
    glShaderSource(vs, 1, &vs_source, nullptr);
    glCompileShader(vs);
    GLint res;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &res);
    if (res != GL_TRUE)
    {
        QMessageBox msg;
        msg.setText("Echec compilation vertex shader");
        msg.exec();
    }

    glAttachShader(m_programme, vs);

    //Fragment Shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fs_source = "varying vec4 color;\n"
            "\n"
            "void main(void)\n"
            "{\n"
            "    gl_FragColor = color.rgba;\n"
            "}\n";
    glShaderSource(fs, 1, &fs_source, nullptr);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &res);
    if (res != GL_TRUE)
    {
        QMessageBox msg;
        msg.setText("Echec compilation fragment shader");
        msg.exec();
    }

    glAttachShader(m_programme, fs);

    glLinkProgram(m_programme);
    glGetShaderiv(m_programme, GL_LINK_STATUS, &res);
    if (res != GL_TRUE)
    {
        QMessageBox msg;
        msg.setText("Echec link");
        msg.exec();
    }

    glDetachShader(m_programme, vs);
    glDetachShader(m_programme, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void WidgetOpenGL::initializeVBO()
{
    //Tableau des donnees : 3 sommets puis 3 couleurs
    GLfloat vertex_data[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    //Generation d'un nom de VBO
    glGenBuffers(1, &m_vbo);

    //Liaison du VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        //Ecriture des donnees dans le VBO
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    //Libération du VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void WidgetOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Réglages du Shader Program
    glUseProgram(m_programme);

    //Récupération identifiant de la variable uniforme
    GLint idMatrice = glGetUniformLocation(m_programme, "u_ModelViewProjectionMatrix");

    //Définition de la matrice de projetcion
    QMatrix4x4 proj = QMatrix4x4();
    proj.perspective(45, 1.33f, 0.1f, 100.0f);

    //Définiion de la matrice de vue
    QMatrix4x4 vue = QMatrix4x4();
    vue.translate(0, 0, -3);

    //Définition de la matrice de placement
    QMatrix4x4 model = QMatrix4x4();

    //Produit des trois matrices (dans ce sens!)
    QMatrix4x4 matrix = proj * vue * model;

    //Passage de la valeur de la variable uniforme
    glUniformMatrix4fv(idMatrice, 1, GL_FALSE, matrix.data());

    //Récupération des identifinats des attributs du programma
    GLuint idPos = glGetAttribLocation(m_programme, "pos");
    GLuint idCol = glGetAttribLocation(m_programme, "col");

    //Activation du VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        //Lien avec les attributs du programme
        glVertexAttribPointer(idPos, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glVertexAttribPointer(idCol, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(9*sizeof(GLfloat)));

        //Activation des attributs
        glEnableVertexAttribArray(idPos);
        glEnableVertexAttribArray(idCol);

            //Commande de rendu
            glDrawArrays(GL_TRIANGLES, 0, 3);

        //Désactivation des atributs
        glDisableVertexAttribArray(idPos);
        glDisableVertexAttribArray(idCol);

    //Désactivation du VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void WidgetOpenGL::resizeGL(int width, int height)
{
    //transformation de viewport
    glViewport(0, 0, width, height);
}
