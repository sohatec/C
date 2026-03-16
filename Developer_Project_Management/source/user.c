#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "user.h"
void createAccount(char *userName, short *dayUser, short *monthUser, short *yearUser,
				   char *email, char *passWord, char *phoneNumber){
	printf("\t\t***CREATE A NEW ACCOUNT***\n\n");
	do {
    	printf("%-27s| ", "Your user name (no space)");
    	fgets(userName, 21, stdin);
    	userName[strcspn(userName, "\n")] = 0;
    	if(strpbrk(userName, " ") != NULL || strlen(userName) == 0) {
        	continue;
    	}else{
        	break;
    	}
	} while(1);
	short max, sign = 0;
	do{
		max = 31;
		printf("%-27s| ", "Your birthday .. .. ....");
		scanf("%hd %hd %hd", dayUser, monthUser, yearUser);
		getchar();
		if(*dayUser < 1 || *dayUser > 31 || *monthUser < 1 || *monthUser > 12 || 
		   *yearUser < 1950 || *yearUser > 2026){
			continue;
		}
		if(*monthUser == 4 || *monthUser == 6 || *monthUser == 9 || *monthUser == 11){
			max = 30;
		}else if(*monthUser == 2){
			if(*yearUser % 400 == 0 || (*yearUser % 4 == 0 && *yearUser % 100 != 0)){
				max = 29;
			}else{
				max = 28;
			}
		}
		if(*dayUser >= 1 && *dayUser <= max){
			sign = 1;
		}else{
			sign = 0;
		}
	}while(sign == 0);
	do{
		printf("%-27s| ", "Your email (...@gmail.com)");
    	fgets(email, 51, stdin);
   	 	email[strcspn(email, "\n")] = 0;
    	if(strstr(email, "@gmail.com")   != NULL ||
		   strstr(email, "@outlook.com") != NULL ||
		   strstr(email, "@hotmail.com") != NULL ||
		   strstr(email, "@iclound.com") != NULL ||
		   strstr(email, "@fpt.com")     != NULL ||
		   strstr(email, "@proton.me")   != NULL ||
		   strstr(email, "@me.com")      != NULL ||
		   strstr(email, "@duck.com")    != NULL ||
		   strstr(email, "@yandex.com")  != NULL ||
		   strstr(email, "@tuta.com")    != NULL){
        	break;
    	}
	}while (1);
	printf("%-27s| ", "Your password");
	fgets(passWord, 21, stdin);
	passWord[strcspn(passWord, "\n")] = 0;
	short isValid;
	do {
		isValid = 1;
        printf("%-27s| ", "Your phone number");
        fgets(phoneNumber, 20, stdin);
        phoneNumber[strcspn(phoneNumber, "\n")] = 0;
        if(strlen(phoneNumber) != 10){
            isValid = 0;
        }else if(phoneNumber[0] != '0'){
            isValid = 0;
        }else {
            for (int i = 0; i < 10; i++) {
                if (isdigit(phoneNumber[i]) == 0) {
                    isValid = 0;
                    break;
                }
            }
        }
    } while(isValid == 0);
	printf("\n\t\t ***Login Your Account***\n");
	char emailCheck[51], passWordCheck[21];
	while(1){
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

void showUserProfile(char *userName, short *dayUser, short *monthUser, short *yearUser,
					 char *email, char *passWord, char *phoneNumber){
	printf("|--------------------------------------------------|\n");
	printf("|                   USER PROFILE                   |\n");
	printf("|--------------------------------------------------|\n");
	printf("|%-15s|%-34s|\n", "User name", userName);
	printf("|%-15s|%2hd/%2hd/%4hd                        |\n", 
		   "Birthday", *dayUser, *monthUser, *yearUser);
	printf("|%-15s|%-34s|\n", "Email", email);
	printf("|%-15s|%-34s|\n", "Password", passWord);
	printf("|%-15s|%-34s|\n", "Phone number", phoneNumber);
	printf("|--------------------------------------------------|\n");
}

void changeEmail(char *email){
	char newEmail[51];
	do{
		printf("%-27s| ", "Your new email");
    	fgets(newEmail, 51, stdin);
   	 	newEmail[strcspn(newEmail, "\n")] = 0;
    	if(strstr(newEmail, "@gmail.com") != NULL) {
        	break;
    	}
	}while (1);
	strcpy(email, newEmail);
	printf("\n\t***Changing Successfully***\n");
}

void changePassword(char *passWord){
	char newPassword[20];
	printf("%-27s| ", "Your new password");
	fgets(newPassword, 20, stdin);
   	newPassword[strcspn(newPassword, "\n")] = 0;
	strcpy(passWord, newPassword);
	printf("\n\t***Changing Successfully***\n");
}