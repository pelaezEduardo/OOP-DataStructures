// CStructures.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "MyLinkedListC.h"
#include "CircularLinkedList.h"
#include "DoubleLinkedList.h"
#include "BinaryTree.h"
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{
	//Ejercicio 1		
	BinaryTree *myBinaryTree = new BinaryTree();
	myBinaryTree->add(15);
	myBinaryTree->add(6);
	myBinaryTree->add(3);
	myBinaryTree->add(9);
	myBinaryTree->add(1);
	myBinaryTree->add(4);
	myBinaryTree->add(7);
	myBinaryTree->add(12);
	myBinaryTree->add(20);
	myBinaryTree->add(18);
	myBinaryTree->add(17);
	myBinaryTree->add(24);
	myBinaryTree->preOrder(myBinaryTree->root);
}
