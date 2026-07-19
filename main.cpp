#include <iostream>
#include "Cancion.h"
#include "crud.h"


int main() {
	int opcion = -1;
	Cancion can;
	string rutaArchivo = "C:/Users/JEREMY/Downloads/crudProyecto.txt";  
	int idBuscar = 0;
	
	crearArchivo(rutaArchivo);
	while (opcion != 0) {
		cout << "\n\n=== REPRODUCTOR DE MUSICA ESFOT ===" << endl;
		cout << " Menu de opciones " << endl;
		cout << " 1. Ver todas las canciones " << endl;
		cout << " 2. Buscar una cancion por ID " << endl;
		cout << " 3. Agregar nueva cancion " << endl;
		cout << " 4. Actualizar informacion de una cancion " << endl;
		cout << " 5. Eliminar una cancion " << endl;
		cout << " 0. Salir " << endl;
		cout << " Digite opcion: "; cin >> opcion;
		
		switch (opcion) {
		case 1:
			verTodas(rutaArchivo);
			break;
		case 2:
			cout << "Ingrese el ID de la cancion a buscar: "; cin >> idBuscar;
			can = buscar(idBuscar, rutaArchivo);
			if (can.id != -1) {
				cout << can.mostrar() << endl;
			} else {
				cout << "Cancion no encontrada." << endl;
			}
			break;
		case 3:
			cout << "Ingrese el ID de la cancion: "; cin >> can.id;
			cout << "Ingrese el nombre (use '_'): "; cin >> can.nombre;
			cout << "Ingrese el artista (use '_'): "; cin >> can.artista;
			cout << "Ingrese el genero (use '_'): "; cin >> can.genero;
			agregar(can, rutaArchivo);
			break; 
		case 4:
			cout << "Ingrese el ID de la cancion a actualizar: "; cin >> can.id;
			cout << "Ingrese el nuevo nombre (use '_'): "; cin >> can.nombre;
			cout << "Ingrese el nuevo artista (use '_'): "; cin >> can.artista;
			cout << "Ingrese el nuevo genero (use '_'): "; cin >> can.genero;
			actualizar(can, rutaArchivo);
			break;
		case 5:
			cout << "Ingrese el ID de la cancion a eliminar: "; cin >> idBuscar;
			eliminar(idBuscar, rutaArchivo); 
			break;
		case 0:
			cout << "Saliendo del reproductor..." << endl;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
	return 0;
}
