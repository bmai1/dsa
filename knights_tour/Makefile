CC = g++
CFLAGS = -std=c++20

all: knights_tour.out warnsdorff.out

knights_tour.out: knights_tour.cpp
	$(CC) $(CFLAGS) $< -o $@

rkt: knights_tour.out
	./knights_tour.out

warnsdorff.out: warnsdorff.cpp
	$(CC) $(CFLAGS) $< -o $@

rwd: warnsdorff.out
	./warnsdorff.out