#include <stdio.h>
void bubble_sort(int* a, int n) {
    for (int j = 0; j < n-1; ++j) {
        for (int i = 0; i < n-1; ++i) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main() {
    int a[10] = {5,4,3,7,2,1,6,0,9,8};
    bubble_sort(a,  sizeof(a)/sizeof(int));
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        printf("%d", a[i]);
    }
    return 0;
}
