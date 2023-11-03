#include <stdio.h>

int main(){
    int n = 0;
    printf("enter");
    scanf("%d", &n);
    // for(int i = 1; i<=n;i++){
    //     for(int j = 1; j <= i; j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}