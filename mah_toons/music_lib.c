#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "music_lib.h"
#include "linked_list.h"

void add_song(char *name, char *artist) {
	int x = strncmp(artist, "a", 1);
	table[x] = insert_order(table[x], name, artist);
}

struct song_node * find_song( char *name,  char *artist) {
	int x = strncmp(artist, "a", 1);
	return find_node(table[x], name, artist);
}

struct song_node * find_artist(char *artist) {
	int x = strncmp(artist, "a", 1);
	return find_first_artist(table[x], artist);
}

void print_letter(char letter) {
	int x = letter - 97;
	printf("%c list\n", letter);
	print_list(table[x]);
}

void print_artist(char *artist) {
	struct song_node *front = find_artist(artist);
	printf("\tSongs by: %s\n", artist);
	while (front && !strncmp(front->artist, artist, sizeof(artist))) {
		printf("%s | ", front->name);
	}
}

void shuffle() {
	srand(time(NULL));
	int z;
	for (z = 0; z < 26; z++) {
		struct song_node *scramble = find_random_node(table[z]);
		printf("%s : %s | ", scramble->name, scramble->artist);
	}
}

void delete_song(char *name, char *artist) {
	table[artist[0] - 97] = remove_node(table[artist[0] - 97], name, artist);
}

void delete_lib() {
	int z;
	for (z = 0; z < 26; z++) {
		table[z] = free_list(table[z]);
	}
}

void print_lib() {
	int z;
	for (z = 0; z < 26; z++) {
		
		if (table[z]) {
			printf("%c list\n", 'a' + z);
			print_list(table[z]);
		} 
	}
}