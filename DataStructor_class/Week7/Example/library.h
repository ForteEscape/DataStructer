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
	char* path;
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

void add_song(char* artist, char* title, char* path);
void status();
void initialize();
void load(FILE* fp);
void search_song(char* artist, char* title);
void search_song(char* artist);
void play(int index);
void save(FILE* fp);
void remove(int index);

#endif // !LIBRARY_H

