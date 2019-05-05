// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Jugador
{
	int codPlayer;
	string nomPlayer;
	float time;
	int asnwerPlayer[4][4];
};

int menu() {
	int opc = 0;
	system("cls");
	cout << "------------MENU------------" << endl;
	cout << "1.Nombre Jugador\n2.Cuadro jugador\n3.evaluacion del cuadro\n4.resultados\n5.similitud\n0.salir\n";
	cin >> opc;
	return opc;
}

void add_player(Jugador player[], int N) {
	string nom;
	float time;
	int valor;
	for (int i = 0; i < N; i++) {
		cout << "ingrese nombre del jugador:" << endl;
		cin >> nom;
		player[i].nomPlayer = nom;
		player[i].codPlayer = i;
		cout << "ingrese tiempo del jugador: " << endl;
		cin >> time;
		player[i].time = time;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cout << "ingrese el valor de la fila " << j << " y columna" << k << " : " << endl;
				cin >> valor;
				player[i].asnwerPlayer[j][k] = valor;
			}
		}
	}
}

int codigojugador(Jugador player[], string nomPlayer, int N) {
	for (int i = 0; i < N; i++) {
		if (player[i].nomPlayer == nomPlayer) {
			return player[i].codPlayer;
		}
	}
}
int evaluarfil(int codPlayer, int fil, Jugador player[], int N) {
	int resFila = 0;
	for (int i = 0; i < 4; i++) {
		resFila = resFila + player[codPlayer].asnwerPlayer[fil - 1][i];
	}
	return resFila;
}
int evaluarco(int codPlayer, int col, Jugador player[], int N) {
	int resColum = 0;
	for (int i = 0; i < 4; i++) {
		resColum = resColum + player[codPlayer].asnwerPlayer[i][col - 1];
	}
	return resColum;
}
int evaluardia(int codPlayer, int dia, Jugador player[], int N) {
	int resDiag = 0;
	if (dia == 1) {//DIAGONAL HACIA ABAJO
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resDiag = resDiag + player[codPlayer].asnwerPlayer[i][j];
			}
		}
	}
	else {//DIAGONAL HACIA ARRIBA
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				resDiag = resDiag + player[codPlayer].asnwerPlayer[i][j];
			}
		}
	}
	return resDiag;
}
int main()
{
	int opc = 0;
	int n;
	cout << "ingrese numero de jugadores:\n";
	cin >> n;
	Jugador player[2];
	add_player(player, n);
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
	} while (opc != 0);
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
