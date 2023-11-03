// sort an array and use binary search

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


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
    printf("\nBefore Sorting: \n");
    for(int i = 0; i < count; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
    printf("\nAfter Sorting: \n");
    for(int i = 0; i < count; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    int key;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    int low = 0, high = count-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == key){
            printf("Key found at index %d\n", mid);
            break;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return 0;
}