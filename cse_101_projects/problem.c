#include<stdio.h>
char main(){
    static int i = 5;
    if(--i){
        main();
        printf("%d ",i);
    }
    return 'c';58*
}