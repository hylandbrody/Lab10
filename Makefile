CC = gcc
CFLAGS = -Wall -Wextra

all: signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

signal_handler: signal_handler.c
	$(CC) $(CFLAGS) -o signal_handler signal_handler.c

signal_alarm: signal_alarm.c
	$(CC) $(CFLAGS) -o signal_alarm signal_alarm.c

signal_segfault: signal_segfault.c
	$(CC) $(CFLAGS) -o signal_segfault signal_segfault.c

signal_sigaction: signal_sigaction.c
	$(CC) $(CFLAGS) -o signal_sigaction signal_sigaction.c

recv_signal: recv_signal.c
	$(CC) $(CFLAGS) -o recv_signal recv_signal.c

send_signal: send_signal.c
	$(CC) $(CFLAGS) -o send_signal send_signal.c

clean:
	rm -f signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal