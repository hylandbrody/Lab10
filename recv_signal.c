/**
 * File: recv_signal
 * Modified by: Brody Hyland
 * 
 * Brief summary of program: Receives SIGUSR1 and 
 * prints the integer sent with it.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal, siginfo_t *info, void *context) {

    printf("\nReceived SIGUSR1!\n");
    printf("Received number: %d\n", info->si_value.sival_int);

}

int main(void) {

    struct sigaction action;

    // Set up the signal handler
    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    // Register SIGUSR1 handler
    sigaction(SIGUSR1, &action, NULL);

    printf("Waiting for a signal...\n");
    printf("Receiver PID: %d\n", getpid());

    // Wait for signals
    while (1) {
        pause();
    }

    return 0;
}