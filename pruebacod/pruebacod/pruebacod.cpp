// pruebacod.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include"pch.h"
//librerias de c++
//libreria para windows
#include<iostream>
//libreria que maneja propiedades del string
#include <string>
//libreria estandar c
#include <stdlib.h>
//libreria pra utilizar el setw
#include<iomanip>

using namespace std;

struct coordenada {
	int pos[2];
	int lim = 2;
};

struct Poligono {
	int resolucion = 0;
	coordenada vertices[10000];
	string color;
	int perimetro = 0;
};

void perimetro(Poligono pol) {
	int y = 0, int x = 0; int res = 0;
	for (int i = 0; i < pol.resolucion - 1; i++) {
		if (pol.vertices[i].pos[0] == pol.vertices[i + 1].pos[0]) {
			res = (pol.vertices[i + 1].pos[1] - pol.vertices[i].pos[1]);
			if (res < 0) {
				res = res * (-1);
			}
			y = y + res; res = 0;
		}
		if (pol.vertices[i].pos[1] == pol.vertices[i + 1].pos[1]) {
			res = (pol.vertices[i + 1].pos[0] - pol.vertices[i].pos[0]);
			if (res < 0) {
				res = res * (-1);
			}
			x = x + res; res = 0;
		}
	}
	pol.perimetro = x + y;
}

void conjunto(Poligono pol[], int tam) {
	Poligono temp;
	int menor, mayor;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam - 1; j++) {
			if (pol[j].resolucion < pol[j + 1].resolucion) {
				temp = pol[j];
				pol[j] = pol[j + 1];
				pol[j + 1] = temp;
			}
		}
	}
	cout << "poligonos con mayor resolucion: " << endl;
	mayor = pol[0].resolucion;
	for (int i = 0; i < tam; i++) {
		if (pol[i].resolucion >= mayor) {
			cout << "poligono " << i << " " << "resolucion: " << pol[i].resolucion << endl;
			mayor = pol[i].resolucion;
		}
	}
	cout << "poligonos con menor perimetro: " << endl;
	menor = pol[0].perimetro;
	for (int i = 0; i < tam; i++) {
		if (pol[i].perimetro <= menor) {
			cout << "poligono " << i << " " << "perimetro: " << pol[i].perimetro << endl;
			menor = pol[i].perimetro;
		}
	}

}

int main(void) {


}
