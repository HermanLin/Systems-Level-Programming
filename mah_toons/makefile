all: main.o linked_list.o music_lib.o
	gcc -o ipod main.o linked_list.o music_lib.o

main.o: main.c
	gcc -c main.c
	
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

music_lib.o: music_lib.c music_lib.h
	gcc -c music_lib.c
	
clean: 
	rm *.o
	
run: all
	./ipod