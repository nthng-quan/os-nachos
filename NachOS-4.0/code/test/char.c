/**
 * @file char_io.c
 * @brief Test PrintChar, ReadChar
 * Read a character and print it
 */
#include "syscall.h"

int main()
{
	PrintChar(ReadChar());
	PrintChar('\n');
	Halt();
}