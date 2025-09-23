#include <stdio.h>
#include <stdlib.h>
struct mat
{
	int row,col;
	float val;
}a[100],b[100],sum[100],trans[100];

void polydisplay(struct mat arr[]){
	printf("Sparse matrix is:\n");
	for(int i=0;(i<=arr[0].val);i++)
	{
		printf("|%d %d %.1f|\n",arr[i].row,arr[i].col,arr[i].val);
	}
	printf("\n");
}
void transpose()
{
	int currb=1;
	trans[0].row=a[0].col;
	trans[0].col=a[0].row;
	trans[0].val=a[0].val;
	for(int i=0;i<a[0].col;i++)
	{
		for(int j=1;j<=a[0].val;j++)
		{
			if (a[j].col==i)
			{
				trans[currb].row=a[j].col;
				trans[currb].col=a[j].row;
				trans[currb].val=a[j].val;
				currb++;
			}
		}	
	}

	
	printf("\nTransposed ");
	polydisplay(trans);
}
void mat_add()
{
	if(a[0].row!=b[0].row||a[0].col!=b[0].col)
	{
		printf("Addition not possible\n");
		return;
	}
	sum[0].row=a[0].row;
	sum[0].col=a[0].col;
	int i=1,j=1,k=1,t1=a[0].val,t2=b[0].val;
	while(i<=t1 && j<=t2)
	{
		if(a[i].row==b[j].row && a[i].col==b[j].col && (a[i].val+b[j].val!=0))
		{
			sum[k].row=a[i].row;
			sum[k].col=a[i].col;
			sum[k].val=a[i].val+b[j].val;
			i++,j++,k++;
		}
		else if(a[i].row==b[j].row && a[i].col<b[j].col){
			sum[k].row=a[i].row;
			sum[k].col=a[i].col;
			sum[k].val=a[i].val;
			i++,k++;
		}
		else if(a[i].row==b[j].row && a[i].col>b[j].col){
			sum[k].row=b[j].row;
			sum[k].col=b[j].col;
			sum[k].val=b[j].val;
			j++,k++;
		}
		else if(a[i].row<b[j].row && a[i].col==b[j].col){
			sum[k].row=a[i].row;
			sum[k].col=a[i].col;
			sum[k].val=a[i].val;
			i++,k++;
		}
		else if(a[i].row>b[j].row && a[i].col==b[j].col){
			sum[k].row=b[j].row;
			sum[k].col=b[j].col;
			sum[k].val=b[j].val;
			j++,k++;
		}
	}
	//printf("HI\n");
	while(i<=t1)
	{
		sum[k].row=a[i].row;
		sum[k].col=a[i].col;
		sum[k].val=a[i].val;
		i++,k++;
	}
	while(j<=t2)
	{
		sum[k].row=b[j].row;
		sum[k].col=b[j].col;
		sum[k].val=b[j].val;
		j++,k++;
	}
	sum[0].val=k-1;
	printf("\nSummed ");
	polydisplay(sum);
}
void polynew(struct mat arr[])
{
	printf("Enter the number of non-zero terms in Matrix :");
	scanf("%f",&arr[0].val);
	printf("Enter the number of rows in Matrix :");
	scanf("%d",&arr[0].row);
	printf("Enter the number of columns in Matrix :");
	scanf("%d",&arr[0].col);
	printf("Enter elements of Sparse matrix:\n");
	for(int i=1;i<=arr[0].val;i++){
		printf("Enter the row index:");
		scanf("%d",&arr[i].row);
		printf("Enter the column index:");
		scanf("%d",&arr[i].col);
		printf("Enter the value:");
		scanf("%f",&arr[i].val);
	}
	polydisplay(arr);
}
void main()
{
	int choice;
	do
	{
		printf("Menu\n1.TRANSPOSE\n2.ADD\n3.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch (choice){
		case 1: {
				polynew(a);
				transpose();
				break;
			}
		case 2: {
				polynew(a);
				polynew(b);
				mat_add();
				break;
			}
		case 3: {printf("Thank you\n");break;}
		default:{printf("Wrong input please try again\n");} 	
		}
	}while(choice!=3);
}
