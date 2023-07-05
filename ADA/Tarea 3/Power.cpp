#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0)
        return 1;

    double half = power(x, n / 2);
    double result = half * half;

    if (n % 2 == 1)
        result *= x;

    return result;
}

int main() {
    double base = 2.5;
    int exponent = 4;

    double result = power(base, exponent);

    cout << base << " elevado a la potencia " << exponent << " es igual a " << result << endl;

    return 0;
}
