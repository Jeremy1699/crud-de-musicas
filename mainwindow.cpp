#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    rutaArchivo = "C:/Users/JEREMY/Downloads/crudProyecto.txt";


    crearArchivo(rutaArchivo);

    ui->tablaCanciones->setColumnCount(4);
    QStringList headers = {"ID", "Nombre", "Artista", "Género"};
    ui->tablaCanciones->setHorizontalHeaderLabels(headers);
    ui->tablaCanciones->horizontalHeader()->setStretchLastSection(true);
    ui->tablaCanciones->setAlternatingRowColors(true);


    onMostrarTodoClicked();


    connect(ui->btnAgregar, &QPushButton::clicked, this, &MainWindow::onAgregarClicked);
    connect(ui->btnActualizar, &QPushButton::clicked, this, &MainWindow::onActualizarClicked);
    connect(ui->btnBuscar, &QPushButton::clicked, this, &MainWindow::onBuscarClicked);
    connect(ui->btnEliminar, &QPushButton::clicked, this, &MainWindow::onEliminarClicked);
    connect(ui->btnMostrarTodo, &QPushButton::clicked, this, &MainWindow::onMostrarTodoClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarTabla(const vector<Cancion>& canciones) {
    ui->tablaCanciones->setRowCount(0);

    for (const auto& cancion : canciones) {
        int row = ui->tablaCanciones->rowCount();
        ui->tablaCanciones->insertRow(row);

        ui->tablaCanciones->setItem(row, 0, new QTableWidgetItem(QString::number(cancion.id)));
        ui->tablaCanciones->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(cancion.nombre)));
        ui->tablaCanciones->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(cancion.artista)));
        ui->tablaCanciones->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(cancion.genero)));
    }

    ui->tablaCanciones->resizeColumnsToContents();
}

void MainWindow::limpiarCampos() {
    ui->txtId->clear();
    ui->txtNombre->clear();
    ui->txtArtista->clear();
    ui->txtGenero->clear();
}

void MainWindow::mostrarMensaje(const QString& mensaje) {
    QMessageBox::information(this, "Información", mensaje);
}

void MainWindow::onAgregarClicked() {

    if (ui->txtId->text().isEmpty() ||
        ui->txtNombre->text().isEmpty() ||
        ui->txtArtista->text().isEmpty() ||
        ui->txtGenero->text().isEmpty()) {
        mostrarMensaje("Por favor, complete todos los campos");
        return;
    }

    Cancion nuevaCancion;
    nuevaCancion.id = ui->txtId->text().toInt();
    nuevaCancion.nombre = ui->txtNombre->text().toStdString();
    nuevaCancion.artista = ui->txtArtista->text().toStdString();
    nuevaCancion.genero = ui->txtGenero->text().toStdString();

    agregar(nuevaCancion, rutaArchivo);
    onMostrarTodoClicked();
    limpiarCampos();
    mostrarMensaje("Canción agregada correctamente");
}

void MainWindow::onActualizarClicked() {
    if (ui->txtId->text().isEmpty()) {
        mostrarMensaje("Por favor, ingrese el ID de la canción a actualizar");
        return;
    }

    Cancion cancionActualizada;
    cancionActualizada.id = ui->txtId->text().toInt();
    cancionActualizada.nombre = ui->txtNombre->text().toStdString();
    cancionActualizada.artista = ui->txtArtista->text().toStdString();
    cancionActualizada.genero = ui->txtGenero->text().toStdString();

    actualizar(cancionActualizada, rutaArchivo);
    onMostrarTodoClicked();
    limpiarCampos();
    mostrarMensaje("Canción actualizada correctamente");
}

void MainWindow::onBuscarClicked() {
    if (ui->txtId->text().isEmpty()) {
        mostrarMensaje("Por favor, ingrese el ID de la canción a buscar");
        return;
    }

    int id = ui->txtId->text().toInt();
    Cancion cancion = buscar(id, rutaArchivo);

    if (cancion.id != -1) {
        ui->txtNombre->setText(QString::fromStdString(cancion.nombre));
        ui->txtArtista->setText(QString::fromStdString(cancion.artista));
        ui->txtGenero->setText(QString::fromStdString(cancion.genero));

        vector<Cancion> canciones;
        canciones.push_back(cancion);
        cargarTabla(canciones);
    } else {
        mostrarMensaje("Canción no encontrada");
    }
}

void MainWindow::onEliminarClicked() {
    if (ui->txtId->text().isEmpty()) {
        mostrarMensaje("Por favor, ingrese el ID de la canción a eliminar");
        return;
    }

    int id = ui->txtId->text().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmar eliminación",
                                  "¿Está seguro de eliminar la canción con ID " + QString::number(id) + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        eliminar(id, rutaArchivo);
        onMostrarTodoClicked();
        limpiarCampos();
        mostrarMensaje("Canción eliminada correctamente");
    }
}

void MainWindow::onMostrarTodoClicked() {
    vector<Cancion> canciones = leer(rutaArchivo);
    cargarTabla(canciones);
}