#include <stdio.h>

#define S 3 // states
#define A 2 // alphabet size

int dfa[S][A] = {{1, 0}, {2, 0}, {2, 2}};
int accept[] = {0, 0, 1};
char alpha[] = {'a', 'b'};

int main()
{
    printf("=== DFA ===\n");
    printf("States: {0,1,2}  Start: 0  Accept: {2}\n");
    printf("Transitions:\n");
    for (int i = 0; i < S; i++)
        for (int j = 0; j < A; j++)
            printf("  d(%d,%c) = %d\n", i, alpha[j], dfa[i][j]);
    int nfa[S][A];
    for (int i = 0; i < S; i++)
        for (int j = 0; j < A; j++)
            nfa[i][j] = 1 << dfa[i][j]; // singleton set {dfa[i][j]}

    printf("\n=== Equivalent NFA ===\n");
    printf("States: {0,1,2}  Start: 0  Accept: {2}\n");
    printf("Transitions (sets):\n");
    for (int i = 0; i < S; i++)
        for (int j = 0; j < A; j++)
        {
            printf("  d(%d,%c) = {", i, alpha[j]);
            int first = 1;
            for (int k = 0; k < S; k++)
                if (nfa[i][j] & (1 << k))
                {
                    if (!first)
                        printf(",");
                    printf("%d", k);
                    first = 0;
                }
            printf("}\n");
        }

    // on input "aab"
    char *input = "aab";
    int cur = 1 << 0; // start state set {0}
    printf("\nSimulating NFA on \"%s\":\n", input);
    printf("  Start: {0}\n");
    for (int i = 0; input[i]; i++)
    {
        int idx = input[i] - 'a';
        int next = 0;
        for (int s = 0; s < S; s++)
            if (cur & (1 << s))
                next |= nfa[s][idx];
        cur = next;
        printf("  After '%c': {", input[i]);
        int first = 1;
        for (int k = 0; k < S; k++)
            if (cur & (1 << k))
            {
                if (!first)
                    printf(",");
                printf("%d", k);
                first = 0;
            }
        printf("}\n");
    }
    int accepted = 0;
    for (int k = 0; k < S; k++)
        if ((cur & (1 << k)) && accept[k])
            accepted = 1;
    printf("  Result: %s\n", accepted ? "ACCEPTED" : "REJECTED");
    return 0;
}
