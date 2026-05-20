#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int main(){
    int nRequests, initHead;
    int requests[30];

    printf("FCFS Disk scheduling\n");

    printf("Enter the number of requests : ");
    scanf("%d", &nRequests);

    printf("Enter requests : ");
    for (int i = 0; i < nRequests; i++)
    {
        scanf("%d", &requests[i]);
    }printf("\n");
    
    printf("Enter the initial head : ");
    scanf("%d", &initHead);

    printf("Step\t| From\t| To\t| Step\t|\n");
    printf("1\t| %d\t| %d\t| %d\t|\n", initHead, requests[0], abs(initHead - requests[0]));

    for (int i = 1; i < nRequests; i++)
    {
        printf("%d\t| %d\t| %d\t| %d\t|\n",i+1,requests[i - 1],requests[i],abs(requests[i] - requests[i - 1]));
    }return 0;
}