menu: DDword.o digits_in_words.o input.o num.o sort.o main.o
	gcc main.o DDword.o digits_in_words.o input.o num.o sort.o -o menu
main.o: main.c DDword.h digits_in_words.h input.h num.h sort.h
	gcc -c main.c
input: input.c input.h sort.h
	gcc -c input.c
DDword.o: DDword.c DDword.h input.h
	gcc -c DDword.c
digits_in_words.o: digits_in_words.c digits_in_words.h
	gcc -c digits_in_words.c
num.o: num.c num.h
	gcc -c num.c
sort.o: sort.c sort.h
	gcc -c sort.c
clean:
	rm -rf *.o main
