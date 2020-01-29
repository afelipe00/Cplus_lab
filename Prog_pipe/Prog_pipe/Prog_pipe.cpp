// Prog_pipe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "pch.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;


struct pelicula
{

};
struct boleta
{
	pelicula peli;
	unsigned char ubicacion[2];
	unsigned char sala;
	unsigned char fecha;

	unsigned int  precio;
};
int main(void) {
	boleta a;
	boleta* a;

}