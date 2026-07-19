#ifndef CANCION_H
#define CANCION_H
#include <string>
#include <sstream>

using namespace std;

struct Cancion {   
	int id;   
	string nombre; 
	string artista;
	string genero;
	
	string mostrar() const {
		ostringstream oss;
		oss << "ID: " << id << ", Nombre: " << nombre << ", Artista: "
		<< artista << ", Genero: " << genero;
		return oss.str();
	}
};
#endif

