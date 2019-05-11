// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include"pch.h"
//librerias de c++
#include<iostream>
#include <string>
#include <stdlib.h>
#include<iomanip>

//palabras reservadas de c++ (standart)
using namespace std;

//CUANTO TIENE QUE DAR EL CUADRADO MAGICO
#define numberCuadrado 34
#define cuadrado 4
//estructura del jugador
struct Jugador {
	int codPlayer;
	string nomPlayer;
	float time;
	int asnwerPlayer[4][4];
};
//declarado de funciones
int menu();
void add_player(Jugador player[], int N);
int codigojugador(Jugador player[], string nomPlayer, int N);
int evaluarfil(int codPlayer, int fil, Jugador[], int N);
int evaluarco(int codPlayer, int col, Jugador[], int N);
int evaluardia(int codPlayer, int dia, Jugador[], int N);
void preJugadores(Jugador player[], int N);
void preRespuestas(Jugador player[], int N);
void preEvaluacion(Jugador player[], int N, int nCuadrado);
void ordenarResultados(Jugador player[], int N, int nCuadrado);
void imp_matriz(Jugador player[], int N, int i);
void solucion_igual(Jugador player[], int N);
//funcion main o principal
int main() {
	int opc = 0;
	const int n = 4;
	Jugador player[n] = { {1,"Carmen",3.1,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{100,"Maria",3.3,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{150,"Ruth",3.2,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{200,"Claudia",3.5,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}} };
	do {
		opc = menu();
		switch (opc) {
		case 1:
			system("cls");
			preJugadores(player, n);
			system("pause");
			break;
		case 2:
			system("cls");
			preRespuestas(player, n);
			system("pause");
			break;
		case 3:
			system("cls");
			preEvaluacion(player, n, numberCuadrado);
			system("pause");
			break;
		case 4:
			system("cls");
			ordenarResultados(player, n, numberCuadrado);
			system("pause");
			break;
		case 5:
			system("cls");
			solucion_igual(player, n);
			system("pause");
			break;
		case 0:
			system("cls");
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
//funcion que despliega el menu de opciones
int menu() {
	int opc = 0;
	system("cls");
	cout << "------------MENU------------" << endl;
	cout << "1.Presentar Jugadores \n2.Presentar Cuadro de jugador\n3.Evaluacion del cuadro\n4.resultados\n5.similitud\n0.salir\n";
	cin >> opc;
	return opc;
}
//funcion para agregar los jugadores por teclado
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
//funcion para obetener el codigo del jugador
int codigojugador(Jugador player[], string nomPlayer, int N) {
	for (int i = 0; i < N; i++) {
		if (player[i].nomPlayer == nomPlayer) {
			return i;
		}
	}
}
//funcion para evaluar fila
int evaluarfil(int codPlayer, int fil, Jugador player[], int N) {
	int resFila = 0;
	for (int i = 0; i < N; i++) {
		resFila = resFila + player[codPlayer].asnwerPlayer[fil][i];
	}
	return resFila;
}
//funcion para evaluar columna
int evaluarco(int codPlayer, int col, Jugador player[], int N) {
	int resColum = 0;
	for (int i = 0; i < N; i++) {
		resColum = resColum + player[codPlayer].asnwerPlayer[i][col];
	}
	return resColum;
}
//funcion para evaluar diagonal
int evaluardia(int codPlayer, int dia, Jugador player[], int N) {
	int resDiag = 0;
	if (dia == 1) {//DIAGONAL HACIA ABAJO
		for (int i = 0; i < N; i++) {
			resDiag = resDiag + player[codPlayer].asnwerPlayer[i][i];
		}
	}
	else {//DIAGONAL HACIA ARRIBA
		for (int i = 0; i < N; i++) {
			resDiag = resDiag + player[codPlayer].asnwerPlayer[N - 1 - i][i];
		}
	}
	return resDiag;
}
//primera opcion
void preJugadores(Jugador player[], int N) {//PRIMER PUNTO
	for (int i = 0; i < N; i++) {
		cout << "Codigo: " << player[i].codPlayer << ", Nombre: " << player[i].nomPlayer << ", Tiempo: " << player[i].time << "\n";
	}
}
//segunda opcion
void preRespuestas(Jugador player[], int N) {//SEGUNDO PUNTO
	int posPlayer = 0; string nomPlayer;
	cout << "Digite el nombre del jugador del cual desea su respuesta: ";
	cin >> nomPlayer;
	posPlayer = codigojugador(player, nomPlayer, N);
	imp_matriz(player, N, posPlayer);
}
//tercera opcion
void preEvaluacion(Jugador player[], int N, int nCuadrado) {//TERCER PUNTO
	int posPlayer = 0; string nomPlayer;
	cout << "Digite el nombre del jugador del cual desea su respuesta: ";
	cin >> nomPlayer;
	posPlayer = codigojugador(player, nomPlayer, N);
	int res[3] = { 0,0,0 };
	for (int i = 0; i < N; i++) {
		if (evaluarfil(posPlayer, i, player, N) != nCuadrado) {
			res[0] = 1;//FILA NO SUMA 34
		}
		if (evaluarco(posPlayer, i, player, N) != nCuadrado) {
			res[1] = 2;//COLUMNA NO SUMA 34
		}
		if (i <= 1) {
			if (evaluardia(posPlayer, i, player, N) != nCuadrado) {
				res[2] = 3;//COLUMNA NO SUMA 34
			}
		}
	}
	if (res[0] == 0 && res[1] == 0 && res[2] == 0) {
		cout << "La respuesta es correcta: " << res[0] << "\n";
	}
	else if (res[0] == 1) {
		cout << "No es cuadro magico alguna fila no suma lo mismo: " << res[0] << "\n";
	}
	else if (res[1] == 2) {
		cout << "No es cuadro magico alguna columna no suma lo mismo: " << res[1] << "\n";
	}
	else if (res[2] == 3) {
		cout << "No es cuadro magico alguna diagonal no suma lo mismo: " << res[2] << "\n";
	}
}
//cuarta opcion
void ordenarResultados(Jugador player[], int N, int nCuadrado) {//CUARTO PUNTO
	float res[cuadrado][2], auxtime, auxpos;
	int resCorrecta[cuadrado], comp = 0;
	for (int i = 0; i < N; i++) {
		res[i][0] = player[i].time; //TIEMPO DE LOS JUGADORES
		res[i][1] = i; //POSICION ARREGLO
	}
	for (int i = 0; i < N; i++) {//ORGANIZAR EL VECTOR POR TIEMPO
		for (int j = 0; j < N; j++) {
			if (res[i][0] < res[j][0]) {
				auxtime = res[i][0];
				auxpos = res[i][1];
				res[i][0] = res[j][0];//TIEMPO
				res[i][1] = res[j][1];//POSICION
				res[j][0] = auxtime;
				res[j][1] = auxpos;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		resCorrecta[i] = 0;
		for (int j = 0; j < N; j++) {
			if (resCorrecta[i] == 0) {
				if (evaluarfil(i, j, player, N) != nCuadrado) {
					resCorrecta[i] = 1;
				}
				if (evaluarco(i, j, player, N) != nCuadrado) {
					resCorrecta[i] = 2;
				}
				if (i <= 1) {
					if (evaluardia(i, j, player, N) != nCuadrado) {
						resCorrecta[i] = 3;
					}
				}
				comp += resCorrecta[i];
			}
		}

	}
	if (comp == 0) {
		cout << "Jugadores con respuesta correcta, organizados por tiempo: \n";
		for (int i = 0; i < N; i++) {
			cout << i << ". Codigo: " << player[int(res[i][1])].codPlayer << ", Nombre: " << player[int(res[i][1])].nomPlayer << ", Tiempo: " << player[int(res[i][1])].time << "\n";
		}
	}
	else {
		cout << "Jugadores con respuesta correcta, organizados por tiempo: \n";
		for (int i = 0; i < N; i++) {
			if (resCorrecta[i] == 0) {
				for (int j = 0; j < N; j++) {
					if (i == res[j][1]) {
						cout << i << ". Codigo: " << player[int(res[i][1])].codPlayer << ", Nombre: " << player[int(res[i][1])].nomPlayer << ", Tiempo: " << player[int(res[i][1])].time << "\n";
					}
				}
			}
		}
		cout << "Jugadores con respuesta Incorrecta, organizados por tiempo: \n";
		for (int i = 0; i < N; i++) {
			if (resCorrecta[i] != 0) {
				for (int j = 0; j < N; j++) {
					if (i == res[j][1]) {
						cout << i << ". Codigo: " << player[int(res[i][1])].codPlayer << ", Nombre: " << player[int(res[i][1])].nomPlayer << ", Tiempo: " << player[int(res[i][1])].time << "\n";
					}
				}
			}
		}
	}
}
//quinta opcion
void solucion_igual(Jugador player[], int N) {
	int cont = 0, contj=0;
	for (int i = 0; i < N ; i++) {
		for (int j = i+1; j < N;j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (player[i].asnwerPlayer[k][l] == player[j].asnwerPlayer[k][l]) {
						cont++;
					}
				}
			}
			if (cont == 16) {
				if (contj == 0) {
					cout << "los siguientes jugadores tuvieron el mismo cuadro:\n";
					cout << "nombre del jugador: " << player[i].nomPlayer << endl;
					cout << "tiempo del jugador: " << player[i].time << endl;
					contj++;
				}
				cout << "nombre del jugador: " << player[j].nomPlayer << endl;
				cout << "tiempo del jugador: " << player[j].time << endl;
				
			}
			cont = 0;
			
		}
		if (contj>0) {
			cout << "solucion : " << endl;
			imp_matriz(player, N, i);
		}
		contj = 0;
	}
}
//funcion para imprimir matriz
void imp_matriz(Jugador player[], int N, int i) {
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			cout << setw(4) << player[i].asnwerPlayer[j][k];
		}
		cout << endl;
	}
}