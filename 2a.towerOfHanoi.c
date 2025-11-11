//2 a.Use recursive program to implement Tower of Hanoi: 

#include <stdio.h>
#include <conio.h>

void tower(int n, char source, char dest, char temp);

void main() {
    int n;
    clrscr();
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower(n, 'S', 'D', 'T');
    getch();
}

//std
//tds
void tower(int n, char source, char dest, char temp) {
    if (n > 0) {
        tower(n - 1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        tower(n - 1, temp, dest, source);
    }
}
