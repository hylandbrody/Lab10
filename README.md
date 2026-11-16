## Lab Week 10 - Signals

## Description

This lab focuses on working with signals in C. It demonstrates how to create signal handlers, handle different signals, and send information between processes.

## Files

signal_handler.c - Creates a handler for SIGINT.

signal_alarm.c - Uses SIGALRM to trigger a message after 5 seconds.

signal_segfault.c - Handles a segmentation fault using SIGSEGV.

signal_sigaction.c - Uses sigaction to handle SIGUSR1 and display the sender's PID.

recv_signal.c - Receives SIGUSR1 with an integer value.

send_signal.c - Sends SIGUSR1 with a random integer to another process.

Compilation

Compile each program using gcc:

gcc -o handler signal_handler.c
gcc -o alarm signal_alarm.c
gcc -o seg signal_segfault.c
gcc -o sig signal_sigaction.c
gcc -o recv recv_signal.c
gcc -o send send_signal.c