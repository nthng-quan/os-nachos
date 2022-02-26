/**
 * @file sort.c
 * @brief Sort program
 * Perform a bubble sort on an array
 */
#include "syscall.h"

int main() {
    int n, a[101], i, j, choice, temp;
    do {
        PrintString("- Number of elements in array: ");
        n = ReadNum();
    } while (n < 0 || n > 100);

    for (i = 0; i < n; i++) {
        PrintString(". Enter a[");
        PrintNum(i);
        PrintString("]: ");
        a[i] = ReadNum();
    }

    do {
        PrintString("-----------------\n1. Increasing\n2: "
                    "Decreasing\n-----------------\n-> Your choice: ");
        choice = ReadNum();
        if (choice != 1 && choice != 2)
            PrintString("!!! Check your input {1,2}\n");
    } while (choice != 1 && choice != 2);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (choice == 1) {
                if (a[j] > a[j + 1]) {
                    //_swap(a[j], a[j+1]);
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            } else if (choice == 2) {
                if (a[j] < a[j + 1]) {
                    //_swap(a[j], a[j+1]);
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    PrintString("-> Sorted array:\n");
    for (i = 0; i < n; i++) {
        PrintNum(a[i]);
        PrintChar(' ');
    }
    PrintChar('\n');

    Halt();
}
