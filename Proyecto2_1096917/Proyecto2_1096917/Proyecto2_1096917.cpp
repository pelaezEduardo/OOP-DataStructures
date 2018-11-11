// Proyecto2_1096917.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Jugador.h"
#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{    
	int opt = 0;
	cout << "SEGUNDO PROYECTO \nClasificacion para el juego de las estrellas." << endl;

	do {
		cout << "\nSELECCIONE UNA OPCION" << endl;
		cout << "1. MANEJO DE DATOS" << endl;
		cout << "2. REPORTE ESTADISTICAS" << endl;
		cout << "3. SIMULACION"<< endl;
		cout << "4. SALIR" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1: {
			cout << "CARGANDO DATOS AL SISTEMA" << endl;
			BinaryTree<Jugador> *guard = new BinaryTree<Jugador>();
			BinaryTree<Jugador> *forward = new BinaryTree<Jugador>();
			BinaryTree<Jugador> *center = new BinaryTree<Jugador>();

			FILE *archivo;
			char caracter;		
			string cadena = "";
			string atributos[18];
			archivo = fopen("Prueba.txt", "r");
			int cont = 0;

			if (archivo == NULL) {
				cout << "Error en apertura de archivo";
			}
			else {
				caracter = fgetc(archivo);
				while (caracter != EOF) {
					if (caracter != '\n') {			
						if (caracter != '|') {
							cadena += caracter;
							caracter = fgetc(archivo);
						}
						else {
							atributos[cont] = cadena;
							cadena = "";
							caracter = fgetc(archivo);
							cont++;
						}
					}
					else {
						Jugador aux;
						aux = *new Jugador(atributos[0], atributos[1], atributos[2], atributos[3], atributos[4], atoi(atributos[5].c_str()), atoi(atributos[6].c_str()),
							atributos[7], atributos[8], atributos[9], atributos[10], atoi(atributos[11].c_str()), atributos[12], atoi(atributos[13].c_str()),
							atoi(atributos[14].c_str()), atoi(atributos[15].c_str()), atoi(atributos[16].c_str()), atoi(atributos[17].c_str()));
						if (atributos[4] == "G") {
							guard->add(aux, aux.getId());
						}
						else if (atributos[4] == "F") {
							forward->add(aux, aux.getId());
						}
						else {
							center->add(aux, aux.getId());
						}
						cont = 0;
						caracter = fgetc(archivo);
					}
				}
			}
			fclose(archivo);
					
			cout << "DATOS INGRESADOS EN EL ARBOL BINARIO EXITOSAMENTE." << endl;
			cout << "\nRecorrido por ID del arbol de defensas" << endl; 
			guard->preOrder(guard->root);
			cout << endl;
			cout << "\nRecorrido por ID del arbol de aleros" << endl;
			forward->preOrder(forward->root);
			cout << endl;
			cout << "\nRecorrido por ID del arbol de pivotes" << endl;
			center->preOrder(center->root);
		}break;

		case 2: {
		}break;

		case 3: {
		}break; 		

		default:
			cout << "GRACIAS POR USAR EL PROGRAMA" << endl;
			break;
		}

	} while (opt != 4);
}