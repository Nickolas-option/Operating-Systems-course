#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int x;
    int y;
    printf("Pass x:\n");
    scanf("%d", &x);
    printf("Pass y:\n");
    scanf("%d", &y);
    swap(&x, &y);
    printf("x = %d, y = %d", x, y);
    return 0;
}
