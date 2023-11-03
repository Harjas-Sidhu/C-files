#include <stdio.h>

void swap(int arr[], int m, int n){
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}

int main(){
    int count;
    printf("Enter the size of array: ");
    scanf("%d", &count);
    int arr[count];
    for(int i = 0; i < count; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nBefore Reversal: \n");
    for(int i = 0; i < count; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    for(int i = 0; i < count/2; i++){
        swap(arr, i, count-1-i);
    }
    printf("\nAfter Reversal: \n");
    for(int i = 0; i < count; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    return 0;
}