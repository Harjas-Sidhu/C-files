#include <stdio.h>


void swap(int arr[], int m, int n){
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}

void buuble_sort(int arr[], int a){
     for (int i = 0; i < a; i++)
    {
        for (int j = i+1; j < a; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }
}

int main(){
    int a;

    printf("Enter a number: ");
    scanf("%d", &a);

    int arr[a];

    for(int i = 0; i < a; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nBefore sorting\n");

    for (int i = 0; i < a; i++)
    {
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }

    buuble_sort(arr, a);

    printf("\nAfter Sorting\n");

    for (int i = 0; i < a; i++)
    {
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }

    return 0;
}