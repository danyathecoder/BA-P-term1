#include <stdio.h>

#define tasknumber 1

#if tasknumber == 1
int main() {
    int i=15, j, k=153;
    printf("Hello, World!\n");
    printf("%d", i+k);
    return 0;
}
#elif  tasknumber == 2
int main() {
    int i=15, j, k=153;
    printf("Hello, World!\n");
    return 0;
}
#endif