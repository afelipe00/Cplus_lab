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

//estructur que almacena los datos de las coordenadas
struct coordenada {
	int pos[2];//vector 2 posiciones (valor en x, valor en y)
	int lim = 2;//tamano del vector
};
//estructura que almacena los datos del poligono
struct Poligono {
	int resolucion = 0;// almacena el dato de la resolucion que equivale al numero de lados del poligono
	coordenada vertices[10000];//vector que almacena los vertices, este verctor es de tipo coordenada para almacenar los datos X y Y
	string color;// string que alamacena el color del poligono
	int perimetro = 0;// int que almacena el perimetro
};

void perimetro(Poligono pol) {
	int y = 0, int x = 0; int res = 0;
	for (int i = 0; i < pol.resolucion - 1; i++) {//ciclo que recorre los puntos del poligono, lo cual es equivalente a la resolucion
		if (pol.vertices[i].pos[0] == pol.vertices[i + 1].pos[0]) {//condicion que verifica si los puntos estan sobre el mismo eje x
			res = (pol.vertices[i + 1].pos[1] - pol.vertices[i].pos[1]);//se restan los valores para conocer la distancia entre ellos
			if (res < 0) {//condicion para verificar si el resultado es menor a cero y asi pasarlo a positivo
				res = res * (-1);
			}
			y = y + res; res = 0;// sumador con las respuestas en y
		}
		if (pol.vertices[i].pos[1] == pol.vertices[i + 1].pos[1]) {//condicion que verifica si los los ejes Y son iguales
			res = (pol.vertices[i + 1].pos[0] - pol.vertices[i].pos[0]);//se restan la diferenci entre los ejes x
			if (res < 0) {//condicion que verifica que el resultado sea negativo y asi convertirlo a positivo
				res = res * (-1);
			}
			x = x + res; res = 0;//sumador de respuestas en Y
		}
	}
	pol.perimetro = x + y;//se suman y alamacenan los resultados en X y Y para obetener el perimetro
}

void conjunto(Poligono pol[], int tam) {
	Poligono temp;//temporal de tipo poligono (estructura)
	int menor, mayor;
	//metodo burbuja para ordenar los poligonos
	for (int i = 0; i < tam; i++) {//ciclo que recorre numero de poligonos
		for (int j = 0; j < tam - 1; j++) {//ciclo que recorre numero de poligonos
			if (pol[j].resolucion < pol[j + 1].resolucion) {//condicion que ordena de mayor a menor
				temp = pol[j];
				pol[j] = pol[j + 1];
				pol[j + 1] = temp;
			}
		}
	}
	cout << "poligonos con mayor resolucion: " << endl;
	//mayor almacena el primer valor
	mayor = pol[0].resolucion;
	for (int i = 0; i < tam; i++) {//se recorren los poligonos
		if (pol[i].resolucion >= mayor) {//se verifica si el poligono en las pos i es igual o mayor a la recolucion de mayor
			cout << "poligono " << i << " " << "resolucion: " << pol[i].resolucion << endl;//si lo es se imprime el poligono
			mayor = pol[i].resolucion;//se iguala mayor a este poligono
		}
	}
	cout << "poligonos con menor perimetro: " << endl;
	//menor almacena el primer valor
	menor = pol[0].perimetro;
	for (int i = 0; i < tam; i++) {//ciclo que recorre los poligonos
		if (pol[i].perimetro <= menor) {//condicion que verifica los poligonos con menor o igual resolucion
			cout << "poligono " << i << " " << "perimetro: " << pol[i].perimetro << endl;//se imprimen los poligonos con esa resolucion
			menor = pol[i].perimetro;//se iguala menor a este poligono en la pos i
		}
	}

}

int main(void) {


}
