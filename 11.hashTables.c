//11. Implement Hash Tables:
#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[50], hash[10], n, i, key;

    clrscr();

    for(i = 0; i < 10; i++)
        hash[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nHashing...\n");
    for(i = 0; i < n; i++)
    {
        key = arr[i] % 10;
        hash[key] = arr[i];
        printf("Location: hash[%d] = %d\n", key, arr[i]);
    }

    printf("\nHash Table:\n");
    for(i = 0; i < 10; i++)
        printf("%d ", hash[i]);

    getch();
}
