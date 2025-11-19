#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Tuple
{
    int row,coloumn,value;
}Tuple;

void display(Tuple Matrix[]){
    printf("%d %d %d\n_________\n",Matrix[0].row, Matrix[0].coloumn, Matrix[0].value);
    for (int i = 1; i <= Matrix[0].value; i++)
    {
        printf("%d %d %d\n", Matrix[i].row, Matrix[i].coloumn, Matrix[i].value);
    }
    printf("_________\n");
}

void transpose(Tuple Matrix[], Tuple Transpose[]){
    Transpose[0].row = Matrix[0].row;
    Transpose[0].coloumn = Matrix[0].coloumn;
    Transpose[0].value = Matrix[0].value;
    int current = 1;
    for (int i = 0; i < Matrix[0].coloumn; i++)
    {
        for (int j = 1; j < Matrix[0].value; j++)
        {
            Transpose[current].coloumn = Matrix[j].coloumn;
            Transpose[current].row = Matrix[j].row;
            Transpose[current].value = Matrix[j].value;
            current++;
        }
    }
    printf("Transposed successfully!\n");
    display(Transpose);
}

void addition(Tuple a[], Tuple b[], Tuple c[]){
    int i,j,k;
    if (a[0].row != b[0].row || a[0].coloumn != b[0].coloumn)
    {
        printf("Addition not possible!\n");
        return;
    }
    i = j = k = 1;
    c[0].row = a[0].row;
    c[0].coloumn = a[0].coloumn;
    while (i <= a[0].value && j <= b[0].value)
    {
        if (a[i].row == b[j].row && a[i].coloumn == b[j].coloumn && a[i].value + b[j].value != 0)
        {
            c[k].row = a[i].row;
            c[k].coloumn = a[i].coloumn;
            c[k].value = a[i].value + b[j].value;
            i++;j++;k++;
        }
        else if (a[i].row == b[j].row && a[i].coloumn < b[j].coloumn)
        {
            c[k].row = a[i].row;
            c[k].coloumn = a[i].coloumn;
            c[k].value = a[i].value;
            i++;k++;
        }
        else if (a[i].row == b[j].row && a[i].coloumn > b[j].coloumn)
        {
            c[k].row = b[j].row;
            c[k].coloumn = b[j].coloumn;
            c[k].value = b[j].value;
            j++;k++;
        }
        else if (a[i].row < b[j].row && a[i].coloumn == b[j].coloumn)
        {
            c[k].row = a[i].row;
            c[k].coloumn = a[i].coloumn;
            c[k].value = a[i].value;
            i++;k++;
        }
        else
        {
            c[k].row = b[j].row;
            c[k].coloumn = b[j].coloumn;
            c[k].value = b[j].value;
            j++;k++;
        }
    }
    while (i <= a[0].value)
    {
        c[k].row = a[i].row;
        c[k].coloumn = a[i].coloumn;
        c[k].value = a[i].value;
        i++;k++;
    }
    while (j <= b[0].value)
    {
        c[k].row = b[j].row;
        c[k].coloumn = b[j].coloumn;
        c[k].value = b[j].value;
        j++;k++;
    }
    c[0].value = k - 1;
    printf("Addition complete!\nResultant matrix : \n");
    display(c);
}

void read(Tuple Matrix[]){
    printf("Enter the number of rows : ");
    scanf("%d", &Matrix[0].row);
    printf("Enter the number of coloumns : ");
    scanf("%d", &Matrix[0].coloumn);
    printf("Enter the number of non - zero values : ");
    scanf("%d", &Matrix[0].value);
    for (int i = 1; i <= Matrix[0].value; i++)
    {
        printf("Enter row, coloumn, value respectively : ");
        scanf("%d%d%d", &Matrix[i].row, &Matrix[i].coloumn, &Matrix[i].value);
    }
    printf("Matrix recorded successfully!\n");
    display(Matrix);
}

int main(){
    int choice;
    Tuple MatrixA[MAX_SIZE], MatrixB[MAX_SIZE], Resultant[MAX_SIZE];
    printf("This is a menu driven program for Matrix!\n");
    while (1)
    {
        printf("Enter\n1 for addition\n2 for transpose\nPlease enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("___Addition___\n");
            printf("Enter first matrix : \n");
            read(MatrixA);
            printf("Enter second matrix : \n");
            read(MatrixB);
            addition(MatrixA, MatrixB, Resultant);
            break;
        case 2:
            printf("___Transpose___\n");
            printf("Enter your matrix : \n");
            read(MatrixA);
            transpose(MatrixA, Resultant);
            break;
        default:
            printf("Invalid!\n");
            break;
        }
    }
}