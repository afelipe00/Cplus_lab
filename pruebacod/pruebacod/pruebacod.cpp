// pruebacod.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include"pch.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
#include<string>;

using namespace std;


struct humano {
	string nombre;
	char sexo;
	int edad;
	int ingreso;
	int numciu;
	int codigo[7];
};

struct poblacion {
	int codigo;
	string nombre;
	char func;
	int temp;
	int costo;
};

void listar_per(humano persona[], int np, poblacion ciudad[], int nc) {
	int homb = 0;
	int mujer = 0;
	int a;
	for (int i = 0; i < np; i++) {
		if (persona[i].sexo == 'm') {
			homb++;
		}
		else {
			mujer++;
		}
		cout << "Nombre: " << persona[i].nombre << endl;
		cout << "Sexo: " << persona[i].sexo << endl;
		cout << "Edad: " << persona[i].edad << endl;
		cout << "Ingreso: " << persona[i].ingreso << endl;
		for (int j = 0; j < persona[i].numciu; j++) {
			for (int k = 0; k < nc; k++) {
				if (persona[i].codigo[j] == ciudad[k].codigo) {
					cout << "Ciudades: " << ciudad[k].nombre << endl;
				}
			}
		}
		if (i == 19) {
			system("pause");
			system("cls");

		}
	}
	cout << " Porcentaje de hombres es: " << (np / homb) * 100 << endl;
	cout << " Porcentaje de mujeres es: " << (np / mujer) * 100 << endl;
}

void estructuras() {
	struct humano persona[100] = {
			{"Manuel",'m',35,1050000,5,{102,107,101,106,104}},
			{"Dilan",'m',38,1150000,4,{102,101,108,104}},
			{"Isabella",'f',33,1850000,7,{107,110,102,108,101,106,103}},
			{"Juan",'m',24,2000000,7,{107,101,110,105,106,102,104}},
			{"Pablo",'m',33,1400000,6,{106,101,103,107,105,102}},
			{"Patricia",'f',22,1750000,5,{101,103,105,110,108}},
			{"Valentina",'f',34,1300000,2,{108,106}},
			{"Andres",'m',27,1950000,7,{106,108,101,104,105,103,102}},
			{"Claudia",'f',22,1950000,4,{103,108,101,104}},
			{"Jairo",'m',40,1600000,5,{101,106,107,102,104}},
			{"Alejandro",'m',35,1550000,4,{102,105,109,106}},
			{"Enrique",'m',39,1700000,4,{110,101,104,102}},
			{"Mauricio",'m',27,1100000,4,{108,110,101,104}},
			{"Milena",'f',32,1050000,4,{102,105,104,101}},
			{"Ximena",'f',22,1850000,6,{102,103,108,101,104,106}},
			{"Nicolas",'m',34,1450000,4,{104,107,106,108}},
			{"David",'m',30,1200000,2,{101,108}},
			{"Carolina",'f',35,1150000,5,{108,106,110,101,104}},
			{"Daniel",'m',34,1350000,3,{108,107,104}},
			{"Tomas",'m',38,1600000,3,{102,101,108}},
			{"Oscar",'m',25,1100000,3,{101,107,104}},
			{"Stiven",'m',30,1800000,5,{102,106,107,103,101}},
			{"Sandra",'f',25,1500000,6,{104,107,109,101,102,106}},
			{"Daniela",'f',36,1900000,3,{104,106,108}},
			{"Noe",'m',28,1650000,2,{101,104}},
			{"Rafael",'m',27,1750000,5,{101,109,110,104,108}},
			{"Maria",'f',30,1350000,7,{109,104,110,101,102,106,105}},
			{"Andrea",'f',26,1100000,2,{108,101}},
			{"Angie",'f',33,1050000,2,{109,107}},
			{"Diego",'m',24,1600000,3,{101,102,105}},
			{"Eduardo",'m',21,1300000,2,{104,103}},
			{"Esteban",'m',33,1300000,6,{109,101,102,106,110,104}},
			{"Santiago",'m',39,1550000,2,{110,101}},
			{"Sofia",'f',32,1200000,2,{107,101,0}},
			{"Diana",'f',25,1200000,5,{110,102,106,109,101}},
			{"Haide",'f',33,1700000,6,{108,109,101,102,105,110}},
			{"Camila",'f',32,1000000,2,{106,108}},
			{"Paula",'f',32,1250000,3,{110,109,106}},
			{"Beatriz",'f',27,1250000,2,{108,101}},
			{"Laura",'f',24,1150000,7,{109,102,106,110,104,108,101}}
	};
	struct poblacion ciudad[10] = {
		   {101,"Paris",'s',27,2700000},
		   {102,"Londres",'s',32,2500000},
		   {103,"Amsterda",'s',34,2000000},
		   {104,"Madrid",'s',29,2600000},
		   {105,"Berlin",'n',31,2300000},
		   {106,"Roma",'s',26,2800000},
		   {107,"Florenci",'n',28,2400000},
		   {108,"Atenas",'s',25,2100000},
		   {109,"Venecia",'s',30,2900000},
		   {110,"Barcelon",'n',33,2200000}
	};
	int np = 40, nc = 10;

	for (int i = 0; i < np; ++i) {
		cout << setw(9) << persona[i].nombre
			<< setw(3) << persona[i].sexo
			<< setw(4) << persona[i].edad << endl;
	}
	system("pause");
	for (int i = 0; i < nc; ++i) {
		cout << setw(10) << ciudad[i].nombre
			<< setw(5) << ciudad[i].codigo
			<< setw(4) << ciudad[i].func << endl;
	}

	listar_per(persona, np, ciudad, nc);
	system("pause");
	//comentareado
}




void menu_s() {
	int opc = 0;
	humano persona[40];
	string ciudad[] = { "bogota","medellin","bucaramanga" };
	system("cls");
	do {
		cout << "------------MENU------------" << endl;
		cout << "1.listar personas\n2.listar ciudades\n3.consultar ciudad\n4.agrupar ciudades\n5.cuadrar un tour\n9.salir\n";
		cin >> opc;
		switch (opc) {
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:

			break;
		}
	} while (opc != 9);

}

int main(void) {
	estructuras();
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
