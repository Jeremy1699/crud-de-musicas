#include <iostream>
#include <fstream>
#include <algorithm>
#include "crud.h"

using namespace std;
//Aca ponemos unas canciones por default         
vector<Cancion> listaCanciones = {
	{1, "Bohemian_Rhapsody", "Queen", "Rock"},
	{2, "Shape_of_You", "Ed_Sheeran", "Pop"},
	{3, "Hotel_California", "Eagles", "Rock"}
};

ostream& operator<<(ostream& os, const Cancion& c) {
	os << c.id << " " << c.nombre << " " << c.artista << " " << c.genero << endl;
	return os;
}

ostream& operator<<(ostream& os, const vector<Cancion>& canciones) {
	for (const auto& c : canciones) {
		os << c;
	}
	return os;
}

istream& operator>>(istream& is, Cancion& c) {
	is >> c.id >> c.nombre >> c.artista >> c.genero;
	return is;
}

istream& operator>>(istream& is, vector<Cancion>& canciones) {
	Cancion c;
	while (is >> c) {
		canciones.push_back(c);
	}
	return is;
}

void guardar(vector<Cancion> lista, string ruta) {
	ofstream archivo(ruta);
	if (archivo.is_open()) {
		archivo << lista;
		archivo.close();
		cout << "Archivo guardado correctamente.\n";
	} else {
		cerr << "No se pudo guardar el archivo.\n";
	}
}

vector<Cancion> leer(const string& ruta) {
	vector<Cancion> cancionesLeidas;
	ifstream archivoEntrada(ruta);
	if (archivoEntrada.is_open()) {
		archivoEntrada >> cancionesLeidas;
		archivoEntrada.close();
	} else {
		cerr << "No se pudo leer el archivo.\n";
	}
	return cancionesLeidas;
}

Cancion buscar(int id, const string& ruta) {
	Cancion cancionB;
	cancionB.id = -1; 
	cancionB.nombre = "No encontrado";
	for (const auto& can : leer(ruta)) {
		if (id == can.id) {
			cancionB = can; 
			break;
		}
	}
	return cancionB;    
}

void agregar(const Cancion& nuevaCancion, const string& ruta) {
	vector<Cancion> lista = leer(ruta);
	auto it = find_if(lista.begin(), lista.end(),
					  [&](const Cancion& c) { return c.id == nuevaCancion.id; });
	
	if (it == lista.end()) {
		lista.push_back(nuevaCancion);
		cout << "Cancion con ID " << nuevaCancion.id << " agregada.\n";
	} else {
		cout << "La cancion con ID " << nuevaCancion.id << " ya existe.\n";
	}
	guardar(lista, ruta);
}

void eliminar(int id, const string& ruta) {
	vector<Cancion> lista = leer(ruta);
	auto it = remove_if(lista.begin(), lista.end(),
						[&](const Cancion& c) { return c.id == id; });
	if (it != lista.end()) {
		lista.erase(it, lista.end());
		cout << "Cancion con ID " << id << " eliminada.\n";
	} else {
		cout << "La cancion con ID " << id << " no se encontro.\n";
	}
	guardar(lista, ruta);
}

void actualizar(const Cancion& cancionActualizada, const string& ruta) {
	vector<Cancion> listaLocal = leer(ruta);
	auto it = find_if(listaLocal.begin(), listaLocal.end(),
					  [&](const Cancion& c) { return c.id == cancionActualizada.id; });
	
	if (it != listaLocal.end()) {
		it->nombre = cancionActualizada.nombre;
		it->artista = cancionActualizada.artista;
		it->genero = cancionActualizada.genero;
		cout << "Cancion con el ID " << cancionActualizada.id << " actualizada.\n";
	} else {
		cout << "La cancion con el ID " << cancionActualizada.id << " no se encontro.\n";
	}
	guardar(listaLocal, ruta);
} 

void verTodas(const string& ruta) {
	vector<Cancion> lista = leer(ruta);
	if (lista.empty()) {
		cout << "La playlist esta vacia.\n";
		return;
	}
	for (const auto& can : lista) {
		cout << can.mostrar() << endl;
	}
}

void crearArchivo(const string& ruta) {
	ifstream archivoPrueba(ruta);
	if (!archivoPrueba.is_open()) {
		archivoPrueba.close();
		cout << "El archivo no existe. Creando uno nuevo con datos...\n";
		guardar(listaCanciones, ruta);
	} else {
		archivoPrueba.close();
		cout << "El archivo ya existe. Cargando datos...\n";
	}
}

