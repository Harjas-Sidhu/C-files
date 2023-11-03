#include <stdio.h>

void add_value(int array[], int position_of_element, int size_of_array, int number){
    for(int i = size_of_array; i >= position_of_element-1; i--){
        array[i+1] = array[i];
    }
    array[position_of_element-1] = number;
}

int main(){
    int count, num, pos;

    printf("Enter the size of array: ");
    scanf("%d", &count);

    int arr[count];

    for(int i = 0; i < count; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to add: \n");
    scanf("%d", &num);

    printf("Enter the position of the number you wanrt it to be added: \n");
    scanf("%d", &pos);

    add_value(arr, pos, count, num);

    for(int i = 0; i < count+1; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
    return 0;
}