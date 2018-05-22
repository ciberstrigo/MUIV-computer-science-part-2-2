#include <stdio.h>

long int factorial(int n)
{
    return (n < 2) ? 1 : n * factorial (n - 1);
}

main()
{
    int i, n;
    long int res = 0;

    printf("Input N: ");
    scanf("%d", &n);


    for(i = 1; i <= n; i++) 
    {
        res = res + factorial(i);
    }

    printf("%ld\n", res);
}
