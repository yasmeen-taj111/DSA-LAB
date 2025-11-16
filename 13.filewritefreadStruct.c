// 13. Write all the members of an array of structures to a file using fwrite(). Read the array from file
and display on the screen.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student {
    int regno;
    char name[20];
};

void main() {
    struct student s[20], temp;
    FILE *fp;
    int i, n;

    clrscr();

    printf("Enter number of students: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Register No: ");
        scanf("%d", &s[i].regno);
    }

    fp = fopen("student.dat", "wb");
    if(fp == NULL) {
        printf("File write error!");
        getch();
        exit(0);
    }
    fwrite(s, sizeof(struct student), n, fp);
    fclose(fp);


    fp = fopen("student.dat", "rb");
    if(fp == NULL) {
        printf("File read error!");
        getch();
        exit(0);
    }

    clrscr();
    printf("----- Data Retrieved From File -----\n");
    while(fread(&temp, sizeof(struct student), 1, fp)) {
        printf("Name     : %s\n", temp.name);
        printf("Register : %d\n\n", temp.regno);
    }
    fclose(fp);

    getch();
}
