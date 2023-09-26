#include <stdio.h>
int max(int a[]);
int main(void)
{
    int b[11] = { 1,2,3,4,5,6,7,8,9,0,11 };
    int m;
    m = maxi(b);
    printf("%d", m);
    return 0;
}


int maxi(int a[])
{
    int max = a[0];
    for (int i = 1; i < 11; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}