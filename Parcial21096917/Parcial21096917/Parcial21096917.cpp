// Parcial21096917.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "CircularLinkedList.h"
#include "BinaryTree.h"
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{    
	//Llenar arbol     auxTortuga = 5000 + rand() % (10001 - 1); 
	BinaryTree *miArbol = new BinaryTree();	
	CircularLinkedList *miLista = new CircularLinkedList();
	int numero = 0;

	/*for (size_t i = 0; i < 100; i++)
	{
		numero = 5000 + rand() % (10001 - 5000);
		miArbol->add(numero);
	}*/

	miArbol->add(6000);
	miArbol->add(5600);
	miArbol->add(5150);
	miArbol->add(5145);
	miArbol->add(5385);
	miArbol->add(5900);
	miArbol->add(5943);
	miArbol->add(5944);
	miArbol->add(5948);
	miArbol->add(7500);
	miArbol->add(6900);
	miArbol->add(8300);
	miArbol->add(8100);
	miArbol->add(8260);
	miArbol->add(8255);
	miArbol->add(8275);
	miArbol->add(8265);
	miArbol->add(9500);
	miArbol->add(9001);
	miArbol->add(9872);

	cout << "Los elementos del arbol B son: " << endl;
	miArbol->inOrder(miArbol->root);

	cout << "\n\nLos nodos padre del arbol son: " << endl;
	miArbol->showParents(miArbol->root);
}
