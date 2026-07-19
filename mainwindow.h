#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <vector>
#include <string>
#include "crud.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAgregarClicked();
    void onActualizarClicked();
    void onBuscarClicked();
    void onEliminarClicked();
    void onMostrarTodoClicked();

private:
    Ui::MainWindow *ui;
    string rutaArchivo;

    void cargarTabla(const vector<Cancion>& canciones);
    void limpiarCampos();
    void mostrarMensaje(const QString& mensaje);
};

#endif // MAINWINDOW_H