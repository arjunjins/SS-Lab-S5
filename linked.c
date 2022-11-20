// To implement Linked File Allocation method
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

struct linked
{
    int start;
    int next;
    int storage;
} linked[MAX_SIZE];

void enterfile()
{
    int start = 0;
    printf("Enter the starting block\n");
    scanf("%d", &start);
    if (linked[start].start == 1)
    {
        printf("Block is not free\n");
        return;
    }
    else
    {
        linked[start].start = 1;
        linked[start].storage = 1;
        int prev = start;
        printf("Enter the path (-1 as last element)\n");
        int ch = 0;
        while (ch != -1)
        {
            scanf("%d", &ch);

            if (ch == -1)
            {
                linked[prev].next = ch;
                break;
            }
            linked[prev].next = ch;
            if (linked[ch].storage != 0)
            {
                printf("Block not free\nEnter new path\n");
                continue;
            }
            else
            {

                linked[ch].storage = 1;
                prev = ch;
            }
        }
    }
}

void deletefile()
{
    int start;
    printf("Enter the starting block\n");
    scanf("%d", &start);
    if (linked[start].start != 1)
    {
        printf("Block is not the starting of any file\n");
        return;
    }
    else
    {
        linked[start].start = 0;
        linked[start].storage = 0;
        int pos = linked[start].next;
        linked[start].next = 0;
        do
        {
            linked[pos].storage = 0;
            int temp = pos;
            pos = linked[pos].next;
            linked[temp].next = 0;
        } while (pos != -1);
    }
}
int main()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        linked[i].storage = 0;
        linked[i].start = 0;
        linked[i].next = 0;
    }
    char ch;
    do
    {
        int chh;
        printf("1. Enter a new file\n2. Delete existing file\n3. Exit\n4. Print storage\n");
        scanf("%d", &chh);
        switch (chh)
        {
        case 1:
            enterfile();
            break;
        case 2:
            deletefile();
            break;
        case 3:
            exit(0);
        case 4:
            for (int i = 0; i < 40; i++)
            {
                printf("%d\nnext is %d\n\n", linked[i].storage, linked[i].next);
            }

            break;
        default:
            printf("Entered choice is invalid\n");
            break;
        }
        getchar();
        printf("Do you want to continue? y/n\n");
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}