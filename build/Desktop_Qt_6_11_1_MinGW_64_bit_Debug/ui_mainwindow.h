/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *txtId;
    QLineEdit *txtNombre;
    QLineEdit *txtArtista;
    QLineEdit *txtGenero;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btnAgregar;
    QPushButton *btnActualizar;
    QPushButton *btnBuscar;
    QPushButton *btnEliminar;
    QPushButton *btnMostrarTodo;
    QTableWidget *tablaCanciones;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("    background-color: #E3F2FD;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        txtId = new QLineEdit(centralwidget);
        txtId->setObjectName("txtId");
        txtId->setGeometry(QRect(360, 100, 113, 22));
        txtId->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border:2px solid #90CAF9;\n"
"    border-radius:6px;\n"
"    padding:4px;\n"
"    background:white;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"    border:2px solid #1976D2;\n"
"}"));
        txtNombre = new QLineEdit(centralwidget);
        txtNombre->setObjectName("txtNombre");
        txtNombre->setGeometry(QRect(360, 130, 113, 22));
        txtNombre->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border:2px solid #90CAF9;\n"
"    border-radius:6px;\n"
"    padding:4px;\n"
"    background:white;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"    border:2px solid #1976D2;\n"
"}"));
        txtArtista = new QLineEdit(centralwidget);
        txtArtista->setObjectName("txtArtista");
        txtArtista->setGeometry(QRect(360, 170, 113, 22));
        txtArtista->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border:2px solid #90CAF9;\n"
"    border-radius:6px;\n"
"    padding:4px;\n"
"    background:white;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"    border:2px solid #1976D2;\n"
"}"));
        txtGenero = new QLineEdit(centralwidget);
        txtGenero->setObjectName("txtGenero");
        txtGenero->setGeometry(QRect(360, 200, 113, 22));
        txtGenero->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border:2px solid #90CAF9;\n"
"    border-radius:6px;\n"
"    padding:4px;\n"
"    background:white;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"    border:2px solid #1976D2;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 100, 161, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 130, 191, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 170, 161, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 200, 181, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 20, 251, 51));
        label_5->setStyleSheet(QString::fromUtf8("color:#1565C0;"));
        btnAgregar = new QPushButton(centralwidget);
        btnAgregar->setObjectName("btnAgregar");
        btnAgregar->setGeometry(QRect(130, 280, 71, 31));
        btnAgregar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#2196F3;\n"
"    color:white;\n"
"    border-radius:8px;\n"
"    padding:6px;\n"
"    font: bold 10pt;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    background-color:#0D47A1;\n"
"}"));
        btnActualizar = new QPushButton(centralwidget);
        btnActualizar->setObjectName("btnActualizar");
        btnActualizar->setGeometry(QRect(230, 280, 71, 31));
        btnActualizar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#2196F3;\n"
"    color:white;\n"
"    border-radius:8px;\n"
"    padding:6px;\n"
"    font: bold 10pt;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    background-color:#0D47A1;\n"
"}"));
        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(350, 280, 71, 31));
        btnBuscar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#2196F3;\n"
"    color:white;\n"
"    border-radius:8px;\n"
"    padding:6px;\n"
"    font: bold 10pt;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    background-color:#0D47A1;\n"
"}"));
        btnEliminar = new QPushButton(centralwidget);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(470, 280, 71, 31));
        btnEliminar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#2196F3;\n"
"    color:white;\n"
"    border-radius:8px;\n"
"    padding:6px;\n"
"    font: bold 10pt;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    background-color:#0D47A1;\n"
"}"));
        btnMostrarTodo = new QPushButton(centralwidget);
        btnMostrarTodo->setObjectName("btnMostrarTodo");
        btnMostrarTodo->setGeometry(QRect(570, 280, 91, 31));
        btnMostrarTodo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#2196F3;\n"
"    color:white;\n"
"    border-radius:8px;\n"
"    padding:6px;\n"
"    font: bold 10pt;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    background-color:#0D47A1;\n"
"}"));
        tablaCanciones = new QTableWidget(centralwidget);
        tablaCanciones->setObjectName("tablaCanciones");
        tablaCanciones->setGeometry(QRect(80, 320, 601, 192));
        tablaCanciones->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"    background-color: white;\n"
"    border:2px solid #2196F3;\n"
"    border-radius:8px;\n"
"    color:black;\n"
"    font: 10pt Consolas;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ingresa el ID de la Cancion", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ingresa el nombre de la Cancion", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ingresa el nombre del Artista", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ingresa el Genero de la Cancion", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CRUD DE CANCIONES", nullptr));
        btnAgregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnActualizar->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnMostrarTodo->setText(QCoreApplication::translate("MainWindow", "Mostrar todo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
