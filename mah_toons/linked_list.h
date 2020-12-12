struct song_node {
  char name[256];
  char artist[256];
  struct song_node * next;
};

struct song_node * create_node (char *name, char *artist);
struct song_node * insert_front(struct song_node *front, char *name, char *artist);
struct song_node * insert_order(struct song_node *front, char *name, char *artist);
void print_list(struct song_node *node);
struct song_node * find_node(struct song_node *front, char *name, char *artist);
struct song_node * find_first_artist(struct song_node *front, char *artist);
struct song_node * find_random_node(struct song_node *front);
struct song_node * remove_node(struct song_node *list, char *name, char *artist);
struct song_node * free_list(struct song_node *list);
int cmp_songs(struct song_node *a, struct song_node *b);
int cmp_artists(struct song_node *a, struct song_node *b);