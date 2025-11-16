// 12. Implement Hashing using open addressing:
#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], hash[10], n, i, index, pos;

    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

   
    for(i = 0; i < 10; i++)
        hash[i] = -1;


    for(i = 0; i < n; i++)
    {
        index = a[i] % 10;
        pos = index;

        while(hash[pos] != -1)
        {
            pos = (pos + 1) % 10; 
        }

        hash[pos] = a[i];
        printf("Stored %d at hash[%d]\n", a[i], pos);
    }

  
    printf("\nHash Table (Open Addressing):\n");
    for(i = 0; i < 10; i++)
    {
        if(hash[i] != -1)
            printf("%d ", hash[i]);
        else
            printf("- ");
    }

    getch();
}
