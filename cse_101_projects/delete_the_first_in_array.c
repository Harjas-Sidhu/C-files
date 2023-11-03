#include <stdio.h>

int main(){
    int count;
    printf("Enter the size of array: ");
    scanf("%d", &count);
    int arr[count];
    for(int i = 0; i < count; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }
    int value = arr[0];
    count -= 1;
    for(int i = 0; i < count; i++){
        arr[i] = arr[i+ 1];
    }
    printf("Value deleted = %d\n", value);
    for(int i = 0; i < count; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    return 0;
}