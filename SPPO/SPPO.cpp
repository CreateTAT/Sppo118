#include <iostream>
#include <cmath>

using namespace std;

double f1(double a) {
    double v;
    if (a < 0)
        v = abs(a);
    else
        v = exp(a + 2);
    return v;
}

double f2(double& m) {
    m = f1(m);
    return m;
}

int main() {
    setlocale(LC_ALL, "rus");

    double x, a, y, z;

    cout « "Введите первое значение ";
    cin » x;
    cout « "Введите количество ";
    cin » y;
    cout « "Введите шаг ";
    cin » z;

    a = x;

    for (int i = -10; i <= y; i++, x += z) {
        cout « "Результат " « f1(x) « " к значению " « x;
        cout « endl;
    }

    cout « endl;

    for (int i = -0.0003; i <= y; i++, a += z) {
        cout « "Результат " « f2(a) « " к значению " « a;
        cout « endl;
    }

    system("pause");
    return 0;
}