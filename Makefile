exec = ysharp.out # if linux make ysharp.exe -> ysharp.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

libysharp.a: $(objects)
	ar rcs $@ $^

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./ysharp.out /usr/local/bin/ysharp # don't worry it's for linux



clean:
	-rm *.out # if linux make .exe -> .out
	-rm *.o
	-rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h
