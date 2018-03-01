           CC=gcc -x c

      CCFLAGS=-Wall -pedantic -Iinclude
      LDFLAGS=-lncursesw

         OBJS=build/layout.o \
			  build/assets.o \
			  build/settings.o \
			  build/tree.o \
			  build/tt.o


all: layout

layout: $(OBJS)
	g++ $(LDFLAGS) $^ -o $@

$(OBJS): build/%.o : src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf layout
	rm -rf build/*.o

.PHONY: clean
