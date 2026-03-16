#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "developer.h"
#include "project.h"
#include "user.h"
#include "menu.h"
#include "file_io.h"

int main(int argc, char *argv[]) {
	
	welcome();
	char userName[21], email[51], passWord[21], phoneNumber[20];
	short dayUser, monthUser, yearUser, checkUser = 0;
	if(R_User_BIN(userName, &dayUser, &monthUser, &yearUser, email, passWord, phoneNumber, &checkUser) != 116){
		createAccount(userName, &dayUser, &monthUser, &yearUser, email, passWord, phoneNumber);
	}else if(R_User_BIN(userName, &dayUser, &monthUser, &yearUser, email, passWord, phoneNumber, &checkUser) == 116){	
		while(1){
			printf("\n\t\t ***Login Your Account***\n");
			char emailCheck[51], passWordCheck[21];
			printf("%-27s| ", "Your email");
			fgets(emailCheck, 51, stdin);
			emailCheck[strcspn(emailCheck, "\n")] = 0;        
			printf("%-27s| ", "Your password");
			fgets(passWordCheck, 21, stdin);
			passWordCheck[strcspn(passWordCheck, "\n")] = 0;
			if(strcmp(email, emailCheck) == 0 && strcmp(passWord, passWordCheck) == 0){
				break;
			}else{
				printf("\n\t   ---Email Or Password Is Incorrect---\n");
			}
		}
	}
	clear();
    
    int count = 0;
	int *pointCount = &count;
	int currentCapacityDEV = 5;
    Developer *dataDeveloper = (Developer*)calloc(5, sizeof(Developer));
	if(dataDeveloper == NULL){
		printf("Error: Memory allocation failed !\n");
		return 1;
	}
	
	int check = 0;
	int *pointCheck = &check;
	int currentCapacityPRJ = 5;
	Project *dataProject = (Project*)calloc(5, sizeof(Project));
	if(dataProject == NULL){
		printf("Error: Memory allocation failed !\n");
		return 1;
	}
	
	R_Developer_BIN(&dataDeveloper, pointCount, &currentCapacityDEV);
		printf("\t\t\t ==================================================\n");
		printf("\t\t\t |        !!! Press ENTER to continue !!!         |\n");
		printf("\t\t\t ==================================================\n");
		while (getchar() != '\n');
		printf("\n");
		clear();
	R_Project_BIN(&dataProject, pointCheck, &currentCapacityPRJ);
		printf("\t\t\t ==================================================\n");
		printf("\t\t\t |         !!! Press ENTER to continue !!!        |\n");
		printf("\t\t\t ==================================================\n");
		while (getchar() != '\n');
	
	short choosen_0, choosen_0_1, choosen_0_2, choosen_0_3, choosen_0_1_2, choosen_0_1_3, 
	choosen_0_4;
    do{
    	clear();
    	menu_0();
    	scanf("%hd", &choosen_0);
    	while ((getchar()) != '\n');
    	if(choosen_0 != 0 && choosen_0 != 1 && choosen_0 != 2 && choosen_0 != 3 &&
		   choosen_0 != 4){
    	   printf("\t## Option is not valid ##\n");
		}
    	switch(choosen_0){
    		case 1:
				do{
					clear();
					menu_0_1();
					scanf("%hd", &choosen_0_1);
					while ((getchar()) != '\n');
					if(choosen_0_1 != 0 && choosen_0_1 != 1 && choosen_0_1 != 2 &&
		   			   choosen_0_1 != 3 && choosen_0_1 != 4 && choosen_0_1 != 5){
    	   			   printf("\t## Option is not valid ##\n");
					}
					switch(choosen_0_1){
						case 1:
							clear();
							int numberDEV;
							do{
								printf("Input the number of developer: ");
								scanf("%d", &numberDEV);
								while(getchar() != '\n');
								if(numberDEV >= 1){
									break;
								}
							}while(1);
							if((*pointCount + numberDEV) > currentCapacityDEV){
								currentCapacityDEV = *pointCount + numberDEV;
								Developer *temp = (Developer*)realloc(dataDeveloper, currentCapacityDEV * sizeof(Developer));
								if (temp != NULL) {
            						dataDeveloper = temp;
        						}else{
            						printf("Error: Memory allocation failed !\n");
        						}
							}
							addDeveloper(dataDeveloper, pointCount, numberDEV);
							printf("\t !!! Press ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 2:
							do{
								clear();
								menu_0_1_2();
								scanf("%hd", &choosen_0_1_2);
								while ((getchar()) != '\n');
								if(choosen_0_1_2 != 0 && choosen_0_1_2 != 1 && choosen_0_1_2 != 2 && choosen_0_1_2 != 3){
    	   			   			printf("\t## Option is not valid ##\n");
								}
								switch(choosen_0_1_2){
									case 1:
										clear();
										searchSalary(dataDeveloper, pointCount);
										printf("\n\t\t\t        !!! Press ENTER to continue !!!");
										while (getchar() != '\n');
										break;
									case 2:
										clear();
										searchName(dataDeveloper, pointCount);
										printf("\n\t\t\t        !!! Press ENTER to continue !!!");
										while (getchar() != '\n');
										break;
									case 3:
										clear();
										searchYear(dataDeveloper, pointCount);
										printf("\n\t\t\t        !!! Press ENTER to continue !!!");
										while (getchar() != '\n');
										break;
								}
							}while(choosen_0_1_2 != 0);
							break;
						case 3:
							do{
								clear();
								menu_0_1_3();
								scanf("%hd", &choosen_0_1_3);
								while ((getchar()) != '\n');
								if(choosen_0_1_3 != 0 && choosen_0_1_3 != 1 && choosen_0_1_3 != 2 && choosen_0_1_3 != 3){
    	   			   			printf("\t## Option is not valid ##\n");
								}
								switch(choosen_0_1_3){
									case 1:
										clear();
										qsort(dataDeveloper, *pointCount, sizeof(Developer), compareSalary);
										printf("\nPress ENTER to continue !!!\n");
										printf("Choose option 6 to watch !!!");
										while (getchar() != '\n');
										break;
									case 2:
										clear();
										qsort(dataDeveloper, *pointCount, sizeof(Developer), compareName);
										printf("\nPress ENTER to continue !!!\n");
										printf("Choose option 6 to watch !!!");
										while (getchar() != '\n');
										break;
									case 3:
										clear();
										qsort(dataDeveloper, *pointCount, sizeof(Developer), compareYear);
										printf("\nPress ENTER to continue !!!\n");
										printf("Choose option 6 to watch !!!");
										while (getchar() != '\n');
										break;
								}
							}while(choosen_0_1_3 != 0);
							break;
						case 4:
							clear();
							updateDeveloper(dataDeveloper, pointCount);
							break;
						case 5:
							clear();
							deleteDeveloper(dataDeveloper, pointCount);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 6:
							clear();
							showListDeveloper(dataDeveloper, pointCount);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
					}
				}while(choosen_0_1 != 0);
    			break;
    		case 2:
				do{
					clear();
					menu_0_2();
					scanf("%hd", &choosen_0_2);
					while ((getchar()) != '\n');
					if(choosen_0_2 != 0 && choosen_0_2 != 1 && choosen_0_2 != 2 && choosen_0_2 != 3){
    	   			   printf("\t## Option is not valid ##\n");
					}
					switch(choosen_0_2){
						case 1:
							clear();
							int numberPRJ;
							do{
								printf("Input the number of projects to add: ");
								scanf("%d", &numberPRJ);
								while((getchar()) != '\n');
								if(numberPRJ >= 1){
									break;
								}
							}while(1);
							if((*pointCheck + numberPRJ) > currentCapacityPRJ){
								currentCapacityPRJ = *pointCheck + numberPRJ;
								Project *temp = (Project*)realloc(dataProject, currentCapacityPRJ * sizeof(Project));
								if (temp != NULL) {
            						dataProject = temp;
        						}else{
            						printf("Error: Memory allocation failed !\n");
        						}
							}
							addProject(dataProject, pointCheck, dataDeveloper, pointCount, numberPRJ);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 2:
							clear();
							totalExperienceTime(dataProject, pointCheck);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 3:
							clear();
							showProject(dataProject, pointCheck);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;	
					}
				}while(choosen_0_2 != 0);
				break;
			case 3:
				do{
					clear();
					menu_0_3();
					scanf("%hd", &choosen_0_3);
					while ((getchar()) != '\n');
					if(choosen_0_3 != 0 && choosen_0_3 != 1 && choosen_0_3 != 2 &&
		   			   choosen_0_3 != 3){
    	   			   printf("\t## Option is not valid ##\n");
					}
					switch(choosen_0_3){
						case 1:
							clear();
							showUserProfile(userName, &dayUser, &monthUser, &yearUser, email, passWord, phoneNumber);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 2:
							clear();
							changeEmail(email);
							printf("\n\tPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 3:
							clear();
							changePassword(passWord);
							printf("\n\tPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
					}
				}while(choosen_0_3 != 0);
				break;
			case 4:
				do{
					clear();
					menu_0_4();
					scanf("%hd", &choosen_0_4);
					while ((getchar()) != '\n');
					if(choosen_0_4 != 0 && choosen_0_4 != 1 && choosen_0_4 != 2 && choosen_0_4 != 3 && choosen_0_4 != 4){
    	   			   printf("\t## Option is not valid ##\n");
					}
					switch(choosen_0_4){
						case 1:
							clear();
							S_Developer_TXT(dataDeveloper, pointCount);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 2:
							clear();
							S_Project_TXT(dataProject, pointCheck);
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 3:
							clear();
							R_Developer_TXT();
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;
						case 4:
							clear();
							R_Project_TXT();
							printf("\nPress ENTER to continue !!!");
							while (getchar() != '\n');
							break;					
					}
				}while(choosen_0_4 != 0);
				break;	
		}
	}while(choosen_0 != 0);
	clear();
	
	S_Developer_BIN(dataDeveloper, pointCount);
	S_Project_BIN(dataProject, pointCheck);
	S_User_BIN(userName, &dayUser, &monthUser, &yearUser, email, passWord, phoneNumber, &checkUser);
	
	free(dataDeveloper);
	free(dataProject);
	
	goodBye();
	return 0;
}