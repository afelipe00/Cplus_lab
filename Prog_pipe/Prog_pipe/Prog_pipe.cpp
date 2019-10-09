// Prog_pipe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int salto_correcto(int vect[], int tam) {
	int indice = 0;
	int pasos = 0;
	bool band = true;
	int temp[] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < tam; i++) {
		temp[i] = vect[i];
	}
	do {
		if (temp[indice] != 0) {
			if (indice + temp[indice] <= tam) {
				pasos = pasos + temp[indice];
				indice = indice + temp[indice];
				temp[indice - temp[indice]] = 0;
			}
			else
			{
				if(indice < tam) {
					int tempi = indice;
					pasos = pasos + temp[indice];
					indice = (temp[indice]-(tam+indice))+2;
					temp[tempi] = 0;
				}
				else  if (indice = tam) {
					int tempi = indice;
					pasos = pasos + temp[indice];
					indice = (temp[indice] - (tam + indice)) + 1;
					temp[tempi] = 0;
				}
			}
		}
		else
		{
			band = false;
			break;
		}
	} while (indice != 0);
	if (band == true) {
		return pasos;
	}
	else
	{
		return -1;
	}
}

void ganadora(int vec1[], int tam1, int vec2[], int tam2) {
	int saltos1 = salto_correcto(vec1, tam1);
	int saltos2 = salto_correcto(vec2, tam2);
	if (saltos1 == -1) {
		cout << "la ranita 1 tiene salto incorrectos" << endl;
	}
	if (saltos2 == -1) {
		cout << "la ranita 2 tiene salto incorrectos" << endl;
	}
	if (saltos1 > saltos2) {
		cout << "Gano la ranita 1" << endl;
	}
	else if (saltos2 > saltos1) {
		cout << "Gano la ranita 2" << endl;
	}
	else {
		cout << "empate" << endl;
	}
}

int main(void) {
	int vect[] = { 3,6,2,8,1 };
	int tam = 5;
	int resp = salto_correcto(vect, tam);
}