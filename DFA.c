#include <stdio.h>
int T[10][10], F[10], n, a;

int test(char *s)
{
    int q = 0;
    for (int i = 0; s[i]; i++)
        q = T[q][s[i] - 'a'];
    return F[q];
}

void display()
{
    printf("\nTransition Table:\n\t");
    for (int j = 0; j < a; j++)
        printf("%c\t", 'a' + j);
    puts("");
    for (int i = 0; i < n; i++)
    {
        printf("q%d%s\t", i, F[i] ? "*" : "");
        for (int j = 0; j < a; j++)
            printf("q%d\t", T[i][j]);
        puts("");
    }
}

int main()
{
    printf("-----------------------------------------\n");
    printf("|----For the string ending with 'ab'----|\n");
    printf("-----------------------------------------\n");
    n = 3;
    a = 2;
    T[0][0] = 1;
    T[0][1] = 0;
    T[1][0] = 1;
    T[1][1] = 2;
    T[2][0] = 1;
    T[2][1] = 0;
    F[2] = 1;

    display();

    char *ex[] = {"ab", "aab", "bab", "abab", "ba", "bb", "a", "abb"};
    printf("\nTest Results:\n");
    for (int i = 0; i < 8; i++)
        printf("  \"%s\" -> %s\n", ex[i], test(ex[i]) ? "Accepted" : "Rejected");
}
