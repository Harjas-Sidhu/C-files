#include <stdio.h>

int main(){
    int i = 0;
    printf("Enter the number of values you want to enter: ");
    scanf("%d", &i);
    int arr[i];
    for(int count = 0; count < i; count++){
        printf("Enter the %d value: ", count+1);
        scanf("%d", &arr[count]);
    }
    int max = arr[0], min = arr[0], loc = -1, user_searched;
    for(int j = 0; j < i; j++){
        if(max < arr[j]){
            max = arr[j];
        }
        if(min > arr[j]){
            min = arr[j];
        }
    }
    printf("enter the value to search: ");
    scanf("%d", &user_searched);
    for(int j = 0; j < i; j++){
        if(arr[j] == user_searched){
            loc = j;
            break;
        }
    }
    printf("Maximum value is %d\n", max);
    printf("Minimum value is %d\n", min);
    printf("Location of %d is %d", user_searched, loc+1);
    return 0;
}