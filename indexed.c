// To implement Indexed File Allocation method
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

int count = -1;

struct indexed
{
    int start;
    int path[MAX_SIZE];
    int size;
} ind[MAX_SIZE];

void enterfile(int storage[])
{
    int indblc, size, temp[MAX_SIZE];
    printf("Enter the index block\n");
    scanf("%d", &indblc);
    if (storage[indblc] == 1)
    {
        printf("Cannot be allocated\n");
        return;
    }
    storage[indblc] = 1;
    ind[++count].start = indblc;
    printf("Enter the size\n");
    scanf("%d", &size);
    ind[count].size = size;
    printf("Enter the blocks\n");
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &temp[i]);
        if (storage[temp[i]] == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Cannot be allocated\n");
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            storage[temp[i]] = 1;
            ind[count].path[i] = temp[i];
        }
    }
}

void deletefile(int storage[])
{
    int del, pos;
    printf("Enter the index block to be deleted\n");
    scanf("%d", &del);
    int flag = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (ind[i].start == del)
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        storage[del] = 0;
        for (int i = 0; i < ind[pos].size; i++)
        {
            storage[ind[pos].path[i]] = 0;
        }
        printf("Index blocks starting with %d deleted\n", del);
    }
    else
    {
        printf("Didn't find index block\n");
    }
}
int main()
{
    int storage[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        storage[i] = 0;
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
            enterfile(storage);
            break;
        case 2:
            deletefile(storage);
            break;
        case 3:
            exit(0);
        case 4:
            for (int i = 0; i < 40; i++)
            {
                printf("%d\t", storage[i]);
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