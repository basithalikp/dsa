#include <stdio.h>
#include <stdlib.h>
struct poly
{
	float coeff;
	int exp;
}p[100],q[100],sum[100];
int np,nq;
void polydisplay(struct poly arr[]);
void poly_add()
{
	int i=0,j=0,k=0;
	while(i<=np && j<=nq)
	{

		if(p[i].exp>q[j].exp){
			sum[k].coeff=p[i].coeff;
			sum[k].exp=p[i].exp;
			i++;
		}
		else if(p[i].exp<q[j].exp){
			sum[k].coeff=q[j].coeff;
			sum[k].exp=q[j].exp;
			j++;
		}
		else if(p[i].exp==q[j].exp){
			sum[k].coeff=p[i].coeff+q[j].coeff;
			sum[k].exp=p[i].exp;
			i++,j++;
		}
		k++;
	}
	while(i<=np)
	{
		sum[k].coeff=p[i].coeff;
		sum[k].exp=p[i].exp;
		i++,k++;
	}
	while(j<=nq)
	{
		
		sum[k].coeff=q[j].coeff;
		sum[k].exp=q[j].exp;
		j++,k++;
	}
	printf("\nSummed ");
	polydisplay(sum);
}
void polydisplay(struct poly arr[]){
	printf("Resultant Polynomial is:\n");
	for(int i=0;arr[i].coeff!='\0';i++)
	{
		printf("%.1fX^%d+",arr[i].coeff,arr[i].exp);
	}
	printf("\b\b\n");
}
void main()
{
	printf("Enter the number of terms in Polynomial P:");
	scanf("%d",&np);
	printf("Enter the number of terms in Polynomial Q:");
	scanf("%d",&nq);
	printf("Enter elements of P:\n");
	for(int i=0;i<np;i++){
		printf("Enter the Coefficient:");
		scanf("%f",&p[i].coeff);
		printf("Enter the exponent:");
		scanf("%d",&p[i].exp);
	}
	polydisplay(p);
	printf("Enter elements of Q:\n");
	for(int j=0;j<nq;j++){
		printf("Enter the Coefficient:");
		scanf("%f",&q[j].coeff);
		printf("Enter the exponent:");
		scanf("%d",&q[j].exp);
	}
	polydisplay(q);
	poly_add();
}
