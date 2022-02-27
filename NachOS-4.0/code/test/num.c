/**
 * @file num.c
 * @brief Test system call ReadNum
 * Read an integer from user input and print it
 */

#include "syscall.h"

int main()
{
	int num;

	// Read input from user
	PrintString("- Insert one number: ");
	num = ReadNum();

	// Print out number
	PrintString("-> ");
	PrintNum(num);
	PrintString("\n");

	// Halt system
	Halt();
}