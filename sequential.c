// To implement Sequential File Allocation method
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

void allocatemem(int storage[], int start, int size)
{
    for (int i = start; i < size + start; i++)
    {
        storage[i] = 1;
    }
    printf("Block allocated\n");
}
void enterfile(int storage[])
{
    int start, size;
    int flag = 0;
    printf("Enter the starting block\n");
    scanf("%d", &start);
    printf("Enter the size of the file\n");
    scanf("%d", &size);
    if (size + start > MAX_SIZE)
    {
        printf("Block limit exceeded!\n");
        return;
    }
    flag = 0;
    for (int i = start; i < size + start; i++)
    {
        if (storage[i] == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Contiguous blocks cannot be allocated\n");
    }
    else
    {
        allocatemem(storage, start, size);
    }
}

void deletefile(int storage[])
{
    int start;
    printf("Enter the starting block of the file to be deleted\n");
    scanf("%d", &start);
    for (int i = start; storage[i] != 0; i++)
    {
        storage[i] = 0;
    }
    printf("File deleted\n");
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