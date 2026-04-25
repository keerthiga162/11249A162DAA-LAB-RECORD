#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void perm(int arr[], int start, int end) {
    int i;

    if (start == end) {
        for (i = 0; i < end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (i = start; i < end; i++) {
    
        swap(&arr[start], &arr[i]);

    
        perm(arr, start + 1, end);

        
        swap(&arr[start], &arr[i]);
    }
}

int main() {
    int n, i;
    int a[10];

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nPermutations are:\n");
    perm(a, 0, n);

    return 0;
}