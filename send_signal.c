/**
 * File: send_signal
 * Modified by: Brody Hyland
 * 
 * Brief summary of program: Sends SIGUSR1 with a random 
 * integer to another process.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Check for PID argument
    if (argc != 2) {
        printf("Usage: ./send_signal PID\n");
        return 1;
    }

    // Convert PID argument to an integer
    pid_t pid = atoi(argv[1]);

    // Seed random number generator
    srand(time(NULL));

    // Generate random number
    union sigval value;
    value.sival_int = rand() % 100 + 1;

    printf("Sending number: %d\n", value.sival_int);

    // Send SIGUSR1 with the random number
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    printf("Signal sent successfully!\n");

    return 0;
}    