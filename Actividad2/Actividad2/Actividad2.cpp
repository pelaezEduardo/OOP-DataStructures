// Actividad2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "MyLinkedListC.h"

using namespace std;
int main()
{
	DoubleLinkedList *miLista = new DoubleLinkedList();
	FILE *archivo;
	char caracter;
	char siguiente;
	string cadena = "";
	archivo = fopen("Prueba.txt", "r");

	if (archivo == NULL)
	{
		cout << "Error en apertura de archivo";
	}
	else
	{
		caracter = fgetc(archivo);
		while (caracter != EOF)
		{
			if (caracter != '\n')
			{
				if (caracter == '-')
				{
					caracter = fgetc(archivo);
				}
				else
				{
					siguiente = fgetc(archivo);
					if (siguiente != '-')
					{
						cadena += caracter;
						cadena += siguiente;
						miLista->addLast(atoi(cadena.c_str()));
						cadena = "";
					}
					else
					{
						cadena = caracter;
						miLista->addLast(atoi(cadena.c_str()));
						cadena = "";
					}
					caracter = fgetc(archivo);
				}
			}
			else
			{
				caracter = fgetc(archivo);
			}
		}
	}
	fclose(archivo);

	cout << "SEBASTIAN ROSALES - 1010417" << endl;
	cout << "EDUARDO PELAEZ - 1096917" << endl;
	miLista->purge();		

}