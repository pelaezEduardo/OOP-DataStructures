#include "stdafx.h"
#include "MyLinkedListCpp.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{	
	MyLinkedListCpp *myList = new MyLinkedListCpp();
	myList->addFirst(1);
	myList->addFirst(2);
	myList->addFirst(3);
	myList->addFirst(4);
	myList->addFirst(5);
	myList->addLast(0);	
	int size = myList->size();

	for (int i = 0; i < size; i++)
	{
		Console::WriteLine(myList->removeFirst());
	}
	return 0;
}
