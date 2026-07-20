#include <iostream>
#include <fstream>
#include <algorithm>
#include "crud.h"
//Gonzalez Alejandro
using namespace std;
//Aca ponemos unas canciones por default       #comentado por ALEJANDRO GONZALES       
vector<Cancion> listaCanciones = {
	{1, "Bohemian_Rhapsody", "Queen", "Rock"},
	{2, "Shape_of_You", "Ed_Sheeran", "Pop"},
	{3, "Hotel_California", "Eagles", "Rock"}
};

// Permite imprimir directamente una canción #comentado por ALEJANDRO GONZALES    
ostream& operator<<(ostream& os, const Cancion& c) {
	os << c.id << " " << c.nombre << " " << c.artista << " " << c.genero << endl;
	return os;
}


// Recorre e imprime todas las canciones #comentado por ALEJANDRO GONZALES    
ostream& operator<<(ostream& os, const vector<Cancion>& canciones) {
	for (const auto& c : canciones) {
		os << c;
	}
	return os;
}

// Permite leer las propiedades separadas por desde un archivo 
istream& operator>>(istream& is, Cancion& c) {
	is >> c.id >> c.nombre >> c.artista >> c.genero;
	return is;
}

// Lee el archivo de forma continua hasta llegar al final (EOF) y llena el vector.
istream& operator>>(istream& is, vector<Cancion>& canciones) {
	Cancion c;
	while (is >> c) {
		canciones.push_back(c);
	}
	return is;
}

// Guarda la lista completa de canciones en el disco
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

// Lee todas las canciones almacenadas en el archivo 
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

// Busca una canción específica por su ID. Retorna un objeto con ID -1 si no se encuentra.
Cancion buscar(int id, const string& ruta) {
	Cancion cancionB;
	cancionB.id = -1; 
	cancionB.nombre = "No encontrado";
	// Búsqueda lineal en el vector devuelto por el archivo
	for (const auto& can : leer(ruta)) {
		if (id == can.id) {
			cancionB = can; 
			break;
		}
	}
	return cancionB;    
}

// Inserta una nueva canción al archivo validando el ID 
void agregar(const Cancion& nuevaCancion, const string& ruta) {
	vector<Cancion> lista = leer(ruta);
	// find_if busca un elemento que cumpla con la condición de la función lambda (mismo ID)
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

// Elimina una canción del archivo buscando por su ID único.
void eliminar(int id, const string& ruta) {
	vector<Cancion> lista = leer(ruta);
// remove_if desplaza los elementos a eliminar al final del vector y retorna un iterador al inicio de estos
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

// Modifica los datos de una canción existente manteniendo el mismo ID.
void actualizar(const Cancion& cancionActualizada, const string& ruta) {
	vector<Cancion> listaLocal = leer(ruta);
	// Localiza la posición de la canción que se desea modificar
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

// Muestra en consola la lista completa de canciones formateadas de forma amigable.
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

// Inicializa el entorno de datos, si el archivo no existe, crea uno nuevo con la lista por defecto
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

