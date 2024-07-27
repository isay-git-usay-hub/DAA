#include <stdio.h>
#include <time.h>

void bfs(int n, int a[10][10], int source, int s[])
{
    int f, r, q[20];
    int u, v;
    int i;
    for (i = 0; i < n; i++)
        s[i] = 0;
    f = r = 0;
    q[r] = source;
    s[source] = 1;
    while (f <= r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1 && s[v] == 0)
            {
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void main()
{
    int n, i, j, source, a[10][10], s[10];
    printf("enter number of vertice\n");
    scanf("%d", &n);
    printf("enter adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("enter source\n ");
    scanf("%d", &source);
    clock_t start = clock();
    bfs(n, a, source, s);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 0)
            printf("%d is not reachable\n", i);
        else
            printf("%d is reachable\n", i);
    }
}
