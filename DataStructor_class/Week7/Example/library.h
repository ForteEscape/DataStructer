#ifndef LIBRARY_H
#define LIBRARY_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;

struct song {
    Artist* artist;
	char* title;
	char* name;
	int index;
};

struct snode { // snode is double linked likst
	struct snode* next;
	struct snode* prev;
	Song* song;
};

struct artist {
	char* name;
	struct artist* next; // artist is single linked list

	SNode* head;
	SNode* tail;
};

void initialize();
void add_song(char* artist, char* title, char* path);
Song* create_song_instance(Artist* ptr_artist, char* title, char* path)

#endif // !LIBRARY_H

