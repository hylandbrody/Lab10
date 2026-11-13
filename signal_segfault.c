/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Brody Hyland
 * 
 * Brief summary of modifications: Added a signal handler for SIGSEGV that prints a message.
 */


#include <stdio.h>
#include <stdio.h>
#include <signal.h>

void handle_segfault(int signal) {
    printf("Received segmentation fault\n");
}

int main (int argc, char* argv[]) {
    signal(SIGSEGV, handle_segfault);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}