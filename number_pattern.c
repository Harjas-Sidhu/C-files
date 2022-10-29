#include <stdio.h>

int main()
{
    int n, num = 1;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        num = num + 2;
    }
    int arr[num][num];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num - i; j++)
        {
            arr[i][j] = n - i;
        }
    }
    for (int i = 0; i < num; i++) 
    {
        for (int j = i; j < num - i; j++)
        {
            arr[j][i] = n - i;
        }
    }
    for (int i = 0; i < num; i++)  
    {
        for (int j = 0; j < num; j++)
        {
            arr[num-i-1][num-j-1] = arr[j][i];
        }
        
    }
    
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (j != num - 1)
            {
                printf("%d\t", arr[i][j]);
            }
            else
            {
                printf("%d\n", arr[i][j]);
            }
        }
    }

    return 0;
}