//To implement paging memory allocation technique

#include<stdio.h>
#include<stdlib.h>
#define MAXT 100



void displaypagetable(int ptable[],int lsize)
{
       printf("\nPage table\n");
       for(int i=0;i<lsize;i++)
       {
                printf("Page no\tFrame No\n");
                printf("%d\t%d\n",i,ptable[i]);
       }
}

void displayframetable(int ftable[],int psize)
{
        printf("\nFrame table\n");
        for(int i=0;i<psize;i++)
       {
                printf("Page no\tFrame No\n");
                printf("%d\t%d\n",i,ftable[i]);
       }
}

void initialise(int a[],int size)
{
        for(int i=0;i<size;i++)
        {
                a[i] = -1;
        }
}

int main()
{
        int ptable[MAXT],ftable[MAXT],psize,lsize,size;
        printf("Enter the size of logical memory\n");
        scanf("%d",&lsize);
        printf("Enter the size of physical memory\n");
        scanf("%d",&psize);
        initialise(ptable,lsize);
        initialise(ftable,psize);
        for(int i=0;i<lsize;i++)
        {
                printf("Enter the Frame number where Page %d must be kept",i);
                scanf("%d",&ptable[i]);
        }
        for(int i=0;i<lsize;i++)
        {
                ftable[ptable[i]] = i;
        }
        displaypagetable(ptable,lsize);
        displayframetable(ftable,psize);
        return 0;
}
