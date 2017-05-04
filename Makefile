#!/usr/bin/env make

################
# tool locations
################
#
SHELL= /bin/bash
CC= gcc
CFLAGS=

all: samp-timestamp.c
		$(CC) $(CFLAGS) samp-timestamp.c -o samp-timestamp

install: all
		@echo are you kidding'??'

clean:
		rm samp-timestamp