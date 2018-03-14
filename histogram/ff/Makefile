all: calibration rdtsc
calibration: calibration.c ../cacheutils.h
	gcc -std=gnu11 -O3 -o $@ $@.c

rdtsc: rdtsc.c ../cacheutils.h
	gcc -std=gnu11 -O3 -o $@ $@.c
