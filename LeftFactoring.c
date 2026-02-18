#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PROD 20
#define MAX_ALT 20
#define MAX_LEN 100

int splitAlternatives(const char *rhs, char alts[][MAX_LEN])
{
    int count = 0, j = 0;
    for (int i = 0; rhs[i] != '\0'; i++)
    {
        if (rhs[i] == '|')
        {
            alts[count][j] = '\0';
            count++;
            j = 0;
        }
        else
        {
            alts[count][j++] = rhs[i];
        }
    }
    alts[count][j] = '\0';
    return count + 1;
}

void eliminateLeftRecursion(char nonTerm, const char *rhs)
{
    char alts[MAX_ALT][MAX_LEN];
    int n = splitAlternatives(rhs, alts);

    char alpha[MAX_ALT][MAX_LEN];
    char beta[MAX_ALT][MAX_LEN];
    int aCnt = 0, bCnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (alts[i][0] == nonTerm)
        {
            strcpy(alpha[aCnt++], alts[i] + 1);
        }
        else
        {
            strcpy(beta[bCnt++], alts[i]);
        }
    }

    if (aCnt == 0)
    {
        printf("  No left recursion found.\n");
        printf("  %c -> %s\n\n", nonTerm, rhs);
        return;
    }

    printf("  %c -> ", nonTerm);
    for (int i = 0; i < bCnt; i++)
    {
        if (i)
            printf(" | ");
        if (strcmp(beta[i], "ε") == 0 || strcmp(beta[i], "e") == 0 || strlen(beta[i]) == 0)
            printf("%c'", nonTerm);
        else
            printf("%s%c'", beta[i], nonTerm);
    }
    printf("\n");

    printf("  %c' -> ", nonTerm);
    for (int i = 0; i < aCnt; i++)
    {
        if (i)
            printf(" | ");
        printf("%s%c'", alpha[i], nonTerm);
    }
    printf(" | ε\n\n");
}

void leftFactor(char nonTerm, const char *rhs)
{
    char alts[MAX_ALT][MAX_LEN];
    int n = splitAlternatives(rhs, alts);

    if (n < 2)
    {
        printf("  No left factoring needed.\n");
        printf("  %c -> %s\n\n", nonTerm, rhs);
        return;
    }

    char prefix[MAX_LEN];
    strcpy(prefix, alts[0]);

    for (int i = 1; i < n; i++)
    {
        int k = 0;
        while (prefix[k] && alts[i][k] && prefix[k] == alts[i][k])
            k++;
        prefix[k] = '\0';
    }

    if (strlen(prefix) == 0)
    {
        printf("  No common prefix found.\n");
        printf("  %c -> %s\n\n", nonTerm, rhs);
        return;
    }

    int pLen = (int)strlen(prefix);

    printf("  %c -> %s%c'\n", nonTerm, prefix, nonTerm);

    printf("  %c' -> ", nonTerm);
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" | ");
        if (alts[i][pLen] == '\0')
            printf("ε");
        else
            printf("%s", alts[i] + pLen);
    }
    printf("\n\n");
}

int main(void)
{
    int n;
    char productions[MAX_PROD][MAX_LEN];

    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║  Left Recursion Elimination & Left Factoring Tool    ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n\n");

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar();

    printf("Enter each production in the form  A->α|β  (use 'e' for ε):\n");
    for (int i = 0; i < n; i++)
    {
        printf("  Production %d: ", i + 1);
        fgets(productions[i], MAX_LEN, stdin);
        productions[i][strcspn(productions[i], "\n")] = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        char *arrow = strstr(productions[i], "->");
        if (!arrow)
        {
            printf("\n⚠  Skipping invalid production: %s\n", productions[i]);
            continue;
        }

        char nonTerm = productions[i][0];
        char *rhs = arrow + 2;

        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("Original : %s\n\n", productions[i]);

        printf("► Left Recursion Elimination:\n");
        eliminateLeftRecursion(nonTerm, rhs);

        printf("► Left Factoring:\n");
        leftFactor(nonTerm, rhs);
    }

    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Done.\n");
    return 0;
}