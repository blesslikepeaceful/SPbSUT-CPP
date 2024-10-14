#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    float y = 0;
    for (int x = -5; x <= 5; x++) 
    {
        if (x < 2.1)
        {
            y = 2/(sqrt(abs(cos(x)+3)));
            printf("Для i = %d, Для y = %lf\n", x, y);
        }
        if (x >= 2.1)
        {
            y = 4/(sqrt(abs(cos(x)+3)));
            printf("Для i = %d, Для y = %lf\n", x, y);
        }
    }
    return 0;
}