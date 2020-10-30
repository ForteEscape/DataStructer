#include "library.h"
#define NUM_CHARS 256 // 1byte size can express 256 character

Artist* artist_directory[NUM_CHARS];
int num_index = 0;

void initialize() {
	for (int i = 0; i < NUM_CHARS; i++) {
		artist_directory[i] = NULL;
	}
}

Song* create_song_instance(Artist* ptr_artist, char* title, char* path){
    Song* ptr_song = (Song*)malloc(sizeof(Song));
    ptr_song->artist = ptr_artist;
    ptr_song->title = title;
    ptr_song->path = path;
    ptr_song->index = num_index;
    
    num_index++;
    
    return ptr_song;
}

void add_song(char* artist, char* title, char* path) {
	Artist* ptr_artist = find_artist(artist);

	if (ptr_artist == NULL) {
        ptr_artist = addArtist(artist)
	}
    
    Song *ptr_song = create_song_instance(ptr_artist, title, path);
    SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));
    
    ptr_snode->song = ptr_song;
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL;
    
    insert_node(ptr_artist, ptr_snode);
}

void insert_node(Artist* ptr_artist, SNode* ptr_snode){
    SNode* p = ptr_artist->head;
    
    while(p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0){
        p = p->next;
    }
    
    //add ptr_snode before p
    if(ptr_artist->head == NULL){ // empty list
        ptr_artist->head = ptr_snode;
        ptr_artist->tail = ptr_snode;
    }
    else if(p == ptr_artist->head){ // at the front
        ptr_snode->next = ptr_artist->head;
        ptr_artist->head = ptr_snode;
    }
    else if(p == NULL){ // at the end
        ptr_snode->prev = ptr_artist->tail;
        ptr_artist->tail->next = ptr_snode;
        ptr_artist->tail = ptr_snode;
    }
    else{ // at the middle
        ptr_snode->next = p;
        ptr_snode->prev = p->prev;
        p->prev->next = ptr_snode;
        p->prev = ptr_snode;
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

Artist* create_artist_instance(char* artist_name){
    Artist* ptr_artist = (Artist*)malloc(sizeof(Artist));
    
    ptr_artist->name = artist_name;
    ptr_artist->head = NULL;
    ptr_artist->tail = NULL;
    ptr_artist->next = NULL;
    
    return ptr_artist;
}

Artist* addArtist(char* artist_name){
    Artist* ptr_artist = create_artist_instance(artist_name);
    Artist* p = artist_directory[(unsigned char)artist_name[0]]; // first node
    Artist* q = NULL; // follow node
    
    while(p != NULL && strcmp(p->name, artist_name) < 0){
        q = p;
        p = p->next;
    }
    
    if(p == NULL && q == NULL){ // have unique node
        artist_directory[(unsigned char)artist_name[0]] = ptr_artist;
    }
    else if(q == NULL){ // add at the front
        ptr_artist->next = p;
        artist_directory[(unsigned char)artist_name[0]] = ptr_artist;
    }
    else{ // add after(q)
        ptr_artist->next = p;
        q->next = ptr_artist;
    }
    return ptr_artist;
}

void status(){
    for(int i = 0; i<NUM_CHARS; i++){
        Artist* p = artist_directory[i];
        while(p != NULL){
            print_artist(p);
            p = p->next;
        }
    }
}

void print_artist(Artist* p){
    printf("%s\n", p->name);
    SNode* ptr_snode = p->head;
    
    while(ptr_snode != NULL){
        print_song(ptr_snode->song);
        ptr_snode = ptr_snode->next;
    }
}

void print_song(Song* ptr_song){
    printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
}