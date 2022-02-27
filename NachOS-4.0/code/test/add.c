/**
 * @file add.c
 * @brief Test system call Add
 * Add two vals and returns result
 */

#include "syscall.h"

int main()
{
	int result;

	result = Add(42, 23);
	PrintNum(result);
	PrintChar('\n');

	Halt();
	/* not reached */
}