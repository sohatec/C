#include <stdio.h>
#include <stdlib.h>
#include "developer.h"
#include "project.h"
#include "file_io.h"

void S_Developer_TXT(Developer *dataDeveloper, int *pointCount){
	FILE *fileDEV = fopen("developer.txt", "w");
	if(fileDEV == NULL){
		printf("\t## Can not open this file ##\n");
		return;
	}
	fprintf(fileDEV, "=====================================================================================================\n");
	fprintf(fileDEV, "|%-15s|%-30s|%-5s|%-20s|%-15s|%-9s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
	fprintf(fileDEV, "=====================================================================================================\n");
	for(int i = 0; i < *pointCount; i++){
		fprintf(fileDEV, "|%-15s|%-30s|%-5hd|%-20s|%15lld|%9hd|\n", dataDeveloper[i].developerID, dataDeveloper[i].fullName,
												   	  	  	  dataDeveloper[i].birthYear, dataDeveloper[i].programLanguage,
													          dataDeveloper[i].monthSalary, dataDeveloper[i].projectCount);
	}
	fclose(fileDEV);
	printf("\n***Saving Successfully***\n");
}

void S_Project_TXT(Project *dataProject, int *pointCheck){
	FILE *filePRJ = fopen("project.txt", "w");
	if(filePRJ == NULL){
		printf("\t## Can not open this file ##\n");
		return;
	}
	fprintf(filePRJ, "===============================================================================================================\n");
	fprintf(filePRJ, "|%-15s|%-50s|%-15s|%-10s|%-15s|\n", "Project ID", "Project name", "Developer ID", "Duration", "Start time");
	fprintf(filePRJ, "===============================================================================================================\n");
	for(int i = 0; i < *pointCheck; i++){
		fprintf(filePRJ, "|%-15s|%-50s|%-15s|%10hd|     %2hd/%2hd/%4hd|\n", 
				dataProject[i].projectID, dataProject[i].projectName,
				dataProject[i].developerID, dataProject[i].duration,
				dataProject[i].startDay, dataProject[i].startMonth, dataProject[i].startYear);
	}
	fclose(filePRJ);
	printf("\n***Saving Successfully***\n");
}

void R_Developer_TXT(){
	FILE *fileDEV = fopen("developer.txt", "r");
	if(fileDEV == NULL){
		printf("\t## Can not open this file ##\n");
		return;
	}
	char line[250];
	while(fgets(line, sizeof(line), fileDEV)){
		printf("%s", line);
	}
	fclose(fileDEV);
}

void R_Project_TXT(){
	FILE *filePRJ = fopen("project.txt", "r");
	if(filePRJ == NULL){
		printf("\t## Can not open this file ##\n");
		return;
	}
	char line[250];
	while(fgets(line, sizeof(line), filePRJ)){
		printf("%s", line);
	}
	fclose(filePRJ);
}

void S_Developer_BIN(Developer *dataDeveloper, int *pointCount){
	if(*pointCount <= 0){
		return;
	}
	FILE *fileDEV = fopen("developer.bin", "wb");	
	if(fileDEV != NULL){
		fwrite(pointCount, sizeof(int), 1, fileDEV);
		fwrite(dataDeveloper, sizeof(Developer), *pointCount, fileDEV);
		fclose(fileDEV);
	}
}

void S_Project_BIN(Project *dataProject, int *pointCheck){
	if(*pointCheck <= 0){
		return;
	}
	FILE *filePRJ = fopen("project.bin", "wb");
	if(filePRJ != NULL){
		fwrite(pointCheck, sizeof(int), 1, filePRJ);
		fwrite(dataProject, sizeof(Project), *pointCheck, filePRJ);
		fclose(filePRJ);
	}
}

void R_Developer_BIN(Developer **dataDeveloper, int *pointCount, int *currentCapacityDEV){
	FILE *fileDEV = fopen("developer.bin", "rb");
	if(fileDEV == NULL){
		printf("\t\t\t      ## List of developer is not created ##\n");
		return;      
	}
	
	int fileCount = 0;
	fread(&fileCount, sizeof(int), 1, fileDEV);
	if(fileCount > *currentCapacityDEV){
		*currentCapacityDEV = fileCount;
		Developer *temp = (Developer*)realloc(*dataDeveloper, (*currentCapacityDEV) * sizeof(Developer));
		if (temp != NULL) {
            *dataDeveloper = temp;
        }	
	}
	fread(*dataDeveloper, sizeof(Developer), fileCount, fileDEV);
	*pointCount = fileCount;
	printf("=====================================================================================================\n");
	printf("|%-15s|%-30s|%-5s|%-20s|%-15s|%-9s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
	printf("=====================================================================================================\n");
	for(int i = 0; i < *pointCount; i++){
		printf("|%-15s|%-30s|%-5hd|%-20s|%15lld|%9hd|\n", (*dataDeveloper)[i].developerID, (*dataDeveloper)[i].fullName,
												   	  	    (*dataDeveloper)[i].birthYear, (*dataDeveloper)[i].programLanguage,
													        (*dataDeveloper)[i].monthSalary, (*dataDeveloper)[i].projectCount);
	}
	printf("\t\t\t ==================================================\n");
	printf("\t\t\t |    !!! READ ALL OLD DATA OF DEVELOPER !!!      |\n");
	printf("\t\t\t ==================================================\n");
	fclose(fileDEV);
}

void R_Project_BIN(Project **dataProject, int *pointCheck, int *currentCapacityPRJ){
	FILE *filePRJ = fopen("project.bin", "rb");
	if(filePRJ == NULL){
		printf("\t\t\t        ## List of project is not created ##\n");
		return;
	}
	int fileCount = 0;
	fread(&fileCount, sizeof(int), 1, filePRJ);
	if(fileCount > *currentCapacityPRJ){
		*currentCapacityPRJ = fileCount;
		Project *temp = (Project*)realloc(*dataProject, (*currentCapacityPRJ) * sizeof(Project));
		if (temp != NULL) {
            *dataProject = temp;
       	}	
	}
	fread(*dataProject, sizeof(Project), fileCount, filePRJ);
	*pointCheck = fileCount;
	printf("===============================================================================================================\n");
	printf("|%-15s|%-50s|%-15s|%-10s|%-15s|\n", "Project ID", "Project name", "Developer ID", "Duration", "Start time");
	printf("===============================================================================================================\n");
	for(int i = 0; i < *pointCheck; i++){
		printf("|%-15s|%-50s|%-15s|%10hd|     %2hd/%2hd/%4hd|\n", 
					(*dataProject)[i].projectID, (*dataProject)[i].projectName,
					(*dataProject)[i].developerID, (*dataProject)[i].duration,
					(*dataProject)[i].startDay, (*dataProject)[i].startMonth, (*dataProject)[i].startYear);
	}
	printf("\t\t\t ==================================================\n");
	printf("\t\t\t |      !!! READ ALL OLD DATA OF PROJECT !!!      |\n");
	printf("\t\t\t ==================================================\n");
	fclose(filePRJ);
}

void S_User_BIN(char *userName, short *dayUser, short *monthUser, short *yearUser, 
				char *email, char *passWord, char *phoneNumber, short *checkUser){
	FILE *fileUSER = fopen("user.bin", "wb");
		fwrite(userName, sizeof(char), 21, fileUSER);
		fwrite(dayUser, sizeof(short), 1, fileUSER);
		fwrite(monthUser, sizeof(short), 1, fileUSER);
		fwrite(yearUser, sizeof(short), 1, fileUSER);
		fwrite(email, sizeof(char), 51, fileUSER);
		fwrite(passWord, sizeof(char), 21, fileUSER);
		fwrite(phoneNumber, sizeof(char), 20, fileUSER);
		*checkUser = 116;	
    fclose(fileUSER);				
}

short R_User_BIN(char *userName, short *dayUser, short *monthUser, short *yearUser, 
				 char *email, char *passWord, char *phoneNumber, short *checkUser){
	FILE *fileUSER = fopen("user.bin", "rb");
		if(fileUSER == NULL){
			return 0;
		}
		short count = 0;
		count += fread(userName, sizeof(char), 21, fileUSER);
		count += fread(dayUser, sizeof(short), 1, fileUSER);
		count += fread(monthUser, sizeof(short), 1, fileUSER);
		count += fread(yearUser, sizeof(short), 1, fileUSER);
		count += fread(email, sizeof(char), 51, fileUSER);
		count += fread(passWord, sizeof(char), 21, fileUSER);
		count += fread(phoneNumber, sizeof(char), 20, fileUSER);
	fclose(fileUSER);
	*checkUser = count;
	return *checkUser;				 	
}