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

	for (size_t i = 0; i < 100; i++)
	{
		numero = 5000 + rand() % (10001 - 5000);
		miArbol->add(numero);
	}

	cout << "Los elementos del arbol B son: " << endl;
	miArbol->inOrder(miArbol->root);

	cout << "\n\nLos nodos padre del arbol son: " << endl;
	miArbol->showParents(miArbol->root);

	miArbol->leaf(miArbol->root, miLista);
	cout << "\n\nElementos de la lista" << endl;
	miLista->showElements();

	//recorrer la lista en saltos de 2 en 2, el metodo está dentro la lista
	int repeticiones = 1 + rand() % (101 - 1);
	cout << "Resultado: " << miLista->searchPointer(repeticiones) << endl;

}
