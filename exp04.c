#include <stdio.h>

void tower(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }


    tower(n - 1, source, auxiliary, destination);

    
    printf("Move disk %d from %c to %c\n", n, source, destination);

    
    tower(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower(n, 'A', 'C', 'B');  

    return 0;
}