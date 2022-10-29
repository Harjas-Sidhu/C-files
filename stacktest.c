#include <stdio.h>
#include <math.h>

float e_Dist(float x1, float y1, float x2, float y2)
{
    float a = (x2 - x1) * (x2 -x1);
    float b = (y2 - y1) * (y2 -y1);
    return sqrt(a+b);
}

float aRea(float (*ptr)(float, float, float, float))
{
    float a, b, c, d;
    printf("Enter the Value of x1:\n");
    scanf("%f", &a);
    printf("Enter the Value of y1:\n");
    scanf("%f", &b);
    printf("Enter the Value of x2:\n");
    scanf("%f", &c);
    printf("Enter the Value of y2:\n");
    scanf("%f", &d);
    float rad = (ptr(a, b, c, d)) * (ptr(a, b, c, d));
    printf("Euclidean Distance is: %f\n", ptr(a, b, c, d));
    return 3.141592 * rad;
}

int main()
{
    float (*ptr1)(float, float, float, float);
    ptr1 = e_Dist;
    printf("Area of Circle is: %f\n", aRea(ptr1));
    return 0;
}