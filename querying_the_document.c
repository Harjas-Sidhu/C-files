#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n)
{
    return document[n][m][k];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m)
{
    return document[m][k];
}

char ***kth_paragraph(char ****document, int k)
{
    return document[k];
}

char ****get_document(char *text)
{
    char chars[strlen(text)];
    int c_num = strlen(text), w_num = 0, s_num = 0, p_num = 0;

    char words[c_num];
    for (int i = 0; i < c_num; i++)
    {
        if (text[i] != ' ')
        {
            words[i] = text[i];
        }
        else
        {
            words[i] = text[i];
            w_num++;
        }
    }

    char **sen = (char **)malloc(1 * sizeof(char));
    for (int i = 0; i < w_num; i++)
    {
        sen = (char **)realloc(sen, (i + 1) * sizeof(char *));
        *(sen + i) = (char *)malloc(1 * sizeof(char));
        for (int j = 0; j < c_num; j++)
        {
            sen = (char **)realloc(sen, (i + 1) * sizeof(char *));
            *(sen + i) = (char *)realloc(sen[i], (j + 1) * sizeof(char));
            if (words[j] != ' ')
            {
                sen[i][j] = words[j];
            }
            else
            {
                sen[i][j] = '\0';
                i++;
                s_num++;
            }
        }
    }

    char ***para = (char ***)malloc(1 * sizeof(char **));
    for (int i = 0; i < s_num; i++)
    {
        para = (char ***)realloc(para, (i + 1) * sizeof(char **));
        *(para + i) = (char **)malloc(1 * sizeof(char *));
        for (int j = 0; j < w_num; j++)
        {
            para = (char ***)realloc(para, (i + 1) * sizeof(char **));
            *(para + i) = (char **)realloc(para[i], (j + 1) * sizeof(char *));
            *(*(para + i) + j) = (char *)malloc(1 * sizeof(char));
            for (int k = 0; k < c_num; k++)
            {
                para = (char ***)realloc(para, (i + 1) * sizeof(char **));
                *(*(para + i) + j) = (char *)realloc(para[i][j], (k + 1) * sizeof(char));
                if (sen[j][k] != '.')
                {
                    if (sen[j][k] == '\0')
                    {
                        para[i][j][k] = ' ';
                    }
                    else
                    {
                        para[i][j][k] = sen[j][k];
                    }
                }
                else
                {
                    para[i][j][k] = '\0';
                    i++;
                    p_num++;
                }
            }
        }
    }

    char ****doc = (char ****)malloc(1 * sizeof(char ***));
    ;

    for (int i = 0; i < p_num; i++)
    {
        doc = (char ****)realloc(doc, (i + 1) * sizeof(char ***));
        *(doc + i) = (char ***)malloc(1 * sizeof(char **));
        for (int j = 0; j < s_num; j++)
        {
            doc = (char ****)realloc(doc, (i + 1) * sizeof(char ***));
            *(doc + i) = (char ***)realloc(doc[i], (j + 1) * sizeof(char **));
            *(*(doc + i) + j) = (char **)malloc(1 * sizeof(char *));
            for (int k = 0; k < w_num; k++)
            {
                doc = (char ****)realloc(doc, (i + 1) * sizeof(char ***));
                *(*(doc + i) + j) = (char **)realloc(doc[i][j], (k + 1) * sizeof(char *));
                *(*(*(doc + i) + j) + k) = (char *)malloc(1 * sizeof(char));
                for (int l = 0; l < c_num; l++)
                {
                    doc = (char ****)realloc(doc, (i + 1) * sizeof(char ***));
                    *(*(*(doc + i) + j) + k) = (char *)realloc(doc[i][j][k], (l + 1) * sizeof(char));
                    if (para[j][k][l] != '\n')
                    {
                        if (para[j][k][l] == '\0')
                        {
                            doc[i][j][k][l] = '.';
                        }
                        else
                        {
                            doc[i][j][k][l] = para[j][k][l];
                        }
                    }
                    else
                    {
                        doc[i][j][k][l] = para[j][k][l];
                        i++;
                    }
                }
            }
        }
    }
    return doc;
    for (int i = 0; i < p_num; i++)
    {
        for (int j = 0; j < s_num; j++)
        {
            for (int k = 0; k < w_num; k++)
            {
                free(doc[i][j][k]);
            }
            free(doc[i][j]);
        }
        free(doc[i]);
    }
    free(doc);
    for (int i = 0; i < w_num; i++)
    {
        free(sen[i]);
    }
    free(sen);
    for (int i = 0; i < s_num; i++)
    {
        for (int j = 0; j < w_num; j++)
        {
            free(para[i][j]);
        }
        free(para[i]);
    }
    free(para);
}

char *get_input_text()
{
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char *word)
{
    printf("%s", word);
}

void print_sentence(char **sentence)
{
    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++)
    {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph)
{
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++)
    {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char *text = get_input_text();
    char ****document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else
        {
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}