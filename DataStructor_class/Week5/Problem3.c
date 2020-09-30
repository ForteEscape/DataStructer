#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct {
	char* IP_address;
	char* time;
	char* URL;
	char* Status;

	int year, month, day, hour, min, sec;
}WebLog;

typedef struct {
	char* ip_address;
	int count;
}Ans;

typedef struct {
	char* time;
	char* URL;
	char* Status;

	int year, month, day, hour, min, sec;
}Ans_ip;

void searchByDate(char* date1, char* date2, int size);
void searchByIp(char* ip, int size);
void timeSeparate(int size);
char* eliminateStr(char* str);
int transMonth(char* strMonth);
int comparator_date(const void* front, const void* back);
int comparator_time(const void* front, const void* back);

WebLog logStruct[100000];

char buffer[1024];
char* str[10000];

int main()
{
	FILE* fp = fopen("webLog.csv", "r");
	int idx = -1;
	int idx_line = 0;
	int idx_cmd = 0;
	int temp = 0;
	char command[100];
	char* cmdStr[3];

	while (fgets(buffer, 1024, fp)) {
		if (idx == -1) {
			idx++;
			continue;
		}
		
		char* ptr = strtok(buffer, ",");
		
		while (ptr != NULL) {
			str[idx] = strdup(ptr);

			idx++;
			ptr = strtok(NULL, ",");
		}
		idx_line++;
	}

	for (int i = 0; i < idx_line; i++) {
		logStruct[i].IP_address = str[temp];
		logStruct[i].time = str[++temp];
		logStruct[i].URL = str[++temp];
		logStruct[i].Status = str[++temp];
		temp++;
	}
	fclose(fp);

	timeSeparate(idx_line);

	while (1) {
		printf("$ ");
		gets_s(command, 100); // 올릴때 gets로 하던가 fgets로 하던가 둘중 하나 해야함

		if (strcmp(command, "exit") == 0) {
			break;
		}

		char* ptr = strtok(command, " ");

		while (ptr != NULL) {
			str[idx_cmd] = ptr;

			idx_cmd++;
			ptr = strtok(NULL, " ");
		}

		if (strcmp(str[0], "search") == 0) {
			if (strcmp(str[1], "-date") == 0) {
				searchByDate(str[2], str[3], idx_line);
			}
			else if (strcmp(str[1], "-ip") == 0) {
				searchByIp(str[2], idx_line);
			}
		}

		idx_cmd = 0;
	}
}

void searchByIp(char* ip, int size) {
	Ans_ip ipAns[1000];

	int logCount = 0;

	for (int i = 0; i < size; i++) {
		if (strcmp(logStruct[i].IP_address, ip) == 0) {
			ipAns[logCount].time = logStruct[i].time;
			ipAns[logCount].URL = logStruct[i].URL;
			ipAns[logCount].Status = logStruct[i].Status;
			ipAns[logCount].year = logStruct[i].year;
			ipAns[logCount].month = logStruct[i].month;
			ipAns[logCount].day = logStruct[i].day;
			ipAns[logCount].hour = logStruct[i].hour;
			ipAns[logCount].min = logStruct[i].min;
			ipAns[logCount].sec = logStruct[i].sec;
			
			logCount++;
		}
	}

	qsort(ipAns, logCount, sizeof(ipAns[0]), comparator_time);

	printf("%d logs found\n", logCount);
	for (int i = 0; i < logCount; i++) {
		printf("%s,%s,%s", ipAns[i].time, ipAns[i].URL, ipAns[i].Status);
	}
}

void timeSeparate(int size) {
	char* time[4];
	char* date[10];
	char* decapsulationStr;

	for (int i = 0; i < size; i++) {
		int idx_date = 0;
		int idx_time = 0;
		decapsulationStr = eliminateStr(logStruct[i].time);

		char* ptr = strtok(decapsulationStr, ":");
		while (ptr != NULL) {
			time[idx_time] = strdup(ptr);

			idx_time++;
			ptr = strtok(NULL, ":");
		}

		char* pptr = strtok(time[0], "/");
		while (pptr != NULL) {
			date[idx_date] = strdup(pptr);

			idx_date++;
			pptr = strtok(NULL, "/");
		}
		
		logStruct[i].year = atoi(date[2]);
		logStruct[i].month = transMonth(date[1]);
		logStruct[i].day = atoi(date[0]);
		logStruct[i].hour = atoi(time[1]);
		logStruct[i].min = atoi(time[2]);
		logStruct[i].sec = atoi(time[3]);
	}
}

int transMonth(char* strMonth) {
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

void searchByDate(char* date1, char* date2, int size) {
	Ans dateAns[1000];

	char* dateArr1[3];
	char* dateArr2[3];
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int idx1 = 0;
	int idx2 = 0;
	int count = 0;
	int year1, month1, day1;
	int year2, month2, day2;

	char* ptr = strtok(date1, "/");
	while (ptr != NULL) {
		dateArr1[idx1] = strdup(ptr);
		
		idx1++;
		ptr = strtok(NULL, "/");
	}
	year1 = atoi(dateArr1[2]);
	month1 = transMonth(dateArr1[1]);
	day1 = atoi(dateArr1[0]);

	char* pptr = strtok(date2, "/");
	while (pptr != NULL) {
		dateArr2[idx2] = strdup(pptr);

		idx2++;
		pptr = strtok(NULL, "/");
	}
	year2 = atoi(dateArr2[2]);
	month2 = transMonth(dateArr2[1]);
	day2 = atoi(dateArr2[0]);

	for (int i = 0; i < size; i++) {
		int tempYear = year1;
		int tempMonth = month1;
		int tempDay = day1;
		int diff_flg = 1;

		for (;;) {
			if (tempYear == year2 && tempMonth == month2 && tempDay > day2) {
				break;
			}
			else if (tempYear > year2) {
				break;
			}
			else if (tempYear == year2 && tempMonth > month2) {
				break;
			}

			if (logStruct[i].year == tempYear && logStruct[i].month == tempMonth && logStruct[i].day == tempDay) {
				if (count == 0) {
					dateAns[count].ip_address = logStruct[i].IP_address;
					dateAns[count].count++;
					count++;
				}
				else {
					for (int j = 0; j < count; j++) {
						if (strcmp(dateAns[j].ip_address, logStruct[i].IP_address) == 0) {
							dateAns[j].count++;
							diff_flg = 0;
							break;
						}
					}

					if (diff_flg == 1) {
						dateAns[count].ip_address = logStruct[i].IP_address;
						dateAns[count].count++;
						count++;
					}
				}
				break;
			}
			else {
				if (tempDay == days[tempMonth - 1]) {
					tempDay = 1;

					if (tempMonth == 12) {
						tempMonth = 1;
						tempYear += 1;
					}
					else {
						tempMonth += 1;
					}
				}
				else {
					tempDay += 1;
				}
			}
		}
	}

	qsort(dateAns, count, sizeof(dateAns[0]), comparator_date);

	printf("%d ips found:\n", count);
	for (int i = 0; i < count; i++) {
		printf("%s: %d\n", dateAns[i].ip_address, dateAns[i].count);
	}

	count = 0;
}

char* eliminateStr(char* str) {
	char tempBuffer[100];
	int len = strlen(str);

	strcpy(tempBuffer, str);

	if (tempBuffer[0] == '[') {
		for (int i = 0; i < len - 1; i++) {
			tempBuffer[i] = tempBuffer[i + 1];
		}
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
	}
	else if (tempBuffer[strlen(tempBuffer) - 1] == ']') {
		tempBuffer[strlen(tempBuffer) - 1] = '\0';
	}

	str = strdup(tempBuffer);

	return str;
}

int comparator_date(const void* front, const void* back) {
	Ans* ans1 = (Ans*)front;
	Ans* ans2 = (Ans*)back;

	if (ans2->count > ans1->count) {
		return 1;
	}
	else if (ans1->count == ans2->count) {
		if (strcmp(ans1->ip_address, ans2->ip_address) == 1) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

int comparator_time(const void* front, const void* back) {
	Ans_ip* ip1 = (Ans_ip*)front;
	Ans_ip* ip2 = (Ans_ip*)back;

	if (ip1->year > ip2->year) {
		return 1;
	}
	else if (ip1->year == ip2->year) {
		if (ip1->month > ip2->month) {
			return 1;
		}
		else if (ip1->month == ip2->month) {
			if (ip1->day > ip2->day) {
				return 1;
			}
			else if (ip1->day == ip2->day) {
				if (ip1->hour > ip2->hour) {
					return 1;
				}
				else if (ip1->hour == ip2->hour) {
					if (ip1->min > ip2->min) {
						return 1;
					}
					else if (ip1->min == ip2->min) {
						if (ip1->sec > ip2->sec) {
							return 1;
						}
						else return -1;
					}
					else return -1;
				}
				else return -1;
			}
			else return -1;
		}
		else return -1;
	}
	else return -1;
}