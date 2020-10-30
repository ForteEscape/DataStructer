#include<stdio.h>
#include<stdlib.h>
#include<string.h>>
#include "string_tools.h"
#include "library.h"
#pragma warning(disable:4996)

#define BUFFER_LEN 200

void process_command();
void handle_add();

int main()
{
	process_command();
}

void process_command() {
	char command_line[BUFFER_LEN];

	while (1) {
		printf("$ "); // cmd prompt

		if (read_line(stdin, command_line, BUFFER_LEN) <= 0) { // if command is empty
			continue;
		}

		char* command = strtok(command_line, " ");

		if (strcmp(command, "add") == 0) {
			handle_add();
		}
		else if (strcmp(command, "search") == 0) {
			handle_search();
		}
		else if (strcmp(command, "remove") == 0) {
			handle_remove();
		}
		else if (strcmp(command, "status") == 0) {
			handle_status();
		}
		else if (strcmp(command, "play") == 0) {
			handle_play();
		}
		else if (strcmp(command, "save") == 0) {
			handle_save();
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}
}

void handle_add() {
	char buffer[BUFFER_LEN];
	char* artist = NULL, * title = NULL, * path = NULL;

	printf("	Artist : ");
	if (read_line(stdin, buffer, BUFFER_LEN) > 0) {
		artist = strdup(buffer);
	}

	printf("	Title : ");
	if (read_line(stdin, buffer, BUFFER_LEN) > 0) {
		title = strdup(buffer);
	}

	printf("	Path : ");
	if (read_line(stdin, buffer, BUFFER_LEN) > 0) {
		path = strdup(buffer);
	}

	printf("%s %s %s\n", artist, title, path);

	add_song(artist, title, path);
}