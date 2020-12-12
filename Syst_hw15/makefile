all: client control

client: client.c header.h
	gcc -o client client.c

control: semmy.c header.h
	gcc -o control semmy.c

clean:
	rm client
	rm control

