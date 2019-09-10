// Prog_pipe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int vehiculo, peajes, costo,total;

	cout << "digite el tipo de vehiculo";
	cin >> vehiculo;
	cout << "Digite los peajes";
	cin >> peajes;

	switch (vehiculo) {
	case 0: 
		costo = 0;
		break;
	case 1: 
		costo = 10500;
		break;
	case 2: 
		costo = 18700;
		break;
	case 3: 
		costo = 25400;
		break;
	case 4:
		costo = 36200;
		break;
	default: 
		cout << "carro no existente";

	}
	total = costo * peajes;

	if (peajes < 2) {
		costo = costo;
	}
	else if (peajes == 2) {
		costo = costo -(costo * 0.5);
	}
	else if (peajes == 3) {
		costo = costo - (costo * 0.10);
	}
	else if (peajes >= 4) {
		costo = costo - (costo * 0.20);

	}

	if (total > 110000) {
		total = total - (total * 0.90);
	}


	cout << "El costo total es:" << total << endl;




}
