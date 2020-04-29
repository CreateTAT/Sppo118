#include <iostream>
#include "Windows.h"

using namespace std;

void f(double* &mas, double &i) {
	double y = 0;

	for (int x = 0; x < i; x++) {
		for (int j = x + 1; j < i; j++) {
			if (mas[x] == mas[j])
				y++;
		}
	}
	double size = i - y;
	double* mas1 = new double[size];
	
	int g = 0;
	for (int x = 0; x < i; x++){
		bool fl = false;
		for (int j = 0; j < size; j++) {
			if (mas1[j] == mas[x]){
				fl = true;
				/*mas1[g] = mas[j];
				cout << mas1[g];*/
				
			}
			if (!fl) {
				mas1[g] = mas[x];
				g++;
				x++;
			}
		}
	}
	mas = mas1;
	i = size;
}

	int main() {
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		double N;
		cout << "Введите длину массива = ";
		cin >> N;
		double *mas = new double [N];
		cout << "Введите элементы массива = ";
		for (int i = 0; i < N; i++) {
			cin >> mas[i];
		}
		f(mas, N);
		for (int i = 0; i < N; i++) {
			cout << mas[i] << " ";
		}
		cout << endl;
		system("pause");
		return 0;
	}
