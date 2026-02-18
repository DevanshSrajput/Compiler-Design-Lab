#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *s)
{
    return !strcmp(s, "if") ||
           !strcmp(s, "else") ||
           !strcmp(s, "while") ||
           !strcmp(s, "int") ||
           !strcmp(s, "float") ||
           !strcmp(s, "return") ||
           !strcmp(s, "void");
}

int isOperator(char c) { return strchr("+-*/<>=", c) != NULL; }
int isSpecial(char c) { return strchr("(){}[];,", c) != NULL; }

void analyze(char *str)
{
    char token[50];
    int i = 0, j;
    int tokenCount = 0;
    while (str[i])
    {
        if (isspace(str[i]))
        {
            i++;
            continue;
        }
        if (isOperator(str[i]))
        {
            printf("Operator: %c\n", str[i++]);
            tokenCount++;
            continue;
        }
        if (isSpecial(str[i]))
        {
            printf("Special: %c\n", str[i++]);
            tokenCount++;
            continue;
        }
        j = 0;
        while (str[i] && !isspace(str[i]) && !isOperator(str[i]) && !isSpecial(str[i]))
            token[j++] = str[i++];
        token[j] = '\0';
        if (isKeyword(token))
            printf("Keyword: %s\n", token);
        else if (isdigit(token[0]))
            printf("Number: %s\n", token);
        else
            printf("Identifier: %s\n", token);
        tokenCount++;
    }
    printf("\nTotal number of tokens: %d\n", tokenCount);
}

int main()
{
    char str[] = "int x = 5;";
    printf("Input: %s\n", str);
    analyze(str);
    return 0;
}