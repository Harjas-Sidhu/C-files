#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void swap(int a, int b, struct triangle *tr)
{
    struct triangle temp = tr[a];
    tr[a] = tr[b];
    tr[b] = temp;
}

float area(int a, struct triangle *tr)
{
    float p = (tr[a].a+tr[a].b+tr[a].c)/2;
    float area = sqrt(p*(p-tr[a].a)*(p-tr[a].b)*(p-tr[a].c));
    return area;