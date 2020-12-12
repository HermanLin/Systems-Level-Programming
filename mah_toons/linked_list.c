#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linked_list.h"

int len_list (struct song_node *list) {
	int z = 0;
	while (list) {
		z++;
		list = list->next;
	}
	return z;
}

struct song_node * create_node (char *name, char *artist) {
	struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(new->name, name);
	strcpy(new->artist, artist);
	new->next = NULL;
	return new;
}

struct song_node * insert_front (struct song_node *front, char *name, char *artist) {
	struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
	strcpy(new->name, name);
	strcpy(new->artist, artist);
	new->next = front;
	return new;
}

int cmp_songs(struct song_node *a, struct song_node *b) {
	int diff = strncmp(a->artist, b->artist, sizeof(a->artist));
	if (diff) {
		return diff;
	} else {
		return strncmp(a->name, b->name, sizeof(a->name));
	}
}

int cmp_artists(struct song_node *a, struct song_node *b) {
	return strncmp(a->artist, b->artist, strlen(a->artist));
}

struct song_node * insert_order (struct song_node *front, char *name, char *artist) {
	struct song_node *new = create_node(name, artist);
	if (!front || cmp_songs(new, front) < 0) {
		return insert_front(front, name, artist);
	}
	while (front->next && cmp_songs(new, front->next) > 0) {
		front = front->next;
	}
	new->next = front->next;
	front->next = new;
	return new;
}

struct song_node * find_node(struct song_node *front, char *name, char *artist) {
	struct song_node *tmp = create_node(name, artist);
	while (front) {
		if (cmp_songs(front, tmp) == 0) {
			return front;
		}
		front = front->next;
	}
}

struct song_node * find_first_artist(struct song_node *front, char *artist) {
	struct song_node *tmp = create_node(artist, artist);
	while(front) {
		if (cmp_artists(front, tmp) == 0) {
			return front;
		}
		front = front->next;
	}
}

struct song_node * find_random_node(struct song_node *front) {
	srand(time(NULL));
	int rando = rand() % len_list(front);
	int i;
	for (i = 0; i < rando; i++) {
		front = front->next;
	}
	return front;
}

struct song_node * remove_node(struct song_node *front, char *name, char *artist) {
	struct song_node *node = find_node(front, name, artist);
	if (!node) {
		return front;
	}
	if (node == front) {
		struct song_node *tmp = front->next;
		front->next = 0;
		free(front);
		return tmp;
	}
	while (front->next && front->next != node) {
		front = front->next;
	}
	struct song_node *tmp2 = front->next;
	front->next = front->next->next;
	free(tmp2);
	return front;
}

struct song_node * free_list(struct song_node *list) {
	struct song_node *pointer = list;
	struct song_node *tmp;
	while (list->next) {
		tmp = list;
		list = list->next;
		printf("\nfreeing node: %s - %s", tmp->name, tmp->artist);
		free(tmp);
	}
	printf("\nfreeing node: %s - %s", list->name, list->artist);
	free(list);
	return pointer;
}

void print_list (struct song_node *list) {
	printf("\tSong List\n");
	while (list->next) {
		printf("%s : %s | ", list->name, list->artist);
		list = list->next;
	}
	printf("%s : %s | END", list->name, list->artist);
}