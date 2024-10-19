#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    float y = 0;
    int i = 0;
    for (float x = -5; x <= 5; x += 10.0/14.0) 
    {
        i++;
        if (x < 2.1)
        {
            y = 2/(sqrt(abs(cos(x)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, x, y);
        }
        if (x >= 2.1)
        {
            y = 4/(sqrt(abs(cos(x)+3)));
            printf("Номер точки: %d, Для x = %f, Для y = %lf\n", i, x, y);
        }
    }
    return 0;
}