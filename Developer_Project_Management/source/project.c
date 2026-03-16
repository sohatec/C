#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "developer.h"
#include "project.h"

void addProject(Project *dataProject, int *pointCheck, Developer *dataDeveloper, int *pointCount, int number){
	char devID[15];
	int added = 0;
	static int autoID = 100;
	short error = 1;
	
	while(added < number){
		printf("\n%-27s", "Developer's ID to assign: ");
		fgets(devID, 15, stdin);
    	devID[strcspn(devID, "\n")] = 0;
    	
    	int found = 0;
    	for(int j = 0; j < *pointCount; j++){
    		if(strcmp(dataDeveloper[j].developerID, devID) == 0){
    			found = 1;
    			error = 1;
    			int i = *pointCheck;
    			printf("\nAdd project's information the %d\n", (i + 1));
    			printf("%-27s| %-20s\n", "Add project's ID", "Auto-generated ID");
				sprintf(dataProject[i].projectID, "PRJ%d", autoID);
				
				strcpy(dataProject[i].developerID, devID);
				
				printf("%-27s| ", "Add project's name");
				fgets(dataProject[i].projectName, 51, stdin);
    			dataProject[i].projectName[strcspn(dataProject[i].projectName, "\n")] = 0;
    			
    			do{
    				printf("%-27s| ", "Add project's duration");
    				scanf("%hd", &dataProject[i].duration);
    				while((getchar()) != '\n');
    				if(dataProject[i].duration >= 1){
    					break;
					}
				}while(1);
				
				short max, sign = 0;
				do{
					max = 31;
					printf("%-27s| ", "Start date .. .. ....");
					scanf("%hd %hd %hd", &dataProject[i].startDay, &dataProject[i].startMonth, &dataProject[i].startYear);
					while(getchar() != '\n');
					if(dataProject[i].startDay < 1 || dataProject[i].startDay > 31 || 
					   dataProject[i].startMonth < 1 || dataProject[i].startMonth > 12 || 
		   			   dataProject[i].startYear < 2026){
					   continue;
					}
					if(dataProject[i].startMonth == 4 || dataProject[i].startMonth == 6 || 
					   dataProject[i].startMonth == 9 || dataProject[i].startMonth == 11){
						max = 30;
					}else if(dataProject[i].startMonth == 2){
						if(dataProject[i].startYear % 400 == 0 || (dataProject[i].startYear % 4 == 0 && dataProject[i].startYear % 100 != 0)){
							max = 29;
						}else{
							max = 28;
						}
					}
					if(dataProject[i].startDay >= 1 && dataProject[i].startDay <= max){
						sign = 1;
					}else{
						sign = 0;
					}
				}while(sign == 0);
		
				dataDeveloper[j].projectCount += 1;
				*pointCheck += 1;
				added += 1; 
				autoID += 7;
				printf("\t*** Adding Successfully ***\n");
				break;
			}	
		}
		if(found == 0){
			printf("*** NOT FOUND THIS DEVELOPER'S ID ***\n");
		}
		if(error == 3){
			printf("\n*** There is no one, review the list of developer'ID ***\n");
			break;
		}
		error += 1;
	}	
}

void totalExperienceTime(Project *dataProject, int *pointCheck){
	char idCheck[15];
	short found = 0, error = 1;
	int totalTime = 0;
	do{
		printf("Enter developer's ID to calculate total experience time: ");
		fgets(idCheck, 15, stdin);
    	idCheck[strcspn(idCheck, "\n")] = 0;
    	for(int i = 0; i < *pointCheck; i++){
    		if(strcmp(dataProject[i].developerID, idCheck) == 0){
    			found = 1;
    			totalTime = totalTime + (int)dataProject[i].duration;
			}
		}
		if(found == 1){
			printf("\n");
			printf("===========================================\n");
			printf("|%-25s|%-15s|\n", "Developer's ID", idCheck);
			printf("|%-25s|%-15d|\n", "Total experience time", totalTime);
			printf("===========================================\n");
			break;
		}else if(found == 0){
			printf("      *** NOT FOUND THIS ID IN LIST OF OUR PROJECT ***\n\n");
		}
		if(error == 3){
			printf("\n *** There is no one, review the list of developer'ID ***\n");
			break;
		}
		error += 1;
	}while(1);
}

void showProject(Project *dataProject, int *pointCheck){
	if(*pointCheck == 0){
		printf("\t\t*** THERE IS NO PROJECT***\n");
	}else{
		printf("===============================================================================================================\n");
		printf("|%-15s|%-50s|%-15s|%-10s|%-15s|\n", "Project ID", "Project name", "Developer ID", "Duration", "Start time");
		printf("===============================================================================================================\n");
		for(int i = 0; i < *pointCheck; i++){
			printf("|%-15s|%-50s|%-15s|%10hd|     %2hd/%2hd/%4hd|\n", 
					dataProject[i].projectID, dataProject[i].projectName,
					dataProject[i].developerID, dataProject[i].duration,
					dataProject[i].startDay, dataProject[i].startMonth, dataProject[i].startYear);
		}
	}
}