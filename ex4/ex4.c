#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
long double fact( const unsigned int a ) {
    unsigned int i;
    long double temp = 1;
 
    for ( i = 2; i <= a; i++ )
        temp *= i;
 
    return temp;
}
 
double fSinX( const double x, const unsigned int e ) {
    double tmp = 0;
    unsigned int n;
    for ( n = 0; n < e; n++ )
    {
    tmp += ( pow( -1., n ) / fact( 2 * n + 1 )) * pow( x, 2 * n + 1 );
    }
    return tmp;
}
 
main() {
    double x;
    int e;
    printf("Input X: ");
    scanf("%lf", &x);
    printf("Input E: ");
    scanf("%d", &e);
    printf("%lf\n", fSinX( x, e ));
    printf("%lf\n", sin( x ));
    return 0;
}
