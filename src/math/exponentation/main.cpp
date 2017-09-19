#include <math.h>
#include <assert.h>

double exponent(double base, int power);

/*
    Возведение в целочисленную степень действительного числа
    - время работы алгоритма O(log n)
    - используемая дополнительная память O(1)
*/
double exponent(double base, int power) {
    assert(power >= 0 && "power of exponent should be non-negative int number");
    assert((base != 0.0 || power != 0) && "incorrect math operation");

    double result = 1;
    double baseInPowerOf2 = base;
    while (power > 0) {
        if (power % 2 == 1) {
            result *= baseInPowerOf2;
        }
        baseInPowerOf2 *= baseInPowerOf2;
        power /= 2;
    }
    return result;
}
