#include <stdio.h>
int main()
{
    int n, t1 = 0, t2 = 1, nexterm;
    printf("Enter number for Febonacci Searies:");
    scanf("%d", &n);
    printf("Fabonacci Searies: %d %d ", t1, t2);
    for (int i = 3; i <= n; i++)
    {
        nexterm = t1 + t2;
        printf(" %d ", nexterm);
        t1 = t2;
        t2 = nexterm;
    }
    printf("\n");
    return 0;
}