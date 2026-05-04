#include <stdio.h>

struct Data {
    char a;
    int b;
    char c;
    double d;
};

int main() {
    struct Data d;
    printf("Structure size: %ld\n", sizeof(d));
    
    printf("Structure address of a: %p\n", (void*)&d.a);
    printf("Structure address of b: %p\n", (void*)&d.b);
    printf("Structure address of c: %p\n", (void*)&d.c);
    printf("Structure address of d: %p\n", (void*)&d.d);

    return 0;
}