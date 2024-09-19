#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return sqrt(fabs(cos(x)) * x * x);  // ?(|cos(x)| * x^2)
}

int main() {
    int n = 8;
    double a = 1.0, b = 3.0, h, y, x, min_y, min_x, max_y, max_x;

    // Обчислюємо крок табулювання
    h = (b - a) / n;

    // Обчислюємо значення функції f(x) у початковій точці
    x = a;
    y = f(x);

    cout << "\nx=\ty=\n";
    // Форматуємо вивід
    cout.width(10);
    cout.precision(5);
    cout << x << '\t' << y << endl;

    // Запам'ятовуємо значення функції у першій точці
    max_y = min_y = y;
    max_x = min_x = x;

    for (int i = 1; i <= n; i++) {
        // Обчислюємо нову точку табулювання
        x = a + h * i;
        y = f(x);

        cout.width(10);
        cout.precision(5);
        cout << x << '\t' << y << endl;

        // Шукаємо найбільше та найменше значення функції
        if (y < min_y) {
            min_y = y;
            min_x = x;
        }
        else if (y > max_y) {
            max_y = y;
            max_x = x;
        }
    }

    // Виводимо результат на екран
    cout << "\nThe largest value taken by the function is "
        << max_y << " at " << max_x
        << "\nThe smallest value taken by the function is "
        << min_y << " at " << min_x;

    cout << "\n\nEnd of program.\n";
    return 0;
}
