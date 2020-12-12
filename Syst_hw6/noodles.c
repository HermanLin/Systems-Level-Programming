#include <stdio.h>
#include <stdlib.h>

struct node {
	int z; 
	struct node *next;
};

void print_list(struct node *);
struct node * insert_front(struct node *, int ins);
struct node * free_list(struct node *);

int main() {
	//make a new node with a NULL next
	struct node * ramen = (struct node *)malloc(sizeof(struct node));
	ramen -> z = 0;
	ramen -> next = NULL;
	
	//print out list before adding noodles
	printf("\nprinting ramen before adding noodles:\n");
	print_list(ramen);
	printf("\n");
	
	//add noodles to the ramen
	ramen = insert_front(ramen, 1);
	ramen = insert_front(ramen, 2);
	ramen = insert_front(ramen, 4);
	ramen = insert_front(ramen, 8);
	
	//print out list
	printf("\nprinting ramen after adding noodles:\n");
	print_list(ramen);
	printf("\n");
	
	//testing free_list
	printf("\nbefore free_list: \t%p\n", ramen);
	free_list(ramen);
	printf("after free_list: \t%p\n", ramen);
	
	return 0;
}

void print_list(struct node *front) {
	printf("head->");
	while (front -> next) {
		printf("%d->", front -> z);
		front = front -> next;
	}
	printf("%d->", front -> z);
	printf("tail");
}

struct node * insert_front(struct node *front, int ins) {
	struct node * new = (struct node *)malloc(sizeof(struct node));
	new -> z = ins;
	new -> next = front;
	return new;
}

struct node * free_list(struct node *front) {
	struct node *bowl = front;
	struct node *packet;
	
	while (front -> next) {
		packet = front;
		front = front -> next;
		free(packet);
	}
	free(front);
	return bowl;
}