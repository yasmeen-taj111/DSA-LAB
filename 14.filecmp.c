// 14. Compare the contents of two files. Write the difference in another file.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    FILE *f1, *f2, *f3;
    char ch1, ch2, ch3;
    char str1[100], str2[100];
    clrscr();


    f1 = fopen("file1.txt", "w");
    f2 = fopen("file2.txt", "w");

    if (f1 == NULL || f2 == NULL) {
        printf("Error opening file!");
        getch();
        exit(0);
    }

    printf("Enter content for file1:\n");
    gets(str1);
    printf("Enter content for file2:\n");
    gets(str2);

    fprintf(f1, "%s", str1);
    fprintf(f2, "%s", str2);

    fclose(f1);
    fclose(f2);


    f1 = fopen("file1.txt", "r");
    f2 = fopen("file2.txt", "r");
    f3 = fopen("file3.txt", "w");

    while ((ch1 = getc(f1)) != EOF && (ch2 = getc(f2)) != EOF)
        if (ch1 != ch2)
            fputc(ch2, f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f3 = fopen("file3.txt", "r");
    ch3 = getc(f3);

    if (ch3 == EOF)
        printf("\nNo differences found");
    else {
        printf("\nDifferences are:\n");
        while (ch3 != EOF) {
            printf("%c", ch3);
            ch3 = getc(f3);
        }
    }
    fclose(f3);
    getch();
}
