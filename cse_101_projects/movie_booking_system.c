#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int sum(int a){
    int opt = 0;
    while(a > 0){
        opt += a%10;
        a /= 10;
    }
    return opt;
}

int main(){
    int num = 0, res = 0;
    scanf("%d", &num);
    if(num < 0 || num > 10000){
        printf("Invalid Number");
    }
    else{
        res = sum(num);
        printf("%d", res);
    } 
    return 0;
}