#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    float y = 0;
    int i = 0;
    int x1 = -5;
    int x2 = 5;
    int n = 15;
    int step = (n - 1);
    for (x1; x2; x1 += step) 
    {
        i++;
        if (x1 < 2.1)
        {
            y = 2/(sqrt(abs(cos(x1)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, x1, y);
        }
        if (x1 >= 2.1)
        {
            y = 4/(sqrt(abs(cos(x1)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, x1, y);
        }
    }
    return 0;
}