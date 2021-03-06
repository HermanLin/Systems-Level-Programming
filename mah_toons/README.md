# Project 0 | My tunez

Task: Write a program in C that implements a music library organizer. The data structure should consist of an array of 26 slots, one for each letter from 'a' to 'z' (you can convert everything to lower case to make comparisons easier). Each slot will contain a linked list of all the artists that have names with the corresponding letter. When you add a song, it should go on to a linked list at the appropriate array slot in the correct position alphabetically. Assume no duplicates.

Your nodes/links should be able to hold a song's title and artist. You might use structures like the following:
```
struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};


//and later:

struct song_node * table[26];
```

You should start by making your linked lists work with the following functionality:
- insert nodes at the front
- insert nodes in order
- print the entire list
- find and return a pointer to a node based on artist and song name
- find and return a pointer to the first song of an artist based on artist name
- Return a pointer to random element in the list.
- remove a single specified node from the list
- free the entire list

Then create your array of linked lists for the full program and have the following functions:
- Add songs.
- Search for a song given song and artist name.
- Search for a song given the song name
- Search for an artist.
- Print out all the entries under a certain letter.
- Print out all the songs of a certain artist
- Print out the entire library.
- Shuffle - print out a series of randomly chosen songs.
- Delete a song
- Delete all the nodes.

Files you should have:
- A .c file that contains the main function you use to test all your work
- At least one set of .h/.c files
  - For example, you can put your struct definition and your linked list headers in a .h file
  - You may also want to set up a .h/.c set for the playlist specific functions and a separate set for the linked list functions.
- A makefile that will compile all the parts of your code and generate a single executable program

Git clone link:
https://github.com/mks65/my_tunez.git

You must test all the functions in your main function in order to receive full credit!!!
