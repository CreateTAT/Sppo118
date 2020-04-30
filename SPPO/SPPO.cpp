#include <iostream>
#include "Windows.h"

using namespace std;

struct TreeElement
{
int value;
TreeElement* right;
TreeElement* left;
TreeElement()
{
value = -1;
right = NULL;
left = NULL;
}
};
struct ListElement
{
int value;
ListElement* pointer;
ListElement()
{
value = -1;
pointer = NULL;
}
};
void Input(TreeElement*& el, int d )
{
if (el == NULL)
{
el = new TreeElement();
el->value = d;
}
else if (el->value > d)
{
Input(el->left, d);
}
else if (el->value < d)
{
Input(el->right, d);
}
}
void Output(TreeElement* el)
{
if (el != NULL)
{
cout << "(";
Output(el->left);
cout << el->value << " ";
Output(el->right);
cout << ")";
}
else
{
cout << ".";
}
}
void Detach(TreeElement* root, TreeElement* el)
{
if (root == NULL || el == NULL) { return; }
else if (root->left == el) { root->left = NULL; }
else if (root->right == el) { root->right = NULL; }
{
Detach(root->left, el);
Detach(root->right, el);
}
}
void Remove(TreeElement* el)
{
if (el != NULL)
{
Remove(el->left);
Remove(el->right);
delete el;
}
}
TreeElement* Find(TreeElement* el, int d)
{
TreeElement* result = NULL;
if (el == NULL) { result = NULL; }
else if (el->value == d) { result = el; }
else
{
result = Find(el->left, d);
if (result == NULL) { result = Find(el->right, d); }
}
return result;
}
void Spisok(ListElement*& one, TreeElement* el, ListElement*& a)
{
if (el != NULL)
{
Spisok(one, el->left, a);
ListElement* a1 = new ListElement();
a1->value = el->value;
if (a == NULL)
{
one = a1;
a = a1;
}
else {
a->pointer = a1;
a = a1;
}
Spisok(one, el->right, a);
}
}
void OutputList(ListElement* l)
{
while (l != NULL)
{
cout << l->value << " ";
l = l->pointer;
}
cout << endl;
}
int main()
{
setlocale(LC_ALL, "rus");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

TreeElement* root = NULL;
ListElement* first = NULL;
int b = 0, el;
cout << "Введите длину элементов ";
cin >> b;
cout << "Введите элементы ";
for (int i = 0; i < b; i++)
{
cin >> el;
Input(root, el);
}
Output(root);
cout << endl;
int m;
cout << "Введите элемент, поддерево которого вы хотите удалить";
cin >> m;
TreeElement* e = Find(root, m);
Detach(root, e);
Remove(e);
Output(root);
cout << endl;
cout << "Список ";
ListElement* l = NULL;
Spisok(first, root, l);
OutputList(first);
return 0;
}
