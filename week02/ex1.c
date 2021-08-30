#include "limits.h"
#include "stdio.h"
#include "float.h"
int main() {
        int a;
        float b;
        double c;
        a = INT_MAX;
        b = FLT_MAX;
        c = DBL_MAX;
        printf("%d\n%f\n%lf\n", a, b, c);
        printf("Size of integer: %lu\n", sizeof(a));
        printf("Size of float: %lu\n", sizeof(b));
        printf("Size of double: %lu\n", sizeof(c));
}
