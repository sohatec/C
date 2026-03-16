#ifndef FILE_IO_H
#define FILE_IO_H

void S_Developer_TXT(Developer *dataDeveloper, int *pointCount);
void S_Project_TXT(Project *dataProject, int *pointCheck);
				
void R_Developer_TXT();
void R_Project_TXT();		
				
void S_Developer_BIN(Developer *dataDeveloper, int *pointCount);
void S_Project_BIN(Project *dataProject, int *pointCheck);
void S_User_BIN(char *userName, short *dayUser, short *monthUser, short *yearUser, 
				char *email, char *passWord, char *phoneNumber, short *checkUser);

void R_Developer_BIN(Developer **dataDeveloper, int *pointCount, int *currentCapacityDEV);
void R_Project_BIN(Project **dataProject, int *pointCheck, int *currentCapacityPRJ);
short R_User_BIN(char *userName, short *dayUser, short *monthUser, short *yearUser, 
				 char *email, char *passWord, char *phoneNumber, short *checkUser);

#endif