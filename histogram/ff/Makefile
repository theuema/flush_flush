all: calibration rdtsc
calibration: calibration.c ../cacheutils.h
	gcc -std=gnu11 -O3 -g -o $@ $@.c

rdtsc: rdtsc.c ../cacheutils.h
	gcc -std=gnu11 -O3 -g -o $@ $@.c
