#include <stdio.h>
main()
{
    int i;
    int a[] = {5,2,4,8};
    int b[sizeof(*a)];
    cparr(a, b);

    ssort(a);
    printf("Unstable Selection Sort: ");
    for(i=0;i<sizeof(*a);i++)
        printf("%d ", a[i]);
    printf("\n");

    stablessort(b);
    printf("Stable Selection Sort: ");
    for(i=0;i<sizeof(*b);i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

cparr(int from[], int to[])
{
    int i;
    int len;
    if(sizeof(*from) == sizeof(*to))
        len = sizeof(*from);
    else
        return 1;
    for (i=0;i<len;i++)
        to[i] = from[i];
}

/*Selection Sort */
ssort(int a[])
{   
    int len = sizeof(*a);
    int min, j;
    int least;
    int tmp;

    for (min=0;min<len-1;min++)
    {
        least = min;

        for (j=min+1; j<len; j++)
            if(a[j] < a[least])
                least = j;

        tmp = a[min];
	    a[min] = a[least];
	    a[least] = tmp;
    }    

}

/*Stable Selection Sort */
stablessort(int a[])
{
    int len = sizeof(*a);
    int min;
    int i, j;
    int key;

    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++)
            if (a[min] > a[j])
                min = j;
        key = a[min];
        while (min > i) {
            a[min] = a[min - 1];
            min--;
        }
        a[i] = key;
    }
}