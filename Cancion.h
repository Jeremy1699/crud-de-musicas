#ifndef CANCION_H
#define CANCION_H
#include <string>
#include <sstream>

using namespace std;

//Se crea la estructura de la cancion en C++
struct Cancion {   
	int id;   
	string nombre; 
	string artista;
	string genero;

//Se crea el constructor de la cancion
	string mostrar() const {
		ostringstream oss;
		oss << "ID: " << id << ", Nombre: " << nombre << ", Artista: "
		<< artista << ", Genero: " << genero;
		return oss.str();
	}
};
#endif

