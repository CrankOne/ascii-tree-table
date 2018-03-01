CFLAGS=-Wall
LDFLAGS=-lncursesw

all: layout

layout: layout.o assets.o
	g++ $(LDFLAGS) $^ -o $@

layout.o: layout.c
	g++ $(CFLAGS) -c $< -o $@

assets.o: assets.c assets.h
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf layout
	rm -rf *.o
