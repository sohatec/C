#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "developer.h"
#include "menu.h"

char* standardName(char *respon){
    respon[0] = toupper(respon[0]);
    for(int i = 1; i < strlen(respon); i++){
        respon[i] = tolower(respon[i]);
    }
    return respon;
}

void addDeveloper(Developer *dataDeveloper, int *pointCount, int number){
	static int autoID = 100;
	int limit = *pointCount + number;
	for(int i = *pointCount; i < limit; i++){
		dataDeveloper[i].projectCount = 0;
		
		printf("\nAdd developer's information the %d\n", (i + 1));
		printf("%-27s| %-20s\n", "Add developer's ID", "Auto-generated ID");
		sprintf(dataDeveloper[i].developerID, "DEV%d", autoID);
    	
    	printf("%-27s| ", "Add developer's name");
    	char name[51], respon[51] = "";
    	fgets(name, 51, stdin);
    	name[strcspn(name, "\n")] = 0;
    	char *token = strtok(name, " ");
    	while(token != NULL){
    		strcat(respon, standardName(token));
        	token = strtok(NULL, " ");
        	if(token != NULL){
            	strcat(respon, " ");
        	}
		}
    	strcpy(dataDeveloper[i].fullName, respon);
    	
    	short year;
    	do{
    		printf("%-27s| ", "Add developer's birthyear");
			scanf("%hd", &year);
			while((getchar() != '\n'));
			if(year >= 1950 && year <= 2026){
				dataDeveloper[i].birthYear = year;
				year = 0;
				break;
			}
		}while(1);
		
		printf("%-27s| ", "Add program language");
		char language[21];
		fgets(language, 21, stdin);
    	language[strcspn(language, "\n")] = 0;
    	strcpy(dataDeveloper[i].programLanguage, language);
    	
    	long long salary;
    	do{
    		printf("%-27s| ", "Add developer's salary");
			scanf("%lld", &salary);
			while((getchar() != '\n'));
			if(salary >= 1000000){
				dataDeveloper[i].monthSalary = salary;
				salary = 0;
				break;
			}
		}while(1);
		
		autoID = autoID + 5;
	}
	*pointCount = limit;
	printf("\n\t  *** Adding Successingfully ***\n");
}

void searchSalary(Developer *dataDeveloper, int *pointCount){
	long long salaryCheck;
	short found = 0;
	do{
		printf("Input salary to search: ");
		scanf("%lld", &salaryCheck);
		while((getchar()) != '\n');
		if(salaryCheck >= 1000){
			break;
		}
	}while(1);
	printf("\n");
	printf("======================================================================================================\n");
	printf("|%-15s|%-30s|%-5s|%-20s|%-15s|%-10s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
	printf("======================================================================================================\n");
	for(short i = 0; i < *pointCount; i++){
		if(dataDeveloper[i].monthSalary == salaryCheck){
			printf("|%-15s|%-30s|%-5hd|%-20s|%15lld|%10hd|\n", dataDeveloper[i].developerID, dataDeveloper[i].fullName,
												   	  dataDeveloper[i].birthYear, dataDeveloper[i].programLanguage,
													  dataDeveloper[i].monthSalary, dataDeveloper[i].projectCount);
			found = 1;
		}
	}
	if(found == 0){
		printf("\n\t\t\t    ** NOT FOUND ANY DEVELOPER'S SALARY **\n");
	}
}

void searchName(Developer *dataDeveloper, int *pointCount){
	char nameCheck[51];
	short found = 0;
	printf("Input name to search: ");
	fgets(nameCheck, 51, stdin);
    nameCheck[strcspn(nameCheck, "\n")] = 0;
    printf("\n");
    printf("======================================================================================================\n");
	printf("|%-15s|%-30s|%-5s|%-20s|%-15s|%-10s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
	printf("======================================================================================================\n");
    for(short i = 0; i < *pointCount; i++){
    	if(strcmp(dataDeveloper[i].fullName, nameCheck) == 0){
    	printf("|%-15s|%-30s|%-5hd|%-20s|%15lld|%10hd|\n", dataDeveloper[i].developerID, dataDeveloper[i].fullName,
												   	  dataDeveloper[i].birthYear, dataDeveloper[i].programLanguage,
													  dataDeveloper[i].monthSalary, dataDeveloper[i].projectCount);
		found = 1;											  
		}
	}
	if(found == 0){
		printf("\n\t\t\t     ** NOT FOUND ANY DEVELOPER'S NAME **\n");
	}
}

void searchYear(Developer *dataDeveloper, int *pointCount){
	short yearCheck, found = 0;
	printf("Input year to search: ");
	scanf("%hd", &yearCheck);
	while((getchar()) != '\n');
	printf("\n");
	printf("======================================================================================================\n");
	printf("|%-15s|%-30s|%-5s|%-20s|%-15s|%-10s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
	printf("======================================================================================================\n");
	for(short i = 0; i < *pointCount; i++){
		if(dataDeveloper[i].birthYear == yearCheck){
			printf("|%-15s|%-30s|%-5hd|%-20s|%15lld|%10hd|\n", dataDeveloper[i].developerID, dataDeveloper[i].fullName,
												   	  dataDeveloper[i].birthYear, dataDeveloper[i].programLanguage,
													  dataDeveloper[i].monthSalary, dataDeveloper[i].projectCount);
			found = 1;
		}
	}
	if(found == 0){
		printf("\n\t\t\t    ** NOT FOUND ANY DEVELOPER'S BIRTHYEAR **\n");
	}
}

int compareSalary(const void *ptr1, const void *ptr2){
	Developer *p1 = (Developer*)ptr1;
	Developer *p2 = (Developer*)ptr2;
	if((*p1).monthSalary < (*p2).monthSalary){
		return -1;
	}
	if((*p1).monthSalary > (*p2).monthSalary){
		return 1;
	}
	return 0;
}

int compareName(const void *ptr1, const void *ptr2){
	Developer *p1 = (Developer*)ptr1;
	Developer *p2 = (Developer*)ptr2;
	return strcmp((*p1).fullName, (*p2).fullName);
}

int compareYear(const void *ptr1, const void *ptr2){
	Developer *p1 = (Developer*)ptr1;
	Developer *p2 = (Developer*)ptr2;
	if((*p1).birthYear < (*p2).birthYear){
		return -1;
	}
	if((*p1).birthYear > (*p2).birthYear){
		return 1;
	}
	return 0;
}

void updateDeveloper(Developer *dataDeveloper, int *pointCount){
	char idCheck[15], newName[51], newLanguage[21];
	short newYear, choosen;
	long long newSalary;
	
	printf("Input developer's ID to update: ");
	fgets(idCheck, 15, stdin);
    idCheck[strcspn(idCheck, "\n")] = 0;
    for(int i = 0; i < *pointCount; i++){
    	if(strcmp(dataDeveloper[i].developerID, idCheck) == 0){
    		do{
    			menuUpdate();
    			scanf("%hd", &choosen);
    			while ((getchar()) != '\n');
    			switch(choosen){
    				case 1:
    					printf("Input new name: ");
    					fgets(newName, 51, stdin);
    					newName[strcspn(newName, "\n")] = 0;
    					strcpy(dataDeveloper[i].fullName, newName);
    					printf("\n      ***Update Successfully***\n\n");
    					break;
    				case 2:
						do{
							printf("Input new year: ");
							scanf("%hd", &newYear);
							while ((getchar()) != '\n');
							if(newYear >= 1950 && newYear <= 2026){
								break;
							}
						}while(1);
						dataDeveloper[i].birthYear = newYear;
						printf("\n      ***Update Successfully***\n\n");
						break;
					case 3:
						printf("Input new program language: ");
    					fgets(newLanguage, 21, stdin);
    					newLanguage[strcspn(newLanguage, "\n")] = 0;
    					strcpy(dataDeveloper[i].programLanguage, newLanguage);
    					printf("\n      ***Update Successfully***\n\n");
						break;
					case 4:
						do{
							printf("Input new salary: ");
							scanf("%lld", &newSalary);
							while ((getchar()) != '\n');
							if(newSalary >= 1000000){
								break;
							}
						}while(1);
						dataDeveloper[i].monthSalary = newSalary;
						printf("\n      ***Update Successfully***\n\n");
						break;			
				}
			}while(choosen != 0);
		}
	}
}

void deleteDeveloper(Developer *dataDeveloper, int *pointCount){
	char idCheck[15];
	printf("%-27s| ", "Developer's ID to remove");
	fgets(idCheck, 15, stdin);
    idCheck[strcspn(idCheck, "\n")] = 0;
    short index = -1;
    for(int i = 0; i < *pointCount; i++){
    	if(strcmp(dataDeveloper[i].developerID, idCheck) == 0 && dataDeveloper[i].projectCount >= 1){
    		printf("***Developer is building project***\n");
    		break;
		}else if(strcmp(dataDeveloper[i].developerID, idCheck) == 0 && dataDeveloper[i].projectCount == 0){
			index = i;
			break;
		}
	}
	if(index >= 0){
	for(int j = index; j < *pointCount - 1; j++){
    	dataDeveloper[j] = dataDeveloper[j + 1];
	}
	*pointCount = *pointCount - 1;
	printf("  *** Deleting successfully ***\n");
	}
}

void showListDeveloper(Developer *dataDeveloper, int *pointCount){
	if(*pointCount == 0){
		printf("\t\t*** THERE IS NO ONE***\n");
	}else{
		printf("=====================================================================================================\n");
		printf("|%-15s|%-30s|%-5s|%-20s|%-15s|%-9s|\n", "ID", "Name", "Year", "Language", "Salary", "Project");
		printf("=====================================================================================================\n");
		for(int i = 0; i < *pointCount; i++){
			printf("|%-15s|%-30s|%-5hd|%-20s|%15lld|%9hd|\n", dataDeveloper[i].developerID, dataDeveloper[i].fullName,
												   	  	  dataDeveloper[i].birthYear, dataDeveloper[i].programLanguage,
													      dataDeveloper[i].monthSalary, dataDeveloper[i].projectCount);
		}
	}
}