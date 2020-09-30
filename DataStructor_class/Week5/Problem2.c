#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct {
	int year, month, day, hour, min, sec;
}MyDate;

int monthTrans(char* month);
int comparator(const void* front, const void* back);
char* eliminateChar(char* ptr);
void setStruct(char* str[], int idx);

MyDate* mydate[200];

int main()
{
	int data_num;
	char input[100];
	char* str[10];
	int idx = 0;

	scanf("%d", &data_num);

	for (int i = 0; i < data_num; i++) {
		scanf("%s", input);

		mydate[i] = (struct MyDate*)malloc(sizeof(MyDate)); // malloc element

		char* ptr = strtok(input, "/");

		while (ptr != NULL) {
			char* pptr = eliminateChar(ptr);

			str[idx] = pptr;
			idx++;
			ptr = strtok(NULL, "/");
		}

		char* tempStr = str[idx - 1];
		char* ptrr = strtok(tempStr, ":");

		idx -= 1;

		while (ptrr != NULL) {
			str[idx] = ptrr;
			idx++;

			ptrr = strtok(NULL, ":");
		}

		setStruct(str, i);
		idx = 0;
	}

	qsort(mydate, data_num, sizeof(mydate[0]), comparator);

	for (int i = 0; i < data_num; i++) {
		printf("%d-%02d-%02d:%02d:%02d:%02d\n", mydate[i]->year, mydate[i]->month, mydate[i]->day, mydate[i]->hour, mydate[i]->min, mydate[i]->sec);
		free(mydate[i]);
	}
}

void setStruct(char* str[], int idx) {
	mydate[idx]->day = atoi(str[0]);
	mydate[idx]->month = monthTrans(str[1]);
	mydate[idx]->year = atoi(str[2]);
	mydate[idx]->hour = atoi(str[3]);
	mydate[idx]->min = atoi(str[4]);
	mydate[idx]->sec = atoi(str[5]);
}

int comparator(const void* front, const void* back) { // filter
	MyDate* data1 = *(MyDate**)front;
	MyDate* data2 = *(MyDate**)back;

	if (data1->year > data2->year) {
		return 1;
	}
	else if (data1->year == data2->year) {
		if (data1->month > data2->month) {
			return 1;
		}
		else if (data1->month == data2->month) {
			if (data1->day > data2->day) {
				return 1;
			}
			else if (data1->day == data2->day) {
				if (data1->hour > data2->hour) {
					return 1;
				}
				else if (data1->hour == data2->hour) {
					if (data1->min > data2->min) {
						return 1;
					}
					else if (data1->min == data2->min) {
						if (data1->sec > data2->sec) {
							return 1;
						}
						else if (data1->sec == data2->sec) {
							return 0;
						}
						else {
							return -1;
						}
					}
					else {
						return -1;
					}
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

int monthTrans(char* strMonth) {
	const char* monthArr[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int intMonth = -1;

	for (int i = 0; i < 12; i++) {
		if (strcmp(strMonth, monthArr[i]) == 0) {
			intMonth = i + 1;
			break;
		}
	}

	return intMonth;
}

char* eliminateChar(char* ptr) {
	char tempBuffer[100];
	int len = strlen(ptr);

	strcpy(tempBuffer, ptr);

	if (tempBuffer[0] == '[') {
		for (int i = 0; i < len - 1; i++) {
			tempBuffer[i] = tempBuffer[i + 1];
		}
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
	}
	else if (tempBuffer[strlen(tempBuffer) - 1] == ']') {
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
	}

	ptr = strdup(tempBuffer);

	return ptr;
}