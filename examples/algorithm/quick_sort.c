#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_pos(int arry[], int left, int right)
{
    int pivot = arry[left];
    while (left < right) {
        if (arry[right] > pivot) {
            right--;
        }
 
        arry[left] = arry[right];

        if (arry[left] < pivot) {
            left++;
        }

        arry[right] = arry[left];
    }

    arry[left] = pivot;

    return left;
}

void quick_sort(int arry[], int left, int right)
{
    if (left >= right) {
        return;
    } else {
        int val = arry[left];
        int pos = find_pos(arry, left, right);
        arry[pos] = val;
        quick_sort(arry, left, pos-1);
        quick_sort(arry, pos+1, right);
    }
}

int main()
{
    int a[8] = {6, 5, 7, 8, 3, 4, 2, 1};
    quick_sort(a, 0, 7);
    for(int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

