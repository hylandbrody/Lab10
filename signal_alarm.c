/**
 * File: signal_alarm.c
 * Modified by: Brody Hyland
 * 
 * Brief summary of program:This program schedules an alarm for 5 seconds.
 *      It prints a message when SIGALRM is received.
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int signal) {
    printf("Alarm received!\n");
}

int main() {

    // Register the signal handler
    signal(SIGALRM, handle_alarm);

    printf("Waiting for alarm...\n");

    // Schedule alarm for 5 seconds
    alarm(5);

    // Wait for the alarm
    while (1) {
        pause();
    }

    return 0;
}