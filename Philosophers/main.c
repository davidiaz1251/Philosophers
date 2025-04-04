#include <stdio.h>

int main (int argc, char **argv)
{
    printf("Hello, World!\n");
    int a = argc;
    char **b = argv;
    printf("a: %d\n", a);
    printf("b: %s\n", b[0]);
    return 0;
}
