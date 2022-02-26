/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"
#include "synchconsole.h"
#include <stdlib.h>

void SysHalt() { kernel->interrupt->Halt(); }

int SysAdd(int op1, int op2) { return op1 + op2; }

char SysReadChar() { return kernel->synchConsoleIn->GetChar(); }

void SysPrintChar(char character) {
    kernel->synchConsoleOut->PutChar(character);
}

int SysRandomNum() { return random(); }

char *SysReadString(int length) {
    char *buffer = new char[length + 1];
    for (int i = 0; i < length; i++) {
        buffer[i] = SysReadChar();
    }
    buffer[length] = '\0';
    return buffer;
}

void SysPrintString(char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        kernel->synchConsoleOut->PutChar(buffer[i]);
    }
}

int SysReadNum() {
    // string INT32_MAX = "2147483647", INT32_MIN = "-2147483648";
    int n = 0, num = 0, c_zeros = 0;
    char c, num_buffer[255];
    do {
        c = kernel->synchConsoleIn->GetChar(); // Read each character.
        if (c == ' ' || c == '\n' || c == '\0')
            break;
        num_buffer[n++] = c;
    } while (true);

    if (n > 11)
        return 0;
    else if (n == 10) {
        for (int i = 0; i < 10; i++)
            if (num_buffer[i] > "2147483647"[i]) {
                return 0;
            }
    } else if (n == 11) {
        for (int i = 1; i < 11; i++)
            if (num_buffer[i] > "-2147483648"[i]) {
                return 0;
            }
    }

    bool negative = false, zero_lead = true;
    if (num_buffer[0] == '-') {
        negative = true;
    }
    for (int i = negative; i < n; i++) {
        if (num_buffer[i] == '0' && zero_lead == true)
            c_zeros++;
        else
            zero_lead = false;
        if (num_buffer[i] < '0' || num_buffer[i] > '9') {
            return 0;
        } else
            num = num * 10 + (num_buffer[i] - '0');
    }
    if (c_zeros > 0) // Avoid case: 002,01,-05,..etc
    {
        return 0;
    }
    if (negative)
        num = -num;
    return num;
}

void SysPrintNum(int num) {
    // string INT32_MAX = "2147483647", INT32_MIN = "-2147483648";
    if (num == 0)
        return kernel->synchConsoleOut->PutChar('0');
    if (num < 0) {
        kernel->synchConsoleOut->PutChar('-');
        num = -num;
    }
    if (num == 2147483647) {
        for (int i = 0; i < 10; i++) {
            kernel->synchConsoleOut->PutChar("2147483647"[i]);
        }
        return;
    }
    if (num == 2147483648) {
        for (int i = 1; i < 11; i++) {
            kernel->synchConsoleOut->PutChar("-2147483648"[i]);
        }
        return;
    }

    char number_buffer[255];
    int n = 0;
    while (num) {
        number_buffer[n++] = num % 10;
        num /= 10;
    }
    for (int i = n - 1; i >= 0; i--) {
        kernel->synchConsoleOut->PutChar(number_buffer[i] + '0');
    }
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
