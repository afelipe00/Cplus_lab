// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include"pch.h"
#include <iostream>
#include <string>
#include<stdlib.h>

using namespace std;
//estructura del jugador
struct Jugador {
	int codPlayer;
	string nomPlayer;
	float time;
	int asnwerPlayer[4][4];
	const int Tcuadro = 4;
};
//funcion del menu principal
int menu() {
	int opc = 0;
	system("cls");
	cout << "------------MENU------------" << endl;
	cout << "1.Nombre Jugador\n2.Cuadro jugador\n3.evaluacion del cuadro\n4.resultados\n5.similitud\n0.salir\n";
	cin >> opc;
	return opc;
}
//funcion para agregar jugadores
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
//funcion para obtener el codigo de un jugador
int codigojugador(Jugador player[], string nomPlayer, int N) {
	for (int i = 0; i < N; i++) {
		if (player[i].nomPlayer == nomPlayer) {
			return player[i].codPlayer;
		}
	}
}
//funcion para obtener la suma de la fila
int evaluarfil(int codPlayer, int fil, Jugador player[], int N) {
	int resFila = 0;
	for (int i = 0; i < 4; i++) {
		resFila = resFila + player[codPlayer].asnwerPlayer[fil - 1][i];
	}
	return resFila;
}
//funcion para obtener la suma de la columna
int evaluarco(int codPlayer, int col, Jugador player[], int N) {
	int resColum = 0;
	for (int i = 0; i < 4; i++) {
		resColum = resColum + player[codPlayer].asnwerPlayer[i][col - 1];
	}
	return resColum;
}
//funcion para obtener la suma de la diagonal
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
void opc_1(Jugador player[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Codigo del jugador: " << player[i].codPlayer << endl;
		cout << "Nombre del jugador: " << player[i].nomPlayer << endl;
		cout << "tiempo del jugador: " << player[i].time << endl;
		cout << "\n--------------------------------------------------\n";
	}
}
//menu principal
int main() {
	int opc = 0;
	const int n = 4;
	Jugador player[n] = { {1,"Carmen",3.1,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
					   {100,"Maria",3.3,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
					   {150,"Ruth",3.2,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
					   {200,"Claudia",3.5,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}} };
	do {
		opc = menu();
		switch (opc)
		{
		case 1:
			system("cls");
			opc_1(player, n);
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
		case 6:
			system("cls");
			add_player(player, n);
			system("pause");
			break;
		case 0:
			cout << "FINALIZADO" << endl;
			break;
		default:
			system("cls");
			cout << "opcion no valida\n";
			system("pause");
			break;
		}
	} while (opc != 0);
	system("pause");
}