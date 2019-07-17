// pruebacod.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include"pch.h"
#include<iostream>
#include<iomanip>
#include <math.h>
#include <string>
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

void palindromo() {
	int opc, n, a, inv, copia;
	system("cls");
	inv = 0;
	cout << endl;
	cout << "\n\tIngrese un n�mero: ";
	cin >> n;
	copia = n;
	while (n != 0) {
		a = n % 10;
		inv = (inv * 10) + a;
		n = n / 10;
	}
	if (inv == copia) {
		cout << "El n�mero es pal�ndromo." << endl;
	}
	else {
		cout << "El n�mero NO es pal�ndromo." << endl;
	}
	system("pause");
	system("cls");
	cout << endl;
}

void integrales() {
	int s, b, c;
	float limi, lims;
	float npar;
	char resp = 's';
	float deltax, integralIzq = 0, integralDer = 0, xIz = 0, xpowIz = 0, xDer = 0, xpowDer = 0;

	system("cls");
	integralIzq = 0;
	integralDer = 0;
	cout << "Ingrese t�rmino x^2: ";
	cin >> s;
	cout << "Ingrese t�rmino x^1: ";
	cin >> b;
	cout << "Ingrese t�rmino de independiente: ";
	cin >> c;
	cout << "\nL�mite inferior: ";
	cin >> limi;
	cout << "L�mite superior: ";
	cin >> lims;
	do {
		cout << "\nIngrese el n�mero de particiones: ";
		cin >> npar;
		deltax = (lims - limi) / npar;
		for (int i = 0; i < npar; i++) {
			xIz = (limi + deltax * i);
			xpowIz = (limi + deltax * i)*(limi + deltax * i);
			integralIzq += deltax * (s*xpowIz + b * xIz + c);
		}
		for (int j = npar; j > 0; j--) {
			xDer = (limi + deltax * j);
			xpowDer = (limi + deltax * j)*(limi + deltax * j);
			integralDer += deltax * (s*xpowDer + b * xDer + c);
		}
		cout << "\nEl resultado de la integral es de: ";
		std::cout << "\nIzquierda: " << integralIzq;
		std::cout << "\nDerecha: " << integralDer;
		cout << "\n\nDesea realizar m�s particiones? (s/n): ";
		cin >> resp;
	} while (resp == 's');
	system("pause");
	system("cls");
}

void imprime(int x[], int r) {
	int i;
	for (i = 0; i < r; ++i) {
		cout << setw(4) << x[i];
	}
	cout << endl;
}

double promedio(int Vec[], int x) {
	int acum, i;
	double prom;
	acum = 0;
	for (i = 0; i < x; i++) {
		acum = acum + Vec[i];
		prom = (float)acum / x;
	}return prom;
}

double Desviacion_Estandar(int Vec[], int x) {
	int i, acum;
	double desve, media, distancia, suma, div;
	acum = 0;
	for (i = 0; i < x; i++) {
		acum = acum + Vec[i];
		media = (float)acum / x;
	}for (i = 0; i < x; i++) {
		distancia = distancia + pow((Vec[i] - media), 2);
	}
	desve = sqrt(distancia / x);
	return desve;
}

int Vector_Nuevo(int Vec2[], int m) {
	int tam, i, cont;
	int Vec3[1000];
	cont = 0;
	cout << "Digite el tama�o del nuevo vector: ";
	cin >> tam;
	for (i = 0; i < tam; i++) {
		cout << "Digite n�mero " << i + 1 << ":" << endl;
		cin >> Vec2[i];
		cont++;
	}
	return tam;
}

int Vector_Repetidos(int Vec1[], int n, int Vec2[], int m, int Vec4[], int z) {
	int i, j, numr;
	z = 0;
	cout << "Vector 1 :" << endl;
	imprime(Vec1, n);
	cout << "Vector 2 :" << endl;
	imprime(Vec2, m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (Vec1[i] == Vec2[j]) {
				Vec4[z] = Vec1[i];
				z++;
			}
		}
	}	cout << "El vector de n�meros repetidos es: " << endl;
	imprime(Vec4, z);
	return z;
}

void MenuVectores() {
	int Vec1[15] = { 3,7,12,17,23,31,34,45,57,59,63,72,89,94,96 };
	int Vec2[12] = { 26,59,6,45,24,69,68,12,11,34,31,85 };
	int Vec3[10000];
	int Vec4[1000];
	int n, m, tam, z, vecr, i;
	double prom, desve;
	n = 15;
	m = 12;
	int opcv, opcp;
	system("cls");
	do {
		cout << endl;
		cout << "\t\t\t\t\t   VECTORES " << endl;
		cout << "\t1.Listar Vectores" << endl;
		cout << "\t2.Medidas Vectores" << endl;
		cout << "\t3.Modificar Vector 2" << endl;
		cout << "\t4.Generar Vector con Repetidos" << endl;
		cout << "\t5.Listar Vector Repetidos" << endl;
		cout << "\t9.Salir" << endl;
		cout << "\nDigite una opci�n: ";
		cin >> opcv;
		system("cls");
		switch (opcv) {
		case 1: system("cls");
			cout << "Vector 1 : " << endl;
			imprime(Vec1, n);
			cout << "Vector 2 : " << endl;
			imprime(Vec2, m);
			system("pause");
			system("cls");
			break;
		case 2:	system("cls");
			cout << "Digite 1 para el vector 1 o 2 para el vector 2" << endl;
			cin >> opcp;
			if (opcp == 1) {
				prom = promedio(Vec1, n);
			}
			if (opcp == 2) {
				prom = promedio(Vec2, m);
			}
			cout << "El promedio es: " << setprecision(4) << prom << endl;
			if (opcp == 1) {
				desve = Desviacion_Estandar(Vec1, n);
			}
			if (opcp == 2) {
				desve = Desviacion_Estandar(Vec2, m);
			}
			cout << "La desviacion estandar es: " << setprecision(6) << desve << endl;
			system("pause");
			system("cls");
			break;
		case 3: system("cls");
			m = Vector_Nuevo(Vec2, m);
			system("pause");
			system("cls");
			break;
		case 4: system("cls");
			z = Vector_Repetidos(Vec1, n, Vec2, m, Vec4, z);
			system("pause");
			system("cls");
			break;
		case 5: system("cls");
			cout << "El Vector Repetido es: " << endl;
			imprime(Vec4, z);
			system("pause");
			system("cls");
			break;
		case 9: system("cls");
			cout << endl;
			system("cls");
			break;
		default:cout << "\n\tOpci�n inv�lida, intente de nuevo..." << endl;
			system("pause");
			system("cls");
			break;
		}

	} while (opcv != 9);
	cout << endl;
}


void mostrar(int mat[][100], int nf, int nc) {
	for (int i = 0; i < nf; ++i) {
		cout << "\n\t";
		for (int j = 0; j < nc; ++j) {
			cout << setw(4) << mat[i][j];
		};
	}
	cout << endl << endl;
}

int captura_mat(int mat[][100]) {
	int fil, col, tam;
	cout << "Ingrese nuevo n�mero de filas: ";
	cin >> fil;
	cout << "Ingrese nuevo n�mero de columnas: ";
	cin >> col;
	for (int i = 0; i < fil; i++) {
		cout << endl;
		for (int j = 0; j < col; j++) {
			cout << "Ingrese el elemento [" << i << "," << j << "]: ";
			cin >> mat[i][j];
		}
	}
	tam = ((fil * 10) + col);
	return tam;
}

void sumaizq(int mat[][100], int nf, int nc) {
	int j, acumsum, men;
	if (nc > nf) {
		men = nf;
	}
	else {
		men = nc;
	}
	j = 0;
	acumsum = 0;
	for (int i = 0; i < men; i++) {
		acumsum = acumsum + mat[i][j];
		j++;
	}
	cout << "\n\tLa suma de la diagonal de izquierda a derecha es: " << acumsum << endl;
}

void sumader(int mat[][100], int nf, int nc) {
	int i, j, accm, men;
	if (nc > nf) {
		men = nf;
	}
	else {
		men = nc;
	}
	accm = 0;
	j = 0;
	for (i = men - 1; i >= 0; i--) {
		accm = accm + mat[i][j];
		++j;
	}
	cout << "\tLa suma de la diagonal de derecha a izquierda es: " << accm << endl;
	cout << endl;
}

int sumacol(int mat[][100], int nf, int nc) {
	int i, j, col, acum;
	acum = 0;
	cout << "N�mero de columna: ";
	cin >> col;
	for (i = 0; i < nf; i++) {
		acum = acum + mat[i][col - 1];
	}
	return acum;
	cout << endl << endl;
}

void abundancia(int mat[][100], int nf, int nc) {
	int i, j, ind, pos, may, cont;
	cout << "Digite un n�mero (indicador): ";
	cin >> ind;
	may = 0;
	for (i = 0; i < nf; i++) {
		cont = 0;
		for (j = 0; j < nc; j++) {
			if (abs(mat[i][j]) > ind) {
				cont++;
			}
		}
		if (cont > may) {
			may = cont;
			pos = i + 1;
		}
	}
	cout << "La fila con m�s n�meros mayores que el indicador es: " << pos;
	cout << endl;
}

void MenuMatrices() {
	int mat[100][100] = { {89,-8,54,0,50,8,15,52,99,-2},
						{78,0,71,11,10,0,77,50,11,16},
						{67,-5,81,59,-8,27,76,-57,38,2},
						{53,93,15,2,79,16,24,0,65,0},
						{46,19,-8,-12,97,0,-95,72,97,19},
						{56,0,6,94,96,0,4,34,5,14},
						{4,86,12,0,92,-23,33,-42,31,0},
						{11,12,17,34,47,10,3,49,31,9} };
	int tam;
	int nf = 8, nc = 10;
	int opcm, acc;
	system("cls");
	do {
		cout << endl;
		cout << "\t\t\t\t  MATRICES " << endl;
		cout << "\t1.Mostrar matriz por pantalla" << endl;
		cout << "\t2.Capturar otra vez la matriz" << endl;
		cout << "\t3.Suma diagonales de la matriz" << endl;
		cout << "\t4.Suma columna de la matriz" << endl;
		cout << "\t5.Fila con mayor abundancia" << endl;
		cout << "\t9.Salir" << endl;
		cout << "\nDigite una opci�n: ";
		cin >> opcm;
		system("cls");
		switch (opcm) {
		case 1: system("cls");
			mostrar(mat, nf, nc);
			system("pause");
			system("cls");
			break;
		case 2:	system("cls");
			tam = captura_mat(mat);
			nf = tam / 10;
			nc = tam % 10;
			system("pause");
			system("cls");
			break;
		case 3: system("cls");
			mostrar(mat, nf, nc);
			sumaizq(mat, nf, nc);
			sumader(mat, nf, nc);
			system("pause");
			system("cls");
			break;
		case 4: system("cls");
			mostrar(mat, nf, nc);
			acc = sumacol(mat, nf, nc);
			cout << "Los elementos suman: " << acc << endl;
			system("pause");
			system("cls");
			break;
		case 5: system("cls");
			mostrar(mat, nf, nc);
			abundancia(mat, nf, nc);
			system("pause");
			system("cls");
			break;
		case 9: system("cls");
			cout << endl;
			system("cls");
			break;
		default:cout << "\n\tOpci�n inv�lida, intente de nuevo..." << endl;
			system("pause");
			system("cls");
			break;
		}

	} while (opcm != 9);
	cout << endl;
}

void listar_personas(humano persona[], int np, poblacion ciudad[], int nc) {
	int acc = 0, conth, contm;
	float porcm, porch;
	cout << endl;
	cout << "   Nombre   Sex  Ed  Ciudad-1 Ciudad-2 Ciudad-3 Ciudad-4 Ciudad-5 Ciudad-6 Ciudad-7" << endl;
	cout << "----------- ---  --  -------- -------- -------- -------- -------- -------- --------" << endl;
	for (int i = 0; i < np; ++i) {
		cout << setw(10) << persona[i].nombre << setw(4) << persona[i].sexo << setw(4) << persona[i].edad;
		for (int j = 0; j < persona[i].numciu; j++) {
			for (int k = 0; k < nc; k++) {
				if (persona[i].codigo[j] == ciudad[k].codigo) {
					cout << setw(9) << ciudad[k].nombre;
				}
			}
		}
		acc++;
		if (persona[i].sexo == 'm') {
			conth++;
		}
		else {
			contm++;
		}
		if (acc == 20) {
			cout << endl;
			system("pause");
			acc = 0;
		}
		cout << endl;
	}
	porcm = (float)contm / (contm + conth) * 100;
	cout << "Mujeres: " << porcm << "%" << endl;
	porch = (float)conth / (contm + conth) * 100;
	cout << "Hombres: " << porch << "%" << endl;
}

void listar_ciudades(poblacion ciudad[], int nc) {
	int acc, cont;
	acc = 0;
	cont = 0;
	double prom, res, ande;
	cout << endl;
	cout << "   Nombre    Codigo  �Turismo?  Temperatura    Costo " << endl;
	cout << "-----------  ------  ---------  -----------  --------- " << endl;
	for (int i = 0; i < nc; ++i) {
		cout << setw(10) << ciudad[i].nombre << setw(8) << ciudad[i].codigo << setw(8) << ciudad[i].func << setw(12) << ciudad[i].temp << setw(15) << ciudad[i].costo;
		acc++;
		if (acc == 10) {
			cout << endl << "\n";
			system("pause");
			acc = 0;
		}
		cout << endl;
	}
	for (int k = 0; k < nc; ++k) {
		if (ciudad[k].func == 's') {
			cont++;
		}
		prom = (float)cont / nc;
	}
	cout << "Porcentaje de ciudades funcionando   : " << prom * 100 << "%" << endl;
	res = 100 - (prom * 100);
	cout << "Porcentaje de ciudades sin funcionar : " << res << "%";
	cout << endl << "\n";
}

void consulta_ciudad(poblacion ciudad[], int nc, humano persona[], int np) {
	string nom;
	int cod, j, cont;
	cout << "Digite el nombre de la ciudad: ";
	cin >> nom;
	for (int i = 0; i < nc; i++) {
		if (nom == ciudad[i].nombre) {
			cod = ciudad[i].codigo;
		}
	}
	cont = 0;
	for (int i = 0; i < np; i++) {
		for (int j = 0; j < persona[i].numciu; j++) {
			if (cod == persona[i].codigo[j]) {
				cout << persona[i].nombre << endl;
				cont++;
			}
		}
	}
	cout << "\nTotal: " << cont << " personas. ";
	cout << endl << endl;
}

int agrupar_ciudad(poblacion ciudad[], int nc, int r_ciud[]) {
	string nom;
	int cont = 0;
	do {
		cout << "Digite el nombre de la ciudad (x to EOF): " << endl;
		cin >> nom;
		for (int i = 0; i < nc; i++) {
			if (nom == ciudad[i].nombre) {
				if (ciudad[i].func == 's') {
					r_ciud[cont] = ciudad[i].codigo;
					cont++;
				}
			}
		}
	} while (nom != "x");
	return cont;
}

void cuadrar_tour(int r_ciud[], int z, humano persona[], int np, poblacion ciudad[], int nc) {
	int i, j, k, cont;
	cout << "\n\tDestinos: " << endl;
	for (i = 0; i < z; i++) {
		for (j = 0; j < nc; j++) {
			if (r_ciud[i] == ciudad[j].codigo) {
				cout << "\t\t" << ciudad[j].nombre << endl;
			}
		}
	}
	cout << "\n\tPersonas que van al Tour: " << endl;
	for (i = 0; i < np; i++) {
		cont = 0;
		for (k = 0; k < z; k++) {
			for (j = 0; j < persona[i].numciu; j++) {
				if (persona[i].codigo[j] == r_ciud[k]) {
					++cont;
					break;
				}
			}
		}
		if (cont == z) {
			cout << "\t\t" << persona[i].nombre << endl;
		}
	}
}


void MenuEstructuras() {
	int opce;
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
	int np = 40, nc = 10, z;
	int r_ciud[10];
	string nombre[10];
	system("cls");
	do {
		cout << endl;
		cout << "\t\t\t\t  CHEVERE ON VACATION " << endl;
		cout << "\t1.Listar personas" << endl;
		cout << "\t2.Listar ciudades" << endl;
		cout << "\t3.Consultar ciudad" << endl;
		cout << "\t4.Agrupar ciudades" << endl;
		cout << "\t5.Cuadrar un Tour" << endl;
		cout << "\t9.Salir" << endl;
		cout << "\nDigite una opci�n: ";
		cin >> opce;
		system("cls");
		switch (opce) {
		case 1: system("cls");
			listar_personas(persona, np, ciudad, nc);
			system("pause");
			system("cls");
			break;
		case 2:	system("cls");
			listar_ciudades(ciudad, nc);
			system("pause");
			system("cls");
			break;
		case 3: system("cls");
			consulta_ciudad(ciudad, nc, persona, np);
			system("pause");
			system("cls");
			break;
		case 4: system("cls");
			z = agrupar_ciudad(ciudad, nc, r_ciud);
			system("pause");
			system("cls");
			break;
		case 5: system("cls");
			cuadrar_tour(r_ciud, z, persona, np, ciudad, nc);
			system("pause");
			system("cls");
			break;
		case 9: system("cls");
			cout << endl;
			system("cls");
			break;
		default:cout << "\n\tOpci�n inv�lida, intente de nuevo..." << endl;
			system("pause");
			system("cls");
			break;
		}

	} while (opce != 9);
	cout << endl;
}

int main(void)
{
	int opc;
	setlocale(LC_CTYPE, "spanish");
	do {
		cout << endl;
		cout << "\t\t\t\t\t  MEN� PRINCIPAL " << endl;
		cout << "\t1.N�mero Pal�ndromo" << endl;
		cout << "\t2.Integral por sumas de Riemann" << endl;
		cout << "\t3.Vectores Unidimensionales" << endl;
		cout << "\t4.Matrices" << endl;
		cout << "\t5.Estructuras" << endl;
		cout << "\t9.Salir" << endl;
		cout << "\nDigite una opci�n: ";
		cin >> opc;
		system("cls");
		switch (opc) {
		case 1: palindromo();
			break;
		case 2:	integrales();
			break;
		case 3: MenuVectores();
			break;
		case 4: MenuMatrices();
			break;
		case 5: MenuEstructuras();
			break;
		case 9: system("cls");
			cout << endl << endl << "\t\tGoodbye." << endl << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		default:cout << "\n\tOpci�n inv�lida... Intente de nuevo." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (opc != 9);
	cout << endl;
}

