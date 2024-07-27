#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k)
{
    int i;
    for (i = 1; i < k; i++)
        if (x[i] == x[k] || (abs(x[i] - x[k]) == abs(i - k)))
            return 0;
    return 1;
}

void display(int x[], int n)
{
    char board[20][20];
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            board[i][j] = 'x';
    for (i = 1; i <= n; i++)
        board[i][x[i]] = 'Q';
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void nqueens(int n)
{
    int x[30];
    int k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k] = x[k] + 1;
        while ((x[k] <= n) && !place(x, k))
            x[k] = x[k] + 1;
        if (x[k] <= n)
            if (k == n)
                display(x, n);
            else
            {
                k++;
                x[k] = 0;
            }
        else
            k--;
    }
}
void main()
{
    int n;
    printf("enter number of queens n>3: ");
    scanf("%d", &n);
    printf("the solution to queen problem is:\n");
    nqueens(n);
}
