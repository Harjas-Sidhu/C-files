#include <stdio.h>

int main(){
    FILE *fp = fopen("new.txt", "a");
    fprintf(fp, "\nI am a Human.");
    fclose(fp);
    return 0;
}