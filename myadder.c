#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 3)
    {
        printf("Usage : %s <num1> <num2>", argv[0]);
        return -1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int sum = a + b;

    printf("Sum of %d and %d is %d", a, b, sum);

    return 0;
}