#include <stdio.h>
#define MAX_SIZE 30

int main(){
    int nRequests, nFrames, requests[MAX_SIZE], frames[MAX_SIZE];

    printf("Enter the number of requests : ");
    scanf("%d", &nRequests);

    printf("Enter the requests : ");
    for (int i = 0; i < nRequests; i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the frame size : ");
    scanf("%d", &nFrames);

    for (int i = 0; i < nFrames; i++)
    {
        frames[i] = -1;
    }
    

    int flagHit = 0, old = 0;

    for (int i = 0; i < nRequests; i++)
    {
        flagHit = 0;
        for (int j = 0; j < nFrames; j++)
        {
            if (requests[i] == frames[j])
            {
                flagHit = 1;
                break;
            }
        }
        if (!flagHit)
        {
            frames[old] = requests[i];
            old = (old + 1) % nFrames;
            printf("%d\t| ", requests[i]);
            for (int k = 0; k < nFrames; k++)
            {
                printf(" %d\t|", frames[k]);
            }
            printf("Fault\t|\n");
        }else
        {
            printf("%d\t| ", requests[i]);
            for (int k = 0; k < nFrames; k++)
            {
                printf(" %d\t|", frames[k]);
            }
            printf("Hit\t|\n");
        }
    }
    return 0;
}