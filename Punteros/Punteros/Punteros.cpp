#include "stdafx.h"
#include <iostream>
#include <cstdio> 
#include <cstdlib> 

using namespace System;

int main(array<System::String ^> ^args)
{
	int n1;
	int *num;	
	num = &n1;
	*num = 10;
	Console::WriteLine("El valor de num es: " + *num);
	std::cout << "El valor de num es: " << n1 << std::endl;
	std::cout << "La direccion de num es: " << "0x" << &n1;	
    return 0;
}
