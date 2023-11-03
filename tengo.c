#include <stdio.h>

void swap(int *p1 , int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int a = 0, b = 0;
    int *p1 = &a, *p2 = &b;
    printf("Enter a number: \n");
    scanf("%d", &a);
    printf("Enter another number: \n");
    scanf("%d", &b); 
    swap(p1, p2);
    printf("%d\n%d", a ,b);
    return 0;
}