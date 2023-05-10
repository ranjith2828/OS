#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
   
    int allocate[processes];
    
    
    for(int i = 0; i < processes; i++)
    {
		allocate[i] = -1;
    }
	
    
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i])
            {
                
                allocate[i] = j;
 
               
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blockSize[100];
    int processSize[100];
    
    int m,i;
    int n;
    printf("Enter the size of blocks:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
    	printf("Enter the block %d:",i+1);
    	scanf("%d",&blockSize[i]);
	}
	printf("Enter the size of arriving blocks:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("Enter the block arriving %d:",i+1);
    	scanf("%d",&processSize[i]);
	}
    implimentFirstFit(blockSize, m, processSize, n);
    return 0;
}
