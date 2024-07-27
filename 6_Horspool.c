#include<stdio.h>
#include<string.h>

const int MAX = 256;

int fn(char string[], char pattern[], int []);
void fn1(char *, int []);

int main()
{
    char text[MAX], pattern[MAX];
    int shiftTable[MAX], found;

    printf("Enter the source string: ");
    fgets(text, MAX, stdin);

    printf("Enter the pattern string: ");
    fgets(pattern, MAX, stdin);

    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;

    fn1(pattern, shiftTable);
    found = fn(text, pattern, shiftTable);

    if (found == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", found + 1);
    return 0;
}

void fn1(char p[], int t[])
{
    int m, i, j;
    m = strlen(p);
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[p[j]] = m - 1 - j;
}

int fn(char s[], char p[], int t[])
{
    int i, n, k, m;
    n = strlen(s);
    m = strlen(p);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == s[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += t[s[i]];
    }
    return -1;
}