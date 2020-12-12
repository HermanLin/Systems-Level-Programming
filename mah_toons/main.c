#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"
#include "music_lib.h"

/*~~~~~~~~~
  main
  ~~~~~~~~~*/
int main() {
	
  //testing linked_list.c functions
	printf("\n\n=====testing linked_list.c functions=====\n");
	printf("testing insert_front():\n");
	struct song_node *node = create_node("Stargazing", "Kygo");
	print_list(node);
	printf("\ninserting 'Thunder, Imagine Dragons'...\n");
	struct song_node *tunes = insert_front(node, "Thunder", "Imagine Dragons");
	printf("printing song list tunes:\n");
	print_list(tunes);
	
	printf("\n\ntesting insert_order():\n");
	printf("inserting 'One More Weekend, MAX'...\n");
	printf("inserting 'Feel It Still, Portugal The Man'...\n");
	printf("inserting 'Pacific Coast Highway, MAX'...\n");
	insert_order(tunes, "One More Weekend", "MAX");
	insert_order(tunes, "Feel It Still", "Portugal The Man");
	insert_order(tunes, "Pacific Coast Highway", "MAX");
	printf("printing song list tunes:\n");
	print_list(tunes);
	
	printf("\n\ntesting find_node():\n");
	printf("finding 'Feel It Still, Portugal The Man'...\n");
	struct song_node *feels = find_node(tunes, "Feel It Still", "Portugal The Man");
	printf("Song Name: %s \tArtist: %s\n", feels->name, feels->artist);
	
	printf("\ntesting find_first_artist()\n");
	printf("finding first song for MAX...\n");
	struct song_node *macks = find_first_artist(tunes, "MAX");
	printf("First Song Name: %s", macks->name);
	
	printf("\n\ntesting find_random_node():\n");
	struct song_node *spook = find_random_node(tunes);
	struct song_node *spook2 = find_random_node(tunes);
	printf("Random Song: %s \tArtist: %s\n", spook->name, spook->artist);
	
	printf("\ntesting remove_node():\n");
	printf("before removal\n");
	print_list(tunes);
	printf("\nremoving 'Pacific Coast Highway, MAX'...\n");
	remove_node(tunes, "Pacific Coast Highway", "MAX");
	printf("after removal\n");
	print_list(tunes);
	
	printf("\n\ntesting free_list():\n");
	free_list(tunes);
	printf("\nprinting tunes after free_list()\n");
	print_list(tunes);
	
	//testing music_lib.c functions
	printf("\n\n=====testing music_lib.c functions=====\n");
	printf("testing add_song():\n");
	//printf("before adding...:\n");
	//print_lib();
	//printf("after adding...:\n");
	add_song("Thunder", "Imagine Dragons");
	//print_lib();
	add_song("One More Weekend", "MAX");
	add_song("Feel It Still", "Portugal The Man");
	add_song("Pacific Coast Highway", "MAX");
	add_song("Stargazing", "Kygo");
	//print_lib();
  
	printf("\n\ntesting find_song():\n");
	printf("finding 'Stargazing, Kygo'...\n");
	struct song_node *wowee = find_song("Stargazing", "Kygo");
	printf("Song Name: %s \tArtist: %s\n", wowee->name, wowee->artist);
	
	printf("\n\ntesting find_artist():\n");
	printf("finding first song for MAX...\n");
	struct song_node *mackz = find_artist("MAX");
	printf("First Song Name: %s", mackz->name);
	
	/*
	printf("\n\ntesting print_letter():\n");
	printf("printing 'm' library...\n");
	print_letter("m");
	*/
	/*
	printf("\n\ntesting print_artist():\n");
	printf("printing songs from MAX");
	print_artist("MAX");
	*/
	/*
	printf("\n\ntesting shuffle():\n");
	printf("before shuffle:\n");
	print_lib();
	printf("after shuffle:\n");
	shuffle();
	print_lib();
	*/
	/*
	printf("\n\ntesting delete_song():\n");
	printf("deleting 'One More Weekend, MAX'...\n");
	printf("before deletion:\n");
	print_lib();
	printf("after deletion:\n");
	delete_song("One More Weekend", "MAX");
	print_lib();
	*/
	/*
	printf("\n\ntesting delete_lib():\n");
	printf("before deleting library...\n");
	print_lib();
	printf("after deleting library...\n");
	delete_lib();
	print_lib();
	*/
	
	return 0;
}