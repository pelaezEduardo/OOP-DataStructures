// HojaTrabajoPA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <string>
#include "pch.h"
#include <iostream>

struct Estudiante {
	char* sNombre;
	int iCarnet;
	int vNotas[3];
};

void vIngresaEstudiante(Estudiante *ptrEstudiante);
void vEstudianteToString(Estudiante *ptrEstudiante);

using namespace std;
int main()
{  
	cout << "Sebastian Rosales, carnet 1010417";
	cout << "Eduardo Pelaez, 1096917";
	Estudiante eDato;
	vIngresaEstudiante(&eDato);
	vEstudianteToString(&eDato);
}

void vIngresaEstudiante(Estudiante *ptrEstudiante) {
	char nombre[20];
	int carnet;
	int notas[3];
	int aux = 0;
	cout << "Ingrese el Nombre: ";
	cin >> nombre;
	cout << "Ingrese el numero de carnet: ";
	cin >> carnet;
	ptrEstudiante->sNombre = nombre;
	ptrEstudiante->iCarnet = carnet;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Ingrese la nota " << i + 1 << " : ";
		cin >> aux;
		if (aux > 0 && aux << 100)
		{
			notas[i] = aux;		
		}
		else
		{
			aux = 0;
			cout << "La notas deben estar entre 0 - 100";
			cout << "\nIngrese la nota " << i + 1 << " : ";
			cin >> aux;
			notas[i] = aux;
		}
		aux = 0;
	}
}

void vEstudianteToString(Estudiante *ptrEstudiante) {
	cout << "[Nombre]: " << ptrEstudiante->sNombre
		<< "\n[Carnet]: " << ptrEstudiante->iCarnet;
	cout << "NOTAS" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Nota " << i + 1 << ": " << ptrEstudiante->vNotas[i];
	}
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
