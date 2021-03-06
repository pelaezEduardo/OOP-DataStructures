// Lab4_1096917.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
void movimientoTortuga(int i);
void movimientoLiebre(int i);
void imprimirPista();
void refrescarPista();
string pista[70];
int *pTortuga = new int;
int *pLiebre = new int; 
int auxTortuga = 0;
int auxLiebre = 0;

int main()
{	
	bool bandera = true;
	srand(time(NULL));
	*pTortuga = 0;
	*pLiebre = 0;
	cout << "BANG!" << endl << "Y ARRANCAN!" << endl;
	while (bandera)
	{
		if (*pTortuga <= 70 && *pLiebre <= 70)
		{
			auxTortuga = 1 + rand() % (11 - 1);
			auxLiebre = 1 + rand() % (11 - 1);
			movimientoTortuga(auxTortuga);
			movimientoLiebre(auxLiebre);
			refrescarPista();
			imprimirPista();			 
		}
		else
		{
			if (*pTortuga >= 70)
			{
				cout << "LA TORTUGA GANA!BRAVO!";				
			}
			else if (*pLiebre >= 70) {
				cout << "La liebre gana. Ni hablar.";				
			}
			else if (*pTortuga >= 70 && *pLiebre >= 70)
			{
				//favorecer a la tortuga
				cout << "LA TORTUGA GANÓ.";				
			}
			bandera = false;
		}

	}
}

void movimientoTortuga(int i) {
	if (i >= 1 && i <= 10) {
		if (i <= 5 && i >= 1) {
			*pTortuga += 3;
		}
		else if (i >= 6 && i <= 7) {
			*pTortuga -= 6;
			if (*pTortuga <= 0){
				*pTortuga = 1;
			}
		}
		else{
			*pTortuga += 1;
		}
	}
}

void movimientoLiebre(int i) {
	if (i >= 1 && i <= 10){	
		if (i >= 1 && i <= 2) {
			if (*pLiebre != 0) {
				*pLiebre += 0;
			}
			else {
				*pLiebre = 1;				
			}
		}
		else if (i >= 3 && i <= 4) {
			*pLiebre += 9;
		}
		else if (i == 5) {
			*pLiebre -= 12;
			if (*pLiebre <= 0) {
				*pLiebre = 1;
			}
		}
		else if (i >= 6 && i <= 8) {
			*pLiebre += 1;
		}
		else
		{
			*pLiebre -= 2;
			if (*pLiebre <= 0) {
				*pLiebre = 1;
			}
		}
	}
}

void refrescarPista() {
	int tortuga = 0;
	int liebre = 0;

	for (int i = 0; i < 70; i++)
	{
		pista[i] = "-";
	}

	if (*pTortuga == 1)
	{
		tortuga = 0;
	}
	else
	{
		tortuga = *pTortuga - 1;
	}

	if (*pLiebre == 1)
	{
		liebre = 0;
	}
	else
	{
		liebre = *pLiebre -1;
	}

	if (tortuga < 70 && liebre < 70)
	{
		if (tortuga != liebre) {
			pista[tortuga] = "T";
			pista[liebre] = "L";
		}
		else {
			if (tortuga != 70)
			{
				pista[tortuga] = "OUCH!";
			}			
		}
	}
	else
	{
		if (tortuga >= 70 && liebre < tortuga)
		{
			pista[69] = "T";
			pista[liebre] = "L";
		}
		else if (liebre >= 70 && tortuga < liebre)
		{
			pista[69] = "L";
			pista[tortuga] = "T";
		}
	}
}

void imprimirPista() {
	for (int i = 0; i < 70; i++)
	{
		cout << pista[i];
	}
	cout << endl;
}
