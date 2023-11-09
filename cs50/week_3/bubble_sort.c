// 冒泡排序
#include <stdio.h>

void bubblesort(int array[], int size);

int main() {
    int array[] = {55, 68, 99, 45, 34, 22, 61, 71};
    int size = sizeof(array) / sizeof(array[0]);

    bubblesort(array, size);

    printf("排序后的数组：");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void bubblesort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
