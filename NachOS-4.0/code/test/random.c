/**
 * @file random.c
 * @brief Generate and print a random number
 */

#include "syscall.h"

int main() {
    int random;
    random = RandomNum();
    PrintNum(random);
    PrintChar('\n');

    Halt();
}
