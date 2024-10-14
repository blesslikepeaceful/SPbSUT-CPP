#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    float y;
    scanf("%d", &x);
    if (x < 2.1)
    {
        y = 2/(sqrt(abs(cos(x)+3)));
    }
    if (x >= 2.1)
    {
        y = 4/(sqrt(abs(cos(x)+3)));
    }
    printf("%f", y);
    return 0;
    
}