#ifndef DEVELOPER_H
#define DEVELOPER_H

typedef struct{
	char developerID[15];
	char fullName[51];
	short birthYear;
	short projectCount;
	char programLanguage[21];
	long long monthSalary;
}Developer;

void addDeveloper(Developer *dataDeveloper, int *pointCount, int number);
void searchSalary(Developer *dataDeveloper, int *pointCount);
void searchName(Developer *dataDeveloper, int *pointCount);
void searchYear(Developer *dataDeveloper, int *pointCount);
int compareSalary(const void *ptr1, const void *ptr2);
int compareName(const void *ptr1, const void *ptr2);
int compareYear(const void *ptr1, const void *ptr2);
void updateDeveloper(Developer *dataDeveloper, int *pointCount);
void deleteDeveloper(Developer *dataDeveloper, int *pointCount);
void showListDeveloper(Developer *dataDeveloper, int *pointCount);
char* standardName(char *s);

#endif