#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char *a, const char *b)
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    if (strcmp(a, b) > 0)
    {
        return -1;
    }
    else if (strcmp(a, b) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int c_a = strlen(a), c_b = strlen(b);
    char s_a[strlen(a)], s_b[strlen(b)];
    for (int i = 0; i < strlen(a); i++)
    {
        s_a[i] = a[i];
    }
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = i+1; j < strlen(a); j++)
        {
            if (s_a[i] == s_a[j])
            {
                if (s_a[j] != ' ')
                {
                    s_a[j] = ' ';
                }
            } 
        }
    }
    for (int i = 0; i < strlen(a); i++)
    {
        if (s_a[i] == ' ')
        {
            c_a--;
        }
    }
    for (int i = 0; i < strlen(b); i++)
    {
        s_b[i] = b[i];
    }
    for (int i = 0; i < strlen(b); i++)
    {
        for (int j = i+1; j < strlen(b); j++)
        {
            if (s_b[i] == s_b[j])
            {
                if (s_b[j] != ' ')
                {
                    s_b[j] = ' ';
                }
            } 
        }
    }
    for (int i = 0; i < strlen(b); i++)
    {
        if (s_b[i] == ' ')
        {
            c_b--;
        }
    }
    if (c_b < c_a)
    {
        return 1;
    }
    else if (c_b == c_a)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int sort_by_length(const char *a, const char *b)
{
    if (strlen(b) > strlen(a))
    {
        return -1;
    }
    else if (strlen(b) == strlen(a))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    for (int na = 0; na < len; na++)
    {
        for (int i = 1; i < len; i++)
        {
            if (cmp_func(arr[i - 1], arr[i]) > 0)
            {
                char *s;
                s = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = s;
            }
            else if (cmp_func(arr[i - 1], arr[i]) == 0)
            {
                if (cmp_func == sort_by_length || cmp_func == sort_by_number_of_distinct_characters) {
                    if (lexicographic_sort(arr[i - 1], arr[i]) > 0)
                    {
                        char *s;
                        s = arr[i - 1];
                        arr[i - 1] = arr[i];
                        arr[i] = s;
                    }
                }
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}