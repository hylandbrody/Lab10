/**
 * File: signal_sugaction.c
 * Modified by: Brody Hyland
 * 
 * Brief summary of program: This program uses sigaction to handle SIGUSR1
 * and print the PID of the sending process.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal, siginfo_t *info, void *context) {

    printf("Received SIGUSR1\n");
    printf("Sender PID: %d\n", info->si_pid);

}

int main() {

    struct sigaction action = {0};

    // Register the signal handler
    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    sigaction(SIGUSR1, &action, NULL);

    printf("Waiting for SIGUSR1...\n");
    printf("My PID is: %d\n", getpid());

    // Wait for signals
    while (1) {
        pause();
    }

    return 0;
}
