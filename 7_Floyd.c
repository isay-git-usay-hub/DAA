#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 999
int cost[10][10], a[10][10];

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

void allpaths(int cost[10][10], int a[10][10], int n)
{
    int i, j, k;
#pragma omp parallel for num_threads(2)
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            a[i][j] = cost[i][j];
    }
#pragma omp parallel for num_threads(3)
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

int main()
{
    int i, j, n;
    printf("\n\nEnter the no. of the vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    allpaths(cost, a, n);
    printf("The shortest poath obtained is as follows: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    return 0;
}
