struct song_node * table[26];

void add_song(char *name, char *artist);
struct song_node * find_song( char *name,  char *artist);
struct song_node * find_artist(char *artist);
void print_letter(char letter);
void print_artist(char *artist);
void shuffle();
void delete_song(char *name, char *artist);
void delete_lib();
void print_lib();