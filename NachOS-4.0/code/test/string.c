/**
 * @file str.c
 * @brief Test ReadString
 * Read a string and print it
 */
#include "syscall.h"
char string[256];
int main()
{
	int convert_length;
	PrintString("- Desired string length to read: (<= 255):\n");
	convert_length = ReadNum();
	PrintString("- Insert string:\n");
	ReadString(string, convert_length);

	PrintString("-> ");
	PrintString(string);
	PrintChar('\n');

	Halt();
}