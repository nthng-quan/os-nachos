/**
 * @file help.c
 * @brief Basic information of project
 */
#include "syscall.h"

int main()
{
	PrintString("* NACHOS - 20CLC05 - Project 1 - Operating System *\n");

	PrintString(
		"-----------------------------------------------------------\n");
	PrintString("* MEMBERS:\n");
	PrintString("20127088 - Nguyen Thien Hoang Tri\n");
	PrintString("20127416 - Pham Anh Tuyen\n");
	PrintString("20127603 - Ninh Tran Hoang Quan\n");
	PrintString(
		"-----------------------------------------------------------\n");

	PrintString("- About the programs that is installed inside Nachos:\n");
	PrintString("- run ./build.linux/nachos -x ./test/{program_name}\n");
	PrintString(
		"-----------------------------------------------------------\n");

	PrintString("- ASCII (ascii): print the ASCII table\n");
	PrintString("- Sort (sort): perform a bubblesort on given array both "
		    "increasingly and decreasingly\n");

	Halt();
}
