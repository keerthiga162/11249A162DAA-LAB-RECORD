#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int a[], int begin, int n, int key) {
    if (begin >= n) {
        return -1; 
    }
    if (a[begin] == key) {
        return begin; 
    }
    return linearSearch(a, begin + 1, n, key);
}

int main() {
    int a[10000], n = 10000, key, i, pos;
    clock_t start, end;
    double time_taken;

    for (i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }

    key = rand() % 10000;


    start = clock();

    pos = linearSearch(a, 0, n, key);


    end = clock();

    
    if (pos == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at position %d\n", pos + 1);
    }

    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time taken: %f seconds\n", time_taken);

    return 0;
}