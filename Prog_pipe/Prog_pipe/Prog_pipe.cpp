// Prog_pipe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
//ESTRUCTURAS PARA EL ALMACENAMIENTO DE LA INFORMACION
struct Carta
{
	string color;
	string forma;
	string relleno;
	int num;
};
struct Jugador
{
	string nombre;
	int num_cartas = 0;
	Carta cartas[10];
	char yo;

};
struct Mazo
{
	Carta cartas[20] = {{"rojo","PRIMERO","vacio",3},{"rojo","circulo","vacio",3},{"rojo","cuadrado","vacio",3},
						{"rojo","triangulo","vacio",3} ,{"rojo","circulo","vacio",3} ,{"rojo","triangulo","vacio",3},
						{"rojo","prueba","vacio",3} ,{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3},
						{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3},
						{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3},
						{"rojo","triangulo","vacio",3} ,{"rojo","triangulo","vacio",3} ,{"rojo","circulo","vacio",3},
						{"rojo","cuadrado","vacio",3} ,{"rojo","ULTIMO","vacio",3} };
	int n_cartas = 20;
};

struct Game {
	Mazo mazo;
	Carta tablero[3][5] = { {{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 }},
							{{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 }},
							{{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 },{ "0","0","0",0 }} };
	int filas = 3, columnas = 5, expand = 0;
	Jugador players[2];
	int tam_players = 2;
	Jugador winner;
	bool set = true;
};

//FUNCIONES PROCESOS LOGICOS DEL CODIGO

//funcion que imprime en forma de matriz las cartas
//si expand es 0, columnas = 4, si expand es 1, columnas = 5;

void imprimir_tablero(Game start) {
	if (start.expand == 0) {
		for (int j = 0; j < start.filas; j++) {
			cout << "------------------------------------------------------------------------------------"<<endl;
			cout << setw(10) << start.tablero[j][0].forma<< setw(10) << "|" << setw(10)<< start.tablero[j][1].forma << setw(10) << "|" << setw(10) << start.tablero[j][2].forma << setw(10) << "|" << setw(10) << start.tablero[j][3].forma<<endl;
			cout << setw(10) << start.tablero[j][0].color << setw(10) << "|" << setw(10) << start.tablero[j][1].color << setw(10) << "|" << setw(10) << start.tablero[j][2].color << setw(10) << "|" << setw(10) << start.tablero[j][3].color << endl;
			cout << setw(10) << start.tablero[j][0].relleno << setw(10) << "|" << setw(10) << start.tablero[j][1].relleno << setw(10) << "|" << setw(10) << start.tablero[j][2].relleno << setw(10) << "|" << setw(10) << start.tablero[j][3].relleno << endl;
			cout << setw(10) << start.tablero[j][0].num << setw(10) << "|" << setw(10) << start.tablero[j][1].num << setw(10) << "|" << setw(10) << start.tablero[j][2].num << setw(10) << "|" << setw(10) << start.tablero[j][3].num << endl;
		}
	}
	else
	{
		for (int j = 0; j < start.filas; j++) {
			cout << "--------------------------------------------------------------------------------------------" << endl;
			cout << setw(10) << start.tablero[j][0].forma << setw(10) << "|" << setw(10) << start.tablero[j][1].forma << setw(10) << "|" << setw(10) << start.tablero[j][2].forma << setw(10) << "|" << setw(10) << start.tablero[j][3].forma << setw(10) << "|" << setw(10) << start.tablero[j][4].forma << endl;
			cout << setw(10) << start.tablero[j][0].color << setw(10) << "|" << setw(10) << start.tablero[j][1].color << setw(10) << "|" << setw(10) << start.tablero[j][2].color << setw(10) << "|" << setw(10) << start.tablero[j][3].color << setw(10) << "|" << setw(10) << start.tablero[j][4].color << endl;
			cout << setw(10) << start.tablero[j][0].relleno << setw(10) << "|" << setw(10) << start.tablero[j][1].relleno << setw(10) << "|" << setw(10) << start.tablero[j][2].relleno << setw(10) << "|" << setw(10) << start.tablero[j][3].relleno << setw(10) << "|" << setw(10) << start.tablero[j][4].relleno << endl;
			cout << setw(10) << start.tablero[j][0].num << setw(10) << "|" << setw(10) << start.tablero[j][1].num << setw(10) << "|" << setw(10) << start.tablero[j][2].num << setw(10) << "|" << setw(10) << start.tablero[j][3].num << setw(10) << "|" << setw(10) << start.tablero[j][4].num << endl;
		}
	}
}

//funcion que quita las cartas del mazo y las pone en la matriz tablero (de forma inicial)
Game llenar_tablero(Game start) {
	if (start.expand == 0) {
		for (int j = 0; j < start.filas; j++) {
			for (int k = 0; k < start.columnas - 1; k++) {
				start.tablero[j][k] = start.mazo.cartas[start.mazo.n_cartas - 1];
				start.mazo.cartas[start.mazo.n_cartas - 1] = { "0","0","0",0 };
				start.mazo.n_cartas = start.mazo.n_cartas - 1;
			}
		}
		imprimir_tablero(start);
	}
	else {
		for (int j = 0; j < start.filas; j++) {
			for (int k = 0; k < start.columnas ; k++) {
				start.tablero[j][k] = start.mazo.cartas[start.mazo.n_cartas - 1];
				start.mazo.cartas[start.mazo.n_cartas - 1] = { "0","0","0",0 };
				start.mazo.n_cartas = start.mazo.n_cartas - 1;
			}
		}
		imprimir_tablero(start);
	}
	return start;
}


Game inscribir(Game start) {
	for (int i = 0; i < start.tam_players; i++) {
		cout << "Registre su nombre "<< "(jugador "<< i+1 <<" ): ";
		cin >> start.players[i].nombre;
		cout << "Su ID va a ser: " << " " << i + 1 << endl;

	}
	system("pause");
	system("cls");
	cout << "Jugadores inscritos: " << endl;
	for (int i = 0; i < start.tam_players; i++) {
		cout << setw(9) << "Jugador " << i + 1 << " ";
		cout << "Nombre: " << start.players[i].nombre<<setw(12);
		cout << "ID : " << i+1 << endl;
	}
	return start;
}

void ganador(Game start) {
	if (start.players[0].num_cartas > start.players[1].num_cartas) {
		cout << "el ganador es el jugador " << start.players[0].nombre << " !!!" << endl;
	}
	else
	{
		cout << "el ganador es el jugador " << start.players[1].nombre << " !!!" << endl;

	}
}

Game ran_mazo(Game start) {
	srand(time(NULL));
	int limit = 20;
	int num = rand() % limit;
	num -= 1;
	Carta temp = start.mazo.cartas[start.mazo.n_cartas - 1];
	start.mazo.cartas[start.mazo.n_cartas - 1] = start.mazo.cartas[num];
	start.mazo.cartas[num] = temp;
	int num2 = rand() % limit;
	num2 -= 2;
	Carta temp2 = start.mazo.cartas[start.mazo.n_cartas - 2];
	start.mazo.cartas[start.mazo.n_cartas - 2] = start.mazo.cartas[num2];
	start.mazo.cartas[num2] = temp2;
	int num3 = rand() % limit;
	num3 -= 3;
	Carta temp3 = start.mazo.cartas[start.mazo.n_cartas - 3];
	start.mazo.cartas[start.mazo.n_cartas - 3] = start.mazo.cartas[num3];
	start.mazo.cartas[num3] = temp3;
	return start;

}

Game yes_set(Game start,int player,Carta temp[],int tam_t) {
	for (int i = 0; i < tam_t; i++) {
		start.players[player].cartas[start.players[player].num_cartas] = temp[i];
		start.players[player].num_cartas++;
	}
	if (start.expand == 0) {
		for (int i = 0; i < start.filas; i++) {
			for (int j = 0; j < start.columnas - 1; j++) {
				if (temp[0].forma == start.tablero[i][j].forma && temp[0].color == start.tablero[i][j].color && temp[0].relleno == start.tablero[i][j].relleno && temp[0].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
				if (temp[1].forma == start.tablero[i][j].forma && temp[1].color == start.tablero[i][j].color && temp[1].relleno == start.tablero[i][j].relleno && temp[1].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
				if (temp[2].forma == start.tablero[i][j].forma && temp[2].color == start.tablero[i][j].color && temp[2].relleno == start.tablero[i][j].relleno && temp[2].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
			}
		}
	}
	else {
		for (int i = 0; i < start.filas; i++) {
			for (int j = 0; j < start.columnas ; j++) {
				if (temp[0].forma == start.tablero[i][j].forma && temp[0].color == start.tablero[i][j].color && temp[0].relleno == start.tablero[i][j].relleno && temp[0].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
				if (temp[1].forma == start.tablero[i][j].forma && temp[1].color == start.tablero[i][j].color && temp[1].relleno == start.tablero[i][j].relleno && temp[1].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
				if (temp[2].forma == start.tablero[i][j].forma && temp[2].color == start.tablero[i][j].color && temp[2].relleno == start.tablero[i][j].relleno && temp[2].num == start.tablero[i][j].num) {
					start.tablero[i][j] = { "0","0","0",0 };
				}
			}
		}

	}
	return start;
}

Game no_set(Game start, int player) {
	if (start.players[player].num_cartas >= 3) {
		start.mazo.cartas[start.mazo.n_cartas + 1] = start.players[player].cartas[start.players[player].num_cartas];
		start.mazo.cartas[start.mazo.n_cartas + 2] = start.players[player].cartas[start.players[player].num_cartas - 1];
		start.mazo.cartas[start.mazo.n_cartas + 3] = start.players[player].cartas[start.players[player].num_cartas - 2];
		start.players[player].cartas[start.players[player].num_cartas] = { "0","0","0",0 };
		start.players[player].cartas[start.players[player].num_cartas - 1] = { "0","0","0",0 };
		start.players[player].cartas[start.players[player].num_cartas - 2] = { "0","0","0",0 };
		start.mazo.n_cartas += 3;
		start.players[player].num_cartas -= 3;
		start = ran_mazo(start);
	}
	else
	{
		cout << "Este jugador no tiene SET'S\n";
	}
	return start;
}

Game rellenar_tablero(Game start) {
	Carta reset = { "0", "0", "0", 0 };
	if (start.expand == 0) {
		for (int i = 0; i < start.filas; i++) {
			for (int j = 0; j < start.columnas - 1; j++) {
				if (start.tablero[i][j].forma == "0" && start.tablero[i][j].color == "0" && start.tablero[i][j].relleno == "0" && start.tablero[i][j].num == 0) {
					start.tablero[i][j] = start.mazo.cartas[start.mazo.n_cartas - 1];
					start.mazo.n_cartas -= 1;
				}
			}
		}
	}
	else {
		for (int i = 0; i < start.filas; i++) {
			for (int j = 0; j < start.columnas; j++) {
				if (start.tablero[i][j].forma == "0" && start.tablero[i][j].color == "0" && start.tablero[i][j].relleno == "0" && start.tablero[i][j].num == 0) {
					start.tablero[i][j] = start.mazo.cartas[start.mazo.n_cartas - 1];
					start.mazo.n_cartas -= 1;
				}
			}
		}
	}
	return start;
}

//Funcion para evaluar si las cartas elegidas son set (se recibe la estructura principal)
Game value_set(Game start, int player) {
	//se crea vector donde se almacenan las cartas elegidas
	Carta temp[3];
	int c_set;
	//ciclo de 3 por lo que se eligen 3 cartas
	for (int i = 0; i < 3; i++) {
		cout << "ingrese la carta " << i + 1 << " del set: " << endl;
		cin >> c_set;
		if (start.expand == 0) {
			switch (c_set)
			{
			case 1:
				temp[i] = start.tablero[0][0];
				break;
			case 2:
				temp[i] = start.tablero[0][1];
				break;
			case 3:
				temp[i] = start.tablero[0][2];
				break;
			case 4:
				temp[i] = start.tablero[0][3];
				break;
			case 5:
				temp[i] = start.tablero[1][0];
				break;
			case 6:
				temp[i] = start.tablero[1][1];
				break;
			case 7:
				temp[i] = start.tablero[1][2];
				break;
			case 8:
				temp[i] = start.tablero[1][3];
				break;
			case 9:
				temp[i] = start.tablero[2][0];
				break;
			case 10:
				temp[i] = start.tablero[2][1];
				break;
			case 11:
				temp[i] = start.tablero[2][2];
				break;
			case 12:
				temp[i] = start.tablero[2][3];
				break;
			default:
				cout << "carta no existente";
				//si hay error se disminuye i para que repita la carta (no se pueden cometer mas de 1 error simultaneo)
				//i--;
				break;
			}
		}
		else
		{
			switch (c_set)
			{
			case 1:
				temp[i] = start.tablero[0][0];
				break;
			case 2:
				temp[i] = start.tablero[0][1];
				break;
			case 3:
				temp[i] = start.tablero[0][2];
				break;
			case 4:
				temp[i] = start.tablero[0][3];
				break;
			case 5:
				temp[i] = start.tablero[0][4];
				break;
			case 6:
				temp[i] = start.tablero[1][0];
				break;
			case 7:
				temp[i] = start.tablero[1][1];
				break;
			case 8:
				temp[i] = start.tablero[1][2];
				break;
			case 9:
				temp[i] = start.tablero[1][3];
				break;
			case 10:
				temp[i] = start.tablero[1][4];
				break;
			case 11:
				temp[i] = start.tablero[2][0];
				break;
			case 12:
				temp[i] = start.tablero[2][1];
				break;
			case 13:
				temp[i] = start.tablero[2][2];
				break;
			case 14:
				temp[i] = start.tablero[2][3];
				break;
			case 15:
				temp[i] = start.tablero[2][4];
				break;
			default:
				cout << "carta no existente";
				//si hay error se disminuye i para que repita la carta (no se pueden cometer mas de 1 error simultaneo)
				//i--;
				break;
			}
		}
	}
	//se verifica el set con contadores indivuales de cada caracteristica
	int contf = 0, contc = 0, contr = 0, contn = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			if (temp[i].forma == temp[j].forma) {
				contf++;
			}
			if (temp[i].color == temp[j].color) {
				contc++;
			}
			if (temp[i].num == temp[j].num) {
				contn++;
			}
			if (temp[i].relleno == temp[j].relleno) {
				contr++;
			}
		}
	}
	cout << "Contadores Caracteristicas: \n";
	cout << "forma: " << contf <<endl;
	cout << "color: " << contc << endl;
	cout << "numero: " << contn << endl;
	cout << "relleno:" << contr << endl;
	//si las cartas son set solo hay dos posibilidades
	// 0 todas diferentes, 3 todas iguales
	//si da 1 es que solo dos de las 3 cartas son iguales
	if (contf == 1 || contc == 1 || contn == 1 || contr == 1 ) {
		cout << "\nNO SET\n";
		start = no_set(start,player);
		imprimir_tablero(start);
	}
	else {
		cout << "\nSET\n";
		start = yes_set(start, player, temp, 3);
		imprimir_tablero(start);
		system("pause");
		start = rellenar_tablero(start);
		imprimir_tablero(start);
	}
	return start;
}

Game juego(Game start) {
	int opc, cont_noset =0;
	do{
		cout << "\nHere We Go";
		cout << "\nIngresa ID (0 NO SET): ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			start = value_set(start,0);
			break;
		case 2:
			start = value_set(start, 1);
			break;
		case 0:
			if (cont_noset == 0) {
				cout << "Se agrega Columna";
				start.expand = 1;
				cont_noset++;
				start = rellenar_tablero(start);
				system("cls");
				imprimir_tablero(start);
			}
			else
			{
				cont_noset++;
				cout << "No mas SET'S";
			}
			break;
		default:
			system("cls");
			cout<<"\nFINISH\n";
			break;
		}
	} while (cont_noset != 2  || start.mazo.n_cartas == 0);
	return start;
}

int main(void) {
	Game start;
	start = inscribir(start);
	start = llenar_tablero(start);
	start = juego(start);
	ganador(start);
}