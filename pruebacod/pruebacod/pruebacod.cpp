// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>

using namespace std;

void vacio(int mat[][7], int fil, int colum, string alma[], string prod[], int res[],int tam, string nom) {
	int i= 0;
	int pos = 0;
	for (i = 0; i < fil; i++) {
		if (nom == prod[i]) {
			pos = i;
			break;
		}
	}
	for (i = 0; i < colum; i++) {
		int cont = 0;
		if (mat[pos][i] == 0) {
			res[cont] = mat[pos][i];
		}
		cont++;
	}
}

int main()
{
	cout << cout << "almacenes sin productos: ";
	for (int i = 0; i < tam; i++) {
		 cout<<res[i]<<", ";
	}
	system("pause");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
