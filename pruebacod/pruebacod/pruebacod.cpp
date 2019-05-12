// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
	//intero para las opciones
	int opc = 0;
	//constante del tamaño de la estructura y el cuadromagico
	const int n = 4;
	//variable de tipo estructura(jugador)
	Jugador player[n] = { {1,"Carmen",3.1,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{100,"Maria",3.3,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{150,"Ruth",3.2,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}},
						{200,"Claudia",3.5,{{1,15,14,4},{12,6,7,9},{8,10,11,5},{13,3,2,16}}} };
	//ciclo do para ver las opciones que se pueden tomar
	do {
		//llamado de la funcion que retorna la opcion
		opc = menu();
		//switch para seleccionar la opcion
		switch (opc) {
		//casos y llamado de las funciones que hacen las opciones
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
	} while (opc != 0);//while diferente de 0 (para salir del do)
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
	//ciclo para recorrer vector player
	for (int i = 0; i < N; i++) {
		cout << "ingrese nombre del jugador:" << endl;
		cin >> nom;
		player[i].nomPlayer = nom;
		player[i].codPlayer = i;
		cout << "ingrese tiempo del jugador: " << endl;
		cin >> time;
		player[i].time = time;
		//ciclo para recorrer matriz (filas)
		for (int j = 0; j < 4; j++) {
			//ciclo para recorrer matriz (columnas)
			for (int k = 0; k < 4; k++) {
				cout << "ingrese el valor de la fila " << j << " y columna" << k << " : " << endl;
				cin >> valor;
				//se almacena en la posicion de la matriz recorrida
				player[i].asnwerPlayer[j][k] = valor;
			}
		}
	}
}
//funcion para obetener el codigo del jugador
int codigojugador(Jugador player[], string nomPlayer, int N) {
	//ciclo para recorrer vector jugador
	for (int i = 0; i < N; i++) {
		//condicion para comparar texto recibido con el de los jugadores
		if (player[i].nomPlayer == nomPlayer) {
			return i;
		}
	}
}
//funcion para evaluar fila
//se reciben codigo del jugador y # de fila asi solo se recorre las columnas para sumar
int evaluarfil(int codPlayer, int fil, Jugador player[], int N) {
	int resFila = 0;
	//codigo para recorrer matriz (posiciones de columna)
	for (int i = 0; i < N; i++) {
		resFila = resFila + player[codPlayer].asnwerPlayer[fil][i];
	}
	return resFila;
}
//funcion para evaluar columna
//se reciben codigo del jugador y # de columna asi solo se recorre las filas para sumar
int evaluarco(int codPlayer, int col, Jugador player[], int N) {
	int resColum = 0;
	//ciclo para recorrer matiz (filas)
	for (int i = 0; i < N; i++) {
		resColum = resColum + player[codPlayer].asnwerPlayer[i][col];
	}
	return resColum;
}
//funcion para evaluar diagonal
int evaluardia(int codPlayer, int dia, Jugador player[], int N) {
	int resDiag = 0;
	//condicion para evaluar que tipo de columna es
	if (dia == 1) {//DIAGONAL HACIA ABAJO
		//ciclo para recorrer diagona hacia abajo
		for (int i = 0; i < N; i++) {
			resDiag = resDiag + player[codPlayer].asnwerPlayer[i][i];
		}
	}
	else {//DIAGONAL HACIA ARRIBA
		//ciclo para recorrer diagonal hacia arriba
		for (int i = 0; i < N; i++) {
			resDiag = resDiag + player[codPlayer].asnwerPlayer[N - 1 - i][i];
		}
	}
	return resDiag;
}
//primera opcion
void preJugadores(Jugador player[], int N) {//PRIMER PUNTO
	//ciclo para recorrer vector jugadores e imprimir sus datos sin matriz
	for (int i = 0; i < N; i++) {
		cout << "Codigo: " << player[i].codPlayer << ", Nombre: " << player[i].nomPlayer << ", Tiempo: " << player[i].time << "\n";
	}
}
//segunda opcion
void preRespuestas(Jugador player[], int N) {//SEGUNDO PUNTO
	int posPlayer = 0; string nomPlayer;
	//se solicita el nom del jugador
	cout << "Digite el nombre del jugador del cual desea su respuesta: ";
	cin >> nomPlayer;
	//se recibe la posicion del jugador para imprimir su solucion
	posPlayer = codigojugador(player, nomPlayer, N); //se llama funcion cod jugador
	//se llama funcion para imprimir matriz
	imp_matriz(player, N, posPlayer);
}
//tercera opcion
void preEvaluacion(Jugador player[], int N, int nCuadrado) {//TERCER PUNTO
	int posPlayer = 0; string nomPlayer;
	//se solicita el nom del jugador
	cout << "Digite el nombre del jugador del cual desea su respuesta: ";
	cin >> nomPlayer;
	//se recibe la posicion del jugador para imprimir su solucion
	posPlayer = codigojugador(player, nomPlayer, N);
	//vector de respuestas en fila, columna y diagonal
	int res[3] = { 0,0,0 };
	//for para recorrer la sumas en el cuadro
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
	//condicion de las posibles opciones de error(0,1,3)
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
	//declaracion de variables temporales
	float res[cuadrado][2], auxtime, auxpos;
	int resCorrecta[cuadrado], comp = 0;
	//for para recorrer vector jugadores y tomar las posiciones de ellos
	for (int i = 0; i < N; i++) {
		res[i][0] = player[i].time; //TIEMPO DE LOS JUGADORES
		res[i][1] = i; //POSICION ARREGLO
	}
	//for para organizar los jugadores por tiempo
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
	//for para evaluar soluciones correctas
	//se define una constante establecida para la solucion del cuadro magico (ncuadrado)
	//si se cambia a otro cuadrado magico se tiene que cambiar esta constante
	for (int i = 0; i < N; i++) {
		resCorrecta[i] = 0;
		for (int j = 0; j < N; j++) {
			if (resCorrecta[i] == 0) {
				if (evaluarfil(i, j, player, N) != nCuadrado) {//error en la fila
					resCorrecta[i] = 1;
				}
				if (evaluarco(i, j, player, N) != nCuadrado) {//error en la columna
					resCorrecta[i] = 2;
				}
				if (i <= 1) {
					if (evaluardia(i, j, player, N) != nCuadrado) {//error en la diagonal
						resCorrecta[i] = 3;
					}
				}
				comp += resCorrecta[i];
			}
		}

	}
	//condiciones para ordenar jugadores segun su tiempo y si su colucion es correcta o tiene errores
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
	//for para recorrer vector jugadores
	for (int i = 0; i < N ; i++) {
		//for para recorrer jugadores (se utilizan dos for para poder compraar posiciones y saber cuales son iguales)
		for (int j = i+1; j < N;j++) {
			//for para recorrer matriz(fila)
			for (int k = 0; k < N; k++) {
				//for para recorrer matriz(columna)
				for (int l = 0; l < N; l++) {
					//se compara si los numeros son iguales
					if (player[i].asnwerPlayer[k][l] == player[j].asnwerPlayer[k][l]) {
						cont++;
					}
				}
			}
			//condicion que verifica que toda la matriz es igual
			if (cont == 16) {
				//se verifica si es la primera verificacion (esto se hace para no duplicar el primer jugador)
				if (contj == 0) {
					cout << "los siguientes jugadores tuvieron el mismo cuadro:\n";
					cout << "nombre del jugador: " << player[i].nomPlayer << endl;
					cout << "tiempo del jugador: " << player[i].time << endl;
					contj++;
				}
				//se imprimer los jugadores con soluciones iguales
				cout << "nombre del jugador: " << player[j].nomPlayer << endl;
				cout << "tiempo del jugador: " << player[j].time << endl;
				
			}
			cont = 0;
			
		}
		//condicion para ver que se termino de imprimir los jugadores
		if (contj>0) {
			//se imprimer solucion en comun
			cout << "solucion : " << endl;
			imp_matriz(player, N, i);
		}
		contj = 0;
	}
}
//funcion para imprimir matriz
void imp_matriz(Jugador player[], int N, int i) {
	//for para recorrer matriz
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			//setw se utiliza como un tap para que la matriz no se corra segun los numeros si no que permanesca alineada
			cout << setw(4) << player[i].asnwerPlayer[j][k];
		}
		cout << endl;
	}
}