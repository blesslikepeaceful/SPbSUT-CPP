#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    float y = 0;
    int i = 0;
    double x1 = -5.0;
    double x2 = 5.0;
    int n = 97;
    float j;
    float step = (x2- x1)/(n - 1);
    for (j = x1; j<=x2 + 0.000001; j += step) 
    {
        i++;
        if (j < 2.1)
        {
            y = 2/(sqrt(abs(cos(j)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, j, y);
        }
        if (j >= 2.1)
        {
            y = 4/(sqrt(abs(cos(j)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, j, y);
        }
    }
    return 0;
}