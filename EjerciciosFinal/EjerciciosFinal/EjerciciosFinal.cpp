// EjerciciosFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"
#include "CircularLinkedList.h"
#include "CircularLinkedList.cpp"
#include "Empleado.h"
#include "EFijo.h"
#include "EPorHoras.h"
#include "ETemporal.h"

bool validacion(CircularLinkedList<char> *lc, DoubleLinkedList<char> *lde);
void bubble1(DoubleLinkedList<ETemporal> *list);
void bubble1(DoubleLinkedList<EFijo> *list);
void bubble1(DoubleLinkedList<EPorHoras> *list);
void bubble2(DoubleLinkedList<ETemporal> *list);
void bubble2(DoubleLinkedList<EFijo> *list);
void bubble2(DoubleLinkedList<EPorHoras> *list);
void bubble3(DoubleLinkedList<Empleado> *list);
void listado1(DoubleLinkedList<ETemporal> *list);
void listado1(DoubleLinkedList<EFijo> *list);
void listado1(DoubleLinkedList<EPorHoras> *list);
void listado2(DoubleLinkedList<ETemporal> *list);
void listado2(DoubleLinkedList<EFijo> *list);
void listado2(DoubleLinkedList<EPorHoras> *list);
void listado3(DoubleLinkedList<Empleado> *list);
CircularLinkedList<char>* change(DoubleLinkedList<char> *list);

using namespace std;
int main(){
	bool flag = true;
	DoubleLinkedList<char> *lde = new DoubleLinkedList<char>(0);
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
	cout << "EDUARDO ANTONIO PELAEZ CIFUENTES. [CARNET]: 10969-17" << endl;
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

	cout << "EJERCICIO 2: Lista enlazada" << endl;
	DoubleLinkedList<int> *listaEnlazadaL = new DoubleLinkedList<int>(0);
	DoubleLinkedList<int> *listaEnlazadaR = new DoubleLinkedList<int>(0);
	listaEnlazadaL->addLast(5);
	listaEnlazadaL->addLast(2);
	listaEnlazadaL->addLast(7);
	listaEnlazadaL->addLast(7);
	listaEnlazadaL->addLast(5);
	listaEnlazadaL->addLast(4);	
	int *repeated = new int[2];
	cout << "Lista: ";
	listaEnlazadaL->showElements();		
	cout << endl;	
	listaEnlazadaL->purge(repeated);
	for (size_t i = 0; i < 2; i++)
	{
		listaEnlazadaR->addLast(repeated[i]);
	}
	cout << "Nueva lista: ";
	listaEnlazadaR->showElements();
	cout << endl;

	cout << "\nEJERCICIO 3: POO - Herencia" << endl;	
	Empleado aux0 = *new Empleado();
	ETemporal aux1 = *new ETemporal();
	EFijo aux2 = *new EFijo();
	EPorHoras aux3 = *new EPorHoras();
	DoubleLinkedList<Empleado> *empleados = new DoubleLinkedList<Empleado>(aux0);
	DoubleLinkedList<ETemporal> *empleadosT = new DoubleLinkedList<ETemporal>(aux1);
	DoubleLinkedList<EFijo> *empleadosF = new DoubleLinkedList<EFijo>(aux2);
	DoubleLinkedList<EPorHoras> *empleadosH = new DoubleLinkedList<EPorHoras>(aux3);
	//lectura de archivo
	FILE *archivo2;
	char car;
	string cadena = "";
	archivo2 = fopen("Empleados.txt", "r");

	if (archivo2 == NULL) {
		cout << "Error en apertura de archivo";
	}
	else {
		car = fgetc(archivo2);
		while (car != EOF) {
			if (car != '\n') {
				cadena += car;
				car = fgetc(archivo2);
			}
			else { 
				if (cadena[14] == '1') {
					ETemporal aux = *new ETemporal(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
						atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 4).c_str()), 
						atoi(cadena.substr(23,4).c_str()));
					empleadosT->addLast(aux);		
					empleados->addLast(aux);
				}
				else if (cadena[14] == '2') {
					EFijo aux = *new EFijo(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
						atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 4).c_str()),
						atoi(cadena.substr(23, 4).c_str()));
					empleadosF->addLast(aux);
					empleados->addLast(aux);
				}
				else if (cadena[14] == '3') {
					EPorHoras aux = *new EPorHoras(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
						atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 2).c_str()));
					empleadosH->addLast(aux);
					empleados->addLast(aux);
				}
				cadena = "";
				car = fgetc(archivo2);
			}
		}
		//cuando el archivo termine agrega la ultima linea
		if (cadena[14] == '1') {
			ETemporal aux = *new ETemporal(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
				atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 4).c_str()),
				atoi(cadena.substr(23, 4).c_str()));
			empleadosT->addLast(aux);
			empleados->addLast(aux);
		}
		else if (cadena[14] == '2') {
			EFijo aux = *new EFijo(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
				atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 4).c_str()),
				atoi(cadena.substr(23, 4).c_str()));
			empleadosF->addLast(aux);
			empleados->addLast(aux);
		}
		else if (cadena[14] == '3') {
			EPorHoras aux = *new EPorHoras(cadena.substr(0, 8), atoi(cadena.substr(8, 2).c_str()), atoi(cadena.substr(10, 4).c_str()),
				atoi(cadena.substr(14, 1).c_str()), atoi(cadena.substr(15, 4).c_str()), atoi(cadena.substr(19, 2).c_str()));
			empleadosH->addLast(aux);
			empleados->addLast(aux);
		}
	}
	fclose(archivo2);
	cout << "LISTADO POR NOMBRE Y TIPO: " << endl;
	bubble1(empleadosT);
	bubble1(empleadosF);
	bubble1(empleadosH);
	cout << "Tipo 1:" << endl;
	listado1(empleadosT);
	cout << "Tipo 2:" << endl;
	listado1(empleadosF);
	cout << "Tipo 3:" << endl;
	listado1(empleadosH);

	cout << "\nLISTADO POR TIPO Y SUELDO: " << endl;
	bubble2(empleadosT);
	bubble2(empleadosF);
	bubble2(empleadosH);
	cout << "Temporal" << endl;
	listado2(empleadosT);
	cout << "Fijo" << endl;
	listado2(empleadosF);
	cout << "Por hora" << endl;
	listado2(empleadosH);

	cout << "\nLISTADO POR EDAD: " << endl;
	bubble3(empleados);
	listado3(empleados);

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

void bubble1(DoubleLinkedList<ETemporal> *list) {
	NodeD<ETemporal> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<ETemporal> *tempj = temp->getNext();
		while (tempj != list->trailer)
		{
			if (temp->getElement().getNombre() > tempj->getElement().getNombre()) {
				ETemporal aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void bubble1(DoubleLinkedList<EFijo> *list) {
	NodeD<EFijo> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<EFijo> *tempj = temp->getNext();
		while (tempj != list->trailer)
		{
			if (temp->getElement().getNombre() > tempj->getElement().getNombre() && temp->getElement().getTipo() > tempj->getElement().getTipo()) {
				EFijo aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void bubble1(DoubleLinkedList<EPorHoras> *list) {
	NodeD<EPorHoras> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<EPorHoras> *tempj = temp->getNext();
		while (tempj != list->trailer)
		{
			if (temp->getElement().getNombre() > tempj->getElement().getNombre() && temp->getElement().getTipo() > tempj->getElement().getTipo()) {
				EPorHoras aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void listado1(DoubleLinkedList<ETemporal> *list) {
	NodeD<ETemporal> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void listado1(DoubleLinkedList<EFijo> *list) {
	NodeD<EFijo> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void listado1(DoubleLinkedList<EPorHoras> *list) {
	NodeD<EPorHoras> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void bubble2(DoubleLinkedList<ETemporal> *list){
	NodeD<ETemporal> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<ETemporal> *tempj = temp->getNext();
		while (tempj != list->trailer) {
			if (temp->getElement().calcularSueldo() > tempj->getElement().calcularSueldo()) {
				ETemporal aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void bubble2(DoubleLinkedList<EFijo> *list) {
	NodeD<EFijo> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<EFijo> *tempj = temp->getNext();
		while (tempj != list->trailer) {
			if (temp->getElement().calcularSueldo() > tempj->getElement().calcularSueldo()) {
				EFijo aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void bubble2(DoubleLinkedList<EPorHoras> *list) {
	NodeD<EPorHoras> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<EPorHoras> *tempj = temp->getNext();
		while (tempj != list->trailer) {
			if (temp->getElement().calcularSueldo() > tempj->getElement().calcularSueldo()) {
				EPorHoras aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void bubble3(DoubleLinkedList<Empleado> *list) {
	NodeD<Empleado> *temp = list->header->getNext();

	while (temp->getNext() != list->trailer) {
		NodeD<Empleado> *tempj = temp->getNext();
		while (tempj != list->trailer) {
			if (temp->getElement().getEdad() > tempj->getElement().getEdad()) {
				Empleado aux = temp->getElement();
				temp->setElement(tempj->getElement());
				tempj->setElement(aux);
			}
			tempj = tempj->getNext();
		}
		temp = temp->getNext();
	}
}

void listado2(DoubleLinkedList<ETemporal> *list){
	NodeD<ETemporal> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << "; [Sueldo]: " << aux->getElement().calcularSueldo();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void listado2(DoubleLinkedList<EFijo> *list) {
	NodeD<EFijo> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << "; [Sueldo]: " << aux->getElement().calcularSueldo();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void listado2(DoubleLinkedList<EPorHoras> *list) {
	NodeD<EPorHoras> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << "; [Sueldo]: " << aux->getElement().calcularSueldo();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}

void listado3(DoubleLinkedList<Empleado> *list) {
	NodeD<Empleado> *aux = list->header->getNext();
	while (aux != list->trailer)
	{
		aux->getElement().toString();
		cout << "; [Edad]: " << aux->getElement().getEdad();
		cout << endl;
		cout << endl;
		aux = aux->getNext();
	}
}
