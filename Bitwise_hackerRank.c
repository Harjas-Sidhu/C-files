#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k)
{
    int and[n+k+1][n+k+1], or[n+k+1][n+k+1], xor[n+k+1][n+k+1], res_and = 0, res_or = 0, res_xor = 0;
    if (n >= 2 && n <= 1000)
    {
        if (k >= 2 && k <= n)
        {
            for (int i = 1; i <= k;)
            {
                for (int j = i + 1; j <= n;)
                {
                    and[i][j] = i & j;
                    or [i][j] = i | j;
                    xor[i][j] = i ^ j;
                    j = j + 1;
                }
                i = i + 1;
            }
            for (int i = 1; i <= k;)
            {
                for (int j = i + 1; j <= n;)
                {
                    if (and[i][j] < k)
                    {
                        if (and[i][j] > res_and)
                        {
                            res_and = and[i][j];
                        }
                    }
                    if (or [i][j] < k)
                    {
                        if (or [i][j] > res_or)
                        {
                            res_or = or [i][j];
                        }
                    }
                    if (xor[i][j] < k)
                    {
                        if (xor[i][j] > res_xor)
                        {
                            res_xor = xor[i][j];
                        }
                    }
                    j = j + 1;
                }
                i = i + 1;
            }
            printf("%d\n%d\n%d", res_and, res_or, res_xor);
        }
        else
        {
            printf("Wrong value of k\n");
        }
    }
    else
    {
        printf("Wrong value of n\n");
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
