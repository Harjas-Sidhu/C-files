//  do not allocate memory for return string
//  assign the value to the pointer "result"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void spin_words(const char *sentence, char *result) 
{

    if((int)strlen(sentence) > 5)
    { 
        for(int i = 0; i < (int)strlen(sentence); i++)
        {
            result[i] = sentence[(int)strlen(sentence) - i - 1];
        }
    }
    else{
      for(int i = 0; i < (int)strlen(sentence); i++)
        {
            result[i] = sentence[i];
        }
    }
}
int main()
{
  char *res, *s;
  scanf("%s", s);
  getchar();
  res = (char*)calloc(strlen(s), sizeof(char));
  spin_words(s, res);
  for(int i = 0; i < (int)strlen(res); i++){
    printf("%c", res[i]);
  }
  free(s);
  free(res);
  return 0;
}