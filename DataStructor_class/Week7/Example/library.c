#include "library.h"
#define NUM_CHARS 256 // 1byte size can express 256 character

Artist* artist_directory[NUM_CHARS];

void initialize() {
	for (int i = 0; i < NUM_CHARS; i++) {
		artist_directory[i] = NULL;
	}
}

void add_song(char* artist, char* title, char* path) {
	Artist* ptr_artist = find_artist(artist);

	if (ptr_artist == NULL) {

	}
}

Artist* find_artist(char* artist_name) {
	Artist* p = artist_directory[(unsigned char)artist_name[0]];

	while (p != NULL && strcmp(p->name, artist_name) < 0) {
		p = p->next;
	}

	if (p != NULL && strcmp(p->name, artist_name) == 0) {
		return p;
	}
	else {
		return NULL;
	}
}