#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 1;
int factorial(int n)
{
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    } 
}
int next_permutation(int n, char **s)
{
    char**sen;
    sen = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        sen[i] = (char*)realloc(sen, strlen(s[i])*sizeof(char));
        sen[i] = s[i];
    }
    int nse = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                nse+= 1;
            }    
        }   
    }
    if (count < (factorial(n)/factorial(nse)))
    {
        for (int i = 0; i < n; i++)
        {
            s[i] = sen[n-i-1];
        }
        count = count+1;
        return 1;
    }
    else {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        free(sen[i]);
    }
    
}
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}