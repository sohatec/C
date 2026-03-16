#ifndef PROJECT_H
#define PROJECT_H

typedef struct{
	char projectID[15];
	char developerID[15];
	char projectName[51];
	short duration;
	short startDay, startMonth, startYear;
}Project;

void addProject(Project *dataProject, int *pointCheck, Developer *dataDeveloper, int *pointCount, int number);
void totalExperienceTime(Project *dataProject, int *pointCheck);
void showProject(Project *dataProject, int *pointCheck);

#endif