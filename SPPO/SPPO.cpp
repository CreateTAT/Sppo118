#include <iostream>
#include "Windows.h"


using namespace std;


struct element {
	int value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};

void InputList(element*& s, int n)
{
	element* p = NULL;
	int i = 0;
	cout << "Введите элементы списка ";
	while (i < n) {
		element* p1 = new element();
		cin >> p1->value;
		if (s == NULL) {
			s = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		i++;
	}
}

void OutputList(element* l) {
	cout << "Список: ";
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}

void DeleteFromList(element*& first, int n) 
{
	element* l = first, *t, * q, *i = first;
	element* p = NULL;
	while (l != NULL) {
		for (t = q = i->pointer; q != NULL; ) {
			if (l->value == i->value) {
				q = l->pointer;
				if (t == l)
					t = i->pointer = l->pointer;
				else
					t->pointer = l->pointer;
				delete l;
				l = q;
				continue;
			}
			t = l;
			l = l->pointer;
		}
		i = i->pointer;
	}
}

 void AddToList(element* first, int value) 
{
	element* i = new element;
	if (i != NULL) {
		i->value = value;
		i->pointer = first;
		first = i;
	}
	return(i != NULL);
}


int main() 
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	element* first = NULL;
	int n;
     cout << "Введите длину списка ";
	cin >> n;
	InputList(first, n);
	OutputList(first);
	DeleteFromList(first, n);
	AddToList (first,0);
	OutputList(first);
	
     system ("pause");
	return 0;
}
