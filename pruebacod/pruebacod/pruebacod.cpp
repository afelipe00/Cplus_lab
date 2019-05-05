// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>

using namespace std;

int menu() {
	int opc = 0;
	system("cls");
	cout << "------------MENU------------" << endl;
	cout << "1.Nombre Jugador\n2.Cuadro jugador\n3.evaluacion del cuadro\n4.resultados\n5.similitud\n0.salir\n";
	cin >> opc;
	return opc;
}

int main()
{
	int opc = 0;
	do {
		opc = menu();
		switch (opc)
		{
			case 1:
				system("cls");
				cout << "opcion 1\n";
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "opcion 2\n";
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "opcion 3\n";
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "opcion 4\n";
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "opcion 5\n";
				system("pause");
				break;
			case 0:
				cout << "FINALIZADO" << endl;
			default:
				system("cls");
				cout << "opcion no valida\n";
				system("pause");
				break;
		}
	} while (opc !=0);
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
