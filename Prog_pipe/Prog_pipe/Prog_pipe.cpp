// Prog_pipe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct jugador {
	string nombre;
	int coord[2];
	int lim = 2;
	int mov = 0;

};

struct laberinto {
	jugador jug[100000];
	int numj = 0;
	int posi[2];
	int tablero[10000][10000];
	int tab_tam[2];
};

void ganador(laberinto tab) {
	bool fin = false;
	for (int i = 0; i < tab.numj; i++) {
		fin = false;
		cout << "jugador " << i << " : ";
		do {
			switch (tab.tablero[tab.jug[i].coord[0]][tab.jug[i].coord[1]]) {
			case 0:
				fin = true;
				break;
			case 1:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] - 1;
				tab.jug[i].mov++;
				cout << " arriba" << endl;
				break;
			case 2:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] - 1;
				tab.jug[i].coord[1] = tab.jug[i].coord[1] + 1;
				tab.jug[i].mov += 2;
				cout << " arriba derecha" << endl;
				break;
			case 3:
				tab.jug[i].coord[1] = tab.jug[i].coord[1] + 1;
				tab.jug[i].mov++;
				cout << " derecha" << endl;
				break;
			case 4:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] + 1;
				tab.jug[i].coord[1] = tab.jug[i].coord[1] + 1;
				tab.jug[i].mov += 2;
				cout << " abajo derecha" << endl;
				break;
			case 5:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] + 1;
				tab.jug[i].mov++;
				cout << " abajo " << endl;
				break;
			case 6:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] + 1;
				tab.jug[i].coord[1] = tab.jug[i].coord[1] - 1;
				tab.jug[i].mov += 2;
				cout << " abajo izquierda" << endl;
				break;
			case 7:
				tab.jug[i].coord[1] = tab.jug[i].coord[1] - 1;
				tab.jug[i].mov++;
				cout << " izquierda " << endl;
				break;
			case 8:
				tab.jug[i].coord[0] = tab.jug[i].coord[0] - 1;
				tab.jug[i].coord[1] = tab.jug[i].coord[1] - 1;
				tab.jug[i].mov += 2;
				cout << " arriba izquierda" << endl;
				break;
			default:
				break;
			}
			if (tab.jug[i].coord[0] == tab.posi[0] && tab.jug[i].coord[1] == tab.posi[1]) {
				fin = true;
			}
			if (tab.jug[i].coord[0] > tab.tab_tam[0] || tab.jug[i].coord[1] > tab.tab_tam[1]) {
				fin = true;
			}
			cout << "\nel numero de movimientos fue: " << tab.jug[i].mov;
		} while (fin == false);
	}
	int menor = tab.jug[0].mov;
	int pos_g = 0;
	for (int i = 0; i < tab.numj; i++) {
		if (tab.jug[i].mov < menor) {
			menor = tab.jug[i].mov;
			pos_g = i;
		}
	}
	cout << "Nombre Ganador: " << tab.jug[pos_g].nombre;
	cout << "\nmovimientos: " << menor;
}

int main()
{
	cout << "asdfasdfasdf";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
