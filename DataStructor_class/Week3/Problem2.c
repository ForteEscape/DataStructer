#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct Album {
	char * title;
	char * artist;
	char * rank;
}Album;

char* blankWipe(char* str);
void rankTrans(struct Album* album, int size);
void sort_rank(struct Album* album, int size);
void swap(struct Album* album, int front, int back);

int main()
{
	Album data[100];

	int lineNum;
	char* strArr[100];
	char buffer[200];
	char* afterProcess;

	scanf("%d%*c", &lineNum);

	for (int i = 0; i < lineNum; i++) {
		fgets(buffer, sizeof(buffer), stdin);

		strArr[i] = strdup(buffer);

		char* ptr = strtok(strArr[i], "-"); // The function can replace this area

		if (ptr != NULL) {
			afterProcess = blankWipe(ptr);
			data[i].title = afterProcess;
			ptr = strtok(NULL, "-");
		}

		if (ptr != NULL) {
			afterProcess = blankWipe(ptr);
			data[i].artist = afterProcess;
			ptr = strtok(NULL, "-");
		}

		if (ptr != NULL) {
			afterProcess = blankWipe(ptr);
			data[i].rank = strtok(afterProcess, ".");
		}
	}

	rankTrans(data, lineNum);
	sort_rank(data, lineNum);

	for (int i = 0; i < lineNum; i++) { // ans
		printf("%s-%s-%s.mp3\n", data[i].rank, data[i].title, data[i].artist);
	}
}

char* blankWipe(char* str) { // eliminate unnecessary blank
	char* afterStr;
	char tempBuf[100];
	int idx = strlen(str);

	strcpy(tempBuf, str);
	
	while (tempBuf[0] == ' ') {
		for (int i = 0; i < strlen(str) - 1; i++) {
			tempBuf[i] = tempBuf[i + 1];
		}
	}
	
	for (int i = strlen(str); i >= 0; i--) {
		if (tempBuf[i] != ' ' && tempBuf[i] != '\0') {
			break;
		}
		else {
			tempBuf[i] = '\0';
		}
	}

	afterStr = strdup(tempBuf);

	return afterStr;
}

void rankTrans(struct Album* album, int size) {
	char* trans;
	for (int i = 0; i < size; i++) {
		trans = album[i].rank;

		if (strlen(trans) == 2) { // the length of #1 ~ #9 is 2 so transform # to 0
			trans[0] = '0';
			continue;
		}

		for (int j = 0; j < strlen(album[i].rank) - 1; j++) {
			trans[j] = trans[j + 1]; // eliminate # symbol
		}
		trans[strlen(trans) - 1] = '\0';
	}
}

void sort_rank(struct Album* album, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (strcmp(album[j].rank, album[j+1].rank) > 0) {
				swap(album, j, j + 1);
			}
		}
	}
}

void swap(struct Album* album, int front, int back) {
	Album temp = album[front];
	album[front] = album[back];
	album[back] = temp;
}