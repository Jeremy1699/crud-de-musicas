#ifndef CRUD_H
#define CRUD_H
#include <vector>
#include <string>
#include "Cancion.h"

using namespace std;

//Se fue creando el void de cada funcion y para que va a servir 
void crearArchivo(const string& ruta);
void guardar(vector<Cancion> lista, string ruta);
vector<Cancion> leer(const string& ruta);
Cancion buscar(int id, const string& ruta);
void agregar(const Cancion& nuevaCancion, const string& ruta);
void eliminar(int id, const string& ruta);
void actualizar(const Cancion& cancionActualizada, const string& ruta);
void verTodas(const string& ruta);
#endif
