#pragma once
#include <string>
#include "Empleado.h"

using namespace std;
class EPorHoras: public Empleado
{
public:
	EPorHoras();
	EPorHoras(string eNombre, int eEdad, int eDui, int eTipo, int hPrecio, int hHorasTrabajadas);
	~EPorHoras();
	void setPrecio(int hPrecio);
	int getPrecio();
	void setHorasTrabajadas(int hHorasTrabajadas);
	int getHorasTrabajadas();
	int calcularSueldo();
private:
	int precio;
	int horasTrabajadas;
};

