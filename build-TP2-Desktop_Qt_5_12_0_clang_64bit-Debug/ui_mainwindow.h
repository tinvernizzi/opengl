/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgetopengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    WidgetOpenGL *openGLWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLabel *fovTextLabel;
    QDial *fov;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QDoubleSpinBox *x;
    QLabel *label_4;
    QDoubleSpinBox *lacet;
    QLabel *label_3;
    QDoubleSpinBox *tangage;
    QDoubleSpinBox *y;
    QDoubleSpinBox *z;
    QDoubleSpinBox *roulis;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 531);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(500, 300));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new WidgetOpenGL(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(400, 300));

        horizontalLayout->addWidget(openGLWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        fovTextLabel = new QLabel(centralWidget);
        fovTextLabel->setObjectName(QString::fromUtf8("fovTextLabel"));
        fovTextLabel->setStyleSheet(QString::fromUtf8(""));
        fovTextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(fovTextLabel);

        fov = new QDial(centralWidget);
        fov->setObjectName(QString::fromUtf8("fov"));
        fov->setMinimum(10);
        fov->setMaximum(120);
        fov->setValue(30);
        fov->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(fov);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignCenter);
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        x = new QDoubleSpinBox(groupBox);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMinimum(-99.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, x);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lacet = new QDoubleSpinBox(groupBox);
        lacet->setObjectName(QString::fromUtf8("lacet"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lacet);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        tangage = new QDoubleSpinBox(groupBox);
        tangage->setObjectName(QString::fromUtf8("tangage"));

        formLayout->setWidget(6, QFormLayout::FieldRole, tangage);

        y = new QDoubleSpinBox(groupBox);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMinimum(-99.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, y);

        z = new QDoubleSpinBox(groupBox);
        z->setObjectName(QString::fromUtf8("z"));
        z->setMinimum(-99.000000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, z);

        roulis = new QDoubleSpinBox(groupBox);
        roulis->setObjectName(QString::fromUtf8("roulis"));

        formLayout->setWidget(5, QFormLayout::FieldRole, roulis);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(9, QFormLayout::SpanningRole, pushButton_2);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 741, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), openGLWidget, SLOT(startAnimation()));
        QObject::connect(fov, SIGNAL(valueChanged(int)), openGLWidget, SLOT(changeFov(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(creeCube()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Realite Virtuelle - TP2 par Tanguy Invernizzi", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Animation", nullptr));
        fovTextLabel->setText(QApplication::translate("MainWindow", "Field of View", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Nouveau Cube", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "x", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "lacet", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "y", nullptr));
        label->setText(QApplication::translate("MainWindow", "z", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "roulis", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "tangage", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cr\303\251er le cube", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
