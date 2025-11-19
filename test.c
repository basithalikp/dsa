#include <stdio.h>
int main() {
    int i = 3;
    int i; // Compilation error: redefinition of 'i'
    printf("%d", i);
    return 0;
}