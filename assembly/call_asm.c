#include <stdio.h>

int my_add(int a, int b);

int main(void) {
    int sum = my_add(3, 4);
    printf("my_add(3, 4) = %d\n", sum);
    return sum == 7 ? 0 : 1;
}
