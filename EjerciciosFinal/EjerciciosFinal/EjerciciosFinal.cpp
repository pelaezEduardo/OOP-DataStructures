// EjerciciosFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"
#include "CircularLinkedList.h"
#include "CircularLinkedList.cpp"

bool validacion(CircularLinkedList<char> *lc, DoubleLinkedList<char> *lde);
CircularLinkedList<char>* change(DoubleLinkedList<char> *list);

using namespace std;
int main(){
	bool flag = true;
	DoubleLinkedList<char> *lde = new DoubleLinkedList<char>();
	CircularLinkedList<char> *lc = new CircularLinkedList<char>();
	CircularLinkedList<char> *lde2 = new CircularLinkedList<char>();
	FILE *archivo;
	char caracter;		
	archivo = fopen("Prueba.txt", "r");

	if (archivo == NULL) {
		cout << "Error en apertura de archivo";
	}
	else {
		caracter = fgetc(archivo);
		while (caracter != EOF) {
			if (caracter != '\n' && flag) {
				lde->addLast(caracter);
				caracter = fgetc(archivo);
			}
			else {
				flag = false;
				if (caracter != '\n') { lc->addLast(caracter); }
				caracter = fgetc(archivo);				
			}
		}
	}
	fclose(archivo);
	cout << "LA LECTURA DEL ARCHIVO SE REALIZO CORRECTAMENTE" << endl;	
	cout << "EJERCICIO 1: LDE y LC" << endl;
	//validacion 1
	CircularLinkedList<char> *val1 = new CircularLinkedList<char>();
	val1->addLast(lc->removeFirst());
	val1->addLast(lc->removeFirst());
	val1->addLast(lc->removeFirst());
	val1->addLast(lc->removeFirst());
	val1->showElements();
	cout << "Validacion 1: ";
	if (validacion(val1, lde)) {
		cout << "100000" << endl;
	}
	else {
		cout << "000000" << endl;
	}
	cout << endl;

	//validacion 2
	CircularLinkedList<char> *val2 = new CircularLinkedList<char>();
	val2->addLast(lc->removeFirst());
	val2->addLast(lc->removeFirst());
	val2->addLast(lc->removeFirst());
	val2->addLast(lc->removeFirst());
	val2->showElements();
	cout << "Validacion 2: ";
	if (validacion(val2, lde)) {
		cout << "010000" << endl;
	}
	else {
		cout << "000000" << endl;
	}
	cout << endl;
	
	//validacion 3
	CircularLinkedList<char> *val3 = new CircularLinkedList<char>();
	val3->addLast(lc->removeFirst());
	val3->addLast(lc->removeFirst());
	val3->addLast(lc->removeFirst());
	val3->addLast(lc->removeFirst());
	val3->addLast(lc->removeFirst());
	val3->showElements();	
	cout << "Validacion 3: ";
	if (validacion(val3, lde)) {
		cout << "001000" << endl;
	}
	else {
		cout << "000000" << endl;
	}
	cout << endl;

	//validacion 4
	CircularLinkedList<char> *val4 = new CircularLinkedList<char>();
	val4->addLast(lc->removeFirst());
	val4->addLast(lc->removeFirst());
	val4->addLast(lc->removeFirst());
	val4->addLast(lc->removeFirst());
	val4->addLast(lc->removeFirst());
	val4->showElements();
	cout << "Validacion 4: ";
	if (validacion(val4, lde)) {
		cout << "000100" << endl;
	}
	else {
		cout << "000000" << endl;
	}
	cout << endl;

	//validacion 5
	CircularLinkedList<char> *val5 = new CircularLinkedList<char>();
	val5->addLast(lc->removeFirst());
	val5->addLast(lc->removeFirst());
	val5->addLast(lc->removeFirst());
	val5->showElements();
	cout << "Validacion 5: ";
	if (validacion(val5, lde)) {
		cout << "000010" << endl;
	}
	else {
		cout << "000000" << endl;
	}
	cout << endl;

	//validacion 6
	CircularLinkedList<char> *val6 = new CircularLinkedList<char>();
	val6->addLast(lc->removeFirst());
	val6->addLast(lc->removeFirst());
	val6->addLast(lc->removeFirst());
	val6->showElements();
	cout << "Validacion 6: ";
	if (validacion(val6, lde)){
		cout << "000001" << endl;}
	else {
		cout << "000000" << endl;
	}
	cout << endl;


}

bool validacion(CircularLinkedList<char> *lc, DoubleLinkedList<char> *lde) {
	bool response = true;
	CircularLinkedList<char> *lc2 = lc;
	NodeD<char> *aux = lde->header->getNext();
	char comp = lc2->removeFirst();
	
	while (comp != NULL) {
		if (aux->getElement() == comp) {
			aux = lde->header->getNext();
			comp = lc2->removeFirst();
			response = true;
		}
		else {
			aux = aux->getNext();
			if (aux == lde->trailer) {
				response = false;
				break;
			}
			else {
				response = false;
			}
		}
	}
	return response;
}

//metodo que traslada la lista DE a una lista circular para el resto de las validaciones
CircularLinkedList<char>* change(DoubleLinkedList<char> *list) {
	NodeD<char> *aux = list->header->getNext();
	CircularLinkedList<char> *response = new CircularLinkedList<char>();

	while (aux = list->trailer)	{
		response->addLast(aux->getElement());
		aux = aux->getNext();
	}

	return response;
}